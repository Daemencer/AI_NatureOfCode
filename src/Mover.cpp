#include <iostream>

#include <SFML/System.hpp>

#include "Mover.hpp"


Mover::Mover(sf::RenderWindow* win):
	_win(win),
	_location({0.f, 0.f}),
	_velocity({0.f, 0.f}),
	_graphic(new sf::CircleShape(20))
{
	_graphic->setFillColor(sf::Color(170, 170, 170, 255));
	_graphic->setOutlineColor(sf::Color(50, 50, 50, 255));
	_graphic->setOutlineThickness(2);
}

Mover::Mover(sf::RenderWindow* win, float xPos, float yPos):
	_win(win),
	_location({xPos, yPos}),
	_velocity({0.f, 0.f}),
	_graphic(new sf::CircleShape(20))
{
	_graphic->setFillColor(sf::Color(170, 170, 170, 255));
	_graphic->setOutlineColor(sf::Color(50, 50, 50, 255));
	_graphic->setOutlineThickness(2);
}


Mover::Mover(sf::RenderWindow* win, float xPos, float yPos, float xVelocity, float yVelocity):
	_win(win),
    _location({xPos, yPos}),
    _velocity({xVelocity, yVelocity}),
    _graphic(new sf::CircleShape(20))
{
    _graphic->setFillColor(sf::Color(170, 170, 170, 255));
    _graphic->setOutlineColor(sf::Color(50, 50, 50, 255));
    _graphic->setOutlineThickness(2);
}


Mover::Mover(sf::RenderWindow* win, float xPos, float yPos, float xVelocity, float yVelocity, float xAcc, float yAcc):
	_win(win),
    _location({xPos, yPos}),
    _velocity({xVelocity, yVelocity}),
	_acceleration({xAcc, yAcc}),
    _graphic(new sf::CircleShape(20))
{
	_graphic->setFillColor(sf::Color(170, 170, 170, 255));
    _graphic->setOutlineColor(sf::Color(50, 50, 50, 255));
    _graphic->setOutlineThickness(2);
}


Mover::Mover(sf::RenderWindow* win, const Vector2f& p):
    _win(win),
    _location({p.x, p.y}),
    _velocity({0.f, 0.f}),
    _graphic(new sf::CircleShape(20))
{
    _graphic->setFillColor(sf::Color(170, 170, 170, 255));
    _graphic->setOutlineColor(sf::Color(50, 50, 50, 255));
    _graphic->setOutlineThickness(2);
}


Mover::Mover(sf::RenderWindow* win, const Vector2f& p, const Vector2f& v):
	_win(win),
    _location({p.x, p.y}),
    _velocity({v.x, v.y}),
    _graphic(new sf::CircleShape(20))
{
    _graphic->setFillColor(sf::Color(170, 170, 170, 255));
    _graphic->setOutlineColor(sf::Color(50, 50, 50, 255));
    _graphic->setOutlineThickness(2);
}


Mover::Mover(sf::RenderWindow* win, const Vector2f& p, const Vector2f& v, const Vector2f& a):
    _win(win),
    _location({p.x, p.y}),
    _velocity({v.x, v.y}),
	_acceleration({a.x, a.y}),
    _graphic(new sf::CircleShape(20))
{
    _graphic->setFillColor(sf::Color(170, 170, 170, 255));
    _graphic->setOutlineColor(sf::Color(50, 50, 50, 255));
    _graphic->setOutlineThickness(2);
}


Mover::~Mover()
{
	_win = nullptr;
	delete _graphic;
}


auto	Mover::update() -> void
{
//	_goToMouse();

	_velocity.add(_acceleration);
	_velocity.limit(_topSpeed);
	_location.add(_velocity);
	_checkEdges();
	_graphic->setPosition(_location.x, _location.y);

	_acceleration.mult(0);
}


auto	Mover::draw() -> void
{
	_win->draw(*_graphic);
}


auto	Mover::applyForce(const Vector2f& force) -> void
{
	auto vec = force.div(_mass);
	_acceleration.add(vec);
}


auto	Mover::_checkEdges() -> void
{
	auto size = _win->getSize();

	float width = size.x;
	float height = size.y;

	if (_location.x > width || _location.x < 0)		_velocity.x = -_velocity.x;
	if (_location.y > height || _location.y < 0)	_velocity.y = -_velocity.y;
}


auto	Mover::_goToMouse() -> void
{
	Vector2f v = {_mousePos.x - _location.x, _mousePos.y - _location.y};

	auto	magAcceleration = v.dist({_mousePos.x, _mousePos.y});

	v.normalize();

	v.mult(magAcceleration / 1000.f);

	_acceleration = v;
}
