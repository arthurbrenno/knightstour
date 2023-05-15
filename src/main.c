#include "lib/knight/k_functions.h"
#include "lib/board/b_aspects.h"
#include <stdio.h>
#include <ctype.h>
#include <windows.h>
#include <time.h>

#define BUFFER_SIZE 5
#define NUM_TOURS 1000

void PrintBoard(char const board[][BOARD_SIZE]);
void FillBoard(char fill_character, char board[][BOARD_SIZE]);

int main() {
	char board[BOARD_SIZE][BOARD_SIZE];
	unsigned int tour = 0;
	unsigned int max = 0;
	unsigned int num_tours = 0;
	printf("(!BRUTE FORCE!) How many tours? >> ");
	scanf_s("%10d", &num_tours);					//yes, scanf.
	srand(time((void*)0));

	while (tour++ < num_tours) {
		Knight my_knight = {
			.character = 'k', 
			.xpos = 0, 
			.ypos = 0
		};
		FillBoard(fill_character, board);
		board[my_knight.xpos][my_knight.ypos] = my_knight.character;
		unsigned int movement = 0;
		unsigned int house_count = 0;
		while (1) {
			system("cls");
			PrintBoard(board);
			printf("  %s     %s  \n", (ckmov(&my_knight, board, 2)) ? "2" : " ", (ckmov(&my_knight, board, 1)) ? "1" : " ");
			printf("%s         %s\n", (ckmov(&my_knight, board, 3)) ? "3" : " ", (ckmov(&my_knight, board, 0)) ? "0" : " ");
			printf("     K     \n");
			printf("%s         %s\n", (ckmov(&my_knight, board, 4)) ? "4" : " ", (ckmov(&my_knight, board, 7)) ? "7" : " ");
			printf("  %s     %s  \n", (ckmov(&my_knight, board, 5)) ? "5" : " ", (ckmov(&my_knight, board, 6)) ? "6" : " ");
			//printf("Movement: ");
		
			// User input version - Uncomment if you want to try yourself
			// if uncommented, comment the "move" function next to this block
			//char buffer[BUFFER_SIZE];
			//fgets(buffer, BUFFER_SIZE - 1, stdin);
			//if (isdigit(buffer[0])) {
				//movement = atoi(buffer);
				//move(&my_knight, board, atoi(buffer), &house_count);
			//}
			movement = rand() % 8;
			if (ckmov(&my_knight, board, movement)) {
				move(&my_knight, board, movement, &house_count);
				Sleep(50);
				continue;
			}
			break;
		}
		printf("Last tour visited: %d\n", ++house_count);
		if (house_count > max) {
			max = house_count;
		}
	}
	printf("Max distance: %d\n", max);
	system("pause");
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
