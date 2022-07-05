#include "raylib.h"

typedef struct HoleStruct {
	Vector2 position;
	Color color;
	int radius;
} Hole;

void initHole(Hole* hole, Vector2 position);