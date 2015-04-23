#include "Liquid.hpp"

Liquid::Liquid(sf::RenderWindow* win, float x, float y, float w, float h, float c)
{
	_graphic = new sf::RectangleShape();
	initialize(win, x, y, w, h, c);
}


Liquid::~Liquid()
{
	shutdown();
}


auto	Liquid::initialize(sf::RenderWindow* win, float x, float y, float w, float h, float c) -> void
{
	_win = win;

	_x = x;
	_y = y;
	_w = w;
	_h = h;

	_c = c;

	_graphic->setPosition({_x, _y});
	_graphic->setSize({_w, _h});
	_graphic->setOrigin(_w / 2, _h / 2);
	_graphic->setFillColor(sf::Color(0, 50, 255, 150));
}


auto	Liquid::shutdown() -> void
{
	_win = nullptr;
	delete _graphic;
}


auto	Liquid::draw() -> void
{
	_win->draw(*_graphic);
}


auto    Liquid::getLocation() const -> Vector2f
{
	return {_x - _w / 2, _y - _h / 2};
}


auto    Liquid::setLocation(float x, float y) -> void
{
	_x = x;
	_y = y;
}


auto    Liquid::setLocation(const Vector2f& v) -> void
{
	_x = v.x;
	_y = v.y;
}


auto    Liquid::getSize() const -> Vector2f
{
	return {_w, _h};
}


auto    Liquid::setSize(float w, float h) -> void
{
	_w = w;
	_h = h;
}


auto    Liquid::setSize(const Vector2f& v) -> void
{
	_w = v.x;
	_h = v.y;
}
