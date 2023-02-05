#pragma once

#include "Event.hpp"
#include <queue>

namespace SFML {
/**
 * @brief EventManager class
 *
 * This class is used to manage events.
 * It is used to store events and to clear them.
 * It is also used to check if the user wants to quit the game.
 *
 */
class EventManager {
public:
    /**
     * @brief Add a new event to the event manager
     *
     * @param event The event to add to the event manager
     */
    void newEvent(const sf::Event& event)
    {
        if (event.type >= sf::Event::TextEntered && event.type <= sf::Event::KeyReleased)
            keyboard_events.emplace_back(event);
        if (event.type >= sf::Event::MouseWheelMoved && event.type <= sf::Event::MouseLeft)
            mouse_events.emplace_back(event);
        if (event.type >= sf::Event::JoystickButtonPressed && event.type <= sf::Event::JoystickDisconnected)
            gamepad_events.emplace_back(event);
        if (event.type == sf::Event::Closed)
            quit = true;
    }
    /**
     * @brief Check if the user wants to quit the game
     *
     * @return true The user wants to quit the game
     * @return false The user doesn't want to quit the game
     */
    bool quitEventRegistered() const
    {
        return (quit);
    }
    /**
     * @brief Get the Keyboard Events object
     *
     * @return const std::vector<Event>& The keyboard events
     */
    const std::vector<Event>& getKeyboardEvents() const
    {
        return (keyboard_events);
    }
    /**
     * @brief Get the Mouse Events object
     *
     * @return const std::vector<Event>& The mouse events
     */
    const std::vector<Event>& getMouseEvents() const
    {
        return (mouse_events);
    }
    /**
     * @brief Get the Gamepad Events object
     *
     * @return const std::vector<Event>& The gamepad events
     */
    const std::vector<Event>& getGamepadEvents() const
    {
        return (gamepad_events);
    }
    /**
     * @brief Clear the events
     */
    void clear()
    {
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