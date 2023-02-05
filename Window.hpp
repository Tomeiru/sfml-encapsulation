#pragma once

#include "EventManager.hpp"
#include "Image.hpp"
#include "Sprite.hpp"
#include "Text.hpp"
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Window/Event.hpp>
#include <cstdint>
#include <string>

namespace SFML {
/**
 * @brief A encapsulation of sf::RenderWindow
 */
class Window {
public:
    /**
     * @brief Style of the window enumeration
     */
    enum Style {
        None = sf::Style::None,
        Default = sf::Style::Default,
        Fullscreen = sf::Style::Fullscreen,
    };
    /**
     * @brief Construct a new Window object
     *
     * @param width The width of the window
     * @param height The height of the window
     * @param title The title of the window
     * @param style The style of the window
     */
    Window(std::uint32_t width, std::uint32_t height, const std::string& title, Style style = Default)
        : window(sf::VideoMode(width, height), title, style)
    {
    }
    /**
     * @brief Display the window
     */
    void display()
    {
        window.display();
    }
    /**
     * @brief Check if the window is open
     *
     * @return true The window is open, false otherwise
     */
    bool isOpen()
    {
        return (window.isOpen());
    }
    /**
     * @brief Close the window
     */
    void close()
    {
        window.close();
    }
    /**
     * @brief Set the icon of the window
     *
     * @param image The image to set as the icon
     */
    void setIcon(const std::shared_ptr<Image>& image)
    {
        window.setIcon(image->getWidth(), image->getHeight(), image->getPixelsPointer());
    }
    /**
     * @brief Clear the window
     */
    void clear()
    {
        window.clear(sf::Color::Black);
    }
    /**
     * @brief Draw a sprite on the window
     *
     * @param sprite The sprite to draw
     */
    void drawSprite(const std::shared_ptr<Sprite>& sprite)
    {
        window.draw(sprite->getSprite());
    }
    /**
     * @brief Draw a text on the window
     *
     * @param text The text to draw
     */
    void drawText(const std::shared_ptr<Text>& text)
    {
        window.draw(text->getText());
    }
    /**
     * @brief Poll an event from the window
     *
     * @param event The event to poll
     * @return true The event is empty, false otherwise
     */
    bool pollEvent(SFML::Event& event)
    {
        sf::Event polled_event;
        bool empty = window.pollEvent(polled_event);
        event.setEvent(polled_event);
        return (empty);
    }
    /**
     * @brief Get the Window object
     *
     * @return const sf::RenderWindow& The window
     */
    const sf::RenderWindow& getWindow() const
    {
        return (window);
    }
    /**
     * @brief Set the framerate limit of the window
     *
     * @param limit The framerate limit
     */
    void setFramerateLimit(std::uint32_t limit)
    {
        window.setFramerateLimit(limit);
    }
    /**
     * @brief Check if the window has focus
     *
     * @return true The window has focus, false otherwise
     */
    bool hasFocus() const
    {
        return window.hasFocus();
    }

private:
    sf::RenderWindow window;
};
}
