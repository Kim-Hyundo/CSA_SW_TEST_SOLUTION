REM armcc -c -W -g -O2 -Otime --no_inline --no_multifile -DMSC_CLOCK dhry_1.c dhry_2.c
REM armlink dhry_1.o dhry_2.o -o dhry.axf --info totals --RO_BASE 0x80000000

armcc -c -g -O0 dhry_1.c -DMSC_CLOCK dhry_2.c
armlink dhry_1.o dhry_2.o -o dhry.axf --RO_BASE 0x80000000


Delete *.bak
Delete *.o


