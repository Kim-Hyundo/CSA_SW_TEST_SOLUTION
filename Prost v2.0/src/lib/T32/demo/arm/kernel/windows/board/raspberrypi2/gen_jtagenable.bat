armcc -g -c -O0 --cpu 7-A --thumb -o jtagenable.o jtagenable.c
armasm -g --cpu 7-A --thumb -o startup.o startup.s
armlink --ro-base 0x8000 -o jtagenable.elf jtagenable.o startup.o
fromelf --bin -o jtagenable.bin jtagenable.elf
del *.o


