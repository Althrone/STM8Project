                                      1 ;--------------------------------------------------------
                                      2 ; File Created by SDCC : free open source ANSI-C Compiler
                                      3 ; Version 4.0.0 #11528 (MINGW64)
                                      4 ;--------------------------------------------------------
                                      5 	.module stm8s_gpio
                                      6 	.optsdcc -mstm8
                                      7 	
                                      8 ;--------------------------------------------------------
                                      9 ; Public variables in this module
                                     10 ;--------------------------------------------------------
                                     11 	.globl _assert_failed
                                     12 	.globl _GPIO_DeInit
                                     13 	.globl _GPIO_Init
                                     14 	.globl _GPIO_Write
                                     15 	.globl _GPIO_WriteHigh
                                     16 	.globl _GPIO_WriteLow
                                     17 	.globl _GPIO_WriteReverse
                                     18 	.globl _GPIO_ReadOutputData
                                     19 	.globl _GPIO_ReadInputData
                                     20 	.globl _GPIO_ReadInputPin
                                     21 	.globl _GPIO_ExternalPullUpConfig
                                     22 ;--------------------------------------------------------
                                     23 ; ram data
                                     24 ;--------------------------------------------------------
                                     25 	.area DATA
                                     26 ;--------------------------------------------------------
                                     27 ; ram data
                                     28 ;--------------------------------------------------------
                                     29 	.area INITIALIZED
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
                                     44 ; global & static initialisations
                                     45 ;--------------------------------------------------------
                                     46 	.area HOME
                                     47 	.area GSINIT
                                     48 	.area GSFINAL
                                     49 	.area GSINIT
                                     50 ;--------------------------------------------------------
                                     51 ; Home
                                     52 ;--------------------------------------------------------
                                     53 	.area HOME
                                     54 	.area HOME
                                     55 ;--------------------------------------------------------
                                     56 ; code
                                     57 ;--------------------------------------------------------
                                     58 	.area CODE
                                     59 ;	source/FWLIB/src/stm8s_gpio.c: 53: void GPIO_DeInit(GPIO_TypeDef* GPIOx)
                                     60 ;	-----------------------------------------
                                     61 ;	 function GPIO_DeInit
                                     62 ;	-----------------------------------------
      008077                         63 _GPIO_DeInit:
                                     64 ;	source/FWLIB/src/stm8s_gpio.c: 55: GPIOx->ODR = GPIO_ODR_RESET_VALUE; /* Reset Output Data Register */
      008077 16 03            [ 2]   65 	ldw	y, (0x03, sp)
      008079 90 7F            [ 1]   66 	clr	(y)
                                     67 ;	source/FWLIB/src/stm8s_gpio.c: 56: GPIOx->DDR = GPIO_DDR_RESET_VALUE; /* Reset Data Direction Register */
      00807B 93               [ 1]   68 	ldw	x, y
      00807C 5C               [ 1]   69 	incw	x
      00807D 5C               [ 1]   70 	incw	x
      00807E 7F               [ 1]   71 	clr	(x)
                                     72 ;	source/FWLIB/src/stm8s_gpio.c: 57: GPIOx->CR1 = GPIO_CR1_RESET_VALUE; /* Reset Control Register 1 */
      00807F 93               [ 1]   73 	ldw	x, y
      008080 6F 03            [ 1]   74 	clr	(0x0003, x)
                                     75 ;	source/FWLIB/src/stm8s_gpio.c: 58: GPIOx->CR2 = GPIO_CR2_RESET_VALUE; /* Reset Control Register 2 */
      008082 93               [ 1]   76 	ldw	x, y
      008083 6F 04            [ 1]   77 	clr	(0x0004, x)
                                     78 ;	source/FWLIB/src/stm8s_gpio.c: 59: }
      008085 81               [ 4]   79 	ret
                                     80 ;	source/FWLIB/src/stm8s_gpio.c: 71: void GPIO_Init(GPIO_TypeDef* GPIOx, GPIO_Pin_TypeDef GPIO_Pin, GPIO_Mode_TypeDef GPIO_Mode)
                                     81 ;	-----------------------------------------
                                     82 ;	 function GPIO_Init
                                     83 ;	-----------------------------------------
      008086                         84 _GPIO_Init:
      008086 52 05            [ 2]   85 	sub	sp, #5
                                     86 ;	source/FWLIB/src/stm8s_gpio.c: 77: assert_param(IS_GPIO_MODE_OK(GPIO_Mode));
      008088 0D 0B            [ 1]   87 	tnz	(0x0b, sp)
      00808A 27 51            [ 1]   88 	jreq	00116$
      00808C 7B 0B            [ 1]   89 	ld	a, (0x0b, sp)
      00808E A1 40            [ 1]   90 	cp	a, #0x40
      008090 27 4B            [ 1]   91 	jreq	00116$
      008092 7B 0B            [ 1]   92 	ld	a, (0x0b, sp)
      008094 A1 20            [ 1]   93 	cp	a, #0x20
      008096 27 45            [ 1]   94 	jreq	00116$
      008098 7B 0B            [ 1]   95 	ld	a, (0x0b, sp)
      00809A A1 60            [ 1]   96 	cp	a, #0x60
      00809C 27 3F            [ 1]   97 	jreq	00116$
      00809E 7B 0B            [ 1]   98 	ld	a, (0x0b, sp)
      0080A0 A1 A0            [ 1]   99 	cp	a, #0xa0
      0080A2 27 39            [ 1]  100 	jreq	00116$
      0080A4 7B 0B            [ 1]  101 	ld	a, (0x0b, sp)
      0080A6 A1 E0            [ 1]  102 	cp	a, #0xe0
      0080A8 27 33            [ 1]  103 	jreq	00116$
      0080AA 7B 0B            [ 1]  104 	ld	a, (0x0b, sp)
      0080AC A1 80            [ 1]  105 	cp	a, #0x80
      0080AE 27 2D            [ 1]  106 	jreq	00116$
      0080B0 7B 0B            [ 1]  107 	ld	a, (0x0b, sp)
      0080B2 A1 C0            [ 1]  108 	cp	a, #0xc0
      0080B4 27 27            [ 1]  109 	jreq	00116$
      0080B6 7B 0B            [ 1]  110 	ld	a, (0x0b, sp)
      0080B8 A1 B0            [ 1]  111 	cp	a, #0xb0
      0080BA 27 21            [ 1]  112 	jreq	00116$
      0080BC 7B 0B            [ 1]  113 	ld	a, (0x0b, sp)
      0080BE A1 F0            [ 1]  114 	cp	a, #0xf0
      0080C0 27 1B            [ 1]  115 	jreq	00116$
      0080C2 7B 0B            [ 1]  116 	ld	a, (0x0b, sp)
      0080C4 A1 90            [ 1]  117 	cp	a, #0x90
      0080C6 27 15            [ 1]  118 	jreq	00116$
      0080C8 7B 0B            [ 1]  119 	ld	a, (0x0b, sp)
      0080CA A1 D0            [ 1]  120 	cp	a, #0xd0
      0080CC 27 0F            [ 1]  121 	jreq	00116$
      0080CE 4B 4D            [ 1]  122 	push	#0x4d
      0080D0 5F               [ 1]  123 	clrw	x
      0080D1 89               [ 2]  124 	pushw	x
      0080D2 4B 00            [ 1]  125 	push	#0x00
      0080D4 4B 24            [ 1]  126 	push	#<(___str_0 + 0)
      0080D6 4B 80            [ 1]  127 	push	#((___str_0 + 0) >> 8)
      0080D8 CD 00 00         [ 4]  128 	call	_assert_failed
      0080DB 5B 06            [ 2]  129 	addw	sp, #6
      0080DD                        130 00116$:
                                    131 ;	source/FWLIB/src/stm8s_gpio.c: 78: assert_param(IS_GPIO_PIN_OK(GPIO_Pin));
      0080DD 0D 0A            [ 1]  132 	tnz	(0x0a, sp)
      0080DF 26 0F            [ 1]  133 	jrne	00151$
      0080E1 4B 4E            [ 1]  134 	push	#0x4e
      0080E3 5F               [ 1]  135 	clrw	x
      0080E4 89               [ 2]  136 	pushw	x
      0080E5 4B 00            [ 1]  137 	push	#0x00
      0080E7 4B 24            [ 1]  138 	push	#<(___str_0 + 0)
      0080E9 4B 80            [ 1]  139 	push	#((___str_0 + 0) >> 8)
      0080EB CD 00 00         [ 4]  140 	call	_assert_failed
      0080EE 5B 06            [ 2]  141 	addw	sp, #6
      0080F0                        142 00151$:
                                    143 ;	source/FWLIB/src/stm8s_gpio.c: 81: GPIOx->CR2 &= (uint8_t)(~(GPIO_Pin));
      0080F0 16 08            [ 2]  144 	ldw	y, (0x08, sp)
      0080F2 93               [ 1]  145 	ldw	x, y
      0080F3 1C 00 04         [ 2]  146 	addw	x, #0x0004
      0080F6 1F 01            [ 2]  147 	ldw	(0x01, sp), x
      0080F8 F6               [ 1]  148 	ld	a, (x)
      0080F9 88               [ 1]  149 	push	a
      0080FA 7B 0B            [ 1]  150 	ld	a, (0x0b, sp)
      0080FC 43               [ 1]  151 	cpl	a
      0080FD 6B 04            [ 1]  152 	ld	(0x04, sp), a
      0080FF 84               [ 1]  153 	pop	a
      008100 14 03            [ 1]  154 	and	a, (0x03, sp)
      008102 1E 01            [ 2]  155 	ldw	x, (0x01, sp)
      008104 F7               [ 1]  156 	ld	(x), a
                                    157 ;	source/FWLIB/src/stm8s_gpio.c: 98: GPIOx->DDR |= (uint8_t)GPIO_Pin;
      008105 93               [ 1]  158 	ldw	x, y
      008106 5C               [ 1]  159 	incw	x
      008107 5C               [ 1]  160 	incw	x
      008108 1F 04            [ 2]  161 	ldw	(0x04, sp), x
                                    162 ;	source/FWLIB/src/stm8s_gpio.c: 87: if ((((uint8_t)(GPIO_Mode)) & (uint8_t)0x80) != (uint8_t)0x00) /* Output mode */
      00810A 0D 0B            [ 1]  163 	tnz	(0x0b, sp)
      00810C 2A 1E            [ 1]  164 	jrpl	00105$
                                    165 ;	source/FWLIB/src/stm8s_gpio.c: 91: GPIOx->ODR |= (uint8_t)GPIO_Pin;
      00810E 90 F6            [ 1]  166 	ld	a, (y)
                                    167 ;	source/FWLIB/src/stm8s_gpio.c: 89: if ((((uint8_t)(GPIO_Mode)) & (uint8_t)0x10) != (uint8_t)0x00) /* High level */
      008110 88               [ 1]  168 	push	a
      008111 7B 0C            [ 1]  169 	ld	a, (0x0c, sp)
      008113 A5 10            [ 1]  170 	bcp	a, #0x10
      008115 84               [ 1]  171 	pop	a
      008116 27 06            [ 1]  172 	jreq	00102$
                                    173 ;	source/FWLIB/src/stm8s_gpio.c: 91: GPIOx->ODR |= (uint8_t)GPIO_Pin;
      008118 1A 0A            [ 1]  174 	or	a, (0x0a, sp)
      00811A 90 F7            [ 1]  175 	ld	(y), a
      00811C 20 04            [ 2]  176 	jra	00103$
      00811E                        177 00102$:
                                    178 ;	source/FWLIB/src/stm8s_gpio.c: 95: GPIOx->ODR &= (uint8_t)(~(GPIO_Pin));
      00811E 14 03            [ 1]  179 	and	a, (0x03, sp)
      008120 90 F7            [ 1]  180 	ld	(y), a
      008122                        181 00103$:
                                    182 ;	source/FWLIB/src/stm8s_gpio.c: 98: GPIOx->DDR |= (uint8_t)GPIO_Pin;
      008122 1E 04            [ 2]  183 	ldw	x, (0x04, sp)
      008124 F6               [ 1]  184 	ld	a, (x)
      008125 1A 0A            [ 1]  185 	or	a, (0x0a, sp)
      008127 1E 04            [ 2]  186 	ldw	x, (0x04, sp)
      008129 F7               [ 1]  187 	ld	(x), a
      00812A 20 08            [ 2]  188 	jra	00106$
      00812C                        189 00105$:
                                    190 ;	source/FWLIB/src/stm8s_gpio.c: 103: GPIOx->DDR &= (uint8_t)(~(GPIO_Pin));
      00812C 1E 04            [ 2]  191 	ldw	x, (0x04, sp)
      00812E F6               [ 1]  192 	ld	a, (x)
      00812F 14 03            [ 1]  193 	and	a, (0x03, sp)
      008131 1E 04            [ 2]  194 	ldw	x, (0x04, sp)
      008133 F7               [ 1]  195 	ld	(x), a
      008134                        196 00106$:
                                    197 ;	source/FWLIB/src/stm8s_gpio.c: 112: GPIOx->CR1 |= (uint8_t)GPIO_Pin;
      008134 93               [ 1]  198 	ldw	x, y
      008135 1C 00 03         [ 2]  199 	addw	x, #0x0003
      008138 F6               [ 1]  200 	ld	a, (x)
                                    201 ;	source/FWLIB/src/stm8s_gpio.c: 110: if ((((uint8_t)(GPIO_Mode)) & (uint8_t)0x40) != (uint8_t)0x00) /* Pull-Up or Push-Pull */
      008139 88               [ 1]  202 	push	a
      00813A 7B 0C            [ 1]  203 	ld	a, (0x0c, sp)
      00813C A5 40            [ 1]  204 	bcp	a, #0x40
      00813E 84               [ 1]  205 	pop	a
      00813F 27 05            [ 1]  206 	jreq	00108$
                                    207 ;	source/FWLIB/src/stm8s_gpio.c: 112: GPIOx->CR1 |= (uint8_t)GPIO_Pin;
      008141 1A 0A            [ 1]  208 	or	a, (0x0a, sp)
      008143 F7               [ 1]  209 	ld	(x), a
      008144 20 03            [ 2]  210 	jra	00109$
      008146                        211 00108$:
                                    212 ;	source/FWLIB/src/stm8s_gpio.c: 116: GPIOx->CR1 &= (uint8_t)(~(GPIO_Pin));
      008146 14 03            [ 1]  213 	and	a, (0x03, sp)
      008148 F7               [ 1]  214 	ld	(x), a
      008149                        215 00109$:
                                    216 ;	source/FWLIB/src/stm8s_gpio.c: 81: GPIOx->CR2 &= (uint8_t)(~(GPIO_Pin));
      008149 1E 01            [ 2]  217 	ldw	x, (0x01, sp)
      00814B F6               [ 1]  218 	ld	a, (x)
                                    219 ;	source/FWLIB/src/stm8s_gpio.c: 123: if ((((uint8_t)(GPIO_Mode)) & (uint8_t)0x20) != (uint8_t)0x00) /* Interrupt or Slow slope */
      00814C 88               [ 1]  220 	push	a
      00814D 7B 0C            [ 1]  221 	ld	a, (0x0c, sp)
      00814F A5 20            [ 1]  222 	bcp	a, #0x20
      008151 84               [ 1]  223 	pop	a
      008152 27 07            [ 1]  224 	jreq	00111$
                                    225 ;	source/FWLIB/src/stm8s_gpio.c: 125: GPIOx->CR2 |= (uint8_t)GPIO_Pin;
      008154 1A 0A            [ 1]  226 	or	a, (0x0a, sp)
      008156 1E 01            [ 2]  227 	ldw	x, (0x01, sp)
      008158 F7               [ 1]  228 	ld	(x), a
      008159 20 05            [ 2]  229 	jra	00113$
      00815B                        230 00111$:
                                    231 ;	source/FWLIB/src/stm8s_gpio.c: 129: GPIOx->CR2 &= (uint8_t)(~(GPIO_Pin));
      00815B 14 03            [ 1]  232 	and	a, (0x03, sp)
      00815D 1E 01            [ 2]  233 	ldw	x, (0x01, sp)
      00815F F7               [ 1]  234 	ld	(x), a
      008160                        235 00113$:
                                    236 ;	source/FWLIB/src/stm8s_gpio.c: 131: }
      008160 5B 05            [ 2]  237 	addw	sp, #5
      008162 81               [ 4]  238 	ret
                                    239 ;	source/FWLIB/src/stm8s_gpio.c: 141: void GPIO_Write(GPIO_TypeDef* GPIOx, uint8_t PortVal)
                                    240 ;	-----------------------------------------
                                    241 ;	 function GPIO_Write
                                    242 ;	-----------------------------------------
      008163                        243 _GPIO_Write:
                                    244 ;	source/FWLIB/src/stm8s_gpio.c: 143: GPIOx->ODR = PortVal;
      008163 1E 03            [ 2]  245 	ldw	x, (0x03, sp)
      008165 7B 05            [ 1]  246 	ld	a, (0x05, sp)
      008167 F7               [ 1]  247 	ld	(x), a
                                    248 ;	source/FWLIB/src/stm8s_gpio.c: 144: }
      008168 81               [ 4]  249 	ret
                                    250 ;	source/FWLIB/src/stm8s_gpio.c: 154: void GPIO_WriteHigh(GPIO_TypeDef* GPIOx, GPIO_Pin_TypeDef PortPins)
                                    251 ;	-----------------------------------------
                                    252 ;	 function GPIO_WriteHigh
                                    253 ;	-----------------------------------------
      008169                        254 _GPIO_WriteHigh:
                                    255 ;	source/FWLIB/src/stm8s_gpio.c: 156: GPIOx->ODR |= (uint8_t)PortPins;
      008169 1E 03            [ 2]  256 	ldw	x, (0x03, sp)
      00816B F6               [ 1]  257 	ld	a, (x)
      00816C 1A 05            [ 1]  258 	or	a, (0x05, sp)
      00816E F7               [ 1]  259 	ld	(x), a
                                    260 ;	source/FWLIB/src/stm8s_gpio.c: 157: }
      00816F 81               [ 4]  261 	ret
                                    262 ;	source/FWLIB/src/stm8s_gpio.c: 167: void GPIO_WriteLow(GPIO_TypeDef* GPIOx, GPIO_Pin_TypeDef PortPins)
                                    263 ;	-----------------------------------------
                                    264 ;	 function GPIO_WriteLow
                                    265 ;	-----------------------------------------
      008170                        266 _GPIO_WriteLow:
      008170 88               [ 1]  267 	push	a
                                    268 ;	source/FWLIB/src/stm8s_gpio.c: 169: GPIOx->ODR &= (uint8_t)(~PortPins);
      008171 1E 04            [ 2]  269 	ldw	x, (0x04, sp)
      008173 F6               [ 1]  270 	ld	a, (x)
      008174 6B 01            [ 1]  271 	ld	(0x01, sp), a
      008176 7B 06            [ 1]  272 	ld	a, (0x06, sp)
      008178 43               [ 1]  273 	cpl	a
      008179 14 01            [ 1]  274 	and	a, (0x01, sp)
      00817B F7               [ 1]  275 	ld	(x), a
                                    276 ;	source/FWLIB/src/stm8s_gpio.c: 170: }
      00817C 84               [ 1]  277 	pop	a
      00817D 81               [ 4]  278 	ret
                                    279 ;	source/FWLIB/src/stm8s_gpio.c: 180: void GPIO_WriteReverse(GPIO_TypeDef* GPIOx, GPIO_Pin_TypeDef PortPins)
                                    280 ;	-----------------------------------------
                                    281 ;	 function GPIO_WriteReverse
                                    282 ;	-----------------------------------------
      00817E                        283 _GPIO_WriteReverse:
                                    284 ;	source/FWLIB/src/stm8s_gpio.c: 182: GPIOx->ODR ^= (uint8_t)PortPins;
      00817E 1E 03            [ 2]  285 	ldw	x, (0x03, sp)
      008180 F6               [ 1]  286 	ld	a, (x)
      008181 18 05            [ 1]  287 	xor	a, (0x05, sp)
      008183 F7               [ 1]  288 	ld	(x), a
                                    289 ;	source/FWLIB/src/stm8s_gpio.c: 183: }
      008184 81               [ 4]  290 	ret
                                    291 ;	source/FWLIB/src/stm8s_gpio.c: 191: uint8_t GPIO_ReadOutputData(GPIO_TypeDef* GPIOx)
                                    292 ;	-----------------------------------------
                                    293 ;	 function GPIO_ReadOutputData
                                    294 ;	-----------------------------------------
      008185                        295 _GPIO_ReadOutputData:
                                    296 ;	source/FWLIB/src/stm8s_gpio.c: 193: return ((uint8_t)GPIOx->ODR);
      008185 1E 03            [ 2]  297 	ldw	x, (0x03, sp)
      008187 F6               [ 1]  298 	ld	a, (x)
                                    299 ;	source/FWLIB/src/stm8s_gpio.c: 194: }
      008188 81               [ 4]  300 	ret
                                    301 ;	source/FWLIB/src/stm8s_gpio.c: 202: uint8_t GPIO_ReadInputData(GPIO_TypeDef* GPIOx)
                                    302 ;	-----------------------------------------
                                    303 ;	 function GPIO_ReadInputData
                                    304 ;	-----------------------------------------
      008189                        305 _GPIO_ReadInputData:
                                    306 ;	source/FWLIB/src/stm8s_gpio.c: 204: return ((uint8_t)GPIOx->IDR);
      008189 1E 03            [ 2]  307 	ldw	x, (0x03, sp)
      00818B E6 01            [ 1]  308 	ld	a, (0x1, x)
                                    309 ;	source/FWLIB/src/stm8s_gpio.c: 205: }
      00818D 81               [ 4]  310 	ret
                                    311 ;	source/FWLIB/src/stm8s_gpio.c: 213: BitStatus GPIO_ReadInputPin(GPIO_TypeDef* GPIOx, GPIO_Pin_TypeDef GPIO_Pin)
                                    312 ;	-----------------------------------------
                                    313 ;	 function GPIO_ReadInputPin
                                    314 ;	-----------------------------------------
      00818E                        315 _GPIO_ReadInputPin:
                                    316 ;	source/FWLIB/src/stm8s_gpio.c: 215: return ((BitStatus)(GPIOx->IDR & (uint8_t)GPIO_Pin));
      00818E 1E 03            [ 2]  317 	ldw	x, (0x03, sp)
      008190 E6 01            [ 1]  318 	ld	a, (0x1, x)
      008192 14 05            [ 1]  319 	and	a, (0x05, sp)
                                    320 ;	source/FWLIB/src/stm8s_gpio.c: 216: }
      008194 81               [ 4]  321 	ret
                                    322 ;	source/FWLIB/src/stm8s_gpio.c: 225: void GPIO_ExternalPullUpConfig(GPIO_TypeDef* GPIOx, GPIO_Pin_TypeDef GPIO_Pin, FunctionalState NewState)
                                    323 ;	-----------------------------------------
                                    324 ;	 function GPIO_ExternalPullUpConfig
                                    325 ;	-----------------------------------------
      008195                        326 _GPIO_ExternalPullUpConfig:
      008195 88               [ 1]  327 	push	a
                                    328 ;	source/FWLIB/src/stm8s_gpio.c: 228: assert_param(IS_GPIO_PIN_OK(GPIO_Pin));
      008196 0D 06            [ 1]  329 	tnz	(0x06, sp)
      008198 26 0F            [ 1]  330 	jrne	00107$
      00819A 4B E4            [ 1]  331 	push	#0xe4
      00819C 5F               [ 1]  332 	clrw	x
      00819D 89               [ 2]  333 	pushw	x
      00819E 4B 00            [ 1]  334 	push	#0x00
      0081A0 4B 24            [ 1]  335 	push	#<(___str_0 + 0)
      0081A2 4B 80            [ 1]  336 	push	#((___str_0 + 0) >> 8)
      0081A4 CD 00 00         [ 4]  337 	call	_assert_failed
      0081A7 5B 06            [ 2]  338 	addw	sp, #6
      0081A9                        339 00107$:
                                    340 ;	source/FWLIB/src/stm8s_gpio.c: 229: assert_param(IS_FUNCTIONALSTATE_OK(NewState));
      0081A9 0D 07            [ 1]  341 	tnz	(0x07, sp)
      0081AB 27 14            [ 1]  342 	jreq	00109$
      0081AD 7B 07            [ 1]  343 	ld	a, (0x07, sp)
      0081AF 4A               [ 1]  344 	dec	a
      0081B0 27 0F            [ 1]  345 	jreq	00109$
      0081B2 4B E5            [ 1]  346 	push	#0xe5
      0081B4 5F               [ 1]  347 	clrw	x
      0081B5 89               [ 2]  348 	pushw	x
      0081B6 4B 00            [ 1]  349 	push	#0x00
      0081B8 4B 24            [ 1]  350 	push	#<(___str_0 + 0)
      0081BA 4B 80            [ 1]  351 	push	#((___str_0 + 0) >> 8)
      0081BC CD 00 00         [ 4]  352 	call	_assert_failed
      0081BF 5B 06            [ 2]  353 	addw	sp, #6
      0081C1                        354 00109$:
                                    355 ;	source/FWLIB/src/stm8s_gpio.c: 233: GPIOx->CR1 |= (uint8_t)GPIO_Pin;
      0081C1 1E 04            [ 2]  356 	ldw	x, (0x04, sp)
      0081C3 1C 00 03         [ 2]  357 	addw	x, #0x0003
      0081C6 F6               [ 1]  358 	ld	a, (x)
                                    359 ;	source/FWLIB/src/stm8s_gpio.c: 231: if (NewState != DISABLE) /* External Pull-Up Set*/
      0081C7 0D 07            [ 1]  360 	tnz	(0x07, sp)
      0081C9 27 05            [ 1]  361 	jreq	00102$
                                    362 ;	source/FWLIB/src/stm8s_gpio.c: 233: GPIOx->CR1 |= (uint8_t)GPIO_Pin;
      0081CB 1A 06            [ 1]  363 	or	a, (0x06, sp)
      0081CD F7               [ 1]  364 	ld	(x), a
      0081CE 20 0A            [ 2]  365 	jra	00104$
      0081D0                        366 00102$:
                                    367 ;	source/FWLIB/src/stm8s_gpio.c: 236: GPIOx->CR1 &= (uint8_t)(~(GPIO_Pin));
      0081D0 88               [ 1]  368 	push	a
      0081D1 7B 07            [ 1]  369 	ld	a, (0x07, sp)
      0081D3 43               [ 1]  370 	cpl	a
      0081D4 6B 02            [ 1]  371 	ld	(0x02, sp), a
      0081D6 84               [ 1]  372 	pop	a
      0081D7 14 01            [ 1]  373 	and	a, (0x01, sp)
      0081D9 F7               [ 1]  374 	ld	(x), a
      0081DA                        375 00104$:
                                    376 ;	source/FWLIB/src/stm8s_gpio.c: 238: }
      0081DA 84               [ 1]  377 	pop	a
      0081DB 81               [ 4]  378 	ret
                                    379 	.area CODE
                                    380 	.area CONST
                                    381 	.area CONST
      008024                        382 ___str_0:
      008024 73 6F 75 72 63 65 2F   383 	.ascii "source/FWLIB/src/stm8s_gpio.c"
             46 57 4C 49 42 2F 73
             72 63 2F 73 74 6D 38
             73 5F 67 70 69 6F 2E
             63
      008041 00                     384 	.db 0x00
                                    385 	.area CODE
                                    386 	.area INITIALIZER
                                    387 	.area CABS (ABS)
