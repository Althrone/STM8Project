# Project name
NAME = RcF_NixieClock_Prototype

# c编译生成文件夹
BUILD_DIR = build

# C源文件
STDPERIPH_C_SOURCES =  $(wildcard source/FWLIB/src/*.c)
DEVICE_C_SOURCES = $(wildcard source/DEVICE/src/*.c)
DRIVER_C_SOURCES = $(wildcard source/DRIVER/src/*.c)
USER_C_SOURCES = $(wildcard source/USER/*.c)

C_SOURCES = $(STDPERIPH_C_SOURCES) $(DEVICE_C_SOURCES) $(DRIVER_C_SOURCES) $(USER_C_SOURCES)

#######################################
# binaries
#######################################
CC = sdcc

#######################################
# CFLAGS
#######################################
CPU = -mstm8

C_DEFS = \
-DUSE_STDPERIPH_DRIVER \
-D_assert_failed

# C includes
C_INCLUDES = \
-Isource/USER \
-Isource/FWLIB/inc \
-Isource/DRIVER/inc \
-Isource/DEVICE/inc \

CFLAGS = $(CPU) $(C_DEFS) $(C_INCLUDES)

$(BUILD_DIR)/%.rel: %.c
	$(CC) -c $(CFLAGS) $< -o $@

build/stm8s_gpio.rel: source/FWLIB/src/stm8s_gpio.c
	sdcc -mstm8 $(C_DEFS) -Isource/FWLIB/inc -Isource/USER -c source/FWLIB/src/stm8s_gpio.c -o build/stm8s_gpio.rel

build/stm8s_clk.rel: source/FWLIB/src/stm8s_clk.c
	sdcc -mstm8 $(C_DEFS) -Isource/FWLIB/inc -Isource/USER -c source/FWLIB/src/stm8s_clk.c -o build/stm8s_clk.rel 

build/main.ihx: source/USER/main.c build/stm8s_gpio.rel
	sdcc -mstm8 $(C_DEFS) -Isource/FWLIB/inc -Isource/USER source/USER/main.c build/stm8s_gpio.rel -o build/main.ihx 

.PHONY: burn aaa bbb ccc


gpio: build/stm8s_gpio.rel

clk: build/stm8s_clk.rel

main: build/main.ihx


burn:
	stm8flash -c stlinkv2 -d /dev/ttyUSB0 -p stm8s103f3 -w $(NAME).ihx



