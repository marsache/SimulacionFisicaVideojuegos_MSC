#pragma once
#include <unordered_map>
#include <unordered_set>
#include "ForceGenerator.h"
#include "Particle.h"
#include "ParticleInfo.h"

using namespace std;
using namespace ParticleInfo;

const int NUM_PARTICLES = 3;

using ListaParticulasPorFuerza = unordered_set<Particle*>;
using ListaFuerzasPorParticula = unordered_set<ForceGenerator*>;

class ParticleForceRegistry
{
protected:
	unordered_map<ForceGenerator*, ListaParticulasPorFuerza> fuerzas;
	unordered_map<Particle*, ListaFuerzasPorParticula> particulas;

public:
	ParticleForceRegistry() {}

	void addRegistry(ForceGenerator* f, Particle* p);
	void deleteParticleRegistry(Particle* p);
	void deleteForceRegistry(ForceGenerator* f);
	void updateForces(double t);
	void addForce(ForceGenerator* f);
	void updateParticles(double t);
	void deleteDeadParticles();
	void generateParticles(ForceGenerator* f);
	void generateStaticParticles(ForceGenerator* f);
	void generateExplosionParticles(ForceGenerator* f);
};