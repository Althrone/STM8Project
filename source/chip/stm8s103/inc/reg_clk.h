#ifndef _CLK_H_
#define _CLK_H_

#include "./memory_map.h"

//寄存器偏移地址
#define CLK_ICKR_OFFSET     0x0000
#define CLK_ECKR_OFFSET     0x0001
//#define CLK_Res_OFFSET    0x0002
#define CLK_CMSR_OFFSET     0x0003
#define CLK_SWR_OFFSET      0x0004
#define CLK_SWCR_OFFSET     0x0005
#define CLK_CKDIVR_OFFSET   0x0006
#define CLK_PCKENR1_OFFSET  0x0007
#define CLK_CSSR_OFFSET     0x0008
#define CLK_CCOR_OFFSET     0x0009
#define CLK_PCKENR2_OFFSET  0x000A
//#define CLK_Res_OFFSET    0x000B
#define CLK_HSITRIMR_OFFSET 0x000C
#define CLK_SWIMCCR_OFFSET  0x000D

//寄存器操作
#define CLK_ICKR_HSIEN                  (1<<0)
#define CLK_ICKR_HSIRDY                 (1<<1)
#define CLK_ICKR_FHW                    (1<<2)
#define CLK_ICKR_LSIEN                  (1<<3)
#define CLK_ICKR_LSIRDY                 (1<<4)
#define CLK_ICKR_REGAH                  (1<<5)

#define CLK_ECKR_HSEEN                  (1<<0)
#define CLK_ECKR_HSERDY                 (1<<1)

#define CLK_CMSR_CKM_SHIFT              (0)
#define CLK_CMSR_CKM_MASK               (0xFF<<CLK_CMSR_CKM_SHIFT)
    #define CLK_CMSR_CKM_HSI            (0xE1<<CLK_CMSR_CKM_SHIFT)
    #define CLK_CMSR_CKM_LSI            (0xD2<<CLK_CMSR_CKM_SHIFT)
    #define CLK_CMSR_CKM_HSE            (0xB4<<CLK_CMSR_CKM_SHIFT)

#define CLK_SWR_SWI_SHIFT               (0)
#define CLK_SWR_SWI_MASK                (0xFF<<CLK_SWR_SWI_SHIFT)
    #define CLK_SWR_SWI_HSI             (0xE1<<CLK_SWR_SWI_SHIFT)
    #define CLK_SWR_SWI_LSI             (0xD2<<CLK_SWR_SWI_SHIFT)
    #define CLK_SWR_SWI_HSE             (0xB4<<CLK_SWR_SWI_SHIFT)

#define CLK_SWCR_SWBSY                  (1<<0)
#define CLK_SWCR_SWEN                   (1<<1)
#define CLK_SWCR_SWIEN                  (1<<2)
#define CLK_SWCR_SWIF                   (1<<3)

#define CLK_CKDIVR_CPUDIV_SHIFT         (0)
#define CLK_CKDIVR_CPUDIV_MASK          (0x07<<CLK_CKDIVR_CPUDIV_SHIFT)
    #define CLK_CKDIVR_CPUDIV_DIV1      (0x00<<CLK_CKDIVR_CPUDIV_SHIFT)
    #define CLK_CKDIVR_CPUDIV_DIV2      (0x01<<CLK_CKDIVR_CPUDIV_SHIFT)
    #define CLK_CKDIVR_CPUDIV_DIV4      (0x02<<CLK_CKDIVR_CPUDIV_SHIFT)
    #define CLK_CKDIVR_CPUDIV_DIV8      (0x03<<CLK_CKDIVR_CPUDIV_SHIFT)
    #define CLK_CKDIVR_CPUDIV_DIV16     (0x04<<CLK_CKDIVR_CPUDIV_SHIFT)
    #define CLK_CKDIVR_CPUDIV_DIV32     (0x05<<CLK_CKDIVR_CPUDIV_SHIFT)
    #define CLK_CKDIVR_CPUDIV_DIV64     (0x06<<CLK_CKDIVR_CPUDIV_SHIFT)
    #define CLK_CKDIVR_CPUDIV_DIV128    (0x07<<CLK_CKDIVR_CPUDIV_SHIFT)
#define CLK_CKDIVR_HSIDIV_SHIFT         (3)
#define CLK_CKDIVR_HSIDIV_MASK          (0x03<<CLK_CKDIVR_HSIDIV_SHIFT)
    #define CLK_CKDIVR_HSIDIV_DIV1      (0x00<<CLK_CKDIVR_HSIDIV_SHIFT)
    #define CLK_CKDIVR_HSIDIV_DIV2      (0x01<<CLK_CKDIVR_HSIDIV_SHIFT)
    #define CLK_CKDIVR_HSIDIV_DIV4      (0x02<<CLK_CKDIVR_HSIDIV_SHIFT)
    #define CLK_CKDIVR_HSIDIV_DIV8      (0x03<<CLK_CKDIVR_HSIDIV_SHIFT)

#define CLK_PCKENR1_I2C                 (1<<0)
#define CLK_PCKENR1_SPI                 (1<<1)
//#define CLK_PCKENR1_Res               (1<<2)
#define CLK_PCKENR1_UART1               (1<<3)
#define CLK_PCKENR1_TIM4                (1<<4)
#define CLK_PCKENR1_TIM2                (1<<5)
//#define CLK_PCKENR1_Res               (1<<6)
#define CLK_PCKENR1_TIM1                (1<<7)

