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