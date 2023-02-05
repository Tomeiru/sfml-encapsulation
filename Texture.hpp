#pragma once

#include "RuntimeException.hpp"
#include <SFML/Graphics/Texture.hpp>

namespace SFML {
/**
 * @brief A encapsulation of sf::Texture
 */
class Texture {
public:
    /**
     * @brief Construct a new Texture object
     *
     * @param filename The path to the texture file
     */
    Texture(const std::string& filename)
        : texture()
    {
        if (!texture.loadFromFile(filename))
            throw RuntimeException("Texture::ctor", "texture.loadFromFile failed, filename must be invalid");
    }
    /**
     * @brief Get the Texture object
     *
     * @return const sf::Texture& The texture
     */
    const sf::Texture& getTexture() const
    {
        return texture;
    }

private:
    sf::Texture texture;
};
}
