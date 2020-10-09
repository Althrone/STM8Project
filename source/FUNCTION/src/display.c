#include "display.h"

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

/**
 * @brief   对四个管子的数据进行译码
 **/
void DISP_ShowNumber(void)
{
    uint16_t tube1,tube2,tube3,tube4;
    tube1=DISP_TubeSet(1,1,CHAR2);
    tube2=DISP_TubeSet(2,1,CHAR0);
    tube3=DISP_TubeSet(3,1,CHAR1);
    tube4=DISP_TubeSet(4,1,CHAR9);
    uint8_t tmp1,tmp2;

    GPIO_WriteLow(GPIOC,GPIO_PIN_7);

    //处理U6
    tmp1=(uint8_t)((tube4&0b11111110)>>1);
    tmp2=(uint8_t)((tube4&0b00000001)<<7);
    tmp1=tmp1|tmp2;
    SPI_SendData(tmp1);delay();
    while(SPI_GetFlagStatus(SPI_FLAG_TXE)==RESET);
    //处理U5
    tmp1=(uint8_t)((tube3&0b1111)<<4);
    tmp2=(uint8_t)(tube4>>8);
    tmp1=tmp1|tmp2;
    tmp2=(tmp1&0b00000001)<<7;
    tmp1=(tmp1>>1)|tmp2;
    SPI_SendData(tmp1);delay();
    while(SPI_GetFlagStatus(SPI_FLAG_TXE)==RESET);
    //处理U4
    tmp1=(uint8_t)(tube3>>5);
    tmp2=(uint8_t)(((tube3&0b10000)>>4)<<7);
    tmp1=tmp1|tmp2;
    SPI_SendData(tmp1);delay();
    while(SPI_GetFlagStatus(SPI_FLAG_TXE)==RESET);

    //处理U3
    tmp1=(uint8_t)((tube2&0b11111110)>>1);
    tmp2=(uint8_t)((tube2&0b00000001)<<7);
    tmp1=tmp1|tmp2;
    SPI_SendData(tmp1);delay();
    while(SPI_GetFlagStatus(SPI_FLAG_TXE)==RESET);
    //处理U2
    tmp1=(uint8_t)((tube1&0b1111)<<4);
    tmp2=(uint8_t)(tube2>>8);
    tmp1=tmp1|tmp2;
    tmp2=(tmp1&0b00000001)<<7;
    tmp1=(tmp1>>1)|tmp2;
    SPI_SendData(tmp1);delay();
    while(SPI_GetFlagStatus(SPI_FLAG_TXE)==RESET);
    //处理U1
    tmp1=(uint8_t)(tube1>>5);
    tmp2=(uint8_t)(((tube1&0b10000)>>4)<<7);
    tmp1=tmp1|tmp2;
    SPI_SendData(tmp1);delay();
    while(SPI_GetFlagStatus(SPI_FLAG_TXE)==RESET);

    GPIO_WriteHigh(GPIOC,GPIO_PIN_7);
}

/**
 * @brief   指定辉光管显示的字符
 * @param   TubeNumber: 对于四位辉光钟，管子编号是1到4
 * @param   TubeState: 控制阳极通断
 * @param   DisplayChar: 显示什么字符
 **/
uint16_t DISP_TubeSet(uint8_t TubeNumber,uint8_t TubeState,uint16_t DisplayChar)
{
    //从参数获得的数据按照.1234567890A的顺序编排
    DisplayChar=DisplayChar|TubeState;
    //两两交换，变成1.32547698A0
    uint16_t tmp;
    tmp=(DisplayChar&0xAAA)>>1;
    DisplayChar=(DisplayChar&0x555)<<1;
    DisplayChar=DisplayChar|tmp;
    return DisplayChar;
}