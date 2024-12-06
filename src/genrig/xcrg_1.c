
#include "globrig.h" 
#include "define.h"  
#include "defpage.h" 
#include "nef2.h"    
#include "c1.h"      
#include "usemod.h"  
#include "def180.h"  
#include "xcrg.h"    
/*  R2 G_LOC_dekl */ 
/*  R4 G_WRK_dekl */ 
/*  R5 G_PL_dekl */ 
/*  R6 G_FLAG_dekl */ 
/*  R7 G_OLDGLOB_dekl */ 
/*  R8 G_sohranitx_GLOB */ 
/*  R9 G_INIT_VARS */ 
/*  R11 G_ATOM_FROM_REZ */ 
/*  R12 G_LABELS */ 
/*===============================================*/ 
/* GENERATED TEXT OF RULE   #G_LOC_dekl   */ 
 Void r2(rez,success,pl)
long *rez;boolean *success;ptr_ *pl; 
{  a rez1;  boolean success1; long k; mpd x; 
v loc1;/* $prawilo*/ 
v loc2;/* $VARS*/ 
v loc3;/* $GVARS*/ 
v loc4;/* $X*/ 
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
 d(1,"G_LOC_dekl", 2 ,pl->cel,0); 
#endif 
/* sohranitx GLOB */ 

/* branch */ pl1=*pl;rez1=NULL;success1=true; 
/* inicializaciq peremennyh */ 
loc1.sa=NULL;/* $prawilo*/ 
loc2.sa=NULL;/* $VARS*/ 
loc3.sa=NULL;/* $GVARS*/ 
loc4.sa=NULL;/* $X*/ 

/* shablon peremennoj */ 
success1=(pl1.nel!=0);rez1=pl1.cel;
if( (pl1.ptrtype!=ptrtree) && success1 ) next(&pl1);
loc1 .sa=rez1; 
if( !success1 ) goto _L103;

/* operator := */ 
selop( 0L,true, loc1 .sa, glob1_1 .sa ,& wrk1 .sa); 
loc2 .sa= wrk1 .sa ;xxx; 

/* operator := */ 
selop( 0L,true, loc1 .sa, glob1_2 .sa ,& wrk1 .sa); 
loc3 .sa= wrk1 .sa ;xxx; 

/*FORALL-op.*/ 
if( loc2.sa==NULL ) goto _L102;
pointr ( loc2 .sa ,&x.sa);  
if( (x.smld->dtype!=listmain)&&(x.smld->dtype!=treemain) 
  ) { er(24L);goto _L102;}; 
first(loc2.sa,&pl2);
while (pl2.nel!=0){
    if( pl2.ptrtype==ptrlist ) 
{loc4.sa=pl2.cel;} 
   else {
  mkatom(pl2.UU.U1.arc,idatom,&loc4.sa);
;}; 
/* IF-operator */ 
selop( 0L,true, loc4 .sa, loc3 .sa ,& wrk1 .sa); 
if( wrk1 .sa!=NULL ) wrk6 .bo=true; else { 
/* operaciq = */ wrk2 .bo= eqatom( loc4 .sa ,acnst[ 13 ]) ; 
if( !( wrk2 .bo )) wrk5 .bo=false; else { 
selop( acnst[ 14 ],false,NULL, glob3_1 .sa ,& wrk3 .sa); 
wrk4 .bo= wrk3 .sa==NULL; wrk5 = wrk4 ;}/*log*/; wrk6 = wrk5 ;}; 
wrk7 .bo= !( wrk6 .bo); 
if( wrk7 .bo) 
{ 
outatm(acnst[15],"v loc",true, false); 
selop( 0L,true, loc4 .sa, loc2 .sa ,& wrk1 .sa); 
outxt(acnst[ 15 ], wrk1 .sa , false, false); 
outatm(acnst[15],";/* $",false, false); ;xxx; 
/* CALL #L */ 
pl3.ptrtype=packedlist;pl3.nel=1;pl3.cel=loc4.sa;
pl3.plistsize= 1;
r31(&wrk1.sa,&flag1,&pl3);/* #Print_name*/ ;xxx; 
outatm(acnst[15],"*/",false, true); ;xxx; 
;} 
_L101:;xxx; 
next(&pl2) ;};_L102:/*END FORALL*/;xxx; 
goto _L99;  _L103:;  /* metka wyhoda po neuspehu wetwi */
 _L99: rez1=NULL; 
 _L98: *rez=rez1;*success=success1; 
 if (*success) *pl=pl1; /* prodwinutx ukazatelx leksem */ 
/* wosstanowitx GLOB */ 
#ifdef XX  
 d(2,"G_LOC_dekl", 2 ,*rez,*success); 
#endif 
;};/* RULE */ 
/*===============================================*/ 
/* GENERATED TEXT OF RULE   #G_WRK_dekl   */ 
 Void r4(rez,success,pl)
