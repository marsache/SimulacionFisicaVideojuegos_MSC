#include "ParticleSystem.h"

ParticleSystem::ParticleSystem() {
	// se crean todos los sistemas de part�culas
	// sistema de part�culas de nieve
	createUniformParticleGenerator();

	// sistema de part�culas de polvo

	// fireworks

	// ...
}

ParticleSystem::~ParticleSystem() {

}

void ParticleSystem::update(double t) {
	// se actualizan todos los generadores
	// las part�culas de cada generador se a�aden a la lista de part�culas del sistema
	for (auto itGenerators : particleGenerators) {
		for (auto itParticle : itGenerators->generateParticles())
			particles.push_back(itParticle);
	}

	// se actualizan todas las part�culas
	for (auto itParticles : particles)
		itParticles->integrate(t);

	// se actualizan todos los fireworks
	/*for (auto itFireworks : fireworks)
		itFireworks->integrate(t);*/

	// se actualizan todas las part�culas afectadas por fuerzas
	particleForceRegistry->updateForces(t);
	//particleForceRegistry->updateParticles(t);

	//particleForceRegistry->deleteDeadParticles();

	// se eliminan las part�culas muertas
	deleteParticles();

	// genera m�s fuegos artificiales
	explode();
}

void ParticleSystem::explode() {
	/*auto it = fireworks.begin();
	while (it != fireworks.end()) {
		if (!(*it)->isAlive()) {
			Firework* aux = (*it);

			FireworkParticleGenerator* fireworkParticleGenerator = new FireworkParticleGenerator();
			list<Firework*> listFireworks = fireworkParticleGenerator->createChildren(aux);

			auto itFireworks = listFireworks.begin();

			while (itFireworks != listFireworks.end()) {
				fireworks.push_back(*itFireworks);
				++itFireworks;
			}

			it = fireworks.erase(it);
			delete(aux);
		}
		else
			++it;
	}*/
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

//void ParticleSystem::createGaussianParticleGenerator() {
//	auto it = particleGenerators.begin();
//	bool encontrado = false;
//	while (!encontrado && it != particleGenerators.end()) {
//		if ((*it)->getName() == "Gaussian") {
//			delete(*it);
//			particleGenerators.erase(it);
//			encontrado = true;
//		}
//		else
//			++it;
//	}
//
//	if (!encontrado) {
//		GaussianParticleGenerator* gaussianPG = new GaussianParticleGenerator();
//		gaussianPG->setName("Gaussian");
//
//		particleGenerators.push_back(gaussianPG);
//	}
//}
//
//void ParticleSystem::createFireworkGenerator() {
//	FireworkParticleGenerator* fireworkParticleGenerator = new FireworkParticleGenerator();
//	fireworks.push_back(fireworkParticleGenerator->generateParticle());
//}