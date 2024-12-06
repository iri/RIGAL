
#include "globrig.h" 
#include "define.h"  
#include "defpage.h" 
#include "nef2.h"    
#include "c1.h"      
#include "usemod.h"  
#include "def180.h"  
#include "xcrg.h"    
/*  R10 ssablon_derewa */ 
/*  R11 NAME_PAT */ 
/*  R12 |l_t_ss_derewa */ 
/*  R13 COMMA */ 
/*  R14 BUILTIN */ 
/*===============================================*/ 
/* GENERATED TEXT OF RULE   #ssablon_derewa   */ 
 Void r10(rez,success,pl)
long *rez;boolean *success;ptr_ *pl; 
{  a rez1;  boolean success1; long k; mpd x; 
v loc1;/* $E*/ 
v loc2;/* $WORK_PL*/ 
v loc3;/* $B*/ 
v loc4;/* $VAR*/ 
v loc5;/* $P*/ 
v wrk1;
v wrk2;
v wrk3;
ptr_ pl1;
ptr_ pl2;
boolean flag1;
#ifdef XX  
 d(1,"ssablon_derewa", 10 ,pl->cel,0); 
#endif 
/* sohranitx GLOB */ 

/* branch */ pl1=*pl;rez1=NULL;success1=true; 
/* inicializaciq peremennyh */ 
loc1.sa=NULL;/* $E*/ 
loc2.sa=NULL;/* $WORK_PL*/ 
loc3.sa=NULL;/* $B*/ 

/* shablon [ ... ] */ pl2=pl1;

loc1 .sa=NULL; 

/* shablon prawila */ r11(&rez1,&success1,&pl1);
if( !success1 ) goto _L101;
loc1 .sa=rez1; 
_L101:if( ! success1 ) pl1=pl2;success1=true;

/* shablon VPAT */ 
wrk1.sa=pl1.cel;
/* operaciq = */ wrk2 .bo= eqatom( wrk1 .sa ,acnst[ 52 ]) ; 
success1= wrk2 .bo ;if( success1 ) { 
rez1=pl1.cel;
   ;} else { rez1=NULL;goto _L104 ;};

bltin1(&rez1,&success1,&pl1,10L);
if( !success1 ) goto _L104;

/* operator := */ 
/* CALL #L */ 
pl2.ptrtype=ptrlist;pl2.nel=0;pl2.cel=NULL;
r42(&wrk1.sa,&flag1,&pl2);/* #GET_WORK_PL*/ ; 
loc2 .sa= wrk1 .sa ;xxx; 

/*shablon STARLIST */ 
 pl2=pl1;while(pl1.nel!=0 ) { 


/* shablon prawila */ r12(&rez1,&success1,&pl1);
if( !success1 ) goto _L103;
lconc(& loc3 .sa,rez1); 
 pl2=pl1;

/* shablon prawila */ r13(&rez1,&success1,&pl1);
if( !success1 ) goto _L102;
;}; 
_L103:if( ! success1 )pl1=pl2;
_L102:;
success1 = true ; 

/* shablon VPAT */ 
wrk1.sa=pl1.cel;
/* operaciq = */ wrk2 .bo= eqatom( wrk1 .sa ,acnst[ 53 ]) ; 
success1= wrk2 .bo ;if( success1 ) { 
rez1=pl1.cel;
   ;} else { rez1=NULL;goto _L104 ;};

bltin1(&rez1,&success1,&pl1,10L);
if( !success1 ) goto _L104;

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
x.smtd->name= cnst[38] .sa ; wrk2 = wrk1 ;}; 
rez1 = wrk2 .sa ;goto _L98 ;xxx; 
goto _L99;  _L104:;  /* metka wyhoda po neuspehu wetwi */

/* branch */ pl1=*pl;rez1=NULL;success1=true; 
/* inicializaciq peremennyh */ 
loc1.sa=NULL;/* $E*/ 
loc2.sa=NULL;/* $WORK_PL*/ 
loc3.sa=NULL;/* $B*/ 
loc4.sa=NULL;/* $VAR*/ 
loc5.sa=NULL;/* $P*/ 

/* shablon [ ... ] */ pl2=pl1;

loc1 .sa=NULL; 

