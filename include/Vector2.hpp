#ifndef __VECTOR2_HPP_INCLUDED__
#define __VECTOR2_HPP_INCLUDED__

#include <iostream>
#include <cmath>
#include <algorithm>

template <typename T>
class Vector2
{
public:
    Vector2();
    Vector2(T, T);
    Vector2(const Vector2<T>&);
    Vector2<T>& operator = (const Vector2<T>&);
    ~Vector2() = default;

    auto    add(const Vector2&) -> Vector2&;

    auto    sub(const Vector2&) -> Vector2&;

    auto    mult(float) -> Vector2&;
    auto    mult(const Vector2&) -> Vector2&;

	auto	div(float) -> Vector2&;

	auto	mag() const -> float;

	auto	normalize() -> Vector2&;

	auto	limit(float) -> void;

	auto	dist(const Vector2&) -> float;

    auto    invert() -> Vector2&;

    auto    dotProduct(Vector2 const&) const -> float;

    auto    crossProduct(Vector2 const&) const -> float;

	auto	clip(float min, float max) -> void;
	auto	clip(const Vector2&) -> void;

	auto 	heading() const -> float;

	// STATIC
   	static	auto    add(const Vector2&, const Vector2&) -> Vector2;

   	static	auto    sub(const Vector2&, const Vector2&) -> Vector2;

   	static	auto    mult(const Vector2&, float) -> Vector2;

   	static	auto    mult(const Vector2&, const Vector2&) -> Vector2;

   	static	auto	div(const Vector2&, float) -> Vector2;

   	static	auto	normalize(const Vector2&) -> Vector2;

   	static	auto	dist(const Vector2&, const Vector2&) -> float;

   	static	auto    inverted(const Vector2&) -> Vector2;

    static	auto    dotProduct(const Vector2&, const Vector2&) -> float;

    static	auto    crossProduct(const Vector2&, const Vector2&) -> float;

	static 	auto	clip(const Vector2&, float, float) -> Vector2;
	static	auto	clip(const Vector2&, const Vector2&) -> Vector2;

// EXPERIMENTAL

	auto	rotate(float) -> Vector2&;
	auto	rotate(float) const -> Vector2;

	auto	lerp() -> Vector2&;
	auto	lerp() const -> Vector2;


	auto	angleBetween(const Vector2&) -> Vector2&;
	auto	angleBetween(const Vector2&) const -> Vector2;

	auto	random2D() -> Vector2;

// END EXPERIMENTAL

    auto    operator * () const -> Vector2;

    auto    operator +  (const Vector2&) const -> Vector2;
    auto    operator += (const Vector2&) -> Vector2&;

    auto    operator -  (const Vector2&) const -> Vector2;
    auto    operator -= (const Vector2&) -> Vector2&;

    auto    operator *  (const Vector2&) const -> Vector2;
    auto    operator *= (const Vector2&) -> Vector2&;

    auto    operator /  (const Vector2&) const -> Vector2;
    auto    operator /= (const Vector2&) -> Vector2&;

    T   x;
    T   y;
};


typedef Vector2<float> 	Vector2f;
typedef Vector2<int>	Vector2i;


template <typename T>
std::ostream&   operator << (std::ostream&, Vector2<T> const&);


#include "Vector2.inl"

#endif /* __VECTOR2_HPP_INCLUDED__ */

