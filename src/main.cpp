#include <stdlib.h>
#include <iostream>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>

#include "Vector2.hpp"
#include "Mover.hpp"
#include "Utils.hpp"

sf::RenderWindow* window = new sf::RenderWindow(sf::VideoMode(800, 600), "Ecosystem");

int main(int ac, char* av[])
{
	(void)ac, (void)av;

	Mover* movers[10];

	for (unsigned int i = 0u; i < 10; ++i)
	{
		movers[i] = new Mover(window, 100.f, 100.f);
		movers[i]->setMass(Utils::random(0.1f, 5.f));
	}

	window->setFramerateLimit(60);

	while (window->isOpen())
	{
	   	sf::Event event;
	   	while (window->pollEvent(event))
	   	{
	       	if (event.type == sf::Event::Closed)
		    	window->close();

			if (event.type == sf::Event::KeyPressed)
			{
				if (event.key.code == sf::Keyboard::Escape)
					window->close();
			}
   		}

   		window->clear();

		for (unsigned int i = 0u; i < 10; ++i)
		{
			movers[i]->applyForce({.01f, 0.f});

			auto m = movers[i]->getMass();
			Vector2f gravity(0.f, 0.1 * m);
			movers[i]->applyForce(gravity);

			movers[i]->update();
			movers[i]->draw();
		}

   		window->display();
	}

	delete window;

	return EXIT_SUCCESS;
}
