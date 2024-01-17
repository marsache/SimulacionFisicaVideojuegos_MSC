#pragma once
#include <list>
#include <unordered_set>
#include "ParticleInfo.h"
#include "RBForceRegistry.h"
#include "RBGenerator.h"
#include "RBTargetGenerator.h"
#include "RigidBody.h"
#include "ProjectileManager.h"

using namespace std;
using namespace ParticleInfo;
extern PxPhysics* gPhysics;
extern PxScene* gScene;

class RigidBodySystem
{
private:
	const int RB_LIMIT = 3;

	// sólidos rígidos 
	list<PxRigidStatic*> staticRigids;
	list<PxRigidDynamic*> dynamicRigids;
	list<pair<RigidBody*, PxRigidStatic*>> staticDynamicRigids;
	RBForceRegistry* rbForceRegistry;
	list<RBGenerator*> rbGenerators;

	ProjectileManager* projectileMngr;

	RBTargetGenerator* targetGenerator;

	void createTargetRBGenerator();
	bool checkCollision(physx::PxActor* actor1, physx::PxActor* actor2);

	bool thereIsTarget;

public:
	RigidBodySystem();
	~RigidBodySystem();
	void update(double t);
	void createProjectile();
	void collision(physx::PxActor* actor1, physx::PxActor* actor2);
};