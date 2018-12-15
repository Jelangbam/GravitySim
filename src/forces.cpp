#include "forces.h"
#include "particle.h"
#include <cmath>
#define FORCE_CONSTANT 1
namespace forces {
    /**
     * Returns the magnitude of the 3 dimensional array
     * @Param vector input 3 element array
     */
	double magnitude(const std::array<double, 3>& vector) {
		auto result = 0.0;
		for(int i = 0; i < 3; i++) {
			result += vector[i]*vector[i];
		}
		return std::pow(result, 0.5);
	}
	/**
	 * Force on particle A by particle B
	 * @Param a The first particle
	 * @Param b The second particle that acts on the first
	 */
	std::array<double, 3> rsquared(const Particle& a, const Particle& b) {
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
