/*
 * iperipheral.c
 *
 *  Created on: Dec 26, 2025
 *      Author: atran
 */
#include "iperipheral.h"
#include <math.h>
#include <stdint.h>

void reset_iper()
{
	*SYST_CTRL = 0;
	*SYST_RVR = 0;
	*SYST_CVR = 0;
}

void delay_ms(volatile int time)
{
	reset_iper();
	// Initialize sequence: program reload value, clear current value, program control and status
	int load_value = (time * pow(10, -3) * 8* pow(10, 6)) - 1;
	*SYST_RVR = load_value;

	*SYST_CTRL |= (1u);

	while (!Counted);
	return;
}

void delay_us(volatile int time)
{
		reset_iper();
		// Initialize sequence: program reload value, clear current value, program control and status
		int load_value = (time * pow(10, -6) * 8* pow(10, 6)) - 1;
		*SYST_RVR = load_value;

		*SYST_CTRL |= (1u);

		while (!Counted);
		return;
}
