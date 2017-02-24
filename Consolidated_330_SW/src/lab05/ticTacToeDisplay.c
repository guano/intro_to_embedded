/*
 * ticTacToeDisplay.c
 *
 *  Created on: May 26, 2015
 *      Author: Taylor Cowley
 */


#include "ticTacToeDisplay.h"
#include "switches.h"
#include "buttons.h"
#include "supportFiles/display.h"
#include <stdint.h>
#include "supportFiles/utils.h"

#include <stdio.h>


// Inits the tic-tac-toe display, draws the lines that form the board.
void ticTacToeDisplay_init(){
	display_init();
	display_fillScreen(BACKGROUND_COLOR);
	ticTacToeDisplay_drawBoardLines();
}

// Draws an X at the specified row and column.
void ticTacToeDisplay_drawX(uint8_t row, uint8_t column){
	//calculate the offsets to start drawing the x in the right box
	uint8_t x_offset = ONE_THIRD_WIDTH * row;
	uint8_t y_offset = ONE_THIRD_HEIGHT * column;

	//top left to bottom right line for the x
	display_drawLine(	x_offset + TOP_LEFT_X_X, 		y_offset + TOP_LEFT_X_Y,
						x_offset + BOTTOM_RIGHT_X_X, 	y_offset + BOTTOM_RIGHT_X_Y, X_COLOR);

	//top right to bottom left line for the x
	display_drawLine(	x_offset + TOP_RIGHT_X_X, 		y_offset + TOP_RIGHT_X_Y,
							x_offset + BOTTOM_LEFT_X_X, y_offset + BOTTOM_LEFT_X_Y, X_COLOR);
}

// Draws an O at the specified row and column.
void ticTacToeDisplay_drawO(uint8_t row, uint8_t column){
	//calculate the offsets to start drawing the x in the right box
	uint8_t x_offset = ONE_THIRD_WIDTH * row;
	uint8_t y_offset = ONE_THIRD_HEIGHT * column;

	display_drawCircle(x_offset + O_COORD_X,	y_offset + O_COORD_Y, O_RADIUS, O_COLOR);
}

// After a touch has been detected and after the proper delay, this sets the row and column arguments
// according to where the user touched the board.
void ticTacToeDisplay_touchScreenComputeBoardRowColumn(uint8_t* row, uint8_t* column){
	  int16_t x;		//init variables for to find where on board it is
	  int16_t y;		//init variables for to find where on board it is
	  uint8_t z;		//Not used, but needed for next line
	  display_getTouchedPoint(&x, &y, &z);	//compute position on board! store in x, y, z
	  display_clearOldTouchData();			//clear it for the next touch :)
	  if(x < ONE_THIRD_WIDTH) {			//on the left 3rd
		  *row = LEFT;					//left
	  } else if(x > TWO_THIRD_WIDTH){	//on the right 3rd
		  *row = RIGHT;					//right
	  } else {							//in the middle
		  *row = MID;					//MID
	  }

	  if(y < ONE_THIRD_HEIGHT) {		//in the top third
		  *column = TOP;				//top
	  } else if (y > TWO_THIRD_HEIGHT){	//in the bottom third
		  *column = BOTTOM;				//bottom
	  } else{							//in the middle
		  *column = MID;				//MID
	  }
}

// Runs a test of the display. Does the following.
// Draws the board. Each time you touch one of the screen areas, the screen will paint
// an X or an O, depending on whether switch 0 (SW0) is slid up (O) or down (X).
// When BTN0 is pushed, the screen is cleared. The test terminates when BTN1 is pushed.
void ticTacToeDisplay_runTest(){
	ticTacToeDisplay_init();
	switches_init();
	buttons_init();
	while(1){
		if(display_isTouched()){
			utils_msDelay(50);
			uint8_t row;
			uint8_t col;
			ticTacToeDisplay_touchScreenComputeBoardRowColumn(&row, &col);
			(switches_read() & 0x01) ? ticTacToeDisplay_drawO(row, col) : ticTacToeDisplay_drawX(row, col);
		}

		if((uint32_t)buttons_read() & RAW_BUTTON_0){
			ticTacToeDisplay_init();
		}

		if((uint32_t)buttons_read() & RAW_BUTTON_1){
			printf("Test terminated");

			display_setTextColor(DISPLAY_BLACK, DISPLAY_WHITE);
			display_setTextSize(5);
			display_setCursor(10, ONE_THIRD_HEIGHT);
			display_println(" Test\nTerminated");

			return;
		}

	}

	ticTacToeDisplay_init();
	ticTacToeDisplay_drawX(1,2);
	utils_msDelay(1000);
	ticTacToeDisplay_drawO(1,1);
	utils_msDelay(1000);
	ticTacToeDisplay_drawX(2,0);
	utils_msDelay(1000);
	ticTacToeDisplay_drawO(0,0);
	utils_msDelay(1000);
	ticTacToeDisplay_drawX(2,2);
	utils_msDelay(1000);
	ticTacToeDisplay_drawO(2,1);
	utils_msDelay(1000);
	ticTacToeDisplay_drawX(0,2);

	display_setTextColor(DISPLAY_BLACK, DISPLAY_WHITE);
	display_setTextSize(6);
	display_setCursor(10, ONE_THIRD_HEIGHT);
	display_println("X WINS!");
}

// This will draw the four board lines.
void ticTacToeDisplay_drawBoardLines(){
	//left vertical line
	display_drawLine(ONE_THIRD_WIDTH, 	0, 	ONE_THIRD_WIDTH, 	DISP_HEIGHT, 	BOARD_COLOR);
	//right vertical line
	display_drawLine(TWO_THIRD_WIDTH, 	0, 	TWO_THIRD_WIDTH, 	DISP_HEIGHT, 	BOARD_COLOR);
	//top horizontal line
	display_drawLine(0, ONE_THIRD_HEIGHT, 	DISP_WIDTH,		ONE_THIRD_HEIGHT,  	BOARD_COLOR);
	//bottom horizontal line
	display_drawLine(0, TWO_THIRD_HEIGHT, 	DISP_WIDTH,		TWO_THIRD_HEIGHT,  	BOARD_COLOR);
}
