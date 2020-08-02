;--------------------------------------------------------
; File Created by SDCC : free open source ANSI-C Compiler
; Version 4.0.0 #11528 (MINGW64)
;--------------------------------------------------------
	.module main
	.optsdcc -mstm8
	
;--------------------------------------------------------
; Public variables in this module
;--------------------------------------------------------
	.globl _main
	.globl _TIM4_UPD_OVF_IRQHandler
	.globl _tim4_init
	.globl _pb5_init
	.globl _clk_init
	.globl _all_tmp
;--------------------------------------------------------
; ram data
;--------------------------------------------------------
	.area DATA
;--------------------------------------------------------
; ram data
;--------------------------------------------------------
	.area INITIALIZED
_all_tmp::
	.ds 2
;--------------------------------------------------------
; Stack segment in internal ram 
;--------------------------------------------------------
	.area	SSEG
__start__stack:
	.ds	1

;--------------------------------------------------------
; absolute external ram data
;--------------------------------------------------------
	.area DABS (ABS)

; default segment ordering for linker
	.area HOME
	.area GSINIT
	.area GSFINAL
	.area CONST
	.area INITIALIZER
	.area CODE

;--------------------------------------------------------
; interrupt vector 
;--------------------------------------------------------
	.area HOME
__interrupt_vect:
	int s_GSINIT ; reset
	int 0x000000 ; trap
	int 0x000000 ; int0
	int 0x000000 ; int1
	int 0x000000 ; int2
	int 0x000000 ; int3
	int 0x000000 ; int4
	int 0x000000 ; int5
	int 0x000000 ; int6
	int 0x000000 ; int7
	int 0x000000 ; int8
	int 0x000000 ; int9
	int 0x000000 ; int10
	int 0x000000 ; int11
	int 0x000000 ; int12
	int 0x000000 ; int13
	int 0x000000 ; int14
	int 0x000000 ; int15
	int 0x000000 ; int16
	int 0x000000 ; int17
	int 0x000000 ; int18
	int 0x000000 ; int19
	int 0x000000 ; int20
	int 0x000000 ; int21
	int 0x000000 ; int22
	int _TIM4_UPD_OVF_IRQHandler ; int23
;--------------------------------------------------------
; global & static initialisations
;--------------------------------------------------------
	.area HOME
	.area GSINIT
	.area GSFINAL
	.area GSINIT
__sdcc_gs_init_startup:
__sdcc_init_data:
; stm8_genXINIT() start
	ldw x, #l_DATA
	jreq	00002$
00001$:
	clr (s_DATA - 1, x)
	decw x
	jrne	00001$
00002$:
	ldw	x, #l_INITIALIZER
	jreq	00004$
00003$:
	ld	a, (s_INITIALIZER - 1, x)
	ld	(s_INITIALIZED - 1, x), a
	decw	x
	jrne	00003$
00004$:
; stm8_genXINIT() end
	.area GSFINAL
	jp	__sdcc_program_startup
;--------------------------------------------------------
; Home
;--------------------------------------------------------
	.area HOME
	.area HOME
__sdcc_program_startup:
	jp	_main
;	return from main will return to caller
;--------------------------------------------------------
; code
;--------------------------------------------------------
	.area CODE
;	main.c: 5: void clk_init()
;	-----------------------------------------
;	 function clk_init
;	-----------------------------------------
_clk_init:
;	main.c: 8: while((CLK_ICKR&CLK_ICKR_HSIRDY)!=CLK_ICKR_HSIRDY);//检查HSI准备好没有
00101$:
	ld	a, 0x50c0
	and	a, #0x02
	cp	a, #0x02
	jrne	00101$
;	main.c: 9: while((CLK_CMSR&CLK_CMSR_CKM_HSI)!=CLK_CMSR_CKM_HSI);//检查主时钟是否为HSI
00104$:
	ld	a, 0x50c3
	and	a, #0xe1
	cp	a, #0xe1
	jrne	00104$
;	main.c: 10: CLK_CKDIVR&=~CLK_CKDIVR_HSIDIV_MASK;
	ld	a, 0x50c6
	and	a, #0xe7
	ld	0x50c6, a
