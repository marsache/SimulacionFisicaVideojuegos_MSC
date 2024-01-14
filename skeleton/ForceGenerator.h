#pragma once
#include "Particle.h"
#include <string>
#include <unordered_set>

using namespace std;

class ForceGenerator
{
protected:
	string name;
	double k; // constante elástica

public:
	ForceGenerator();
	~ForceGenerator() { 
		name = "";
		k = 0;
		delete(this); 
	}
	virtual void updateForce(Particle* p, double t) {};
	virtual void updateForce(PxRigidDynamic* p, double t) {};
	//virtual unordered_set<Particle*> generateParticles() = 0;

	void setName(string _name) { name = _name; }
	string getName() { return name; }

	inline void setK(double _k) { k = _k; }
	inline double getK() { return k; }
};