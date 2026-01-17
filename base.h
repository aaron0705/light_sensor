/*
 * base.h
 *
 *  Created on: Dec 17, 2025
 *      Author: atran
 */

#ifndef BASE_H
#define BASE_H

#include <stdint.h>

#define base_peripherals (0x40000000)

#define RCC_offset (0x00021000)
#define RCC (base_peripherals + RCC_offset)

#define PortA_offset (0x00010800)
#define PortA (base_peripherals + PortA_offset)

#define PortB_offset (0x00010C00)
#define PortB (base_peripherals + PortB_offset)

#define PortC_offset (0x00011000)
#define PortC (base_peripherals + PortC_offset)

#define I2C_offset (0x00005400)
#define I2C (base_peripherals + I2C_offset)

#define AFIO_offset 	(0x00010000)
#define AFIO 					(base_peripherals + afio_offset)

#define ADC1_offset 	(0x00012400)
#define ADC1 				(base_peripherals + ADC1_offset)

#define CAN_offset 		(0x00006400)
#define CAN 					(base_peripherals + CAN_offset)

#define SPI1_offset 		(0x00013000)
#define SPI1 					(base_peripherals + SPI1_offset)

#define UART1_offset	(0x00013800)
#define UART1				(base_peripherals + UART1_offset)

#define RST_Register (0x00000000)

#endif /* BASE_H */
