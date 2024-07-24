/*
 * @Author: Gyy0727 3155833132@qq.com
 * @Date: 2023-11-21 16:04:55
 * @LastEditors: Gyy0727 3155833132@qq.com
 * @LastEditTime: 2024-04-01 14:43:30
 * @FilePath: /桌面/myModuo/src/Channel.cc
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置
 * 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#include "../include/Channel.h"
#include "../include/EventLoop.h"
#include "../include/Logger.h"
#include <memory>
const int Channel::KNONEEVENT = 0;
const int Channel::KREADEVENT = EPOLLIN | EPOLLPRI;
const int Channel::KWRITEEVENT = EPOLLOUT;

Channel::Channel(EventLoop *loop, int fd)
    : m_loop(loop), m_fd(fd), m_events(0), m_rtevent(0), m_index(-1),
      m_tied(false) {}

void Channel::remove() { m_loop->removeChannel(this); }

Channel::~Channel() {}

void Channel::update() { m_loop->updateChannel(this); }

void Channel::handleEvent(TimeStamp receiveTime) {
  if (m_tied) {
    std::shared_ptr<void> guard = m_tie.lock();
    if (guard) {
      submitEventWithLock(receiveTime);
    }
  } else {
    submitEventWithLock(receiveTime);
  }
}

//*执行回调函数
void Channel::submitEventWithLock(TimeStamp receiveTime) {
  LOG_INFO(LOG_ROOT()) << "channel handleEvent revents:" << m_rtevent;

  if ((m_rtevent & EPOLLHUP) && !(m_rtevent & EPOLLIN)) {
    if (m_closeCallback) {
      m_closeCallback();
    }
  }

  if (m_rtevent & EPOLLERR) {
    if (m_errorCallback) {
      m_errorCallback();
    }
  }

  if (m_rtevent & (EPOLLIN | EPOLLPRI)) {
    if (m_readCallback) {
      m_readCallback(receiveTime);
    }
  }

  if (m_rtevent & EPOLLOUT) {
    if (m_writeCallback) {
      m_writeCallback();
    }
  }
}