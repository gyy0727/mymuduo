/*
 * @Author: Gyy0727 3155833132@qq.com
 * @Date: 2023-11-21 17:07:19
 * @LastEditors: Gyy0727 3155833132@qq.com
 * @LastEditTime: 2024-03-26 17:27:13
 * @FilePath: /桌面/myModuo/include/EventLoop.h
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置
 * 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#pragma once
#include "NonCopyable.h"
#include "TimeStamp.h"
#include "util.h"
#include <atomic>
#include <fcntl.h>
#include <functional>
#include <memory>
#include <mutex>
#include <sched.h>
#include <sys/eventfd.h>
#include <unistd.h>
#include <vector>
/**
 * Reactor模式， 每个线程最多一个EventLoop (One loop per thread).
 * 接口类, 不要暴露太多细节给客户
 */
class Channel;
class Poller;
class EventLoop : NonCopyable {
public:
  using EventLoopPtr = std::shared_ptr<EventLoop>;
  using Func = std::function<void()>;
  EventLoop();
  ~EventLoop();
  int getWakeupfd() {
    return m_wakeupfd;
  }
  void startLoop();
  void quitLoop();
  void runInLoop(Func func);
  void wakeupLoop(Func func);
  void wakeup();
  void updateChannel(Channel *channel);
  void removeChannel(Channel *channel);
  bool hasChannel(Channel *channel);
  pid_t getThreadId() const { return m_threadId; }
  // 判断EventLoop对象是否在自己的线程里面
  bool isInLoopThread() const { return m_threadId == GetThreadId(); }

private:
  void handleRead();
  void execCallBack();

  using ChannelList = std::vector<Channel *>;
  std::atomic_bool m_looping;
  std::atomic_bool m_quit;
  const pid_t m_threadId;
  int m_wakeupfd;
  std::unique_ptr<Channel> m_wakeupChannel;
  std::unique_ptr<Poller> m_poller;
  ChannelList m_activeChannels;
  std::atomic_bool m_ifThisLoopExecingCallBacks;
  std::vector<Func> m_callBacks;
  std::mutex m_mutex;
};
