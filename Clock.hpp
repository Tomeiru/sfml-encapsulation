#pragma once

#include "Time.hpp"
#include <SFML/System/Clock.hpp>

namespace SFML {
/**
 * @brief A encapsulation of sf::Clock
 */
class Clock {
public:
    /**
     * @brief Get the elapsed time
     * @return The elapsed time
     */
    Time getElapsedTime() const
    {
        return (clock.getElapsedTime());
    }
    /**
     * @brief Restart the clock
     * @return The elapsed time
     */
    Time restart()
    {
        return (clock.restart());
    }

private:
    sf::Clock clock;
};
}
