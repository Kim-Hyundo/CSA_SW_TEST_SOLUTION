# 	link -dll -debug:full -debugtype:cv -out:pproto.dll pproto.obj pipeproto.obj -def:pproto.def

COPTS = -c -W3 -D_X86_=1 -DWIN32 -DMS_WINDOWS -Z7 -O2 -Gs

all: pproto.dll

pproto.dll: pproto.obj mypipe.obj pipeproto.obj mypipe.h pipeproto.h
	link -dll -out:pproto.dll pproto.obj mypipe.obj pipeproto.obj -def:pproto.def

.c.obj: ; cl $(COPTS) $*.c

clean:
	del /F *.obj *.exp *.ilk *.dll *.pdb
