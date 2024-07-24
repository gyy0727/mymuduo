/*
 * @Author: Gyy0727 3155833132@qq.com
 * @Date: 2023-11-21 18:37:53
 * @LastEditors: Gyy0727 3155833132@qq.com
 * @LastEditTime: 2024-04-01 13:08:35
 * @FilePath: /桌面/myModuo/include/TcpServer.h
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置
 * 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#pragma once

/**
 * 用户使用muduo编写服务器程序
 */
#include "Acceptor.h"
#include "Buffer.h"
#include "Callback.h"
#include "EventLoop.h"
#include "EventLoopThreadPool.h"
#include "InetAddress.h"
#include "NonCopyable.h"
#include "TcpConnection.h"
#include <atomic>
#include <functional>
#include <memory>
#include <mutex>
#include <string>
#include <unordered_map>
// TcpServer.h
/**
 * Tcp Server, 支持单线程和thread-poll模型.
 * 接口类, 因此不要暴露太多细节.
 */
// 对外的服务器编程使用的类
class TcpServer : NonCopyable {
public:
  using ThreadInitCallback = std::function<void(EventLoop *)>;

  enum Option {
    kNoReusePort,
    kReusePort,
  };

  TcpServer(EventLoop *loop, const InetAddress &listenAddr,
            const std::string &nameArg, Option option = kReusePort);
  ~TcpServer();

  void setThreadInitcallback(const ThreadInitCallback &cb) {
    m_threadInitCallback = cb;
  }
  void setConnectionCallback(const ConnectionCallback &cb) {
    m_connectionCallback = cb;
  }
  void setMessageCallback(const MessageCallback &cb) { m_messageCallback = cb; }
  void setWriteCompleteCallback(const WriteCompleteCallback &cb) {
    m_writeCompleteCallback = cb;
  }

  // 设置底层subloop的个数
  void setThreadNum(int numThreads);

  // 开启服务器监听
  void start();

private:
  void newConnection(int sockfd, const InetAddress &peerAddr);
  void removeConnection(const TcpConnectionPtr &conn);
  void removeConnectionInLoop(const TcpConnectionPtr &conn);

  using ConnectionMap = std::unordered_map<std::string, TcpConnectionPtr>;

  EventLoop *m_baseLoop; // baseLoop 用户定义的loop

  const std::string m_ipPort;
  const std::string m_name;

  std::unique_ptr<Acceptor> m_acceptor; // 运行在mainLoop，任务就是监听新连接事件

  std::shared_ptr<EventLoopThreadPool> m_threadPool; // one loop per thread

  ConnectionCallback m_connectionCallback;       // 有新连接时的回调
  MessageCallback m_messageCallback;             // 有读写消息时的回调
  WriteCompleteCallback m_writeCompleteCallback; // 消息发送完成以后的回调

  ThreadInitCallback m_threadInitCallback; // loop线程初始化的回调
  std::mutex m_mutex;
  
  
  std::atomic_bool m_started;

  int  m_nextConnId;
  ConnectionMap m_connections; // 保存所有的连接
};