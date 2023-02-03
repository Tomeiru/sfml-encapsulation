#pragma once


#include <unordered_map>
#include <string>
#include <memory>
#include "Sprite.hpp"

namespace SFML {
    /**
     * @brief A manager for sprites
     */
    class SpriteManager {
    public:
        /**
         * @brief Register a sprite
         * 
         * @param id The ID of the sprite
         * @param texture The texture of the sprite
         */
        void registerSprite(const std::string &id, const std::shared_ptr<Texture> &texture) {
            if (sprites.find(id) != sprites.end())
                throw RuntimeException("SpriteManager::registerSprite", "A texture with this ID has already been registered");
            std::shared_ptr<Sprite> sprite = std::make_shared<Sprite>(texture);
            sprites.emplace(id, sprite);
        }
        /**
         * @brief Get a sprite
         * 
         * @param id The ID of the sprite
         * @return std::shared_ptr<Sprite> The sprite
         */
        std::shared_ptr<Sprite> getSprite(const std::string &id) {
            if (sprites.find(id) == sprites.end())
                throw RuntimeException("SpriteManager::getSprite", "The ID provided doesn't match with any texture previously registered");
            return sprites.at(id);
        }
    private:
        std::unordered_map<std::string, std::shared_ptr<Sprite>> sprites;
    };
}
