#pragma once

#include <SFML/Graphics/Sprite.hpp>
#include <memory>
#include "Texture.hpp"
#include "Vector2.hpp"
#include "Color.hpp"
#include "Rect.hpp"

namespace SFML {
    /**
     * @brief A encapsulation of sf::Sprite
     */
    class Sprite {
    public:
        /**
         * @brief Construct a new Sprite object
         * 
         * @param texture The texture of the sprite
         */
        Sprite(const std::shared_ptr<Texture> &texture) : sprite(texture->getTexture()), _visible(true) {}
        /**
         *  @brief Set a sprite visible or not
         * 
         * @param visible The visibility of the sprite
         */
        void setVisible(bool visible) {
            _visible = visible;
        }
        /**
         * @brief Get the Sprite object
         * 
         * @return const sf::Sprite& The sprite
         */
        const sf::Sprite &getSprite() {
            return (sprite);
        }
        /**
         * @brief Set the position of the sprite
         * 
         * @param position The position of the sprite
         */
        void setPosition(const Vector2f &position) {
            sprite.setPosition(position.getVector2());
        }
        /**
         * @brief Set the rotation of the sprite
         * 
         * @param rotation The rotation of the sprite
         */
        void setRotation(const float &rotation) {
            sprite.setRotation(rotation);
        }
        /**
         * @brief Set the scale of the sprite
         * 
         * @param scale The scale of the sprite
         */
        void setScale(const Vector2f &scale) {
            sprite.setScale(scale.getVector2());
        }
        /**
         * @brief Set the origin of the sprite
         * 
         * @param origin The origin of the sprite
         */
        void setOrigin(const Vector2f &origin) {
            sprite.setOrigin(origin.getVector2());
        }
        /**
         * @brief Check if the sprite is visible
         * 
         * @return true If the sprite is visible, false otherwise
         */
        bool isVisible() const {
            return (_visible);
        }
        /**
         * @brief Set the color of the sprite
         * 
         * @param color The color of the sprite
         */
        void setColor(const std::shared_ptr<Color> &color) {
            sprite.setColor(color->getColor());
        }
        /**
         * @brief Get the bounds of the sprite
         * 
         * @return FloatRect The bounds of the sprite
         */
        FloatRect getGlobalBounds() const {
            return (sprite.getGlobalBounds());
        }
    private:
        sf::Sprite sprite;
        bool _visible;
    };
}
