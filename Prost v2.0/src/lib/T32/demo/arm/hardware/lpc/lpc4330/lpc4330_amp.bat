
@ECHO OFF
REM Windows batch file for a one-click start of the amp demo. It
REM assumes TRACE32 is installed to ../t32_altera, modify it to fit your needs.
REM Other core(s) will be started by practice script

SET MACHINE=windows64
SET PPD=%~dp0
SET T32SYS=%PPD%t32\
SET T32PATH=C:/t32/

cd %PPD%
REM Common Syntax:
REM t32m<arch>.exe -c <ConfigFile>.t32 [<param> [<param> [...]]] [-s <StartupScript> [<param> ...]]

start %T32PATH%bin\%MACHINE%\t32marm -c "%PPD%config_amp.t32" "%T32PATH%" 10000 LPC4330 CORE=1 -s "%PPD%lpc4330_multisieve_amp_demo.cmm"
