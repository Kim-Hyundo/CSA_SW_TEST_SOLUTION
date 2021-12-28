REM generates semihosting demo with ARM compiler V3.1
REM system variables below need to be adapted

REM set PATH=<bin_path>
REM set ARMLIB=<lib_path>

armcc -O0 -c -g termdemo.c t32term.c t32term_arm7_arm9.c
armlink -o t32term_arm7_arm9.axf --scatter=t32term.scat termdemo.o t32term.o t32term_arm7_arm9.o
