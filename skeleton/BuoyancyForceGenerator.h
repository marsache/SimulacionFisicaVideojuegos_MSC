#pragma once
#include "ForceGenerator.h"

class BuoyancyForceGenerator : public ForceGenerator
{
protected:
	float height;
	float volume;
	float liquidDensity;
	float gravity = 9.8;

	Particle* liquidParticle;

public:
	BuoyancyForceGenerator(float h, float v, float d, Particle* lP);
	virtual void updateForce(Particle* p, double t);
};