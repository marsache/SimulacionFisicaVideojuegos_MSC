#include "ProjectileManager.h"

ProjectileManager::ProjectileManager() : cooldown(false), cooldownTime(0) {}

ProjectileManager::~ProjectileManager() {
	delete(this);
}

void ProjectileManager::createProjectile() {
	if (!cooldown) {
		cooldown = true;
		cooldownTime = 0;
		RBTypes rbType;
		projectiles.push_back(new RigidBody(GetCamera()->getTransform().p,
			rbType.projectile.radiusMin, GetCamera()->getDir() * 150, rbType.projectile.life, true, { 0.8, 0.8, 0, 1 }));
	}
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
	cooldownTime++;
	if (cooldownTime >= COOLDOWN_TIME)
		cooldown = false;
	for (auto itProjectile : projectiles)
		(*itProjectile).integrate(t);

	killProjectile();
}

bool ProjectileManager::collision(physx::PxActor* actor1, physx::PxActor* actor2) {
	int i = 0;
	bool encontrado = false;
	while (i < projectiles.size() && !encontrado) {
		if (projectiles[i]->getBody() == actor1 || projectiles[i]->getBody() == actor2) {
			projectiles[i]->kill();
			encontrado = true;
		}
		else
			++i;
	}
	return encontrado;
}