/*
 * @Author: Gyy0727 3155833132@qq.com
 * @Date: 2023-11-21 19:06:25
 * @LastEditors: Gyy0727 3155833132@qq.com
 * @LastEditTime: 2024-04-01 14:08:46
 * @FilePath: /桌面/myModuo/src/EPollPoller.cc
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置
 * 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#include "../include/EPollPoller.h"
#include "../include/Channel.h"
#include "../include/Logger.h"
#include <errno.h>
#include <strings.h>
#include <sys/epoll.h>
#include <unistd.h>

// channel未添加到poller中
const int kNew = -1; // channel的成员index_ = -1
// channel已添加到poller中
const int kAdded = 1;
// channel从poller中删除
const int kDeleted = 2;
EPollPoller::EPollPoller(EventLoop *loop)
    : Poller(loop), m_epollfd(::epoll_create1(EPOLL_CLOEXEC)),
      m_rtevents(kInitEventListSize) {
  if (m_epollfd < 0) {
    LOG_FATAL(LOG_ROOT()) << "epoll_create error: " << errno;
  }
}

EPollPoller::~EPollPoller() { ::close(m_epollfd); }

int EPollPoller::poll(int timeout, ChannelList &activechannels) {
  LOG_DEBUG(LOG_ROOT()) << "fd total count: " << m_channels.size();
  int rt = epoll_wait(m_epollfd, &*m_rtevents.begin(),
                      static_cast<int>(m_rtevents.size()), timeout);
  int saveErrno = errno;
  TimeStamp now;
  if (rt > 0) {
    LOG_INFO(LOG_ROOT()) << "events happend ";
    if (rt == (int)activechannels.size()) {
      activechannels.resize(1.5 * activechannels.size());
    }
    fillActiveChannels(rt, activechannels);
    return rt;
  } else if (rt == 0) {
    LOG_INFO(LOG_ROOT()) << "epoll_wait time_outs";
    return rt;
  } else {
    if (saveErrno != EINTR) {
      errno = saveErrno;
      LOG_ERROR(LOG_ROOT()) << "EPollPoller::poll() err!";
    }
    return rt;
  }
  return rt;
}

void EPollPoller::updateChannel(Channel *channel) {
  const int index = channel->getIndex();
  LOG_INFO(LOG_ROOT()) << "event " << channel->getfd() << "  add ";
  if (index == kNew || index == kDeleted) {
    if (index == kNew) {
      channel->set_index(kAdded);
      m_channels[channel->getfd()]=channel;
    }
    update(EPOLL_CTL_ADD, channel);
  } else {

    if (channel->isNoneEvent()) {
      update(EPOLL_CTL_DEL, channel);
      channel->set_index(kDeleted);
    } else {
      update(EPOLL_CTL_MOD,channel);
    }
  }
}
void EPollPoller::removeChannel(Channel *channel) {
  int fd = channel->getfd();
  m_channels.erase(fd);
  if (channel->getIndex() == kAdded) {
    channel->set_index(kDeleted);
    update(EPOLL_CTL_DEL, channel);
  }
}

void EPollPoller::fillActiveChannels(int numEvents,
                                     ChannelList &activeChannels) const {
  for (int i = 0; i < numEvents; i++) {
    Channel *channel = static_cast<Channel *>(m_rtevents[i].data.ptr);
    channel->setRtEvent(m_rtevents[i].events);
    activeChannels.push_back(channel);
  }
}

void EPollPoller::update(int operation, Channel *channel) {
  epoll_event event;
  memset(&event, 0, sizeof(event));
  int fd = channel->getfd();
  event.events = channel->getEvents();
  event.data.fd = fd;
  event.data.ptr = channel;
  if (epoll_ctl(m_epollfd, operation, fd, &event) < 0) {
    if (operation == EPOLL_CTL_ADD) {
      LOG_FATAL(LOG_ROOT()) << "epoll_ctl_add error: " << errno;
    } else {
      LOG_FATAL(LOG_ROOT()) << "epoll_ctl_delete error: " << errno;
    }
  }
}
