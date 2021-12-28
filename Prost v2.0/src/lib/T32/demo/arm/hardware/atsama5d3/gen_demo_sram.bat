
armcc -g --cpu=Cortex-A5 -c demo.c -o demo.o
armasm -g --apcs /interwork --cpu=Cortex-A5 startup_sram.s -o startup_sram.o
armlink -o demo_sram.axf --scatter=scatter_sram.ld demo.o startup_sram.o
del *.o

