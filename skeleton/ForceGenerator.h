#pragma once
#include "Particle.h"
#include <string>
#include <unordered_set>

using namespace std;

class ForceGenerator
{
protected:
	string name;
	double k; // constante el�stica

public:
	ForceGenerator();
	virtual void updateForce(Particle* p, double t) {};
	//virtual unordered_set<Particle*> generateParticles() = 0;

	void setName(string _name) { name = _name; }
	string getName() { return name; }

	inline void setK(double _k) { k = _k; }
	inline double getK() { return k; }
};