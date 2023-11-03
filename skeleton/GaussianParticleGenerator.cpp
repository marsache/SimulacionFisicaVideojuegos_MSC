#include "GaussianParticleGenerator.h"

GaussianParticleGenerator::GaussianParticleGenerator() : ParticleGenerator() {}

list<Particle*> GaussianParticleGenerator::generateParticles() {
	list<Particle*> particlesList;
	ParticleTypes particleType;

	std::random_device rd{};
	std::mt19937 gen{ rd() };

	//std::normal_distribution<double> d{ 5.0, 2.0 };
	//std::normal_distribution<double> pos{ 70.0, 10.0 };
	std::normal_distribution<double> pos{ particleType.gaussianParticle.positionMin.x, particleType.gaussianParticle.positionMax.x };
	std::normal_distribution<double> vel{ particleType.gaussianParticle.velocityMin.x, particleType.gaussianParticle.velocityMax.x };

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

		particlesList.push_back(new Particle(meanPos, meanVel, particleType.gaussianParticle.radius, particleType.gaussianParticle.mass, 
			&PxSphereGeometry(particleType.gaussianParticle.radius), particleType.gaussianParticle.generation, GAUSSIAN_PARTICLE_LIFE));
	}

	return particlesList;
}