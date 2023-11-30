#include "ParticleForceRegistry.h"

void ParticleForceRegistry::addRegistry(ForceGenerator* f, Particle* p) {
	// se actualiza el map de fuerzas
	auto itMapFuerzas = fuerzas.find(f);
	// si no se ha registrado ya la fuerza, se crea
	if (itMapFuerzas == fuerzas.end()) {
		ListaParticulasPorFuerza lista;
		lista.insert(p);
		fuerzas.insert({ f, lista }); // se inserta la fuerza y la partícula
	}
	// si ya existe la fuerza, se añade la partícula
	else 
		itMapFuerzas->second.insert(p); // se inserta la partícula

	// se actualiza el map de partículas
	auto itMapParticulas = particulas.find(p);
	// si no se ha registrado ya la fuerza, se crea
	if (itMapParticulas == particulas.end()) {
		ListaFuerzasPorParticula lista;
		lista.insert(f);
		particulas.insert({ p, lista }); // se inserta la partícula y la fuerza
	}
	// si ya existe la partícula, se añade la fuerza
	else
		itMapParticulas->second.insert(f);
}

void ParticleForceRegistry::deleteParticleRegistry(Particle* p) {
	// se elimina la partícula de todas las fuerzas que tiene
	// (se elimina del map de fuerzas)
	auto itMapParticula = particulas.find(p); // coste constante
	// sólo se procesa la partícula si esta existe
	if (itMapParticula != particulas.end()) {
		// se recorre la lista de fuerzas que afectan a la partícula
		auto itListaFuerzas = itMapParticula->second.begin();
		while (itListaFuerzas != itMapParticula->second.end()) { // coste lineal en función del número de fuerzas que afectan a la partícula
			// se modifica el map de fuerzas
			auto itMapFuerzas = fuerzas.find(*itListaFuerzas); // coste constante
			// se busca la partícula a la que afecta la fuerza
			auto itListaParticulas = itMapFuerzas->second.find(p); // coste constante
			if (itListaParticulas != itMapFuerzas->second.end())
				itMapFuerzas->second.erase(itListaParticulas);
			itListaFuerzas++;
		}

		// se elimina completamente la partícula del map de partículas
		particulas.erase(itMapParticula);

		//delete(p);
	}
}

void ParticleForceRegistry::deleteForceRegistry(ForceGenerator* f) {
	// se elimina la fuerza de todas las partículas que la tienen
	// (se elimina del map de partículas)
	auto itMapFuerzas = fuerzas.find(f); // coste constante
	// sólo se procesa la fuerza si esta existe
	if (itMapFuerzas != fuerzas.end()) {
		// se recorre la lista de partículas a las que afecta la fuerza
		auto itListaPartículas = itMapFuerzas->second.begin();
		while (itListaPartículas != itMapFuerzas->second.end()) { // coste lineal en función del número de fuerzas que afectan a la partícula
			// se modifica el map de partículas
			auto itMapParticulas = particulas.find(*itListaPartículas); // coste constante
			// se busca la fuerza a la que afecta a la partícula
			auto itListaFuerzas = itMapParticulas->second.find(f); // coste constante
			if (itListaFuerzas != itMapParticulas->second.end())
				itMapParticulas->second.erase(itListaFuerzas);
			itListaPartículas++;
		}

		// se elimina completamente la fuerza del map de fuerza
		fuerzas.erase(itMapFuerzas);

		//delete(f);
	}
}

void ParticleForceRegistry::updateForces(double t) {
	// recorre el map de particulas
	auto itMapParticulas = particulas.begin();
	while (itMapParticulas != particulas.end())
	{
		auto itFuerzaParticula = itMapParticulas->second.begin();
		while (itFuerzaParticula != itMapParticulas->second.end()) {
			// actualiza la fuerza
			(*itFuerzaParticula)->updateForce(itMapParticulas->first, t);
			++itFuerzaParticula;
		}
		++itMapParticulas;
	}
}

//void ParticleForceRegistry::updateForces() {
//	// recorre el map de fuerzas
//	auto itMapFuerzas = fuerzas.begin();
//	while (itMapFuerzas != fuerzas.end())
//	{
//		unordered_set<Particle*> newParticles = (*itMapFuerzas).first->generateParticles();
//		auto particles = newParticles.begin();
//		while (particles != newParticles.end()) {
//			(*itMapFuerzas).second.insert(*particles);
//
//			unordered_set<ForceGenerator*> lista;
//			lista.insert((*itMapFuerzas).first);
//			particulas.insert({ *particles, lista });
//
//			particles++;
//		}
//
//		itMapFuerzas++;
//	}
//}

