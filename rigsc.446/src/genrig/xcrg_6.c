
#include "globrig.h" 
#include "define.h"  
#include "defpage.h" 
#include "nef2.h"    
#include "c1.h"      
#include "usemod.h"  
#include "def180.h"  
#include "xcrg.h"    
/*  R49 WW */ 
/*  R50 G_INIT_GLOB */ 
/*  R51 GEN_ATOM_INITIALIZATION */ 
/*  R52 ACON_LIST */ 
/*  R53 G_COMMON_PART */ 
/*===============================================*/ 
/* GENERATED TEXT OF RULE   #WW   */ 
 Void r49(rez,success,pl)
long *rez;boolean *success;ptr_ *pl; 
{  a rez1;  boolean success1; long k; mpd x; 
v loc1;/* $w*/ 
v loc2;/* $dd*/ 
ptr_ pl1;
#ifdef XX  
 d(1,"WW", 49 ,pl->cel,0); 
#endif 
/* sohranitx GLOB */ 

/* branch */ pl1=*pl;rez1=NULL;success1=true; 
/* inicializaciq peremennyh */ 

loc1 .sa=NULL; 

/* shablon peremennoj */ 
success1=(pl1.nel!=0);rez1=pl1.cel;
if( (pl1.ptrtype!=ptrtree) && success1 ) next(&pl1);
loc2 .sa=rez1; 
if( !success1 ) goto _L101;
loc1 .sa=rez1; 
goto _L99;  _L101:;  /* metka wyhoda po neuspehu wetwi */
 _L99: rez1=NULL; 
 _L98: *rez=rez1;*success=success1; 
 if (*success) *pl=pl1; /* prodwinutx ukazatelx leksem */ 
/* wosstanowitx GLOB */ 
#ifdef XX  
 d(2,"WW", 49 ,*rez,*success); 
#endif 
;};/* RULE */ 
/*===============================================*/ 
/* GENERATED TEXT OF RULE   #G_INIT_GLOB   */ 
 Void r50(rez,success,pl)
