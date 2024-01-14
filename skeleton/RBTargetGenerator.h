#pragma once
#include "RBGenerator.h"

using namespace std;
using namespace ParticleInfo;

class RBTargetGenerator : public RBGenerator
{
	const int RBs = 1;
private:
	virtual list<PxRigidDynamic*> generateRBsDynamic() {
		list<PxRigidDynamic*> l; return l;
	}

	virtual list<PxRigidStatic*> generateRBsStatic() {
		list<PxRigidStatic*> l; return l;
	}

	virtual list<pair<PxRigidDynamic*, PxRigidStatic*>> generateRBsDynamicStatic();
	bool generate;

public:
	RBTargetGenerator();
	~RBTargetGenerator();
};