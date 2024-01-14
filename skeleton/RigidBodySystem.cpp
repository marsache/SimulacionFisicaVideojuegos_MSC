#include "RigidBodySystem.h"

RigidBodySystem::RigidBodySystem() {
	// creación de todos los sistemas de partículas
	// creación de dianas y soportes
	createTargetRBGenerator();
	projectileMngr = new ProjectileManager();
}

RigidBodySystem::~RigidBodySystem() {
	staticRigids.clear();
	dynamicRigids.clear();
	staticDynamicRigids.clear();
	rbGenerators.clear();
	delete(this);
}

void RigidBodySystem::update(double t) {
	for (auto itGenerators : rbGenerators) {
		for (auto itRB : itGenerators->generateRBsDynamicStatic())
			staticDynamicRigids.push_back(itRB);
	}

	projectileMngr->integrate(t);
}

void RigidBodySystem::createTargetRBGenerator() {
	auto it = rbGenerators.begin();
	bool encontrado = false;
	while (!encontrado && it != rbGenerators.end()) {
		if ((*it)->getName() == "Target") {
			delete(*it);
			rbGenerators.erase(it);
			encontrado = true;
		}
		else
			++it;
	}

	if (!encontrado) {
		RBTargetGenerator* targetRBG = new RBTargetGenerator();
		targetRBG->setName("Target");

		rbGenerators.push_back(targetRBG);
	}
}

void RigidBodySystem::createProjectile() {
	projectileMngr->createProjectile();
}