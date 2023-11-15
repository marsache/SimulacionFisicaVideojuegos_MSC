#include "ParticleForceRegistry.h"

void ParticleForceRegistry::addRegistry(ForceGenerator* f, Particle* p) {
	// se actualiza el map de fuerzas
	auto itMapFuerzas = fuerzas.find(f);
	// si no se ha registrado ya la fuerza, se crea
	if (itMapFuerzas == fuerzas.end()) {
		ListaParticulasPorFuerza lista;
		lista.insert(p);
		fuerzas.insert({ f, lista }); // se inserta la fuerza y la part�cula
	}
	// si ya existe la fuerza, se a�ade la part�cula
	else 
		itMapFuerzas->second.insert(p); // se inserta la part�cula

	// se actualiza el map de part�culas
	auto itMapParticulas = particulas.find(p);
	// si no se ha registrado ya la fuerza, se crea
	if (itMapParticulas == particulas.end()) {
		ListaFuerzasPorParticula lista;
		lista.insert(f);
		particulas.insert({ p, lista }); // se inserta la part�cula y la fuerza
	}
	// si ya existe la part�cula, se a�ade la fuerza
	else
		itMapParticulas->second.insert(f);
}

void ParticleForceRegistry::deleteParticleRegistry(Particle* p) {
	// se elimina la part�cula de todas las fuerzas que tiene
	// (se elimina del map de fuerzas)
	auto itMapParticula = particulas.find(p); // coste constante
	// s�lo se procesa la part�cula si esta existe
	if (itMapParticula != particulas.end()) {
		// se recorre la lista de fuerzas que afectan a la part�cula
		auto itListaFuerzas = itMapParticula->second.begin();
		while (itListaFuerzas != itMapParticula->second.end()) { // coste lineal en funci�n del n�mero de fuerzas que afectan a la part�cula
			// se modifica el map de fuerzas
			auto itMapFuerzas = fuerzas.find(*itListaFuerzas); // coste constante
			// se busca la part�cula a la que afecta la fuerza
			auto itListaParticulas = itMapFuerzas->second.find(p); // coste constante
			if (itListaParticulas != itMapFuerzas->second.end())
				itMapFuerzas->second.erase(itListaParticulas);
			itListaFuerzas++;
		}

		// se elimina completamente la part�cula del map de part�culas
		particulas.erase(itMapParticula);
	}
}

void ParticleForceRegistry::deleteForceRegistry(ForceGenerator* f) {
	// se elimina la fuerza de todas las part�culas que la tienen
	// (se elimina del map de part�culas)
	auto itMapFuerzas = fuerzas.find(f); // coste constante
	// s�lo se procesa la fuerza si esta existe
	if (itMapFuerzas != fuerzas.end()) {
		// se recorre la lista de part�culas a las que afecta la fuerza
		auto itListaPart�culas = itMapFuerzas->second.begin();
		while (itListaPart�culas != itMapFuerzas->second.end()) { // coste lineal en funci�n del n�mero de fuerzas que afectan a la part�cula
			// se modifica el map de part�culas
			auto itMapParticulas = particulas.find(*itListaPart�culas); // coste constante
			// se busca la fuerza a la que afecta a la part�cula
			auto itListaFuerzas = itMapParticulas->second.find(f); // coste constante
			if (itListaFuerzas != itMapParticulas->second.end())
				itMapParticulas->second.erase(itListaFuerzas);
			itListaPart�culas++;
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