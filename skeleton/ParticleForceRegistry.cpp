#include "ParticleForceRegistry.h"

void ParticleForceRegistry::addRegistry(ForceGenerator* f, Particle* p) {

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

}

void ParticleForceRegistry::updateForces() {

}