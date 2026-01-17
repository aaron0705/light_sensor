/*
 * spi.c
 *
 *  Created on: Jan 13, 2026
 *      Author: atran
 */
#include "spi.h"
#include "gpio.h"

void spi_init(uint8_t mode, uint8_t baudrate, uint8_t data_format)
{
	// Cấu hinh bit BR, CPOL, CPHA, DFF, LSBFIRST, SSOE, MSTR, SSI, SSM, SPE
	*SPI_CR1 |= baudrate;
	*SPI_CR1 |= CPOL;
	*SPI_CR1 |= CPHA;
	*SPI_CR1 &= ~LSBFIRST;
	*SPI_CR1 |= SSI | SSM;
	if (data_format == 0)
	{
		// 8 bit data frame
		*SPI_CR1 &= ~DFF;
	}
	else
	{
		// 16 bit data frame
		*SPI_CR1 |= DFF;
	}
	*SPI_CR2 |= SSOE;

	if (mode == 'M' || mode == 'm')
	{
		*SPI_CR1 |= MSTR;
	}
	else if (mode == 'S' || mode == 's')
	{
		*SPI_CR1 &= ~MSTR;
	}
	*SPI_CR1 |= SPE;
}

void spi_transmit(uint8_t data)
{
	*GPIOA_ODR &= ~GPIO4_EN;

	while (!SPI_TXE);
	*SPI_DR = data;

	while (BSY);
	*GPIOA_ODR |= GPIO4_EN;
}

