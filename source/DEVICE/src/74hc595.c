#include "74hc595.h"

/**
 * @brief   74hc595初始化
 **/
void HC595_Init(void)
{
    GPIO_Init(GPIOC,GPIO_PIN_5,GPIO_MODE_OUT_PP_LOW_FAST);//PC5 SHCP 复用功能
    GPIO_Init(GPIOC,GPIO_PIN_6,GPIO_MODE_OUT_PP_LOW_FAST);//PC6 DATA 复用功能
    GPIO_Init(GPIOC,GPIO_PIN_7,GPIO_MODE_OUT_PP_LOW_FAST);//PC7 STCP 普通IO口
    SPI_DeInit();
    //初始化SPI：
    SPI_Init(SPI_FIRSTBIT_LSB,
             SPI_BAUDRATEPRESCALER_256,
             SPI_MODE_MASTER,
             SPI_CLOCKPOLARITY_LOW,
             SPI_CLOCKPHASE_1EDGE,
             SPI_DATADIRECTION_1LINE_TX,
             SPI_NSS_SOFT,
             0x07);
    SPI_Cmd(ENABLE);
}