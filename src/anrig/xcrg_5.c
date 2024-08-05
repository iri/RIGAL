
#include "globrig.h" 
#include "define.h"  
#include "defpage.h" 
#include "nef2.h"    
#include "c1.h"      
#include "usemod.h"  
#include "def180.h"  
#include "xcrg.h"    
/*  R15 wyravenie */ 
/*  R16 EXPR7 */ 
/*  R17 EXPR6 */ 
/*  R18 EXPR5 */ 
/*  R19 EXPR4 */ 
/*  R20 EXPR3 */ 
/*  R21 EXPR2 */ 
/*===============================================*/ 
/* GENERATED TEXT OF RULE   #wyravenie   */ 
 Void r15(rez,success,pl)
long *rez;boolean *success;ptr_ *pl; 
{  a rez1;  boolean success1; long k; mpd x; 
v loc1;/* $A1*/ 
v loc2;/* $A2*/ 
v wrk1;
v wrk2;
v wrk3;
v wrk4;
ptr_ pl1;
ptr_ pl2;
ptr_ pl3;
ptr_ pl4;
boolean flag1;
boolean flag2;
#ifdef XX  
 d(1,"wyravenie", 15 ,pl->cel,0); 
#endif 
/* sohranitx GLOB */ 

/* branch */ pl1=*pl;rez1=NULL;success1=true; 
/* inicializaciq peremennyh */ 
loc1.sa=NULL;/* $A1*/ 
loc2.sa=NULL;/* $A2*/ 

loc1 .sa=NULL; 

/* shablon prawila */ r16(&rez1,&success1,&pl1);
if( !success1 ) goto _L102;
loc1 .sa=rez1; 

/*shablon STARLIST */ 
 pl2=pl1;while(pl1.nel!=0 ) { 

/* shablon VPAT */ 
wrk1.sa=pl1.cel;
/* operaciq = */ wrk2 .bo= eqatom( wrk1 .sa ,acnst[ 83 ]) ; 
success1= wrk2 .bo ;if( success1 ) { 
rez1=pl1.cel;
   ;} else { rez1=NULL;goto _L101 ;};

bltin1(&rez1,&success1,&pl1,10L);
if( !success1 ) goto _L101;

loc2 .sa=NULL; 

/* shablon prawila */ r16(&rez1,&success1,&pl1);
if( !success1 ) goto _L101;
loc2 .sa=rez1; 

/* operator := */ 
wrk3 .sa =NULL; 
addel( acnst[ 84 ],false,NULL, loc1 .sa ,& wrk3 .sa ); 
addel( acnst[ 85 ],false,NULL, loc2 .sa ,& wrk3 .sa ); 
addel( acnst[ 86 ],false,NULL, cnst[43] .sa ,& wrk3 .sa ); 
wrk2 .sa=NULL; 
lconc(& wrk2 .sa , cnst[44] .sa ); 
/* CALL #L */ 
pl4.ptrtype=ptrlist;pl4.nel=0;pl4.cel=NULL;
r40(&wrk1.sa,&flag2,&pl4);/* #GETWRK*/ ; 
lconc(& wrk2 .sa , wrk1 .sa ); 
first(wrk2.sa,&pl3);implod(&pl3,&wrk2.sa); 
addel( acnst[ 47 ],false,NULL, wrk2 .sa ,& wrk3 .sa ); 
/* operaciq :: */ wrk4 .sa=NULL; 
if( wrk3 .sa!=NULL ) { points( wrk3 .sa,&x.sa); 
x.smtd->name= cnst[42] .sa ; wrk4 = wrk3 ;}; 
loc1 .sa= wrk4 .sa ;xxx; 
 pl2=pl1;
;}; 
_L101:if( ! success1 )pl1=pl2;
success1 = true ; 

/* RETURN-op. */ 
rez1 = loc1 .sa ;goto _L98 ;xxx; 
goto _L99;  _L102:;  /* metka wyhoda po neuspehu wetwi */
 _L99: rez1=NULL; 
 _L98: *rez=rez1;*success=success1; 
 if (*success) *pl=pl1; /* prodwinutx ukazatelx leksem */ 
/* wosstanowitx GLOB */ 
#ifdef XX  
 d(2,"wyravenie", 15 ,*rez,*success); 
#endif 
;};/* RULE */ 
/*===============================================*/ 
/* GENERATED TEXT OF RULE   #EXPR7   */ 
 Void r16(rez,success,pl)
