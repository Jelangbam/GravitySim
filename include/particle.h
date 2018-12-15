#ifndef PARTICLE_H
#define PARTICLE_H

#include <array>
class Particle {
	private:
		double mass;
		std::array<double, 3> acceleration;
		std::array<double, 3> velocity;
		std::array<double, 3> position;
		void updateHalfVelocity(const double timestep);
		void updatePosition(const double timestep);
		void updateAcceleration(const std::array<double, 3>& force);
	public:
		Particle(const std::array<double, 3>& initPosition, const std::array<double, 3>& initVelocity, const double initMass);
		std::array<double, 3> getPosition() const;
		double getMass() const;
		void update1(const double timestep);
		void update2(const double timestep, const std::array<double, 3>& force);
		void printData() const;
};
#endif
