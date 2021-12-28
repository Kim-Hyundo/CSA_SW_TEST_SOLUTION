
armcc -c -g -O2 -li -apcs /interwork demo.c
armasm -g --li --apcs /interwork startup_sram.s -o startup_sram.o
armlink -o demo_sram.axf --scatter=scatter_sram.ld demo.o startup_sram.o
del *.o