/* shablon prawila */ r11(&rez1,&success1,&pl1);
if( !success1 ) goto _L105;
loc1 .sa=rez1; 
_L105:if( ! success1 ) pl1=pl2;success1=true;

/* shablon VPAT */ 
wrk1.sa=pl1.cel;
/* operaciq = */ wrk2 .bo= eqatom( wrk1 .sa ,acnst[ 54 ]) ; 
success1= wrk2 .bo ;if( success1 ) { 
rez1=pl1.cel;
   ;} else { rez1=NULL;goto _L109 ;};

bltin1(&rez1,&success1,&pl1,10L);
if( !success1 ) goto _L109;

/* operator := */ 
/* CALL #L */ 
pl2.ptrtype=ptrlist;pl2.nel=0;pl2.cel=NULL;
r42(&wrk1.sa,&flag1,&pl2);/* #GET_WORK_PL*/ ; 
loc2 .sa= wrk1 .sa ;xxx; 

/*shablon STARLIST */ 
 pl2=pl1;while(pl1.nel!=0 ) { 


/* shablon prawila */ r12(&rez1,&success1,&pl1);
if( !success1 ) goto _L106;
lconc(& loc3 .sa,rez1); 

/* shablon prawila */ r13(&rez1,&success1,&pl1);
if( !success1 ) goto _L106;
 pl2=pl1;
;}; 
_L106:if( ! success1 )pl1=pl2;
success1 = true ; 

loc4 .sa=NULL; 

bltin1(&rez1,&success1,&pl1,17L);
if( !success1 ) goto _L109;
loc4 .sa=rez1; 

/* CALL #L */ 
pl2.ptrtype=packedlist;pl2.nel=1;pl2.cel=glob2_5.sa;
pl2.UU.plistelt[ 0 ]=loc4.sa;
pl2.plistsize= 2;
r38(&wrk1.sa,&flag1,&pl2);/* #TAB*/ ;xxx; 

/* CALL #L */ 
pl2.ptrtype=packedlist;pl2.nel=1;pl2.cel=loc4.sa;
pl2.plistsize= 1;
r37(&wrk1.sa,&flag1,&pl2);/* #ADD_USEVAR*/ ;xxx; 

/* operator !.:= */ 
wrk1 .sa =NULL; 
addel( acnst[ 41 ],false,NULL, loc4 .sa ,& wrk1 .sa ); 
/* operaciq :: */ wrk2 .sa=NULL; 
if( wrk1 .sa!=NULL ) { points( wrk1 .sa,&x.sa); 
x.smtd->name= cnst[27] .sa ; wrk2 = wrk1 ;}; 
lconc(& loc5 .sa, wrk2 .sa ) ;xxx; 

/* shablon VPAT */ 
wrk1.sa=pl1.cel;
/* operaciq = */ wrk2 .bo= eqatom( wrk1 .sa ,acnst[ 55 ]) ; 
success1= wrk2 .bo ;if( success1 ) { 
rez1=pl1.cel;
   ;} else { rez1=NULL;goto _L109 ;};

bltin1(&rez1,&success1,&pl1,10L);
if( !success1 ) goto _L109;

/* shablon [ ... ] */ pl2=pl1;


/* shablon prawila */ r28(&rez1,&success1,&pl1);
if( !success1 ) goto _L107;
concop(& loc5 .sa,rez1); 
_L107:if( ! success1 ) pl1=pl2;success1=true;


/* shablon prawila */ r6(&rez1,&success1,&pl1);
if( !success1 ) goto _L109;
lconc(& loc5 .sa,rez1); 

/* shablon [ ... ] */ pl2=pl1;


/* shablon prawila */ r28(&rez1,&success1,&pl1);
if( !success1 ) goto _L108;
concop(& loc5 .sa,rez1); 
_L108:if( ! success1 ) pl1=pl2;success1=true;

