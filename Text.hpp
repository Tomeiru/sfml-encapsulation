#pragma once

#include <string>
#include <memory>
#include "Font.hpp"
#include "SFML/Graphics/Text.hpp"
#include "Vector2.hpp"
#include "Color.hpp"

namespace SFML {
    class Text {
    public:
        Text(const std::string &string, const std::shared_ptr<Font> &font, std::uint32_t characterSize) : text(string, font->getFont(), characterSize), _visible(true) {}
        void setVisible(bool visible) {
            _visible = visible;
        }
        const sf::Text &getText() {
            return (text);
        }
        void setPosition(const Vector2f &position) {
            text.setPosition(position.getVector2());
        }
        void setRotation(const float &rotation) {
            text.setRotation(rotation);
        }
        void setScale(const Vector2f &scale) {
            text.setScale(scale.getVector2());
        }
        void setOrigin(const Vector2f &origin) {
            text.setOrigin(origin.getVector2());
        }
        bool isVisible() const {
            return (_visible);
        }
        void setFillColor(const std::shared_ptr<Color> &color) {
            text.setFillColor(color->getColor());
        }
        void setOutlineColor(const std::shared_ptr<Color> &color) {
            text.setOutlineColor(color->getColor());
        }
        void setOutlineThickness(float thickness) {
            text.setOutlineThickness(thickness);
        }
    private:
        sf::Text text;
        bool _visible;
    };
}
