#include "Particle.h"

Particle::Particle(Vector3 Pos, Vector3 Vel, int Rad, float Masa) : _pose(Pos), vel(Vel), radius(Rad), mass(Masa), timeAlive(0) {
	renderItem = new RenderItem(CreateShape(PxSphereGeometry(radius)), &_pose ,Vector4(50, 50, 50, 50));
	alive = true;
}

Particle::~Particle() {
	renderItem->release();
}

//void Particle::integrate(double t) {
//	_pose.p.x += vel.x;
//	_pose.p.y += vel.y;
//	_pose.p.z += vel.z;
//}

void Particle::integratev2(double t) {
	// velocidad y posición
	/*vel.x = (vel.x + ACCELERATION.x * t) * pow(DAMPING, t);
	vel.y = (vel.y + ACCELERATION.y * t) * pow(DAMPING, t);
	vel.z = (vel.z + ACCELERATION.z * t) * pow(DAMPING, t);
	_pose.p.x += vel.x;
	_pose.p.y += vel.y;
	_pose.p.z += vel.z;*/

	vel += ACCELERATION * t;
	vel *= pow(DAMPING, t);
	_pose.p += vel * t;

	// vida
	if (timeAlive < PARTICLE_LIFE)
		timeAlive += 0.1;
	else
		alive = false;

}