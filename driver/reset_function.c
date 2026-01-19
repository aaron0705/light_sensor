/*
 * reset_function.c
 *
 *  Created on: Dec 18, 2025
 *      Author: atran
 */
#include "reset_function.h"

void reset_gpioa()
{
    *GPIOA_CRL = GPIO_CR_RST;
    *GPIOA_CRH = GPIO_CR_RST;
    *GPIOA_ODR = RST_Register;
}

void reset_gpiob()
{
    *GPIOB_CRL = GPIO_CR_RST;
    *GPIOB_CRH = GPIO_CR_RST;
    *GPIOB_ODR = RST_Register;
}

void reset_gpioc()
{
    *GPIOC_CRL = GPIO_CR_RST;
    *GPIOC_CRH = GPIO_CR_RST;
    *GPIOC_ODR = RST_Register;
}

void reset_gpio()
{
	I2C_Reset();
	reset_gpioa();
	reset_gpiob();
	reset_gpioc();
}

void reset_clock()
{
    *RCC_APB1ENR = RST_Register;
    *RCC_APB2ENR = RST_Register;
    *RCC_CFGR2   = RST_Register;
    *RCC_CFGR    = RST_Register;
    *RCC_CR      = RCC_CR_RST;
}

void reset_sys()
{
    reset_gpio();
    reset_clock();
}

