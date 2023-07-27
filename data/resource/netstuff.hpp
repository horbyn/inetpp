#pragma once
#ifndef __DATA_RESOURCE_NETSTUFF_HPP__
#define __DATA_RESOURCE_NETSTUFF_HPP__

#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>

namespace inetpp {

/**
 * @brief IP 协议版本枚举 (IP version enum)
 */
enum class ipver_t {
    IPV4 = 0,
    IPV6
};
#define MACRO_IPVER(e) \
    ((e) == ipver_t::IPV4 ? AF_INET :  \
     (e) == ipver_t::IPV6 ? AF_INET6 : \
     AF_UNSPEC)

/**
 * @brief socket 类型枚举 (socket type enum)
 */
enum class socktype_t {
    RAW = 0,                                                            // 三层 (layer-3)
    STREAM,                                                             // 四层流式 (stream of layer-4)
    DGRAM                                                               // 四层数据报 (datagram of layer-4)
};
#define MACRO_SOCKTYPE(e) \
    ((e) == socktype_t::RAW ? SOCK_RAW :       \
     (e) == socktype_t::DGRAM ? SOCK_DGRAM :   \
     SOCK_STREAM)

/**
 * @brief 协议枚举 (protocol enum)
 */
enum class proto_t {
    TCP = 0,
    UDP
};
#define MACRO_PROTO(e) \
    ((e) == proto_t::TCP ? IPPROTO_TCP : \
     (e) == proto_t::UDP ? IPPROTO_UDP : \
     IPPROTO_IP)

} // end namespace inetpp

#endif
