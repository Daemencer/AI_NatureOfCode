#include <stdlib.h>
#include <iostream>

#include "Vector2.h"

int main(int ac, char* av[])
{
	(void)ac, (void)av;

	Vector2f v(10, 15);

	std::cout << "vector mag = " << v.mag() << std::endl;

	v.normalize();

	std::cout << v << std::endl;

	return EXIT_SUCCESS;
}
