/*
 * clockDisplay.c
 *
 *  Created on: May 19, 2015
 *      Author: Taylor Cowley
 */

#include <stdio.h>
#include "clockDisplay.h"
#include "supportFiles/display.h"
#include "supportFiles/utils.h"


#define WIDTH 320				//width of board
#define HEIGHT 240				//height of board
#define HALF_HEIGHT HEIGHT/2	//half the height
#define HALF_WIDTH WIDTH/2		//half the width

#define SIZE 3		//YOU CAN CHANGE THIS IF YOU WANT - this is the size of each block. usable values 1-6
#define CLOCK_CENTER 4			//4 characters is half the clock "##:##:##"
#define TEXT_WIDTH_BLOCKS 6		//Each text has 6 blocks in pixels
#define TEXT_HEIGHT_BLOCKS 7	//Each text has 7 blocks in height
#define TEXT_WIDTH TEXT_WIDTH_BLOCKS * SIZE		//width = width in blocks * block size
#define TEXT_HEIGHT TEXT_HEIGHT_BLOCKS * SIZE	//height= height in blocks * block size

#define CENTERING_CONSTANT TEXT_WIDTH * CLOCK_CENTER	//the centering constant is half the clock * each char's width
#define START_X HALF_WIDTH - CENTERING_CONSTANT			//the start x point is the center - centering constant
#define START_Y HALF_HEIGHT - (TEXT_HEIGHT / 2)			//to center in y- y center- half of text height.

#define TRIANGLE_VERTICAL_SPACE TEXT_HEIGHT / 2	//We want a space the size of half the text height

#define HOURS_OFFSET 0
#define MINS_OFFSET 3 * TEXT_WIDTH
#define SECS_OFFSET 6 * TEXT_WIDTH

#define SEC_MAX 59
#define MIN_MAX 59
#define HOUR_MAX 12

#define TEXT_COLOR DISPLAY_GREEN

void draw_triangles();
void add_sec(bool add);
void add_min(bool add);
void add_hour(bool add);

uint32_t hours = 10;	//Standard clock init number
uint32_t mins = 10;		//Standard clock init number
uint32_t secs = 10;		//Standard clock init number

uint32_t prev_hours = hours;	//Standard clock init number
uint32_t prev_mins = mins;		//Standard clock init number
uint32_t prev_secs = secs;		//Standard clock init number


/** Called only once - performs any necessary inits. */
void clockDisplay_init(){
	display_init();							//Inits the screen
	display_fillScreen(DISPLAY_BLACK);		//Blanks the screen

	display_setTextColor(TEXT_COLOR);	//we want our text green
	display_setTextSize(SIZE);				//sets the text size. To change, change SIZE up above
	display_setCursor(START_X,	START_Y);	//top-left of text

	char initTime[9];
	sprintf(initTime, "%02hd:%02hd:%02hd", hours, mins, secs);
	display_println(initTime);			//probably will go away
	draw_triangles();						//draws the triangles
}


