
#include "globrig.h" 
#include "define.h"  
#include "defpage.h" 
#include "nef2.h"    
#include "c1.h"      
#include "usemod.h"  
#include "def180.h"  
#include "xcrg.h"    
/*  R4 |l_t_posled_ssablonow */ 
/*  R5 ALTERNATIVE_SYMBOL */ 
/*  R6 ssablon */ 
/*  R7 ASS_SYMBOL */ 
/*===============================================*/ 
/* GENERATED TEXT OF RULE   #|l_t_posled_ssablonow   */ 
 Void r4(rez,success,pl)
long *rez;boolean *success;ptr_ *pl; 
{  a rez1;  boolean success1; long k; mpd x; 
v loc0;/* $_*/ 
v loc1;/* $WORK_PL*/ 
v loc2;/* $E*/ 
v loc3;/* $D*/ 
v loc4;/* $DELIM_LABEL*/ 
v loc5;/* $FLAG*/ 
v loc6;/* $metka_uspeha*/ 
v wrk1;
v wrk2;
v wrk3;
ptr_ pl1;
ptr_ pl2;
ptr_ pl3;
ptr_ pl4;
boolean flag1;
#ifdef XX  
 d(1,"|l_t_posled_ssablonow", 4 ,pl->cel,0); 
#endif 
/* sohranitx GLOB */ 
loc0.sa=pl->cel; 

/* branch */ pl1=*pl;rez1=NULL;success1=true; 
/* inicializaciq peremennyh */ 
loc1.sa=NULL;/* $WORK_PL*/ 
loc2.sa=NULL;/* $E*/ 
loc3.sa=NULL;/* $D*/ 
loc4.sa=NULL;/* $DELIM_LABEL*/ 

/* shablon VPAT */ 
/* operaciq = */ wrk1 .bo= eqatom( loc0 .sa ,acnst[ 22 ]) ; 
success1= wrk1 .bo ;if( success1 ) { 
rez1=pl1.cel;
   ;} else { rez1=NULL;goto _L108 ;};

bltin1(&rez1,&success1,&pl1,10L);
if( !success1 ) goto _L108;

/* operator := */ 
/* CALL #L */ 
pl2.ptrtype=ptrlist;pl2.nel=0;pl2.cel=NULL;
r42(&wrk1.sa,&flag1,&pl2);/* #GET_WORK_PL*/ ; 
loc1 .sa= wrk1 .sa ;xxx; 

loc2 .sa=NULL; 

/* shablon prawila */ r27(&rez1,&success1,&pl1);
if( !success1 ) goto _L108;
loc2 .sa=rez1; 

/* Alternative pattern */ 
pl2=pl1;
/* nonatomic alternative branches */ 

/* Alternative pattern */ 
pl3=pl1;

/* shablon VPAT */ 
wrk1.sa=pl1.cel;
/* operaciq = */ wrk2 .bo= eqatom( wrk1 .sa ,acnst[ 23 ]) ; 
success1= wrk2 .bo ;if( success1 ) { 
rez1=pl1.cel;
   ;} else { rez1=NULL;goto _L101 ;};

bltin1(&rez1,&success1,&pl1,10L);
if( !success1 ) goto _L101;
goto _L102/*uspeh*/;
_L101:; 
pl1=pl3;
goto  _L103;
_L102:;/*uspeh alxtern.*/
goto _L107/*uspeh*/;
_L103:; 
pl1=pl2;

/* Alternative pattern */ 
pl3=pl1;

/* shablon VPAT */ 
wrk1.sa=pl1.cel;
/* operaciq = */ wrk2 .bo= eqatom( wrk1 .sa ,acnst[ 24 ]) ; 
success1= wrk2 .bo ;if( success1 ) { 
rez1=pl1.cel;
   ;} else { rez1=NULL;goto _L104 ;};

bltin1(&rez1,&success1,&pl1,10L);
if( !success1 ) goto _L104;

loc3 .sa=NULL; 

/* shablon prawila */ r8(&rez1,&success1,&pl1);
if( !success1 ) goto _L104;
loc3 .sa=rez1; 

/* shablon VPAT */ 
wrk1.sa=pl1.cel;
/* operaciq = */ wrk2 .bo= eqatom( wrk1 .sa ,acnst[ 25 ]) ; 
success1= wrk2 .bo ;if( success1 ) { 
rez1=pl1.cel;
   ;} else { rez1=NULL;goto _L104 ;};

bltin1(&rez1,&success1,&pl1,10L);
if( !success1 ) goto _L104;

/* operator := */ 
/* CALL #L */ 
pl4.ptrtype=ptrlist;pl4.nel=0;pl4.cel=NULL;
r44(&wrk1.sa,&flag1,&pl4);/* #NEW_LABEL*/ ; 
loc4 .sa= wrk1 .sa ;xxx; 
goto _L105/*uspeh*/;
_L104:; 
pl1=pl3;
goto  _L106;
_L105:;/*uspeh alxtern.*/
goto _L107/*uspeh*/;
_L106:; 
pl1=pl2;
goto  _L108;
_L107:;/*uspeh alxtern.*/

/* operator := */ 
wrk1 .nu= numval( glob2_4 .sa) - 1L ; 
mknumb( wrk1 .nu ,& wrk2 .sa); 
glob2_4 .sa= wrk2 .sa ;xxx; 

/* RETURN-op. */ 
wrk2 .sa =NULL; 
addel( acnst[ 26 ],false,NULL, loc1 .sa ,& wrk2 .sa ); 
/* CALL #L */ 
pl2.ptrtype=ptrlist;pl2.nel=0;pl2.cel=NULL;
r44(&wrk1.sa,&flag1,&pl2);/* #NEW_LABEL*/ ; 
addel( acnst[ 27 ],false,NULL, wrk1 .sa ,& wrk2 .sa ); 
addel( acnst[ 21 ],false,NULL, loc2 .sa ,& wrk2 .sa ); 
addel( acnst[ 28 ],false,NULL, loc4 .sa ,& wrk2 .sa ); 
addel( acnst[ 29 ],false,NULL, loc3 .sa ,& wrk2 .sa ); 
/* operaciq :: */ wrk3 .sa=NULL; 
if( wrk2 .sa!=NULL ) { points( wrk2 .sa,&x.sa); 
x.smtd->name= cnst[23] .sa ; wrk3 = wrk2 ;}; 
rez1 = wrk3 .sa ;goto _L98 ;xxx; 
goto _L99;  _L108:;  /* metka wyhoda po neuspehu wetwi */

/* branch */ pl1=*pl;rez1=NULL;success1=true; 
/* inicializaciq peremennyh */ 
loc1.sa=NULL;/* $WORK_PL*/ 
loc2.sa=NULL;/* $E*/ 
loc3.sa=NULL;/* $D*/ 
loc4.sa=NULL;/* $DELIM_LABEL*/ 
loc5.sa=NULL;/* $FLAG*/ 

/* shablon VPAT */ 
wrk1.sa=pl1.cel;
/* operaciq = */ wrk2 .bo= eqatom( wrk1 .sa ,acnst[ 30 ]) ; 
success1= wrk2 .bo ;if( success1 ) { 
rez1=pl1.cel;
   ;} else { rez1=NULL;goto _L116 ;};

bltin1(&rez1,&success1,&pl1,10L);
if( !success1 ) goto _L116;

/* operator := */ 
/* CALL #L */ 
pl2.ptrtype=ptrlist;pl2.nel=0;pl2.cel=NULL;
r42(&wrk1.sa,&flag1,&pl2);/* #GET_WORK_PL*/ ; 
loc1 .sa= wrk1 .sa ;xxx; 

/* operator := */ 
/* CALL #L */ 
pl2.ptrtype=ptrlist;pl2.nel=0;pl2.cel=NULL;
r43(&wrk1.sa,&flag1,&pl2);/* #GET_FLAG*/ ; 
loc5 .sa= wrk1 .sa ;xxx; 

loc2 .sa=NULL; 

/* shablon prawila */ r27(&rez1,&success1,&pl1);
if( !success1 ) goto _L116;
loc2 .sa=rez1; 

/* Alternative pattern */ 
pl2=pl1;
/* nonatomic alternative branches */ 

/* Alternative pattern */ 
pl3=pl1;

/* shablon VPAT */ 
wrk1.sa=pl1.cel;
/* operaciq = */ wrk2 .bo= eqatom( wrk1 .sa ,acnst[ 31 ]) ; 
success1= wrk2 .bo ;if( success1 ) { 
rez1=pl1.cel;
   ;} else { rez1=NULL;goto _L109 ;};

bltin1(&rez1,&success1,&pl1,10L);
if( !success1 ) goto _L109;
goto _L110/*uspeh*/;
_L109:; 
pl1=pl3;
goto  _L111;
_L110:;/*uspeh alxtern.*/
goto _L115/*uspeh*/;
_L111:; 
pl1=pl2;

/* Alternative pattern */ 
pl3=pl1;

/* shablon VPAT */ 
wrk1.sa=pl1.cel;
/* operaciq = */ wrk2 .bo= eqatom( wrk1 .sa ,acnst[ 32 ]) ; 
success1= wrk2 .bo ;if( success1 ) { 
rez1=pl1.cel;
   ;} else { rez1=NULL;goto _L112 ;};

bltin1(&rez1,&success1,&pl1,10L);
if( !success1 ) goto _L112;

loc3 .sa=NULL; 

/* shablon prawila */ r8(&rez1,&success1,&pl1);
if( !success1 ) goto _L112;
loc3 .sa=rez1; 

/* shablon VPAT */ 
wrk1.sa=pl1.cel;
/* operaciq = */ wrk2 .bo= eqatom( wrk1 .sa ,acnst[ 25 ]) ; 
success1= wrk2 .bo ;if( success1 ) { 
rez1=pl1.cel;
   ;} else { rez1=NULL;goto _L112 ;};

bltin1(&rez1,&success1,&pl1,10L);
if( !success1 ) goto _L112;

/* operator := */ 
/* CALL #L */ 
pl4.ptrtype=ptrlist;pl4.nel=0;pl4.cel=NULL;
r44(&wrk1.sa,&flag1,&pl4);/* #NEW_LABEL*/ ; 
loc4 .sa= wrk1 .sa ;xxx; 
goto _L113/*uspeh*/;
_L112:; 
pl1=pl3;
goto  _L114;
_L113:;/*uspeh alxtern.*/
goto _L115/*uspeh*/;
_L114:; 
pl1=pl2;
goto  _L116;
_L115:;/*uspeh alxtern.*/

/* operator := */ 
wrk1 .nu= numval( glob2_4 .sa) - 1L ; 
mknumb( wrk1 .nu ,& wrk2 .sa); 
glob2_4 .sa= wrk2 .sa ;xxx; 

/* operator := */ 
wrk1 .nu= numval( glob2_8 .sa) - 1L ; 
mknumb( wrk1 .nu ,& wrk2 .sa); 
glob2_8 .sa= wrk2 .sa ;xxx; 

/* RETURN-op. */ 
wrk2 .sa =NULL; 
addel( acnst[ 26 ],false,NULL, loc1 .sa ,& wrk2 .sa ); 
/* CALL #L */ 
pl2.ptrtype=ptrlist;pl2.nel=0;pl2.cel=NULL;
r44(&wrk1.sa,&flag1,&pl2);/* #NEW_LABEL*/ ; 
addel( acnst[ 27 ],false,NULL, wrk1 .sa ,& wrk2 .sa ); 
addel( acnst[ 33 ],false,NULL, loc5 .sa ,& wrk2 .sa ); 
addel( acnst[ 21 ],false,NULL, loc2 .sa ,& wrk2 .sa ); 
addel( acnst[ 28 ],false,NULL, loc4 .sa ,& wrk2 .sa ); 
addel( acnst[ 29 ],false,NULL, loc3 .sa ,& wrk2 .sa ); 
/* operaciq :: */ wrk3 .sa=NULL; 
if( wrk2 .sa!=NULL ) { points( wrk2 .sa,&x.sa); 
x.smtd->name= cnst[24] .sa ; wrk3 = wrk2 ;}; 
rez1 = wrk3 .sa ;goto _L98 ;xxx; 
goto _L99;  _L116:;  /* metka wyhoda po neuspehu wetwi */

/* branch */ pl1=*pl;rez1=NULL;success1=true; 
/* inicializaciq peremennyh */ 
loc1.sa=NULL;/* $WORK_PL*/ 
loc2.sa=NULL;/* $E*/ 

/* shablon VPAT */ 
wrk1.sa=pl1.cel;
/* operaciq = */ wrk2 .bo= eqatom( wrk1 .sa ,acnst[ 34 ]) ; 
success1= wrk2 .bo ;if( success1 ) { 
rez1=pl1.cel;
   ;} else { rez1=NULL;goto _L117 ;};

bltin1(&rez1,&success1,&pl1,10L);
if( !success1 ) goto _L117;

/* operator := */ 
/* CALL #L */ 
pl2.ptrtype=ptrlist;pl2.nel=0;pl2.cel=NULL;
r42(&wrk1.sa,&flag1,&pl2);/* #GET_WORK_PL*/ ; 
loc1 .sa= wrk1 .sa ;xxx; 

loc2 .sa=NULL; 

/* shablon prawila */ r27(&rez1,&success1,&pl1);
if( !success1 ) goto _L117;
loc2 .sa=rez1; 

/* shablon VPAT */ 
wrk1.sa=pl1.cel;
/* operaciq = */ wrk2 .bo= eqatom( wrk1 .sa ,acnst[ 35 ]) ; 
success1= wrk2 .bo ;if( success1 ) { 
rez1=pl1.cel;
   ;} else { rez1=NULL;goto _L117 ;};

bltin1(&rez1,&success1,&pl1,10L);
if( !success1 ) goto _L117;

/* operator := */ 
wrk1 .nu= numval( glob2_4 .sa) - 1L ; 
mknumb( wrk1 .nu ,& wrk2 .sa); 
glob2_4 .sa= wrk2 .sa ;xxx; 

/* RETURN-op. */ 
wrk2 .sa =NULL; 
/* CALL #L */ 
pl2.ptrtype=ptrlist;pl2.nel=0;pl2.cel=NULL;
r44(&wrk1.sa,&flag1,&pl2);/* #NEW_LABEL*/ ; 
addel( acnst[ 27 ],false,NULL, wrk1 .sa ,& wrk2 .sa ); 
addel( acnst[ 26 ],false,NULL, loc1 .sa ,& wrk2 .sa ); 
addel( acnst[ 21 ],false,NULL, loc2 .sa ,& wrk2 .sa ); 
/* operaciq :: */ wrk3 .sa=NULL; 
if( wrk2 .sa!=NULL ) { points( wrk2 .sa,&x.sa); 
x.smtd->name= cnst[25] .sa ; wrk3 = wrk2 ;}; 
rez1 = wrk3 .sa ;goto _L98 ;xxx; 
goto _L99;  _L117:;  /* metka wyhoda po neuspehu wetwi */

/* branch */ pl1=*pl;rez1=NULL;success1=true; 
/* inicializaciq peremennyh */ 
loc1.sa=NULL;/* $WORK_PL*/ 
loc2.sa=NULL;/* $E*/ 
loc3.sa=NULL;/* $D*/ 
loc6.sa=NULL;/* $metka_uspeha*/ 

/* shablon VPAT */ 
wrk1.sa=pl1.cel;
/* operaciq = */ wrk2 .bo= eqatom( wrk1 .sa ,acnst[ 36 ]) ; 
success1= wrk2 .bo ;if( success1 ) { 
rez1=pl1.cel;
   ;} else { rez1=NULL;goto _L120 ;};

bltin1(&rez1,&success1,&pl1,10L);
if( !success1 ) goto _L120;

/* operator := */ 
/* CALL #L */ 
pl2.ptrtype=ptrlist;pl2.nel=0;pl2.cel=NULL;
r42(&wrk1.sa,&flag1,&pl2);/* #GET_WORK_PL*/ ; 
loc1 .sa= wrk1 .sa ;xxx; 

/*shablon STARLIST */ 
 pl2=pl1;while(pl1.nel!=0 ) { 

loc3 .sa=NULL; 

/* shablon prawila */ r27(&rez1,&success1,&pl1);
if( !success1 ) goto _L119;
loc3 .sa=rez1; 

/* operator !.:= */ 
wrk2 .sa =NULL; 
/* CALL #L */ 
pl3.ptrtype=ptrlist;pl3.nel=0;pl3.cel=NULL;
r44(&wrk1.sa,&flag1,&pl3);/* #NEW_LABEL*/ ; 
lconc(& wrk2 .sa , wrk1 .sa ); 
wrk3 .sa= wrk2 .sa ; 
concop(& wrk3 .sa, loc3 .sa ); 
lconc(& loc2 .sa, wrk3 .sa ) ;xxx; 
 pl2=pl1;

/* shablon prawila */ r5(&rez1,&success1,&pl1);
if( !success1 ) goto _L118;
;}; 
_L119:if( ! success1 )pl1=pl2;
_L118:;
success1 = true ; 

/* shablon VPAT */ 
wrk1.sa=pl1.cel;
/* operaciq = */ wrk2 .bo= eqatom( wrk1 .sa ,acnst[ 25 ]) ; 
success1= wrk2 .bo ;if( success1 ) { 
rez1=pl1.cel;
   ;} else { rez1=NULL;goto _L120 ;};

bltin1(&rez1,&success1,&pl1,10L);
if( !success1 ) goto _L120;

/* operator := */ 
/* CALL #L */ 
pl2.ptrtype=ptrlist;pl2.nel=0;pl2.cel=NULL;
r44(&wrk1.sa,&flag1,&pl2);/* #NEW_LABEL*/ ; 
loc6 .sa= wrk1 .sa ;xxx; 

/* operator := */ 
wrk1 .nu= numval( glob2_4 .sa) - 1L ; 
mknumb( wrk1 .nu ,& wrk2 .sa); 
glob2_4 .sa= wrk2 .sa ;xxx; 

/* RETURN-op. */ 
wrk1 .sa =NULL; 
addel( acnst[ 37 ],false,NULL, loc6 .sa ,& wrk1 .sa ); 
addel( acnst[ 26 ],false,NULL, loc1 .sa ,& wrk1 .sa ); 
addel( acnst[ 21 ],false,NULL, loc2 .sa ,& wrk1 .sa ); 
/* operaciq :: */ wrk2 .sa=NULL; 
if( wrk1 .sa!=NULL ) { points( wrk1 .sa,&x.sa); 
x.smtd->name= cnst[26] .sa ; wrk2 = wrk1 ;}; 
rez1 = wrk2 .sa ;goto _L98 ;xxx; 
goto _L99;  _L120:;  /* metka wyhoda po neuspehu wetwi */

/* branch */ pl1=*pl;rez1=NULL;success1=true; 
/* inicializaciq peremennyh */ 
loc2.sa=NULL;/* $E*/ 

loc2 .sa=NULL; 

/* shablon prawila */ r6(&rez1,&success1,&pl1);
if( !success1 ) goto _L121;
loc2 .sa=rez1; 

/* RETURN-op. */ 
rez1 = loc2 .sa ;goto _L98 ;xxx; 
goto _L99;  _L121:;  /* metka wyhoda po neuspehu wetwi */
 _L99: rez1=NULL; 
 _L98: *rez=rez1;*success=success1; 
 if (*success) *pl=pl1; /* prodwinutx ukazatelx leksem */ 
/* wosstanowitx GLOB */ 
#ifdef XX  
 d(2,"|l_t_posled_ssablonow", 4 ,*rez,*success); 
#endif 
;};/* RULE */ 
/*===============================================*/ 
/* GENERATED TEXT OF RULE   #ALTERNATIVE_SYMBOL   */ 
 Void r5(rez,success,pl)
