
#include "globrig.h" 
#include "define.h"  
#include "defpage.h" 
#include "nef2.h"    
#include "c1.h"      
#include "usemod.h"  
#include "def180.h"  
#include "xcrg.h"    
/*  R38 TAB */ 
/*  R39 LASTTAB */ 
/*  R40 GETWRK */ 
/*  R41 GETCNST */ 
/*  R42 GET_WORK_PL */ 
/*  R43 GET_FLAG */ 
/*  R44 NEW_LABEL */ 
/*  R45 RULENUM */ 
/*  R46 CROSS */ 
/*===============================================*/ 
/* GENERATED TEXT OF RULE   #TAB   */ 
 Void r38(rez,success,pl)
long *rez;boolean *success;ptr_ *pl; 
{  a rez1;  boolean success1; long k; mpd x; 
v loc1;/* $imq_prawila*/ 
v loc2;/* $T*/ 
v loc3;/* $imq_peremennoj*/ 
v loc4;/* $NOM*/ 
v wrk1;
v wrk2;
v wrk3;
ptr_ pl1;
ptr_ pl2;
boolean flag1;
#ifdef XX  
 d(1,"TAB", 38 ,pl->cel,0); 
#endif 
/* sohranitx GLOB */ 

/* branch */ pl1=*pl;rez1=NULL;success1=true; 
/* inicializaciq peremennyh */ 
loc1.sa=NULL;/* $imq_prawila*/ 
loc2.sa=NULL;/* $T*/ 
loc3.sa=NULL;/* $imq_peremennoj*/ 
loc4.sa=NULL;/* $NOM*/ 

/* shablon peremennoj */ 
success1=(pl1.nel!=0);rez1=pl1.cel;
if( (pl1.ptrtype!=ptrtree) && success1 ) next(&pl1);
loc1 .sa=rez1; 
if( !success1 ) goto _L104;

/* operator := */ 
selop( 0L,true, loc1 .sa, glob1_3 .sa ,& wrk1 .sa); 
loc2 .sa= wrk1 .sa ;xxx; 

/* IF-operator */ 
wrk1 .bo= loc2 .sa==NULL; 
if( wrk1 .bo) 
{ 
/* operator ++:= */ 
wrk3 = glob1_3 ; 
wrk2 .sa =NULL; 
mknumb( 0L,& wrk1 .sa); 
addel( acnst[ 130 ],false,NULL, wrk1 .sa ,& wrk2 .sa ); 
addel( 0L,true, loc1 .sa, wrk2 .sa ,& glob1_3 .sa); ;xxx; 
;} 
_L101:;xxx; 

/* shablon [ ... ] */ pl2=pl1;

/* shablon peremennoj */ 
success1=(pl1.nel!=0);rez1=pl1.cel;
if( (pl1.ptrtype!=ptrtree) && success1 ) next(&pl1);
loc3 .sa=rez1; 
if( !success1 ) goto _L103;

/* operator := */ 
selop( 0L,true, loc1 .sa, glob1_3 .sa ,& wrk1 .sa); 
loc2 .sa= wrk1 .sa ;xxx; 

/* operator := */ 
selop( 0L,true, loc3 .sa, loc2 .sa ,& wrk1 .sa); 
loc4 .sa= wrk1 .sa ;xxx; 

/* IF-operator */ 
/* operaciq = */ wrk1 .bo= loc4 .sa ==NULL ; 
if( wrk1 .bo) 
{ 
/* operator ++:= */ 
wrk3 = loc2 ; 
bltin(&wrk1,&flag1,loc2.sa,15L); 
mknumb( wrk1 .nu ,& wrk2 .sa); 
addel( 0L,true, loc3 .sa, wrk2 .sa ,& loc2 .sa); ;xxx; 
;} 
_L102:;xxx; 
_L103:if( ! success1 ) pl1=pl2;success1=true;
goto _L99;  _L104:;  /* metka wyhoda po neuspehu wetwi */
 _L99: rez1=NULL; 
 _L98: *rez=rez1;*success=success1; 
 if (*success) *pl=pl1; /* prodwinutx ukazatelx leksem */ 
/* wosstanowitx GLOB */ 
#ifdef XX  
 d(2,"TAB", 38 ,*rez,*success); 
#endif 
;};/* RULE */ 
/*===============================================*/ 
/* GENERATED TEXT OF RULE   #LASTTAB   */ 
 Void r39(rez,success,pl)
