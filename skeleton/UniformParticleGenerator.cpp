#include "UniformParticleGenerator.h"

UniformParticleGenerator::UniformParticleGenerator() : ParticleGenerator(), index(0) {}

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

		if (index%2 == 0) {

			position.x = rand() % int(particleType.uniformParticle1.positionMax.x) + int(particleType.uniformParticle1.positionMin.x);
			position.y = rand() % int(particleType.uniformParticle1.positionMax.y) + int(particleType.uniformParticle1.positionMin.y);
			position.z = rand() % int(particleType.uniformParticle1.positionMax.z) + int(particleType.uniformParticle1.positionMin.z);

			velocity = particleType.uniformParticle1.velocityMax;

			particlesList.push_back(new Particle(position, velocity, particleType.uniformParticle1.radius, particleType.uniformParticle1.mass,
				particleType.uniformParticle1.shape, particleType.uniformParticle1.generation, particleType.uniformParticle1.life, particleType.uniformParticle1.color));

			position.x = rand() % int(particleType.uniformParticle2.positionMax.x) + int(particleType.uniformParticle2.positionMin.x);
			position.y = rand() % int(particleType.uniformParticle2.positionMax.y) + int(particleType.uniformParticle2.positionMin.y);
			position.z = rand() % int(particleType.uniformParticle2.positionMax.z) + int(particleType.uniformParticle2.positionMin.z);

			velocity = particleType.uniformParticle2.velocityMax;

			particlesList.push_back(new Particle(position, velocity, particleType.uniformParticle2.radius, particleType.uniformParticle2.mass,
				particleType.uniformParticle2.shape, particleType.uniformParticle2.generation, particleType.uniformParticle2.life, particleType.uniformParticle2.color));

		}
		else {

			position.x = rand() % int(particleType.uniformParticle3.positionMax.x) + int(particleType.uniformParticle3.positionMin.x);
			position.y = rand() % int(particleType.uniformParticle3.positionMax.y) + int(particleType.uniformParticle3.positionMin.y);
			position.z = rand() % int(particleType.uniformParticle3.positionMax.z) + int(particleType.uniformParticle3.positionMin.z);

			velocity = particleType.uniformParticle3.velocityMax;

			particlesList.push_back(new Particle(position, velocity, particleType.uniformParticle3.radius, particleType.uniformParticle3.mass,
				particleType.uniformParticle3.shape, particleType.uniformParticle3.generation, particleType.uniformParticle3.life, particleType.uniformParticle3.color));


			position.x = rand() % int(particleType.uniformParticle4.positionMax.x) + int(particleType.uniformParticle4.positionMin.x);
			position.y = rand() % int(particleType.uniformParticle4.positionMax.y) + int(particleType.uniformParticle4.positionMin.y);
			position.z = rand() % int(particleType.uniformParticle4.positionMax.z) + int(particleType.uniformParticle4.positionMin.z);

			velocity = particleType.uniformParticle4.velocityMax;

			particlesList.push_back(new Particle(position, velocity, particleType.uniformParticle4.radius, particleType.uniformParticle4.mass,
				particleType.uniformParticle4.shape, particleType.uniformParticle4.generation, particleType.uniformParticle4.life, particleType.uniformParticle4.color));

		}
		++index;
	}

	return particlesList;
}