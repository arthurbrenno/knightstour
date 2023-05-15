#ifndef B_FUNCTIONS_H
#define B_FUNCTIONS_H

#define BOARD_SIZE 8
#include "../knight/k_piece.h"

//b_functions.h fill_character
static const char fill_character = '.';

int wasvisited(char board[][8], int x, int y);

#endif
