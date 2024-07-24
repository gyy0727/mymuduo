/*
 * @Author: Gyy0727 3155833132@qq.com
 * @Date: 2024-03-24 16:47:56
 * @LastEditors: Gyy0727 3155833132@qq.com
 * @LastEditTime: 2024-03-27 15:48:13
 * @FilePath: /muduo/include/TimeStamp.h
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置
 * 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#pragma once
#include "TimeStamp.h"
#include <chrono>
#include <cstdint>
#include <ctime>
#include <iostream>
#include <ostream>
#include <string>
#include <time.h>
class TimeStamp {
public:
  TimeStamp() {
    m_time = time(NULL);
    std::chrono::system_clock::time_point now =
        std::chrono::system_clock::now();

    // 将时间点转换为毫秒数
    std::chrono::milliseconds duration =
        std::chrono::duration_cast<std::chrono::milliseconds>(
            now.time_since_epoch());
    // long long millis = duration.count();
    // std::cout << "Current time in milliseconds: " << millis << std::endl;
  }

  std::string timeToString() const {
    struct tm *info;
    info = localtime(&m_time);
    char buffer[80];
    strftime(buffer, 80, "%Y-%m-%d %H:%M:%S", info);
    return buffer;
  }

private:
  time_t m_time;
  long long m_timems;
};
