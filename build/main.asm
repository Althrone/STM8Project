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
	.globl _GPIO_WriteReverse
	.globl _GPIO_WriteHigh
	.globl _GPIO_Init
;--------------------------------------------------------
; ram data
;--------------------------------------------------------
	.area DATA
;--------------------------------------------------------
; ram data
;--------------------------------------------------------
	.area INITIALIZED
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
;	source/USER/main.c: 103: void main()
;	-----------------------------------------
;	 function main
;	-----------------------------------------
_main:
;	source/USER/main.c: 117: GPIO_Init(GPIOB,GPIO_PIN_5,GPIO_MODE_OUT_PP_LOW_FAST);
	push	#0xe0
	push	#0x20
	push	#0x05
	push	#0x50
	call	_GPIO_Init
	addw	sp, #4
;	source/USER/main.c: 118: GPIO_WriteHigh(GPIOB,GPIO_PIN_5);
	push	#0x20
	push	#0x05
	push	#0x50
	call	_GPIO_WriteHigh
	addw	sp, #3
;	source/USER/main.c: 120: while(1)
00104$:
;	source/USER/main.c: 122: GPIO_WriteReverse(GPIOB,GPIO_PIN_5);
	push	#0x20
	push	#0x05
	push	#0x50
	call	_GPIO_WriteReverse
	addw	sp, #3
;	source/USER/main.c: 123: for(char i=0;i<200;i++)
	clrw	x
00110$:
	ld	a, xl
	cp	a, #0xc8
	jrnc	00104$
;	source/USER/main.c: 125: for(char j=0;j<200;j++);
	clr	a
00107$:
	cp	a, #0xc8
	jrnc	00111$
	inc	a
	jra	00107$
00111$:
;	source/USER/main.c: 123: for(char i=0;i<200;i++)
	incw	x
	jra	00110$
;	source/USER/main.c: 129: }
	ret
	.area CODE
	.area CONST
	.area INITIALIZER
	.area CABS (ABS)
