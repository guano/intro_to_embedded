/*
 * globals.c
 *
 *  Created on: Jun 4, 2015
 *      Author: Taylor Cowley
 */


#include "globals.h"

uint8_t globals_sequence[GLOBALS_MAX_FLASH_SEQUENCE];
uint16_t globals_length = 0;
uint16_t globals_current_iteration_length = 0;

// This is the length of the complete sequence at maximum length.
// You must copy the contents of the sequence[] array into the global variable that you maintain.
// Do not just grab the pointer as this will fail.
void globals_setSequence(const uint8_t sequence[], uint16_t length){
	globals_length = length;				//store the length in our global length var
	for(uint16_t i = 0; i<length; i++){		//iterate through the new array
		globals_sequence[i] = sequence[i];	//store that index in our global array
	}
}

// This returns the value of the sequence at the index.
uint8_t globals_getSequenceValue(uint16_t index){
	return globals_sequence[index];		//return the value at this index.
}

// Retrieve the sequence length.
uint16_t globals_getSequenceLength(){
	return globals_length;				//a simple getter function
}

// This is the length of the sequence that you are currently working on.
void globals_setSequenceIterationLength(uint16_t length){
	globals_current_iteration_length = length;	//a simple setter
}

// This is the length of the sequence that you are currently working on (not the maximum length but the interim length as
// the use works through the pattern one color at a time.
uint16_t globals_getSequenceIterationLength(){
	return globals_current_iteration_length;	//another simple getter
}
