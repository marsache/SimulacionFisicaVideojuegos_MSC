#pragma once
#include <PxPhysicsAPI.h>

using namespace std;
using namespace physx;
typedef physx::PxVec3 Vector3;
typedef physx::PxVec4 Vector4;

namespace ParticleInfo {
	// partículas
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
		Vector4 color;
	};

	struct ParticleTypes {
		//ParticleParameters uniformParticle = { Vector3(0, 200, 155), Vector3(400, 15, 15), Vector3(0, -6, 0), Vector3(0, -6, 0), 1, 1, &PxSphereGeometry(1), 1, 400, Vector4(50, 50, 50, 50) };
		ParticleParameters uniformParticle1 = { Vector3(-200, 250, 300), Vector3(600, 50, 100), Vector3(0, -6, 0), Vector3(0, -6, 0), 1, 1, &PxSphereGeometry(1), 1, 180, Vector4(50, 50, 50, 50) };
		ParticleParameters uniformParticle2 = { Vector3(-200, 250, -300), Vector3(600, 50, -100), Vector3(0, -6, 0), Vector3(0, -6, 0), 1, 1, &PxSphereGeometry(1), 1, 150, Vector4(50, 50, 50, 50) };
		ParticleParameters uniformParticle3 = { Vector3(300, 250, -200), Vector3(100, 50, 500), Vector3(0, -6, 0), Vector3(0, -6, 0), 1, 1, &PxSphereGeometry(1), 1, 180, Vector4(50, 50, 50, 50) };
		ParticleParameters uniformParticle4 = { Vector3(-300, 250, -200), Vector3(-100, 50, 500), Vector3(0, -6, 0), Vector3(0, -6, 0), 1, 1, &PxSphereGeometry(1), 1, 150, Vector4(50, 50, 50, 50) };

		ParticleParameters particle3 = { Vector3(-100, -100, -100), Vector3(-30, -10, -30), Vector3(-20, 30, -20), Vector3(30, 70, 30), 3, 1, &PxSphereGeometry(3), 3, 30, Vector4(1, 0, 0, 1) };
		ParticleParameters particle2 = { Vector3(-100, -100, -100), Vector3(-30, -10, -30), Vector3(-20, 30, -20), Vector3(30, 70, 30), 2, 1, &PxSphereGeometry(2), 2, 20, Vector4(1, 0.5, 0, 1) };
		ParticleParameters particle1 = { Vector3(-100, -100, -100), Vector3(-30, -10, -30), Vector3(-20, 30, -20), Vector3(30, 70, 30), 1, 1, &PxSphereGeometry(1), 4, 15, Vector4(1, 1, 0, 1) };
		ParticleParameters particle0 = { Vector3(-100, -100, -100), Vector3(-30, -10, -30), Vector3(-20, 30, -20), Vector3(30, 70, 30), 0.5, 1, &PxSphereGeometry(0.5), 4, 80, Vector4(0, 1, 0, 1) };


		ParticleParameters fountainParticle = { Vector3(1, 1, 1), Vector3(10, 10, 10), Vector3(3, 3, 3), Vector3(5, 5, 5), 2, 1, &PxSphereGeometry(3), 1, 100 };
		ParticleParameters gaussianParticle = { Vector3(70, 70, 70), Vector3(10, 10, 10), Vector3(0, 0, 0), Vector3(1, 1, 1), 0.06, 1, &PxSphereGeometry(0.06), 1, 20 };
		ParticleParameters jetParticle = { Vector3(20, -50, 20), Vector3(30, -20, 30), Vector3(1, 90, 1), Vector3(1, 110, 1), 1, 10, &PxSphereGeometry(3), 1, 80 };
		ParticleParameters jetParticleExplosion = { Vector3(20, -50, 20), Vector3(30, -20, 30), Vector3(1, 20, 1), Vector3(1, 40, 1), 1, 10, &PxSphereGeometry(3), 1, 80 };/*
		ParticleParameters particle3 = { Vector3(-100, -100, -100), Vector3(-30, -10, -30), Vector3(-20, 30, -20), Vector3(30, 70, 30), 3, 1, &PxSphereGeometry(3), 3, 70 };
		ParticleParameters particle2 = { Vector3(-100, -100, -100), Vector3(-30, -10, -30), Vector3(-20, 30, -20), Vector3(30, 70, 30), 2, 1, &PxSphereGeometry(2), 2, 30 };
		ParticleParameters particle1 = { Vector3(-100, -100, -100), Vector3(-30, -10, -30), Vector3(-20, 30, -20), Vector3(30, 70, 30), 1, 1, &PxSphereGeometry(1), 4, 30 };
		ParticleParameters particle0 = { Vector3(-100, -100, -100), Vector3(-30, -10, -30), Vector3(-20, 30, -20), Vector3(30, 70, 30), 0.5, 1, &PxSphereGeometry(0.5), 4, 150 };*/
	};


	// sólidos rígidos
	struct RBParameters {
		Vector3 positionMin;
		Vector3 positionMax;
		Vector3 velocityMin;
		Vector3 velocityMax;
		float radiusMin;
		float radiusMax;
		float massMin;
		float massMax;
		float life;
	};

	struct RBTypes {
		RBParameters targetRB = { Vector3(15, 15, 15), Vector3(150, 150, 150), Vector3(0, 0, 0), Vector3(0, 0, 0), 2, 6, 10, 20, 100 };
		RBParameters projectile = { Vector3(80, 80, 80), Vector3(200, 200, 200), Vector3(0, 0, 0), Vector3(0, 0, 0), 2, 2, 5, 5, 50 };
	};
}