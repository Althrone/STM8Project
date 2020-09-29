#ifndef _ITC_H_
#define _ITC_H_

#define ISR(name,vector) void name(void) __interrupt(vector - 2)

#define AWU_vector                           0x03
#define EXTI_PORTA_vector                    0x05
#define EXTI_PORTB_vector                    0x06

/* Interrupt commands */
#define enableInterrupts()    {__asm__("rim\n");}  /* enable interrupts */
#define disableInterrupts()   {__asm__("sim\n");}  /* disable interrupts */
#define rim()                 {__asm__("rim\n");}  /* enable interrupts */
#define sim()                 {__asm__("sim\n");}  /* disable interrupts */
#define nop()                 {__asm__("nop\n");}  /* No Operation */
#define trap()                {__asm__("trap\n");} /* Trap (soft IT) */
#define wfi()                 {__asm__("wfi\n");}  /* Wait For Interrupt */
#define halt()                {__asm__("halt\n");} /* Halt */

// void TRAP_IRQHandler(void) __trap;
// void TLI_IRQHandler(void) __intreeupt(0);
// void AWU_IRQHandler(void) __intreeupt(1);
// void CLK_IRQHandler(void) __intreeupt(2);
// void EXTI_PORTA_IRQHandler(void) __intreeupt(3);
// void EXTI_PORTB_IRQHandler(void) __intreeupt(4);
// void EXTI_PORTC_IRQHandler(void) __intreeupt(5);
// void EXTI_PORTD_IRQHandler(void) __intreeupt(6);
// void EXTI_PORTE_IRQHandler(void) __intreeupt(7);
// //void (void) __intreeupt(8);
// //void (void) __intreeupt(9);
// void SPI_IRQHandler(void) __intreeupt(10);
// void TIM1_UPD_OVF_TRG_BRK_IRQHandler(void) __intreeupt(11);
// void TIM1_CAP_COM_IRQHandler(void) __intreeupt(12);
// void TIM2_UPD_OVF_BRK_IRQHandler(void) __intreeupt(13);
// void TIM2_CAP_COM_IRQHandler(void) __intreeupt(14);
// //void (void) __intreeupt(15);
// //void (void) __intreeupt(16);
// void UART1_TX_IRQHandler(void) __intreeupt(17);
// void UART1_RX_IRQHandler(void) __intreeupt(18);
// void I2C_IRQHandler(void) __intreeupt(19);
// void (void) __intreeupt(20);
// ////void (void) __intreeupt(21);
// void ADC1_IRQHandler(void) __intreeupt(22);
// void TIM4_UPD_OVF_IRQHandler(void) __intreeupt(23);
// void FLASH_IRQHandler(void) __intreeupt(24);

//#define INTERRUPT_HANDLER(a,b) a(void) __interrupt(b)

#endif /*_ITC_H_*/