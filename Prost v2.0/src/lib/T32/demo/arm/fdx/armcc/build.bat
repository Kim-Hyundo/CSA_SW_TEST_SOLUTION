REM set PATH=X:\arm\arm251\bin;%PATH%
REM set ARMLIB=X:\arm\arm251\lib
set ROBASE=0x8000

REM set COMPILER=tcc
set COMPILER=armcc

%COMPILER% -g -c fdxtarget.c -DT32_FDX_TRACE_COMPRESSED
%COMPILER% -g -c fdxtrace.c -DT32_FDX_TRACE_COMPRESSED -DT32_FDX_TRACE_BUFSIZE=512

REM t32fdxarm.c cannot be compiled with in thumb mode due to inline assembly for dcc
if "%COMPILER%"=="tcc" goto TCC

%COMPILER% -g -c t32fdx.c -DT32_FDX_DCC3 -DT32_FDX_TRACE_COMPRESSED -DT32_FDX_TRACE_BUFSIZE=512
%COMPILER% -g -c t32dcc3.c -DT32_FDX_DCC3
%COMPILER% -g -c fdxtarget.c
%COMPILER% -g -c fdxtrace.c

%COMPILER% -g -c t32fdxarm.c -DARM7 -DT32_FDX_DCC3
armlink -o armfdxtargetarm7.axf -ro-base %ROBASE% fdxtarget.o t32fdx.o t32fdxarm.o t32dcc3.o
armlink -o armfdxtracearm7.axf  -ro-base %ROBASE% fdxtrace.o  t32fdx.o t32fdxarm.o t32dcc3.o

%COMPILER% -g -c t32fdxarm.c -DARM9 -DT32_FDX_DCC3
armlink -o armfdxtargetarm9.axf -ro-base %ROBASE% fdxtarget.o t32fdx.o t32fdxarm.o t32dcc3.o
armlink -o armfdxtracearm9.axf  -ro-base %ROBASE% fdxtrace.o  t32fdx.o t32fdxarm.o t32dcc3.o

%COMPILER% -g -c t32fdxarm.c -DARM11 -DT32_FDX_DCC3
armlink -o armfdxtargetarm11.axf -ro-base %ROBASE% fdxtarget.o t32fdx.o t32fdxarm.o t32dcc3.o
armlink -o armfdxtracearm11.axf  -ro-base %ROBASE% fdxtrace.o  t32fdx.o t32fdxarm.o t32dcc3.o

%COMPILER% -g -c t32fdxarm.c -DXSCALE -DT32_FDX_DCC3
armlink -o armfdxtargetarmxscale.axf -ro-base %ROBASE% fdxtarget.o t32fdx.o t32fdxarm.o t32dcc3.o
armlink -o armfdxtracearmxscale.axf -ro-base %ROBASE% fdxtrace.o t32fdx.o t32fdxarm.o t32dcc3.o

:TCC
%COMPILER% -g -c t32fdx.c -DT32_FDX_TRACE_COMPRESSED -DT32_FDX_TRACE_BUFSIZE=512
%COMPILER% -g -c t32fdxarm.c -DCORTEXM3
armlink -o armfdxtargetcoretexm3.axf -ro-base %ROBASE% fdxtarget.o t32fdx.o t32fdxarm.o
armlink -o armfdxtracecoretexm3.axf -ro-base %ROBASE% fdxtrace.o t32fdx.o t32fdxarm.o
