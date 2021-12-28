armcc -g -O0 -c --thumb --cpu Cortex-M4 sort.c -o sort.o
armlink --ro-base 0x20000000 sort.o -o demo.axf
