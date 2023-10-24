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

	std::normal_distribution<double> d{ 5.0, 2.0 };

	auto random_double = [&d, &gen] { return d(gen); };

	// cambiar velocidad
	for (int i = 0; i < GAUSSIAN_PARTICLES; ++i) {
		particlesList.push_back(new Particle(meanPos, Vector3(0, -3, 0), PARTICLE_RADIUS, 5, &PxSphereGeometry(PARTICLE_RADIUS), 1));
	}

	return particlesList;
}