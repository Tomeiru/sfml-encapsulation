#pragma once


#include <unordered_map>
#include <string>
#include <memory>
#include "Text.hpp"

namespace SFML {
    /**
     * @brief A manager for texts
     */
    class TextManager {
    public:
        /**
         * @brief Register a text
         * 
         * @param id The ID of the text
         * @param string The string of the text
         * @param font The font of the text
         * @param characterSize The character size of the text
         */
        void registerText(const std::string &id, const std::string &string, const std::shared_ptr<Font> &font, std::uint32_t characterSize) {
            if (texts.find(id) != texts.end())
                throw RuntimeException("TextManager::registerText", "A texture with this ID has already been registered");
            std::shared_ptr<Text> text = std::make_shared<Text>(string, font, characterSize);
            texts.emplace(id, text);
        }

        /**
         * @brief Get a text
         * 
         * @param id The ID of the text
         * @return std::shared_ptr<Text> The text
         */
        std::shared_ptr<Text> getText(const std::string &id) {
            if (texts.find(id) == texts.end())
                throw RuntimeException("TextManager::getText", "The ID provided doesn't match with any texture previously registered");
            return texts.at(id);
        }
    private:
        std::unordered_map<std::string, std::shared_ptr<Text>> texts;
    };
}
