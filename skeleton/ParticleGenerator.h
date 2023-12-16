#pragma once

#include <string>
#include <list>
#include "Particle.h"

using namespace std;
extern PxPhysics* gPhysics;
extern PxScene* gScene;

class ParticleGenerator
{
protected:
	string name;
	Vector3 meanPos, meanVel;
	double generationProbability;
	int numParticles;
	Particle* model;

public:
	void setParticle(Particle* model) {};
	virtual list<Particle*> generateParticles() = 0;
	virtual list<PxRigidDynamic*> generateRBsDynamic() = 0;

	void setName(string _name) { name = _name; }
	string getName() { return name; }
};