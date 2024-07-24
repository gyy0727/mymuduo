/*
 * @Author: Gyy0727 3155833132@qq.com
 * @Date: 2024-03-22 15:17:46
 * @LastEditors: Gyy0727 3155833132@qq.com
 * @LastEditTime: 2024-04-03 20:59:05
 * @FilePath: /sylar/home/muqiu0614/桌面/myModuo/src/test.cc
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置
 * 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#include "../include/EventLoop.h"
#include "../include/EventLoopThreadPool.h"
#include <unistd.h>

#if 0
#include "../include/EventLoop.h"
#include "../include/Logger.h"
#include "../include/Thread.h"
#include <functional>
#include <thread>
int main() {
  LOG_INFO(LOG_ROOT()) << " main start ";
  EventLoop loop;
  std::cout << " threadID  " << loop.getThreadId() << std::endl;

  Thread t(std::bind(&EventLoop::startLoop, &loop));
  t.start();
  sleep(10);
  std::function<void()> func0 = [&]() {
    LOG_DEBUG(LOG_ROOT()) << "I AM LOOPING "
                          << "is in thread " << loop.isInLoopThread()
                          << "  get threadID " << GetThreadId();
  };
  std::function<void()> func1 = [&]() {
    loop.runInLoop(func0);
    loop.quitLoop();
  };

  Thread t2(func1);
  t2.start();
  sleep(5);

  return 0;
}
#endif

#if 0
#include <iostream>
#include <stdio.h>
#include <string.h>
#include <ucontext.h>
struct ucontext_t test;
struct ucontext_t test1;
char stack[102400];
char stack1[102400];
int n = 0;
void testv();
int test4() {
  getcontext(&test);
  getcontext(&test1);
  printf("Test\n");
  if (n == 0) {
    test.uc_stack.ss_sp = stack;
    test.uc_stack.ss_size = 102400;
    test1.uc_stack.ss_sp = stack1;
    test1.uc_stack.ss_size = 102400;
    makecontext(&test1, &testv, 0);
    std::cout << " n  = " << n << std::endl;
    swapcontext(&test, &test1);
    std::cout << " n  = " << n << std::endl;
    // setcontext(&test1);
     n = 1;
    
   
  }
  std::cout << " n  = " << n << std::endl;
  return 0;
}
void testv() {
  printf("Hello World!\n");
  setcontext(&test);
}
int main() {
  test4();
  return 0;
}
#endif

#if 0
int main() {
  EventLoop loop;
  EventLoopThreadPool pool(&loop, 1);
  pool.startPool();
  sleep(20);
  return 0;
}
#endif
#if 0
#include <arpa/inet.h>
#include <stdio.h>
int main() {
  //创建一个 IP 字符串, 点分十进制的 IP地址 字符串
  char buf[] = "192.168.1.4";
  unsigned int num = 0;
  //将点分十进制 IP 字符串转换成 网络字节序的整数
  inet_pton(AF_INET, buf, &num);
  // unsigned char * p = (unsigned char *)&num;
  // // printf("%d %d %d %d\n", *p, *(p+1), *(p+2), *(p+3));//输出: 192 168 1
  // 4 cout << p << endl;
  //
  cout << "Network byte order: " << num << endl;
  unsigned int host_order_num = ntohl(num); // 转换为主机字节序
  cout << "Host byte order: " << host_order_num << endl;
  //将网络字节序的 IP 整数转换成 点分十进制的 IP字符串
  char ip[16] =
      ""; // 192(3)   .(1)    168(3)    .(1)    1(3)    .(1)    4(3)   终止符(1)
  const char *str = inet_ntop(AF_INET, &num, ip, 16); // 16 = sizeof(ip)
  cout << str << endl;
  return 0;
}
#endif
#include "../include/Logger.h"
#include "../include/TcpServer.h"

#include <functional>
#include <string>

class EchoServer {
public:
  EchoServer(EventLoop *loop, const InetAddress &addr, const std::string &name)
      : server_(loop, addr, name), loop_(loop) {
    // 注册回调函数
    server_.setConnectionCallback(
        std::bind(&EchoServer::onConnection, this, std::placeholders::_1));

    server_.setMessageCallback(
        std::bind(&EchoServer::onMessage, this, std::placeholders::_1,
                  std::placeholders::_2, std::placeholders::_3));

    // 设置合适的loop线程数量 loopthread
    server_.setThreadNum(3);
  }
  void start() { server_.start(); }

private:
  // 连接建立或者断开的回调
  void onConnection(const TcpConnectionPtr &conn) {
    if (conn->connected()) {
      LOG_INFO(LOG_ROOT()) << "Connection UP : "
                           << conn->getPeerAddress().toIpPort().c_str();
    } else {
      LOG_INFO(LOG_ROOT()) << "Connection DOWN : "
                           << conn->getPeerAddress().toIpPort().c_str();
    }
  }

  // 可读写事件回调
  void onMessage(const TcpConnectionPtr &conn, Buffer *buf, TimeStamp time) {
    string m = "HTTP/1.1 200 OK\r\n"
                           "Content-Type: application/json\r\n"
                           "Content-Length: 27\r\n"
                           "\r\n"
                           "hello world\r\n";
    std::string msg = buf->retrieveAllAsString();
    m = m + msg;
    conn->send(m);
    // 写端   EPOLLHUP =》 closeCallback_
  }

  TcpServer server_;
  EventLoop *loop_;
};

int main() {
  EventLoop loop;
  InetAddress addr(6006);
  EchoServer server(
      &loop, addr,
      "EchoServer-01"); // Acceptor non-blocking listenfd  create bind
  server
      .start(); // listen  loopthread  listenfd => acceptChannel => mainLoop =>
  loop.startLoop();  // 启动mainLoop的底层Poller

  return 0;
}
