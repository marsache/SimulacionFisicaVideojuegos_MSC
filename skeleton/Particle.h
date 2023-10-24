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
const Vector3 GRAVITY = Vector3(0, -10, 0);
//const float PARTICLE_LIFE = 170.0;
//const float PARTICLE_LIFE = 100.0;

class Particle
{
public:
	Particle(Vector3 pos, Vector3 _vel, float rad, float _mass, PxGeometry* shape, int gen, float pLife);
	~Particle();

	//void integrate(double t);
	void integratev2(double t);

	bool isAlive() { return alive; }
	void setAlive(bool a) { alive = a; }

private:
	Vector3 vel;
	float radius, particleLife = 100;
	int mass;
	physx::PxTransform _pose;
	RenderItem* renderItem; // es importante que sea un puntero
	float timeAlive;
	bool alive;
	int generation;
};

