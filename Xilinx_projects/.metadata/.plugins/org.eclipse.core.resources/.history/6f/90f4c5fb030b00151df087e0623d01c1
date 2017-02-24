/*
 * flashSequence.h
 *
 *  Created on: Oct 28, 2014
 *      Author: hutch
 */

#ifndef FLASHSEQUENCE_H_
#define FLASHSEQUENCE_H_

#include <stdint.h>
#include <stdbool.h>
#include "simonDisplay.h"
#include "globals.h"


#define FLASHSEQUENCE_BLINK_SPEED (GLOBALS_FLASH_SPEED / 10)
#define FLASHSEQUENCE_BLANK_SPEED (FLASHSEQUENCE_BLINK_SPEED / 3)

enum flashSequence_st_t{
	flashSequence_init_st,				//Init anything (like the screen)
	wait_for_enable,		//we can't do anything unless enabled
	display_current_square,	//flash the current square of the sequence
	blank,					//a blank in between every flash
	end_flash_sequence,		//we have ended the flash sequence
	wait_for_disable		//chill here until disabled
};


// Turns on the state machine. Part of the interlock.
void flashSequence_enable();

// Turns off the state machine. Part of the interlock.
void flashSequence_disable();

// Other state machines can call this to determine if this state machine is finished.
bool flashSequence_completed();

// Standard tick function.
void flashSequence_tick();

// Tests the flashSequence state machine.
void flashSequence_runTest();

#endif /* FLASHSEQUENCE_H_ */
