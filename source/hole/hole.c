#include "hole.h"

void initHole(Hole* hole, Vector2 position) {
	hole->position = position;
	hole->radius   = 20;
	hole->color    = GREEN;
}