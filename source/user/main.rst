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
                                     14 	.globl _spi_init
                                     15 	.globl _pb5_init
                                     16 	.globl _clk_init
                                     17 	.globl _all_tmp
                                     18 	.globl _num
                                     19 ;--------------------------------------------------------
                                     20 ; ram data
                                     21 ;--------------------------------------------------------
                                     22 	.area DATA
                                     23 ;--------------------------------------------------------
                                     24 ; ram data
                                     25 ;--------------------------------------------------------
                                     26 	.area INITIALIZED
      000001                         27 _num::
      000001                         28 	.ds 1
      000002                         29 _all_tmp::
      000002                         30 	.ds 2
                                     31 ;--------------------------------------------------------
                                     32 ; Stack segment in internal ram 
                                     33 ;--------------------------------------------------------
                                     34 	.area	SSEG
      FFFFFF                         35 __start__stack:
      FFFFFF                         36 	.ds	1
                                     37 
                                     38 ;--------------------------------------------------------
                                     39 ; absolute external ram data
                                     40 ;--------------------------------------------------------
                                     41 	.area DABS (ABS)
                                     42 
                                     43 ; default segment ordering for linker
                                     44 	.area HOME
                                     45 	.area GSINIT
                                     46 	.area GSFINAL
                                     47 	.area CONST
                                     48 	.area INITIALIZER
                                     49 	.area CODE
                                     50 
                                     51 ;--------------------------------------------------------
                                     52 ; interrupt vector 
                                     53 ;--------------------------------------------------------
                                     54 	.area HOME
      008000                         55 __interrupt_vect:
      008000 82 00 80 6B             56 	int s_GSINIT ; reset
      008004 82 00 00 00             57 	int 0x000000 ; trap
      008008 82 00 00 00             58 	int 0x000000 ; int0
      00800C 82 00 00 00             59 	int 0x000000 ; int1
      008010 82 00 00 00             60 	int 0x000000 ; int2
      008014 82 00 00 00             61 	int 0x000000 ; int3
      008018 82 00 00 00             62 	int 0x000000 ; int4
      00801C 82 00 00 00             63 	int 0x000000 ; int5
      008020 82 00 00 00             64 	int 0x000000 ; int6
      008024 82 00 00 00             65 	int 0x000000 ; int7
      008028 82 00 00 00             66 	int 0x000000 ; int8
      00802C 82 00 00 00             67 	int 0x000000 ; int9
      008030 82 00 00 00             68 	int 0x000000 ; int10
      008034 82 00 00 00             69 	int 0x000000 ; int11
      008038 82 00 00 00             70 	int 0x000000 ; int12
      00803C 82 00 00 00             71 	int 0x000000 ; int13
      008040 82 00 00 00             72 	int 0x000000 ; int14
      008044 82 00 00 00             73 	int 0x000000 ; int15
      008048 82 00 00 00             74 	int 0x000000 ; int16
      00804C 82 00 00 00             75 	int 0x000000 ; int17
      008050 82 00 00 00             76 	int 0x000000 ; int18
      008054 82 00 00 00             77 	int 0x000000 ; int19
      008058 82 00 00 00             78 	int 0x000000 ; int20
      00805C 82 00 00 00             79 	int 0x000000 ; int21
      008060 82 00 00 00             80 	int 0x000000 ; int22
      008064 82 00 81 1F             81 	int _TIM4_UPD_OVF_IRQHandler ; int23
                                     82 ;--------------------------------------------------------
                                     83 ; global & static initialisations
                                     84 ;--------------------------------------------------------
                                     85 	.area HOME
                                     86 	.area GSINIT
                                     87 	.area GSFINAL
                                     88 	.area GSINIT
      00806B                         89 __sdcc_gs_init_startup:
      00806B                         90 __sdcc_init_data:
                                     91 ; stm8_genXINIT() start
      00806B AE 00 00         [ 2]   92 	ldw x, #l_DATA
      00806E 27 07            [ 1]   93 	jreq	00002$
      008070                         94 00001$:
      008070 72 4F 00 00      [ 1]   95 	clr (s_DATA - 1, x)
      008074 5A               [ 2]   96 	decw x
      008075 26 F9            [ 1]   97 	jrne	00001$
      008077                         98 00002$:
      008077 AE 00 03         [ 2]   99 	ldw	x, #l_INITIALIZER
      00807A 27 09            [ 1]  100 	jreq	00004$
      00807C                        101 00003$:
      00807C D6 80 87         [ 1]  102 	ld	a, (s_INITIALIZER - 1, x)
      00807F D7 00 00         [ 1]  103 	ld	(s_INITIALIZED - 1, x), a
      008082 5A               [ 2]  104 	decw	x
      008083 26 F7            [ 1]  105 	jrne	00003$
      008085                        106 00004$:
                                    107 ; stm8_genXINIT() end
                                    108 	.area GSFINAL
      008085 CC 80 68         [ 2]  109 	jp	__sdcc_program_startup
                                    110 ;--------------------------------------------------------
                                    111 ; Home
                                    112 ;--------------------------------------------------------
                                    113 	.area HOME
                                    114 	.area HOME
      008068                        115 __sdcc_program_startup:
      008068 CC 81 D9         [ 2]  116 	jp	_main
                                    117 ;	return from main will return to caller
                                    118 ;--------------------------------------------------------
                                    119 ; code
                                    120 ;--------------------------------------------------------
                                    121 	.area CODE
                                    122 ;	main.c: 5: void clk_init()
                                    123 ;	-----------------------------------------
                                    124 ;	 function clk_init
                                    125 ;	-----------------------------------------
      00808B                        126 _clk_init:
                                    127 ;	main.c: 8: while((CLK_ICKR&CLK_ICKR_HSIRDY)!=CLK_ICKR_HSIRDY);//检查HSI准备好没有
      00808B                        128 00101$:
      00808B C6 50 C0         [ 1]  129 	ld	a, 0x50c0
      00808E A4 02            [ 1]  130 	and	a, #0x02
      008090 A1 02            [ 1]  131 	cp	a, #0x02
      008092 26 F7            [ 1]  132 	jrne	00101$
                                    133 ;	main.c: 9: while((CLK_CMSR&CLK_CMSR_CKM_HSI)!=CLK_CMSR_CKM_HSI);//检查主时钟是否为HSI
      008094                        134 00104$:
      008094 C6 50 C3         [ 1]  135 	ld	a, 0x50c3
      008097 A4 E1            [ 1]  136 	and	a, #0xe1
      008099 A1 E1            [ 1]  137 	cp	a, #0xe1
      00809B 26 F7            [ 1]  138 	jrne	00104$
                                    139 ;	main.c: 10: CLK_CKDIVR&=~CLK_CKDIVR_HSIDIV_MASK;
      00809D C6 50 C6         [ 1]  140 	ld	a, 0x50c6
      0080A0 A4 E7            [ 1]  141 	and	a, #0xe7
      0080A2 C7 50 C6         [ 1]  142 	ld	0x50c6, a
                                    143 ;	main.c: 11: CLK_CKDIVR|=CLK_CKDIVR_HSIDIV_DIV1;//HSI作为主时钟最初是8分频，变成1分频快点
      0080A5 C6 50 C6         [ 1]  144 	ld	a, 0x50c6
      0080A8 C7 50 C6         [ 1]  145 	ld	0x50c6, a
                                    146 ;	main.c: 12: CLK_PCKENR1&=~(CLK_PCKENR1_I2C|
      0080AB C6 50 C7         [ 1]  147 	ld	a, 0x50c7
      0080AE A4 56            [ 1]  148 	and	a, #0x56
      0080B0 C7 50 C7         [ 1]  149 	ld	0x50c7, a
                                    150 ;	main.c: 16: CLK_PCKENR2&=~(CLK_PCKENR2_ADC|
      0080B3 C6 50 CA         [ 1]  151 	ld	a, 0x50ca
      0080B6 A4 F3            [ 1]  152 	and	a, #0xf3
      0080B8 C7 50 CA         [ 1]  153 	ld	0x50ca, a
                                    154 ;	main.c: 19: }
      0080BB 81               [ 4]  155 	ret
                                    156 ;	main.c: 21: void pb5_init()
                                    157 ;	-----------------------------------------
                                    158 ;	 function pb5_init
                                    159 ;	-----------------------------------------
      0080BC                        160 _pb5_init:
                                    161 ;	main.c: 23: PB_DDR|=PX_DDR_DDR5;//DDR PB5输出模式
      0080BC 72 1A 50 07      [ 1]  162 	bset	20487, #5
                                    163 ;	main.c: 24: PB_CR1|=PX_CR1_C15; //CR1 推挽输出
      0080C0 72 1A 50 08      [ 1]  164 	bset	20488, #5
                                    165 ;	main.c: 25: PB_CR2|=PX_CR2_C25; //CR2 输出速度10MHz
      0080C4 72 1A 50 09      [ 1]  166 	bset	20489, #5
                                    167 ;	main.c: 26: }
      0080C8 81               [ 4]  168 	ret
                                    169 ;	main.c: 28: void spi_init()//PC6 PC5
                                    170 ;	-----------------------------------------
                                    171 ;	 function spi_init
                                    172 ;	-----------------------------------------
      0080C9                        173 _spi_init:
                                    174 ;	main.c: 30: PC_DDR|=PX_DDR_DDR5;//SPI_SCK  clk
      0080C9 72 1A 50 0C      [ 1]  175 	bset	20492, #5
                                    176 ;	main.c: 31: PC_DDR|=PX_DDR_DDR6;//SPI_MOSI hcp
      0080CD 72 1C 50 0C      [ 1]  177 	bset	20492, #6
                                    178 ;	main.c: 32: PC_DDR|=PX_DDR_DDR7;//tcp
      0080D1 72 1E 50 0C      [ 1]  179 	bset	20492, #7
                                    180 ;	main.c: 33: PC_CR1|=PX_CR1_C15;
      0080D5 72 1A 50 0D      [ 1]  181 	bset	20493, #5
                                    182 ;	main.c: 34: PC_CR1|=PX_CR1_C16;
      0080D9 72 1C 50 0D      [ 1]  183 	bset	20493, #6
                                    184 ;	main.c: 35: PC_CR1|=PX_CR1_C17;
      0080DD 72 1E 50 0D      [ 1]  185 	bset	20493, #7
                                    186 ;	main.c: 36: PC_CR2|=PX_CR2_C25;
      0080E1 72 1A 50 0E      [ 1]  187 	bset	20494, #5
                                    188 ;	main.c: 37: PC_CR2|=PX_CR2_C26;
      0080E5 72 1C 50 0E      [ 1]  189 	bset	20494, #6
                                    190 ;	main.c: 38: PC_CR2|=PX_CR2_C27;
      0080E9 72 1E 50 0E      [ 1]  191 	bset	20494, #7
                                    192 ;	main.c: 40: SPI_CR1=SPIX_CR1_BR_DIV128;//波特率二分频
      0080ED 35 30 52 00      [ 1]  193 	mov	0x5200+0, #0x30
                                    194 ;	main.c: 41: SPI_CR2|=(SPIX_CR2_SSM|
      0080F1 C6 52 01         [ 1]  195 	ld	a, 0x5201
      0080F4 AA C3            [ 1]  196 	or	a, #0xc3
      0080F6 C7 52 01         [ 1]  197 	ld	0x5201, a
                                    198 ;	main.c: 46: SPI_CR1|=SPIX_CR1_LSBFIRST;
      0080F9 72 1E 52 00      [ 1]  199 	bset	20992, #7
                                    200 ;	main.c: 47: SPI_CR1|=SPIX_CR1_MSTR;
      0080FD 72 14 52 00      [ 1]  201 	bset	20992, #2
                                    202 ;	main.c: 48: SPI_CR1|=SPIX_CR1_SPE;
      008101 72 1C 52 00      [ 1]  203 	bset	20992, #6
                                    204 ;	main.c: 49: }
      008105 81               [ 4]  205 	ret
                                    206 ;	main.c: 51: void tim4_init()//16MHz输入
                                    207 ;	-----------------------------------------
                                    208 ;	 function tim4_init
                                    209 ;	-----------------------------------------
      008106                        210 _tim4_init:
                                    211 ;	main.c: 53: TIM4_PSCR|=TIMX_PSCR_PSC_(8);//定时器分频 计数器速度2MHz
      008106 72 14 53 47      [ 1]  212 	bset	21319, #2
                                    213 ;	main.c: 54: TIM4_ARR|=TIMX_ARR_ARR_(56);//自动重装载值 0.1ms
      00810A C6 53 48         [ 1]  214 	ld	a, 0x5348
      00810D AA 37            [ 1]  215 	or	a, #0x37
      00810F C7 53 48         [ 1]  216 	ld	0x5348, a
                                    217 ;	main.c: 55: TIM4_IER|=TIMX_IER_UIE;//开中断
      008112 72 10 53 43      [ 1]  218 	bset	21315, #0
                                    219 ;	main.c: 56: TIM4_CR1|=TIMX_CR1_APRE;//自动重装载预装载
      008116 72 1E 53 40      [ 1]  220 	bset	21312, #7
                                    221 ;	main.c: 57: TIM4_CR1|=TIMX_CR1_CEN;//计时器使能
      00811A 72 10 53 40      [ 1]  222 	bset	21312, #0
                                    223 ;	main.c: 58: }
      00811E 81               [ 4]  224 	ret
                                    225 ;	main.c: 64: void TIM4_UPD_OVF_IRQHandler(void) __interrupt(23)
                                    226 ;	-----------------------------------------
                                    227 ;	 function TIM4_UPD_OVF_IRQHandler
                                    228 ;	-----------------------------------------
      00811F                        229 _TIM4_UPD_OVF_IRQHandler:
      00811F 88               [ 1]  230 	push	a
                                    231 ;	main.c: 66: if((TIM4_SR&TIMX_SR_UIF)==TIMX_SR_UIF)//计数器溢出
      008120 C6 53 44         [ 1]  232 	ld	a, 0x5344
      008123 A4 01            [ 1]  233 	and	a, #0x01
      008125 4A               [ 1]  234 	dec	a
      008126 27 03            [ 1]  235 	jreq	00186$
      008128 CC 81 D7         [ 2]  236 	jp	00122$
      00812B                        237 00186$:
                                    238 ;	main.c: 68: TIM4_SR&=~TIMX_SR_UIF;
      00812B 72 11 53 44      [ 1]  239 	bres	21316, #0
                                    240 ;	main.c: 69: all_tmp++;
      00812F CE 00 02         [ 2]  241 	ldw	x, _all_tmp+0
      008132 5C               [ 1]  242 	incw	x
                                    243 ;	main.c: 70: if (all_tmp>=1000)
      008133 CF 00 02         [ 2]  244 	ldw	_all_tmp+0, x
      008136 A3 03 E8         [ 2]  245 	cpw	x, #0x03e8
      008139 24 03            [ 1]  246 	jrnc	00187$
      00813B CC 81 D7         [ 2]  247 	jp	00122$
      00813E                        248 00187$:
                                    249 ;	main.c: 72: all_tmp=0;
      00813E 5F               [ 1]  250 	clrw	x
      00813F CF 00 02         [ 2]  251 	ldw	_all_tmp+0, x
                                    252 ;	main.c: 73: if((PB_ODR&PX_ODR_ODR5)==PX_ODR_ODR5)
      008142 C6 50 05         [ 1]  253 	ld	a, 0x5005
      008145 A4 20            [ 1]  254 	and	a, #0x20
      008147 97               [ 1]  255 	ld	xl, a
      008148 C6 50 05         [ 1]  256 	ld	a, 0x5005
      00814B 88               [ 1]  257 	push	a
      00814C 9F               [ 1]  258 	ld	a, xl
      00814D A1 20            [ 1]  259 	cp	a, #0x20
      00814F 84               [ 1]  260 	pop	a
      008150 26 07            [ 1]  261 	jrne	00102$
                                    262 ;	main.c: 74: PB_ODR&=~PX_ODR_ODR5;
      008152 A4 DF            [ 1]  263 	and	a, #0xdf
      008154 C7 50 05         [ 1]  264 	ld	0x5005, a
      008157 20 05            [ 2]  265 	jra	00103$
      008159                        266 00102$:
                                    267 ;	main.c: 76: PB_ODR|=PX_ODR_ODR5;
      008159 AA 20            [ 1]  268 	or	a, #0x20
      00815B C7 50 05         [ 1]  269 	ld	0x5005, a
      00815E                        270 00103$:
                                    271 ;	main.c: 79: a1=0x01<<num;
      00815E C6 00 01         [ 1]  272 	ld	a, _num+0
      008161 95               [ 1]  273 	ld	xh, a
      008162 A6 01            [ 1]  274 	ld	a, #0x01
      008164 6B 01            [ 1]  275 	ld	(0x01, sp), a
      008166 9E               [ 1]  276 	ld	a, xh
      008167 4D               [ 1]  277 	tnz	a
      008168 27 05            [ 1]  278 	jreq	00192$
      00816A                        279 00191$:
      00816A 08 01            [ 1]  280 	sll	(0x01, sp)
      00816C 4A               [ 1]  281 	dec	a
      00816D 26 FB            [ 1]  282 	jrne	00191$
      00816F                        283 00192$:
                                    284 ;	main.c: 80: a2=0x01<<(num-8);
      00816F 9E               [ 1]  285 	ld	a, xh
      008170 A0 08            [ 1]  286 	sub	a, #0x08
      008172 41               [ 1]  287 	exg	a, xl
      008173 A6 01            [ 1]  288 	ld	a, #0x01
      008175 41               [ 1]  289 	exg	a, xl
      008176 4D               [ 1]  290 	tnz	a
      008177 27 06            [ 1]  291 	jreq	00194$
      008179                        292 00193$:
      008179 41               [ 1]  293 	exg	a, xl
      00817A 48               [ 1]  294 	sll	a
      00817B 41               [ 1]  295 	exg	a, xl
      00817C 4A               [ 1]  296 	dec	a
      00817D 26 FA            [ 1]  297 	jrne	00193$
      00817F                        298 00194$:
                                    299 ;	main.c: 81: a3=0x01<<(num-16);
      00817F 9E               [ 1]  300 	ld	a, xh
      008180 A0 10            [ 1]  301 	sub	a, #0x10
      008182 02               [ 1]  302 	rlwa	x
      008183 A6 01            [ 1]  303 	ld	a, #0x01
      008185 01               [ 1]  304 	rrwa	x
      008186 4D               [ 1]  305 	tnz	a
      008187 27 06            [ 1]  306 	jreq	00196$
      008189                        307 00195$:
      008189 02               [ 1]  308 	rlwa	x
      00818A 48               [ 1]  309 	sll	a
      00818B 01               [ 1]  310 	rrwa	x
      00818C 4A               [ 1]  311 	dec	a
      00818D 26 FA            [ 1]  312 	jrne	00195$
      00818F                        313 00196$:
                                    314 ;	main.c: 83: PC_DDR&=~PX_DDR_DDR7;
      00818F 72 1F 50 0C      [ 1]  315 	bres	20492, #7
                                    316 ;	main.c: 84: while((SPI_SR&SPIX_SR_TXE)!=SPIX_SR_TXE);
      008193                        317 00104$:
      008193 C6 52 03         [ 1]  318 	ld	a, 0x5203
      008196 A4 02            [ 1]  319 	and	a, #0x02
      008198 A1 02            [ 1]  320 	cp	a, #0x02
      00819A 26 F7            [ 1]  321 	jrne	00104$
                                    322 ;	main.c: 85: SPI_DR=SPIX_DR_DR_(a1);
      00819C 7B 01            [ 1]  323 	ld	a, (0x01, sp)
      00819E C7 52 04         [ 1]  324 	ld	0x5204, a
                                    325 ;	main.c: 86: while((SPI_SR&SPIX_SR_TXE)!=SPIX_SR_TXE);
      0081A1                        326 00107$:
      0081A1 C6 52 03         [ 1]  327 	ld	a, 0x5203
      0081A4 A4 02            [ 1]  328 	and	a, #0x02
      0081A6 A1 02            [ 1]  329 	cp	a, #0x02
      0081A8 26 F7            [ 1]  330 	jrne	00107$
                                    331 ;	main.c: 87: SPI_DR=SPIX_DR_DR_(a2);
      0081AA 9F               [ 1]  332 	ld	a, xl
      0081AB C7 52 04         [ 1]  333 	ld	0x5204, a
                                    334 ;	main.c: 88: while((SPI_SR&SPIX_SR_TXE)!=SPIX_SR_TXE);
      0081AE                        335 00110$:
      0081AE C6 52 03         [ 1]  336 	ld	a, 0x5203
      0081B1 A4 02            [ 1]  337 	and	a, #0x02
      0081B3 A1 02            [ 1]  338 	cp	a, #0x02
      0081B5 26 F7            [ 1]  339 	jrne	00110$
                                    340 ;	main.c: 89: SPI_DR=SPIX_DR_DR_(a3);
      0081B7 9E               [ 1]  341 	ld	a, xh
      0081B8 C7 52 04         [ 1]  342 	ld	0x5204, a
                                    343 ;	main.c: 90: while((SPI_SR&SPIX_SR_TXE)!=SPIX_SR_TXE);
      0081BB                        344 00113$:
      0081BB C6 52 03         [ 1]  345 	ld	a, 0x5203
      0081BE A4 02            [ 1]  346 	and	a, #0x02
      0081C0 A1 02            [ 1]  347 	cp	a, #0x02
      0081C2 26 F7            [ 1]  348 	jrne	00113$
                                    349 ;	main.c: 91: PC_DDR|=PX_DDR_DDR7;
      0081C4 72 1E 50 0C      [ 1]  350 	bset	20492, #7
                                    351 ;	main.c: 92: num++;
      0081C8 72 5C 00 01      [ 1]  352 	inc	_num+0
                                    353 ;	main.c: 93: if(num==25)
      0081CC C6 00 01         [ 1]  354 	ld	a, _num+0
      0081CF A1 19            [ 1]  355 	cp	a, #0x19
      0081D1 26 04            [ 1]  356 	jrne	00122$
                                    357 ;	main.c: 94: num=1;
      0081D3 35 01 00 01      [ 1]  358 	mov	_num+0, #0x01
      0081D7                        359 00122$:
                                    360 ;	main.c: 99: }
      0081D7 84               [ 1]  361 	pop	a
      0081D8 80               [11]  362 	iret
                                    363 ;	main.c: 103: void main()
                                    364 ;	-----------------------------------------
                                    365 ;	 function main
                                    366 ;	-----------------------------------------
      0081D9                        367 _main:
                                    368 ;	main.c: 105: clk_init();
      0081D9 CD 80 8B         [ 4]  369 	call	_clk_init
                                    370 ;	main.c: 106: pb5_init();
      0081DC CD 80 BC         [ 4]  371 	call	_pb5_init
                                    372 ;	main.c: 107: tim4_init();
      0081DF CD 81 06         [ 4]  373 	call	_tim4_init
                                    374 ;	main.c: 108: rim();
      0081E2 9A               [ 1]  375 	rim
                                    376 ;	main.c: 109: spi_init();
      0081E3 CD 80 C9         [ 4]  377 	call	_spi_init
                                    378 ;	main.c: 110: while(1)
      0081E6                        379 00102$:
      0081E6 20 FE            [ 2]  380 	jra	00102$
                                    381 ;	main.c: 122: }
      0081E8 81               [ 4]  382 	ret
                                    383 	.area CODE
                                    384 	.area CONST
                                    385 	.area INITIALIZER
      008088                        386 __xinit__num:
      008088 01                     387 	.db #0x01	; 1
      008089                        388 __xinit__all_tmp:
      008089 00 00                  389 	.dw #0x0000
                                    390 	.area CABS (ABS)
