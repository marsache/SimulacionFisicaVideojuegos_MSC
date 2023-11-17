#pragma once
#include "ForceGenerator.h"
#include <cmath>

using namespace std;

const int EXPLOSION_TIME = 150;
const int EXPLOSION_RADIUS = 70;
const float SOUND_AIR_SPEED = 331;
const int K_EXPLOSION = 1000;
const int TAU = 500;

class ExplosionForce : public ForceGenerator
{
private:
	float elapsedTime, elapsedTimeExplosion, radius;
	bool explodes;
	Vector3 core;

public:
	ExplosionForce() : ForceGenerator(), elapsedTime(0), elapsedTimeExplosion(0), explodes(false), core(25, -50, 25) {}
	virtual void updateForce(Particle* p, double t);

	bool didExplode() { return explodes; }
};