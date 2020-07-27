#ifndef _GPIO_H_
#define _GPIO_H_

#include "./memory_map.h"

#define PX_ODR_OFFSET	0x0000
#define PX_IDR_OFFSET	0x0001
#define PX_DDR_OFFSET	0x0002
#define PX_CR1_OFFSET	0x0003
#define PX_CR2_OFFSET	0x0004

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
#define P_ODR *(volatile uint8_t *)(P_BASE+PX_ODR_OFFSET)
#define P_IDR *(volatile uint8_t *)(P_BASE+PX_IDR_OFFSET)
#define P_DDR *(volatile uint8_t *)(P_BASE+PX_DDR_OFFSET)
#define P_CR1 *(volatile uint8_t *)(P_BASE+PX_CR1_OFFSET)
#define P_CR2 *(volatile uint8_t *)(P_BASE+PX_CR2_OFFSET)
*/