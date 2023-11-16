#pragma once
#include "WindForce.h"
#include "WindForce.h"
#include "ParticleInfo.h"
#include <unordered_set>

using namespace std;
using namespace ParticleInfo;

const int MAX_HEIGHT = 0;

class WhirlwindForce : public ForceGenerator
{
protected:
	Vector3 acceleration;
	physx::PxTransform influencedArea;

public:
	WhirlwindForce(int _acceleration) : ForceGenerator(), acceleration(0, _acceleration, 0), influencedArea(25, -10, 25) {}
	virtual void updateForce(Particle* p);
};