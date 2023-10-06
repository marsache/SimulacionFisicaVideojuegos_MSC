#include "ParticleSystem.h"

ParticleSystem::ParticleSystem() {

}

ParticleSystem::~ParticleSystem() {}

void ParticleSystem::update(double t) {
	// parámetros randomizados
	// posición
	// int randNum = rand()%(max-min + 1) + min;
	int posX = rand() % (PARTICLE_POS_FIN - PARTICLE_POS_INI + 1) + PARTICLE_POS_INI;
	int posY = rand() % (PARTICLE_POS_FIN - PARTICLE_POS_INI + 1) + PARTICLE_POS_INI;
	int posZ = rand() % (PARTICLE_POS_FIN - PARTICLE_POS_INI + 1) + PARTICLE_POS_INI;

	particles.push_back(new Particle(Vector3(posX, posY, posZ), PARTICLE_DIR,
		PARTICLE_RADIUS, 0.5, &PxSphereGeometry(PARTICLE_RADIUS)));
}

void ParticleSystem::generateFireworkSystem() {

}