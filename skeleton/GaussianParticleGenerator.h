#pragma once
#include "ParticleGenerator.h"

using namespace std;

class GaussianParticleGenerator : public ParticleGenerator
{
public:
	GaussianParticleGenerator();

protected:
	//virtual list<Particle*> generateParticles();

	Vector3 devPos, devVel;
	double devT;
};