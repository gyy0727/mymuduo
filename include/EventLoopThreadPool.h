/*
 * @Author: Gyy0727 3155833132@qq.com
 * @Date: 2024-03-24 16:47:56
 * @LastEditors: Gyy0727 3155833132@qq.com
 * @LastEditTime: 2024-04-01 12:43:38
 * @FilePath: /muduo/include/EventLoopThreadPool.h
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置
 * 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#pragma once
#include "NonCopyable.h"
#include <functional>
#include <memory>
#include <string>
#include <vector>
class EventLoop;
class EventLoopThread;
// 作为线程池对象，绑定了背后的系统资源，如线程，因此是引用语义（不可拷贝）
class EventLoopThreadPool : NonCopyable {
public:
  using ThreadInitCallback = std::function<void(EventLoop *)>;
  EventLoopThreadPool(EventLoop *baseLoop,const ThreadInitCallback &cb = ThreadInitCallback());
  ~EventLoopThreadPool();
  void startPool();
  EventLoop *getNextLoop();
  std::vector<EventLoop *> getAllLoops();
  void setThreadNums(int nums) {
    m_threadNums=nums;
  }
private:
  EventLoop *m_baseLoop;
  bool m_start;
  int m_threadNums;
  int  m_nextLoop;
  std::vector<std::unique_ptr<EventLoopThread>> m_threads;
  std::vector<EventLoop *> m_loops;
  ThreadInitCallback m_func;
};