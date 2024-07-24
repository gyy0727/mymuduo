/*
 * @Author: Gyy0727 3155833132@qq.com
 * @Date: 2023-11-30 16:05:09
 * @LastEditors: Gyy0727 3155833132@qq.com
 * @LastEditTime: 2024-03-28 19:48:28
 * @FilePath: /桌面/myModuo/src/EventLoopThread.cc
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置
 * 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#include "../include/EventLoopThread.h"
#include "../include/EventLoop.h"
#include <condition_variable>
#include <functional>
#include <memory>
#include <mutex>
EventLoopThread::EventLoopThread(ThreadInitCallback func, std::string)
    : m_loop(nullptr), m_started(false), m_quit(false),
      m_threadLoop(std::bind(&EventLoopThread::ThreadFunc, this)),
      m_initCallback(func) {}

EventLoopThread::~EventLoopThread()
{
  m_quit = true;
  if (m_loop)
  {
    m_loop->quitLoop();
    m_threadLoop.join();
  }
}

EventLoop *EventLoopThread::startLoop()
{
  m_threadLoop.start();
  EventLoop *loop = nullptr;
  {
    std::unique_lock<std::mutex> lock(m_mutex);
    while (m_loop == nullptr)
    {
      m_cond.wait(lock);
    }
    loop = m_loop;
  }
  return loop;
}
void EventLoopThread::quitLoop()
{
}

void EventLoopThread::ThreadFunc()
{
  EventLoop loop;
  if (m_initCallback)
  {
    m_initCallback(&loop);
  }
  {
    std::unique_lock<std::mutex> lock(m_mutex);
    m_loop = &loop;
    m_cond.notify_one();
  }
  loop.startLoop();
  std::unique_lock<std::mutex> lock(m_mutex);
  m_loop = nullptr;
}