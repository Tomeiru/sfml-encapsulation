#pragma once

#include <cstdint>
#include <string>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Window/Event.hpp>
#include "Image.hpp"
#include "Sprite.hpp"
#include "Text.hpp"
#include "EventManager.hpp"
#include "../ecs/Coordinator.hpp"

namespace SFML {
    class Window {
    public:
        enum Style {
            None = sf::Style::None,
            Default = sf::Style::Default,
            Fullscreen = sf::Style::Fullscreen,
        };
        Window(std::uint32_t width, std::uint32_t height, const std::string &title, Style style = Default) : window(sf::VideoMode(width, height), title, style) {}
        void display() {
            window.display();
        }
        bool isOpen() {
            return (window.isOpen());
        }
        void close() {
            window.close();
        }
        void setIcon(const std::shared_ptr<Image> &image) {
            window.setIcon(image->getWidth(), image->getHeight(), image->getPixelsPointer());
        }
        void clear() {
            window.clear(sf::Color::Black);
        }
        void drawSprite(const std::shared_ptr<Sprite> &sprite) {
            window.draw(sprite->getSprite());
        }
        void drawText(const std::shared_ptr<Text> &text) {
            window.draw(text->getText());
        }
        void clearEventQueue(ECS::Coordinator &coordinator) {
            auto event_manager = coordinator.getResource<SFML::EventManager>();
            sf::Event event;
            while (window.pollEvent(event)) {
                event_manager->newEvent(event);
            }
        }
        const sf::RenderWindow &getWindow() const {
            return (window);
        }
        void setFramerateLimit(std::uint32_t limit) {
            window.setFramerateLimit(limit);
        }
    private:
        sf::RenderWindow window;
    };
}
