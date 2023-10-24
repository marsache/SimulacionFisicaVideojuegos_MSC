#include "GaussianParticleGenerator.h"

GaussianParticleGenerator::GaussianParticleGenerator() : ParticleGenerator() {}

list<Particle*> GaussianParticleGenerator::generateParticles() {
	list<Particle*> particlesList;

	// cálculo de la posición
	// como es nieve, las coordenadas y, z varían mucho menos que la x
	/*meanPos.x = rand() % MAX_X;
	meanPos.y = rand() % MAX_YZ + MIN_YZ;
	meanPos.z = rand() % MAX_YZ + MIN_YZ;*/

	std::random_device rd{};
	std::mt19937 gen{ rd() };

	//std::normal_distribution<double> d{ 5.0, 2.0 };
	std::normal_distribution<double> pos{ 70.0, 10.0 };
	std::normal_distribution<double> vel{ 0.0, 1.0 };

	//auto random_double = [&d, &gen] { return d(gen); };


	for (int i = 0; i < GAUSSIAN_PARTICLES; ++i) {
		// generación de la posición
		meanPos.x = round(pos(gen));
		meanPos.y = round(pos(gen));
		meanPos.z = round(pos(gen));

		// generación de la velocidad
		meanVel.x = round(vel(gen));
		meanVel.y = round(vel(gen));
		meanVel.z = round(vel(gen));

		particlesList.push_back(new Particle(meanPos, meanVel, PARTICLE_RADIUS, 5, &PxSphereGeometry(PARTICLE_RADIUS), 1, GAUSSIAN_PARTICLE_LIFE));
	}

	return particlesList;
}