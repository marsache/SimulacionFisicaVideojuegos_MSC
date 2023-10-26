#include "ParticleSystem.h"

ParticleSystem::ParticleSystem() {

}

ParticleSystem::~ParticleSystem() {}

void ParticleSystem::update(double t) {
	// par�metros randomizados
	// posici�n
	// int randNum = rand()%(max-min + 1) + min;
	/*int posX = rand() % (PARTICLE_POS_FIN - PARTICLE_POS_INI + 1) + PARTICLE_POS_INI;
	int posY = rand() % (PARTICLE_POS_FIN - PARTICLE_POS_INI + 1) + PARTICLE_POS_INI;
	int posZ = rand() % (PARTICLE_POS_FIN - PARTICLE_POS_INI + 1) + PARTICLE_POS_INI;

	particles.push_back(new Particle(Vector3(posX, posY, posZ), PARTICLE_DIR,
		PARTICLE_RADIUS, 0.5, &PxSphereGeometry(PARTICLE_RADIUS)));*/

	// se actualizan todos los generadores
	// las part�culas se a�aden a la lista de part�culas del sistema
	for (auto itGenerators : particleGenerators) {
		for (auto itParticle : itGenerators->generateParticles())
			particles.push_back(itParticle);
	}

	// se actualizan todas las part�culas
	for (auto itParticles : particles) 
		itParticles->integratev2(t);

	// se eliminan las part�culas muertas
	deleteParticles();
}

void ParticleSystem::generateFireworkSystem() {

}

ParticleGenerator* ParticleSystem::getParticleGenerator(string name) {
	for (auto it : particleGenerators) {
		if (it->getName() == name)
			return it;
	}
}

void ParticleSystem::deleteParticles() {
	auto it = particles.begin();

	it = particles.begin();
	while (it != particles.end()) {
		if (!(*it)->isAlive()) {
			Particle* aux = (*it);
			it = particles.erase(it);
			delete(aux);
		}
		else
			++it;
	}
}

void ParticleSystem::createUniformParticleGenerator() {
	auto it = particleGenerators.begin();
	bool encontrado = false;
	while (!encontrado && it != particleGenerators.end()) {
		if ((*it)->getName() == "Uniform") {
			delete(*it);
			particleGenerators.erase(it);
			encontrado = true;
		}
		else
			++it;
	}

	if (!encontrado) {
		UniformParticleGenerator* uniformPG = new UniformParticleGenerator();
		uniformPG->setName("Uniform");

		particleGenerators.push_back(uniformPG);
	}
}

void ParticleSystem::createGaussianParticleGenerator() {
	auto it = particleGenerators.begin();
	bool encontrado = false;
	while (!encontrado && it != particleGenerators.end()) {
		if ((*it)->getName() == "Gaussian") {
			delete(*it);
			particleGenerators.erase(it);
			encontrado = true;
		}
		else
			++it;
	}

	if (!encontrado) {
		GaussianParticleGenerator* gaussianPG = new GaussianParticleGenerator();
		gaussianPG->setName("Gaussian");

		particleGenerators.push_back(gaussianPG);
	}
}