long *rez;boolean *success;ptr_ *pl; 
{  a rez1;  boolean success1; long k; mpd x; 
v loc1;/* $imq_prawila*/ 
v loc2;/* $imq_peremennoj*/ 
v loc3;/* $T*/ 
v loc4;/* $NOM*/ 
v wrk1;
v wrk2;
v wrk3;
v wrk4;
ptr_ pl1;
boolean flag1;
#ifdef XX  
 d(1,"LASTTAB", 39 ,pl->cel,0); 
#endif 
/* sohranitx GLOB */ 

/* branch */ pl1=*pl;rez1=NULL;success1=true; 
/* inicializaciq peremennyh */ 
loc1.sa=NULL;/* $imq_prawila*/ 
loc2.sa=NULL;/* $imq_peremennoj*/ 
loc3.sa=NULL;/* $T*/ 
loc4.sa=NULL;/* $NOM*/ 

/* shablon peremennoj */ 
success1=(pl1.nel!=0);rez1=pl1.cel;
if( (pl1.ptrtype!=ptrtree) && success1 ) next(&pl1);
loc1 .sa=rez1; 
if( !success1 ) goto _L102;

/* shablon peremennoj */ 
success1=(pl1.nel!=0);rez1=pl1.cel;
if( (pl1.ptrtype!=ptrtree) && success1 ) next(&pl1);
loc2 .sa=rez1; 
if( !success1 ) goto _L102;

/* operator := */ 
selop( 0L,true, loc1 .sa, glob1_5 .sa ,& wrk1 .sa); 
loc3 .sa= wrk1 .sa ;xxx; 

/* operator := */ 
selop( 0L,true, loc2 .sa, loc3 .sa ,& wrk1 .sa); 
loc4 .sa= wrk1 .sa ;xxx; 

/* IF-operator */ 
/* operaciq = */ wrk1 .bo= loc3 .sa ==NULL ; 
if( wrk1 .bo) 
{ 
/* operator ++:= */ 
wrk3 = glob1_5 ; 
wrk2 .sa =NULL; 
mknumb( 1L,& wrk1 .sa); 
addel( 0L,true, loc2 .sa, wrk1 .sa ,& wrk2 .sa ); 
addel( 0L,true, loc1 .sa, wrk2 .sa ,& glob1_5 .sa); ;xxx; 
goto _L101;
;} 
/* operaciq = */ wrk4 .bo= loc4 .sa ==NULL ; 
if( wrk4 .bo) 
{ 
/* operator ++:= */ 
wrk4 = loc3 ; 
bltin(&wrk1,&flag1,loc3.sa,15L); 
wrk2 .nu= wrk1 .nu + 1L ; 
mknumb( wrk2 .nu ,& wrk3 .sa); 
addel( 0L,true, loc2 .sa, wrk3 .sa ,& loc3 .sa); ;xxx; 
;} 
_L101:;xxx; 
goto _L99;  _L102:;  /* metka wyhoda po neuspehu wetwi */
 _L99: rez1=NULL; 
 _L98: *rez=rez1;*success=success1; 
 if (*success) *pl=pl1; /* prodwinutx ukazatelx leksem */ 
/* wosstanowitx GLOB */ 
#ifdef XX  
 d(2,"LASTTAB", 39 ,*rez,*success); 
#endif 
;};/* RULE */ 
/*===============================================*/ 
/* GENERATED TEXT OF RULE   #GETWRK   */ 
 Void r40(rez,success,pl)
