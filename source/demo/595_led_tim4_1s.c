#include "../include/config.h"

//用定时器中断点个灯

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

void pb5_init()
{
    PB_DDR|=PX_DDR_DDR5;//DDR PB5输出模式
    PB_CR1|=PX_CR1_C15; //CR1 推挽输出
    PB_CR2|=PX_CR2_C25; //CR2 输出速度10MHz
}

void spi_init()//PC6 PC5
{//最快是10MHz，595可以撑100MHz
    PC_DDR|=PX_DDR_DDR5;//SPI_SCK  clk
    PC_DDR|=PX_DDR_DDR6;//SPI_MOSI hcp
    PC_DDR|=PX_DDR_DDR7;//tcp
    PC_CR1|=PX_CR1_C15;
    PC_CR1|=PX_CR1_C16;
    PC_CR1|=PX_CR1_C17;
    PC_CR2|=PX_CR2_C25;
    PC_CR2|=PX_CR2_C26;
    PC_CR2|=PX_CR2_C27;

    SPI_CR1=SPIX_CR1_BR_DIV128;//波特率二分频
    SPI_CR2|=(SPIX_CR2_SSM|
              SPIX_CR2_SSI|
              SPIX_CR2_BDM|
              SPIX_CR2_BDOE
              );
    SPI_CR1|=SPIX_CR1_LSBFIRST;
    SPI_CR1|=SPIX_CR1_MSTR;
    SPI_CR1|=SPIX_CR1_SPE;
}

void tim4_init()//16MHz输入
{
    TIM4_PSCR|=TIMX_PSCR_PSC_(8);//定时器分频 计数器速度2MHz
    TIM4_ARR|=TIMX_ARR_ARR_(56);//自动重装载值 0.1ms
    TIM4_IER|=TIMX_IER_UIE;//开中断
    TIM4_CR1|=TIMX_CR1_APRE;//自动重装载预装载
    TIM4_CR1|=TIMX_CR1_CEN;//计时器使能
}

uint8_t num=1;

uint16_t all_tmp=0;

void TIM4_UPD_OVF_IRQHandler(void) __interrupt(23)
{
    if((TIM4_SR&TIMX_SR_UIF)==TIMX_SR_UIF)//计数器溢出
    {
        TIM4_SR&=~TIMX_SR_UIF;
        all_tmp++;
        if (all_tmp>=1000)
        {
            all_tmp=0;
            if((PB_ODR&PX_ODR_ODR5)==PX_ODR_ODR5)
                PB_ODR&=~PX_ODR_ODR5;
            else
                PB_ODR|=PX_ODR_ODR5;
            
            uint8_t a1,a2,a3;
            a1=0x01<<num;
            a2=0x01<<(num-8);
            a3=0x01<<(num-16);

            PC_DDR&=~PX_DDR_DDR7;
            while((SPI_SR&SPIX_SR_TXE)!=SPIX_SR_TXE);
            SPI_DR=SPIX_DR_DR_(a1);
            while((SPI_SR&SPIX_SR_TXE)!=SPIX_SR_TXE);
            SPI_DR=SPIX_DR_DR_(a2);
            while((SPI_SR&SPIX_SR_TXE)!=SPIX_SR_TXE);
            SPI_DR=SPIX_DR_DR_(a3);
            while((SPI_SR&SPIX_SR_TXE)!=SPIX_SR_TXE);
            PC_DDR|=PX_DDR_DDR7;
            num++;
            if(num==25)
            num=1;
            

        }
    }
}



void main()
{
    clk_init();
    pb5_init();
    tim4_init();
    rim();
    spi_init();
    while(1)
    {
        
    }
}