long *rez;boolean *success;ptr_ *pl; 
{  a rez1;  boolean success1; long k; mpd x; 
v wrk1;
v wrk2;
ptr_ pl1;
#ifdef XX  
 d(1,"ALTERNATIVE_SYMBOL", 5 ,pl->cel,0); 
#endif 
/* sohranitx GLOB */ 

/* branch */ pl1=*pl;rez1=NULL;success1=true; 
/* inicializaciq peremennyh */ 

/* shablon VPAT */ 
wrk1.sa=pl1.cel;
/* operaciq = */ wrk2 .bo= eqatom( wrk1 .sa ,acnst[ 38 ]) ; 
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
 d(2,"ALTERNATIVE_SYMBOL", 5 ,*rez,*success); 
#endif 
;};/* RULE */ 
/*===============================================*/ 
/* GENERATED TEXT OF RULE   #ssablon   */ 
 Void r6(rez,success,pl)
long *rez;boolean *success;ptr_ *pl; 
{  a rez1;  boolean success1; long k; mpd x; 
v loc1;/* $V*/ 
v loc2;/* $ASS_SYMBOL*/ 
v loc3;/* $P*/ 
v wrk1;
v wrk2;
v wrk3;
v wrk4;
ptr_ pl1;
ptr_ pl2;
ptr_ pl3;
boolean flag1;
#ifdef XX  
 d(1,"ssablon", 6 ,pl->cel,0); 
#endif 
/* sohranitx GLOB */ 

/* branch */ pl1=*pl;rez1=NULL;success1=true; 
/* inicializaciq peremennyh */ 
loc1.sa=NULL;/* $V*/ 
loc2.sa=NULL;/* $ASS_SYMBOL*/ 
loc3.sa=NULL;/* $P*/ 

/* shablon [ ... ] */ pl2=pl1;

loc1 .sa=NULL; 

bltin1(&rez1,&success1,&pl1,17L);
if( !success1 ) goto _L101;
loc1 .sa=rez1; 

/* CALL #L */ 
pl3.ptrtype=packedlist;pl3.nel=1;pl3.cel=glob2_5.sa;
pl3.UU.plistelt[ 0 ]=loc1.sa;
pl3.plistsize= 2;
r38(&wrk1.sa,&flag1,&pl3);/* #TAB*/ ;xxx; 

loc2 .sa=NULL; 

/* shablon prawila */ r7(&rez1,&success1,&pl1);
if( !success1 ) goto _L101;
loc2 .sa=rez1; 
_L101:if( ! success1 ) pl1=pl2;success1=true;

loc3 .sa=NULL; 

/* shablon prawila */ r8(&rez1,&success1,&pl1);
if( !success1 ) goto _L104;
loc3 .sa=rez1; 

/* IF-operator */ 
if( loc2 .sa!=NULL) 
{ 
/* IF-operator */ 
/* operaciq <> */ wrk1 .bo= ! eqatom( loc2 .sa ,acnst[ 39 ]) ; 
if( wrk1 .bo) 
{ 
/* CALL #L */ 
pl2.ptrtype=packedlist;pl2.nel=1;pl2.cel=loc1.sa;
pl2.plistsize= 1;
r37(&wrk1.sa,&flag1,&pl2);/* #ADD_USEVAR*/ ;xxx; 
;} 
_L103:;xxx; 
/* RETURN-op. */ 
wrk3 .sa =NULL; 
wrk1 .sa =NULL; 
addel( acnst[ 41 ],false,NULL, loc1 .sa ,& wrk1 .sa ); 
/* operaciq :: */ wrk2 .sa=NULL; 
if( wrk1 .sa!=NULL ) { points( wrk1 .sa,&x.sa); 
x.smtd->name= cnst[27] .sa ; wrk2 = wrk1 ;}; 
addel( acnst[ 40 ],false,NULL, wrk2 .sa ,& wrk3 .sa ); 
addel( acnst[ 42 ],false,NULL, loc3 .sa ,& wrk3 .sa ); 
/* operaciq :: */ wrk4 .sa=NULL; 
if( wrk3 .sa!=NULL ) { points( wrk3 .sa,&x.sa); 
x.smtd->name= loc2 .sa ; wrk4 = wrk3 ;}; 
rez1 = wrk4 .sa ;goto _L98 ;xxx; 
goto _L102;
;} 
{ 
/* RETURN-op. */ 
rez1 = loc3 .sa ;goto _L98 ;xxx; 
;} 
_L102:;xxx; 
goto _L99;  _L104:;  /* metka wyhoda po neuspehu wetwi */
 _L99: rez1=NULL; 
 _L98: *rez=rez1;*success=success1; 
 if (*success) *pl=pl1; /* prodwinutx ukazatelx leksem */ 
/* wosstanowitx GLOB */ 
#ifdef XX  
 d(2,"ssablon", 6 ,*rez,*success); 
#endif 
;};/* RULE */ 
/*===============================================*/ 
/* GENERATED TEXT OF RULE   #ASS_SYMBOL   */ 
 Void r7(rez,success,pl)