/* shablon VPAT */ 
wrk1.sa=pl1.cel;
/* operaciq = */ wrk2 .bo= eqatom( wrk1 .sa ,acnst[ 56 ]) ; 
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
wrk2 .sa =NULL; 
addel( acnst[ 41 ],false,NULL, loc1 .sa ,& wrk2 .sa ); 
addel( acnst[ 26 ],false,NULL, loc2 .sa ,& wrk2 .sa ); 
/* CALL #L */ 
pl2.ptrtype=ptrlist;pl2.nel=0;pl2.cel=NULL;
r44(&wrk1.sa,&flag1,&pl2);/* #NEW_LABEL*/ ; 
addel( acnst[ 27 ],false,NULL, wrk1 .sa ,& wrk2 .sa ); 
addel( acnst[ 21 ],false,NULL, loc3 .sa ,& wrk2 .sa ); 
addel( acnst[ 57 ],false,NULL, loc5 .sa ,& wrk2 .sa ); 
/* operaciq :: */ wrk3 .sa=NULL; 
if( wrk2 .sa!=NULL ) { points( wrk2 .sa,&x.sa); 
x.smtd->name= cnst[38] .sa ; wrk3 = wrk2 ;}; 
rez1 = wrk3 .sa ;goto _L98 ;xxx; 
goto _L99;  _L109:;  /* metka wyhoda po neuspehu wetwi */
 _L99: rez1=NULL; 
 _L98: *rez=rez1;*success=success1; 
 if (*success) *pl=pl1; /* prodwinutx ukazatelx leksem */ 
/* wosstanowitx GLOB */ 
#ifdef XX  
 d(2,"ssablon_derewa", 10 ,*rez,*success); 
#endif 
;};/* RULE */ 
/*===============================================*/ 
/* GENERATED TEXT OF RULE   #NAME_PAT   */ 
 Void r11(rez,success,pl)
