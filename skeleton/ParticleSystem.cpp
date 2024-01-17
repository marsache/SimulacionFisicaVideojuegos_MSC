#include "ParticleSystem.h"

ParticleSystem::ParticleSystem() : points(0) {
	particleForceRegistry = new ParticleForceRegistry();
	// se crean todos los sistemas de partículas
	// sistema de partículas de nieve
	uniformPG = new UniformParticleGenerator();
	uniformPG->setName("Uniform");

	// sistema de partículas de polvo
	gaussianPG = new GaussianParticleGenerator();
	gaussianPG->setName("Gaussian");

	windForce = new WindForce(1000);
	windForce->setName("Wind");
	forceGenerators.push_back(windForce);
	particleForceRegistry->addForce(windForce);

	generateBuoyancyForce();
	createGravityForce();
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

	if (points % 10 == 1) {
		for (auto itParticle : uniformPG->generateParticles())
			particleForceRegistry->addParticle(itParticle);
		particleForceRegistry->addForceToAllParticles(windForce);

	}
	else if (points % 20 <= 10) {
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
	particleForceRegistry->updateParticles(t);

	particleForceRegistry->deleteDeadParticles();

	// se eliminan las partículas muertas
	//deleteParticles();
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

void ParticleSystem::generateBuoyancyForce() {
	auto itFuerza = forceGenerators.begin();
	bool encontrado = false;
	while (!encontrado && itFuerza != forceGenerators.end()) {
		if ((*itFuerza)->getName() == "Buoyancy") {
			particleForceRegistry->deleteForceRegistry(*itFuerza);
			delete(*itFuerza);
			forceGenerators.erase(itFuerza);
			encontrado = true;
		}
		else
			++itFuerza;
	}

	if (!encontrado) {
		for (int i = 0; i < 5; ++i) {
			int x = rand() % 600 - 600;
			int z = rand() % 600 - 600;
			Particle* p1 = new Particle(Vector3(x, -380, -z), Vector3(0, 0, 0), 40, 100, &PxBoxGeometry(10, 10, 10), 1, -1, Vector4(1, 0.2, 0.2, 1));
			Particle* p2 = new Particle(Vector3(x - 30, -450, -z), Vector3(0, 0, 0), 20, 100, &PxBoxGeometry(70, 5, 70), 1, -1, Vector4(0, 1, 1, 1));

			BuoyancyForceGenerator* f1 = new BuoyancyForceGenerator(10, 1000, 1000, p2);
			f1->setName("Buoyancy");

			forceGenerators.push_back(f1);

			particleForceRegistry->addRegistry(f1, p1);
			//particleForceRegistry->addForce(f1);

			particlesWForces.insert(p1);
			particles.push_back(p2);
		}
	}
}

void ParticleSystem::createGravityForce() {
	auto itFuerza = forceGenerators.begin();
	bool encontrado = false;
	while (!encontrado && itFuerza != forceGenerators.end()) {
		if ((*itFuerza)->getName() == "Gravity") {
			particleForceRegistry->deleteForceRegistry(*itFuerza);
			delete(*itFuerza);
			forceGenerators.erase(itFuerza);
			encontrado = true;
		}
		else
			++itFuerza;
	}

	if (!encontrado) {
		GravityForce* gravityForce = new GravityForce(-10);
		gravityForce->setName("Gravity");

		forceGenerators.push_back(gravityForce);
		particleForceRegistry->addForce(gravityForce);
		particleForceRegistry->addForceToAllParticles(gravityForce);
	}
}