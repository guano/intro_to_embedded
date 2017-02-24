/*
 * intervalTimer.h
 *
 *  Created on: May 12, 2015
 *      Author: tcowley0
 */

#ifndef INTERVALTIMER_H_
#define INTERVALTIMER_H_


#include <stdint.h>

#define TCSR0	0x00
#define TCSR1	0x10

#define TLR0	0x04
#define TLR1	0x14

#define TCR0	0x08
#define TCR1	0x18

#define ENT0	0x00000080
#define LOAD0	0x00000020
#define LOAD1	0x00000020
#define CASC	0x00000800

uint32_t intervalTimer_start(uint32_t timerNumber);
uint32_t intervalTimer_stop(uint32_t timerNumber);
uint32_t intervalTimer_reset(uint32_t timerNumber);
uint32_t intervalTimer_init(uint32_t timerNumber);
uint32_t intervalTimer_initAll();
uint32_t intervalTimer_resetAll();
uint32_t intervalTimer_testAll();
uint32_t intervalTimer_runTest(uint32_t timerNumber);
uint32_t intervalTimer_getTotalDurationInSeconds(uint32_t timerNumber, double *seconds);

uint32_t set_bit_in_address(uint32_t address, uint32_t bit);
uint32_t clear_bit_in_address(uint32_t address, uint32_t bit);

#endif /* INTERVALTIMER_H_ */
