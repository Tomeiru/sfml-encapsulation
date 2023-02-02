#pragma once

#include <SFML/Window/Joystick.hpp>

namespace SFML {
    /**
     * @brief A encapsulation of sf::Joystick
     */
    class Joystick {
    public:
        /**
         * @brief The axis of the joystick
         */
        enum Axis {
            X = sf::Joystick::X,
            Y = sf::Joystick::Y,
            Z = sf::Joystick::Z,
            R = sf::Joystick::R,
            U = sf::Joystick::U,
            V = sf::Joystick::V,
            PovX = sf::Joystick::PovX,
            PovY = sf::Joystick::PovY,
        };
        /**
         * @brief Check if a joystick is connected
         * 
         * @param joystick The joystick id
         * @return true The joystick is connected
         * @return false The joystick is not connected
         */
        static bool isConnected(std::uint32_t joystick) {
            return (sf::Joystick::isConnected(joystick));
        }
        /**
         * @brief Check if a joystick button is pressed
         * 
         * @param joystick The joystick id
         * @param button The button to check
         * @return true The button is pressed
         * @return false The button is not pressed
         */
        static bool isButtonPressed(std::uint32_t joystick, std::uint32_t button) {
            return (sf::Joystick::isButtonPressed(joystick, button));
        }
        /**
         * @brief Get the position of a joystick axis
         * 
         * @param joystick The joystick id
         * @param axis The axis to check
         * @return float The position of the axis
         */
        static float getAxisPosition(std::uint32_t joystick, Axis axis) {
            return (sf::Joystick::getAxisPosition(joystick, (sf::Joystick::Axis)axis));
        }
        /**
         * @brief Update the state of all joysticks
         * 
         * @return true The state of all joysticks was updated
         * @return false The state of all joysticks was not updated
         */
        static bool update() {
            return (update());
        }
    };
}
