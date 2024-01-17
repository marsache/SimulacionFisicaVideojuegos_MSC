#pragma once
#include "Particle.h"
#include <list>

using namespace std;

class Firework : public Particle
{
public:
	Firework(Vector3 pos, Vector3 _vel, float rad, float _mass, PxGeometry* shape, int gen, float pLife, Vector4 color) :
		Particle(pos, _vel, rad, _mass, shape, gen, pLife, color), generation(gen) {}

	int getGen() { return generation; }

private:

	int generation;
};