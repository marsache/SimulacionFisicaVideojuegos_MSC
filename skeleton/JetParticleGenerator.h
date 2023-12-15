#pragma once
#include "ParticleGenerator.h"
#include "ParticleInfo.h"
#include "Particle.h"
#include <list>

using namespace std;
using namespace ParticleInfo;
extern PxPhysics* gPhysics;

class JetParticleGenerator : public ParticleGenerator
{
	const int JET_PARTICLES = 1;
	const int JET_RBS = 1;

public:
	JetParticleGenerator() : ParticleGenerator() {}

private:
	virtual list<Particle*> generateParticles();
	//list<PxRigidDynamic*> generateRBsDynamic();
};