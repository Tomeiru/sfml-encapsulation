#pragma once

#include <SFML/System/Time.hpp>
#include <cstdint>

namespace SFML {
    class Time {
    public:
        Time(const sf::Time &time) : time(time) {}
        float asSeconds() const {
            return time.asSeconds();
        }
        std::int32_t asMilliseconds() const {
            return time.asMilliseconds();
        }
        std::int64_t asMicroseconds() const {
            return time.asMicroseconds();
        }
    private:
        sf::Time time;
    };
}
