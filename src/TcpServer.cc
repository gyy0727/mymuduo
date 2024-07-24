/*
 * @Author: Gyy0727 3155833132@qq.com
 * @Date: 2023-11-21 18:38:01
 * @LastEditors: Gyy0727 3155833132@qq.com
 * @LastEditTime: 2024-04-01 13:49:40
 * @FilePath: /桌面/myModuo/src/TcpServer.cc
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置
 * 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#include "../include/TcpServer.h"
#include "../include/EventLoopThreadPool.h"
#include "../include/Logger.h"
#include "../include/TcpConnection.h"
#include <cstdio>
#include <functional>
#include <mutex>

static EventLoop *CheckLoopNotNull(EventLoop *loop) {
  if (loop == nullptr) {
    LOG_FATAL(LOG_ROOT()) << " mainLoop is null! ";
  }
  return loop;
}
TcpServer::TcpServer(EventLoop *loop, const InetAddress &listenAddr,
                     const std::string &nameArg, Option option)
    : m_baseLoop(loop), m_ipPort(listenAddr.toIpPort()), m_name(nameArg),
      m_acceptor(new Acceptor(loop, listenAddr,  kReusePort)),
      m_threadPool(new EventLoopThreadPool(loop)), m_connectionCallback(),
      m_messageCallback(),  m_started(false), m_nextConnId(){
  m_acceptor->setNewConnectionCallback(std::bind(&TcpServer::newConnection,
                                                 this, std::placeholders::_1,
                                                 std::placeholders::_2));
}

TcpServer::~TcpServer() {}

// 设置底层subloop的个数
void TcpServer::setThreadNum(int numThreads) {
  m_threadPool->setThreadNums(numThreads);
}

// 开启服务器监听   loop.loop()
void TcpServer::start() {
  if (m_started == false) {
    m_threadPool->startPool();
    m_baseLoop->runInLoop(std::bind(&Acceptor::listen, m_acceptor.get()));
  }
}

// 有一个新的客户端的连接，acceptor会执行这个回调操作
void TcpServer::newConnection(int sockfd, const InetAddress &peerAddr) {
  // 轮询算法，选择一个subLoop，来管理channel
  EventLoop *loop = m_threadPool->getNextLoop();
  char buf[64] = {0};
  snprintf(buf, sizeof(buf), "-%s#%d", m_ipPort.c_str(), m_nextConnId);
  {
    std::unique_lock<std::mutex> lock(m_mutex);
    ++m_nextConnId;
  }
  std::string connName = m_name + buf;
  LOG_INFO(LOG_ROOT()) << "TcpServer::newConnection [" << m_name.c_str()
                       << "] - new connection [" << connName.c_str()
                       << "] from " << peerAddr.toIpPort().c_str();
  sockaddr_in local;
  ::bzero(&local, sizeof local);
  socklen_t addrlen = sizeof local;
  if (::getsockname(sockfd, (sockaddr *)&local, &addrlen) < 0) {
    LOG_ERROR(LOG_ROOT()) << "sockets::getLocalAddr";
  }
  InetAddress localAddr(local);
  TcpConnectionPtr conn(new TcpConnection(
                            loop,
                            connName,
                            sockfd,   // Socket Channel
                            localAddr,
                            peerAddr));
    m_connections[connName] = conn;
    // 下面的回调都是用户设置给TcpServer=>TcpConnection=>Channel=>Poller=>notify channel调用回调
    conn->setConnectionCallback(m_connectionCallback);
    conn->setMessageCallback(m_messageCallback);
    conn->setWriteCompleteCallback(m_writeCompleteCallback);

    // 设置了如何关闭连接的回调   conn->shutDown()
    conn->setCloseCallback(
        std::bind(&TcpServer::removeConnection, this, std::placeholders::_1)
    );

    // 直接调用TcpConnection::connectEstablished
    loop->runInLoop(std::bind(&TcpConnection::connectEstablished, conn));
}

void TcpServer::removeConnection(const TcpConnectionPtr &conn) {
  m_baseLoop->runInLoop(
      std::bind(&TcpServer::removeConnectionInLoop, this, conn));
}

void TcpServer::removeConnectionInLoop(const TcpConnectionPtr &conn) {
  LOG_INFO(LOG_ROOT()) << "TcpServer::removeConnectionInLoop  "
                       << conn->getName() << " - connection";
  m_connections.erase(conn->getName());
  EventLoop *ioLoop = conn->getLoop();
  ioLoop->wakeupLoop(std::bind(&TcpConnection::connectDestroyed, conn));
}