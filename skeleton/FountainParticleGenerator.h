#pragma once
#include "ParticleGenerator.h"
#include "ParticleInfo.h"
#include "Particle.h"
#include <list>

using namespace std;
using namespace ParticleInfo;

const int FOUNTAIN_PARTICLES = 1;

class FountainParticleGenerator : public ParticleGenerator
{
public:
	FountainParticleGenerator() : ParticleGenerator() {}
	~FountainParticleGenerator() {}

private:
	virtual list<Particle*> generateParticles();
};