long *rez;boolean *success;ptr_ *pl; 
{  a rez1;  boolean success1; long k; mpd x; 
v loc1;/* $E*/ 
v wrk1;
v wrk2;
v wrk3;
ptr_ pl1;
ptr_ pl2;
boolean flag1;
#ifdef XX  
 d(1,"NAME_PAT", 11 ,pl->cel,0); 
#endif 
/* sohranitx GLOB */ 

/* branch */ pl1=*pl;rez1=NULL;success1=true; 
/* inicializaciq peremennyh */ 
loc1.sa=NULL;/* $E*/ 

/* shablon VPAT */ 
wrk1.sa=pl1.cel;
bltin(&wrk2,&flag1,wrk1.sa,10L); 
wrk3 .bo= wrk2 .sa==NULL; 
success1= wrk3 .bo ;if( success1 ) { 
rez1=pl1.cel;
   ;} else { rez1=NULL;goto _L102 ;};

loc1 .sa=NULL; 

bltin1(&rez1,&success1,&pl1,3L);
if( !success1 ) goto _L102;
loc1 .sa=rez1; 

/* shablon VPAT */ 
wrk1.sa=pl1.cel;
/* operaciq = */ wrk2 .bo= eqatom( wrk1 .sa ,acnst[ 58 ]) ; 
success1= wrk2 .bo ;if( success1 ) { 
rez1=pl1.cel;
   ;} else { rez1=NULL;goto _L102 ;};

bltin1(&rez1,&success1,&pl1,10L);
if( !success1 ) goto _L102;

/* IF-operator */ 
bltin(&wrk1,&flag1,loc1.sa,4L); 
if( wrk1 .sa!=NULL) 
{ 
/* RETURN-op. */ 
wrk1 .sa =NULL; 
lconc(& wrk1 .sa , loc1 .sa ); 
/* operaciq :: */ wrk2 .sa=NULL; 
if( wrk1 .sa!=NULL ) { points( wrk1 .sa,&x.sa); 
x.smtd->name= cnst[39] .sa ; wrk2 = wrk1 ;}; 
rez1 = wrk2 .sa ;goto _L98 ;xxx; 
goto _L101;
;} 
{ 
/* RETURN-op. */ 
wrk2 .sa =NULL; 
/* CALL #L */ 
pl2.ptrtype=packedlist;pl2.nel=1;pl2.cel=loc1.sa;
pl2.UU.plistelt[ 0 ]=glob1_2.sa;
pl2.plistsize= 2;
r41(&wrk1.sa,&flag1,&pl2);/* #GETCNST*/ ; 
lconc(& wrk2 .sa , wrk1 .sa ); 
/* operaciq :: */ wrk3 .sa=NULL; 
if( wrk2 .sa!=NULL ) { points( wrk2 .sa,&x.sa); 
x.smtd->name= cnst[40] .sa ; wrk3 = wrk2 ;}; 
rez1 = wrk3 .sa ;goto _L98 ;xxx; 
;} 
_L101:;xxx; 
goto _L99;  _L102:;  /* metka wyhoda po neuspehu wetwi */

/* branch */ pl1=*pl;rez1=NULL;success1=true; 
/* inicializaciq peremennyh */ 
loc1.sa=NULL;/* $E*/ 

loc1 .sa=NULL; 

bltin1(&rez1,&success1,&pl1,17L);
if( !success1 ) goto _L103;
loc1 .sa=rez1; 

/* shablon VPAT */ 
wrk1.sa=pl1.cel;
/* operaciq = */ wrk2 .bo= eqatom( wrk1 .sa ,acnst[ 58 ]) ; 
success1= wrk2 .bo ;if( success1 ) { 
rez1=pl1.cel;
   ;} else { rez1=NULL;goto _L103 ;};

bltin1(&rez1,&success1,&pl1,10L);
if( !success1 ) goto _L103;

/* CALL #L */ 
pl2.ptrtype=packedlist;pl2.nel=1;pl2.cel=glob2_5.sa;
pl2.UU.plistelt[ 0 ]=loc1.sa;
pl2.plistsize= 2;
r38(&wrk1.sa,&flag1,&pl2);/* #TAB*/ ;xxx; 

/* CALL #L */ 
pl2.ptrtype=packedlist;pl2.nel=1;pl2.cel=loc1.sa;
pl2.plistsize= 1;
r37(&wrk1.sa,&flag1,&pl2);/* #ADD_USEVAR*/ ;xxx; 

/* RETURN-op. */ 
wrk1 .sa =NULL; 
addel( acnst[ 41 ],false,NULL, loc1 .sa ,& wrk1 .sa ); 
/* operaciq :: */ wrk2 .sa=NULL; 
if( wrk1 .sa!=NULL ) { points( wrk1 .sa,&x.sa); 
x.smtd->name= cnst[27] .sa ; wrk2 = wrk1 ;}; 
rez1 = wrk2 .sa ;goto _L98 ;xxx; 
goto _L99;  _L103:;  /* metka wyhoda po neuspehu wetwi */

/* branch */ pl1=*pl;rez1=NULL;success1=true; 
/* inicializaciq peremennyh */ 

/* shablon VPAT */ 
wrk1.sa=pl1.cel;
bltin(&wrk2,&flag1,wrk1.sa,21L); 
/* operaciq = */ wrk3 .bo= eqnum( wrk2 .sa , 0L ) ; 
success1= wrk3 .bo ;if( success1 ) { 
rez1=pl1.cel;
   ;} else { rez1=NULL;goto _L104 ;};

bltin1(&rez1,&success1,&pl1,11L);
if( !success1 ) goto _L104;

/* shablon VPAT */ 
wrk1.sa=pl1.cel;
/* operaciq = */ wrk2 .bo= eqatom( wrk1 .sa ,acnst[ 58 ]) ; 
success1= wrk2 .bo ;if( success1 ) { 
rez1=pl1.cel;
   ;} else { rez1=NULL;goto _L104 ;};

bltin1(&rez1,&success1,&pl1,10L);
if( !success1 ) goto _L104;

/* RETURN-op. */ 
rez1 = cnst[29] .sa ;goto _L98 ;xxx; 
goto _L99;  _L104:;  /* metka wyhoda po neuspehu wetwi */
 _L99: rez1=NULL; 
 _L98: *rez=rez1;*success=success1; 
 if (*success) *pl=pl1; /* prodwinutx ukazatelx leksem */ 
/* wosstanowitx GLOB */ 
#ifdef XX  
 d(2,"NAME_PAT", 11 ,*rez,*success); 
#endif 
;};/* RULE */ 
/*===============================================*/ 
/* GENERATED TEXT OF RULE   #|l_t_ss_derewa   */ 
 Void r12(rez,success,pl)
