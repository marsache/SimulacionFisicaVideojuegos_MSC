#pragma once
#include "RBGenerator.h"

using namespace std;
using namespace ParticleInfo;

class RBTargetGenerator : public RBGenerator
{
private:
	virtual list<PxRigidDynamic*> generateRBsDynamic() {
		list<PxRigidDynamic*> l; return l;
	}

	virtual list<PxRigidStatic*> generateRBsStatic() {
		list<PxRigidStatic*> l; return l;
	}

	virtual list<pair<RigidBody*, PxRigidStatic*>> generateRBsDynamicStatic();

	bool generate;

public:
	RBTargetGenerator();
	~RBTargetGenerator();
	pair<RigidBody*, PxRigidStatic*> generateTarget();
	void destroyTarget() { generate = true; }
};