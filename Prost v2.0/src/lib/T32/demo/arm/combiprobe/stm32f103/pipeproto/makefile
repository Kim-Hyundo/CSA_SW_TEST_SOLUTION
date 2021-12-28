# Makefile for cygwin MinGW compiler

all: pread.exe pread2.exe pread_pipe.exe pread2_pipe.exe

pread.exe: pread.c dll/mypipe.c
	gcc -mno-cygwin -DMS_WINDOWS -O2 -o $@ $^

pread2.exe: pread2.c
	gcc -mno-cygwin -O2 -o $@ $^

pread_pipe.exe: pread_pipe.c
	gcc -mno-cygwin -O2 -o $@ $^

pread2_pipe.exe: pread2_pipe.c
	gcc -mno-cygwin -O2 -o $@ $^


clean:
	rm -rf *.exe
