#include "k_functions.h"

int move(Knight* knight, char board[][8], int movement) {
	//remove knight old position
	board[(*knight).xpos][(*knight).ypos] = '#';

	//update the position
	(*knight).xpos += vertical[movement];
	(*knight).ypos += horizontal[movement];
	
	//if exceeds either row or col, then rollback. leave at the same place it was
	if ((*knight).xpos >= BOARD_SIZE ||
		(*knight).ypos >= BOARD_SIZE ||
		(*knight).xpos < 0 ||
		(*knight).ypos < 0) {

		//discard movement
		(*knight).xpos -= vertical[movement];
		(*knight).ypos -= horizontal[movement];
		//replace knight old position
		board[(*knight).xpos][(*knight).ypos] = (*knight).character;
		return 0;
	}
	//place to new position
	board[(*knight).xpos][(*knight).ypos] = (*knight).character;
	return 1;
}

int ckmov(Knight* knight, char board[][BOARD_SIZE], int movement) {
	//if exceeds or is less than 0, fail.
	if ((*knight).xpos + vertical[movement] < 0 ||
		(*knight).ypos + horizontal[movement] < 0 ||
		(*knight).xpos + vertical[movement] >= BOARD_SIZE ||
		(*knight).ypos + horizontal[movement] >= BOARD_SIZE) {
		return 0;
	}
	//otherwise, return true.
	return 1;
}

