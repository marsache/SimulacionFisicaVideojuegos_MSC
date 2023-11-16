#include "WindForce.h"

void WindForce::updateForce(Particle* p) {
	// la fuerza s�lo se aplica si la part�cula se encuentra en el �rea de influencia
	Vector3 posIArea;
	posIArea.x = influencedArea.p.x;
	posIArea.y = influencedArea.p.y;
	posIArea.z = influencedArea.p.z;
	if ((p->getPosition() - posIArea).magnitude() <= RADIUS_INFLUENCED_AREA) {
		// c�lculo de la fuerza del viento
		// F = k1 (vv - v)
		p->addForce(0.5 * (acceleration - p->getVel()));
	}
	else
		p->clearAcum();
}