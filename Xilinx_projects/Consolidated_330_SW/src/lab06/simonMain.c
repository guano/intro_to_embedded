/*
 * simonMain.c
 *
 *  Created on: Jun 11, 2015
 *      Author: Taylor Cowley
 */


#include "simonMain.h"
//
//int main() {
//	printf("Simon says.... :)\n\r");
//
//	while(1){
//		buttonHandler_tick();
//		flashSequence_tick();
//		verifySequence_tick();
//		simonControl_tick();
//		utils_msDelay(10);
//	}
//
//	printf("You win!\n\r");
//	return 0;
//}
//

#define TOTAL_SECONDS 60
#define TIMER_PERIOD 1.0E-2					////this is a good timer period
#define TIMER_CLOCK_FREQUENCY (XPAR_CPU_CORTEXA9_0_CPU_CLK_FREQ_HZ / 2)
#define TIMER_LOAD_VALUE ((TIMER_PERIOD * TIMER_CLOCK_FREQUENCY) - 1.0)

int main()
{
    // Initialize the GPIO LED driver and print out an error message if it fails (argument = true).
	   // You need to init the LEDs so that LD4 can function as a heartbeat.
    leds_init(true);
    // Init all interrupts (but does not enable the interrupts at the devices).
    // Prints an error message if an internal failure occurs because the argument = true.
    interrupts_initAll(true);
    interrupts_setPrivateTimerLoadValue(TIMER_LOAD_VALUE);
    u32 privateTimerTicksPerSecond = interrupts_getPrivateTimerTicksPerSecond();
    printf("private timer ticks per second: %ld\n\r", privateTimerTicksPerSecond);
    // Allow the timer to generate interrupts.
    interrupts_enableTimerGlobalInts();
    // Initialization of the clock display is not time-dependent, do it outside of the state machine.
    // Keep track of your personal interrupt count. Want to make sure that you don't miss any interrupts.
     int32_t personalInterruptCount = 0;
    // Start the private ARM timer running.
    interrupts_startArmPrivateTimer();
    // Enable interrupts at the ARM.
    interrupts_enableArmInts();
    // interrupts_isrInvocationCount() returns the number of times that the timer ISR was invoked.
    // This value is maintained by the timer ISR. Compare this number with your own local
    // interrupt count to determine if you have missed any interrupts.
    // while (interrupts_isrInvocationCount() < (TOTAL_SECONDS * privateTimerTicksPerSecond)) {
    while(1){
      if (interrupts_isrFlagGlobal) {  // This is a global flag that is set by the timer interrupt handler.
    	  // Count ticks.
      	personalInterruptCount++;

		buttonHandler_tick();
		flashSequence_tick();
		verifySequence_tick();
		simonControl_tick();
    	interrupts_isrFlagGlobal = 0;
      }
   }
   interrupts_disableArmInts();
   printf("isr invocation count: %ld\n\r", interrupts_isrInvocationCount());
   printf("internal interrupt count: %ld\n\r", personalInterruptCount);
   return 0;
}
