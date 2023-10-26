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

struct particleInfo {
	Vector3 position1;
	Vector3 position2;
	Vector3 velocity1;
	Vector3 velocity2;
	float radius;
	float mass;
	PxGeometry* shape;
	int generation;
	float life;
};

struct particleTypes {
	particleInfo particle3 = { Vector3(0, 0, 0), Vector3(5, 5, 5), Vector3(3, 3, 3), Vector3(7, 7, 7), 3, 1, &PxSphereGeometry(3), 1, 100 };
};

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

