#pragma once

#include <string>
#include <SFML/Network/IpAddress.hpp>

namespace SFML {
    /**
     * @brief A encapsulation of sf::IpAddress
     */
    class IpAddress {
    public:
        /**
         * @brief Construct a new IpAddress object
         * 
         * @param address The address as string
         */
        IpAddress(const std::string &address) : _address(address) {}
        /**
         * @brief Construct a new IpAddress object
         * 
         * @param address The address as unsigned integer
         */
        IpAddress(std::uint32_t address) : _address(address) {}
        /**
         * @brief Construct a new IpAddress object
         * 
         * @param address The address as sf::IpAddress
         */
        IpAddress(sf::IpAddress address) : _address(address) {}
        /**
         * @brief Set the IpAddress object
         * 
         * @return const sf::IpAddress& The address
         */
        void setIpAddress(sf::IpAddress address) {
            _address = address;
        }
        /**
         * @brief Get the IpAddress object
         * 
         * @return const sf::IpAddress& The address
         */
        const sf::IpAddress &getIpAdress() const {
            return (_address);
        }
        /**
         * @brief Get the IpAddress object as string
         * 
         * @return const std::string& The address as string
         */
        std::string toString() const {
            return (_address.toString());
        }
        /**
         * @brief Get the IpAddress object as unsigned integer
         * 
         * @return std::uint32_t The address as unsigned integer
         */
        std::uint32_t toInteger() const {
            return (_address.toInteger());
        }
        /**
         * @brief Get a sf::IpAddress::Any object
         * 
         * @return IpAddress The sf::IpAddress::Any object
         */
        static IpAddress any() {
            return (sf::IpAddress::Any);
        }
        /**
         * @brief Get a sf::IpAddress::None object
         * 
         * @return IpAddress The sf::IpAddress::None object
         */
        static IpAddress none() {
            return (sf::IpAddress::None);
        }
        /**
         * @brief Get a sf::IpAddress::LocalHost object
         * 
         * @return IpAddress The sf::IpAddress::LocalHost object
         */
        static IpAddress localhost() {
            return (sf::IpAddress::LocalHost);
        }
        /**
         * @brief Get a sf::IpAddress::Broadcast object
         * 
         * @return IpAddress The sf::IpAddress::Broadcast object
         */
        static IpAddress broadcast() {
            return (sf::IpAddress::Broadcast);
        }
    private:
        sf::IpAddress _address;
    };
}
