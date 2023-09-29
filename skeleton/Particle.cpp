#include "Particle.h"

Particle::Particle(Vector3 Pos, Vector3 Vel, int Rad) : _pose(Pos), vel(Vel), radius(Rad) {
	renderItem = new RenderItem(CreateShape(PxSphereGeometry(radius)), &_pose ,Vector4(50, 50, 50, 50));
}

Particle::~Particle() {
	delete(renderItem);
}

void Particle::integrate(double t) {
	_pose.p.x += vel.x;
	_pose.p.y += vel.y;
	_pose.p.z += vel.z;
}

void Particle::integratev2(double t) {
	vel.x = (vel.x + ACCELERATION.x * t) * pow(DAMPING, t);
	vel.y = (vel.y + ACCELERATION.y * t) * pow(DAMPING, t);
	vel.z = (vel.z + ACCELERATION.z * t) * pow(DAMPING, t);
	_pose.p.x += vel.x;
	_pose.p.y += vel.y;
	_pose.p.z += vel.z;
}