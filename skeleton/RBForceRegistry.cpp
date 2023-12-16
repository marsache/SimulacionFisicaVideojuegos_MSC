#include "RBForceRegistry.h"

void RBForceRegistry::addRegistry(ForceGenerator* f, PxRigidDynamic* rb) {
	// se actualiza el map de fuerzas
	auto itMapFuerzas = fuerzas.find(f);
	// si no se ha registrado ya la fuerza, se crea
	if (itMapFuerzas == fuerzas.end()) {
		ListaRBPorFuerza lista;
		lista.insert(rb);
		fuerzas.insert({ f, lista }); // se inserta la fuerza y la partícula
	}
	// si ya existe la fuerza, se añade la partícula
	else
		itMapFuerzas->second.insert(rb); // se inserta la partícula

	// se actualiza el map de partículas
	auto itMapRBs = RBs.find(rb);
	// si no se ha registrado ya la fuerza, se crea
	if (itMapRBs == RBs.end()) {
		ListaFuerzasPorRB lista;
		lista.insert(f);
		RBs.insert({ rb, lista }); // se inserta la partícula y la fuerza
	}
	// si ya existe la partícula, se añade la fuerza
	else
		itMapRBs->second.insert(f);
}

void RBForceRegistry::deleteRBRegistry(PxRigidDynamic* rb) {
	// se elimina la partícula de todas las fuerzas que tiene
	// (se elimina del map de fuerzas)
	auto itMapRBs = RBs.find(rb); // coste constante
	// sólo se procesa la partícula si esta existe
	if (itMapRBs != RBs.end()) {
		// se recorre la lista de fuerzas que afectan a la partícula
		auto itListaFuerzas = itMapRBs->second.begin();
		while (itListaFuerzas != itMapRBs->second.end()) { // coste lineal en función del número de fuerzas que afectan a la partícula
			// se modifica el map de fuerzas
			auto itMapFuerzas = fuerzas.find(*itListaFuerzas); // coste constante
			// se busca la partícula a la que afecta la fuerza
			auto itListaRBs = itMapFuerzas->second.find(rb); // coste constante
			if (itListaRBs != itMapFuerzas->second.end())
				itMapFuerzas->second.erase(itListaRBs);
			itListaFuerzas++;
		}

		// se elimina completamente la partícula del map de partículas
		RBs.erase(itMapRBs);

		//delete(p);
	}
}

void RBForceRegistry::deleteForceRegistry(ForceGenerator* f) {
	// se elimina la fuerza de todas las partículas que la tienen
	// (se elimina del map de partículas)
	auto itMapFuerzas = fuerzas.find(f); // coste constante
	// sólo se procesa la fuerza si esta existe
	if (itMapFuerzas != fuerzas.end()) {
		// se recorre la lista de partículas a las que afecta la fuerza
		auto itListaRBs = itMapFuerzas->second.begin();
		while (itListaRBs != itMapFuerzas->second.end()) { // coste lineal en función del número de fuerzas que afectan a la partícula
			// se modifica el map de partículas
			auto itMapRBs = RBs.find(*itListaRBs); // coste constante
			// se busca la fuerza a la que afecta a la partícula
			auto itListaFuerzas = itMapRBs->second.find(f); // coste constante
			if (itListaFuerzas != itMapRBs->second.end())
				itMapRBs->second.erase(itListaFuerzas);
			itListaRBs++;
		}

		// se elimina completamente la fuerza del map de fuerza
		fuerzas.erase(itMapFuerzas);

		//delete(f);
	}
}

void RBForceRegistry::updateForces(double t) {
	// recorre el map de particulas
	auto itMapRBs = RBs.begin();
	while (itMapRBs != RBs.end())
	{
		auto itFuerzaRB = itMapRBs->second.begin();
		while (itFuerzaRB != itMapRBs->second.end()) {
			// actualiza la fuerza
			(*itFuerzaRB)->updateForce(itMapRBs->first, t);
			++itFuerzaRB;
		}
		++itMapRBs;
	}
}

