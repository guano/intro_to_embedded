/*
 * lab05FINAL.c
 *
 *  Created on: Jun 2, 2015
 *      Author: tcowley0
 */


#include <stdio.h>
#include "ticTacToeControl.h"
#include "supportFiles/utils.h"
#include "intervalTimer.h"

int main() {
	intervalTimer_initAll();
	intervalTimer_resetAll();
	double seconds = 0.0;
	double max_time = 0.0;

	//test the init function's time.
	intervalTimer_start(0);
	ticTacToeControl_tick();
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
		ticTacToeControl_tick();
		intervalTimer_stop(0);
		intervalTimer_getTotalDurationInSeconds(0, &seconds);
		intervalTimer_reset(0);

		if(seconds > max_time){
			max_time = seconds;
			printf("We have acheived a new max time for our tick function!  %6.2e\n\r", max_time);
		}
		//printf("Not a max time...  %6.2e\n\r", seconds);
		utils_msDelay(300);
	}



	printf("Starting test of ticTacToe\n\r");
	while(1){
		ticTacToeControl_tick();
		utils_msDelay(300);
	}
	return 0;
}
