#pragma once

#include <cstdint>
#include <SFML/Graphics/Color.hpp>

namespace SFML {
    class Color {
    public:
        Color(std::uint8_t red = 255, std::uint8_t green = 255, std::uint8_t blue = 255, std::uint8_t alpha = 255) : color(red, green, blue, alpha) {}
        Color(std::uint32_t color = 0) : color(color) {}
        const sf::Color &getColor() const {
            return (color);
        }
    private:
        sf::Color color;
    };
}
