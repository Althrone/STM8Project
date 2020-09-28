# sdcc -mstm8 --out-fmt-ihx -o main.ihx main.c



# OBJECTS = main.o

C_DEFS = \
-DUSE_STDPERIPH_DRIVER

build/stm8s_gpio.rel: source/FWLIB/src/stm8s_gpio.c
	sdcc -mstm8 $(C_DEFS) -c source/FWLIB/src/stm8s_gpio.c -o build/stm8s_gpio.rel -Isource/FWLIB/inc -Isource/USER

build/main.ihx: source/USER/main.c build/stm8s_gpio.rel
	sdcc -mstm8 $(C_DEFS) source/USER/main.c build/stm8s_gpio.rel -o build/main.ihx -Isource/FWLIB/inc -Isource/USER
# build/main.ihx: build/stm8s_gpio.rel build/main.rel
# 	sdcc -mstm8 build/main.rel build/stm8s_gpio.rel --out-fmt-ihx -o main.ihx $(C_DEFS)

.PHONY: burn aaa bbb ccc


aaa: build/stm8s_gpio.rel

bbb: build/main.rel

ccc: build/main.ihx


burn:
	stm8flash -c stlinkv2 -d /dev/ttyUSB0 -p stm8s103f3 -w main.ihx



