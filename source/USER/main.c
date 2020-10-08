#include "main.h"

void delay(void)
{
    for (uint8_t i = 0; i < 100; i++)
        {
            for (uint8_t j = 0; j < 100; j++)
            {
                // for (uint8_t k = 0; k < 100; k++);
            }
        };
}

void main()
{
    HC595_Init();
    rim();
    while(1)
    {
        GPIO_WriteLow(GPIOC,GPIO_PIN_7);
        SPI_SendData(0xac);
        delay();
        while(SPI_GetFlagStatus(SPI_FLAG_TXE)==RESET);
        // SPI_SendData(0xAA);
        // delay();
        // while(SPI_GetFlagStatus(SPI_FLAG_TXE)==RESET);
        // SPI_SendData(0xFF);
        // delay();
        // while(SPI_GetFlagStatus(SPI_FLAG_TXE)==RESET);
        // SPI_SendData(0xAA);
        // delay();
        // while(SPI_GetFlagStatus(SPI_FLAG_TXE)==RESET);
        // SPI_SendData(0xFF);
        // delay();
        // while(SPI_GetFlagStatus(SPI_FLAG_TXE)==RESET);
        // SPI_SendData(0xAA);
        // delay();
        while(SPI_GetFlagStatus(SPI_FLAG_TXE)==RESET);
        GPIO_WriteLow(GPIOC,GPIO_PIN_7);
    }
}

// void TIM4_UPD_OVF_IRQHandler(void) __interrupt(23)
// {

// }
