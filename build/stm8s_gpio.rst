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
      008CC1                         62 _GPIO_DeInit:
                                     63 ;	source/FWLIB/src/stm8s_gpio.c: 55: GPIOx->ODR = GPIO_ODR_RESET_VALUE; /* Reset Output Data Register */
      008CC1 16 03            [ 2]   64 	ldw	y, (0x03, sp)
      008CC3 90 7F            [ 1]   65 	clr	(y)
                                     66 ;	source/FWLIB/src/stm8s_gpio.c: 56: GPIOx->DDR = GPIO_DDR_RESET_VALUE; /* Reset Data Direction Register */
      008CC5 93               [ 1]   67 	ldw	x, y
      008CC6 5C               [ 1]   68 	incw	x
      008CC7 5C               [ 1]   69 	incw	x
      008CC8 7F               [ 1]   70 	clr	(x)
                                     71 ;	source/FWLIB/src/stm8s_gpio.c: 57: GPIOx->CR1 = GPIO_CR1_RESET_VALUE; /* Reset Control Register 1 */
      008CC9 93               [ 1]   72 	ldw	x, y
      008CCA 6F 03            [ 1]   73 	clr	(0x0003, x)
                                     74 ;	source/FWLIB/src/stm8s_gpio.c: 58: GPIOx->CR2 = GPIO_CR2_RESET_VALUE; /* Reset Control Register 2 */
      008CCC 93               [ 1]   75 	ldw	x, y
      008CCD 6F 04            [ 1]   76 	clr	(0x0004, x)
                                     77 ;	source/FWLIB/src/stm8s_gpio.c: 59: }
      008CCF 81               [ 4]   78 	ret
                                     79 ;	source/FWLIB/src/stm8s_gpio.c: 71: void GPIO_Init(GPIO_TypeDef* GPIOx, GPIO_Pin_TypeDef GPIO_Pin, GPIO_Mode_TypeDef GPIO_Mode)
                                     80 ;	-----------------------------------------
                                     81 ;	 function GPIO_Init
                                     82 ;	-----------------------------------------
      008CD0                         83 _GPIO_Init:
      008CD0 52 05            [ 2]   84 	sub	sp, #5
                                     85 ;	source/FWLIB/src/stm8s_gpio.c: 81: GPIOx->CR2 &= (uint8_t)(~(GPIO_Pin));
      008CD2 16 08            [ 2]   86 	ldw	y, (0x08, sp)
      008CD4 93               [ 1]   87 	ldw	x, y
      008CD5 1C 00 04         [ 2]   88 	addw	x, #0x0004
      008CD8 1F 01            [ 2]   89 	ldw	(0x01, sp), x
      008CDA F6               [ 1]   90 	ld	a, (x)
      008CDB 88               [ 1]   91 	push	a
      008CDC 7B 0B            [ 1]   92 	ld	a, (0x0b, sp)
      008CDE 43               [ 1]   93 	cpl	a
      008CDF 6B 04            [ 1]   94 	ld	(0x04, sp), a
      008CE1 84               [ 1]   95 	pop	a
      008CE2 14 03            [ 1]   96 	and	a, (0x03, sp)
      008CE4 1E 01            [ 2]   97 	ldw	x, (0x01, sp)
      008CE6 F7               [ 1]   98 	ld	(x), a
                                     99 ;	source/FWLIB/src/stm8s_gpio.c: 98: GPIOx->DDR |= (uint8_t)GPIO_Pin;
      008CE7 93               [ 1]  100 	ldw	x, y
      008CE8 5C               [ 1]  101 	incw	x
      008CE9 5C               [ 1]  102 	incw	x
      008CEA 1F 04            [ 2]  103 	ldw	(0x04, sp), x
                                    104 ;	source/FWLIB/src/stm8s_gpio.c: 87: if ((((uint8_t)(GPIO_Mode)) & (uint8_t)0x80) != (uint8_t)0x00) /* Output mode */
      008CEC 0D 0B            [ 1]  105 	tnz	(0x0b, sp)
      008CEE 2A 1E            [ 1]  106 	jrpl	00105$
                                    107 ;	source/FWLIB/src/stm8s_gpio.c: 91: GPIOx->ODR |= (uint8_t)GPIO_Pin;
      008CF0 90 F6            [ 1]  108 	ld	a, (y)
                                    109 ;	source/FWLIB/src/stm8s_gpio.c: 89: if ((((uint8_t)(GPIO_Mode)) & (uint8_t)0x10) != (uint8_t)0x00) /* High level */
      008CF2 88               [ 1]  110 	push	a
      008CF3 7B 0C            [ 1]  111 	ld	a, (0x0c, sp)
      008CF5 A5 10            [ 1]  112 	bcp	a, #0x10
      008CF7 84               [ 1]  113 	pop	a
      008CF8 27 06            [ 1]  114 	jreq	00102$
                                    115 ;	source/FWLIB/src/stm8s_gpio.c: 91: GPIOx->ODR |= (uint8_t)GPIO_Pin;
      008CFA 1A 0A            [ 1]  116 	or	a, (0x0a, sp)
      008CFC 90 F7            [ 1]  117 	ld	(y), a
      008CFE 20 04            [ 2]  118 	jra	00103$
      008D00                        119 00102$:
                                    120 ;	source/FWLIB/src/stm8s_gpio.c: 95: GPIOx->ODR &= (uint8_t)(~(GPIO_Pin));
      008D00 14 03            [ 1]  121 	and	a, (0x03, sp)
      008D02 90 F7            [ 1]  122 	ld	(y), a
      008D04                        123 00103$:
                                    124 ;	source/FWLIB/src/stm8s_gpio.c: 98: GPIOx->DDR |= (uint8_t)GPIO_Pin;
      008D04 1E 04            [ 2]  125 	ldw	x, (0x04, sp)
      008D06 F6               [ 1]  126 	ld	a, (x)
      008D07 1A 0A            [ 1]  127 	or	a, (0x0a, sp)
      008D09 1E 04            [ 2]  128 	ldw	x, (0x04, sp)
      008D0B F7               [ 1]  129 	ld	(x), a
      008D0C 20 08            [ 2]  130 	jra	00106$
      008D0E                        131 00105$:
                                    132 ;	source/FWLIB/src/stm8s_gpio.c: 103: GPIOx->DDR &= (uint8_t)(~(GPIO_Pin));
      008D0E 1E 04            [ 2]  133 	ldw	x, (0x04, sp)
      008D10 F6               [ 1]  134 	ld	a, (x)
      008D11 14 03            [ 1]  135 	and	a, (0x03, sp)
      008D13 1E 04            [ 2]  136 	ldw	x, (0x04, sp)
      008D15 F7               [ 1]  137 	ld	(x), a
      008D16                        138 00106$:
                                    139 ;	source/FWLIB/src/stm8s_gpio.c: 112: GPIOx->CR1 |= (uint8_t)GPIO_Pin;
      008D16 93               [ 1]  140 	ldw	x, y
      008D17 1C 00 03         [ 2]  141 	addw	x, #0x0003
      008D1A F6               [ 1]  142 	ld	a, (x)
                                    143 ;	source/FWLIB/src/stm8s_gpio.c: 110: if ((((uint8_t)(GPIO_Mode)) & (uint8_t)0x40) != (uint8_t)0x00) /* Pull-Up or Push-Pull */
      008D1B 88               [ 1]  144 	push	a
      008D1C 7B 0C            [ 1]  145 	ld	a, (0x0c, sp)
      008D1E A5 40            [ 1]  146 	bcp	a, #0x40
      008D20 84               [ 1]  147 	pop	a
      008D21 27 05            [ 1]  148 	jreq	00108$
                                    149 ;	source/FWLIB/src/stm8s_gpio.c: 112: GPIOx->CR1 |= (uint8_t)GPIO_Pin;
      008D23 1A 0A            [ 1]  150 	or	a, (0x0a, sp)
      008D25 F7               [ 1]  151 	ld	(x), a
      008D26 20 03            [ 2]  152 	jra	00109$
      008D28                        153 00108$:
                                    154 ;	source/FWLIB/src/stm8s_gpio.c: 116: GPIOx->CR1 &= (uint8_t)(~(GPIO_Pin));
      008D28 14 03            [ 1]  155 	and	a, (0x03, sp)
      008D2A F7               [ 1]  156 	ld	(x), a
      008D2B                        157 00109$:
                                    158 ;	source/FWLIB/src/stm8s_gpio.c: 81: GPIOx->CR2 &= (uint8_t)(~(GPIO_Pin));
      008D2B 1E 01            [ 2]  159 	ldw	x, (0x01, sp)
      008D2D F6               [ 1]  160 	ld	a, (x)
                                    161 ;	source/FWLIB/src/stm8s_gpio.c: 123: if ((((uint8_t)(GPIO_Mode)) & (uint8_t)0x20) != (uint8_t)0x00) /* Interrupt or Slow slope */
      008D2E 88               [ 1]  162 	push	a
      008D2F 7B 0C            [ 1]  163 	ld	a, (0x0c, sp)
      008D31 A5 20            [ 1]  164 	bcp	a, #0x20
      008D33 84               [ 1]  165 	pop	a
      008D34 27 07            [ 1]  166 	jreq	00111$
                                    167 ;	source/FWLIB/src/stm8s_gpio.c: 125: GPIOx->CR2 |= (uint8_t)GPIO_Pin;
      008D36 1A 0A            [ 1]  168 	or	a, (0x0a, sp)
      008D38 1E 01            [ 2]  169 	ldw	x, (0x01, sp)
      008D3A F7               [ 1]  170 	ld	(x), a
      008D3B 20 05            [ 2]  171 	jra	00113$
      008D3D                        172 00111$:
                                    173 ;	source/FWLIB/src/stm8s_gpio.c: 129: GPIOx->CR2 &= (uint8_t)(~(GPIO_Pin));
      008D3D 14 03            [ 1]  174 	and	a, (0x03, sp)
      008D3F 1E 01            [ 2]  175 	ldw	x, (0x01, sp)
      008D41 F7               [ 1]  176 	ld	(x), a
      008D42                        177 00113$:
                                    178 ;	source/FWLIB/src/stm8s_gpio.c: 131: }
      008D42 5B 05            [ 2]  179 	addw	sp, #5
      008D44 81               [ 4]  180 	ret
                                    181 ;	source/FWLIB/src/stm8s_gpio.c: 141: void GPIO_Write(GPIO_TypeDef* GPIOx, uint8_t PortVal)
                                    182 ;	-----------------------------------------
                                    183 ;	 function GPIO_Write
                                    184 ;	-----------------------------------------
      008D45                        185 _GPIO_Write:
                                    186 ;	source/FWLIB/src/stm8s_gpio.c: 143: GPIOx->ODR = PortVal;
      008D45 1E 03            [ 2]  187 	ldw	x, (0x03, sp)
      008D47 7B 05            [ 1]  188 	ld	a, (0x05, sp)
      008D49 F7               [ 1]  189 	ld	(x), a
                                    190 ;	source/FWLIB/src/stm8s_gpio.c: 144: }
      008D4A 81               [ 4]  191 	ret
                                    192 ;	source/FWLIB/src/stm8s_gpio.c: 154: void GPIO_WriteHigh(GPIO_TypeDef* GPIOx, GPIO_Pin_TypeDef PortPins)
                                    193 ;	-----------------------------------------
                                    194 ;	 function GPIO_WriteHigh
                                    195 ;	-----------------------------------------
      008D4B                        196 _GPIO_WriteHigh:
                                    197 ;	source/FWLIB/src/stm8s_gpio.c: 156: GPIOx->ODR |= (uint8_t)PortPins;
      008D4B 1E 03            [ 2]  198 	ldw	x, (0x03, sp)
      008D4D F6               [ 1]  199 	ld	a, (x)
      008D4E 1A 05            [ 1]  200 	or	a, (0x05, sp)
      008D50 F7               [ 1]  201 	ld	(x), a
                                    202 ;	source/FWLIB/src/stm8s_gpio.c: 157: }
      008D51 81               [ 4]  203 	ret
                                    204 ;	source/FWLIB/src/stm8s_gpio.c: 167: void GPIO_WriteLow(GPIO_TypeDef* GPIOx, GPIO_Pin_TypeDef PortPins)
                                    205 ;	-----------------------------------------
                                    206 ;	 function GPIO_WriteLow
                                    207 ;	-----------------------------------------
      008D52                        208 _GPIO_WriteLow:
      008D52 88               [ 1]  209 	push	a
                                    210 ;	source/FWLIB/src/stm8s_gpio.c: 169: GPIOx->ODR &= (uint8_t)(~PortPins);
      008D53 1E 04            [ 2]  211 	ldw	x, (0x04, sp)
      008D55 F6               [ 1]  212 	ld	a, (x)
      008D56 6B 01            [ 1]  213 	ld	(0x01, sp), a
      008D58 7B 06            [ 1]  214 	ld	a, (0x06, sp)
      008D5A 43               [ 1]  215 	cpl	a
      008D5B 14 01            [ 1]  216 	and	a, (0x01, sp)
      008D5D F7               [ 1]  217 	ld	(x), a
                                    218 ;	source/FWLIB/src/stm8s_gpio.c: 170: }
      008D5E 84               [ 1]  219 	pop	a
      008D5F 81               [ 4]  220 	ret
                                    221 ;	source/FWLIB/src/stm8s_gpio.c: 180: void GPIO_WriteReverse(GPIO_TypeDef* GPIOx, GPIO_Pin_TypeDef PortPins)
                                    222 ;	-----------------------------------------
                                    223 ;	 function GPIO_WriteReverse
                                    224 ;	-----------------------------------------
      008D60                        225 _GPIO_WriteReverse:
                                    226 ;	source/FWLIB/src/stm8s_gpio.c: 182: GPIOx->ODR ^= (uint8_t)PortPins;
      008D60 1E 03            [ 2]  227 	ldw	x, (0x03, sp)
      008D62 F6               [ 1]  228 	ld	a, (x)
      008D63 18 05            [ 1]  229 	xor	a, (0x05, sp)
      008D65 F7               [ 1]  230 	ld	(x), a
                                    231 ;	source/FWLIB/src/stm8s_gpio.c: 183: }
      008D66 81               [ 4]  232 	ret
                                    233 ;	source/FWLIB/src/stm8s_gpio.c: 191: uint8_t GPIO_ReadOutputData(GPIO_TypeDef* GPIOx)
                                    234 ;	-----------------------------------------
                                    235 ;	 function GPIO_ReadOutputData
                                    236 ;	-----------------------------------------
      008D67                        237 _GPIO_ReadOutputData:
                                    238 ;	source/FWLIB/src/stm8s_gpio.c: 193: return ((uint8_t)GPIOx->ODR);
      008D67 1E 03            [ 2]  239 	ldw	x, (0x03, sp)
      008D69 F6               [ 1]  240 	ld	a, (x)
                                    241 ;	source/FWLIB/src/stm8s_gpio.c: 194: }
      008D6A 81               [ 4]  242 	ret
                                    243 ;	source/FWLIB/src/stm8s_gpio.c: 202: uint8_t GPIO_ReadInputData(GPIO_TypeDef* GPIOx)
                                    244 ;	-----------------------------------------
                                    245 ;	 function GPIO_ReadInputData
                                    246 ;	-----------------------------------------
      008D6B                        247 _GPIO_ReadInputData:
                                    248 ;	source/FWLIB/src/stm8s_gpio.c: 204: return ((uint8_t)GPIOx->IDR);
      008D6B 1E 03            [ 2]  249 	ldw	x, (0x03, sp)
      008D6D E6 01            [ 1]  250 	ld	a, (0x1, x)
                                    251 ;	source/FWLIB/src/stm8s_gpio.c: 205: }
      008D6F 81               [ 4]  252 	ret
                                    253 ;	source/FWLIB/src/stm8s_gpio.c: 213: BitStatus GPIO_ReadInputPin(GPIO_TypeDef* GPIOx, GPIO_Pin_TypeDef GPIO_Pin)
                                    254 ;	-----------------------------------------
                                    255 ;	 function GPIO_ReadInputPin
                                    256 ;	-----------------------------------------
      008D70                        257 _GPIO_ReadInputPin:
                                    258 ;	source/FWLIB/src/stm8s_gpio.c: 215: return ((BitStatus)(GPIOx->IDR & (uint8_t)GPIO_Pin));
      008D70 1E 03            [ 2]  259 	ldw	x, (0x03, sp)
      008D72 E6 01            [ 1]  260 	ld	a, (0x1, x)
      008D74 14 05            [ 1]  261 	and	a, (0x05, sp)
                                    262 ;	source/FWLIB/src/stm8s_gpio.c: 216: }
      008D76 81               [ 4]  263 	ret
                                    264 ;	source/FWLIB/src/stm8s_gpio.c: 225: void GPIO_ExternalPullUpConfig(GPIO_TypeDef* GPIOx, GPIO_Pin_TypeDef GPIO_Pin, FunctionalState NewState)
                                    265 ;	-----------------------------------------
                                    266 ;	 function GPIO_ExternalPullUpConfig
                                    267 ;	-----------------------------------------
      008D77                        268 _GPIO_ExternalPullUpConfig:
      008D77 88               [ 1]  269 	push	a
                                    270 ;	source/FWLIB/src/stm8s_gpio.c: 233: GPIOx->CR1 |= (uint8_t)GPIO_Pin;
      008D78 1E 04            [ 2]  271 	ldw	x, (0x04, sp)
      008D7A 1C 00 03         [ 2]  272 	addw	x, #0x0003
      008D7D F6               [ 1]  273 	ld	a, (x)
                                    274 ;	source/FWLIB/src/stm8s_gpio.c: 231: if (NewState != DISABLE) /* External Pull-Up Set*/
      008D7E 0D 07            [ 1]  275 	tnz	(0x07, sp)
      008D80 27 05            [ 1]  276 	jreq	00102$
                                    277 ;	source/FWLIB/src/stm8s_gpio.c: 233: GPIOx->CR1 |= (uint8_t)GPIO_Pin;
      008D82 1A 06            [ 1]  278 	or	a, (0x06, sp)
      008D84 F7               [ 1]  279 	ld	(x), a
      008D85 20 0A            [ 2]  280 	jra	00104$
      008D87                        281 00102$:
                                    282 ;	source/FWLIB/src/stm8s_gpio.c: 236: GPIOx->CR1 &= (uint8_t)(~(GPIO_Pin));
      008D87 88               [ 1]  283 	push	a
      008D88 7B 07            [ 1]  284 	ld	a, (0x07, sp)
      008D8A 43               [ 1]  285 	cpl	a
      008D8B 6B 02            [ 1]  286 	ld	(0x02, sp), a
      008D8D 84               [ 1]  287 	pop	a
      008D8E 14 01            [ 1]  288 	and	a, (0x01, sp)
      008D90 F7               [ 1]  289 	ld	(x), a
      008D91                        290 00104$:
                                    291 ;	source/FWLIB/src/stm8s_gpio.c: 238: }
      008D91 84               [ 1]  292 	pop	a
      008D92 81               [ 4]  293 	ret
                                    294 	.area CODE
                                    295 	.area CONST
                                    296 	.area INITIALIZER
                                    297 	.area CABS (ABS)
