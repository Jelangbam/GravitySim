#include "forces.hpp"
#include "particle.hpp"
#include <cmath>
#include <iostream>

#define FORCE_CONSTANT 1.0
namespace forces {
	double magnitude(const std::array<double, 3>& vector) {
		auto result = 0.0;
		for(int i = 0; i < 3; i++) {
			result += vector[i]*vector[i];
		}
		return std::pow(result, 0.5);
	}

    std::array<double, 3> rsquared(const Particle& a, const Particle& b) {
		std::array<double, 3> force;
		std::array<double, 3> aPos = a.getPosition();
		std::array<double, 3> bPos = b.getPosition();
		double mag;

        //distance vector between the two objects
		for(int i = 0; i < 3; i++) {
			force[i] = bPos[i] - aPos[i];
		}
		mag = magnitude(force);

		for(int i = 0; i < 3; i++) {
			//divide by magnitude once to get unit vector, and then divide twice more for 1/r^2
			force[i] *= FORCE_CONSTANT / std::pow(mag, 3);
		}
		return force;
	}
}