;	main.c: 11: CLK_CKDIVR|=CLK_CKDIVR_HSIDIV_DIV1;//HSI作为主时钟最初是8分频，变成1分频快点
	ld	a, 0x50c6
	ld	0x50c6, a
;	main.c: 12: CLK_PCKENR1&=~(CLK_PCKENR1_I2C|
	ld	a, 0x50c7
	and	a, #0x54
	ld	0x50c7, a
;	main.c: 17: CLK_PCKENR2&=~(CLK_PCKENR2_ADC|
	ld	a, 0x50ca
	and	a, #0xf3
	ld	0x50ca, a
;	main.c: 20: }
	ret
;	main.c: 22: void pb5_init()
;	-----------------------------------------
;	 function pb5_init
;	-----------------------------------------
_pb5_init:
;	main.c: 24: PB_DDR|=PX_DDR_DDR5;//DDR PB5输出模式
	bset	20487, #5
;	main.c: 25: PB_CR1|=PX_CR1_C15; //CR1 推挽输出
	bset	20488, #5
;	main.c: 26: PB_CR2|=PX_CR2_C25; //CR2 输出速度10MHz
	bset	20489, #5
;	main.c: 27: }
	ret
;	main.c: 29: void tim4_init()//16MHz输入
;	-----------------------------------------
;	 function tim4_init
;	-----------------------------------------
_tim4_init:
;	main.c: 31: TIM4_PSCR|=TIMX_PSCR_PSC_(8);//定时器分频 计数器速度2MHz
	bset	21319, #2
;	main.c: 32: TIM4_ARR|=TIMX_ARR_ARR_(56);//自动重装载值 0.1ms
	ld	a, 0x5348
	or	a, #0x37
	ld	0x5348, a
;	main.c: 33: TIM4_IER|=TIMX_IER_UIE;//开中断
	bset	21315, #0
;	main.c: 34: TIM4_CR1|=TIMX_CR1_APRE;//自动重装载预装载
	bset	21312, #7
;	main.c: 35: TIM4_CR1|=TIMX_CR1_CEN;//计时器使能
	bset	21312, #0
;	main.c: 36: }
	ret
;	main.c: 45: void TIM4_UPD_OVF_IRQHandler(void) __interrupt(23)
;	-----------------------------------------
;	 function TIM4_UPD_OVF_IRQHandler
;	-----------------------------------------
_TIM4_UPD_OVF_IRQHandler:
;	main.c: 47: if((TIM4_SR&TIMX_SR_UIF)==TIMX_SR_UIF)//计数器溢出
	ld	a, 0x5344
	and	a, #0x01
	dec	a
	jrne	00108$
;	main.c: 49: TIM4_SR&=~TIMX_SR_UIF;
	bres	21316, #0
;	main.c: 50: all_tmp++;
	ldw	x, _all_tmp+0
	incw	x
;	main.c: 51: if (all_tmp>=1000)
	ldw	_all_tmp+0, x
	cpw	x, #0x03e8
	jrc	00108$
;	main.c: 53: all_tmp=0;
	clrw	x
	ldw	_all_tmp+0, x
;	main.c: 54: if((PB_ODR&PX_ODR_ODR5)==PX_ODR_ODR5)
	ld	a, 0x5005
	and	a, #0x20
	ld	xl, a
	ld	a, 0x5005
	push	a
	ld	a, xl
	cp	a, #0x20
	pop	a
	jrne	00102$
;	main.c: 55: PB_ODR&=~PX_ODR_ODR5;
	and	a, #0xdf
	ld	0x5005, a
	jra	00108$
00102$:
;	main.c: 57: PB_ODR|=PX_ODR_ODR5;
	or	a, #0x20
	ld	0x5005, a
00108$:
;	main.c: 69: }
	iret
;	main.c: 71: void main()
;	-----------------------------------------
;	 function main
;	-----------------------------------------
_main:
;	main.c: 73: clk_init();
	call	_clk_init
;	main.c: 74: pb5_init();
	call	_pb5_init
;	main.c: 75: tim4_init();
	call	_tim4_init
;	main.c: 76: rim();
	rim
;	main.c: 77: while(1)
00102$:
	jra	00102$
;	main.c: 84: }
	ret
	.area CODE
	.area CONST
	.area INITIALIZER
__xinit__all_tmp:
	.dw #0x0000
	.area CABS (ABS)
