/*
 * clockDisplay.h
 *
 *  Created on: May 19, 2015
 *      Author: Taylor Cowley
 */

#ifndef CLOCKDISPLAY_H_
#define CLOCKDISPLAY_H_

#include <stdbool.h>

void clockDisplay_init();  // Called only once - performs any necessary inits.
void clockDisplay_updateTimeDisplay(bool forceUpdateAll);  // Updates the time display with latest time.
void clockDisplay_performIncDec();         // Performs the increment or decrement, depending upon the touched region.
void clockDisplay_advanceTimeOneSecond();  // Advances the time forward by 1 second.
void clockDisplay_runTest();               // Run a test of clock-display functions.

#define WIDTH 320					//width of board
#define HEIGHT 240					//height of board
#define HALF_HEIGHT HEIGHT/2		//half the height
#define HALF_WIDTH WIDTH/2			//half the width
#define ONE_THIRD_WIDTH WIDTH/3 	//1/3 the width, or in between hours and mins
#define TWO_THIRD_WIDTH 2*WIDTH/3 	//2/3 the width, or in between mins and seconds

#define SIZE 5		//YOU CAN CHANGE THIS IF YOU WANT - this is the size of each block. usable values 1-6
#define CLOCK_CENTER 4			//4 characters is half the clock "##:##:##"
#define TEXT_WIDTH_BLOCKS 6		//Each text has 6 blocks in pixels
#define TEXT_HEIGHT_BLOCKS 7	//Each text has 7 blocks in height
#define TEXT_WIDTH TEXT_WIDTH_BLOCKS * SIZE		//width = width in blocks * block size
#define TEXT_HEIGHT TEXT_HEIGHT_BLOCKS * SIZE	//height= height in blocks * block size

#define CENTERING_CONSTANT TEXT_WIDTH * CLOCK_CENTER	//the centering constant is half the clock * each char's width
#define START_X HALF_WIDTH - CENTERING_CONSTANT			//the start x point is the center - centering constant
#define START_Y HALF_HEIGHT - (TEXT_HEIGHT / 2)			//to center in y- y center- half of text height.

#define TRIANGLE_VERTICAL_SPACE TEXT_HEIGHT / 2	//We want a space the size of half the text height

#define HOURS_OFFSET 0					//the hours are printed to the far left of the time
#define MINS_OFFSET 3 * TEXT_WIDTH		//the minutes are printed 3 characters in (2 for hours and 1 for colon)
#define SECS_OFFSET 6 * TEXT_WIDTH		//the seconds are printed 6 characters in (2 hours, 2 mins, 2 colons)

#define SEC_MAX 59		//no more than 59 secs
#define MIN_MAX 59		//no more than 59 mins
#define HOUR_MAX 12		//no more than 12 hours (should be 23)

#define TEXT_COLOR DISPLAY_CYAN			//cool color
#define GOOD_LOOKING_CLOCK_NUMBER 10;	//good looking number

#endif /* CLOCKDISPLAY_H_ */
