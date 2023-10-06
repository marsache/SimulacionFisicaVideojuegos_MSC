#pragma once

#include <list>
#include "Particle.h"
#include "ParticleGenerator.h"

using namespace std;

const int PARTICLE_RADIUS = 2;
const int PARTICLE_POS_INI = 0;
const int PARTICLE_POS_FIN = 5;
const Vector3 PARTICLE_DIR = Vector3(0, 10, 0);

class ParticleSystem
{
private:
	list<Particle*> particles;
	list<ParticleGenerator*> particleGenerators;

public:
	ParticleSystem();
	~ParticleSystem();

	void update(double t);
	//ParticleGenerator* getParticleGenerator(string name);
	void generateFireworkSystem();
};