#ifndef FORCES_HPP
#define FORCES_HPP
#include <array>
#include "particle.hpp"
namespace forces {
    /**
     * Returns the magnitude of the 3 dimensional array
     * @Param vector input 3 element array
     */
	double magnitude(const std::array<double, 3>& vector);
	/**
     * Returns the force on particle a *by* particle b
     * @Param a first particle
     * @Param b second particle
     */
	std::array<double, 3> rsquared(const Particle& a, const Particle& b);
}

#endif //FORCES_HPP
