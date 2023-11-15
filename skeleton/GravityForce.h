#pragma once
#include "ForceGenerator.h"
#include "ParticleInfo.h"
#include <unordered_set>

using namespace std;
using namespace ParticleInfo;

const int GRAVITY_PARTICLES = 1;

class GravityForce : public ForceGenerator
{
public:
	GravityForce(int _acceleration) : acceleration(0, _acceleration, 0) {}
	virtual void updateForce(Particle* p);
	virtual unordered_set<Particle*> generateParticles();

protected:
	Vector3 acceleration;
};