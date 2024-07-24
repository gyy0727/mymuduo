/*
 * @Author: Gyy0727 3155833132@qq.com
 * @Date: 2023-11-21 16:02:19
 * @LastEditors: Gyy0727 3155833132@qq.com
 * @LastEditTime: 2024-04-01 14:41:11
 * @FilePath: /桌面/myModuo/include/Channel.h
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置
 * 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#pragma once

#include "Logger.h"
#include "NonCopyable.h"
#include "TimeStamp.h"
#include <functional>
#include <memory>
#include <sys/epoll.h>
class EventLoop;

/**
 * 理清楚  EventLoop、Channel、Poller之间的关系   《= Reactor模型上对应
 * Demultiplex Channel
 * 理解为通道，封装了sockfd和其感兴趣的event，如EPOLLIN、EPOLLOUT事件
 * 还绑定了poller返回的具体事件
 */
class Channel;
using EventCallback = std::function<void()>;
using ReadCallback = std::function<void(TimeStamp)>;
using ChannelPtr = std::shared_ptr<Channel>;
class Channel : NonCopyable {
public:
  Channel(EventLoop *loop, int fd);
  ~Channel();
  void handleEvent(TimeStamp receiveTime);
  void setReadCallback(ReadCallback cb) { m_readCallback = std::move(cb); }
  void setWriteCallback(EventCallback cb) { m_writeCallback = std::move(cb); }
  void setCloseCallback(EventCallback cb) { m_closeCallback = std::move(cb); }
  void setErrorCallback(EventCallback cb) { m_errorCallback = std::move(cb); }
  // !
  void tie(const std::shared_ptr<void> &T) {
    
    m_tie = T;
    m_tied = true;
  }

  int getfd() { return m_fd; }

  int getEvents() { return m_events; }

  void setRtEvent(int event) { m_rtevent = event; }

  void listenReading() {
    m_events |= KREADEVENT;
    update();
  }

  void notlistenReading() {
    m_events &= ~KREADEVENT;
    update();
  }

  void listenWriting() {
    m_events |= KWRITEEVENT;
    update();
  }

  void notlistenWriting() {
    m_events &= ~KWRITEEVENT;
    update();
  }

  void notlistenAll() {
    m_events = KNONEEVENT;
    update();
  }
  bool isNoneEvent() const { return m_events == KNONEEVENT; }

  bool isWriting() const { return m_events & KWRITEEVENT; }

  bool isReading() const { return m_events & KREADEVENT; }

  int getIndex() { return m_index; }

  void set_index(int idx) { m_index = idx; }

  // one loop per thread
  EventLoop *ownerLoop() { return m_loop; }

  void remove();

private:
  void update();

  void submitEventWithLock(TimeStamp receiveTime);

  static const int KNONEEVENT;
  static const int KREADEVENT;
  static const int KWRITEEVENT;
  EventLoop *m_loop;
  const int m_fd = 0;
  int m_events;
  int m_rtevent;
  int m_index;
  std::weak_ptr<void> m_tie;
  bool m_tied;
  ReadCallback m_readCallback;
  EventCallback m_writeCallback;
  EventCallback m_closeCallback;
  EventCallback m_errorCallback;
};
