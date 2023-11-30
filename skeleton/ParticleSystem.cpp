#include "ParticleSystem.h"

ParticleSystem::ParticleSystem() {
	particleForceRegistry = new ParticleForceRegistry();
}

ParticleSystem::~ParticleSystem() {}

void ParticleSystem::update(double t) {
	// parámetros randomizados
	// posición
	// int randNum = rand()%(max-min + 1) + min;
	/*int posX = rand() % (PARTICLE_POS_FIN - PARTICLE_POS_INI + 1) + PARTICLE_POS_INI;
	int posY = rand() % (PARTICLE_POS_FIN - PARTICLE_POS_INI + 1) + PARTICLE_POS_INI;
	int posZ = rand() % (PARTICLE_POS_FIN - PARTICLE_POS_INI + 1) + PARTICLE_POS_INI;

	particles.push_back(new Particle(Vector3(posX, posY, posZ), PARTICLE_DIR,
		PARTICLE_RADIUS, 0.5, &PxSphereGeometry(PARTICLE_RADIUS)));*/

	// se actualizan todos los generadores
	// las partículas se añaden a la lista de partículas del sistema
	for (auto itGenerators : particleGenerators) {
		for (auto itParticle : itGenerators->generateParticles())
			particles.push_back(itParticle);
	}

	// se actualizan todas las partículas
	for (auto itParticles : particles) 
		itParticles->integratev3(t);
		//itParticles->integratev2(t);

	// se actualizan todos los fireworks
	for (auto itFireworks : fireworks) 
		itFireworks->integratev2(t);

	// se añaden partículas afectadas por fuerzas
	// se recorre la lista de fuerzas para ir creando partículas para cada fuerza
	/*for (auto itForce : forceGenerators) {
		if (itForce->getName() == "Whirlwind")
			particleForceRegistry->generateStaticParticles(itForce);
		else if (itForce->getName() == "Explosion")
			particleForceRegistry->generateExplosionParticles(itForce);
		else
			particleForceRegistry->generateParticles(itForce);
	}*/

	// se actualizan todas las partículas afectadas por fuerzas
	particleForceRegistry->updateForces(t);
	particleForceRegistry->updateParticles(t);

	particleForceRegistry->deleteDeadParticles();

	// se eliminan las partículas muertas
	deleteParticles(); 

	// genera más fuegos artificiales
	explode();
}

void ParticleSystem::explode() {
	auto it = fireworks.begin();
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
	}
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

void ParticleSystem::createFountainParticleGenerator() {
	auto it = particleGenerators.begin();
	bool encontrado = false;
	while (!encontrado && it != particleGenerators.end()) {
		if ((*it)->getName() == "Fountain") {
			delete(*it);
			particleGenerators.erase(it);
			encontrado = true;
		}
		else
			++it;
	}

	if (!encontrado) {
		FountainParticleGenerator* fountainPG = new FountainParticleGenerator();
		fountainPG->setName("Fountain");

		particleGenerators.push_back(fountainPG);
	}
}

void ParticleSystem::createFireworkGenerator() {
	FireworkParticleGenerator* fireworkParticleGenerator = new FireworkParticleGenerator();
	fireworks.push_back(fireworkParticleGenerator->generateParticle());
}

