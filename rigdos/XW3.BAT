@echo off
cd
dir %1
call %2\cmplbeg.bat %1 %2
if exist xcrg.exe del xcrg.exe
if exist %1.exe del %1.exe
if exist %1.par del %1.par
copy xcrg.pas %1.par
del %2*.dsk
del *.rc2
pause