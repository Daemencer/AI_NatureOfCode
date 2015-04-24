#ifndef __MOVER_HPP_INCLUDED__
#define __MOVER_HPP_INCLUDED__

#include <SFML/Graphics.hpp>

#include "Vector2.hpp"
#include "Liquid.hpp"

class Mover
{
public:
	Mover(sf::RenderWindow*
		, float xPos = 0.f, float yPos = 0.f
		, float xVelocity = 0.f, float yVelocity = 0.f
		, float xAcc = 0.f, float yAcc = 0.f
		, float mass = 5.f);
	Mover(sf::RenderWindow*
		, const Vector2f& p = {0.f, 0.f}
		, const Vector2f& v = {0.f, 0.f}
		, const Vector2f& a = {0.f, 0.f}
		, float mass = 5.f);
	Mover(const Mover&) = default; // todo
	auto	operator = (const Mover&) -> Mover&; // todo
	~Mover();

	auto	initialize(sf::RenderWindow*) -> void;
	auto	shutdown() -> void; 

	auto	update() -> void;
	auto	draw() -> void;

	auto	isInsideLiquid(const Liquid&) -> bool;

	auto	drag(const Liquid&) -> void;

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

	// force lasts for 1 frame (easier for now)
	auto	addForce(const Vector2f&) -> void;

private:
	auto	_checkEdges() -> void;
	auto	_applyForces() -> void;
	auto	_applyForce(const Vector2f&) -> void;
	auto	_applyGravity() -> void;
	auto	_applyFriction() -> void;
	auto	_applyCustomForces() -> void;


	// experimental functions
	auto	_goToMouse() -> void;

	// experimental members
	Vector2f	_mousePos = {0.f, 0.f};


	// static members
	static Vector2f	gravity;


	// contextual data
	sf::RenderWindow*	_win 		= nullptr;
	sf::CircleShape*	_graphic 	= new sf::CircleShape();


	// relevant data
	Vector2f 	_location 		= {0.f, 0.f};
	Vector2f 	_velocity 		= {0.f, 0.f};
	Vector2f	_acceleration 	= {0.f, 0.f};
	std::vector<Vector2f>		_customForces;


	// members (might move to a struct)
	float	_mass 		= 5.f;
	float	_friction	= 0.01;
	float	_topSpeed	= 10.f;
};

#endif /* __MOVER_HPP_INCLUDED__ */
