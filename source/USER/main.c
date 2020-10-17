#include "main.h"

// void delay(void)
// {
//     for (uint8_t i = 0; i < 100; i++)
//         {
//             for (uint8_t j = 0; j < 100; j++)
//             {
//                 // for (uint8_t k = 0; k < 100; k++);
//             }
//         };
// }

void main()
{
    CLK_DeInit();
    BEEP_Init(BEEP_FREQUENCY_1KHZ);
    BEEP_Cmd(ENABLE);
    HC595_Init();
    rim();
    // uint8_t a=0x00;
    while(1)
    {

        // GPIO_WriteLow(GPIOC,GPIO_PIN_7);
        // SPI_SendData(0b10000001);
        // delay();
        // while(SPI_GetFlagStatus(SPI_FLAG_TXE)==RESET);
        // SPI_SendData(0);
        // delay();
        // while(SPI_GetFlagStatus(SPI_FLAG_TXE)==RESET);
        // SPI_SendData(0);
        // delay();
        // while(SPI_GetFlagStatus(SPI_FLAG_TXE)==RESET);
        // SPI_SendData(0);
        // delay();
        // while(SPI_GetFlagStatus(SPI_FLAG_TXE)==RESET);
        // SPI_SendData(0);
        // delay();
        // while(SPI_GetFlagStatus(SPI_FLAG_TXE)==RESET);
        // SPI_SendData(0);
        // delay();
        // while(SPI_GetFlagStatus(SPI_FLAG_TXE)==RESET);
        // delay();
        // GPIO_WriteHigh(GPIOC,GPIO_PIN_7);
        // a++;
        // if(a>0xff)
        // a=0x00;
        // delay();delay();delay();delay();delay();delay();delay();delay();delay();

        DISP_ShowNumber();
    }
}

// void TIM4_UPD_OVF_IRQHandler(void) __interrupt(23)
// {

// }
