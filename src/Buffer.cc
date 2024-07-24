/*
 * @Author: Gyy0727 3155833132@qq.com
 * @Date: 2023-12-02 18:56:07
 * @LastEditors: Gyy0727 3155833132@qq.com
 * @LastEditTime: 2024-04-01 13:47:12
 * @FilePath: /sylar/home/muqiu0614/桌面/myModuo/src/Buffer.cc
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置
 * 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#include "../include/Buffer.h"
#include "../include/Logger.h"
#include <cstddef>
#include <errno.h>
#include <sys/uio.h>
#include <unistd.h>

// 从fd上读取数据
ssize_t Buffer::readFd(int fd, int *saveErrno) {
  char buf[65536] = {0};
  struct iovec vec[2];
  const size_t writeable = writableBytes();
  vec[0].iov_base = begin() + m_writerIndex;
  vec[0].iov_len = writeable;

  vec[1].iov_base = buf;
  vec[1].iov_len = sizeof buf;
  const int iovcnt = (writeable < sizeof buf) ? 2 : 1;
  const size_t n = ::readv(fd, vec, iovcnt);
  if (n < 0) {
    *saveErrno = errno;
  } else if (n <= writeable) // Buffer的可写缓冲区已经够存储读出来的数据了
  {
    m_writerIndex += n;
  } else // extrabuf里面也写入了数据
  {
    m_writerIndex = m_buffer.size();
    append(buf, n - writeable); // writerIndex_开始写 n - writable大小的数据
  }

  return n;
}

// 通过fd发送数据
ssize_t Buffer::writeFd(int fd, int *saveErrno) {
  size_t n = ::write(fd, peek(), readableBytes());
  *saveErrno = errno;
  if (n < 0) {
    LOG_FATAL(LOG_ROOT()) << "buffer wirteFd error : " << saveErrno;
  }
  return n;
}