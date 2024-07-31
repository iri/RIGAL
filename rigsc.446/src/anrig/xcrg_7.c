
#include "globrig.h" 
#include "define.h"  
#include "defpage.h" 
#include "nef2.h"    
#include "c1.h"      
#include "usemod.h"  
#include "def180.h"  
#include "xcrg.h"    
/*  R24 prawilo */ 
/*  R25 END_OF_BRANCH */ 
/*  R26 prostoe_prawilo */ 
/*  R27 PLO */ 
/*  R28 dejstwiq */ 
/*  R29 SEMICOLON */ 
/*  R30 operator */ 
/*  R31 operator1 */ 
/*  R32 ONE_ATOM */ 
/*===============================================*/ 
/* GENERATED TEXT OF RULE   #prawilo   */ 
 Void r24(rez,success,pl)
long *rez;boolean *success;ptr_ *pl; 
{  a rez1;  boolean success1; long k; mpd x; 
v loc2;/* $E*/ 
v wrk1;
v wrk2;
v oldglob24_1;
v oldglob24_2;
ptr_ pl1;
ptr_ pl2;
boolean flag1;
#ifdef XX  
 d(1,"prawilo", 24 ,pl->cel,0); 
#endif 
/* sohranitx GLOB */ 
oldglob24_1=glob24_1;
oldglob24_2=glob24_2;

/* branch */ pl1=*pl;rez1=NULL;success1=true; 
/* inicializaciq peremennyh */ 
glob24_2.sa=NULL;
loc2.sa=NULL;/* $E*/ 
glob24_1.sa=NULL;

glob24_2 .sa=NULL; 

bltin1(&rez1,&success1,&pl1,16L);
if( !success1 ) goto _L103;
glob24_2 .sa=rez1; 

/* operator := */ 
mknumb( 0L,& wrk1 .sa); 
glob2_1 .sa= wrk1 .sa ;xxx; 

/* operator := */ 
mknumb( 0L,& wrk1 .sa); 
glob2_2 .sa= wrk1 .sa ;xxx; 

/* operator := */ 
mknumb( 0L,& wrk1 .sa); 
glob2_7 .sa= wrk1 .sa ;xxx; 

/* operator := */ 
mknumb( 0L,& wrk1 .sa); 
glob2_8 .sa= wrk1 .sa ;xxx; 

/* operator := */ 
mknumb( 1L,& wrk1 .sa); 
glob2_3 .sa= wrk1 .sa ;xxx; 

/* operator := */ 
mknumb( 1L,& wrk1 .sa); 
glob2_4 .sa= wrk1 .sa ;xxx; 

/* operator := */ 
glob2_5 .sa= glob24_2 .sa ;xxx; 

/* operator := */ 
mknumb( 100L,& wrk1 .sa); 
glob2_6 .sa= wrk1 .sa ;xxx; 

/* CALL #L */ 
pl2.ptrtype=packedlist;pl2.nel=1;pl2.cel=glob24_2.sa;
pl2.plistsize= 1;
r38(&wrk1.sa,&flag1,&pl2);/* #TAB*/ ;xxx; 

/*shablon STARLIST */ 
 pl2=pl1;while(pl1.nel!=0 ) { 


/* shablon prawila */ r26(&rez1,&success1,&pl1);
if( !success1 ) goto _L102;
lconc(& loc2 .sa,rez1); 
 pl2=pl1;

/* shablon prawila */ r25(&rez1,&success1,&pl1);
if( !success1 ) goto _L101;
;}; 
_L102:if( ! success1 )pl1=pl2;
_L101:;
success1 = true ; 

/* shablon VPAT */ 
wrk1.sa=pl1.cel;
/* operaciq = */ wrk2 .bo= eqatom( wrk1 .sa ,acnst[ 16 ]) ; 
success1= wrk2 .bo ;if( success1 ) { 
rez1=pl1.cel;
   ;} else { rez1=NULL;goto _L103 ;};

/* shablon SPAT */ 
if( pl1.nel==0 ) { success1=false;goto _L103 ;};
wrk1.sa=pl1.cel;
bltin(&wrk2,&flag1,wrk1.sa,10L); 
success1= wrk2 .sa!=NULL ;if( success1 ) { 
rez1=pl1.cel;
if( pl1.ptrtype!=ptrtree ) next(&pl1);
   ;} else { rez1=NULL;goto _L103 ;};

/* RETURN-op. */ 
wrk1 .sa =NULL; 
addel( acnst[ 17 ],false,NULL, glob2_2 .sa ,& wrk1 .sa ); 
addel( acnst[ 20 ],false,NULL, glob2_6 .sa ,& wrk1 .sa ); 
addel( acnst[ 19 ],false,NULL, glob2_7 .sa ,& wrk1 .sa ); 
addel( acnst[ 118 ],false,NULL, glob24_1 .sa ,& wrk1 .sa ); 
addel( acnst[ 18 ],false,NULL, glob2_3 .sa ,& wrk1 .sa ); 
addel( acnst[ 21 ],false,NULL, loc2 .sa ,& wrk1 .sa ); 
/* operaciq :: */ wrk2 .sa=NULL; 
if( wrk1 .sa!=NULL ) { points( wrk1 .sa,&x.sa); 
x.smtd->name= glob24_2 .sa ; wrk2 = wrk1 ;}; 
rez1 = wrk2 .sa ;goto _L98 ;xxx; 
goto _L99;  _L103:;  /* metka wyhoda po neuspehu wetwi */

/* branch */ pl1=*pl;rez1=NULL;success1=true; 
/* inicializaciq peremennyh */ 
glob24_2.sa=NULL;
glob24_1.sa=NULL;

outatm(acnst[2],"ERROR : COMPILATION ERROR IN RIGAL, RULE #",true, false); 
outxt(acnst[ 2 ], glob24_2 .sa , false, false); 
outatm(acnst[2]," NUMBER ",false, true); 
bltin(&wrk1,&flag1,glob1_3.sa,15L); 
mknumb( wrk1 .nu ,& wrk2 .sa); 
outxt(acnst[ 2 ], wrk2 .sa , false, true); ;xxx; 

outatm(acnst[2],"        TRY CHECK IT",true, true); ;xxx; 

/* operator +:= */ 
addnum(& glob1_4 .sa, 1L ) ;xxx; 

/* IF-operator */ 
wrk1 .bo= numval( glob1_4 .sa) > 3L ; 
if( wrk1 .bo) 
{ 
outatm(acnst[2],"COMPILATION ABORTED - TOO MUCH (>2) ERRORS",true, true); ;xxx; 
/* FAIL */ rez1=NULL;success1=false; 
if (pl1.ptrtype!=ptrtree) next(&pl1); /*wyhod iz der.ili sp.*/ 
goto _L105;xxx; 
;} 
_L104:;xxx; 
goto _L99;  _L105:;  /* metka wyhoda po neuspehu wetwi */
 _L99: rez1=NULL; 
 _L98: *rez=rez1;*success=success1; 
 if (*success) *pl=pl1; /* prodwinutx ukazatelx leksem */ 
/* wosstanowitx GLOB */ 
glob24_1=oldglob24_1;
glob24_2=oldglob24_2;
#ifdef XX  
 d(2,"prawilo", 24 ,*rez,*success); 
#endif 
;};/* RULE */ 
/*===============================================*/ 
/* GENERATED TEXT OF RULE   #END_OF_BRANCH   */ 
 Void r25(rez,success,pl)