long *rez;boolean *success;ptr_ *pl; 
{  a rez1;  boolean success1; long k; mpd x; 
v loc1;/* $MAXWRK*/ 
v loc2;/* $X*/ 
v wrk1;
ptr_ pl1;
#ifdef XX  
 d(1,"G_WRK_dekl", 4 ,pl->cel,0); 
#endif 
/* sohranitx GLOB */ 

/* branch */ pl1=*pl;rez1=NULL;success1=true; 
/* inicializaciq peremennyh */ 
loc1.sa=NULL;/* $MAXWRK*/ 
loc2.sa=NULL;/* $X*/ 

/* shablon peremennoj */ 
success1=(pl1.nel!=0);rez1=pl1.cel;
if( (pl1.ptrtype!=ptrtree) && success1 ) next(&pl1);
loc1 .sa=rez1; 
if( !success1 ) goto _L103;

/* operator := */ 
mknumb( 1L,& wrk1 .sa); 
loc2 .sa= wrk1 .sa ;xxx; 

/*LOOP*/while (true) { 
/* IF-operator */ 
wrk1 .bo=compare( 3L , loc2 .sa , loc1 .sa ); 
if( wrk1 .bo) 
{ 
/*BREAK*/ goto _L102;xxx; 
;} 
_L101:;xxx; 
outatm(acnst[15],"v wrk",true, false); 
outxt(acnst[ 15 ], loc2 .sa , false, false); 
outatm(acnst[15],";",false, false); ;xxx; 
/* operator +:= */ 
addnum(& loc2 .sa, 1L ) ;xxx; 
;};  _L102:/*END LOOP*/;xxx; 
goto _L99;  _L103:;  /* metka wyhoda po neuspehu wetwi */
 _L99: rez1=NULL; 
 _L98: *rez=rez1;*success=success1; 
 if (*success) *pl=pl1; /* prodwinutx ukazatelx leksem */ 
/* wosstanowitx GLOB */ 
#ifdef XX  
 d(2,"G_WRK_dekl", 4 ,*rez,*success); 
#endif 
;};/* RULE */ 
/*===============================================*/ 
/* GENERATED TEXT OF RULE   #G_PL_dekl   */ 
 Void r5(rez,success,pl)
