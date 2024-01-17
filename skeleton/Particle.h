#pragma once
#include "PxPhysicsAPI.h"
#include "RenderUtils.hpp"
#include <iostream>
#include <math.h>

using namespace std;
using namespace physx;
typedef physx::PxVec3 Vector3;
typedef physx::PxVec4 Vector4;

class Particle
{
protected:
	Vector3 velocity, forces, acceleration, initialVelocity;
	float radius, particleLife;
	int mass;
	PxTransform position;
	RenderItem* renderItem; 
	float timeAlive;
	bool alive;
	int generation;
	Vector4 color;

public:
	Particle(Vector3 pos, Vector3 vel, float rad, float _mass, PxGeometry* shape, int gen, float pLife = 100, Vector4 _color = Vector4(50, 50, 50, 50));
	~Particle();
	void integrate(double t);
	void addForce(Vector3 f) { forces += f; }
	bool isAlive() { return alive; }
	void setAlive(bool a) { alive = a; }
	Vector3 getPosition() { return position.p; }
	Vector3 getVelocity() { return velocity; }
};