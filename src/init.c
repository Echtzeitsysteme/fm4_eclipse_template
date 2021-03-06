#include "init.h"
#include "lcd.h"
#include "analog.h"
#include "display.h"
#include "gfx.h"
#include "acceleration_app.h"
#include "pdl.h"
#include "pins.h"
#include "timer.h"
//#include  "interrupts_fm4_type_b.c"
#define   __INTERRUPTS_FM4_TYPE_B_C__

void initBoard() {
	cppp_initLCDPins();
	cppp_resetLCD();
	cppp_setupLCD();
	cppp_initAdc();
	cppp_fillScreen(BLACK);
	timer_start();  // start timer
	// Configure all used ports as inputs.
	LED_BLUE_DDR &= ~(1 << LED_BLUE_PIN);
	LED_RED_DDR &= ~(1 << LED_RED_PIN);
	LED_GREEN_DDR &= ~(1 << LED_GREEN_PIN);
	BUTTON_DDR &= ~(1 << BUTTON_PIN);

	bFM4_GPIO_ADE_AN08 = 0; // Disable analog-digital channel 08
	bFM4_GPIO_ADE_AN10 = 0; // Disable analog-digital channel 10
	bFM4_GPIO_ADE_AN18 = 0; // Disable analog-digital channel 18

	//cppp_initAccelerometerPrequisites();
}
