#include "stm8s.h"

void main()
{
    GPIO_Init(GPIOB,GPIO_PIN_5,GPIO_MODE_OUT_PP_LOW_FAST);
    GPIO_WriteHigh(GPIOB,GPIO_PIN_5);

    while(1)
    {
        GPIO_WriteReverse(GPIOB,GPIO_PIN_5);
        for(char i=0;i<200;i++)
        {
            for(char j=0;j<200;j++);

        }
    }
}