long *rez;boolean *success;ptr_ *pl; 
{  a rez1;  boolean success1; long k; mpd x; 
v loc1;/* $A1*/ 
v loc2;/* $A2*/ 
v wrk1;
v wrk2;
v wrk3;
v wrk4;
ptr_ pl1;
ptr_ pl2;
ptr_ pl3;
ptr_ pl4;
boolean flag1;
boolean flag2;
#ifdef XX  
 d(1,"EXPR7", 16 ,pl->cel,0); 
#endif 
/* sohranitx GLOB */ 

/* branch */ pl1=*pl;rez1=NULL;success1=true; 
/* inicializaciq peremennyh */ 
loc1.sa=NULL;/* $A1*/ 
loc2.sa=NULL;/* $A2*/ 

loc1 .sa=NULL; 

/* shablon prawila */ r17(&rez1,&success1,&pl1);
if( !success1 ) goto _L102;
loc1 .sa=rez1; 

/*shablon STARLIST */ 
 pl2=pl1;while(pl1.nel!=0 ) { 

/* shablon VPAT */ 
wrk1.sa=pl1.cel;
/* operaciq = */ wrk2 .bo= eqatom( wrk1 .sa ,acnst[ 87 ]) ; 
success1= wrk2 .bo ;if( success1 ) { 
rez1=pl1.cel;
   ;} else { rez1=NULL;goto _L101 ;};

bltin1(&rez1,&success1,&pl1,10L);
if( !success1 ) goto _L101;

loc2 .sa=NULL; 

/* shablon prawila */ r17(&rez1,&success1,&pl1);
if( !success1 ) goto _L101;
loc2 .sa=rez1; 

/* operator := */ 
wrk3 .sa =NULL; 
addel( acnst[ 84 ],false,NULL, loc1 .sa ,& wrk3 .sa ); 
addel( acnst[ 85 ],false,NULL, loc2 .sa ,& wrk3 .sa ); 
addel( acnst[ 86 ],false,NULL, cnst[43] .sa ,& wrk3 .sa ); 
wrk2 .sa=NULL; 
lconc(& wrk2 .sa , cnst[44] .sa ); 
/* CALL #L */ 
pl4.ptrtype=ptrlist;pl4.nel=0;pl4.cel=NULL;
r40(&wrk1.sa,&flag2,&pl4);/* #GETWRK*/ ; 
lconc(& wrk2 .sa , wrk1 .sa ); 
first(wrk2.sa,&pl3);implod(&pl3,&wrk2.sa); 
addel( acnst[ 47 ],false,NULL, wrk2 .sa ,& wrk3 .sa ); 
/* operaciq :: */ wrk4 .sa=NULL; 
if( wrk3 .sa!=NULL ) { points( wrk3 .sa,&x.sa); 
x.smtd->name= cnst[45] .sa ; wrk4 = wrk3 ;}; 
loc1 .sa= wrk4 .sa ;xxx; 
 pl2=pl1;
;}; 
_L101:if( ! success1 )pl1=pl2;
success1 = true ; 

/* RETURN-op. */ 
rez1 = loc1 .sa ;goto _L98 ;xxx; 
goto _L99;  _L102:;  /* metka wyhoda po neuspehu wetwi */
 _L99: rez1=NULL; 
 _L98: *rez=rez1;*success=success1; 
 if (*success) *pl=pl1; /* prodwinutx ukazatelx leksem */ 
/* wosstanowitx GLOB */ 
#ifdef XX  
 d(2,"EXPR7", 16 ,*rez,*success); 
#endif 
;};/* RULE */ 
/*===============================================*/ 
/* GENERATED TEXT OF RULE   #EXPR6   */ 
 Void r17(rez,success,pl)
