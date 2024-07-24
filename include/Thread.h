/*
 * @Author: Gyy0727 3155833132@qq.com
 * @Date: 2023-11-30 15:33:22
 * @LastEditors: Gyy0727 3155833132@qq.com
 * @LastEditTime: 2024-03-27 15:44:46
 * @FilePath: /桌面/myModuo/include/Thread.h
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置
 * 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#pragma once

#include "NonCopyable.h"
#include <functional>
#include <memory>
#include <sched.h>
#include <semaphore.h>
#include <string>
#include <thread>
#include <unistd.h>
class Thread : NonCopyable {
public:
  // 线程函数
  using ThreadFunc = std::function<void()>;
  ~Thread();
  Thread(ThreadFunc func, std::string name="新xainc") ;
  void join();
  void detach();
  void start();
  pid_t getId() {
    return m_threadId;
  }

private:
  bool m_started;
  bool m_joined;
  std::shared_ptr<std::thread> m_thread;
  pid_t m_threadId;
  ThreadFunc m_func;
  std::string m_threadName;
};