#include "Particle.h"
#include "Particle.h"

Particle::Particle(Vector3 pos, Vector3 vel, float rad, float _mass, PxGeometry* shape, int gen, float pLife, Vector4 _color) :
	position(pos), velocity(vel), initialVelocity(vel), radius(rad), mass(_mass), timeAlive(0), generation(gen), 
	particleLife(pLife), acceleration(0, 0, 0), forces(0, 0, 0), alive(true), color(_color) {
	renderItem = new RenderItem(CreateShape(PxSphereGeometry(rad)), &position, color);
}

Particle::~Particle() {
	renderItem->release();
}

void Particle::integrate(double t) {
	float aux = 1.0 / mass;
	acceleration = forces * aux;
	//vel *= pow(DAMPING, t);
	velocity += acceleration * t;
	position.p += velocity * t;

	// vida
	if (particleLife != -1) {
		if (timeAlive < particleLife)
			timeAlive += 0.1;
		else
			alive = false;
	}

	forces = Vector3(0, 0, 0);
}