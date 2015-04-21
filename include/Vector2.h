#ifndef __VECTOR2_H_INCLUDED__
#define __VECTOR2_H_INCLUDED__

#include <iostream>
#include <cmath>

namespace Utils
{
    namespace Math
    {

        template <typename T>
        class Vector2
        {
        public:
            Vector2();
            Vector2(T, T);
            Vector2(Vector2<T> const&);
            Vector2<T>& operator = (Vector2<T> const&);
            ~Vector2() = default;

            T   getX() const;
            T   getY() const;

            auto    set(float, float) -> void;

            auto    add(Vector2 const&) -> Vector2&;
            auto    add(Vector2 const&) const -> Vector2;

            auto    sub(Vector2 const&) -> Vector2&;
            auto    sub(Vector2 const&) const -> Vector2;

            auto    mult(float const&) -> Vector2&;
            auto    mult(float const&) const -> Vector2;

            auto    mult(Vector2 const&) -> Vector2&;
            auto    mult(Vector2 const&) const -> Vector2;

            auto    getNorm() const -> float;

            auto    normalize() -> Vector2&;
            auto    getNormalized() const -> Vector2;

            auto    invert() -> Vector2&;
            auto    getInverted() const -> Vector2;

            auto    dotProduct(Vector2 const&) const -> float;
            auto    crossProduct(Vector2 const&) const -> float;

            auto    operator * () const -> Vector2;

            auto    operator +  (Vector2 const&) const -> Vector2;
            auto    operator += (Vector2 const&) -> Vector2&;

            auto    operator -  (Vector2 const&) const -> Vector2;
            auto    operator -= (Vector2 const&) -> Vector2&;

            auto    operator *  (Vector2 const&) const -> Vector2;
            auto    operator *= (Vector2 const&) -> Vector2&;

        private:
            T   _x;
            T   _y;
        };

    } // namespace Math

} /* namespace Utils */

template <typename T>
std::ostream&   operator << (std::ostream&, Utils::Math::Vector2<T> const&);

#include "Vector2.inl"

#endif /* __VECTOR2_H_INCLUDED__ */

