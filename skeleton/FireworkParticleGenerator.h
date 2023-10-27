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
	list<Firework*> createChildren(Firework* parent);

private:
	virtual list<Particle*> generateParticles();
};