/*
 * adc.h
 *
 *  Created on: Jan 9, 2026
 *      Author: atran
 */
#ifndef ADC_H_
#define ADC_H_

#include "base.h"
#include "stdint.h"

#define ADC_SR_offset (0x00)
#define ADC_SR ((volatile uint32_t *)(ADC1 + ADC_SR_offset))

#define ADC_CR1_offset (0x04)
#define ADC_CR1 ((volatile uint32_t *)(ADC1 + ADC_CR1_offset))
#define ADC_CR2_offset (0x08)
#define ADC_CR2 ((volatile uint32_t *)(ADC1 + ADC_CR2_offset))

#define ADC_SQR1_offset (0x2c)
#define ADC_SQR1 ((volatile uint32_t *)(ADC1 + ADC_SQR1_offset))
#define ADC_SQR2_offset (0x30)
#define ADC_SQR2 ((volatile uint32_t *)(ADC1 + ADC_SQR2_offset))
#define ADC_SQR3_offset (0x34)
#define ADC_SQR3 ((volatile uint32_t *)(ADC1 + ADC_SQR3_offset))

#define ADC_SMPR2_offset (0x10)
#define ADC_SMPR2 ((volatile uint32_t *)(ADC1 + ADC_SMPR2_offset))

#define ADC_DR_offset (0x4C)
#define ADC_DR ((volatile uint32_t *)(ADC1 + ADC_DR_offset))

#define ADC_EOC 		(*ADC_SR & (1u << 1))
#define ADC_ADON 	(1u << 0)
#define ADC_CONT		(1u << 1)
#define ADC_CAL		(1u << 2)
#define ADC_RSTCAL (1u << 3)
#define ADC_ALIGN		(1u << 11)
#define ADC_SWSTART		(1u << 22)
#define ADC_EOCIE		(1u << 5)
#define SWSTART		(0b111 << 17)
#define ADRST_VALUE (0x00000000)
#define  ADC_STRT		(*ADC_SR & (1u << 4))
#define ADC_SCAN (1u << 8)

void ADC_init();

uint16_t read_adc(int channel);

void ADC_Read_8Channels(uint16_t *buffer);

void ADC_Start();

#endif /* ADC_H_ */
