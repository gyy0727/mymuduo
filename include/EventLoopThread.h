/*
 * @Author: Gyy0727 3155833132@qq.com
 * @Date: 2023-11-30 16:05:15
 * @LastEditors: Gyy0727 3155833132@qq.com
 * @LastEditTime: 2024-03-28 15:16:29
 * @FilePath: /桌面/myModuo/include/EventLoopThread..h
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置
 * 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#pragma once

#include "NonCopyable.h"
#include "Thread.h"
#include <condition_variable>
#include <functional>
#include <mutex>
#include <string>

class EventLoop;
class Thread;
class EventLoopThread : NonCopyable {
public:
  using ThreadInitCallback = std::function<void(EventLoop *)>;
  EventLoopThread(ThreadInitCallback func=ThreadInitCallback(), std::string = "新事件循环线程");
 ~EventLoopThread();

  EventLoop* startLoop();
  void quitLoop();

private:
  void ThreadFunc();
  EventLoop *m_loop;
  bool m_started;
  bool m_quit;
  Thread m_threadLoop;
  std::mutex m_mutex;
  std::condition_variable m_cond;
  ThreadInitCallback m_initCallback;
};