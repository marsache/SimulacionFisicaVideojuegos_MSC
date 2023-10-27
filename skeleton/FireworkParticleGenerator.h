#pragma once
#include "ParticleGenerator.h"
#include "ParticleInfo.h"
#include "Firework.h"
#include <list>

using namespace std;
using namespace ParticleInfo;

class FireworkParticleGenerator : public ParticleGenerator
{
public:
	FireworkParticleGenerator() : ParticleGenerator() {}
	~FireworkParticleGenerator() {}

	Firework* generateParticle();

private:
	virtual list<Particle*> generateParticles();
};