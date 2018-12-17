#include <vector>
#include "simulator.hpp"
#include "particle.hpp"

#define STEPS 10000000

int main() {
	auto test = Simulator(0.0000001);
	std::vector<Particle> state = test.getState();
	test.writeOutput(true);
	for(int i = 0; i < STEPS; i++) {
        if(i % 100000 == 0 && i != 0) {
            test.writeOutput();
        }
        test.next();
	}
	test.writeOutput();
}
