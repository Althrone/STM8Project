#ifndef _OPTION_BYTE_H_
#define _OPTION_BYTE_H_

#include "./memory_map.h"

//寄存器偏移地址
#define OPT_ROP_OFFSET              0x0000//Read-out protection
#define OPT_UBC_OFFSET              0x0001//User boot code area
#define OPT_NUBC_OFFSET             0x0002
#define OPT_AFR_OFFSET              0x0003//Alternate function remapping
#define OPT_NAFR_OFFSET             0x0004
#define OPT_MISC_OFFSET             0x0005//Misc. option
#define OPT_NMISC_OFFSET            0x0006
#define OPT_CLK_OFFSET              0x0007//Clock option
#define OPT_NCLK_OFFSET             0x0008
#define OPT_HSE_OFFSET              0x0009//HSE clock startup
#define OPT_NHSE_OFFSET             0x000A

//寄存器操作
#define OPT_ROP_ROP_SHIFT           (0)
#define OPT_ROP_ROP_MASK            (0xFF<<OPT_ROP_ROP_SHIFT)
    #define OPT_ROP_ROP_EN          (0xAA<<OPT_ROP_ROP_SHIFT)

#define OPT_UBC_UBC_SHIFT           (0)
#define OPT_UBC_UBC_MASK            (0xFF<<OPT_UBC_UBC_SHIFT)
    #define OPT_UBC_UBC_(n)         ((n)<<OPT_UBC_UBC_SHIFT)//输入0~127，0=no UBC，127=Pages 0 to 126 defined as UBC

#define OPT_NUBC_NUBC_SHIFT         (0)
#define OPT_NUBC_NUBC_MASK          (0xFF<<OPT_NUBC_NUBC_SHIFT)
    #define OPT_NUBC_NUBC_(n)      ~((n)<<OPT_NUBC_NUBC_SHIFT)//输入与OPT_UBC_UBC_(n)一样的值

#if defined(__STM8S103F2_)||defined(__STM8S103F3_)

    #define OPT_AFR_AFR0            (1<<0)
    #define OPT_AFR_AFR1            (1<<1)
    //#define OPT_AFR_Res           (1<<2)
    #define OPT_AFR_AFR3            (1<<3)
    #define OPT_AFR_AFR4            (1<<4)
    //#define OPT_AFR_Res           (1<<5)
    //#define OPT_AFR_Res           (1<<6)
    #define OPT_AFR_AFR7            (1<<7)

    #define OPT_NAFR_NAFR0         ~(1<<0)
    #define OPT_NAFR_NAFR1         ~(1<<1)
    //#define OPT_NAFR_Res         ~(1<<2)
    #define OPT_NAFR_NAFR3         ~(1<<3)
    #define OPT_NAFR_NAFR4         ~(1<<4)
    //#define OPT_NAFR_Res         ~(1<<5)
    //#define OPT_NAFR_Res         ~(1<<6)
    #define OPT_NAFR_NAFR7         ~(1<<7)

#endif /*defined(__STM8S103F2_)||defined(__STM8S103F3_)*/

#if defined(__STM8S103K3_)

    //#define OPT_AFR_Res           (1<<0)
    #define OPT_AFR_AFR1            (1<<1)
    //#define OPT_AFR_Res           (1<<2)
    //#define OPT_AFR_Res           (1<<3)
    //#define OPT_AFR_Res           (1<<4)
    #define OPT_AFR_AFR5            (1<<5)
    #define OPT_AFR_AFR6            (1<<6)
    //#define OPT_AFR_Res           (1<<7)

    //#define OPT_NAFR_Res         ~(1<<0)
    #define OPT_NAFR_NAFR1         ~(1<<1)
    //#define OPT_NAFR_Res         ~(1<<2)
    //#define OPT_NAFR_Res         ~(1<<3)
    //#define OPT_NAFR_Res         ~(1<<4)
    #define OPT_NAFR_NAFR5         ~(1<<5)
    #define OPT_NAFR_NAFR6         ~(1<<6)
    //#define OPT_NAFR_Res         ~(1<<7)

#endif /*defined(__STM8S103K3_)*/

