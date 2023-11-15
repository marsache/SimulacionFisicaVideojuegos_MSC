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
	}
}

void ParticleForceRegistry::updateForces() {
	// recorre el map de particulas
	auto itMapParticulas = particulas.begin();
	while (itMapParticulas != particulas.end())
	{
		auto itFuerzaParticula = itMapParticulas->second.begin();
		while (itFuerzaParticula != itMapParticulas->second.end()) {
			// actualiza la fuerza
			(*itFuerzaParticula)->updateForce(itMapParticulas->first);
		}
	}
}