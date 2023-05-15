#include "b_functions.h"

int wasvisited(char board[][8], int x, int y) {
    return board[x][y] == '#';
}
