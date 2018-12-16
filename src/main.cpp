#include <vector>
#include "simulator.hpp"
#include "particle.hpp"

int main() {
	auto test = Simulator(0.01);
	std::vector<Particle> state = test.getState();
	state[0].printData();
	for(int i = 0; i < 101; i++) {
		test.next();
	}
	state = test.getState();
	state[0].printData();
}
