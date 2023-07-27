#pragma once
#ifndef __DATA_RESOURCE_SOCKCONF_HPP__
#define __DATA_RESOURCE_SOCKCONF_HPP__

#include "netstuff.hpp"

namespace inetpp {

/**
 * @brief 定义 socket 配置 (socket configuration definition)
 */
class Sockconf {
public:
    ipver_t ipver_;                                                     // IP 协议版本 (ip protocol version)
    socktype_t socktype_;                                               // socket 类型 (socket type)
    proto_t proto_;                                                     // 协议类型 (protocol)

    /**
     * @brief 默认构造
     * 默认 IPv4、流式 socket、TCP 协议
     * (default c'tor with ipv4, stream socket type, tcp protocol)
     */
    Sockconf();
    ~Sockconf();
};

} // end namespace inetpp

#endif
