#include "lib/knight/k_functions.h"
#include "lib/board/b_aspects.h"
#include <stdio.h>
#include <ctype.h>

#define BUFFER_SIZE 5

void PrintBoard(char const board[][BOARD_SIZE]);
void FillBoard(char fill_character, char board[][BOARD_SIZE]);

int main() {
	char board[BOARD_SIZE][BOARD_SIZE];

	Knight my_knight = {
		.character = 'k', 
		.xpos = 0, 
		.ypos = 0
	};

	FillBoard(fill_character, board);
	board[my_knight.xpos][my_knight.ypos] = my_knight.character;
	int movement = 0;
	while (movement != -9) {
		system("cls");
		PrintBoard(board);
		printf("  %s     %s  \n", (ckmov(&my_knight, board, 2)) ? "2" : " ", (ckmov(&my_knight, board, 1)) ? "1" : " ");
		printf("%s         %s\n", (ckmov(&my_knight, board, 3)) ? "3" : " ", (ckmov(&my_knight, board, 0)) ? "0" : " ");
		printf("     K     \n");
		printf("%s         %s\n", (ckmov(&my_knight, board, 4)) ? "4" : " ", (ckmov(&my_knight, board, 7)) ? "7" : " ");
		printf("  %s     %s  \n", (ckmov(&my_knight, board, 5)) ? "5" : " ", (ckmov(&my_knight, board, 6)) ? "6" : " ");
		printf("Movement: ");
		
		char buffer[BUFFER_SIZE];
		fgets(buffer, BUFFER_SIZE - 1, stdin);
		if (isdigit(buffer[0])) {
			movement = atoi(buffer);
			move(&my_knight, board, atoi(buffer));
		}
	}
	
	return 0;
}

void PrintBoard(char const board[][BOARD_SIZE]) {
	for (int i = 0; i < BOARD_SIZE; ++i) {
		for (int j = 0; j < BOARD_SIZE; ++j) {
			printf("%c ", board[i][j]);
		}
		printf("\n");
	}
}

void FillBoard(char fill_character, char board[][BOARD_SIZE]) {
	for (int i = 0; i < BOARD_SIZE; ++i) {
		for (int j = 0; j < BOARD_SIZE; ++j) {
			board[i][j] = fill_character;
		}
	}
}



