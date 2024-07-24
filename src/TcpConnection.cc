/*
 * @Author: Gyy0727 3155833132@qq.com
 * @Date: 2023-12-02 18:58:04
 * @LastEditors: Gyy0727 3155833132@qq.com
 * @LastEditTime: 2024-04-02 12:54:07
 * @FilePath: /桌面/myModuo/src/TcpConnection.cc
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置
 * 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#include "../include/TcpConnection.h"
#include "../include/Channel.h"
#include "../include/EventLoop.h"
#include "../include/Logger.h"
#include "../include/Socket.h"
static EventLoop *CheckLoopNotNull(EventLoop *loop)
{
  if (loop == nullptr)
  {
    LOG_FATAL(LOG_ROOT()) << " TcpConnection Loop is null!";
  }
  return loop;
}

TcpConnection::TcpConnection(EventLoop *loop, const std::string &name,
                             int sockfd, const InetAddress &localAddr,
                             const InetAddress &peerAddr)
    : m_loop(loop), m_name(name), m_state(Connecting), m_reading(true),
      m_socket(new Socket(sockfd)), m_channel(new Channel(loop, sockfd)),
      m_localAddr(localAddr), m_peerAddr(peerAddr),
      highWaterMark_(64 * 1024 * 1024)
{
  m_channel->setReadCallback(
      std::bind(&TcpConnection::handleRead, this, std::placeholders::_1));
  m_channel->setWriteCallback(std::bind(&TcpConnection::handleWrite, this));
  m_channel->setCloseCallback(std::bind(&TcpConnection::handleClose, this));
  m_channel->setErrorCallback(std::bind(&TcpConnection::handleError, this));
  LOG_INFO(LOG_ROOT()) << "TcpConnection::ctor " << m_name.c_str()
                       << "at fd= " << sockfd;
  m_socket->setKeepAlive(true);
}

TcpConnection::~TcpConnection()
{
  LOG_INFO(LOG_ROOT()) << "TcpConnection::dtor[" << m_name.c_str()
                       << "] at fd=" << m_channel->getfd()
                       << " state= " << (int)m_state;
}

void TcpConnection::send(const std::string &buf)
{

  if (m_state == Connected)
  {
    if (m_loop->isInLoopThread())
    {
      sendInLoop(buf.c_str(), buf.size());
    }
    else
    {
      m_loop->runInLoop(
          std::bind(&TcpConnection::sendInLoop, this, buf.c_str(), buf.size()));
    }
  }
}

void TcpConnection::sendInLoop(const void *data, size_t len)
{
  ssize_t nwrote = 0;
  size_t remaining = len;
  bool faultError = false;

  // 之前调用过该connection的shutdown，不能再进行发送了
  if (m_state == Disconnected)
  {
    LOG_ERROR(LOG_ROOT()) << "disconnected, give up writing!";
    return;
  }

  // 表示channel_第一次开始写数据，而且缓冲区没有待发送数据
  if (!m_channel->isWriting() && outputBuffer_.readableBytes() == 0)
  {
    nwrote = ::write(m_channel->getfd(), data, len);
    if (nwrote >= 0)
    {
      remaining = len - nwrote;
      if (remaining == 0 && writeCompleteCallback_)
      {
        // 既然在这里数据全部发送完成，就不用再给channel设置epollout事件了
        m_loop->wakeupLoop(
            std::bind(writeCompleteCallback_, shared_from_this()));
      }
    }
    else // nwrote < 0
    {
      nwrote = 0;
      if (errno != EWOULDBLOCK)
      {
        LOG_ERROR(LOG_ROOT()) << "TcpConnection::sendInLoop";
        if (errno == EPIPE || errno == ECONNRESET) // SIGPIPE  RESET
        {
          faultError = true;
        }
      }
    }
  }

  // 说明当前这一次write，并没有把数据全部发送出去，剩余的数据需要保存到缓冲区当中，然后给channel
  // 注册epollout事件，poller发现tcp的发送缓冲区有空间，会通知相应的sock-channel，调用writeCallback_回调方法
  // 也就是调用TcpConnection::handleWrite方法，把发送缓冲区中的数据全部发送完成
  if (!faultError && remaining > 0)
  {
    // 目前发送缓冲区剩余的待发送数据的长度
    size_t oldLen = outputBuffer_.readableBytes();
    if (oldLen + remaining >= highWaterMark_ && oldLen < highWaterMark_ &&
        highWaterMarkCallback_)
    {
      m_loop->wakeupLoop(std::bind(highWaterMarkCallback_, shared_from_this(),
                                   oldLen + remaining));
    }
    outputBuffer_.append((char *)data + nwrote, remaining);
    if (!m_channel->isWriting())
    {
      m_channel
          ->listenWriting(); // 这里一定要注册channel的写事件，否则poller不会给channel通知epollout
    }
  }
}
void TcpConnection::shutdown()
{

  if (m_state == Connected)
  {
    setState(Disconnecting);
    m_loop->runInLoop(std::bind(&TcpConnection::shutdownInLoop, this));
  }
}

void TcpConnection::shutdownInLoop()
{
  if (!m_channel->isWriting()) // 说明outputBuffer中的数据已经全部发送完成
  {
    m_socket->shutdownWrite(); // 关闭写端
  }
}

// 连接建立
void TcpConnection::connectEstablished()
{
  setState(Connected);
  m_channel->tie(shared_from_this());
  m_channel->listenReading(); // 向poller注册channel的epollin事件

  // 新连接建立，执行回调
  connectionCallback_(shared_from_this());
}

// 连接销毁
void TcpConnection::connectDestroyed()
{

  if (m_state == Connected)
  {
    setState(Disconnected);
    m_channel->notlistenAll(); // 把channel的所有感兴趣的事件，从poller中del掉
    connectionCallback_(shared_from_this());
  }
  m_channel->remove(); // 把channel从poller中删除掉
}

void TcpConnection::handleRead(TimeStamp receiveTime)
{

  int savedErrno = 0;
  ssize_t n = inputBuffer_.readFd(m_channel->getfd(), &savedErrno);
  if (n > 0)
  {
    // 已建立连接的用户，有可读事件发生了，调用用户传入的回调操作onMessage
    messageCallback_(shared_from_this(), &inputBuffer_, receiveTime);
  }
  else if (n == 0)
  {
    handleClose();
  }
  else
  {
    errno = savedErrno;
    LOG_ERROR(LOG_ROOT()) << "TcpConnection::handleRead";
    handleError();
  }
}

void TcpConnection::handleWrite()
{
  if (m_channel->isWriting())
  {
    int savedErrno = 0;
    ssize_t n = outputBuffer_.writeFd(m_channel->getfd(), &savedErrno);
    if (n > 0)
    {
      outputBuffer_.retrieve(n);
      if (outputBuffer_.readableBytes() == 0)
      {
        m_channel->notlistenWriting();
        if (writeCompleteCallback_)
        {
          // 唤醒loop_对应的thread线程，执行回调
          m_loop->wakeupLoop(
              std::bind(writeCompleteCallback_, shared_from_this()));
        }
        if (m_state == Disconnecting)
        {
          shutdownInLoop();
        }
      }
    }
    else
    {
      LOG_ERROR(LOG_ROOT()) << "TcpConnection::handleWrite";
    }
  }
  else
  {
    LOG_ERROR(LOG_ROOT()) << "TcpConnection fd=" << m_channel->getfd()
                          << "is down, no more writing ";
  }
}

// poller => channel::closeCallback => TcpConnection::handleClose
void TcpConnection::handleClose()
{
  LOG_INFO(LOG_ROOT()) << "TcpConnection::handleClose fd=" << m_channel->getfd()
                       << " state=" << (int)m_state;
  setState(Disconnected);
  m_channel->notlistenAll();

  TcpConnectionPtr connPtr(shared_from_this());
  connectionCallback_(connPtr); // 执行连接关闭的回调
  closeCallback_(
      connPtr); // 关闭连接的回调  执行的是TcpServer::removeConnection回调方法
}

void TcpConnection::handleError()
{
  int optval;
  socklen_t optlen = sizeof optval;
  int err = 0;
  if (::getsockopt(m_channel->getfd(), SOL_SOCKET, SO_ERROR, &optval, &optlen) <
      0)
  {
    err = errno;
  }
  else
  {
    err = optval;
  }
  LOG_ERROR(LOG_ROOT()) << "TcpConnection::handleError name:" << m_name.c_str()
                        << " - SO_ERROR:" << err;
}