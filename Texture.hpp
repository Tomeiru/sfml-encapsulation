#pragma once


#include <SFML/Graphics/Texture.hpp>
#include "RuntimeException.hpp"

namespace SFML {
    class Texture {
    public:
        Texture(const std::string &filename) : texture() {
            if (!texture.loadFromFile(filename))
                throw RuntimeException("Texture::ctor", "texture.loadFromFile failed, filename must be invalid");
        }
        const sf::Texture &getTexture() const {
            return texture;
        }
    private:
        sf::Texture texture;
    };
}
