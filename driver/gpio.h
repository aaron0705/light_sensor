/*
 * gpio.h
 *
 *  Created on: Dec 17, 2025
 *      Author: atran
 */

#ifndef GPIO_H_
#define GPIO_H_

#include "base.h"
#include <stdint.h>

// GPIOA
#define GPIOA_CRL_OFFSET    (0x00)
#define GPIOA_CRL           ((volatile uint32_t *)(PortA + GPIOA_CRL_OFFSET))

#define GPIOA_CRH_OFFSET    (0x04)
#define GPIOA_CRH           ((volatile uint32_t *)(PortA + GPIOA_CRH_OFFSET))

#define GPIOA_IDR_OFFSET    (0x08)
#define GPIOA_IDR           ((volatile uint32_t *)(PortA + GPIOA_IDR_OFFSET))

#define GPIOA_ODR_OFFSET    (0x0C)
#define GPIOA_ODR           ((volatile uint32_t *)(PortA + GPIOA_ODR_OFFSET))

// GPIOC
#define GPIOB_CRL_OFFSET    (0x00)
#define GPIOB_CRL           ((volatile uint32_t *)(PortB + GPIOB_CRL_OFFSET))

#define GPIOB_CRH_OFFSET    (0x04)
#define GPIOB_CRH           ((volatile uint32_t *)(PortB + GPIOB_CRH_OFFSET))

#define GPIOB_IDR_OFFSET    (0x08)
#define GPIOB_IDR           ((volatile uint32_t *)(PortB + GPIOB_IDR_OFFSET))

#define GPIOB_ODR_OFFSET    (0x0C)
#define GPIOB_ODR           ((volatile uint32_t *)(PortB + GPIOB_ODR_OFFSET))

// GPIOC
#define GPIOC_CRL_OFFSET    (0x00)
#define GPIOC_CRL           ((volatile uint32_t *)(PortC + GPIOC_CRL_OFFSET))

#define GPIOC_CRH_OFFSET    (0x04)
#define GPIOC_CRH           ((volatile uint32_t *)(PortC + GPIOC_CRH_OFFSET))

#define GPIOC_IDR_OFFSET    (0x08)
#define GPIOC_IDR           ((volatile uint32_t *)(PortC + GPIOC_IDR_OFFSET))

#define GPIOC_ODR_OFFSET    (0x0C)
#define GPIOC_ODR           ((volatile uint32_t *)(PortC + GPIOC_ODR_OFFSET))

#define AFIO_MAPR_offset (0x04)
#define AFIO_MAPR 			((volatile uint32_t *)(AFIO + AFIO_MAPR_offset))

/* MODEy[1:0] */
#define GPIO_MODE_INPUT         0x0U  // Input mode
#define GPIO_MODE_OUTPUT_10MHZ  0x1U  // Output mode, max speed 10 MHz
#define GPIO_MODE_OUTPUT_2MHZ   0x2U  // Output mode, max speed 2 MHz
#define GPIO_MODE_OUTPUT_50MHZ  0x3U  // Output mode, max speed 50 MHz

/* CNFy[1:0] khi MODE = Input */
#define GPIO_CNF_INPUT_ANALOG      0x0U  // Analog mode
#define GPIO_CNF_INPUT_FLOATING    0x1U  // Floating input
#define GPIO_CNF_INPUT_PUPD        0x2U  // Input with pull-up/pull-down

/* CNFy[1:0] khi MODE = Output */
#define GPIO_CNF_OUTPUT_PP         0x0U  // General purpose output push-pull
#define GPIO_CNF_OUTPUT_OD         0x1U  // General purpose output open-drain
#define GPIO_CNF_OUTPUT_AF_PP      0x2U  // Alternate function output push-pull
#define GPIO_CNF_OUTPUT_AF_OD      0x3U  // Alternate function output open-drain

#define MODE0   0
#define CNF0    2

#define MODE1   4
#define CNF1    6

#define MODE2   8
#define CNF2    10

#define MODE3   12
#define CNF3    14

#define MODE4   16
#define CNF4    18

#define MODE5   20
#define CNF5    22

#define MODE6   24
#define CNF6    26

#define MODE7   28
#define CNF7    30

#define MODE8   0
#define CNF8    2

#define MODE9   4
#define CNF9    6

#define MODE10  8
#define CNF10   10

#define MODE11  12
#define CNF11   14

#define MODE12  16
#define CNF12   18

#define MODE13  20
#define CNF13   22

#define MODE14  24
#define CNF14   26

#define MODE15  28
#define CNF15   30

#define GPIO0_EN   ((uint32_t)0x00000001)  // Bit 0: Output enable cho pin 0
#define GPIO1_EN   ((uint32_t)0x00000002)  // Bit 1: Output enable cho pin 1
#define GPIO2_EN   ((uint32_t)0x00000004)  // Bit 2: Output enable cho pin 2
#define GPIO3_EN   ((uint32_t)0x00000008)  // Bit 3: Output enable cho pin 3
#define GPIO4_EN   ((uint32_t)0x00000010)  // Bit 4: Output enable cho pin 4
#define GPIO5_EN   ((uint32_t)0x00000020)  // Bit 5: Output enable cho pin 5
#define GPIO6_EN   ((uint32_t)0x00000040)  // Bit 6: Output enable cho pin 6
#define GPIO7_EN   ((uint32_t)0x00000080)  // Bit 7: Output enable cho pin 7
#define GPIO8_EN   ((uint32_t)0x00000100)  // Bit 8: Output enable cho pin 8
#define GPIO9_EN   ((uint32_t)0x00000200)  // Bit 9: Output enable cho pin 9
#define GPIO10_EN  ((uint32_t)0x00000400)  // Bit 10: Output enable cho pin 10
#define GPIO11_EN  ((uint32_t)0x00000800)  // Bit 11: Output enable cho pin 11
#define GPIO12_EN  ((uint32_t)0x00001000)  // Bit 12: Output enable cho pin 12
#define GPIO13_EN  ((uint32_t)0x00002000)  // Bit 13: Output enable cho pin 13
#define GPIO14_EN  ((uint32_t)0x00004000)  // Bit 14: Output enable cho pin 14
#define GPIO15_EN  ((uint32_t)0x00008000)  // Bit 15: Output enable cho pin 15

#define GPIO_CR_RST (0x44444444)

void reset_gpioa();
void reset_gpiob();
void reset_gpioc();
void reset_gpio();

#endif /* GPIO_H_ */