void RBForceRegistry::addForce(ForceGenerator* f) {
	// sólo crea la fuerza si aún no existe
	auto itFuerza = fuerzas.find(f);
	if (itFuerza == fuerzas.end())
		fuerzas.insert({ f, {} });
}

//void RBForceRegistry::updateRBs(double t) {
//	for (auto rb : RBs) {
//		rb.first->integratev3(t);
//	}
//}

//void RBForceRegistry::deleteDeadRBs() {
//	auto rb = RBs.begin();
//	while (rb != RBs.end()) {
//		if (!(*rb).first->isAlive()) {
//			PxRigidBody* aux = (*rb).first;
//			rb++;
//			deleteRBRegistry(aux);
//			delete(aux);
//		}
//		else
//			rb++;
//	}
//}

// RBs dinámicos
void RBForceRegistry::generateRBs(ForceGenerator* f) {
	// creación de una fuente como núcleo de partículas genéricas sobre las que probar las fuerzas
	for (int i = 0; i < NUM_RBS; ++i) {
		// cálculo de la posición
		PxRigidDynamic* rigidBDynamic = gPhysics->createRigidDynamic(PxTransform({-70, 200, -70}));
		rigidBDynamic->setLinearVelocity({0, 5, 0});
		rigidBDynamic->setAngularVelocity({0, 0, 0});
		PxShape* shape_box = CreateShape(PxBoxGeometry(5, 5, 5));
		rigidBDynamic->attachShape(*shape_box);



		//ParticleTypes particleType;
		//Vector3 position, velocity;

		//position.x = rand() % int(particleType.jetParticle.positionMin.x) + int(particleType.jetParticle.positionMin.x);
		//position.y = rand() % int(particleType.jetParticle.positionMax.y) + int(particleType.jetParticle.positionMin.y);
		//position.z = rand() % int(particleType.jetParticle.positionMax.z) + int(particleType.jetParticle.positionMin.z);

		//// generación de la velocidad
		//velocity.x = rand() % int(particleType.jetParticle.velocityMin.x) + int(particleType.jetParticle.velocityMax.x);
		//velocity.y = rand() % int(particleType.jetParticle.velocityMin.y) + int(particleType.jetParticle.velocityMax.y);
		//velocity.z = rand() % int(particleType.jetParticle.velocityMin.z) + int(particleType.jetParticle.velocityMax.z);

		//Particle* particle = new Particle(position, velocity, particleType.jetParticle.radius, particleType.jetParticle.mass,
		//	&PxSphereGeometry(particleType.jetParticle.radius), particleType.jetParticle.generation, particleType.jetParticle.life);

		addRegistry(f, rigidBDynamic);
	}
}

//void RBForceRegistry::generateStaticRBs(ForceGenerator* f) {
//	// creación de una fuente como núcleo de partículas genéricas sobre las que probar las fuerzas
//	for (int i = 0; i < NUM_RBS; ++i) {
//		// cálculo de la posición
//		ParticleTypes particleType;
//		Vector3 position, velocity;
//
//		position.x = rand() % int(particleType.jetParticle.positionMin.x) + int(particleType.jetParticle.positionMin.x);
//		position.y = rand() % int(particleType.jetParticle.positionMax.y) + int(particleType.jetParticle.positionMin.y);
//		position.z = rand() % int(particleType.jetParticle.positionMax.z) + int(particleType.jetParticle.positionMin.z);
//
//		// generación de la velocidad
//		velocity = { 0, 0, 0 };
//
//		Particle* particle = new Particle(position, velocity, particleType.jetParticle.radius, particleType.jetParticle.mass,
//			&PxSphereGeometry(particleType.jetParticle.radius), particleType.jetParticle.generation, particleType.jetParticle.life);
//
//		addRegistry(f, particle);
//	}
//}
//
//void RBForceRegistry::generateExplosionRBs(ForceGenerator* f) {
//	// creación de una fuente como núcleo de partículas genéricas sobre las que probar las fuerzas
//	for (int i = 0; i < NUM_RBS; ++i) {
//		// cálculo de la posición
//		ParticleTypes particleType;
//		Vector3 position, velocity;
//
//		position.x = rand() % int(particleType.jetParticleExplosion.positionMin.x) + int(particleType.jetParticleExplosion.positionMin.x);
//		position.y = rand() % int(particleType.jetParticleExplosion.positionMax.y) + int(particleType.jetParticleExplosion.positionMin.y);
//		position.z = rand() % int(particleType.jetParticleExplosion.positionMax.z) + int(particleType.jetParticleExplosion.positionMin.z);
//
//		// generación de la velocidad
//		velocity = { 0, 0, 0 };
//
//		Particle* particle = new Particle(position, velocity, particleType.jetParticleExplosion.radius, particleType.jetParticleExplosion.mass,
//			&PxSphereGeometry(particleType.jetParticleExplosion.radius), particleType.jetParticleExplosion.generation, particleType.jetParticleExplosion.life);
//
//		addRegistry(f, particle);
//	}
//}

