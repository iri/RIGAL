
#include "globrig.h" 
#include "define.h"  
#include "defpage.h" 
#include "nef2.h"    
#include "c1.h"      
#include "usemod.h"  
#include "def180.h"  
#include "xcrg.h"    
/*  R22 operator2 */ 
/*  R23 operator3 */ 
/*===============================================*/ 
/* GENERATED TEXT OF RULE   #operator2   */ 
 Void r22(rez,success,pl)
long *rez;boolean *success;ptr_ *pl; 
{  a rez1;  boolean success1; long k; mpd x; 
v loc1;/* $OP*/ 
v loc2;/* $E*/ 
v loc3;/* $NPL*/ 
v loc4;/* $VAR*/ 
v loc5;/* $BVAR*/ 
v loc6;/* $OPS*/ 
v wrk1;
v wrk2;
v wrk3;
v wrk4;
v wrk5;
v wrk6;
v wrk7;
ptr_ pl1;
ptr_ pl2;
ptr_ pl3;
boolean flag1;
#ifdef XX  
 d(1,"operator2", 22 ,pl->cel,0); 
#endif 
/* sohranitx GLOB */ 

/* branch */ pl1=*pl;rez1=NULL;success1=true; 
/* inicializaciq peremennyh */ 
loc1.sa=NULL;/* $OP*/ 
loc2.sa=NULL;/* $E*/ 

/* shablon VPAT */ 
wrk1.sa=pl1.cel;
/* operaciq = */ wrk2 .bo= eqatom( wrk1 .sa ,acnst[ 100 ]) ; 
if( wrk2 .bo ) wrk5 .bo=true; else { 
wrk3.sa=pl1.cel;
/* operaciq = */ wrk4 .bo= eqatom( wrk3 .sa ,acnst[ 101 ]) ; wrk5 = wrk4 ;}; 
success1= wrk5 .bo ;if( success1 ) { 
rez1=pl1.cel;
   ;} else { rez1=NULL;goto _L102 ;};

loc1 .sa=NULL; 

bltin1(&rez1,&success1,&pl1,10L);
if( !success1 ) goto _L102;
loc1 .sa=rez1; 

loc2 .sa=NULL; 

/* shablon prawila */ r15(&rez1,&success1,&pl1);
if( !success1 ) goto _L102;
loc2 .sa=rez1; 

/* IF-operator */ 
/* operaciq = */ wrk1 .bo= eqatom( loc1 .sa ,acnst[ 100 ]) ; 
if( wrk1 .bo) 
{ 
/* CALL #L */ 
pl2.ptrtype=packedlist;pl2.nel=1;pl2.cel=loc2.sa;
pl2.plistsize= 1;
r35(&wrk1.sa,&flag1,&pl2);/* #sozdatx_mesto2*/ ;xxx; 
;} 
_L101:;xxx; 

/* RETURN-op. */ 
wrk1 .sa =NULL; 
lconc(& wrk1 .sa , loc2 .sa ); 
/* operaciq :: */ wrk2 .sa=NULL; 
if( wrk1 .sa!=NULL ) { points( wrk1 .sa,&x.sa); 
x.smtd->name= loc1 .sa ; wrk2 = wrk1 ;}; 
rez1 = wrk2 .sa ;goto _L98 ;xxx; 
goto _L99;  _L102:;  /* metka wyhoda po neuspehu wetwi */

/* branch */ pl1=*pl;rez1=NULL;success1=true; 
/* inicializaciq peremennyh */ 
loc2.sa=NULL;/* $E*/ 
loc3.sa=NULL;/* $NPL*/ 
loc4.sa=NULL;/* $VAR*/ 
loc5.sa=NULL;/* $BVAR*/ 
loc6.sa=NULL;/* $OPS*/ 

/* shablon VPAT */ 
wrk1.sa=pl1.cel;
/* operaciq = */ wrk2 .bo= eqatom( wrk1 .sa ,acnst[ 102 ]) ; 
success1= wrk2 .bo ;if( success1 ) { 
rez1=pl1.cel;
   ;} else { rez1=NULL;goto _L109 ;};

bltin1(&rez1,&success1,&pl1,10L);
if( !success1 ) goto _L109;

/* operator := */ 
/* CALL #L */ 
pl2.ptrtype=ptrlist;pl2.nel=0;pl2.cel=NULL;
r42(&wrk1.sa,&flag1,&pl2);/* #GET_WORK_PL*/ ; 
loc3 .sa= wrk1 .sa ;xxx; 

/* shablon [ ... ] */ pl2=pl1;

/* shablon [ ... ] */ pl3=pl1;

/* shablon VPAT */ 
wrk1.sa=pl1.cel;
/* operaciq = */ wrk2 .bo= eqatom( wrk1 .sa ,acnst[ 103 ]) ; 
success1= wrk2 .bo ;if( success1 ) { 
rez1=pl1.cel;
   ;} else { rez1=NULL;goto _L103 ;};

bltin1(&rez1,&success1,&pl1,10L);
if( !success1 ) goto _L103;
_L103:if( ! success1 ) pl1=pl3;success1=true;

loc4 .sa=NULL; 

bltin1(&rez1,&success1,&pl1,17L);
if( !success1 ) goto _L104;
loc4 .sa=rez1; 

/* CALL #L */ 
pl3.ptrtype=packedlist;pl3.nel=1;pl3.cel=loc4.sa;
pl3.plistsize= 1;
r37(&wrk1.sa,&flag1,&pl3);/* #ADD_USEVAR*/ ;xxx; 

/* CALL #L */ 
pl3.ptrtype=packedlist;pl3.nel=1;pl3.cel=glob2_5.sa;
pl3.UU.plistelt[ 0 ]=loc4.sa;
pl3.plistsize= 2;
r38(&wrk1.sa,&flag1,&pl3);/* #TAB*/ ;xxx; 
_L104:if( ! success1 ) pl1=pl2;success1=true;

/* shablon [ ... ] */ pl2=pl1;

/* shablon VPAT */ 
wrk1.sa=pl1.cel;
/* operaciq = */ wrk2 .bo= eqatom( wrk1 .sa ,acnst[ 104 ]) ; 
success1= wrk2 .bo ;if( success1 ) { 
rez1=pl1.cel;
   ;} else { rez1=NULL;goto _L105 ;};

bltin1(&rez1,&success1,&pl1,10L);
if( !success1 ) goto _L105;

loc5 .sa=NULL; 

bltin1(&rez1,&success1,&pl1,17L);
if( !success1 ) goto _L105;
loc5 .sa=rez1; 

/* CALL #L */ 
pl3.ptrtype=packedlist;pl3.nel=1;pl3.cel=loc5.sa;
pl3.plistsize= 1;
r37(&wrk1.sa,&flag1,&pl3);/* #ADD_USEVAR*/ ;xxx; 

/* CALL #L */ 
pl3.ptrtype=packedlist;pl3.nel=1;pl3.cel=glob2_5.sa;
pl3.UU.plistelt[ 0 ]=loc5.sa;
pl3.plistsize= 2;
r38(&wrk1.sa,&flag1,&pl3);/* #TAB*/ ;xxx; 
_L105:if( ! success1 ) pl1=pl2;success1=true;

/* shablon VPAT */ 
wrk1.sa=pl1.cel;
/* operaciq = */ wrk2 .bo= eqatom( wrk1 .sa ,acnst[ 105 ]) ; 
success1= wrk2 .bo ;if( success1 ) { 
rez1=pl1.cel;
   ;} else { rez1=NULL;goto _L109 ;};

bltin1(&rez1,&success1,&pl1,10L);
if( !success1 ) goto _L109;

loc2 .sa=NULL; 

/* shablon prawila */ r15(&rez1,&success1,&pl1);
if( !success1 ) goto _L109;
loc2 .sa=rez1; 

/* shablon VPAT */ 
wrk1.sa=pl1.cel;
/* operaciq = */ wrk2 .bo= eqatom( wrk1 .sa ,acnst[ 106 ]) ; 
success1= wrk2 .bo ;if( success1 ) { 
rez1=pl1.cel;
   ;} else { rez1=NULL;goto _L109 ;};

bltin1(&rez1,&success1,&pl1,10L);
if( !success1 ) goto _L109;

/*shablon STARLIST */ 
 pl2=pl1;while(pl1.nel!=0 ) { 


/* shablon prawila */ r30(&rez1,&success1,&pl1);
if( !success1 ) goto _L107;
lconc(& loc6 .sa,rez1); 
 pl2=pl1;

/* shablon prawila */ r29(&rez1,&success1,&pl1);
if( !success1 ) goto _L106;
;}; 
_L107:if( ! success1 )pl1=pl2;
_L106:;
success1 = true ; 

/* shablon [ ... ] */ pl2=pl1;

/* shablon prawila */ r29(&rez1,&success1,&pl1);
if( !success1 ) goto _L108;
_L108:if( ! success1 ) pl1=pl2;success1=true;

/* shablon VPAT */ 
wrk1.sa=pl1.cel;
/* operaciq = */ wrk2 .bo= eqatom( wrk1 .sa ,acnst[ 107 ]) ; 
success1= wrk2 .bo ;if( success1 ) { 
rez1=pl1.cel;
   ;} else { rez1=NULL;goto _L109 ;};

bltin1(&rez1,&success1,&pl1,10L);
if( !success1 ) goto _L109;

/* operator := */ 
wrk1 .nu= numval( glob2_4 .sa) - 1L ; 
mknumb( wrk1 .nu ,& wrk2 .sa); 
glob2_4 .sa= wrk2 .sa ;xxx; 

/* RETURN-op. */ 
wrk6 .sa =NULL; 
/* CALL #L */ 
pl2.ptrtype=ptrlist;pl2.nel=0;pl2.cel=NULL;
r44(&wrk1.sa,&flag1,&pl2);/* #NEW_LABEL*/ ; 
addel( acnst[ 27 ],false,NULL, wrk1 .sa ,& wrk6 .sa ); 
addel( acnst[ 108 ],false,NULL, loc3 .sa ,& wrk6 .sa ); 
wrk2 .sa =NULL; 
addel( acnst[ 41 ],false,NULL, loc4 .sa ,& wrk2 .sa ); 
/* operaciq :: */ wrk3 .sa=NULL; 
if( wrk2 .sa!=NULL ) { points( wrk2 .sa,&x.sa); 
x.smtd->name= cnst[27] .sa ; wrk3 = wrk2 ;}; 
addel( acnst[ 40 ],false,NULL, wrk3 .sa ,& wrk6 .sa ); 
wrk4 .sa =NULL; 
addel( acnst[ 41 ],false,NULL, loc5 .sa ,& wrk4 .sa ); 
/* operaciq :: */ wrk5 .sa=NULL; 
if( wrk4 .sa!=NULL ) { points( wrk4 .sa,&x.sa); 
x.smtd->name= cnst[27] .sa ; wrk5 = wrk4 ;}; 
addel( acnst[ 109 ],false,NULL, wrk5 .sa ,& wrk6 .sa ); 
addel( acnst[ 105 ],false,NULL, loc2 .sa ,& wrk6 .sa ); 
addel( acnst[ 21 ],false,NULL, loc6 .sa ,& wrk6 .sa ); 
/* operaciq :: */ wrk7 .sa=NULL; 
if( wrk6 .sa!=NULL ) { points( wrk6 .sa,&x.sa); 
x.smtd->name= cnst[49] .sa ; wrk7 = wrk6 ;}; 
rez1 = wrk7 .sa ;goto _L98 ;xxx; 
goto _L99;  _L109:;  /* metka wyhoda po neuspehu wetwi */

/* branch */ pl1=*pl;rez1=NULL;success1=true; 
/* inicializaciq peremennyh */ 
loc6.sa=NULL;/* $OPS*/ 

/* shablon VPAT */ 
wrk1.sa=pl1.cel;
/* operaciq = */ wrk2 .bo= eqatom( wrk1 .sa ,acnst[ 57 ]) ; 
success1= wrk2 .bo ;if( success1 ) { 
rez1=pl1.cel;
   ;} else { rez1=NULL;goto _L113 ;};

bltin1(&rez1,&success1,&pl1,10L);
if( !success1 ) goto _L113;

/*shablon STARLIST */ 
 pl2=pl1;while(pl1.nel!=0 ) { 


/* shablon prawila */ r30(&rez1,&success1,&pl1);
if( !success1 ) goto _L111;
lconc(& loc6 .sa,rez1); 
 pl2=pl1;

/* shablon prawila */ r29(&rez1,&success1,&pl1);
if( !success1 ) goto _L110;
;}; 
_L111:if( ! success1 )pl1=pl2;
_L110:;
success1 = true ; 

/* shablon [ ... ] */ pl2=pl1;

/* shablon prawila */ r29(&rez1,&success1,&pl1);
if( !success1 ) goto _L112;
_L112:if( ! success1 ) pl1=pl2;success1=true;

/* shablon VPAT */ 
wrk1.sa=pl1.cel;
/* operaciq = */ wrk2 .bo= eqatom( wrk1 .sa ,acnst[ 110 ]) ; 
success1= wrk2 .bo ;if( success1 ) { 
rez1=pl1.cel;
   ;} else { rez1=NULL;goto _L113 ;};

bltin1(&rez1,&success1,&pl1,10L);
if( !success1 ) goto _L113;

/* RETURN-op. */ 
wrk2 .sa =NULL; 
/* CALL #L */ 
pl2.ptrtype=ptrlist;pl2.nel=0;pl2.cel=NULL;
r44(&wrk1.sa,&flag1,&pl2);/* #NEW_LABEL*/ ; 
addel( acnst[ 27 ],false,NULL, wrk1 .sa ,& wrk2 .sa ); 
addel( acnst[ 21 ],false,NULL, loc6 .sa ,& wrk2 .sa ); 
/* operaciq :: */ wrk3 .sa=NULL; 
if( wrk2 .sa!=NULL ) { points( wrk2 .sa,&x.sa); 
x.smtd->name= cnst[50] .sa ; wrk3 = wrk2 ;}; 
rez1 = wrk3 .sa ;goto _L98 ;xxx; 
goto _L99;  _L113:;  /* metka wyhoda po neuspehu wetwi */

/* branch */ pl1=*pl;rez1=NULL;success1=true; 
/* inicializaciq peremennyh */ 
loc1.sa=NULL;/* $OP*/ 

/* shablon VPAT */ 
wrk1.sa=pl1.cel;
/* operaciq = */ wrk2 .bo= eqatom( wrk1 .sa ,acnst[ 111 ]) ; 
if( wrk2 .bo ) wrk5 .bo=true; else { 
wrk3.sa=pl1.cel;
/* operaciq = */ wrk4 .bo= eqatom( wrk3 .sa ,acnst[ 112 ]) ; wrk5 = wrk4 ;}; 
success1= wrk5 .bo ;if( success1 ) { 
rez1=pl1.cel;
   ;} else { rez1=NULL;goto _L114 ;};

loc1 .sa=NULL; 

bltin1(&rez1,&success1,&pl1,10L);
if( !success1 ) goto _L114;
loc1 .sa=rez1; 

/* RETURN-op. */ 
wrk1 .sa =NULL; 
lconc(& wrk1 .sa , cnst[1] .sa ); 
/* operaciq :: */ wrk2 .sa=NULL; 
if( wrk1 .sa!=NULL ) { points( wrk1 .sa,&x.sa); 
x.smtd->name= loc1 .sa ; wrk2 = wrk1 ;}; 
rez1 = wrk2 .sa ;goto _L98 ;xxx; 
goto _L99;  _L114:;  /* metka wyhoda po neuspehu wetwi */
 _L99: rez1=NULL; 
 _L98: *rez=rez1;*success=success1; 
 if (*success) *pl=pl1; /* prodwinutx ukazatelx leksem */ 
/* wosstanowitx GLOB */ 
#ifdef XX  
 d(2,"operator2", 22 ,*rez,*success); 
#endif 
;};/* RULE */ 
/*===============================================*/ 
/* GENERATED TEXT OF RULE   #operator3   */ 
 Void r23(rez,success,pl)
