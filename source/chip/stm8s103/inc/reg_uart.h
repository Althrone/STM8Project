#ifndef _UARTX_H_
#define _UARTX_H_

#include "./memory_map.h"

//寄存器偏移地址
#define UARTX_SR_OFFSET         0x0000
#define UARTX_DR_OFFSET         0x0001
#define UARTX_BRR1_OFFSET       0x0002
#define UARTX_BRR2_OFFSET       0x0003
#define UARTX_CR1_OFFSET        0x0004
#define UARTX_CR2_OFFSET        0x0005
#define UARTX_CR3_OFFSET        0x0006
#define UARTX_CR4_OFFSET        0x0007
#define UARTX_CR5_OFFSET        0x0008
#define UARTX_GTR_OFFSET        0x0009
#define UARTX_PSCR_OFFSET       0x000A

//寄存器操作
#define UARTX_SR_PE             (1<<0)
#define UARTX_SR_FE             (1<<1)
#define UARTX_SR_NF             (1<<2)
#define UARTX_SR_OR             (1<<3)
#define UARTX_SR_IDLE           (1<<4)
#define UARTX_SR_RXNE           (1<<5)
#define UARTX_SR_TC             (1<<6)
#define UARTX_SR_TXE            (1<<7)

#define UARTX_DR_DR_SHIFT       (0)
#define UARTX_DR_DR_MASK        (0xFF<<UARTX_DR_DR_SHIFT)
    #define UARTX_DR_DR_(n)     ((n)<<UARTX_DR_DR_SHIFT)

#define UARTX_BRR1_DIV_SHIFT    (0)
#define UARTX_BRR1_DIV_MASK     (0xFF<<UARTX_BRR1_DIV_SHIFT)
    #define UARTX_BRR1_DIV_(n)  ((n)<<UARTX_BRR1_DIV_SHIFT)

#define UARTX_BRR2_LSB_SHIFT    (0)
#define UARTX_BRR2_LSB_MASK     (0xF<<UARTX_BRR2_LSB_SHIFT)
    #define UARTX_BRR2_LSB_(n)  ((n)<<UARTX_BRR2_LSB_SHIFT)
#define UARTX_BRR2_MSB_SHIFT    (4)
#define UARTX_BRR2_MSB_MASK     (0xF<<UARTX_BRR2_MSB_SHIFT)
    #define UARTX_BRR2_MSB_(n)  ((n)<<UARTX_BRR2_MSB_SHIFT)

#define UARTX_CR1_PIEN          (1<<0)
#define UARTX_CR1_PS            (1<<1)
#define UARTX_CR1_PCEN          (1<<2)
#define UARTX_CR1_WAKE          (1<<3)
#define UARTX_CR1_M             (1<<4)
#define UARTX_CR1_UARTD         (1<<5)
#define UARTX_CR1_T8            (1<<6)
#define UARTX_CR1_R8            (1<<7)

#define UARTX_CR2_SBK           (1<<0)
#define UARTX_CR2_RWU           (1<<1)
#define UARTX_CR2_REN           (1<<2)
#define UARTX_CR2_TEN           (1<<3)
#define UARTX_CR2_ILIEN         (1<<4)
#define UARTX_CR2_RIEN          (1<<5)
#define UARTX_CR2_TCIEN         (1<<6)
#define UARTX_CR2_TIEN          (1<<7)

#define UARTX_CR3_LBCL          (1<<0)
#define UARTX_CR3_CPHA          (1<<1)
#define UARTX_CR3_CPOL          (1<<2)
#define UARTX_CR3_CLKEN         (1<<3)
#define UARTX_CR3_STOP_SHIFT    (4)
#define UARTX_CR3_STOP_MASK     (0x3<<UARTX_CR3_STOP_SHIFT)
    #define UARTX_CR3_STOP_1    (0x0<<UARTX_CR3_STOP_SHIFT)
  //#define UARTX_CR3_STOP_Res  (0x1<<UARTX_CR3_STOP_SHIFT)
    #define UARTX_CR3_STOP_2    (0x2<<UARTX_CR3_STOP_SHIFT)
    #define UARTX_CR3_STOP_1P5  (0x3<<UARTX_CR3_STOP_SHIFT)
#define UARTX_CR3_LINEN         (1<<6)
//#define UARTX_CR3_Res         (1<<7)

