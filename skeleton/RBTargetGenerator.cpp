#include "RBTargetGenerator.h"

RBTargetGenerator::RBTargetGenerator() : generate(true) {}

RBTargetGenerator::~RBTargetGenerator() {
	delete(this);
}

list<pair<RigidBody*, PxRigidStatic*>> RBTargetGenerator::generateRBsDynamicStatic() {
	list<pair<RigidBody*, PxRigidStatic*>> RBsList;
	if (generate) {
		generate = false;

		RBTypes rbType;

		position.x = rand() % int(rbType.targetRB.positionMax.x) + int(rbType.targetRB.positionMin.x);
		position.y = rand() % int(rbType.targetRB.positionMax.y) + int(rbType.targetRB.positionMin.y);
		position.z = rand() % int(rbType.targetRB.positionMax.z) + int(rbType.targetRB.positionMin.z);

		velocity = rbType.targetRB.velocityMin;

		radius = rand() % int(rbType.targetRB.radiusMax) + int(rbType.targetRB.radiusMin);

		PxRigidStatic* rigidBStatic = gPhysics->createRigidStatic(PxTransform(position - Vector3(0, 100, 0)));
		PxShape* shape_box_static = CreateShape(PxBoxGeometry(5, 1, 5));
		rigidBStatic->attachShape(*shape_box_static);
		gScene->addActor(*rigidBStatic);

		RenderItem* staticItem;
		staticItem = new RenderItem(shape_box_static, rigidBStatic, { 0.8, 0.8, 0.8, 1 });


		RBsList.push_back({ new RigidBody(position, radius, velocity, rbType.targetRB.life, false, {0.8, 0.8, 0.8, 1}), rigidBStatic });

	}
	return RBsList;
}