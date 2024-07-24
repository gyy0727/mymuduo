/*
 * @Author: Gyy0727 3155833132@qq.com
 * @Date: 2023-11-26 17:38:09
 * @LastEditors: Gyy0727 3155833132@qq.com
 * @LastEditTime: 2024-04-01 12:38:58
 * @FilePath: /桌面/myModuo/include/Acceptor.h
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置
 * 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
/**
 * @description: 负责处理新链接
 */
/**
 * TCP连接接受器
 * 基础调用为accept(2)/accept4(2)
 */
#pragma once
#include "Channel.h"

#include "NonCopyable.h"
#include "Socket.h"
#include <functional>
class EventLoop;
class InetAddress;
class Acceptor : NonCopyable {
public:
  using NewConnectionCallback =
      std::function<void(int sockfd, const InetAddress &)>;

  Acceptor(EventLoop *loop, const InetAddress &listenaddr, bool reuseport);
  ~Acceptor();

  void setNewConnectionCallback(const NewConnectionCallback &cb) {
    m_newConnectionCallback = cb;
  }
  bool listening() { return m_listening; }
  void listen();

private:
  void handleRead();

  EventLoop *m_loop;
  Socket m_acceptSocket;
  Channel m_acceptChannel;
  NewConnectionCallback m_newConnectionCallback;
  bool m_listening;
};