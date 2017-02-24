/*
 * buttonHandler.h
 *
 *  Created on: Jun 4, 2015
 *      Author: tcowley0
 */

#ifndef BUTTONHANDLER_H_
#define BUTTONHANDLER_H_

#include <stdint.h>
#include <stdio.h>
#include <stdbool.h>
#include "supportFiles/display.h"
#include "supportFiles/utils.h"
#include "simonDisplay.h"


//This is how many ticks to let the touch sensor cool off before reading it
#define BUTTON_HANDLER_TOUCH_COOLDOWN 50

//states for our button handler state machine
enum buttonHandler_st_t {
	init_st,				//inits our state machine
	wait_for_enable_st,		//we wait here until we are enabled
	wait_for_touch_st,		//we are active and waiting for a button push
	touch_ad_timer_st,		//we wait here for the touch sensor to cool
	record_touch_st,		//We record where the button was touched
	wait_for_release_st,	//the button is being pushed
	end_st,					//we finalize things
	wait_for_disable_st		//now we just wait to be disabled
};


// Get the simon region numbers. See the source code for the region numbering scheme.
uint8_t buttonHandler_getRegionNumber();

// Turn on the state machine. Part of the interlock.
void buttonHandler_enable();

// Turn off the state machine. Part of the interlock.
void buttonHandler_disable();

// Other state machines can call this function to see if the user has stopped touching the pad.
bool buttonHandler_releaseDetected();

// Standard tick function.
void buttonHandler_tick();

// This tests the functionality of the buttonHandler state machine.
// buttonHandler_runTest(int16_t touchCount) runs the test until
// the user has touched the screen touchCount times. It indicates
// that a button was pushed by drawing a large square while
// the button is pressed and then erasing the large square and
// redrawing the button when the user releases their touch.
void buttonHandler_runTest(int16_t touchCount);

#endif /* BUTTONHANDLER_H_ */
