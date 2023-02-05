#pragma once

#include "RuntimeException.hpp"
#include <SFML/Graphics/Image.hpp>
#include <string>

namespace SFML {
class Image {
public:
    /**
     * @brief Construct a new Image object
     *
     * @param filename The path to the image file
     */
    Image(const std::string& filename)
        : image()
    {
        if (!image.loadFromFile(filename))
            throw RuntimeException("Image::ctor", "image.loadFromFile failed, filename must be invalid");
    }

    /**
     * @brief Get the Image object
     *
     * @return const sf::Image& The image
     */
    const std::uint8_t* getPixelsPointer() const
    {
        return (image.getPixelsPtr());
    }
    /**
     * @brief Get the width of the image
     *
     * @return std::uint32_t The width
     */
    std::uint32_t getWidth() const
    {
        return (image.getSize().x);
    }
    /**
     * @brief Get the height of the image
     *
     * @return std::uint32_t The height
     */
    std::uint32_t getHeight() const
    {
        return (image.getSize().y);
    }

private:
    sf::Image image;
};
}