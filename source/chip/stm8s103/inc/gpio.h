#ifndef _GPIO_H_
#define _GPIO_H_

#include "./memory_map.h"

//寄存器偏移地址
#define PX_ODR_OFFSET   0x0000
#define PX_IDR_OFFSET   0x0001
#define PX_DDR_OFFSET   0x0002
#define PX_CR1_OFFSET   0x0003
#define PX_CR2_OFFSET   0x0004

//寄存器操作
#define PX_ODR_ODR0     (1<<0)
#define PX_ODR_ODR1     (1<<1)
#define PX_ODR_ODR2     (1<<2)
#define PX_ODR_ODR3     (1<<3)
#define PX_ODR_ODR4     (1<<4)
#define PX_ODR_ODR5     (1<<5)
#define PX_ODR_ODR6     (1<<6)
#define PX_ODR_ODR7     (1<<7)

#define PX_IDR_IDR0     (1<<0)
#define PX_IDR_IDR1     (1<<1)
#define PX_IDR_IDR2     (1<<2)
#define PX_IDR_IDR3     (1<<3)
#define PX_IDR_IDR4     (1<<4)
#define PX_IDR_IDR5     (1<<5)
#define PX_IDR_IDR6     (1<<6)
#define PX_IDR_IDR7     (1<<7)

#define PX_DDR_DDR0     (1<<0)
#define PX_DDR_DDR1     (1<<1)
#define PX_DDR_DDR2     (1<<2)
#define PX_DDR_DDR3     (1<<3)
#define PX_DDR_DDR4     (1<<4)
#define PX_DDR_DDR5     (1<<5)
#define PX_DDR_DDR6     (1<<6)
#define PX_DDR_DDR7     (1<<7)

#define PX_CR1_C10      (1<<0)
#define PX_CR1_C11      (1<<1)
#define PX_CR1_C12      (1<<2)
#define PX_CR1_C13      (1<<3)
#define PX_CR1_C14      (1<<4)
#define PX_CR1_C15      (1<<5)
#define PX_CR1_C16      (1<<6)
#define PX_CR1_C17      (1<<7)

#define PX_CR2_C20      (1<<0)
#define PX_CR2_C21      (1<<1)
#define PX_CR2_C22      (1<<2)
#define PX_CR2_C23      (1<<3)
#define PX_CR2_C24      (1<<4)
#define PX_CR2_C25      (1<<5)
#define PX_CR2_C26      (1<<6)
#define PX_CR2_C27      (1<<7)

//寄存器基地址+偏移地址
#define PA_ODR *(volatile uint8_t *)(PA_BASE+PX_ODR_OFFSET)
#define PA_IDR *(volatile uint8_t *)(PA_BASE+PX_IDR_OFFSET)
#define PA_DDR *(volatile uint8_t *)(PA_BASE+PX_DDR_OFFSET)
#define PA_CR1 *(volatile uint8_t *)(PA_BASE+PX_CR1_OFFSET)
#define PA_CR2 *(volatile uint8_t *)(PA_BASE+PX_CR2_OFFSET)

#define PB_ODR *(volatile uint8_t *)(PB_BASE+PX_ODR_OFFSET)
#define PB_IDR *(volatile uint8_t *)(PB_BASE+PX_IDR_OFFSET)
#define PB_DDR *(volatile uint8_t *)(PB_BASE+PX_DDR_OFFSET)
#define PB_CR1 *(volatile uint8_t *)(PB_BASE+PX_CR1_OFFSET)
#define PB_CR2 *(volatile uint8_t *)(PB_BASE+PX_CR2_OFFSET)

#define PC_ODR *(volatile uint8_t *)(PC_BASE+PX_ODR_OFFSET)
#define PC_IDR *(volatile uint8_t *)(PC_BASE+PX_IDR_OFFSET)
#define PC_DDR *(volatile uint8_t *)(PC_BASE+PX_DDR_OFFSET)
#define PC_CR1 *(volatile uint8_t *)(PC_BASE+PX_CR1_OFFSET)
#define PC_CR2 *(volatile uint8_t *)(PC_BASE+PX_CR2_OFFSET)

#define PD_ODR *(volatile uint8_t *)(PD_BASE+PX_ODR_OFFSET)
#define PD_IDR *(volatile uint8_t *)(PD_BASE+PX_IDR_OFFSET)
#define PD_DDR *(volatile uint8_t *)(PD_BASE+PX_DDR_OFFSET)
#define PD_CR1 *(volatile uint8_t *)(PD_BASE+PX_CR1_OFFSET)
#define PD_CR2 *(volatile uint8_t *)(PD_BASE+PX_CR2_OFFSET)

#define PE_ODR *(volatile uint8_t *)(PE_BASE+PX_ODR_OFFSET)
#define PE_IDR *(volatile uint8_t *)(PE_BASE+PX_IDR_OFFSET)
#define PE_DDR *(volatile uint8_t *)(PE_BASE+PX_DDR_OFFSET)
#define PE_CR1 *(volatile uint8_t *)(PE_BASE+PX_CR1_OFFSET)
#define PE_CR2 *(volatile uint8_t *)(PE_BASE+PX_CR2_OFFSET)

#define PF_ODR *(volatile uint8_t *)(PF_BASE+PX_ODR_OFFSET)
#define PF_IDR *(volatile uint8_t *)(PF_BASE+PX_IDR_OFFSET)
#define PF_DDR *(volatile uint8_t *)(PF_BASE+PX_DDR_OFFSET)
#define PF_CR1 *(volatile uint8_t *)(PF_BASE+PX_CR1_OFFSET)
#define PF_CR2 *(volatile uint8_t *)(PF_BASE+PX_CR2_OFFSET)

#endif /*_GPIO_H_*/

/*用于批量修改
#define PX_DR_DR0       (1<<0)
#define PX_DR_DR1       (1<<1)
#define PX_DR_DR2       (1<<2)
#define PX_DR_DR3       (1<<3)
#define PX_DR_DR4       (1<<4)
#define PX_DR_DR5       (1<<5)
#define PX_DR_DR6       (1<<6)
#define PX_DR_DR7       (1<<7)

#define PX_CR_C         (1<<0)
#define PX_CR_C         (1<<1)
#define PX_CR_C         (1<<2)
#define PX_CR_C         (1<<3)
#define PX_CR_C         (1<<4)
#define PX_CR_C         (1<<5)
#define PX_CR_C         (1<<6)
#define PX_CR_C         (1<<7)

#define P_ODR *(volatile uint8_t *)(P_BASE+PX_ODR_OFFSET)
#define P_IDR *(volatile uint8_t *)(P_BASE+PX_IDR_OFFSET)
#define P_DDR *(volatile uint8_t *)(P_BASE+PX_DDR_OFFSET)
#define P_CR1 *(volatile uint8_t *)(P_BASE+PX_CR1_OFFSET)
#define P_CR2 *(volatile uint8_t *)(P_BASE+PX_CR2_OFFSET)
*/