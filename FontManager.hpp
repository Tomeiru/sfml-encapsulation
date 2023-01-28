#pragma once

#include <string>
#include <memory>
#include <unordered_map>
#include "Font.hpp"

namespace SFML {
    class FontManager {
    public:
        void registerFont(const std::string &id, const std::string &filename) {
            if (fonts.find(id) != fonts.end())
                throw RuntimeException("FontManager::registerFont", "A font with this ID has already been registered");
            std::shared_ptr<Font> font = std::make_shared<Font>(filename);
            fonts.emplace(id, font);
        }

        std::shared_ptr<Font> getFont(const std::string &id) {
            if (fonts.find(id) == fonts.end())
                throw RuntimeException("FontManager::getFont", "The ID provided doesn't match with any font previously registered");
            return fonts.at(id);
        }
    private:
        std::unordered_map<std::string, std::shared_ptr<Font>> fonts;
    };
}
