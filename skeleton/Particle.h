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
//const Vector3 ACCELERATION = Vector3(0, -20, 0);
const Vector3 GRAVITY = Vector3(0, -10, 0);
//const float PARTICLE_LIFE = 170.0;
//const float PARTICLE_LIFE = 100.0;

class Particle
{
public:
	Particle(Vector3 pos, Vector3 _vel, float rad, float _mass, PxGeometry* shape, int gen, float pLife);

	//void integrate(double t);
	void integratev2(double t);
	void integratev3(double t);

	~Particle();
	bool isAlive() { return alive; }
	void setAlive(bool a) { alive = a; }

	Vector3 getPosition() { return { _pose.p.x, _pose.p.y, _pose.p.z }; }
	void addForce(Vector3 f) { forces += f; }
	void clearAcum() { 
		forces = { 0, 0, 0 }; 
		vel = iniVel; 
	}
	Vector3 getVel() { return vel; }
	float getRadius() { return radius; }

private:
	Vector3 vel, forces, acceleration, iniVel;
	float radius, particleLife = 100;
	int mass;
	physx::PxTransform _pose;
	RenderItem* renderItem; // es importante que sea un puntero
	float timeAlive;
	bool alive;
	int generation;
};

