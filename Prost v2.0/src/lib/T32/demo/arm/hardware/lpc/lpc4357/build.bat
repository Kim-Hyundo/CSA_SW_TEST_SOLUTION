armcc -g -O0 -c --thumb --cpu Cortex-M4 sieve.c -o sieve.o
armlink --ro-base 0x10000000 sieve.o -o demo.axf