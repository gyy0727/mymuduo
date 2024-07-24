/*
 * @Author: Gyy0727 3155833132@qq.com
 * @Date: 2024-03-27 16:13:44
 * @LastEditors: Gyy0727 3155833132@qq.com
 * @LastEditTime: 2024-03-27 19:12:09
 * @FilePath: /muduo/include/Fiber.h
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置
 * 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#include <cstdint>
#include <functional>
#include <memory>
#include <sys/ucontext.h>
#include <ucontext.h>
#include "NonCopyable.h"
#include "json.hpp"


class Fiber : NonCopyable,public enable_shared_from_this<Fiber> {
public:
  using ptr = std::shared_ptr<Fiber>;
  enum STATE { INIT, EXEC, HOLD, EXIT, EXCEPT };

  Fiber();

    Fiber(std::function<void()> cb, size_t stacksize = 128*1024, bool runInScheduler = false);

  
    ~Fiber();
 
    void reset(std::function<void()> cb);

    void swapIn();

    void swapOut();

    uint64_t getFiberId() const ;

    STATE getState() const { return m_state;}
public:

    static void SetThis(Fiber* f);

    static Fiber::ptr GetThis();

    static uint64_t TotalFibers();


    static void MainFunc();


private:
  uint64_t m_id = 0;
  uint64_t m_stackSize = 0;
  STATE m_state = INIT;
  ucontext_t m_context;
  void *m_stack = nullptr;
  std::function<void()> m_func;
  bool m_runInScheduler;
  
};