long *rez;boolean *success;ptr_ *pl; 
{  a rez1;  boolean success1; long k; mpd x; 
v loc1;/* $A*/ 
v wrk1;
v wrk2;
ptr_ pl1;
ptr_ pl2;
boolean flag1;
#ifdef XX  
 d(1,"ASS_SYMBOL", 7 ,pl->cel,0); 
#endif 
/* sohranitx GLOB */ 

/* branch */ pl1=*pl;rez1=NULL;success1=true; 
/* inicializaciq peremennyh */ 
loc1.sa=NULL;/* $A*/ 

loc1 .sa=NULL; 

bltin1(&rez1,&success1,&pl1,10L);
if( !success1 ) goto _L107;
loc1 .sa=rez1; 

/* IF-operator */ 
/* operaciq = */ wrk1 .bo= eqatom( loc1 .sa ,acnst[ 39 ]) ; 
if( wrk1 .bo) 
{ 
/* RETURN-op. */ 
rez1 = loc1 .sa ;goto _L98 ;xxx; 
;} 
_L101:;xxx; 

/* Alternative pattern */ 
pl2=pl1;
/* nonatomic alternative branches */ 

/* shablon VPAT */ 
/* operaciq = */ wrk1 .bo= eqatom( loc1 .sa ,acnst[ 32 ]) ; 
success1= wrk1 .bo ;if( success1 ) { 
rez1=pl1.cel;
   ;} else { rez1=NULL;goto _L102 ;};
goto _L106/*uspeh*/;
_L102:; 
pl1=pl2;

/* shablon VPAT */ 
/* operaciq = */ wrk1 .bo= eqatom( loc1 .sa ,acnst[ 43 ]) ; 
success1= wrk1 .bo ;if( success1 ) { 
rez1=pl1.cel;
   ;} else { rez1=NULL;goto _L103 ;};
goto _L106/*uspeh*/;
_L103:; 
pl1=pl2;

/* shablon VPAT */ 
/* operaciq = */ wrk1 .bo= eqatom( loc1 .sa ,acnst[ 44 ]) ; 
success1= wrk1 .bo ;if( success1 ) { 
rez1=pl1.cel;
   ;} else { rez1=NULL;goto _L104 ;};
goto _L106/*uspeh*/;
_L104:; 
pl1=pl2;

/* shablon VPAT */ 
/* operaciq = */ wrk1 .bo= eqatom( loc1 .sa ,acnst[ 45 ]) ; 
success1= wrk1 .bo ;if( success1 ) { 
rez1=pl1.cel;
   ;} else { rez1=NULL;goto _L105 ;};
goto _L106/*uspeh*/;
_L105:; 
pl1=pl2;
goto  _L107;
_L106:;/*uspeh alxtern.*/

/* shablon VPAT */ 
wrk1.sa=pl1.cel;
/* operaciq = */ wrk2 .bo= eqatom( wrk1 .sa ,acnst[ 39 ]) ; 
success1= wrk2 .bo ;if( success1 ) { 
rez1=pl1.cel;
   ;} else { rez1=NULL;goto _L107 ;};

bltin1(&rez1,&success1,&pl1,10L);
if( !success1 ) goto _L107;

/* RETURN-op. */ 
wrk1 .sa=NULL; 
lconc(& wrk1 .sa , loc1 .sa ); 
lconc(& wrk1 .sa , cnst[28] .sa ); 
first(wrk1.sa,&pl2);implod(&pl2,&wrk1.sa); 
rez1 = wrk1 .sa ;goto _L98 ;xxx; 
goto _L99;  _L107:;  /* metka wyhoda po neuspehu wetwi */
 _L99: rez1=NULL; 
 _L98: *rez=rez1;*success=success1; 
 if (*success) *pl=pl1; /* prodwinutx ukazatelx leksem */ 
/* wosstanowitx GLOB */ 
#ifdef XX  
 d(2,"ASS_SYMBOL", 7 ,*rez,*success); 
#endif 
;};/* RULE */ 
