/*
 * ticTacToeDisplay.h
 *
 *  Created on: May 26, 2015
 *      Author: Taylor Cowley
 */

#ifndef TICTACTOEDISPLAY_H_
#define TICTACTOEDISPLAY_H_

#include "supportFiles/display.h"

#define DISP_WIDTH	320//display_width();
#define DISP_HEIGHT 240//display_height();

#define ONE_THIRD_WIDTH 	DISP_WIDTH / 3
#define ONE_THIRD_HEIGHT	DISP_HEIGHT/ 3
#define TWO_THIRD_WIDTH		2 * ONE_THIRD_WIDTH
#define TWO_THIRD_HEIGHT	2 * ONE_THIRD_HEIGHT

#define BACKGROUND_COLOR DISPLAY_BLACK
#define BOARD_COLOR DISPLAY_CYAN
#define X_COLOR DISPLAY_MAGENTA
#define O_COLOR DISPLAY_YELLOW


#define TOP_LEFT_X_X		20
#define TOP_LEFT_X_Y		10
#define BOTTOM_RIGHT_X_X	ONE_THIRD_WIDTH - 20
#define BOTTOM_RIGHT_X_Y	ONE_THIRD_HEIGHT - 10

#define TOP_RIGHT_X_X		ONE_THIRD_WIDTH - 20
#define TOP_RIGHT_X_Y		10
#define BOTTOM_LEFT_X_X		20
#define BOTTOM_LEFT_X_Y		ONE_THIRD_HEIGHT - 10

#define O_COORD_X	ONE_THIRD_WIDTH / 2
#define O_COORD_Y	ONE_THIRD_HEIGHT / 2
#define O_RADIUS	ONE_THIRD_HEIGHT / 3

#define LEFT 0
#define MID 1
#define RIGHT 2
#define TOP 0
#define BOTTOM 2

// Inits the tic-tac-toe display, draws the lines that form the board.
void ticTacToeDisplay_init();

// Draws an X at the specified row and column.
void ticTacToeDisplay_drawX(uint8_t row, uint8_t column);

// Draws an O at the specified row and column.
void ticTacToeDisplay_drawO(uint8_t row, uint8_t column);

// After a touch has been detected and after the proper delay, this sets the row and column arguments
// according to where the user touched the board.
void ticTacToeDisplay_touchScreenComputeBoardRowColumn(uint8_t* row, uint8_t* column);

// Runs a test of the display. Does the following.
// Draws the board. Each time you touch one of the screen areas, the screen will paint
// an X or an O, depending on whether switch 0 (SW0) is slid up (O) or down (X).
// When BTN0 is pushed, the screen is cleared. The test terminates when BTN1 is pushed.
void ticTacToeDisplay_runTest();

// This will draw the four board lines.
void ticTacToeDisplay_drawBoardLines();



#endif /* TICTACTOEDISPLAY_H_ */
