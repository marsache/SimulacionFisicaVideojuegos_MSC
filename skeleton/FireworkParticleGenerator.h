#pragma once
#include "ParticleGenerator.h"
#include "ParticleInfo.h"
#include "Firework.h"
#include <list>

using namespace std;
using namespace ParticleInfo;

const int RADIUS = 150;

class FireworkParticleGenerator : public ParticleGenerator
{
public:
	FireworkParticleGenerator() : ParticleGenerator() {}
	~FireworkParticleGenerator() { delete(this); }

	Firework* generateParticle();
	list<Firework*> createChildren(Firework* parent);

private:
	virtual list<Particle*> generateParticles();
	virtual list<PxRigidDynamic*> generateRBsDynamic() { list<PxRigidDynamic*> l; return l; }
};