long *rez;boolean *success;ptr_ *pl; 
{  a rez1;  boolean success1; long k; mpd x; 
v loc1;/* $A1*/ 
v loc2;/* $OP*/ 
v loc3;/* $A2*/ 
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
v wrk11;
ptr_ pl1;
ptr_ pl2;
ptr_ pl3;
ptr_ pl4;
ptr_ pl5;
boolean flag1;
boolean flag2;
#ifdef XX  
 d(1,"EXPR6", 17 ,pl->cel,0); 
#endif 
/* sohranitx GLOB */ 

/* branch */ pl1=*pl;rez1=NULL;success1=true; 
/* inicializaciq peremennyh */ 
loc1.sa=NULL;/* $A1*/ 
loc2.sa=NULL;/* $OP*/ 
loc3.sa=NULL;/* $A2*/ 

loc1 .sa=NULL; 

/* shablon prawila */ r18(&rez1,&success1,&pl1);
if( !success1 ) goto _L112;
loc1 .sa=rez1; 

/*shablon STARLIST */ 
 pl2=pl1;while(pl1.nel!=0 ) { 

/* Alternative pattern */ 
pl3=pl1;
/* nonatomic alternative branches */ 

/* Alternative pattern */ 
pl4=pl1;

loc2 .sa=NULL; 

/* shablon VPAT */ 
wrk1.sa=pl1.cel;
/* operaciq = */ wrk2 .bo= eqatom( wrk1 .sa ,acnst[ 88 ]) ; 
if( wrk2 .bo ) wrk5 .bo=true; else { 
wrk3.sa=pl1.cel;
/* operaciq = */ wrk4 .bo= eqatom( wrk3 .sa ,acnst[ 89 ]) ; wrk5 = wrk4 ;}; 
success1= wrk5 .bo ;if( success1 ) { 
rez1=pl1.cel;
   ;} else { rez1=NULL;goto _L104 ;};
loc2 .sa=rez1; 

bltin1(&rez1,&success1,&pl1,10L);
if( !success1 ) goto _L104;

loc3 .sa=NULL; 

/* Alternative pattern */ 
pl5=pl1;
/* nonatomic alternative branches */ 

/* shablon prawila */ r36(&rez1,&success1,&pl1);
if( !success1 ) goto _L101;
goto _L103/*uspeh*/;
_L101:; 
pl1=pl5;

/* shablon prawila */ r18(&rez1,&success1,&pl1);
if( !success1 ) goto _L102;
goto _L103/*uspeh*/;
_L102:; 
pl1=pl5;
goto  _L104;
_L103:;/*uspeh alxtern.*/
loc3 .sa=rez1; 
goto _L105/*uspeh*/;
_L104:; 
pl1=pl4;
goto  _L106;
_L105:;/*uspeh alxtern.*/
goto _L110/*uspeh*/;
_L106:; 
pl1=pl3;

/* Alternative pattern */ 
pl5=pl1;

/* shablon VPAT */ 
wrk1.sa=pl1.cel;
/* operaciq = */ wrk2 .bo= eqatom( wrk1 .sa ,acnst[ 90 ]) ; 
if( wrk2 .bo ) wrk5 .bo=true; else { 
wrk3.sa=pl1.cel;
/* operaciq = */ wrk4 .bo= eqatom( wrk3 .sa ,acnst[ 91 ]) ; wrk5 = wrk4 ;}; 
if( wrk5 .bo ) wrk8 .bo=true; else { 
wrk6.sa=pl1.cel;
/* operaciq = */ wrk7 .bo= eqatom( wrk6 .sa ,acnst[ 92 ]) ; wrk8 = wrk7 ;}; 
if( wrk8 .bo ) wrk11 .bo=true; else { 
wrk9.sa=pl1.cel;
/* operaciq = */ wrk10 .bo= eqatom( wrk9 .sa ,acnst[ 93 ]) ; wrk11 = wrk10 ;}; 
success1= wrk11 .bo ;if( success1 ) { 
rez1=pl1.cel;
   ;} else { rez1=NULL;goto _L107 ;};

loc2 .sa=NULL; 

bltin1(&rez1,&success1,&pl1,10L);
if( !success1 ) goto _L107;
loc2 .sa=rez1; 

loc3 .sa=NULL; 

/* shablon prawila */ r18(&rez1,&success1,&pl1);
if( !success1 ) goto _L107;
loc3 .sa=rez1; 
goto _L108/*uspeh*/;
_L107:; 
pl1=pl5;
goto  _L109;
_L108:;/*uspeh alxtern.*/
goto _L110/*uspeh*/;
_L109:; 
pl1=pl3;
goto  _L111;
_L110:;/*uspeh alxtern.*/

/* operator := */ 
wrk3 .sa =NULL; 
addel( acnst[ 84 ],false,NULL, loc1 .sa ,& wrk3 .sa ); 
addel( acnst[ 85 ],false,NULL, loc3 .sa ,& wrk3 .sa ); 
addel( acnst[ 86 ],false,NULL, cnst[43] .sa ,& wrk3 .sa ); 
wrk2 .sa=NULL; 
lconc(& wrk2 .sa , cnst[44] .sa ); 
/* CALL #L */ 
pl5.ptrtype=ptrlist;pl5.nel=0;pl5.cel=NULL;
r40(&wrk1.sa,&flag2,&pl5);/* #GETWRK*/ ; 
lconc(& wrk2 .sa , wrk1 .sa ); 
first(wrk2.sa,&pl4);implod(&pl4,&wrk2.sa); 
addel( acnst[ 47 ],false,NULL, wrk2 .sa ,& wrk3 .sa ); 
/* operaciq :: */ wrk4 .sa=NULL; 
if( wrk3 .sa!=NULL ) { points( wrk3 .sa,&x.sa); 
x.smtd->name= loc2 .sa ; wrk4 = wrk3 ;}; 
loc1 .sa= wrk4 .sa ;xxx; 
 pl2=pl1;
;}; 
_L111:if( ! success1 )pl1=pl2;
success1 = true ; 

/* RETURN-op. */ 
rez1 = loc1 .sa ;goto _L98 ;xxx; 
goto _L99;  _L112:;  /* metka wyhoda po neuspehu wetwi */
 _L99: rez1=NULL; 
 _L98: *rez=rez1;*success=success1; 
 if (*success) *pl=pl1; /* prodwinutx ukazatelx leksem */ 
/* wosstanowitx GLOB */ 
#ifdef XX  
 d(2,"EXPR6", 17 ,*rez,*success); 
#endif 
;};/* RULE */ 
/*===============================================*/ 
/* GENERATED TEXT OF RULE   #EXPR5   */ 
 Void r18(rez,success,pl)
