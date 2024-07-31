@echo off
call %2cmplbeg.bat %2
%2anrig.exe NUL 
%2genrig.exe NUL 
if exist xcrg.exe del xcrg.exe
if exist %1.exe del %1.exe
del *.rc2
%2tpc.exe xcrg /m/l/T%2/U%2/I%2/$M32000,0,650000
copy xcrg.exe %1.exe
call %2cmplend.bat %1
