#pragma once

#include <cstdint>
#include <SFML/Graphics/Color.hpp>

namespace SFML {
    /**
     * @brief A encapsulation of sf::Color
     */
    class Color {
    public:
        /**
         * @brief Construct a new Color object
         * @param red The red value
         * @param green The green value
         * @param blue The blue value
         * @param alpha The alpha value
         */

        Color(std::uint8_t red = 255, std::uint8_t green = 255, std::uint8_t blue = 255, std::uint8_t alpha = 255) : color(red, green, blue, alpha) {}
        Color(std::uint32_t color = 0) : color(color) {}
        /**
         * @brief Get the red value
         * @return The red value
         */
        const sf::Color &getColor() const {
            return (color);
        }
    private:
        sf::Color color;
    };
}
