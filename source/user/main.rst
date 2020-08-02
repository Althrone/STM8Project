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
                                     12 	.globl _TIM4_UPD_OVF_IRQHandler
                                     13 	.globl _tim4_init
                                     14 	.globl _pb5_init
                                     15 	.globl _clk_init
                                     16 	.globl _all_tmp
                                     17 ;--------------------------------------------------------
                                     18 ; ram data
                                     19 ;--------------------------------------------------------
                                     20 	.area DATA
                                     21 ;--------------------------------------------------------
                                     22 ; ram data
                                     23 ;--------------------------------------------------------
                                     24 	.area INITIALIZED
      000001                         25 _all_tmp::
      000001                         26 	.ds 2
                                     27 ;--------------------------------------------------------
                                     28 ; Stack segment in internal ram 
                                     29 ;--------------------------------------------------------
                                     30 	.area	SSEG
      FFFFFF                         31 __start__stack:
      FFFFFF                         32 	.ds	1
                                     33 
                                     34 ;--------------------------------------------------------
                                     35 ; absolute external ram data
                                     36 ;--------------------------------------------------------
                                     37 	.area DABS (ABS)
                                     38 
                                     39 ; default segment ordering for linker
                                     40 	.area HOME
                                     41 	.area GSINIT
                                     42 	.area GSFINAL
                                     43 	.area CONST
                                     44 	.area INITIALIZER
                                     45 	.area CODE
                                     46 
                                     47 ;--------------------------------------------------------
                                     48 ; interrupt vector 
                                     49 ;--------------------------------------------------------
                                     50 	.area HOME
      008000                         51 __interrupt_vect:
      008000 82 00 80 6B             52 	int s_GSINIT ; reset
      008004 82 00 00 00             53 	int 0x000000 ; trap
      008008 82 00 00 00             54 	int 0x000000 ; int0
      00800C 82 00 00 00             55 	int 0x000000 ; int1
      008010 82 00 00 00             56 	int 0x000000 ; int2
      008014 82 00 00 00             57 	int 0x000000 ; int3
      008018 82 00 00 00             58 	int 0x000000 ; int4
      00801C 82 00 00 00             59 	int 0x000000 ; int5
      008020 82 00 00 00             60 	int 0x000000 ; int6
      008024 82 00 00 00             61 	int 0x000000 ; int7
      008028 82 00 00 00             62 	int 0x000000 ; int8
      00802C 82 00 00 00             63 	int 0x000000 ; int9
      008030 82 00 00 00             64 	int 0x000000 ; int10
      008034 82 00 00 00             65 	int 0x000000 ; int11
      008038 82 00 00 00             66 	int 0x000000 ; int12
      00803C 82 00 00 00             67 	int 0x000000 ; int13
      008040 82 00 00 00             68 	int 0x000000 ; int14
      008044 82 00 00 00             69 	int 0x000000 ; int15
      008048 82 00 00 00             70 	int 0x000000 ; int16
      00804C 82 00 00 00             71 	int 0x000000 ; int17
      008050 82 00 00 00             72 	int 0x000000 ; int18
      008054 82 00 00 00             73 	int 0x000000 ; int19
      008058 82 00 00 00             74 	int 0x000000 ; int20
      00805C 82 00 00 00             75 	int 0x000000 ; int21
      008060 82 00 00 00             76 	int 0x000000 ; int22
      008064 82 00 80 E1             77 	int _TIM4_UPD_OVF_IRQHandler ; int23
                                     78 ;--------------------------------------------------------
                                     79 ; global & static initialisations
                                     80 ;--------------------------------------------------------
                                     81 	.area HOME
                                     82 	.area GSINIT
                                     83 	.area GSFINAL
                                     84 	.area GSINIT
      00806B                         85 __sdcc_gs_init_startup:
      00806B                         86 __sdcc_init_data:
                                     87 ; stm8_genXINIT() start
      00806B AE 00 00         [ 2]   88 	ldw x, #l_DATA
      00806E 27 07            [ 1]   89 	jreq	00002$
      008070                         90 00001$:
      008070 72 4F 00 00      [ 1]   91 	clr (s_DATA - 1, x)
      008074 5A               [ 2]   92 	decw x
      008075 26 F9            [ 1]   93 	jrne	00001$
      008077                         94 00002$:
      008077 AE 00 02         [ 2]   95 	ldw	x, #l_INITIALIZER
      00807A 27 09            [ 1]   96 	jreq	00004$
      00807C                         97 00003$:
      00807C D6 80 87         [ 1]   98 	ld	a, (s_INITIALIZER - 1, x)
      00807F D7 00 00         [ 1]   99 	ld	(s_INITIALIZED - 1, x), a
      008082 5A               [ 2]  100 	decw	x
      008083 26 F7            [ 1]  101 	jrne	00003$
      008085                        102 00004$:
                                    103 ; stm8_genXINIT() end
                                    104 	.area GSFINAL
      008085 CC 80 68         [ 2]  105 	jp	__sdcc_program_startup
                                    106 ;--------------------------------------------------------
                                    107 ; Home
                                    108 ;--------------------------------------------------------
                                    109 	.area HOME
                                    110 	.area HOME
      008068                        111 __sdcc_program_startup:
      008068 CC 81 1A         [ 2]  112 	jp	_main
                                    113 ;	return from main will return to caller
                                    114 ;--------------------------------------------------------
                                    115 ; code
                                    116 ;--------------------------------------------------------
                                    117 	.area CODE
                                    118 ;	main.c: 5: void clk_init()
                                    119 ;	-----------------------------------------
                                    120 ;	 function clk_init
                                    121 ;	-----------------------------------------
      00808A                        122 _clk_init:
                                    123 ;	main.c: 8: while((CLK_ICKR&CLK_ICKR_HSIRDY)!=CLK_ICKR_HSIRDY);//检查HSI准备好没有
      00808A                        124 00101$:
      00808A C6 50 C0         [ 1]  125 	ld	a, 0x50c0
      00808D A4 02            [ 1]  126 	and	a, #0x02
      00808F A1 02            [ 1]  127 	cp	a, #0x02
      008091 26 F7            [ 1]  128 	jrne	00101$
                                    129 ;	main.c: 9: while((CLK_CMSR&CLK_CMSR_CKM_HSI)!=CLK_CMSR_CKM_HSI);//检查主时钟是否为HSI
      008093                        130 00104$:
      008093 C6 50 C3         [ 1]  131 	ld	a, 0x50c3
      008096 A4 E1            [ 1]  132 	and	a, #0xe1
      008098 A1 E1            [ 1]  133 	cp	a, #0xe1
      00809A 26 F7            [ 1]  134 	jrne	00104$
                                    135 ;	main.c: 10: CLK_CKDIVR&=~CLK_CKDIVR_HSIDIV_MASK;
      00809C C6 50 C6         [ 1]  136 	ld	a, 0x50c6
      00809F A4 E7            [ 1]  137 	and	a, #0xe7
      0080A1 C7 50 C6         [ 1]  138 	ld	0x50c6, a
                                    139 ;	main.c: 11: CLK_CKDIVR|=CLK_CKDIVR_HSIDIV_DIV1;//HSI作为主时钟最初是8分频，变成1分频快点
      0080A4 C6 50 C6         [ 1]  140 	ld	a, 0x50c6
      0080A7 C7 50 C6         [ 1]  141 	ld	0x50c6, a
                                    142 ;	main.c: 12: CLK_PCKENR1&=~(CLK_PCKENR1_I2C|
      0080AA C6 50 C7         [ 1]  143 	ld	a, 0x50c7
      0080AD A4 54            [ 1]  144 	and	a, #0x54
      0080AF C7 50 C7         [ 1]  145 	ld	0x50c7, a
                                    146 ;	main.c: 17: CLK_PCKENR2&=~(CLK_PCKENR2_ADC|
      0080B2 C6 50 CA         [ 1]  147 	ld	a, 0x50ca
      0080B5 A4 F3            [ 1]  148 	and	a, #0xf3
      0080B7 C7 50 CA         [ 1]  149 	ld	0x50ca, a
                                    150 ;	main.c: 20: }
      0080BA 81               [ 4]  151 	ret
                                    152 ;	main.c: 22: void pb5_init()
                                    153 ;	-----------------------------------------
                                    154 ;	 function pb5_init
                                    155 ;	-----------------------------------------
      0080BB                        156 _pb5_init:
                                    157 ;	main.c: 24: PB_DDR|=PX_DDR_DDR5;//DDR PB5输出模式
      0080BB 72 1A 50 07      [ 1]  158 	bset	20487, #5
                                    159 ;	main.c: 25: PB_CR1|=PX_CR1_C15; //CR1 推挽输出
      0080BF 72 1A 50 08      [ 1]  160 	bset	20488, #5
                                    161 ;	main.c: 26: PB_CR2|=PX_CR2_C25; //CR2 输出速度10MHz
      0080C3 72 1A 50 09      [ 1]  162 	bset	20489, #5
                                    163 ;	main.c: 27: }
      0080C7 81               [ 4]  164 	ret
                                    165 ;	main.c: 29: void tim4_init()//16MHz输入
                                    166 ;	-----------------------------------------
                                    167 ;	 function tim4_init
                                    168 ;	-----------------------------------------
      0080C8                        169 _tim4_init:
                                    170 ;	main.c: 31: TIM4_PSCR|=TIMX_PSCR_PSC_(8);//定时器分频 计数器速度2MHz
      0080C8 72 14 53 47      [ 1]  171 	bset	21319, #2
                                    172 ;	main.c: 32: TIM4_ARR|=TIMX_ARR_ARR_(56);//自动重装载值 0.1ms
      0080CC C6 53 48         [ 1]  173 	ld	a, 0x5348
      0080CF AA 37            [ 1]  174 	or	a, #0x37
      0080D1 C7 53 48         [ 1]  175 	ld	0x5348, a
                                    176 ;	main.c: 33: TIM4_IER|=TIMX_IER_UIE;//开中断
      0080D4 72 10 53 43      [ 1]  177 	bset	21315, #0
                                    178 ;	main.c: 34: TIM4_CR1|=TIMX_CR1_APRE;//自动重装载预装载
      0080D8 72 1E 53 40      [ 1]  179 	bset	21312, #7
                                    180 ;	main.c: 35: TIM4_CR1|=TIMX_CR1_CEN;//计时器使能
      0080DC 72 10 53 40      [ 1]  181 	bset	21312, #0
                                    182 ;	main.c: 36: }
      0080E0 81               [ 4]  183 	ret
                                    184 ;	main.c: 45: void TIM4_UPD_OVF_IRQHandler(void) __interrupt(23)
                                    185 ;	-----------------------------------------
                                    186 ;	 function TIM4_UPD_OVF_IRQHandler
                                    187 ;	-----------------------------------------
      0080E1                        188 _TIM4_UPD_OVF_IRQHandler:
                                    189 ;	main.c: 47: if((TIM4_SR&TIMX_SR_UIF)==TIMX_SR_UIF)//计数器溢出
      0080E1 C6 53 44         [ 1]  190 	ld	a, 0x5344
      0080E4 A4 01            [ 1]  191 	and	a, #0x01
      0080E6 4A               [ 1]  192 	dec	a
      0080E7 26 30            [ 1]  193 	jrne	00108$
                                    194 ;	main.c: 49: TIM4_SR&=~TIMX_SR_UIF;
      0080E9 72 11 53 44      [ 1]  195 	bres	21316, #0
                                    196 ;	main.c: 50: all_tmp++;
      0080ED CE 00 01         [ 2]  197 	ldw	x, _all_tmp+0
      0080F0 5C               [ 1]  198 	incw	x
                                    199 ;	main.c: 51: if (all_tmp>=1000)
      0080F1 CF 00 01         [ 2]  200 	ldw	_all_tmp+0, x
      0080F4 A3 03 E8         [ 2]  201 	cpw	x, #0x03e8
      0080F7 25 20            [ 1]  202 	jrc	00108$
                                    203 ;	main.c: 53: all_tmp=0;
      0080F9 5F               [ 1]  204 	clrw	x
      0080FA CF 00 01         [ 2]  205 	ldw	_all_tmp+0, x
                                    206 ;	main.c: 54: if((PB_ODR&PX_ODR_ODR5)==PX_ODR_ODR5)
      0080FD C6 50 05         [ 1]  207 	ld	a, 0x5005
      008100 A4 20            [ 1]  208 	and	a, #0x20
      008102 97               [ 1]  209 	ld	xl, a
      008103 C6 50 05         [ 1]  210 	ld	a, 0x5005
      008106 88               [ 1]  211 	push	a
      008107 9F               [ 1]  212 	ld	a, xl
      008108 A1 20            [ 1]  213 	cp	a, #0x20
      00810A 84               [ 1]  214 	pop	a
      00810B 26 07            [ 1]  215 	jrne	00102$
                                    216 ;	main.c: 55: PB_ODR&=~PX_ODR_ODR5;
      00810D A4 DF            [ 1]  217 	and	a, #0xdf
      00810F C7 50 05         [ 1]  218 	ld	0x5005, a
      008112 20 05            [ 2]  219 	jra	00108$
      008114                        220 00102$:
                                    221 ;	main.c: 57: PB_ODR|=PX_ODR_ODR5;
      008114 AA 20            [ 1]  222 	or	a, #0x20
      008116 C7 50 05         [ 1]  223 	ld	0x5005, a
      008119                        224 00108$:
                                    225 ;	main.c: 69: }
      008119 80               [11]  226 	iret
                                    227 ;	main.c: 71: void main()
                                    228 ;	-----------------------------------------
                                    229 ;	 function main
                                    230 ;	-----------------------------------------
      00811A                        231 _main:
                                    232 ;	main.c: 73: clk_init();
      00811A CD 80 8A         [ 4]  233 	call	_clk_init
                                    234 ;	main.c: 74: pb5_init();
      00811D CD 80 BB         [ 4]  235 	call	_pb5_init
                                    236 ;	main.c: 75: tim4_init();
      008120 CD 80 C8         [ 4]  237 	call	_tim4_init
                                    238 ;	main.c: 76: rim();
      008123 9A               [ 1]  239 	rim
                                    240 ;	main.c: 77: while(1)
      008124                        241 00102$:
      008124 20 FE            [ 2]  242 	jra	00102$
                                    243 ;	main.c: 84: }
      008126 81               [ 4]  244 	ret
                                    245 	.area CODE
                                    246 	.area CONST
                                    247 	.area INITIALIZER
      008088                        248 __xinit__all_tmp:
      008088 00 00                  249 	.dw #0x0000
                                    250 	.area CABS (ABS)
