#pragma once

#include "RuntimeException.hpp"
#include <SFML/Graphics/Font.hpp>

namespace SFML {
/**
 * @brief A encapsulation of sf::Font
 */
class Font {
public:
    /**
     * @brief Construct a new Font object
     *
     * @param filename The path to the font file
     */
    Font(const std::string& filename)
        : font()
    {
        if (!font.loadFromFile(filename))
            throw RuntimeException("Font::ctor", "font.loadFromFile failed, filename must be invalid");
    }
    /**
     * @brief Get the Font object
     *
     * @return const sf::Font& The font
     */
    const sf::Font& getFont() const
    {
        return font;
    }

private:
    sf::Font font;
};
}