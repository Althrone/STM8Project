#ifndef _I2C_H_
#define _I2C_H_

#include "./memory_map.h"

//寄存器偏移地址
#define I2C_CR1_OFFSET      0x0000
#define I2C_CR2_OFFSET      0x0001
#define I2C_FREQR_OFFSET    0x0002
#define I2C_OARL_OFFSET     0x0003
#define I2C_OARH_OFFSET     0x0004
//#define I2C_Res_OFFSET    0x0005
#define I2C_DR_OFFSET       0x0006
#define I2C_SR1_OFFSET      0x0007
#define I2C_SR2_OFFSET      0x0008
#define I2C_SR3_OFFSET      0x0009
#define I2C_ITR_OFFSET      0x000A
#define I2C_CCRL_OFFSET     0x000B
#define I2C_CCRH_OFFSET     0x000C
#define I2C_TRISER_OFFSET   0x000D
#define I2C_PECR_OFFSET     0x000E

//寄存器操作


//寄存器基地址+偏移地址
#define I2C_CR1     *(volatile uint8_t *)(I2C_BASE+I2C_CR1_OFFSET)
#define I2C_CR2     *(volatile uint8_t *)(I2C_BASE+I2C_CR2_OFFSET)
#define I2C_FREQR   *(volatile uint8_t *)(I2C_BASE+I2C_FREQR_OFFSET)
#define I2C_OARL    *(volatile uint8_t *)(I2C_BASE+I2C_OARL_OFFSET)
#define I2C_OARH    *(volatile uint8_t *)(I2C_BASE+I2C_OARH_OFFSET)
//#define I2C_Res   *(volatile uint8_t *)(I2C_BASE+I2C_Res_OFFSET)
#define I2C_DR      *(volatile uint8_t *)(I2C_BASE+I2C_DR_OFFSET)
#define I2C_SR1     *(volatile uint8_t *)(I2C_BASE+I2C_SR1_OFFSET)
#define I2C_SR2     *(volatile uint8_t *)(I2C_BASE+I2C_SR2_OFFSET)
#define I2C_SR3     *(volatile uint8_t *)(I2C_BASE+I2C_SR3_OFFSET)
#define I2C_ITR     *(volatile uint8_t *)(I2C_BASE+I2C_ITR_OFFSET)
#define I2C_CCRL    *(volatile uint8_t *)(I2C_BASE+I2C_CCRL_OFFSET)
#define I2C_CCRH    *(volatile uint8_t *)(I2C_BASE+I2C_CCRH_OFFSET)
#define I2C_TRISER  *(volatile uint8_t *)(I2C_BASE+I2C_TRISER_OFFSET)
#define I2C_PECR    *(volatile uint8_t *)(I2C_BASE+I2C_PECR_OFFSET)

#endif /*_I2C_H_*/

/*用于批量修改
*/