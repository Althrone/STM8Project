#ifndef _SPI_H_
#define _SPI_H_

#include "./memory_map.h"

//寄存器偏移地址
#define SPI_CR1_OFFSET              0x0000
#define SPI_CR2_OFFSET              0x0001
#define SPI_ICR_OFFSET              0x0002
#define SPI_SR_OFFSET               0x0003
#define SPI_DR_OFFSET               0x0004
#define SPI_CRCPR_OFFSET            0x0005
#define SPI_RXCRCR_OFFSET           0x0006
#define SPI_TXCRCR_OFFSET           0x0007

//寄存器操作
#define SPIX_CR1_CPHA               (1<<0)
#define SPIX_CR1_CPOL               (1<<1)
#define SPIX_CR1_MSTR               (1<<2)
#define SPIX_CR1_BR_SHIFT           (3)
#define SPIX_CR1_BR_MASK            (0x07<<SPIX_CR1_BR_SHIFT)
    #define SPIX_CR1_BR_DIV2        (0x00<<SPIX_CR1_BR_SHIFT)
    #define SPIX_CR1_BR_DIV4        (0x01<<SPIX_CR1_BR_SHIFT)
    #define SPIX_CR1_BR_DIV8        (0x02<<SPIX_CR1_BR_SHIFT)
    #define SPIX_CR1_BR_DIV16       (0x03<<SPIX_CR1_BR_SHIFT)
    #define SPIX_CR1_BR_DIV32       (0x04<<SPIX_CR1_BR_SHIFT)
    #define SPIX_CR1_BR_DIV64       (0x05<<SPIX_CR1_BR_SHIFT)
    #define SPIX_CR1_BR_DIV128      (0x06<<SPIX_CR1_BR_SHIFT)
    #define SPIX_CR1_BR_DIV256      (0x07<<SPIX_CR1_BR_SHIFT)
#define SPIX_CR1_SPE                (1<<6)
#define SPIX_CR1_LSBFIRST           (1<<7)

#define SPIX_CR2_SSI                (1<<0)
#define SPIX_CR2_SSM                (1<<1)
#define SPIX_CR2_RXONLY             (1<<2)
//#define SPIX_CR2_Res              (1<<3)
#define SPIX_CR2_CRCNEXT            (1<<4)
#define SPIX_CR2_CRCEN              (1<<5)
#define SPIX_CR2_BDOE               (1<<6)
#define SPIX_CR2_BDM                (1<<7)

//#define SPIX_ICR_Res              (1<<0)
//#define SPIX_ICR_Res              (1<<1)
//#define SPIX_ICR_Res              (1<<2)
//#define SPIX_ICR_Res              (1<<3)
#define SPIX_ICR_WKIE               (1<<4)
#define SPIX_ICR_ERRIE              (1<<5)
#define SPIX_ICR_RXIE               (1<<6)
#define SPIX_ICR_TXIE               (1<<7)

#define SPIX_SR_RXNE                (1<<0)
#define SPIX_SR_TXE                 (1<<1)
//#define SPIX_SR_Res               (1<<2)
#define SPIX_SR_WKUP                (1<<3)
#define SPIX_SR_CRCERR              (1<<4)
#define SPIX_SR_MODF                (1<<5)
#define SPIX_SR_OVR                 (1<<6)
#define SPIX_SR_BSY                 (1<<7)

#define SPIX_DR_DR_SHIFT            (0)
#define SPIX_DR_DR_MASK             (0xFF<<SPIX_DR_DR_SHIFT)
    #define SPIX_DR_DR_(n)          ((n)<<SPIX_DR_DR_SHIFT)

#define SPIX_CRCPR_CRCPOLY_SHIFT    (0)
#define SPIX_CRCPR_CRCPOLY_MASK     (0xFF<<SPIX_CRCPR_CRCPOLY_SHIFT)
    #define SPIX_CRCPR_CRCPOLY_(n)  ((n)<<SPIX_CRCPR_CRCPOLY_SHIFT)

#define SPIX_RXCRCR_RXCRC_SHIFT     (0)
#define SPIX_RXCRCR_RXCRC_MASK      (0xFF<<SPIX_RXCRCR_RXCRC_SHIFT)
    #define SPIX_RXCRCR_RXCRC_(n)   ((n)<<SPIX_RXCRCR_RXCRC_SHIFT)

#define SPIX_TXCRCR_TXCRC_SHIFT     (0)
#define SPIX_TXCRCR_TXCRC_MASK      (0xFF<<SPIX_TXCRCR_TXCRC_SHIFT)
    #define SPIX_TXCRCR_TXCRC_(n)   ((n)<<SPIX_TXCRCR_TXCRC_SHIFT)

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