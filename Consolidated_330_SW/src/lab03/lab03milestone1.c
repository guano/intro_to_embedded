#include "intervalTimer.h"
#include "buttons.h"
#include <stdio.h>
#include "xparameters.h"

int main() {
	double duration0, duration1, duration2;
	buttons_init();
	printf("we init the buttons?\n\r");
	intervalTimer_initAll();
	intervalTimer_resetAll();
	// Poll the push-buttons waiting for BTN0 to be pushed.
	printf("Interval Timer Accuracy Test\n\r");
	printf("waiting until BTN0 is pressed.\n\r");
	while (!(buttons_read() & 0x1));
	intervalTimer_start(0);
	intervalTimer_start(1);
	intervalTimer_start(2);
	printf("started timers.\n\r");
	printf("waiting until BTN1 is pressed.\n\r");
	while (!(buttons_read() & 0x2));
	intervalTimer_stop(0);
	intervalTimer_stop(1);
	intervalTimer_stop(2);
	printf("stopped timers.\n\r");
	intervalTimer_getTotalDurationInSeconds(0, &duration0);
	intervalTimer_getTotalDurationInSeconds(1, &duration1);
	intervalTimer_getTotalDurationInSeconds(2, &duration2);
	printf("Time Duration 0: %6.2e seconds.\n\r", duration0);
	printf("Time Duration 1: %6.2e seconds.\n\r", duration1);
	printf("Time Duration 2: %6.2e seconds.\n\r", duration2);

	//double duration0, duration1, duration2;

	duration0 = 0.0;
	duration1 = 0.0;
	duration2 = 0.0;
	buttons_init();
	printf("we init the buttons?\n\r");
	intervalTimer_initAll();
	intervalTimer_resetAll();
	// Poll the push-buttons waiting for BTN0 to be pushed.
	printf("Interval Timer Accuracy Test\n\r");
	printf("waiting until BTN0 is pressed.\n\r");
	while (!(buttons_read() & 0x1));
	intervalTimer_start(0);
	intervalTimer_start(1);
	intervalTimer_start(2);
	printf("started timers.\n\r");
	printf("waiting until BTN1 is pressed.\n\r");
	while (!(buttons_read() & 0x2));
	intervalTimer_stop(0);
	intervalTimer_stop(1);
	intervalTimer_stop(2);
	printf("stopped timers.\n\r");
	intervalTimer_getTotalDurationInSeconds(0, &duration0);
	intervalTimer_getTotalDurationInSeconds(1, &duration1);
	intervalTimer_getTotalDurationInSeconds(2, &duration2);
	printf("Time Duration 0: %6.2e seconds.\n\r", duration0);
	printf("Time Duration 1: %6.2e seconds.\n\r", duration1);
	printf("Time Duration 2: %6.2e seconds.\n\r", duration2);
}
