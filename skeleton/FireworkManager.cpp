#include "FireworkManager.h"

FireworkManager::FireworkManager() {
	// fireworks
	fireworkPG = new FireworkParticleGenerator();
}

void FireworkManager::explode() {
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

void FireworkManager::update(double t) {
	// se actualizan todos los fireworks
	auto it = fireworks.begin();
	while (it != fireworks.end()) {
		(*it)->integrate(t);
		++it;
	}

	// genera más fuegos artificiales
	explode();
}

void FireworkManager::startFireworks() {
	fireworks.push_back(fireworkPG->generateParticle());
}