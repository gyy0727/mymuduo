/*
 * @Author: Gyy0727 3155833132@qq.com
 * @Date: 2024-03-24 16:47:56
 * @LastEditors: Gyy0727 3155833132@qq.com
 * @LastEditTime: 2024-03-29 12:29:33
 * @FilePath: /muduo/include/InetAddress.h
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%A
 */
/*
 * @Author: Gyy0727 3155833132@qq.com
 * @Date: 2023-11-21 14:31:48
 * @LastEditors: Gyy0727 3155833132@qq.com
 * @LastEditTime: 2023-11-21 16:03:08
 * @FilePath: /桌面/myModuo/include/InetAddress.h
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#pragma once
#include <arpa/inet.h>
#include <cstdint>
#include <netinet/in.h>
#include <string>
class InetAddress
{
public:
    explicit InetAddress(uint16_t port = 0, std::string ip = "127.0.0.1");
    explicit InetAddress(const sockaddr_in &addr)
        : addr_(addr)
    {}

    std::string toIp() const;
    std::string toIpPort() const;
    uint16_t toPort() const;

    const sockaddr_in* getSockAddr() const {return &addr_;}
    void setSockAddr(const sockaddr_in &addr) { addr_ = addr; }
private:
    sockaddr_in addr_;
};