/** Updates the time display with latest time. */
void clockDisplay_updateTimeDisplay(bool forceUpdateAll){
	char timeChange[3];				//the little string we will use for printing
	if(hours != prev_hours || forceUpdateAll) {
		display_setCursor(START_X + HOURS_OFFSET,START_Y);	//we are printing the hours
		display_setTextColor(DISPLAY_BLACK);				//the blanking color
		sprintf(timeChange, "%02hd", prev_hours);			//print the old values to blank them
		display_println(timeChange);						//print the old values to blank them

		display_setTextColor(TEXT_COLOR);				//the print color!
		display_setCursor(START_X + HOURS_OFFSET,START_Y);	//we are printing the hours
		sprintf(timeChange, "%02hd", hours);			//print the new hours
		display_println(timeChange);					//print the new hours

		prev_hours = hours;								//and reset the hours number
	}

	if(mins != prev_mins || forceUpdateAll) {
		display_setCursor(START_X + MINS_OFFSET,START_Y);	//we are printing the mins
		display_setTextColor(DISPLAY_BLACK);				//the blanking color
		sprintf(timeChange, "%02hd", prev_mins);			//print the old values to blank them
		display_println(timeChange);						//print the old values to blank them

		display_setTextColor(TEXT_COLOR);				//the print color!
		display_setCursor(START_X + MINS_OFFSET,START_Y);	//we are printing the mins
		sprintf(timeChange, "%02hd", mins);			//print the new mins
		display_println(timeChange);					//print the new mins

		prev_mins = mins;								//and reset the hours number
	}

	if(secs != prev_secs || forceUpdateAll) {
		display_setCursor(START_X + SECS_OFFSET,START_Y);	//we are printing the secs
		display_setTextColor(DISPLAY_BLACK);				//the blanking color
		sprintf(timeChange, "%02hd", prev_secs);			//print the old values to blank them
		display_println(timeChange);						//print the old values to blank them

		display_setTextColor(TEXT_COLOR);				//the print color!
		display_setCursor(START_X + SECS_OFFSET,START_Y);	//we are printing the secs
		sprintf(timeChange, "%02hd", secs);			//print the new secs
		display_println(timeChange);					//print the new secs

		prev_secs = secs;								//and reset the secs number
	}

}


/** Performs the increment or decrement, depending upon the touched region. */
void clockDisplay_performIncDec(){


}


/** Advances the time forward by 1 second. */
void clockDisplay_advanceTimeOneSecond(){
	if(secs == SEC_MAX) {		//we need to update minutes too!
		secs = 0;
		if(mins == MIN_MAX) {	//we need to update hours too!
			mins = 0;
			if(hours == HOUR_MAX) {	//hour overflow!
				hours = 0;			//So goes to zero
			}else{					//normal
				hours = hours + 1;	//So add one to hours
			}
		} else {	//Minutes didn't overflow
			mins = mins + 1;
		}
	} else { //seconds didn't overflow
		secs = secs + 1;
	}
	clockDisplay_updateTimeDisplay(0);
}


/** Run a test of clock-display functions. */
void clockDisplay_runTest(){
	utils_msDelay(100);//delays by milliseconds.

	for(int i = 0; i < 100; i++) {
		add_sec(1);
		utils_msDelay(50);//delays by milliseconds.
	}
	for(int i = 0; i < 100; i++) {
		add_sec(0);
		utils_msDelay(50);//delays by milliseconds.
	}
	for(int i = 0; i < 100; i++) {
		add_min(1);
		utils_msDelay(50);//delays by milliseconds.
	}
	for(int i = 0; i < 100; i++) {
		add_min(0);
		utils_msDelay(50);//delays by milliseconds.
	}
	for(int i = 0; i < 100; i++) {
		add_hour(1);
		utils_msDelay(50);//delays by milliseconds.
	}
	for(int i = 0; i < 100; i++) {
		add_hour(0);
		utils_msDelay(50);//delays by milliseconds.
	}
	for(int i = 0; i < 1000; i++) {
		clockDisplay_advanceTimeOneSecond();
		utils_msDelay(50);//delays by milliseconds.
	}


}


/** adds/subtracs one to the secs. Takes care of overflow, etc. subtracts if add is 0 */
void add_sec(bool add){
	if(add == 0) { 				//we subtract
		if(secs == 0){
			secs = SEC_MAX;
		} else {
			secs = secs - 1;
		}
	} else {					//we add
		if(secs == SEC_MAX) {
			secs = 0;
		} else {
			secs = secs + 1;
		}
	}
	clockDisplay_updateTimeDisplay(0);
}

