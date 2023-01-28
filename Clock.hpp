#pragma once

#include <SFML/System/Clock.hpp>
#include "Time.hpp"

namespace SFML {
    class Clock {
    public:
        Time getElapsedTime() const {
            return (clock.getElapsedTime());
        }
        Time restart() {
            return (clock.restart());
        }
    private:
        sf::Clock clock;
    };
}
