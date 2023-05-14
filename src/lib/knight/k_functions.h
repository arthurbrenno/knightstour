#ifndef K_MOVER_H
#define K_MOVER_H

#include "k_movements.h"
#include "../board/b_aspects.h"

//piece structure
typedef struct {
	unsigned int xpos;
	unsigned int ypos;
	char character;
} Knight;

/**
 * Move a knight piece.
 *
 * This will take a knight and move
 * it based on the movement type.
 *
 * @param Knight struct, a chess board and a movement type
 * @return 1 if suceeds, 0 if movement is not possible.
 */
int move(Knight* knight, char board[][BOARD_SIZE], int movement);

/**
 * Check if the movement is possible.
 *
 * This will take a movement and check if
 * it exceeds the board.
 *
 * @param Knight struct, a chess board and a movement type
 * @return 1 if possible, 0 if movement is not possible.
 */
int ckmov(Knight* knight, char board[][BOARD_SIZE], int movement);

#endif
