/*
 * lab06test.c
 *
 *  Created on: Jun 4, 2015
 *      Author: tcowley0
 */
#include "simonDisplay.h"
#include "buttonHandler.h"
#include "flashSequence.h"
#include "verifySequence.h"
#include "simonControl.h"
#include "supportFiles/utils.h"
#include <stdio.h>
#include <stdlib.h>


int main() {
	printf("Testing our stuff\n\r");
	//simonDisplay_runTest(5);
	//buttonHandler_runTest(20);
	//flashSequence_runTest();
	//verifySequence_runTest();
	//srand(40);

	//for(int i = 0; i < 50; i++){
	//	printf("A random number: %d\n\r", rand());
	//}

	//for(int i = 0; i <50; i++){
	//	printf("A random number between 0 and 3: %d\n\r", rand()%4);
	//}
	display_init();
	simonControl_display_splash();
	simonControl_start_rand_timer();
	utils_msDelay(67);
	simonControl_create_random_sequence(10);
	utils_msDelay(66);
	simonControl_create_random_sequence(10);
	utils_msDelay(68);
	simonControl_create_random_sequence(10);
	utils_msDelay(73);
	simonControl_create_random_sequence(10);
	utils_msDelay(89);
	simonControl_create_random_sequence(10);
	utils_msDelay(100);
	simonControl_create_random_sequence(10);
	utils_msDelay(3);
	simonControl_create_random_sequence(10);
	utils_msDelay(1);
	simonControl_create_random_sequence(10);
	utils_msDelay(2);
	simonControl_create_random_sequence(10);
	utils_msDelay(4);
	simonControl_create_random_sequence(10);
	utils_msDelay(5);
	simonControl_create_random_sequence(10);
	utils_msDelay(6);
	simonControl_create_random_sequence(10);
	utils_msDelay(7);
	simonControl_create_random_sequence(10);
	utils_msDelay(8);
	simonControl_create_random_sequence(10);
	utils_msDelay(9);
	simonControl_create_random_sequence(10);
	utils_msDelay(10);
	simonControl_create_random_sequence(10);


	printf("End of test\n\r");
}
