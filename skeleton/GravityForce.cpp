#include "GravityForce.h"

void GravityForce::updateForce(Particle* p) {
	p->addForce(acceleration);
}