#include "ball.h"
#include "math.h"
#include "stdio.h"

void initBall(Ball* ball, Vector2 position) {
	ball->position = position;
	ball->velocity = (Vector2){ 0, 0 };
	ball->color    = BLACK;
	ball->radius   = 15;
}

void setVelocity(Ball* ball, float lengthX, float lengthY) {
	ball->velocity = (Vector2){ lengthX * VECLOCITY_RATIO, lengthY * VECLOCITY_RATIO};
}

void updateBall(Ball* ball) {
	// We update the balls position
	ball->position.x += ball->velocity.x; 
	ball->position.y += ball->velocity.y; 

	// We declare that for velocities between -MOVEMENT_THRESHOLD and MOVEMENT_THRESHOLD the value becomes 0
	// I do this because if we waited for it to become 0 naturally it would 
	// enter an infinite loop.
	ball->velocity.x = ball->velocity.x * RESISTANCE_RATIO;
	ball->velocity.y = ball->velocity.y * RESISTANCE_RATIO;
	

	// We dont want the ball to stop until both the axis
	// are in between -MOVEMENT_THRESHOLD and MOVEMENT_THRESHOLD because it would make 
	// the ball movement weird at the end. 
	if ((ball->velocity.x <= MOVEMENT_THRESHOLD && ball->velocity.x >= -MOVEMENT_THRESHOLD) && 
		(ball->velocity.y <= MOVEMENT_THRESHOLD && ball->velocity.y >= -MOVEMENT_THRESHOLD)) {
		ball->velocity.y = 0;
		ball->velocity.x = 0;
	}
}

void collisionsBallWorld(Ball* ball) {
	if (ball->position.y < 15 || ball->position.y > 585) {
		ball->velocity.y *= -1;
	}
	if (ball->position.x < 15 || ball->position.x > 785) {
		ball->velocity.x *= -1;
	}
}

int collisionsBallHole(Ball* ball, Vector2 position, int radius) {
	int win = 0;
	if (CheckCollisionCircles(ball->position, ball->radius, position, radius)) {
		ball->position = (Vector2) {0 , 0};
		ball->velocity = (Vector2) {0 , 0};
		ball->radius = 0;
		win = 1;
	}
	return win;
}

void collisionsBallBlock(Ball* ball, Vector2 position, Vector2 size) {
	Rectangle rec = (Rectangle){position.x, position.y, size.x, size.y};

	if (CheckCollisionCircleRec(ball->position, ball->radius, rec)) {
		if (ball->position.x < rec.x || ball->position.x > rec.x + rec.width){
			ball->velocity.x *= -1;
		}
		if (ball->position.y < rec.y || ball->position.y > rec.y + rec.height){
			ball->velocity.y *= -1;
		}
	}
}