/*
 * can.c
 *
 *  Created on: Jan 12, 2026
 *      Author: atran
 */
#include <stdint.h>
#include <stdlib.h>
#include "can.h"

void set_baudrate()
{
	*CAN_BTR = (0 << 24) | (3 << 20) | (10 << 16) | (0 << 0);
}

void CAN_init()
{
	CAN_reset();
	// sets the INRQ bit in the CAN_MCR register
	*CAN_MCR |= CAN_MCR_INRQ;
	// waits until the hardware has confirmed the request by setting the INAK bit in the CAN_MSR register
	while (!CAN_MSR_INAK);
	// end init mode clears the INRQ bit
	*CAN_MCR &= ~CAN_MCR_INRQ;
	// wait INAK bit has been cleared by hardware
	while (CAN_MSR_INAK);
}

int get_mailbox_level()
{
	for (int i = 26; i <= 28; i++)
	{
		if (*CAN_TSR & (1u << i))
		{
			return i-26;
		}
	}
	return 0;
}

void set_mailbox_identifier(uint8_t standard_id, uint8_t extended_id, uint8_t IDE, uint8_t RTR, uint8_t mailbox_level)
{
	volatile uint32_t* mailbox;
	switch (mailbox_level)
	{
	case 0:
		mailbox = CAN_TI0R;
		break;
	case 1:
		mailbox = CAN_TI1R;
		break;
	case 2:
		mailbox = CAN_TI2R;
		break;
	}
	if (IDE == standard_identifier)
	{
		*mailbox |= standard_id << 21;
	}
	else
	{
		// ex_id dài 29 bit, 11 bit đầu ở bit 31-21, còn lại từ 20-3
		*mailbox |= extended_id << 3;
	}

	if (RTR == data_frame)
	{
		*mailbox &= ~(1u<<1);
	}
	else
	{
		*mailbox |= (1u<<1);
	}
}

void set_data_low_register(uint32_t data, uint32_t mailbox_level)
{
	volatile uint32_t* mailbox;
	switch (mailbox_level)
	{
	case 0:
		mailbox = CAN_TDL0R;
		break;
	case 1:
		mailbox = CAN_TDL1R;
		break;
	case 2:
		mailbox = CAN_TDL2R;
		break;
	}
	*mailbox = 0x00000000;
	*mailbox = data;
}

void set_data_high_register(uint32_t data, uint32_t mailbox_level)
{
	volatile uint32_t* mailbox;
	switch (mailbox_level)
	{
	case 0:
		mailbox = CAN_TDH0R;
		break;
	case 1:
		mailbox = CAN_TDH1R;
		break;
	case 2:
		mailbox = CAN_TDH2R;
		break;
	}
	*mailbox = 0x00000000;
	*mailbox = data;
}

void CAN_start_transmit(uint8_t mailbox_level)
{
	volatile uint32_t* mailbox;
	switch (mailbox_level)
	{
	case 0:
		mailbox = CAN_TI0R;
		break;
	case 1:
		mailbox = CAN_TI1R;
		break;
	case 2:
		mailbox = CAN_TI2R;
		break;
	}
	*mailbox |= TXRQ;
}

void set_data_length(uint64_t length, int mailbox_level)
{
	volatile uint32_t* mailbox;
	switch (mailbox_level)
	{
		case 0:
			mailbox = CAN_TDT0R;
			break;
		case 1:
			mailbox = CAN_TDT1R;
			break;
		case 2:
			mailbox = CAN_TDT2R;
			break;
	}
	*mailbox |= length;
}

void CAN_transmit(uint8_t* data, uint8_t standard_id, uint8_t extended_id,uint8_t IDE,uint8_t RTR)
{
	int mailbox_level;
	do
	{
		mailbox_level = get_mailbox_level();
	} while (!mailbox_level);


	set_mailbox_identifier(standard_id, extended_id, IDE, RTR, mailbox_level);

	uint32_t data_low = 0;
	uint32_t data_high = 0;

	data_low |= (uint32_t)data[0] << 0;
	data_low |= (uint32_t)data[1] << 8;
	data_low |= (uint32_t)data[2] << 16;
	data_low |= (uint32_t)data[3] << 24;

	data_high |= (uint32_t)data[4] << 0;
	data_high |= (uint32_t)data[5] << 8;
	data_high |= (uint32_t)data[6] << 16;
	data_high |= (uint32_t)data[7] << 24;

	set_data_low_register(data_low, mailbox_level);
	set_data_high_register(data_high, mailbox_level);

	CAN_start_transmit(mailbox_level);
}

void CAN_reset(void)
{
    // 1. Kích hoạt Software Master Reset (Bit 15 trong MCR)
    // Việc này sẽ buộc bxCAN reset hoàn toàn trạng thái nội bộ.
    *CAN_MCR |= CAN_MCR_RESET;

    // 2. Chờ xác nhận từ phần cứng
    // Theo tài liệu STM32, bit này sẽ được phần cứng tự động xóa về 0
    // sau khi quá trình reset hoàn tất. Ta dùng vòng while để đợi.
    while ((*CAN_MCR & CAN_MCR_RESET) == CAN_MCR_RESET);

    // Lưu ý: Sau khi Master Reset, bxCAN sẽ tự động chuyển vào chế độ SLEEP.
    // Các thanh ghi sẽ trở về giá trị mặc định (như CAN_MCR_RST, CAN_MSR_RST...).
}

