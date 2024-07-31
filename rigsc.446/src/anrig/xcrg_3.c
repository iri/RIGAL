
#include "globrig.h" 
#include "define.h"  
#include "defpage.h" 
#include "nef2.h"    
#include "c1.h"      
#include "usemod.h"  
#include "def180.h"  
#include "xcrg.h"    
/*  R8 prostoj_ssablon */ 
/*  R9 ssablon_spiska */ 
/*===============================================*/ 
/* GENERATED TEXT OF RULE   #prostoj_ssablon   */ 
 Void r8(rez,success,pl)
long *rez;boolean *success;ptr_ *pl; 
{  a rez1;  boolean success1; long k; mpd x; 
v loc1;/* $E*/ 
v loc2;/* $mesto*/ 
v loc3;/* $S*/ 
v loc4;/* $WORK_PL*/ 
v loc5;/* $metka_uspeha*/ 
v wrk1;
v wrk2;
v wrk3;
v wrk4;
v wrk5;
ptr_ pl1;
ptr_ pl2;
ptr_ pl3;
ptr_ pl4;
boolean flag1;
boolean flag2;
#ifdef XX  
 d(1,"prostoj_ssablon", 8 ,pl->cel,0); 
#endif 
/* sohranitx GLOB */ 

/* branch */ pl1=*pl;rez1=NULL;success1=true; 
/* inicializaciq peremennyh */ 
loc1.sa=NULL;/* $E*/ 

loc1 .sa=NULL; 

/* Alternative pattern */ 
pl2=pl1;
/* nonatomic alternative branches */ 

/* shablon prawila */ r9(&rez1,&success1,&pl1);
if( !success1 ) goto _L101;
goto _L103/*uspeh*/;
_L101:; 
pl1=pl2;

/* shablon prawila */ r10(&rez1,&success1,&pl1);
if( !success1 ) goto _L102;
goto _L103/*uspeh*/;
_L102:; 
pl1=pl2;
goto  _L104;
_L103:;/*uspeh alxtern.*/
loc1 .sa=rez1; 

/* RETURN-op. */ 
rez1 = loc1 .sa ;goto _L98 ;xxx; 
goto _L99;  _L104:;  /* metka wyhoda po neuspehu wetwi */

/* branch */ pl1=*pl;rez1=NULL;success1=true; 
/* inicializaciq peremennyh */ 

/* shablon VPAT */ 
wrk1.sa=pl1.cel;
bltin(&wrk2,&flag1,wrk1.sa,21L); 
/* operaciq = */ wrk3 .bo= eqnum( wrk2 .sa , 0L ) ; 
success1= wrk3 .bo ;if( success1 ) { 
rez1=pl1.cel;
   ;} else { rez1=NULL;goto _L105 ;};

bltin1(&rez1,&success1,&pl1,11L);
if( !success1 ) goto _L105;

/* RETURN-op. */ 
wrk1 .sa =NULL; 
lconc(& wrk1 .sa , cnst[1] .sa ); 
/* operaciq :: */ wrk2 .sa=NULL; 
if( wrk1 .sa!=NULL ) { points( wrk1 .sa,&x.sa); 
x.smtd->name= cnst[29] .sa ; wrk2 = wrk1 ;}; 
rez1 = wrk2 .sa ;goto _L98 ;xxx; 
goto _L99;  _L105:;  /* metka wyhoda po neuspehu wetwi */

/* branch */ pl1=*pl;rez1=NULL;success1=true; 
/* inicializaciq peremennyh */ 
loc1.sa=NULL;/* $E*/ 
loc2.sa=NULL;/* $mesto*/ 

/* shablon VPAT */ 
wrk1.sa=pl1.cel;
bltin(&wrk2,&flag1,wrk1.sa,10L); 
wrk3 .bo= wrk2 .sa==NULL; 
success1= wrk3 .bo ;if( success1 ) { 
rez1=pl1.cel;
   ;} else { rez1=NULL;goto _L107 ;};

loc1 .sa=NULL; 

bltin1(&rez1,&success1,&pl1,3L);
if( !success1 ) goto _L107;
loc1 .sa=rez1; 

/* IF-operator */ 
bltin(&wrk1,&flag1,loc1.sa,4L); 
wrk2 .bo= wrk1 .sa==NULL; 
if( wrk2 .bo) 
{ 
/* operator := */ 
/* CALL #L */ 
pl3.ptrtype=packedlist;pl3.nel=1;pl3.cel=loc1.sa;
pl3.UU.plistelt[ 0 ]=glob1_2.sa;
pl3.plistsize= 2;
r41(&wrk1.sa,&flag1,&pl3);/* #GETCNST*/ ; 
loc2 .sa= wrk1 .sa ;xxx; 
;} 
_L106:;xxx; 

/* RETURN-op. */ 
wrk1 .sa =NULL; 
addel( acnst[ 46 ],false,NULL, loc1 .sa ,& wrk1 .sa ); 
addel( acnst[ 47 ],false,NULL, loc2 .sa ,& wrk1 .sa ); 
/* operaciq :: */ wrk2 .sa=NULL; 
if( wrk1 .sa!=NULL ) { points( wrk1 .sa,&x.sa); 
x.smtd->name= cnst[30] .sa ; wrk2 = wrk1 ;}; 
rez1 = wrk2 .sa ;goto _L98 ;xxx; 
goto _L99;  _L107:;  /* metka wyhoda po neuspehu wetwi */

/* branch */ pl1=*pl;rez1=NULL;success1=true; 
/* inicializaciq peremennyh */ 
loc1.sa=NULL;/* $E*/ 

loc1 .sa=NULL; 

bltin1(&rez1,&success1,&pl1,17L);
if( !success1 ) goto _L108;
loc1 .sa=rez1; 

/* CALL #L */ 
pl3.ptrtype=packedlist;pl3.nel=1;pl3.cel=glob2_5.sa;
pl3.UU.plistelt[ 0 ]=loc1.sa;
pl3.plistsize= 2;
r38(&wrk1.sa,&flag1,&pl3);/* #TAB*/ ;xxx; 

/* RETURN-op. */ 
wrk1 .sa =NULL; 
addel( acnst[ 41 ],false,NULL, loc1 .sa ,& wrk1 .sa ); 
/* operaciq :: */ wrk2 .sa=NULL; 
if( wrk1 .sa!=NULL ) { points( wrk1 .sa,&x.sa); 
x.smtd->name= cnst[27] .sa ; wrk2 = wrk1 ;}; 
rez1 = wrk2 .sa ;goto _L98 ;xxx; 
goto _L99;  _L108:;  /* metka wyhoda po neuspehu wetwi */

/* branch */ pl1=*pl;rez1=NULL;success1=true; 
/* inicializaciq peremennyh */ 
loc1.sa=NULL;/* $E*/ 
loc3.sa=NULL;/* $S*/ 

loc1 .sa=NULL; 

bltin1(&rez1,&success1,&pl1,16L);
if( !success1 ) goto _L110;
loc1 .sa=rez1; 

/* operator := */ 
/* CALL #L */ 
pl3.ptrtype=packedlist;pl3.nel=1;pl3.cel=loc1.sa;
pl3.plistsize= 1;
r14(&wrk1.sa,&flag1,&pl3);/* #BUILTIN*/ ; 
loc3 .sa= wrk1 .sa ;xxx; 

/* IF-operator */ 
if( loc3 .sa!=NULL) 
{ 
/* RETURN-op. */ 
wrk1 .sa =NULL; 
lconc(& wrk1 .sa , loc3 .sa ); 
/* operaciq :: */ wrk2 .sa=NULL; 
if( wrk1 .sa!=NULL ) { points( wrk1 .sa,&x.sa); 
x.smtd->name= cnst[31] .sa ; wrk2 = wrk1 ;}; 
rez1 = wrk2 .sa ;goto _L98 ;xxx; 
goto _L109;
;} 
/* operaciq = */ wrk3 .bo= eqatom( loc1 .sa ,acnst[ 48 ]) ; 
if( wrk3 .bo ) wrk5 .bo=true; else { 
/* operaciq = */ wrk4 .bo= eqatom( loc1 .sa ,acnst[ 49 ]) ; wrk5 = wrk4 ;}; 
if( wrk5 .bo) 
{ 
/* RETURN-op. */ 
wrk1 .sa =NULL; 
lconc(& wrk1 .sa , cnst[1] .sa ); 
/* operaciq :: */ wrk2 .sa=NULL; 
if( wrk1 .sa!=NULL ) { points( wrk1 .sa,&x.sa); 
x.smtd->name= loc1 .sa ; wrk2 = wrk1 ;}; 
rez1 = wrk2 .sa ;goto _L98 ;xxx; 
goto _L109;
;} 
{ 
/* CALL #L */ 
pl3.ptrtype=packedlist;pl3.nel=1;pl3.cel=loc1.sa;
pl3.plistsize= 1;
r46(&wrk1.sa,&flag1,&pl3);/* #CROSS*/ ;xxx; 
/* RETURN-op. */ 
wrk1 .sa =NULL; 
lconc(& wrk1 .sa , loc1 .sa ); 
/* operaciq :: */ wrk2 .sa=NULL; 
if( wrk1 .sa!=NULL ) { points( wrk1 .sa,&x.sa); 
x.smtd->name= cnst[32] .sa ; wrk2 = wrk1 ;}; 
rez1 = wrk2 .sa ;goto _L98 ;xxx; 
;} 
_L109:;xxx; 
goto _L99;  _L110:;  /* metka wyhoda po neuspehu wetwi */

/* branch */ pl1=*pl;rez1=NULL;success1=true; 
/* inicializaciq peremennyh */ 
loc1.sa=NULL;/* $E*/ 

/* shablon VPAT */ 
wrk1.sa=pl1.cel;
wrk4 .sa=NULL; 
lconc(& wrk4 .sa , cnst[33] .sa ); 
mknumb( 39L,& wrk2 .sa); 
bltin(&wrk3,&flag2,wrk2.sa,22L); 
lconc(& wrk4 .sa , wrk3 .sa ); 
first(wrk4.sa,&pl3);implod(&pl3,&wrk4.sa); 
/* operaciq = */ wrk5 .bo= eqop(0L, wrk1 .sa , wrk4 .sa ) ; 
success1= wrk5 .bo ;if( success1 ) { 
rez1=pl1.cel;
   ;} else { rez1=NULL;goto _L111 ;};

bltin1(&rez1,&success1,&pl1,10L);
if( !success1 ) goto _L111;

/* shablon VPAT */ 
wrk1.sa=pl1.cel;
/* operaciq = */ wrk2 .bo= eqatom( wrk1 .sa ,acnst[ 36 ]) ; 
success1= wrk2 .bo ;if( success1 ) { 
rez1=pl1.cel;
   ;} else { rez1=NULL;goto _L111 ;};

bltin1(&rez1,&success1,&pl1,10L);
if( !success1 ) goto _L111;

/* operator := */ 
mknumb( 0L,& wrk1 .sa); 
glob2_1 .sa= wrk1 .sa ;xxx; 

loc1 .sa=NULL; 

/* shablon prawila */ r15(&rez1,&success1,&pl1);
if( !success1 ) goto _L111;
loc1 .sa=rez1; 

/* shablon VPAT */ 
wrk1.sa=pl1.cel;
/* operaciq = */ wrk2 .bo= eqatom( wrk1 .sa ,acnst[ 25 ]) ; 
success1= wrk2 .bo ;if( success1 ) { 
rez1=pl1.cel;
   ;} else { rez1=NULL;goto _L111 ;};

bltin1(&rez1,&success1,&pl1,10L);
if( !success1 ) goto _L111;

/* RETURN-op. */ 
wrk1 .sa =NULL; 
lconc(& wrk1 .sa , loc1 .sa ); 
/* operaciq :: */ wrk2 .sa=NULL; 
if( wrk1 .sa!=NULL ) { points( wrk1 .sa,&x.sa); 
x.smtd->name= cnst[34] .sa ; wrk2 = wrk1 ;}; 
rez1 = wrk2 .sa ;goto _L98 ;xxx; 
goto _L99;  _L111:;  /* metka wyhoda po neuspehu wetwi */

/* branch */ pl1=*pl;rez1=NULL;success1=true; 
/* inicializaciq peremennyh */ 
loc1.sa=NULL;/* $E*/ 

/* shablon VPAT */ 
wrk1.sa=pl1.cel;
wrk4 .sa=NULL; 
lconc(& wrk4 .sa , cnst[35] .sa ); 
mknumb( 39L,& wrk2 .sa); 
bltin(&wrk3,&flag2,wrk2.sa,22L); 
lconc(& wrk4 .sa , wrk3 .sa ); 
first(wrk4.sa,&pl3);implod(&pl3,&wrk4.sa); 
/* operaciq = */ wrk5 .bo= eqop(0L, wrk1 .sa , wrk4 .sa ) ; 
success1= wrk5 .bo ;if( success1 ) { 
rez1=pl1.cel;
   ;} else { rez1=NULL;goto _L112 ;};

bltin1(&rez1,&success1,&pl1,10L);
if( !success1 ) goto _L112;

/* shablon VPAT */ 
wrk1.sa=pl1.cel;
/* operaciq = */ wrk2 .bo= eqatom( wrk1 .sa ,acnst[ 36 ]) ; 
success1= wrk2 .bo ;if( success1 ) { 
rez1=pl1.cel;
   ;} else { rez1=NULL;goto _L112 ;};

bltin1(&rez1,&success1,&pl1,10L);
if( !success1 ) goto _L112;

/* operator := */ 
mknumb( 0L,& wrk1 .sa); 
glob2_1 .sa= wrk1 .sa ;xxx; 

loc1 .sa=NULL; 

/* shablon prawila */ r15(&rez1,&success1,&pl1);
if( !success1 ) goto _L112;
loc1 .sa=rez1; 

/* shablon VPAT */ 
wrk1.sa=pl1.cel;
/* operaciq = */ wrk2 .bo= eqatom( wrk1 .sa ,acnst[ 25 ]) ; 
success1= wrk2 .bo ;if( success1 ) { 
rez1=pl1.cel;
   ;} else { rez1=NULL;goto _L112 ;};

bltin1(&rez1,&success1,&pl1,10L);
if( !success1 ) goto _L112;

/* RETURN-op. */ 
wrk1 .sa =NULL; 
lconc(& wrk1 .sa , loc1 .sa ); 
/* operaciq :: */ wrk2 .sa=NULL; 
if( wrk1 .sa!=NULL ) { points( wrk1 .sa,&x.sa); 
x.smtd->name= cnst[36] .sa ; wrk2 = wrk1 ;}; 
rez1 = wrk2 .sa ;goto _L98 ;xxx; 
goto _L99;  _L112:;  /* metka wyhoda po neuspehu wetwi */

/* branch */ pl1=*pl;rez1=NULL;success1=true; 
/* inicializaciq peremennyh */ 
loc1.sa=NULL;/* $E*/ 
loc3.sa=NULL;/* $S*/ 
loc4.sa=NULL;/* $WORK_PL*/ 
loc5.sa=NULL;/* $metka_uspeha*/ 

/* shablon VPAT */ 
wrk1.sa=pl1.cel;
/* operaciq = */ wrk2 .bo= eqatom( wrk1 .sa ,acnst[ 36 ]) ; 
success1= wrk2 .bo ;if( success1 ) { 
rez1=pl1.cel;
   ;} else { rez1=NULL;goto _L117 ;};

bltin1(&rez1,&success1,&pl1,10L);
if( !success1 ) goto _L117;

/* operator := */ 
/* CALL #L */ 
pl3.ptrtype=ptrlist;pl3.nel=0;pl3.cel=NULL;
r42(&wrk1.sa,&flag1,&pl3);/* #GET_WORK_PL*/ ; 
loc4 .sa= wrk1 .sa ;xxx; 

/*shablon STARLIST */ 
 pl3=pl1;while(pl1.nel!=0 ) { 

/* operator := */ 
loc3 .sa= NULL ;xxx; 

/* shablon [ ... ] */ pl4=pl1;


/* shablon prawila */ r28(&rez1,&success1,&pl1);
if( !success1 ) goto _L113;
concop(& loc3 .sa,rez1); 
_L113:if( ! success1 ) pl1=pl4;success1=true;


/* shablon prawila */ r6(&rez1,&success1,&pl1);
if( !success1 ) goto _L116;
lconc(& loc3 .sa,rez1); 

/* shablon [ ... ] */ pl4=pl1;


/* shablon prawila */ r28(&rez1,&success1,&pl1);
if( !success1 ) goto _L114;
concop(& loc3 .sa,rez1); 
_L114:if( ! success1 ) pl1=pl4;success1=true;

/* operator !.:= */ 
wrk2 .sa =NULL; 
/* CALL #L */ 
pl4.ptrtype=ptrlist;pl4.nel=0;pl4.cel=NULL;
r44(&wrk1.sa,&flag1,&pl4);/* #NEW_LABEL*/ ; 
lconc(& wrk2 .sa , wrk1 .sa ); 
wrk3 .sa= wrk2 .sa ; 
concop(& wrk3 .sa, loc3 .sa ); 
lconc(& loc1 .sa, wrk3 .sa ) ;xxx; 
 pl3=pl1;

/* shablon prawila */ r5(&rez1,&success1,&pl1);
if( !success1 ) goto _L115;
;}; 
_L116:if( ! success1 )pl1=pl3;
_L115:;
success1 = true ; 

/* shablon VPAT */ 
wrk1.sa=pl1.cel;
/* operaciq = */ wrk2 .bo= eqatom( wrk1 .sa ,acnst[ 25 ]) ; 
success1= wrk2 .bo ;if( success1 ) { 
rez1=pl1.cel;
   ;} else { rez1=NULL;goto _L117 ;};

bltin1(&rez1,&success1,&pl1,10L);
if( !success1 ) goto _L117;

/* operator := */ 
/* CALL #L */ 
pl3.ptrtype=ptrlist;pl3.nel=0;pl3.cel=NULL;
r44(&wrk1.sa,&flag1,&pl3);/* #NEW_LABEL*/ ; 
loc5 .sa= wrk1 .sa ;xxx; 

/* RETURN-op. */ 
wrk1 .sa =NULL; 
addel( acnst[ 37 ],false,NULL, loc5 .sa ,& wrk1 .sa ); 
addel( acnst[ 26 ],false,NULL, loc4 .sa ,& wrk1 .sa ); 
addel( acnst[ 21 ],false,NULL, loc1 .sa ,& wrk1 .sa ); 
/* operaciq :: */ wrk2 .sa=NULL; 
if( wrk1 .sa!=NULL ) { points( wrk1 .sa,&x.sa); 
x.smtd->name= cnst[26] .sa ; wrk2 = wrk1 ;}; 
rez1 = wrk2 .sa ;goto _L98 ;xxx; 
goto _L99;  _L117:;  /* metka wyhoda po neuspehu wetwi */
 _L99: rez1=NULL; 
 _L98: *rez=rez1;*success=success1; 
 if (*success) *pl=pl1; /* prodwinutx ukazatelx leksem */ 
/* wosstanowitx GLOB */ 
#ifdef XX  
 d(2,"prostoj_ssablon", 8 ,*rez,*success); 
#endif 
;};/* RULE */ 
/*===============================================*/ 
/* GENERATED TEXT OF RULE   #ssablon_spiska   */ 
 Void r9(rez,success,pl)
