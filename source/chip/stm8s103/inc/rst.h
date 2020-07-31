#ifndef _RST_H_
#define _RST_H_

#include "./memory_map.h"

//寄存器偏移地址
#define RST_SR_OFFSET   0x0000

//寄存器操作
#define RST_SR_WWDGF    (1<<0)
#define RST_SR_IWDGF    (1<<1)
#define RST_SR_ILLOPF   (1<<2)
#define RST_SR_SWIMF    (1<<3)
#define RST_SR_EMCF     (1<<4)
//#define RST_SR_Res    (1<<5)
//#define RST_SR_Res    (1<<6)
//#define RST_SR_Res    (1<<7)

//寄存器基地址+偏移地址
#define RST_SR *(volatile uint8_t *)(RST_BASE+RST_SR_OFFSET)

#endif /*_RST_H_*/

/*用于批量修改
*/