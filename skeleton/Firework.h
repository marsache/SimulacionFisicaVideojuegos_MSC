#pragma once
#include "Particle.h"
#include <list>

using namespace std;

class Firework : public Particle
{
public:
	Firework(Vector3 pos, Vector3 _vel, int rad, float _mass, PxGeometry* shape, int gen, float pLife) : 
		Particle(pos, _vel, rad, _mass, shape, gen, pLife) {}
	~Firework() {}

private:
	virtual list<Particle*> generateParticles();
};