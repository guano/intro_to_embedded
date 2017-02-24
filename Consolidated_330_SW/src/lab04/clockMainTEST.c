/*
 * clockMain.c
 *
 *  Created on: May 19, 2015
 *      Author: Taylor Cowley
 */

#include "clockDisplay.h"
#include "clockControl.h"
#include "supportFiles/utils.h"
#include <stdio.h>
#include "intervalTimer.h"

int main() {
	printf("starting test program 04\n\r");

	//clockDisplay_init();
	//clockDisplay_runTest();
	intervalTimer_initAll();
	intervalTimer_resetAll();
	double seconds = 0.0;
	double max_time = 0.0;

	intervalTimer_start(0);
	clockControl_tick();
	intervalTimer_stop(0);
	intervalTimer_getTotalDurationInSeconds(0, &seconds);
	intervalTimer_reset(0);

	if(seconds > max_time){
		max_time = seconds;
		printf("Time for our init tick function!  %6.2e\n\r", max_time);
	}
	max_time = 0.0;

	while(1){
		intervalTimer_start(0);
		clockControl_tick();
		intervalTimer_stop(0);
		intervalTimer_getTotalDurationInSeconds(0, &seconds);
		intervalTimer_reset(0);

		if(seconds > max_time){
			max_time = seconds;
			printf("We have acheived a new max time for our tick function!  %6.2e\n\r", max_time);
		}
		//printf("Not a max time...  %6.2e\n\r", seconds);
		utils_msDelay(1);
	}
	printf("ending test program 04\n\r");
	return 0;
}
