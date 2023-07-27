#pragma once
#ifndef __INETSOCK_SOCKET_HPP__
#define __INETSOCK_SOCKET_HPP__

#include "data/resource/Sockconf.hpp"
#include <unistd.h>                                                     // ::close()
#include <errno.h>

namespace inetpp {

/**
 * @brief 定义一个 socket base 类：负责维护 socket fd，负责打开关闭 fd
 * (a basing socket class that holds fd and the operations on opening and closing)
 */
class Socket {
private:
    Sockconf conf_;                                                     // 配置信息 (configuration info)
    int sockfd_;                                                        // socket fd

public:
    Socket();
    virtual ~Socket();

    Socket(Socket &&other);
    Socket &operator=(Socket &&other);

    Socket(const Socket &) = delete;
    Socket &operator=(const Socket &) = delete;

    /**
     * @brief 判断 socket fd 是否已打开 (whether socket fd opens)
     * @retval true 已打开 (opened)
     * @retval false 关闭 (closed)
     */
    bool is_open() const;
    /**
     * @brief 打开 socket fd (open socket fd)
     * @return errno 变量 (errno variable)
     */
    int open();
    /**
     * @brief 重新打开 socket fd (reopen socket fd)
     * @return errno 变量 (errno variable)
     */
    int reopen();
    /**
     * @brief 关闭 socket fd，不验证 socket fd 是否有效
     * (close socket fd regardless of whether it is valid or not)
     * @return errno 变量 (errno variable)
     */
    int close();
};

} // end namespace inetpp

#endif
