/*
 * @Author: Gyy0727 3155833132@qq.com
 * @Date: 2023-12-02 18:58:13
 * @LastEditors: Gyy0727 3155833132@qq.com
 * @LastEditTime: 2024-04-01 12:54:14
 * @FilePath: /桌面/myModuo/include/TcpConnection.h
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置
 * 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#pragma once

#include "Buffer.h"
#include "Callback.h"
#include "InetAddress.h"
#include "NonCopyable.h"
#include "TimeStamp.h"
#include <atomic>
#include <memory>
#include <string>
/**
 * Tcp连接, 为服务器和客户端使用.
 * 接口类, 因此不要暴露太多细节.
 *
 * @note 继承自std::enable_shared_from_this的类,
 * 可以用getSelf返回用std::shared_ptr管理的this指针
 */
class Channel;
class EventLoop;
class Socket;
class TcpConnection : NonCopyable,
                      public std::enable_shared_from_this<TcpConnection> {
public:
  TcpConnection(EventLoop *loop, const std::string &name, int sockfd,
                const InetAddress &localAddr, const InetAddress &peerAddr);
  ~TcpConnection();

  EventLoop *getLoop() const { return m_loop; }
  const std::string &getName() const { return m_name; }
  const InetAddress &getLocalAddress() const { return m_localAddr; }
  const InetAddress &getPeerAddress() const { return m_localAddr; }

  bool connected() const { return m_state == Connected; }

  // 发送数据
  void send(const std::string &buf);
  // 关闭连接
  void shutdown();
  void setConnectionCallback(const ConnectionCallback &cb) {
    connectionCallback_ = cb;
  }

  void setMessageCallback(const MessageCallback &cb) { messageCallback_ = cb; }

  void setWriteCompleteCallback(const WriteCompleteCallback &cb) {
    writeCompleteCallback_ = cb;
  }

  void setHighWaterMarkCallback(const HighWaterMarkCallback &cb,
                                size_t highWaterMark) {
    highWaterMarkCallback_ = cb;
    highWaterMark_ = highWaterMark;
  }

  void setCloseCallback(const CloseCallback &cb) { closeCallback_ = cb; }

  // 连接建立
  void connectEstablished();
  // 连接销毁
  void connectDestroyed();

private:
  enum STATE { Disconnected, Connecting, Connected, Disconnecting };
  void setState(STATE state) { m_state = state; }
  void handleRead(TimeStamp receiveTime);
  void handleWrite();
  void handleClose();
  void handleError();

  void sendInLoop(const void *message, size_t len);
  void shutdownInLoop();
  EventLoop *m_loop;
  const std::string m_name;
  std::atomic_int m_state;
  bool m_reading;
  std::unique_ptr<Socket> m_socket;
  std::unique_ptr<Channel> m_channel;
  const InetAddress m_localAddr;
  const InetAddress m_peerAddr;
  ConnectionCallback connectionCallback_;       //* 有新连接时的回调
  MessageCallback messageCallback_;             //* 有读写消息时的回调
  WriteCompleteCallback writeCompleteCallback_; //* 消息发送完成以后的回调
  HighWaterMarkCallback highWaterMarkCallback_; //* 高水位回调
  CloseCallback closeCallback_;
  size_t highWaterMark_;
  Buffer inputBuffer_;  //* 接收数据的缓冲区
  Buffer outputBuffer_; //* 发送数据的缓冲区
};