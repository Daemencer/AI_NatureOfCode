#ifndef __UTILS_HPP_INCLUDED__
#define __UTILS_HPP_INCLUDED__

#include <cstdlib>

namespace Utils {


auto	random(float min = 0.f, float max = 1.f) -> float
{
	int rand = std::rand() % 100;

	return (((max - min) * ((float)rand - 0.f)) / (100.f - 0.f) + min);
}


} // namespace Utils

#endif /* __UTILS_HPP_INCLUDED__ */
