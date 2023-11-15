#pragma once
#include "Particle.h"
#include <string>
#include <unordered_set>

using namespace std;

class ForceGenerator
{
protected:
	string name;
public:
	ForceGenerator();
	virtual void updateForce(Particle* p) {};
	virtual unordered_set<Particle*> generateParticles() = 0;

	void setName(string _name) { name = _name; }
	string getName() { return name; }
};