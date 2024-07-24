/*
 * @Author: Gyy0727 3155833132@qq.com
 * @Date: 2024-03-24 16:47:56
 * @LastEditors: Gyy0727 3155833132@qq.com
 * @LastEditTime: 2024-04-01 12:44:53
 * @FilePath: /muduo/src/EventLoopThreadPool.cc
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置
 * 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#include "../include/EventLoopThreadPool.h"
#include "../include/EventLoopThread.h"
#include <cstddef>

EventLoopThreadPool::EventLoopThreadPool(EventLoop *baseLoop,
                                         const ThreadInitCallback &cb)
    : m_baseLoop(baseLoop), m_start(false),m_threadNums(5), m_nextLoop(0) {
  m_func = cb;
}

EventLoopThreadPool::~EventLoopThreadPool() {}

void EventLoopThreadPool::startPool() {
  m_start = true;
  for (int i = 0; i < m_threadNums; ++i) {
    char buf[32];
    snprintf(buf, sizeof buf, "%s%d", "事件循环", i);
    EventLoopThread *t = new EventLoopThread(m_func, buf);
    m_threads.push_back(std::unique_ptr<EventLoopThread>(t));
    m_loops.push_back(
        t->startLoop()); // 底层创建线程，绑定一个新的EventLoop，并返回该loop的地址
  }
  // 整个服务端只有一个线程，运行着baseloop
  if (m_threadNums == 0 && m_func) {
    m_func(m_baseLoop);
  }
}

EventLoop *EventLoopThreadPool::getNextLoop() {

  EventLoop *loop = m_baseLoop;

  if (!m_loops.empty()) // 通过轮询获取下一个处理事件的loop
  {
    loop = m_loops[m_nextLoop];
    ++m_nextLoop;
    if (m_nextLoop >= static_cast<int>(m_loops.size())) {
      m_nextLoop = 0;
    }
  }

  return loop;
}

std::vector<EventLoop *> EventLoopThreadPool::getAllLoops() {
  if (m_loops.empty()) {
    return std::vector<EventLoop *>(1, m_baseLoop);
  } else {
    return m_loops;
  }
}
