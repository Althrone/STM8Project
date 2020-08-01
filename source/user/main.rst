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
                                     11 	.globl _TIM4_UPD_OVF_IRQHandler
                                     12 	.globl _main
                                     13 	.globl _delay
                                     14 	.globl _tim4_init
                                     15 	.globl _pb5_init
                                     16 	.globl _clk_init
                                     17 	.globl _all_tmp
                                     18 ;--------------------------------------------------------
                                     19 ; ram data
                                     20 ;--------------------------------------------------------
                                     21 	.area DATA
                                     22 ;--------------------------------------------------------
                                     23 ; ram data
                                     24 ;--------------------------------------------------------
                                     25 	.area INITIALIZED
      000001                         26 _all_tmp::
      000001                         27 	.ds 2
                                     28 ;--------------------------------------------------------
                                     29 ; Stack segment in internal ram 
                                     30 ;--------------------------------------------------------
                                     31 	.area	SSEG
      FFFFFF                         32 __start__stack:
      FFFFFF                         33 	.ds	1
                                     34 
                                     35 ;--------------------------------------------------------
                                     36 ; absolute external ram data
                                     37 ;--------------------------------------------------------
                                     38 	.area DABS (ABS)
                                     39 
                                     40 ; default segment ordering for linker
                                     41 	.area HOME
                                     42 	.area GSINIT
                                     43 	.area GSFINAL
                                     44 	.area CONST
                                     45 	.area INITIALIZER
                                     46 	.area CODE
                                     47 
                                     48 ;--------------------------------------------------------
                                     49 ; interrupt vector 
                                     50 ;--------------------------------------------------------
                                     51 	.area HOME
      008000                         52 __interrupt_vect:
      008000 82 00 80 6B             53 	int s_GSINIT ; reset
      008004 82 00 00 00             54 	int 0x000000 ; trap
      008008 82 00 00 00             55 	int 0x000000 ; int0
      00800C 82 00 00 00             56 	int 0x000000 ; int1
      008010 82 00 00 00             57 	int 0x000000 ; int2
      008014 82 00 00 00             58 	int 0x000000 ; int3
      008018 82 00 00 00             59 	int 0x000000 ; int4
      00801C 82 00 00 00             60 	int 0x000000 ; int5
      008020 82 00 00 00             61 	int 0x000000 ; int6
      008024 82 00 00 00             62 	int 0x000000 ; int7
      008028 82 00 00 00             63 	int 0x000000 ; int8
      00802C 82 00 00 00             64 	int 0x000000 ; int9
      008030 82 00 00 00             65 	int 0x000000 ; int10
      008034 82 00 00 00             66 	int 0x000000 ; int11
      008038 82 00 00 00             67 	int 0x000000 ; int12
      00803C 82 00 00 00             68 	int 0x000000 ; int13
      008040 82 00 00 00             69 	int 0x000000 ; int14
      008044 82 00 00 00             70 	int 0x000000 ; int15
      008048 82 00 00 00             71 	int 0x000000 ; int16
      00804C 82 00 00 00             72 	int 0x000000 ; int17
      008050 82 00 00 00             73 	int 0x000000 ; int18
      008054 82 00 00 00             74 	int 0x000000 ; int19
      008058 82 00 00 00             75 	int 0x000000 ; int20
      00805C 82 00 00 00             76 	int 0x000000 ; int21
      008060 82 00 00 00             77 	int 0x000000 ; int22
      008064 82 00 81 15             78 	int _TIM4_UPD_OVF_IRQHandler ; int23
                                     79 ;--------------------------------------------------------
                                     80 ; global & static initialisations
                                     81 ;--------------------------------------------------------
                                     82 	.area HOME
                                     83 	.area GSINIT
                                     84 	.area GSFINAL
                                     85 	.area GSINIT
      00806B                         86 __sdcc_gs_init_startup:
      00806B                         87 __sdcc_init_data:
                                     88 ; stm8_genXINIT() start
      00806B AE 00 00         [ 2]   89 	ldw x, #l_DATA
      00806E 27 07            [ 1]   90 	jreq	00002$
      008070                         91 00001$:
      008070 72 4F 00 00      [ 1]   92 	clr (s_DATA - 1, x)
      008074 5A               [ 2]   93 	decw x
      008075 26 F9            [ 1]   94 	jrne	00001$
      008077                         95 00002$:
      008077 AE 00 02         [ 2]   96 	ldw	x, #l_INITIALIZER
      00807A 27 09            [ 1]   97 	jreq	00004$
      00807C                         98 00003$:
      00807C D6 80 87         [ 1]   99 	ld	a, (s_INITIALIZER - 1, x)
      00807F D7 00 00         [ 1]  100 	ld	(s_INITIALIZED - 1, x), a
      008082 5A               [ 2]  101 	decw	x
      008083 26 F7            [ 1]  102 	jrne	00003$
      008085                        103 00004$:
                                    104 ; stm8_genXINIT() end
                                    105 	.area GSFINAL
      008085 CC 80 68         [ 2]  106 	jp	__sdcc_program_startup
                                    107 ;--------------------------------------------------------
                                    108 ; Home
                                    109 ;--------------------------------------------------------
                                    110 	.area HOME
                                    111 	.area HOME
      008068                        112 __sdcc_program_startup:
      008068 CC 81 09         [ 2]  113 	jp	_main
                                    114 ;	return from main will return to caller
                                    115 ;--------------------------------------------------------
                                    116 ; code
                                    117 ;--------------------------------------------------------
                                    118 	.area CODE
                                    119 ;	main.c: 5: void clk_init()
                                    120 ;	-----------------------------------------
                                    121 ;	 function clk_init
                                    122 ;	-----------------------------------------
      00808A                        123 _clk_init:
                                    124 ;	main.c: 8: while(CLK_ICKR&CLK_ICKR_HSIRDY!=CLK_ICKR_HSIRDY);//检查HSI准备好没有
      00808A                        125 00101$:
      00808A C6 50 C0         [ 1]  126 	ld	a, 0x50c0
      00808D 4F               [ 1]  127 	clr	a
      00808E 4D               [ 1]  128 	tnz	a
      00808F 26 F9            [ 1]  129 	jrne	00101$
                                    130 ;	main.c: 9: while(CLK_CMSR&CLK_CMSR_CKM_HSI!=CLK_CMSR_CKM_HSI);//检查主时钟是否为HSI
      008091                        131 00104$:
      008091 C6 50 C3         [ 1]  132 	ld	a, 0x50c3
      008094 4F               [ 1]  133 	clr	a
      008095 4D               [ 1]  134 	tnz	a
      008096 26 F9            [ 1]  135 	jrne	00104$
                                    136 ;	main.c: 10: CLK_CKDIVR&=~CLK_CKDIVR_HSIDIV_MASK;
      008098 C6 50 C6         [ 1]  137 	ld	a, 0x50c6
      00809B A4 E7            [ 1]  138 	and	a, #0xe7
      00809D C7 50 C6         [ 1]  139 	ld	0x50c6, a
                                    140 ;	main.c: 11: CLK_CKDIVR|=CLK_CKDIVR_HSIDIV_DIV1;//HSI作为主时钟最初是8分频，变成1分频快点
      0080A0 C6 50 C6         [ 1]  141 	ld	a, 0x50c6
      0080A3 C7 50 C6         [ 1]  142 	ld	0x50c6, a
                                    143 ;	main.c: 12: CLK_PCKENR1&=~(CLK_PCKENR1_I2C|
      0080A6 C6 50 C7         [ 1]  144 	ld	a, 0x50c7
      0080A9 A4 54            [ 1]  145 	and	a, #0x54
      0080AB C7 50 C7         [ 1]  146 	ld	0x50c7, a
                                    147 ;	main.c: 17: CLK_PCKENR2&=~(CLK_PCKENR2_ADC|
      0080AE C6 50 CA         [ 1]  148 	ld	a, 0x50ca
      0080B1 A4 F3            [ 1]  149 	and	a, #0xf3
      0080B3 C7 50 CA         [ 1]  150 	ld	0x50ca, a
                                    151 ;	main.c: 20: }
      0080B6 81               [ 4]  152 	ret
                                    153 ;	main.c: 22: void pb5_init()
                                    154 ;	-----------------------------------------
                                    155 ;	 function pb5_init
                                    156 ;	-----------------------------------------
      0080B7                        157 _pb5_init:
                                    158 ;	main.c: 24: PB_DDR|=PX_DDR_DDR5;//DDR PB5输出模式
      0080B7 72 1A 50 07      [ 1]  159 	bset	20487, #5
                                    160 ;	main.c: 25: PB_CR1|=PX_CR1_C15; //CR1 推挽输出
      0080BB 72 1A 50 08      [ 1]  161 	bset	20488, #5
                                    162 ;	main.c: 26: PB_CR2|=PX_CR2_C25; //CR2 输出速度10MHz
      0080BF 72 1A 50 09      [ 1]  163 	bset	20489, #5
                                    164 ;	main.c: 27: }
      0080C3 81               [ 4]  165 	ret
                                    166 ;	main.c: 29: void tim4_init()//16MHz输入
                                    167 ;	-----------------------------------------
                                    168 ;	 function tim4_init
                                    169 ;	-----------------------------------------
      0080C4                        170 _tim4_init:
                                    171 ;	main.c: 31: TIM4_PSCR|=TIMX_PSCR_PSC_(8);//定时器分频 计数器速度2MHz
      0080C4 72 14 53 47      [ 1]  172 	bset	21319, #2
                                    173 ;	main.c: 32: TIM4_ARR|=TIMX_ARR_ARR_(200);//自动重装载值 0.1ms
      0080C8 C6 53 48         [ 1]  174 	ld	a, 0x5348
      0080CB AA C7            [ 1]  175 	or	a, #0xc7
      0080CD C7 53 48         [ 1]  176 	ld	0x5348, a
                                    177 ;	main.c: 33: TIM4_IER|=TIMX_IER_UIE;//开中断
      0080D0 72 10 53 43      [ 1]  178 	bset	21315, #0
                                    179 ;	main.c: 34: TIM4_CR1|=TIMX_CR1_APRE;//自动重装载预装载
      0080D4 72 1E 53 40      [ 1]  180 	bset	21312, #7
                                    181 ;	main.c: 35: TIM4_CR1|=TIMX_CR1_CEN;//计时器使能
      0080D8 72 10 53 40      [ 1]  182 	bset	21312, #0
                                    183 ;	main.c: 36: }
      0080DC 81               [ 4]  184 	ret
                                    185 ;	main.c: 38: void delay(unsigned long count) {
                                    186 ;	-----------------------------------------
                                    187 ;	 function delay
                                    188 ;	-----------------------------------------
      0080DD                        189 _delay:
      0080DD 52 08            [ 2]  190 	sub	sp, #8
                                    191 ;	main.c: 39: while (count--)
      0080DF 16 0D            [ 2]  192 	ldw	y, (0x0d, sp)
      0080E1 17 07            [ 2]  193 	ldw	(0x07, sp), y
      0080E3 1E 0B            [ 2]  194 	ldw	x, (0x0b, sp)
      0080E5                        195 00101$:
      0080E5 1F 01            [ 2]  196 	ldw	(0x01, sp), x
      0080E7 7B 07            [ 1]  197 	ld	a, (0x07, sp)
      0080E9 6B 03            [ 1]  198 	ld	(0x03, sp), a
      0080EB 7B 08            [ 1]  199 	ld	a, (0x08, sp)
      0080ED 16 07            [ 2]  200 	ldw	y, (0x07, sp)
      0080EF 72 A2 00 01      [ 2]  201 	subw	y, #0x0001
      0080F3 17 07            [ 2]  202 	ldw	(0x07, sp), y
      0080F5 24 01            [ 1]  203 	jrnc	00117$
      0080F7 5A               [ 2]  204 	decw	x
      0080F8                        205 00117$:
      0080F8 4D               [ 1]  206 	tnz	a
      0080F9 26 08            [ 1]  207 	jrne	00118$
      0080FB 16 02            [ 2]  208 	ldw	y, (0x02, sp)
      0080FD 26 04            [ 1]  209 	jrne	00118$
      0080FF 0D 01            [ 1]  210 	tnz	(0x01, sp)
      008101 27 03            [ 1]  211 	jreq	00104$
      008103                        212 00118$:
                                    213 ;	main.c: 40: __asm__("nop");//sdcc内嵌入汇编
      008103 9D               [ 1]  214 	nop
      008104 20 DF            [ 2]  215 	jra	00101$
      008106                        216 00104$:
                                    217 ;	main.c: 41: }
      008106 5B 08            [ 2]  218 	addw	sp, #8
      008108 81               [ 4]  219 	ret
                                    220 ;	main.c: 43: void main()
                                    221 ;	-----------------------------------------
                                    222 ;	 function main
                                    223 ;	-----------------------------------------
      008109                        224 _main:
                                    225 ;	main.c: 45: clk_init();
      008109 CD 80 8A         [ 4]  226 	call	_clk_init
                                    227 ;	main.c: 46: pb5_init();
      00810C CD 80 B7         [ 4]  228 	call	_pb5_init
                                    229 ;	main.c: 47: tim4_init();
      00810F CD 80 C4         [ 4]  230 	call	_tim4_init
                                    231 ;	main.c: 48: while(1)
      008112                        232 00102$:
      008112 20 FE            [ 2]  233 	jra	00102$
                                    234 ;	main.c: 55: }
      008114 81               [ 4]  235 	ret
                                    236 ;	main.c: 59: void TIM4_UPD_OVF_IRQHandler(void) __interrupt(23)
                                    237 ;	-----------------------------------------
                                    238 ;	 function TIM4_UPD_OVF_IRQHandler
                                    239 ;	-----------------------------------------
      008115                        240 _TIM4_UPD_OVF_IRQHandler:
      008115 88               [ 1]  241 	push	a
                                    242 ;	main.c: 61: all_tmp++;
      008116 CE 00 01         [ 2]  243 	ldw	x, _all_tmp+0
      008119 5C               [ 1]  244 	incw	x
                                    245 ;	main.c: 62: if(all_tmp==1000)
      00811A CF 00 01         [ 2]  246 	ldw	_all_tmp+0, x
      00811D A3 03 E8         [ 2]  247 	cpw	x, #0x03e8
      008120 26 1C            [ 1]  248 	jrne	00105$
                                    249 ;	main.c: 64: all_tmp=0;
      008122 5F               [ 1]  250 	clrw	x
      008123 CF 00 01         [ 2]  251 	ldw	_all_tmp+0, x
                                    252 ;	main.c: 65: if(PB_ODR&PX_ODR_ODR5!=PX_ODR_ODR5)
      008126 C6 50 05         [ 1]  253 	ld	a, 0x5005
      008129 0F 01            [ 1]  254 	clr	(0x01, sp)
      00812B C6 50 05         [ 1]  255 	ld	a, 0x5005
      00812E 0D 01            [ 1]  256 	tnz	(0x01, sp)
      008130 27 07            [ 1]  257 	jreq	00102$
                                    258 ;	main.c: 66: PB_ODR&=~PX_ODR_ODR5;
      008132 A4 DF            [ 1]  259 	and	a, #0xdf
      008134 C7 50 05         [ 1]  260 	ld	0x5005, a
      008137 20 05            [ 2]  261 	jra	00105$
      008139                        262 00102$:
                                    263 ;	main.c: 68: PB_ODR|=PX_ODR_ODR5;
      008139 AA 20            [ 1]  264 	or	a, #0x20
      00813B C7 50 05         [ 1]  265 	ld	0x5005, a
      00813E                        266 00105$:
                                    267 ;	main.c: 70: TIM4_SR&=~TIMX_SR_UIF;
      00813E 72 11 53 44      [ 1]  268 	bres	21316, #0
                                    269 ;	main.c: 71: }
      008142 84               [ 1]  270 	pop	a
      008143 80               [11]  271 	iret
                                    272 	.area CODE
                                    273 	.area CONST
                                    274 	.area INITIALIZER
      008088                        275 __xinit__all_tmp:
      008088 00 00                  276 	.dw #0x0000
                                    277 	.area CABS (ABS)
