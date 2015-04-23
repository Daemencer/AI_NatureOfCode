#ifndef __LIQUID_HPP_INCLUDED__
#define __LIQUID_HPP_INCLUDED__

#include <SFML/Graphics.hpp>

#include "Vector2.hpp"

class Liquid
{
public:
	Liquid(sf::RenderWindow*, float x, float y, float w, float h, float c = 0.1f);
	Liquid(const Liquid&) = default;
	auto	operator = (const Liquid&) -> Liquid& = default;
	~Liquid();

	auto	initialize(sf::RenderWindow*, float x, float y, float w, float h, float c) -> void;
	auto	shutdown() -> void;

	auto	draw() -> void;

	auto	setCoefficient(float c) -> void { _c = c; }
	auto	getCoefficient() const -> float { return _c; }

	auto	getLocation() const -> Vector2f;
	auto	setLocation(float, float) -> void;
	auto	setLocation(const Vector2f&) -> void;

	auto	getSize() const -> Vector2f;
	auto	setSize(float, float) -> void;
	auto	setSize(const Vector2f&) -> void;

private:
	sf::RenderWindow*	_win 		= nullptr;
	sf::RectangleShape*	_graphic 	= nullptr;

	float	_x = 0.f;
	float	_y = 0.f;
	float	_w = 0.f;
	float	_h = 0.f;

	float	_c = 0.1f;

};

#endif /* __LIQUID_HPP_INCLUDED__ */
