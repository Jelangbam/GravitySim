#include <array>
#include <iostream>
#include "particle.hpp"


Particle::Particle(const std::array<double, 3> &initPosition, const std::array<double, 3> &initVelocity, const double initMass) {
	velocity = initVelocity;
	position = initPosition;
	mass = initMass;
	acceleration = {0.0, 0.0, 0.0};
}

void Particle::updateHalfVelocity(const double timestep) {
	for(int i = 0; i < 3; i++) {
		velocity[i] += + 0.5 * timestep * acceleration[i];
	}
}

void Particle::updatePosition(const double timestep) {
	for(int i = 0; i < 3; i++) {
		position[i] += + velocity[i] * timestep;
	}
}

void Particle::updateAcceleration(const std::array<double, 3>& force) {
	for(int i = 0; i < 3; i++) {
		acceleration[i] = force[i] / mass;
	}
}

std::array<double, 3> Particle::getPosition() const {
	return position;
}

double Particle::getMass() const {
	return mass;
}

void Particle::update1(const double timestep) {
	updateHalfVelocity(timestep);
	updatePosition(timestep);
}

void Particle::update2(const double timestep, const std::array<double, 3>& force) {
	updateAcceleration(force);
	updateHalfVelocity(timestep);
}

void Particle::printData() const {
	std::cout << position[0] << " " << position[1] << " " << position[2] << std::endl;
}
