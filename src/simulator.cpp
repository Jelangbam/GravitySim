#include <iostream>
#include <fstream>
#include <vector>
#include <array>
#include "simulator.h"
#include "particle.h"
#include "forces.h"

void Simulator::changeTimestep(const double newTimestep) {
	timestep = newTimestep;
}

Simulator::Simulator(const double initTimestep) {
	timestep = initTimestep;
	time = 0.0;
	// Testing with a particle starting at the origin moving right with mass 1	
	Particle a = Particle({1, 0.01, 0.0}, {-0.1, 0.0, 0.0}, 1.0);
	Particle b = Particle({0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, 1.0);
	particles.push_back(a); 
	particles.push_back(b);
}

void Simulator::next() {
	//TODO: multithread this calculation
	//pre force calculation update
	for(Particle &x : particles) {
		x.update1(timestep);
	}
	//force calculation
	std::vector<std::array<double, 3>> forces(particles.size());
	const std::array<double, 3> initialForce = {0.0, 0.0, 0.0};
	std::fill(forces.begin(), forces.end(), initialForce);

	for(int i = 0; i < (int) particles.size(); i++) {
		for(int j = i+1; j < (int) particles.size(); j++) {
			const std::array<double, 3> forceab = forces::rsquared(particles[i], particles[j]);
			for(int k = 0; k < 3; k++) {
				forces[i][k] += forceab[k];
				forces[j][k] -= forceab[k];
			}
		}
	}

	//finish update of timestep
		for(int i = 0; i < (int) particles.size(); i++) {
		particles[i].update2(timestep, forces[i]);
	}
}

std::vector<Particle> Simulator::getState() const {
	return particles;
}
