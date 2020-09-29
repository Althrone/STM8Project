# sdcc -mstm8 --out-fmt-ihx -o main.ihx main.c



# OBJECTS = main.o

C_DEFS = \
-DUSE_STDPERIPH_DRIVER \
-D_assert_failed

build/stm8s_gpio.rel: source/FWLIB/src/stm8s_gpio.c
	sdcc -mstm8 $(C_DEFS) -Isource/FWLIB/inc -Isource/USER -c source/FWLIB/src/stm8s_gpio.c -o build/stm8s_gpio.rel

build/stm8s_clk.rel: source/FWLIB/src/stm8s_clk.c
	sdcc -mstm8 $(C_DEFS) -Isource/FWLIB/inc -Isource/USER -c source/FWLIB/src/stm8s_clk.c -o build/stm8s_clk.rel 

build/main.ihx: source/USER/main.c build/stm8s_gpio.rel
	sdcc -mstm8 $(C_DEFS) -Isource/FWLIB/inc -Isource/USER source/USER/main.c build/stm8s_gpio.rel -o build/main.ihx 
# build/main.ihx: build/stm8s_gpio.rel build/main.rel
# 	sdcc -mstm8 build/main.rel build/stm8s_gpio.rel --out-fmt-ihx -o main.ihx $(C_DEFS)

.PHONY: burn aaa bbb ccc


gpio: build/stm8s_gpio.rel

clk: build/stm8s_clk.rel

main: build/main.ihx


burn:
	stm8flash -c stlinkv2 -d /dev/ttyUSB0 -p stm8s103f3 -w main.ihx