long *rez;boolean *success;ptr_ *pl; 
{  a rez1;  boolean success1; long k; mpd x; 
v loc1;/* $NPL*/ 
v loc2;/* $X*/ 
v wrk1;
ptr_ pl1;
#ifdef XX  
 d(1,"G_PL_dekl", 5 ,pl->cel,0); 
#endif 
/* sohranitx GLOB */ 

/* branch */ pl1=*pl;rez1=NULL;success1=true; 
/* inicializaciq peremennyh */ 
loc1.sa=NULL;/* $NPL*/ 
loc2.sa=NULL;/* $X*/ 

/* shablon peremennoj */ 
varpat(&pl1,number,&rez1,&success1);
loc1 .sa=rez1; 
if( !success1 ) goto _L103;

/* operator := */ 
mknumb( 1L,& wrk1 .sa); 
loc2 .sa= wrk1 .sa ;xxx; 

/*LOOP*/while (true) { 
/* IF-operator */ 
wrk1 .bo=compare( 3L , loc2 .sa , loc1 .sa ); 
if( wrk1 .bo) 
{ 
/*BREAK*/ goto _L102;xxx; 
;} 
_L101:;xxx; 
outatm(acnst[15],"ptr_ pl",true, false); 
outxt(acnst[ 15 ], loc2 .sa , false, false); 
outatm(acnst[15],";",false, false); ;xxx; 
/* operator +:= */ 
addnum(& loc2 .sa, 1L ) ;xxx; 
;};  _L102:/*END LOOP*/;xxx; 
goto _L99;  _L103:;  /* metka wyhoda po neuspehu wetwi */
 _L99: rez1=NULL; 
 _L98: *rez=rez1;*success=success1; 
 if (*success) *pl=pl1; /* prodwinutx ukazatelx leksem */ 
/* wosstanowitx GLOB */ 
#ifdef XX  
 d(2,"G_PL_dekl", 5 ,*rez,*success); 
#endif 
;};/* RULE */ 
/*===============================================*/ 
/* GENERATED TEXT OF RULE   #G_FLAG_dekl   */ 
 Void r6(rez,success,pl)
long *rez;boolean *success;ptr_ *pl; 
{  a rez1;  boolean success1; long k; mpd x; 
v loc1;/* $NFLAG*/ 
v loc2;/* $X*/ 
v wrk1;
ptr_ pl1;
#ifdef XX  
 d(1,"G_FLAG_dekl", 6 ,pl->cel,0); 
#endif 
/* sohranitx GLOB */ 

/* branch */ pl1=*pl;rez1=NULL;success1=true; 
/* inicializaciq peremennyh */ 
loc1.sa=NULL;/* $NFLAG*/ 
loc2.sa=NULL;/* $X*/ 

/* shablon peremennoj */ 
varpat(&pl1,number,&rez1,&success1);
loc1 .sa=rez1; 
if( !success1 ) goto _L103;

/* operator := */ 
mknumb( 1L,& wrk1 .sa); 
loc2 .sa= wrk1 .sa ;xxx; 

/*LOOP*/while (true) { 
/* IF-operator */ 
wrk1 .bo=compare( 3L , loc2 .sa , loc1 .sa ); 
if( wrk1 .bo) 
{ 
/*BREAK*/ goto _L102;xxx; 
;} 
_L101:;xxx; 
outatm(acnst[15],"boolean flag",true, false); 
outxt(acnst[ 15 ], loc2 .sa , false, false); 
outatm(acnst[15],";",false, false); ;xxx; 
/* operator +:= */ 
addnum(& loc2 .sa, 1L ) ;xxx; 
;};  _L102:/*END LOOP*/;xxx; 
goto _L99;  _L103:;  /* metka wyhoda po neuspehu wetwi */
 _L99: rez1=NULL; 
 _L98: *rez=rez1;*success=success1; 
 if (*success) *pl=pl1; /* prodwinutx ukazatelx leksem */ 
/* wosstanowitx GLOB */ 
#ifdef XX  
 d(2,"G_FLAG_dekl", 6 ,*rez,*success); 
#endif 
;};/* RULE */ 
/*===============================================*/ 
/* GENERATED TEXT OF RULE   #G_OLDGLOB_dekl   */ 
 Void r7(rez,success,pl)
