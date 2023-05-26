/*************************************************************
	Knight's tour playground v1.0
	Author: Arthur Brenno, 2023
	github: arthurbrenno
	public release date: 15-05-2023

	3rd semester I.S project
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
#include <stdint.h>

#define BUFFER_SIZE 5

void PrintBoard(char const board[][BOARD_SIZE]);
void FillBoard(char fill_character, char board[][BOARD_SIZE]);
void SetBoardMoves(Knight knight, char board[][BOARD_SIZE]);

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

	while (1) {
		system("cls");
		printf("[GOAl: Visit all places only once.]\n");
		SetBoardMoves(my_knight, board);
		PrintBoard(board);

		//check moves
		int_fast8_t ck_mov_zero = ckmov(&my_knight, board, 0);
		int_fast8_t ck_mov_one = ckmov(&my_knight, board, 1);
		int_fast8_t ck_mov_two = ckmov(&my_knight, board, 2);
		int_fast8_t ck_mov_three = ckmov(&my_knight, board, 3);
		int_fast8_t ck_mov_four = ckmov(&my_knight, board, 4);
		int_fast8_t ck_mov_five = ckmov(&my_knight, board, 5);
		int_fast8_t ck_mov_six = ckmov(&my_knight, board, 6);
		int_fast8_t ck_mov_sev = ckmov(&my_knight, board, 7);

		printf("%s-------------", " ");
		printf("\n%s|  %s     %s  |\n", " ", (ck_mov_two && !wasvisited(board, my_knight.xpos + vertical[2], my_knight.ypos + horizontal[2])) ? "2" : " ", ck_mov_one && !wasvisited(board, my_knight.xpos + vertical[1], my_knight.ypos + horizontal[1]) ? "1" : " ");
		printf("%s|%s         %s|\n", " ", (ck_mov_three && !wasvisited(board, my_knight.xpos + vertical[3], my_knight.ypos + horizontal[3])) ? "3" : " ", ck_mov_zero && !wasvisited(board, my_knight.xpos + vertical[0], my_knight.ypos + horizontal[0]) ? "0" : " ");
		printf("%s|     K     |            <-- zoom\n", " ");
		printf("%s|%s         %s|\n", " ", (ck_mov_four && !wasvisited(board, my_knight.xpos + vertical[4], my_knight.ypos + horizontal[4])) ? "4" : " ", ck_mov_sev && !wasvisited(board, my_knight.xpos + vertical[7], my_knight.ypos + horizontal[7]) ? "7" : " ");
		printf("%s|  %s     %s  |\n", " ", (ck_mov_five && !wasvisited(board, my_knight.xpos + vertical[5], my_knight.ypos + horizontal[5])) ? "5" : " ", ck_mov_six && !wasvisited(board, my_knight.xpos + vertical[6], my_knight.ypos + horizontal[6]) ? "6" : " ");
		printf("%s-------------\n\n", " ");
		
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
		board[my_knight.xpos - vertical[movement]][my_knight.ypos - horizontal[movement]] = '#';
		board[my_knight.xpos][my_knight.ypos] = my_knight.character;
	}
	printf("Max distance: %d\n", max);
	system("pause");
	return 0;
}
void PrintBoard(char const board[][BOARD_SIZE]) {
	printf("\n");
	for (int i = 0; i < BOARD_SIZE; ++i) {
		printf("   +");
		for (int j = 0; j < BOARD_SIZE; ++j) {
			printf("-------+");
		}
		printf("\n");
		printf(" %d |", 8 - i);
		for (int j = 0; j < BOARD_SIZE; ++j) {
			printf("   %c   |", board[i][j]);
		}
		printf("\n");
	}
	printf("   +");
	for (int j = 0; j < BOARD_SIZE; ++j) {
		printf("-------+");
	}
	printf("\n    ");
	for (int j = 0; j < BOARD_SIZE; ++j) {
		printf("   %c    ", 'A' + j);
	}
	printf("\n");
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

//set the possible moves into the board
void SetBoardMoves(Knight knight, char board[][BOARD_SIZE]) {
	if (ckmov(&knight, board, 0) && !wasvisited(board, knight.xpos + vertical[0], knight.ypos + horizontal[0])) {
		board[knight.xpos + vertical[0]][knight.ypos + horizontal[0]] = '0';
	}
	if (ckmov(&knight, board, 1) && !wasvisited(board, knight.xpos + vertical[1], knight.ypos + horizontal[1])) {
		board[knight.xpos + vertical[1]][knight.ypos + horizontal[1]] = '1';
	}
	if (ckmov(&knight, board, 2) && !wasvisited(board, knight.xpos + vertical[2], knight.ypos + horizontal[2])) {
		board[knight.xpos + vertical[2]][knight.ypos + horizontal[2]] = '2';
	}
	if (ckmov(&knight, board, 3) && !wasvisited(board, knight.xpos + vertical[3], knight.ypos + horizontal[3])) {
		board[knight.xpos + vertical[3]][knight.ypos + horizontal[3]] = '3';
	}
	if (ckmov(&knight, board, 4) && !wasvisited(board, knight.xpos + vertical[4], knight.ypos + horizontal[4])) {
		board[knight.xpos + vertical[4]][knight.ypos + horizontal[4]] = '4';
	}
	if (ckmov(&knight, board, 5) && !wasvisited(board, knight.xpos + vertical[5], knight.ypos + horizontal[5])) {
		board[knight.xpos + vertical[5]][knight.ypos + horizontal[5]] = '5';
	}
	if (ckmov(&knight, board, 6) && !wasvisited(board, knight.xpos + vertical[6], knight.ypos + horizontal[6])) {
		board[knight.xpos + vertical[6]][knight.ypos + horizontal[6]] = '6';
	}
	if (ckmov(&knight, board, 7) && !wasvisited(board, knight.xpos + vertical[7], knight.ypos + horizontal[7])) {
		board[knight.xpos + vertical[7]][knight.ypos + horizontal[7]] = '7';
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