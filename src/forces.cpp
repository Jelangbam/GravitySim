#include "forces.h"
#include "particle.h"
#include <cmath>
#define FORCE_CONSTANT 1
namespace forces {
	double magnitude(const std::array<double, 3> vector) {
		double result = 0.0;
		for(int i = 0; i < 3; i++) {
			result += vector[i]*vector[i];
		}
		return std::pow(result, 0.5);
	}
	/**
	 * Force on particle A by particle B
	 */
	std::array<double, 3> rsquared(const Particle a, const Particle b) {
		std::array<double, 3> force;
		std::array<double, 3> aPos = a.getPosition();
		std::array<double, 3> bPos = b.getPosition();
		
		for(int i = 0; i < 3; i++) {
			force[i] = bPos[i] - aPos[i]; 
		}
		for(int i = 0; i < 3; i++) {
			//divide by magnitude once to get unit vector, and then divide twice more for 1/r^2
			force[i] *= FORCE_CONSTANT / std::pow(magnitude(force), 3);
		}
		return force;
	}
}
