#include "UniformParticleGenerator.h"

UniformParticleGenerator::UniformParticleGenerator() : ParticleGenerator() {}

UniformParticleGenerator::~UniformParticleGenerator() {
	delete(this);
}

list<Particle*> UniformParticleGenerator::generateParticles() {
	list<Particle*> particlesList;

	// cambiar velocidad
	for (int i = 0; i < UNIFORM_PARTICLES; ++i) {
		// cálculo de la posición
	// como es nieve, las coordenadas y, z varían mucho menos que la x
		meanPos.x = rand() % MAX_X;
		meanPos.y = rand() % MAX_YZ + MIN_YZ;
		meanPos.z = rand() % MAX_YZ + MIN_YZ;

		particlesList.push_back(new Particle(meanPos, Vector3(0, -3, 0), UNIFORM_PARTICLE_RADIUS, 5, &PxSphereGeometry(UNIFORM_PARTICLE_RADIUS), 1, UNIFORM_PARTICLE_LIFE));
	}

	return particlesList;
}

list<PxRigidDynamic*> UniformParticleGenerator::generateRBsDynamic() {
	list<PxRigidDynamic*> rbList;

	// cambiar velocidad
	for (int i = 0; i < UNIFORM_PARTICLES; ++i) {
		// cálculo de la posición
		// como es nieve, las coordenadas y, z varían mucho menos que la x
		meanPos.x = rand() % MAX_X;
		meanPos.y = rand() % MAX_YZ + MIN_YZ;
		meanPos.z = rand() % MAX_YZ + MIN_YZ;

		PxRigidDynamic* rigidBDynamic = gPhysics->createRigidDynamic(PxTransform(meanPos));
		rigidBDynamic->setLinearVelocity(Vector3(0, -3, 0));
		rigidBDynamic->setAngularVelocity({ 0, 0, 0 });
		PxShape* shape_box = CreateShape(PxBoxGeometry(UNIFORM_PARTICLE_RADIUS, UNIFORM_PARTICLE_RADIUS, UNIFORM_PARTICLE_RADIUS));
		rigidBDynamic->attachShape(*shape_box);
		PxRigidBodyExt::updateMassAndInertia(*rigidBDynamic, 0.15);
		gScene->addActor(*rigidBDynamic);

		RenderItem* dynamicItem;
		dynamicItem = new RenderItem(shape_box, rigidBDynamic, { 0.8, 0.8, 0.8, 1 });

		rbList.push_back(rigidBDynamic);
	}

	return rbList;
}