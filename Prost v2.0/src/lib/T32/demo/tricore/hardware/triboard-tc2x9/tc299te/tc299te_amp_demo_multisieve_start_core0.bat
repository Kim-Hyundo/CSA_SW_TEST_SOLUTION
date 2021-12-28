@ECHO OFF
REM --------------------------------------------------------------------------------
REM @Title: Batch file for TC299TE on TRIBOARD-TC2X9
REM @Description:
REM   Windows batch file for a one-click start of the amp multisieve demo. It
REM   assumes TRACE32 is installed to C:\T32, modify it to fit your needs.
REM   Other core(s) will be started by the tc299te_amp_demo_multisieve.cmm
REM   practice script.
REM @Board: TriBoard-TC2x9
REM @Chip: TC299TE
REM @Copyright: (C) 1989-2020 Lauterbach GmbH, licensed for use with TRACE32(R) only
REM --------------------------------------------------------------------------------
REM $Id: tc299te_amp_demo_multisieve_start_core0.bat 15579 2020-01-27 15:08:53Z sltaief $


SET P1_PORT=10000
SET P2_TITLE=TriCore-Core0
SET P3_TMP=%TMP%
SET P4_SYS=C:\t32
SET P5_HELP=%P4_SYS%\pdf
IF "%1"=="" (
  SET P6_PBI=USB
  SET P7_OPT=CORE=1
  SET P8_OPT=
  SET P9_OPT=
) ELSE (
  SET P6_PBI=NET
  SET P7_OPT=NODE=%1
  SET P8_OPT=PACKLEN=1024
  SET P9_OPT=CORE=1
)

REM Try to find TriCore executable
SET T32MTC_EXE=%P4_SYS%\bin\windows64\t32mtc.exe
IF NOT EXIST %T32MTC_EXE% (
  SET T32MTC_EXE=%P4_SYS%\bin\windows\t32mtc.exe
)
IF NOT EXIST %T32MTC_EXE% (
  ECHO "t32mtc.exe not found"
  ECHO "Please check that P4_SYS is set to your TRACE32 system directory (Current value: %P4_SYS%)"
  PAUSE
)

start %T32MTC_EXE% -c config_multicore.t32 %P1_PORT% %P2_TITLE% %P3_TMP% %P4_SYS% %P5_HELP% %P6_PBI% %P7_OPT% %P8_OPT% %P9_OPT% -s tc299te_amp_demo_multisieve.cmm
