#pragma once
#include "ForceGenerator.h"
#include <cstdlib>
#include <cmath>

class SpringForceGenerator : public ForceGenerator {
protected:
	double k; // constante elástica
	double restingLength; // longitud que tiene el muelle cando está en equilibrio
	Particle* other;

public:
	SpringForceGenerator(double _k, double _restingLength, Particle* _other);

	virtual void updateForce(Particle* particle, double t);
	inline void setK(double _k) { k = _k; }
};