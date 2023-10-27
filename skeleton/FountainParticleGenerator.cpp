#include "FountainParticleGenerator.h"

list<Particle*> FountainParticleGenerator::generateParticles() {
	list<Particle*> particlesList;

	for (int i = 0; i < FOUNTAIN_PARTICLES; ++i) {
		// c�lculo de la posici�n
		// como es nieve, las coordenadas y, z var�an mucho menos que la x
		ParticleTypes particleType;
		Vector3 position, velocity;

		position.x = rand() % int(particleType.fountainParticle.positionMin.x) + int(particleType.fountainParticle.positionMin.x);
		position.y = rand() % int(particleType.fountainParticle.positionMax.y) + int(particleType.fountainParticle.positionMin.y);
		position.z = rand() % int(particleType.fountainParticle.positionMax.z) + int(particleType.fountainParticle.positionMin.z);

		// generaci�n de la velocidad
		velocity.x = rand() % int(particleType.fountainParticle.velocityMin.x) + int(particleType.fountainParticle.velocityMax.x);
		velocity.y = rand() % int(particleType.fountainParticle.velocityMin.y) + int(particleType.fountainParticle.velocityMax.y);
		velocity.z = rand() % int(particleType.fountainParticle.velocityMin.z) + int(particleType.fountainParticle.velocityMax.z);

		particlesList.push_back(new Particle(position, velocity, particleType.fountainParticle.radius, particleType.fountainParticle.mass,
			&PxSphereGeometry(particleType.fountainParticle.radius), particleType.fountainParticle.generation, particleType.fountainParticle.life));
	}

	return particlesList;
}