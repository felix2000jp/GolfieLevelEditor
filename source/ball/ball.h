#include "raylib.h"

#define VECLOCITY_RATIO    0.0100
#define RESISTANCE_RATIO   0.9995
#define MOVEMENT_THRESHOLD 0.0050

typedef struct BallStruct {
	Vector2 position;
	Vector2 velocity;
	Color color;
	int radius;
} Ball;

void initBall(Ball* ball, Vector2 position);
void setVelocity(Ball* ball, float lengthX, float lengthY);
void updateBall(Ball* ball);
void collisionsBallWorld(Ball* ball);
int collisionsBallHole(Ball* ball, Vector2 position, int radius);
void collisionsBallBlock(Ball* ball, Vector2 position, Vector2 size);