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
      008638                         77 _CLK_DeInit:
                                     78 ;	source/FWLIB/src/stm8s_clk.c: 74: CLK->ICKR = CLK_ICKR_RESET_VALUE;
      008638 35 01 50 C0      [ 1]   79 	mov	0x50c0+0, #0x01
                                     80 ;	source/FWLIB/src/stm8s_clk.c: 75: CLK->ECKR = CLK_ECKR_RESET_VALUE;
      00863C 35 00 50 C1      [ 1]   81 	mov	0x50c1+0, #0x00
                                     82 ;	source/FWLIB/src/stm8s_clk.c: 76: CLK->SWR  = CLK_SWR_RESET_VALUE;
      008640 35 E1 50 C4      [ 1]   83 	mov	0x50c4+0, #0xe1
                                     84 ;	source/FWLIB/src/stm8s_clk.c: 77: CLK->SWCR = CLK_SWCR_RESET_VALUE;
      008644 35 00 50 C5      [ 1]   85 	mov	0x50c5+0, #0x00
                                     86 ;	source/FWLIB/src/stm8s_clk.c: 78: CLK->CKDIVR = CLK_CKDIVR_RESET_VALUE;
      008648 35 18 50 C6      [ 1]   87 	mov	0x50c6+0, #0x18
                                     88 ;	source/FWLIB/src/stm8s_clk.c: 79: CLK->PCKENR1 = CLK_PCKENR1_RESET_VALUE;
      00864C 35 FF 50 C7      [ 1]   89 	mov	0x50c7+0, #0xff
                                     90 ;	source/FWLIB/src/stm8s_clk.c: 80: CLK->PCKENR2 = CLK_PCKENR2_RESET_VALUE;
      008650 35 FF 50 CA      [ 1]   91 	mov	0x50ca+0, #0xff
                                     92 ;	source/FWLIB/src/stm8s_clk.c: 81: CLK->CSSR = CLK_CSSR_RESET_VALUE;
      008654 35 00 50 C8      [ 1]   93 	mov	0x50c8+0, #0x00
                                     94 ;	source/FWLIB/src/stm8s_clk.c: 82: CLK->CCOR = CLK_CCOR_RESET_VALUE;
      008658 35 00 50 C9      [ 1]   95 	mov	0x50c9+0, #0x00
                                     96 ;	source/FWLIB/src/stm8s_clk.c: 83: while ((CLK->CCOR & CLK_CCOR_CCOEN)!= 0)
      00865C                         97 00101$:
      00865C C6 50 C9         [ 1]   98 	ld	a, 0x50c9
      00865F 44               [ 1]   99 	srl	a
      008660 25 FA            [ 1]  100 	jrc	00101$
                                    101 ;	source/FWLIB/src/stm8s_clk.c: 85: CLK->CCOR = CLK_CCOR_RESET_VALUE;
      008662 35 00 50 C9      [ 1]  102 	mov	0x50c9+0, #0x00
                                    103 ;	source/FWLIB/src/stm8s_clk.c: 86: CLK->HSITRIMR = CLK_HSITRIMR_RESET_VALUE;
      008666 35 00 50 CC      [ 1]  104 	mov	0x50cc+0, #0x00
                                    105 ;	source/FWLIB/src/stm8s_clk.c: 87: CLK->SWIMCCR = CLK_SWIMCCR_RESET_VALUE;
      00866A 35 00 50 CD      [ 1]  106 	mov	0x50cd+0, #0x00
                                    107 ;	source/FWLIB/src/stm8s_clk.c: 88: }
      00866E 81               [ 4]  108 	ret
                                    109 ;	source/FWLIB/src/stm8s_clk.c: 99: void CLK_FastHaltWakeUpCmd(FunctionalState NewState)
                                    110 ;	-----------------------------------------
                                    111 ;	 function CLK_FastHaltWakeUpCmd
                                    112 ;	-----------------------------------------
      00866F                        113 _CLK_FastHaltWakeUpCmd:
                                    114 ;	source/FWLIB/src/stm8s_clk.c: 107: CLK->ICKR |= CLK_ICKR_FHWU;
      00866F C6 50 C0         [ 1]  115 	ld	a, 0x50c0
                                    116 ;	source/FWLIB/src/stm8s_clk.c: 104: if (NewState != DISABLE)
      008672 0D 03            [ 1]  117 	tnz	(0x03, sp)
      008674 27 06            [ 1]  118 	jreq	00102$
                                    119 ;	source/FWLIB/src/stm8s_clk.c: 107: CLK->ICKR |= CLK_ICKR_FHWU;
      008676 AA 04            [ 1]  120 	or	a, #0x04
      008678 C7 50 C0         [ 1]  121 	ld	0x50c0, a
      00867B 81               [ 4]  122 	ret
      00867C                        123 00102$:
                                    124 ;	source/FWLIB/src/stm8s_clk.c: 112: CLK->ICKR &= (uint8_t)(~CLK_ICKR_FHWU);
      00867C A4 FB            [ 1]  125 	and	a, #0xfb
      00867E C7 50 C0         [ 1]  126 	ld	0x50c0, a
                                    127 ;	source/FWLIB/src/stm8s_clk.c: 114: }
      008681 81               [ 4]  128 	ret
                                    129 ;	source/FWLIB/src/stm8s_clk.c: 121: void CLK_HSECmd(FunctionalState NewState)
                                    130 ;	-----------------------------------------
                                    131 ;	 function CLK_HSECmd
                                    132 ;	-----------------------------------------
      008682                        133 _CLK_HSECmd:
                                    134 ;	source/FWLIB/src/stm8s_clk.c: 129: CLK->ECKR |= CLK_ECKR_HSEEN;
      008682 C6 50 C1         [ 1]  135 	ld	a, 0x50c1
                                    136 ;	source/FWLIB/src/stm8s_clk.c: 126: if (NewState != DISABLE)
      008685 0D 03            [ 1]  137 	tnz	(0x03, sp)
      008687 27 06            [ 1]  138 	jreq	00102$
                                    139 ;	source/FWLIB/src/stm8s_clk.c: 129: CLK->ECKR |= CLK_ECKR_HSEEN;
      008689 AA 01            [ 1]  140 	or	a, #0x01
      00868B C7 50 C1         [ 1]  141 	ld	0x50c1, a
      00868E 81               [ 4]  142 	ret
      00868F                        143 00102$:
                                    144 ;	source/FWLIB/src/stm8s_clk.c: 134: CLK->ECKR &= (uint8_t)(~CLK_ECKR_HSEEN);
      00868F A4 FE            [ 1]  145 	and	a, #0xfe
      008691 C7 50 C1         [ 1]  146 	ld	0x50c1, a
                                    147 ;	source/FWLIB/src/stm8s_clk.c: 136: }
      008694 81               [ 4]  148 	ret
                                    149 ;	source/FWLIB/src/stm8s_clk.c: 143: void CLK_HSICmd(FunctionalState NewState)
                                    150 ;	-----------------------------------------
                                    151 ;	 function CLK_HSICmd
                                    152 ;	-----------------------------------------
      008695                        153 _CLK_HSICmd:
                                    154 ;	source/FWLIB/src/stm8s_clk.c: 151: CLK->ICKR |= CLK_ICKR_HSIEN;
      008695 C6 50 C0         [ 1]  155 	ld	a, 0x50c0
                                    156 ;	source/FWLIB/src/stm8s_clk.c: 148: if (NewState != DISABLE)
      008698 0D 03            [ 1]  157 	tnz	(0x03, sp)
      00869A 27 06            [ 1]  158 	jreq	00102$
                                    159 ;	source/FWLIB/src/stm8s_clk.c: 151: CLK->ICKR |= CLK_ICKR_HSIEN;
      00869C AA 01            [ 1]  160 	or	a, #0x01
      00869E C7 50 C0         [ 1]  161 	ld	0x50c0, a
      0086A1 81               [ 4]  162 	ret
      0086A2                        163 00102$:
                                    164 ;	source/FWLIB/src/stm8s_clk.c: 156: CLK->ICKR &= (uint8_t)(~CLK_ICKR_HSIEN);
      0086A2 A4 FE            [ 1]  165 	and	a, #0xfe
      0086A4 C7 50 C0         [ 1]  166 	ld	0x50c0, a
                                    167 ;	source/FWLIB/src/stm8s_clk.c: 158: }
      0086A7 81               [ 4]  168 	ret
                                    169 ;	source/FWLIB/src/stm8s_clk.c: 166: void CLK_LSICmd(FunctionalState NewState)
                                    170 ;	-----------------------------------------
                                    171 ;	 function CLK_LSICmd
                                    172 ;	-----------------------------------------
      0086A8                        173 _CLK_LSICmd:
                                    174 ;	source/FWLIB/src/stm8s_clk.c: 174: CLK->ICKR |= CLK_ICKR_LSIEN;
      0086A8 C6 50 C0         [ 1]  175 	ld	a, 0x50c0
                                    176 ;	source/FWLIB/src/stm8s_clk.c: 171: if (NewState != DISABLE)
      0086AB 0D 03            [ 1]  177 	tnz	(0x03, sp)
      0086AD 27 06            [ 1]  178 	jreq	00102$
                                    179 ;	source/FWLIB/src/stm8s_clk.c: 174: CLK->ICKR |= CLK_ICKR_LSIEN;
      0086AF AA 08            [ 1]  180 	or	a, #0x08
      0086B1 C7 50 C0         [ 1]  181 	ld	0x50c0, a
      0086B4 81               [ 4]  182 	ret
      0086B5                        183 00102$:
                                    184 ;	source/FWLIB/src/stm8s_clk.c: 179: CLK->ICKR &= (uint8_t)(~CLK_ICKR_LSIEN);
      0086B5 A4 F7            [ 1]  185 	and	a, #0xf7
      0086B7 C7 50 C0         [ 1]  186 	ld	0x50c0, a
                                    187 ;	source/FWLIB/src/stm8s_clk.c: 181: }
      0086BA 81               [ 4]  188 	ret
                                    189 ;	source/FWLIB/src/stm8s_clk.c: 189: void CLK_CCOCmd(FunctionalState NewState)
                                    190 ;	-----------------------------------------
                                    191 ;	 function CLK_CCOCmd
                                    192 ;	-----------------------------------------
      0086BB                        193 _CLK_CCOCmd:
                                    194 ;	source/FWLIB/src/stm8s_clk.c: 197: CLK->CCOR |= CLK_CCOR_CCOEN;
      0086BB C6 50 C9         [ 1]  195 	ld	a, 0x50c9
                                    196 ;	source/FWLIB/src/stm8s_clk.c: 194: if (NewState != DISABLE)
      0086BE 0D 03            [ 1]  197 	tnz	(0x03, sp)
      0086C0 27 06            [ 1]  198 	jreq	00102$
                                    199 ;	source/FWLIB/src/stm8s_clk.c: 197: CLK->CCOR |= CLK_CCOR_CCOEN;
      0086C2 AA 01            [ 1]  200 	or	a, #0x01
      0086C4 C7 50 C9         [ 1]  201 	ld	0x50c9, a
      0086C7 81               [ 4]  202 	ret
      0086C8                        203 00102$:
                                    204 ;	source/FWLIB/src/stm8s_clk.c: 202: CLK->CCOR &= (uint8_t)(~CLK_CCOR_CCOEN);
      0086C8 A4 FE            [ 1]  205 	and	a, #0xfe
      0086CA C7 50 C9         [ 1]  206 	ld	0x50c9, a
                                    207 ;	source/FWLIB/src/stm8s_clk.c: 204: }
      0086CD 81               [ 4]  208 	ret
                                    209 ;	source/FWLIB/src/stm8s_clk.c: 213: void CLK_ClockSwitchCmd(FunctionalState NewState)
                                    210 ;	-----------------------------------------
                                    211 ;	 function CLK_ClockSwitchCmd
                                    212 ;	-----------------------------------------
      0086CE                        213 _CLK_ClockSwitchCmd:
                                    214 ;	source/FWLIB/src/stm8s_clk.c: 221: CLK->SWCR |= CLK_SWCR_SWEN;
      0086CE C6 50 C5         [ 1]  215 	ld	a, 0x50c5
                                    216 ;	source/FWLIB/src/stm8s_clk.c: 218: if (NewState != DISABLE )
      0086D1 0D 03            [ 1]  217 	tnz	(0x03, sp)
      0086D3 27 06            [ 1]  218 	jreq	00102$
                                    219 ;	source/FWLIB/src/stm8s_clk.c: 221: CLK->SWCR |= CLK_SWCR_SWEN;
      0086D5 AA 02            [ 1]  220 	or	a, #0x02
      0086D7 C7 50 C5         [ 1]  221 	ld	0x50c5, a
      0086DA 81               [ 4]  222 	ret
      0086DB                        223 00102$:
                                    224 ;	source/FWLIB/src/stm8s_clk.c: 226: CLK->SWCR &= (uint8_t)(~CLK_SWCR_SWEN);
      0086DB A4 FD            [ 1]  225 	and	a, #0xfd
      0086DD C7 50 C5         [ 1]  226 	ld	0x50c5, a
                                    227 ;	source/FWLIB/src/stm8s_clk.c: 228: }
      0086E0 81               [ 4]  228 	ret
                                    229 ;	source/FWLIB/src/stm8s_clk.c: 238: void CLK_SlowActiveHaltWakeUpCmd(FunctionalState NewState)
                                    230 ;	-----------------------------------------
                                    231 ;	 function CLK_SlowActiveHaltWakeUpCmd
                                    232 ;	-----------------------------------------
      0086E1                        233 _CLK_SlowActiveHaltWakeUpCmd:
                                    234 ;	source/FWLIB/src/stm8s_clk.c: 246: CLK->ICKR |= CLK_ICKR_SWUAH;
      0086E1 C6 50 C0         [ 1]  235 	ld	a, 0x50c0
                                    236 ;	source/FWLIB/src/stm8s_clk.c: 243: if (NewState != DISABLE)
      0086E4 0D 03            [ 1]  237 	tnz	(0x03, sp)
      0086E6 27 06            [ 1]  238 	jreq	00102$
                                    239 ;	source/FWLIB/src/stm8s_clk.c: 246: CLK->ICKR |= CLK_ICKR_SWUAH;
      0086E8 AA 20            [ 1]  240 	or	a, #0x20
      0086EA C7 50 C0         [ 1]  241 	ld	0x50c0, a
      0086ED 81               [ 4]  242 	ret
      0086EE                        243 00102$:
                                    244 ;	source/FWLIB/src/stm8s_clk.c: 251: CLK->ICKR &= (uint8_t)(~CLK_ICKR_SWUAH);
      0086EE A4 DF            [ 1]  245 	and	a, #0xdf
      0086F0 C7 50 C0         [ 1]  246 	ld	0x50c0, a
                                    247 ;	source/FWLIB/src/stm8s_clk.c: 253: }
      0086F3 81               [ 4]  248 	ret
                                    249 ;	source/FWLIB/src/stm8s_clk.c: 263: void CLK_PeripheralClockConfig(CLK_Peripheral_TypeDef CLK_Peripheral, FunctionalState NewState)
                                    250 ;	-----------------------------------------
                                    251 ;	 function CLK_PeripheralClockConfig
                                    252 ;	-----------------------------------------
      0086F4                        253 _CLK_PeripheralClockConfig:
      0086F4 52 02            [ 2]  254 	sub	sp, #2
                                    255 ;	source/FWLIB/src/stm8s_clk.c: 274: CLK->PCKENR1 |= (uint8_t)((uint8_t)1 << ((uint8_t)CLK_Peripheral & (uint8_t)0x0F));
      0086F6 7B 05            [ 1]  256 	ld	a, (0x05, sp)
      0086F8 A4 0F            [ 1]  257 	and	a, #0x0f
      0086FA 88               [ 1]  258 	push	a
      0086FB A6 01            [ 1]  259 	ld	a, #0x01
      0086FD 6B 02            [ 1]  260 	ld	(0x02, sp), a
      0086FF 84               [ 1]  261 	pop	a
      008700 4D               [ 1]  262 	tnz	a
      008701 27 05            [ 1]  263 	jreq	00128$
      008703                        264 00127$:
      008703 08 01            [ 1]  265 	sll	(0x01, sp)
      008705 4A               [ 1]  266 	dec	a
      008706 26 FB            [ 1]  267 	jrne	00127$
      008708                        268 00128$:
                                    269 ;	source/FWLIB/src/stm8s_clk.c: 279: CLK->PCKENR1 &= (uint8_t)(~(uint8_t)(((uint8_t)1 << ((uint8_t)CLK_Peripheral & (uint8_t)0x0F))));
      008708 7B 01            [ 1]  270 	ld	a, (0x01, sp)
      00870A 43               [ 1]  271 	cpl	a
      00870B 6B 02            [ 1]  272 	ld	(0x02, sp), a
                                    273 ;	source/FWLIB/src/stm8s_clk.c: 269: if (((uint8_t)CLK_Peripheral & (uint8_t)0x10) == 0x00)
      00870D 7B 05            [ 1]  274 	ld	a, (0x05, sp)
      00870F A5 10            [ 1]  275 	bcp	a, #0x10
      008711 26 15            [ 1]  276 	jrne	00108$
                                    277 ;	source/FWLIB/src/stm8s_clk.c: 274: CLK->PCKENR1 |= (uint8_t)((uint8_t)1 << ((uint8_t)CLK_Peripheral & (uint8_t)0x0F));
      008713 C6 50 C7         [ 1]  278 	ld	a, 0x50c7
                                    279 ;	source/FWLIB/src/stm8s_clk.c: 271: if (NewState != DISABLE)
      008716 0D 06            [ 1]  280 	tnz	(0x06, sp)
      008718 27 07            [ 1]  281 	jreq	00102$
                                    282 ;	source/FWLIB/src/stm8s_clk.c: 274: CLK->PCKENR1 |= (uint8_t)((uint8_t)1 << ((uint8_t)CLK_Peripheral & (uint8_t)0x0F));
      00871A 1A 01            [ 1]  283 	or	a, (0x01, sp)
      00871C C7 50 C7         [ 1]  284 	ld	0x50c7, a
      00871F 20 1A            [ 2]  285 	jra	00110$
      008721                        286 00102$:
                                    287 ;	source/FWLIB/src/stm8s_clk.c: 279: CLK->PCKENR1 &= (uint8_t)(~(uint8_t)(((uint8_t)1 << ((uint8_t)CLK_Peripheral & (uint8_t)0x0F))));
      008721 14 02            [ 1]  288 	and	a, (0x02, sp)
      008723 C7 50 C7         [ 1]  289 	ld	0x50c7, a
      008726 20 13            [ 2]  290 	jra	00110$
      008728                        291 00108$:
                                    292 ;	source/FWLIB/src/stm8s_clk.c: 287: CLK->PCKENR2 |= (uint8_t)((uint8_t)1 << ((uint8_t)CLK_Peripheral & (uint8_t)0x0F));
      008728 C6 50 CA         [ 1]  293 	ld	a, 0x50ca
                                    294 ;	source/FWLIB/src/stm8s_clk.c: 284: if (NewState != DISABLE)
      00872B 0D 06            [ 1]  295 	tnz	(0x06, sp)
      00872D 27 07            [ 1]  296 	jreq	00105$
                                    297 ;	source/FWLIB/src/stm8s_clk.c: 287: CLK->PCKENR2 |= (uint8_t)((uint8_t)1 << ((uint8_t)CLK_Peripheral & (uint8_t)0x0F));
      00872F 1A 01            [ 1]  298 	or	a, (0x01, sp)
      008731 C7 50 CA         [ 1]  299 	ld	0x50ca, a
      008734 20 05            [ 2]  300 	jra	00110$
      008736                        301 00105$:
                                    302 ;	source/FWLIB/src/stm8s_clk.c: 292: CLK->PCKENR2 &= (uint8_t)(~(uint8_t)(((uint8_t)1 << ((uint8_t)CLK_Peripheral & (uint8_t)0x0F))));
      008736 14 02            [ 1]  303 	and	a, (0x02, sp)
      008738 C7 50 CA         [ 1]  304 	ld	0x50ca, a
      00873B                        305 00110$:
                                    306 ;	source/FWLIB/src/stm8s_clk.c: 295: }
      00873B 5B 02            [ 2]  307 	addw	sp, #2
      00873D 81               [ 4]  308 	ret
                                    309 ;	source/FWLIB/src/stm8s_clk.c: 309: ErrorStatus CLK_ClockSwitchConfig(CLK_SwitchMode_TypeDef CLK_SwitchMode, CLK_Source_TypeDef CLK_NewClock, FunctionalState ITState, CLK_CurrentClockState_TypeDef CLK_CurrentClockState)
                                    310 ;	-----------------------------------------
                                    311 ;	 function CLK_ClockSwitchConfig
                                    312 ;	-----------------------------------------
      00873E                        313 _CLK_ClockSwitchConfig:
                                    314 ;	source/FWLIB/src/stm8s_clk.c: 322: clock_master = (CLK_Source_TypeDef)CLK->CMSR;
      00873E C6 50 C3         [ 1]  315 	ld	a, 0x50c3
      008741 90 97            [ 1]  316 	ld	yl, a
                                    317 ;	source/FWLIB/src/stm8s_clk.c: 328: CLK->SWCR |= CLK_SWCR_SWEN;
      008743 C6 50 C5         [ 1]  318 	ld	a, 0x50c5
                                    319 ;	source/FWLIB/src/stm8s_clk.c: 325: if (CLK_SwitchMode == CLK_SWITCHMODE_AUTO)
      008746 88               [ 1]  320 	push	a
      008747 7B 04            [ 1]  321 	ld	a, (0x04, sp)
      008749 4A               [ 1]  322 	dec	a
      00874A 84               [ 1]  323 	pop	a
      00874B 26 37            [ 1]  324 	jrne	00122$
                                    325 ;	source/FWLIB/src/stm8s_clk.c: 328: CLK->SWCR |= CLK_SWCR_SWEN;
      00874D AA 02            [ 1]  326 	or	a, #0x02
      00874F C7 50 C5         [ 1]  327 	ld	0x50c5, a
      008752 C6 50 C5         [ 1]  328 	ld	a, 0x50c5
                                    329 ;	source/FWLIB/src/stm8s_clk.c: 331: if (ITState != DISABLE)
      008755 0D 05            [ 1]  330 	tnz	(0x05, sp)
      008757 27 07            [ 1]  331 	jreq	00102$
                                    332 ;	source/FWLIB/src/stm8s_clk.c: 333: CLK->SWCR |= CLK_SWCR_SWIEN;
      008759 AA 04            [ 1]  333 	or	a, #0x04
      00875B C7 50 C5         [ 1]  334 	ld	0x50c5, a
      00875E 20 05            [ 2]  335 	jra	00103$
      008760                        336 00102$:
                                    337 ;	source/FWLIB/src/stm8s_clk.c: 337: CLK->SWCR &= (uint8_t)(~CLK_SWCR_SWIEN);
      008760 A4 FB            [ 1]  338 	and	a, #0xfb
      008762 C7 50 C5         [ 1]  339 	ld	0x50c5, a
      008765                        340 00103$:
                                    341 ;	source/FWLIB/src/stm8s_clk.c: 341: CLK->SWR = (uint8_t)CLK_NewClock;
      008765 AE 50 C4         [ 2]  342 	ldw	x, #0x50c4
      008768 7B 04            [ 1]  343 	ld	a, (0x04, sp)
      00876A F7               [ 1]  344 	ld	(x), a
                                    345 ;	source/FWLIB/src/stm8s_clk.c: 344: while((((CLK->SWCR & CLK_SWCR_SWBSY) != 0 )&& (DownCounter != 0)))
      00876B 5F               [ 1]  346 	clrw	x
      00876C 5A               [ 2]  347 	decw	x
      00876D                        348 00105$:
      00876D C6 50 C5         [ 1]  349 	ld	a, 0x50c5
      008770 44               [ 1]  350 	srl	a
      008771 24 06            [ 1]  351 	jrnc	00107$
      008773 5D               [ 2]  352 	tnzw	x
      008774 27 03            [ 1]  353 	jreq	00107$
                                    354 ;	source/FWLIB/src/stm8s_clk.c: 346: DownCounter--;
      008776 5A               [ 2]  355 	decw	x
      008777 20 F4            [ 2]  356 	jra	00105$
      008779                        357 00107$:
                                    358 ;	source/FWLIB/src/stm8s_clk.c: 349: if(DownCounter != 0)
      008779 5D               [ 2]  359 	tnzw	x
      00877A 27 05            [ 1]  360 	jreq	00109$
                                    361 ;	source/FWLIB/src/stm8s_clk.c: 351: Swif = SUCCESS;
      00877C A6 01            [ 1]  362 	ld	a, #0x01
      00877E 97               [ 1]  363 	ld	xl, a
      00877F 20 34            [ 2]  364 	jra	00123$
      008781                        365 00109$:
                                    366 ;	source/FWLIB/src/stm8s_clk.c: 355: Swif = ERROR;
      008781 5F               [ 1]  367 	clrw	x
      008782 20 31            [ 2]  368 	jra	00123$
      008784                        369 00122$:
                                    370 ;	source/FWLIB/src/stm8s_clk.c: 361: if (ITState != DISABLE)
      008784 0D 05            [ 1]  371 	tnz	(0x05, sp)
      008786 27 07            [ 1]  372 	jreq	00112$
                                    373 ;	source/FWLIB/src/stm8s_clk.c: 363: CLK->SWCR |= CLK_SWCR_SWIEN;
      008788 AA 04            [ 1]  374 	or	a, #0x04
      00878A C7 50 C5         [ 1]  375 	ld	0x50c5, a
      00878D 20 05            [ 2]  376 	jra	00113$
      00878F                        377 00112$:
                                    378 ;	source/FWLIB/src/stm8s_clk.c: 367: CLK->SWCR &= (uint8_t)(~CLK_SWCR_SWIEN);
      00878F A4 FB            [ 1]  379 	and	a, #0xfb
      008791 C7 50 C5         [ 1]  380 	ld	0x50c5, a
      008794                        381 00113$:
                                    382 ;	source/FWLIB/src/stm8s_clk.c: 371: CLK->SWR = (uint8_t)CLK_NewClock;
      008794 AE 50 C4         [ 2]  383 	ldw	x, #0x50c4
      008797 7B 04            [ 1]  384 	ld	a, (0x04, sp)
      008799 F7               [ 1]  385 	ld	(x), a
                                    386 ;	source/FWLIB/src/stm8s_clk.c: 374: while((((CLK->SWCR & CLK_SWCR_SWIF) != 0 ) && (DownCounter != 0)))
      00879A 5F               [ 1]  387 	clrw	x
      00879B 5A               [ 2]  388 	decw	x
      00879C                        389 00115$:
      00879C C6 50 C5         [ 1]  390 	ld	a, 0x50c5
      00879F A5 08            [ 1]  391 	bcp	a, #0x08
      0087A1 27 06            [ 1]  392 	jreq	00117$
      0087A3 5D               [ 2]  393 	tnzw	x
      0087A4 27 03            [ 1]  394 	jreq	00117$
                                    395 ;	source/FWLIB/src/stm8s_clk.c: 376: DownCounter--;
      0087A6 5A               [ 2]  396 	decw	x
      0087A7 20 F3            [ 2]  397 	jra	00115$
      0087A9                        398 00117$:
                                    399 ;	source/FWLIB/src/stm8s_clk.c: 379: if(DownCounter != 0)
      0087A9 5D               [ 2]  400 	tnzw	x
      0087AA 27 08            [ 1]  401 	jreq	00119$
                                    402 ;	source/FWLIB/src/stm8s_clk.c: 382: CLK->SWCR |= CLK_SWCR_SWEN;
      0087AC 72 12 50 C5      [ 1]  403 	bset	20677, #1
                                    404 ;	source/FWLIB/src/stm8s_clk.c: 383: Swif = SUCCESS;
      0087B0 A6 01            [ 1]  405 	ld	a, #0x01
      0087B2 97               [ 1]  406 	ld	xl, a
                                    407 ;	source/FWLIB/src/stm8s_clk.c: 387: Swif = ERROR;
      0087B3 21                     408 	.byte 0x21
      0087B4                        409 00119$:
      0087B4 5F               [ 1]  410 	clrw	x
      0087B5                        411 00123$:
                                    412 ;	source/FWLIB/src/stm8s_clk.c: 390: if(Swif != ERROR)
      0087B5 9F               [ 1]  413 	ld	a, xl
      0087B6 4D               [ 1]  414 	tnz	a
      0087B7 27 2E            [ 1]  415 	jreq	00136$
                                    416 ;	source/FWLIB/src/stm8s_clk.c: 393: if((CLK_CurrentClockState == CLK_CURRENTCLOCKSTATE_DISABLE) && ( clock_master == CLK_SOURCE_HSI))
      0087B9 0D 06            [ 1]  417 	tnz	(0x06, sp)
      0087BB 26 0C            [ 1]  418 	jrne	00132$
      0087BD 90 9F            [ 1]  419 	ld	a, yl
      0087BF A1 E1            [ 1]  420 	cp	a, #0xe1
      0087C1 26 06            [ 1]  421 	jrne	00132$
                                    422 ;	source/FWLIB/src/stm8s_clk.c: 395: CLK->ICKR &= (uint8_t)(~CLK_ICKR_HSIEN);
      0087C3 72 11 50 C0      [ 1]  423 	bres	20672, #0
      0087C7 20 1E            [ 2]  424 	jra	00136$
      0087C9                        425 00132$:
                                    426 ;	source/FWLIB/src/stm8s_clk.c: 397: else if((CLK_CurrentClockState == CLK_CURRENTCLOCKSTATE_DISABLE) && ( clock_master == CLK_SOURCE_LSI))
      0087C9 0D 06            [ 1]  427 	tnz	(0x06, sp)
      0087CB 26 0C            [ 1]  428 	jrne	00128$
      0087CD 90 9F            [ 1]  429 	ld	a, yl
      0087CF A1 D2            [ 1]  430 	cp	a, #0xd2
      0087D1 26 06            [ 1]  431 	jrne	00128$
                                    432 ;	source/FWLIB/src/stm8s_clk.c: 399: CLK->ICKR &= (uint8_t)(~CLK_ICKR_LSIEN);
      0087D3 72 17 50 C0      [ 1]  433 	bres	20672, #3
      0087D7 20 0E            [ 2]  434 	jra	00136$
      0087D9                        435 00128$:
                                    436 ;	source/FWLIB/src/stm8s_clk.c: 401: else if ((CLK_CurrentClockState == CLK_CURRENTCLOCKSTATE_DISABLE) && ( clock_master == CLK_SOURCE_HSE))
      0087D9 0D 06            [ 1]  437 	tnz	(0x06, sp)
      0087DB 26 0A            [ 1]  438 	jrne	00136$
      0087DD 90 9F            [ 1]  439 	ld	a, yl
      0087DF A1 B4            [ 1]  440 	cp	a, #0xb4
      0087E1 26 04            [ 1]  441 	jrne	00136$
                                    442 ;	source/FWLIB/src/stm8s_clk.c: 403: CLK->ECKR &= (uint8_t)(~CLK_ECKR_HSEEN);
      0087E3 72 11 50 C1      [ 1]  443 	bres	20673, #0
      0087E7                        444 00136$:
                                    445 ;	source/FWLIB/src/stm8s_clk.c: 406: return(Swif);
      0087E7 9F               [ 1]  446 	ld	a, xl
                                    447 ;	source/FWLIB/src/stm8s_clk.c: 407: }
      0087E8 81               [ 4]  448 	ret
                                    449 ;	source/FWLIB/src/stm8s_clk.c: 415: void CLK_HSIPrescalerConfig(CLK_Prescaler_TypeDef HSIPrescaler)
                                    450 ;	-----------------------------------------
                                    451 ;	 function CLK_HSIPrescalerConfig
                                    452 ;	-----------------------------------------
      0087E9                        453 _CLK_HSIPrescalerConfig:
                                    454 ;	source/FWLIB/src/stm8s_clk.c: 421: CLK->CKDIVR &= (uint8_t)(~CLK_CKDIVR_HSIDIV);
      0087E9 C6 50 C6         [ 1]  455 	ld	a, 0x50c6
      0087EC A4 E7            [ 1]  456 	and	a, #0xe7
      0087EE C7 50 C6         [ 1]  457 	ld	0x50c6, a
                                    458 ;	source/FWLIB/src/stm8s_clk.c: 424: CLK->CKDIVR |= (uint8_t)HSIPrescaler;
      0087F1 C6 50 C6         [ 1]  459 	ld	a, 0x50c6
      0087F4 1A 03            [ 1]  460 	or	a, (0x03, sp)
      0087F6 C7 50 C6         [ 1]  461 	ld	0x50c6, a
                                    462 ;	source/FWLIB/src/stm8s_clk.c: 425: }
      0087F9 81               [ 4]  463 	ret
                                    464 ;	source/FWLIB/src/stm8s_clk.c: 436: void CLK_CCOConfig(CLK_Output_TypeDef CLK_CCO)
                                    465 ;	-----------------------------------------
                                    466 ;	 function CLK_CCOConfig
                                    467 ;	-----------------------------------------
      0087FA                        468 _CLK_CCOConfig:
                                    469 ;	source/FWLIB/src/stm8s_clk.c: 442: CLK->CCOR &= (uint8_t)(~CLK_CCOR_CCOSEL);
      0087FA C6 50 C9         [ 1]  470 	ld	a, 0x50c9
      0087FD A4 E1            [ 1]  471 	and	a, #0xe1
      0087FF C7 50 C9         [ 1]  472 	ld	0x50c9, a
                                    473 ;	source/FWLIB/src/stm8s_clk.c: 445: CLK->CCOR |= (uint8_t)CLK_CCO;
      008802 C6 50 C9         [ 1]  474 	ld	a, 0x50c9
      008805 1A 03            [ 1]  475 	or	a, (0x03, sp)
      008807 C7 50 C9         [ 1]  476 	ld	0x50c9, a
                                    477 ;	source/FWLIB/src/stm8s_clk.c: 448: CLK->CCOR |= CLK_CCOR_CCOEN;
      00880A 72 10 50 C9      [ 1]  478 	bset	20681, #0
                                    479 ;	source/FWLIB/src/stm8s_clk.c: 449: }
      00880E 81               [ 4]  480 	ret
                                    481 ;	source/FWLIB/src/stm8s_clk.c: 459: void CLK_ITConfig(CLK_IT_TypeDef CLK_IT, FunctionalState NewState)
                                    482 ;	-----------------------------------------
                                    483 ;	 function CLK_ITConfig
                                    484 ;	-----------------------------------------
      00880F                        485 _CLK_ITConfig:
      00880F 88               [ 1]  486 	push	a
                                    487 ;	source/FWLIB/src/stm8s_clk.c: 467: switch (CLK_IT)
      008810 7B 04            [ 1]  488 	ld	a, (0x04, sp)
      008812 A0 0C            [ 1]  489 	sub	a, #0x0c
      008814 26 04            [ 1]  490 	jrne	00140$
      008816 4C               [ 1]  491 	inc	a
      008817 6B 01            [ 1]  492 	ld	(0x01, sp), a
      008819 C5                     493 	.byte 0xc5
      00881A                        494 00140$:
      00881A 0F 01            [ 1]  495 	clr	(0x01, sp)
      00881C                        496 00141$:
      00881C 7B 04            [ 1]  497 	ld	a, (0x04, sp)
      00881E A0 1C            [ 1]  498 	sub	a, #0x1c
      008820 26 02            [ 1]  499 	jrne	00143$
      008822 4C               [ 1]  500 	inc	a
      008823 21                     501 	.byte 0x21
      008824                        502 00143$:
      008824 4F               [ 1]  503 	clr	a
      008825                        504 00144$:
                                    505 ;	source/FWLIB/src/stm8s_clk.c: 465: if (NewState != DISABLE)
      008825 0D 05            [ 1]  506 	tnz	(0x05, sp)
      008827 27 13            [ 1]  507 	jreq	00110$
                                    508 ;	source/FWLIB/src/stm8s_clk.c: 467: switch (CLK_IT)
      008829 0D 01            [ 1]  509 	tnz	(0x01, sp)
      00882B 26 09            [ 1]  510 	jrne	00102$
      00882D 4D               [ 1]  511 	tnz	a
      00882E 27 1D            [ 1]  512 	jreq	00112$
                                    513 ;	source/FWLIB/src/stm8s_clk.c: 470: CLK->SWCR |= CLK_SWCR_SWIEN;
      008830 72 14 50 C5      [ 1]  514 	bset	20677, #2
                                    515 ;	source/FWLIB/src/stm8s_clk.c: 471: break;
      008834 20 17            [ 2]  516 	jra	00112$
                                    517 ;	source/FWLIB/src/stm8s_clk.c: 472: case CLK_IT_CSSD: /* Enable the clock security system detection interrupt */
      008836                        518 00102$:
                                    519 ;	source/FWLIB/src/stm8s_clk.c: 473: CLK->CSSR |= CLK_CSSR_CSSDIE;
      008836 72 14 50 C8      [ 1]  520 	bset	20680, #2
                                    521 ;	source/FWLIB/src/stm8s_clk.c: 474: break;
      00883A 20 11            [ 2]  522 	jra	00112$
                                    523 ;	source/FWLIB/src/stm8s_clk.c: 477: }
      00883C                        524 00110$:
                                    525 ;	source/FWLIB/src/stm8s_clk.c: 481: switch (CLK_IT)
      00883C 0D 01            [ 1]  526 	tnz	(0x01, sp)
      00883E 26 09            [ 1]  527 	jrne	00106$
      008840 4D               [ 1]  528 	tnz	a
      008841 27 0A            [ 1]  529 	jreq	00112$
                                    530 ;	source/FWLIB/src/stm8s_clk.c: 484: CLK->SWCR  &= (uint8_t)(~CLK_SWCR_SWIEN);
      008843 72 15 50 C5      [ 1]  531 	bres	20677, #2
                                    532 ;	source/FWLIB/src/stm8s_clk.c: 485: break;
      008847 20 04            [ 2]  533 	jra	00112$
                                    534 ;	source/FWLIB/src/stm8s_clk.c: 486: case CLK_IT_CSSD: /* Disable the clock security system detection interrupt */
      008849                        535 00106$:
                                    536 ;	source/FWLIB/src/stm8s_clk.c: 487: CLK->CSSR &= (uint8_t)(~CLK_CSSR_CSSDIE);
      008849 72 15 50 C8      [ 1]  537 	bres	20680, #2
                                    538 ;	source/FWLIB/src/stm8s_clk.c: 491: }
      00884D                        539 00112$:
                                    540 ;	source/FWLIB/src/stm8s_clk.c: 493: }
      00884D 84               [ 1]  541 	pop	a
      00884E 81               [ 4]  542 	ret
                                    543 ;	source/FWLIB/src/stm8s_clk.c: 500: void CLK_SYSCLKConfig(CLK_Prescaler_TypeDef CLK_Prescaler)
                                    544 ;	-----------------------------------------
                                    545 ;	 function CLK_SYSCLKConfig
                                    546 ;	-----------------------------------------
      00884F                        547 _CLK_SYSCLKConfig:
      00884F 88               [ 1]  548 	push	a
                                    549 ;	source/FWLIB/src/stm8s_clk.c: 507: CLK->CKDIVR &= (uint8_t)(~CLK_CKDIVR_HSIDIV);
      008850 C6 50 C6         [ 1]  550 	ld	a, 0x50c6
                                    551 ;	source/FWLIB/src/stm8s_clk.c: 505: if (((uint8_t)CLK_Prescaler & (uint8_t)0x80) == 0x00) /* Bit7 = 0 means HSI divider */
      008853 0D 04            [ 1]  552 	tnz	(0x04, sp)
      008855 2B 15            [ 1]  553 	jrmi	00102$
                                    554 ;	source/FWLIB/src/stm8s_clk.c: 507: CLK->CKDIVR &= (uint8_t)(~CLK_CKDIVR_HSIDIV);
      008857 A4 E7            [ 1]  555 	and	a, #0xe7
      008859 C7 50 C6         [ 1]  556 	ld	0x50c6, a
                                    557 ;	source/FWLIB/src/stm8s_clk.c: 508: CLK->CKDIVR |= (uint8_t)((uint8_t)CLK_Prescaler & (uint8_t)CLK_CKDIVR_HSIDIV);
      00885C C6 50 C6         [ 1]  558 	ld	a, 0x50c6
      00885F 6B 01            [ 1]  559 	ld	(0x01, sp), a
      008861 7B 04            [ 1]  560 	ld	a, (0x04, sp)
      008863 A4 18            [ 1]  561 	and	a, #0x18
      008865 1A 01            [ 1]  562 	or	a, (0x01, sp)
      008867 C7 50 C6         [ 1]  563 	ld	0x50c6, a
      00886A 20 13            [ 2]  564 	jra	00104$
      00886C                        565 00102$:
                                    566 ;	source/FWLIB/src/stm8s_clk.c: 512: CLK->CKDIVR &= (uint8_t)(~CLK_CKDIVR_CPUDIV);
      00886C A4 F8            [ 1]  567 	and	a, #0xf8
      00886E C7 50 C6         [ 1]  568 	ld	0x50c6, a
                                    569 ;	source/FWLIB/src/stm8s_clk.c: 513: CLK->CKDIVR |= (uint8_t)((uint8_t)CLK_Prescaler & (uint8_t)CLK_CKDIVR_CPUDIV);
      008871 C6 50 C6         [ 1]  570 	ld	a, 0x50c6
      008874 6B 01            [ 1]  571 	ld	(0x01, sp), a
      008876 7B 04            [ 1]  572 	ld	a, (0x04, sp)
      008878 A4 07            [ 1]  573 	and	a, #0x07
      00887A 1A 01            [ 1]  574 	or	a, (0x01, sp)
      00887C C7 50 C6         [ 1]  575 	ld	0x50c6, a
      00887F                        576 00104$:
                                    577 ;	source/FWLIB/src/stm8s_clk.c: 515: }
      00887F 84               [ 1]  578 	pop	a
      008880 81               [ 4]  579 	ret
                                    580 ;	source/FWLIB/src/stm8s_clk.c: 523: void CLK_SWIMConfig(CLK_SWIMDivider_TypeDef CLK_SWIMDivider)
                                    581 ;	-----------------------------------------
                                    582 ;	 function CLK_SWIMConfig
                                    583 ;	-----------------------------------------
      008881                        584 _CLK_SWIMConfig:
                                    585 ;	source/FWLIB/src/stm8s_clk.c: 531: CLK->SWIMCCR |= CLK_SWIMCCR_SWIMDIV;
      008881 C6 50 CD         [ 1]  586 	ld	a, 0x50cd
                                    587 ;	source/FWLIB/src/stm8s_clk.c: 528: if (CLK_SWIMDivider != CLK_SWIMDIVIDER_2)
      008884 0D 03            [ 1]  588 	tnz	(0x03, sp)
      008886 27 06            [ 1]  589 	jreq	00102$
                                    590 ;	source/FWLIB/src/stm8s_clk.c: 531: CLK->SWIMCCR |= CLK_SWIMCCR_SWIMDIV;
      008888 AA 01            [ 1]  591 	or	a, #0x01
      00888A C7 50 CD         [ 1]  592 	ld	0x50cd, a
      00888D 81               [ 4]  593 	ret
      00888E                        594 00102$:
                                    595 ;	source/FWLIB/src/stm8s_clk.c: 536: CLK->SWIMCCR &= (uint8_t)(~CLK_SWIMCCR_SWIMDIV);
      00888E A4 FE            [ 1]  596 	and	a, #0xfe
      008890 C7 50 CD         [ 1]  597 	ld	0x50cd, a
                                    598 ;	source/FWLIB/src/stm8s_clk.c: 538: }
      008893 81               [ 4]  599 	ret
                                    600 ;	source/FWLIB/src/stm8s_clk.c: 547: void CLK_ClockSecuritySystemEnable(void)
                                    601 ;	-----------------------------------------
                                    602 ;	 function CLK_ClockSecuritySystemEnable
                                    603 ;	-----------------------------------------
      008894                        604 _CLK_ClockSecuritySystemEnable:
                                    605 ;	source/FWLIB/src/stm8s_clk.c: 550: CLK->CSSR |= CLK_CSSR_CSSEN;
      008894 72 10 50 C8      [ 1]  606 	bset	20680, #0
                                    607 ;	source/FWLIB/src/stm8s_clk.c: 551: }
      008898 81               [ 4]  608 	ret
                                    609 ;	source/FWLIB/src/stm8s_clk.c: 559: CLK_Source_TypeDef CLK_GetSYSCLKSource(void)
                                    610 ;	-----------------------------------------
                                    611 ;	 function CLK_GetSYSCLKSource
                                    612 ;	-----------------------------------------
      008899                        613 _CLK_GetSYSCLKSource:
                                    614 ;	source/FWLIB/src/stm8s_clk.c: 561: return((CLK_Source_TypeDef)CLK->CMSR);
      008899 C6 50 C3         [ 1]  615 	ld	a, 0x50c3
                                    616 ;	source/FWLIB/src/stm8s_clk.c: 562: }
      00889C 81               [ 4]  617 	ret
                                    618 ;	source/FWLIB/src/stm8s_clk.c: 569: uint32_t CLK_GetClockFreq(void)
                                    619 ;	-----------------------------------------
                                    620 ;	 function CLK_GetClockFreq
                                    621 ;	-----------------------------------------
      00889D                        622 _CLK_GetClockFreq:
      00889D 52 04            [ 2]  623 	sub	sp, #4
                                    624 ;	source/FWLIB/src/stm8s_clk.c: 576: clocksource = (CLK_Source_TypeDef)CLK->CMSR;
      00889F C6 50 C3         [ 1]  625 	ld	a, 0x50c3
                                    626 ;	source/FWLIB/src/stm8s_clk.c: 578: if (clocksource == CLK_SOURCE_HSI)
      0088A2 6B 04            [ 1]  627 	ld	(0x04, sp), a
      0088A4 A1 E1            [ 1]  628 	cp	a, #0xe1
      0088A6 26 26            [ 1]  629 	jrne	00105$
                                    630 ;	source/FWLIB/src/stm8s_clk.c: 580: tmp = (uint8_t)(CLK->CKDIVR & CLK_CKDIVR_HSIDIV);
      0088A8 C6 50 C6         [ 1]  631 	ld	a, 0x50c6
      0088AB A4 18            [ 1]  632 	and	a, #0x18
                                    633 ;	source/FWLIB/src/stm8s_clk.c: 581: tmp = (uint8_t)(tmp >> 3);
      0088AD 44               [ 1]  634 	srl	a
      0088AE 44               [ 1]  635 	srl	a
      0088AF 44               [ 1]  636 	srl	a
                                    637 ;	source/FWLIB/src/stm8s_clk.c: 582: presc = HSIDivFactor[tmp];
      0088B0 5F               [ 1]  638 	clrw	x
      0088B1 97               [ 1]  639 	ld	xl, a
      0088B2 1C 80 46         [ 2]  640 	addw	x, #(_HSIDivFactor + 0)
      0088B5 F6               [ 1]  641 	ld	a, (x)
                                    642 ;	source/FWLIB/src/stm8s_clk.c: 583: clockfrequency = HSI_VALUE / presc;
      0088B6 5F               [ 1]  643 	clrw	x
      0088B7 97               [ 1]  644 	ld	xl, a
      0088B8 90 5F            [ 1]  645 	clrw	y
      0088BA 89               [ 2]  646 	pushw	x
      0088BB 90 89            [ 2]  647 	pushw	y
      0088BD 4B 00            [ 1]  648 	push	#0x00
      0088BF 4B 24            [ 1]  649 	push	#0x24
      0088C1 4B F4            [ 1]  650 	push	#0xf4
      0088C3 4B 00            [ 1]  651 	push	#0x00
      0088C5 CD A7 F4         [ 4]  652 	call	__divulong
      0088C8 5B 08            [ 2]  653 	addw	sp, #8
      0088CA 1F 03            [ 2]  654 	ldw	(0x03, sp), x
      0088CC 20 1A            [ 2]  655 	jra	00106$
      0088CE                        656 00105$:
                                    657 ;	source/FWLIB/src/stm8s_clk.c: 585: else if ( clocksource == CLK_SOURCE_LSI)
      0088CE 7B 04            [ 1]  658 	ld	a, (0x04, sp)
      0088D0 A1 D2            [ 1]  659 	cp	a, #0xd2
      0088D2 26 0B            [ 1]  660 	jrne	00102$
                                    661 ;	source/FWLIB/src/stm8s_clk.c: 587: clockfrequency = LSI_VALUE;
      0088D4 AE F4 00         [ 2]  662 	ldw	x, #0xf400
      0088D7 1F 03            [ 2]  663 	ldw	(0x03, sp), x
      0088D9 90 AE 00 01      [ 2]  664 	ldw	y, #0x0001
      0088DD 20 09            [ 2]  665 	jra	00106$
      0088DF                        666 00102$:
                                    667 ;	source/FWLIB/src/stm8s_clk.c: 591: clockfrequency = HSE_VALUE;
      0088DF AE 24 00         [ 2]  668 	ldw	x, #0x2400
      0088E2 1F 03            [ 2]  669 	ldw	(0x03, sp), x
      0088E4 90 AE 00 F4      [ 2]  670 	ldw	y, #0x00f4
      0088E8                        671 00106$:
                                    672 ;	source/FWLIB/src/stm8s_clk.c: 594: return((uint32_t)clockfrequency);
      0088E8 1E 03            [ 2]  673 	ldw	x, (0x03, sp)
                                    674 ;	source/FWLIB/src/stm8s_clk.c: 595: }
      0088EA 5B 04            [ 2]  675 	addw	sp, #4
      0088EC 81               [ 4]  676 	ret
                                    677 ;	source/FWLIB/src/stm8s_clk.c: 604: void CLK_AdjustHSICalibrationValue(CLK_HSITrimValue_TypeDef CLK_HSICalibrationValue)
                                    678 ;	-----------------------------------------
                                    679 ;	 function CLK_AdjustHSICalibrationValue
                                    680 ;	-----------------------------------------
      0088ED                        681 _CLK_AdjustHSICalibrationValue:
                                    682 ;	source/FWLIB/src/stm8s_clk.c: 610: CLK->HSITRIMR = (uint8_t)( (uint8_t)(CLK->HSITRIMR & (uint8_t)(~CLK_HSITRIMR_HSITRIM))|((uint8_t)CLK_HSICalibrationValue));
      0088ED C6 50 CC         [ 1]  683 	ld	a, 0x50cc
      0088F0 A4 F8            [ 1]  684 	and	a, #0xf8
      0088F2 1A 03            [ 1]  685 	or	a, (0x03, sp)
      0088F4 C7 50 CC         [ 1]  686 	ld	0x50cc, a
                                    687 ;	source/FWLIB/src/stm8s_clk.c: 611: }
      0088F7 81               [ 4]  688 	ret
                                    689 ;	source/FWLIB/src/stm8s_clk.c: 622: void CLK_SYSCLKEmergencyClear(void)
                                    690 ;	-----------------------------------------
                                    691 ;	 function CLK_SYSCLKEmergencyClear
                                    692 ;	-----------------------------------------
      0088F8                        693 _CLK_SYSCLKEmergencyClear:
                                    694 ;	source/FWLIB/src/stm8s_clk.c: 624: CLK->SWCR &= (uint8_t)(~CLK_SWCR_SWBSY);
      0088F8 72 11 50 C5      [ 1]  695 	bres	20677, #0
                                    696 ;	source/FWLIB/src/stm8s_clk.c: 625: }
      0088FC 81               [ 4]  697 	ret
                                    698 ;	source/FWLIB/src/stm8s_clk.c: 634: FlagStatus CLK_GetFlagStatus(CLK_Flag_TypeDef CLK_FLAG)
                                    699 ;	-----------------------------------------
                                    700 ;	 function CLK_GetFlagStatus
                                    701 ;	-----------------------------------------
      0088FD                        702 _CLK_GetFlagStatus:
      0088FD 52 02            [ 2]  703 	sub	sp, #2
                                    704 ;	source/FWLIB/src/stm8s_clk.c: 644: statusreg = (uint16_t)((uint16_t)CLK_FLAG & (uint16_t)0xFF00);
      0088FF 1E 05            [ 2]  705 	ldw	x, (0x05, sp)
      008901 4F               [ 1]  706 	clr	a
      008902 97               [ 1]  707 	ld	xl, a
                                    708 ;	source/FWLIB/src/stm8s_clk.c: 647: if (statusreg == 0x0100) /* The flag to check is in ICKRregister */
      008903 1F 01            [ 2]  709 	ldw	(0x01, sp), x
      008905 A3 01 00         [ 2]  710 	cpw	x, #0x0100
      008908 26 05            [ 1]  711 	jrne	00111$
                                    712 ;	source/FWLIB/src/stm8s_clk.c: 649: tmpreg = CLK->ICKR;
      00890A C6 50 C0         [ 1]  713 	ld	a, 0x50c0
      00890D 20 27            [ 2]  714 	jra	00112$
      00890F                        715 00111$:
                                    716 ;	source/FWLIB/src/stm8s_clk.c: 651: else if (statusreg == 0x0200) /* The flag to check is in ECKRregister */
      00890F 1E 01            [ 2]  717 	ldw	x, (0x01, sp)
      008911 A3 02 00         [ 2]  718 	cpw	x, #0x0200
      008914 26 05            [ 1]  719 	jrne	00108$
                                    720 ;	source/FWLIB/src/stm8s_clk.c: 653: tmpreg = CLK->ECKR;
      008916 C6 50 C1         [ 1]  721 	ld	a, 0x50c1
      008919 20 1B            [ 2]  722 	jra	00112$
      00891B                        723 00108$:
                                    724 ;	source/FWLIB/src/stm8s_clk.c: 655: else if (statusreg == 0x0300) /* The flag to check is in SWIC register */
      00891B 1E 01            [ 2]  725 	ldw	x, (0x01, sp)
      00891D A3 03 00         [ 2]  726 	cpw	x, #0x0300
      008920 26 05            [ 1]  727 	jrne	00105$
                                    728 ;	source/FWLIB/src/stm8s_clk.c: 657: tmpreg = CLK->SWCR;
      008922 C6 50 C5         [ 1]  729 	ld	a, 0x50c5
      008925 20 0F            [ 2]  730 	jra	00112$
      008927                        731 00105$:
                                    732 ;	source/FWLIB/src/stm8s_clk.c: 659: else if (statusreg == 0x0400) /* The flag to check is in CSS register */
      008927 1E 01            [ 2]  733 	ldw	x, (0x01, sp)
      008929 A3 04 00         [ 2]  734 	cpw	x, #0x0400
      00892C 26 05            [ 1]  735 	jrne	00102$
                                    736 ;	source/FWLIB/src/stm8s_clk.c: 661: tmpreg = CLK->CSSR;
      00892E C6 50 C8         [ 1]  737 	ld	a, 0x50c8
      008931 20 03            [ 2]  738 	jra	00112$
      008933                        739 00102$:
                                    740 ;	source/FWLIB/src/stm8s_clk.c: 665: tmpreg = CLK->CCOR;
      008933 C6 50 C9         [ 1]  741 	ld	a, 0x50c9
      008936                        742 00112$:
                                    743 ;	source/FWLIB/src/stm8s_clk.c: 668: if ((tmpreg & (uint8_t)CLK_FLAG) != (uint8_t)RESET)
      008936 88               [ 1]  744 	push	a
      008937 7B 07            [ 1]  745 	ld	a, (0x07, sp)
      008939 6B 03            [ 1]  746 	ld	(0x03, sp), a
      00893B 84               [ 1]  747 	pop	a
      00893C 14 02            [ 1]  748 	and	a, (0x02, sp)
      00893E 27 03            [ 1]  749 	jreq	00114$
                                    750 ;	source/FWLIB/src/stm8s_clk.c: 670: bitstatus = SET;
      008940 A6 01            [ 1]  751 	ld	a, #0x01
                                    752 ;	source/FWLIB/src/stm8s_clk.c: 674: bitstatus = RESET;
      008942 21                     753 	.byte 0x21
      008943                        754 00114$:
      008943 4F               [ 1]  755 	clr	a
      008944                        756 00115$:
                                    757 ;	source/FWLIB/src/stm8s_clk.c: 678: return((FlagStatus)bitstatus);
                                    758 ;	source/FWLIB/src/stm8s_clk.c: 679: }
      008944 5B 02            [ 2]  759 	addw	sp, #2
      008946 81               [ 4]  760 	ret
                                    761 ;	source/FWLIB/src/stm8s_clk.c: 687: ITStatus CLK_GetITStatus(CLK_IT_TypeDef CLK_IT)
                                    762 ;	-----------------------------------------
                                    763 ;	 function CLK_GetITStatus
                                    764 ;	-----------------------------------------
      008947                        765 _CLK_GetITStatus:
                                    766 ;	source/FWLIB/src/stm8s_clk.c: 694: if (CLK_IT == CLK_IT_SWIF)
      008947 7B 03            [ 1]  767 	ld	a, (0x03, sp)
      008949 A1 1C            [ 1]  768 	cp	a, #0x1c
      00894B 26 0D            [ 1]  769 	jrne	00108$
                                    770 ;	source/FWLIB/src/stm8s_clk.c: 697: if ((CLK->SWCR & (uint8_t)CLK_IT) == (uint8_t)0x0C)
      00894D C6 50 C5         [ 1]  771 	ld	a, 0x50c5
      008950 14 03            [ 1]  772 	and	a, (0x03, sp)
                                    773 ;	source/FWLIB/src/stm8s_clk.c: 699: bitstatus = SET;
      008952 A0 0C            [ 1]  774 	sub	a, #0x0c
      008954 26 02            [ 1]  775 	jrne	00102$
      008956 4C               [ 1]  776 	inc	a
      008957 81               [ 4]  777 	ret
      008958                        778 00102$:
                                    779 ;	source/FWLIB/src/stm8s_clk.c: 703: bitstatus = RESET;
      008958 4F               [ 1]  780 	clr	a
      008959 81               [ 4]  781 	ret
      00895A                        782 00108$:
                                    783 ;	source/FWLIB/src/stm8s_clk.c: 709: if ((CLK->CSSR & (uint8_t)CLK_IT) == (uint8_t)0x0C)
      00895A C6 50 C8         [ 1]  784 	ld	a, 0x50c8
      00895D 14 03            [ 1]  785 	and	a, (0x03, sp)
                                    786 ;	source/FWLIB/src/stm8s_clk.c: 711: bitstatus = SET;
      00895F A0 0C            [ 1]  787 	sub	a, #0x0c
      008961 26 02            [ 1]  788 	jrne	00105$
      008963 4C               [ 1]  789 	inc	a
      008964 81               [ 4]  790 	ret
      008965                        791 00105$:
                                    792 ;	source/FWLIB/src/stm8s_clk.c: 715: bitstatus = RESET;
      008965 4F               [ 1]  793 	clr	a
                                    794 ;	source/FWLIB/src/stm8s_clk.c: 720: return bitstatus;
                                    795 ;	source/FWLIB/src/stm8s_clk.c: 721: }
      008966 81               [ 4]  796 	ret
                                    797 ;	source/FWLIB/src/stm8s_clk.c: 729: void CLK_ClearITPendingBit(CLK_IT_TypeDef CLK_IT)
                                    798 ;	-----------------------------------------
                                    799 ;	 function CLK_ClearITPendingBit
                                    800 ;	-----------------------------------------
      008967                        801 _CLK_ClearITPendingBit:
                                    802 ;	source/FWLIB/src/stm8s_clk.c: 734: if (CLK_IT == (uint8_t)CLK_IT_CSSD)
      008967 7B 03            [ 1]  803 	ld	a, (0x03, sp)
      008969 A1 0C            [ 1]  804 	cp	a, #0x0c
      00896B 26 05            [ 1]  805 	jrne	00102$
                                    806 ;	source/FWLIB/src/stm8s_clk.c: 737: CLK->CSSR &= (uint8_t)(~CLK_CSSR_CSSD);
      00896D 72 17 50 C8      [ 1]  807 	bres	20680, #3
      008971 81               [ 4]  808 	ret
      008972                        809 00102$:
                                    810 ;	source/FWLIB/src/stm8s_clk.c: 742: CLK->SWCR &= (uint8_t)(~CLK_SWCR_SWIF);
      008972 72 17 50 C5      [ 1]  811 	bres	20677, #3
                                    812 ;	source/FWLIB/src/stm8s_clk.c: 745: }
      008976 81               [ 4]  813 	ret
                                    814 	.area CODE
                                    815 	.area CONST
      008046                        816 _HSIDivFactor:
      008046 01                     817 	.db #0x01	; 1
      008047 02                     818 	.db #0x02	; 2
      008048 04                     819 	.db #0x04	; 4
      008049 08                     820 	.db #0x08	; 8
      00804A                        821 _CLKPrescTable:
      00804A 01                     822 	.db #0x01	; 1
      00804B 02                     823 	.db #0x02	; 2
      00804C 04                     824 	.db #0x04	; 4
      00804D 08                     825 	.db #0x08	; 8
      00804E 0A                     826 	.db #0x0a	; 10
      00804F 10                     827 	.db #0x10	; 16
      008050 14                     828 	.db #0x14	; 20
      008051 28                     829 	.db #0x28	; 40
                                    830 	.area INITIALIZER
                                    831 	.area CABS (ABS)
