#include "SpringForceGenerator.h"

SpringForceGenerator::SpringForceGenerator(double _k, double _restingLength, Particle* _other) : ForceGenerator(), restingLength(_restingLength), other(_other) {
	k = _k;
}

void SpringForceGenerator::updateForce(Particle* particle, double t) {
	// particle es la partícula a la que se le aplica la fuerza
	Vector3 relativePosVector = other->getPosition() - particle->getPosition();

	// normalize: normaliza relativePosVector y devuelve su longitud
	const float deltaX = relativePosVector.normalize() - restingLength;

	Vector3 force = relativePosVector * deltaX * k;

	particle->addForce(force);
}