#include "UniformParticleGenerator.h"

UniformParticleGenerator::UniformParticleGenerator() : ParticleGenerator() {}

UniformParticleGenerator::~UniformParticleGenerator() {
	delete(this);
}

list<Particle*> UniformParticleGenerator::generateParticles() {
	list<Particle*> particlesList;
	ParticleTypes particleType;

	// cambiar velocidad
	for (int i = 0; i < PARTICLES; ++i) {
		// cálculo de la posición
		// como es nieve, las coordenadas y, z varían mucho menos que la x

		// uso de rand():
		// v1 = rand() % 100;         // v1 in the range 0 to 99
		//v2 = rand() % 100 + 1;     // v2 in the range 1 to 100
		//v3 = rand() % 30 + 1985;   // v3 in the range 1985-2014 


		position.x = rand() % int(particleType.uniformParticle.positionMax.x) + int(particleType.uniformParticle.positionMin.x);
		position.y = rand() % int(particleType.uniformParticle.positionMax.y) + int(particleType.uniformParticle.positionMin.y);
		position.z = rand() % int(particleType.uniformParticle.positionMax.z) + int(particleType.uniformParticle.positionMin.z);

		velocity = particleType.uniformParticle.velocityMax;

		particlesList.push_back(new Particle(position, velocity, particleType.uniformParticle.radius, particleType.uniformParticle.mass, 
			particleType.uniformParticle.shape, particleType.uniformParticle.generation, particleType.uniformParticle.life, particleType.uniformParticle.color));
	}

	return particlesList;
}