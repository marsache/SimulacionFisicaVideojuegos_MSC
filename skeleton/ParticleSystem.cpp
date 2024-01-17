#include "ParticleSystem.h"

ParticleSystem::ParticleSystem() : points(0) {
	// se crean todos los sistemas de partículas
	// sistema de partículas de nieve
	uniformPG = new UniformParticleGenerator();
	uniformPG->setName("Uniform");

	// sistema de partículas de polvo
	gaussianPG = new GaussianParticleGenerator();
	gaussianPG->setName("Gaussian");
}

ParticleSystem::~ParticleSystem() {
	particles.clear();
	particleGenerators.clear();
	forceGenerators.clear();
	particlesWForces.clear();
	delete(this);
}

void ParticleSystem::update(double t) {
	// se actualizan todos los generadores
	// las partículas de cada generador se añaden a la lista de partículas del sistema
	/*for (auto itGenerators : particleGenerators) {
		for (auto itParticle : itGenerators->generateParticles())
			particles.push_back(itParticle);
	}*/

	if (points % 20 <= 10) {
		for (auto itParticle : uniformPG->generateParticles())
			particles.push_back(itParticle);
	}
	else {
		for (auto itParticle : gaussianPG->generateParticles())
			particles.push_back(itParticle);
	}

	// se actualizan todas las partículas
	for (auto itParticles : particles)
		itParticles->integrate(t);

	// se actualizan todas las partículas afectadas por fuerzas
	particleForceRegistry->updateForces(t);
	//particleForceRegistry->updateParticles(t);

	//particleForceRegistry->deleteDeadParticles();

	// se eliminan las partículas muertas
	deleteParticles();
}

ParticleGenerator* ParticleSystem::getParticleGenerator(string name) {
	for (auto it : particleGenerators) {
		if (it->getName() == name)
			return it;
	}
}

void ParticleSystem::deleteParticles() {
	auto it = particles.begin();
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