/*************************************************************
	Knight's tour playground v1.0
	Author: Arthur Brenno, 2023
	github: arthurbrenno
	public release date: 15-05-2023

	Changes:
	15-05-2023: finished basic logic
 *************************************************************/

#include "lib/knight/k_functions.h"
#include "lib/board/b_functions.h"
#include "lib/knight/k_piece.h"
#include <stdio.h>
#include <ctype.h>
#include <windows.h>
#include <time.h>

#define BUFFER_SIZE 5

void PrintBoard(char const board[][BOARD_SIZE]);
void FillBoard(char fill_character, char board[][BOARD_SIZE]);

int main() {
	char board[BOARD_SIZE][BOARD_SIZE];
	unsigned int tour = 0;
	unsigned int max = 0;
	unsigned int house_count = 0;
	Knight my_knight = {
		.character = 'K', 
		.xpos = 0, 
		.ypos = 0
	};
	memset(&board, ' ', sizeof board);
	board[my_knight.xpos][my_knight.ypos] = my_knight.character;
	unsigned int movement = 0;

	while (movement != 999) {
		system("cls");
		if (ckmov(&my_knight, board, 0) && !wasvisited(board, my_knight.xpos + vertical[0], my_knight.ypos + horizontal[0])) {
			board[my_knight.xpos + vertical[0]][my_knight.ypos + horizontal[0]] = '0';
		}
		if (ckmov(&my_knight, board, 1) && !wasvisited(board, my_knight.xpos + vertical[1], my_knight.ypos + horizontal[1])) {
			board[my_knight.xpos + vertical[1]][my_knight.ypos + horizontal[1]] = '1';
		}
		if (ckmov(&my_knight, board, 2) && !wasvisited(board, my_knight.xpos + vertical[2], my_knight.ypos + horizontal[2])) {
			board[my_knight.xpos + vertical[2]][my_knight.ypos + horizontal[2]] = '2';
		}
		if (ckmov(&my_knight, board, 3) && !wasvisited(board, my_knight.xpos + vertical[3], my_knight.ypos + horizontal[3])) {
			board[my_knight.xpos + vertical[3]][my_knight.ypos + horizontal[3]] = '3';
		}
		if (ckmov(&my_knight, board, 4) && !wasvisited(board, my_knight.xpos + vertical[4], my_knight.ypos + horizontal[4])) {
			board[my_knight.xpos + vertical[4]][my_knight.ypos + horizontal[4]] = '4';
		}
		if (ckmov(&my_knight, board, 5) && !wasvisited(board, my_knight.xpos + vertical[5], my_knight.ypos + horizontal[5])) {
			board[my_knight.xpos + vertical[5]][my_knight.ypos + horizontal[5]] = '5';
		}
		if (ckmov(&my_knight, board, 6) && !wasvisited(board, my_knight.xpos + vertical[6], my_knight.ypos + horizontal[6])) {
			board[my_knight.xpos + vertical[6]][my_knight.ypos + horizontal[6]] = '6';
		}
		if (ckmov(&my_knight, board, 7) && !wasvisited(board, my_knight.xpos + vertical[7], my_knight.ypos + horizontal[7])) {
			board[my_knight.xpos + vertical[7]][my_knight.ypos + horizontal[7]] = '7';
		}
		PrintBoard(board);
		printf("  %s     %s  \n", (ckmov(&my_knight, board, 2) && !wasvisited(board, my_knight.xpos + vertical[2], my_knight.ypos + horizontal[2])) ? "2" : " ", (ckmov(&my_knight, board, 1) && !wasvisited(board, my_knight.xpos + vertical[1], my_knight.ypos + horizontal[1])) ? "1" : " ");
		printf("%s         %s\n", (ckmov(&my_knight, board, 3) && !wasvisited(board, my_knight.xpos + vertical[3], my_knight.ypos + horizontal[3])) ? "3" : " ", (ckmov(&my_knight, board, 0) && !wasvisited(board, my_knight.xpos + vertical[0], my_knight.ypos + horizontal[0])) ? "0" : " ");
		printf("     K     \n");
		printf("%s         %s\n", (ckmov(&my_knight, board, 4) && !wasvisited(board, my_knight.xpos + vertical[4], my_knight.ypos + horizontal[4])) ? "4" : " ", (ckmov(&my_knight, board, 7) && !wasvisited(board, my_knight.xpos + vertical[7], my_knight.ypos + horizontal[7])) ? "7" : " ");
		printf("  %s     %s  \n", (ckmov(&my_knight, board, 5) && !wasvisited(board, my_knight.xpos + vertical[5], my_knight.ypos + horizontal[5])) ? "5" : " ", (ckmov(&my_knight, board, 6) && !wasvisited(board, my_knight.xpos + vertical[6], my_knight.ypos + horizontal[6])) ? "6" : " ");
		


		/*User input version */
		printf("Movement: ");
		char buffer[BUFFER_SIZE];
		fgets(buffer, BUFFER_SIZE - 1, stdin);
		if (isdigit(buffer[0])) {
			movement = atoi(buffer);
			if (wasvisited(board, my_knight.xpos + vertical[movement], my_knight.ypos + horizontal[movement])) {
				break;
			}
			move(&my_knight, board, atoi(buffer));
		}
		FillBoard(fill_character, board);
		//memset(&board, ' ', sizeof board);
		board[my_knight.xpos - vertical[movement]][my_knight.ypos - horizontal[movement]] = '#';
		board[my_knight.xpos][my_knight.ypos] = my_knight.character;
	}
	printf("Max distance: %d\n", max);
	system("pause");
	return 0;
}
void PrintBoard(char const board[][BOARD_SIZE]) {
	for (int i = 0; i < BOARD_SIZE; ++i) {
		printf("    ");
		for (int j = 0; j < BOARD_SIZE; ++j) {
			printf("%c |    ", board[i][j]);
		}
		printf("\n"); printf("\n");
	}
}

void FillBoard(char fill_character, char board[][BOARD_SIZE]) {
	for (int i = 0; i < BOARD_SIZE; ++i) {
		for (int j = 0; j < BOARD_SIZE; ++j) {
			if (board[i][j] != '#') {
				board[i][j] = fill_character;
			}
		}
	}
}

/* OLD FUNCTION, too much confusing, was giving me visual pain
void PrintBoard(char const board[][BOARD_SIZE]) {
	printf("-----------------------------------------\n");
	for (int i = 0; i < BOARD_SIZE; ++i) {
		printf("|");
		for (int j = 0; j < BOARD_SIZE; ++j) {
			printf("%c   |", board[i][j]);
		}
		printf("\n-----------------------------------------\n");
	}
}
*/