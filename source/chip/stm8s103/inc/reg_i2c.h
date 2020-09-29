#ifndef _I2C_H_
#define _I2C_H_

#include "./memory_map.h"

//寄存器偏移地址
#define I2C_CR1_OFFSET              0x0000
#define I2C_CR2_OFFSET              0x0001
#define I2C_FREQR_OFFSET            0x0002
#define I2C_OARL_OFFSET             0x0003
#define I2C_OARH_OFFSET             0x0004
//#define I2C_Res_OFFSET            0x0005
#define I2C_DR_OFFSET               0x0006
#define I2C_SR1_OFFSET              0x0007
#define I2C_SR2_OFFSET              0x0008
#define I2C_SR3_OFFSET              0x0009
#define I2C_ITR_OFFSET              0x000A
#define I2C_CCRL_OFFSET             0x000B
#define I2C_CCRH_OFFSET             0x000C
#define I2C_TRISER_OFFSET           0x000D
#define I2C_PECR_OFFSET             0x000E

//寄存器操作
#define I2CX_CR1_PE                 (1<<0)
//#define I2CX_CR1_Res              (1<<1)
//#define I2CX_CR1_Res              (1<<2)
//#define I2CX_CR1_Res              (1<<3)
//#define I2CX_CR1_Res              (1<<4)
//#define I2CX_CR1_Res              (1<<5)
#define I2CX_CR1_ENGC               (1<<6)
#define I2CX_CR1_NOSTRETCH          (1<<7)

#define I2CX_CR2_START              (1<<0)
#define I2CX_CR2_STOP               (1<<1)
#define I2CX_CR2_ACK                (1<<2)
#define I2CX_CR2_POS                (1<<3)
//#define I2CX_CR1_Res              (1<<4)
//#define I2CX_CR1_Res              (1<<5)
//#define I2CX_CR1_Res              (1<<6)
#define I2CX_CR2_SWRST              (1<<7)

#define I2CX_FREQR_FREQ_SHIFT       (0)
#define I2CX_FREQR_FREQ_MASK        (0x3F<<I2CX_FREQR_FREQ_SHIFT)
    #define I2CX_FREQR_FREQ_(n)     ((n)<<I2CX_FREQR_FREQ_SHIFT)//输入1~24，单位MHz

#define I2CX_OARL_ADD0              (1<<0)
#define I2CX_OARL_ADD_SHIFT         (1)
#define I2CX_OARL_ADD_MASK          (0x7F<<I2CX_OARL_ADD_SHIFT)
    #define I2CX_OARL_ADD_(n)       ((n)<<I2CX_OARL_ADD_SHIFT)

#define I2CX_OARH_ADD_SHIFT         (1)
#define I2CX_OARH_ADD_MASK          (0x03<<I2CX_OARH_ADD_SHIFT)
    #define I2CX_OARH_ADD_(n)       ((n)<<I2CX_OARH_ADD_SHIFT)
#define I2CX_OARH_ADDCONF           (1<<6)
#define I2CX_OARH_ADDMODE           (1<<7)

#define I2CX_DR_DR_SHIFT            (0)
#define I2CX_DR_DR_MASK             (0xFF<<I2CX_DR_DR_SHIFT)
    #define I2CX_DR_DR_(n)          ((n)<<I2CX_DR_DR_SHIFT)

#define I2CX_SR1_SB                 (1<<0)
#define I2CX_SR1_ADDR               (1<<1)
#define I2CX_SR1_BTF                (1<<2)
#define I2CX_SR1_ADD10              (1<<3)
#define I2CX_SR1_STOPF              (1<<4)
//#define I2CX_SR1_Res              (1<<5)
#define I2CX_SR1_RXNE               (1<<6)
#define I2CX_SR1_TXE                (1<<7)

#define I2CX_SR2_BERR               (1<<0)
#define I2CX_SR2_ARLO               (1<<1)
#define I2CX_SR2_AF                 (1<<2)
#define I2CX_SR2_OVR                (1<<3)
//#define I2CX_SR2_Res              (1<<4)
#define I2CX_SR2_WUFH               (1<<5)
//#define I2CX_SR2_Res              (1<<6)
//#define I2CX_SR2_Res              (1<<7)

#define I2CX_SR3_MSL                (1<<0)
#define I2CX_SR3_BUSY               (1<<1)
#define I2CX_SR3_TRA                (1<<2)
//#define I2CX_SR3_Res              (1<<3)
#define I2CX_SR3_GENCALL            (1<<4)
//#define I2CX_SR3_Res              (1<<5)
//#define I2CX_SR3_Res              (1<<6)
#define I2CX_SR3_DUALF              (1<<7)

#define I2CX_ITERREN                (1<<0)
#define I2CX_ITEVTEN                (1<<1)
#define I2CX_ITBUFEN                (1<<2)

#define I2CX_CCRL_CCR_SHIFT         (0)
#define I2CX_CCRL_CCR_MASK          (0xFF<<I2CX_CCRL_CCR_SHIFT)
    #define I2CX_CCRL_CCR_(n)       ((n)<<I2CX_CCRL_CCR_SHIFT)

#define I2CX_CCRH_CCR_SHIFT         (0)
#define I2CX_CCRH_CCR_MASK          (0x0F<<I2CX_CCRH_CCR_SHIFT)
    #define I2CX_CCRH_CCR_(n)       ((n)<<I2CX_CCRH_CCR_SHIFT)
#define I2CX_CCRH_DUTY              (1<<6)
#define I2CX_CCRH_FAST              (1<<7)

#define I2CX_TRISER_TRISE_SHIFT     (0)
#define I2CX_TRISER_TRISE_MASK      (0x3F<<I2CX_TRISER_TRISE_SHIFT)
    #define I2CX_TRISER_TRISE_(n)   ((n)<<I2CX_TRISER_TRISE_SHIFT)

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