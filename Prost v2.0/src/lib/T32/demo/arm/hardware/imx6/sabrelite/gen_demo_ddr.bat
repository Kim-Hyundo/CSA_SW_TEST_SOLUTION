
armcc -c -g -O2 -li -apcs /interwork demo.c
armasm -g --li --apcs /interwork startup_ddr.s -o startup_ddr.o
armlink -o demo_ddr.axf --scatter=scatter_ddr.ld demo.o startup_ddr.o 
del *.o

