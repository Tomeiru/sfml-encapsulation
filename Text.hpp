#pragma once

#include "Color.hpp"
#include "Font.hpp"
#include "SFML/Graphics/Text.hpp"
#include "Vector2.hpp"
#include <memory>
#include <string>

namespace SFML {
/**
 * @brief A encapsulation of sf::Text
 */
class Text {
public:
    /**
     * @brief Construct a new Text object
     *
     * @param string The string of the text
     * @param font The font of the text
     * @param characterSize The character size of the text
     */
    Text(const std::string& string, const std::shared_ptr<Font>& font, std::uint32_t characterSize)
        : text(string, font->getFont(), characterSize)
        , _visible(true)
    {
    }
    /**
     * @brief Set a text visible or not
     *
     * @param visible The visibility of the text
     */
    void setVisible(bool visible)
    {
        _visible = visible;
    }
    /**
     * @brief Get the Text object
     *
     * @return const sf::Text& The text
     */
    const sf::Text& getText()
    {
        return (text);
    }
    /**
     * @brief Set the position of the text
     *
     * @param position The position of the text
     */
    void setPosition(const Vector2f& position)
    {
        text.setPosition(position.getVector2());
    }
    /**
     * @brief Set the rotation of the text
     *
     * @param rotation The rotation of the text
     */
    void setRotation(const float& rotation)
    {
        text.setRotation(rotation);
    }
    /**
     * @brief Set the scale of the text
     *
     * @param scale The scale of the text
     */
    void setScale(const Vector2f& scale)
    {
        text.setScale(scale.getVector2());
    }
    /**
     * @brief Set the origin of the text
     *
     * @param origin The origin of the text
     */
    void setOrigin(const Vector2f& origin)
    {
        text.setOrigin(origin.getVector2());
    }
    /**
     * @brief Check if the text is visible
     *
     * @return true The text is visible, false otherwise
     */
    bool isVisible() const
    {
        return (_visible);
    }
    /**
     * @brief Set the fill color of the text
     *
     * @param color The fill color of the text
     */
    void setFillColor(const std::shared_ptr<Color>& color)
    {
        text.setFillColor(color->getColor());
    }
    /**
     * @brief Set the outline color of the text
     *
     * @param color The outline color of the text
     */
    void setOutlineColor(const std::shared_ptr<Color>& color)
    {
        text.setOutlineColor(color->getColor());
    }
    /**
     * @brief Set the outline thickness of the text
     *
     * @param thickness The outline thickness of the text
     */
    void setOutlineThickness(float thickness)
    {
        text.setOutlineThickness(thickness);
    }

private:
    sf::Text text;
    bool _visible;
};
}