/** adds/subtracs one to the mins. Takes care of overflow, etc. subtracts if add is 0 */
void add_min(bool add){
	if(add == 0){				//we subtract
		if(mins == 0) {
			mins = MIN_MAX;
		} else {
			mins = mins -1;
		}
	} else {					//we add
		if(mins == MIN_MAX) {
			mins = 0;
		} else {
			mins = mins + 1;
		}
	}
	clockDisplay_updateTimeDisplay(0);
}

/** adds/subtracs one to the hours. Takes care of overflow, etc. subtracts if add is 0 */
void add_hour(bool add){
	if(add == 0) {				//we subtract
		if(hours == 0) {
			hours = HOUR_MAX;
		} else {
			hours = hours - 1;
		}
	} else {					//we add
		if(hours == HOUR_MAX) {
			hours = 0;
		} else {
			hours = hours + 1;
		}
	}
	clockDisplay_updateTimeDisplay(0);
}

/** Draws the up/down triangles everywhere */
void draw_triangles() {
#define TRIANGLE_COLOR DISPLAY_GREEN

	//make a variable for the x coordinates
	uint16_t x = START_X;

	//hours top
	display_fillTriangle(	x, 				START_Y - TRIANGLE_VERTICAL_SPACE,
							x + TEXT_WIDTH, 	START_Y - TRIANGLE_VERTICAL_SPACE - TEXT_HEIGHT,
							x + TEXT_WIDTH + TEXT_WIDTH , START_Y - TRIANGLE_VERTICAL_SPACE,
			TRIANGLE_COLOR);
	//hours bottom
	display_fillTriangle(	x, 				START_Y + TEXT_HEIGHT + TRIANGLE_VERTICAL_SPACE,
							x + TEXT_WIDTH, 	START_Y + TRIANGLE_VERTICAL_SPACE + TEXT_HEIGHT + TEXT_HEIGHT,
							x + TEXT_WIDTH + TEXT_WIDTH , START_Y + TEXT_HEIGHT + TRIANGLE_VERTICAL_SPACE,
			TRIANGLE_COLOR);


	//move to minutes
	x = x + 3 * TEXT_WIDTH;
	//minutes top
	display_fillTriangle(	x, 				START_Y - TRIANGLE_VERTICAL_SPACE,
							x + TEXT_WIDTH, 	START_Y - TRIANGLE_VERTICAL_SPACE - TEXT_HEIGHT,
							x + TEXT_WIDTH + TEXT_WIDTH , START_Y - TRIANGLE_VERTICAL_SPACE,
			TRIANGLE_COLOR);
	//minutes bottom
	display_fillTriangle(	x, 				START_Y + TEXT_HEIGHT + TRIANGLE_VERTICAL_SPACE,
							x + TEXT_WIDTH, 	START_Y + TRIANGLE_VERTICAL_SPACE + TEXT_HEIGHT + TEXT_HEIGHT,
							x + TEXT_WIDTH + TEXT_WIDTH , START_Y + TEXT_HEIGHT + TRIANGLE_VERTICAL_SPACE,
			TRIANGLE_COLOR);


	//move to seconds
	x = x + 3 * TEXT_WIDTH;
	//seconds top
	display_fillTriangle(	x, 				START_Y - TRIANGLE_VERTICAL_SPACE,
							x + TEXT_WIDTH, 	START_Y - TRIANGLE_VERTICAL_SPACE - TEXT_HEIGHT,
							x + TEXT_WIDTH + TEXT_WIDTH , START_Y - TRIANGLE_VERTICAL_SPACE,
			TRIANGLE_COLOR);
	//seconds bottom
	display_fillTriangle(	x, 				START_Y + TEXT_HEIGHT + TRIANGLE_VERTICAL_SPACE,
							x + TEXT_WIDTH, 	START_Y + TRIANGLE_VERTICAL_SPACE + TEXT_HEIGHT + TEXT_HEIGHT,
							x + TEXT_WIDTH + TEXT_WIDTH , START_Y + TEXT_HEIGHT + TRIANGLE_VERTICAL_SPACE,
			TRIANGLE_COLOR);
}