long *rez;boolean *success;ptr_ *pl; 
{  a rez1;  boolean success1; long k; mpd x; 
v loc1;/* $prawilo*/ 
v loc2;/* $NUM*/ 
v loc3;/* $X*/ 
v loc4;/* $A*/ 
v wrk1;
ptr_ pl1;
ptr_ pl2;
#ifdef XX  
 d(1,"G_OLDGLOB_dekl", 7 ,pl->cel,0); 
#endif 
/* sohranitx GLOB */ 

/* branch */ pl1=*pl;rez1=NULL;success1=true; 
/* inicializaciq peremennyh */ 
loc1.sa=NULL;/* $prawilo*/ 
loc2.sa=NULL;/* $NUM*/ 
loc3.sa=NULL;/* $X*/ 
loc4.sa=NULL;/* $A*/ 

/* shablon peremennoj */ 
success1=(pl1.nel!=0);rez1=pl1.cel;
if( (pl1.ptrtype!=ptrtree) && success1 ) next(&pl1);
loc1 .sa=rez1; 
if( !success1 ) goto _L102;

/* operator := */ 
selop( 0L,true, loc1 .sa, glob1_3 .sa ,& wrk1 .sa); 
loc2 .sa= wrk1 .sa ;xxx; 

/* operator := */ 
selop( 0L,true, loc1 .sa, glob1_2 .sa ,& wrk1 .sa); 
loc3 .sa= wrk1 .sa ;xxx; 

/*FORALL-op.*/ 
if( loc3.sa==NULL ) goto _L101;
pointr ( loc3 .sa ,&x.sa);  
if( (x.smld->dtype!=listmain)&&(x.smld->dtype!=treemain) 
  ) { er(24L);goto _L101;}; 
first(loc3.sa,&pl2);
while (pl2.nel!=0){
    if( pl2.ptrtype==ptrlist ) 
{loc4.sa=pl2.cel;} 
   else {
  mkatom(pl2.UU.U1.arc,idatom,&loc4.sa);
;}; 
outatm(acnst[15],"v oldglob",true, false); 
outxt(acnst[ 15 ], loc2 .sa , false, false); 
outatm(acnst[15],"_",false, false); 
selop( 0L,true, loc4 .sa, loc3 .sa ,& wrk1 .sa); 
outxt(acnst[ 15 ], wrk1 .sa , false, false); 
outatm(acnst[15],";",false, false); ;xxx; 
next(&pl2) ;};_L101:/*END FORALL*/;xxx; 
goto _L99;  _L102:;  /* metka wyhoda po neuspehu wetwi */
 _L99: rez1=NULL; 
 _L98: *rez=rez1;*success=success1; 
 if (*success) *pl=pl1; /* prodwinutx ukazatelx leksem */ 
/* wosstanowitx GLOB */ 
#ifdef XX  
 d(2,"G_OLDGLOB_dekl", 7 ,*rez,*success); 
#endif 
;};/* RULE */ 
/*===============================================*/ 
/* GENERATED TEXT OF RULE   #G_sohranitx_GLOB   */ 
 Void r8(rez,success,pl)
