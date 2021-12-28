
armcc -g --cpu=ARM926EJ-S -c demo.c -o demo.o
armasm -g --cpu=ARM926EJ-S startup_sdram.s -o startup_sdram.o
armlink -o demo_sdram.axf --scatter=scatter_sdram.ld demo.o startup_sdram.o
del *.o

