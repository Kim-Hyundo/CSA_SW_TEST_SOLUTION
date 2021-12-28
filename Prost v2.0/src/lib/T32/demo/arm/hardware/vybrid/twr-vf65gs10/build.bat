armcc -g -O0 -c --cpu Cortex-A5 demo.c -o demo.o
armlink --ro-base 0x3F008000 demo.o -o demo.axf
del *.bak *.o