long *rez;boolean *success;ptr_ *pl; 
{  a rez1;  boolean success1; long k; mpd x; 
v loc1;/* $TABL*/ 
v loc2;/* $X*/ 
v loc3;/* $VARS*/ 
v loc4;/* $NOM*/ 
v loc5;/* $Y*/ 
v wrk1;
ptr_ pl1;
ptr_ pl2;
ptr_ pl3;
#ifdef XX  
 d(1,"G_INIT_GLOB", 50 ,pl->cel,0); 
#endif 
/* sohranitx GLOB */ 

/* branch */ pl1=*pl;rez1=NULL;success1=true; 
/* inicializaciq peremennyh */ 
loc1.sa=NULL;/* $TABL*/ 
loc2.sa=NULL;/* $X*/ 
loc3.sa=NULL;/* $VARS*/ 
loc4.sa=NULL;/* $NOM*/ 
loc5.sa=NULL;/* $Y*/ 

/* operator := */ 
loc1 .sa= glob1_2 .sa ;xxx; 

outatm(acnst[15],"/* inicializaciq LAST-perem.*/",true, true); ;xxx; 

/*FORALL-op.*/ 
if( loc1.sa==NULL ) goto _L103;
pointr ( loc1 .sa ,&x.sa);  
if( (x.smld->dtype!=listmain)&&(x.smld->dtype!=treemain) 
  ) { er(24L);goto _L103;}; 
first(loc1.sa,&pl2);
while (pl2.nel!=0){
    if( pl2.ptrtype==ptrlist ) 
{loc2.sa=pl2.cel;} 
   else {
  mkatom(pl2.UU.U1.arc,idatom,&loc2.sa);
;}; 
/* IF-operator */ 
/* operaciq <> */ wrk1 .bo= ! eqop(0L, loc2 .sa , glob24_3 .sa ) ; 
if( wrk1 .bo) 
{ 
/* operator := */ 
selop( 0L,true, loc2 .sa, loc1 .sa ,& wrk1 .sa); 
loc3 .sa= wrk1 .sa ;xxx; 
/* operator := */ 
selop( 0L,true, loc2 .sa, glob1_3 .sa ,& wrk1 .sa); 
loc4 .sa= wrk1 .sa ;xxx; 
/*FORALL-op.*/ 
if( loc3.sa==NULL ) goto _L102;
pointr ( loc3 .sa ,&x.sa);  
if( (x.smld->dtype!=listmain)&&(x.smld->dtype!=treemain) 
  ) { er(24L);goto _L102;}; 
first(loc3.sa,&pl3);
while (pl3.nel!=0){
    if( pl3.ptrtype==ptrlist ) 
{loc5.sa=pl3.cel;} 
   else {
  mkatom(pl3.UU.U1.arc,idatom,&loc5.sa);
;}; 
outatm(acnst[15],"glob",true, false); 
outxt(acnst[ 15 ], loc4 .sa , false, false); 
outatm(acnst[15],"_",false, false); 
selop( 0L,true, loc5 .sa, loc3 .sa ,& wrk1 .sa); 
outxt(acnst[ 15 ], wrk1 .sa , false, false); 
outatm(acnst[15],".sa=NULL;",false, false); ;xxx; 
next(&pl3) ;};_L102:/*END FORALL*/;xxx; 
;} 
_L101:;xxx; 
next(&pl2) ;};_L103:/*END FORALL*/;xxx; 
goto _L99;  _L104:;  /* metka wyhoda po neuspehu wetwi */
 _L99: rez1=NULL; 
 _L98: *rez=rez1;*success=success1; 
 if (*success) *pl=pl1; /* prodwinutx ukazatelx leksem */ 
/* wosstanowitx GLOB */ 
#ifdef XX  
 d(2,"G_INIT_GLOB", 50 ,*rez,*success); 
#endif 
;};/* RULE */ 
/*===============================================*/ 
/* GENERATED TEXT OF RULE   #GEN_ATOM_INITIALIZATION   */ 
 Void r51(rez,success,pl)
