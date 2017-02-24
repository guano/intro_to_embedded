/*
 * clockMain.c
 *
 *  Created on: May 19, 2015
 *      Author: Taylor Cowley
 */

#include "clockDisplay.h"
#include "clockControl.h"
#include <stdio.h>

int main() {
	printf("starting test program 04\n\r");

	clockDisplay_init();
	clockDisplay_runTest();

	printf("ending test program 04\n\r");
	return 0;
}
