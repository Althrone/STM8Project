/****************************************************************************
 * memory_map.h
 * 按照芯片数据手册进行各类宏定义
 ****************************************************************************/

#ifndef _MEMORY_MAPE_H_
#define _MEMORY_MAPE_H_

#include "../../../include/config.h"
/*RAM****************************************************************************/
                                /* 0x000000-0x0003FF: RAM (1 Kbyte)             */
                                /* 0x0001FF-0x0003FF: stack (513 byte)          */
/*Reserved***********************************************************************/
                                /* 0x000800-0x003FFF: Reserved area (120 Kbyte) */
/*640 bytes data EEPROM**********************************************************/
                                /* 0x004000-0x00427F: data EEPROM (640 byte)    */
/*Reserved***********************************************************************/
                                /* 0x004280-0x0047FF: Reserved area (1408 byte) */
/*Option bytes*******************************************************************/
#define OPT_BSAE        0x004800/* 0x004800-0x00480A: Option bytes (11 byte)    */
/*Reserved***********************************************************************/
                                /* 0x00480B-0x004864: Reserved area (90 byte)   */
/*Unique ID**********************************************************************/
#define UID_BASE        0x004865/* 0x004865-0x004870: Unique ID (12 byte)       */
/*Reserved***********************************************************************/
                                /* 0x004871-0x004FFF: Reserved area (1935 byte) */
/*GPIO and periph. reg.**********************************************************/
#define PA_BASE         0x005000/* 0x005000-0x005004: Port A                    */
#define PB_BASE         0x005005/* 0x005005-0x005009: Port B                    */
#define PC_BASE         0x00500A/* 0x00500A-0x00500E: Port C                    */
#define PD_BASE         0x00500F/* 0x00500F-0x005013: Port D                    */
#define PE_BASE         0x005014/* 0x005014-0x005018: Port E                    */
#define PF_BASE         0x005019/* 0x005019-0x00501D: Port F                    */
                                /* 0x00501E-0x005059: Reserved area (60 byte)   */
#define FLASH_BASE      0x00505A/* 0x00505A-0x005064: Flash                     */
                                /* 0x005065-0x00509F: Reserved area (59 byte)   */
#define EXTI_BASE       0x0050A0/* 0x0050A0-0x0050A1: EXTI                      */
                                /* 0x0050A2-0x0050B2: Reserved area (17 byte)   */
#define RST_BASE        0x0050B3/* 0x0050B3-0x0050B3: RST                       */
                                /* 0x0050B4-0x0050BF: Reserved area (12 byte)   */
#define CLK_BASE        0x0050C0/* 0x0050C0-0x0050CD: CLK                       */
                                /* 0x0050CE-0x0050D0: Reserved area (3 byte)    */
#define WWDG_BASE       0x0050D1/* 0x0050D1-0x0050D2: WWDG                      */
                                /* 0x0050D3-0x0050DF: Reserved area (13 byte)   */
#define IWDG_BASE       0x0050E0/* 0x0050E0-0x0050E2: IWDG                      */
                                /* 0x0050E3-0x0050EF: Reserved area (13 byte)   */
#define AWU_BASE        0x0050F0/* 0x0050F0-0x0050F2: AWU                       */
#define BEEP_BASE       0x0050F3/* 0x0050F3-0x0050F3: BEEP                      */
                                /* 0x0050F4-0x0050FF: Reserved area (12 byte)   */
                                /* 0x005100-0x0051FF: Reserved area (265 byte)  */
#define SPI_BASE        0x005200/* 0x005200-0x005207: SPI                       */
                                /* 0x005208-0x00520F: Reserved area (8 byte)    */
#define I2C_BASE        0x005210/* 0x005210-0x00521E: I2C                       */
                                /* 0x00521F-0x00522F: Reserved area (17 byte)   */
#define UART1_BASE      0x005230/* 0x005230-0x00523A: UART1                     */
                                /* 0x00523B-0x00524F: Reserved area (21 byte)   */
#define TIM1_BASE       0x005250/* 0x005250-0x00526F: TIM1                      */
                                /* 0x005270-0x0052FF: Reserved area (144 byte)  */
#define TIM2_BASE       0x005300/* 0x005300-0x005316: TIM2                      */
                                /* 0x005317-0x00533F: Reserved area (43 byte)   */
#define TIM4_BASE       0x005340/* 0x005340-0x005348: TIM4                      */
                                /* 0x005349-0x0053DF: Reserved area (153 byte)  */
#define ADC1_BASE       0x0053E0/* 0x0053E0-0x00540F: ADC1                      */
                                /* 0x005410-0x0057FF: Reserved area (1008 byte) */
/*Reserved***********************************************************************/
                                /* 0x005800-0x007EFF: Reserved area (9984 byte) */
/*CPU/SWIM/debug/ITC registers***************************************************/
#define CPU_BASE        0X007F00/* 0X007F00-0X007F60: CPU                       */
                                /* 0x007F61-0x007F6F: Reserved area (15 byte)   */
#define ITC_BASE        0x007F70/* 0x007F70-0x007F77: ITC                       */
                                /* 0x007F78-0x007F79: Reserved area (2 byte)    */
#define SWIM_BASE       0x007F80/* 0x007F80-0x007F80: SWIM                      */
                                /* 0x007F81-0x007F8F: Reserved area (15 byte)   */
#define DM_BASE         0x007F90/* 0x007F90-0x007F9A: DM                        */
                                /* 0x007F9B-0x007F9F: Reserved area (5 byte)    */
                                /* 0x007FA0-0x007FFF: Reserved area (104 byte)  */
/*Flash program memory***********************************************************/
                                /* 0x008000-0x00807F: 32 interrupt vectors      */
                                /* 0x008000-0x009FFF: ROM (8 Kbyte)             */
/*Reserved***********************************************************************/
                                /* 0x00A000-0x027FFF: Reserved area (120 Kbyte) */
/********************************************************************************/

#endif /*_MEMORY_MAPE_H_*/