long *rez;boolean *success;ptr_ *pl; 
{  a rez1;  boolean success1; long k; mpd x; 
v loc1;/* $LISTACON*/ 
v loc2;/* $LISTACOP*/ 
v wrk1;
v wrk2;
v wrk3;
ptr_ pl1;
ptr_ pl2;
boolean flag1;
#ifdef XX  
 d(1,"GEN_ATOM_INITIALIZATION", 51 ,pl->cel,0); 
#endif 
/* sohranitx GLOB */ 

/* branch */ pl1=*pl;rez1=NULL;success1=true; 
/* inicializaciq peremennyh */ 
loc1.sa=NULL;/* $LISTACON*/ 
loc2.sa=NULL;/* $LISTACOP*/ 

/* shablon peremennoj */ 
success1=(pl1.nel!=0);rez1=pl1.cel;
if( (pl1.ptrtype!=ptrtree) && success1 ) next(&pl1);
loc1 .sa=rez1; 
if( !success1 ) goto _L101;

/* shablon peremennoj */ 
success1=(pl1.nel!=0);rez1=pl1.cel;
if( (pl1.ptrtype!=ptrtree) && success1 ) next(&pl1);
loc2 .sa=rez1; 
if( !success1 ) goto _L101;

opn(acnst[ 101 ], cnst[50] .sa ) ;xxx; 

outatm(acnst[101],"/* Local variables for acon: */  ",true, true); ;xxx; 

outatm(acnst[101],"struct LOC_acon {a k;allpacked r;} ;",true, true); ;xxx; 

outatm(acnst[101],"Local Void uc(l, cn, dt, LINK)      ",true, true); ;xxx; 

outatm(acnst[101],"long l, cn; char dt;                ",true, true); ;xxx; 

outatm(acnst[101],"struct LOC_acon *LINK;              ",true, true); ;xxx; 

outatm(acnst[101],"{  putatm(LINK->r.bl, l, &LINK->k); ",true, true); ;xxx; 

outatm(acnst[101],"  mkatom(LINK->k, dt, &cnst[cn ].sa);}",true, true); ;xxx; 

outatm(acnst[101],"Static Void acon()                 ",true, true); ;xxx; 

outatm(acnst[101],"{  struct LOC_acon V;    mpd x;    ",true, true); ;xxx; 

outatm(acnst[101],"  mainlistdescriptor *WITH;        ",true, true); ;xxx; 

/* CALL #L */ 
pl2.ptrtype=packedlist;pl2.nel=1;pl2.cel=cnst[2].sa;
pl2.UU.plistelt[ 0 ]=loc1.sa;
pl2.plistsize= 2;
r52(&wrk1.sa,&flag1,&pl2);/* #ACON_LIST*/ ;xxx; 

outatm(acnst[101],"  gets5(&cnst[",true, true); 
bltin(&wrk1,&flag1,glob1_6.sa,15L); 
wrk2 .nu= wrk1 .nu + 1L ; 
mknumb( wrk2 .nu ,& wrk3 .sa); 
outxt(acnst[ 101 ], wrk3 .sa , false, true); 
outatm(acnst[101],"].sa, &x.sa);",false, true); ;xxx; 

outatm(acnst[101],"  WITH = x.smld;  ",true, true); ;xxx; 

outatm(acnst[101],"  WITH->dtype = listmain; ",true, true); ;xxx; 

outatm(acnst[101],"  WITH->elnum = 1;        ",true, true); ;xxx; 

outatm(acnst[101],"  WITH->totalelnum = 1;   ",true, true); ;xxx; 

outatm(acnst[101],"  WITH->name = null_;     ",true, true); ;xxx; 

outatm(acnst[101],"  WITH->next = null_;}    ",true, true); ;xxx; 

outatm(acnst[101],"/* Local variables for acop: */    ",true, true); ;xxx; 

outatm(acnst[101],"struct LOC_acop {  allpacked r;} ; ",true, true); ;xxx; 

outatm(acnst[101],"Local Void uc_(l, cn, dt, LINK)    ",true, true); ;xxx; 

outatm(acnst[101],"long l, cn; char dt;               ",true, true); ;xxx; 

outatm(acnst[101],"struct LOC_acop *LINK;             ",true, true); ;xxx; 

outatm(acnst[101],"{putatm(LINK->r.bl, l, &acnst[cn ]);}  ",true, true); ;xxx; 

outatm(acnst[101],"Static Void acop()    ",true, true); ;xxx; 

outatm(acnst[101],"{struct LOC_acop V;   ",true, true); ;xxx; 

/* CALL #L */ 
pl2.ptrtype=packedlist;pl2.nel=1;pl2.cel=cnst[40].sa;
pl2.UU.plistelt[ 0 ]=loc2.sa;
pl2.plistsize= 2;
r52(&wrk1.sa,&flag1,&pl2);/* #ACON_LIST*/ ;xxx; 

outatm(acnst[101],"}",true, true); ;xxx; 

clsfil(acnst[ 101 ]) ;xxx; 
goto _L99;  _L101:;  /* metka wyhoda po neuspehu wetwi */
 _L99: rez1=NULL; 
 _L98: *rez=rez1;*success=success1; 
 if (*success) *pl=pl1; /* prodwinutx ukazatelx leksem */ 
/* wosstanowitx GLOB */ 
#ifdef XX  
 d(2,"GEN_ATOM_INITIALIZATION", 51 ,*rez,*success); 
#endif 
;};/* RULE */ 
/*===============================================*/ 
/* GENERATED TEXT OF RULE   #ACON_LIST   */ 
 Void r52(rez,success,pl)
