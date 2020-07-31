#include "../include/config.h"

//用定时器中断点个灯

void pb5_init()
{
    PB_DDR|=PX_DDR_DDR5;//DDR PB5输出模式
    PB_CR1|=PX_CR1_C15; //CR1 推挽输出
    PB_CR2|=PX_CR2_C25; //CR2 输出速度10MHz
}

void tim4_init()
{

}

void main()
{
    pb5_init();
    while(1)
    {
        
    }
}

// void TIM4_UPD_OVF_IRQHandler(void) __interrupt(23)
// {

// }

// void EXTI_PORTE_IRQHandler(void) __intreeupt(7)
// {

// }

// void TIM2_CAP_COM_IRQHandler(void) __intreeupt(14);
// {

// }