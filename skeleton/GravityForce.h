#pragma once
#include "ForceGenerator.h"

class GravityForce : public ForceGenerator
{
public:
	GravityForce(int _acceleration) : acceleration(0, _acceleration, 0) {}
	virtual void updateForce(Particle* p);

protected:
	Vector3 acceleration;
};