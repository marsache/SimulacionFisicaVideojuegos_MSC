#pragma once
#include "ForceGenerator.h"
#include "ParticleInfo.h"
#include <unordered_set>

using namespace std;
using namespace ParticleInfo;

const int WIND_PARTICLES = 1;

class WindForce : ForceGenerator
{
protected:
	Vector3 acceleration;
public:
	WindForce(int _acceleration) : acceleration(0, _acceleration, 0) {}

	virtual void updateForce(Particle* p);
	//virtual unordered_set<Particle*> generateParticles();
};