long *rez;boolean *success;ptr_ *pl; 
{  a rez1;  boolean success1; long k; mpd x; 
v loc1;/* $MARK*/ 
v loc2;/* $E*/ 
v loc3;/* $I*/ 
v loc4;/* $LEN*/ 
v loc5;/* $ID*/ 
v wrk1;
v wrk2;
v wrk3;
ptr_ pl1;
ptr_ pl2;
ptr_ pl3;
ptr_ pl4;
boolean flag1;
#ifdef XX  
 d(1,"ACON_LIST", 52 ,pl->cel,0); 
#endif 
/* sohranitx GLOB */ 

/* branch */ pl1=*pl;rez1=NULL;success1=true; 
/* inicializaciq peremennyh */ 
loc1.sa=NULL;/* $MARK*/ 
loc2.sa=NULL;/* $E*/ 
loc3.sa=NULL;/* $I*/ 
loc4.sa=NULL;/* $LEN*/ 
loc5.sa=NULL;/* $ID*/ 

/* shablon peremennoj */ 
success1=(pl1.nel!=0);rez1=pl1.cel;
if( (pl1.ptrtype!=ptrtree) && success1 ) next(&pl1);
loc1 .sa=rez1; 
if( !success1 ) goto _L105;

/* shablon listmain */ rez1=pl1.cel;
success1=false;if(pl1.nel==0 ) goto _L105; 
 if (rez1!=NULL ) { pointr(rez1,&x.sa); 
       if (x.smld->dtype!= listmain )  
        { rez1=NULL;goto _L105;};
{pl2.ptrtype=ptrlist; pl2.nel=1;
pl2.cel=x.smld->elt[0];pl2.UU.U1.curfragment=rez1;}
;} else  
{pl2.ptrtype=ptrlist;pl2.nel=0;pl2.cel=NULL;}

/*shablon STARLIST */ 
 pl3=pl2;while(pl2.nel!=0 ) { 

/* shablon peremennoj */ 
success1=(pl2.nel!=0);rez1=pl2.cel;
if( (pl2.ptrtype!=ptrtree) && success1 ) next(&pl2);
loc2 .sa=rez1; 
if( !success1 ) goto _L104;

/* operator +:= */ 
addnum(& loc3 .sa, 1L ) ;xxx; 

/* operator := */ 
bltin(&wrk1,&flag1,loc2.sa,15L); 
mknumb( wrk1 .nu ,& wrk2 .sa); 
loc4 .sa= wrk2 .sa ;xxx; 

/* IF-operator */ 
/* operaciq = */ wrk1 .bo= eqnum( loc4 .sa , 1L ) ; 
if( wrk1 .bo) 
{ 
/* IF-operator */ 
/* operaciq = */ wrk1 .bo= eqatom( loc2 .sa ,acnst[ 102 ]) ; 
if( wrk1 .bo ) wrk3 .bo=true; else { 
/* operaciq = */ wrk2 .bo= eqatom( loc2 .sa ,acnst[ 103 ]) ; wrk3 = wrk2 ;}; 
if( wrk3 .bo) 
{ 
outatm(acnst[101],"V.r.p1='\\",true, false); 
outxt(acnst[ 101 ], loc2 .sa , false, false); 
outatm(acnst[101],"';",false, false); ;xxx; 
goto _L102;
;} 
{ 
outatm(acnst[101],"V.r.p1='",true, false); 
outxt(acnst[ 101 ], loc2 .sa , false, false); 
outatm(acnst[101],"';",false, false); ;xxx; 
;} 
_L102:;xxx; 
goto _L101;
;} 
{ 
outatm(acnst[101],"memcpy(V.r.p",true, false); 
outxt(acnst[ 101 ], loc4 .sa , false, false); 
outatm(acnst[101],",",false, false); 
/* CALL_PAS */ 
use_116(loc2.sa,NULL,NULL,&wrk2.sa);; 
outxt(acnst[ 101 ], wrk2 .sa , false, false); 
outatm(acnst[101],",",false, false); 
outxt(acnst[ 101 ], loc4 .sa , false, false); 
outatm(acnst[101],"L);",false, false); ;xxx; 
;} 
_L101:;xxx; 

/* IF-operator */ 
bltin(&wrk1,&flag1,loc2.sa,5L); 
if( wrk1 .sa!=NULL) 
{ 
/* operator := */ 
loc5 .sa= cnst[51] .sa ;xxx; 
goto _L103;
;} 
{ 
/* operator := */ 
loc5 .sa= cnst[52] .sa ;xxx; 
;} 
_L103:;xxx; 

outatm(acnst[101],"uc",true, false); 
outxt(acnst[ 101 ], loc1 .sa , false, false); 
outatm(acnst[101],"(",false, false); 
outxt(acnst[ 101 ], loc4 .sa , false, false); 
outatm(acnst[101],"L,",false, false); 
outxt(acnst[ 101 ], loc3 .sa , false, false); 
outatm(acnst[101],"L,",false, false); 
outxt(acnst[ 101 ], loc5 .sa , false, false); 
outatm(acnst[101],",&V);",false, false); ;xxx; 
 pl3=pl2;
;}; 
_L104:if( ! success1 )pl2=pl3;
success1 = true ; 

if( pl2.nel !=0 )
{ success1=false;rez1=NULL;goto _L105;};
success1=true;rez1=pl1.cel;
 if( pl1.ptrtype!=ptrtree ) next(&pl1);

/* RETURN-op. */ 
rez1 = loc3 .sa ;goto _L98 ;xxx; 
goto _L99;  _L105:;  /* metka wyhoda po neuspehu wetwi */
 _L99: rez1=NULL; 
 _L98: *rez=rez1;*success=success1; 
 if (*success) *pl=pl1; /* prodwinutx ukazatelx leksem */ 
/* wosstanowitx GLOB */ 
#ifdef XX  
 d(2,"ACON_LIST", 52 ,*rez,*success); 
#endif 
;};/* RULE */ 
/*===============================================*/ 
/* GENERATED TEXT OF RULE   #G_COMMON_PART   */ 
 Void r53(rez,success,pl)
