#pragma once
#include <vector>
#include <string>
#include <list>
#include <PxPhysicsAPI.h>
#include "ParticleInfo.h"
#include "PxPhysicsAPI.h"
#include "RenderUtils.hpp"
#include "RigidBody.h"

using namespace std;
extern PxPhysics* gPhysics;
extern PxScene* gScene;

class ProjectileManager
{
	const int COOLDOWN_TIME = 100;
public:
	ProjectileManager();
	~ProjectileManager();
	void createProjectile();
	void killProjectile();
	void integrate(double t);
	bool collision(physx::PxActor* actor1, physx::PxActor* actor2);

private:
	vector<RigidBody*> projectiles;
	bool cooldown;
	int cooldownTime;
};