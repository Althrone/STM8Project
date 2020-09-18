# sdcc -mstm8 --out-fmt-ihx -o main.ihx main.c



OBJECTS = main.o

.PHONY: burn

burn:
	stm8flash -c stlinkv2 -d /dev/ttyUSB0 -p stm8s103f3 -w main.ihx