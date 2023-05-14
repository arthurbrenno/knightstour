#include "k_functions.h"

int move(Knight* knight, char board[][BOARD_SIZE], int movement) {
	//remove knight old position
	board[(*knight).current_row][(*knight).current_col] = fill_character;

	//update the position
	(*knight).current_row += vertical[movement];
	(*knight).current_col += horizontal[movement];
	
	//if exceeds either row or col, then rollback. leave at the same place it was
	if (
		(*knight).current_row >= BOARD_SIZE || 
		(*knight).current_col >= BOARD_SIZE || 
		(*knight).current_row < 0 || 
		(*knight).current_col < 0) {

		//discard movement
		(*knight).current_row -= vertical[movement];
		(*knight).current_col -= horizontal[movement];
		//replace knight old position
		board[(*knight).current_row][(*knight).current_col] = (*knight).character;
		return 0;
	}
	//place to new position
	board[(*knight).current_row][(*knight).current_col] = (*knight).character;
	return 1;
}