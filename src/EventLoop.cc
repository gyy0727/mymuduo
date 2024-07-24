/*
 * @Author: Gyy0727 3155833132@qq.com
 * @Date: 2023-11-21 17:07:25
 * @LastEditors: Gyy0727 3155833132@qq.com
 * @LastEditTime: 2024-04-01 19:24:23
 * @FilePath: /桌面/myModuo/src/EventLoop.cc
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置
 * 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE

 */
#include "../include/EventLoop.h"
#include "../include/Channel.h"
#include "../include/EPollPoller.h"
#include "../include/Logger.h"
#include "../include/TimeStamp.h"
#include <cerrno>
#include <cstddef>
#include <cstdint>
#include <fcntl.h>
#include <functional>
#include <mutex>
#include <sys/eventfd.h>
#include <unistd.h>
#include <vector>
class TimeStamp;
static thread_local EventLoop *t_loop_inthread = nullptr;
int createfd() {
  int evtfd = ::eventfd(0, EFD_NONBLOCK | EFD_CLOEXEC);
  LOG_INFO(LOG_ROOT()) << "wakeup fd " << evtfd << " have create" ;
  if (evtfd < 0) {
    LOG_FATAL(LOG_ROOT()) << "eventfd error: " << errno;
  }
  return evtfd;
}

EventLoop::EventLoop()
    : m_looping(false), m_quit(false), m_threadId(GetThreadId()),
      m_wakeupfd(createfd()), m_wakeupChannel(new Channel(this, m_wakeupfd)),
      m_poller(new EPollPoller(this)), m_ifThisLoopExecingCallBacks(false) {
  LOG_INFO(LOG_ROOT()) << "EventLoop created  in thread";
  if (t_loop_inthread) {
    if (t_loop_inthread != this) {
      LOG_FATAL(LOG_ROOT()) << "Another EventLoop  exists in this thread";
    }
  } else {
    t_loop_inthread = this;
  }
  m_wakeupChannel->setReadCallback(std::bind(&EventLoop::handleRead, this));
  m_wakeupChannel->listenReading();

}

EventLoop::~EventLoop() {
  m_wakeupChannel->notlistenAll();
  m_wakeupChannel->remove();
  close(m_wakeupfd);
  m_callBacks.clear();
  m_activeChannels.clear();
}

void EventLoop::startLoop() {
  m_looping = true;
  m_quit = false;
  LOG_INFO(LOG_ROOT()) << "EventLoop  start looping ";

  while (!m_quit) {
    m_activeChannels.clear();
    int rt = m_poller->poll(10000, m_activeChannels);
    if (rt <= 0) {
      continue;
    }
    for (auto it : m_activeChannels) {
      TimeStamp now;
      it->handleEvent(now);
    }
    execCallBack();
  }
  LOG_INFO(LOG_ROOT()) << "eventloop stop looping";
  m_looping = false;
}

void EventLoop::quitLoop() {

  if (!isInLoopThread()) {

    wakeup();
  }
  if (m_quit == true && m_looping == false) {
    return;
  }
  while (m_quit ==false) {
    if (m_callBacks.empty() && m_activeChannels.empty() &&
        m_ifThisLoopExecingCallBacks == false) {
      LOG_INFO(LOG_ROOT()) << "try to stop event loop";
      m_quit = true;
      break;
    }
  }
}

void EventLoop::runInLoop(Func func) {
  if (isInLoopThread()) // 在当前的loop线程中，执行cb
  {
    func();
  } else // 在非当前loop线程中执行cb , 就需要唤醒loop所在线程，执行cb
  {
    wakeupLoop(func);
  }
}

void EventLoop::wakeupLoop(Func func) {
  {
    std::unique_lock<std::mutex> lock(m_mutex);
    m_callBacks.emplace_back(func);
  }
  if (!isInLoopThread() || m_ifThisLoopExecingCallBacks) {
    wakeup(); // 唤醒loop所在线程
  }
}

void EventLoop::wakeup() {
  uint64_t one = 1;
  ssize_t n = write(m_wakeupfd, &one, sizeof(one));
  if (n == -1) {
    LOG_ERROR(LOG_ROOT()) << "wakeup loop by write \"t\"  fail";
    return;
  }
   LOG_DEBUG(LOG_ROOT()) << "write loop by write \"t\"  sucessful";
}
void EventLoop::updateChannel(Channel *channel) {
  m_poller->updateChannel(channel);
}

void EventLoop::removeChannel(Channel *channel) {
  m_poller->removeChannel(channel);
}

bool EventLoop::hasChannel(Channel *channel) {
  return m_poller->hasChannel(channel);
}

void EventLoop::handleRead() {
  uint64_t one = 1;
  ssize_t n = read(m_wakeupfd, &one, sizeof(one));
  if (n == -1) {
    LOG_ERROR(LOG_ROOT()) << "read loop by read \"t\"  fail";
    return;
  }
   LOG_DEBUG(LOG_ROOT()) << "read loop by read \"t\"  sucessful";
}


void EventLoop::execCallBack() {

  m_ifThisLoopExecingCallBacks = true;
  std::vector<Func> func;
  {
    std::unique_lock<std::mutex> lock(m_mutex);
    func.swap(m_callBacks);
  }
  for (const Func &f : func) {
    
    f();
  }
  m_ifThisLoopExecingCallBacks = false;
}
