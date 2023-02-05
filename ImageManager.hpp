#pragma once

#include "Image.hpp"
#include "RuntimeException.hpp"
#include <memory>
#include <string>
#include <unordered_map>

namespace SFML {
/**
 * @brief A manager for images
 */
class ImageManager {
public:
    /**
     * @brief Register a image
     *
     * @param id The ID of the image
     * @param filename The path to the image file
     */
    void registerImage(const std::string& id, const std::string& filename)
    {
        if (images.find(id) != images.end())
            throw RuntimeException("ImageManager::registerImage", "A image with this ID has already been registered");
        std::shared_ptr<Image> image = std::make_shared<Image>(filename);
        images.emplace(id, image);
    }

    /**
     * @brief Get a image
     *
     * @param id The ID of the image
     * @return std::shared_ptr<Image> The image
     */
    std::shared_ptr<Image> getImage(const std::string& id)
    {
        if (images.find(id) == images.end())
            throw RuntimeException("ImageManager::getImage", "The ID provided doesn't match with any image previously registered");
        return images.at(id);
    }

private:
    std::unordered_map<std::string, std::shared_ptr<Image>> images;
};
}