long *rez;boolean *success;ptr_ *pl; 
{  a rez1;  boolean success1; long k; mpd x; 
v loc1;/* $N*/ 
v loc2;/* $A*/ 
v loc3;/* $I*/ 
v loc4;/* $N1*/ 
v wrk1;
v wrk2;
ptr_ pl1;
ptr_ pl2;
ptr_ pl3;
boolean flag1;
#ifdef XX  
 d(1,"|l_t_ss_derewa", 12 ,pl->cel,0); 
#endif 
/* sohranitx GLOB */ 

/* branch */ pl1=*pl;rez1=NULL;success1=true; 
/* inicializaciq peremennyh */ 
loc1.sa=NULL;/* $N*/ 
loc2.sa=NULL;/* $A*/ 
loc3.sa=NULL;/* $I*/ 

/* shablon [ ... ] */ pl2=pl1;

/* shablon VPAT */ 
wrk1.sa=pl1.cel;
/* operaciq = */ wrk2 .bo= eqatom( wrk1 .sa ,acnst[ 34 ]) ; 
success1= wrk2 .bo ;if( success1 ) { 
rez1=pl1.cel;
   ;} else { rez1=NULL;goto _L101 ;};

loc1 .sa=NULL; 

bltin1(&rez1,&success1,&pl1,10L);
if( !success1 ) goto _L101;
loc1 .sa=rez1; 

/* operator !.:= */ 
/* CALL #L */ 
pl3.ptrtype=ptrlist;pl3.nel=0;pl3.cel=NULL;
r44(&wrk1.sa,&flag1,&pl3);/* #NEW_LABEL*/ ; 
lconc(& loc2 .sa, wrk1 .sa ) ;xxx; 
_L101:if( ! success1 ) pl1=pl2;success1=true;

loc3 .sa=NULL; 

bltin1(&rez1,&success1,&pl1,5L);
if( !success1 ) goto _L106;
loc3 .sa=rez1; 

/* operator !.:= */ 
/* CALL #L */ 
pl2.ptrtype=packedlist;pl2.nel=1;pl2.cel=loc3.sa;
pl2.UU.plistelt[ 0 ]=glob1_2.sa;
pl2.plistsize= 2;
r41(&wrk1.sa,&flag1,&pl2);/* #GETCNST*/ ; 
lconc(& loc2 .sa, wrk1 .sa ) ;xxx; 

/* shablon VPAT */ 
wrk1.sa=pl1.cel;
/* operaciq = */ wrk2 .bo= eqatom( wrk1 .sa ,acnst[ 55 ]) ; 
success1= wrk2 .bo ;if( success1 ) { 
rez1=pl1.cel;
   ;} else { rez1=NULL;goto _L106 ;};

bltin1(&rez1,&success1,&pl1,10L);
if( !success1 ) goto _L106;

/* shablon [ ... ] */ pl2=pl1;


/* shablon prawila */ r28(&rez1,&success1,&pl1);
if( !success1 ) goto _L102;
concop(& loc2 .sa,rez1); 
_L102:if( ! success1 ) pl1=pl2;success1=true;


/* shablon prawila */ r6(&rez1,&success1,&pl1);
if( !success1 ) goto _L106;
lconc(& loc2 .sa,rez1); 

/* shablon [ ... ] */ pl2=pl1;


/* shablon prawila */ r28(&rez1,&success1,&pl1);
if( !success1 ) goto _L103;
concop(& loc2 .sa,rez1); 
_L103:if( ! success1 ) pl1=pl2;success1=true;

/* shablon [ ... ] */ pl2=pl1;

/* shablon VPAT */ 
wrk1.sa=pl1.cel;
/* operaciq = */ wrk2 .bo= eqatom( wrk1 .sa ,acnst[ 35 ]) ; 
success1= wrk2 .bo ;if( success1 ) { 
rez1=pl1.cel;
   ;} else { rez1=NULL;goto _L104 ;};

loc4 .sa=NULL; 

bltin1(&rez1,&success1,&pl1,10L);
if( !success1 ) goto _L104;
loc4 .sa=rez1; 
_L104:if( ! success1 ) pl1=pl2;success1=true;

/* IF-operator */ 
if( loc1 .sa!=NULL) 
{ 
/* RETURN-op. */ 
/* operaciq :: */ wrk1 .sa=NULL; 
if( loc2 .sa!=NULL ) { points( loc2 .sa,&x.sa); 
if( (x.smld->dtype==treemain)||(x.smtd->dtype==listmain)) { 
x.smtd->name= cnst[41] .sa ; wrk1 = loc2 ;} ;}; 
rez1 = wrk1 .sa ;goto _L98 ;xxx; 
goto _L105;
;} 
{ 
/* RETURN-op. */ 
rez1 = loc2 .sa ;goto _L98 ;xxx; 
;} 
_L105:;xxx; 
goto _L99;  _L106:;  /* metka wyhoda po neuspehu wetwi */
 _L99: rez1=NULL; 
 _L98: *rez=rez1;*success=success1; 
 if (*success) *pl=pl1; /* prodwinutx ukazatelx leksem */ 
/* wosstanowitx GLOB */ 
#ifdef XX  
 d(2,"|l_t_ss_derewa", 12 ,*rez,*success); 
#endif 
;};/* RULE */ 
/*===============================================*/ 
/* GENERATED TEXT OF RULE   #COMMA   */ 
 Void r13(rez,success,pl)
