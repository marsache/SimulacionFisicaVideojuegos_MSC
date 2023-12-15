#include "JetParticleGenerator.h"

list<Particle*> JetParticleGenerator::generateParticles() {
	list<Particle*> particlesList;
	for (int i = 0; i < JET_PARTICLES; ++i) {
		// c�lculo de la posici�n
		ParticleTypes particleType;
		Vector3 position, velocity;

		position.x = rand() % int(particleType.jetParticle.positionMin.x) + int(particleType.jetParticle.positionMin.x);
		position.y = rand() % int(particleType.jetParticle.positionMax.y) + int(particleType.jetParticle.positionMin.y);
		position.z = rand() % int(particleType.jetParticle.positionMax.z) + int(particleType.jetParticle.positionMin.z);

		// generaci�n de la velocidad
		velocity.x = rand() % int(particleType.jetParticle.velocityMin.x) + int(particleType.jetParticle.velocityMax.x);
		velocity.y = rand() % int(particleType.jetParticle.velocityMin.y) + int(particleType.jetParticle.velocityMax.y);
		velocity.z = rand() % int(particleType.jetParticle.velocityMin.z) + int(particleType.jetParticle.velocityMax.z);

		particlesList.push_back(new Particle(position, velocity, particleType.jetParticle.radius, particleType.jetParticle.mass,
			&PxSphereGeometry(particleType.jetParticle.radius), particleType.jetParticle.generation, particleType.jetParticle.life));
	}

	return particlesList;
}

//list<PxRigidDynamic*> JetParticleGenerator::generateRBsDynamic() {
//	list<PxRigidDynamic*> RBsList;
//	for (int i = 0; i < JET_RBS; ++i) {
//		// c�lculo de la posici�n
//		ParticleTypes particleType;
//		Vector3 position, velocity;
//
//		position.x = rand() % int(particleType.jetParticle.positionMin.x) + int(particleType.jetParticle.positionMin.x);
//		position.y = rand() % int(particleType.jetParticle.positionMax.y) + int(particleType.jetParticle.positionMin.y);
//		position.z = rand() % int(particleType.jetParticle.positionMax.z) + int(particleType.jetParticle.positionMin.z);
//
//		// generaci�n de la velocidad
//		velocity.x = rand() % int(particleType.jetParticle.velocityMin.x) + int(particleType.jetParticle.velocityMax.x);
//		velocity.y = rand() % int(particleType.jetParticle.velocityMin.y) + int(particleType.jetParticle.velocityMax.y);
//		velocity.z = rand() % int(particleType.jetParticle.velocityMin.z) + int(particleType.jetParticle.velocityMax.z);
//
//
//
//		particlesList.push_back(new Particle(position, velocity, particleType.jetParticle.radius, particleType.jetParticle.mass,
//			&PxSphereGeometry(particleType.jetParticle.radius), particleType.jetParticle.generation, particleType.jetParticle.life));
//	}
//
//	return particlesList;
//}