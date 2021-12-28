@ECHO OFF

set MAKEUTIL_PATH="$$${COMPILER_AMK_PATH}$$$"

cd %cd%\Debug\
%MAKEUTIL_PATH% -j8 all -a
echo [Compiler Module:Info] - Build Done!

pause / pause>nul : pause
@ECHO ON