long *rez;boolean *success;ptr_ *pl; 
{  a rez1;  boolean success1; long k; mpd x; 
v loc1;/* $prawilo*/ 
v loc2;/* $sohranitx*/ 
v loc3;/* $NUM*/ 
v loc4;/* $X*/ 
v loc5;/* $lew*/ 
v loc6;/* $praw*/ 
v loc7;/* $A*/ 
v loc8;/* $N2*/ 
v wrk1;
ptr_ pl1;
ptr_ pl2;
#ifdef XX  
 d(1,"G_sohranitx_GLOB", 8 ,pl->cel,0); 
#endif 
/* sohranitx GLOB */ 

/* branch */ pl1=*pl;rez1=NULL;success1=true; 
/* inicializaciq peremennyh */ 
loc1.sa=NULL;/* $prawilo*/ 
loc2.sa=NULL;/* $sohranitx*/ 
loc3.sa=NULL;/* $NUM*/ 
loc4.sa=NULL;/* $X*/ 
loc5.sa=NULL;/* $lew*/ 
loc6.sa=NULL;/* $praw*/ 
loc7.sa=NULL;/* $A*/ 
loc8.sa=NULL;/* $N2*/ 

/* shablon peremennoj */ 
success1=(pl1.nel!=0);rez1=pl1.cel;
if( (pl1.ptrtype!=ptrtree) && success1 ) next(&pl1);
loc1 .sa=rez1; 
if( !success1 ) goto _L103;

/* shablon peremennoj */ 
success1=(pl1.nel!=0);rez1=pl1.cel;
if( (pl1.ptrtype!=ptrtree) && success1 ) next(&pl1);
loc2 .sa=rez1; 
if( !success1 ) goto _L103;

/* operator := */ 
selop( 0L,true, loc1 .sa, glob1_3 .sa ,& wrk1 .sa); 
loc3 .sa= wrk1 .sa ;xxx; 

/* operator := */ 
selop( 0L,true, loc1 .sa, glob1_2 .sa ,& wrk1 .sa); 
loc4 .sa= wrk1 .sa ;xxx; 

/* IF-operator */ 
if( loc2 .sa!=NULL) 
{ 
/* operator := */ 
loc5 .sa= cnst[15] .sa ;xxx; 
/* operator := */ 
loc6 .sa= NULL ;xxx; 
outatm(acnst[15],"/* sohranitx GLOB */",true, true); ;xxx; 
goto _L101;
;} 
{ 
/* operator := */ 
loc5 .sa= NULL ;xxx; 
/* operator := */ 
loc6 .sa= cnst[15] .sa ;xxx; 
outatm(acnst[15],"/* wosstanowitx GLOB */",true, true); ;xxx; 
;} 
_L101:;xxx; 

/*FORALL-op.*/ 
if( loc4.sa==NULL ) goto _L102;
pointr ( loc4 .sa ,&x.sa);  
if( (x.smld->dtype!=listmain)&&(x.smld->dtype!=treemain) 
  ) { er(24L);goto _L102;}; 
first(loc4.sa,&pl2);
while (pl2.nel!=0){
    if( pl2.ptrtype==ptrlist ) 
{loc7.sa=pl2.cel;} 
   else {
  mkatom(pl2.UU.U1.arc,idatom,&loc7.sa);
;}; 
/* operator := */ 
selop( 0L,true, loc7 .sa, loc4 .sa ,& wrk1 .sa); 
loc8 .sa= wrk1 .sa ;xxx; 
outxt(acnst[ 15 ], loc5 .sa , true, false); 
outatm(acnst[15],"glob",false, false); 
outxt(acnst[ 15 ], loc3 .sa , false, false); 
outatm(acnst[15],"_",false, false); 
outxt(acnst[ 15 ], loc8 .sa , false, false); 
outatm(acnst[15],"=",false, false); 
outxt(acnst[ 15 ], loc6 .sa , false, false); 
outatm(acnst[15],"glob",false, false); 
outxt(acnst[ 15 ], loc3 .sa , false, false); 
outatm(acnst[15],"_",false, false); 
outxt(acnst[ 15 ], loc8 .sa , false, false); 
outatm(acnst[15],";",false, false); ;xxx; 
next(&pl2) ;};_L102:/*END FORALL*/;xxx; 
goto _L99;  _L103:;  /* metka wyhoda po neuspehu wetwi */
 _L99: rez1=NULL; 
 _L98: *rez=rez1;*success=success1; 
 if (*success) *pl=pl1; /* prodwinutx ukazatelx leksem */ 
/* wosstanowitx GLOB */ 
#ifdef XX  
 d(2,"G_sohranitx_GLOB", 8 ,*rez,*success); 
#endif 
;};/* RULE */ 
/*===============================================*/ 
/* GENERATED TEXT OF RULE   #G_INIT_VARS   */ 
 Void r9(rez,success,pl)
