#ifndef _OPTION_BYTE_H_
#define _OPTION_BYTE_H_

#include "./memory_map.h"

//寄存器偏移地址
#define OPT_ROP_OFFSET          0x0000//Read-out protection
#define OPT_UBC_OFFSET          0x0001//User boot code area
#define OPT_NUBC_OFFSET         0x0002
#define OPT_AFR_OFFSET          0x0003//Alternate function remapping
#define OPT_NAFR_OFFSET         0x0004
#define OPT_MISC_OFFSET         0x0005//Misc. option
#define OPT_NMISC_OFFSET        0x0006
#define OPT_CLK_OFFSET          0x0007//Clock option
#define OPT_NCLK_OFFSET         0x0008
#define OPT_HSE_OFFSET          0x0009//HSE clock startup
#define OPT_NHSE_OFFSET         0x000A

//寄存器操作
#define OPT_ROP_ROP_SHIFT       (0)
#define OPT_ROP_ROP_MASK        (0xFF<<OPT_ROP_ROP_SHIFT)
    #define OPT_ROP_ROP_EN      (0xAA<<OPT_ROP_ROP_SHIFT)

#define OPT_UBC_UBC_SHIFT       (0)
#define OPT_UBC_UBC_MASK        (0xFF<<OPT_UBC_UBC_SHIFT)
    #define OPT_UBC_UBC_(n)     ((n)<<OPT_UBC_UBC_SHIFT)//输入0~127，0=no UBC，127=Pages 0 to 126 defined as UBC

#define OPT_NUBC_NUBC_SHIFT     (0)
#define OPT_NUBC_NUBC_MASK      (0xFF<<OPT_NUBC_NUBC_SHIFT)
    #define OPT_NUBC_NUBC_(n)   (~(n)<<OPT_NUBC_NUBC_SHIFT)//输入与OPT_UBC_UBC_(n)一样的值

#if defined(__STM8S103F2_)||defined(__STM8S103F3_)

    #define OPT_AFR_AFR0        (1<<0)
    #define OPT_AFR_AFR1        (1<<1)
    //#define OPT_AFR_Res       (1<<2)
    #define OPT_AFR_AFR3        (1<<3)
    #define OPT_AFR_AFR4        (1<<4)
    //#define OPT_AFR_Res       (1<<5)
    //#define OPT_AFR_Res       (1<<6)
    #define OPT_AFR_AFR7        (1<<7)

    #define OPT_NAFR_NAFR0      (0<<0)
    #define OPT_NAFR_NAFR1      (0<<1)
    //#define OPT_NAFR_Res      (0<<2)
    #define OPT_NAFR_NAFR3      (0<<3)
    #define OPT_NAFR_NAFR4      (0<<4)
    //#define OPT_NAFR_Res      (0<<5)
    //#define OPT_NAFR_Res      (0<<6)
    #define OPT_NAFR_NAFR7      (0<<7)

#endif /*defined(__STM8S103F2_)||defined(__STM8S103F3_)*/

#if defined(__STM8S103K3_)

    //#define OPT_AFR_Res       (1<<0)
    #define OPT_AFR_AFR1        (1<<1)
    //#define OPT_AFR_Res       (1<<2)
    //#define OPT_AFR_Res       (1<<3)
    //#define OPT_AFR_Res       (1<<4)
    #define OPT_AFR_AFR5        (1<<5)
    #define OPT_AFR_AFR6        (1<<6)
    //#define OPT_AFR_Res       (1<<7)

    //#define OPT_NAFR_Res      (0<<0)
    #define OPT_NAFR_NAFR1      (0<<1)
    //#define OPT_NAFR_Res      (0<<2)
    //#define OPT_NAFR_Res      (0<<3)
    //#define OPT_NAFR_Res      (0<<4)
    #define OPT_NAFR_NAFR5      (0<<5)
    #define OPT_NAFR_NAFR6      (0<<6)
    //#define OPT_NAFR_Res      (0<<7)

#endif /*defined(__STM8S103K3_)*/

//寄存器基地址+偏移地址
#define OPT_ROP     *(volatile uint8_t *)(OPT_BSAE+OPT_ROP_OFFSET)
#define OPT_UBC     *(volatile uint8_t *)(OPT_BSAE+OPT_UBC_OFFSET)
#define OPT_NUBC    *(volatile uint8_t *)(OPT_BSAE+OPT_NUBC_OFFSET)
#define OPT_AFR     *(volatile uint8_t *)(OPT_BSAE+OPT_AFR_OFFSET)
#define OPT_NAFR    *(volatile uint8_t *)(OPT_BSAE+OPT_NAFR_OFFSET)
#define OPT_MISC    *(volatile uint8_t *)(OPT_BSAE+OPT_MISC_OFFSET)
#define OPT_NMISC   *(volatile uint8_t *)(OPT_BSAE+OPT_NMISC_OFFSET)
#define OPT_CLK     *(volatile uint8_t *)(OPT_BSAE+OPT_CLK_OFFSET)
#define OPT_NCLK    *(volatile uint8_t *)(OPT_BSAE+OPT_NCLK_OFFSET)
#define OPT_HSE     *(volatile uint8_t *)(OPT_BSAE+OPT_HSE_OFFSET)
#define OPT_NHSE    *(volatile uint8_t *)(OPT_BSAE+OPT_NHSE_OFFSET)

#endif /*_OPTION_BYTE_H_*/

/*用于批量修改
*/