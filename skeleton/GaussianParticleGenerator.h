#pragma once
#include "ParticleGenerator.h"
#include "ParticleInfo.h"
#include <random>

using namespace std;
using namespace ParticleInfo;

const int GAUSSIAN_PARTICLES = 2;
const float PARTICLE_RADIUS = 0.06;
const float GAUSSIAN_PARTICLE_LIFE = 20;

// generador de partículas de polvo
class GaussianParticleGenerator : public ParticleGenerator
{
public:
	GaussianParticleGenerator();
	virtual list<Particle*> generateParticles();

protected:

	Vector3 devPos, devVel;
	double devT;
};