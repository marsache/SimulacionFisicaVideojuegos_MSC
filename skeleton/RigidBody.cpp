#include "RigidBody.h"

RigidBody::RigidBody(Vector3 _position, int _radius, Vector3 _linearVelocity, float _life, bool _hasLife, Vector4 _color) : 
	position(_position), radius(_radius), linearVelocity(_linearVelocity), life(_life), alive(true), timeAlive(0), color(_color) {
	rigidBDynamic = gPhysics->createRigidDynamic(PxTransform(position));
	rigidBDynamic->setLinearVelocity(linearVelocity);
	rigidBDynamic->setAngularVelocity({ 0, 0, 0 });
	PxShape* shape_box_dynamic = CreateShape(PxBoxGeometry(radius, radius, radius));
	rigidBDynamic->attachShape(*shape_box_dynamic);
	PxRigidBodyExt::updateMassAndInertia(*rigidBDynamic, 0.15);
	gScene->addActor(*rigidBDynamic);

	

	rigidBDynamic->setMassSpaceInertiaTensor(Vector3(0, 0, 0));

	dynamicItem = new RenderItem(shape_box_dynamic, rigidBDynamic, color);
}

RigidBody::~RigidBody() {
	dynamicItem->release();
}

void RigidBody::integrate(double t) {
	if (hasLife) {
		if (timeAlive < life)
			timeAlive += 0.1;
		else
			alive = false;
	}
}