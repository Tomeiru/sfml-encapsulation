#pragma once

#include <SFML/Window/Mouse.hpp>
#include "Vector2.hpp"

namespace SFML {
    class Window;
    class Mouse {
    public:
        enum Button {
            Left = sf::Mouse::Left,
            Right = sf::Mouse::Right,
            Middle = sf::Mouse::Middle,
            XButton1 = sf::Mouse::XButton1,
            XButton2 = sf::Mouse::XButton2,
        };
        enum Wheel {
            VerticalWheel = sf::Mouse::VerticalWheel,
            HorizontalWheel = sf::Mouse::HorizontalWheel
        };
        static bool isButtonPressed(Button button);
        static Vector2i getDesktopPosition();
        static Vector2i getWindowPosition(const std::shared_ptr<Window> &window);
        static void setDesktopPosition(const Vector2i &position);
        static void setWindowPosition(const Vector2i &position, const std::shared_ptr<Window> &window);
    };
}
