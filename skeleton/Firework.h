#pragma once
#include "Particle.h"
#include <list>

using namespace std;

class Firework : public Particle
{
public:
	Firework(Vector3 pos, Vector3 _vel, float rad, float _mass, PxGeometry* shape, int gen, float pLife) :
		Particle(pos, _vel, rad, _mass, shape, gen, pLife), generation(gen) {}
	~Firework() {}

	int getGen() { return generation; }

private:
	//virtual list<Particle*> generateParticles();

	int generation;
};