#pragma once
#include <list>
#include <unordered_set>
#include "Particle.h"
#include "ParticleGenerator.h"
#include "ParticleForceRegistry.h"
#include "ParticleInfo.h"
#include "UniformParticleGenerator.h"

using namespace std;
using namespace ParticleInfo;
extern PxPhysics* gPhysics;
extern PxScene* gScene;

class ParticleSystem
{
private:
	// partículas
	list<Particle*> particles;
	list<ParticleGenerator*> particleGenerators;

	ParticleForceRegistry* particleForceRegistry;
	list<ForceGenerator*> forceGenerators;
	unordered_set<Particle*> particlesWForces;

	void createUniformParticleGenerator();
	void createGaussianParticleGenerator();
	//void createFountainParticleGenerator();
	//void createFireworkGenerator();

	ParticleGenerator* getParticleGenerator(string name);
	void deleteParticles();

	// sólidos rígidos 
	/*list<PxRigidStatic*> staticRigids;
	list<PxRigidDynamic*> dynamicRigids;
	RBForceRegistry* rbForceRegistry;
	list<ParticleGenerator*> rbGenerators;*/

public:
	ParticleSystem();
	~ParticleSystem();
	void update(double t);
};