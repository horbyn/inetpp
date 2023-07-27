#include "Socket.hpp"

namespace inetpp {

Socket::Socket(): sockfd_{-1} {
}

Socket::~Socket() {
    this->close();
}

Socket::Socket(Socket &&other): conf_(other.conf_), sockfd_(other.sockfd_) {
    other.sockfd_ = -1;
}

Socket &
Socket::operator=(Socket &&other) {
    if (this != &other) {
        this->conf_ = other.conf_;
        this->sockfd_ = other.sockfd_;
        other.sockfd_ = -1;
    }
    return *this;
}

bool
Socket::is_open() const {
    return (this->sockfd_ != -1);
}

int
Socket::open() {
    if (-1 == ::socket(
        MACRO_IPVER(this->conf_.ipver_),
        MACRO_SOCKTYPE(this->conf_.socktype_),
        MACRO_PROTO(this->conf_.proto_)
    ))    return errno;
    else    return 0;
}

int
Socket::reopen() {
    int err = this->close();
    if (err != 0)    return err;

    return this->open();
}

int
Socket::close() {
    if ((this->sockfd_ != -1) && (::close(this->sockfd_) == -1))
        return errno;

    this->sockfd_ = -1;
    return 0;
}

} // end namespace inetpp
