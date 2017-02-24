/*
 * simonControl.h
 *
 *  Created on: Jun 11, 2015
 *      Author: Taylor Cowley
 */

#ifndef SIMONCONTROL_H_
#define SIMONCONTROL_H_

#include <stdio.h>
#include "intervalTimer.h"
#include "supportFiles/display.h"
#include "globals.h"
#include "flashSequence.h"
#include "verifySequence.h"

//Timer 1 will be the timer for the random seed
#define SIMONCONTROL_RAND_TIMER 1
//For testing purposes (or maybe gameplay), we can only have this many possible sequences
#define SIMONCONTROL_TOTAL_POSSIBLE_SEQUENCES 10
//The level that we start on. Can get higher.
#define SIMONCONTROL_START_LEVEL 4
//I suppose this could be changed to have a different number of buttons...
#define SIMONCONTROL_NUM_BUTTONS 4

#define SIMONCONTROL_TITLE_SIZE 6			//Size of the big text for simon
#define SIMONCONTROL_STATUS_TEXT_SIZE 3		//Size of the small text for simon

#define SIMONCONTROL_SUCCESS_DELAY 200;		//how many ticks to display the success
#define SIMONCONTROL_TOUCH_NEW_LEVEL 200;	//how many ticks to display this option
#define SIMONCONTROL_LONGEST_RUN_DELAY 300;	//how many ticks to tell them how long they got
#define SIMONCONTROL_FAILURE_DELAY 200;		//how many ticks to tell the user they failed

#define SIMONCONTROL_UPPER_HEIGHT display_height()/4	//where the title gets displayed
#define SIMONCONTROL_LOWER_HEIGHT display_height() * 3 / 4	//where the subtitles get displayed
#define SIMONCONTROL_DISPLAY_SCREEN_MAX_LENGTH 20

enum simonControl_st_t{
	simonControl_init_st,			//Init everything (like the screen)
	start_wait_for_touch_st,			//start when they touch
	start_wait_for_release_st,			//I lied. start when they release
	flash_sequence_st,					//show the user the current sequence
	validate_sequence_st,				//Let the user try
	success_st,							//You beat the level!
	touch_for_new_level_st,				//Display "touch for a new level"
	failure_st,							//Display of failure
	longest_run_st,						//we have ended the verify sequence
};


//This is the only function that needs to be called from the outside.
//it runs the game as long as all of the state machines are ticking.
void simonControl_tick();

//Starts the timer that we use for the rand seed
void simonControl_start_rand_timer();

//Stops the timer that we use for the rand seed
void simonControl_stop_rand_timer();

//Turns the timer that we use for the rand seed into a random sequence for our game.
void simonControl_create_random_sequence(uint16_t length);

//This is the starting splash screen
void simonControl_display_splash();

//This is the "touch for new level" screen
void simonControl_display_touch_for_new_level();

//This is the success screen
void simonControl_display_success();

//This is the failure screen
void simonControl_display_failure();

//This is the best run screen
void simonControl_display_best_run(uint16_t best_score);

#endif /* SIMONCONTROL_H_ */
