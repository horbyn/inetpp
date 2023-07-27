#pragma once
#ifndef __INETSOCK_INETSOCK_HPP__
#define __INETSOCK_INETSOCK_HPP__

#include "Socket.hpp"

namespace inetpp {

/**
 * @brief 以太网 socket 地址信息类：负责维护地址信息
 * (a class about ethernet socket address info that holds address info)
 */
class Inetsock : public Socket {
private:
    struct sockaddr_storage ss_;                                        // 地址信息 (addr info)

public:
    Inetsock();
    ~Inetsock();

};

} // end namespace inetpp

#endif
