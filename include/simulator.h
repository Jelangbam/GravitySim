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
	    /**
	     * Change the timestep of the simulation
	     * @param newTimestep new interval of time to use per next()
	     */
		void changeTimestep(const double newTimestep);
		Simulator(const double initTimestep);
		/**
		 * Advance the simulation by one step
		 */
		void next();
		/**
		 * Returns the array of particles at the current time
		 */
		std::vector<Particle> getState() const;
};
#endif