long *rez;boolean *success;ptr_ *pl; 
{  a rez1;  boolean success1; long k; mpd x; 
v wrk1;
v wrk2;
ptr_ pl1;
#ifdef XX  
 d(1,"END_OF_BRANCH", 25 ,pl->cel,0); 
#endif 
/* sohranitx GLOB */ 

/* branch */ pl1=*pl;rez1=NULL;success1=true; 
/* inicializaciq peremennyh */ 

/* shablon VPAT */ 
wrk1.sa=pl1.cel;
/* operaciq = */ wrk2 .bo= eqatom( wrk1 .sa ,acnst[ 119 ]) ; 
success1= wrk2 .bo ;if( success1 ) { 
rez1=pl1.cel;
   ;} else { rez1=NULL;goto _L101 ;};

bltin1(&rez1,&success1,&pl1,10L);
if( !success1 ) goto _L101;
goto _L99;  _L101:;  /* metka wyhoda po neuspehu wetwi */
 _L99: rez1=NULL; 
 _L98: *rez=rez1;*success=success1; 
 if (*success) *pl=pl1; /* prodwinutx ukazatelx leksem */ 
/* wosstanowitx GLOB */ 
#ifdef XX  
 d(2,"END_OF_BRANCH", 25 ,*rez,*success); 
#endif 
;};/* RULE */ 
/*===============================================*/ 
/* GENERATED TEXT OF RULE   #prostoe_prawilo   */ 
 Void r26(rez,success,pl)
long *rez;boolean *success;ptr_ *pl; 
{  a rez1;  boolean success1; long k; mpd x; 
v loc1;/* $E*/ 
v loc2;/* $ONFAIL*/ 
v wrk1;
v wrk2;
v oldglob26_1;
ptr_ pl1;
ptr_ pl2;
ptr_ pl3;
boolean flag1;
#ifdef XX  
 d(1,"prostoe_prawilo", 26 ,pl->cel,0); 
#endif 
/* sohranitx GLOB */ 
oldglob26_1=glob26_1;

/* branch */ pl1=*pl;rez1=NULL;success1=true; 
/* inicializaciq peremennyh */ 
loc1.sa=NULL;/* $E*/ 
loc2.sa=NULL;/* $ONFAIL*/ 
glob26_1.sa=NULL;

loc1 .sa=NULL; 

/* shablon prawila */ r27(&rez1,&success1,&pl1);
if( !success1 ) goto _L105;
loc1 .sa=rez1; 

/* shablon [ ... ] */ pl2=pl1;

/* shablon VPAT */ 
wrk1.sa=pl1.cel;
/* operaciq = */ wrk2 .bo= eqatom( wrk1 .sa ,acnst[ 120 ]) ; 
success1= wrk2 .bo ;if( success1 ) { 
rez1=pl1.cel;
   ;} else { rez1=NULL;goto _L104 ;};

bltin1(&rez1,&success1,&pl1,10L);
if( !success1 ) goto _L104;

/*shablon STARLIST */ 
 pl3=pl1;while(pl1.nel!=0 ) { 


/* shablon prawila */ r30(&rez1,&success1,&pl1);
if( !success1 ) goto _L102;
lconc(& loc2 .sa,rez1); 
 pl3=pl1;

/* shablon atoma */ atmpat(acnst[15],&pl1,&rez1,&success1);
if( !success1 ) goto _L101;
;}; 
_L102:if( ! success1 )pl1=pl3;
_L101:;
success1 = true ; 

/* shablon [ ... ] */ pl3=pl1;

/* shablon atoma */ atmpat(acnst[15],&pl1,&rez1,&success1);
if( !success1 ) goto _L103;
_L103:if( ! success1 ) pl1=pl3;success1=true;
_L104:if( ! success1 ) pl1=pl2;success1=true;

/* RETURN-op. */ 
wrk2 .sa =NULL; 
/* CALL #L */ 
pl2.ptrtype=ptrlist;pl2.nel=0;pl2.cel=NULL;
r44(&wrk1.sa,&flag1,&pl2);/* #NEW_LABEL*/ ; 
addel( acnst[ 27 ],false,NULL, wrk1 .sa ,& wrk2 .sa ); 
addel( acnst[ 121 ],false,NULL, glob26_1 .sa ,& wrk2 .sa ); 
addel( acnst[ 21 ],false,NULL, loc1 .sa ,& wrk2 .sa ); 
addel( acnst[ 120 ],false,NULL, loc2 .sa ,& wrk2 .sa ); 
rez1 = wrk2 .sa ;goto _L98 ;xxx; 
goto _L99;  _L105:;  /* metka wyhoda po neuspehu wetwi */
 _L99: rez1=NULL; 
 _L98: *rez=rez1;*success=success1; 
 if (*success) *pl=pl1; /* prodwinutx ukazatelx leksem */ 
/* wosstanowitx GLOB */ 
glob26_1=oldglob26_1;
#ifdef XX  
 d(2,"prostoe_prawilo", 26 ,*rez,*success); 
#endif 
;};/* RULE */ 
/*===============================================*/ 
/* GENERATED TEXT OF RULE   #PLO   */ 
 Void r27(rez,success,pl)
