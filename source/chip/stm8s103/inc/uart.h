#ifndef _UART_H_
#define _UART_H_

#include "./memory_map.h"

//寄存器偏移地址
                        //
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

//寄存器基地址+偏移地址


#endif /*_UART_H_*/

/*用于批量修改

*/