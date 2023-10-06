#pragma once

#include <string>
#include "Particle.h"

using namespace std;

class ParticleGenerator
{
private:
	string name;
	Vector3 pos, vel;
	double generationProbability;
	int numParticles;
	Particle* model;

public:
	void setParticle(Particle* model);
	virtual list<Particle*> generateParticles() = 0;

};