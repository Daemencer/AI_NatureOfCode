#ifndef __MOVER_HPP_INCLUDED__
#define __MOVER_HPP_INCLUDED__

#include <SFML/Graphics.hpp>

#include "Vector2.hpp"

class Mover
{
public:
	Mover(sf::RenderWindow*);
	Mover(sf::RenderWindow*, float xPos, float yPos);
	Mover(sf::RenderWindow*, float xPos, float yPos, float xVelocity, float yVelocity);
	Mover(sf::RenderWindow*, float xPos, float yPos, float xVelocity, float yVelocity, float xAcc, float yAcc);
	Mover(sf::RenderWindow*, const Vector2f& p);
	Mover(sf::RenderWindow*, const Vector2f& p, const Vector2f& v);
	Mover(sf::RenderWindow*, const Vector2f& p, const Vector2f& v, const Vector2f& a);
	Mover(const Mover&) = default; // todo
	auto	operator = (const Mover&) -> Mover&; // todo
	~Mover();

	auto	update() -> void;
	auto	draw() -> void;

	auto	getLocation() const -> Vector2f { return _location; }
	auto	setLocation(float x, float y) -> void { _location.x = x; _location.y = y; }
	auto	setLocation(const Vector2f& v) -> void { _location.x = v.x; _location.y = v.y; }

	auto	getVelocity() const -> Vector2f { return _velocity; }
	auto	setVelocity(float x, float y) -> void { _velocity.x = x; _velocity.y = y; }
	auto	setVelocity(const Vector2f& v) -> void { _velocity.x = v.x; _velocity.y = v.y; }

	auto	getAcceleration() const -> Vector2f { return _velocity; }
	auto	setAcceleration(float x, float y) -> void { _acceleration.x = x; _acceleration.y = y; }
	auto	setAcceleration(const Vector2f& v) -> void { _acceleration.x = v.x; _acceleration.y = v.y; }

	auto	getMass() const -> float { return _mass; }
	auto	setMass(float m) -> void { _mass = m; }

	auto	getTopSpeed() const -> float { return _topSpeed; }
	auto	setTopSpeed(float s) -> void { _topSpeed = s; }

	auto	setMousePos(float x, float y) -> void { _mousePos.x = x; _mousePos.y = y; }

	auto	applyForce(const Vector2f&) -> void;

private:
	auto	_checkEdges() -> void;
	auto	_goToMouse() -> void;

	sf::RenderWindow*	_win 		= nullptr;

	Vector2f 	_location;
	Vector2f 	_velocity;
	Vector2f	_acceleration;

	float		_mass;

	float		_topSpeed = 10.f;

	Vector2f	_mousePos = {0.f, 0.f};

	sf::Shape*			_graphic 	= nullptr;
};

#endif /* __MOVER_HPP_INCLUDED__ */
