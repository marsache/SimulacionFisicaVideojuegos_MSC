#pragma once
#include <unordered_map>
#include <unordered_set>
#include "ForceGenerator.h"

extern PxPhysics* gPhysics;
extern PxScene* gScene;
using namespace std;

const int NUM_RBS = 1;

using ListaRBPorFuerza = unordered_set<PxRigidDynamic*>;
using ListaFuerzasPorRB = unordered_set<ForceGenerator*>;

class RBForceRegistry
{
protected:
	unordered_map<ForceGenerator*, ListaRBPorFuerza> fuerzas;
	unordered_map<PxRigidDynamic*, ListaFuerzasPorRB> RBs;

public:
	RBForceRegistry() {}

	void addRegistry(ForceGenerator* f, PxRigidDynamic* rb);
	void deleteRBRegistry(PxRigidDynamic* rb);
	void deleteForceRegistry(ForceGenerator* f);
	void updateForces(double t);
	void addForce(ForceGenerator* f);
	//void updateRBs(double t);
	//void deleteDeadRBs();
	void generateRBs(ForceGenerator* f);
	//void generateStaticRBs(ForceGenerator* f);
	//void generateExplosionRBs(ForceGenerator* f);
	void addForceToAllRBs(ForceGenerator* f);
	list<PxRigidDynamic*> generateDynamicRigids();
	list<PxRigidDynamic*> generateGroundDynamicRigids();
	void addRBToRegistry(PxRigidDynamic* RB);
};