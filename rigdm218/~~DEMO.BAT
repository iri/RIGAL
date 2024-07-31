echo off

rem ------------------------------------------- 11
clear 14,0,1

color 14
big 1,,7,c{{o{{m{{p{{i{{l{{e{{r
color 14,1
box 6,,75,15,2
call ~~wait  10 %1
color 15,1
put 7,,HOW CAN YOU WRITE COMPILER IN RIGAL ?
color 1,7
box 9,7,15,4,2
box 9,55,15,4,2
put 11,13,SOURCE
put 12,12,PROGRAM
put 11,59,RESULTING
put 12,61,CODE
color 14,4
call ~~wait  8 %1
put 11,25,\\\\\
put 12,25,/////
call ~~wait  8 %1
put 11,37,\\\\\
put 12,37,/////
call ~~wait  8 %1
put 11,49,\\\\\
put 12,49,/////
call ~~wait  10 %1
color 0,7
box 9,,15,4,2
put 11,,PROGRAM'S
put 12,,ABSTRACT
put 13,,TREE
color 14,4
call ~~wait  50 %1
put 13,27,V
put 13,51,V
box 14,14,20,3,1
box 14,42,20,3,1
call ~~wait  7 %1
color 14,4
put 15,21,   PARSING
put 16,23,     and
put 17,18,TREE BUILDING
put 15,43,TRAVERSING THE TREE
put 16,45,  AND GENERATION
put 17,47,    OF THE CODE
color 15,1
put 21,,YOU WRITE BOTH PHASES IN RIGAL
call ~~wait  150 %1

rem --------------------------------------- 12
clear 14,0,1

color 14
big 1,,7,o{{p{{t{{i{{m{{i{{z{{e{{r
color 14,1
box 6,,75,15,2
call ~~wait  10 %1
color 15,1
put 7,,HOW  CAN  YOU  WRITE  OPTIMIZER ?
color 1,7
box 9,7,15,4,2
box 9,55,15,4,2
put 11,13,SOURCE
put 12,12,PROGRAM
put 11,60,OPTIMIZED
put 12,61,PROGRAM
put 13,62,TREE
color 14,4
put 11,25,\\\\\
put 12,25,/////
put 11,49,\\\\\
put 12,49,/////
color 0,7
box 9,,15,4,2
put 11,,PROGRAM'S
put 12,,ABSTRACT
put 13,,TREE
color 14,4
call ~~wait  50 %1
put 13,27,V
put 13,51,V
color 0,7
box 14,14,20,3,1
put 15,16,... SAME PARSING
put 16,23,     and
put 17,18,TREE BUILDING
call ~~wait  10 %1
color 14,4
box 14,42,20,3,1
put 15,44,TRAVERSING THE TREE
put 16,51,     AND
put 17,44,TRANSFORMING IT
color 15,1
call ~~wait  150 %1

rem ------------------------------------ 13
clear 14,0,1

color 14
big 1,,7,implementation
color 14,1
box 6,,75,15,2
call ~~wait  10 %1
color 15,1
put 7,,IMPLEMENTATION OF RIGAL INCLUDES
color 1,7
box 9,,15,3,2
put 10,,TEXT
put 12,,EDITOR
box 9,8,17,3,2
put 10,13,RIGAL
put 12,12,CHECKER
box 9,52,17,3,2
put 10,59,SERVICE
put 12,58,PROGRAMS
box 15,19,17,3,2
put 17,23,INTERPRETER
box 15,42,17,3,2
put 17,46,COMPILER
call ~~wait  10 %1
color 14,4
put 21,,ALL COMPONENTS ARE CALLED FROM TEXT EDITOR
box 9,,15,3,2
put 10,,TEXT
put 12,,EDITOR
put 10,27,----
put 11,27,----
put 10,48,----
put 11,48,----
put 14,34,!!
put 14,44,!!
call ~~wait  200 %1
color 1,7
box 9,,15,3,2
put 10,,TEXT
put 12,,EDITOR
color 14,4
box 9,8,17,3,2
put 10,13,RIGAL
put 12,12,CHECKER
put 21,,CHECKS  RIGAL  PROGRAM  FOR  SYNTAX ERRORS
call ~~wait  50 %1
color 1,7
box 9,8,17,3,2
put 10,13,RIGAL
put 12,12,CHECKER
color 14,4
box 15,19,17,3,2
put 17,23,INTERPRETER
put 21,,EXECUTES   RIGAL  PROGRAM  AFTER  CHECKING
call ~~wait  50 %1
color 1,7
box 15,19,17,3,2
put 17,23,INTERPRETER
color 14,4
box 15,42,17,3,2
put 17,46,COMPILER
put 21,,Compiles RIGAL program to PASCAL and then to ".EXE" file
call ~~wait  50 %1
color 1,7
box 15,42,17,3,2
put 17,46,COMPILER
color 14,4
box 9,52,17,3,2
put 10,59,SERVICE
put 12,58,PROGRAMS
put 21,,Different   services  like   CROSS-REFERENCER  or   LINT
call ~~wait  60 %1

call ~~contin.BAT %1

rem ------------------------------------ 14
clear 14,0,1

color 14
big 1,,7,implementation
color 15,1
box 5,,60,17,2
put 6,,RIGAL IMPLEMENTED IN
put 7,,PDP-11    for    RSX-11M
put 8,,VAX       for    VAX/VMS
color 15,0
put 9,,IBM/PC/XT/AT for MS-DOS/PC-DOS and MS-WINDOWS
color 15,1
put 10,,SUN-4 workstations for SUN/UNIX
put 12,,Tool requires minimum 2 MBytes of hard disc space
put 13,,and 640 KBytes of RAM memory.
put 14,,Size of one RIGAL program - not more than 40 000 tokens.
put 16,,All implementations are written
put 17,,in PASCAL and RIGAL itself.
put 18,,THREE LARGE SYSTEMS WERE WRITTEN IN RIGAL:
put 19,,compiler from RIGAL to PASCAL,
put 20,,compiler from SDL/PLUS to PASCAL and
put 21,,compiler from GRAPES/4GL to INFORMIX/4GL plus C
call ~~wait  200 %1

rem ------------------------------------ 15
clear 14,0,1

color 14
big 1,,8,H{{O{{W{{{{I{{T
big 9,,8,W{{O{{R{{K{{S
box 17,,60,3,2
put 18,,LOOK HOW TO CREATE A SIMPLE PROGRAM
put 19,,in file EXA.RIG and EXECUTE IT
put 20,,USING THE RIGAL INTEGRATED ENVIRONMENT
call ~~wait  200 %1
if exist exa.rig del exa.rig
RIG.EXE EMPTY ~~demo_D.dat
if errorlevel 5 ~~stop

rem ------------------------------------ 16
clear 14,0,1

color 14
big 1,,7,How to debug
big 7,,7,RIGAL program ?
box 13,,60,5,2
put 15,,LOOK HOW TO DEBUG
put 17,,EXISTING PROGRAM in file EXA.RIG
call ~~wait  200 %1
RIG.EXE EXA ~~demo_F.DAT
if errorlevel 5 ~~stop

CALL ~~contin.BAT %1

rem ------------------------------------ 17
clear 14,0,1

color 14
big 1,,7,How to write
big 7,,7,parser ?
box 15,,60,4,2
put 16,,LOOK HOW TO HAVE
put 17,,AN ARITHMETICAL EXPRESSION FROM FILE,
put 18,,HOW TO PARSE IT,
put 19,,HOW TO GENERATE  THE POLISH POSTFIX FORM.
call ~~wait  200 %1
RIG.EXE EMPTY ~~DEMO_G.DAT
if errorlevel 5 ~~stop

rem ------------------------------------ 18
clear 14,0,1

color 14
big 1,,7,Try to write
big 7,,7,by yourself
box 15,,60,4,2
put 16,,YOU CAN MAKE COPY OF THIS DEMO PACKAGE.
put 17,,TRY TO RUN RIG.EXE WITH DIFFERENT EXAMPLES.
put 18,,    RIG.EXE  [ filename ]
put 19,,   default file is Work.rig
call ~~wait  200 %1




rem ------------------------------------ 19
clear 14,0,1

color 14
big 1,,7,CONTACT
color 15,1
box 6,,60,15,2
color 15,1
put 8,,RIGAL was designed in 1987-1992
put 9,,IN THE UNIVERSITY OF LATVIA
put 10,,by MIKHAIL AUGUSTON, VADIM ENGELSON and ANDRIS ZARINSH
color 15,0
put 12,,WE WOULD LIKE TO HAVE CONTACTS
put 13,,DEVOTED TO THE THEORY AND PRACTICE OF RIGAL.
put 14,,THE TOOL IS COMMERCIALLY AVAILABLE SINCE MIDDLE OF 1990.
color 15,1
put 16,,Contact:  Mikhail Auguston, Vadim Engelson
put 17,,e-mail:   vadim@lumii.lat.su
PUt 18,,University of Latvia, Institute of Mathematics,
put 19,,Rainis Boul. 29,       226250 RIGA LATVIA
put 20,,TELEX: 161172 TEMA SU          Phone:(0132)211014
call ~~wait  200 %1
remove > NUL