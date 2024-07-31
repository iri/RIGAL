
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
v loc3;/* $SUN*/ 
v loc4;/* $FL*/ 
v loc5;/* $FN*/ 
v loc6;/* $R*/ 
v loc7;/* $PROG*/ 
v loc10;/* $RIGLIB*/ 
v loc14;/* $PN*/ 
v wrk1;
v wrk2;
v wrk3;
v wrk4;
v wrk5;
v wrk6;
v wrk7;
v wrk8;
v wrk9;
v wrk10;
ptr_ pl1;
ptr_ pl2;
boolean flag1;
boolean flag2;
main(argc, argv) 
int argc;Char *argv[]; 
{ out = NULL;   
  g_argc=argc;  g_argv=argv; 
  prolog(argc,argv);  acon(); acop(); 
/* inicializaciq peremennyh */ 
glob1_5.sa=NULL;
glob1_8.sa=NULL;
loc3.sa=NULL;/* $SUN*/ 
loc4.sa=NULL;/* $FL*/ 
loc5.sa=NULL;/* $FN*/ 
loc6.sa=NULL;/* $R*/ 
loc7.sa=NULL;/* $PROG*/ 
glob1_1.sa=NULL;
glob1_3.sa=NULL;
loc10.sa=NULL;/* $RIGLIB*/ 
glob1_2.sa=NULL;
glob1_6.sa=NULL;
glob1_7.sa=NULL;
loc14.sa=NULL;/* $PN*/ 
glob1_4.sa=NULL;
/* inicializaciq LAST-perem.*/ 
glob3_1.sa=NULL;
glob3_2.sa=NULL;
glob3_3.sa=NULL;
glob10_1.sa=NULL;
glob10_2.sa=NULL;
glob10_3.sa=NULL;
glob10_4.sa=NULL;
glob15_1.sa=NULL;
glob24_1.sa=NULL;
glob24_2.sa=NULL;
glob24_3.sa=NULL;
glob30_1.sa=NULL;
glob71_1.sa=NULL;
opn(acnst[ 2 ], cnst[2] .sa ) ;xxx; 
outatm(acnst[2]," Starting...",true, true); ;xxx; 
/* operator := */ 
bltin(&wrk1,&flag1,cnst[1].sa,23L); 
glob1_5 .sa= wrk1 .sa ;xxx; 
/* IF-operator */ 
indxop( 1L,false,NULL, glob1_5 .sa ,& wrk1 .sa); 
/* operaciq = */ wrk2 .bo= eqatom( wrk1 .sa ,acnst[ 3 ]) ; 
if( wrk2 .bo) 
{ 
/* operator := */ 
glob1_8 .sa= cnst[1] .sa ;xxx; 
;} 
_L101:;xxx; 
/* IF-operator */ 
indxop( 1L,false,NULL, glob1_5 .sa ,& wrk1 .sa); 
/* operaciq = */ wrk2 .bo= eqatom( wrk1 .sa ,acnst[ 4 ]) ; 
if( wrk2 .bo) 
{ 
/* operator := */ 
loc3 .sa= cnst[1] .sa ;xxx; 
;} 
_L102:;xxx; 
/* operator := */ 
/* CALL_PAS */ 
use_16(cnst[3].sa,NULL,NULL,&wrk2.sa);; 
loc4 .sa= wrk2 .sa ;xxx; 
/* IF-operator */ 
wrk1 .bo= loc4 .sa==NULL; 
if( wrk1 .bo) 
{ 
outatm(acnst[2]," Compilation aborted - no file RIGCOMP.TMP ",true, true); ;xxx;
 
/* RETURN-op. */ 
rez1 = cnst[1] .sa ;goto _L98 ;xxx; 
;} 
_L103:;xxx; 
/* operator := */ 
wrk2 .sa=NULL; 
indxop( 1L,false,NULL, loc4 .sa ,& wrk1 .sa); 
lconc(& wrk2 .sa , wrk1 .sa ); 
lconc(& wrk2 .sa , cnst[4] .sa ); 
first(wrk2.sa,&pl1);implod(&pl1,&wrk2.sa); 
loc5 .sa= wrk2 .sa ;xxx; 
/* operator LOAD */ 
loasav(& loc6 , loc5 .sa, 0L 
) ;xxx; 
/* IF-operator */ 
wrk1 .bo= loc6 .sa==NULL; 
if( wrk1 .bo) 
{ 
outatm(acnst[2]," Compilation aborted - no file",true, true); 
outxt(acnst[ 2 ], loc5 .sa , false, true); ;xxx; 
/* RETURN-op. */ 
rez1 = cnst[1] .sa ;goto _L98 ;xxx; 
;} 
_L104:;xxx; 
/* operator := */ 
wrk2 .sa=NULL; 
indxop( 1L,false,NULL, loc4 .sa ,& wrk1 .sa); 
lconc(& wrk2 .sa , wrk1 .sa ); 
lconc(& wrk2 .sa , cnst[5] .sa ); 
first(wrk2.sa,&pl1);implod(&pl1,&wrk2.sa); 
loc5 .sa= wrk2 .sa ;xxx; 
/* operator LOAD */ 
loasav(& loc7 , loc5 .sa, 0L 
) ;xxx; 
/* IF-operator */ 
wrk1 .bo= loc7 .sa==NULL; 
if( wrk1 .bo) 
{ 
outatm(acnst[2]," Compilation aborted - no file",true, true); 
outxt(acnst[ 2 ], loc5 .sa , false, true); ;xxx; 
/* RETURN-op. */ 
rez1 = cnst[1] .sa ;goto _L98 ;xxx; 
;} 
_L105:;xxx; 
/* CALL_PAS */ 
mknumb( 1L,& wrk2 .sa); 
/* CALL_PAS */ 
use_34(NULL,NULL,NULL,&wrk4.sa);; 
use_25(wrk2.sa,wrk4.sa,NULL,&wrk5.sa);;xxx; 
/* CALL_PAS */ 
wrk3 .sa=NULL; 
lconc(& wrk3 .sa , cnst[6] .sa ); 
indxop( 1L,false,NULL, loc4 .sa ,& wrk2 .sa); 
lconc(& wrk3 .sa , wrk2 .sa ); 
first(wrk3.sa,&pl2);implod(&pl2,&wrk3.sa); 
use_30(wrk3.sa,NULL,NULL,&wrk4.sa);;xxx; 
/* CALL_PAS */ 
use_28(NULL,NULL,NULL,&wrk2.sa);;xxx; 
/* operator := */ 
wrk7 .sa =NULL; 
indxop( 1L,false,NULL, loc4 .sa ,& wrk1 .sa); 
lconc(& wrk7 .sa , wrk1 .sa ); 
indxop( 1L,false,NULL, loc4 .sa ,& wrk2 .sa); 
lconc(& wrk7 .sa , wrk2 .sa ); 
mknumb( 0L,& wrk3 .sa); 
lconc(& wrk7 .sa , wrk3 .sa ); 
bltin(&wrk4,&flag1,loc4.sa,15L); 
wrk5 .nu= wrk4 .nu - 1L ; 
mknumb( wrk5 .nu ,& wrk6 .sa); 
lconc(& wrk7 .sa , wrk6 .sa ); 
glob1_5 .sa= wrk7 .sa ;xxx; 
/* operator := */ 
selop( acnst[ 5 ],false,NULL, loc6 .sa ,& wrk1 .sa); 
glob1_1 .sa= wrk1 .sa ;xxx; 
/* operator := */ 
selop( acnst[ 6 ],false,NULL, loc6 .sa ,& wrk1 .sa); 
glob1_3 .sa= wrk1 .sa ;xxx; 
/* operator := */ 
selop( acnst[ 7 ],false,NULL, loc6 .sa ,& wrk1 .sa); 
loc10 .sa= wrk1 .sa ;xxx; 
/* operator := */ 
selop( acnst[ 8 ],false,NULL, loc6 .sa ,& wrk1 .sa); 
glob1_2 .sa= wrk1 .sa ;xxx; 
/* operator := */ 
selop( acnst[ 9 ],false,NULL, loc6 .sa ,& wrk1 .sa); 
glob1_6 .sa= wrk1 .sa ;xxx; 
/* operator := */ 
selop( acnst[ 10 ],false,NULL, loc6 .sa ,& wrk1 .sa); 
glob1_7 .sa= wrk1 .sa ;xxx; 
/* CALL #L */ 
pl1.ptrtype=ptrlist;pl1.nel=0;pl1.cel=NULL;
r53(&wrk1.sa,&flag1,&pl1);/* #G_COMMON_PART*/ ;xxx; 
/* CALL #L */ 
pl1.ptrtype=packedlist;pl1.nel=1;pl1.cel=glob1_6.sa;
pl1.UU.plistelt[ 0 ]=glob1_7.sa;
pl1.plistsize= 2;
r51(&wrk1.sa,&flag1,&pl1);/* #GEN_ATOM_INITIALIZATION*/ ;xxx; 
/* CALL #L */ 
pl1.ptrtype=packedlist;pl1.nel=1;pl1.cel=cnst[7].sa;
indxop( 1L,false,NULL, loc7 .sa ,& wrk1 .sa); 
pl1.UU.plistelt[ 0 ]=wrk1.sa;
pl1.plistsize= 2;
r24(&wrk2.sa,&flag1,&pl1);/* #G_programma*/ ;xxx; 
/* CALL #L */ 
pl1.ptrtype=packedlist;pl1.nel=1;pl1.cel=cnst[8].sa;
pl1.UU.plistelt[ 0 ]=loc7.sa;
pl1.plistsize= 2;
r24(&wrk1.sa,&flag1,&pl1);/* #G_programma*/ ;xxx; 
/* operator := */ 
mknumb( 1L,& wrk2 .sa); 
setsel( acnst[ 11 ],false,NULL, loc6 .sa , wrk2 .sa ) ;xxx; 
/*LOOP*/while (true) { 
/* operator +:= */ 
selop( acnst[ 11 ],false,NULL, loc6 .sa ,& wrk1 .sa);addnum(& wrk1 .sa, 1L 
);setsel( acnst[ 11 ],false,NULL, loc6 .sa , wrk1 .sa) ;xxx; 
/* IF-operator */ 
selop( acnst[ 11 ],false,NULL, loc6 .sa ,& wrk1 .sa); 
selop( acnst[ 12 ],false,NULL, loc6 .sa ,& wrk2 .sa); 
bltin(&wrk3,&flag1,wrk2.sa,15L); 
wrk4 .bo= numval( wrk1 .sa) > wrk3 .nu ; 
if( wrk4 .bo) 
{ 
/*BREAK*/ goto _L109;xxx; 
;} 
_L106:;xxx; 
/* IF-operator */ 
/* CALL_PAS */ 
use_46(cnst[1].sa,NULL,NULL,&wrk2.sa);; 
wrk3 .bo= wrk2 .sa==NULL; 
if( wrk3 .bo) 
{ 
/* operator := */ 
/* CALL_PAS */ 
use_45(loc6.sa,NULL,NULL,&wrk2.sa);; 
loc6 .sa= wrk2 .sa ;xxx; 
/* CALL_PAS */ 
/* USER:*/ acon();  ;xxx; 
;} 
_L107:;xxx; 
/* operator := */ 
selop( acnst[ 12 ],false,NULL, loc6 .sa ,& wrk1 .sa); 
selop( acnst[ 11 ],false,NULL, loc6 .sa ,& wrk2 .sa); 
indxop( 0L,true, wrk2 .sa, wrk1 .sa ,& wrk3 .sa); 
loc14 .sa= wrk3 .sa ;xxx; 
/* operator := */ 
wrk1 .sa=NULL; 
lconc(& wrk1 .sa , loc14 .sa ); 
lconc(& wrk1 .sa , cnst[5] .sa ); 
first(wrk1.sa,&pl1);implod(&pl1,&wrk1.sa); 
loc5 .sa= wrk1 .sa ;xxx; 
/* operator LOAD */ 
loasav(& loc7 , loc5 .sa, 0L 
) ;xxx; 
/* IF-operator */ 
wrk1 .bo= loc7 .sa==NULL; 
if( wrk1 .bo) 
{ 
outatm(acnst[2]," Compilation aborted - no file",true, true); 
outxt(acnst[ 2 ], loc5 .sa , false, true); ;xxx; 
/* RETURN-op. */ 
rez1 = cnst[1] .sa ;goto _L98 ;xxx; 
;} 
_L108:;xxx; 
wrk5 .sa=NULL; 
lconc(& wrk5 .sa , cnst[10] .sa ); 
lconc(& wrk5 .sa , loc14 .sa ); 
lconc(& wrk5 .sa , cnst[11] .sa ); 
selop( acnst[ 11 ],false,NULL, loc6 .sa ,& wrk1 .sa); 
lconc(& wrk5 .sa , wrk1 .sa ); 
lconc(& wrk5 .sa , cnst[12] .sa ); 
selop( acnst[ 12 ],false,NULL, loc6 .sa ,& wrk2 .sa); 
bltin(&wrk3,&flag2,wrk2.sa,15L); 
mknumb( wrk3 .nu ,& wrk4 .sa); 
lconc(& wrk5 .sa , wrk4 .sa ); 
lconc(& wrk5 .sa , cnst[13] .sa ); 
first(wrk5.sa,&pl1);implod(&pl1,&wrk5.sa); 
outxt(acnst[ 2 ], wrk5 .sa , true, true); ;xxx; 
/* operator := */ 
wrk10 .sa =NULL; 
selop( acnst[ 12 ],false,NULL, loc6 .sa ,& wrk1 .sa); 
indxop( 1L,false,NULL, wrk1 .sa ,& wrk2 .sa); 
lconc(& wrk10 .sa , wrk2 .sa ); 
lconc(& wrk10 .sa , loc14 .sa ); 
selop( acnst[ 11 ],false,NULL, loc6 .sa ,& wrk3 .sa); 
wrk4 .nu= numval( wrk3 .sa) - 1L ; 
mknumb( wrk4 .nu ,& wrk5 .sa); 
lconc(& wrk10 .sa , wrk5 .sa ); 
selop( acnst[ 12 ],false,NULL, loc6 .sa ,& wrk6 .sa); 
bltin(&wrk7,&flag1,wrk6.sa,15L); 
wrk8 .nu= wrk7 .nu - 1L ; 
mknumb( wrk8 .nu ,& wrk9 .sa); 
lconc(& wrk10 .sa , wrk9 .sa ); 
glob1_5 .sa= wrk10 .sa ;xxx; 
/* operator := */ 
selop( acnst[ 5 ],false,NULL, loc6 .sa ,& wrk1 .sa); 
glob1_1 .sa= wrk1 .sa ;xxx; 
/* operator := */ 
selop( acnst[ 6 ],false,NULL, loc6 .sa ,& wrk1 .sa); 
glob1_3 .sa= wrk1 .sa ;xxx; 
/* operator := */ 
selop( acnst[ 7 ],false,NULL, loc6 .sa ,& wrk1 .sa); 
loc10 .sa= wrk1 .sa ;xxx; 
/* operator := */ 
selop( acnst[ 8 ],false,NULL, loc6 .sa ,& wrk1 .sa); 
glob1_2 .sa= wrk1 .sa ;xxx; 
/* operator := */ 
selop( acnst[ 9 ],false,NULL, loc6 .sa ,& wrk1 .sa); 
glob1_6 .sa= wrk1 .sa ;xxx; 
/* operator := */ 
selop( acnst[ 10 ],false,NULL, loc6 .sa ,& wrk1 .sa); 
glob1_7 .sa= wrk1 .sa ;xxx; 
/* CALL #L */ 
pl1.ptrtype=packedlist;pl1.nel=1;pl1.cel=cnst[14].sa;
pl1.UU.plistelt[ 0 ]=loc7.sa;
pl1.plistsize= 2;
r24(&wrk1.sa,&flag1,&pl1);/* #G_programma*/ ;xxx; 
;};  _L109:/*END LOOP*/;xxx; 
   _L98:; 
   _L99: epilog(); 
 if(out!=NULL) fclose(out);exit(0); 
 }  
