#include "Window.hpp"
#include "Mouse.hpp"

namespace SFML {
    bool Mouse::isButtonPressed(Mouse::Button button) {
        return (sf::Mouse::isButtonPressed((sf::Mouse::Button)button));
    }
    Vector2i Mouse::getDesktopPosition() {
        return (sf::Mouse::getPosition());
    }
    Vector2i Mouse::getWindowPosition(const std::shared_ptr<Window> &window) {
        return (sf::Mouse::getPosition(window->getWindow()));
    }
    void Mouse::setDesktopPosition(const Vector2i &position) {
        return (sf::Mouse::setPosition(position.getVector2()));
    }
    void Mouse::setWindowPosition(const Vector2i &position, const std::shared_ptr<Window> &window) {
        return (sf::Mouse::setPosition(position.getVector2(), window->getWindow()));
    }
};