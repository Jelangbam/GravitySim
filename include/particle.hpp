#ifndef PARTICLE_HPP
#define PARTICLE_HPP
#include <string>
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
		/**
		 * Returns current position of particle as an array
		 */
		std::array<double, 3> getPosition() const;
		/**
		 * Returns mass of particle
		 */
		double getMass() const;
		/**
		 * Performs the pre-force calculation in the velocity-verlet algorithm
		 * Use before calculating forces
		 * @Param timestep amount of time to be forwarded in this step
		 */
		void update1(const double timestep);
		/**
		 * Finishes updating the particle's information for the timestep after force calculation
		 * @Param timestep Use same value as update1
		 * @Param force The force vector on the particle
		 */
		void update2(const double timestep, const std::array<double, 3>& force);
		/**
		 * Prints the particle's location
		 */
		std::string printData() const;
};
#endif //Particle_HPP
