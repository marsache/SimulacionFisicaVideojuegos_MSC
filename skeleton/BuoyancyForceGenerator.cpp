#include "BuoyancyForceGenerator.h"

BuoyancyForceGenerator::BuoyancyForceGenerator(float h, float v, float d, Particle* lP) : ForceGenerator(), height(h), volume(v), liquidDensity(d), liquidParticle(lP) {}

void BuoyancyForceGenerator::updateForce(Particle* p, double t) {
	float h = p->getPosition().y;
	float h0 = liquidParticle->getPosition().y;

	Vector3 f(0, 0, 0);
	float immersed = 0.0;
	if (h - h0 > height * 0.5)
		immersed = 0.0;
	else if (h0 - h > height + 0.5)
		immersed = 1.0;
	else
		immersed = (h0 - h) / height + 0.5;
	f.y = liquidDensity * volume * immersed * 9.8;

	p->addForce(f);
}