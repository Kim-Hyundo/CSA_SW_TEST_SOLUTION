armcc -g -O0 -c --thumb --cpu Cortex-M4 printfk60.c -o printfk60.o
armcc -g -O0 -c --thumb --cpu Cortex-M4 vsprintf.c -o vsprintf.o
armlink --ro-base 0x20000000 vsprintf.o printfk60.o -o demo.axf