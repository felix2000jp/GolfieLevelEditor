#include "block.h"

void initBlock(Block* block, Vector2 position, Vector2 size) {
	block->position = position;
	block->size  = size;
	block->color = RED;
} 