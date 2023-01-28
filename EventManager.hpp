#pragma once

#include <queue>
#include "Event.hpp"

namespace SFML {
    class EventManager {
    public:
        void newEvent(const sf::Event &event) {
            if (event.type >= sf::Event::TextEntered && event.type <= sf::Event::KeyReleased)
                keyboard_events.emplace_back(event);
            if (event.type >= sf::Event::MouseWheelMoved && event.type <= sf::Event::MouseLeft)
                mouse_events.emplace_back(event);
            if (event.type >= sf::Event::JoystickButtonPressed && event.type <= sf::Event::JoystickDisconnected)
                gamepad_events.emplace_back(event);
            if (event.type == sf::Event::Closed)
                quit = true;
        }
        bool quitEventRegistered() const {
            return (quit);
        }
        const std::vector<Event> &getKeyboardEvents() const {
            return (keyboard_events);
        }
        const std::vector<Event> &getMouseEvents() const {
            return (mouse_events);
        }
        const std::vector<Event> &getGamepadEvents() const {
            return (gamepad_events);
        }
        void clear() {
            keyboard_events.clear();
            mouse_events.clear();
            gamepad_events.clear();
            quit = false;
        }
    private:
        std::vector<Event> keyboard_events;
        std::vector<Event> mouse_events;
        std::vector<Event> gamepad_events;
        bool quit;
    };
}