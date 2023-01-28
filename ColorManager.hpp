#pragma once

#include <string>
#include <memory>
#include <unordered_map>
#include "RuntimeException.hpp"
#include "Color.hpp"

namespace SFML {
    class ColorManager {
    public:
        void registerRGBColor(const std::string &id, std::uint8_t red = 255, std::uint8_t green = 255, std::uint8_t blue = 255, std::uint8_t alpha = 255) {
            if (colors.find(id) != colors.end())
                throw RuntimeException("ColorManager::registerColor", "A color with this ID has already been registered");
            std::shared_ptr<Color> color = std::make_shared<Color>(red, green, blue, alpha);
            colors.emplace(id, color);
        }

        void registerHexColor(const std::string &id, std::uint32_t hex_color = 0) {
            if (colors.find(id) != colors.end())
                throw RuntimeException("ColorManager::registerColor", "A color with this ID has already been registered");
            std::shared_ptr<Color> color = std::make_shared<Color>(hex_color);
            colors.emplace(id, color);
        }

        std::shared_ptr<Color> getColor(const std::string &id) {
            if (colors.find(id) == colors.end())
                throw RuntimeException("ColorManager::getColor", "The ID provided doesn't match with any color previously registered");
            return colors.at(id);
        }
    private:
        std::unordered_map<std::string, std::shared_ptr<Color>> colors;
    };
}
