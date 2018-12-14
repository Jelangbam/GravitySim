#ifndef FORCES_H
#define FORCES_H
#include <array>
#include "particle.h"
namespace forces {
	double magnitude(const std::array<double, 3> vector);
	std::array<double, 3> rsquared(const Particle a, const Particle b);
}

#endif