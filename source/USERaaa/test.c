#include "clk.h"

void clk_init()
{
    //开机HSI自动开启
    while((CLK_ICKR&CLK_ICKR_HSIRDY)!=CLK_ICKR_HSIRDY);//检查HSI准备好没有
    while((CLK_CMSR&CLK_CMSR_CKM_HSI)!=CLK_CMSR_CKM_HSI);//检查主时钟是否为HSI
    CLK_CKDIVR&=~CLK_CKDIVR_HSIDIV_MASK;
    CLK_CKDIVR|=CLK_CKDIVR_HSIDIV_DIV1;//HSI作为主时钟最初是8分频，变成1分频快点
    CLK_PCKENR1&=~(CLK_PCKENR1_I2C|
                   CLK_PCKENR1_UART1|
                   CLK_PCKENR1_TIM2|
                   CLK_PCKENR1_TIM1);//外设时钟开启,stm8的gpio是不用开的，其他外设默认全开了，我们把除了tim4之外的关掉
    CLK_PCKENR2&=~(CLK_PCKENR2_ADC|
                   CLK_PCKENR2_AWU);//这个寄存器同理
    //最终fMASTER=fCPU=16MHz
}