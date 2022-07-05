#include "line.h"
#include "math.h" 
#include "stdio.h"

void initLine(Line* line, Vector2 ballPosition) {
	line->startPosition = ballPosition;
	line->finalPosition = ballPosition;
	line->color         = BLACK;
}

void updateLine(Line* line) {
	// We get the mouse position
	Vector2 mouse = GetMousePosition();
	
	// We calculate the line final point
	float finalX = line->startPosition.x - mouse.x;
	float finalY = line->startPosition.y - mouse.y;
	
	// We calculate the vector of the line
	// We also calculate the distance to see if we should scale the line
	Vector2 vectorLine = (Vector2){ finalX, finalY };
	float vectorDistance = sqrt(pow(vectorLine.x, 2) + pow(vectorLine.y, 2));
	
	// We verify that the distance of the line is not bigger than the MAX_LENGTH allowed
	if (vectorDistance > MAX_LENGTH) {
		// We calculate the magnitude
		float magnitude = sqrt(pow(vectorLine.x, 2) + pow(vectorLine.y, 2));
		// We divide each for the magnitude so we get something of length 1
		// And multiply it by the MAX_LENGTH to get the max length
		finalX = (vectorLine.x / magnitude) * MAX_LENGTH;
		finalY = (vectorLine.y / magnitude) * MAX_LENGTH;
		vectorDistance = MAX_LENGTH;
	}
	
	// We apply the transformation
	line->finalPosition.x = line->startPosition.x + finalX;
	line->finalPosition.y = line->startPosition.y + finalY;
}