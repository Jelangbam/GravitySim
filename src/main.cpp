#include <vector>
#include "simulator.h"
#include "particle.h"

int main() {
	Simulator test = Simulator(0.01);
	std::vector<Particle> state = test.getState();
	state[0].printData();
	for(int i = 0; i < 101; i++) {
		test.next();
	}	
	state = test.getState();
	state[0].printData();
}