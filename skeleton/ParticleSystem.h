#pragma once
#include <list>
#include <unordered_set>
#include "Particle.h"
#include "ParticleGenerator.h"
#include "ParticleForceRegistry.h"
#include "ParticleInfo.h"
#include "UniformParticleGenerator.h"
#include "GaussianParticleGenerator.h"
#include "BuoyancyForceGenerator.h"
#include "GravityForce.h"
#include "WindForce.h"

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

	ParticleGenerator* getParticleGenerator(string name);
	void deleteParticles();

	UniformParticleGenerator* uniformPG;
	GaussianParticleGenerator* gaussianPG;
	WindForce* windForce;

	void generateBuoyancyForce();
	void createGravityForce();

	int points;

public:
	ParticleSystem();
	~ParticleSystem();
	void update(double t);

	int getPoints() { return points; }
	void winPoint() { points++; }
};