long *rez;boolean *success;ptr_ *pl; 
{  a rez1;  boolean success1; long k; mpd x; 
v loc1;/* $P*/ 
v loc2;/* $X*/ 
v loc3;/* $VAR*/ 
v loc4;/* $N*/ 
v loc5;/* $U*/ 
v wrk1;
v wrk2;
v wrk3;
ptr_ pl1;
ptr_ pl2;
ptr_ pl3;
boolean flag1;
#ifdef XX  
 d(1,"G_COMMON_PART", 53 ,pl->cel,0); 
#endif 
/* sohranitx GLOB */ 

/* branch */ pl1=*pl;rez1=NULL;success1=true; 
/* inicializaciq peremennyh */ 
loc1.sa=NULL;/* $P*/ 
loc2.sa=NULL;/* $X*/ 
loc3.sa=NULL;/* $VAR*/ 
loc4.sa=NULL;/* $N*/ 
loc5.sa=NULL;/* $U*/ 

opn(acnst[ 104 ], cnst[53] .sa ) ;xxx; 

outatm(acnst[104],"v cnst[",true, false); 
bltin(&wrk1,&flag1,glob1_6.sa,15L); 
wrk2 .nu= wrk1 .nu + 2L ; 
mknumb( wrk2 .nu ,& wrk3 .sa); 
outxt(acnst[ 104 ], wrk3 .sa , false, false); 
outatm(acnst[104],"];",false, false); ;xxx; 

outatm(acnst[104],"a acnst[",true, false); 
bltin(&wrk1,&flag1,glob1_7.sa,15L); 
wrk2 .nu= wrk1 .nu + 1L ; 
mknumb( wrk2 .nu ,& wrk3 .sa); 
outxt(acnst[ 104 ], wrk3 .sa , false, false); 
outatm(acnst[104],"];",false, false); ;xxx; 

/*FORALL-op.*/ 
if( glob1_2.sa==NULL ) goto _L102;
pointr ( glob1_2 .sa ,&x.sa);  
if( (x.smld->dtype!=listmain)&&(x.smld->dtype!=treemain) 
  ) { er(24L);goto _L102;}; 
first(glob1_2.sa,&pl2);
while (pl2.nel!=0){
    if( pl2.ptrtype==ptrlist ) 
{loc1.sa=pl2.cel;} 
   else {
  mkatom(pl2.UU.U1.arc,idatom,&loc1.sa);
;}; 
/* operator := */ 
selop( 0L,true, loc1 .sa, glob1_2 .sa ,& wrk1 .sa); 
loc2 .sa= wrk1 .sa ;xxx; 
/*FORALL-op.*/ 
if( loc2.sa==NULL ) goto _L101;
pointr ( loc2 .sa ,&x.sa);  
if( (x.smld->dtype!=listmain)&&(x.smld->dtype!=treemain) 
  ) { er(24L);goto _L101;}; 
first(loc2.sa,&pl3);
while (pl3.nel!=0){
    if( pl3.ptrtype==ptrlist ) 
{loc3.sa=pl3.cel;} 
   else {
  mkatom(pl3.UU.U1.arc,idatom,&loc3.sa);
;}; 
outxt(acnst[ 104 ], cnst[54] .sa , true, false); 
selop( 0L,true, loc1 .sa, glob1_3 .sa ,& wrk1 .sa); 
outxt(acnst[ 104 ], wrk1 .sa , false, false); 
outatm(acnst[104],"_",false, false); 
selop( 0L,true, loc3 .sa, loc2 .sa ,& wrk1 .sa); 
outxt(acnst[ 104 ], wrk1 .sa , false, false); 
outatm(acnst[104],";",false, false); ;xxx; 
next(&pl3) ;};_L101:/*END FORALL*/;xxx; 
next(&pl2) ;};_L102:/*END FORALL*/;xxx; 

/* operator := */ 
bltin(&wrk1,&flag1,glob1_3.sa,15L); 
mknumb( wrk1 .nu ,& wrk2 .sa); 
loc4 .sa= wrk2 .sa ;xxx; 

/* operator := */ 
indxop( 4L,false,NULL, glob1_5 .sa ,& wrk1 .sa); 
loc5 .sa= wrk1 .sa ;xxx; 

/* operator := */ 
mknumb( 2L,& wrk1 .sa); 
loc2 .sa= wrk1 .sa ;xxx; 

/*LOOP*/while (true) { 
/* IF-operator */ 
wrk1 .bo=compare( 3L , loc2 .sa , loc4 .sa ); 
if( wrk1 .bo) 
{ 
/*BREAK*/ goto _L104;xxx; 
;} 
_L103:;xxx; 
outatm(acnst[104],"extern Void r",true, false); 
outxt(acnst[ 104 ], loc2 .sa , false, false); 
outatm(acnst[104]," PP((long *rez, boolean *success, ptr_ *pl));",false, false);
 ;xxx; 
/* operator +:= */ 
addnum(& loc2 .sa, 1L ) ;xxx; 
;};  _L104:/*END LOOP*/;xxx; 

clsfil(acnst[ 104 ]) ;xxx; 
goto _L99;  _L105:;  /* metka wyhoda po neuspehu wetwi */
 _L99: rez1=NULL; 
 _L98: *rez=rez1;*success=success1; 
 if (*success) *pl=pl1; /* prodwinutx ukazatelx leksem */ 
/* wosstanowitx GLOB */ 
#ifdef XX  
 d(2,"G_COMMON_PART", 53 ,*rez,*success); 
#endif 
;};/* RULE */ 
