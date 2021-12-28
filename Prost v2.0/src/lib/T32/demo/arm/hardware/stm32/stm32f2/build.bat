armcc -g -O0 -c --cpu Cortex-M3 sieve.c -o sieve.o
armasm -g --cpu Cortex-M3 startup.s -o startup.o
armlink --ro-base 0x20000000 sieve.o -o demo_sram.axf
armlink --scatter=scatter.ld startup.o sieve.o -o demo_flash.axf
rm *.o