void ParticleSystem::createJetParticleGenerator() {
	auto it = particleGenerators.begin();
	bool encontrado = false;
	while (!encontrado && it != particleGenerators.end()) {
		if ((*it)->getName() == "Jet") {
			delete(*it);
			particleGenerators.erase(it);
			encontrado = true;
		}
		else
			++it;
	}

	if (!encontrado) {
		JetParticleGenerator* jetPG = new JetParticleGenerator();
		jetPG->setName("Jet");

		particleGenerators.push_back(jetPG);
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

void ParticleSystem::createWindForce() {
	auto itFuerza = forceGenerators.begin();
	bool encontrado = false;
	while (!encontrado && itFuerza != forceGenerators.end()) {
		if ((*itFuerza)->getName() == "Wind") {
			particleForceRegistry->deleteForceRegistry(*itFuerza);
			delete(*itFuerza);
			forceGenerators.erase(itFuerza);
			encontrado = true;
		}
		else
			++itFuerza;
	}

	if (!encontrado) {
		WindForce* windForce = new WindForce(1000);
		windForce->setName("Wind");

		forceGenerators.push_back(windForce);
		particleForceRegistry->addForce(windForce);
		particleForceRegistry->addForceToAllParticles(windForce);
	}
}

void ParticleSystem::createWhirlwindForce() {
	auto itFuerza = forceGenerators.begin();
	bool encontrado = false;
	while (!encontrado && itFuerza != forceGenerators.end()) {
		if ((*itFuerza)->getName() == "Whirlwind") {
			particleForceRegistry->deleteForceRegistry(*itFuerza);
			delete(*itFuerza);
			forceGenerators.erase(itFuerza);
			encontrado = true;
		}
		else
			++itFuerza;
	}

	if (!encontrado) {
		WhirlwindForce* whirlwindForce = new WhirlwindForce(1);
		whirlwindForce->setName("Whirlwind");

		forceGenerators.push_back(whirlwindForce);
		particleForceRegistry->addForce(whirlwindForce);
		particleForceRegistry->addForceToAllParticles(whirlwindForce);
	}
}

void ParticleSystem::createExplosionForce() {
	auto itFuerza = forceGenerators.begin();
	bool encontrado = false;
	while (!encontrado && itFuerza != forceGenerators.end()) {
		if ((*itFuerza)->getName() == "Explosion") {
			particleForceRegistry->deleteForceRegistry(*itFuerza);
			delete(*itFuerza);
			forceGenerators.erase(itFuerza);
			encontrado = true;
		}
		else
			++itFuerza;
	}

	if (!encontrado) {
		ExplosionForce* explosionForce = new ExplosionForce();
		explosionForce->setName("Explosion");

		forceGenerators.push_back(explosionForce);
		particleForceRegistry->addForce(explosionForce);
	}
}

void ParticleSystem::generateSpringForce() {
	auto itFuerza = forceGenerators.begin();
	bool encontrado = false;
	while (!encontrado && itFuerza != forceGenerators.end()) {
		if ((*itFuerza)->getName() == "Spring1") {
			particleForceRegistry->deleteForceRegistry(*itFuerza);
			delete(*itFuerza);
			forceGenerators.erase(itFuerza);
			encontrado = true;
		}
		else
			++itFuerza;
	}

	if (!encontrado) {
		Particle* p1 = new Particle(Vector3(-10, 10, 0), Vector3(0, 0, 0), 10, 1, &PxSphereGeometry(10), 1, -1);
		Particle* p2 = new Particle(Vector3(20, 10, 0), Vector3(0, 0, 0), 10, 1, &PxSphereGeometry(10), 1, -1);

		SpringForceGenerator* f1 = new SpringForceGenerator(10, 20, p2);
		f1->setName("Spring1");

		forceGenerators.push_back(f1);

		particleForceRegistry->addRegistry(f1, p1);

		particlesWForces.insert(p1);
		particles.push_back(p2);
	}
}

void ParticleSystem::generateDoubleSpringForce() {
	auto itFuerza = forceGenerators.begin();
	bool encontrado = false;
	while (!encontrado && itFuerza != forceGenerators.end()) {
		if ((*itFuerza)->getName() == "Spring2") {
			particleForceRegistry->deleteForceRegistry(*itFuerza);
			delete(*itFuerza);
			forceGenerators.erase(itFuerza);
			encontrado = true;
		}
		else
			++itFuerza;
	}

	if (!encontrado) {
		Particle* p1 = new Particle(Vector3(-30, 10, 0), Vector3(0, 0, 0), 10, 1, &PxSphereGeometry(10), 1, -1);
		Particle* p2 = new Particle(Vector3(30, 10, 0), Vector3(0, 0, 0), 10, 1, &PxSphereGeometry(10), 1, -1);

		SpringForceGenerator* f1 = new SpringForceGenerator(10, 30, p2);
		f1->setName("Spring2");
		SpringForceGenerator* f2 = new SpringForceGenerator(10, 30, p1);
		f2->setName("Spring2");

		forceGenerators.push_back(f1);
		forceGenerators.push_back(f2);

		particleForceRegistry->addRegistry(f1, p1);
		particleForceRegistry->addRegistry(f2, p2);

		particlesWForces.insert(p1);
		particlesWForces.insert(p2);
	}
}

void ParticleSystem::increaseKSpring() {
	auto itFuerza = forceGenerators.begin();
	bool encontrado = false;
	while (!encontrado && itFuerza != forceGenerators.end()) {
		if ((*itFuerza)->getName() == "Spring1") {
			(*itFuerza)->setK((*itFuerza)->getK() + 1);
			encontrado = true;
		}
		else
			++itFuerza;
	}
}

void ParticleSystem::decreaseKSpring() {
	auto itFuerza = forceGenerators.begin();
	bool encontrado = false;
	while (!encontrado && itFuerza != forceGenerators.end()) {
		if ((*itFuerza)->getName() == "Spring1") {
			(*itFuerza)->setK((*itFuerza)->getK() - 1);
			encontrado = true;
		}
		else
			++itFuerza;
	}
}