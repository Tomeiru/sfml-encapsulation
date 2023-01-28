#pragma once

#include <SFML/System/Vector2.hpp>
#include <cstdint>

namespace SFML {
    template<typename T>
    class Vector2 {
    public:
        Vector2() : vector() {};
        Vector2(T x, T y) : vector(x, y) {}
        Vector2(const sf::Vector2<T> &vector) : vector(vector) {}
        template<typename U>
        Vector2(const Vector2<U> &vector) : vector(vector) {}
        const sf::Vector2<T> &getVector2() const {
            return vector;
        }
        T getX() const {
            return (vector.x);
        }
        T getY() const {
            return (vector.y);
        }
    private:
        sf::Vector2<T> vector;
    };
    using Vector2f = Vector2<float>;
    using Vector2u = Vector2<std::uint32_t>;
    using Vector2i = Vector2<std::int32_t>;
}
