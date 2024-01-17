#include "RigidBodySystem.h"

RigidBodySystem::RigidBodySystem() : thereIsTarget(false) {
	// creación de todos los sistemas de partículas
	// creación de dianas y soportes
	//createTargetRBGenerator();
	targetGenerator = new RBTargetGenerator();
	targetGenerator->setName("Target");

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
	/*for (auto itGenerators : rbGenerators) {
		for (auto itRB : itGenerators->generateRBsDynamicStatic())
			staticDynamicRigids.push_back(itRB);
	}*/

	if (!thereIsTarget) {
		staticDynamicRigids.push_back(targetGenerator->generateTarget());
		thereIsTarget = true;
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

void RigidBodySystem::collision(physx::PxActor* actor1, physx::PxActor* actor2) {
	if (staticDynamicRigids.size() > 0) {
		if ((actor1 == staticDynamicRigids.front().first->getBody() || actor2 == staticDynamicRigids.front().first->getBody()) && projectileMngr->collision(actor1, actor2)) {
			staticDynamicRigids.front().first->kill();
			staticDynamicRigids.front().second->release();
			staticDynamicRigids.pop_front();
			targetGenerator->destroyTarget();
			thereIsTarget = false;
		}
	}
}

bool RigidBodySystem::checkCollision(physx::PxActor* actor1, physx::PxActor* actor2) {
	auto it = staticDynamicRigids.begin();
	bool encontrado = false;
	while (it != staticDynamicRigids.end() && !encontrado) {
		if ((*it).first->getBody() == actor1 || (*it).first->getBody() == actor2) {
			(*it).first->kill();
			(*it).second->release();
			staticDynamicRigids.erase(it);
			//targetGenerator->destroyTarget();
			encontrado = true;
		}
		else
			++it;
	}
	return encontrado;
}