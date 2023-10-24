#include "UniformParticleGenerator.h"

UniformParticleGenerator::UniformParticleGenerator() : ParticleGenerator() {

}

list<Particle*> UniformParticleGenerator::generateParticles() {
	list<Particle*> particlesList;

	// cambiar velocidad
	for (int i = 0; i < UNIFORM_PARTICLES; ++i) {
		// cálculo de la posición
	// como es nieve, las coordenadas y, z varían mucho menos que la x
		meanPos.x = rand() % MAX_X;
		meanPos.y = rand() % MAX_YZ + MIN_YZ;
		meanPos.z = rand() % MAX_YZ + MIN_YZ;

		particlesList.push_back(new Particle(meanPos, Vector3(0, -3, 0), UNIFORM_PARTICLE_RADIUS, 5, &PxSphereGeometry(UNIFORM_PARTICLE_RADIUS), 1, UNIFORM_PARTICLE_LIFE));
	}

	return particlesList;
}