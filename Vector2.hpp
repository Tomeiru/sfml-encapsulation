#pragma once

#include <SFML/System/Vector2.hpp>
#include <cstdint>

namespace SFML {
    /**
     * @brief A encapsulation of sf::Vector2
     * 
     * @tparam T The type of the vector
     */
    template<typename T>
    class Vector2 {
    public:
        /**
         * @brief Construct a new Vector2 object
         */
        Vector2() : vector() {};
        /**
         * @brief Construct a new Vector2 object
         * 
         * @param x The x position of the vector
         * @param y The y position of the vector
         */
        Vector2(T x, T y) : vector(x, y) {}
        /**
         * @brief Construct a new Vector2 object
         * 
         * @param vector The sf::Vector2 to copy
         */
        Vector2(const sf::Vector2<T> &vector) : vector(vector) {}
        /**
         * @brief Construct a new Vector2 object
         * 
         * @param vector The Vector2 to copy
         * @tparam U The type of the Vector2 to copy
         */
        template<typename U>
        Vector2(const Vector2<U> &vector) : vector(vector) {}
        /**
         * @brief Get the Vector2 object
         * 
         * @return const sf::Vector2<T>& The vector
         */
        const sf::Vector2<T> &getVector2() const {
            return vector;
        }
        /**
         * @brief Get the x position of the vector
         * 
         * @return T The x position of the vector
         */
        T getX() const {
            return (vector.x);
        }
        /**
         * @brief Get the y position of the vector
         * 
         * @return T The y position of the vector
         */
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
