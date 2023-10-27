#include "FireworkParticleGenerator.h"

list<Particle*> FireworkParticleGenerator::generateParticles() {
	list<Particle*> particlesList;

	// c�lculo de la posici�n
	// como es nieve, las coordenadas y, z var�an mucho menos que la x
	ParticleTypes particleType;
	Vector3 position, velocity;

	position.x = rand() % int(particleType.particle3.positionMin.x) + int(particleType.particle3.positionMin.x);
	position.y = rand() % int(particleType.particle3.positionMax.y) + int(particleType.particle3.positionMin.y);
	position.z = rand() % int(particleType.particle3.positionMax.z) + int(particleType.particle3.positionMin.z);

	// generaci�n de la velocidad
	velocity.x = rand() % int(particleType.particle3.velocityMin.x) + int(particleType.particle3.velocityMax.x);
	velocity.y = rand() % int(particleType.particle3.velocityMin.y) + int(particleType.particle3.velocityMax.y);
	velocity.z = rand() % int(particleType.particle3.velocityMin.z) + int(particleType.particle3.velocityMax.z);

	particlesList.push_back(new Firework(position, velocity, particleType.particle3.radius - 2, particleType.particle3.mass,
		&PxSphereGeometry(particleType.particle3.radius), particleType.particle3.generation, particleType.particle3.life));

	return particlesList;
}

Firework* FireworkParticleGenerator::generateParticle() {
	// c�lculo de la posici�n
	// como es nieve, las coordenadas y, z var�an mucho menos que la x
	ParticleTypes particleType;
	Vector3 position, velocity;

	position.x = rand() % int(particleType.particle3.positionMin.x) + int(particleType.particle3.positionMin.x);
	position.y = rand() % int(particleType.particle3.positionMax.y) + int(particleType.particle3.positionMin.y);
	position.z = rand() % int(particleType.particle3.positionMax.z) + int(particleType.particle3.positionMin.z);

	// generaci�n de la velocidad
	velocity.x = rand() % int(particleType.particle3.velocityMin.x) + int(particleType.particle3.velocityMax.x);
	velocity.y = rand() % int(particleType.particle3.velocityMin.y) + int(particleType.particle3.velocityMax.y);
	velocity.z = rand() % int(particleType.particle3.velocityMin.z) + int(particleType.particle3.velocityMax.z);

	return new Firework(position, velocity, particleType.particle3.radius - 2, particleType.particle3.mass, &PxSphereGeometry(particleType.particle3.radius), particleType.particle3.generation, particleType.particle3.life);
}