/*
 * ADC.c
 *
 *  Created on: Jan 9, 2026
 *      Author: atran
 */
#include "adc.h"
#include "iperipheral.h"

void ADC_init()
{
	    *ADC_SQR1 = (1u << 20);

	    *ADC_SMPR2 =
	        (7 << 0)  |   // CH0 sample
	        (7 << 3)  |   // CH1
	        (7 << 6)  |   // CH2
	        (7 << 9)  |   // CH3
	        (7 << 12) |   // CH4
	        (7 << 15) |   // CH5
	        (7 << 18) |   // CH6
	        (7 << 21);    // CH7

	    *ADC_CR2 |= ADC_ADON;
	    delay_us(10);

	    *ADC_CR2 |= ADC_RSTCAL;
	    while (*ADC_CR2 & ADC_RSTCAL);

	    *ADC_CR2 |= ADC_CAL;
	    while (*ADC_CR2 & ADC_CAL);

}

uint16_t read_adc(int channel)
{
	*ADC_SQR3 |= channel;
	*ADC_CR2 |= ADC_ADON;

    while (!ADC_EOC); // Đợi EOC = 1

    return (uint16_t)*ADC_DR;
}

void ADC_Read_8Channels(uint16_t *buffer)
{
    for (int i = 0; i < 8; i++)
    {
        buffer[i] = read_adc(i);
    }
}

void ADC_Start()
{
	*ADC_CR2 |= SWSTART;
	*ADC_CR2 |= ADC_SWSTART;
	*ADC_CR2 &= ~((uint32_t)(1 << 20));
}