long *rez;boolean *success;ptr_ *pl; 
{  a rez1;  boolean success1; long k; mpd x; 
v wrk1;
ptr_ pl1;
#ifdef XX  
 d(1,"GETWRK", 40 ,pl->cel,0); 
#endif 
/* sohranitx GLOB */ 

/* branch */ pl1=*pl;rez1=NULL;success1=true; 
/* inicializaciq peremennyh */ 

/* operator +:= */ 
addnum(& glob2_1 .sa, 1L ) ;xxx; 

/* IF-operator */ 
wrk1 .bo=compare( 1L , glob2_2 .sa , glob2_1 .sa ); 
if( wrk1 .bo) 
{ 
/* operator +:= */ 
addnum(& glob2_2 .sa, 1L ) ;xxx; 
;} 
_L101:;xxx; 

/* RETURN-op. */ 
copyop( glob2_1 .sa ,& wrk1 .sa); 
rez1 = wrk1 .sa ;goto _L98 ;xxx; 
goto _L99;  _L102:;  /* metka wyhoda po neuspehu wetwi */
 _L99: rez1=NULL; 
 _L98: *rez=rez1;*success=success1; 
 if (*success) *pl=pl1; /* prodwinutx ukazatelx leksem */ 
/* wosstanowitx GLOB */ 
#ifdef XX  
 d(2,"GETWRK", 40 ,*rez,*success); 
#endif 
;};/* RULE */ 
/*===============================================*/ 
/* GENERATED TEXT OF RULE   #GETCNST   */ 
 Void r41(rez,success,pl)
long *rez;boolean *success;ptr_ *pl; 
{  a rez1;  boolean success1; long k; mpd x; 
v loc1;/* $C*/ 
v loc2;/* $N*/ 
v loc3;/* $L*/ 
v loc4;/* $E*/ 
v wrk1;
ptr_ pl1;
ptr_ pl2;
ptr_ pl3;
#ifdef XX  
 d(1,"GETCNST", 41 ,pl->cel,0); 
#endif 
/* sohranitx GLOB */ 

/* branch */ pl1=*pl;rez1=NULL;success1=true; 
/* inicializaciq peremennyh */ 
loc1.sa=NULL;/* $C*/ 
loc2.sa=NULL;/* $N*/ 
loc3.sa=NULL;/* $L*/ 
loc4.sa=NULL;/* $E*/ 

/* shablon peremennoj */ 
success1=(pl1.nel!=0);rez1=pl1.cel;
if( (pl1.ptrtype!=ptrtree) && success1 ) next(&pl1);
loc1 .sa=rez1; 
if( !success1 ) goto _L103;

/* operator := */ 
mknumb( 1L,& wrk1 .sa); 
loc2 .sa= wrk1 .sa ;xxx; 

loc3 .sa=NULL; 

/* shablon listmain */ rez1=pl1.cel;
success1=false;if(pl1.nel==0 ) goto _L103; 
 if (rez1!=NULL ) { pointr(rez1,&x.sa); 
       if (x.smld->dtype!= listmain )  
        { rez1=NULL;goto _L103;};
{pl2.ptrtype=ptrlist; pl2.nel=1;
pl2.cel=x.smld->elt[0];pl2.UU.U1.curfragment=rez1;}
;} else  
{pl2.ptrtype=ptrlist;pl2.nel=0;pl2.cel=NULL;}

/*shablon STARLIST */ 
 pl3=pl2;while(pl2.nel!=0 ) { 

/* shablon peremennoj */ 
success1=(pl2.nel!=0);rez1=pl2.cel;
if( (pl2.ptrtype!=ptrtree) && success1 ) next(&pl2);
loc4 .sa=rez1; 
if( !success1 ) goto _L102;

/* IF-operator */ 
/* operaciq = */ wrk1 .bo= eqop(0L, loc4 .sa , loc1 .sa ) ; 
if( wrk1 .bo) 
{ 
/* RETURN-op. */ 
rez1 = loc2 .sa 
;if (pl1.ptrtype!=ptrtree) next(&pl1) /*wyhod iz der.ili sp.*/ ;goto _L98 ;xxx; 
;} 
_L101:;xxx; 

/* operator +:= */ 
addnum(& loc2 .sa, 1L ) ;xxx; 
 pl3=pl2;
;}; 
_L102:if( ! success1 )pl2=pl3;
success1 = true ; 

if( pl2.nel !=0 )
{ success1=false;rez1=NULL;goto _L103;};
success1=true;rez1=pl1.cel;
 if( pl1.ptrtype!=ptrtree ) next(&pl1);
loc3 .sa=rez1; 

/* operator !.:= */ 
lconc(& loc3 .sa, loc1 .sa ) ;xxx; 

/* RETURN-op. */ 
rez1 = loc2 .sa ;goto _L98 ;xxx; 
goto _L99;  _L103:;  /* metka wyhoda po neuspehu wetwi */
 _L99: rez1=NULL; 
 _L98: *rez=rez1;*success=success1; 
 if (*success) *pl=pl1; /* prodwinutx ukazatelx leksem */ 
/* wosstanowitx GLOB */ 
#ifdef XX  
 d(2,"GETCNST", 41 ,*rez,*success); 
#endif 
;};/* RULE */ 
/*===============================================*/ 
/* GENERATED TEXT OF RULE   #GET_WORK_PL   */ 
 Void r42(rez,success,pl)
