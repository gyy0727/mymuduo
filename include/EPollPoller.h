/*
 * @Author: Gyy0727 3155833132@qq.com
 * @Date: 2023-11-21 19:06:19
 * @LastEditors: Gyy0727 3155833132@qq.com
 * @LastEditTime: 2024-03-26 13:53:22
 * @FilePath: /桌面/myModuo/include/EPollPoller.h
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置
 * 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#pragma once
/**
 * IO Multiplexing with epoll(7).
 */
#include "../include/Poller.h"
#include "../include/TimeStamp.h"

#include <memory>
#include <sys/epoll.h>
#include <vector>
class EPollPoller : public Poller {
public:
  using EPollPollerPtr = std::shared_ptr<EPollPoller>;
  EPollPoller(EventLoop *loop);
  ~EPollPoller() override;
  int poll(int timeout, ChannelList &activechannels) override;
  void updateChannel(Channel *channel) override;
  void removeChannel(Channel *channel) override;

private:
  static const int kInitEventListSize = 16;

  void fillActiveChannels(int numEvents, ChannelList &activeChannels) const;
  void update(int operation, Channel *channel);

  using EventList = std::vector<epoll_event>;

  int m_epollfd;
  EventList m_rtevents;
};