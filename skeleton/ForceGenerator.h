#pragma once
#include "Particle.h"

class ForceGenerator
{
public:
	ForceGenerator();
	void updateForce(Particle* p);
};