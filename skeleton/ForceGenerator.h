#pragma once
#include "Particle.h"

class ForceGenerator
{
public:
	ForceGenerator();
	virtual void updateForce(Particle* p) {}
};