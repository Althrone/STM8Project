#ifndef _SPI_H_
#define _SPI_H_

#include "./memory_map.h"

//寄存器偏移地址
#define SPI_CR1_OFFSET      0x0000
#define SPI_CR2_OFFSET      0x0001
#define SPI_ICR_OFFSET      0x0002
#define SPI_SR_OFFSET       0x0003
#define SPI_DR_OFFSET       0x0004
#define SPI_CRCPR_OFFSET    0x0005
#define SPI_RXCRCR_OFFSET   0x0006
#define SPI_TXCRCR_OFFSET   0x0007

//寄存器操作

//寄存器基地址+偏移地址
#define SPI_CR1     *(volatile uint8_t *)(SPI_BASE+SPI_CR1_OFFSET)
#define SPI_CR2     *(volatile uint8_t *)(SPI_BASE+SPI_CR2_OFFSET)
#define SPI_ICR     *(volatile uint8_t *)(SPI_BASE+SPI_ICR_OFFSET)
#define SPI_SR      *(volatile uint8_t *)(SPI_BASE+SPI_SR_OFFSET)
#define SPI_DR      *(volatile uint8_t *)(SPI_BASE+SPI_DR_OFFSET)
#define SPI_CRCPR   *(volatile uint8_t *)(SPI_BASE+SPI_CRCPR_OFFSET)
#define SPI_RXCRCR  *(volatile uint8_t *)(SPI_BASE+SPI_RXCRCR_OFFSET)
#define SPI_TXCRCR  *(volatile uint8_t *)(SPI_BASE+SPI_TXCRCR_OFFSET)

#endif /*_SPI_H_*/

/*用于批量修改
*/