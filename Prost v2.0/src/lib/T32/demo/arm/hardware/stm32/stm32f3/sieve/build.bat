armcc -g -O0 -c --cpu Cortex-M4 sieve.c -o sieve.o
armasm -g --cpu Cortex-M0 startup.s -o startup.o
armlink --ro-base 0x20000000 sieve.o -o demo_sram.axf
armlink --scatter=scatter.ld startup.o sieve.o -o demo_flash.axf
rm *.o