long *rez;boolean *success;ptr_ *pl; 
{  a rez1;  boolean success1; long k; mpd x; 
v wrk1;
v wrk2;
ptr_ pl1;
#ifdef XX  
 d(1,"COMMA", 13 ,pl->cel,0); 
#endif 
/* sohranitx GLOB */ 

/* branch */ pl1=*pl;rez1=NULL;success1=true; 
/* inicializaciq peremennyh */ 

/* shablon VPAT */ 
wrk1.sa=pl1.cel;
/* operaciq = */ wrk2 .bo= eqatom( wrk1 .sa ,acnst[ 59 ]) ; 
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
 d(2,"COMMA", 13 ,*rez,*success); 
#endif 
;};/* RULE */ 
/*===============================================*/ 
/* GENERATED TEXT OF RULE   #BUILTIN   */ 
 Void r14(rez,success,pl)
long *rez;boolean *success;ptr_ *pl; 
{  a rez1;  boolean success1; long k; mpd x; 
v wrk1;
ptr_ pl1;
ptr_ pl2;
#ifdef XX  
 d(1,"BUILTIN", 14 ,pl->cel,0); 
#endif 
/* sohranitx GLOB */ 

/* branch */ pl1=*pl;rez1=NULL;success1=true; 
/* inicializaciq peremennyh */ 

/* OPT SP */  
/* OPT SP */  
/* OPT SP */  
/* OPT SP */  
/* OPT SP */  
/* OPT SP */  
/* OPT SP */  
/* OPT SP */  
/* OPT SP */  
/* OPT SP */  
/* OPT SP */  
/* OPT SP */  
/* OPT SP */  
/* OPT SP */  
/* OPT SP */  
/* OPT SP */  
/* OPT SP */  
/* OPT SP */  
/* OPT SP */  
/* OPT SP */  
/* OPT SP */  
/* OPT SP */  
/* OPT SP */  
/* Alternative pattern */ 
pl2=pl1;
rez1=pl1.cel;
if ((pl1.nel==0) || (rez1==NULL)) goto _L123;
else { pointr(rez1,&x.sa); 
if (!((x.sad->dtype==atom)|| (x.sad->dtype==idatom)||(x.sad->dtype==keyword) 
||(x.sad->dtype==fatom)) ) goto _L123;
else x.sa=x.sad->name ;}; 

/* atomic branch */ 
if (x.sa==acnst[ 60 ] ) { success1=true; 
 if (pl1.ptrtype!=ptrtree ) 
next(&pl1);

/* RETURN-op. */ 
mknumb( 3L,& wrk1 .sa); 
rez1 = wrk1 .sa ;goto _L98 ;xxx; 
goto _L124;}; _L101:;

/* atomic branch */ 
if (x.sa==acnst[ 61 ] ) { success1=true; 
 if (pl1.ptrtype!=ptrtree ) 
next(&pl1);

/* RETURN-op. */ 
mknumb( 4L,& wrk1 .sa); 
rez1 = wrk1 .sa ;goto _L98 ;xxx; 
goto _L124;}; _L102:;

/* atomic branch */ 
if (x.sa==acnst[ 62 ] ) { success1=true; 
 if (pl1.ptrtype!=ptrtree ) 
next(&pl1);

/* RETURN-op. */ 
mknumb( 5L,& wrk1 .sa); 
rez1 = wrk1 .sa ;goto _L98 ;xxx; 
goto _L124;}; _L103:;

/* atomic branch */ 
if (x.sa==acnst[ 63 ] ) { success1=true; 
 if (pl1.ptrtype!=ptrtree ) 
next(&pl1);

/* RETURN-op. */ 
mknumb( 6L,& wrk1 .sa); 
rez1 = wrk1 .sa ;goto _L98 ;xxx; 
goto _L124;}; _L104:;

/* atomic branch */ 
if (x.sa==acnst[ 64 ] ) { success1=true; 
 if (pl1.ptrtype!=ptrtree ) 
next(&pl1);

/* RETURN-op. */ 
mknumb( 7L,& wrk1 .sa); 
rez1 = wrk1 .sa ;goto _L98 ;xxx; 
goto _L124;}; _L105:;

/* atomic branch */ 
if (x.sa==acnst[ 65 ] ) { success1=true; 
 if (pl1.ptrtype!=ptrtree ) 
next(&pl1);

/* RETURN-op. */ 
mknumb( 8L,& wrk1 .sa); 
rez1 = wrk1 .sa ;goto _L98 ;xxx; 
goto _L124;}; _L106:;

/* atomic branch */ 
if (x.sa==acnst[ 66 ] ) { success1=true; 
 if (pl1.ptrtype!=ptrtree ) 
next(&pl1);

/* RETURN-op. */ 
mknumb( 9L,& wrk1 .sa); 
rez1 = wrk1 .sa ;goto _L98 ;xxx; 
goto _L124;}; _L107:;

/* atomic branch */ 
if (x.sa==acnst[ 67 ] ) { success1=true; 
 if (pl1.ptrtype!=ptrtree ) 
next(&pl1);

/* RETURN-op. */ 
mknumb( 10L,& wrk1 .sa); 
rez1 = wrk1 .sa ;goto _L98 ;xxx; 
goto _L124;}; _L108:;

/* atomic branch */ 
if (x.sa==acnst[ 68 ] ) { success1=true; 
 if (pl1.ptrtype!=ptrtree ) 
next(&pl1);

/* RETURN-op. */ 
mknumb( 11L,& wrk1 .sa); 
rez1 = wrk1 .sa ;goto _L98 ;xxx; 
goto _L124;}; _L109:;

/* atomic branch */ 
if (x.sa==acnst[ 69 ] ) { success1=true; 
 if (pl1.ptrtype!=ptrtree ) 
next(&pl1);

/* RETURN-op. */ 
mknumb( 12L,& wrk1 .sa); 
rez1 = wrk1 .sa ;goto _L98 ;xxx; 
goto _L124;}; _L110:;

/* atomic branch */ 
if (x.sa==acnst[ 70 ] ) { success1=true; 
 if (pl1.ptrtype!=ptrtree ) 
next(&pl1);

/* RETURN-op. */ 
mknumb( 14L,& wrk1 .sa); 
rez1 = wrk1 .sa ;goto _L98 ;xxx; 
goto _L124;}; _L111:;

/* atomic branch */ 
if (x.sa==acnst[ 71 ] ) { success1=true; 
 if (pl1.ptrtype!=ptrtree ) 
next(&pl1);

/* RETURN-op. */ 
mknumb( 15L,& wrk1 .sa); 
rez1 = wrk1 .sa ;goto _L98 ;xxx; 
goto _L124;}; _L112:;

/* atomic branch */ 
if (x.sa==acnst[ 72 ] ) { success1=true; 
 if (pl1.ptrtype!=ptrtree ) 
next(&pl1);

/* RETURN-op. */ 
mknumb( 16L,& wrk1 .sa); 
rez1 = wrk1 .sa ;goto _L98 ;xxx; 
goto _L124;}; _L113:;

/* atomic branch */ 
if (x.sa==acnst[ 73 ] ) { success1=true; 
 if (pl1.ptrtype!=ptrtree ) 
next(&pl1);

/* RETURN-op. */ 
mknumb( 17L,& wrk1 .sa); 
rez1 = wrk1 .sa ;goto _L98 ;xxx; 
goto _L124;}; _L114:;

/* atomic branch */ 
if (x.sa==acnst[ 74 ] ) { success1=true; 
 if (pl1.ptrtype!=ptrtree ) 
next(&pl1);

/* RETURN-op. */ 
mknumb( 19L,& wrk1 .sa); 
rez1 = wrk1 .sa ;goto _L98 ;xxx; 
goto _L124;}; _L115:;

/* atomic branch */ 
if (x.sa==acnst[ 75 ] ) { success1=true; 
 if (pl1.ptrtype!=ptrtree ) 
next(&pl1);

/* RETURN-op. */ 
mknumb( 20L,& wrk1 .sa); 
rez1 = wrk1 .sa ;goto _L98 ;xxx; 
goto _L124;}; _L116:;

/* atomic branch */ 
if (x.sa==acnst[ 76 ] ) { success1=true; 
 if (pl1.ptrtype!=ptrtree ) 
next(&pl1);

/* RETURN-op. */ 
mknumb( 21L,& wrk1 .sa); 
rez1 = wrk1 .sa ;goto _L98 ;xxx; 
goto _L124;}; _L117:;

/* atomic branch */ 
if (x.sa==acnst[ 77 ] ) { success1=true; 
 if (pl1.ptrtype!=ptrtree ) 
next(&pl1);

/* RETURN-op. */ 
mknumb( 22L,& wrk1 .sa); 
rez1 = wrk1 .sa ;goto _L98 ;xxx; 
goto _L124;}; _L118:;

/* atomic branch */ 
if (x.sa==acnst[ 78 ] ) { success1=true; 
 if (pl1.ptrtype!=ptrtree ) 
next(&pl1);

/* RETURN-op. */ 
mknumb( 23L,& wrk1 .sa); 
rez1 = wrk1 .sa ;goto _L98 ;xxx; 
goto _L124;}; _L119:;

/* atomic branch */ 
if (x.sa==acnst[ 79 ] ) { success1=true; 
 if (pl1.ptrtype!=ptrtree ) 
next(&pl1);

/* RETURN-op. */ 
mknumb( 24L,& wrk1 .sa); 
rez1 = wrk1 .sa ;goto _L98 ;xxx; 
goto _L124;}; _L120:;

/* atomic branch */ 
if (x.sa==acnst[ 80 ] ) { success1=true; 
 if (pl1.ptrtype!=ptrtree ) 
next(&pl1);

/* RETURN-op. */ 
mknumb( 25L,& wrk1 .sa); 
rez1 = wrk1 .sa ;goto _L98 ;xxx; 
goto _L124;}; _L121:;

/* atomic branch */ 
if (x.sa==acnst[ 81 ] ) { success1=true; 
 if (pl1.ptrtype!=ptrtree ) 
next(&pl1);

/* RETURN-op. */ 
mknumb( 26L,& wrk1 .sa); 
rez1 = wrk1 .sa ;goto _L98 ;xxx; 
goto _L124;}; _L122:;

/* atomic branch */ 
if (x.sa==acnst[ 82 ] ) { success1=true; 
 if (pl1.ptrtype!=ptrtree ) 
next(&pl1);

/* RETURN-op. */ 
mknumb( 27L,& wrk1 .sa); 
rez1 = wrk1 .sa ;goto _L98 ;xxx; 
goto _L124;}; _L123:;
success1=false;rez1=NULL; 
pl1=pl2;
goto _L125;
_L124:;/*uspeh alxtern.*/
goto _L99;  _L125:;  /* metka wyhoda po neuspehu wetwi */
 _L99: rez1=NULL; 
 _L98: *rez=rez1;*success=success1; 
 if (*success) *pl=pl1; /* prodwinutx ukazatelx leksem */ 
/* wosstanowitx GLOB */ 
#ifdef XX  
 d(2,"BUILTIN", 14 ,*rez,*success); 
#endif 
;};/* RULE */ 
