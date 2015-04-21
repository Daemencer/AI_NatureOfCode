#include "Vector2.hpp"

class Mover
{
public:
	Mover() = default;
	Mover(const Mover&) = default;
	auto	operator = (const Mover&) -> Mover&;
	~Mover() = default;

private:
	Vector2f _location;
	Vector2f _velocity;
};
