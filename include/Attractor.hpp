#ifndef __ATTRACTOR_HPP_INCLUDED__
#define __ATTRACTOR_HPP_INCLUDED__

#define GRAVITATIONAL_CONSTANT 0.4f

#include <SFML/Graphics.hpp>

#include "Vector2.hpp"

class Mover;

class Attractor
{
public:
	Attractor(sf::RenderWindow*, float x = 0.f, float y = 0.f, float m = 15.f);
	Attractor(const Attractor&) = default;
	auto	operator = (const Attractor&) -> Attractor& = default;
	~Attractor();

	auto	initialize(sf::RenderWindow*, float x, float y, float m) -> void;
	auto	shutdown() -> void;

	auto	draw() -> void;

	auto	attract(const Mover&) -> Vector2f;

private:
	sf::RenderWindow*	_win		= nullptr;
	sf::CircleShape*	_graphic 	= new sf::CircleShape();

	Vector2f	_location 	= {0.f, 0.f};
	float		_mass 		= 15.f;

};

#endif /* __ATTRACTOR_HPP_INCLUDED__ */
