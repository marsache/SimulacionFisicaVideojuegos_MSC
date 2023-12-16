#include "FountainParticleGenerator.h"

list<Particle*> FountainParticleGenerator::generateParticles() {
	list<Particle*> particlesList;

	for (int i = 0; i < FOUNTAIN_PARTICLES; ++i) {
		// c�lculo de la posici�n
		ParticleTypes particleType;
		Vector3 position, velocity;

		position.x = rand() % int(particleType.fountainParticle.positionMin.x) + int(particleType.fountainParticle.positionMin.x);
		position.y = rand() % int(particleType.fountainParticle.positionMax.y) + int(particleType.fountainParticle.positionMin.y);
		position.z = rand() % int(particleType.fountainParticle.positionMax.z) + int(particleType.fountainParticle.positionMin.z);

		// generaci�n de la velocidad
		velocity.x = rand() % int(particleType.fountainParticle.velocityMin.x) + int(particleType.fountainParticle.velocityMax.x);
		velocity.y = rand() % int(particleType.fountainParticle.velocityMin.y) + int(particleType.fountainParticle.velocityMax.y);
		velocity.z = rand() % int(particleType.fountainParticle.velocityMin.z) + int(particleType.fountainParticle.velocityMax.z);

		particlesList.push_back(new Particle(position, velocity, particleType.fountainParticle.radius, particleType.fountainParticle.mass,
			&PxSphereGeometry(particleType.fountainParticle.radius), particleType.fountainParticle.generation, particleType.fountainParticle.life));
	}

	return particlesList;
}

list<PxRigidDynamic*> FountainParticleGenerator::generateRBsDynamic() {
	list<PxRigidDynamic*> rbList;

	for (int i = 0; i < FOUNTAIN_PARTICLES; ++i) {
		// c�lculo de la posici�n
		ParticleTypes particleType;
		Vector3 position, velocity;

		position.x = rand() % int(particleType.fountainRB.positionMax.x) + int(particleType.fountainRB.positionMin.x);
		position.y = rand() % int(particleType.fountainRB.positionMax.y) + int(particleType.fountainRB.positionMin.y);
		position.z = rand() % int(particleType.fountainRB.positionMax.z) + int(particleType.fountainRB.positionMin.z);

		// generaci�n de la velocidad
		velocity.x = rand() % int(particleType.fountainRB.velocityMin.x) + int(particleType.fountainRB.velocityMax.x);
		velocity.y = rand() % int(particleType.fountainRB.velocityMin.y) + int(particleType.fountainRB.velocityMax.y);
		velocity.z = rand() % int(particleType.fountainRB.velocityMin.z) + int(particleType.fountainRB.velocityMax.z);

		PxRigidDynamic* rigidBDynamic = gPhysics->createRigidDynamic(PxTransform(position));
		rigidBDynamic->setLinearVelocity({0, 100, 0});
		rigidBDynamic->setAngularVelocity({ 0, 0, 0 });
		PxShape* shape_box = CreateShape(PxBoxGeometry(particleType.fountainRB.radius, particleType.fountainRB.radius, particleType.fountainRB.radius));
		rigidBDynamic->attachShape(*shape_box);
		PxRigidBodyExt::updateMassAndInertia(*rigidBDynamic, 0.15);
		gScene->addActor(*rigidBDynamic);

		RenderItem* dynamicItem;
		dynamicItem = new RenderItem(shape_box, rigidBDynamic, { 0.8, 0.8, 0.8, 1 });

		rbList.push_back(rigidBDynamic);
	}

	return rbList;
}