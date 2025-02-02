/*
 * @Author: Gyy0727 3155833132@qq.com
 * @Date: 2023-11-21 18:55:47
 * @LastEditors: Gyy0727 3155833132@qq.com
 * @LastEditTime: 2024-03-26 16:30:55
 * @FilePath: /桌面/myModuo/src/Poller.cc
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置
 * 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#include "../include/Poller.h"
#include "../include/Channel.h"
// 将Poller和事件循环绑定
Poller::Poller(EventLoop* loop) : m_ownerLoop(loop) {}
bool Poller::hasChannel(Channel* channel) const {
  auto it = m_channels.find(channel->getfd());
  return it != m_channels.end() && it->second == channel;
}