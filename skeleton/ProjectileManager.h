#pragma once
#include <vector>
#include "Particle.h"

using namespace std;

const int PROJECTILE_RADIUS = 2;
const float PROJECTILE_LIFE = 100;

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