/*
 * can.h
 *
 *  Created on: Jan 12, 2026
 *      Author: atran
 */

#ifndef CAN_H_
#define CAN_H_

#include "base.h"

#define CAN_MCR_offset (0x00)
#define CAN_MCR (volatile uint32_t *)(CAN + CAN_MCR_offset)

#define CAN_MSR_offset (0x04)
#define CAN_MSR (volatile uint32_t *)(CAN + CAN_MSR_offset)

#define CAN_TSR_offset (0x08)
#define CAN_TSR (volatile uint32_t *)(CAN + CAN_TSR_offset)

#define CAN_RF0R_offset (0x0C)
#define CAN_RF0R (volatile uint32_t *)(CAN + CAN_RF0R_offset)

#define CAN_RF1R_offset (0x10)
#define CAN_RF1R (volatile uint32_t *)(CAN + CAN_RF1R_offset)

#define CAN_IER_offset (0x14)
#define CAN_IER (volatile uint32_t *)(CAN + CAN_IER_offset)

#define CAN_ESR_offset (0x18)
#define CAN_ESR (volatile uint32_t *)(CAN + CAN_ESR_offset)

#define CAN_BTR_offset (0x1C)
#define CAN_BTR (volatile uint32_t *)(CAN + CAN_BTR_offset)

#define CAN_TI0R_offset (0x180)
#define CAN_TI0R (volatile uint32_t *)(CAN + CAN_TI0R_offset)

#define CAN_TI1R_offset (0x190)
#define CAN_TI1R (volatile uint32_t *)(CAN + CAN_TI1R_offset)

#define CAN_TI2R_offset (0x1A0)
#define CAN_TI2R (volatile uint32_t *)(CAN + CAN_TI2R_offset)

#define CAN_TDT0R_offset (0x184)
#define CAN_TDT0R (volatile uint32_t *)(CAN + CAN_TDT0R_offset)

#define CAN_TDT1R_offset (0x194)
#define CAN_TDT1R (volatile uint32_t *)(CAN + CAN_TDT1R_offset)

#define CAN_TDT2R_offset (0x1A4)
#define CAN_TDT2R (volatile uint32_t *)(CAN + CAN_TDT2R_offset)

#define CAN_TDL0R_offset (0x188)
#define CAN_TDL0R (volatile uint32_t *)(CAN + CAN_TDL0R_offset)

#define CAN_TDL1R_offset (0x198)
#define CAN_TDL1R (volatile uint32_t *)(CAN + CAN_TDL1R_offset)

#define CAN_TDL2R_offset (0x1A8)
#define CAN_TDL2R (volatile uint32_t *)(CAN + CAN_TDL2R_offset)

#define CAN_TDH0R_offset (0x18C)
#define CAN_TDH0R (volatile uint32_t *)(CAN + CAN_TDH0R_offset)

#define CAN_TDH1R_offset (0x19C)
#define CAN_TDH1R (volatile uint32_t *)(CAN + CAN_TDH1R_offset)

#define CAN_TDH2R_offset (0x1AC)
#define CAN_TDH2R (volatile uint32_t *)(CAN + CAN_TDH2R_offset)

#define CAN_RI0R_offset (0x1B0)
#define CAN_RI0R (volatile uint32_t *)(CAN + CAN_RI0R_offset)

#define CAN_RI1R_offset (0x1C0)
#define CAN_RI1R (volatile uint32_t *)(CAN + CAN_RI1R_offset)

#define CAN_RDT0R_offset (0x1B4)
#define CAN_RDT0R (volatile uint32_t *)(CAN + CAN_RDT0R_offset)

#define CAN_RDT1R_offset (0x1C4)
#define CAN_RDT1R (volatile uint32_t *)(CAN + CAN_RDT1R_offset)

#define CAN_RDL0R_offset (0x1B8)
#define CAN_RDL0R (volatile uint32_t *)(CAN + CAN_RDT0L_offset)

#define CAN_RDL1R_offset (0x1C8)
#define CAN_RDL1R (volatile uint32_t *)(CAN + CAN_RDL1R_offset)

#define CAN_RDH0R_offset (0x1BC)
#define CAN_RDH0R (volatile uint32_t *)(CAN + CAN_RDH0L_offset)

#define CAN_RDH1R_offset (0x1CC)
#define CAN_RDH1R (volatile uint32_t *)(CAN + CAN_RDH1R_offset)

#define CAN_FMR_offset (0x200)
#define CAN_FMR (volatile uint32_t *)(CAN + CAN_FMR_offset)

#define CAN_FM1R_offset (0x204)
#define CAN_FM1R (volatile uint32_t *)(CAN + CAN_FM1R_offset)

#define CAN_FS1R_offset (0x20C)
#define CAN_FS1R (volatile uint32_t *)(CAN + CAN_FS1R_offset)

