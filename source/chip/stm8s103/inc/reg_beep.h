#ifndef _BEEP_H_
#define _BEEP_H_

#include "./memory_map.h"

//寄存器偏移地址
#define BEEP_CSR_OFFSET 0x0000

//寄存器操作
#define BEEP_CSR_BEEPDIV_SHIFT      (0)
#define BEEP_CSR_BEEPDIV_MASK       (0x1F<<BEEP_CSR_BEEPDIV_SHIFT)
    #define BEEP_CSR_BEEPDIV_(n)    ((n-2)<<BEEP_CSR_BEEPDIV_SHIFT)//输入2~32分频系数，fLS除此值应等于8

#define BEEP_CSR_BEEPEN             (1<<5)

#define BEEP_CSR_BEEPSEL_SHIFT      (6)
#define BEEP_CSR_BEEPSEL_MASK       (0x03<<BEEP_CSR_BEEPSEL_SHIFT)
    #define BEEP_CSR_BEEPSEL_1kHz   (0x00<<BEEP_CSR_BEEPSEL_SHIFT)
    #define BEEP_CSR_BEEPSEL_2kHz   (0x01<<BEEP_CSR_BEEPSEL_SHIFT)
    #define BEEP_CSR_BEEPSEL_4kHz   (0x02<<BEEP_CSR_BEEPSEL_SHIFT)
  //#define BEEP_CSR_BEEPSEL_4kHz   (0x03<<BEEP_CSR_BEEPSEL_SHIFT)

//寄存器基地址+偏移地址
#define BEEP_CSR *(volatile uint8_t *)(BEEP_BASE+BEEP_CSR_OFFSET)

#endif /*_BEEP_H_*/

/*用于批量修改
*/