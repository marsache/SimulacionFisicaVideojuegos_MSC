#pragma once
#include <PxPhysicsAPI.h>

using namespace std;
using namespace physx;
typedef physx::PxVec3 Vector3;

namespace ParticleInfo {
	struct ParticleParameters {
		Vector3 positionMin;
		Vector3 positionMax;
		Vector3 velocityMin;
		Vector3 velocityMax;
		float radius;
		float mass;
		PxGeometry* shape;
		int generation;
		float life;
	};

	struct ParticleTypes {
		ParticleParameters fountainParticle = { Vector3(1, 1, 1), Vector3(10, 10, 10), Vector3(3, 3, 3), Vector3(10, 10, 10), 2, 1, &PxSphereGeometry(3), 1, 100 };
		ParticleParameters gaussianParticle = { Vector3(70, 70, 70), Vector3(10, 10, 10), Vector3(0, 0, 0), Vector3(1, 1, 1), 0.06, 1, &PxSphereGeometry(0.06), 1, 20 };
		ParticleParameters jetParticle = { Vector3(20, 20, 20), Vector3(30, 30, 30), Vector3(1, 90, 1), Vector3(1, 110, 1), 1, 10, &PxSphereGeometry(3), 1, 100 };
		ParticleParameters particle3 = { Vector3(-100, -100, -100), Vector3(-30, -10, -30), Vector3(-20, 30, -20), Vector3(30, 70, 30), 3, 1, &PxSphereGeometry(3), 3, 70 };
		ParticleParameters particle2 = { Vector3(-100, -100, -100), Vector3(-30, -10, -30), Vector3(-20, 30, -20), Vector3(30, 70, 30), 2, 1, &PxSphereGeometry(2), 2, 30 };
		ParticleParameters particle1 = { Vector3(-100, -100, -100), Vector3(-30, -10, -30), Vector3(-20, 30, -20), Vector3(30, 70, 30), 1, 1, &PxSphereGeometry(1), 4, 30 };
		ParticleParameters particle0 = { Vector3(-100, -100, -100), Vector3(-30, -10, -30), Vector3(-20, 30, -20), Vector3(30, 70, 30), 0.5, 1, &PxSphereGeometry(0.5), 4, 150 };
	};
}