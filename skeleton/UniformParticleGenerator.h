#pragma once
#include "ParticleGenerator.h"
#include "ParticleInfo.h"

using namespace std;
using namespace ParticleInfo;

// generador de nieve
class UniformParticleGenerator : public ParticleGenerator
{
	const int PARTICLES = 1;

public:
	UniformParticleGenerator();
	~UniformParticleGenerator();

protected:
	int index;
	virtual list<Particle*> generateParticles();
};