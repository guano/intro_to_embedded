/*
 * clockControl.h
 *
 *  Created on: May 19, 2015
 *      Author: Taylor Cowley
 */


#ifndef CLOCKCONTROL_H_
#define CLOCKCONTROL_H_

void clockControl_tick();


//These times are based on how long it takes to tick
#define AD_TIMER_EXPIRED 5			//50 milliseconds
#define AUTO_TIMER_EXPIRED 50 		//0.5 seconds
#define RATE_TIMER_EXPIRED 10		//0.1 seconds
#define CLOCK_TIMER_EXPIRED 100		//1 second


#endif /* CLOCKCONTROL_H_ */
