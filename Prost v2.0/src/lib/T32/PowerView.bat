:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
set DEV_NAME=Prost
set IP=192.168.20.100
:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::


IF "%1"=="TRICORE" (
  start %2\bin\windows64\t32mtc.exe -c %2\config.t32, %2\autostart.cmm %DEV_NAME% %2 %3 %4
) ELSE (
  start %2\bin\windows64\t32marm.exe -c %2\config.t32, %2\autostart.cmm %DEV_NAME% %2 %3 %4
)