#pragma once
#include "ParticleGenerator.h"

using namespace std;

const int UNIFORM_PARTICLES = 1;
const int MAX_X = 200;
const int MAX_YZ = 10;
const int MIN_YZ = 155;
const int UNIFORM_PARTICLE_RADIUS = 1;
const float UNIFORM_PARTICLE_LIFE = 150;

// generador de nieve
class UniformParticleGenerator : public ParticleGenerator
{
public:
	UniformParticleGenerator();
	~UniformParticleGenerator();

protected:
	virtual list<Particle*> generateParticles();
};