#define OPT_MISC_WWDGHALT           (1<<0)
#define OPT_MISC_WWDGHW             (1<<1)
#define OPT_MISC_IWDGHW             (1<<2)
#define OPT_MISC_LSIEN              (1<<3)
#define OPT_MISC_HSITRIM            (1<<4)
//#define OPT_MISC_Res              (1<<5)
//#define OPT_MISC_Res              (1<<6)
//#define OPT_MISC_Res              (1<<7)

#define OPT_NMISC_NWWDGHALT        ~(1<<0)
#define OPT_NMISC_NWWDGHW          ~(1<<1)
#define OPT_NMISC_NIWDGHW          ~(1<<2)
#define OPT_NMISC_NLSIEN           ~(1<<3)
#define OPT_NMISC_NHSITRIM         ~(1<<4)
//#define OPT_NMISC_Res            ~(1<<5)
//#define OPT_NMISC_Res            ~(1<<6)
//#define OPT_NMISC_Res            ~(1<<7)

#define OPT_CLK_PRSC_SHIFT          (0)
#define OPT_CLK_PRSC_MASK           (0x03<<OPT_CLK_PRSC_SHIFT)
  //#define OPT_CLK_PRSC_16M_Res    (0x00<OPT_CLK_PRSC_SHIFT)
    #define OPT_CLK_PRSC_16M        (0x01<<OPT_CLK_PRSC_SHIFT)
    #define OPT_CLK_PRSC_8M         (0x02<<OPT_CLK_PRSC_SHIFT)
    #define OPT_CLK_PRSC_4M         (0x03<<OPT_CLK_PRSC_SHIFT)
#define OPT_CLK_CKAWUSEL            (1<<2)
#define OPT_CLK_EXTCLK              (1<<3)
//#define OPT_CLK_Res               (1<<4)
//#define OPT_CLK_Res               (1<<5)
//#define OPT_CLK_Res               (1<<6)
//#define OPT_CLK_Res               (1<<7)

#define OPT_NCLK_NPRSC_SHIFT        (0)
#define OPT_NCLK_NPRSC_MASK         (0x03<<OPT_NCLK_NPRSC_SHIFT)
  //#define OPT_NCLK_NPRSC_16M_Res ~(0x00<OPT_NCLK_NPRSC_SHIFT)
    #define OPT_NCLK_NPRSC_16M     ~(0x01<<OPT_NCLK_NPRSC_SHIFT)
    #define OPT_NCLK_NPRSC_8M      ~(0x02<<OPT_NCLK_NPRSC_SHIFT)
    #define OPT_NCLK_NPRSC_4M      ~(0x03<<OPT_NCLK_NPRSC_SHIFT)
#define OPT_NCLK_NCKAWUSEL         ~(1<<2)
#define OPT_NCLK_EXTCLK            ~(1<<3)
//#define OPT_NCLK_Res             ~(1<<4)
//#define OPT_NCLK_Res             ~(1<<5)
//#define OPT_NCLK_Res             ~(1<<6)
//#define OPT_NCLK_Res             ~(1<<7)

#define OPT_HSE_HSECNT_SHIFT        (0)
#define OPT_HSE_HSECNT_MASK         (0xFF<<OPT_HSE_HSECNT_SHIFT)
    #define OPT_HSE_HSECNT_2048     (0x00<<OPT_HSE_HSECNT_SHIFT)
    #define OPT_HSE_HSECNT_128      (0xB4<<OPT_HSE_HSECNT_SHIFT)
    #define OPT_HSE_HSECNT_8        (0xD2<<OPT_HSE_HSECNT_SHIFT)
    #define OPT_HSE_HSECNT_0P5      (0xE1<<OPT_HSE_HSECNT_SHIFT)

#define OPT_NHSE_NHSECNT_SHIFT      (0)
#define OPT_NHSE_NHSECNT_MASK       (0xFF<<OPT_NHSE_NHSECNT_SHIFT)
    #define OPT_NHSE_NHSECNT_2048  ~(0x00<<OPT_NHSE_NHSECNT_SHIFT)
    #define OPT_NHSE_NHSECNT_128   ~(0xB4<<OPT_NHSE_NHSECNT_SHIFT)
    #define OPT_NHSE_NHSECNT_8     ~(0xD2<<OPT_NHSE_NHSECNT_SHIFT)
    #define OPT_NHSE_NHSECNT_0P5   ~(0xE1<<OPT_NHSE_NHSECNT_SHIFT)

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