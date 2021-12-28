:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
set DEV_NAME=Prost
set IP=192.168.20.100
::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::

if "%1" == "TRICORE" goto t32mtc
elif "%1" == "ARM" goto t32arm

:t32mtc
start %2\bin\windows64\t32mtc.exe -c %2\config_Coverage.t32, %2\autostart.cmm %DEV_NAME% %2 %3 %4

goto:eof

:t32arm
start %2\bin\windows64\t32arm.exe -c %2\config_Coverage.t32, %2\autostart.cmm %DEV_NAME% %2 %3 %4
