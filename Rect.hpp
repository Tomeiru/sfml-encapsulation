#pragma once

#include "Vector2.hpp"
#include <SFML/Graphics/Rect.hpp>

namespace SFML {
/**
 * @brief A encapsulation of sf::Rect
 *
 * @tparam T The type of the rect
 */
template<typename T>
class Rect {
public:
    /**
     * @brief Construct a new Rect object
     *
     * @param left The left position of the rect
     * @param top The top position of the rect
     * @param width The width of the rect
     * @param height The height of the rect
     */
    Rect(T left, T top, T width, T height)
        : _rect(left, top, width, height) {};
    /**
     * @brief Construct a new Rect object
     *
     * @param pos The position of the rect
     * @param size The size of the rect
     */
    Rect(const Vector2<T>& pos, const Vector2<T>& size)
        : _rect(pos.getVector2(), size.getVector2()) {};
    /**
     * @brief Construct a new Rect object
     *
     * @param rect The sf::Rect to copy
     */
    Rect(const sf::Rect<T>& rect)
        : _rect(rect) {};
    /**
     * @brief Construct a new Rect object
     *
     * @param rect The Rect to copy
     * @tparam U The type of the Rect to copy
     */
    template<typename U>
    Rect(const Rect<U>& rect)
        : _rect(rect) {};
    /**
     * @brief Check if the rect contains a point
     *
     * @param x The x position of the point
     * @param y The y position of the point
     * @return true If the rect contains the point, false otherwise
     */
    bool contains(T x, T y) const
    {
        return (_rect.contains(x, y));
    }
    /**
     * @brief Check if the rect contains a point
     *
     * @param point The point
     * @return true If the rect contains the point, false otherwise
     */
    bool contains(const Vector2<T>& point) const
    {
        return (_rect.contains(point.getVector2()));
    }
    /**
     * @brief Check if the rect contains another rect
     *
     * @param rect The rect
     * @return true If the rect contains the other rect, false otherwise
     */
    bool intersects(const Rect<T>& rect) const
    {
        return (_rect.intersects(rect._rect));
    }
    /**
     * @brief Check if the rect intersects another rect
     *
     * @param rect The rect
     * @param intersection The intersection of the two rects
     * @return true If the rect intersects the other rect, false otherwise
     */
    bool intersects(const Rect<T>& rect, Rect<T>& intersection) const
    {
        return (_rect.intersects(rect._rect, intersection._rect));
    }
    /**
     * @brief Set the top position and left position of the rect
     */
    void setTopLeft(T left, T top)
    {
        _rect.top = top;
        _rect.left = left;
    }

private:
    sf::Rect<T> _rect;
};
using FloatRect = Rect<float>;
using IntRect = Rect<std::int32_t>;
}
