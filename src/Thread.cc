/*
 * @Author: Gyy0727 3155833132@qq.com
 * @Date: 2023-11-30 15:33:14
 * @LastEditors: Gyy0727 3155833132@qq.com
 * @LastEditTime: 2024-03-27 16:13:07
 * @FilePath: /桌面/myModuo/src/Thread.cc
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置
 * 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#include "../include/Thread.h"
#include "../include/util.h"
#include <memory>
#include <semaphore.h>
#include <thread>

Thread::Thread(ThreadFunc func, std::string name)
    : m_started(false), m_joined(false), m_threadId(0),
      m_func(func), m_threadName(name) {
  //*
}

Thread::~Thread() {
  if (m_started && !m_joined) {
    this->detach();
  }
}

void Thread::join() {
  if (!m_joined) {
    m_joined=true;
    m_thread->join();
  }
}

void Thread::detach() {
  if (!m_joined) {
    m_joined=true;
    m_thread->detach();
  }
}

void Thread::start() {
  m_started=true;
  sem_t sem;
  sem_init(&sem, false, 0);
  m_thread = std::shared_ptr<std::thread>(new std::thread([&]() {
    m_threadId = GetThreadId();
    sem_post(&sem);
    m_func();
  }));
  sem_wait(&sem);
}
