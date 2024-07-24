#pragma once

#include "NonCopyable.h"
#include <algorithm>
#include <cstddef>
#include <string>
#include <vector>

// *为什么需要有应用层缓冲区？
// *non-blocking网络编程中，non-blockingIO核心思想是避免阻塞在read()/write()或其他IO系统调用上，可以最大限度复用thread-of-control，让一个线程能服务于多个socket连接。而IO线程只能阻塞在IO-multiplexing函数上，如select()/poll()/epoll_wait()，这样应用层的缓冲区就是必须的，每个TCP
// *socket都要有stateful的input buffer和output buffer。
// *具体来说，
// *TcpConnection必须要有output buffer
// *一个常见场景：程序想通过TCP连接发送100K
// *byte数据，但在write()调用中，OS只接收80K（受TCP通告窗口advertised
// *window的控制），而程序又不能原地阻塞等待，事实上也不知道要等多久。程序应该尽快交出控制器，返回到event
// *loop。此时，剩余20K数据怎么办？
// *对应用程序，它只管生成数据，不应该关系到底数据是一次发送，还是分几次发送，这些应该由网络库操心，程序只需要调用TcpConnection::send()就行。网络库应该接管剩余的20K数据，把它保存到TcpConnection的output
// *buffer，然后注册POLLOUT事件，一旦socket变得可写就立刻发送数据。当然，第二次不一定能完全写入20K，如果有剩余，网络库应该继续关注POLLOUT事件；如果写完20K，网络库应该停止关注POLLOUT，以免造成busy
// *loop。
// *如果程序又写入50K，而此时output
// *buffer里还有待发20K数据，那么网络库不应该直接调用write()，而应该把这50K数据append到那20K数据之后，等socket变得可写时再一并写入。
// *如果output
// *buffer里还有待发送数据，而程序又想关闭连接，但对程序而言，调用TcpConnection::send()后就认为数据迟早会发出去，此时网络库不应该直接关闭连接，而要等数据发送完毕。因为此时数据可能还在内核缓冲区中，并没有通过网卡成功发送给接收方。
// *将数据append到buffer，甚至write进内核，都不代表数据成功发送给对端。
//* 综上，要让程序在write操作上不阻塞，网络库必须给每个tcp connection配置output
//* buffer。

class Buffer : NonCopyable {
public:
  static const size_t kCheapPrepend = 8;
  static const size_t kInitialSize = 1024;

  explicit Buffer(size_t initsize = kInitialSize)
      : m_buffer(kCheapPrepend + kInitialSize), m_readerIndex(kCheapPrepend),
        m_writerIndex(kCheapPrepend) {}

  //* 返回可读的字节长度
  size_t readableBytes() const { return m_writerIndex - m_readerIndex; }

  //* 返回可读的字节长度
  size_t writableBytes() const { return m_buffer.size() - m_writerIndex; }

  //* 返回的前置缓冲区字节长度
  size_t prependableBytes() const { return m_readerIndex; }

  //* 返回缓冲区中可读数据的起始地址
  const char *peek() const { return begin() + m_readerIndex; }

  //* 读取一部分字节
  void retrieve(size_t len) {
    if (len < readableBytes()) {
      m_readerIndex +=
          len; // 应用只读取了刻度缓冲区数据的一部分，就是len，还剩下readerIndex_
               // += len -> writerIndex_
    } else     // len == readableBytes()
    {
      retrieveAll();
    }
  }

  //* 读取全部字节
  void retrieveAll() { m_readerIndex = m_writerIndex = kCheapPrepend; }

  std::string retrieveAllAsString() {
    return retrieveAsString(readableBytes()); // 应用可读取数据的长度
  }

  std::string retrieveAsString(size_t len) {
    std::string result(peek(), len);
    //* 上面一句把缓冲区中可读的数据，已经读取出来，这里肯定要对缓冲区进行复位操作
    retrieve(len);
    return result;
  }

  void ensureWriteableBytes(size_t len) {
    if (writableBytes() < len) {
      makeSpace(len); // 扩容函数
    }
  }

  // 把[data, data+len]内存上的数据，添加到writable缓冲区当中
  void append(const char *data, size_t len) {
    ensureWriteableBytes(len);
    std::copy(data, data + len, beginWrite());
    m_writerIndex += len;
  }

  char *beginWrite() { return begin() + m_writerIndex; }

  const char *beginWrite() const { return begin() + m_writerIndex; }

  // 从fd上读取数据
  ssize_t readFd(int fd, int *saveErrno);
  // 通过fd发送数据
  ssize_t writeFd(int fd, int *saveErrno);

private:
  char *begin() {
    // it.operator*()
    return &*m_buffer.begin();
  }
  const char *begin() const { return &*m_buffer.begin(); }

  void makeSpace(size_t len) {
    if (writableBytes() + prependableBytes() < len + kCheapPrepend) {
      m_buffer.resize(m_writerIndex + len);
    } else {
      size_t readalbe = readableBytes();
      std::copy(begin() + m_readerIndex, begin() + m_writerIndex,
                begin() + kCheapPrepend);
      m_readerIndex = kCheapPrepend;
      m_writerIndex = m_readerIndex + readalbe;
    }
  }
  std::vector<char> m_buffer;
  size_t m_readerIndex;
  size_t m_writerIndex;
};