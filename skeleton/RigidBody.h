#pragma once
#include <string>
#include <list>
#include <PxPhysicsAPI.h>
#include "ParticleInfo.h"
#include "PxPhysicsAPI.h"
#include "RenderUtils.hpp"

using namespace std;
using namespace ParticleInfo;
extern PxPhysics* gPhysics;
extern PxScene* gScene;

class RigidBody
{
private:
	float timeAlive, life;
	int radius;
	Vector3 position, linearVelocity;
	bool alive, hasLife;
	Vector4 color;
	RenderItem* dynamicItem;

public:
	RigidBody(Vector3 _position, int _radius, Vector3 _linearVelocity, float _life, bool _hasLife, Vector4 _color);
	~RigidBody();

	bool isAlive() { return alive; }
	void integrate(double t);
};