#include "Ground.h"

Ground::Ground(PxTransform pos, Vector4 color, PxVec3 size) : position(pos) {
	renderItem = new RenderItem(CreateShape(PxBoxGeometry(size)), &position, color);
}