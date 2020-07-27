/**
 * 此文件节选自c99中引进的一个标准C库的文件
 * 
 * /
/* 7.18.1.1  Exact-width integer types */
typedef signed char			int8_t;
typedef unsigned char		uint8_t;

typedef signed short		int16_t;
typedef unsigned short		uint16_t;

typedef signed int			int32_t;
typedef unsigned int		uint32_t;

typedef signed long long	int64_t;
typedef unsigned long long	uint64_t;

//_t代表types，最基础的种类

//_s代表struct，结构体
//_e代表enum，枚举类型
//_u代表union,共用体

//_p代表指针

//_c代表clock，与时间相关的都以他结尾，使用数字+全小写单位传递参数，如20ms，20ns，20us,20s