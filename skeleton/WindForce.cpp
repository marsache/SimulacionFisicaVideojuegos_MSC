#include "WindForce.h"

void WindForce::updateForce(Particle* p, double t) {
	// la fuerza sólo se aplica si la partícula se encuentra en el área de influencia
	Vector3 posIArea;
	posIArea.x = influencedArea.p.x;
	posIArea.y = influencedArea.p.y;
	posIArea.z = influencedArea.p.z;
	if ((p->getPosition() - posIArea).magnitude() <= RADIUS_INFLUENCED_AREA) {
		// cálculo de la fuerza del viento
		// F = k1 (vv - v)
		p->addForce(0.5 * (acceleration - p->getVel()));
		/*Vector3 v = acceleration - p->getVel();
		p->addForce(0.5 * v + v.magnitude() * v);*/

		// opcional
		/*float A = M_PI * (2 * p->getRadius()) * (2 * p->getRadius()) / 4;
		p->addForce(0.5 * (acceleration - p->getVel()) + 
			(A * 0.5 * AIR_DENSITY) * (acceleration - p->getVel()).magnitude() * (acceleration - p->getVel()));
		p->addForce(0.5 * (acceleration - p->getVel()) + 0.5 * (acceleration - p->getVel()).magnitude() * (acceleration - p->getVel()));*/
	}
	else
		p->clearAcum();
}