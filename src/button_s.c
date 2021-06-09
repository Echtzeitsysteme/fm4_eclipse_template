#include "button.h"
#include "delay.h"
#include "pdl_header.h"
#include "s6e2ccxj.h"
#include "pins.h"
#include "timer.h"
#include "diag/Trace.h"

static uint8_t ledStatus;

static void initLED_s();

/**
 * Returns true (1) if the button is pressed
 */
static int isButtonPressed_s();

/**
 *  Changes the status of the blue LED.
 */
static void toggleBlueLED_s();

/**
 *  Sets the blue LED to its status.
 */
static void setBlueLED_s(uint8_t status);

void ButtonToggleBlueLED_s() {
	initLED_s();
	
	while (1) {
		if (isButtonPressed_s()) {
			toggleBlueLED_s();
			setBlueLED_s(ledStatus);
			while (isButtonPressed_s()) {}
		}
		cppp_microDelay(1000);
	}
}

void ButtonHoldBlueLEDOn_s() {
	initLED_s();
	
	while (1) {

		while (isButtonPressed_s()) {
			setBlueLED_s(1u);
			cppp_microDelay(1000);
		}

		setBlueLED_s(0u);
		cppp_microDelay(1000);

	}
}

static void initLED_s() {
	ledStatus = 0u;
	timer_start();
	// Initialize left button as input and activate pullup resistor
	BUTTON_DDR &= ~(1 << BUTTON_PIN);
	BUTTON_PCR |= (1 << BUTTON_PIN);

	LED_BLUE_DDR |= (1 << LED_ORANGE_PIN); // Configure blue led as output pin
	LED_BLUE_DOR |= (1 << LED_ORANGE_PIN); // Switch LED off

}

static int isButtonPressed_s() {
	// Inverted logic as input is pulled up
	return !(BUTTON_DIR & (1 << BUTTON_PIN));
}

static void toggleBlueLED_s() {
	if (ledStatus) ledStatus = 0u;
	else ledStatus = 1u;
}

static void setBlueLED_s(uint8_t status) {
	if (status) LED_BLUE_DOR &= ~(1 << LED_ORANGE_PIN);
	else LED_BLUE_DOR |= (1 << LED_ORANGE_PIN);
}

