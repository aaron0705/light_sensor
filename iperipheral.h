/*
 * iperipheral.h
 *
 *  Created on: Dec 23, 2025
 *      Author: atran
 */

#ifndef IPERIPHERAL_H_
#define IPERIPHERAL_H_

#include <stdint.h>

#define base (0xE0000000)

/* 0: Enable
 * 1: Tick int
 * 2: CLK source
 * 3-15: Reversed
 * 16: Count flag
 * 17-31: Reversed*/
#define SYST_CTRL_offset 	(0x0000E010)
#define SYST_CTRL 			((volatile uint32_t *)(base + SYST_CTRL_offset))


/* 0-23: Reload
 * 24-31: Reserved
 * */
#define SYST_RVR_offset		(0x0000E014)
#define SYST_RVR			((volatile uint32_t *)(base + SYST_RVR_offset))

/* 0-23: Current
 * 24-31: Reserved*/
#define SYST_CVR_offset		(0x0000E018)
#define SYST_CVR			((volatile uint32_t *)(base + SYST_CVR_offset))

/* 0-23: Tenms
 * 24-29: Reserved
 * 30: Skew
 * 31: Noref*/
#define SYST_CALIB_offset 	(0x0000E01C)
#define SYST_CALIB			((volatile uint32_t *)(base + SYST_CALIB_offset))

#define Counted (*SYST_CTRL & ~(1u<<16))

void reset_iper();

void delay_ms(volatile int time);

void delay_us(volatile int time);

#endif /* IPERIPHERAL_H_ */
