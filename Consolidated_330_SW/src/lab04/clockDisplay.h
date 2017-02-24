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

//mental note- do not put any other functions here.


#endif /* CLOCKDISPLAY_H_ */
