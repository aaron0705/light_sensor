/*
 * reset_function.h
 *
 *  Created on: Dec 20, 2025
 *      Author: atran
 */

#ifndef RESET_FUNCTION_H_
#define RESET_FUNCTION_H_

#include "rcc.h"
#include "gpio.h"
#include "I2C.h"

void reset_gpioa();
void reset_gpiob();
void reset_gpioc();
void reset_gpio();
void reset_clock();
void reset_sys();

#endif /* RESET_FUNCTION_H_ */
