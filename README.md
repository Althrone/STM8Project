# STM8Project

针对全系列STM8编程、编译、烧录的开源开发方法。Editor: VSCode, Compiler: SDCC, Programmer: stm8flash. STM8 open source development method.

工具链：Windows-VSCode-SDCC-make-stm8flash

这个工程最主要的目的是对stm8芯片进行轻量化开发，现在多数初学者开发单片机都是不同芯片装不同IDE，体积臃肿，而且工作后如果从事这一行有可能被查水表。使用该方法可以使得程序全部在VSCode上编辑，只需要安装不同的编译器、烧录器和调试器即可。

VSCode不说了，最强IDE(雾。

SDCC支持多种8位机的编译。[SDCC官网](http://sdcc.sourceforge.net/)`←鼠标中键点击以打开新窗口`

stm8flash在GitHub可以下载，但是在Windows环境下使用MinGW64对烧录器进行编译的时候需要修改stm8flash的源代码才能进行编译，我后面会放出修改后的程序，Linux环境下直接make就行了。你也可以自行下载源代码，然后进行更改。[stm8flash下载地址](https://github.com/vdudouyt/stm8flash)`←鼠标中键点击以打开新窗口`

debug软件还没找到，openocd不支持stm8，这个后面再说吧。

注1：GitHub文件下载后文件名都会变成xxxx-master，其实它是代表不同分支，不喜欢的话可以把后缀删掉。（前提是如果你下了其他分支你能搞清楚区别）

注2：stm的单片机开发主要有寄存器开发、标准库开发和hal库开发三种方法，现在st主推hal库开发，因为STM32CubeMX是他家现在主推的产品。这个工程主要以寄存器开发为主，因为是为一个闹钟的项目服务的，如有必要我也会在工程中添加标准库和hal库。

注3：这个工程很可能只针对s003和s103来编写，因为我的项目是用s003来做的，103是最小系统拿来试手的。其他部分欢迎各位老哥补充。

## 文件树
├─build（编译后的.o文件和.ihx文件都存放在这里）  
├─document（主要是一些芯片的数据手册和应用手册，选择性下载）  
├─source（.c和.h文件都存放在这里）  
│  ├─chip（主要是存放芯片的寄存器地址，挑选需要的进行下载）  
│  ├─include（工程包含头文件的定义，还有一些外部的头文件）  
│  └─user（用户的程序存放在这里）  
└─tools（程序以外的工具包，选择性下载）  
    └─stm8flash-master（stm8flash的Windows版本）  
┌└┐┘─│├┤┬┴┼

## 更新进度
|时间|更新内容|
|-|-|
|2020/7/23|tools文件夹中新增了适用于Windows的stm8flash，里面包含一个编译好的可执行文件，你也可以自行下载主分支的程序和我这个程序进行对比，详见tools\stm8flash-master内的README-FIX.txt文件。|