#ifndef __ENTITY_HPP_INCLUDED__
#define __ENTITY_HPP_INCLUDED__

#include <SFML/Graphics.hpp>

#include "Vector2.hpp"

class Entity
{
public:
	Entity();
	Entity(const Entity&) = default;
	auto	operator = (const Entity&) -> Entity& = default;
	~Entity();

	auto	initialize() -> void;
	auto	shutdown() -> void;

	auto	draw() -> void = 0;

	auto	getLocation() const -> Vector2f { return _location; }
	auto	setLocation(float x, float y) -> void { _location = {x, y}; }
	auto	setLocation(const Vector2f& v) -> void { _location = v; }

private:
	sf::RenderWindow*	_win 	= nullptr;
	sf::Shape*			_shape 	= nullptr;

	Vector2f	_location = {0.f, 0.f};

};

#endif /* __ENTITY_HPP_INCLUDED__ */
