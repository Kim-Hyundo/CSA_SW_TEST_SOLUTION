@echo off
cls
echo.
echo.

bin\armasm -g -o monitor.o monitor.s
bin\armlink -map -ro-base 0x00 -Output armmon.elf monitor.o

