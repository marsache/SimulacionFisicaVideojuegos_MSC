#include "RBTargetGenerator.h"

RBTargetGenerator::RBTargetGenerator() : generate(true) {}

RBTargetGenerator::~RBTargetGenerator() {
	delete(this);
}

list<pair<PxRigidDynamic*, PxRigidStatic*>> RBTargetGenerator::generateRBsDynamicStatic() {
	list<pair<PxRigidDynamic*, PxRigidStatic*>> RBsList;
	if (generate) {
		generate = false;

		RBTypes rbType;

		position.x = rand() % int(rbType.targetRB.positionMax.x) + int(rbType.targetRB.positionMin.x);
		position.y = rand() % int(rbType.targetRB.positionMax.y) + int(rbType.targetRB.positionMin.y);
		position.z = rand() % int(rbType.targetRB.positionMax.z) + int(rbType.targetRB.positionMin.z);

		velocity = rbType.targetRB.velocityMin;

		radius = rand() % int(rbType.targetRB.radiusMax) + int(rbType.targetRB.radiusMin);

		PxRigidDynamic* rigidBDynamic = gPhysics->createRigidDynamic(PxTransform(position));
		rigidBDynamic->setLinearVelocity({ 0, 0, 0 });
		rigidBDynamic->setAngularVelocity({ 0, 0, 0 });
		PxShape* shape_box_dynamic = CreateShape(PxBoxGeometry(radius, radius, radius));
		rigidBDynamic->attachShape(*shape_box_dynamic);
		PxRigidBodyExt::updateMassAndInertia(*rigidBDynamic, 0.15);
		gScene->addActor(*rigidBDynamic);

		rigidBDynamic->setMassSpaceInertiaTensor(Vector3(0, 0, 0));

		RenderItem* dynamicItem;
		dynamicItem = new RenderItem(shape_box_dynamic, rigidBDynamic, { 0.8, 0.8, 0.8, 1 });


		PxRigidStatic* rigidBStatic = gPhysics->createRigidStatic(PxTransform(position - Vector3(0, 100, 0)));
		PxShape* shape_box_static = CreateShape(PxBoxGeometry(5, 1, 5));
		rigidBStatic->attachShape(*shape_box_static);
		gScene->addActor(*rigidBStatic);

		RenderItem* staticItem;
		staticItem = new RenderItem(shape_box_static, rigidBStatic, { 0.8, 0.8, 0.8, 1 });


		RBsList.push_back({ rigidBDynamic, rigidBStatic });

	}
	return RBsList;
}