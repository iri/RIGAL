verify on
del scan.tpu
del usepasu.tpu
del *.rsc
settime
set v=246
call wi copy win
call wi del
cd win
del *.lzh
pkzip  rig_%v%w *.*
cd ..
del *.lzh
pkzip  rig_%v% *.*
cd win
call ..\wi copy ..
call ..\wi del