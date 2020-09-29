                                      1 ;--------------------------------------------------------
                                      2 ; File Created by SDCC : free open source ANSI-C Compiler
                                      3 ; Version 4.0.0 #11528 (MINGW64)
                                      4 ;--------------------------------------------------------
                                      5 	.module stm8s_clk
                                      6 	.optsdcc -mstm8
                                      7 	
                                      8 ;--------------------------------------------------------
                                      9 ; Public variables in this module
                                     10 ;--------------------------------------------------------
                                     11 	.globl _CLKPrescTable
                                     12 	.globl _HSIDivFactor
                                     13 	.globl _CLK_DeInit
                                     14 	.globl _CLK_FastHaltWakeUpCmd
                                     15 	.globl _CLK_HSECmd
                                     16 	.globl _CLK_HSICmd
                                     17 	.globl _CLK_LSICmd
                                     18 	.globl _CLK_CCOCmd
                                     19 	.globl _CLK_ClockSwitchCmd
                                     20 	.globl _CLK_SlowActiveHaltWakeUpCmd
                                     21 	.globl _CLK_PeripheralClockConfig
                                     22 	.globl _CLK_ClockSwitchConfig
                                     23 	.globl _CLK_HSIPrescalerConfig
                                     24 	.globl _CLK_CCOConfig
                                     25 	.globl _CLK_ITConfig
                                     26 	.globl _CLK_SYSCLKConfig
                                     27 	.globl _CLK_SWIMConfig
                                     28 	.globl _CLK_ClockSecuritySystemEnable
                                     29 	.globl _CLK_GetSYSCLKSource
                                     30 	.globl _CLK_GetClockFreq
                                     31 	.globl _CLK_AdjustHSICalibrationValue
                                     32 	.globl _CLK_SYSCLKEmergencyClear
                                     33 	.globl _CLK_GetFlagStatus
                                     34 	.globl _CLK_GetITStatus
                                     35 	.globl _CLK_ClearITPendingBit
                                     36 ;--------------------------------------------------------
                                     37 ; ram data
                                     38 ;--------------------------------------------------------
                                     39 	.area DATA
                                     40 ;--------------------------------------------------------
                                     41 ; ram data
                                     42 ;--------------------------------------------------------
                                     43 	.area INITIALIZED
                                     44 ;--------------------------------------------------------
                                     45 ; absolute external ram data
                                     46 ;--------------------------------------------------------
                                     47 	.area DABS (ABS)
                                     48 
                                     49 ; default segment ordering for linker
                                     50 	.area HOME
                                     51 	.area GSINIT
                                     52 	.area GSFINAL
                                     53 	.area CONST
                                     54 	.area INITIALIZER
                                     55 	.area CODE
                                     56 
                                     57 ;--------------------------------------------------------
                                     58 ; global & static initialisations
                                     59 ;--------------------------------------------------------
                                     60 	.area HOME
                                     61 	.area GSINIT
                                     62 	.area GSFINAL
                                     63 	.area GSINIT
                                     64 ;--------------------------------------------------------
                                     65 ; Home
                                     66 ;--------------------------------------------------------
                                     67 	.area HOME
                                     68 	.area HOME
                                     69 ;--------------------------------------------------------
                                     70 ; code
                                     71 ;--------------------------------------------------------
                                     72 	.area CODE
                                     73 ;	source/FWLIB/src/stm8s_clk.c: 72: void CLK_DeInit(void)
                                     74 ;	-----------------------------------------
                                     75 ;	 function CLK_DeInit
                                     76 ;	-----------------------------------------
      008033                         77 _CLK_DeInit:
                                     78 ;	source/FWLIB/src/stm8s_clk.c: 74: CLK->ICKR = CLK_ICKR_RESET_VALUE;
      008033 35 01 50 C0      [ 1]   79 	mov	0x50c0+0, #0x01
                                     80 ;	source/FWLIB/src/stm8s_clk.c: 75: CLK->ECKR = CLK_ECKR_RESET_VALUE;
      008037 35 00 50 C1      [ 1]   81 	mov	0x50c1+0, #0x00
                                     82 ;	source/FWLIB/src/stm8s_clk.c: 76: CLK->SWR  = CLK_SWR_RESET_VALUE;
      00803B 35 E1 50 C4      [ 1]   83 	mov	0x50c4+0, #0xe1
                                     84 ;	source/FWLIB/src/stm8s_clk.c: 77: CLK->SWCR = CLK_SWCR_RESET_VALUE;
      00803F 35 00 50 C5      [ 1]   85 	mov	0x50c5+0, #0x00
                                     86 ;	source/FWLIB/src/stm8s_clk.c: 78: CLK->CKDIVR = CLK_CKDIVR_RESET_VALUE;
      008043 35 18 50 C6      [ 1]   87 	mov	0x50c6+0, #0x18
                                     88 ;	source/FWLIB/src/stm8s_clk.c: 79: CLK->PCKENR1 = CLK_PCKENR1_RESET_VALUE;
      008047 35 FF 50 C7      [ 1]   89 	mov	0x50c7+0, #0xff
                                     90 ;	source/FWLIB/src/stm8s_clk.c: 80: CLK->PCKENR2 = CLK_PCKENR2_RESET_VALUE;
      00804B 35 FF 50 CA      [ 1]   91 	mov	0x50ca+0, #0xff
                                     92 ;	source/FWLIB/src/stm8s_clk.c: 81: CLK->CSSR = CLK_CSSR_RESET_VALUE;
      00804F 35 00 50 C8      [ 1]   93 	mov	0x50c8+0, #0x00
                                     94 ;	source/FWLIB/src/stm8s_clk.c: 82: CLK->CCOR = CLK_CCOR_RESET_VALUE;
      008053 35 00 50 C9      [ 1]   95 	mov	0x50c9+0, #0x00
                                     96 ;	source/FWLIB/src/stm8s_clk.c: 83: while ((CLK->CCOR & CLK_CCOR_CCOEN)!= 0)
      008057                         97 00101$:
      008057 C6 50 C9         [ 1]   98 	ld	a, 0x50c9
      00805A 44               [ 1]   99 	srl	a
      00805B 25 FA            [ 1]  100 	jrc	00101$
                                    101 ;	source/FWLIB/src/stm8s_clk.c: 85: CLK->CCOR = CLK_CCOR_RESET_VALUE;
      00805D 35 00 50 C9      [ 1]  102 	mov	0x50c9+0, #0x00
                                    103 ;	source/FWLIB/src/stm8s_clk.c: 86: CLK->HSITRIMR = CLK_HSITRIMR_RESET_VALUE;
      008061 35 00 50 CC      [ 1]  104 	mov	0x50cc+0, #0x00
                                    105 ;	source/FWLIB/src/stm8s_clk.c: 87: CLK->SWIMCCR = CLK_SWIMCCR_RESET_VALUE;
      008065 35 00 50 CD      [ 1]  106 	mov	0x50cd+0, #0x00
                                    107 ;	source/FWLIB/src/stm8s_clk.c: 88: }
      008069 81               [ 4]  108 	ret
                                    109 ;	source/FWLIB/src/stm8s_clk.c: 99: void CLK_FastHaltWakeUpCmd(FunctionalState NewState)
                                    110 ;	-----------------------------------------
                                    111 ;	 function CLK_FastHaltWakeUpCmd
                                    112 ;	-----------------------------------------
      00806A                        113 _CLK_FastHaltWakeUpCmd:
                                    114 ;	source/FWLIB/src/stm8s_clk.c: 107: CLK->ICKR |= CLK_ICKR_FHWU;
      00806A C6 50 C0         [ 1]  115 	ld	a, 0x50c0
                                    116 ;	source/FWLIB/src/stm8s_clk.c: 104: if (NewState != DISABLE)
      00806D 0D 03            [ 1]  117 	tnz	(0x03, sp)
      00806F 27 06            [ 1]  118 	jreq	00102$
                                    119 ;	source/FWLIB/src/stm8s_clk.c: 107: CLK->ICKR |= CLK_ICKR_FHWU;
      008071 AA 04            [ 1]  120 	or	a, #0x04
      008073 C7 50 C0         [ 1]  121 	ld	0x50c0, a
      008076 81               [ 4]  122 	ret
      008077                        123 00102$:
                                    124 ;	source/FWLIB/src/stm8s_clk.c: 112: CLK->ICKR &= (uint8_t)(~CLK_ICKR_FHWU);
      008077 A4 FB            [ 1]  125 	and	a, #0xfb
      008079 C7 50 C0         [ 1]  126 	ld	0x50c0, a
                                    127 ;	source/FWLIB/src/stm8s_clk.c: 114: }
      00807C 81               [ 4]  128 	ret
                                    129 ;	source/FWLIB/src/stm8s_clk.c: 121: void CLK_HSECmd(FunctionalState NewState)
                                    130 ;	-----------------------------------------
                                    131 ;	 function CLK_HSECmd
                                    132 ;	-----------------------------------------
      00807D                        133 _CLK_HSECmd:
                                    134 ;	source/FWLIB/src/stm8s_clk.c: 129: CLK->ECKR |= CLK_ECKR_HSEEN;
      00807D C6 50 C1         [ 1]  135 	ld	a, 0x50c1
                                    136 ;	source/FWLIB/src/stm8s_clk.c: 126: if (NewState != DISABLE)
      008080 0D 03            [ 1]  137 	tnz	(0x03, sp)
      008082 27 06            [ 1]  138 	jreq	00102$
                                    139 ;	source/FWLIB/src/stm8s_clk.c: 129: CLK->ECKR |= CLK_ECKR_HSEEN;
      008084 AA 01            [ 1]  140 	or	a, #0x01
      008086 C7 50 C1         [ 1]  141 	ld	0x50c1, a
      008089 81               [ 4]  142 	ret
      00808A                        143 00102$:
                                    144 ;	source/FWLIB/src/stm8s_clk.c: 134: CLK->ECKR &= (uint8_t)(~CLK_ECKR_HSEEN);
      00808A A4 FE            [ 1]  145 	and	a, #0xfe
      00808C C7 50 C1         [ 1]  146 	ld	0x50c1, a
                                    147 ;	source/FWLIB/src/stm8s_clk.c: 136: }
      00808F 81               [ 4]  148 	ret
                                    149 ;	source/FWLIB/src/stm8s_clk.c: 143: void CLK_HSICmd(FunctionalState NewState)
                                    150 ;	-----------------------------------------
                                    151 ;	 function CLK_HSICmd
                                    152 ;	-----------------------------------------
      008090                        153 _CLK_HSICmd:
                                    154 ;	source/FWLIB/src/stm8s_clk.c: 151: CLK->ICKR |= CLK_ICKR_HSIEN;
      008090 C6 50 C0         [ 1]  155 	ld	a, 0x50c0
                                    156 ;	source/FWLIB/src/stm8s_clk.c: 148: if (NewState != DISABLE)
      008093 0D 03            [ 1]  157 	tnz	(0x03, sp)
      008095 27 06            [ 1]  158 	jreq	00102$
                                    159 ;	source/FWLIB/src/stm8s_clk.c: 151: CLK->ICKR |= CLK_ICKR_HSIEN;
      008097 AA 01            [ 1]  160 	or	a, #0x01
      008099 C7 50 C0         [ 1]  161 	ld	0x50c0, a
      00809C 81               [ 4]  162 	ret
      00809D                        163 00102$:
                                    164 ;	source/FWLIB/src/stm8s_clk.c: 156: CLK->ICKR &= (uint8_t)(~CLK_ICKR_HSIEN);
      00809D A4 FE            [ 1]  165 	and	a, #0xfe
      00809F C7 50 C0         [ 1]  166 	ld	0x50c0, a
                                    167 ;	source/FWLIB/src/stm8s_clk.c: 158: }
      0080A2 81               [ 4]  168 	ret
                                    169 ;	source/FWLIB/src/stm8s_clk.c: 166: void CLK_LSICmd(FunctionalState NewState)
                                    170 ;	-----------------------------------------
                                    171 ;	 function CLK_LSICmd
                                    172 ;	-----------------------------------------
      0080A3                        173 _CLK_LSICmd:
                                    174 ;	source/FWLIB/src/stm8s_clk.c: 174: CLK->ICKR |= CLK_ICKR_LSIEN;
      0080A3 C6 50 C0         [ 1]  175 	ld	a, 0x50c0
                                    176 ;	source/FWLIB/src/stm8s_clk.c: 171: if (NewState != DISABLE)
      0080A6 0D 03            [ 1]  177 	tnz	(0x03, sp)
      0080A8 27 06            [ 1]  178 	jreq	00102$
                                    179 ;	source/FWLIB/src/stm8s_clk.c: 174: CLK->ICKR |= CLK_ICKR_LSIEN;
      0080AA AA 08            [ 1]  180 	or	a, #0x08
      0080AC C7 50 C0         [ 1]  181 	ld	0x50c0, a
      0080AF 81               [ 4]  182 	ret
      0080B0                        183 00102$:
                                    184 ;	source/FWLIB/src/stm8s_clk.c: 179: CLK->ICKR &= (uint8_t)(~CLK_ICKR_LSIEN);
      0080B0 A4 F7            [ 1]  185 	and	a, #0xf7
      0080B2 C7 50 C0         [ 1]  186 	ld	0x50c0, a
                                    187 ;	source/FWLIB/src/stm8s_clk.c: 181: }
      0080B5 81               [ 4]  188 	ret
                                    189 ;	source/FWLIB/src/stm8s_clk.c: 189: void CLK_CCOCmd(FunctionalState NewState)
                                    190 ;	-----------------------------------------
                                    191 ;	 function CLK_CCOCmd
                                    192 ;	-----------------------------------------
      0080B6                        193 _CLK_CCOCmd:
                                    194 ;	source/FWLIB/src/stm8s_clk.c: 197: CLK->CCOR |= CLK_CCOR_CCOEN;
      0080B6 C6 50 C9         [ 1]  195 	ld	a, 0x50c9
                                    196 ;	source/FWLIB/src/stm8s_clk.c: 194: if (NewState != DISABLE)
      0080B9 0D 03            [ 1]  197 	tnz	(0x03, sp)
      0080BB 27 06            [ 1]  198 	jreq	00102$
                                    199 ;	source/FWLIB/src/stm8s_clk.c: 197: CLK->CCOR |= CLK_CCOR_CCOEN;
      0080BD AA 01            [ 1]  200 	or	a, #0x01
      0080BF C7 50 C9         [ 1]  201 	ld	0x50c9, a
      0080C2 81               [ 4]  202 	ret
      0080C3                        203 00102$:
                                    204 ;	source/FWLIB/src/stm8s_clk.c: 202: CLK->CCOR &= (uint8_t)(~CLK_CCOR_CCOEN);
      0080C3 A4 FE            [ 1]  205 	and	a, #0xfe
      0080C5 C7 50 C9         [ 1]  206 	ld	0x50c9, a
                                    207 ;	source/FWLIB/src/stm8s_clk.c: 204: }
      0080C8 81               [ 4]  208 	ret
                                    209 ;	source/FWLIB/src/stm8s_clk.c: 213: void CLK_ClockSwitchCmd(FunctionalState NewState)
                                    210 ;	-----------------------------------------
                                    211 ;	 function CLK_ClockSwitchCmd
                                    212 ;	-----------------------------------------
      0080C9                        213 _CLK_ClockSwitchCmd:
                                    214 ;	source/FWLIB/src/stm8s_clk.c: 221: CLK->SWCR |= CLK_SWCR_SWEN;
      0080C9 C6 50 C5         [ 1]  215 	ld	a, 0x50c5
                                    216 ;	source/FWLIB/src/stm8s_clk.c: 218: if (NewState != DISABLE )
      0080CC 0D 03            [ 1]  217 	tnz	(0x03, sp)
      0080CE 27 06            [ 1]  218 	jreq	00102$
                                    219 ;	source/FWLIB/src/stm8s_clk.c: 221: CLK->SWCR |= CLK_SWCR_SWEN;
      0080D0 AA 02            [ 1]  220 	or	a, #0x02
      0080D2 C7 50 C5         [ 1]  221 	ld	0x50c5, a
      0080D5 81               [ 4]  222 	ret
      0080D6                        223 00102$:
                                    224 ;	source/FWLIB/src/stm8s_clk.c: 226: CLK->SWCR &= (uint8_t)(~CLK_SWCR_SWEN);
      0080D6 A4 FD            [ 1]  225 	and	a, #0xfd
      0080D8 C7 50 C5         [ 1]  226 	ld	0x50c5, a
                                    227 ;	source/FWLIB/src/stm8s_clk.c: 228: }
      0080DB 81               [ 4]  228 	ret
                                    229 ;	source/FWLIB/src/stm8s_clk.c: 238: void CLK_SlowActiveHaltWakeUpCmd(FunctionalState NewState)
                                    230 ;	-----------------------------------------
                                    231 ;	 function CLK_SlowActiveHaltWakeUpCmd
                                    232 ;	-----------------------------------------
      0080DC                        233 _CLK_SlowActiveHaltWakeUpCmd:
                                    234 ;	source/FWLIB/src/stm8s_clk.c: 246: CLK->ICKR |= CLK_ICKR_SWUAH;
      0080DC C6 50 C0         [ 1]  235 	ld	a, 0x50c0
                                    236 ;	source/FWLIB/src/stm8s_clk.c: 243: if (NewState != DISABLE)
      0080DF 0D 03            [ 1]  237 	tnz	(0x03, sp)
      0080E1 27 06            [ 1]  238 	jreq	00102$
                                    239 ;	source/FWLIB/src/stm8s_clk.c: 246: CLK->ICKR |= CLK_ICKR_SWUAH;
      0080E3 AA 20            [ 1]  240 	or	a, #0x20
      0080E5 C7 50 C0         [ 1]  241 	ld	0x50c0, a
      0080E8 81               [ 4]  242 	ret
      0080E9                        243 00102$:
                                    244 ;	source/FWLIB/src/stm8s_clk.c: 251: CLK->ICKR &= (uint8_t)(~CLK_ICKR_SWUAH);
      0080E9 A4 DF            [ 1]  245 	and	a, #0xdf
      0080EB C7 50 C0         [ 1]  246 	ld	0x50c0, a
                                    247 ;	source/FWLIB/src/stm8s_clk.c: 253: }
      0080EE 81               [ 4]  248 	ret
                                    249 ;	source/FWLIB/src/stm8s_clk.c: 263: void CLK_PeripheralClockConfig(CLK_Peripheral_TypeDef CLK_Peripheral, FunctionalState NewState)
                                    250 ;	-----------------------------------------
                                    251 ;	 function CLK_PeripheralClockConfig
                                    252 ;	-----------------------------------------
      0080EF                        253 _CLK_PeripheralClockConfig:
      0080EF 52 02            [ 2]  254 	sub	sp, #2
                                    255 ;	source/FWLIB/src/stm8s_clk.c: 274: CLK->PCKENR1 |= (uint8_t)((uint8_t)1 << ((uint8_t)CLK_Peripheral & (uint8_t)0x0F));
      0080F1 7B 05            [ 1]  256 	ld	a, (0x05, sp)
      0080F3 A4 0F            [ 1]  257 	and	a, #0x0f
      0080F5 88               [ 1]  258 	push	a
      0080F6 A6 01            [ 1]  259 	ld	a, #0x01
      0080F8 6B 02            [ 1]  260 	ld	(0x02, sp), a
      0080FA 84               [ 1]  261 	pop	a
      0080FB 4D               [ 1]  262 	tnz	a
      0080FC 27 05            [ 1]  263 	jreq	00128$
      0080FE                        264 00127$:
      0080FE 08 01            [ 1]  265 	sll	(0x01, sp)
      008100 4A               [ 1]  266 	dec	a
      008101 26 FB            [ 1]  267 	jrne	00127$
      008103                        268 00128$:
                                    269 ;	source/FWLIB/src/stm8s_clk.c: 279: CLK->PCKENR1 &= (uint8_t)(~(uint8_t)(((uint8_t)1 << ((uint8_t)CLK_Peripheral & (uint8_t)0x0F))));
      008103 7B 01            [ 1]  270 	ld	a, (0x01, sp)
      008105 43               [ 1]  271 	cpl	a
      008106 6B 02            [ 1]  272 	ld	(0x02, sp), a
                                    273 ;	source/FWLIB/src/stm8s_clk.c: 269: if (((uint8_t)CLK_Peripheral & (uint8_t)0x10) == 0x00)
      008108 7B 05            [ 1]  274 	ld	a, (0x05, sp)
      00810A A5 10            [ 1]  275 	bcp	a, #0x10
      00810C 26 15            [ 1]  276 	jrne	00108$
                                    277 ;	source/FWLIB/src/stm8s_clk.c: 274: CLK->PCKENR1 |= (uint8_t)((uint8_t)1 << ((uint8_t)CLK_Peripheral & (uint8_t)0x0F));
      00810E C6 50 C7         [ 1]  278 	ld	a, 0x50c7
                                    279 ;	source/FWLIB/src/stm8s_clk.c: 271: if (NewState != DISABLE)
      008111 0D 06            [ 1]  280 	tnz	(0x06, sp)
      008113 27 07            [ 1]  281 	jreq	00102$
                                    282 ;	source/FWLIB/src/stm8s_clk.c: 274: CLK->PCKENR1 |= (uint8_t)((uint8_t)1 << ((uint8_t)CLK_Peripheral & (uint8_t)0x0F));
      008115 1A 01            [ 1]  283 	or	a, (0x01, sp)
      008117 C7 50 C7         [ 1]  284 	ld	0x50c7, a
      00811A 20 1A            [ 2]  285 	jra	00110$
      00811C                        286 00102$:
                                    287 ;	source/FWLIB/src/stm8s_clk.c: 279: CLK->PCKENR1 &= (uint8_t)(~(uint8_t)(((uint8_t)1 << ((uint8_t)CLK_Peripheral & (uint8_t)0x0F))));
      00811C 14 02            [ 1]  288 	and	a, (0x02, sp)
      00811E C7 50 C7         [ 1]  289 	ld	0x50c7, a
      008121 20 13            [ 2]  290 	jra	00110$
      008123                        291 00108$:
                                    292 ;	source/FWLIB/src/stm8s_clk.c: 287: CLK->PCKENR2 |= (uint8_t)((uint8_t)1 << ((uint8_t)CLK_Peripheral & (uint8_t)0x0F));
      008123 C6 50 CA         [ 1]  293 	ld	a, 0x50ca
                                    294 ;	source/FWLIB/src/stm8s_clk.c: 284: if (NewState != DISABLE)
      008126 0D 06            [ 1]  295 	tnz	(0x06, sp)
      008128 27 07            [ 1]  296 	jreq	00105$
                                    297 ;	source/FWLIB/src/stm8s_clk.c: 287: CLK->PCKENR2 |= (uint8_t)((uint8_t)1 << ((uint8_t)CLK_Peripheral & (uint8_t)0x0F));
      00812A 1A 01            [ 1]  298 	or	a, (0x01, sp)
      00812C C7 50 CA         [ 1]  299 	ld	0x50ca, a
      00812F 20 05            [ 2]  300 	jra	00110$
      008131                        301 00105$:
                                    302 ;	source/FWLIB/src/stm8s_clk.c: 292: CLK->PCKENR2 &= (uint8_t)(~(uint8_t)(((uint8_t)1 << ((uint8_t)CLK_Peripheral & (uint8_t)0x0F))));
      008131 14 02            [ 1]  303 	and	a, (0x02, sp)
      008133 C7 50 CA         [ 1]  304 	ld	0x50ca, a
      008136                        305 00110$:
                                    306 ;	source/FWLIB/src/stm8s_clk.c: 295: }
      008136 5B 02            [ 2]  307 	addw	sp, #2
      008138 81               [ 4]  308 	ret
                                    309 ;	source/FWLIB/src/stm8s_clk.c: 309: ErrorStatus CLK_ClockSwitchConfig(CLK_SwitchMode_TypeDef CLK_SwitchMode, CLK_Source_TypeDef CLK_NewClock, FunctionalState ITState, CLK_CurrentClockState_TypeDef CLK_CurrentClockState)
                                    310 ;	-----------------------------------------
                                    311 ;	 function CLK_ClockSwitchConfig
                                    312 ;	-----------------------------------------
      008139                        313 _CLK_ClockSwitchConfig:
                                    314 ;	source/FWLIB/src/stm8s_clk.c: 322: clock_master = (CLK_Source_TypeDef)CLK->CMSR;
      008139 C6 50 C3         [ 1]  315 	ld	a, 0x50c3
      00813C 90 97            [ 1]  316 	ld	yl, a
                                    317 ;	source/FWLIB/src/stm8s_clk.c: 328: CLK->SWCR |= CLK_SWCR_SWEN;
      00813E C6 50 C5         [ 1]  318 	ld	a, 0x50c5
                                    319 ;	source/FWLIB/src/stm8s_clk.c: 325: if (CLK_SwitchMode == CLK_SWITCHMODE_AUTO)
      008141 88               [ 1]  320 	push	a
      008142 7B 04            [ 1]  321 	ld	a, (0x04, sp)
      008144 4A               [ 1]  322 	dec	a
      008145 84               [ 1]  323 	pop	a
      008146 26 37            [ 1]  324 	jrne	00122$
                                    325 ;	source/FWLIB/src/stm8s_clk.c: 328: CLK->SWCR |= CLK_SWCR_SWEN;
      008148 AA 02            [ 1]  326 	or	a, #0x02
      00814A C7 50 C5         [ 1]  327 	ld	0x50c5, a
      00814D C6 50 C5         [ 1]  328 	ld	a, 0x50c5
                                    329 ;	source/FWLIB/src/stm8s_clk.c: 331: if (ITState != DISABLE)
      008150 0D 05            [ 1]  330 	tnz	(0x05, sp)
      008152 27 07            [ 1]  331 	jreq	00102$
                                    332 ;	source/FWLIB/src/stm8s_clk.c: 333: CLK->SWCR |= CLK_SWCR_SWIEN;
      008154 AA 04            [ 1]  333 	or	a, #0x04
      008156 C7 50 C5         [ 1]  334 	ld	0x50c5, a
      008159 20 05            [ 2]  335 	jra	00103$
      00815B                        336 00102$:
                                    337 ;	source/FWLIB/src/stm8s_clk.c: 337: CLK->SWCR &= (uint8_t)(~CLK_SWCR_SWIEN);
      00815B A4 FB            [ 1]  338 	and	a, #0xfb
      00815D C7 50 C5         [ 1]  339 	ld	0x50c5, a
      008160                        340 00103$:
                                    341 ;	source/FWLIB/src/stm8s_clk.c: 341: CLK->SWR = (uint8_t)CLK_NewClock;
      008160 AE 50 C4         [ 2]  342 	ldw	x, #0x50c4
      008163 7B 04            [ 1]  343 	ld	a, (0x04, sp)
      008165 F7               [ 1]  344 	ld	(x), a
                                    345 ;	source/FWLIB/src/stm8s_clk.c: 344: while((((CLK->SWCR & CLK_SWCR_SWBSY) != 0 )&& (DownCounter != 0)))
      008166 5F               [ 1]  346 	clrw	x
      008167 5A               [ 2]  347 	decw	x
      008168                        348 00105$:
      008168 C6 50 C5         [ 1]  349 	ld	a, 0x50c5
      00816B 44               [ 1]  350 	srl	a
      00816C 24 06            [ 1]  351 	jrnc	00107$
      00816E 5D               [ 2]  352 	tnzw	x
      00816F 27 03            [ 1]  353 	jreq	00107$
                                    354 ;	source/FWLIB/src/stm8s_clk.c: 346: DownCounter--;
      008171 5A               [ 2]  355 	decw	x
      008172 20 F4            [ 2]  356 	jra	00105$
      008174                        357 00107$:
                                    358 ;	source/FWLIB/src/stm8s_clk.c: 349: if(DownCounter != 0)
      008174 5D               [ 2]  359 	tnzw	x
      008175 27 05            [ 1]  360 	jreq	00109$
                                    361 ;	source/FWLIB/src/stm8s_clk.c: 351: Swif = SUCCESS;
      008177 A6 01            [ 1]  362 	ld	a, #0x01
      008179 97               [ 1]  363 	ld	xl, a
      00817A 20 34            [ 2]  364 	jra	00123$
      00817C                        365 00109$:
                                    366 ;	source/FWLIB/src/stm8s_clk.c: 355: Swif = ERROR;
      00817C 5F               [ 1]  367 	clrw	x
      00817D 20 31            [ 2]  368 	jra	00123$
      00817F                        369 00122$:
                                    370 ;	source/FWLIB/src/stm8s_clk.c: 361: if (ITState != DISABLE)
      00817F 0D 05            [ 1]  371 	tnz	(0x05, sp)
      008181 27 07            [ 1]  372 	jreq	00112$
                                    373 ;	source/FWLIB/src/stm8s_clk.c: 363: CLK->SWCR |= CLK_SWCR_SWIEN;
      008183 AA 04            [ 1]  374 	or	a, #0x04
      008185 C7 50 C5         [ 1]  375 	ld	0x50c5, a
      008188 20 05            [ 2]  376 	jra	00113$
      00818A                        377 00112$:
                                    378 ;	source/FWLIB/src/stm8s_clk.c: 367: CLK->SWCR &= (uint8_t)(~CLK_SWCR_SWIEN);
      00818A A4 FB            [ 1]  379 	and	a, #0xfb
      00818C C7 50 C5         [ 1]  380 	ld	0x50c5, a
      00818F                        381 00113$:
                                    382 ;	source/FWLIB/src/stm8s_clk.c: 371: CLK->SWR = (uint8_t)CLK_NewClock;
      00818F AE 50 C4         [ 2]  383 	ldw	x, #0x50c4
      008192 7B 04            [ 1]  384 	ld	a, (0x04, sp)
      008194 F7               [ 1]  385 	ld	(x), a
                                    386 ;	source/FWLIB/src/stm8s_clk.c: 374: while((((CLK->SWCR & CLK_SWCR_SWIF) != 0 ) && (DownCounter != 0)))
      008195 5F               [ 1]  387 	clrw	x
      008196 5A               [ 2]  388 	decw	x
      008197                        389 00115$:
      008197 C6 50 C5         [ 1]  390 	ld	a, 0x50c5
      00819A A5 08            [ 1]  391 	bcp	a, #0x08
      00819C 27 06            [ 1]  392 	jreq	00117$
      00819E 5D               [ 2]  393 	tnzw	x
      00819F 27 03            [ 1]  394 	jreq	00117$
                                    395 ;	source/FWLIB/src/stm8s_clk.c: 376: DownCounter--;
      0081A1 5A               [ 2]  396 	decw	x
      0081A2 20 F3            [ 2]  397 	jra	00115$
      0081A4                        398 00117$:
                                    399 ;	source/FWLIB/src/stm8s_clk.c: 379: if(DownCounter != 0)
      0081A4 5D               [ 2]  400 	tnzw	x
      0081A5 27 08            [ 1]  401 	jreq	00119$
                                    402 ;	source/FWLIB/src/stm8s_clk.c: 382: CLK->SWCR |= CLK_SWCR_SWEN;
      0081A7 72 12 50 C5      [ 1]  403 	bset	20677, #1
                                    404 ;	source/FWLIB/src/stm8s_clk.c: 383: Swif = SUCCESS;
      0081AB A6 01            [ 1]  405 	ld	a, #0x01
      0081AD 97               [ 1]  406 	ld	xl, a
                                    407 ;	source/FWLIB/src/stm8s_clk.c: 387: Swif = ERROR;
      0081AE 21                     408 	.byte 0x21
      0081AF                        409 00119$:
      0081AF 5F               [ 1]  410 	clrw	x
      0081B0                        411 00123$:
                                    412 ;	source/FWLIB/src/stm8s_clk.c: 390: if(Swif != ERROR)
      0081B0 9F               [ 1]  413 	ld	a, xl
      0081B1 4D               [ 1]  414 	tnz	a
      0081B2 27 2E            [ 1]  415 	jreq	00136$
                                    416 ;	source/FWLIB/src/stm8s_clk.c: 393: if((CLK_CurrentClockState == CLK_CURRENTCLOCKSTATE_DISABLE) && ( clock_master == CLK_SOURCE_HSI))
      0081B4 0D 06            [ 1]  417 	tnz	(0x06, sp)
      0081B6 26 0C            [ 1]  418 	jrne	00132$
      0081B8 90 9F            [ 1]  419 	ld	a, yl
      0081BA A1 E1            [ 1]  420 	cp	a, #0xe1
      0081BC 26 06            [ 1]  421 	jrne	00132$
                                    422 ;	source/FWLIB/src/stm8s_clk.c: 395: CLK->ICKR &= (uint8_t)(~CLK_ICKR_HSIEN);
      0081BE 72 11 50 C0      [ 1]  423 	bres	20672, #0
      0081C2 20 1E            [ 2]  424 	jra	00136$
      0081C4                        425 00132$:
                                    426 ;	source/FWLIB/src/stm8s_clk.c: 397: else if((CLK_CurrentClockState == CLK_CURRENTCLOCKSTATE_DISABLE) && ( clock_master == CLK_SOURCE_LSI))
      0081C4 0D 06            [ 1]  427 	tnz	(0x06, sp)
      0081C6 26 0C            [ 1]  428 	jrne	00128$
      0081C8 90 9F            [ 1]  429 	ld	a, yl
      0081CA A1 D2            [ 1]  430 	cp	a, #0xd2
      0081CC 26 06            [ 1]  431 	jrne	00128$
                                    432 ;	source/FWLIB/src/stm8s_clk.c: 399: CLK->ICKR &= (uint8_t)(~CLK_ICKR_LSIEN);
      0081CE 72 17 50 C0      [ 1]  433 	bres	20672, #3
      0081D2 20 0E            [ 2]  434 	jra	00136$
      0081D4                        435 00128$:
                                    436 ;	source/FWLIB/src/stm8s_clk.c: 401: else if ((CLK_CurrentClockState == CLK_CURRENTCLOCKSTATE_DISABLE) && ( clock_master == CLK_SOURCE_HSE))
      0081D4 0D 06            [ 1]  437 	tnz	(0x06, sp)
      0081D6 26 0A            [ 1]  438 	jrne	00136$
      0081D8 90 9F            [ 1]  439 	ld	a, yl
      0081DA A1 B4            [ 1]  440 	cp	a, #0xb4
      0081DC 26 04            [ 1]  441 	jrne	00136$
                                    442 ;	source/FWLIB/src/stm8s_clk.c: 403: CLK->ECKR &= (uint8_t)(~CLK_ECKR_HSEEN);
      0081DE 72 11 50 C1      [ 1]  443 	bres	20673, #0
      0081E2                        444 00136$:
                                    445 ;	source/FWLIB/src/stm8s_clk.c: 406: return(Swif);
      0081E2 9F               [ 1]  446 	ld	a, xl
                                    447 ;	source/FWLIB/src/stm8s_clk.c: 407: }
      0081E3 81               [ 4]  448 	ret
                                    449 ;	source/FWLIB/src/stm8s_clk.c: 415: void CLK_HSIPrescalerConfig(CLK_Prescaler_TypeDef HSIPrescaler)
                                    450 ;	-----------------------------------------
                                    451 ;	 function CLK_HSIPrescalerConfig
                                    452 ;	-----------------------------------------
      0081E4                        453 _CLK_HSIPrescalerConfig:
                                    454 ;	source/FWLIB/src/stm8s_clk.c: 421: CLK->CKDIVR &= (uint8_t)(~CLK_CKDIVR_HSIDIV);
      0081E4 C6 50 C6         [ 1]  455 	ld	a, 0x50c6
      0081E7 A4 E7            [ 1]  456 	and	a, #0xe7
      0081E9 C7 50 C6         [ 1]  457 	ld	0x50c6, a
                                    458 ;	source/FWLIB/src/stm8s_clk.c: 424: CLK->CKDIVR |= (uint8_t)HSIPrescaler;
      0081EC C6 50 C6         [ 1]  459 	ld	a, 0x50c6
      0081EF 1A 03            [ 1]  460 	or	a, (0x03, sp)
      0081F1 C7 50 C6         [ 1]  461 	ld	0x50c6, a
                                    462 ;	source/FWLIB/src/stm8s_clk.c: 425: }
      0081F4 81               [ 4]  463 	ret
                                    464 ;	source/FWLIB/src/stm8s_clk.c: 436: void CLK_CCOConfig(CLK_Output_TypeDef CLK_CCO)
                                    465 ;	-----------------------------------------
                                    466 ;	 function CLK_CCOConfig
                                    467 ;	-----------------------------------------
      0081F5                        468 _CLK_CCOConfig:
                                    469 ;	source/FWLIB/src/stm8s_clk.c: 442: CLK->CCOR &= (uint8_t)(~CLK_CCOR_CCOSEL);
      0081F5 C6 50 C9         [ 1]  470 	ld	a, 0x50c9
      0081F8 A4 E1            [ 1]  471 	and	a, #0xe1
      0081FA C7 50 C9         [ 1]  472 	ld	0x50c9, a
                                    473 ;	source/FWLIB/src/stm8s_clk.c: 445: CLK->CCOR |= (uint8_t)CLK_CCO;
      0081FD C6 50 C9         [ 1]  474 	ld	a, 0x50c9
      008200 1A 03            [ 1]  475 	or	a, (0x03, sp)
      008202 C7 50 C9         [ 1]  476 	ld	0x50c9, a
                                    477 ;	source/FWLIB/src/stm8s_clk.c: 448: CLK->CCOR |= CLK_CCOR_CCOEN;
      008205 72 10 50 C9      [ 1]  478 	bset	20681, #0
                                    479 ;	source/FWLIB/src/stm8s_clk.c: 449: }
      008209 81               [ 4]  480 	ret
                                    481 ;	source/FWLIB/src/stm8s_clk.c: 459: void CLK_ITConfig(CLK_IT_TypeDef CLK_IT, FunctionalState NewState)
                                    482 ;	-----------------------------------------
                                    483 ;	 function CLK_ITConfig
                                    484 ;	-----------------------------------------
      00820A                        485 _CLK_ITConfig:
      00820A 88               [ 1]  486 	push	a
                                    487 ;	source/FWLIB/src/stm8s_clk.c: 467: switch (CLK_IT)
      00820B 7B 04            [ 1]  488 	ld	a, (0x04, sp)
      00820D A0 0C            [ 1]  489 	sub	a, #0x0c
      00820F 26 04            [ 1]  490 	jrne	00140$
      008211 4C               [ 1]  491 	inc	a
      008212 6B 01            [ 1]  492 	ld	(0x01, sp), a
      008214 C5                     493 	.byte 0xc5
      008215                        494 00140$:
      008215 0F 01            [ 1]  495 	clr	(0x01, sp)
      008217                        496 00141$:
      008217 7B 04            [ 1]  497 	ld	a, (0x04, sp)
      008219 A0 1C            [ 1]  498 	sub	a, #0x1c
      00821B 26 02            [ 1]  499 	jrne	00143$
      00821D 4C               [ 1]  500 	inc	a
      00821E 21                     501 	.byte 0x21
      00821F                        502 00143$:
      00821F 4F               [ 1]  503 	clr	a
      008220                        504 00144$:
                                    505 ;	source/FWLIB/src/stm8s_clk.c: 465: if (NewState != DISABLE)
      008220 0D 05            [ 1]  506 	tnz	(0x05, sp)
      008222 27 13            [ 1]  507 	jreq	00110$
                                    508 ;	source/FWLIB/src/stm8s_clk.c: 467: switch (CLK_IT)
      008224 0D 01            [ 1]  509 	tnz	(0x01, sp)
      008226 26 09            [ 1]  510 	jrne	00102$
      008228 4D               [ 1]  511 	tnz	a
      008229 27 1D            [ 1]  512 	jreq	00112$
                                    513 ;	source/FWLIB/src/stm8s_clk.c: 470: CLK->SWCR |= CLK_SWCR_SWIEN;
      00822B 72 14 50 C5      [ 1]  514 	bset	20677, #2
                                    515 ;	source/FWLIB/src/stm8s_clk.c: 471: break;
      00822F 20 17            [ 2]  516 	jra	00112$
                                    517 ;	source/FWLIB/src/stm8s_clk.c: 472: case CLK_IT_CSSD: /* Enable the clock security system detection interrupt */
      008231                        518 00102$:
                                    519 ;	source/FWLIB/src/stm8s_clk.c: 473: CLK->CSSR |= CLK_CSSR_CSSDIE;
      008231 72 14 50 C8      [ 1]  520 	bset	20680, #2
                                    521 ;	source/FWLIB/src/stm8s_clk.c: 474: break;
      008235 20 11            [ 2]  522 	jra	00112$
                                    523 ;	source/FWLIB/src/stm8s_clk.c: 477: }
      008237                        524 00110$:
                                    525 ;	source/FWLIB/src/stm8s_clk.c: 481: switch (CLK_IT)
      008237 0D 01            [ 1]  526 	tnz	(0x01, sp)
      008239 26 09            [ 1]  527 	jrne	00106$
      00823B 4D               [ 1]  528 	tnz	a
      00823C 27 0A            [ 1]  529 	jreq	00112$
                                    530 ;	source/FWLIB/src/stm8s_clk.c: 484: CLK->SWCR  &= (uint8_t)(~CLK_SWCR_SWIEN);
      00823E 72 15 50 C5      [ 1]  531 	bres	20677, #2
                                    532 ;	source/FWLIB/src/stm8s_clk.c: 485: break;
      008242 20 04            [ 2]  533 	jra	00112$
                                    534 ;	source/FWLIB/src/stm8s_clk.c: 486: case CLK_IT_CSSD: /* Disable the clock security system detection interrupt */
      008244                        535 00106$:
                                    536 ;	source/FWLIB/src/stm8s_clk.c: 487: CLK->CSSR &= (uint8_t)(~CLK_CSSR_CSSDIE);
      008244 72 15 50 C8      [ 1]  537 	bres	20680, #2
                                    538 ;	source/FWLIB/src/stm8s_clk.c: 491: }
      008248                        539 00112$:
                                    540 ;	source/FWLIB/src/stm8s_clk.c: 493: }
      008248 84               [ 1]  541 	pop	a
      008249 81               [ 4]  542 	ret
                                    543 ;	source/FWLIB/src/stm8s_clk.c: 500: void CLK_SYSCLKConfig(CLK_Prescaler_TypeDef CLK_Prescaler)
                                    544 ;	-----------------------------------------
                                    545 ;	 function CLK_SYSCLKConfig
                                    546 ;	-----------------------------------------
      00824A                        547 _CLK_SYSCLKConfig:
      00824A 88               [ 1]  548 	push	a
                                    549 ;	source/FWLIB/src/stm8s_clk.c: 507: CLK->CKDIVR &= (uint8_t)(~CLK_CKDIVR_HSIDIV);
      00824B C6 50 C6         [ 1]  550 	ld	a, 0x50c6
                                    551 ;	source/FWLIB/src/stm8s_clk.c: 505: if (((uint8_t)CLK_Prescaler & (uint8_t)0x80) == 0x00) /* Bit7 = 0 means HSI divider */
      00824E 0D 04            [ 1]  552 	tnz	(0x04, sp)
      008250 2B 15            [ 1]  553 	jrmi	00102$
                                    554 ;	source/FWLIB/src/stm8s_clk.c: 507: CLK->CKDIVR &= (uint8_t)(~CLK_CKDIVR_HSIDIV);
      008252 A4 E7            [ 1]  555 	and	a, #0xe7
      008254 C7 50 C6         [ 1]  556 	ld	0x50c6, a
                                    557 ;	source/FWLIB/src/stm8s_clk.c: 508: CLK->CKDIVR |= (uint8_t)((uint8_t)CLK_Prescaler & (uint8_t)CLK_CKDIVR_HSIDIV);
      008257 C6 50 C6         [ 1]  558 	ld	a, 0x50c6
      00825A 6B 01            [ 1]  559 	ld	(0x01, sp), a
      00825C 7B 04            [ 1]  560 	ld	a, (0x04, sp)
      00825E A4 18            [ 1]  561 	and	a, #0x18
      008260 1A 01            [ 1]  562 	or	a, (0x01, sp)
      008262 C7 50 C6         [ 1]  563 	ld	0x50c6, a
      008265 20 13            [ 2]  564 	jra	00104$
      008267                        565 00102$:
                                    566 ;	source/FWLIB/src/stm8s_clk.c: 512: CLK->CKDIVR &= (uint8_t)(~CLK_CKDIVR_CPUDIV);
      008267 A4 F8            [ 1]  567 	and	a, #0xf8
      008269 C7 50 C6         [ 1]  568 	ld	0x50c6, a
                                    569 ;	source/FWLIB/src/stm8s_clk.c: 513: CLK->CKDIVR |= (uint8_t)((uint8_t)CLK_Prescaler & (uint8_t)CLK_CKDIVR_CPUDIV);
      00826C C6 50 C6         [ 1]  570 	ld	a, 0x50c6
      00826F 6B 01            [ 1]  571 	ld	(0x01, sp), a
      008271 7B 04            [ 1]  572 	ld	a, (0x04, sp)
      008273 A4 07            [ 1]  573 	and	a, #0x07
      008275 1A 01            [ 1]  574 	or	a, (0x01, sp)
      008277 C7 50 C6         [ 1]  575 	ld	0x50c6, a
      00827A                        576 00104$:
                                    577 ;	source/FWLIB/src/stm8s_clk.c: 515: }
      00827A 84               [ 1]  578 	pop	a
      00827B 81               [ 4]  579 	ret
                                    580 ;	source/FWLIB/src/stm8s_clk.c: 523: void CLK_SWIMConfig(CLK_SWIMDivider_TypeDef CLK_SWIMDivider)
                                    581 ;	-----------------------------------------
                                    582 ;	 function CLK_SWIMConfig
                                    583 ;	-----------------------------------------
      00827C                        584 _CLK_SWIMConfig:
                                    585 ;	source/FWLIB/src/stm8s_clk.c: 531: CLK->SWIMCCR |= CLK_SWIMCCR_SWIMDIV;
      00827C C6 50 CD         [ 1]  586 	ld	a, 0x50cd
                                    587 ;	source/FWLIB/src/stm8s_clk.c: 528: if (CLK_SWIMDivider != CLK_SWIMDIVIDER_2)
      00827F 0D 03            [ 1]  588 	tnz	(0x03, sp)
      008281 27 06            [ 1]  589 	jreq	00102$
                                    590 ;	source/FWLIB/src/stm8s_clk.c: 531: CLK->SWIMCCR |= CLK_SWIMCCR_SWIMDIV;
      008283 AA 01            [ 1]  591 	or	a, #0x01
      008285 C7 50 CD         [ 1]  592 	ld	0x50cd, a
      008288 81               [ 4]  593 	ret
      008289                        594 00102$:
                                    595 ;	source/FWLIB/src/stm8s_clk.c: 536: CLK->SWIMCCR &= (uint8_t)(~CLK_SWIMCCR_SWIMDIV);
      008289 A4 FE            [ 1]  596 	and	a, #0xfe
      00828B C7 50 CD         [ 1]  597 	ld	0x50cd, a
                                    598 ;	source/FWLIB/src/stm8s_clk.c: 538: }
      00828E 81               [ 4]  599 	ret
                                    600 ;	source/FWLIB/src/stm8s_clk.c: 547: void CLK_ClockSecuritySystemEnable(void)
                                    601 ;	-----------------------------------------
                                    602 ;	 function CLK_ClockSecuritySystemEnable
                                    603 ;	-----------------------------------------
      00828F                        604 _CLK_ClockSecuritySystemEnable:
                                    605 ;	source/FWLIB/src/stm8s_clk.c: 550: CLK->CSSR |= CLK_CSSR_CSSEN;
      00828F 72 10 50 C8      [ 1]  606 	bset	20680, #0
                                    607 ;	source/FWLIB/src/stm8s_clk.c: 551: }
      008293 81               [ 4]  608 	ret
                                    609 ;	source/FWLIB/src/stm8s_clk.c: 559: CLK_Source_TypeDef CLK_GetSYSCLKSource(void)
                                    610 ;	-----------------------------------------
                                    611 ;	 function CLK_GetSYSCLKSource
                                    612 ;	-----------------------------------------
      008294                        613 _CLK_GetSYSCLKSource:
                                    614 ;	source/FWLIB/src/stm8s_clk.c: 561: return((CLK_Source_TypeDef)CLK->CMSR);
      008294 C6 50 C3         [ 1]  615 	ld	a, 0x50c3
                                    616 ;	source/FWLIB/src/stm8s_clk.c: 562: }
      008297 81               [ 4]  617 	ret
                                    618 ;	source/FWLIB/src/stm8s_clk.c: 569: uint32_t CLK_GetClockFreq(void)
                                    619 ;	-----------------------------------------
                                    620 ;	 function CLK_GetClockFreq
                                    621 ;	-----------------------------------------
      008298                        622 _CLK_GetClockFreq:
      008298 52 04            [ 2]  623 	sub	sp, #4
                                    624 ;	source/FWLIB/src/stm8s_clk.c: 576: clocksource = (CLK_Source_TypeDef)CLK->CMSR;
      00829A C6 50 C3         [ 1]  625 	ld	a, 0x50c3
                                    626 ;	source/FWLIB/src/stm8s_clk.c: 578: if (clocksource == CLK_SOURCE_HSI)
      00829D 6B 04            [ 1]  627 	ld	(0x04, sp), a
      00829F A1 E1            [ 1]  628 	cp	a, #0xe1
      0082A1 26 26            [ 1]  629 	jrne	00105$
                                    630 ;	source/FWLIB/src/stm8s_clk.c: 580: tmp = (uint8_t)(CLK->CKDIVR & CLK_CKDIVR_HSIDIV);
      0082A3 C6 50 C6         [ 1]  631 	ld	a, 0x50c6
      0082A6 A4 18            [ 1]  632 	and	a, #0x18
                                    633 ;	source/FWLIB/src/stm8s_clk.c: 581: tmp = (uint8_t)(tmp >> 3);
      0082A8 44               [ 1]  634 	srl	a
      0082A9 44               [ 1]  635 	srl	a
      0082AA 44               [ 1]  636 	srl	a
                                    637 ;	source/FWLIB/src/stm8s_clk.c: 582: presc = HSIDivFactor[tmp];
      0082AB 5F               [ 1]  638 	clrw	x
      0082AC 97               [ 1]  639 	ld	xl, a
      0082AD 1C 80 24         [ 2]  640 	addw	x, #(_HSIDivFactor + 0)
      0082B0 F6               [ 1]  641 	ld	a, (x)
                                    642 ;	source/FWLIB/src/stm8s_clk.c: 583: clockfrequency = HSI_VALUE / presc;
      0082B1 5F               [ 1]  643 	clrw	x
      0082B2 97               [ 1]  644 	ld	xl, a
      0082B3 90 5F            [ 1]  645 	clrw	y
      0082B5 89               [ 2]  646 	pushw	x
      0082B6 90 89            [ 2]  647 	pushw	y
      0082B8 4B 00            [ 1]  648 	push	#0x00
      0082BA 4B 24            [ 1]  649 	push	#0x24
      0082BC 4B F4            [ 1]  650 	push	#0xf4
      0082BE 4B 00            [ 1]  651 	push	#0x00
      0082C0 CD 83 72         [ 4]  652 	call	__divulong
      0082C3 5B 08            [ 2]  653 	addw	sp, #8
      0082C5 1F 03            [ 2]  654 	ldw	(0x03, sp), x
      0082C7 20 1A            [ 2]  655 	jra	00106$
      0082C9                        656 00105$:
                                    657 ;	source/FWLIB/src/stm8s_clk.c: 585: else if ( clocksource == CLK_SOURCE_LSI)
      0082C9 7B 04            [ 1]  658 	ld	a, (0x04, sp)
      0082CB A1 D2            [ 1]  659 	cp	a, #0xd2
      0082CD 26 0B            [ 1]  660 	jrne	00102$
                                    661 ;	source/FWLIB/src/stm8s_clk.c: 587: clockfrequency = LSI_VALUE;
      0082CF AE F4 00         [ 2]  662 	ldw	x, #0xf400
      0082D2 1F 03            [ 2]  663 	ldw	(0x03, sp), x
      0082D4 90 AE 00 01      [ 2]  664 	ldw	y, #0x0001
      0082D8 20 09            [ 2]  665 	jra	00106$
      0082DA                        666 00102$:
                                    667 ;	source/FWLIB/src/stm8s_clk.c: 591: clockfrequency = HSE_VALUE;
      0082DA AE 24 00         [ 2]  668 	ldw	x, #0x2400
      0082DD 1F 03            [ 2]  669 	ldw	(0x03, sp), x
      0082DF 90 AE 00 F4      [ 2]  670 	ldw	y, #0x00f4
      0082E3                        671 00106$:
                                    672 ;	source/FWLIB/src/stm8s_clk.c: 594: return((uint32_t)clockfrequency);
      0082E3 1E 03            [ 2]  673 	ldw	x, (0x03, sp)
                                    674 ;	source/FWLIB/src/stm8s_clk.c: 595: }
      0082E5 5B 04            [ 2]  675 	addw	sp, #4
      0082E7 81               [ 4]  676 	ret
                                    677 ;	source/FWLIB/src/stm8s_clk.c: 604: void CLK_AdjustHSICalibrationValue(CLK_HSITrimValue_TypeDef CLK_HSICalibrationValue)
                                    678 ;	-----------------------------------------
                                    679 ;	 function CLK_AdjustHSICalibrationValue
                                    680 ;	-----------------------------------------
      0082E8                        681 _CLK_AdjustHSICalibrationValue:
                                    682 ;	source/FWLIB/src/stm8s_clk.c: 610: CLK->HSITRIMR = (uint8_t)( (uint8_t)(CLK->HSITRIMR & (uint8_t)(~CLK_HSITRIMR_HSITRIM))|((uint8_t)CLK_HSICalibrationValue));
      0082E8 C6 50 CC         [ 1]  683 	ld	a, 0x50cc
      0082EB A4 F8            [ 1]  684 	and	a, #0xf8
      0082ED 1A 03            [ 1]  685 	or	a, (0x03, sp)
      0082EF C7 50 CC         [ 1]  686 	ld	0x50cc, a
                                    687 ;	source/FWLIB/src/stm8s_clk.c: 611: }
      0082F2 81               [ 4]  688 	ret
                                    689 ;	source/FWLIB/src/stm8s_clk.c: 622: void CLK_SYSCLKEmergencyClear(void)
                                    690 ;	-----------------------------------------
                                    691 ;	 function CLK_SYSCLKEmergencyClear
                                    692 ;	-----------------------------------------
      0082F3                        693 _CLK_SYSCLKEmergencyClear:
                                    694 ;	source/FWLIB/src/stm8s_clk.c: 624: CLK->SWCR &= (uint8_t)(~CLK_SWCR_SWBSY);
      0082F3 72 11 50 C5      [ 1]  695 	bres	20677, #0
                                    696 ;	source/FWLIB/src/stm8s_clk.c: 625: }
      0082F7 81               [ 4]  697 	ret
                                    698 ;	source/FWLIB/src/stm8s_clk.c: 634: FlagStatus CLK_GetFlagStatus(CLK_Flag_TypeDef CLK_FLAG)
                                    699 ;	-----------------------------------------
                                    700 ;	 function CLK_GetFlagStatus
                                    701 ;	-----------------------------------------
      0082F8                        702 _CLK_GetFlagStatus:
      0082F8 52 02            [ 2]  703 	sub	sp, #2
                                    704 ;	source/FWLIB/src/stm8s_clk.c: 644: statusreg = (uint16_t)((uint16_t)CLK_FLAG & (uint16_t)0xFF00);
      0082FA 1E 05            [ 2]  705 	ldw	x, (0x05, sp)
      0082FC 4F               [ 1]  706 	clr	a
      0082FD 97               [ 1]  707 	ld	xl, a
                                    708 ;	source/FWLIB/src/stm8s_clk.c: 647: if (statusreg == 0x0100) /* The flag to check is in ICKRregister */
      0082FE 1F 01            [ 2]  709 	ldw	(0x01, sp), x
      008300 A3 01 00         [ 2]  710 	cpw	x, #0x0100
      008303 26 05            [ 1]  711 	jrne	00111$
                                    712 ;	source/FWLIB/src/stm8s_clk.c: 649: tmpreg = CLK->ICKR;
      008305 C6 50 C0         [ 1]  713 	ld	a, 0x50c0
      008308 20 27            [ 2]  714 	jra	00112$
      00830A                        715 00111$:
                                    716 ;	source/FWLIB/src/stm8s_clk.c: 651: else if (statusreg == 0x0200) /* The flag to check is in ECKRregister */
      00830A 1E 01            [ 2]  717 	ldw	x, (0x01, sp)
      00830C A3 02 00         [ 2]  718 	cpw	x, #0x0200
      00830F 26 05            [ 1]  719 	jrne	00108$
                                    720 ;	source/FWLIB/src/stm8s_clk.c: 653: tmpreg = CLK->ECKR;
      008311 C6 50 C1         [ 1]  721 	ld	a, 0x50c1
      008314 20 1B            [ 2]  722 	jra	00112$
      008316                        723 00108$:
                                    724 ;	source/FWLIB/src/stm8s_clk.c: 655: else if (statusreg == 0x0300) /* The flag to check is in SWIC register */
      008316 1E 01            [ 2]  725 	ldw	x, (0x01, sp)
      008318 A3 03 00         [ 2]  726 	cpw	x, #0x0300
      00831B 26 05            [ 1]  727 	jrne	00105$
                                    728 ;	source/FWLIB/src/stm8s_clk.c: 657: tmpreg = CLK->SWCR;
      00831D C6 50 C5         [ 1]  729 	ld	a, 0x50c5
      008320 20 0F            [ 2]  730 	jra	00112$
      008322                        731 00105$:
                                    732 ;	source/FWLIB/src/stm8s_clk.c: 659: else if (statusreg == 0x0400) /* The flag to check is in CSS register */
      008322 1E 01            [ 2]  733 	ldw	x, (0x01, sp)
      008324 A3 04 00         [ 2]  734 	cpw	x, #0x0400
      008327 26 05            [ 1]  735 	jrne	00102$
                                    736 ;	source/FWLIB/src/stm8s_clk.c: 661: tmpreg = CLK->CSSR;
      008329 C6 50 C8         [ 1]  737 	ld	a, 0x50c8
      00832C 20 03            [ 2]  738 	jra	00112$
      00832E                        739 00102$:
                                    740 ;	source/FWLIB/src/stm8s_clk.c: 665: tmpreg = CLK->CCOR;
      00832E C6 50 C9         [ 1]  741 	ld	a, 0x50c9
      008331                        742 00112$:
                                    743 ;	source/FWLIB/src/stm8s_clk.c: 668: if ((tmpreg & (uint8_t)CLK_FLAG) != (uint8_t)RESET)
      008331 88               [ 1]  744 	push	a
      008332 7B 07            [ 1]  745 	ld	a, (0x07, sp)
      008334 6B 03            [ 1]  746 	ld	(0x03, sp), a
      008336 84               [ 1]  747 	pop	a
      008337 14 02            [ 1]  748 	and	a, (0x02, sp)
      008339 27 03            [ 1]  749 	jreq	00114$
                                    750 ;	source/FWLIB/src/stm8s_clk.c: 670: bitstatus = SET;
      00833B A6 01            [ 1]  751 	ld	a, #0x01
                                    752 ;	source/FWLIB/src/stm8s_clk.c: 674: bitstatus = RESET;
      00833D 21                     753 	.byte 0x21
      00833E                        754 00114$:
      00833E 4F               [ 1]  755 	clr	a
      00833F                        756 00115$:
                                    757 ;	source/FWLIB/src/stm8s_clk.c: 678: return((FlagStatus)bitstatus);
                                    758 ;	source/FWLIB/src/stm8s_clk.c: 679: }
      00833F 5B 02            [ 2]  759 	addw	sp, #2
      008341 81               [ 4]  760 	ret
                                    761 ;	source/FWLIB/src/stm8s_clk.c: 687: ITStatus CLK_GetITStatus(CLK_IT_TypeDef CLK_IT)
                                    762 ;	-----------------------------------------
                                    763 ;	 function CLK_GetITStatus
                                    764 ;	-----------------------------------------
      008342                        765 _CLK_GetITStatus:
                                    766 ;	source/FWLIB/src/stm8s_clk.c: 694: if (CLK_IT == CLK_IT_SWIF)
      008342 7B 03            [ 1]  767 	ld	a, (0x03, sp)
      008344 A1 1C            [ 1]  768 	cp	a, #0x1c
      008346 26 0D            [ 1]  769 	jrne	00108$
                                    770 ;	source/FWLIB/src/stm8s_clk.c: 697: if ((CLK->SWCR & (uint8_t)CLK_IT) == (uint8_t)0x0C)
      008348 C6 50 C5         [ 1]  771 	ld	a, 0x50c5
      00834B 14 03            [ 1]  772 	and	a, (0x03, sp)
                                    773 ;	source/FWLIB/src/stm8s_clk.c: 699: bitstatus = SET;
      00834D A0 0C            [ 1]  774 	sub	a, #0x0c
      00834F 26 02            [ 1]  775 	jrne	00102$
      008351 4C               [ 1]  776 	inc	a
      008352 81               [ 4]  777 	ret
      008353                        778 00102$:
                                    779 ;	source/FWLIB/src/stm8s_clk.c: 703: bitstatus = RESET;
      008353 4F               [ 1]  780 	clr	a
      008354 81               [ 4]  781 	ret
      008355                        782 00108$:
                                    783 ;	source/FWLIB/src/stm8s_clk.c: 709: if ((CLK->CSSR & (uint8_t)CLK_IT) == (uint8_t)0x0C)
      008355 C6 50 C8         [ 1]  784 	ld	a, 0x50c8
      008358 14 03            [ 1]  785 	and	a, (0x03, sp)
                                    786 ;	source/FWLIB/src/stm8s_clk.c: 711: bitstatus = SET;
      00835A A0 0C            [ 1]  787 	sub	a, #0x0c
      00835C 26 02            [ 1]  788 	jrne	00105$
      00835E 4C               [ 1]  789 	inc	a
      00835F 81               [ 4]  790 	ret
      008360                        791 00105$:
                                    792 ;	source/FWLIB/src/stm8s_clk.c: 715: bitstatus = RESET;
      008360 4F               [ 1]  793 	clr	a
                                    794 ;	source/FWLIB/src/stm8s_clk.c: 720: return bitstatus;
                                    795 ;	source/FWLIB/src/stm8s_clk.c: 721: }
      008361 81               [ 4]  796 	ret
                                    797 ;	source/FWLIB/src/stm8s_clk.c: 729: void CLK_ClearITPendingBit(CLK_IT_TypeDef CLK_IT)
                                    798 ;	-----------------------------------------
                                    799 ;	 function CLK_ClearITPendingBit
                                    800 ;	-----------------------------------------
      008362                        801 _CLK_ClearITPendingBit:
                                    802 ;	source/FWLIB/src/stm8s_clk.c: 734: if (CLK_IT == (uint8_t)CLK_IT_CSSD)
      008362 7B 03            [ 1]  803 	ld	a, (0x03, sp)
      008364 A1 0C            [ 1]  804 	cp	a, #0x0c
      008366 26 05            [ 1]  805 	jrne	00102$
                                    806 ;	source/FWLIB/src/stm8s_clk.c: 737: CLK->CSSR &= (uint8_t)(~CLK_CSSR_CSSD);
      008368 72 17 50 C8      [ 1]  807 	bres	20680, #3
      00836C 81               [ 4]  808 	ret
      00836D                        809 00102$:
                                    810 ;	source/FWLIB/src/stm8s_clk.c: 742: CLK->SWCR &= (uint8_t)(~CLK_SWCR_SWIF);
      00836D 72 17 50 C5      [ 1]  811 	bres	20677, #3
                                    812 ;	source/FWLIB/src/stm8s_clk.c: 745: }
      008371 81               [ 4]  813 	ret
                                    814 	.area CODE
                                    815 	.area CONST
      008024                        816 _HSIDivFactor:
      008024 01                     817 	.db #0x01	; 1
      008025 02                     818 	.db #0x02	; 2
      008026 04                     819 	.db #0x04	; 4
      008027 08                     820 	.db #0x08	; 8
      008028                        821 _CLKPrescTable:
      008028 01                     822 	.db #0x01	; 1
      008029 02                     823 	.db #0x02	; 2
      00802A 04                     824 	.db #0x04	; 4
      00802B 08                     825 	.db #0x08	; 8
      00802C 0A                     826 	.db #0x0a	; 10
      00802D 10                     827 	.db #0x10	; 16
      00802E 14                     828 	.db #0x14	; 20
      00802F 28                     829 	.db #0x28	; 40
                                    830 	.area INITIALIZER
                                    831 	.area CABS (ABS)
