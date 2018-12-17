#include <vector>
#include "simulator.hpp"
#include "particle.hpp"

int main() {
	auto test = Simulator(0.01);
	std::vector<Particle> state = test.getState();
	test.writeOutput(true);
	for(int i = 0; i < 101; i++) {
		test.next();
	}
	state = test.getState();
	test.writeOutput();
}
