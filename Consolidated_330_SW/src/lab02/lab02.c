//Read from the switches and buttons

#include <stdio.h>				//standard input/output
//#include "xparameters.h"		//has the addresses of the GPIO blocks
//#include "xil_io.h"				//low-level functions for accessing registers
#include "switches.h"
#include "buttons.h"
#include "supportFiles/display.h"	//to output to the screen

int main() {
	printf("hello world!\n\r");

	buttons_runTest();
	switches_runTest();
	return 0;
}