long *rez;boolean *success;ptr_ *pl; 
{  a rez1;  boolean success1; long k; mpd x; 
v loc1;/* $A1*/ 
v loc2;/* $OP*/ 
v loc3;/* $A2*/ 
v loc4;/* $tip*/ 
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
v wrk11;
v wrk12;
v wrk13;
v wrk14;
ptr_ pl1;
ptr_ pl2;
ptr_ pl3;
ptr_ pl4;
boolean flag1;
boolean flag2;
#ifdef XX  
 d(1,"EXPR5", 18 ,pl->cel,0); 
#endif 
/* sohranitx GLOB */ 

/* branch */ pl1=*pl;rez1=NULL;success1=true; 
/* inicializaciq peremennyh */ 
loc1.sa=NULL;/* $A1*/ 
loc2.sa=NULL;/* $OP*/ 
loc3.sa=NULL;/* $A2*/ 
loc4.sa=NULL;/* $tip*/ 

loc1 .sa=NULL; 

/* shablon prawila */ r19(&rez1,&success1,&pl1);
if( !success1 ) goto _L103;
loc1 .sa=rez1; 

/*shablon STARLIST */ 
 pl2=pl1;while(pl1.nel!=0 ) { 

loc2 .sa=NULL; 

/* shablon VPAT */ 
wrk1.sa=pl1.cel;
/* operaciq = */ wrk2 .bo= eqatom( wrk1 .sa ,acnst[ 44 ]) ; 
if( wrk2 .bo ) wrk5 .bo=true; else { 
wrk3.sa=pl1.cel;
/* operaciq = */ wrk4 .bo= eqatom( wrk3 .sa ,acnst[ 45 ]) ; wrk5 = wrk4 ;}; 
if( wrk5 .bo ) wrk8 .bo=true; else { 
wrk6.sa=pl1.cel;
/* operaciq = */ wrk7 .bo= eqatom( wrk6 .sa ,acnst[ 43 ]) ; wrk8 = wrk7 ;}; 
if( wrk8 .bo ) wrk11 .bo=true; else { 
wrk9.sa=pl1.cel;
/* operaciq = */ wrk10 .bo= eqatom( wrk9 .sa ,acnst[ 32 ]) ; wrk11 = wrk10 ;}; 
if( wrk11 .bo ) wrk14 .bo=true; else { 
wrk12.sa=pl1.cel;
/* operaciq = */ wrk13 .bo= eqatom( wrk12 .sa ,acnst[ 94 ]) ; wrk14 = wrk13 ;}; 
success1= wrk14 .bo ;if( success1 ) { 
rez1=pl1.cel;
   ;} else { rez1=NULL;goto _L102 ;};
loc2 .sa=rez1; 

bltin1(&rez1,&success1,&pl1,10L);
if( !success1 ) goto _L102;

loc3 .sa=NULL; 

/* shablon prawila */ r19(&rez1,&success1,&pl1);
if( !success1 ) goto _L102;
loc3 .sa=rez1; 

/* IF-operator */ 
/* operaciq = */ wrk1 .bo= eqatom( loc2 .sa ,acnst[ 32 ]) ; 
if( wrk1 .bo ) wrk3 .bo=true; else { 
/* operaciq = */ wrk2 .bo= eqatom( loc2 .sa ,acnst[ 94 ]) ; wrk3 = wrk2 ;}; 
if( wrk3 .bo) 
{ 
/* operator := */ 
loc4 .sa= cnst[46] .sa ;xxx; 
goto _L101;
;} 
{ 
/* CALL #L */ 
pl3.ptrtype=packedlist;pl3.nel=1;pl3.cel=loc3.sa;
pl3.plistsize= 1;
r35(&wrk1.sa,&flag1,&pl3);/* #sozdatx_mesto2*/ ;xxx; 
;} 
_L101:;xxx; 

/* operator := */ 
wrk3 .sa =NULL; 
addel( acnst[ 84 ],false,NULL, loc1 .sa ,& wrk3 .sa ); 
addel( acnst[ 85 ],false,NULL, loc3 .sa ,& wrk3 .sa ); 
addel( acnst[ 86 ],false,NULL, loc4 .sa ,& wrk3 .sa ); 
wrk2 .sa=NULL; 
lconc(& wrk2 .sa , cnst[44] .sa ); 
/* CALL #L */ 
pl4.ptrtype=ptrlist;pl4.nel=0;pl4.cel=NULL;
r40(&wrk1.sa,&flag2,&pl4);/* #GETWRK*/ ; 
lconc(& wrk2 .sa , wrk1 .sa ); 
first(wrk2.sa,&pl3);implod(&pl3,&wrk2.sa); 
addel( acnst[ 47 ],false,NULL, wrk2 .sa ,& wrk3 .sa ); 
/* operaciq :: */ wrk4 .sa=NULL; 
if( wrk3 .sa!=NULL ) { points( wrk3 .sa,&x.sa); 
x.smtd->name= loc2 .sa ; wrk4 = wrk3 ;}; 
loc1 .sa= wrk4 .sa ;xxx; 
 pl2=pl1;
;}; 
_L102:if( ! success1 )pl1=pl2;
success1 = true ; 

/* RETURN-op. */ 
rez1 = loc1 .sa ;goto _L98 ;xxx; 
goto _L99;  _L103:;  /* metka wyhoda po neuspehu wetwi */
 _L99: rez1=NULL; 
 _L98: *rez=rez1;*success=success1; 
 if (*success) *pl=pl1; /* prodwinutx ukazatelx leksem */ 
/* wosstanowitx GLOB */ 
#ifdef XX  
 d(2,"EXPR5", 18 ,*rez,*success); 
#endif 
;};/* RULE */ 
/*===============================================*/ 
/* GENERATED TEXT OF RULE   #EXPR4   */ 
 Void r19(rez,success,pl)