#define CAN_FFA1R_offset (0x214)
#define CAN_FFA1R (volatile uint32_t *)(CAN + CAN_FFA1R_offset)

#define CAN_FA1R_offset (0x21C)
#define CAN_FA1R (volatile uint32_t *)(CAN + CAN_FA1R_offset)

// CAN_MCR
#define CAN_MCR_DBF     (1u << 16)

// Bit 15: Software Master Reset (Reset phần mềm)
#define CAN_MCR_RESET   (1u << 15)

// Bit 7: Time Triggered Communication Mode (Kích hoạt theo thời gian)
#define CAN_MCR_TTCM    (1u << 7)

// Bit 6: Automatic Bus-Off Management (Tự động thoát lỗi Bus-Off)
#define CAN_MCR_ABOM    (1u << 6)

// Bit 5: Automatic Wakeup Mode (Tự động thức dậy khi có tin nhắn)
#define CAN_MCR_AWUM    (1u << 5)

// Bit 4: No Automatic Retransmission (Không tự động gửi lại tin nhắn - Single Shot)
#define CAN_MCR_NART    (1u << 4)

// Bit 3: Transmit FIFO Priority (Thứ tự ưu tiên FIFO gửi: 0=ID, 1=Request Order)
#define CAN_MCR_TXFP    (1u << 3)

// Bit 2: Sleep Mode Request (Yêu cầu ngủ: 0=Wakeup, 1=Sleep)
#define CAN_MCR_SLEEP   (1u << 2)

// Bit 1: Initialization Request (Yêu cầu khởi tạo: 0=Normal, 1=Init)
#define CAN_MCR_INRQ    (1u << 1)
// CAN_MSR
/* --- CAN Master Status Register (CAN_MSR) Bits --- */

// Bit 11: RX - CAN Rx Signal (Giám sát mức logic thực tế trên chân CAN_RX)
#define CAN_MSR_RX      (*CAN_MSR & (1u << 11))

// Bit 10: SAMP - Last Sample Point (Giá trị mẫu bit cuối cùng nhận được)
#define CAN_MSR_SAMP    (*CAN_MSR & (1u << 10))

// Bit 9: RXM - Receive Mode (Phần cứng đang ở chế độ Nhận)
#define CAN_MSR_RXM     (*CAN_MSR & (1u << 9))

// Bit 8: TXM - Transmit Mode (Phần cứng đang ở chế độ Gửi)
#define CAN_MSR_TXM     (*CAN_MSR & (1u << 8))

// Bit 4: SLAKI - Sleep Acknowledge Interrupt (Cờ ngắt báo đã vào chế độ ngủ)
#define CAN_MSR_SLAKI   (*CAN_MSR & (1u << 4))

// Bit 3: WKUI - Wakeup Interrupt (Cờ ngắt báo đã thức dậy do phát hiện bit SOF)
#define CAN_MSR_WKUI    (*CAN_MSR & (1u << 3))

// Bit 2: ERRI - Error Interrupt (Cờ ngắt báo lỗi, set khi có lỗi trong CAN_ESR)
#define CAN_MSR_ERRI    (*CAN_MSR & (1u << 2))

// Bit 1: SLAK - Sleep Acknowledge (Báo trạng thái đã thực sự vào chế độ ngủ)
#define CAN_MSR_SLAK    (*CAN_MSR & (1u << 1))

// Bit 0: INAK - Initialization Acknowledge (Báo trạng thái đã thực sự vào chế độ khởi tạo)
#define CAN_MSR_INAK    (*CAN_MSR & (1u << 0))

// Bit 31: LOW2 - Lowest Priority Flag Mailbox 2 (Cờ báo Mailbox 2 có ưu tiên thấp nhất)
#define CAN_TSR_LOW2    (*CAN_TSR & (1u << 31))

// Bit 28: TME2 - Transmit Mailbox 2 Empty (Mailbox 2 trống, sẵn sàng nhận dữ liệu mới)
#define CAN_TSR_TME2    (*CAN_TSR & (1u << 28))

// Bit 23: ABRQ2 - Abort Request Mailbox 2 (Trạng thái yêu cầu hủy gửi Mailbox 2)
#define CAN_TSR_ABRQ2   (*CAN_TSR & (1u << 23))

// Bit 19: TERR2 - Transmission Error Mailbox 2 (Lỗi truyền Mailbox 2)
#define CAN_TSR_TERR2   (*CAN_TSR & (1u << 19))

// Bit 18: ALST2 - Arbitration Lost Mailbox 2 (Mất quyền ưu tiên Mailbox 2)
#define CAN_TSR_ALST2   (*CAN_TSR & (1u << 18))

