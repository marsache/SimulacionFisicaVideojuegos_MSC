#pragma once
#include "PxPhysicsAPI.h"
#include "RenderUtils.hpp"
#include <iostream>

using namespace std;
using namespace physx;
typedef physx::PxVec3 Vector3;
typedef physx::PxVec4 Vector4;

class Particle
{
public:
	Particle(Vector3 Pos, Vector3 Vel, int Rad);
	~Particle();

	void integrate(double t);

private:
	Vector3 vel;
	int radius;
	physx::PxTransform _pose;
	RenderItem* renderItem; // es importante que sea un puntero
};

