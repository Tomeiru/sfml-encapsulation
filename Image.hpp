#pragma once

#include <string>
#include <SFML/Graphics/Image.hpp>
#include "RuntimeException.hpp"

namespace SFML {
    class Image {
    public:
        Image(const std::string &filename) : image() {
            if (!image.loadFromFile(filename))
                throw RuntimeException("Image::ctor", "image.loadFromFile failed, filename must be invalid");
        }
        const std::uint8_t *getPixelsPointer() const {
            return (image.getPixelsPtr());
        }
        std::uint32_t getWidth() const {
            return (image.getSize().x);
        }
        std::uint32_t getHeight() const {
            return (image.getSize().y);
        }
    private:
        sf::Image image;
    };
}