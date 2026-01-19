/*
 * uart.h
 *
 *  Created on: Jan 16, 2026
 *      Author: atran
 */

#ifndef UART_H_
#define UART_H_

#include "base.h"
#include <stdint.h>

#define USART_SR_offset (0x00)
#define USART_SR ((volatile uint32_t *)(UART1 + USART_SR_offset))

#define USART_DR_offset (0x04)
#define USART_DR ((volatile uint32_t *)(UART1 + USART_DR_offset))

#define USART_BRR_offset (0x08)
#define USART_BRR ((volatile uint32_t *)(UART1 + USART_BRR_offset))

#define USART_CR1_offset (0x0C)
#define USART_CR1 ((volatile uint32_t *)(UART1 + USART_CR1_offset))

#define USART_CR2_offset (0x10)
#define USART_CR2 ((volatile uint32_t *)(UART1 + USART_CR2_offset))

#define USART_CR3_offset (0x14)
#define USART_CR3 ((volatile uint32_t *)(UART1 + USART_CR3_offset))

#define USART_GTPR_offset (0x18)
#define USART_GTPR ((volatile uint32_t *)(UART1 + USART_GTPR_offset))

#define UE 					(1u<<13)
#define TE 						(1u<<3)
#define RE 					(1u<<2)
#define UART_RXNE 	(*USART_SR & (1u<<5))
#define UART_TXE 		(*USART_SR & (1u<<7))
#define TC 					(*USART_SR & (1u<<6))
#define IDLE 					(1u<<4)
#define eight_data_bits 0
#define nine_data_bits 1

#define ORE	(*USART_SR & (1u<<3))
#define NE		(*USART_SR & (1u<<2))
#define FE		(*USART_SR & (1u<<1))
#define PE		(*USART_SR & (1u<<0))

#define USART_SR_RST (0x00C0)
#define USART_RST 	(0x0000)

void uart_init(uint32_t baudrate, uint8_t word_length, uint8_t num_stop_bit);
void uart_transmit(uint8_t data);
void uart_reset();

#endif /* UART_H_ */