long *rez;boolean *success;ptr_ *pl; 
{  a rez1;  boolean success1; long k; mpd x; 
v loc1;/* $A1*/ 
v loc2;/* $OP*/ 
v loc3;/* $A2*/ 
v wrk1;
v wrk2;
v wrk3;
v wrk4;
v wrk5;
v wrk6;
v wrk7;
v wrk8;
ptr_ pl1;
ptr_ pl2;
ptr_ pl3;
ptr_ pl4;
boolean flag1;
boolean flag2;
#ifdef XX  
 d(1,"EXPR4", 19 ,pl->cel,0); 
#endif 
/* sohranitx GLOB */ 

/* branch */ pl1=*pl;rez1=NULL;success1=true; 
/* inicializaciq peremennyh */ 
loc1.sa=NULL;/* $A1*/ 
loc2.sa=NULL;/* $OP*/ 
loc3.sa=NULL;/* $A2*/ 

loc1 .sa=NULL; 

/* shablon prawila */ r20(&rez1,&success1,&pl1);
if( !success1 ) goto _L102;
loc1 .sa=rez1; 

/*shablon STARLIST */ 
 pl2=pl1;while(pl1.nel!=0 ) { 

loc2 .sa=NULL; 

/* shablon VPAT */ 
wrk1.sa=pl1.cel;
/* operaciq = */ wrk2 .bo= eqatom( wrk1 .sa ,acnst[ 24 ]) ; 
if( wrk2 .bo ) wrk5 .bo=true; else { 
wrk3.sa=pl1.cel;
/* operaciq = */ wrk4 .bo= eqatom( wrk3 .sa ,acnst[ 95 ]) ; wrk5 = wrk4 ;}; 
if( wrk5 .bo ) wrk8 .bo=true; else { 
wrk6.sa=pl1.cel;
/* operaciq = */ wrk7 .bo= eqatom( wrk6 .sa ,acnst[ 96 ]) ; wrk8 = wrk7 ;}; 
success1= wrk8 .bo ;if( success1 ) { 
rez1=pl1.cel;
   ;} else { rez1=NULL;goto _L101 ;};
loc2 .sa=rez1; 

bltin1(&rez1,&success1,&pl1,10L);
if( !success1 ) goto _L101;

loc3 .sa=NULL; 

/* shablon prawila */ r20(&rez1,&success1,&pl1);
if( !success1 ) goto _L101;
loc3 .sa=rez1; 

/* operator := */ 
wrk3 .sa =NULL; 
addel( acnst[ 84 ],false,NULL, loc1 .sa ,& wrk3 .sa ); 
addel( acnst[ 85 ],false,NULL, loc3 .sa ,& wrk3 .sa ); 
addel( acnst[ 86 ],false,NULL, cnst[46] .sa ,& wrk3 .sa ); 
wrk2 .sa=NULL; 
lconc(& wrk2 .sa , cnst[44] .sa ); 
/* CALL #L */ 
pl4.ptrtype=ptrlist;pl4.nel=0;pl4.cel=NULL;
r40(&wrk1.sa,&flag2,&pl4);/* #GETWRK*/ ; 
lconc(& wrk2 .sa , wrk1 .sa ); 
first(wrk2.sa,&pl3);implod(&pl3,&wrk2.sa); 
addel( acnst[ 47 ],false,NULL, wrk2 .sa ,& wrk3 .sa ); 
/* operaciq :: */ wrk4 .sa=NULL; 
if( wrk3 .sa!=NULL ) { points( wrk3 .sa,&x.sa); 
x.smtd->name= loc2 .sa ; wrk4 = wrk3 ;}; 
loc1 .sa= wrk4 .sa ;xxx; 
 pl2=pl1;
;}; 
_L101:if( ! success1 )pl1=pl2;
success1 = true ; 

/* RETURN-op. */ 
rez1 = loc1 .sa ;goto _L98 ;xxx; 
goto _L99;  _L102:;  /* metka wyhoda po neuspehu wetwi */
 _L99: rez1=NULL; 
 _L98: *rez=rez1;*success=success1; 
 if (*success) *pl=pl1; /* prodwinutx ukazatelx leksem */ 
/* wosstanowitx GLOB */ 
#ifdef XX  
 d(2,"EXPR4", 19 ,*rez,*success); 
#endif 
;};/* RULE */ 
/*===============================================*/ 
/* GENERATED TEXT OF RULE   #EXPR3   */ 
 Void r20(rez,success,pl)
