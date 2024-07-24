/*
 * @Author: Gyy0727 3155833132@qq.com
 * @Date: 2024-03-27 16:13:59
 * @LastEditors: Gyy0727 3155833132@qq.com
 * @LastEditTime: 2024-03-27 20:05:46
 * @FilePath: /muduo/src/Fiber.cc
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置
 * 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#include "../include/Fiber.h"
#include "../include/Logger.h"
#include "stdlib.h"
#include <atomic>
#include <cstddef>
#include <cstdlib>
#include <ucontext.h>
static std::atomic<uint64_t> s_fiber_id{0};
static std::atomic<uint64_t> s_fiber_count{0};

static thread_local Fiber *t_fiber = nullptr;
static thread_local Fiber::ptr t_threadFiber = nullptr;

class Malloctor {
public:
  static void *Alloc(size_t size) { return malloc(size); }
  static void Dealloc(void *vp) { return free(vp); }
};

Fiber::Fiber() {
  m_state = EXEC;
  SetThis(this);
  getcontext(&m_context);
  ++s_fiber_count;
}
uint64_t Fiber::getFiberId()const {
  return m_id;
}

Fiber::Fiber(std::function<void()> cb, size_t stacksize, bool runInScheduler)
    : m_id(++s_fiber_id), m_func(cb) {
  ++s_fiber_count;
  m_stackSize = stacksize ? stacksize : 128 * 1024;
  m_stack = Malloctor::Alloc(m_stackSize);
  getcontext(&m_context);
  m_context.uc_link = nullptr;
  m_context.uc_stack.ss_sp = m_stack;
  m_context.uc_stack.ss_size = m_stackSize;
  makecontext(&m_context, &Fiber::MainFunc, 0);
  LOG_DEBUG(LOG_ROOT()) << "Fiber::Fiber id=" << m_id;
}

Fiber::~Fiber() {
  --s_fiber_count;
  if (m_stack) {
    Malloctor::Dealloc(m_stack);
  } else {
    Fiber *cur = t_fiber;
    if (cur == this) {
      SetThis(nullptr);
    }
  }
}

void Fiber::reset(std::function<void()> cb) {
  m_func = cb;
  m_context.uc_link = nullptr;
  m_context.uc_stack.ss_sp = m_stack;
  m_context.uc_stack.ss_size = m_stackSize;
  makecontext(&m_context, &Fiber::MainFunc, 0);
  m_state = INIT;
}

void Fiber::swapIn() {
  SetThis(this);
  m_state = EXEC;
  if (m_runInScheduler) {
    swapcontext(&t_threadFiber->m_context, &m_context);

  } else {
    swapcontext(&t_threadFiber->m_context, &m_context);
  }
}

void Fiber::swapOut() {
  SetThis(this);
  m_state = EXIT;
  if (m_runInScheduler) {
    swapcontext(&m_context, &t_threadFiber->m_context);

  } else {
    swapcontext(&m_context, &t_threadFiber->m_context);
  }
}

void Fiber::SetThis(Fiber *f) { t_fiber = f; }

Fiber::ptr Fiber::GetThis() {
  if (t_fiber) {
    return t_fiber->shared_from_this();
  }
  Fiber::ptr main_fiber(new Fiber);
  t_threadFiber = main_fiber;
  return t_fiber->shared_from_this();
}

uint64_t Fiber::TotalFibers() { return s_fiber_count; }

void Fiber::MainFunc() {
  Fiber::ptr cur = GetThis();
  try {
    cur->m_func();
    cur->m_func = nullptr;
  } catch (std::exception &ex) {
    cur->m_state = EXCEPT;
    LOG_ERROR(LOG_ROOT()) << "Fiber Except: " << ex.what()
                          << " fiber_id=" << cur->getFiberId() << std::endl;
  } catch (...) {
    cur->m_state = EXCEPT;
    LOG_ERROR(LOG_ROOT()) << "Fiber Except"
                          << " fiber_id=" << cur->getFiberId() << std::endl;
  }

  auto raw_ptr = cur.get();
  cur.reset();
  raw_ptr->swapOut();
}