long *rez;boolean *success;ptr_ *pl; 
{  a rez1;  boolean success1; long k; mpd x; 
v wrk1;
ptr_ pl1;
#ifdef XX  
 d(1,"GET_WORK_PL", 42 ,pl->cel,0); 
#endif 
/* sohranitx GLOB */ 

/* branch */ pl1=*pl;rez1=NULL;success1=true; 
/* inicializaciq peremennyh */ 

/* operator +:= */ 
addnum(& glob2_4 .sa, 1L ) ;xxx; 

/* IF-operator */ 
wrk1 .bo=compare( 1L , glob2_3 .sa , glob2_4 .sa ); 
if( wrk1 .bo) 
{ 
/* operator +:= */ 
addnum(& glob2_3 .sa, 1L ) ;xxx; 
;} 
_L101:;xxx; 

/* RETURN-op. */ 
copyop( glob2_4 .sa ,& wrk1 .sa); 
rez1 = wrk1 .sa ;goto _L98 ;xxx; 
goto _L99;  _L102:;  /* metka wyhoda po neuspehu wetwi */
 _L99: rez1=NULL; 
 _L98: *rez=rez1;*success=success1; 
 if (*success) *pl=pl1; /* prodwinutx ukazatelx leksem */ 
/* wosstanowitx GLOB */ 
#ifdef XX  
 d(2,"GET_WORK_PL", 42 ,*rez,*success); 
#endif 
;};/* RULE */ 
/*===============================================*/ 
/* GENERATED TEXT OF RULE   #GET_FLAG   */ 
 Void r43(rez,success,pl)
long *rez;boolean *success;ptr_ *pl; 
{  a rez1;  boolean success1; long k; mpd x; 
v wrk1;
ptr_ pl1;
#ifdef XX  
 d(1,"GET_FLAG", 43 ,pl->cel,0); 
#endif 
/* sohranitx GLOB */ 

/* branch */ pl1=*pl;rez1=NULL;success1=true; 
/* inicializaciq peremennyh */ 

/* operator +:= */ 
addnum(& glob2_8 .sa, 1L ) ;xxx; 

/* IF-operator */ 
wrk1 .bo=compare( 1L , glob2_7 .sa , glob2_8 .sa ); 
if( wrk1 .bo) 
{ 
/* operator +:= */ 
addnum(& glob2_7 .sa, 1L ) ;xxx; 
;} 
_L101:;xxx; 

/* RETURN-op. */ 
copyop( glob2_8 .sa ,& wrk1 .sa); 
rez1 = wrk1 .sa ;goto _L98 ;xxx; 
goto _L99;  _L102:;  /* metka wyhoda po neuspehu wetwi */
 _L99: rez1=NULL; 
 _L98: *rez=rez1;*success=success1; 
 if (*success) *pl=pl1; /* prodwinutx ukazatelx leksem */ 
/* wosstanowitx GLOB */ 
#ifdef XX  
 d(2,"GET_FLAG", 43 ,*rez,*success); 
#endif 
;};/* RULE */ 
/*===============================================*/ 
/* GENERATED TEXT OF RULE   #NEW_LABEL   */ 
 Void r44(rez,success,pl)
