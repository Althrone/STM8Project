#ifndef _CONFIG_H_
#define _CONFIG_H_

	#define __STDINT_H_		//功能：定义时使用int8_t等数据类型				默认：定义
	#define __STM8S103_		//功能：定义芯片组，使用对应的chip文件夹文件	默认：STM8S103
	//#define __STM8S105_	

	#ifdef __STDINT_H_
		#include "./stdint.h"
	#endif

#endif /*_CONFIG_H_*/