#define UARTX_CR4_ADD_SHIFT     (0)
#define UARTX_CR4_ADD_MASK      (0xF<<UARTX_CR4_ADD_SHIFT)
    #define UARTX_CR4_ADD_(n)   ((n)<<UARTX_CR4_ADD_SHIFT)
#define UARTX_CR4_LBDF          (1<<4)
#define UARTX_CR4_LBDL          (1<<5)
#define UARTX_CR4_LBDIEN        (1<<6)
//#define UARTX_CR4_Res         (1<<7)

//#define UARTX_CR5_Res         (1<<0)
#define UARTX_CR5_IREN          (1<<1)
#define UARTX_CR5_IRLP          (1<<2)
#define UARTX_CR5_HDSEL         (1<<3)
#define UARTX_CR5_NACK          (1<<4)
#define UARTX_CR5_SCEN          (1<<5)
//#define UARTX_CR5_Res         (1<<6)
//#define UARTX_CR5_Res         (1<<7)

#define UARTX_GTR_GT_SHIFT      (0)
#define UARTX_GTR_GT_MASK       (0xFF<<UARTX_GTR_GT_SHIFT)
    #define UARTX_GTR_GT_(n)    ((n)<<UARTX_GTR_GT_SHIFT)

#define UARTX_PSCR_PSC_SHIFT    (0)
#define UARTX_PSCR_PSC_MASK     (0xFF<<UARTX_PSCR_PSC_SHIFT)
    #define UARTX_PSCR_PSC_(n)  ((n)<<UARTX_PSCR_PSC_SHIFT)

//寄存器基地址+偏移地址
#define UART1_SR    *(volatile uint8_t *)(UART1_BASE+UARTX_SR_OFFSET)
#define UART1_DR    *(volatile uint8_t *)(UART1_BASE+UARTX_DR_OFFSET)
#define UART1_BRR1  *(volatile uint8_t *)(UART1_BASE+UARTX_BRR1_OFFSET)
#define UART1_BRR2  *(volatile uint8_t *)(UART1_BASE+UARTX_BRR2_OFFSET)
#define UART1_CR1   *(volatile uint8_t *)(UART1_BASE+UARTX_CR1_OFFSET)
#define UART1_CR2   *(volatile uint8_t *)(UART1_BASE+UARTX_CR2_OFFSET)
#define UART1_CR3   *(volatile uint8_t *)(UART1_BASE+UARTX_CR3_OFFSET)
#define UART1_CR4   *(volatile uint8_t *)(UART1_BASE+UARTX_CR4_OFFSET)
#define UART1_CR5   *(volatile uint8_t *)(UART1_BASE+UARTX_CR5_OFFSET)
#define UART1_GTR   *(volatile uint8_t *)(UART1_BASE+UARTX_GTR_OFFSET)
#define UART1_PSCR  *(volatile uint8_t *)(UART1_BASE+UARTX_PSCR_OFFSET)

#endif /*_UARTX_H_*/

/*用于批量修改
#define UARTX_(1<<)

#define UART_SR    *(volatile uint8_t *)(UART_BASE+UARTX_SR_OFFSET)
#define UART_DR    *(volatile uint8_t *)(UART_BASE+UARTX_DR_OFFSET)
#define UART_BRR1  *(volatile uint8_t *)(UART_BASE+UARTX_BRR1_OFFSET)
#define UART_BRR2  *(volatile uint8_t *)(UART_BASE+UARTX_BRR2_OFFSET)
#define UART_CR1   *(volatile uint8_t *)(UART_BASE+UARTX_CR1_OFFSET)
#define UART_CR2   *(volatile uint8_t *)(UART_BASE+UARTX_CR2_OFFSET)
#define UART_CR3   *(volatile uint8_t *)(UART_BASE+UARTX_CR3_OFFSET)
#define UART_CR4   *(volatile uint8_t *)(UART_BASE+UARTX_CR4_OFFSET)
#define UART_CR5   *(volatile uint8_t *)(UART_BASE+UARTX_CR5_OFFSET)
#define UART_GTR   *(volatile uint8_t *)(UART_BASE+UARTX_GTR_OFFSET)
#define UART_PSCR  *(volatile uint8_t *)(UART_BASE+UARTX_PSCR_OFFSET)
*/