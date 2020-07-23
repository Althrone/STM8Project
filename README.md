# STM8Project

针对全系列STM8编程、编译、烧录的开源开发方法。Editor: VSCode, Compiler: SDCC, Programmer: stm8flash. STM8 open source development method.

工具链：Windows-VSCode-SDCC-make-stm8flash

这个工程最主要的目的是对stm8芯片进行轻量化开发，现在多数初学者开发单片机都是不同芯片装不同IDE，体积臃肿，而且工作后如果从事这一行有可能被查水表。使用该方法可以使得程序全部在VSCode上编辑，只需要安装不同的编译器、烧录器和调试器即可。

VSCode不说了，最强IDE(雾。

SDCC支持多种8位机的编译。[SDCC官网](http://sdcc.sourceforge.net/)`（鼠标中键点击以打开新窗口）`

stm8flash在GitHub可以下载，但是在Windows环境下使用MinGW64对烧录器进行编译的时候需要修改stm8flash的源代码才能进行编译，我后面会放出修改后的程序，Linux环境下直接make就行了。你也可以自行下载源代码，然后进行更改。[stm8flash下载地址](https://github.com/vdudouyt/stm8flash)`（鼠标中键点击以打开新窗口）`

debug软件还没找到，openocd不支持stm8，这个后面再说吧。

## 文件树
├─build（编译后的.o文件和.ihx文件都存放在这里）  
├─document（主要是一些芯片的数据手册和应用手册，可以选择性下载）  
├─source  
│  ├─chip  
│  │  ├─stm8s103  
│  │  │  └─inc  
│  │  └─stm8s105  
│  └─user  
└─tools  