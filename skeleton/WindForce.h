#pragma once
#include "ForceGenerator.h"
#include "ParticleInfo.h"
#include <unordered_set>
#define _USE_MATH_DEFINES
#include <math.h>

using namespace std;
using namespace ParticleInfo;

const int WIND_PARTICLES = 4;
const int RADIUS_INFLUENCED_AREA = 500;
const float AIR_DENSITY = 1.2;
const Vector4 COLOR = Vector4(0.0, 255.0, 0.0, 0.5);

class WindForce : public ForceGenerator
{
protected:
	Vector3 acceleration;
	physx::PxTransform influencedArea;
	RenderItem* renderInfluenceArea;

public:
	WindForce(int _acceleration) : acceleration(_acceleration, 0, 0), influencedArea(0, 250, 0) {
		//physx::PxShape* shape = CreateShape(physx::PxSphereGeometry(RADIUS_INFLUENCED_AREA));
		//renderInfluenceArea = new RenderItem(shape, &influencedArea, COLOR);
	}

	virtual void updateForce(Particle* p, double t);
	//virtual void updateForce(PxRigidDynamic* p, double t);
};