long *rez;boolean *success;ptr_ *pl; 
{  a rez1;  boolean success1; long k; mpd x; 
v loc1;/* $E*/ 
ptr_ pl1;
ptr_ pl2;
ptr_ pl3;
#ifdef XX  
 d(1,"PLO", 27 ,pl->cel,0); 
#endif 
/* sohranitx GLOB */ 

/* branch */ pl1=*pl;rez1=NULL;success1=true; 
/* inicializaciq peremennyh */ 
loc1.sa=NULL;/* $E*/ 

/*shablon STARLIST */ 
 pl2=pl1;while(pl1.nel!=0 ) { 

/* Alternative pattern */ 
pl3=pl1;
/* nonatomic alternative branches */ 


/* shablon prawila */ r28(&rez1,&success1,&pl1);
if( !success1 ) goto _L101;
concop(& loc1 .sa,rez1); 
goto _L103/*uspeh*/;
_L101:; 
pl1=pl3;


/* shablon prawila */ r4(&rez1,&success1,&pl1);
if( !success1 ) goto _L102;
lconc(& loc1 .sa,rez1); 
goto _L103/*uspeh*/;
_L102:; 
pl1=pl3;
goto  _L104;
_L103:;/*uspeh alxtern.*/
 pl2=pl1;
;}; 
_L104:if( ! success1 )pl1=pl2;
success1 = true ; 

/* RETURN-op. */ 
rez1 = loc1 .sa ;goto _L98 ;xxx; 
goto _L99;  _L105:;  /* metka wyhoda po neuspehu wetwi */
 _L99: rez1=NULL; 
 _L98: *rez=rez1;*success=success1; 
 if (*success) *pl=pl1; /* prodwinutx ukazatelx leksem */ 
/* wosstanowitx GLOB */ 
#ifdef XX  
 d(2,"PLO", 27 ,*rez,*success); 
#endif 
;};/* RULE */ 
/*===============================================*/ 
/* GENERATED TEXT OF RULE   #dejstwiq   */ 
 Void r28(rez,success,pl)
long *rez;boolean *success;ptr_ *pl; 
{  a rez1;  boolean success1; long k; mpd x; 
v loc1;/* $E*/ 
v wrk1;
v wrk2;
v wrk3;
v wrk4;
v wrk5;
ptr_ pl1;
ptr_ pl2;
ptr_ pl3;
boolean flag1;
boolean flag2;
#ifdef XX  
 d(1,"dejstwiq", 28 ,pl->cel,0); 
#endif 
/* sohranitx GLOB */ 

/* branch */ pl1=*pl;rez1=NULL;success1=true; 
/* inicializaciq peremennyh */ 
loc1.sa=NULL;/* $E*/ 

/*shablon PLUSLIST */ 
flag1=false;
 pl2=pl1;while(pl1.nel!=0 ) { 

/* shablon VPAT */ 
wrk1.sa=pl1.cel;
/* operaciq = */ wrk2 .bo= eqatom( wrk1 .sa ,acnst[ 122 ]) ; 
success1= wrk2 .bo ;if( success1 ) { 
rez1=pl1.cel;
   ;} else { rez1=NULL;goto _L104 ;};

bltin1(&rez1,&success1,&pl1,10L);
if( !success1 ) goto _L104;

/*shablon STARLIST */ 
 pl3=pl1;while(pl1.nel!=0 ) { 


/* shablon prawila */ r30(&rez1,&success1,&pl1);
if( !success1 ) goto _L102;
lconc(& loc1 .sa,rez1); 
 pl3=pl1;

/* shablon prawila */ r29(&rez1,&success1,&pl1);
if( !success1 ) goto _L101;
;}; 
_L102:if( ! success1 )pl1=pl3;
_L101:;
success1 = true ; 

/* shablon [ ... ] */ pl3=pl1;

/* shablon prawila */ r29(&rez1,&success1,&pl1);
if( !success1 ) goto _L103;
_L103:if( ! success1 ) pl1=pl3;success1=true;

/* shablon SPAT */ 
if( pl1.nel==0 ) { success1=false;goto _L104 ;};
wrk1.sa=pl1.cel;
bltin(&wrk2,&flag2,wrk1.sa,10L); 
if( wrk2 .sa==NULL ) wrk5 .bo=false; else { 
wrk3.sa=pl1.cel;
/* operaciq = */ wrk4 .bo= eqatom( wrk3 .sa ,acnst[ 122 ]) ; wrk5 = wrk4 ;}; 
success1= wrk5 .bo ;if( success1 ) { 
rez1=pl1.cel;
if( pl1.ptrtype!=ptrtree ) next(&pl1);
   ;} else { rez1=NULL;goto _L104 ;};
 pl2=pl1;
flag1=true;
;}; 
_L104:if( ! success1 )pl1=pl2;
success1 = flag1;
if( ! success1 ) goto _L105;

/* RETURN-op. */ 
rez1 = loc1 .sa ;goto _L98 ;xxx; 
goto _L99;  _L105:;  /* metka wyhoda po neuspehu wetwi */
 _L99: rez1=NULL; 
 _L98: *rez=rez1;*success=success1; 
 if (*success) *pl=pl1; /* prodwinutx ukazatelx leksem */ 
/* wosstanowitx GLOB */ 
#ifdef XX  
 d(2,"dejstwiq", 28 ,*rez,*success); 
#endif 
;};/* RULE */ 
/*===============================================*/ 
/* GENERATED TEXT OF RULE   #SEMICOLON   */ 
 Void r29(rez,success,pl)
