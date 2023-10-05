#pragma once
#include <vector>
#include "Particle.h"

using namespace std;

class ProjectileManager
{
public:
	ProjectileManager();
	~ProjectileManager();
	void createProjectile();
	void killProjectile();
	void integrate(double t);

private:
	std::vector<Particle*> particles;
};