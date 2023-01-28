#pragma once

#include <SFML/Graphics/Rect.hpp>
#include "Vector2.hpp"

namespace SFML {
    template <typename T>
    class Rect {
    public:
        Rect(T left, T top, T width, T height) : _rect(left, top, width, height) {};
        Rect(const Vector2<T> &pos, const Vector2<T> &size) : _rect(pos.getVector2(), size.getVector2()) {};
        Rect(const sf::Rect<T> &rect) : _rect(rect) {};
        template<typename U>
        Rect(const Rect<U> &rect) : _rect(rect) {};
        bool contains(T x, T y) const {
            return (_rect.contains(x, y));
        }
        bool contains(const Vector2<T> &point) const {
            return (_rect.contains(point.getVector2()));
        }
        bool intersects(const Rect<T> &rect) const {
            return (_rect.intersects(rect._rect));
        }
        bool intersects(const Rect<T> &rect, Rect<T> &intersection) const {
            return (_rect.intersects(rect._rect, intersection._rect));
        }
        void setTopLeft(T left, T top) {
            _rect.top = top;
            _rect.left = left;
        }
    private:
        sf::Rect<T> _rect;
    };
    using FloatRect = Rect<float>;
    using IntRect = Rect<std::int32_t>;
}
