#pragma once

#include <string>
#include <memory>
#include <unordered_map>
#include "RuntimeException.hpp"
#include "Color.hpp"

namespace SFML {
    /**
     * @brief A manager for colors
     */
    class ColorManager {
    public:
        /**
         * @brief Register a color with red, green, blue and alpha values
         * @param id The ID of the color
         * @param red The red value
         * @param green The green value
         * @param blue The blue value
         * @param alpha The alpha value
         */
        void registerRGBColor(const std::string &id, std::uint8_t red = 255, std::uint8_t green = 255, std::uint8_t blue = 255, std::uint8_t alpha = 255) {
            if (colors.find(id) != colors.end())
                throw RuntimeException("ColorManager::registerColor", "A color with this ID has already been registered");
            std::shared_ptr<Color> color = std::make_shared<Color>(red, green, blue, alpha);
            colors.emplace(id, color);
        }

        /**
         * @brief Register a color with a hex value
         * @param id The ID of the color
         * @param hex_color The hex color
         */
        void registerHexColor(const std::string &id, std::uint32_t hex_color = 0) {
            if (colors.find(id) != colors.end())
                throw RuntimeException("ColorManager::registerColor", "A color with this ID has already been registered");
            std::shared_ptr<Color> color = std::make_shared<Color>(hex_color);
            colors.emplace(id, color);
        }

        /**
         * @brief Get a color
         * @param id The ID of the color
         * @return The color
         */
        std::shared_ptr<Color> getColor(const std::string &id) {
            if (colors.find(id) == colors.end())
                throw RuntimeException("ColorManager::getColor", "The ID provided doesn't match with any color previously registered");
            return colors.at(id);
        }
    private:
        std::unordered_map<std::string, std::shared_ptr<Color>> colors;
    };
}
