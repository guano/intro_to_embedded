/*
 * ticTacToeDisplay.h
 *
 *  Created on: May 26, 2015
 *      Author: Taylor Cowley
 */

#ifndef TICTACTOEDISPLAY_H_
#define TICTACTOEDISPLAY_H_

#include "supportFiles/display.h"

#define TICTACTOEDISPLAY_DISP_WIDTH	320//display_width();
#define TICTACTOEDISPLAY_DISP_HEIGHT 240//display_height();

#define TICTACTOEDISPLAY_ONE_THIRD_WIDTH 	TICTACTOEDISPLAY_DISP_WIDTH / 3
#define TICTACTOEDISPLAY_ONE_THIRD_HEIGHT	TICTACTOEDISPLAY_DISP_HEIGHT/ 3
#define TICTACTOEDISPLAY_TWO_THIRD_WIDTH		2 * TICTACTOEDISPLAY_ONE_THIRD_WIDTH
#define TICTACTOEDISPLAY_TWO_THIRD_HEIGHT	2 * TICTACTOEDISPLAY_ONE_THIRD_HEIGHT

#define TICTACTOEDISPLAY_BACKGROUND_COLOR DISPLAY_BLACK
#define TICTACTOEDISPLAY_BOARD_COLOR DISPLAY_CYAN
#define TICTACTOEDISPLAY_X_COLOR DISPLAY_MAGENTA
#define TICTACTOEDISPLAY_O_COLOR DISPLAY_YELLOW


#define TICTACTOEDISPLAY_TICTACTOEDISPLAY_TOP_TICTACTOEDISPLAY_LEFT_X_X		20
#define TICTACTOEDISPLAY_TICTACTOEDISPLAY_TOP_TICTACTOEDISPLAY_LEFT_X_Y		10
#define TICTACTOEDISPLAY_TICTACTOEDISPLAY_BOTTOM_TICTACTOEDISPLAY_RIGHT_X_X	TICTACTOEDISPLAY_ONE_THIRD_WIDTH - 20
#define TICTACTOEDISPLAY_TICTACTOEDISPLAY_BOTTOM_TICTACTOEDISPLAY_RIGHT_X_Y	TICTACTOEDISPLAY_ONE_THIRD_HEIGHT - 10

#define TICTACTOEDISPLAY_TICTACTOEDISPLAY_TOP_TICTACTOEDISPLAY_RIGHT_X_X		TICTACTOEDISPLAY_ONE_THIRD_WIDTH - 20
#define TICTACTOEDISPLAY_TICTACTOEDISPLAY_TOP_TICTACTOEDISPLAY_RIGHT_X_Y		10
#define TICTACTOEDISPLAY_TICTACTOEDISPLAY_BOTTOM_TICTACTOEDISPLAY_LEFT_X_X		20
#define TICTACTOEDISPLAY_TICTACTOEDISPLAY_BOTTOM_TICTACTOEDISPLAY_LEFT_X_Y		TICTACTOEDISPLAY_ONE_THIRD_HEIGHT - 10

#define TICTACTOEDISPLAY_O_COORD_X	TICTACTOEDISPLAY_ONE_THIRD_WIDTH / 2
#define TICTACTOEDISPLAY_O_COORD_Y	TICTACTOEDISPLAY_ONE_THIRD_HEIGHT / 2
#define TICTACTOEDISPLAY_O_RADIUS	TICTACTOEDISPLAY_ONE_THIRD_HEIGHT / 3

#define TICTACTOEDISPLAY_LEFT 0
#define TICTACTOEDISPLAY_MID 1
#define TICTACTOEDISPLAY_RIGHT 2
#define TICTACTOEDISPLAY_TOP 0
#define TICTACTOEDISPLAY_BOTTOM 2

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
