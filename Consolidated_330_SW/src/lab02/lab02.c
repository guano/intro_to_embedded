//Read from the switches and buttons

#include <stdio.h>				//standard input/output
#include "xparameters.h"		//has the addresses of the GPIO blocks
#include "xil_io.h"				//low-level functions for accessing registers
#include "supportFiles/leds.h"

int main() {
	printf("hello world!");
	for(int i = 0; i < 20; i++){
		leds_runTest();
	}
	return 0;
}
