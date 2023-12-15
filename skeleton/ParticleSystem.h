#pragma once

#include <list>
#include <unordered_set>
#include "Particle.h"
#include "ParticleGenerator.h"
#include "GaussianParticleGenerator.h"
#include "UniformParticleGenerator.h"
#include "FountainParticleGenerator.h"
#include "FireworkParticleGenerator.h"
#include "JetParticleGenerator.h"

#include "ParticleForceRegistry.h"
#include "ForceGenerator.h"
#include "GravityForce.h"
#include "WindForce.h"
#include "WhirlwindForce.h"
#include "ExplosionForce.h"

#include "SpringForceGenerator.h"
#include "BuoyancyForceGenerator.h"

#include "RBForceRegistry.h"

using namespace std;

//const int PARTICLE_RADIUS = 2;
//const int PARTICLE_POS_INI = 0;
//const int PARTICLE_POS_FIN = 5;
//const Vector3 PARTICLE_DIR = Vector3(0, 10, 0);

class ParticleSystem
{
private:
	const int RB_LIMIT = 1;

	// partículas
	list<Particle*> particles;
	list<Firework*> fireworks;
	list<ParticleGenerator*> particleGenerators;

	ParticleForceRegistry* particleForceRegistry;
	list<ForceGenerator*> forceGenerators;
	unordered_set<Particle*> particlesWForces;

	// sólidos rígidos 
	list<PxRigidStatic*> staticRigids;
	list<PxRigidDynamic*> dynamicRigids;
	RBForceRegistry* rbForceRegistry;
	//list<ForceGenerator*> rbforceGenerators;
	/*list<ParticleGenerator*> particleGenerators;

	unordered_set<Particle*> particlesWForces;*/

public:
	ParticleSystem();
	~ParticleSystem();

	void update(double t);
	ParticleGenerator* getParticleGenerator(string name);
	void generateFireworkSystem();
	void deleteParticles();
	void explode();

	void createUniformParticleGenerator();
	void createGaussianParticleGenerator();
	void createFountainParticleGenerator();
	void createFireworkGenerator();
	void createJetParticleGenerator();

	void createGravityForce();
	void createWindForce();
	void createWhirlwindForce();
	void createExplosionForce();

	void generateSpringForce();
	void generateDoubleSpringForce();
	void generateBuoyancyForce();
	void generateSlinkyForce();
	void increaseKSpring();
	void decreaseKSpring();
};