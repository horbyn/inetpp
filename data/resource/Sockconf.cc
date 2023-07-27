#include "Sockconf.hpp"

namespace inetpp {

Sockconf::Sockconf() : ipver_(ipver_t::IPV4), socktype_(socktype_t::STREAM), proto_(proto_t::TCP) {
}

Sockconf::~Sockconf() {
}

} // end namespace inetpp
