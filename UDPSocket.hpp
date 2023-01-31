#pragma once

#include <SFML/Network/UdpSocket.hpp>
#include "IpAddress.hpp"

namespace SFML {
    class UDPSocket {
    public:
        enum Status {
            Done = sf::UdpSocket::Done,
            NotReady = sf::UdpSocket::NotReady,
            Partial = sf::UdpSocket::Partial,
            Disconnected = sf::UdpSocket::Disconnected,
            Error = sf::UdpSocket::Error,
        };
        UDPSocket() : _socket() {}
        Status bind(std::uint32_t port, const IpAddress &address = IpAddress::any()) {
            return (Status)(_socket.bind(port, address.getIpAdress()));
        }
        void unbind() {
            _socket.unbind();
        }
        void setBlocking(bool blocking) {
            return (_socket.setBlocking(blocking));
        }
        Status send(const void *data, std::size_t size, const IpAddress &address, uint16_t port) {
            return (Status)(_socket.send(data, size, address.getIpAdress(), port));
        }
        Status receive(void *data, std::size_t size, std::size_t &received, IpAddress &address, uint16_t &port) {
            sf::IpAddress ip_address;
            Status status = (Status)_socket.receive(data, size, received, ip_address, port);
            address.setIpAddress(ip_address);
            return (status);
        }
    private:
        sf::UdpSocket _socket;
    };
}
