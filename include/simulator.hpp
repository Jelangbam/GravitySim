#ifndef SIMULATOR_HPP
#define SIMULATOR_HPP
#include <fstream>
#include <vector>
#include "particle.hpp"

class Simulator {
	private:
		double timestep;
		std::vector<Particle> particles;
		std::ofstream outputFile;
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
		/**
		 * Returns the current time in the simulation
		 */
		double getTime() const;
		/**
		 * Writes current state of simulation to file
		 */
		void writeOutput();
};
#endif // SIMULATOR_HPP