long *rez;boolean *success;ptr_ *pl; 
{  a rez1;  boolean success1; long k; mpd x; 
v wrk1;
v wrk2;
ptr_ pl1;
#ifdef XX  
 d(1,"SEMICOLON", 29 ,pl->cel,0); 
#endif 
/* sohranitx GLOB */ 

/* branch */ pl1=*pl;rez1=NULL;success1=true; 
/* inicializaciq peremennyh */ 

/* shablon VPAT */ 
wrk1.sa=pl1.cel;
/* operaciq = */ wrk2 .bo= eqatom( wrk1 .sa ,acnst[ 15 ]) ; 
success1= wrk2 .bo ;if( success1 ) { 
rez1=pl1.cel;
   ;} else { rez1=NULL;goto _L101 ;};

bltin1(&rez1,&success1,&pl1,10L);
if( !success1 ) goto _L101;
goto _L99;  _L101:;  /* metka wyhoda po neuspehu wetwi */
 _L99: rez1=NULL; 
 _L98: *rez=rez1;*success=success1; 
 if (*success) *pl=pl1; /* prodwinutx ukazatelx leksem */ 
/* wosstanowitx GLOB */ 
#ifdef XX  
 d(2,"SEMICOLON", 29 ,*rez,*success); 
#endif 
;};/* RULE */ 
/*===============================================*/ 
/* GENERATED TEXT OF RULE   #operator   */ 
 Void r30(rez,success,pl)
long *rez;boolean *success;ptr_ *pl; 
{  a rez1;  boolean success1; long k; mpd x; 
v loc1;/* $X*/ 
v wrk1;
ptr_ pl1;
ptr_ pl2;
#ifdef XX  
 d(1,"operator", 30 ,pl->cel,0); 
#endif 
/* sohranitx GLOB */ 

/* branch */ pl1=*pl;rez1=NULL;success1=true; 
/* inicializaciq peremennyh */ 
loc1.sa=NULL;/* $X*/ 

/* operator := */ 
mknumb( 0L,& wrk1 .sa); 
glob2_1 .sa= wrk1 .sa ;xxx; 

loc1 .sa=NULL; 

/* Alternative pattern */ 
pl2=pl1;
/* nonatomic alternative branches */ 

/* shablon prawila */ r31(&rez1,&success1,&pl1);
if( !success1 ) goto _L101;
goto _L104/*uspeh*/;
_L101:; 
pl1=pl2;

/* shablon prawila */ r22(&rez1,&success1,&pl1);
if( !success1 ) goto _L102;
goto _L104/*uspeh*/;
_L102:; 
pl1=pl2;

/* shablon prawila */ r23(&rez1,&success1,&pl1);
if( !success1 ) goto _L103;
goto _L104/*uspeh*/;
_L103:; 
pl1=pl2;
goto  _L105;
_L104:;/*uspeh alxtern.*/
loc1 .sa=rez1; 

/* RETURN-op. */ 
rez1 = loc1 .sa ;goto _L98 ;xxx; 
goto _L99;  _L105:;  /* metka wyhoda po neuspehu wetwi */
 _L99: rez1=NULL; 
 _L98: *rez=rez1;*success=success1; 
 if (*success) *pl=pl1; /* prodwinutx ukazatelx leksem */ 
/* wosstanowitx GLOB */ 
#ifdef XX  
 d(2,"operator", 30 ,*rez,*success); 
#endif 
;};/* RULE */ 
/*===============================================*/ 
/* GENERATED TEXT OF RULE   #operator1   */ 
 Void r31(rez,success,pl)
