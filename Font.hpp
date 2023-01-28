#pragma once

#include <SFML/Graphics/Font.hpp>
#include "RuntimeException.hpp"

namespace SFML {
    class Font {
    public:
        Font(const std::string &filename) : font() {
            if (!font.loadFromFile(filename))
                throw RuntimeException("Font::ctor", "font.loadFromFile failed, filename must be invalid");
        }
        const sf::Font &getFont() const {
            return font;
        }
    private:
        sf::Font font;
    };
}