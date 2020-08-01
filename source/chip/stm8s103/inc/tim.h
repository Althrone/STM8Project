#ifndef _TIM_H_
#define _TIM_H_

#include "./memory_map.h"

//寄存器偏移地址

//寄存器操作
#define TIMX_CR1_CEN            (1<<0)
#define TIMX_CR1_UDIS           (1<<1)
#define TIMX_CR1_URS            (1<<2)
#define TIMX_CR1_OPM            (1<<3)
#define TIMX_CR1_DIR            (1<<4)
#define TIMX_CR1_CMSH           (1<<6)
#define TIMX_CR1_CMSL           (1<<5)
#define TIMX_CR1_CMS_SHIFT      (5)
#define TIMX_CR1_CMS_MASK       (0x03<<TIMX_CR1_CMS_SHIFT)
    #define TIMX_CR1_CMS_EDGE   (0x00<<TIMX_CR1_CMS_SHIFT)
    #define TIMX_CR1_CMS_CEN1   (0x01<<TIMX_CR1_CMS_SHIFT)
    #define TIMX_CR1_CMS_CEN2   (0x02<<TIMX_CR1_CMS_SHIFT)
    #define TIMX_CR1_CMS_CEN3   (0x03<<TIMX_CR1_CMS_SHIFT)
#define TIMX_CR1_APRE           (1<<7)

#define TIMX_IER_UIE            (1<<0)
#define TIMX_IER_TIE            (1<<6)

#define TIMX_SR_UIF             (1<<0)
#define TIMX_SR_TIF             (1<<6)

#define TIMX_EGR_UG             (1<<0)
#define TIMX_EGR_TG             (1<<6)

#define TIMX_CNTR_CNT_SHIFT     (0)
#define TIMX_CNTR_CNT_MASK      (0xFF<<TIMX_CNTR_CNT_SHIFT)
    #define TIMX_CNTR_CNT_(n)   ((n)<<TIMX_CNTR_CNT_SHIFT)

#define TIMX_PSCR_PSC_SHIFT     (0)
#define TIMX_PSCR_PSC_MASK      (0x07<<TIMX_PSCR_PSC_SHIFT)
    #define TIMX_PSCR_PSC_(n)   ((n/2)<<TIMX_PSCR_PSC_SHIFT)//输入0、2、4...14的整数

#define TIMX_ARR_ARR_SHIFT      (0)
#define TIMX_ARR_ARR_MASK       (0xFF<<TIMX_ARR_ARR_SHIFT)
    #define TIMX_ARR_ARR_(n)    ((n-1)<<TIMX_ARR_ARR_SHIFT)

//寄存器基地址+偏移地址
#define TIM1_CR1    *(volatile uint8_t *)0x5250
#define TIM1_CR2    *(volatile uint8_t *)0x5251
#define TIM1_SMCR   *(volatile uint8_t *)0x5252
#define TIM1_ETR    *(volatile uint8_t *)0x5253
#define TIM1_IER    *(volatile uint8_t *)0x5254
#define TIM1_SR1    *(volatile uint8_t *)0x5255
#define TIM1_SR2    *(volatile uint8_t *)0x5256
#define TIM1_EGR    *(volatile uint8_t *)0x5257
#define TIM1_CCMR1  *(volatile uint8_t *)0x5258
#define TIM1_CCMR2  *(volatile uint8_t *)0x5259
#define TIM1_CCMR3  *(volatile uint8_t *)0x525A
#define TIM1_CCMR4  *(volatile uint8_t *)0x525B
#define TIM1_CCER1  *(volatile uint8_t *)0x525C
#define TIM1_CCER2  *(volatile uint8_t *)0x525D
#define TIM1_CNTRH  *(volatile uint8_t *)0x525E
#define TIM1_CNTRL  *(volatile uint8_t *)0x525F
#define TIM1_PSCRH  *(volatile uint8_t *)0x5260
#define TIM1_PSCRL  *(volatile uint8_t *)0x5261
#define TIM1_ARRH   *(volatile uint8_t *)0x5262
#define TIM1_ARRL   *(volatile uint8_t *)0x5263
#define TIM1_RCR    *(volatile uint8_t *)0x5264
#define TIM1_CCR1H  *(volatile uint8_t *)0x5265
#define TIM1_CCR1L  *(volatile uint8_t *)0x5266
#define TIM1_CCR2H  *(volatile uint8_t *)0x5267
#define TIM1_CCR2L  *(volatile uint8_t *)0x5268
#define TIM1_CCR3H  *(volatile uint8_t *)0x5269
#define TIM1_CCR3L  *(volatile uint8_t *)0x526A
#define TIM1_CCR4H  *(volatile uint8_t *)0x526B
#define TIM1_CCR4L  *(volatile uint8_t *)0x526C
#define TIM1_BKR    *(volatile uint8_t *)0x526D
#define TIM1_DTR    *(volatile uint8_t *)0x526E
#define TIM1_OISR   *(volatile uint8_t *)0x526F

/* Note these are for STM8S103 and STM8S003
   STM8S105,104/207/208 are different */
#define TIM2_CR1    *(volatile uint8_t *)0x5300
#define TIM2_CR2    *(volatile uint8_t *)0x5301
#define TIM2_SMCR   *(volatile uint8_t *)0x5302
#define TIM2_IER    *(volatile uint8_t *)0x5303
#define TIM2_SR1    *(volatile uint8_t *)0x5304
#define TIM2_SR2    *(volatile uint8_t *)0x5305
#define TIM2_EGR    *(volatile uint8_t *)0x5306
#define TIM2_CCMR1  *(volatile uint8_t *)0x5307
#define TIM2_CCMR2  *(volatile uint8_t *)0x5308
#define TIM2_CCMR3  *(volatile uint8_t *)0x5309
#define TIM2_CCER1  *(volatile uint8_t *)0x530A
#define TIM2_CCER2  *(volatile uint8_t *)0x530B
#define TIM2_CNTRH  *(volatile uint8_t *)0x530C
#define TIM2_CNTRL  *(volatile uint8_t *)0x530D
#define TIM2_PSCR   *(volatile uint8_t *)0x530E
#define TIM2_ARRH   *(volatile uint8_t *)0x530F
#define TIM2_ARRL   *(volatile uint8_t *)0x5310
#define TIM2_CCR1H  *(volatile uint8_t *)0x5311
#define TIM2_CCR1L  *(volatile uint8_t *)0x5312
#define TIM2_CCR2H  *(volatile uint8_t *)0x5313
#define TIM2_CCR2L  *(volatile uint8_t *)0x5314
#define TIM2_CCR3H  *(volatile uint8_t *)0x5315
#define TIM2_CCR3L  *(volatile uint8_t *)0x5316

/* Note these are for STM8S103 and STM8S003
   STM8S105,104/207/208 are different */
#define TIM4_CR1    *(volatile uint8_t *)0x5340
//#define TIM4_CR2  *(volatile uint8_t *)0x5341
//#define TIM4_SMCR *(volatile uint8_t *)0x5342
#define TIM4_IER    *(volatile uint8_t *)0x5343
#define TIM4_SR     *(volatile uint8_t *)0x5344
#define TIM4_EGR    *(volatile uint8_t *)0x5345
#define TIM4_CNTR   *(volatile uint8_t *)0x5346
#define TIM4_PSCR   *(volatile uint8_t *)0x5347
#define TIM4_ARR    *(volatile uint8_t *)0x5348

#endif /*_TIM_H_*/

/*用于批量修改
*/