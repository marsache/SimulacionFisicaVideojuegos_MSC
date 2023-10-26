#pragma once
#include "ParticleGenerator.h"
#include <random>

using namespace std;

const int GAUSSIAN_PARTICLES = 1;
const float PARTICLE_RADIUS = 0.06;
const float GAUSSIAN_PARTICLE_LIFE = 20;

// generador de partículas de polvo
class GaussianParticleGenerator : public ParticleGenerator
{
public:
	GaussianParticleGenerator();

protected:
	virtual list<Particle*> generateParticles();

	Vector3 devPos, devVel;
	double devT;
};