void ParticleForceRegistry::addForce(ForceGenerator* f) {
	// sólo crea la fuerza si aún no existe
	auto itFuerza = fuerzas.find(f);
	if (itFuerza == fuerzas.end())
		fuerzas.insert({ f, {} });
}

void ParticleForceRegistry::updateParticles(double t) {
	for (auto particle : particulas) {
		particle.first->integratev3(t);
	}
}

void ParticleForceRegistry::deleteDeadParticles() {
	auto particle = particulas.begin();
	while (particle != particulas.end()) {
		if (!(*particle).first->isAlive()) {
			Particle* aux = (*particle).first;
			particle++;
			deleteParticleRegistry(aux);
			delete(aux);
		}
		else
			particle++;
	}
}

void ParticleForceRegistry::generateParticles(ForceGenerator* f) {
	// creación de una fuente como núcleo de partículas genéricas sobre las que probar las fuerzas
	for (int i = 0; i < NUM_PARTICLES; ++i) {
		// cálculo de la posición
		ParticleTypes particleType;
		Vector3 position, velocity;

		position.x = rand() % int(particleType.jetParticle.positionMin.x) + int(particleType.jetParticle.positionMin.x);
		position.y = rand() % int(particleType.jetParticle.positionMax.y) + int(particleType.jetParticle.positionMin.y);
		position.z = rand() % int(particleType.jetParticle.positionMax.z) + int(particleType.jetParticle.positionMin.z);

		// generación de la velocidad
		velocity.x = rand() % int(particleType.jetParticle.velocityMin.x) + int(particleType.jetParticle.velocityMax.x);
		velocity.y = rand() % int(particleType.jetParticle.velocityMin.y) + int(particleType.jetParticle.velocityMax.y);
		velocity.z = rand() % int(particleType.jetParticle.velocityMin.z) + int(particleType.jetParticle.velocityMax.z);

		Particle* particle = new Particle(position, velocity, particleType.jetParticle.radius, particleType.jetParticle.mass,
			&PxSphereGeometry(particleType.jetParticle.radius), particleType.jetParticle.generation, particleType.jetParticle.life);

		addRegistry(f, particle);
	}
}

void ParticleForceRegistry::generateStaticParticles(ForceGenerator* f) {
	// creación de una fuente como núcleo de partículas genéricas sobre las que probar las fuerzas
	for (int i = 0; i < NUM_PARTICLES; ++i) {
		// cálculo de la posición
		ParticleTypes particleType;
		Vector3 position, velocity;

		position.x = rand() % int(particleType.jetParticle.positionMin.x) + int(particleType.jetParticle.positionMin.x);
		position.y = rand() % int(particleType.jetParticle.positionMax.y) + int(particleType.jetParticle.positionMin.y);
		position.z = rand() % int(particleType.jetParticle.positionMax.z) + int(particleType.jetParticle.positionMin.z);

		// generación de la velocidad
		velocity = { 0, 0, 0 };

		Particle* particle = new Particle(position, velocity, particleType.jetParticle.radius, particleType.jetParticle.mass,
			&PxSphereGeometry(particleType.jetParticle.radius), particleType.jetParticle.generation, particleType.jetParticle.life);

		addRegistry(f, particle);
	}
}

void ParticleForceRegistry::generateExplosionParticles(ForceGenerator* f) {
	// creación de una fuente como núcleo de partículas genéricas sobre las que probar las fuerzas
	for (int i = 0; i < NUM_PARTICLES; ++i) {
		// cálculo de la posición
		ParticleTypes particleType;
		Vector3 position, velocity;

		position.x = rand() % int(particleType.jetParticleExplosion.positionMin.x) + int(particleType.jetParticleExplosion.positionMin.x);
		position.y = rand() % int(particleType.jetParticleExplosion.positionMax.y) + int(particleType.jetParticleExplosion.positionMin.y);
		position.z = rand() % int(particleType.jetParticleExplosion.positionMax.z) + int(particleType.jetParticleExplosion.positionMin.z);

		// generación de la velocidad
		velocity = { 0, 0, 0 };

		Particle* particle = new Particle(position, velocity, particleType.jetParticleExplosion.radius, particleType.jetParticleExplosion.mass,
			&PxSphereGeometry(particleType.jetParticleExplosion.radius), particleType.jetParticleExplosion.generation, particleType.jetParticleExplosion.life);

		addRegistry(f, particle);
	}
}

void ParticleForceRegistry::addForceToAllParticles(ForceGenerator* f) {
	auto itParticles = particulas.begin();
	while (itParticles != particulas.end()) {
		(*itParticles).second.insert(f);
		++itParticles;
	}
}