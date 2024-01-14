#pragma once
#include <string>
#include <list>
#include <PxPhysicsAPI.h>
#include "ParticleInfo.h"
#include "PxPhysicsAPI.h"
#include "RenderUtils.hpp"

using namespace std;
extern PxPhysics* gPhysics;
extern PxScene* gScene;

class RBGenerator
{
protected:
	string name;
	Vector3 position, velocity;
	//double generationProbability;
	int numParticles, radius;

public:
	virtual list<PxRigidDynamic*> generateRBsDynamic() = 0;
	virtual list<PxRigidStatic*> generateRBsStatic() = 0;
	virtual list<pair<PxRigidDynamic*, PxRigidStatic*>> generateRBsDynamicStatic() = 0;

	void setName(string _name) { name = _name; }
	string getName() { return name; }
};