long *rez;boolean *success;ptr_ *pl; 
{  a rez1;  boolean success1; long k; mpd x; 
v loc1;/* $LABEL*/ 
v loc2;/* $COND*/ 
v loc3;/* $OPS*/ 
v loc4;/* $R*/ 
v loc5;/* $OP*/ 
v loc6;/* $VAR*/ 
v loc7;/* $FSPEC*/ 
v loc8;/* $ID*/ 
v loc9;/* $E*/ 
v loc10;/* $E1*/ 
v wrk1;
v wrk2;
v wrk3;
v wrk4;
v wrk5;
ptr_ pl1;
ptr_ pl2;
ptr_ pl3;
ptr_ pl4;
ptr_ pl5;
boolean flag1;
#ifdef XX  
 d(1,"operator1", 31 ,pl->cel,0); 
#endif 
/* sohranitx GLOB */ 

/* branch */ pl1=*pl;rez1=NULL;success1=true; 
/* inicializaciq peremennyh */ 
loc1.sa=NULL;/* $LABEL*/ 
loc2.sa=NULL;/* $COND*/ 
loc3.sa=NULL;/* $OPS*/ 
loc4.sa=NULL;/* $R*/ 

/* shablon VPAT */ 
wrk1.sa=pl1.cel;
/* operaciq = */ wrk2 .bo= eqatom( wrk1 .sa ,acnst[ 123 ]) ; 
success1= wrk2 .bo ;if( success1 ) { 
rez1=pl1.cel;
   ;} else { rez1=NULL;goto _L108 ;};

bltin1(&rez1,&success1,&pl1,10L);
if( !success1 ) goto _L108;

/* operator := */ 
/* CALL #L */ 
pl2.ptrtype=ptrlist;pl2.nel=0;pl2.cel=NULL;
r44(&wrk1.sa,&flag1,&pl2);/* #NEW_LABEL*/ ; 
loc1 .sa= wrk1 .sa ;xxx; 

loc2 .sa=NULL; 

/* shablon prawila */ r15(&rez1,&success1,&pl1);
if( !success1 ) goto _L108;
loc2 .sa=rez1; 

/* shablon VPAT */ 
wrk1.sa=pl1.cel;
/* operaciq = */ wrk2 .bo= eqatom( wrk1 .sa ,acnst[ 124 ]) ; 
success1= wrk2 .bo ;if( success1 ) { 
rez1=pl1.cel;
   ;} else { rez1=NULL;goto _L108 ;};

bltin1(&rez1,&success1,&pl1,10L);
if( !success1 ) goto _L108;

/*shablon STARLIST */ 
 pl2=pl1;while(pl1.nel!=0 ) { 


/* shablon prawila */ r30(&rez1,&success1,&pl1);
if( !success1 ) goto _L102;
lconc(& loc3 .sa,rez1); 
 pl2=pl1;

/* shablon prawila */ r29(&rez1,&success1,&pl1);
if( !success1 ) goto _L101;
;}; 
_L102:if( ! success1 )pl1=pl2;
_L101:;
success1 = true ; 

/* shablon [ ... ] */ pl2=pl1;

/* shablon prawila */ r29(&rez1,&success1,&pl1);
if( !success1 ) goto _L103;
_L103:if( ! success1 ) pl1=pl2;success1=true;

/* operator !.:= */ 
wrk1 .sa =NULL; 
addel( acnst[ 125 ],false,NULL, loc2 .sa ,& wrk1 .sa ); 
addel( acnst[ 21 ],false,NULL, loc3 .sa ,& wrk1 .sa ); 
lconc(& loc4 .sa, wrk1 .sa ) ;xxx; 

/*shablon STARLIST */ 
 pl2=pl1;while(pl1.nel!=0 ) { 

/* shablon VPAT */ 
wrk1.sa=pl1.cel;
/* operaciq = */ wrk2 .bo= eqatom( wrk1 .sa ,acnst[ 126 ]) ; 
success1= wrk2 .bo ;if( success1 ) { 
rez1=pl1.cel;
   ;} else { rez1=NULL;goto _L107 ;};

bltin1(&rez1,&success1,&pl1,10L);
if( !success1 ) goto _L107;

loc2 .sa=NULL; 

/* shablon prawila */ r15(&rez1,&success1,&pl1);
if( !success1 ) goto _L107;
loc2 .sa=rez1; 

/* shablon VPAT */ 
wrk1.sa=pl1.cel;
/* operaciq = */ wrk2 .bo= eqatom( wrk1 .sa ,acnst[ 124 ]) ; 
success1= wrk2 .bo ;if( success1 ) { 
rez1=pl1.cel;
   ;} else { rez1=NULL;goto _L107 ;};

bltin1(&rez1,&success1,&pl1,10L);
if( !success1 ) goto _L107;

/* operator := */ 
loc3 .sa= NULL ;xxx; 

/*shablon STARLIST */ 
 pl3=pl1;while(pl1.nel!=0 ) { 


/* shablon prawila */ r30(&rez1,&success1,&pl1);
if( !success1 ) goto _L105;
lconc(& loc3 .sa,rez1); 
 pl3=pl1;

/* shablon prawila */ r29(&rez1,&success1,&pl1);
if( !success1 ) goto _L104;
;}; 
_L105:if( ! success1 )pl1=pl3;
_L104:;
success1 = true ; 

/* shablon [ ... ] */ pl3=pl1;

/* shablon prawila */ r29(&rez1,&success1,&pl1);
if( !success1 ) goto _L106;
_L106:if( ! success1 ) pl1=pl3;success1=true;

/* operator !.:= */ 
wrk1 .sa =NULL; 
addel( acnst[ 125 ],false,NULL, loc2 .sa ,& wrk1 .sa ); 
addel( acnst[ 21 ],false,NULL, loc3 .sa ,& wrk1 .sa ); 
lconc(& loc4 .sa, wrk1 .sa ) ;xxx; 
 pl2=pl1;
;}; 
_L107:if( ! success1 )pl1=pl2;
success1 = true ; 

/* shablon VPAT */ 
wrk1.sa=pl1.cel;
/* operaciq = */ wrk2 .bo= eqatom( wrk1 .sa ,acnst[ 127 ]) ; 
success1= wrk2 .bo ;if( success1 ) { 
rez1=pl1.cel;
   ;} else { rez1=NULL;goto _L108 ;};

bltin1(&rez1,&success1,&pl1,10L);
if( !success1 ) goto _L108;

/* RETURN-op. */ 
wrk1 .sa =NULL; 
addel( acnst[ 27 ],false,NULL, loc1 .sa ,& wrk1 .sa ); 
addel( acnst[ 104 ],false,NULL, loc4 .sa ,& wrk1 .sa ); 
/* operaciq :: */ wrk2 .sa=NULL; 
if( wrk1 .sa!=NULL ) { points( wrk1 .sa,&x.sa); 
x.smtd->name= cnst[55] .sa ; wrk2 = wrk1 ;}; 
rez1 = wrk2 .sa ;goto _L98 ;xxx; 
goto _L99;  _L108:;  /* metka wyhoda po neuspehu wetwi */

/* branch */ pl1=*pl;rez1=NULL;success1=true; 
/* inicializaciq peremennyh */ 
loc5.sa=NULL;/* $OP*/ 
loc6.sa=NULL;/* $VAR*/ 
loc7.sa=NULL;/* $FSPEC*/ 

/* shablon VPAT */ 
wrk1.sa=pl1.cel;
/* operaciq = */ wrk2 .bo= eqatom( wrk1 .sa ,acnst[ 128 ]) ; 
if( wrk2 .bo ) wrk5 .bo=true; else { 
wrk3.sa=pl1.cel;
/* operaciq = */ wrk4 .bo= eqatom( wrk3 .sa ,acnst[ 129 ]) ; wrk5 = wrk4 ;}; 
success1= wrk5 .bo ;if( success1 ) { 
rez1=pl1.cel;
   ;} else { rez1=NULL;goto _L110 ;};

loc5 .sa=NULL; 

bltin1(&rez1,&success1,&pl1,10L);
if( !success1 ) goto _L110;
loc5 .sa=rez1; 

loc6 .sa=NULL; 

bltin1(&rez1,&success1,&pl1,17L);
if( !success1 ) goto _L110;
loc6 .sa=rez1; 

/* IF-operator */ 
/* operaciq = */ wrk1 .bo= eqatom( loc6 .sa ,acnst[ 130 ]) ; 
if( wrk1 .bo) 
{ 
/* operator := */ 
glob24_1 .sa= cnst[1] .sa ;xxx; 
;} 
_L109:;xxx; 

/* CALL #L */ 
pl2.ptrtype=packedlist;pl2.nel=1;pl2.cel=loc6.sa;
pl2.plistsize= 1;
r37(&wrk1.sa,&flag1,&pl2);/* #ADD_USEVAR*/ ;xxx; 

/* CALL #L */ 
pl2.ptrtype=packedlist;pl2.nel=1;pl2.cel=glob2_5.sa;
pl2.UU.plistelt[ 0 ]=loc6.sa;
pl2.plistsize= 2;
r38(&wrk1.sa,&flag1,&pl2);/* #TAB*/ ;xxx; 

loc7 .sa=NULL; 

/* shablon prawila */ r15(&rez1,&success1,&pl1);
if( !success1 ) goto _L110;
loc7 .sa=rez1; 

/* RETURN-op. */ 
wrk3 .sa =NULL; 
wrk1 .sa =NULL; 
addel( acnst[ 41 ],false,NULL, loc6 .sa ,& wrk1 .sa ); 
/* operaciq :: */ wrk2 .sa=NULL; 
if( wrk1 .sa!=NULL ) { points( wrk1 .sa,&x.sa); 
x.smtd->name= cnst[27] .sa ; wrk2 = wrk1 ;}; 
addel( acnst[ 40 ],false,NULL, wrk2 .sa ,& wrk3 .sa ); 
addel( acnst[ 131 ],false,NULL, loc7 .sa ,& wrk3 .sa ); 
/* operaciq :: */ wrk4 .sa=NULL; 
if( wrk3 .sa!=NULL ) { points( wrk3 .sa,&x.sa); 
x.smtd->name= loc5 .sa ; wrk4 = wrk3 ;}; 
rez1 = wrk4 .sa ;goto _L98 ;xxx; 
goto _L99;  _L110:;  /* metka wyhoda po neuspehu wetwi */

/* branch */ pl1=*pl;rez1=NULL;success1=true; 
/* inicializaciq peremennyh */ 
loc7.sa=NULL;/* $FSPEC*/ 
loc8.sa=NULL;/* $ID*/ 

/* shablon VPAT */ 
wrk1.sa=pl1.cel;
/* operaciq = */ wrk2 .bo= eqatom( wrk1 .sa ,acnst[ 132 ]) ; 
success1= wrk2 .bo ;if( success1 ) { 
rez1=pl1.cel;
   ;} else { rez1=NULL;goto _L111 ;};

bltin1(&rez1,&success1,&pl1,10L);
if( !success1 ) goto _L111;

/* shablon peremennoj */ 
varpat(&pl1,idatom,&rez1,&success1);
loc8 .sa=rez1; 
if( !success1 ) goto _L111;

loc7 .sa=NULL; 

/* shablon prawila */ r15(&rez1,&success1,&pl1);
if( !success1 ) goto _L111;
loc7 .sa=rez1; 

/* CALL #L */ 
pl2.ptrtype=packedlist;pl2.nel=1;pl2.cel=loc7.sa;
pl2.plistsize= 1;
r35(&wrk1.sa,&flag1,&pl2);/* #sozdatx_mesto2*/ ;xxx; 

/* RETURN-op. */ 
wrk2 .sa =NULL; 
/* CALL #L */ 
pl2.ptrtype=packedlist;pl2.nel=1;pl2.cel=loc8.sa;
pl2.UU.plistelt[ 0 ]=glob1_2.sa;
pl2.plistsize= 2;
r41(&wrk1.sa,&flag1,&pl2);/* #GETCNST*/ ; 
addel( acnst[ 41 ],false,NULL, wrk1 .sa ,& wrk2 .sa ); 
addel( acnst[ 131 ],false,NULL, loc7 .sa ,& wrk2 .sa ); 
/* operaciq :: */ wrk3 .sa=NULL; 
if( wrk2 .sa!=NULL ) { points( wrk2 .sa,&x.sa); 
x.smtd->name= cnst[56] .sa ; wrk3 = wrk2 ;}; 
rez1 = wrk3 .sa ;goto _L98 ;xxx; 
goto _L99;  _L111:;  /* metka wyhoda po neuspehu wetwi */

/* branch */ pl1=*pl;rez1=NULL;success1=true; 
/* inicializaciq peremennyh */ 
loc5.sa=NULL;/* $OP*/ 
loc8.sa=NULL;/* $ID*/ 
loc9.sa=NULL;/* $E*/ 
loc10.sa=NULL;/* $E1*/ 

/* shablon peremennoj */ 
varpat(&pl1,idatom,&rez1,&success1);
loc8 .sa=rez1; 
if( !success1 ) goto _L121;

/* shablon VPAT */ 
wrk1.sa=pl1.cel;
/* operaciq = */ wrk2 .bo= eqatom( wrk1 .sa ,acnst[ 133 ]) ; 
if( wrk2 .bo ) wrk5 .bo=true; else { 
wrk3.sa=pl1.cel;
/* operaciq = */ wrk4 .bo= eqatom( wrk3 .sa ,acnst[ 134 ]) ; wrk5 = wrk4 ;}; 
success1= wrk5 .bo ;if( success1 ) { 
rez1=pl1.cel;
   ;} else { rez1=NULL;goto _L121 ;};

loc5 .sa=NULL; 

bltin1(&rez1,&success1,&pl1,10L);
if( !success1 ) goto _L121;
loc5 .sa=rez1; 

/*shablon STARLIST */ 
 pl2=pl1;while(pl1.nel!=0 ) { 

/* Alternative pattern */ 
pl3=pl1;
/* nonatomic alternative branches */ 

/* Alternative pattern */ 
pl4=pl1;

/* shablon VPAT */ 
wrk1.sa=pl1.cel;
/* operaciq = */ wrk2 .bo= eqatom( wrk1 .sa ,acnst[ 135 ]) ; 
success1= wrk2 .bo ;if( success1 ) { 
rez1=pl1.cel;
   ;} else { rez1=NULL;goto _L112 ;};

bltin1(&rez1,&success1,&pl1,10L);
if( !success1 ) goto _L112;

/* operator !.:= */ 
lconc(& loc9 .sa, cnst[57] .sa ) ;xxx; 
goto _L113/*uspeh*/;
_L112:; 
pl1=pl4;
goto  _L114;
_L113:;/*uspeh alxtern.*/
goto _L119/*uspeh*/;
_L114:; 
pl1=pl3;


/* shablon prawila */ r32(&rez1,&success1,&pl1);
if( !success1 ) goto _L115;
lconc(& loc9 .sa,rez1); 
goto _L119/*uspeh*/;
_L115:; 
pl1=pl3;

/* Alternative pattern */ 
pl4=pl1;

loc10 .sa=NULL; 

/* shablon prawila */ r15(&rez1,&success1,&pl1);
if( !success1 ) goto _L116;
loc10 .sa=rez1; 

/* CALL #L */ 
pl5.ptrtype=packedlist;pl5.nel=1;pl5.cel=loc10.sa;
pl5.plistsize= 1;
r35(&wrk1.sa,&flag1,&pl5);/* #sozdatx_mesto2*/ ;xxx; 

/* operator !.:= */ 
lconc(& loc9 .sa, loc10 .sa ) ;xxx; 

/* operator := */ 
glob2_1 .sa= NULL ;xxx; 
goto _L117/*uspeh*/;
_L116:; 
pl1=pl4;
goto  _L118;
_L117:;/*uspeh alxtern.*/
goto _L119/*uspeh*/;
_L118:; 
pl1=pl3;
goto  _L120;
_L119:;/*uspeh alxtern.*/
 pl2=pl1;
;}; 
_L120:if( ! success1 )pl1=pl2;
success1 = true ; 

/* RETURN-op. */ 
wrk2 .sa =NULL; 
/* CALL #L */ 
pl2.ptrtype=packedlist;pl2.nel=1;pl2.cel=loc8.sa;
pl2.UU.plistelt[ 0 ]=glob1_2.sa;
pl2.plistsize= 2;
r41(&wrk1.sa,&flag1,&pl2);/* #GETCNST*/ ; 
addel( acnst[ 41 ],false,NULL, wrk1 .sa ,& wrk2 .sa ); 
addel( acnst[ 86 ],false,NULL, loc5 .sa ,& wrk2 .sa ); 
addel( acnst[ 136 ],false,NULL, loc9 .sa ,& wrk2 .sa ); 
/* operaciq :: */ wrk3 .sa=NULL; 
if( wrk2 .sa!=NULL ) { points( wrk2 .sa,&x.sa); 
x.smtd->name= cnst[58] .sa ; wrk3 = wrk2 ;}; 
rez1 = wrk3 .sa ;goto _L98 ;xxx; 
goto _L99;  _L121:;  /* metka wyhoda po neuspehu wetwi */

/* branch */ pl1=*pl;rez1=NULL;success1=true; 
/* inicializaciq peremennyh */ 
loc8.sa=NULL;/* $ID*/ 

/* shablon VPAT */ 
wrk1.sa=pl1.cel;
/* operaciq = */ wrk2 .bo= eqatom( wrk1 .sa ,acnst[ 137 ]) ; 
success1= wrk2 .bo ;if( success1 ) { 
rez1=pl1.cel;
   ;} else { rez1=NULL;goto _L122 ;};

bltin1(&rez1,&success1,&pl1,10L);
if( !success1 ) goto _L122;

/* shablon peremennoj */ 
varpat(&pl1,idatom,&rez1,&success1);
loc8 .sa=rez1; 
if( !success1 ) goto _L122;

/* RETURN-op. */ 
wrk2 .sa =NULL; 
/* CALL #L */ 
pl2.ptrtype=packedlist;pl2.nel=1;pl2.cel=loc8.sa;
pl2.UU.plistelt[ 0 ]=glob1_2.sa;
pl2.plistsize= 2;
r41(&wrk1.sa,&flag1,&pl2);/* #GETCNST*/ ; 
lconc(& wrk2 .sa , wrk1 .sa ); 
/* operaciq :: */ wrk3 .sa=NULL; 
if( wrk2 .sa!=NULL ) { points( wrk2 .sa,&x.sa); 
x.smtd->name= cnst[59] .sa ; wrk3 = wrk2 ;}; 
rez1 = wrk3 .sa ;goto _L98 ;xxx; 
goto _L99;  _L122:;  /* metka wyhoda po neuspehu wetwi */
 _L99: rez1=NULL; 
 _L98: *rez=rez1;*success=success1; 
 if (*success) *pl=pl1; /* prodwinutx ukazatelx leksem */ 
/* wosstanowitx GLOB */ 
#ifdef XX  
 d(2,"operator1", 31 ,*rez,*success); 
#endif 
;};/* RULE */ 
/*===============================================*/ 
/* GENERATED TEXT OF RULE   #ONE_ATOM   */ 
 Void r32(rez,success,pl)
