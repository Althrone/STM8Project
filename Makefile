# sdcc -c -mstm8 -DUSE_STDPERIPH_DRIVER  -Isource/USER -Isource/FWLIB/inc -Isource/DRIVER/inc -Isource/DEVICE/inc -Isource/FUNCTION/inc  source/FUNCTION/src/display.c -o build/display.rel


# Project name
NAME = RcF_NixieClock_Prototype

# c编译生成文件夹
BUILD_DIR = build

# C源文件
USER_C_SOURCES = $(wildcard source/USER/*.c)
STDPERIPH_C_SOURCES =  $(wildcard source/FWLIB/src/*.c)
DEVICE_C_SOURCES = $(wildcard source/DEVICE/src/*.c)
DRIVER_C_SOURCES = $(wildcard source/DRIVER/src/*.c)
FUNCTION_C_SOURCES = $(wildcard source/FUNCTION/src/*.c)

C_SOURCES = $(USER_C_SOURCES) $(STDPERIPH_C_SOURCES) $(DEVICE_C_SOURCES) $(DRIVER_C_SOURCES) $(FUNCTION_C_SOURCES)

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
-Isource/FUNCTION/inc

CFLAGS = $(CPU) $(C_DEFS) $(C_INCLUDES)

#######################################
#OpenOCD
#######################################
OCD_LINK_FILE = stlink-v2.cfg#烧录器配置文件，用于普通买到的烧录器
# OCD_LINK_FILE = stlink-v2-1.cfg	#烧录器配置文件，用于stm32f4discovery
OCD_CHIP_FILE = stm8s.cfg	#芯片配置文件

#######################################
# 开始编译
#######################################
USER_OBJECTS = $(addprefix $(BUILD_DIR)/,$(notdir $(USER_C_SOURCES:.c=.rel)))
STDPERIPH_OBJECTS = $(addprefix $(BUILD_DIR)/,$(notdir $(STDPERIPH_C_SOURCES:.c=.rel)))
DEVICE_OBJECTS = $(addprefix $(BUILD_DIR)/,$(notdir $(DEVICE_C_SOURCES:.c=.rel)))
DRIVER_OBJECTS = $(addprefix $(BUILD_DIR)/,$(notdir $(DRIVER_C_SOURCES:.c=.rel)))
FUNCTION_OBJECTS = $(addprefix $(BUILD_DIR)/,$(notdir $(FUNCTION_C_SOURCES:.c=.rel)))

OBJECTS = $(USER_OBJECTS) $(STDPERIPH_OBJECTS) $(DEVICE_OBJECTS) $(DRIVER_OBJECTS) $(FUNCTION_OBJECTS)

.PHONY: all \
user stdperiph device driver function\
$(BUILD_DIR)/main.ihx $(BUILD_DIR)/main.elf $(BUILD_DIR)/main.s19\
burn link\

all: stdperiph device driver user $(BUILD_DIR)/main.ihx $(BUILD_DIR)/main.elf $(BUILD_DIR)/main.s19

$(BUILD_DIR)/main.ihx: build/main.rel \
build/stm8s_spi.rel build/74hc595.rel build/stm8s_gpio.rel build/stm8s_clk.rel build/stm8s_beep.rel\
build/display.rel
	$(CC) --debug $(CFLAGS) $^ --out-fmt-ihx -o $@

$(BUILD_DIR)/main.elf: build/main.rel \
build/stm8s_spi.rel build/74hc595.rel build/stm8s_gpio.rel build/stm8s_clk.rel build/stm8s_beep.rel\
build/display.rel
	$(CC) --debug $(CFLAGS) $^ --out-fmt-elf -o $@

$(BUILD_DIR)/main.s19: build/main.rel \
build/stm8s_spi.rel build/74hc595.rel build/stm8s_gpio.rel build/stm8s_clk.rel build/stm8s_beep.rel\
build/display.rel
	$(CC) --debug $(CFLAGS) $^ --out-fmt-s19 -o $@


# build/main.ihx: source/USER/main.c build/stm8s_gpio.rel
# 	sdcc -mstm8 $(C_DEFS) -Isource/FWLIB/inc -Isource/USER source/USER/main.c build/stm8s_gpio.rel 

$(BUILD_DIR)/%.rel: %.c
	$(CC) -c --debug $(CFLAGS) $< -o $@

vpath %.c $(sort $(dir $(STDPERIPH_C_SOURCES)))

stdperiph: $(STDPERIPH_OBJECTS)
	@echo \<\<\<\<\<Standard Peripheral Library Compile Completely\>\>\>\>\>

vpath %.c $(sort $(dir $(DEVICE_C_SOURCES)))

device: $(DEVICE_OBJECTS)
	@echo \<\<\<\<\<Device Compile Completely\>\>\>\>\>

vpath %.c $(sort $(dir $(DRIVER_C_SOURCES)))

driver: $(DRIVER_OBJECTS)
	@echo \<\<\<\<\<Driver Compile Completely\>\>\>\>\>

vpath %.c $(sort $(dir $(USER_C_SOURCES)))

user: $(USER_OBJECTS)
	@echo \<\<\<\<\<User File Compile Completely\>\>\>\>\>

vpath %.c $(sort $(dir $(FUNCTION_C_SOURCES)))

user: $(FUNCTION_OBJECTS)
	@echo \<\<\<\<\<Function File Compile Completely\>\>\>\>\>


burn:
	stm8flash -c stlinkv2 -d /dev/ttyUSB0 -p stm8s003f3 -w build/main.ihx

link:
	openocd \
-f interface/$(OCD_LINK_FILE) \
-f target/$(OCD_CHIP_FILE)