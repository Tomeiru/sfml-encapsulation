#pragma once

#include <unordered_map>
#include <string>
#include <memory>
#include "RuntimeException.hpp"
#include "Image.hpp"

namespace SFML {
    class ImageManager {
    public:
        void registerImage(const std::string &id, const std::string &filename) {
            if (images.find(id) != images.end())
                throw RuntimeException("ImageManager::registerImage", "A image with this ID has already been registered");
            std::shared_ptr<Image> image = std::make_shared<Image>(filename);
            images.emplace(id, image);
        }

        std::shared_ptr<Image> getImage(const std::string &id) {
            if (images.find(id) == images.end())
                throw RuntimeException("ImageManager::getImage", "The ID provided doesn't match with any image previously registered");
            return images.at(id);
        }
    private:
        std::unordered_map<std::string, std::shared_ptr<Image>> images;
    };
}