echo off
xtra
clear +cyan,black,blue
big 3,,7,University
big 12,,7,of
big 19,,7,Latvia
call ~~wait  60 %1
clear
big 9,,8,  PRESENTS
call ~~wait  35 %1
clear
big 1,,7,new programming
big 6,,7,language
call ~~wait  5 %1
color 12
big 16,,8,R{{{I{{{G{{{A{{{L
call ~~wait  60 %1
rem ---------------------------------------------- 1
clear
color 14

box 2,,50,16,2
put 3,,This is DEMO film about RIGAL.
put 4,,Contains 20 pages.
put 5,,You can SUSPEND it by pressing any key
put 6,,and CONTINUE by pressing "ENTER" key
put 8,,To change speed - run
put 9,,       DEMO 10 (fast)     or
put 10,,      DEMO 300 (low speed)
put 12,,DEMO is arranged for IBM/PC/XT/AT or compatible,
put 13,,with any graphic card;
put 14,,DEMO requires 400 KBytes free RAM.
put 16,,DEMO is not copy protected.
put 18,,Written by Vadim Engelson Univ. of Latvia RIGA
call ~~wait  170 %1

rem ---------------------------------------------- 2
clear 14,0,1

color 14
big 1,,7,Rigal assigned for
color 14,1
box 9,,40,13,2
call ~~wait  10 %1
color 15,1
put 10,,PARSING
put 12,,PROGRAM OPTIMIZATION
put 14,,CODE GENERATION
put 16,,STATIC ANALYSIS OF PROGRAMS
put 18,,PREPROCESSOR AND CONVERTOR WRITING
put 20,,PROGRAM TRANSFORMATION
call ~~wait  150 %1

rem --------------------------------------------- 3
clear 14,0,1
color 14

big 1,,7,Rigal data types are
color 14,0

box 7,5,20,2,2

color 15,1
put 8,9,ATOMS :
color 14,0
put 9,8,ABC  37  ':='

box 7,45,20,2,2
color 15,1
put 8,55,LISTS :
color 14,0
put 9,50, (. AA BB CC .)

box 12,27,25,8,2
color 15,1
put 13,,TREES :
color 14,0
put 14,29,. S1 : AB , S2 : CD .
put 14,28,12
put 14,50,14
color 15,0
put 16,, represents tree
put 17,,       / \
put 18,,   S1/     \S2
put 19,34,/
put 19,45,\
color 0,7
put 20,32,AB
put 20,46,CD
call ~~wait  200 %1

rem ------------------------------------------ 4
clear 14,0,1
color 14

big 1,,7,can manipulate with
color 14,1
box 7,,40,14,2
call ~~wait  10 %1
color 15,1
put 8,,VARIABLES
put 10,,are
color 14,0
put 12,,$AA     $SUMMA
color 15,1
put 14,,We assign them ANY value
color 14,0
put 16,, $SUMMA := 77+2 ;
put 18,, $NAME_OF_BOY := JOHN;
put 20,, $FR := (. AA BB CC .);
call ~~wait  130 %1

rem ------------------------------------------- 5
clear 14,0,1
color 14

big 1,,7,can operate with
color 14,1
box 7,,40,15,2
call ~~wait  10 %1
color 15,1
put 8,,L I S T S
put 10,,Adds element to list
color 14,0
put 11,,$FR := (. AA BB CC .)  !. DD;
color 15,1
put 12,,After the execution value of $FR is
color 14,0
put 13,, (. AA BB CC DD .);
color 15,1
put 15,,Takes element of list :
put 16,,  $FR [2]  is
color 14,0
put 17,, BB
color 15,1
put 19,, Concatenates :
put 20,, $FR !! (. KKK AA .)  is
color 14,0
put 21,, (. AA BB CC DD KKK AA .);
call ~~wait  200 %1

rem ------------------------------------------ 6
clear 14,0,1

color 14
big 1,,7,can operate with
color 14,1
box 7,,40,15,2
call ~~wait  10 %1
color 15,1
put 8,,T R E E S
color 14,0
put 10,,$M:=   . S1 :  AAA , S2 : BBB . ;
put 10,29,12
put 10,54,14
color 15,1
put 11,,Takes component of tree :
put 12,,Value of   $M.S1 is
color 14,0
put 13,, AAA
color 15,1
put 15,,Adds new branch to tree:
color 14,0
put 16,,$NEW := $M ++  . R2 : 33 .
put 16,41,12
put 16,53,14
color 15,1
put 17,, in result value of $NEW is
color 14,0
put 18,,  . S1 : AAA , S2 : BBB , R2 : 33 . ;
put 18,21,12
put 18,55,14
call ~~wait  220 %1

rem ---------------------------------------------- 7
clear 14,0,1

color 14
big 1,,7,P{{A{{R{{S{{I{{N{{G
color 14,1
box 7,,55,15,2
call ~~wait  10 %1
color 15,1
put 8,,For    P A R S I N G    we use
put 9,,PATTERNS.
put 11,,They  may  be  written  like
put 12,,BACKUS - NAUR    FORMULAE (BNF).

put 14,,If  SS  is  any  pattern  then
color 14,0
put 16,14,(* SS *)
put 18,14,(+ SS +)
put 20,14,[  SS  ]
put 22,14,(SS1 ! SS2)
color 15,1
put 16,33,0
put 16,35,or some times SS
put 18,33,1
put 18,35,or  some  times SS
put 20,33,SS   or    nothing
put 22,33,SS1  or   SS2
color 15,0
put 15,63,*
put 16,57,( SS )
put 17,65,+
put 18,59,( SS )
call ~~wait  180 %1

CALL ~~contin.BAT %1

rem ----------------------------------------- 8
clear 14,0,1
color 14

big 1,,7,R{{U{{L{{E
color 14,1
box 7,,53,15,2
call ~~wait  10 %1
color 15,1
put 8,,R U L E  is the main control tool in Rigal.
put 10,22, IN RIGAL :
put 10,43, IN PASCAL :
color 14,0

put 11,19,#SUMMA
put 12,23,   $A $B
put 13,23,   / $C := $A+$B ;
put 14,23,   RETURN $C   /
put 15,19,##
put 17,19, -- call of #SUMMA:
put 18,19, $E:=#SUMMA(5 6)
color 15,0
put 11,40, Function Summa
put 12,43,  (a:int;b:int):int;begin
put 13,43,  c:=a+b;
put 14,43,  Summa:=c;
put 15,40, end;
put 17,43,  { call of Summa }
put 18,40,  e:=Summa(5,6);
color 15,1
put 20,,Rule in RIGAL - like Function in PASCAL
call ~~wait  190 %1

rem ------------------------------------------- 9
clear 14,0,1

color 14
big 1,,2,list and tree
big 5,,2,patterns
color 14,1
box 10,,55,12,2
call ~~wait  10 %1
color 15,1
put 11,,WE CAN TRAVERSE LISTS :
color 14,0
put 13,20,#STATEMENT_LIST
put 14,25,(. (* #STATEMENT *) .)
put 15,20,##
color 15,1
put 16,,... AND TREES:
color 14,0
put 17,20,#EXPRESSION
put 18,25,[. OPERATION : ( '+' ! '-' ),
put 18,25,12
put 19,28,   ARGUMENT_1 : #FACTOR ,
put 20,28,   ARGUMENT_2 : #FACTOR  .]
put 20,51,14
put 21,20,##
call ~~wait  220 %1

rem --------------------------------------------- 10
clear 14,0,1
color 14

big 1,,7,T{{W{{O{{{{{R{{U{{L{{E{{S
color 14,1
box 7,,50,15,2
call ~~wait  10 %1
color 15,1
put 8,,R U L E   IS  like  BACKUS-NAUR FORMULA:
put 10,22,IN RIGAL
put 10,43,IN   B N F
color 14,0
put 11,17,#PROGRAM
put 12,20, 'BEGIN'
put 13,20, (* #STATEMENT *)
put 14,20, 'END'
put 15,17,##
put 16,17,#STATEMENT
put 17,20,  #VARIABLE
put 18,20,  ':='
put 19,20,  #EXPRESSION
put 20,17,##
color 15,0
put 11,40,program ::=
put 12,44,   'BEGIN'
put 12,56,*
put 13,47,      statement
put 14,44,   'END'
put 16,40,statement ::=
put 17,44,   variable
put 18,44,   ':='
put 19,44,   expression
color 15,1
put 21,,This is the way to
put 22,,describe and parse program structure
call ~~wait  150 %1


clear 14,0,1
big 1,,7,new programming
big 6,,7,language
call ~~wait  5 %1
color 12
big 16,,8,R{{{I{{{G{{{A{{{L
call ~~wait  60 %1
clear
color 14
big 1,,7,powerful
big 6,,7,and simple
big 12,,7,tool for writing
big 18,,7,compilers
call ~~wait  100 %1
call ~~demo %1