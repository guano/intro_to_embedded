// Print out "hello world" on both the console and the LCD screen.

#include <stdio.h>
#include "supportFiles/display.h"
//commented out because we don't want to run this anymore.
//int main() {
int helloWorld(){
	display_init();  // Must init all of the software and underlying hardware for LCD.
	display_fillScreen(DISPLAY_BLACK);  // Blank the screen.
	display_setCursor(0, 0);            // The upper left of the LCD screen.
	display_setTextColor(DISPLAY_RED);  // Make the text red.
	display_setTextSize(2);             // Make the text a little larger.
	//display_println("hello world (on the LCD)!");    // This actually prints the string to the LCD.
	printf("hello world!\n\r");  // This prints on the console.



	display_setRotation(0);

	int16_t h = display_height();
	int16_t w = display_width();

	//display_drawRect(w/3, h/3, w/3, h/3, DISPLAY_CYAN);
	display_drawLine(0,0,w,h,DISPLAY_GREEN);
	display_drawLine(0,h,w,0,DISPLAY_GREEN);

	int16_t temp = h;
	h = w;
	w = temp;

	//display_drawTriangle(w/2, 3*h/8,   3*w/8, h/5,     5*w/8,h/5,   DISPLAY_YELLOW);
	//display_fillTriangle(w/2, 5*h/8,   3*w/8, 4*h/5,   5*w/8,4*h/5, DISPLAY_YELLOW);
	display_drawTriangle(3*h/8,w/2,  h/5,3*w/8,   h/5,5*w/8,   DISPLAY_YELLOW);
	display_fillTriangle(5*h/8,w/2,  4*h/5,3*w/8, 4*h/5,5*w/8, DISPLAY_YELLOW);

	display_drawCircle(h/2, 2*w/8,   h/12, DISPLAY_RED);
	display_fillCircle(h/2, 6*w/8,   h/12, DISPLAY_RED);

	//display_drawCircle( 2*w/8, h/2,  h/12, DISPLAY_RED);
	//display_fillCircle( 6*w/8, h/2,  h/12, DISPLAY_RED);


}
