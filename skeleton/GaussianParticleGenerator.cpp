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
		position.x = round(pos(gen));
		position.y = round(pos(gen));
		position.z = round(pos(gen));

		// generación de la velocidad
		velocity.x = round(vel(gen));
		velocity.y = round(vel(gen));
		velocity.z = round(vel(gen));

		particlesList.push_back(new Particle(position, velocity, particleType.gaussianParticle.radius, particleType.gaussianParticle.mass,
			&PxSphereGeometry(particleType.gaussianParticle.radius), particleType.gaussianParticle.generation, GAUSSIAN_PARTICLE_LIFE));
	}

	return particlesList;
}