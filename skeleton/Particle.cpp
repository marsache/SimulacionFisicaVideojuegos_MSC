#include "Particle.h"

Particle::Particle(Vector3 pos, Vector3 _vel, int rad, float _mass, PxGeometry* shape) : _pose(pos), vel(_vel), radius(rad), mass(_mass), timeAlive(0) {
	renderItem = new RenderItem(CreateShape(*shape), &_pose, Vector4(50, 50, 50, 50));
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