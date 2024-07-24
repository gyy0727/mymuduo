/*
 * @Author: Gyy0727 3155833132@qq.com
 * @Date: 2023-11-21 18:55:39
 * @LastEditors: Gyy0727 3155833132@qq.com
 * @LastEditTime: 2024-03-26 16:37:13
 * @FilePath: /桌面/myModuo/include/Poller.h
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置
 * 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#pragma once
/**
 * IO Multiplexing Interface
 * Support poll(2), epoll(7)
 *
 * Only owner EventLoop IO thread can invoke it, so thread safe is not
 * necessary.
 */
/**
 * IO复用接口
 * 禁止编译器生成copy构造函数和copy assignment
 * 支持poll(2), epoll(7)
 */
#pragma once


#include "NonCopyable.h"
#include "TimeStamp.h"
#include <unordered_map>
#include <vector>
class Channel;
class EventLoop;

// muduo库中多路事件分发器的核心IO复用模块
class Poller : NonCopyable {
public:
  Poller();
  using ChannelList = std::vector<Channel*>;
  Poller(EventLoop* loop);
  virtual ~Poller()=default;
  virtual void updateChannel(Channel *channel)=0;
  virtual void removeChannel(Channel *channel)=0;
  virtual int  poll(int Timeout, ChannelList &activechannels) = 0;
  bool hasChannel(Channel* channel) const;
  // static Poller &newDafaultPoller(EventLoop* loop);

protected:
  using ChannelMap = std::unordered_map<int, Channel*>;
  ChannelMap m_channels;
  private:
    EventLoop* m_ownerLoop;
};