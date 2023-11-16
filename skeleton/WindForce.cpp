#include "WindForce.h"

void WindForce::updateForce(Particle* p) {
	// la fuerza sólo se aplica si la partícula se encuentra en el área de influencia
	Vector3 posIArea;
	posIArea.x = influencedArea.p.x;
	posIArea.y = influencedArea.p.y;
	posIArea.z = influencedArea.p.z;
	if ((p->getPosition() - posIArea).magnitude() <= RADIUS_INFLUENCED_AREA) {
		// cálculo de la fuerza del viento
		// F = k1 (vv - v)
		p->addForce(0.5 * (acceleration - p->getVel()));
	}
	else
		p->clearAcum();
}