long *rez;boolean *success;ptr_ *pl; 
{  a rez1;  boolean success1; long k; mpd x; 
v loc1;/* $ID*/ 
v loc2;/* $R*/ 
v loc3;/* $BLTIN*/ 
v loc4;/* $E*/ 
v loc5;/* $tip*/ 
v loc6;/* $FLAG*/ 
v loc7;/* $CALL*/ 
v loc8;/* $N*/ 
v loc9;/* $E1*/ 
v loc10;/* $LEFT*/ 
v loc11;/* $OP*/ 
v loc12;/* $RIGHT*/ 
v wrk1;
v wrk2;
v wrk3;
v wrk4;
ptr_ pl1;
ptr_ pl2;
ptr_ pl3;
boolean flag1;
boolean flag2;
#ifdef XX  
 d(1,"operator3", 23 ,pl->cel,0); 
#endif 
/* sohranitx GLOB */ 

/* branch */ pl1=*pl;rez1=NULL;success1=true; 
/* inicializaciq peremennyh */ 
loc1.sa=NULL;/* $ID*/ 
loc2.sa=NULL;/* $R*/ 
loc3.sa=NULL;/* $BLTIN*/ 
loc4.sa=NULL;/* $E*/ 
loc5.sa=NULL;/* $tip*/ 
loc6.sa=NULL;/* $FLAG*/ 

loc1 .sa=NULL; 

bltin1(&rez1,&success1,&pl1,16L);
if( !success1 ) goto _L105;
loc1 .sa=rez1; 

/* shablon VPAT */ 
wrk1.sa=pl1.cel;
/* operaciq = */ wrk2 .bo= eqatom( wrk1 .sa ,acnst[ 36 ]) ; 
success1= wrk2 .bo ;if( success1 ) { 
rez1=pl1.cel;
   ;} else { rez1=NULL;goto _L105 ;};

bltin1(&rez1,&success1,&pl1,10L);
if( !success1 ) goto _L105;

/* operator := */ 
/* CALL #L */ 
pl2.ptrtype=packedlist;pl2.nel=1;pl2.cel=loc1.sa;
pl2.plistsize= 1;
r14(&wrk1.sa,&flag1,&pl2);/* #BUILTIN*/ ; 
loc2 .sa= wrk1 .sa ;xxx; 

/* Alternative pattern */ 
pl2=pl1;
/* nonatomic alternative branches */ 

/* shablon VPAT */ 
success1= loc2 .sa!=NULL ;if( success1 ) { 
rez1=pl1.cel;
   ;} else { rez1=NULL;goto _L101 ;};

/* operator := */ 
loc3 .sa= cnst[51] .sa ;xxx; 
goto _L103/*uspeh*/;
_L101:; 
pl1=pl2;

/* shablon VPAT */ 
/* operaciq = */ wrk1 .bo= eqatom( loc1 .sa ,acnst[ 48 ]) ; 
success1= wrk1 .bo ;if( success1 ) { 
rez1=pl1.cel;
   ;} else { rez1=NULL;goto _L102 ;};

/* operator := */ 
loc3 .sa= loc1 .sa ;xxx; 
goto _L103/*uspeh*/;
_L102:; 
pl1=pl2;
goto  _L105;
_L103:;/*uspeh alxtern.*/

loc4 .sa=NULL; 

/* shablon prawila */ r15(&rez1,&success1,&pl1);
if( !success1 ) goto _L105;
loc4 .sa=rez1; 

/* CALL #L */ 
pl2.ptrtype=packedlist;pl2.nel=1;pl2.cel=loc4.sa;
pl2.plistsize= 1;
r35(&wrk1.sa,&flag1,&pl2);/* #sozdatx_mesto2*/ ;xxx; 

/* shablon VPAT */ 
wrk1.sa=pl1.cel;
/* operaciq = */ wrk2 .bo= eqatom( wrk1 .sa ,acnst[ 25 ]) ; 
success1= wrk2 .bo ;if( success1 ) { 
rez1=pl1.cel;
   ;} else { rez1=NULL;goto _L105 ;};

bltin1(&rez1,&success1,&pl1,10L);
if( !success1 ) goto _L105;

/* IF-operator */ 
/* operaciq = */ wrk1 .bo= eqnum( loc2 .sa , 15L ) ; 
if( wrk1 .bo) 
{ 
/* operator := */ 
loc5 .sa= cnst[46] .sa ;xxx; 
;} 
_L104:;xxx; 

/* operator := */ 
/* CALL #L */ 
pl2.ptrtype=ptrlist;pl2.nel=0;pl2.cel=NULL;
r43(&wrk1.sa,&flag1,&pl2);/* #GET_FLAG*/ ; 
loc6 .sa= wrk1 .sa ;xxx; 

/* operator := */ 
wrk1 .nu= numval( glob2_8 .sa) - 1L ; 
mknumb( wrk1 .nu ,& wrk2 .sa); 
glob2_8 .sa= wrk2 .sa ;xxx; 

/* RETURN-op. */ 
wrk3 .sa =NULL; 
addel( acnst[ 113 ],false,NULL, loc2 .sa ,& wrk3 .sa ); 
addel( acnst[ 98 ],false,NULL, loc4 .sa ,& wrk3 .sa ); 
wrk2 .sa=NULL; 
lconc(& wrk2 .sa , cnst[44] .sa ); 
/* CALL #L */ 
pl3.ptrtype=ptrlist;pl3.nel=0;pl3.cel=NULL;
r40(&wrk1.sa,&flag2,&pl3);/* #GETWRK*/ ; 
lconc(& wrk2 .sa , wrk1 .sa ); 
first(wrk2.sa,&pl2);implod(&pl2,&wrk2.sa); 
addel( acnst[ 47 ],false,NULL, wrk2 .sa ,& wrk3 .sa ); 
addel( acnst[ 86 ],false,NULL, loc5 .sa ,& wrk3 .sa ); 
addel( acnst[ 33 ],false,NULL, loc6 .sa ,& wrk3 .sa ); 
/* operaciq :: */ wrk4 .sa=NULL; 
if( wrk3 .sa!=NULL ) { points( wrk3 .sa,&x.sa); 
x.smtd->name= loc3 .sa ; wrk4 = wrk3 ;}; 
rez1 = wrk4 .sa ;goto _L98 ;xxx; 
goto _L99;  _L105:;  /* metka wyhoda po neuspehu wetwi */

/* branch */ pl1=*pl;rez1=NULL;success1=true; 
/* inicializaciq peremennyh */ 
loc1.sa=NULL;/* $ID*/ 
loc4.sa=NULL;/* $E*/ 
loc6.sa=NULL;/* $FLAG*/ 
loc7.sa=NULL;/* $CALL*/ 
loc8.sa=NULL;/* $N*/ 
loc9.sa=NULL;/* $E1*/ 

loc1 .sa=NULL; 

bltin1(&rez1,&success1,&pl1,16L);
if( !success1 ) goto _L110;
loc1 .sa=rez1; 

/* shablon VPAT */ 
wrk1.sa=pl1.cel;
/* operaciq = */ wrk2 .bo= eqatom( wrk1 .sa ,acnst[ 36 ]) ; 
success1= wrk2 .bo ;if( success1 ) { 
rez1=pl1.cel;
   ;} else { rez1=NULL;goto _L110 ;};

bltin1(&rez1,&success1,&pl1,10L);
if( !success1 ) goto _L110;

/* Alternative pattern */ 
pl2=pl1;
/* nonatomic alternative branches */ 

/* shablon VPAT */ 
/* operaciq = */ wrk1 .bo= eqatom( loc1 .sa ,acnst[ 49 ]) ; 
success1= wrk1 .bo ;if( success1 ) { 
rez1=pl1.cel;
   ;} else { rez1=NULL;goto _L106 ;};

/* operator := */ 
loc7 .sa= cnst[52] .sa ;xxx; 
goto _L108/*uspeh*/;
_L106:; 
pl1=pl2;

/* operator := */ 
loc7 .sa= cnst[53] .sa ;xxx; success1=true; 
goto _L108/*uspeh*/;
_L107:; 
pl1=pl2;
goto  _L110;
_L108:;/*uspeh alxtern.*/

/* operator := */ 
/* CALL #L */ 
pl2.ptrtype=ptrlist;pl2.nel=0;pl2.cel=NULL;
r42(&wrk1.sa,&flag1,&pl2);/* #GET_WORK_PL*/ ; 
loc8 .sa= wrk1 .sa ;xxx; 

/* operator := */ 
/* CALL #L */ 
pl2.ptrtype=ptrlist;pl2.nel=0;pl2.cel=NULL;
r43(&wrk1.sa,&flag1,&pl2);/* #GET_FLAG*/ ; 
loc6 .sa= wrk1 .sa ;xxx; 

/*shablon STARLIST */ 
 pl2=pl1;while(pl1.nel!=0 ) { 

loc9 .sa=NULL; 

/* shablon prawila */ r15(&rez1,&success1,&pl1);
if( !success1 ) goto _L109;
loc9 .sa=rez1; 

/* CALL #L */ 
pl3.ptrtype=packedlist;pl3.nel=1;pl3.cel=loc9.sa;
pl3.plistsize= 1;
r35(&wrk1.sa,&flag1,&pl3);/* #sozdatx_mesto2*/ ;xxx; 

/* operator !.:= */ 
lconc(& loc4 .sa, loc9 .sa ) ;xxx; 
 pl2=pl1;
;}; 
_L109:if( ! success1 )pl1=pl2;
success1 = true ; 

/* shablon VPAT */ 
wrk1.sa=pl1.cel;
/* operaciq = */ wrk2 .bo= eqatom( wrk1 .sa ,acnst[ 25 ]) ; 
success1= wrk2 .bo ;if( success1 ) { 
rez1=pl1.cel;
   ;} else { rez1=NULL;goto _L110 ;};

bltin1(&rez1,&success1,&pl1,10L);
if( !success1 ) goto _L110;

/* operator := */ 
wrk1 .nu= numval( glob2_8 .sa) - 1L ; 
mknumb( wrk1 .nu ,& wrk2 .sa); 
glob2_8 .sa= wrk2 .sa ;xxx; 

/* operator := */ 
wrk1 .nu= numval( glob2_4 .sa) - 1L ; 
mknumb( wrk1 .nu ,& wrk2 .sa); 
glob2_4 .sa= wrk2 .sa ;xxx; 

/* CALL #L */ 
pl2.ptrtype=packedlist;pl2.nel=1;pl2.cel=loc1.sa;
pl2.plistsize= 1;
r46(&wrk1.sa,&flag1,&pl2);/* #CROSS*/ ;xxx; 

/* RETURN-op. */ 
wrk3 .sa =NULL; 
addel( acnst[ 41 ],false,NULL, loc1 .sa ,& wrk3 .sa ); 
addel( acnst[ 108 ],false,NULL, loc8 .sa ,& wrk3 .sa ); 
wrk2 .sa=NULL; 
lconc(& wrk2 .sa , cnst[44] .sa ); 
/* CALL #L */ 
pl3.ptrtype=ptrlist;pl3.nel=0;pl3.cel=NULL;
r40(&wrk1.sa,&flag2,&pl3);/* #GETWRK*/ ; 
lconc(& wrk2 .sa , wrk1 .sa ); 
first(wrk2.sa,&pl2);implod(&pl2,&wrk2.sa); 
addel( acnst[ 47 ],false,NULL, wrk2 .sa ,& wrk3 .sa ); 
addel( acnst[ 33 ],false,NULL, loc6 .sa ,& wrk3 .sa ); 
addel( acnst[ 114 ],false,NULL, loc4 .sa ,& wrk3 .sa ); 
/* operaciq :: */ wrk4 .sa=NULL; 
if( wrk3 .sa!=NULL ) { points( wrk3 .sa,&x.sa); 
x.smtd->name= loc7 .sa ; wrk4 = wrk3 ;}; 
rez1 = wrk4 .sa ;goto _L98 ;xxx; 
goto _L99;  _L110:;  /* metka wyhoda po neuspehu wetwi */

/* branch */ pl1=*pl;rez1=NULL;success1=true; 
/* inicializaciq peremennyh */ 
loc10.sa=NULL;/* $LEFT*/ 
loc11.sa=NULL;/* $OP*/ 
loc12.sa=NULL;/* $RIGHT*/ 

loc10 .sa=NULL; 

/* shablon prawila */ r15(&rez1,&success1,&pl1);
if( !success1 ) goto _L111;
loc10 .sa=rez1; 

loc11 .sa=NULL; 

/* shablon prawila */ r7(&rez1,&success1,&pl1);
if( !success1 ) goto _L111;
loc11 .sa=rez1; 

loc12 .sa=NULL; 

/* shablon prawila */ r15(&rez1,&success1,&pl1);
if( !success1 ) goto _L111;
loc12 .sa=rez1; 

/* CALL #L */ 
pl2.ptrtype=packedlist;pl2.nel=1;pl2.cel=loc12.sa;
pl2.plistsize= 1;
r35(&wrk1.sa,&flag1,&pl2);/* #sozdatx_mesto2*/ ;xxx; 

/* RETURN-op. */ 
wrk1 .sa =NULL; 
addel( acnst[ 115 ],false,NULL, loc11 .sa ,& wrk1 .sa ); 
addel( acnst[ 116 ],false,NULL, loc12 .sa ,& wrk1 .sa ); 
addel( acnst[ 117 ],false,NULL, loc10 .sa ,& wrk1 .sa ); 
/* operaciq :: */ wrk2 .sa=NULL; 
if( wrk1 .sa!=NULL ) { points( wrk1 .sa,&x.sa); 
x.smtd->name= cnst[54] .sa ; wrk2 = wrk1 ;}; 
rez1 = wrk2 .sa ;goto _L98 ;xxx; 
goto _L99;  _L111:;  /* metka wyhoda po neuspehu wetwi */
 _L99: rez1=NULL; 
 _L98: *rez=rez1;*success=success1; 
 if (*success) *pl=pl1; /* prodwinutx ukazatelx leksem */ 
/* wosstanowitx GLOB */ 
#ifdef XX  
 d(2,"operator3", 23 ,*rez,*success); 
#endif 
;};/* RULE */ 
