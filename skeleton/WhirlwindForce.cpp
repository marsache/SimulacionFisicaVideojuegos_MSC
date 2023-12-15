#include "WhirlwindForce.h"

void WhirlwindForce::updateForce(Particle* p, double t) {
	Vector3 force;
	force.x = -(p->getPosition().z - influencedArea.p.z);
	if (p->getPosition().y >= influencedArea.p.y + MAX_HEIGHT)
		force.y = 0;
	else
		force.y = 50 - (p->getPosition().y - influencedArea.p.y);
	force.z = p->getPosition().x - influencedArea.p.x;

	p->addForce(K_WHIRLWIND * force);
}

void WhirlwindForce::updateForce(PxRigidDynamic* rb, double t) {
	Vector3 force;
	force.x = -(rb->getGlobalPose().p.z - influencedArea.p.z);
	if (rb->getGlobalPose().p.y >= influencedArea.p.y + MAX_HEIGHT)
		force.y = 0;
	else
		force.y = 50 - (rb->getGlobalPose().p.y - influencedArea.p.y);
	force.z = rb->getGlobalPose().p.x - influencedArea.p.x;

	rb->addForce(K_WHIRLWIND * force);
}