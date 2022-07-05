#include "raylib.h"
#include "source/ball/ball.h"
#include "source/line/line.h"
#include "source/hole/hole.h"
#include "source/block/block.h"
#include "stdio.h"


int main(void) {
	
	// Declare stuff
	Ball ball;
	Line line;
	Hole hole;
	Block block1;
	Vector2 blockPos;
	Vector2 holePos;
	bool ballMoving;     // If the ball is moving or not
	int currentGesture;  // This is the action currently being made with the mouse
	int previousGesture; // This is the action previously made with the mouse 
	int KeyPressed;
	int win;

	// Initialize stuff
	blockPos = (Vector2) {350, 250};
	holePos = (Vector2) {400, 100};

	initBall(&ball, (Vector2){400, 500});
	initLine(&line, ball.position);

	initHole(&hole, holePos);
	initBlock(&block1, blockPos, (Vector2){100, 100});

	previousGesture = GESTURE_NONE;
	currentGesture = GESTURE_NONE;
	KeyPressed = -1;
	ballMoving = false;
	win = 0;


	InitWindow(800, 600, "Golfie");

	while (!WindowShouldClose()) {
		KeyPressed = GetKeyPressed();
		if (KeyPressed == KEY_S) {
			Vector2 mouse = GetMousePosition();
			blockPos = (Vector2) {mouse.x - 50, mouse.y - 50};
			block1.position = blockPos;
		} 
		else if (KeyPressed == KEY_A) {
			win = 0;
			// Initialize stuff
			initBall(&ball, (Vector2){400, 500});
			initLine(&line, ball.position);

			initHole(&hole, holePos);
			initBlock(&block1, blockPos, (Vector2){100, 100});
		} 

		if (!ballMoving) {
			// We update the line
			previousGesture = currentGesture;
			currentGesture = GetGestureDetected();
			if (currentGesture == GESTURE_TAP || currentGesture == GESTURE_HOLD || currentGesture == GESTURE_DRAG) {
				// We enter here while holding and draging the mouse button
				updateLine(&line);
			}
			else if (previousGesture != GESTURE_NONE) {
				// We enter here when we realease the mouse
				setVelocity(&ball, line.finalPosition.x - line.startPosition.x, line.finalPosition.y - line.startPosition.y);
				initLine(&line, ball.position);
				ballMoving = true;
			}
		}
		else {
			// We update the ball
			if (ball.velocity.x == 0 && ball.velocity.y == 0) {
				initLine(&line, ball.position); // Reset line to the ball's position
				ballMoving = false;
			}
			else {
				updateBall(&ball);
				collisionsBallWorld(&ball);
				collisionsBallBlock(&ball, block1.position, block1.size);
				win = collisionsBallHole(&ball, hole.position, hole.radius);
			}
		}
		
		BeginDrawing();
		ClearBackground(RAYWHITE);
		if (win == 0) {
			// Player
			DrawCircleV(hole.position, hole.radius, hole.color); 
			DrawLineV(line.startPosition, line.finalPosition, line.color);
			
			// Blocks
			DrawRectangleV(block1.position, block1.size, block1.color);
			DrawCircleV(ball.position, ball.radius, ball.color);
		}
		else {
			DrawText("YOU WON", 350, 200, 30, BLACK);
		}
		
		EndDrawing();
	}
	CloseWindow();
	return 0;
}