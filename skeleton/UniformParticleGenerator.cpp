#include "UniformParticleGenerator.h"

UniformParticleGenerator::UniformParticleGenerator() : ParticleGenerator() {

}

list<Particle*> UniformParticleGenerator::generateParticles() {
	list<Particle*> particlesList;

	// cálculo de la posición
	// como es nieve, las coordenadas y, z varían mucho menos que la x
	meanPos.x = rand() % MAX_X;
	meanPos.y = rand() % MAX_YZ + MIN_YZ;
	meanPos.z = rand() % MAX_YZ + MIN_YZ;

	// cambiar velocidad
	for (int i = 0; i < UNIFORM_PARTICLES; ++i) {
		particlesList.push_back(new Particle(meanPos, Vector3(0, -3, 0), PARTICLE_RADIUS, 5, &PxSphereGeometry(PARTICLE_RADIUS)));
	}

	return particlesList;
}