#include <iostream>
#include <fstream>
#include <vector>
#include <array>
#include "simulator.hpp"
#include "particle.hpp"
#include "forces.hpp"

#define FILENAME "output.txt"

void Simulator::changeTimestep(const double newTimestep) {
	timestep = newTimestep;
}

Simulator::Simulator(const double initTimestep) {
	timestep = initTimestep;
	time = 0.0;
	// Testing with a particle starting at the origin moving right with mass 1
	auto a = Particle({0.0, 0.1, 0.0}, {-0.1, 0.0, 0.0}, 1.0);
	auto b = Particle({0.0, -0.1, 0.0}, {0.1, 0.0, 0.0}, 1.0);
	particles.push_back(a);
	particles.push_back(b);
}

void Simulator::next() {
	//TODO: multithread this calculation
	//pre force calculation update
	for(auto &x : particles) {
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
	time += timestep;
}

double Simulator::getTime() const {
    return time;
}
std::vector<Particle> Simulator::getState() const {
	return particles;
}

void Simulator::writeOutput(bool newFile) {
    newFile ? outputFile.open(FILENAME): outputFile.open(FILENAME, std::ios_base::app);
    for(auto i = 0; i < (int) particles.size(); i++) {
        outputFile << std::to_string(time) << " " << std::to_string(i) << " " << particles[i].printData() << "\n";
    }
    outputFile << std::flush;
    outputFile.close();
}

void Simulator::writeOutput() {
    Simulator::writeOutput(false);
}
