#include "raylib.h"

#define MAX_LENGTH 100

typedef struct LineStruct {
	Vector2 startPosition;
	Vector2 finalPosition;
	Color color;
} Line;

void initLine(Line* line, Vector2 ballPosition);
void updateLine(Line* line);