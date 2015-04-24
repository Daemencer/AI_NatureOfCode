#include "Attractor.hpp"

#include "Mover.hpp"

Attractor::Attractor(sf::RenderWindow* win, float x, float y, float m)
{
	initialize(win, x, y, m);
}


Attractor::~Attractor()
{
	shutdown();
}


auto	Attractor::initialize(sf::RenderWindow* win, float x, float y, float m) -> void
{
	_win = win;
	_location.x = x;
	_location.y = y;
	_mass = m;

	_graphic->setPosition(_location.x, _location.y);
	_graphic->setRadius(_mass * 2.f);
    _graphic->setFillColor(sf::Color(100, 100, 100, 255));
    _graphic->setOutlineColor(sf::Color(50, 50, 50, 255));
    _graphic->setOutlineThickness(_mass / 4);
    _graphic->setOrigin(_mass, _mass);
}


auto	Attractor::shutdown() -> void
{
	_win = nullptr;
	delete _graphic;
}


auto	Attractor::draw() -> void
{
	_win->draw(*_graphic);
}


auto	Attractor::attract(const Mover& m) -> Vector2f
{
	Vector2f force;
	float dist;
	float strength;

	force = Vector2f::sub(_location, m.getLocation());
	dist = force.mag();

	dist = dist < 5.f ? 5.f : (dist > 25.f ? 25.f : dist);

	force.normalize();

	strength = (GRAVITATIONAL_CONSTANT * _mass * m.getMass()) / (dist * dist);

	force.mult(strength);

	return force;
}
