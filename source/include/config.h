#ifndef _CONFIG_H_
#define _CONFIG_H_

#define __SDCC_         //功能：定义编译器，用于添加两个中断处理函数
#define __STDINT_H_     //功能：定义时使用int8_t等数据类型             默认：定义
#define __STM8S103_     //功能：定义芯片组，使用对应的chip 文件夹文件   默认：STM8S103
//#define __STM8S105_

#ifdef __SDCC_
    //#include 
#endif /*__SDCC_*/
#ifdef __STDINT_H_
    #include "./stdint.h"
#endif
#ifdef __STM8S103_
    //#define __STM8S103F2_
    #define __STM8S103F3_//功能：定义详细芯片，主要是用于操作字节
    //#define __STM8S103K3_
    #include "../chip/stm8s103/stm8s103.h"
#endif
#ifdef __STM8S105_
    #include "../chip/stm8s105/stm8s105.h"
#endif

#endif /*_CONFIG_H_*/