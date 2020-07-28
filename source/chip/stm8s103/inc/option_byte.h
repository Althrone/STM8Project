#ifndef _OPTION_BYTE_H_
#define _OPTION_BYTE_H_

//寄存器偏移地址
#define OPT_ROP_OFFSET      0x0000//Read-out protection
#define OPT_UBC_OFFSET      0x0001//User boot code area
#define OPT_NUBC_OFFSET     0x0002
#define OPT_AFR_OFFSET      0x0003//Alternate function remapping
#define OPT_NAFR_OFFSET     0x0004
#define OPT_MISC_OFFSET     0x0005//Misc. option
#define OPT_NMISC_OFFSET    0x0006
#define OPT_CLK_OFFSET      0x0007//Clock option
#define OPT_NCLK_OFFSET     0x0008
#define OPT_HSE_OFFSET      0x0009//HSE clock startup
#define OPT_NHSE_OFFSET     0x000A

//寄存器操作

//寄存器基地址+偏移地址


#endif /*_OPTION_BYTE_H_*/

/*用于批量修改
*/