void RBForceRegistry::addForceToAllRBs(ForceGenerator* f) {
	auto itForce = fuerzas.find(f);
	auto itRBs = RBs.begin();
	while (itRBs != RBs.end()) {
		(*itRBs).second.insert(f);
		(*itForce).second.insert((*itRBs).first);
		++itRBs;
	}
}

list<PxRigidDynamic*> RBForceRegistry::generateDynamicRigids() {
	list<PxRigidDynamic*> lista;

	for (int i = 0; i < NUM_RBS; ++i) {
		// cálculo de la posición
		PxRigidDynamic* rigidBDynamic = gPhysics->createRigidDynamic(PxTransform({ -70, 200, -70 }));
		rigidBDynamic->setLinearVelocity({ 0, -1, 0 });
		rigidBDynamic->setAngularVelocity({ 0, 0, 0 });
		PxShape* shape_box = CreateShape(PxBoxGeometry(5, 5, 5));
		rigidBDynamic->attachShape(*shape_box);
		PxRigidBodyExt::updateMassAndInertia(*rigidBDynamic, 0.15);
		gScene->addActor(*rigidBDynamic);

		RenderItem* dynamicItem;
		dynamicItem = new RenderItem(shape_box, rigidBDynamic, {0.8, 0.8, 0.8, 1});

		lista.push_back(rigidBDynamic);

		ListaFuerzasPorRB listaAux;
		RBs.insert({ rigidBDynamic, listaAux });
	}

	return lista;
}

list<PxRigidDynamic*> RBForceRegistry::generateGroundDynamicRigids() {
	list<PxRigidDynamic*> lista;

	for (int i = 0; i < NUM_RBS; ++i) {
		Vector3 position;
		position.x = rand() % 30;
		position.y = rand() % 30;
		position.z = rand() % 30;

		// cálculo de la posición
		//PxRigidDynamic* rigidBDynamic = gPhysics->createRigidDynamic(PxTransform({ 0, 100, 0 }));
		//rigidBDynamic->setLinearVelocity({ 0, -20, 0 });
		//PxRigidDynamic* rigidBDynamic = gPhysics->createRigidDynamic(PxTransform({ 0, 10, 0 }));
		//rigidBDynamic->setLinearVelocity({ 0, 1, 0 });
		PxRigidDynamic* rigidBDynamic = gPhysics->createRigidDynamic(PxTransform(position));
		rigidBDynamic->setLinearVelocity({ 0, 1, 0 });
		rigidBDynamic->setAngularVelocity({ 0, 0, 0 });
		PxShape* shape_box = CreateShape(PxBoxGeometry(5, 5, 5));
		rigidBDynamic->attachShape(*shape_box);
		PxRigidBodyExt::updateMassAndInertia(*rigidBDynamic, 0.15);
		gScene->addActor(*rigidBDynamic);

		RenderItem* dynamicItem;
		dynamicItem = new RenderItem(shape_box, rigidBDynamic, { 0.8, 0.8, 0.8, 1 });

		lista.push_back(rigidBDynamic);

		ListaFuerzasPorRB listaAux;
		RBs.insert({ rigidBDynamic, listaAux });
	}

	return lista;
}

void RBForceRegistry::addRBToRegistry(PxRigidDynamic* RB) {
	ListaFuerzasPorRB listaAux;
	RBs.insert({ RB, listaAux });
}