long *rez;boolean *success;ptr_ *pl; 
{  a rez1;  boolean success1; long k; mpd x; 
v wrk1;
ptr_ pl1;
#ifdef XX  
 d(1,"NEW_LABEL", 44 ,pl->cel,0); 
#endif 
/* sohranitx GLOB */ 

/* branch */ pl1=*pl;rez1=NULL;success1=true; 
/* inicializaciq peremennyh */ 

/* operator +:= */ 
addnum(& glob2_6 .sa, 1L ) ;xxx; 

/* RETURN-op. */ 
copyop( glob2_6 .sa ,& wrk1 .sa); 
rez1 = wrk1 .sa ;goto _L98 ;xxx; 
goto _L99;  _L101:;  /* metka wyhoda po neuspehu wetwi */
 _L99: rez1=NULL; 
 _L98: *rez=rez1;*success=success1; 
 if (*success) *pl=pl1; /* prodwinutx ukazatelx leksem */ 
/* wosstanowitx GLOB */ 
#ifdef XX  
 d(2,"NEW_LABEL", 44 ,*rez,*success); 
#endif 
;};/* RULE */ 
/*===============================================*/ 
/* GENERATED TEXT OF RULE   #RULENUM   */ 
 Void r45(rez,success,pl)
long *rez;boolean *success;ptr_ *pl; 
{  a rez1;  boolean success1; long k; mpd x; 
v loc1;/* $N*/ 
v loc2;/* $E*/ 
v loc3;/* $imq*/ 
v loc4;/* $R*/ 
v wrk1;
v wrk2;
ptr_ pl1;
ptr_ pl2;
#ifdef XX  
 d(1,"RULENUM", 45 ,pl->cel,0); 
#endif 
/* sohranitx GLOB */ 

/* branch */ pl1=*pl;rez1=NULL;success1=true; 
/* inicializaciq peremennyh */ 
loc1.sa=NULL;/* $N*/ 
loc2.sa=NULL;/* $E*/ 
loc3.sa=NULL;/* $imq*/ 
loc4.sa=NULL;/* $R*/ 

/* operator := */ 
mknumb( 1L,& wrk1 .sa); 
loc1 .sa= wrk1 .sa ;xxx; 

/* shablon peremennoj */ 
success1=(pl1.nel!=0);rez1=pl1.cel;
if( (pl1.ptrtype!=ptrtree) && success1 ) next(&pl1);
loc2 .sa=rez1; 
if( !success1 ) goto _L102;

/*FORALL-op.*/ 
if( loc2.sa==NULL ) goto _L101;
pointr ( loc2 .sa ,&x.sa);  
if( (x.smld->dtype!=listmain)&&(x.smld->dtype!=treemain) 
  ) { er(24L);goto _L101;}; 
first(loc2.sa,&pl2);
while (pl2.nel!=0){
    if( pl2.ptrtype==ptrlist ) 
{loc3.sa=pl2.cel;} 
   else {
  mkatom(pl2.UU.U1.arc,idatom,&loc3.sa);
;}; 
/* operator ++:= */ 
wrk1 = loc4 ; 
addel( 0L,true, loc3 .sa, loc1 .sa ,& loc4 .sa); ;xxx; 
/* operator := */ 
wrk1 .nu= numval( loc1 .sa) + 1L ; 
mknumb( wrk1 .nu ,& wrk2 .sa); 
loc1 .sa= wrk2 .sa ;xxx; 
next(&pl2) ;};_L101:/*END FORALL*/;xxx; 

/* RETURN-op. */ 
rez1 = loc4 .sa ;goto _L98 ;xxx; 
goto _L99;  _L102:;  /* metka wyhoda po neuspehu wetwi */
 _L99: rez1=NULL; 
 _L98: *rez=rez1;*success=success1; 
 if (*success) *pl=pl1; /* prodwinutx ukazatelx leksem */ 
/* wosstanowitx GLOB */ 
#ifdef XX  
 d(2,"RULENUM", 45 ,*rez,*success); 
#endif 
;};/* RULE */ 
/*===============================================*/ 
/* GENERATED TEXT OF RULE   #CROSS   */ 
 Void r46(rez,success,pl)
