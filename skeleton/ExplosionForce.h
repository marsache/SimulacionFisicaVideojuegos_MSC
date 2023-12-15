#pragma once
#include "ForceGenerator.h"
#include <cmath>

using namespace std;

const int EXPLOSION_TIME = 1;
//const int EXPLOSION_RADIUS = 70;
const int EXPLOSION_RADIUS = 200;
const float SOUND_AIR_SPEED = 331;
const int K_EXPLOSION_PARTICLE = 1000;
const int K_EXPLOSION = 100000;
const int TAU_PARTICLE = 500;
const int TAU = 5;

class ExplosionForce : public ForceGenerator
{
private:
	float elapsedTime, elapsedTimeExplosion, radius;
	bool explodes;
	Vector3 core;

public:
	//ExplosionForce() : ForceGenerator(), elapsedTime(0), elapsedTimeExplosion(0), explodes(false), core(25, -50, 25) {}
	ExplosionForce() : ForceGenerator(), elapsedTime(0), elapsedTimeExplosion(0), explodes(false), core(0, 0, 0) {}
	virtual void updateForce(Particle* p, double t);
	virtual void updateForce(PxRigidDynamic* p, double t);

	bool didExplode() { return explodes; }
};