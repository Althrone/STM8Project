                                      1 ;--------------------------------------------------------
                                      2 ; File Created by SDCC : free open source ANSI-C Compiler
                                      3 ; Version 4.0.0 #11528 (MINGW64)
                                      4 ;--------------------------------------------------------
                                      5 	.module main
                                      6 	.optsdcc -mstm8
                                      7 	
                                      8 ;--------------------------------------------------------
                                      9 ; Public variables in this module
                                     10 ;--------------------------------------------------------
                                     11 	.globl _main
                                     12 	.globl _GPIO_WriteReverse
                                     13 	.globl _GPIO_WriteHigh
                                     14 	.globl _GPIO_Init
                                     15 ;--------------------------------------------------------
                                     16 ; ram data
                                     17 ;--------------------------------------------------------
                                     18 	.area DATA
                                     19 ;--------------------------------------------------------
                                     20 ; ram data
                                     21 ;--------------------------------------------------------
                                     22 	.area INITIALIZED
                                     23 ;--------------------------------------------------------
                                     24 ; Stack segment in internal ram 
                                     25 ;--------------------------------------------------------
                                     26 	.area	SSEG
      FFFFFF                         27 __start__stack:
      FFFFFF                         28 	.ds	1
                                     29 
                                     30 ;--------------------------------------------------------
                                     31 ; absolute external ram data
                                     32 ;--------------------------------------------------------
                                     33 	.area DABS (ABS)
                                     34 
                                     35 ; default segment ordering for linker
                                     36 	.area HOME
                                     37 	.area GSINIT
                                     38 	.area GSFINAL
                                     39 	.area CONST
                                     40 	.area INITIALIZER
                                     41 	.area CODE
                                     42 
                                     43 ;--------------------------------------------------------
                                     44 ; interrupt vector 
                                     45 ;--------------------------------------------------------
                                     46 	.area HOME
      008000                         47 __interrupt_vect:
      008000 82 00 80 07             48 	int s_GSINIT ; reset
                                     49 ;--------------------------------------------------------
                                     50 ; global & static initialisations
                                     51 ;--------------------------------------------------------
                                     52 	.area HOME
                                     53 	.area GSINIT
                                     54 	.area GSFINAL
                                     55 	.area GSINIT
      008007                         56 __sdcc_gs_init_startup:
      008007                         57 __sdcc_init_data:
                                     58 ; stm8_genXINIT() start
      008007 AE 00 00         [ 2]   59 	ldw x, #l_DATA
      00800A 27 07            [ 1]   60 	jreq	00002$
      00800C                         61 00001$:
      00800C 72 4F 00 00      [ 1]   62 	clr (s_DATA - 1, x)
      008010 5A               [ 2]   63 	decw x
      008011 26 F9            [ 1]   64 	jrne	00001$
      008013                         65 00002$:
      008013 AE 00 00         [ 2]   66 	ldw	x, #l_INITIALIZER
      008016 27 09            [ 1]   67 	jreq	00004$
      008018                         68 00003$:
      008018 D6 80 41         [ 1]   69 	ld	a, (s_INITIALIZER - 1, x)
      00801B D7 00 00         [ 1]   70 	ld	(s_INITIALIZED - 1, x), a
      00801E 5A               [ 2]   71 	decw	x
      00801F 26 F7            [ 1]   72 	jrne	00003$
      008021                         73 00004$:
                                     74 ; stm8_genXINIT() end
                                     75 	.area GSFINAL
      008021 CC 80 04         [ 2]   76 	jp	__sdcc_program_startup
                                     77 ;--------------------------------------------------------
                                     78 ; Home
                                     79 ;--------------------------------------------------------
                                     80 	.area HOME
                                     81 	.area HOME
      008004                         82 __sdcc_program_startup:
      008004 CC 80 42         [ 2]   83 	jp	_main
                                     84 ;	return from main will return to caller
                                     85 ;--------------------------------------------------------
                                     86 ; code
                                     87 ;--------------------------------------------------------
                                     88 	.area CODE
                                     89 ;	source/USER/main.c: 103: void main()
                                     90 ;	-----------------------------------------
                                     91 ;	 function main
                                     92 ;	-----------------------------------------
      008042                         93 _main:
                                     94 ;	source/USER/main.c: 114: GPIO_Init(GPIOB,GPIO_PIN_5,GPIO_MODE_OUT_PP_LOW_FAST);
      008042 4B E0            [ 1]   95 	push	#0xe0
      008044 4B 20            [ 1]   96 	push	#0x20
      008046 4B 05            [ 1]   97 	push	#0x05
      008048 4B 50            [ 1]   98 	push	#0x50
      00804A CD 80 86         [ 4]   99 	call	_GPIO_Init
      00804D 5B 04            [ 2]  100 	addw	sp, #4
                                    101 ;	source/USER/main.c: 115: GPIO_WriteHigh(GPIOB,GPIO_PIN_5);
      00804F 4B 20            [ 1]  102 	push	#0x20
      008051 4B 05            [ 1]  103 	push	#0x05
      008053 4B 50            [ 1]  104 	push	#0x50
      008055 CD 81 69         [ 4]  105 	call	_GPIO_WriteHigh
      008058 5B 03            [ 2]  106 	addw	sp, #3
                                    107 ;	source/USER/main.c: 117: while(1)
      00805A                        108 00104$:
                                    109 ;	source/USER/main.c: 119: GPIO_WriteReverse(GPIOB,GPIO_PIN_5);
      00805A 4B 20            [ 1]  110 	push	#0x20
      00805C 4B 05            [ 1]  111 	push	#0x05
      00805E 4B 50            [ 1]  112 	push	#0x50
      008060 CD 81 7E         [ 4]  113 	call	_GPIO_WriteReverse
      008063 5B 03            [ 2]  114 	addw	sp, #3
                                    115 ;	source/USER/main.c: 120: for(char i=0;i<200;i++)
      008065 5F               [ 1]  116 	clrw	x
      008066                        117 00110$:
      008066 9F               [ 1]  118 	ld	a, xl
      008067 A1 C8            [ 1]  119 	cp	a, #0xc8
      008069 24 EF            [ 1]  120 	jrnc	00104$
                                    121 ;	source/USER/main.c: 122: for(char j=0;j<200;j++);
      00806B 4F               [ 1]  122 	clr	a
      00806C                        123 00107$:
      00806C A1 C8            [ 1]  124 	cp	a, #0xc8
      00806E 24 03            [ 1]  125 	jrnc	00111$
      008070 4C               [ 1]  126 	inc	a
      008071 20 F9            [ 2]  127 	jra	00107$
      008073                        128 00111$:
                                    129 ;	source/USER/main.c: 120: for(char i=0;i<200;i++)
      008073 5C               [ 1]  130 	incw	x
      008074 20 F0            [ 2]  131 	jra	00110$
                                    132 ;	source/USER/main.c: 126: }
      008076 81               [ 4]  133 	ret
                                    134 	.area CODE
                                    135 	.area CONST
                                    136 	.area INITIALIZER
                                    137 	.area CABS (ABS)