long *rez;boolean *success;ptr_ *pl; 
{  a rez1;  boolean success1; long k; mpd x; 
v loc1;/* $R*/ 
v loc2;/* $C*/ 
v loc3;/* $T*/ 
v wrk1;
v wrk2;
ptr_ pl1;
#ifdef XX  
 d(1,"CROSS", 46 ,pl->cel,0); 
#endif 
/* sohranitx GLOB */ 

/* branch */ pl1=*pl;rez1=NULL;success1=true; 
/* inicializaciq peremennyh */ 
loc1.sa=NULL;/* $R*/ 
loc2.sa=NULL;/* $C*/ 
loc3.sa=NULL;/* $T*/ 

/* shablon peremennoj */ 
success1=(pl1.nel!=0);rez1=pl1.cel;
if( (pl1.ptrtype!=ptrtree) && success1 ) next(&pl1);
loc1 .sa=rez1; 
if( !success1 ) goto _L103;

/* operator := */ 
loc2 .sa= glob24_2 .sa ;xxx; 

/* IF-operator */ 
wrk1 .bo= loc2 .sa==NULL; 
if( wrk1 .bo) 
{ 
/* operator := */ 
loc2 .sa= glob3_1 .sa ;xxx; 
;} 
_L101:;xxx; 

/* operator := */ 
loc3 .sa= glob1_6 .sa ;xxx; 

/* IF-operator */ 
selop( 0L,true, loc2 .sa, loc3 .sa ,& wrk1 .sa); 
if( wrk1 .sa!=NULL) 
{ 
/* operator ++:= */ 
selop( 0L,true, loc2 .sa, loc3 .sa ,& wrk1 .sa); 
wrk2 = wrk1 ; 
addel( 0L,true, loc1 .sa, cnst[1] .sa ,& wrk1 .sa); 
if( wrk1 .sa==NULL ) setsel( 0L,true, loc2 .sa, loc3 .sa ,NULL) ;xxx; 
goto _L102;
;} 
if( loc3 .sa!=NULL) 
{ 
/* operator ++:= */ 
wrk2 = loc3 ; 
wrk1 .sa =NULL; 
addel( 0L,true, loc1 .sa, cnst[1] .sa ,& wrk1 .sa ); 
addel( 0L,true, loc2 .sa, wrk1 .sa ,& loc3 .sa); ;xxx; 
goto _L102;
;} 
{ 
/* operator := */ 
wrk2 .sa =NULL; 
wrk1 .sa =NULL; 
addel( 0L,true, loc1 .sa, cnst[1] .sa ,& wrk1 .sa ); 
addel( 0L,true, loc2 .sa, wrk1 .sa ,& wrk2 .sa ); 
glob1_6 .sa= wrk2 .sa ;xxx; 
;} 
_L102:;xxx; 
goto _L99;  _L103:;  /* metka wyhoda po neuspehu wetwi */
 _L99: rez1=NULL; 
 _L98: *rez=rez1;*success=success1; 
 if (*success) *pl=pl1; /* prodwinutx ukazatelx leksem */ 
/* wosstanowitx GLOB */ 
#ifdef XX  
 d(2,"CROSS", 46 ,*rez,*success); 
#endif 
;};/* RULE */ 
