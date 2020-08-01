sdcc -mstm8 --out-fmt-ihx -o main.ihx main.c

stm8flash.exe -c stlinkv2 -d /dev/ttyUSB0 -p stm8s103f3 -w main.ihx