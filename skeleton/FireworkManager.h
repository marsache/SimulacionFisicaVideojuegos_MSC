#pragma once
#include "FireworkParticleGenerator.h"
#include "Firework.h"

class FireworkManager
{
private:
	FireworkParticleGenerator* fireworkPG;
	list<Firework*> fireworks;
	void explode();

public:
	FireworkManager();
	void update(double t);
	void startFireworks();
};