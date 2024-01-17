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
	~FireworkManager() { delete(this); }
	void update(double t);
	void startFireworks();
};