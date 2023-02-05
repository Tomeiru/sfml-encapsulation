#pragma once

#include "Joystick.hpp"
#include "Keyboard.hpp"
#include "Mouse.hpp"
#include <SFML/Window/Event.hpp>

namespace SFML {
/**
 * @brief A encapsulation of sf::Event
 */
class Event {
public:
    /**
     * @brief Enum of event types
     */
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

    /**
     * @brief Encapsulation of sf::Event::SizeEvent
     */
    struct SizeEvent {
        /**
         * @brief Construct a new Size Event object
         * @param event The sf::Event::SizeEvent
         */
        SizeEvent(const sf::Event::SizeEvent& event)
            : width(event.width)
            , height(event.height)
        {
        }
        std::uint32_t width;
        std::uint32_t height;
    };

    /**
     * @brief Encapsulation of sf::Event::KeyEvent
     */
    struct KeyEvent {
        /**
         * @brief Construct a new Key Event object
         * @param event The sf::Event::KeyEvent
         */
        KeyEvent(const sf::Event::KeyEvent& event)
            : code((Keyboard::Key)event.code)
            , alt(event.alt)
            , control(event.control)
            , shift(event.shift)
            , system(event.system)
        {
        }
        Keyboard::Key code;
        bool alt;
        bool control;
        bool shift;
        bool system;
    };

    /**
     * @brief Encapsulation of sf::Event::TextEvent
     */
    struct TextEvent {
        /**
         * @brief Construct a new Text Event object
         * @param event The sf::Event::TextEvent
         */
        TextEvent(const sf::Event::TextEvent& event)
            : unicode(event.unicode)
        {
        }
        std::uint32_t unicode;
    };

    /**
     * @brief Encapsulation of sf::Event::MouseMoveEvent
     */
    struct MouseMoveEvent {
        /**
         * @brief Construct a new Mouse Move Event object
         * @param event The sf::Event::MouseMoveEvent
         */
        MouseMoveEvent(const sf::Event::MouseMoveEvent& event)
            : x(event.x)
            , y(event.y)
        {
        }
        std::int32_t x;
        std::int32_t y;
    };

    /**
     * @brief Encapsulation of sf::Event::MouseButtonEvent
     */
    struct MouseButtonEvent {
        /**
         * @brief Construct a new Mouse Button Event object
         * @param event The sf::Event::MouseButtonEvent
         */
        MouseButtonEvent(const sf::Event::MouseButtonEvent& event)
            : button((Mouse::Button)event.button)
            , x(event.x)
            , y(event.y)
        {
        }
        Mouse::Button button;
        std::int32_t x;
        std::int32_t y;
    };

    /**
     * @brief Encapsulation of sf::Event::MouseWheelEvent
     */
    struct MouseWheelEvent {
        /**
         * @brief Construct a new Mouse Wheel Event object
         * @param event The sf::Event::MouseWheelEvent
         */
        MouseWheelEvent(const sf::Event::MouseWheelEvent& event)
            : delta(event.delta)
            , x(event.x)
            , y(event.y)
        {
        }
        std::int32_t delta;
        std::int32_t x;
        std::int32_t y;
    };

    /**
     * @brief Encapsulation of sf::Event::MouseWheelScrollEvent
     */
    struct MouseWheelScrollEvent {
        /**
         * @brief Construct a new Mouse Wheel Scroll Event object
         * @param event The sf::Event::MouseWheelScrollEvent
         */
        MouseWheelScrollEvent(const sf::Event::MouseWheelScrollEvent& event)
            : wheel((Mouse::Wheel)event.wheel)
            , delta(event.delta)
            , x(event.x)
            , y(event.y)
        {
        }
        Mouse::Wheel wheel;
        float delta;
        std::int32_t x;
        std::int32_t y;
    };

    /**
     * @brief Encapsulation of sf::Event::JoystickConnectEvent
     */
    struct JoystickConnectEvent {
        /**
         * @brief Construct a new Joystick Connect Event object
         * @param event The sf::Event::JoystickConnectEvent
         */
        JoystickConnectEvent(const sf::Event::JoystickConnectEvent& event)
            : joystickId(event.joystickId)
        {
        }
        std::uint32_t joystickId;
    };

    /**
     * @brief Encapsulation of sf::Event::JoystickMoveEvent
     */
    struct JoystickMoveEvent {
        /**
         * @brief Construct a new Joystick Move Event object
         * @param event The sf::Event::JoystickMoveEvent
         */
        JoystickMoveEvent(const sf::Event::JoystickMoveEvent& event)
            : joystickId(event.joystickId)
            , axis((Joystick::Axis)event.axis)
            , position(event.position)
        {
        }
        std::uint32_t joystickId;
        Joystick::Axis axis;
        float position;
    };

    /**
     * @brief Encapsulation of sf::Event::JoystickButtonEvent
     */
    struct JoystickButtonEvent {
        /**
         * @brief Construct a new Joystick Button Event object
         * @param event The sf::Event::JoystickButtonEvent
         */
        JoystickButtonEvent(const sf::Event::JoystickButtonEvent& event)
            : joystickId(event.joystickId)
            , button(event.button)
        {
        }
        std::uint32_t joystickId;
        std::uint32_t button;
    };

    /**
     * @brief Construct a new Event class
     */
    Event()
        : _event() {};

    /**
     * @brief Construct a new Event class from a sf::Event
     * @param event The sf::Event the encapsulation is build around
     */
    Event(const sf::Event& event)
        : _event(event) {};
    /**
     * @brief Get the Event Type
     */
    EventType getEventType() const
    {
        return ((EventType)_event.type);
    }
    /**
     * @brief Get the Event
     */
    const sf::Event& getEvent() const
    {
        return (_event);
    }
    /**
     * @brief Set the Event
     */
    void setEvent(sf::Event event)
    {
        _event = event;
    }
    /**
     * @brief Get the Size of the Event
     */
    SizeEvent getSizeEvent() const
    {
        return (_event.size);
    }
    /**
     * @brief Get the Key of the Event
     */
    KeyEvent getKeyEvent() const
    {
        return (_event.key);
    }
    /**
     * @brief Get the Text of the Event
     */
    TextEvent getTextEvent() const
    {
        return (_event.text);
    }
    /**
     * @brief Get the Mouse Move of the Event
     */
    MouseMoveEvent getMouseMoveEvent() const
    {
        return (_event.mouseMove);
    }
    /**
     * @brief Get the Mouse Button of the Event
     */
    MouseButtonEvent getMouseButtonEvent() const
    {
        return (_event.mouseButton);
    }
    /**
     * @brief Get the Mouse Wheel of the Event
     */
    MouseWheelEvent getMouseWheelEvent() const
    {
        return (_event.mouseWheel);
    }
    /**
     * @brief Get the Mouse Wheel Scroll of the Event
     */
    MouseWheelScrollEvent getMouseWheelScrollEvent() const
    {
        return (_event.mouseWheelScroll);
    }
    /**
     * @brief Get the Joystick Connect of the Event
     */
    JoystickConnectEvent getJoystickConnectEvent() const
    {
        return (_event.joystickConnect);
    }
    /**
     * @brief Get the Joystick Move of the Event
     */
    JoystickMoveEvent getJoystickMoveEvent() const
    {
        return (_event.joystickMove);
    }
    /**
     * @brief Get the Joystick Button of the Event
     */
    JoystickButtonEvent getJoystickButtonEvent() const
    {
        return (_event.joystickButton);
    }

private:
    sf::Event _event;
};
}
