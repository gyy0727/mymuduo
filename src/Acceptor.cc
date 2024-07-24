/*
 * @Author: Gyy0727 3155833132@qq.com
 * @Date: 2023-11-26 17:37:55
 * @LastEditors: Gyy0727 3155833132@qq.com
 * @LastEditTime: 2024-04-01 14:46:30
 * @FilePath: /桌面/myModuo/src/Acceptor.cc
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置
 * 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#include "../include/Acceptor.h"
#include "../include/Logger.h"
#include <cerrno>
#include <utility>
// 创建一个非阻塞文件描述符
static int createNonblocking() {
  int sockfd = ::socket(AF_INET, SOCK_STREAM | SOCK_NONBLOCK | SOCK_CLOEXEC, 0);
  if (sockfd < 0) {
    LOG_FATAL(LOG_ROOT()) << "listen socket create err:" << errno;
  }
  return sockfd;
}

Acceptor::Acceptor(EventLoop *loop, const InetAddress &listenaddr,
                   bool reuseport)
    : m_loop(loop), m_acceptSocket(createNonblocking()),
      m_acceptChannel(m_loop, m_acceptSocket.getSocketFd()),
      m_listening(false) {
  m_acceptSocket.setReusePort(true);
  m_acceptSocket.setReuseAddr(true);
  m_acceptSocket.bindAddress(listenaddr);
  m_acceptChannel.setReadCallback(std::bind(&Acceptor::handleRead, this));
 
}

Acceptor::~Acceptor() {
  m_acceptChannel.remove();
  m_acceptChannel.notlistenAll();
}
void Acceptor::listen() {
 
  m_listening = true;
  m_acceptSocket.listen();         // listen
  m_acceptChannel.listenReading(); // acceptChannel_ => Poller
}
void Acceptor::handleRead() {
 
  InetAddress peerAddr;
  int connfd = m_acceptSocket.accept(&peerAddr);
  if (connfd >= 0) {
    if (m_newConnectionCallback) {
      m_newConnectionCallback(
          
          connfd,
          peerAddr); // 轮询找到subLoop，唤醒，分发当前的新客户端的Channel
    } else {
      ::close(connfd);
    }
  } else {
    LOG_ERROR(LOG_ROOT()) << " accept err: " << errno;
    if (errno == EMFILE) {
      LOG_ERROR(LOG_ROOT()) << " sockfd reached limit! ";
    }
  }
}