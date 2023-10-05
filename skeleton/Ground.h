#pragma once
#include "PxPhysicsAPI.h"
#include "RenderUtils.hpp"
#include <iostream>
#include <math.h>

using namespace std;
using namespace physx;
typedef physx::PxVec3 Vector3;
typedef physx::PxVec4 Vector4;

class Ground
{
public:
	Ground(PxTransform pos, Vector4 color, PxVec3 size);
	~Ground() {}

private:
	PxTransform position;
	RenderItem* renderItem; // es importante que sea un puntero
};

