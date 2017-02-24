/* verifySequence.h
 *
 *      Author: Taylor Cowley
 */

#ifndef VERIFYSEQUENCE_H_
#define VERIFYSEQUENCE_H_

#include <stdint.h>
#include <stdbool.h>
#include <stdio.h>
#include "supportFiles/display.h"
#include "simonDisplay.h"
#include "buttonHandler.h"
#include "globals.h"
#include "buttons.h"

#define VERIFYSEQUENCE_TIMEOUT_SPEED (GLOBALS_VERIFY_TIMEOUT_SPEED)

enum verifySequence_st_t{
	verifySequence_init_st,	//Init everything (like the screen)
	wait_for_enable_v,		//we can't do anything unless enabled
	wait_for_touch,			//wait for the user to touch a button
	wait_for_release,		//we wait for the touch sensor to cool down
	analyze_touch,			//time to register the touch
	end_verify_sequence,	//we have ended the verify sequence
	wait_for_disable_v		//chill here until disabled
};


// State machine will run when enabled.
void verifySequence_enable();

// This is part of the interlock. You disable the state-machine and then enable it again.
void verifySequence_disable();

// Used to detect if there has been a time-out error.
bool verifySequence_isTimeOutError();

// Used to detect if the user tapped the incorrect sequence.
bool verifySequence_isUserInputError();

// Used to detect if the verifySequence state machine has finished verifying.
bool verifySequence_isComplete();

// Standard tick function.
void verifySequence_tick();

// Standard runTest function.
void verifySequence_runTest();

#endif /* VERIFYSEQUENCE_H_ */
