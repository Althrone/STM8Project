/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __DISPLAY_H
#define __DISPLAY_H

/* Includes ------------------------------------------------------------------*/
#include "stm8s.h"

/* Exported types ------------------------------------------------------------*/
#define CHARP   (uint16_t)0b100000000000    //小数点
#define CHAR1   (uint16_t)0b010000000000
#define CHAR2   (uint16_t)0b001000000000
#define CHAR3   (uint16_t)0b000100000000
#define CHAR4   (uint16_t)0b000010000000
#define CHAR5   (uint16_t)0b000001000000
#define CHAR6   (uint16_t)0b000000100000
#define CHAR7   (uint16_t)0b000000010000
#define CHAR8   (uint16_t)0b000000001000
#define CHAR9   (uint16_t)0b000000000100
#define CHAR0   (uint16_t)0b000000000010
#define CHARA   (uint16_t)0b000000000001    //阳极


/* Exported constants --------------------------------------------------------*/

/* Exported macros -----------------------------------------------------------*/

/* Private macros ------------------------------------------------------------*/

/* Exported functions ------------------------------------------------------- */
void DISP_ShowNumber(void);
uint16_t DISP_TubeSet(uint8_t TubeNumber,uint8_t TubeState,uint16_t DisplayChar);


#endif /* __DISPLAY_H */