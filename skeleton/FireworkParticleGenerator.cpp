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

	return new Firework(position, velocity, particleType.particle3.radius - 2, particleType.particle3.mass, 
		&PxSphereGeometry(particleType.particle3.radius), particleType.particle3.generation, particleType.particle3.life);
}

list<Firework*> FireworkParticleGenerator::createChildren(Firework* parent) {
	ParticleTypes particleTypes;
	int particlesToCreate, life;
	float radius, mass;
	// por limpiar
	switch (parent->getGen()) {
	case 3:
		particlesToCreate = 4;
		radius = particleTypes.particle2.radius;
		mass = particleTypes.particle2.mass;
		life = particleTypes.particle2.life;
		break;
	case 2:
		particlesToCreate = 4;
		radius = particleTypes.particle1.radius;
		mass = particleTypes.particle1.mass;
		life = particleTypes.particle1.life;
		break;
	case 1:
		particlesToCreate = 5;
		radius = particleTypes.particle0.radius;
		mass = particleTypes.particle0.mass;
		life = particleTypes.particle0.life;
		break;
	case 0:
		particlesToCreate = 0;
		radius = 0;
		break;
	}

	list <Firework*> fireworks;
	for (int i = 0; i < particlesToCreate; i++) {
		Vector3 velocity;
		int R = 50 / particlesToCreate;
		float degrees = 360.0 / particlesToCreate;
		// c�lculo de la velocidad
		int velMin = degrees * i + 1;
		int velMax = degrees * i;
		velocity.x = R * cos(rand() % velMin + velMax);
		velocity.y = R * sin(rand() % velMin + velMax);
		velocity.z = rand() % 1;

		fireworks.push_back(new Firework(parent->getPosition(), velocity, radius, mass,
			&PxSphereGeometry(radius), parent->getGen() - 1, life));
	}

	return fireworks;
}