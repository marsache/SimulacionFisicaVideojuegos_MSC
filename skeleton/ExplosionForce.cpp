#include "ExplosionForce.h"

void ExplosionForce::updateForce(Particle* p, double t) {
	elapsedTime += t;
	if (elapsedTime >= EXPLOSION_TIME)
		explodes = true;

	if (explodes) {
		elapsedTimeExplosion += t;
		Vector3 differenceRadius = p->getPosition() - core;
		float differenceRadiusMagnitude = differenceRadius.magnitude();
		if (differenceRadiusMagnitude < EXPLOSION_RADIUS) {
			Vector3 force = (K_EXPLOSION / pow(differenceRadiusMagnitude, 2)) * differenceRadius * exp(-elapsedTimeExplosion / TAU);
			p->addForce(force);
		}
	}
}