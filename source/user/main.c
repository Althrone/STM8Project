#include "../include/config.h"

void main()
{
    TIM4_PSCR|=TIMX_PSCR_PSC_(14);
}



// void EXTI_PORTE_IRQHandler(void) __intreeupt(7)
// {

// }

// void TIM2_CAP_COM_IRQHandler(void) __intreeupt(14);
// {

// }