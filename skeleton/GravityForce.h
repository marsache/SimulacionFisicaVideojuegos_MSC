#pragma once
#include "ForceGenerator.h"
#include "ParticleInfo.h"
#include <unordered_set>

using namespace std;
using namespace ParticleInfo;

class GravityForce : public ForceGenerator
{
public:
	GravityForce(int _acceleration) : acceleration(0, _acceleration, 0) {}
	~GravityForce() { delete(this); }
	virtual void updateForce(Particle* p, double t);
	//virtual unordered_set<Particle*> generateParticles();

protected:
	Vector3 acceleration;
};