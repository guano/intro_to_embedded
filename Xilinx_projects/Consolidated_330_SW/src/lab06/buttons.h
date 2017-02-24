/*
 * buttons.h
 *
 *  Created on: May 5, 2015
 *      Author: tcowley0
 */

#ifndef BUTTONS_H_
#define BUTTONS_H_

#include <stdint.h>

#define BUTTONS_INIT_STATUS_OK 1
#define BUTTONS_INIT_STATUS_FAIL 0

#define BUTTON_0 0
#define BUTTON_1 1
#define BUTTON_2 2
#define BUTTON_3 3

#define RAW_BUTTON_0 0x01
#define RAW_BUTTON_1 0x02
#define RAW_BUTTON_2 0x04
#define RAW_BUTTON_3 0x08
#define RAW_BUTTON_ALL 0x0f

#define HALF_SCREEN 2
#define CURSOR_HEIGHT 8
#define QUARTER_WIDTH 4

#define TRI_STATE_OFFSET 0x04
#define TRI_STATE_READ 0xFF

//reads the buttons register
uint32_t read_buttons_gpio_register(int32_t offset);

//writes to a buttons register
//really only useful to write to the tri-state
void write_buttons_register(int32_t offset, uint32_t value);

//call me first!
int buttons_init();

// Returns the current value of all 4 buttons as the lower 4 bits of the returned value.
// bit3 = BTN3, bit2 = BTN2, bit1 = BTN1, bit0 = BTN0.
int32_t buttons_read();

// Runs a test of the buttons. As you push the buttons, graphics and messages will be written to the LCD
// panel. The test will until all 4 pushbuttons are simultaneously pressed.
void buttons_runTest();

//this function calles the other disp functions based on which button it is
void disp_button(char blank, char button);

//displays or blanks button 0
void disp_button_0(char blank);

//displays or blanks button 1
void disp_button_1(char blank);

//displays or blanks button 2
void disp_button_2(char blank);

//displays or blanks button 3
void disp_button_3(char blank);

#endif /* BUTTONS_H_ */
