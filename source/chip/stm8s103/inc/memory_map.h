/****************************************************************************
 * memory_map.h
 * 按照芯片数据手册进行各类宏定义
 ****************************************************************************/

#ifndef _MEMORY_MAPE_H_
#define _MEMORY_MAPE_H_

#include "../../../include/config.h"

#define PA_BASE			0x005000/* 0x005000-0x005004: Port A                    */
#define PB_BASE			0x005005/* 0x005005-0x005009: Port B                    */
#define PC_BASE			0x00500A/* 0x00500A-0x00500E: Port C                    */
#define PD_BASE			0x00500F/* 0x00500F-0x005013: Port D                    */
#define PE_BASE			0x005014/* 0x005014-0x005018: Port E                    */
#define PF_BASE			0x005019/* 0x005019-0x00501D: Port F                    */
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
#define SPI_BASE        0x005200/* 0x005200-0x0050F3: SPI                       */





                                /* 0x005410-0x0057FF: Reserved area (1008 byte) */


#define CPU_BASE        0X007F60/* 0X007F60-0X007F60: CPU                       */
                                /* 0x007F61-0x007F6F: Reserved area (2 byte)    */
#define ITC_BASE        0x007F70/* 0x007F70-0x007F77: ITC                       */
                                /* 0x007F78-0x007F79: Reserved area (2 byte)    */
#define SWIM_BASE       0x007F80/* 0x007F80-0x007F80: SWIM                      */
                                /* 0x007F81-0x007F8F: Reserved area (15 byte)   */
#define DM_BASE         0x007F90/* 0x007F90-0x007F9A: DM                        */


#endif /*_MEMORY_MAPE_H_*/

/**/