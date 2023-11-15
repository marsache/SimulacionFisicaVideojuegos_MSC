#include "Particle.h"

Particle::Particle(Vector3 pos, Vector3 _vel, float rad, float _mass, PxGeometry* shape, int gen, float pLife) : 
	_pose(pos), vel(_vel), radius(rad), mass(_mass), timeAlive(0), generation(gen), particleLife(pLife), acceleration(0, 0, 0), forces(0, 0, 0) {
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

	vel += GRAVITY * t;
	vel *= pow(DAMPING, t);
	_pose.p += vel * t;

	// vida
	if (timeAlive < particleLife)
		timeAlive += 0.1;
	else
		alive = false;

}

void Particle::integratev3(double t) {
	float aux = 1.0 / mass;
	acceleration = forces * aux;
	vel += acceleration * t;
	_pose.p += vel * t;

	// vida
	if (timeAlive < particleLife)
		timeAlive += 0.1;
	else
		alive = false;
}