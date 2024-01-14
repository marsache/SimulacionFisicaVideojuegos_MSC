#include "ProjectileManager.h"

ProjectileManager::ProjectileManager() {}

ProjectileManager::~ProjectileManager() {
	delete(this);
}

void ProjectileManager::createProjectile() {
	RBTypes rbType;
	projectiles.push_back(new RigidBody(GetCamera()->getTransform().p, 
		rbType.projectile.radiusMin, GetCamera()->getDir() * 150, rbType.projectile.life, true, {0.8, 0.8, 0, 1}));
}

void ProjectileManager::killProjectile() {
	auto it = projectiles.begin();

	it = projectiles.begin();
	while (it != projectiles.end()) {
		if (!(*it)->isAlive()) {
			RigidBody* aux = (*it);
			it = projectiles.erase(it);
			delete(aux);
		}
		else
			++it;
	}
}

void ProjectileManager::integrate(double t) {
	for (auto itProjectile : projectiles) 
		(*itProjectile).integrate(t);

	killProjectile();
}