//#define CLK_PCKENR2_Res               (1<<0)
//#define CLK_PCKENR2_Res               (1<<1)
#define CLK_PCKENR2_AWU                 (1<<2)
#define CLK_PCKENR2_ADC                 (1<<3)
//#define CLK_PCKENR2_Res               (1<<4)
//#define CLK_PCKENR2_Res               (1<<5)
//#define CLK_PCKENR2_Res               (1<<6)
//#define CLK_PCKENR2_Res               (1<<7)

#define CLK_CSSR_CSSEN                  (1<<0)
#define CLK_CSSR_AUX                    (1<<1)
#define CLK_CSSR_CSSDIE                 (1<<2)
#define CLK_CSSR_CSSD                   (1<<3)

#define CLK_CCOR_CCOEN                  (1<<0)
#define CLK_CCOR_CCOSEL_SHIFT           (1)
#define CLK_CCOR_CCOSEL_MASK            (0x0F<<CLK_CCOR_CCOSEL_SHIFT)
    #define CLK_CCOR_CCOSEL_HSIDIV      (0x00<<CLK_CCOR_CCOSEL_SHIFT)
    #define CLK_CCOR_CCOSEL_LSI         (0x01<<CLK_CCOR_CCOSEL_SHIFT)
    #define CLK_CCOR_CCOSEL_HSE         (0x02<<CLK_CCOR_CCOSEL_SHIFT)
  //#define CLK_CCOR_CCOSEL_Res         (0x03<<CLK_CCOR_CCOSEL_SHIFT)
    #define CLK_CCOR_CCOSEL_CPU         (0x04<<CLK_CCOR_CCOSEL_SHIFT)
    #define CLK_CCOR_CCOSEL_CPUD2       (0x05<<CLK_CCOR_CCOSEL_SHIFT)
    #define CLK_CCOR_CCOSEL_CPUD4       (0x06<<CLK_CCOR_CCOSEL_SHIFT)
    #define CLK_CCOR_CCOSEL_CPUD8       (0x07<<CLK_CCOR_CCOSEL_SHIFT)
    #define CLK_CCOR_CCOSEL_CPUD16      (0x08<<CLK_CCOR_CCOSEL_SHIFT)
    #define CLK_CCOR_CCOSEL_CPUD32      (0x09<<CLK_CCOR_CCOSEL_SHIFT)
    #define CLK_CCOR_CCOSEL_CPUD64      (0x0A<<CLK_CCOR_CCOSEL_SHIFT)
    #define CLK_CCOR_CCOSEL_HSI         (0x0B<<CLK_CCOR_CCOSEL_SHIFT)
    #define CLK_CCOR_CCOSEL_MASTER      (0x0C<<CLK_CCOR_CCOSEL_SHIFT)
  //#define CLK_CCOR_CCOSEL_Res         (0x0D<<CLK_CCOR_CCOSEL_SHIFT)
  //#define CLK_CCOR_CCOSEL_Res         (0x0E<<CLK_CCOR_CCOSEL_SHIFT)
  //#define CLK_CCOR_CCOSEL_Res         (0x0F<<CLK_CCOR_CCOSEL_SHIFT)
#define CLK_CCOR_CCORDY                 (1<<5)
#define CLK_CCOR_CCOBSY                 (1<<6)
//#define CLK_CCOR_Res                  (1<<7)

#define CLK_HSITRIMR_HSITRIM_SHIFT      (0)
#define CLK_HSITRIMR_HSITRIM_MASK       (0x0F<<CLK_HSITRIMR_HSITRIM_SHIFT)
    #define CLK_HSITRIMR_HSITRIM_(n)    ((n)<<CLK_HSITRIMR_HSITRIM_SHIFT)

#define CLK_SWIMCCR_SWIMCLK             (1<<0)//0二分频，1不分频

//寄存器基地址+偏移地址
#define CLK_ICKR        *(volatile uint8_t *)(CLK_BASE+CLK_ICKR_OFFSET)
#define CLK_ECKR        *(volatile uint8_t *)(CLK_BASE+CLK_ECKR_OFFSET)
//#define CLK_Res       *(volatile uint8_t *)(CLK_BASE+CLK_Res_OFFSET)
#define CLK_CMSR        *(volatile uint8_t *)(CLK_BASE+CLK_CMSR_OFFSET)
#define CLK_SWR         *(volatile uint8_t *)(CLK_BASE+CLK_SWR_OFFSET)
#define CLK_SWCR        *(volatile uint8_t *)(CLK_BASE+CLK_SWCR_OFFSET)
#define CLK_CKDIVR      *(volatile uint8_t *)(CLK_BASE+CLK_CKDIVR_OFFSET)
#define CLK_PCKENR1     *(volatile uint8_t *)(CLK_BASE+CLK_PCKENR1_OFFSET)
#define CLK_CSSR        *(volatile uint8_t *)(CLK_BASE+CLK_CSSR_OFFSET)
#define CLK_CCOR        *(volatile uint8_t *)(CLK_BASE+CLK_CCOR_OFFSET)
#define CLK_PCKENR2     *(volatile uint8_t *)(CLK_BASE+CLK_PCKENR2_OFFSET)
//#define CLK_Res       *(volatile uint8_t *)(CLK_BASE+CLK_Res_OFFSET)
#define CLK_HSITRIMR    *(volatile uint8_t *)(CLK_BASE+CLK_HSITRIMR_OFFSET)
#define CLK_SWIMCCR     *(volatile uint8_t *)(CLK_BASE+CLK_SWIMCCR_OFFSET)

#endif /*_CLK_H_*/

/*用于批量修改
*/