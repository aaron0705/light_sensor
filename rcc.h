/*
 * rcc.h
 *
 *  Created on: Dec 17, 2025
 *      Author: atran
 */

#ifndef RCC_H_
#define RCC_H_

#include "base.h"
#include <stdint.h>

#define RCC_CR_offset   (0x00)
#define RCC_CR          ((volatile uint32_t *)(RCC + RCC_CR_offset))

#define RCC_CFGR_offset (0x04)
#define RCC_CFGR        ((volatile uint32_t *)(RCC + RCC_CFGR_offset))

#define RCC_APB2ENR_offset  (0x18)
#define RCC_APB2ENR         ((volatile uint32_t *)(RCC + RCC_APB2ENR_offset))

#define RCC_APB1ENR_offset  (0x1C)
#define RCC_APB1ENR         ((volatile uint32_t *)(RCC + RCC_APB1ENR_offset))

#define RCC_CFGR2_offset    (0x2C)
#define RCC_CFGR2           ((volatile uint32_t *)(RCC + RCC_CFGR2_offset))

#define HSI_ON (1u<<0)
#define HSE_ON (1u<<16)
#define PLL_ON (1u<<24)

#define HSI_RDY_FLAG (1u<<1)
#define HSE_RDY_FLAG (1u<<17)
#define PLL_RDY_FLAG (1u<<25)

#define HSI_RDY (*RCC_CR & HSI_RDY_FLAG)
#define HSE_RDY (*RCC_CR & HSE_RDY_FLAG)
#define PLL_RDY (*RCC_CR & PLL_RDY_FLAG)

#define HSI_SYSCLK (0b00)
#define HSE_SYSCLK (0b01)
#define PLL_SYSCLK (0b10)

#define SYSCLK_RDY_FLAG (0b11<<2)

#define AHB_CLK_NOT_DIVIDE  	(0B0000<<4)
#define APB1_CLK_NOT_DIVIDE 	(0B000<<8)
#define APB2_CLK_NOT_DIVIDE 	(0B000<<11)
#define ADCPRE_DVD2 					(0b00 << 14)

#define UART1_EN    (1u<<14)
#define SPI1_EN     (1u<<12)
#define ADC1_EN     (1U<<9)
#define PORTC_EN    (1U<<4)
#define PORTB_EN    (1U<<3)
#define PORTA_EN    (1U<<2)
#define AFIO_EN     (1U<<0)

#define I2C_EN 		(1u<<21)
#define CAN_EN		(1u<<25)

#define RCC_CR_RST  (0x00000083)

void reset_clock();

#endif /* RCC_H_ */
