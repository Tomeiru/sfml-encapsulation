#pragma once

#include <SFML/Window/Joystick.hpp>

namespace SFML {
    class Joystick {
    public:
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
        static bool isConnected(std::uint32_t joystick) {
            return (sf::Joystick::isConnected(joystick));
        }
        static bool isButtonPressed(std::uint32_t joystick, std::uint32_t button) {
            return (sf::Joystick::isButtonPressed(joystick, button));
        }
        static float getAxisPosition(std::uint32_t joystick, Axis axis) {
            return (sf::Joystick::getAxisPosition(joystick, (sf::Joystick::Axis)axis));
        }
        static bool update() {
            return (update());
        }
    };
}
