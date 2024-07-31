
/* ****************************************** */ 
/*      rigal/pascal compiler                 */ 
/*  vax/vms & omsi/rsx & ms/dos & ms-windows  */ 
/*  & unix/sun         v 2.42/4.45 february 1996    */ 
/*      author M.Auguston,Riga                */ 
/*  adaptation by V.Engelson ,Riga            */ 
/*  sponsored by P.Fritzson, Linkoping        */ 
/*  IMCS University of Latvia ,Riga (c) 1987-1996  */ 
/*  IDA Linkoping  University, Sweden         */ 
/* ****************************************** */ 
#include "globrig.h"  
#include "define.h"   
#include "defpage.h"  
#include "nef2.h"     
#include "c1.h"       
#include "usemod.h"   
#include "def180.h"   
#include "xcrg.h"     
#include "xcrga.h"    
a rez1;boolean success1;long k;mpd x; 
v loc1;/* $glavn*/ 
v loc2;/* $FL*/ 
v loc3;/* $FN*/ 
v loc4;/* $L*/ 
v loc5;/* $PROG*/ 
v loc6;/* $RULENUM*/ 
v loc8;/* $REZ*/ 
v loc13;/* $PN*/ 
v wrk1;
v wrk2;
v wrk3;
v wrk4;
v wrk5;
v wrk6;
v wrk7;
ptr_ pl1;
boolean flag1;
boolean flag2;
main(argc, argv) 
int argc;Char *argv[]; 
{ out = NULL;   
  g_argc=argc;  g_argv=argv; 
  prolog(argc,argv);  acon(); acop(); 
/* inicializaciq peremennyh */ 
loc1.sa=NULL;/* $glavn*/ 
loc2.sa=NULL;/* $FL*/ 
loc3.sa=NULL;/* $FN*/ 
loc4.sa=NULL;/* $L*/ 
loc5.sa=NULL;/* $PROG*/ 
loc6.sa=NULL;/* $RULENUM*/ 
glob1_3.sa=NULL;
loc8.sa=NULL;/* $REZ*/ 
glob1_5.sa=NULL;
glob1_1.sa=NULL;
glob1_6.sa=NULL;
glob1_2.sa=NULL;
loc13.sa=NULL;/* $PN*/ 
glob1_4.sa=NULL;
/* inicializaciq LAST-perem.*/ 
glob2_1.sa=NULL;
glob2_2.sa=NULL;
glob2_3.sa=NULL;
glob2_4.sa=NULL;
glob2_5.sa=NULL;
glob2_6.sa=NULL;
glob2_7.sa=NULL;
glob2_8.sa=NULL;
glob24_1.sa=NULL;
glob24_2.sa=NULL;
glob26_1.sa=NULL;
glob3_1.sa=NULL;
opn(acnst[ 2 ], cnst[2] .sa ) ;xxx; 
/* operator := */ 
loc1 .sa= cnst[1] .sa ;xxx; 
/* operator := */ 
/* CALL_PAS */ 
use_16(cnst[3].sa,NULL,NULL,&wrk2.sa);; 
loc2 .sa= wrk2 .sa ;xxx; 
/* IF-operator */ 
wrk1 .bo= loc2 .sa==NULL; 
if( wrk1 .bo) 
{ 
outatm(acnst[2]," Compilation aborted - no file RIGCOMP.TMP ",true, true); ;xxx;
 
/* RETURN-op. */ 
rez1 = cnst[1] .sa ;goto _L98 ;xxx; 
;} 
_L101:;xxx; 
/* operator := */ 
wrk2 .sa=NULL; 
indxop( 1L,false,NULL, loc2 .sa ,& wrk1 .sa); 
lconc(& wrk2 .sa , wrk1 .sa ); 
lconc(& wrk2 .sa , cnst[4] .sa ); 
first(wrk2.sa,&pl1);implod(&pl1,&wrk2.sa); 
loc3 .sa= wrk2 .sa ;xxx; 
/* operator := */ 
/* CALL_PAS */ 
use_15(loc3.sa,NULL,NULL,&wrk2.sa);; 
loc4 .sa= wrk2 .sa ;xxx; 
/* IF-operator */ 
wrk1 .bo= loc4 .sa==NULL; 
if( wrk1 .bo) 
{ 
outatm(acnst[2]," Compilation aborted - no file ",true, true); 
outxt(acnst[ 2 ], loc3 .sa , false, true); ;xxx; 
/* RETURN-op. */ 
rez1 = cnst[1] .sa ;goto _L98 ;xxx; 
;} 
_L102:;xxx; 
wrk3 .sa=NULL; 
lconc(& wrk3 .sa , cnst[5] .sa ); 
lconc(& wrk3 .sa , loc3 .sa ); 
lconc(& wrk3 .sa , cnst[6] .sa ); 
bltin(&wrk1,&flag2,loc4.sa,15L); 
mknumb( wrk1 .nu ,& wrk2 .sa); 
lconc(& wrk3 .sa , wrk2 .sa ); 
lconc(& wrk3 .sa , cnst[7] .sa ); 
first(wrk3.sa,&pl1);implod(&pl1,&wrk3.sa); 
outxt(acnst[ 2 ], wrk3 .sa , true, true); ;xxx; 
/* operator := */ 
/* CALL #L */ 
pl1.ptrtype=packedlist;pl1.nel=1;pl1.cel=cnst[8].sa;
pl1.UU.plistelt[ 0 ]=loc4.sa;
pl1.plistsize= 2;
r2(&wrk1.sa,&flag1,&pl1);/* #programma*/ ; 
loc5 .sa= wrk1 .sa ;xxx; 
/* operator := */ 
/* CALL #L */ 
pl1.ptrtype=packedlist;pl1.nel=1;pl1.cel=glob1_3.sa;
pl1.plistsize= 1;
r45(&wrk1.sa,&flag1,&pl1);/* #RULENUM*/ ; 
loc6 .sa= wrk1 .sa ;xxx; 
/* operator SAVE */ 
wrk2 .sa=NULL; 
indxop( 1L,false,NULL, loc2 .sa ,& wrk1 .sa); 
lconc(& wrk2 .sa , wrk1 .sa ); 
lconc(& wrk2 .sa , cnst[9] .sa ); 
first(wrk2.sa,&pl1);implod(&pl1,&wrk2.sa); 
loasav(& loc5 , wrk2 .sa, 1L 
) ;xxx; 
/* operator := */ 
wrk4 .sa =NULL; 
addel( acnst[ 3 ],false,NULL, loc2 .sa ,& wrk4 .sa ); 
bltin(&wrk1,&flag1,loc4.sa,15L); 
mknumb( wrk1 .nu ,& wrk2 .sa); 
addel( acnst[ 4 ],false,NULL, wrk2 .sa ,& wrk4 .sa ); 
mknumb( 1L,& wrk3 .sa); 
addel( acnst[ 5 ],false,NULL, wrk3 .sa ,& wrk4 .sa ); 
loc8 .sa= wrk4 .sa ;xxx; 
/*LOOP*/while (true) { 
/* operator ++:= */ 
wrk1 = loc8 ; 
addel( acnst[ 6 ],false,NULL, glob1_3 .sa ,& loc8 .sa); 
addel( acnst[ 7 ],false,NULL, loc6 .sa ,& loc8 .sa); 
addel( acnst[ 8 ],false,NULL, glob1_5 .sa ,& loc8 .sa); 
addel( acnst[ 9 ],false,NULL, glob1_1 .sa ,& loc8 .sa); 
addel( acnst[ 10 ],false,NULL, glob1_6 .sa ,& loc8 .sa); 
addel( acnst[ 11 ],false,NULL, glob1_2 .sa ,& loc8 .sa); ;xxx; 
/* operator +:= */ 
selop( acnst[ 5 ],false,NULL, loc8 .sa ,& wrk1 .sa);addnum(& wrk1 .sa, 1L 
);setsel( acnst[ 5 ],false,NULL, loc8 .sa , wrk1 .sa) ;xxx; 
/* IF-operator */ 
selop( acnst[ 5 ],false,NULL, loc8 .sa ,& wrk1 .sa); 
selop( acnst[ 3 ],false,NULL, loc8 .sa ,& wrk2 .sa); 
bltin(&wrk3,&flag1,wrk2.sa,15L); 
wrk4 .bo= numval( wrk1 .sa) > wrk3 .nu ; 
if( wrk4 .bo) 
{ 
/*BREAK*/ goto _L106;xxx; 
;} 
_L103:;xxx; 
/* IF-operator */ 
/* CALL_PAS */ 
use_46(cnst[1].sa,NULL,NULL,&wrk2.sa);; 
wrk3 .bo= wrk2 .sa==NULL; 
if( !( wrk3 .bo )) wrk7 .bo=false; else { 
bltin(&wrk4,&flag1,cnst[1].sa,23L); 
indxop( 1L,false,NULL, wrk4 .sa ,& wrk5 .sa); 
/* operaciq = */ wrk6 .bo= eqatom( wrk5 .sa ,acnst[ 12 ]) ; wrk7 = wrk6 
;}/*log*/; 
if( wrk7 .bo) 
{ 
if (out_screen) {pscr( cnst[10] .sa);putchar('\n');} else { pout( cnst[10] 
.sa);putc('\n',out);}  ;xxx; 
/* operator := */ 
/* CALL_PAS */ 
use_45(loc8.sa,NULL,NULL,&wrk2.sa);; 
loc8 .sa= wrk2 .sa ;xxx; 
/* CALL_PAS */ 
/* USER:*/ acon();  ;xxx; 
;} 
_L104:;xxx; 
/* operator := */ 
selop( acnst[ 3 ],false,NULL, loc8 .sa ,& wrk1 .sa); 
selop( acnst[ 5 ],false,NULL, loc8 .sa ,& wrk2 .sa); 
indxop( 0L,true, wrk2 .sa, wrk1 .sa ,& wrk3 .sa); 
loc13 .sa= wrk3 .sa ;xxx; 
/* operator := */ 
wrk1 .sa=NULL; 
lconc(& wrk1 .sa , loc13 .sa ); 
lconc(& wrk1 .sa , cnst[4] .sa ); 
first(wrk1.sa,&pl1);implod(&pl1,&wrk1.sa); 
loc3 .sa= wrk1 .sa ;xxx; 
/* operator := */ 
/* CALL_PAS */ 
use_15(loc3.sa,NULL,NULL,&wrk2.sa);; 
loc4 .sa= wrk2 .sa ;xxx; 
/* IF-operator */ 
wrk1 .bo= loc4 .sa==NULL; 
if( wrk1 .bo) 
{ 
outatm(acnst[2]," Compilation aborted - no file ",true, true); 
outxt(acnst[ 2 ], loc3 .sa , false, true); ;xxx; 
/* RETURN-op. */ 
rez1 = cnst[1] .sa ;goto _L98 ;xxx; 
;} 
_L105:;xxx; 
wrk7 .sa=NULL; 
lconc(& wrk7 .sa , cnst[12] .sa ); 
lconc(& wrk7 .sa , loc3 .sa ); 
lconc(& wrk7 .sa , cnst[13] .sa ); 
bltin(&wrk1,&flag2,loc4.sa,15L); 
mknumb( wrk1 .nu ,& wrk2 .sa); 
lconc(& wrk7 .sa , wrk2 .sa ); 
lconc(& wrk7 .sa , cnst[14] .sa ); 
selop( acnst[ 5 ],false,NULL, loc8 .sa ,& wrk3 .sa); 
lconc(& wrk7 .sa , wrk3 .sa ); 
lconc(& wrk7 .sa , cnst[15] .sa ); 
selop( acnst[ 3 ],false,NULL, loc8 .sa ,& wrk4 .sa); 
bltin(&wrk5,&flag2,wrk4.sa,15L); 
mknumb( wrk5 .nu ,& wrk6 .sa); 
lconc(& wrk7 .sa , wrk6 .sa ); 
lconc(& wrk7 .sa , cnst[16] .sa ); 
first(wrk7.sa,&pl1);implod(&pl1,&wrk7.sa); 
outxt(acnst[ 2 ], wrk7 .sa , true, true); ;xxx; 
/* operator +:= */ 
bltin(&wrk2,&flag1,loc4.sa,15L); 
selop( acnst[ 4 ],false,NULL, loc8 .sa ,& wrk1 .sa);addnum(& wrk1 .sa, wrk2 .nu 
);setsel( acnst[ 4 ],false,NULL, loc8 .sa , wrk1 .sa) ;xxx; 
/* operator := */ 
loc1 .sa= NULL ;xxx; 
/* operator := */ 
selop( acnst[ 6 ],false,NULL, loc8 .sa ,& wrk1 .sa); 
glob1_3 .sa= wrk1 .sa ;xxx; 
/* operator := */ 
selop( acnst[ 8 ],false,NULL, loc8 .sa ,& wrk1 .sa); 
glob1_5 .sa= wrk1 .sa ;xxx; 
/* operator := */ 
selop( acnst[ 9 ],false,NULL, loc8 .sa ,& wrk1 .sa); 
glob1_1 .sa= wrk1 .sa ;xxx; 
/* operator := */ 
selop( acnst[ 11 ],false,NULL, loc8 .sa ,& wrk1 .sa); 
glob1_2 .sa= wrk1 .sa ;xxx; 
/* operator := */ 
selop( acnst[ 10 ],false,NULL, loc8 .sa ,& wrk1 .sa); 
glob1_6 .sa= wrk1 .sa ;xxx; 
/* operator := */ 
/* CALL #L */ 
pl1.ptrtype=packedlist;pl1.nel=1;pl1.cel=cnst[17].sa;
pl1.UU.plistelt[ 0 ]=loc4.sa;
pl1.plistsize= 2;
r2(&wrk1.sa,&flag1,&pl1);/* #programma*/ ; 
loc5 .sa= wrk1 .sa ;xxx; 
/* operator := */ 
/* CALL #L */ 
pl1.ptrtype=packedlist;pl1.nel=1;pl1.cel=glob1_3.sa;
pl1.plistsize= 1;
r45(&wrk1.sa,&flag1,&pl1);/* #RULENUM*/ ; 
loc6 .sa= wrk1 .sa ;xxx; 
/* operator SAVE */ 
wrk1 .sa=NULL; 
lconc(& wrk1 .sa , loc13 .sa ); 
lconc(& wrk1 .sa , cnst[9] .sa ); 
first(wrk1.sa,&pl1);implod(&pl1,&wrk1.sa); 
loasav(& loc5 , wrk1 .sa, 1L 
) ;xxx; 
;};  _L106:/*END LOOP*/;xxx; 
wrk5 .sa=NULL; 
lconc(& wrk5 .sa , cnst[18] .sa ); 
selop( acnst[ 4 ],false,NULL, loc8 .sa ,& wrk1 .sa); 
lconc(& wrk5 .sa , wrk1 .sa ); 
lconc(& wrk5 .sa , cnst[19] .sa ); 
selop( acnst[ 3 ],false,NULL, loc8 .sa ,& wrk2 .sa); 
bltin(&wrk3,&flag2,wrk2.sa,15L); 
mknumb( wrk3 .nu ,& wrk4 .sa); 
lconc(& wrk5 .sa , wrk4 .sa ); 
lconc(& wrk5 .sa , cnst[20] .sa ); 
first(wrk5.sa,&pl1);implod(&pl1,&wrk5.sa); 
outxt(acnst[ 2 ], wrk5 .sa , true, true); ;xxx; 
/* operator SAVE */ 
wrk3 .sa=NULL; 
selop( acnst[ 3 ],false,NULL, loc8 .sa ,& wrk1 .sa); 
indxop( 1L,false,NULL, wrk1 .sa ,& wrk2 .sa); 
lconc(& wrk3 .sa , wrk2 .sa ); 
lconc(& wrk3 .sa , cnst[21] .sa ); 
first(wrk3.sa,&pl1);implod(&pl1,&wrk3.sa); 
loasav(& loc8 , wrk3 .sa, 2L 
) ;xxx; 
   _L98:; 
   _L99: epilog(); 
 if(out!=NULL) fclose(out);exit(0); 
 }  
