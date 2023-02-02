#pragma once

#include <SFML/System/Time.hpp>
#include <cstdint>

namespace SFML {
    /**
     * @brief A encapsulation of sf::Time
     */
    class Time {
    public:
        /**
         * @brief Construct a new Time object
         * 
         * @param time The sf::Time to copy
         */
        Time(const sf::Time &time) : time(time) {}
        /**
         * @brief Get the Time object as seconds
         * 
         * @return const sf::Time& The time as seconds
         */
        float asSeconds() const {
            return time.asSeconds();
        }
        /**
         * @brief Get the Time object as milliseconds
         * 
         * @return const sf::Time& The time as milliseconds
         */
        std::int32_t asMilliseconds() const {
            return time.asMilliseconds();
        }
        /**
         * @brief Get the Time object as microseconds
         * 
         * @return const sf::Time& The time as microseconds
         */
        std::int64_t asMicroseconds() const {
            return time.asMicroseconds();
        }
    private:
        sf::Time time;
    };
}
