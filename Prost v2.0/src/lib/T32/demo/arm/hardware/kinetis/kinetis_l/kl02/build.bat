armcc -g -O0 -c --cpu Cortex-M0 midi.c -o midi.o
armasm -g --cpu Cortex-M0 startup.s -o startup.o
armlink --ro-base 0x20000000 midi.o -o demo_sram.axf
armlink --scatter=scatter.ld startup.o midi.o -o demo_flash.axf
rm *.o
