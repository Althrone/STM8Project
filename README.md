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
│  ├─chip（寄存器版，现已弃用，主要是存放芯片的寄存器地址，挑选需要的进行下载）  
│  ├─demo（寄存器版的例程，自行添加chip文件夹内的头文件就行）  
│  ├─DEVICE（板载外设，实现某种硬件的功能）  
│  ├─DRIVER（驱动程序，例如串口，iic，spi就放在这里）  
│  ├─FWLIB（stm8的标准库）  
│  └─user（用户的程序存放在这里）  
└─tools（程序以外的工具包，选择性下载）  
    └─stm8flash-master（stm8flash的Windows版本）  

## 更新进度
|时间|更新内容|
|-|-|
|2020/7/23|tools文件夹中新增了适用于Windows的stm8flash，里面包含一个编译好的可执行文件，你也可以自行下载主分支的程序和我这个程序进行对比，详见tools\stm8flash-master内的README-FIX.txt文件。|
|2020/7/28|stm8s103的Memory map差不多弄好了，GPIO和外设以及一堆乱七八糟的玩意好糟心，我到时候看看有没有什么好的软件弄个思维导图。|
|2020/8/1|八 一 献 礼（雾，103所有外设寄存器基本更新完毕，stm8s103.h里面包含的头文件基本都齐全的，建议用的时候对着参考手册和数据手册来弄，接下来会新增一个demo文件夹，存放一些设计过程中有趣的例程。|
|2020/8/2|久 等 了，source文件夹新增demo文件夹，目前存放了一个pb5led用定时器定时一秒的led闪烁例程，这表明着芯片基本调通，下一步就是看看如何debug了，我在VSCode的扩展应用里面找到了一个对应的debuger，但是下下来用不了，看看如何调教。|
|2020/9/29|十 一 献 礼，sb寄存器开发我扔了，现在已经支持标准库开发，我迟点把makefile写好一点，现在这个太拉跨。|

## DEMO
|名称|描述|
|-|-|
|pb5_led_tim4_1s.c|就是网上能买到的103的最小系统板，上面有个叫TEST的led灯，是连着PB5的，我加了一个定时器定时一秒的闪烁。|
|595_led_tim4_1s.c|用spi驱动三个级联的595芯片，然后输出全接led，做了一个24颗led的流水灯实验。|

## BUG
|所在文件|解释|
|-|-|
|chip/stm8s103.h|参考手册（319页）中I2C的寄存器只到I2C_TRISER，但是数据手册（35页）在这个寄存器后面还有一个I2C_PECR，不知道有什么用的，以后用到的时候请注意。|
|source/USER/stm8s_conf.h|第90行的宏定义我注释掉了，#define USE_FULL_ASSERT，不知道为什么不注释的话会报错，?ASlink-Warning-Undefined Global '_assert_failed' referenced by module 'xxxxxx'|