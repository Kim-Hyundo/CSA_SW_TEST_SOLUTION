armcc -g -c jtagenable.c
armlink -o jtagenable.elf -ro-base 0x8000 jtagenable.o
del jtagenable.o


