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
public:
	ProjectileManager();
	~ProjectileManager();
	void createProjectile();
	void killProjectile();
	void integrate(double t);

private:
	std::vector<RigidBody*> projectiles;
};