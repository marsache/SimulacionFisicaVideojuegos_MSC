#pragma once
#include "PxPhysicsAPI.h"
#include "RenderUtils.hpp"
#include <iostream>
#include <math.h>

using namespace std;
using namespace physx;
typedef physx::PxVec3 Vector3;
typedef physx::PxVec4 Vector4;

const double DAMPING = 0.6;
const Vector3 ACCELERATION = Vector3(0, -20, 0);
const float PARTICLE_LIFE = 170.0;

class Particle
{
public:
	Particle(Vector3 Pos, Vector3 Vel, int Rad, float Masa);
	~Particle();

	//void integrate(double t);
	void integratev2(double t);

	bool isAlive() { return alive; }
	void setAlive(bool a) { alive = a; }

private:
	Vector3 vel;
	int radius, mass;
	physx::PxTransform _pose;
	RenderItem* renderItem; // es importante que sea un puntero
	float timeAlive;
	bool alive;
};