long *rez;boolean *success;ptr_ *pl; 
{  a rez1;  boolean success1; long k; mpd x; 
v loc1;/* $prawilo*/ 
v loc2;/* $VARS*/ 
v loc3;/* $NOM*/ 
v loc4;/* $GVARS*/ 
v loc5;/* $X*/ 
v loc6;/* $GNOM*/ 
v wrk1;
v wrk2;
v wrk3;
v wrk4;
ptr_ pl1;
ptr_ pl2;
ptr_ pl3;
boolean flag1;
#ifdef XX  
 d(1,"G_INIT_VARS", 9 ,pl->cel,0); 
#endif 
/* sohranitx GLOB */ 

/* branch */ pl1=*pl;rez1=NULL;success1=true; 
/* inicializaciq peremennyh */ 
loc1.sa=NULL;/* $prawilo*/ 
loc2.sa=NULL;/* $VARS*/ 
loc3.sa=NULL;/* $NOM*/ 
loc4.sa=NULL;/* $GVARS*/ 
loc5.sa=NULL;/* $X*/ 
loc6.sa=NULL;/* $GNOM*/ 

/* shablon peremennoj */ 
success1=(pl1.nel!=0);rez1=pl1.cel;
if( (pl1.ptrtype!=ptrtree) && success1 ) next(&pl1);
loc1 .sa=rez1; 
if( !success1 ) goto _L104;

/* operator := */ 
selop( 0L,true, loc1 .sa, glob1_1 .sa ,& wrk1 .sa); 
loc2 .sa= wrk1 .sa ;xxx; 

/* operator := */ 
selop( 0L,true, loc1 .sa, glob1_3 .sa ,& wrk1 .sa); 
loc3 .sa= wrk1 .sa ;xxx; 

/* operator := */ 
selop( 0L,true, loc1 .sa, glob1_2 .sa ,& wrk1 .sa); 
loc4 .sa= wrk1 .sa ;xxx; 

outatm(acnst[15],"/* inicializaciq peremennyh */",true, true); ;xxx; 

/*FORALL-op.*/ 
if( loc2.sa==NULL ) goto _L103;
pointr ( loc2 .sa ,&x.sa);  
if( (x.smld->dtype!=listmain)&&(x.smld->dtype!=treemain) 
  ) { er(24L);goto _L103;}; 
first(loc2.sa,&pl2);
while (pl2.nel!=0){
    if( pl2.ptrtype==ptrlist ) 
{loc5.sa=pl2.cel;} 
   else {
  mkatom(pl2.UU.U1.arc,idatom,&loc5.sa);
;}; 
/* IF-operator */ 
/* operaciq <> */ wrk1 .bo= ! eqatom( loc5 .sa ,acnst[ 13 ]) ; 
if( wrk1 .bo) 
{ 
/* operator := */ 
selop( 0L,true, loc5 .sa, loc4 .sa ,& wrk1 .sa); 
loc6 .sa= wrk1 .sa ;xxx; 
/* IF-operator */ 
if( loc6 .sa!=NULL) 
{ 
outatm(acnst[15],"glob",true, false); 
outxt(acnst[ 15 ], loc3 .sa , false, false); 
outatm(acnst[15],"_",false, false); 
outxt(acnst[ 15 ], loc6 .sa , false, false); 
outatm(acnst[15],".sa=NULL;",false, false); ;xxx; 
goto _L102;
;} 
wrk1 .bo= glob10_1 .sa==NULL; 
if( wrk1 .bo ) wrk4 .bo=true; else { 
selop( acnst[ 16 ],false,NULL, glob10_1 .sa ,& wrk2 .sa); 
selop( 0L,true, loc5 .sa, wrk2 .sa ,& wrk3 .sa); wrk4 .bo= wrk3 .sa!=NULL ;}; 
if( wrk4 .bo) 
{ 
outatm(acnst[15],"loc",true, false); 
selop( 0L,true, loc5 .sa, loc2 .sa ,& wrk1 .sa); 
outxt(acnst[ 15 ], wrk1 .sa , false, false); 
outatm(acnst[15],".sa=NULL;/* $",false, false); ;xxx; 
/* CALL #L */ 
pl3.ptrtype=packedlist;pl3.nel=1;pl3.cel=loc5.sa;
pl3.plistsize= 1;
r31(&wrk1.sa,&flag1,&pl3);/* #Print_name*/ ;xxx; 
outatm(acnst[15],"*/",false, true); ;xxx; 
;} 
_L102:;xxx; 
;} 
_L101:;xxx; 
next(&pl2) ;};_L103:/*END FORALL*/;xxx; 
goto _L99;  _L104:;  /* metka wyhoda po neuspehu wetwi */
 _L99: rez1=NULL; 
 _L98: *rez=rez1;*success=success1; 
 if (*success) *pl=pl1; /* prodwinutx ukazatelx leksem */ 
/* wosstanowitx GLOB */ 
#ifdef XX  
 d(2,"G_INIT_VARS", 9 ,*rez,*success); 
#endif 
;};/* RULE */ 
/*===============================================*/ 
/* GENERATED TEXT OF RULE   #G_ATOM_FROM_REZ   */ 
 Void r11(rez,success,pl)
