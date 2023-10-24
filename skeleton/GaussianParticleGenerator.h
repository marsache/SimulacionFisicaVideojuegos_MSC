#pragma once
#include "ParticleGenerator.h"
#include <random>

using namespace std;

const int GAUSSIAN_PARTICLES = 3;
const int PARTICLE_RADIUS = 1;

class GaussianParticleGenerator : public ParticleGenerator
{
public:
	GaussianParticleGenerator();

protected:
	virtual list<Particle*> generateParticles();

	Vector3 devPos, devVel;
	double devT;
	
    //std::normal_distribution<double> d{10.0, 2.0};
};