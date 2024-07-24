/*
 * @Author: Gyy0727 3155833132@qq.com
 * @Date: 2023-11-22 15:06:35
 * @LastEditors: Gyy0727 3155833132@qq.com
 * @LastEditTime: 2024-04-01 14:22:26
 * @FilePath: /桌面/smallchat/src/socket.cc
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置
 * 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#include "../include/Socket.h"
#include "../include/Logger.h"
#include <arpa/inet.h>
#include <iostream>
#include <netinet/in.h>
#include <netinet/tcp.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <unistd.h>

Socket::~Socket() { close(m_sockfd); }

void Socket::bindAddress(const InetAddress &localaddr) {
  if (0 != ::bind(m_sockfd, (sockaddr *)localaddr.getSockAddr(),
                  sizeof(sockaddr_in))) {
    LOG_FATAL(LOG_ROOT()) << "bind sockfd: " << m_sockfd << " fail";
  }
}
void Socket::listen() {
  LOG_ERROR(LOG_ROOT()) << "++++++++++++++++++++++++++listen++++++++++++++++++++++++++++++++++++++" ;
  if (0 != ::listen(m_sockfd, 1024)) {
    LOG_FATAL(LOG_ROOT()) << "listen sockfd " << m_sockfd << " fail";
  }
}
int Socket::accept(InetAddress *peeraddr) {
   LOG_ERROR(LOG_ROOT()) << "++++++++++++++++++++++++++++++accept++++++++++++++++++++++++++++++++++" ;
  sockaddr_in addr;
  socklen_t len = sizeof addr;
  bzero(&addr, sizeof addr);
  int connfd = ::accept4(m_sockfd, (sockaddr *)&addr, &len,
                         SOCK_NONBLOCK | SOCK_CLOEXEC);
  if (connfd >= 0) {
    peeraddr->setSockAddr(addr);
  }
  return connfd;
}

void Socket::shutdownWrite() {
  if (::shutdown(m_sockfd, SHUT_WR) < 0)
    {
        LOG_ERROR(LOG_ROOT()) << "shutdownWrite error";
    }
}

void Socket::setTcpNoDelay(bool on)
{
    int optval = on ? 1 : 0;
    ::setsockopt(m_sockfd, IPPROTO_TCP, TCP_NODELAY, &optval, sizeof optval);
}

void Socket::setReuseAddr(bool on)
{
    int optval = on ? 1 : 0;
    ::setsockopt(m_sockfd, SOL_SOCKET, SO_REUSEADDR, &optval, sizeof optval);
}

void Socket::setReusePort(bool on)
{
    int optval = on ? 1 : 0;
    ::setsockopt(m_sockfd, SOL_SOCKET, SO_REUSEPORT, &optval, sizeof optval);
}

void Socket::setKeepAlive(bool on)
{
    int optval = on ? 1 : 0;
    ::setsockopt(m_sockfd, SOL_SOCKET, SO_KEEPALIVE, &optval, sizeof optval);
}