long *rez;boolean *success;ptr_ *pl; 
{  a rez1;  boolean success1; long k; mpd x; 
v loc1;/* $OP*/ 
v loc2;/* $A1*/ 
v loc3;/* $tip*/ 
v wrk1;
v wrk2;
v wrk3;
v wrk4;
v wrk5;
v wrk6;
v wrk7;
v wrk8;
ptr_ pl1;
ptr_ pl2;
ptr_ pl3;
boolean flag1;
boolean flag2;
#ifdef XX  
 d(1,"EXPR3", 20 ,pl->cel,0); 
#endif 
/* sohranitx GLOB */ 

/* branch */ pl1=*pl;rez1=NULL;success1=true; 
/* inicializaciq peremennyh */ 
loc1.sa=NULL;/* $OP*/ 
loc2.sa=NULL;/* $A1*/ 
loc3.sa=NULL;/* $tip*/ 

loc1 .sa=NULL; 

/* shablon SPAT */ 
if( pl1.nel==0 ) { success1=false;goto _L102 ;};
wrk1.sa=pl1.cel;
bltin(&wrk2,&flag1,wrk1.sa,10L); 
if( wrk2 .sa==NULL ) wrk8 .bo=false; else { 
wrk3.sa=pl1.cel;
/* operaciq = */ wrk4 .bo= eqatom( wrk3 .sa ,acnst[ 97 ]) ; 
if( wrk4 .bo ) wrk7 .bo=true; else { 
wrk5.sa=pl1.cel;
/* operaciq = */ wrk6 .bo= eqatom( wrk5 .sa ,acnst[ 94 ]) ; wrk7 = wrk6 ;}; wrk8
 = wrk7 ;}; 
success1= wrk8 .bo ;if( success1 ) { 
rez1=pl1.cel;
if( pl1.ptrtype!=ptrtree ) next(&pl1);
   ;} else { rez1=NULL;goto _L102 ;};
loc1 .sa=rez1; 

loc2 .sa=NULL; 

/* shablon prawila */ r20(&rez1,&success1,&pl1);
if( !success1 ) goto _L102;
loc2 .sa=rez1; 

/* IF-operator */ 
/* operaciq = */ wrk1 .bo= eqatom( loc1 .sa ,acnst[ 94 ]) ; 
if( wrk1 .bo) 
{ 
/* operator := */ 
loc3 .sa= cnst[46] .sa ;xxx; 
goto _L101;
;} 
/* operaciq = */ wrk1 .bo= eqatom( loc1 .sa ,acnst[ 97 ]) ; 
if( wrk1 .bo) 
{ 
/* operator := */ 
loc3 .sa= cnst[43] .sa ;xxx; 
;} 
_L101:;xxx; 

/* RETURN-op. */ 
wrk3 .sa =NULL; 
addel( acnst[ 98 ],false,NULL, loc2 .sa ,& wrk3 .sa ); 
addel( acnst[ 86 ],false,NULL, loc3 .sa ,& wrk3 .sa ); 
wrk2 .sa=NULL; 
lconc(& wrk2 .sa , cnst[44] .sa ); 
/* CALL #L */ 
pl3.ptrtype=ptrlist;pl3.nel=0;pl3.cel=NULL;
r40(&wrk1.sa,&flag2,&pl3);/* #GETWRK*/ ; 
lconc(& wrk2 .sa , wrk1 .sa ); 
first(wrk2.sa,&pl2);implod(&pl2,&wrk2.sa); 
addel( acnst[ 47 ],false,NULL, wrk2 .sa ,& wrk3 .sa ); 
/* operaciq :: */ wrk4 .sa=NULL; 
if( wrk3 .sa!=NULL ) { points( wrk3 .sa,&x.sa); 
x.smtd->name= loc1 .sa ; wrk4 = wrk3 ;}; 
rez1 = wrk4 .sa ;goto _L98 ;xxx; 
goto _L99;  _L102:;  /* metka wyhoda po neuspehu wetwi */

/* branch */ pl1=*pl;rez1=NULL;success1=true; 
/* inicializaciq peremennyh */ 
loc2.sa=NULL;/* $A1*/ 

loc2 .sa=NULL; 

/* shablon prawila */ r21(&rez1,&success1,&pl1);
if( !success1 ) goto _L103;
loc2 .sa=rez1; 

/* RETURN-op. */ 
rez1 = loc2 .sa ;goto _L98 ;xxx; 
goto _L99;  _L103:;  /* metka wyhoda po neuspehu wetwi */
 _L99: rez1=NULL; 
 _L98: *rez=rez1;*success=success1; 
 if (*success) *pl=pl1; /* prodwinutx ukazatelx leksem */ 
/* wosstanowitx GLOB */ 
#ifdef XX  
 d(2,"EXPR3", 20 ,*rez,*success); 
#endif 
;};/* RULE */ 
/*===============================================*/ 
/* GENERATED TEXT OF RULE   #EXPR2   */ 
 Void r21(rez,success,pl)
