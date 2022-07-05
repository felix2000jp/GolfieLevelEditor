#include "raylib.h"

typedef struct BlockStruct {
	Vector2 position;
	Vector2 size;
	Color color;
} Block;

void initBlock(Block* block, Vector2 position, Vector2 size);