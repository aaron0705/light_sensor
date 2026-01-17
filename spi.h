/*
 * spi.h
 *
 *  Created on: Jan 13, 2026
 *      Author: atran
 */

#ifndef SPI_H_
#define SPI_H_

#include "base.h"
#include <stdint.h>

#define SPI_CR1_offset (0x00)
#define SPI_CR1 ((volatile uint32_t *)(SPI1 + SPI_CR1_offset))

#define SPI_CR2_offset (0x04)
#define SPI_CR2 ((volatile uint32_t *)(SPI1 + SPI_CR2_offset))

#define SPI_SR_offset (0x08)
#define SPI_SR ((volatile uint32_t *)(SPI1 + SPI_SR_offset))

#define SPI_DR_offset (0x0C)
#define SPI_DR ((volatile uint32_t *)(SPI1 + SPI_DR_offset))

#define BR
#define CPOL	(1u<<1)
#define CPHA	(1u<<0)
#define DFF 		(1u<<11)
#define LSBFIRST	(1u<<7)
#define SSOE	(1u<<2)
#define MSTR	(1u<<2)
#define SPE		(1u<<6)

#define fPCLKDVD2 		0b000
#define fPCLKDVD4 		0b001
#define fPCLKDVD8 		0b010
#define fPCLKDVD16 		0b011
#define fPCLKDVD32 		0b100
#define fPCLKDVD64 		0b101
#define fPCLKDVD128 	0b110
#define fPCLKDVD256 	0b111

#define DFF8		0
#define DFF16	1

#define SSI 		(1u<<8)
#define SSM		(1u<<9)

#define BSY 		(1u<<7)

#define SPI_TXE		(*SPI_SR & (1u<<1))
#define RXNE	(*SPI_SR & (1u<<0))

void spi_init(uint8_t mode, uint8_t baudrate, uint8_t data_format);

void spi_transmit(uint8_t data);

#endif /* SPI_H_ */
