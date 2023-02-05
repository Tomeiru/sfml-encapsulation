#pragma once

#include "Vector2.hpp"
#include <SFML/Window/Mouse.hpp>
#include <memory>

namespace SFML {
class Window;

/**
 * @brief A encapsulation of sf::Mouse
 */
class Mouse {
public:
    /**
     * @brief Mouse buttons enumeration
     */
    enum Button {
        Left = sf::Mouse::Left,
        Right = sf::Mouse::Right,
        Middle = sf::Mouse::Middle,
        XButton1 = sf::Mouse::XButton1,
        XButton2 = sf::Mouse::XButton2,
    };
    /**
     * @brief Mouse wheel enumeration
     */
    enum Wheel {
        VerticalWheel = sf::Mouse::VerticalWheel,
        HorizontalWheel = sf::Mouse::HorizontalWheel
    };
    /**
     * @brief Check if a mouse button is pressed
     *
     * @return true The button is pressed, false otherwise
     */
    static bool isButtonPressed(Button button);
    /**
     * @brief Get the current position of the mouse
     *
     * @return Vector2i The position of the mouse
     */
    static Vector2i getDesktopPosition();
    /**
     * @brief Get the current position of the mouse relative to a window
     *
     * @param window The window to get the position from
     * @return Vector2i The position of the mouse
     */
    static Vector2i getWindowPosition(const std::shared_ptr<Window>& window);
    /**
     * @brief Set the current position of the mouse
     *
     * @param position The new position of the mouse
     */
    static void setDesktopPosition(const Vector2i& position);
    /**
     * @brief Set the current position of the mouse relative to a window
     *
     * @param position The new position of the mouse
     * @param window The window to set the position to
     */
    static void setWindowPosition(const Vector2i& position, const std::shared_ptr<Window>& window);
};
}
