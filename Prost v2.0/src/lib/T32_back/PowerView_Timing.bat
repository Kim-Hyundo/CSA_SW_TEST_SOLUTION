﻿:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
set DEV_NAME=Prost
set IP=192.168.20.100
::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::

start %1\bin\windows64\t32mtc.exe -c %1\config_Timing.t32, %1\autostart.cmm %DEV_NAME% %1 %2 %3