// Bit 17: TXOK2 - Transmission OK Mailbox 2 (Truyền thành công Mailbox 2)
#define CAN_TSR_TXOK2   (*CAN_TSR & (1u << 17))

// Bit 16: RQCP2 - Request Completed Mailbox 2 (Yêu cầu đã hoàn tất - Gửi xong hoặc Hủy xong)
#define CAN_TSR_RQCP2   (*CAN_TSR & (1u << 16))


/* ================== Mailbox 1 Status ================== */

// Bit 30: LOW1 - Lowest Priority Flag Mailbox 1
#define CAN_TSR_LOW1    (*CAN_TSR & (1u << 30))

// Bit 27: TME1 - Transmit Mailbox 1 Empty
#define CAN_TSR_TME1    (*CAN_TSR & (1u << 27))

// Bit 15: ABRQ1 - Abort Request Mailbox 1
#define CAN_TSR_ABRQ1   (*CAN_TSR & (1u << 15))

// Bit 11: TERR1 - Transmission Error Mailbox 1
#define CAN_TSR_TERR1   (*CAN_TSR & (1u << 11))

// Bit 10: ALST1 - Arbitration Lost Mailbox 1
#define CAN_TSR_ALST1   (*CAN_TSR & (1u << 10))

// Bit 9: TXOK1 - Transmission OK Mailbox 1
#define CAN_TSR_TXOK1   (*CAN_TSR & (1u << 9))

// Bit 8: RQCP1 - Request Completed Mailbox 1
#define CAN_TSR_RQCP1   (*CAN_TSR & (1u << 8))


/* ================== Mailbox 0 Status ================== */

// Bit 29: LOW0 - Lowest Priority Flag Mailbox 0
#define CAN_TSR_LOW0    (*CAN_TSR & (1u << 29))

// Bit 26: TME0 - Transmit Mailbox 0 Empty
#define CAN_TSR_TME0    (*CAN_TSR & (1u << 26))

// Bit 7: ABRQ0 - Abort Request Mailbox 0
#define CAN_TSR_ABRQ0   (*CAN_TSR & (1u << 7))

// Bit 3: TERR0 - Transmission Error Mailbox 0
#define CAN_TSR_TERR0   (*CAN_TSR & (1u << 3))

// Bit 2: ALST0 - Arbitration Lost Mailbox 0
#define CAN_TSR_ALST0   (*CAN_TSR & (1u << 2))

// Bit 1: TXOK0 - Transmission OK Mailbox 0
#define CAN_TSR_TXOK0   (*CAN_TSR & (1u << 1))

// Bit 0: RQCP0 - Request Completed Mailbox 0
#define CAN_TSR_RQCP0   (*CAN_TSR & (1u << 0))


/* ================== General Status ================== */

// Bits 25:24: CODE - Mailbox Code (Mã Mailbox trống tiếp theo hoặc Mailbox ưu tiên thấp nhất)
// Lưu ý: Vì đây là 2 bit liền nhau, ta dùng mask 0x3 (nhị phân 11) dịch sang trái 24 bit
#define CAN_TSR_CODE    (*CAN_TSR & (3u << 24))

//reset value
#define CAN_MCR_RST 0x00010002
#define CAN_MSR_RST 0x00000C02
#define CAN_TSR_RST 0x1C000000
#define CAN_RFR_RST 0x00000000
#define CAN_ESR_RST 0x00000000
#define CAN_BTR_RST  0x01230000
#define CAN_TIR_RST 0x11111110
#define CAN_TDTR_RST 0x00000000
#define CAN_TDLR_RST 0x00000000
#define CAN_TDHR_RST 0x00000000
#define CAN_RIR_RST 0x00000000
#define CAN_RDTR_RST 0x00000000
#define CAN_RDLR_RST 0x00000000
#define CAN_RDHR_RST 0x00000000
#define CAN_FMR_RST 0x2A1C0E01
#define CAN_FM1R_RST 0x00000000
#define CAN_FS1R_RST 0x00000000
#define CAN_FFA1R_RST 0x00000000
#define CAN_FA1R_RST 0x00000000
#define CAN_FiRx_RST 0x00000000
//
#define standard_identifier 0
#define  extended_identifier 1
#define data_frame 0
#define remote_frame 1
#define TXRQ (1u<<0)

void set_baudrate();
void CAN_init();
int get_mailbox_level();
void set_mailbox_identifier(uint8_t standard_id, uint8_t extended_id, uint8_t IDE, uint8_t RTR, uint8_t mailbox_level);
void set_data_low_register(uint32_t data, uint32_t mailbox_level);
void set_data_high_register(uint32_t data, uint32_t mailbox_level);
void CAN_transmit(uint8_t* data, uint8_t standard_id, uint8_t extended_id, uint8_t IDE, uint8_t RTR);
void CAN_reset();

#endif /* CAN_H_ */