long *rez;boolean *success;ptr_ *pl; 
{  a rez1;  boolean success1; long k; mpd x; 
v loc1;/* $E*/ 
v loc2;/* $WORK_PL*/ 
v loc3;/* $R*/ 
v wrk1;
v wrk2;
ptr_ pl1;
ptr_ pl2;
boolean flag1;
#ifdef XX  
 d(1,"ssablon_spiska", 9 ,pl->cel,0); 
#endif 
/* sohranitx GLOB */ 

/* branch */ pl1=*pl;rez1=NULL;success1=true; 
/* inicializaciq peremennyh */ 
loc1.sa=NULL;/* $E*/ 
loc2.sa=NULL;/* $WORK_PL*/ 
loc3.sa=NULL;/* $R*/ 

/* shablon [ ... ] */ pl2=pl1;

loc1 .sa=NULL; 

/* shablon prawila */ r11(&rez1,&success1,&pl1);
if( !success1 ) goto _L101;
loc1 .sa=rez1; 
_L101:if( ! success1 ) pl1=pl2;success1=true;

/* shablon VPAT */ 
wrk1.sa=pl1.cel;
/* operaciq = */ wrk2 .bo= eqatom( wrk1 .sa ,acnst[ 50 ]) ; 
success1= wrk2 .bo ;if( success1 ) { 
rez1=pl1.cel;
   ;} else { rez1=NULL;goto _L102 ;};

bltin1(&rez1,&success1,&pl1,10L);
if( !success1 ) goto _L102;

/* operator := */ 
/* CALL #L */ 
pl2.ptrtype=ptrlist;pl2.nel=0;pl2.cel=NULL;
r42(&wrk1.sa,&flag1,&pl2);/* #GET_WORK_PL*/ ; 
loc2 .sa= wrk1 .sa ;xxx; 

loc3 .sa=NULL; 

/* shablon prawila */ r27(&rez1,&success1,&pl1);
if( !success1 ) goto _L102;
loc3 .sa=rez1; 

/* shablon VPAT */ 
wrk1.sa=pl1.cel;
/* operaciq = */ wrk2 .bo= eqatom( wrk1 .sa ,acnst[ 51 ]) ; 
success1= wrk2 .bo ;if( success1 ) { 
rez1=pl1.cel;
   ;} else { rez1=NULL;goto _L102 ;};

bltin1(&rez1,&success1,&pl1,10L);
if( !success1 ) goto _L102;

/* operator := */ 
wrk1 .nu= numval( glob2_4 .sa) - 1L ; 
mknumb( wrk1 .nu ,& wrk2 .sa); 
glob2_4 .sa= wrk2 .sa ;xxx; 

/* RETURN-op. */ 
wrk1 .sa =NULL; 
addel( acnst[ 41 ],false,NULL, loc1 .sa ,& wrk1 .sa ); 
addel( acnst[ 26 ],false,NULL, loc2 .sa ,& wrk1 .sa ); 
addel( acnst[ 21 ],false,NULL, loc3 .sa ,& wrk1 .sa ); 
/* operaciq :: */ wrk2 .sa=NULL; 
if( wrk1 .sa!=NULL ) { points( wrk1 .sa,&x.sa); 
x.smtd->name= cnst[37] .sa ; wrk2 = wrk1 ;}; 
rez1 = wrk2 .sa ;goto _L98 ;xxx; 
goto _L99;  _L102:;  /* metka wyhoda po neuspehu wetwi */
 _L99: rez1=NULL; 
 _L98: *rez=rez1;*success=success1; 
 if (*success) *pl=pl1; /* prodwinutx ukazatelx leksem */ 
/* wosstanowitx GLOB */ 
#ifdef XX  
 d(2,"ssablon_spiska", 9 ,*rez,*success); 
#endif 
;};/* RULE */ 
