#pragma once

#include "IpAddress.hpp"
#include <SFML/Network/UdpSocket.hpp>

namespace SFML {
/**
 * @brief A encapsulation of sf::UdpSocket
 */
class UDPSocket {
public:
    /**
     * @brief UdpSocket status enumeration
     */
    enum Status {
        Done = sf::UdpSocket::Done,
        NotReady = sf::UdpSocket::NotReady,
        Partial = sf::UdpSocket::Partial,
        Disconnected = sf::UdpSocket::Disconnected,
        Error = sf::UdpSocket::Error,
    };
    /**
     * @brief Construct a new UDPSocket object
     */
    UDPSocket()
        : _socket()
    {
    }
    /**
     * @brief Bind the socket to a specific port and address
     *
     * @param port The port to bind the socket to
     * @param address The address to bind the socket to
     * @return Status The status of the binding
     */
    Status bind(std::uint32_t port, const IpAddress& address = IpAddress::any())
    {
        return (Status)(_socket.bind(port, address.getIpAdress()));
    }
    /**
     * @brief Unbind the socket
     */
    void unbind()
    {
        _socket.unbind();
    }
    /**
     * @brief Set the blocking state of the socket
     *
     * @param blocking The blocking state of the socket
     */
    void setBlocking(bool blocking)
    {
        return (_socket.setBlocking(blocking));
    }
    /**
     * @brief Send data to a specific address and port
     *
     * @param data The data to send
     * @param size The size of the data
     * @param address The address to send the data to
     * @param port The port to send the data to
     * @return Status The status of the sending
     */
    Status send(const void* data, std::size_t size, const IpAddress& address, uint16_t port)
    {
        return (Status)(_socket.send(data, size, address.getIpAdress(), port));
    }
    /**
     * @brief Receive data from a specific address and port
     *
     * @param data The data to receive
     * @param size The size of the data
     * @param received The size of the received data
     * @param address The address to receive the data from
     * @param port The port to receive the data from
     * @return Status The status of the receiving
     */
    Status receive(void* data, std::size_t size, std::size_t& received, IpAddress& address, uint16_t& port)
    {
        sf::IpAddress ip_address;
        Status status = (Status)_socket.receive(data, size, received, ip_address, port);
        address.setIpAddress(ip_address);
        return (status);
    }

private:
    sf::UdpSocket _socket;
};
}
