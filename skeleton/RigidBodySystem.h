#pragma once
#include <list>
#include <unordered_set>
#include "ParticleInfo.h"
#include "RBForceRegistry.h"
#include "RBGenerator.h"
#include "RBTargetGenerator.h"

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
	list<pair<PxRigidDynamic*, PxRigidStatic*>> staticDynamicRigids;
	RBForceRegistry* rbForceRegistry;
	list<RBGenerator*> rbGenerators;

	void createTargetRBGenerator();

public:
	RigidBodySystem();
	~RigidBodySystem();
	void update(double t);
};