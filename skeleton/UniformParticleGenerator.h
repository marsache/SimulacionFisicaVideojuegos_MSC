#pragma once
#include "ParticleGenerator.h"

using namespace std;

const int UNIFORM_PARTICLES = 3;
const int MAX_X = 200;
const int MAX_YZ = 10;
const int MIN_YZ = 155;
const int PARTICLE_RADIUS = 1;

// generador de nieve
class UniformParticleGenerator : public ParticleGenerator
{
public:
	UniformParticleGenerator();

protected:
	virtual list<Particle*> generateParticles();
};