long *rez;boolean *success;ptr_ *pl; 
{  a rez1;  boolean success1; long k; mpd x; 
v loc1;/* $E*/ 
v loc2;/* $E1*/ 
v wrk1;
v wrk2;
ptr_ pl1;
ptr_ pl2;
boolean flag1;
#ifdef XX  
 d(1,"G_ATOM_FROM_REZ", 11 ,pl->cel,0); 
#endif 
/* sohranitx GLOB */ 

/* branch */ pl1=*pl;rez1=NULL;success1=true; 
/* inicializaciq peremennyh */ 
loc1.sa=NULL;/* $E*/ 
loc2.sa=NULL;/* $E1*/ 

/* shablon treemain */ rez1=pl1.cel;
success1=false;if(pl1.nel==0 ) goto _L101; 
 if (rez1!=NULL ) { pointr(rez1,&x.sa); 
       if (x.smld->dtype!= treemain )  
        { rez1=NULL;goto _L101;};
;}; 
pl2.nel=1;pl2.ptrtype=ptrtree;
success1=true; 
selop(acnst[17],false,0L,pl1.cel,&rez1);pl2.cel=rez1;
   if( rez1==NULL ) { success1=false;goto _L101;};

/* shablon atoma */ atmpat(acnst[18],&pl2,&rez1,&success1);
if( !success1 ) goto _L101;
selop(acnst[19],false,0L,pl1.cel,&rez1);pl2.cel=rez1;
   if( rez1==NULL ) { success1=false;goto _L101;};

/* shablon peremennoj */ 
success1=(pl2.nel!=0);rez1=pl2.cel;
if( (pl2.ptrtype!=ptrtree) && success1 ) next(&pl2);
loc1 .sa=rez1; 
if( !success1 ) goto _L101;
selop(acnst[20],false,0L,pl1.cel,&rez1);pl2.cel=rez1;
   if( rez1==NULL ) { success1=false;goto _L101;};

/* shablon peremennoj */ 
success1=(pl2.nel!=0);rez1=pl2.cel;
if( (pl2.ptrtype!=ptrtree) && success1 ) next(&pl2);
loc2 .sa=rez1; 
if( !success1 ) goto _L101;
if( success1 ) {
 rez1=pl1.cel;if( pl1.ptrtype!=ptrtree ) next(&pl1) ;}
 else { rez1=NULL;goto _L101 ;};

outatm(acnst[15],"if(",true, true); 
outxt(acnst[ 15 ], loc1 .sa , false, true); 
outatm(acnst[15],".bo )",false, true); 
outxt(acnst[ 15 ], loc2 .sa , false, true); 
outatm(acnst[15],".sa=cnst[1].sa; else",false, true); 
outxt(acnst[ 15 ], loc2 .sa , false, true); 
outatm(acnst[15],".sa=NULL;",false, true); ;xxx; 
goto _L99;  _L101:;  /* metka wyhoda po neuspehu wetwi */

/* branch */ pl1=*pl;rez1=NULL;success1=true; 
/* inicializaciq peremennyh */ 
loc1.sa=NULL;/* $E*/ 
loc2.sa=NULL;/* $E1*/ 

/* shablon treemain */ rez1=pl1.cel;
success1=false;if(pl1.nel==0 ) goto _L103; 
 if (rez1!=NULL ) { pointr(rez1,&x.sa); 
       if (x.smld->dtype!= treemain )  
        { rez1=NULL;goto _L103;};
;}; 
pl2.nel=1;pl2.ptrtype=ptrtree;
success1=true; 
selop(acnst[17],false,0L,pl1.cel,&rez1);pl2.cel=rez1;
   if( rez1==NULL ) { success1=false;goto _L103;};

/* shablon atoma */ atmpat(acnst[21],&pl2,&rez1,&success1);
if( !success1 ) goto _L103;
selop(acnst[19],false,0L,pl1.cel,&rez1);pl2.cel=rez1;
   if( rez1==NULL ) { success1=false;goto _L103;};

/* shablon peremennoj */ 
success1=(pl2.nel!=0);rez1=pl2.cel;
if( (pl2.ptrtype!=ptrtree) && success1 ) next(&pl2);
loc1 .sa=rez1; 
if( !success1 ) goto _L103;
selop(acnst[20],false,0L,pl1.cel,&rez1);pl2.cel=rez1;
   if( rez1==NULL ) { success1=false;goto _L103;};

/* shablon peremennoj */ 
success1=(pl2.nel!=0);rez1=pl2.cel;
if( (pl2.ptrtype!=ptrtree) && success1 ) next(&pl2);
loc2 .sa=rez1; 
if( !success1 ) goto _L103;
if( success1 ) {
 rez1=pl1.cel;if( pl1.ptrtype!=ptrtree ) next(&pl1) ;}
 else { rez1=NULL;goto _L103 ;};

outatm(acnst[15],"mknumb(",true, true); ;xxx; 

/* IF-operator */ 
bltin(&wrk1,&flag1,loc1.sa,4L); 
wrk2 .bo= wrk1 .sa==NULL; 
if( wrk2 .bo) 
{ 
outxt(acnst[ 15 ], loc1 .sa , false, true); 
outatm(acnst[15],".nu",false, true); ;xxx; 
goto _L102;
;} 
{ 
outxt(acnst[ 15 ], loc1 .sa , false, false); 
outatm(acnst[15],"L",false, false); ;xxx; 
;} 
_L102:;xxx; 

outatm(acnst[15],",&",false, true); 
outxt(acnst[ 15 ], loc2 .sa , false, true); 
outatm(acnst[15],".sa);",false, true); ;xxx; 
goto _L99;  _L103:;  /* metka wyhoda po neuspehu wetwi */
 _L99: rez1=NULL; 
 _L98: *rez=rez1;*success=success1; 
 if (*success) *pl=pl1; /* prodwinutx ukazatelx leksem */ 
/* wosstanowitx GLOB */ 
#ifdef XX  
 d(2,"G_ATOM_FROM_REZ", 11 ,*rez,*success); 
#endif 
;};/* RULE */ 
/*===============================================*/ 
/* GENERATED TEXT OF RULE   #G_LABELS   */ 
 Void r12(rez,success,pl)
long *rez;boolean *success;ptr_ *pl; 
{  a rez1;  boolean success1; long k; mpd x; 
v loc1;/* $N*/ 
ptr_ pl1;
#ifdef XX  
 d(1,"G_LABELS", 12 ,pl->cel,0); 
#endif 
/* sohranitx GLOB */ 

/* branch */ pl1=*pl;rez1=NULL;success1=true; 
/* inicializaciq peremennyh */ 

/* shablon peremennoj */ 
varpat(&pl1,number,&rez1,&success1);
loc1 .sa=rez1; 
if( !success1 ) goto _L101;
goto _L99;  _L101:;  /* metka wyhoda po neuspehu wetwi */
 _L99: rez1=NULL; 
 _L98: *rez=rez1;*success=success1; 
 if (*success) *pl=pl1; /* prodwinutx ukazatelx leksem */ 
/* wosstanowitx GLOB */ 
#ifdef XX  
 d(2,"G_LABELS", 12 ,*rez,*success); 
#endif 
;};/* RULE */ 
