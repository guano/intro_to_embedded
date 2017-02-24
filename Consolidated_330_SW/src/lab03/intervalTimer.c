/*
 * intervalTimer.c
 *
 *  Created on: May 12, 2015
 *      Author: tcowley0
 */

#include "intervalTimer.h"			//my file
#include "xparameters.h"			//Addresses of timers.
#include <stdint.h>					//weird types.
#include <stdio.h>					//print to the screen
#include "xil_io.h"					//read and write the registers

/**	For the selected timer, sets the ENT0 bit in TCSR0; starting the timer */
uint32_t intervalTimer_start(uint32_t timerNumber){
	switch(timerNumber) {
		case XPAR_AXI_TIMER_2_DEVICE_ID:
			printf("tried to reset timer %d \n\r", timerNumber);
			break;
		case XPAR_AXI_TIMER_1_DEVICE_ID:
			printf("tried to reset timer %d \n\r", timerNumber);
			break;
		case XPAR_AXI_TIMER_0_DEVICE_ID:
			printf("tried to reset timer %d \n\r", timerNumber);

			set_bit_in_address(XPAR_AXI_TIMER_0_BASEADDR + TCSR0, ENT0); //Set ENT0 bit

			break;
		default:
			printf("tried to reset timer %d \n\r", timerNumber);
			break;

		}
}

/**	For the selected timer, clears the ENT0 bit in TCSR0; stopping the timer */
uint32_t intervalTimer_stop(uint32_t timerNumber){
	switch(timerNumber) {
			case XPAR_AXI_TIMER_2_DEVICE_ID:
				printf("tried to reset timer %d \n\r", timerNumber);
				break;
			case XPAR_AXI_TIMER_1_DEVICE_ID:
				printf("tried to reset timer %d \n\r", timerNumber);
				break;
			case XPAR_AXI_TIMER_0_DEVICE_ID:
				printf("tried to reset timer %d \n\r", timerNumber);

				clear_bit_in_address(XPAR_AXI_TIMER_0_BASEADDR + TCSR0, ENT0); //clear ENT0 bit

				break;
			default:
				printf("tried to reset timer %d \n\r", timerNumber);
				break;

			}

}

/**This resets the selected timer. It puts 0 in the number register and loads it into the timer. */
uint32_t intervalTimer_reset(uint32_t timerNumber){

	switch(timerNumber) {
		case XPAR_AXI_TIMER_2_DEVICE_ID:
			printf("tried to reset timer %d \n\r", timerNumber);
			break;
		case XPAR_AXI_TIMER_1_DEVICE_ID:
			printf("tried to reset timer %d \n\r", timerNumber);
			break;
		case XPAR_AXI_TIMER_0_DEVICE_ID:
			printf("tried to reset timer %d \n\r", timerNumber);

			Xil_Out32(XPAR_AXI_TIMER_0_BASEADDR + TLR0, 0x0000);		//0 in TLR0
			set_bit_in_address(XPAR_AXI_TIMER_0_BASEADDR + TCSR0, LOAD0);//Set Load0 bit in TCSR0
			Xil_Out32(XPAR_AXI_TIMER_0_BASEADDR + TLR1, 0x0000);		//0 in TLR1
			set_bit_in_address(XPAR_AXI_TIMER_0_BASEADDR + TCSR1, LOAD1);//Set Load1 bit in TCSR1

			intervalTimer_init(timerNumber);
			break;
		default:
			printf("tried to reset timer %d \n\r", timerNumber);
			break;
		}
}

/**inits the selected timer
 * Writes 0 to TCSR0
 * Writes 0 to TCSR1
 * Sets the Cascade bit in TCSR0 so they act as one
 *  */
uint32_t intervalTimer_init(uint32_t timerNumber){
	/**
	To initialize the counters, you should do the following:
    write a 0 to the TCSR0 register.
    write a 0 to the TCSR1 register.
    set the CASC bit and clear the UDT0 bit in the TCSR0 register (cascade mode and up counting).
	 **/

	switch(timerNumber) {
	case XPAR_AXI_TIMER_2_DEVICE_ID:						//timer 2
		printf("tried to init timer %d \n\r", timerNumber);
		break;
	case XPAR_AXI_TIMER_1_DEVICE_ID:						//timer 1
		printf("tried to init timer %d \n\r", timerNumber);
		break;
	case XPAR_AXI_TIMER_0_DEVICE_ID:						//timer 0
		printf("tried to init timer %d \n\r", timerNumber);

		Xil_Out32(XPAR_AXI_TIMER_0_BASEADDR + TCSR0, 0x0000);		//0 in TCSR0
		Xil_Out32(XPAR_AXI_TIMER_0_BASEADDR + TCSR1, 0x0000);		//0 in TCSR1

		set_bit_in_address(XPAR_AXI_TIMER_0_BASEADDR + TCSR0, CASC); //set the cascade bit

		break;
	default:												//There has been a terrible error
		printf("tried to init timer %d \n\r", timerNumber);
		printf("There has been a bad error\n\r");
		break;
	}

	return 1;
}

/** This has the potential to set many bits; as many bits as are 1 in bit
 * ONLY SETS THE BITS THAT ARE 1 */
uint32_t set_bit_in_address(uint32_t address, uint32_t bit){
	uint32_t value = Xil_In32(address);		//get the old value from that address
	value = value | bit;					//mask the new bit onto the old value
	Xil_Out32(address, value);				//write the new value to the address
}

/** This has the potential to clear many bits; as many bits as are 1 in bit
 * ONLY CLEARS THE BITS THAT ARE 1 */
uint32_t clear_bit_in_address(uint32_t address, uint32_t bit){
	uint32_t value = Xil_In32(address);		//get the old value from that address
	value = value & ~bit;					//mask the new bit onto the old value
	Xil_Out32(address, value);				//write the new value to the address
}

/*
/**Currently does nothing
uint32_t intervalTimer_initAll(){}
/**Currently does nothing
uint32_t intervalTimer_resetAll(){}
/**Currently does nothing
uint32_t intervalTimer_testAll(){}
/**Currently does nothing
uint32_t intervalTimer_runTest(uint32_t timerNumber){}
/**Currently does nothing
uint32_t intervalTimer_getTotalDurationInSeconds(uint32_t timerNumber, double *seconds){}
*/


/* Definitions for driver TMRCTR
#define XPAR_XTMRCTR_NUM_INSTANCES 3

/* Definitions for peripheral AXI_TIMER_0
#define XPAR_AXI_TIMER_0_DEVICE_ID 0
#define XPAR_AXI_TIMER_0_BASEADDR 0x42800000
#define XPAR_AXI_TIMER_0_HIGHADDR 0x4280FFFF
#define XPAR_AXI_TIMER_0_CLOCK_FREQ_HZ 100000000


/* Definitions for peripheral AXI_TIMER_1
#define XPAR_AXI_TIMER_1_DEVICE_ID 1
#define XPAR_AXI_TIMER_1_BASEADDR 0x42840000
#define XPAR_AXI_TIMER_1_HIGHADDR 0x4284FFFF
#define XPAR_AXI_TIMER_1_CLOCK_FREQ_HZ 100000000


/* Definitions for peripheral AXI_TIMER_2
#define XPAR_AXI_TIMER_2_DEVICE_ID 2
#define XPAR_AXI_TIMER_2_BASEADDR 0x42880000
#define XPAR_AXI_TIMER_2_HIGHADDR 0x4288FFFF
#define XPAR_AXI_TIMER_2_CLOCK_FREQ_HZ 100000000

*/
