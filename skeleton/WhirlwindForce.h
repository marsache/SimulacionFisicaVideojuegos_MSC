#pragma once
#include "WindForce.h"
#include "WindForce.h"
#include "ParticleInfo.h"
#include <unordered_set>

using namespace std;
using namespace ParticleInfo;

const int MAX_HEIGHT = 0;
const float K_WHIRLWIND = 0.05;

class WhirlwindForce : public ForceGenerator
{
protected:
	Vector3 acceleration;
	physx::PxTransform influencedArea;

public:
	WhirlwindForce(int _acceleration) : ForceGenerator(), acceleration(0, _acceleration, 0), influencedArea(25, -10, 25) {}
	virtual void updateForce(Particle* p, double t);
	virtual void updateForce(PxRigidDynamic* rb, double t);
};