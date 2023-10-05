#include "ProjectileManager.h"

ProjectileManager::ProjectileManager() {

}

ProjectileManager::~ProjectileManager() {

}

void ProjectileManager::createProjectile() {
	//particles.push_back({ new Particle(Vector3(0, 0, 0), Vector3(0.01, 0, 0), 2, 0.1), true });
	particles.push_back(new Particle(GetCamera()->getTransform().p, GetCamera()->getDir() * 150, 2, 0.5));
}

void ProjectileManager::killProjectile() {
	auto it = particles.begin();
	/*while (it != particles.end()) {
		if ((*it)->isAlive())
			(*it)->setAlive(false);
		++it;
	}*/

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

void ProjectileManager::integrate(double t) {
	auto it = particles.begin();
	while (it != particles.end()) {
		(*it)->integratev2(t);
		++it;
	}
	killProjectile();
	//cout << particles.size() << endl;
}