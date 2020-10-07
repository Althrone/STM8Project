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

# C includes
C_INCLUDES = \
-Isource/USER \
-Isource/FWLIB/inc \
-Isource/DRIVER/inc \
-Isource/DEVICE/inc \

CFLAGS = $(CPU) $(C_DEFS) $(C_INCLUDES)

$(BUILD_DIR)/%.rel: %.c
	$(CC) -c $(CFLAGS) $< -o $@

#######################################
# 开始编译
#######################################
STDPERIPH_OBJECTS = $(addprefix $(BUILD_DIR)/,$(notdir $(STDPERIPH_C_SOURCES:.c=.o)))
DEVICE_OBJECTS = $(addprefix $(BUILD_DIR)/,$(notdir $(DEVICE_C_SOURCES:.c=.o)))
DRIVER_OBJECTS = $(addprefix $(BUILD_DIR)/,$(notdir $(DRIVER_C_SOURCES:.c=.o)))
USER_OBJECTS = $(addprefix $(BUILD_DIR)/,$(notdir $(USER_C_SOURCES:.c=.o)))

OBJECTS = $(STDPERIPH_OBJECTS) $(DEVICE_OBJECTS) $(DRIVER_OBJECTS) $(USER_OBJECTS)

.PHONY: all \
stdperiph

# all: stdperiph device driver user

$(BUILD_DIR)/%.o: %.c
	$(CC) -c $(CFLAGS) $< -o $@

vpath %.c $(sort $(dir $(STDPERIPH_C_SOURCES)))

stdperiph: $(STDPERIPH_OBJECTS)
	@echo \<\<\<\<\<Standard Peripheral Library Compile Completely\>\>\>\>\>

# build/stm8s_gpio.rel: source/FWLIB/src/stm8s_gpio.c
# 	sdcc -mstm8 $(C_DEFS) -Isource/FWLIB/inc -Isource/USER -c source/FWLIB/src/stm8s_gpio.c -o build/stm8s_gpio.rel

# build/stm8s_clk.rel: source/FWLIB/src/stm8s_clk.c
# 	sdcc -mstm8 $(C_DEFS) -Isource/FWLIB/inc -Isource/USER -c source/FWLIB/src/stm8s_clk.c -o build/stm8s_clk.rel 

# build/main.ihx: source/USER/main.c build/stm8s_gpio.rel
# 	sdcc -mstm8 $(C_DEFS) -Isource/FWLIB/inc -Isource/USER source/USER/main.c build/stm8s_gpio.rel -o build/main.ihx 

# gpio: build/stm8s_gpio.rel

# clk: build/stm8s_clk.rel

# main: build/main.ihx


burn:
	stm8flash -c stlinkv2 -d /dev/ttyUSB0 -p stm8s103f3 -w build/main.ihx