long *rez;boolean *success;ptr_ *pl; 
{  a rez1;  boolean success1; long k; mpd x; 
v loc1;/* $A1*/ 
v loc2;/* $OP*/ 
v loc3;/* $A2*/ 
v wrk1;
v wrk2;
v wrk3;
v wrk4;
ptr_ pl1;
ptr_ pl2;
ptr_ pl3;
ptr_ pl4;
ptr_ pl5;
ptr_ pl6;
boolean flag1;
boolean flag2;
#ifdef XX  
 d(1,"EXPR2", 21 ,pl->cel,0); 
#endif 
/* sohranitx GLOB */ 

/* branch */ pl1=*pl;rez1=NULL;success1=true; 
/* inicializaciq peremennyh */ 
loc1.sa=NULL;/* $A1*/ 
loc2.sa=NULL;/* $OP*/ 
loc3.sa=NULL;/* $A2*/ 

loc1 .sa=NULL; 

/* shablon prawila */ r33(&rez1,&success1,&pl1);
if( !success1 ) goto _L115;
loc1 .sa=rez1; 

/*shablon STARLIST */ 
 pl2=pl1;while(pl1.nel!=0 ) { 

/* Alternative pattern */ 
pl3=pl1;
/* nonatomic alternative branches */ 

/* Alternative pattern */ 
pl4=pl1;

loc2 .sa=NULL; 

/* shablon VPAT */ 
wrk1.sa=pl1.cel;
/* operaciq = */ wrk2 .bo= eqatom( wrk1 .sa ,acnst[ 58 ]) ; 
success1= wrk2 .bo ;if( success1 ) { 
rez1=pl1.cel;
   ;} else { rez1=NULL;goto _L101 ;};
loc2 .sa=rez1; 

bltin1(&rez1,&success1,&pl1,10L);
if( !success1 ) goto _L101;

/* CALL #L */ 
pl5.ptrtype=packedlist;pl5.nel=1;pl5.cel=loc1.sa;
pl5.plistsize= 1;
r35(&wrk1.sa,&flag1,&pl5);/* #sozdatx_mesto2*/ ;xxx; 

loc3 .sa=NULL; 

/* shablon prawila */ r33(&rez1,&success1,&pl1);
if( !success1 ) goto _L101;
loc3 .sa=rez1; 
goto _L102/*uspeh*/;
_L101:; 
pl1=pl4;
goto  _L103;
_L102:;/*uspeh alxtern.*/
goto _L113/*uspeh*/;
_L103:; 
pl1=pl3;

/* Alternative pattern */ 
pl4=pl1;

/* shablon VPAT */ 
wrk1.sa=pl1.cel;
/* operaciq = */ wrk2 .bo= eqatom( wrk1 .sa ,acnst[ 99 ]) ; 
success1= wrk2 .bo ;if( success1 ) { 
rez1=pl1.cel;
   ;} else { rez1=NULL;goto _L107 ;};

bltin1(&rez1,&success1,&pl1,10L);
if( !success1 ) goto _L107;

/* operator := */ 
loc2 .sa= cnst[47] .sa ;xxx; 

loc3 .sa=NULL; 

/* Alternative pattern */ 
pl5=pl1;
/* nonatomic alternative branches */ 

/* shablon prawila */ r34(&rez1,&success1,&pl1);
if( !success1 ) goto _L104;
goto _L106/*uspeh*/;
_L104:; 
pl1=pl5;

/* shablon prawila */ r33(&rez1,&success1,&pl1);
if( !success1 ) goto _L105;
goto _L106/*uspeh*/;
_L105:; 
pl1=pl5;
goto  _L107;
_L106:;/*uspeh alxtern.*/
loc3 .sa=rez1; 

/* CALL #L */ 
pl6.ptrtype=packedlist;pl6.nel=1;pl6.cel=loc3.sa;
pl6.plistsize= 1;
r35(&wrk1.sa,&flag1,&pl6);/* #sozdatx_mesto2*/ ;xxx; 
goto _L108/*uspeh*/;
_L107:; 
pl1=pl4;
goto  _L109;
_L108:;/*uspeh alxtern.*/
goto _L113/*uspeh*/;
_L109:; 
pl1=pl3;

/* Alternative pattern */ 
pl5=pl1;

/* shablon VPAT */ 
wrk1.sa=pl1.cel;
/* operaciq = */ wrk2 .bo= eqatom( wrk1 .sa ,acnst[ 34 ]) ; 
success1= wrk2 .bo ;if( success1 ) { 
rez1=pl1.cel;
   ;} else { rez1=NULL;goto _L110 ;};

bltin1(&rez1,&success1,&pl1,10L);
if( !success1 ) goto _L110;

loc3 .sa=NULL; 

/* shablon prawila */ r15(&rez1,&success1,&pl1);
if( !success1 ) goto _L110;
loc3 .sa=rez1; 

/* shablon VPAT */ 
wrk1.sa=pl1.cel;
/* operaciq = */ wrk2 .bo= eqatom( wrk1 .sa ,acnst[ 35 ]) ; 
success1= wrk2 .bo ;if( success1 ) { 
rez1=pl1.cel;
   ;} else { rez1=NULL;goto _L110 ;};

bltin1(&rez1,&success1,&pl1,10L);
if( !success1 ) goto _L110;

/* operator := */ 
loc2 .sa= cnst[48] .sa ;xxx; 
goto _L111/*uspeh*/;
_L110:; 
pl1=pl5;
goto  _L112;
_L111:;/*uspeh alxtern.*/
goto _L113/*uspeh*/;
_L112:; 
pl1=pl3;
goto  _L114;
_L113:;/*uspeh alxtern.*/

/* operator := */ 
wrk3 .sa =NULL; 
addel( acnst[ 84 ],false,NULL, loc1 .sa ,& wrk3 .sa ); 
addel( acnst[ 85 ],false,NULL, loc3 .sa ,& wrk3 .sa ); 
wrk2 .sa=NULL; 
lconc(& wrk2 .sa , cnst[44] .sa ); 
/* CALL #L */ 
pl5.ptrtype=ptrlist;pl5.nel=0;pl5.cel=NULL;
r40(&wrk1.sa,&flag2,&pl5);/* #GETWRK*/ ; 
lconc(& wrk2 .sa , wrk1 .sa ); 
first(wrk2.sa,&pl4);implod(&pl4,&wrk2.sa); 
addel( acnst[ 47 ],false,NULL, wrk2 .sa ,& wrk3 .sa ); 
/* operaciq :: */ wrk4 .sa=NULL; 
if( wrk3 .sa!=NULL ) { points( wrk3 .sa,&x.sa); 
x.smtd->name= loc2 .sa ; wrk4 = wrk3 ;}; 
loc1 .sa= wrk4 .sa ;xxx; 
 pl2=pl1;
;}; 
_L114:if( ! success1 )pl1=pl2;
success1 = true ; 

/* RETURN-op. */ 
rez1 = loc1 .sa ;goto _L98 ;xxx; 
goto _L99;  _L115:;  /* metka wyhoda po neuspehu wetwi */
 _L99: rez1=NULL; 
 _L98: *rez=rez1;*success=success1; 
 if (*success) *pl=pl1; /* prodwinutx ukazatelx leksem */ 
/* wosstanowitx GLOB */ 
#ifdef XX  
 d(2,"EXPR2", 21 ,*rez,*success); 
#endif 
;};/* RULE */ 
