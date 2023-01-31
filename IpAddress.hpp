#pragma once

#include <string>
#include <SFML/Network/IpAddress.hpp>

namespace SFML {
    class IpAddress {
    public:
        IpAddress(const std::string &address) : _address(address) {}
        IpAddress(std::uint32_t address) : _address(address) {}
        IpAddress(sf::IpAddress address) : _address(address) {}
        void setIpAddress(sf::IpAddress address) {
            _address = address;
        }
        const sf::IpAddress &getIpAdress() const {
            return (_address);
        }
        std::string toString() const {
            return (_address.toString());
        }
        std::uint32_t toInteger() const {
            return (_address.toInteger());
        }
        static IpAddress any() {
            return (sf::IpAddress::Any);
        }
        static IpAddress none() {
            return (sf::IpAddress::None);
        }
        static IpAddress localhost() {
            return (sf::IpAddress::LocalHost);
        }
        static IpAddress broadcast() {
            return (sf::IpAddress::Broadcast);
        }
    private:
        sf::IpAddress _address;
    };
}
