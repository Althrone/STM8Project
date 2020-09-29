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
                                     11 	.globl _GPIO_DeInit
                                     12 	.globl _GPIO_Init
                                     13 	.globl _GPIO_Write
                                     14 	.globl _GPIO_WriteHigh
                                     15 	.globl _GPIO_WriteLow
                                     16 	.globl _GPIO_WriteReverse
                                     17 	.globl _GPIO_ReadOutputData
                                     18 	.globl _GPIO_ReadInputData
                                     19 	.globl _GPIO_ReadInputPin
                                     20 	.globl _GPIO_ExternalPullUpConfig
                                     21 ;--------------------------------------------------------
                                     22 ; ram data
                                     23 ;--------------------------------------------------------
                                     24 	.area DATA
                                     25 ;--------------------------------------------------------
                                     26 ; ram data
                                     27 ;--------------------------------------------------------
                                     28 	.area INITIALIZED
                                     29 ;--------------------------------------------------------
                                     30 ; absolute external ram data
                                     31 ;--------------------------------------------------------
                                     32 	.area DABS (ABS)
                                     33 
                                     34 ; default segment ordering for linker
                                     35 	.area HOME
                                     36 	.area GSINIT
                                     37 	.area GSFINAL
                                     38 	.area CONST
                                     39 	.area INITIALIZER
                                     40 	.area CODE
                                     41 
                                     42 ;--------------------------------------------------------
                                     43 ; global & static initialisations
                                     44 ;--------------------------------------------------------
                                     45 	.area HOME
                                     46 	.area GSINIT
                                     47 	.area GSFINAL
                                     48 	.area GSINIT
                                     49 ;--------------------------------------------------------
                                     50 ; Home
                                     51 ;--------------------------------------------------------
                                     52 	.area HOME
                                     53 	.area HOME
                                     54 ;--------------------------------------------------------
                                     55 ; code
                                     56 ;--------------------------------------------------------
                                     57 	.area CODE
                                     58 ;	source/FWLIB/src/stm8s_gpio.c: 53: void GPIO_DeInit(GPIO_TypeDef* GPIOx)
                                     59 ;	-----------------------------------------
                                     60 ;	 function GPIO_DeInit
                                     61 ;	-----------------------------------------
      008059                         62 _GPIO_DeInit:
                                     63 ;	source/FWLIB/src/stm8s_gpio.c: 55: GPIOx->ODR = GPIO_ODR_RESET_VALUE; /* Reset Output Data Register */
      008059 16 03            [ 2]   64 	ldw	y, (0x03, sp)
      00805B 90 7F            [ 1]   65 	clr	(y)
                                     66 ;	source/FWLIB/src/stm8s_gpio.c: 56: GPIOx->DDR = GPIO_DDR_RESET_VALUE; /* Reset Data Direction Register */
      00805D 93               [ 1]   67 	ldw	x, y
      00805E 5C               [ 1]   68 	incw	x
      00805F 5C               [ 1]   69 	incw	x
      008060 7F               [ 1]   70 	clr	(x)
                                     71 ;	source/FWLIB/src/stm8s_gpio.c: 57: GPIOx->CR1 = GPIO_CR1_RESET_VALUE; /* Reset Control Register 1 */
      008061 93               [ 1]   72 	ldw	x, y
      008062 6F 03            [ 1]   73 	clr	(0x0003, x)
                                     74 ;	source/FWLIB/src/stm8s_gpio.c: 58: GPIOx->CR2 = GPIO_CR2_RESET_VALUE; /* Reset Control Register 2 */
      008064 93               [ 1]   75 	ldw	x, y
      008065 6F 04            [ 1]   76 	clr	(0x0004, x)
                                     77 ;	source/FWLIB/src/stm8s_gpio.c: 59: }
      008067 81               [ 4]   78 	ret
                                     79 ;	source/FWLIB/src/stm8s_gpio.c: 71: void GPIO_Init(GPIO_TypeDef* GPIOx, GPIO_Pin_TypeDef GPIO_Pin, GPIO_Mode_TypeDef GPIO_Mode)
                                     80 ;	-----------------------------------------
                                     81 ;	 function GPIO_Init
                                     82 ;	-----------------------------------------
      008068                         83 _GPIO_Init:
      008068 52 05            [ 2]   84 	sub	sp, #5
                                     85 ;	source/FWLIB/src/stm8s_gpio.c: 81: GPIOx->CR2 &= (uint8_t)(~(GPIO_Pin));
      00806A 16 08            [ 2]   86 	ldw	y, (0x08, sp)
      00806C 93               [ 1]   87 	ldw	x, y
      00806D 1C 00 04         [ 2]   88 	addw	x, #0x0004
      008070 1F 01            [ 2]   89 	ldw	(0x01, sp), x
      008072 F6               [ 1]   90 	ld	a, (x)
      008073 88               [ 1]   91 	push	a
      008074 7B 0B            [ 1]   92 	ld	a, (0x0b, sp)
      008076 43               [ 1]   93 	cpl	a
      008077 6B 04            [ 1]   94 	ld	(0x04, sp), a
      008079 84               [ 1]   95 	pop	a
      00807A 14 03            [ 1]   96 	and	a, (0x03, sp)
      00807C 1E 01            [ 2]   97 	ldw	x, (0x01, sp)
      00807E F7               [ 1]   98 	ld	(x), a
                                     99 ;	source/FWLIB/src/stm8s_gpio.c: 98: GPIOx->DDR |= (uint8_t)GPIO_Pin;
      00807F 93               [ 1]  100 	ldw	x, y
      008080 5C               [ 1]  101 	incw	x
      008081 5C               [ 1]  102 	incw	x
      008082 1F 04            [ 2]  103 	ldw	(0x04, sp), x
                                    104 ;	source/FWLIB/src/stm8s_gpio.c: 87: if ((((uint8_t)(GPIO_Mode)) & (uint8_t)0x80) != (uint8_t)0x00) /* Output mode */
      008084 0D 0B            [ 1]  105 	tnz	(0x0b, sp)
      008086 2A 1E            [ 1]  106 	jrpl	00105$
                                    107 ;	source/FWLIB/src/stm8s_gpio.c: 91: GPIOx->ODR |= (uint8_t)GPIO_Pin;
      008088 90 F6            [ 1]  108 	ld	a, (y)
                                    109 ;	source/FWLIB/src/stm8s_gpio.c: 89: if ((((uint8_t)(GPIO_Mode)) & (uint8_t)0x10) != (uint8_t)0x00) /* High level */
      00808A 88               [ 1]  110 	push	a
      00808B 7B 0C            [ 1]  111 	ld	a, (0x0c, sp)
      00808D A5 10            [ 1]  112 	bcp	a, #0x10
      00808F 84               [ 1]  113 	pop	a
      008090 27 06            [ 1]  114 	jreq	00102$
                                    115 ;	source/FWLIB/src/stm8s_gpio.c: 91: GPIOx->ODR |= (uint8_t)GPIO_Pin;
      008092 1A 0A            [ 1]  116 	or	a, (0x0a, sp)
      008094 90 F7            [ 1]  117 	ld	(y), a
      008096 20 04            [ 2]  118 	jra	00103$
      008098                        119 00102$:
                                    120 ;	source/FWLIB/src/stm8s_gpio.c: 95: GPIOx->ODR &= (uint8_t)(~(GPIO_Pin));
      008098 14 03            [ 1]  121 	and	a, (0x03, sp)
      00809A 90 F7            [ 1]  122 	ld	(y), a
      00809C                        123 00103$:
                                    124 ;	source/FWLIB/src/stm8s_gpio.c: 98: GPIOx->DDR |= (uint8_t)GPIO_Pin;
      00809C 1E 04            [ 2]  125 	ldw	x, (0x04, sp)
      00809E F6               [ 1]  126 	ld	a, (x)
      00809F 1A 0A            [ 1]  127 	or	a, (0x0a, sp)
      0080A1 1E 04            [ 2]  128 	ldw	x, (0x04, sp)
      0080A3 F7               [ 1]  129 	ld	(x), a
      0080A4 20 08            [ 2]  130 	jra	00106$
      0080A6                        131 00105$:
                                    132 ;	source/FWLIB/src/stm8s_gpio.c: 103: GPIOx->DDR &= (uint8_t)(~(GPIO_Pin));
      0080A6 1E 04            [ 2]  133 	ldw	x, (0x04, sp)
      0080A8 F6               [ 1]  134 	ld	a, (x)
      0080A9 14 03            [ 1]  135 	and	a, (0x03, sp)
      0080AB 1E 04            [ 2]  136 	ldw	x, (0x04, sp)
      0080AD F7               [ 1]  137 	ld	(x), a
      0080AE                        138 00106$:
                                    139 ;	source/FWLIB/src/stm8s_gpio.c: 112: GPIOx->CR1 |= (uint8_t)GPIO_Pin;
      0080AE 93               [ 1]  140 	ldw	x, y
      0080AF 1C 00 03         [ 2]  141 	addw	x, #0x0003
      0080B2 F6               [ 1]  142 	ld	a, (x)
                                    143 ;	source/FWLIB/src/stm8s_gpio.c: 110: if ((((uint8_t)(GPIO_Mode)) & (uint8_t)0x40) != (uint8_t)0x00) /* Pull-Up or Push-Pull */
      0080B3 88               [ 1]  144 	push	a
      0080B4 7B 0C            [ 1]  145 	ld	a, (0x0c, sp)
      0080B6 A5 40            [ 1]  146 	bcp	a, #0x40
      0080B8 84               [ 1]  147 	pop	a
      0080B9 27 05            [ 1]  148 	jreq	00108$
                                    149 ;	source/FWLIB/src/stm8s_gpio.c: 112: GPIOx->CR1 |= (uint8_t)GPIO_Pin;
      0080BB 1A 0A            [ 1]  150 	or	a, (0x0a, sp)
      0080BD F7               [ 1]  151 	ld	(x), a
      0080BE 20 03            [ 2]  152 	jra	00109$
      0080C0                        153 00108$:
                                    154 ;	source/FWLIB/src/stm8s_gpio.c: 116: GPIOx->CR1 &= (uint8_t)(~(GPIO_Pin));
      0080C0 14 03            [ 1]  155 	and	a, (0x03, sp)
      0080C2 F7               [ 1]  156 	ld	(x), a
      0080C3                        157 00109$:
                                    158 ;	source/FWLIB/src/stm8s_gpio.c: 81: GPIOx->CR2 &= (uint8_t)(~(GPIO_Pin));
      0080C3 1E 01            [ 2]  159 	ldw	x, (0x01, sp)
      0080C5 F6               [ 1]  160 	ld	a, (x)
                                    161 ;	source/FWLIB/src/stm8s_gpio.c: 123: if ((((uint8_t)(GPIO_Mode)) & (uint8_t)0x20) != (uint8_t)0x00) /* Interrupt or Slow slope */
      0080C6 88               [ 1]  162 	push	a
      0080C7 7B 0C            [ 1]  163 	ld	a, (0x0c, sp)
      0080C9 A5 20            [ 1]  164 	bcp	a, #0x20
      0080CB 84               [ 1]  165 	pop	a
      0080CC 27 07            [ 1]  166 	jreq	00111$
                                    167 ;	source/FWLIB/src/stm8s_gpio.c: 125: GPIOx->CR2 |= (uint8_t)GPIO_Pin;
      0080CE 1A 0A            [ 1]  168 	or	a, (0x0a, sp)
      0080D0 1E 01            [ 2]  169 	ldw	x, (0x01, sp)
      0080D2 F7               [ 1]  170 	ld	(x), a
      0080D3 20 05            [ 2]  171 	jra	00113$
      0080D5                        172 00111$:
                                    173 ;	source/FWLIB/src/stm8s_gpio.c: 129: GPIOx->CR2 &= (uint8_t)(~(GPIO_Pin));
      0080D5 14 03            [ 1]  174 	and	a, (0x03, sp)
      0080D7 1E 01            [ 2]  175 	ldw	x, (0x01, sp)
      0080D9 F7               [ 1]  176 	ld	(x), a
      0080DA                        177 00113$:
                                    178 ;	source/FWLIB/src/stm8s_gpio.c: 131: }
      0080DA 5B 05            [ 2]  179 	addw	sp, #5
      0080DC 81               [ 4]  180 	ret
                                    181 ;	source/FWLIB/src/stm8s_gpio.c: 141: void GPIO_Write(GPIO_TypeDef* GPIOx, uint8_t PortVal)
                                    182 ;	-----------------------------------------
                                    183 ;	 function GPIO_Write
                                    184 ;	-----------------------------------------
      0080DD                        185 _GPIO_Write:
                                    186 ;	source/FWLIB/src/stm8s_gpio.c: 143: GPIOx->ODR = PortVal;
      0080DD 1E 03            [ 2]  187 	ldw	x, (0x03, sp)
      0080DF 7B 05            [ 1]  188 	ld	a, (0x05, sp)
      0080E1 F7               [ 1]  189 	ld	(x), a
                                    190 ;	source/FWLIB/src/stm8s_gpio.c: 144: }
      0080E2 81               [ 4]  191 	ret
                                    192 ;	source/FWLIB/src/stm8s_gpio.c: 154: void GPIO_WriteHigh(GPIO_TypeDef* GPIOx, GPIO_Pin_TypeDef PortPins)
                                    193 ;	-----------------------------------------
                                    194 ;	 function GPIO_WriteHigh
                                    195 ;	-----------------------------------------
      0080E3                        196 _GPIO_WriteHigh:
                                    197 ;	source/FWLIB/src/stm8s_gpio.c: 156: GPIOx->ODR |= (uint8_t)PortPins;
      0080E3 1E 03            [ 2]  198 	ldw	x, (0x03, sp)
      0080E5 F6               [ 1]  199 	ld	a, (x)
      0080E6 1A 05            [ 1]  200 	or	a, (0x05, sp)
      0080E8 F7               [ 1]  201 	ld	(x), a
                                    202 ;	source/FWLIB/src/stm8s_gpio.c: 157: }
      0080E9 81               [ 4]  203 	ret
                                    204 ;	source/FWLIB/src/stm8s_gpio.c: 167: void GPIO_WriteLow(GPIO_TypeDef* GPIOx, GPIO_Pin_TypeDef PortPins)
                                    205 ;	-----------------------------------------
                                    206 ;	 function GPIO_WriteLow
                                    207 ;	-----------------------------------------
      0080EA                        208 _GPIO_WriteLow:
      0080EA 88               [ 1]  209 	push	a
                                    210 ;	source/FWLIB/src/stm8s_gpio.c: 169: GPIOx->ODR &= (uint8_t)(~PortPins);
      0080EB 1E 04            [ 2]  211 	ldw	x, (0x04, sp)
      0080ED F6               [ 1]  212 	ld	a, (x)
      0080EE 6B 01            [ 1]  213 	ld	(0x01, sp), a
      0080F0 7B 06            [ 1]  214 	ld	a, (0x06, sp)
      0080F2 43               [ 1]  215 	cpl	a
      0080F3 14 01            [ 1]  216 	and	a, (0x01, sp)
      0080F5 F7               [ 1]  217 	ld	(x), a
                                    218 ;	source/FWLIB/src/stm8s_gpio.c: 170: }
      0080F6 84               [ 1]  219 	pop	a
      0080F7 81               [ 4]  220 	ret
                                    221 ;	source/FWLIB/src/stm8s_gpio.c: 180: void GPIO_WriteReverse(GPIO_TypeDef* GPIOx, GPIO_Pin_TypeDef PortPins)
                                    222 ;	-----------------------------------------
                                    223 ;	 function GPIO_WriteReverse
                                    224 ;	-----------------------------------------
      0080F8                        225 _GPIO_WriteReverse:
                                    226 ;	source/FWLIB/src/stm8s_gpio.c: 182: GPIOx->ODR ^= (uint8_t)PortPins;
      0080F8 1E 03            [ 2]  227 	ldw	x, (0x03, sp)
      0080FA F6               [ 1]  228 	ld	a, (x)
      0080FB 18 05            [ 1]  229 	xor	a, (0x05, sp)
      0080FD F7               [ 1]  230 	ld	(x), a
                                    231 ;	source/FWLIB/src/stm8s_gpio.c: 183: }
      0080FE 81               [ 4]  232 	ret
                                    233 ;	source/FWLIB/src/stm8s_gpio.c: 191: uint8_t GPIO_ReadOutputData(GPIO_TypeDef* GPIOx)
                                    234 ;	-----------------------------------------
                                    235 ;	 function GPIO_ReadOutputData
                                    236 ;	-----------------------------------------
      0080FF                        237 _GPIO_ReadOutputData:
                                    238 ;	source/FWLIB/src/stm8s_gpio.c: 193: return ((uint8_t)GPIOx->ODR);
      0080FF 1E 03            [ 2]  239 	ldw	x, (0x03, sp)
      008101 F6               [ 1]  240 	ld	a, (x)
                                    241 ;	source/FWLIB/src/stm8s_gpio.c: 194: }
      008102 81               [ 4]  242 	ret
                                    243 ;	source/FWLIB/src/stm8s_gpio.c: 202: uint8_t GPIO_ReadInputData(GPIO_TypeDef* GPIOx)
                                    244 ;	-----------------------------------------
                                    245 ;	 function GPIO_ReadInputData
                                    246 ;	-----------------------------------------
      008103                        247 _GPIO_ReadInputData:
                                    248 ;	source/FWLIB/src/stm8s_gpio.c: 204: return ((uint8_t)GPIOx->IDR);
      008103 1E 03            [ 2]  249 	ldw	x, (0x03, sp)
      008105 E6 01            [ 1]  250 	ld	a, (0x1, x)
                                    251 ;	source/FWLIB/src/stm8s_gpio.c: 205: }
      008107 81               [ 4]  252 	ret
                                    253 ;	source/FWLIB/src/stm8s_gpio.c: 213: BitStatus GPIO_ReadInputPin(GPIO_TypeDef* GPIOx, GPIO_Pin_TypeDef GPIO_Pin)
                                    254 ;	-----------------------------------------
                                    255 ;	 function GPIO_ReadInputPin
                                    256 ;	-----------------------------------------
      008108                        257 _GPIO_ReadInputPin:
                                    258 ;	source/FWLIB/src/stm8s_gpio.c: 215: return ((BitStatus)(GPIOx->IDR & (uint8_t)GPIO_Pin));
      008108 1E 03            [ 2]  259 	ldw	x, (0x03, sp)
      00810A E6 01            [ 1]  260 	ld	a, (0x1, x)
      00810C 14 05            [ 1]  261 	and	a, (0x05, sp)
                                    262 ;	source/FWLIB/src/stm8s_gpio.c: 216: }
      00810E 81               [ 4]  263 	ret
                                    264 ;	source/FWLIB/src/stm8s_gpio.c: 225: void GPIO_ExternalPullUpConfig(GPIO_TypeDef* GPIOx, GPIO_Pin_TypeDef GPIO_Pin, FunctionalState NewState)
                                    265 ;	-----------------------------------------
                                    266 ;	 function GPIO_ExternalPullUpConfig
                                    267 ;	-----------------------------------------
      00810F                        268 _GPIO_ExternalPullUpConfig:
      00810F 88               [ 1]  269 	push	a
                                    270 ;	source/FWLIB/src/stm8s_gpio.c: 233: GPIOx->CR1 |= (uint8_t)GPIO_Pin;
      008110 1E 04            [ 2]  271 	ldw	x, (0x04, sp)
      008112 1C 00 03         [ 2]  272 	addw	x, #0x0003
      008115 F6               [ 1]  273 	ld	a, (x)
                                    274 ;	source/FWLIB/src/stm8s_gpio.c: 231: if (NewState != DISABLE) /* External Pull-Up Set*/
      008116 0D 07            [ 1]  275 	tnz	(0x07, sp)
      008118 27 05            [ 1]  276 	jreq	00102$
                                    277 ;	source/FWLIB/src/stm8s_gpio.c: 233: GPIOx->CR1 |= (uint8_t)GPIO_Pin;
      00811A 1A 06            [ 1]  278 	or	a, (0x06, sp)
      00811C F7               [ 1]  279 	ld	(x), a
      00811D 20 0A            [ 2]  280 	jra	00104$
      00811F                        281 00102$:
                                    282 ;	source/FWLIB/src/stm8s_gpio.c: 236: GPIOx->CR1 &= (uint8_t)(~(GPIO_Pin));
      00811F 88               [ 1]  283 	push	a
      008120 7B 07            [ 1]  284 	ld	a, (0x07, sp)
      008122 43               [ 1]  285 	cpl	a
      008123 6B 02            [ 1]  286 	ld	(0x02, sp), a
      008125 84               [ 1]  287 	pop	a
      008126 14 01            [ 1]  288 	and	a, (0x01, sp)
      008128 F7               [ 1]  289 	ld	(x), a
      008129                        290 00104$:
                                    291 ;	source/FWLIB/src/stm8s_gpio.c: 238: }
      008129 84               [ 1]  292 	pop	a
      00812A 81               [ 4]  293 	ret
                                    294 	.area CODE
                                    295 	.area CONST
                                    296 	.area INITIALIZER
                                    297 	.area CABS (ABS)
