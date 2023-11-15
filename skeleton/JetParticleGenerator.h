#pragma once
#include "ParticleGenerator.h"
#include "ParticleInfo.h"
#include "Particle.h"
#include <list>

using namespace std;
using namespace ParticleInfo;

const int JET_PARTICLES = 1;

class JetParticleGenerator : public ParticleGenerator
{
public:
	JetParticleGenerator() : ParticleGenerator() {}

private:
	virtual list<Particle*> generateParticles();
};