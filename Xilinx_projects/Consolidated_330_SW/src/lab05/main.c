/* 
 * File:   main.c
 * Author: Taylor Cowley
 *
 * Created on May 28, 2015, 12:39 PM
 */

#include "minimax.h"
#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>

int main() {
    printf("This is me testing my code. Love, Taylor\n\r");

    minimax_board_t board1; // Board 1 is the main example in the web-tutorial that I use on the web-site.
    board1.squares[0][0] = MINIMAX_OPPONENT_SQUARE;
    board1.squares[0][1] = MINIMAX_EMPTY_SQUARE;
    board1.squares[0][2] = MINIMAX_PLAYER_SQUARE;
    board1.squares[1][0] = MINIMAX_PLAYER_SQUARE;
    board1.squares[1][1] = MINIMAX_EMPTY_SQUARE;
    board1.squares[1][2] = MINIMAX_EMPTY_SQUARE;
    board1.squares[2][0] = MINIMAX_PLAYER_SQUARE;
    board1.squares[2][1] = MINIMAX_OPPONENT_SQUARE;
    board1.squares[2][2] = MINIMAX_OPPONENT_SQUARE;

    minimax_board_t board2;
    board2.squares[0][0] = MINIMAX_OPPONENT_SQUARE;
    board2.squares[0][1] = MINIMAX_EMPTY_SQUARE;
    board2.squares[0][2] = MINIMAX_PLAYER_SQUARE;
    board2.squares[1][0] = MINIMAX_EMPTY_SQUARE;
    board2.squares[1][1] = MINIMAX_EMPTY_SQUARE;
    board2.squares[1][2] = MINIMAX_EMPTY_SQUARE;
    board2.squares[2][0] = MINIMAX_PLAYER_SQUARE;
    board2.squares[2][1] = MINIMAX_EMPTY_SQUARE;
    board2.squares[2][2] = MINIMAX_OPPONENT_SQUARE;

    minimax_board_t board3;
    board3.squares[0][0] = MINIMAX_OPPONENT_SQUARE;
    board3.squares[0][1] = MINIMAX_EMPTY_SQUARE;
    board3.squares[0][2] = MINIMAX_EMPTY_SQUARE;
    board3.squares[1][0] = MINIMAX_OPPONENT_SQUARE;
    board3.squares[1][1] = MINIMAX_EMPTY_SQUARE;
    board3.squares[1][2] = MINIMAX_EMPTY_SQUARE;
    board3.squares[2][0] = MINIMAX_PLAYER_SQUARE;
    board3.squares[2][1] = MINIMAX_EMPTY_SQUARE;
    board3.squares[2][2] = MINIMAX_PLAYER_SQUARE;

    minimax_board_t board4;
    board4.squares[0][0] = MINIMAX_OPPONENT_SQUARE;
    board4.squares[0][1] = MINIMAX_EMPTY_SQUARE;
    board4.squares[0][2] = MINIMAX_EMPTY_SQUARE;
    board4.squares[1][0] = MINIMAX_EMPTY_SQUARE;
    board4.squares[1][1] = MINIMAX_EMPTY_SQUARE;
    board4.squares[1][2] = MINIMAX_EMPTY_SQUARE;
    board4.squares[2][0] = MINIMAX_PLAYER_SQUARE;
    board4.squares[2][1] = MINIMAX_EMPTY_SQUARE;
    board4.squares[2][2] = MINIMAX_PLAYER_SQUARE;

    minimax_board_t board5;
    board5.squares[0][0] = MINIMAX_PLAYER_SQUARE;
    board5.squares[0][1] = MINIMAX_PLAYER_SQUARE;
    board5.squares[0][2] = MINIMAX_EMPTY_SQUARE;
    board5.squares[1][0] = MINIMAX_EMPTY_SQUARE;
    board5.squares[1][1] = MINIMAX_OPPONENT_SQUARE;
    board5.squares[1][2] = MINIMAX_EMPTY_SQUARE;
    board5.squares[2][0] = MINIMAX_EMPTY_SQUARE;
    board5.squares[2][1] = MINIMAX_EMPTY_SQUARE;
    board5.squares[2][2] = MINIMAX_EMPTY_SQUARE;

    uint8_t row, column;

    minimax_computeNextMove(&board1, true, &row, &column);
    minimax_print_board(&board1, true);
    printf("next move for board1: (%d, %d)\n\r", row, column);
    printf("---------------------------------------------------------------\n\n");
    
    minimax_computeNextMove(&board2, true, &row, &column);
    minimax_print_board(&board2, true);
    printf("next move for board2: (%d, %d)\n\r", row, column);
    printf("---------------------------------------------------------------\n\n");
    
    minimax_computeNextMove(&board3, true, &row, &column);
    minimax_print_board(&board3, true);
    printf("next move for board3: (%d, %d)\n\r", row, column);
    printf("---------------------------------------------------------------\n\n");
    
    minimax_computeNextMove(&board4, false, &row, &column);
    minimax_print_board(&board4, true);
    printf("next move for board4: (%d, %d)\n\r", row, column);
    printf("---------------------------------------------------------------\n\n");
    
    minimax_computeNextMove(&board5, false, &row, &column);
    minimax_print_board(&board5, true);
    printf("next move for board5: (%d, %d)\n\r", row, column);
    printf("---------------------------------------------------------------\n\n");
}

