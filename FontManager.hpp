#pragma once

#include "Font.hpp"
#include <memory>
#include <string>
#include <unordered_map>

namespace SFML {
/**
 * @brief A manager for fonts
 */
class FontManager {
public:
    /**
     * @brief Register a font
     *
     * @param id The ID of the font
     * @param filename The path to the font file
     */
    void registerFont(const std::string& id, const std::string& filename)
    {
        if (fonts.find(id) != fonts.end())
            throw RuntimeException("FontManager::registerFont", "A font with this ID has already been registered");
        std::shared_ptr<Font> font = std::make_shared<Font>(filename);
        fonts.emplace(id, font);
    }

    /**
     * @brief Get a font
     *
     * @param id The ID of the font
     * @return std::shared_ptr<Font> The font
     */
    std::shared_ptr<Font> getFont(const std::string& id)
    {
        if (fonts.find(id) == fonts.end())
            throw RuntimeException("FontManager::getFont", "The ID provided doesn't match with any font previously registered");
        return fonts.at(id);
    }

private:
    std::unordered_map<std::string, std::shared_ptr<Font>> fonts;
};
}
