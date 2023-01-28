#pragma once

#include <SFML/Window/Event.hpp>
#include "Keyboard.hpp"
#include "Mouse.hpp"
#include "Joystick.hpp"

namespace SFML {
    class Event {
    public:
        enum EventType {
            Closed = sf::Event::Closed,
            Resize = sf::Event::Resized,
            LostFocus = sf::Event::LostFocus,
            GainedFocus = sf::Event::GainedFocus,
            TextEntered = sf::Event::TextEntered,
            KeyPressed = sf::Event::KeyPressed,
            KeyReleased = sf::Event::KeyReleased,
            MouseWheelMoved = sf::Event::MouseWheelMoved,
            MouseWheelScrolled = sf::Event::MouseWheelScrolled,
            MouseButtonPressed = sf::Event::MouseButtonPressed,
            MouseButtonReleased = sf::Event::MouseButtonReleased,
            MouseMoved = sf::Event::MouseMoved,
            MouseEntered = sf::Event::MouseEntered,
            MouseLeft = sf::Event::MouseLeft,
            JoystickButtonPressed = sf::Event::JoystickButtonPressed,
            JoystickButtonReleased = sf::Event::JoystickButtonReleased,
            JoystickMoved = sf::Event::JoystickMoved,
            JoystickConnected = sf::Event::JoystickConnected,
            JoystickDisconnected = sf::Event::JoystickDisconnected,
        };

        struct SizeEvent
        {
            SizeEvent(const sf::Event::SizeEvent &event) : width(event.width), height(event.height) {}
            std::uint32_t width;
            std::uint32_t height;
        };

        struct KeyEvent
        {
            KeyEvent(const sf::Event::KeyEvent &event) : code((Keyboard::Key)event.code), alt(event.alt), control(event.control), shift(event.shift) , system(event.system) {}
            Keyboard::Key code;
            bool alt;
            bool control;
            bool shift;
            bool system;
        };

        struct TextEvent
        {
            TextEvent(const sf::Event::TextEvent &event) : unicode(event.unicode) {}
            std::uint32_t unicode;
        };

        struct MouseMoveEvent
        {
            MouseMoveEvent(const sf::Event::MouseMoveEvent &event) : x(event.x), y(event.y) {}
            std::int32_t x;
            std::int32_t y;
        };

        struct MouseButtonEvent
        {
            MouseButtonEvent(const sf::Event::MouseButtonEvent &event) : button((Mouse::Button)event.button), x(event.x), y(event.y) {}
            Mouse::Button button;
            std::int32_t x;
            std::int32_t y;
        };

        struct MouseWheelEvent
        {
            MouseWheelEvent(const sf::Event::MouseWheelEvent &event) : delta(event.delta), x(event.x), y(event.y) {}
            std::int32_t delta;
            std::int32_t x;
            std::int32_t y;
        };

        struct MouseWheelScrollEvent
        {
            MouseWheelScrollEvent(const sf::Event::MouseWheelScrollEvent &event) : wheel((Mouse::Wheel)event.wheel), delta(event.delta), x(event.x), y(event.y) {}
            Mouse::Wheel wheel;
            float delta;
            std::int32_t x;
            std::int32_t y;
        };

        struct JoystickConnectEvent
        {
            JoystickConnectEvent(const sf::Event::JoystickConnectEvent &event) : joystickId(event.joystickId) {}
            std::uint32_t joystickId;
        };

        struct JoystickMoveEvent
        {
            JoystickMoveEvent(const sf::Event::JoystickMoveEvent &event) : joystickId(event.joystickId), axis((Joystick::Axis)event.axis), position(event.position) {}
            std::uint32_t joystickId;
            Joystick::Axis axis;
            float position;
        };

        struct JoystickButtonEvent
        {
            JoystickButtonEvent(const sf::Event::JoystickButtonEvent &event) : joystickId(event.joystickId), button(event.button) {}
            std::uint32_t joystickId;
            std::uint32_t button;
        };

        Event(const sf::Event &event) : event(event) {};
        EventType getEventType() const {
            return ((EventType)event.type);
        }
        const sf::Event &getEvent() const {
            return (event);
        }
        SizeEvent getSizeEvent() const {
            return (event.size);
        }
        KeyEvent getKeyEvent() const {
            return (event.key);
        }
        TextEvent getTextEvent() const {
            return (event.text);
        }
        MouseMoveEvent getMouseMoveEvent() const {
            return (event.mouseMove);
        }
        MouseButtonEvent getMouseButtonEvent() const {
            return (event.mouseButton);
        }
        MouseWheelEvent getMouseWheelEvent() const {
            return (event.mouseWheel);
        }
        MouseWheelScrollEvent getMouseWheelScrollEvent() const {
            return (event.mouseWheelScroll);
        }
        JoystickConnectEvent getJoystickConnectEvent() const {
            return (event.joystickConnect);
        }
        JoystickMoveEvent getJoystickMoveEvent() const {
            return (event.joystickMove);
        }
        JoystickButtonEvent getJoystickButtonEvent() const {
            return (event.joystickButton);
        }
    private:
        sf::Event event;
    };
}
