#include <iostream>

#include <SFML/System.hpp>

#include "Mover.hpp"


Vector2f Mover::gravity = {0.f, .1f};


Mover::Mover(sf::RenderWindow* win)
{
	initialize(win);
}

Mover::Mover(sf::RenderWindow* win, float xPos, float yPos):
	_location({xPos, yPos})
{
	initialize(win);
}


Mover::Mover(sf::RenderWindow* win, float xPos, float yPos, float xVelocity, float yVelocity):
    _location({xPos, yPos}),
    _velocity({xVelocity, yVelocity})
{
	initialize(win);
}


Mover::Mover(sf::RenderWindow* win, float xPos, float yPos, float xVelocity, float yVelocity, float xAcc, float yAcc):
    _location({xPos, yPos}),
    _velocity({xVelocity, yVelocity}),
	_acceleration({xAcc, yAcc})
{
	initialize(win);
}


Mover::Mover(sf::RenderWindow* win, const Vector2f& p):
    _location({p.x, p.y})
{
	initialize(win);
}


Mover::Mover(sf::RenderWindow* win, const Vector2f& p, const Vector2f& v):
    _location({p.x, p.y}),
    _velocity({v.x, v.y})
{
	initialize(win);
}


Mover::Mover(sf::RenderWindow* win, const Vector2f& p, const Vector2f& v, const Vector2f& a):
    _location({p.x, p.y}),
    _velocity({v.x, v.y}),
	_acceleration({a.x, a.y})
{
	initialize(win);
}


auto	Mover::initialize(sf::RenderWindow* win) -> void
{
	_win = win;

	_graphic->setFillColor(sf::Color(170, 170, 170, 255));
    _graphic->setOutlineColor(sf::Color(50, 50, 50, 255));
    _graphic->setOutlineThickness(2);
	_graphic->setOrigin(10, 10);
}


auto	Mover::shutdown() -> void
{
	_win = nullptr;
	delete _graphic;
}


Mover::~Mover()
{
	shutdown();
}


auto	Mover::update() -> void
{
	_applyForces();

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


auto	Mover::isInsideLiquid(const Liquid& l) -> bool
{
	if ((_location.x + _graphic->getRadius()) >= l.getLocation().x 
	&& (_location.x - _graphic->getRadius()) <= (l.getLocation().x + l.getSize().x))
	{
		if ((_location.y + _graphic->getRadius()) >= l.getLocation().y 
		&& (_location.y - _graphic->getRadius()) <= (l.getLocation().y + l.getSize().y))
		{
			return true;
		}
	}

	return false;
}


auto    Mover::drag(const Liquid& l) -> void
{
    if (isInsideLiquid(l))
    {
        float speed = _velocity.mag();
        float dragMag = l.getCoefficient() * speed * speed;

        Vector2f drag = _velocity;
        drag.mult(-1);
        drag.normalize();
        drag.mult(dragMag);

        _applyForce(drag);
    }
}


auto	Mover::addForce(const Vector2f& f) -> void
{
	_customForces.push_back(f);
}


auto	Mover::_applyForce(const Vector2f& force) -> void
{
	auto vec = force.div(_mass);
	_acceleration.add(vec);
}


auto	Mover::_applyForces() -> void
{
	_applyGravity();
	_applyFriction();
	_applyCustomForces();
}


auto	Mover::_applyGravity() -> void
{
    Vector2f gravity(0.f, 0.3 * _mass);
    _applyForce(gravity);
}


auto	Mover::_applyFriction() -> void
{
	float 		normal;
	float 		frictionMag;
	Vector2f 	friction;

	normal = 1;
	frictionMag = _friction * normal;

	friction = _velocity;
	friction.mult(-1);
	friction.normalize();
	friction.mult(frictionMag);

	_applyForce(friction);
}


auto 	Mover::_applyCustomForces() -> void
{
	for (auto&& force : _customForces)
	{
		_applyForce(force);
	}

	_customForces.clear();
}


auto	Mover::_checkEdges() -> void
{
	auto size = _win->getSize();

	float width = size.x;
	float height = size.y;

	if (_location.x > (width -  _graphic->getRadius()))
	{
		_location.x = width - _graphic->getRadius();
		_velocity.x = -_velocity.x * .9f;
	}
	else if (_location.x < 0)
	{
		_location.x = _graphic->getRadius();
		_velocity.x = -_velocity.x * .9f;
	}


	if (_location.y > (height - _graphic->getRadius()))
	{
		_location.y = height - _graphic->getRadius();
		_velocity.y = -_velocity.y * .9f;
	}
	else if (_location.y < 0)
	{
		_location.y = _graphic->getRadius();
		_velocity.y = -_velocity.y * .9f;
	}
}


// experimental
auto	Mover::_goToMouse() -> void
{
	Vector2f v = {_mousePos.x - _location.x, _mousePos.y - _location.y};

	auto	magAcceleration = v.dist({_mousePos.x, _mousePos.y});

	v.normalize();

	v.mult(magAcceleration / 1000.f);

	_acceleration = v;
}
