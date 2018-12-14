#ifndef SIMULATOR_H
#define SIMULATOR_H

#include <vector>
#include "particle.h"

class Simulator {
	private:
		double timestep;
		std::vector<Particle> particles;
		double time;
	public:
		void changeTimestep(const double newTimestep);
		Simulator(const double initTimestep);
		void next();
		std::vector<Particle> getState() const;
};
#endif
