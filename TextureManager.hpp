#pragma once

#include <unordered_map>
#include <string>
#include <memory>
#include "Texture.hpp"
#include "RuntimeException.hpp"

namespace SFML {
    class TextureManager {
    public:
        void registerTexture(const std::string &id, const std::string &filename) {
            if (textures.find(id) != textures.end())
                throw RuntimeException("TextureManager::registerTexture", "A texture with this ID has already been registered");
            std::shared_ptr<Texture> texture = std::make_shared<Texture>(filename);
            textures.emplace(id, texture);
        }

        std::shared_ptr<Texture> getTexture(const std::string &id) {
            if (textures.find(id) == textures.end())
                throw RuntimeException("TextureManager::getTexture", "The ID provided doesn't match with any texture previously registered");
            return textures.at(id);
        }
    private:
        std::unordered_map<std::string, std::shared_ptr<Texture>> textures;
    };
}