long *rez;boolean *success;ptr_ *pl; 
{  a rez1;  boolean success1; long k; mpd x; 
v loc1;/* $E*/ 
v wrk1;
v wrk2;
v wrk3;
v wrk4;
v wrk5;
ptr_ pl1;
ptr_ pl2;
boolean flag1;
#ifdef XX  
 d(1,"ONE_ATOM", 32 ,pl->cel,0); 
#endif 
/* sohranitx GLOB */ 

/* branch */ pl1=*pl;rez1=NULL;success1=true; 
/* inicializaciq peremennyh */ 
loc1.sa=NULL;/* $E*/ 

loc1 .sa=NULL; 

bltin1(&rez1,&success1,&pl1,3L);
if( !success1 ) goto _L111;
loc1 .sa=rez1; 

/* Alternative pattern */ 
pl2=pl1;
/* nonatomic alternative branches */ 

/* shablon VPAT */ 
wrk1.sa=pl1.cel;
bltin(&wrk2,&flag1,wrk1.sa,10L); 
wrk3 .bo= wrk2 .sa==NULL; 
success1= wrk3 .bo ;if( success1 ) { 
rez1=pl1.cel;
   ;} else { rez1=NULL;goto _L101 ;};
goto _L109/*uspeh*/;
_L101:; 
pl1=pl2;

/* shablon VPAT */ 
wrk1.sa=pl1.cel;
/* operaciq = */ wrk2 .bo= eqatom( wrk1 .sa ,acnst[ 15 ]) ; 
success1= wrk2 .bo ;if( success1 ) { 
rez1=pl1.cel;
   ;} else { rez1=NULL;goto _L102 ;};
goto _L109/*uspeh*/;
_L102:; 
pl1=pl2;

/* shablon VPAT */ 
wrk1.sa=pl1.cel;
/* operaciq = */ wrk2 .bo= eqatom( wrk1 .sa ,acnst[ 122 ]) ; 
success1= wrk2 .bo ;if( success1 ) { 
rez1=pl1.cel;
   ;} else { rez1=NULL;goto _L103 ;};
goto _L109/*uspeh*/;
_L103:; 
pl1=pl2;

/* shablon VPAT */ 
wrk1.sa=pl1.cel;
/* operaciq = */ wrk2 .bo= eqatom( wrk1 .sa ,acnst[ 135 ]) ; 
success1= wrk2 .bo ;if( success1 ) { 
rez1=pl1.cel;
   ;} else { rez1=NULL;goto _L104 ;};
goto _L109/*uspeh*/;
_L104:; 
pl1=pl2;

/* shablon VPAT */ 
wrk1.sa=pl1.cel;
/* operaciq = */ wrk2 .bo= eqatom( wrk1 .sa ,acnst[ 127 ]) ; 
success1= wrk2 .bo ;if( success1 ) { 
rez1=pl1.cel;
   ;} else { rez1=NULL;goto _L105 ;};
goto _L109/*uspeh*/;
_L105:; 
pl1=pl2;

/* shablon VPAT */ 
wrk1.sa=pl1.cel;
/* operaciq = */ wrk2 .bo= eqatom( wrk1 .sa ,acnst[ 126 ]) ; 
success1= wrk2 .bo ;if( success1 ) { 
rez1=pl1.cel;
   ;} else { rez1=NULL;goto _L106 ;};
goto _L109/*uspeh*/;
_L106:; 
pl1=pl2;

/* shablon VPAT */ 
wrk1.sa=pl1.cel;
/* operaciq = */ wrk2 .bo= eqatom( wrk1 .sa ,acnst[ 107 ]) ; 
success1= wrk2 .bo ;if( success1 ) { 
rez1=pl1.cel;
   ;} else { rez1=NULL;goto _L107 ;};
goto _L109/*uspeh*/;
_L107:; 
pl1=pl2;

/* shablon VPAT */ 
wrk1.sa=pl1.cel;
/* operaciq = */ wrk2 .bo= eqatom( wrk1 .sa ,acnst[ 110 ]) ; 
success1= wrk2 .bo ;if( success1 ) { 
rez1=pl1.cel;
   ;} else { rez1=NULL;goto _L108 ;};
goto _L109/*uspeh*/;
_L108:; 
pl1=pl2;
goto  _L111;
_L109:;/*uspeh alxtern.*/

/* IF-operator */ 
bltin(&wrk1,&flag1,loc1.sa,10L); 
if( wrk1 .sa!=NULL ) wrk3 .bo=true; else { 
bltin(&wrk2,&flag1,loc1.sa,8L); wrk3 .bo= wrk2 .sa!=NULL ;}; 
if( wrk3 .bo ) wrk5 .bo=true; else { 
bltin(&wrk4,&flag1,loc1.sa,4L); wrk5 .bo= wrk4 .sa!=NULL ;}; 
if( wrk5 .bo) 
{ 
/* FAIL */ rez1=NULL;success1=false; 
if (pl1.ptrtype!=ptrtree) next(&pl1); /*wyhod iz der.ili sp.*/ 
goto _L111;xxx; 
;} 
_L110:;xxx; 

/* RETURN-op. */ 
rez1 = loc1 .sa ;goto _L98 ;xxx; 
goto _L99;  _L111:;  /* metka wyhoda po neuspehu wetwi */
 _L99: rez1=NULL; 
 _L98: *rez=rez1;*success=success1; 
 if (*success) *pl=pl1; /* prodwinutx ukazatelx leksem */ 
/* wosstanowitx GLOB */ 
#ifdef XX  
 d(2,"ONE_ATOM", 32 ,*rez,*success); 
#endif 
;};/* RULE */ 
