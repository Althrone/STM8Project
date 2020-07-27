/****************************************************************************
 * memory_map.h
 * 按照芯片数据手册进行各类宏定义
 ****************************************************************************/

#ifndef _MEMORY_MAPE_H_
#define _MEMORY_MAPE_H_

#include "../../../include/config.h"

#define RAM_BASE	0x00000000 /**/



#define PA_ODR *(volatile uint8_t *)0x5000
#define PA_IDR *(volatile uint8_t *)0x5001
#define PA_DDR *(volatile uint8_t *)0x5002
#define PA_CR1 *(volatile uint8_t *)0x5003
#define PA_CR2 *(volatile uint8_t *)0x5004


#define PB_ODR *(volatile uint8_t *)0x5005
#define PB_IDR *(volatile uint8_t *)0x5006
#define PB_DDR *(volatile uint8_t *)0x5007
#define PB_CR1 *(volatile uint8_t *)0x5008
#define PB_CR2 *(volatile uint8_t *)0x5009

#define PC_ODR *(volatile uint8_t *)0x500A
#define PC_IDR *(volatile uint8_t *)0x500B
#define PC_DDR *(volatile uint8_t *)0x500C
#define PC_CR1 *(volatile uint8_t *)0x500D
#define PC_CR2 *(volatile uint8_t *)0x500E

#define PD_ODR *(volatile uint8_t *)0x500F
#define PD_IDR *(volatile uint8_t *)0x5010
#define PD_DDR *(volatile uint8_t *)0x5011
#define PD_CR1 *(volatile uint8_t *)0x5012
#define PD_CR2 *(volatile uint8_t *)0x5013

#define PE_ODR *(volatile uint8_t *)0x5014
#define PE_IDR *(volatile uint8_t *)0x5015
#define PE_DDR *(volatile uint8_t *)0x5016
#define PE_CR1 *(volatile uint8_t *)0x5017
#define PE_CR2 *(volatile uint8_t *)0x5018

#define PF_ODR *(volatile uint8_t *)0x5019
#define PF_IDR *(volatile uint8_t *)0x501A
#define PF_DDR *(volatile uint8_t *)0x501B
#define PF_CR1 *(volatile uint8_t *)0x501C
#define PF_CR2 *(volatile uint8_t *)0x501D



#endif /*_MEMORY_MAPE_H_*/