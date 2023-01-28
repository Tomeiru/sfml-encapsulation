#pragma once

#include <SFML/Graphics/Sprite.hpp>
#include <memory>
#include "Texture.hpp"
#include "Vector2.hpp"
#include "Color.hpp"
#include "Rect.hpp"

namespace SFML {
    class Sprite {
    public:
        Sprite(const std::shared_ptr<Texture> &texture) : sprite(texture->getTexture()), _visible(true) {}
        void setVisible(bool visible) {
            _visible = visible;
        }
        const sf::Sprite &getSprite() {
            return (sprite);
        }
        void setPosition(const Vector2f &position) {
            sprite.setPosition(position.getVector2());
        }
        void setRotation(const float &rotation) {
            sprite.setRotation(rotation);
        }
        void setScale(const Vector2f &scale) {
            sprite.setScale(scale.getVector2());
        }
        void setOrigin(const Vector2f &origin) {
            sprite.setOrigin(origin.getVector2());
        }
        bool isVisible() const {
            return (_visible);
        }
        void setColor(const std::shared_ptr<Color> &color) {
            sprite.setColor(color->getColor());
        }
        FloatRect getGlobalBounds() const {
            return (sprite.getGlobalBounds());
        }
    private:
        sf::Sprite sprite;
        bool _visible;
    };
}
