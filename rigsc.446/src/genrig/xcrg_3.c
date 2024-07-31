
#include "globrig.h" 
#include "define.h"  
#include "defpage.h" 
#include "nef2.h"    
#include "c1.h"      
#include "usemod.h"  
#include "def180.h"  
#include "xcrg.h"    
/*  R24 G_programma */ 
/*  R29 G_UNIT */ 
/*  R30 G_telo_glawn */ 
/*  R31 Print_name */ 
/*  R3 G_prawilo */ 
/*  R10 G_SIMPLE */ 
/*===============================================*/ 
/* GENERATED TEXT OF RULE   #G_programma   */ 
 Void r24(rez,success,pl)
long *rez;boolean *success;ptr_ *pl; 
{  a rez1;  boolean success1; long k; mpd x; 
v loc3;/* $MAXWRK*/ 
v loc4;/* $MAXPL*/ 
v loc5;/* $MAX_FLAG*/ 
v loc6;/* $MAXLABEL*/ 
v loc7;/* $BODY*/ 
v loc9;/* $PROCNAME*/ 
v loc10;/* $EEE*/ 
v wrk1;
v oldglob24_1;
v oldglob24_2;
v oldglob24_3;
ptr_ pl1;
ptr_ pl2;
boolean flag1;
#ifdef XX  
 d(1,"G_programma", 24 ,pl->cel,0); 
#endif 
/* sohranitx GLOB */ 
oldglob24_1=glob24_1;
oldglob24_2=glob24_2;
oldglob24_3=glob24_3;

/* branch */ pl1=*pl;rez1=NULL;success1=true; 
/* inicializaciq peremennyh */ 
glob24_1.sa=NULL;
glob24_3.sa=NULL;
loc3.sa=NULL;/* $MAXWRK*/ 
loc4.sa=NULL;/* $MAXPL*/ 
loc5.sa=NULL;/* $MAX_FLAG*/ 
loc6.sa=NULL;/* $MAXLABEL*/ 
loc7.sa=NULL;/* $BODY*/ 
glob24_2.sa=NULL;
loc9.sa=NULL;/* $PROCNAME*/ 

/* shablon atoma */ atmpat(acnst[52],&pl1,&rez1,&success1);
if( !success1 ) goto _L105;

/* shablon treemain */ rez1=pl1.cel;
success1=false;if(pl1.nel==0 ) goto _L105; 
 if (rez1!=NULL ) { pointr(rez1,&x.sa); 
       if (x.smld->dtype!= treemain )  
        { rez1=NULL;goto _L105;};
/* prowerka imeni */ 
glob24_3 .sa=x.smld->name; 
;}; 
pl2.nel=1;pl2.ptrtype=ptrtree;
success1=true; 
selop(acnst[53],false,0L,pl1.cel,&rez1);pl2.cel=rez1;
   if( rez1==NULL ) { success1=false;goto _L105;};

/* shablon peremennoj */ 
success1=(pl2.nel!=0);rez1=pl2.cel;
if( (pl2.ptrtype!=ptrtree) && success1 ) next(&pl2);
loc3 .sa=rez1; 
if( !success1 ) goto _L105;
selop(acnst[54],false,0L,pl1.cel,&rez1);pl2.cel=rez1;
   if( rez1==NULL ) { success1=false;goto _L105;};

/* shablon peremennoj */ 
success1=(pl2.nel!=0);rez1=pl2.cel;
if( (pl2.ptrtype!=ptrtree) && success1 ) next(&pl2);
loc4 .sa=rez1; 
if( !success1 ) goto _L105;
selop(acnst[55],false,0L,pl1.cel,&rez1);pl2.cel=rez1;
   if( rez1==NULL ) { success1=false;goto _L101;};

/* shablon peremennoj */ 
success1=(pl2.nel!=0);rez1=pl2.cel;
if( (pl2.ptrtype!=ptrtree) && success1 ) next(&pl2);
loc5 .sa=rez1; 
if( !success1 ) goto _L101;
_L101:success1=true;
selop(acnst[56],false,0L,pl1.cel,&rez1);pl2.cel=rez1;
   if( rez1==NULL ) { success1=false;goto _L105;};

/* shablon peremennoj */ 
success1=(pl2.nel!=0);rez1=pl2.cel;
if( (pl2.ptrtype!=ptrtree) && success1 ) next(&pl2);
loc6 .sa=rez1; 
if( !success1 ) goto _L105;
selop(acnst[39],false,0L,pl1.cel,&rez1);pl2.cel=rez1;
   if( rez1==NULL ) { success1=false;goto _L102;};

/* shablon peremennoj */ 
success1=(pl2.nel!=0);rez1=pl2.cel;
if( (pl2.ptrtype!=ptrtree) && success1 ) next(&pl2);
loc7 .sa=rez1; 
if( !success1 ) goto _L102;
_L102:success1=true;
if( success1 ) {
 rez1=pl1.cel;if( pl1.ptrtype!=ptrtree ) next(&pl1) ;}
 else { rez1=NULL;goto _L105 ;};

opn(acnst[ 15 ], cnst[25] .sa ) ;xxx; 

outatm(acnst[15],"/* ****************************************** */",true, true);
 ;xxx; 

outatm(acnst[15],"/*      rigal/pascal compiler                 */",true, true);
 ;xxx; 

outatm(acnst[15],"/*  vax/vms & omsi/rsx & ms/dos & ms-windows  */",true, true);
 ;xxx; 

outatm(acnst[15],"/*  & unix/sun         v 2.42/4.45 february 1996    */",true, 
true); ;xxx; 

outatm(acnst[15],"/*      author M.Auguston,Riga                */",true, true);
 ;xxx; 

outatm(acnst[15],"/*  adaptation by V.Engelson ,Riga            */",true, true);
 ;xxx; 

outatm(acnst[15],"/*  sponsored by P.Fritzson, Linkoping        */",true, true);
 ;xxx; 

outatm(acnst[15],"/*  IMCS University of Latvia ,Riga (c) 1987-1996  */",true, 
true); ;xxx; 

outatm(acnst[15],"/*  IDA Linkoping  University, Sweden         */",true, true);
 ;xxx; 

outatm(acnst[15],"/* ****************************************** */",true, true);
 ;xxx; 

outatm(acnst[15],"#include \"globrig.h\" ",true, true); ;xxx; 

outatm(acnst[15],"#include \"define.h\"  ",true, true); ;xxx; 

outatm(acnst[15],"#include \"defpage.h\" ",true, true); ;xxx; 

outatm(acnst[15],"#include \"nef2.h\"    ",true, true); ;xxx; 

outatm(acnst[15],"#include \"c1.h\"      ",true, true); ;xxx; 

outatm(acnst[15],"#include \"usemod.h\"  ",true, true); ;xxx; 

outatm(acnst[15],"#include \"def180.h\"  ",true, true); ;xxx; 

outatm(acnst[15],"#include \"xcrg.h\"    ",true, true); ;xxx; 

outatm(acnst[15],"#include \"xcrga.h\"   ",true, true); ;xxx; 

outatm(acnst[15],"a rez1;boolean success1;long k;mpd x;",true, true); ;xxx; 

/* CALL #L */ 
pl2.ptrtype=packedlist;pl2.nel=1;pl2.cel=glob24_3.sa;
pl2.plistsize= 1;
r2(&wrk1.sa,&flag1,&pl2);/* #G_LOC_dekl*/ ;xxx; 

/* CALL #L */ 
pl2.ptrtype=packedlist;pl2.nel=1;pl2.cel=loc3.sa;
pl2.plistsize= 1;
r4(&wrk1.sa,&flag1,&pl2);/* #G_WRK_dekl*/ ;xxx; 

/* CALL #L */ 
pl2.ptrtype=packedlist;pl2.nel=1;pl2.cel=loc4.sa;
pl2.plistsize= 1;
r5(&wrk1.sa,&flag1,&pl2);/* #G_PL_dekl*/ ;xxx; 

/* CALL #L */ 
pl2.ptrtype=packedlist;pl2.nel=1;pl2.cel=loc5.sa;
pl2.plistsize= 1;
r6(&wrk1.sa,&flag1,&pl2);/* #G_FLAG_dekl*/ ;xxx; 

/* IF-operator */ 
wrk1 .bo= numval( loc6 .sa) > 100L ; 
if( wrk1 .bo) 
{ 
/* CALL #L */ 
pl2.ptrtype=packedlist;pl2.nel=1;pl2.cel=loc6.sa;
pl2.plistsize= 1;
r12(&wrk1.sa,&flag1,&pl2);/* #G_LABELS*/ ;xxx; 
;} 
_L103:;xxx; 

/* operator := */ 
glob24_2 .sa= glob24_3 .sa ;xxx; 

outatm(acnst[15],"main(argc, argv)",true, true); ;xxx; 

outatm(acnst[15],"int argc;Char *argv[];",true, true); ;xxx; 

outatm(acnst[15],"{ out = NULL;  ",true, true); ;xxx; 

outatm(acnst[15],"  g_argc=argc;  g_argv=argv;",true, true); ;xxx; 

outatm(acnst[15],"  prolog(argc,argv);  acon(); acop();",true, true); ;xxx; 

/*FORALL-op.*/ 
if( glob1_4.sa==NULL ) goto _L104;
pointr ( glob1_4 .sa ,&x.sa);  
if( (x.smld->dtype!=listmain)&&(x.smld->dtype!=treemain) 
  ) { er(24L);goto _L104;}; 
first(glob1_4.sa,&pl2);
while (pl2.nel!=0){
    if( pl2.ptrtype==ptrlist ) 
{loc9.sa=pl2.cel;} 
   else {
  mkatom(pl2.UU.U1.arc,idatom,&loc9.sa);
;}; 
outxt(acnst[ 15 ], loc9 .sa , false, true); 
outatm(acnst[15],"();",false, true); ;xxx; 
next(&pl2) ;};_L104:/*END FORALL*/;xxx; 

/* CALL #L */ 
pl2.ptrtype=packedlist;pl2.nel=1;pl2.cel=glob24_3.sa;
pl2.plistsize= 1;
r9(&wrk1.sa,&flag1,&pl2);/* #G_INIT_VARS*/ ;xxx; 

/* CALL #L */ 
pl2.ptrtype=ptrlist;pl2.nel=0;pl2.cel=NULL;
r50(&wrk1.sa,&flag1,&pl2);/* #G_INIT_GLOB*/ ;xxx; 

/* CALL #L */ 
pl2.ptrtype=packedlist;pl2.nel=1;pl2.cel=loc7.sa;
pl2.plistsize= 1;
r30(&wrk1.sa,&flag1,&pl2);/* #G_telo_glawn*/ ;xxx; 

outatm(acnst[15],"   _L98:;",true, true); ;xxx; 

outatm(acnst[15],"   _L99: epilog();",true, true); ;xxx; 

outatm(acnst[15]," if(out!=NULL) fclose(out);exit(0);",true, true); ;xxx; 

outatm(acnst[15]," } ",true, true); ;xxx; 

clsfil(acnst[ 15 ]) ;xxx; 
goto _L99;  _L105:;  /* metka wyhoda po neuspehu wetwi */

/* branch */ pl1=*pl;rez1=NULL;success1=true; 
/* inicializaciq peremennyh */ 
glob24_1.sa=NULL;
glob24_3.sa=NULL;
glob24_2.sa=NULL;

/* shablon atoma */ atmpat(acnst[57],&pl1,&rez1,&success1);
if( !success1 ) goto _L106;

/* shablon listmain */ rez1=pl1.cel;
success1=false;if(pl1.nel==0 ) goto _L106; 
 if (rez1!=NULL ) { pointr(rez1,&x.sa); 
       if (x.smld->dtype!= listmain )  
        { rez1=NULL;goto _L106;};
{pl2.ptrtype=ptrlist; pl2.nel=1;
pl2.cel=x.smld->elt[0];pl2.UU.U1.curfragment=rez1;}
;} else  
{pl2.ptrtype=ptrlist;pl2.nel=0;pl2.cel=NULL;}

/* shablon prawila */ r29(&rez1,&success1,&pl2);
if( !success1 ) goto _L106;

if( pl2.nel !=0 )
{ success1=false;rez1=NULL;goto _L106;};
success1=true;rez1=pl1.cel;
 if( pl1.ptrtype!=ptrtree ) next(&pl1);
goto _L99;  _L106:;  /* metka wyhoda po neuspehu wetwi */

/* branch */ pl1=*pl;rez1=NULL;success1=true; 
/* inicializaciq peremennyh */ 
glob24_1.sa=NULL;
glob24_3.sa=NULL;
glob24_2.sa=NULL;

/* shablon atoma */ atmpat(acnst[58],&pl1,&rez1,&success1);
if( !success1 ) goto _L107;

/* shablon listmain */ rez1=pl1.cel;
success1=false;if(pl1.nel==0 ) goto _L107; 
 if (rez1!=NULL ) { pointr(rez1,&x.sa); 
       if (x.smld->dtype!= listmain )  
        { rez1=NULL;goto _L107;};
{pl2.ptrtype=ptrlist; pl2.nel=1;
pl2.cel=x.smld->elt[0];pl2.UU.U1.curfragment=rez1;}
;} else  
{pl2.ptrtype=ptrlist;pl2.nel=0;pl2.cel=NULL;}

/* shablon peremennoj */ 
success1=(pl2.nel!=0);rez1=pl2.cel;
if( (pl2.ptrtype!=ptrtree) && success1 ) next(&pl2);
loc10 .sa=rez1; 
if( !success1 ) goto _L107;

/* shablon prawila */ r29(&rez1,&success1,&pl2);
if( !success1 ) goto _L107;

if( pl2.nel !=0 )
{ success1=false;rez1=NULL;goto _L107;};
success1=true;rez1=pl1.cel;
 if( pl1.ptrtype!=ptrtree ) next(&pl1);
goto _L99;  _L107:;  /* metka wyhoda po neuspehu wetwi */
 _L99: rez1=NULL; 
 _L98: *rez=rez1;*success=success1; 
 if (*success) *pl=pl1; /* prodwinutx ukazatelx leksem */ 
/* wosstanowitx GLOB */ 
glob24_1=oldglob24_1;
glob24_2=oldglob24_2;
glob24_3=oldglob24_3;
#ifdef XX  
 d(2,"G_programma", 24 ,*rez,*success); 
#endif 
;};/* RULE */ 
/*===============================================*/ 
/* GENERATED TEXT OF RULE   #G_UNIT   */ 
 Void r29(rez,success,pl)
long *rez;boolean *success;ptr_ *pl; 
{  a rez1;  boolean success1; long k; mpd x; 
v loc1;/* $FN*/ 
v loc2;/* $imq*/ 
v loc3;/* $MAXWRK*/ 
v loc4;/* $CURRENT*/ 
v wrk1;
v wrk2;
ptr_ pl1;
ptr_ pl2;
ptr_ pl3;
boolean flag1;
#ifdef XX  
 d(1,"G_UNIT", 29 ,pl->cel,0); 
#endif 
/* sohranitx GLOB */ 

/* branch */ pl1=*pl;rez1=NULL;success1=true; 
/* inicializaciq peremennyh */ 
loc1.sa=NULL;/* $FN*/ 
loc2.sa=NULL;/* $imq*/ 

/* operator := */ 
wrk2 .sa=NULL; 
lconc(& wrk2 .sa , cnst[26] .sa ); 
indxop( 3L,false,NULL, glob1_5 .sa ,& wrk1 .sa); 
lconc(& wrk2 .sa , wrk1 .sa ); 
first(wrk2.sa,&pl2);implod(&pl2,&wrk2.sa); 
loc1 .sa= wrk2 .sa ;xxx; 

wrk1 .sa=NULL; 
lconc(& wrk1 .sa , loc1 .sa ); 
lconc(& wrk1 .sa , cnst[27] .sa ); 
first(wrk1.sa,&pl2);implod(&pl2,&wrk1.sa); 
opn(acnst[ 15 ], wrk1 .sa ) ;xxx; 

outatm(acnst[15],"#include \"globrig.h\"",true, true); ;xxx; 

outatm(acnst[15],"#include \"define.h\" ",true, true); ;xxx; 

outatm(acnst[15],"#include \"defpage.h\"",true, true); ;xxx; 

outatm(acnst[15],"#include \"nef2.h\"   ",true, true); ;xxx; 

outatm(acnst[15],"#include \"c1.h\"     ",true, true); ;xxx; 

outatm(acnst[15],"#include \"usemod.h\" ",true, true); ;xxx; 

outatm(acnst[15],"#include \"def180.h\" ",true, true); ;xxx; 

outatm(acnst[15],"#include \"xcrg.h\"   ",true, true); ;xxx; 

/*shablon STARLIST */ 
 pl2=pl1;while(pl1.nel!=0 ) { 

/* shablon treemain */ rez1=pl1.cel;
success1=false;if(pl1.nel==0 ) goto _L102; 
 if (rez1!=NULL ) { pointr(rez1,&x.sa); 
       if (x.smld->dtype!= treemain )  
        { rez1=NULL;goto _L102;};
/* prowerka imeni */ 
loc2 .sa=x.smld->name; 
;}; 
pl3.nel=1;pl3.ptrtype=ptrtree;
success1=true; 
selop(acnst[53],false,0L,pl1.cel,&rez1);pl3.cel=rez1;
   if( rez1==NULL ) { success1=false;goto _L101;};

/* shablon peremennoj */ 
success1=(pl3.nel!=0);rez1=pl3.cel;
if( (pl3.ptrtype!=ptrtree) && success1 ) next(&pl3);
loc3 .sa=rez1; 
if( !success1 ) goto _L101;
_L101:success1=true;
if( success1 ) {
 rez1=pl1.cel;if( pl1.ptrtype!=ptrtree ) next(&pl1) ;}
 else { rez1=NULL;goto _L102 ;};

outxt(acnst[ 15 ], cnst[28] .sa , true, false); 
selop( 0L,true, loc2 .sa, glob1_3 .sa ,& wrk1 .sa); 
outxt(acnst[ 15 ], wrk1 .sa , false, false); 
outatm(acnst[15]," ",false, false); ;xxx; 

/* CALL #L */ 
pl3.ptrtype=packedlist;pl3.nel=1;pl3.cel=loc2.sa;
pl3.plistsize= 1;
r31(&wrk1.sa,&flag1,&pl3);/* #Print_name*/ ;xxx; 

outatm(acnst[15]," */",false, true); ;xxx; 
 pl2=pl1;
;}; 
_L102:if( ! success1 )pl1=pl2;
success1 = true ; 

/* FAIL */ rez1=NULL;success1=false; 
if (pl1.ptrtype!=ptrtree) next(&pl1); /*wyhod iz der.ili sp.*/ 
goto _L103;xxx; 
goto _L99;  _L103:;  /* metka wyhoda po neuspehu wetwi */

/* branch */ pl1=*pl;rez1=NULL;success1=true; 
/* inicializaciq peremennyh */ 
loc4.sa=NULL;/* $CURRENT*/ 

/*shablon STARLIST */ 
 pl2=pl1;while(pl1.nel!=0 ) { 

/* operator +:= */ 
addnum(& loc4 .sa, 1L ) ;xxx; 

/* shablon prawila */ r3(&rez1,&success1,&pl1);
if( !success1 ) goto _L104;
 pl2=pl1;
;}; 
_L104:if( ! success1 )pl1=pl2;
success1 = true ; 

clsfil(acnst[ 15 ]) ;xxx; 
goto _L99;  _L105:;  /* metka wyhoda po neuspehu wetwi */
 _L99: rez1=NULL; 
 _L98: *rez=rez1;*success=success1; 
 if (*success) *pl=pl1; /* prodwinutx ukazatelx leksem */ 
/* wosstanowitx GLOB */ 
#ifdef XX  
 d(2,"G_UNIT", 29 ,*rez,*success); 
#endif 
;};/* RULE */ 
/*===============================================*/ 
/* GENERATED TEXT OF RULE   #G_telo_glawn   */ 
 Void r30(rez,success,pl)
long *rez;boolean *success;ptr_ *pl; 
{  a rez1;  boolean success1; long k; mpd x; 
v loc1;/* $total*/ 
v wrk1;
v wrk2;
v oldglob30_1;
ptr_ pl1;
ptr_ pl2;
ptr_ pl3;
boolean flag1;
#ifdef XX  
 d(1,"G_telo_glawn", 30 ,pl->cel,0); 
#endif 
/* sohranitx GLOB */ 
oldglob30_1=glob30_1;
glob30_1.sa=pl->cel;

/* branch */ pl1=*pl;rez1=NULL;success1=true; 
/* inicializaciq peremennyh */ 
loc1.sa=NULL;/* $total*/ 

/* operator := */ 
bltin(&wrk1,&flag1,glob30_1.sa,15L); 
mknumb( wrk1 .nu ,& wrk2 .sa); 
loc1 .sa= wrk2 .sa ;xxx; 

/* shablon listmain */ rez1=pl1.cel;
success1=false;if(pl1.nel==0 ) goto _L102; 
 if (rez1!=NULL ) { pointr(rez1,&x.sa); 
       if (x.smld->dtype!= listmain )  
        { rez1=NULL;goto _L102;};
{pl2.ptrtype=ptrlist; pl2.nel=1;
pl2.cel=x.smld->elt[0];pl2.UU.U1.curfragment=rez1;}
;} else  
{pl2.ptrtype=ptrlist;pl2.nel=0;pl2.cel=NULL;}

/*shablon STARLIST */ 
 pl3=pl2;while(pl2.nel!=0 ) { 

/* shablon prawila */ r63(&rez1,&success1,&pl2);
if( !success1 ) goto _L101;

/* operator +:= */ 
wrk1 .nu=- 1L ; 
addnum(& loc1 .sa, wrk1 .nu ) ;xxx; 
 pl3=pl2;
;}; 
_L101:if( ! success1 )pl2=pl3;
success1 = true ; 

if( pl2.nel !=0 )
{ success1=false;rez1=NULL;goto _L102;};
success1=true;rez1=pl1.cel;
 if( pl1.ptrtype!=ptrtree ) next(&pl1);
goto _L99;  _L102:;  /* metka wyhoda po neuspehu wetwi */
 _L99: rez1=NULL; 
 _L98: *rez=rez1;*success=success1; 
 if (*success) *pl=pl1; /* prodwinutx ukazatelx leksem */ 
/* wosstanowitx GLOB */ 
glob30_1=oldglob30_1;
#ifdef XX  
 d(2,"G_telo_glawn", 30 ,*rez,*success); 
#endif 
;};/* RULE */ 
/*===============================================*/ 
/* GENERATED TEXT OF RULE   #Print_name   */ 
 Void r31(rez,success,pl)
long *rez;boolean *success;ptr_ *pl; 
{  a rez1;  boolean success1; long k; mpd x; 
v loc1;/* $imq*/ 
v loc2;/* $EXPL*/ 
v loc3;/* $LETTER*/ 
v wrk1;
ptr_ pl1;
ptr_ pl2;
boolean flag1;
#ifdef XX  
 d(1,"Print_name", 31 ,pl->cel,0); 
#endif 
/* sohranitx GLOB */ 

/* branch */ pl1=*pl;rez1=NULL;success1=true; 
/* inicializaciq peremennyh */ 
loc1.sa=NULL;/* $imq*/ 
loc2.sa=NULL;/* $EXPL*/ 
loc3.sa=NULL;/* $LETTER*/ 

/* shablon peremennoj */ 
success1=(pl1.nel!=0);rez1=pl1.cel;
if( (pl1.ptrtype!=ptrtree) && success1 ) next(&pl1);
loc1 .sa=rez1; 
if( !success1 ) goto _L104;

/* operator := */ 
if( loc1 .sa ==NULL ) wrk1 .sa=NULL; else explod( loc1 .sa ,& wrk1 .sa) ; 
loc2 .sa= wrk1 .sa ;xxx; 

/*FORALL-op.*/ 
if( loc2.sa==NULL ) goto _L103;
pointr ( loc2 .sa ,&x.sa);  
if( (x.smld->dtype!=listmain)&&(x.smld->dtype!=treemain) 
  ) { er(24L);goto _L103;}; 
first(loc2.sa,&pl2);
while (pl2.nel!=0){
    if( pl2.ptrtype==ptrlist ) 
{loc3.sa=pl2.cel;} 
   else {
  mkatom(pl2.UU.U1.arc,idatom,&loc3.sa);
;}; 
/* IF-operator */ 
/* operaciq = */ wrk1 .bo= eqatom( loc3 .sa ,acnst[ 59 ]) ; 
if( wrk1 .bo) 
{ 
/* operator := */ 
loc3 .sa= cnst[29] .sa ;xxx; 
;} 
_L101:;xxx; 
/* IF-operator */ 
/* operaciq = */ wrk1 .bo= eqatom( loc3 .sa ,acnst[ 60 ]) ; 
if( wrk1 .bo) 
{ 
/* operator := */ 
loc3 .sa= cnst[30] .sa ;xxx; 
;} 
_L102:;xxx; 
outxt(acnst[ 15 ], loc3 .sa , false, false); ;xxx; 
next(&pl2) ;};_L103:/*END FORALL*/;xxx; 
goto _L99;  _L104:;  /* metka wyhoda po neuspehu wetwi */
 _L99: rez1=NULL; 
 _L98: *rez=rez1;*success=success1; 
 if (*success) *pl=pl1; /* prodwinutx ukazatelx leksem */ 
/* wosstanowitx GLOB */ 
#ifdef XX  
 d(2,"Print_name", 31 ,*rez,*success); 
#endif 
;};/* RULE */ 
/*===============================================*/ 
/* GENERATED TEXT OF RULE   #G_prawilo   */ 
 Void r3(rez,success,pl)
long *rez;boolean *success;ptr_ *pl; 
{  a rez1;  boolean success1; long k; mpd x; 
v loc2;/* $MAXWRK*/ 
v loc3;/* $MAXLABEL*/ 
v loc4;/* $MAX_FLAG*/ 
v loc5;/* $MAXPL*/ 
v loc6;/* $NUM*/ 
v loc7;/* $FN*/ 
v loc8;/* $X*/ 
v loc10;/* $E*/ 
v wrk1;
v wrk2;
v oldglob3_1;
v oldglob3_2;
v oldglob3_3;
ptr_ pl1;
ptr_ pl2;
ptr_ pl3;
ptr_ pl4;
ptr_ pl5;
ptr_ pl6;
ptr_ pl7;
boolean flag1;
#ifdef XX  
 d(1,"G_prawilo", 3 ,pl->cel,0); 
#endif 
/* sohranitx GLOB */ 
oldglob3_1=glob3_1;
oldglob3_2=glob3_2;
oldglob3_3=glob3_3;
glob3_1.sa=pl->cel;

/* branch */ pl1=*pl;rez1=NULL;success1=true; 
/* inicializaciq peremennyh */ 
glob3_2.sa=NULL;
loc2.sa=NULL;/* $MAXWRK*/ 
loc3.sa=NULL;/* $MAXLABEL*/ 
loc4.sa=NULL;/* $MAX_FLAG*/ 
loc5.sa=NULL;/* $MAXPL*/ 
loc6.sa=NULL;/* $NUM*/ 
loc7.sa=NULL;/* $FN*/ 
loc8.sa=NULL;/* $X*/ 
glob3_3.sa=NULL;
loc10.sa=NULL;/* $E*/ 

/* shablon treemain */ rez1=pl1.cel;
success1=false;if(pl1.nel==0 ) goto _L108; 
 if (rez1!=NULL ) { pointr(rez1,&x.sa); 
       if (x.smld->dtype!= treemain )  
        { rez1=NULL;goto _L108;};
/* prowerka imeni */ 
glob3_2 .sa=x.smld->name; 
;}; 
pl2.nel=1;pl2.ptrtype=ptrtree;
success1=true; 
selop(acnst[53],false,0L,pl1.cel,&rez1);pl2.cel=rez1;
   if( rez1==NULL ) { success1=false;goto _L108;};

/* shablon peremennoj */ 
success1=(pl2.nel!=0);rez1=pl2.cel;
if( (pl2.ptrtype!=ptrtree) && success1 ) next(&pl2);
loc2 .sa=rez1; 
if( !success1 ) goto _L108;
selop(acnst[56],false,0L,pl1.cel,&rez1);pl2.cel=rez1;
   if( rez1==NULL ) { success1=false;goto _L108;};

/* shablon peremennoj */ 
success1=(pl2.nel!=0);rez1=pl2.cel;
if( (pl2.ptrtype!=ptrtree) && success1 ) next(&pl2);
loc3 .sa=rez1; 
if( !success1 ) goto _L108;
selop(acnst[55],false,0L,pl1.cel,&rez1);pl2.cel=rez1;
   if( rez1==NULL ) { success1=false;goto _L108;};

/* shablon peremennoj */ 
success1=(pl2.nel!=0);rez1=pl2.cel;
if( (pl2.ptrtype!=ptrtree) && success1 ) next(&pl2);
loc4 .sa=rez1; 
if( !success1 ) goto _L108;
selop(acnst[54],false,0L,pl1.cel,&rez1);pl2.cel=rez1;
   if( rez1==NULL ) { success1=false;goto _L108;};

/* shablon peremennoj */ 
success1=(pl2.nel!=0);rez1=pl2.cel;
if( (pl2.ptrtype!=ptrtree) && success1 ) next(&pl2);
loc5 .sa=rez1; 
if( !success1 ) goto _L108;

/* operator := */ 
selop( 0L,true, glob3_2 .sa, glob1_3 .sa ,& wrk1 .sa); 
loc6 .sa= wrk1 .sa ;xxx; 

/* operator := */ 
wrk1 .sa=NULL; 
lconc(& wrk1 .sa , cnst[26] .sa ); 
lconc(& wrk1 .sa , loc6 .sa ); 
first(wrk1.sa,&pl3);implod(&pl3,&wrk1.sa); 
loc7 .sa= wrk1 .sa ;xxx; 

/* operator := */ 
glob24_2 .sa= glob3_2 .sa ;xxx; 

outatm(acnst[15],"/*===============================================*/",true, 
true); ;xxx; 

outatm(acnst[15],"/* GENERATED TEXT OF RULE   #",true, false); ;xxx; 

/* CALL #L */ 
pl3.ptrtype=packedlist;pl3.nel=1;pl3.cel=glob3_2.sa;
pl3.plistsize= 1;
r31(&wrk1.sa,&flag1,&pl3);/* #Print_name*/ ;xxx; 

outatm(acnst[15],"   */",false, true); ;xxx; 

outatm(acnst[15]," Void r",true, false); 
outxt(acnst[ 15 ], loc6 .sa , false, false); 
outatm(acnst[15],"(rez,success,pl)",false, false); ;xxx; 

outatm(acnst[15],"long *rez;boolean *success;ptr_ *pl;",true, true); ;xxx; 

outatm(acnst[15],"{  a rez1;  boolean success1; long k; mpd x;",true, true); 
;xxx; 

/* CALL #L */ 
pl3.ptrtype=packedlist;pl3.nel=1;pl3.cel=glob3_2.sa;
pl3.plistsize= 1;
r2(&wrk1.sa,&flag1,&pl3);/* #G_LOC_dekl*/ ;xxx; 

/* CALL #L */ 
pl3.ptrtype=packedlist;pl3.nel=1;pl3.cel=loc2.sa;
pl3.plistsize= 1;
r4(&wrk1.sa,&flag1,&pl3);/* #G_WRK_dekl*/ ;xxx; 

/* CALL #L */ 
pl3.ptrtype=packedlist;pl3.nel=1;pl3.cel=glob3_2.sa;
pl3.plistsize= 1;
r7(&wrk1.sa,&flag1,&pl3);/* #G_OLDGLOB_dekl*/ ;xxx; 

/* CALL #L */ 
pl3.ptrtype=packedlist;pl3.nel=1;pl3.cel=loc5.sa;
pl3.plistsize= 1;
r5(&wrk1.sa,&flag1,&pl3);/* #G_PL_dekl*/ ;xxx; 

/* CALL #L */ 
pl3.ptrtype=packedlist;pl3.nel=1;pl3.cel=loc4.sa;
pl3.plistsize= 1;
r6(&wrk1.sa,&flag1,&pl3);/* #G_FLAG_dekl*/ ;xxx; 

/* CALL #L */ 
pl3.ptrtype=packedlist;pl3.nel=1;pl3.cel=loc3.sa;
pl3.plistsize= 1;
r12(&wrk1.sa,&flag1,&pl3);/* #G_LABELS*/ ;xxx; 

outatm(acnst[15],"#ifdef XX ",true, true); ;xxx; 

outatm(acnst[15]," d(1,\"",true, false); ;xxx; 

/* CALL #L */ 
pl3.ptrtype=packedlist;pl3.nel=1;pl3.cel=glob3_2.sa;
pl3.plistsize= 1;
r31(&wrk1.sa,&flag1,&pl3);/* #Print_name*/ ;xxx; 

outatm(acnst[15],"\",",false, true); 
outxt(acnst[ 15 ], loc6 .sa , false, true); 
outatm(acnst[15],",pl->cel,0);",false, true); ;xxx; 

outatm(acnst[15],"#endif",true, true); ;xxx; 

/* CALL #L */ 
pl3.ptrtype=packedlist;pl3.nel=1;pl3.cel=glob3_2.sa;
pl3.UU.plistelt[ 0 ]=cnst[31].sa;
pl3.plistsize= 2;
r8(&wrk1.sa,&flag1,&pl3);/* #G_sohranitx_GLOB*/ ;xxx; 

/* operator := */ 
selop( 0L,true, glob3_2 .sa, glob1_2 .sa ,& wrk1 .sa); 
selop( acnst[ 13 ],false,NULL, wrk1 .sa ,& wrk2 .sa); 
loc8 .sa= wrk2 .sa ;xxx; 

/* IF-operator */ 
if( loc8 .sa!=NULL) 
{ 
outatm(acnst[15],"glob",true, false); 
outxt(acnst[ 15 ], loc6 .sa , false, false); 
outatm(acnst[15],"_",false, false); 
outxt(acnst[ 15 ], loc8 .sa , false, false); 
outatm(acnst[15],".sa=pl->cel;",false, false); ;xxx; 
goto _L101;
;} 
selop( acnst[ 14 ],false,NULL, glob3_1 .sa ,& wrk1 .sa); 
if( wrk1 .sa!=NULL) 
{ 
outatm(acnst[15],"loc0.sa=pl->cel;",true, true); ;xxx; 
;} 
_L101:;xxx; 

/* operator := */ 
mknumb( 1L,& wrk1 .sa); 
glob3_3 .sa= wrk1 .sa ;xxx; 
selop(acnst[39],false,0L,pl1.cel,&rez1);pl2.cel=rez1;
   if( rez1==NULL ) { success1=false;goto _L108;};

/* shablon listmain */ rez1=pl2.cel;
success1=false;if(pl2.nel==0 ) goto _L108; 
 if (rez1!=NULL ) { pointr(rez1,&x.sa); 
       if (x.smld->dtype!= listmain )  
        { rez1=NULL;goto _L108;};
{pl3.ptrtype=ptrlist; pl3.nel=1;
pl3.cel=x.smld->elt[0];pl3.UU.U1.curfragment=rez1;}
;} else  
{pl3.ptrtype=ptrlist;pl3.nel=0;pl3.cel=NULL;}

/*shablon STARLIST */ 
 pl4=pl3;while(pl3.nel!=0 ) { 

/* Alternative pattern */ 
pl5=pl3;
/* nonatomic alternative branches */ 

/* shablon prawila */ r10(&rez1,&success1,&pl3);
if( !success1 ) goto _L102;
goto _L106/*uspeh*/;
_L102:; 
pl3=pl5;

/* Alternative pattern */ 
pl6=pl3;

/* shablon treemain */ rez1=pl3.cel;
success1=false;if(pl3.nel==0 ) goto _L103; 
 if (rez1!=NULL ) { pointr(rez1,&x.sa); 
       if (x.smld->dtype!= treemain )  
        { rez1=NULL;goto _L103;};
;}; 
pl7.nel=1;pl7.ptrtype=ptrtree;
success1=true; 
selop(acnst[38],false,0L,pl3.cel,&rez1);pl7.cel=rez1;
   if( rez1==NULL ) { success1=false;goto _L103;};

/* shablon peremennoj */ 
success1=(pl7.nel!=0);rez1=pl7.cel;
if( (pl7.ptrtype!=ptrtree) && success1 ) next(&pl7);
loc10 .sa=rez1; 
if( !success1 ) goto _L103;
if( success1 ) {
 rez1=pl3.cel;if( pl3.ptrtype!=ptrtree ) next(&pl3) ;}
 else { rez1=NULL;goto _L103 ;};

outatm(acnst[15],"_L",true, false); 
outxt(acnst[ 15 ], loc10 .sa , false, false); 
outatm(acnst[15],":;",false, false); ;xxx; 
goto _L104/*uspeh*/;
_L103:; 
pl3=pl6;
goto  _L105;
_L104:;/*uspeh alxtern.*/
goto _L106/*uspeh*/;
_L105:; 
pl3=pl5;
goto  _L107;
_L106:;/*uspeh alxtern.*/
 pl4=pl3;
;}; 
_L107:if( ! success1 )pl3=pl4;
success1 = true ; 

if( pl3.nel !=0 )
{ success1=false;rez1=NULL;goto _L108;};
success1=true;rez1=pl2.cel;
 if( pl2.ptrtype!=ptrtree ) next(&pl2);
if( success1 ) {
 rez1=pl1.cel;if( pl1.ptrtype!=ptrtree ) next(&pl1) ;}
 else { rez1=NULL;goto _L108 ;};

/* CALL #L */ 
pl2.ptrtype=ptrlist;pl2.nel=0;pl2.cel=NULL;
r54(&wrk1.sa,&flag1,&pl2);/* #ss6*/ ;xxx; 

/* CALL #L */ 
pl2.ptrtype=packedlist;pl2.nel=1;pl2.cel=glob3_2.sa;
pl2.UU.plistelt[ 0 ]=NULL;
pl2.plistsize= 2;
r8(&wrk1.sa,&flag1,&pl2);/* #G_sohranitx_GLOB*/ ;xxx; 

outatm(acnst[15],"#ifdef XX ",true, true); ;xxx; 

outatm(acnst[15]," d(2,\"",true, false); ;xxx; 

/* CALL #L */ 
pl2.ptrtype=packedlist;pl2.nel=1;pl2.cel=glob3_2.sa;
pl2.plistsize= 1;
r31(&wrk1.sa,&flag1,&pl2);/* #Print_name*/ ;xxx; 

outatm(acnst[15],"\",",false, true); 
outxt(acnst[ 15 ], loc6 .sa , false, true); 
outatm(acnst[15],",*rez,*success);",false, true); ;xxx; 

outatm(acnst[15],"#endif",true, true); ;xxx; 

outatm(acnst[15],";};/* RULE */",true, true); ;xxx; 
goto _L99;  _L108:;  /* metka wyhoda po neuspehu wetwi */
 _L99: rez1=NULL; 
 _L98: *rez=rez1;*success=success1; 
 if (*success) *pl=pl1; /* prodwinutx ukazatelx leksem */ 
/* wosstanowitx GLOB */ 
glob3_1=oldglob3_1;
glob3_2=oldglob3_2;
glob3_3=oldglob3_3;
#ifdef XX  
 d(2,"G_prawilo", 3 ,*rez,*success); 
#endif 
;};/* RULE */ 
/*===============================================*/ 
/* GENERATED TEXT OF RULE   #G_SIMPLE   */ 
 Void r10(rez,success,pl)
long *rez;boolean *success;ptr_ *pl; 
{  a rez1;  boolean success1; long k; mpd x; 
v wrk1;
v oldglob10_1;
v oldglob10_2;
v oldglob10_3;
v oldglob10_4;
ptr_ pl1;
ptr_ pl2;
ptr_ pl3;
ptr_ pl4;
ptr_ pl5;
boolean flag1;
#ifdef XX  
 d(1,"G_SIMPLE", 10 ,pl->cel,0); 
#endif 
/* sohranitx GLOB */ 
oldglob10_1=glob10_1;
oldglob10_2=glob10_2;
oldglob10_3=glob10_3;
oldglob10_4=glob10_4;
glob10_1.sa=pl->cel;

/* branch */ pl1=*pl;rez1=NULL;success1=true; 
/* inicializaciq peremennyh */ 
glob10_2.sa=NULL;
glob10_4.sa=NULL;
glob10_3.sa=NULL;

/* CALL #L */ 
pl2.ptrtype=ptrlist;pl2.nel=0;pl2.cel=NULL;
r55(&wrk1.sa,&flag1,&pl2);/* #ss7*/ ;xxx; 

/* CALL #L */ 
pl2.ptrtype=packedlist;pl2.nel=1;pl2.cel=glob3_2.sa;
pl2.plistsize= 1;
r9(&wrk1.sa,&flag1,&pl2);/* #G_INIT_VARS*/ ;xxx; 

/* shablon treemain */ rez1=pl1.cel;
success1=false;if(pl1.nel==0 ) goto _L107; 
 if (rez1!=NULL ) { pointr(rez1,&x.sa); 
       if (x.smld->dtype!= treemain )  
        { rez1=NULL;goto _L107;};
;}; 
pl2.nel=1;pl2.ptrtype=ptrtree;
success1=true; 
selop(acnst[38],false,0L,pl1.cel,&rez1);pl2.cel=rez1;
   if( rez1==NULL ) { success1=false;goto _L107;};

/* shablon peremennoj */ 
success1=(pl2.nel!=0);rez1=pl2.cel;
if( (pl2.ptrtype!=ptrtree) && success1 ) next(&pl2);
glob10_2 .sa=rez1; 
if( !success1 ) goto _L107;

/* operator := */ 
glob10_4 .sa= glob10_2 .sa ;xxx; 
selop(acnst[39],false,0L,pl1.cel,&rez1);pl2.cel=rez1;
   if( rez1==NULL ) { success1=false;goto _L107;};

/* operator := */ 
mknumb( 0L,& wrk1 .sa); 
glob10_3 .sa= wrk1 .sa ;xxx; 

/* shablon listmain */ rez1=pl2.cel;
success1=false;if(pl2.nel==0 ) goto _L107; 
 if (rez1!=NULL ) { pointr(rez1,&x.sa); 
       if (x.smld->dtype!= listmain )  
        { rez1=NULL;goto _L107;};
{pl3.ptrtype=ptrlist; pl3.nel=1;
pl3.cel=x.smld->elt[0];pl3.UU.U1.curfragment=rez1;}
;} else  
{pl3.ptrtype=ptrlist;pl3.nel=0;pl3.cel=NULL;}

/*shablon STARLIST */ 
 pl4=pl3;while(pl3.nel!=0 ) { 

/* Alternative pattern */ 
pl5=pl3;
/* nonatomic alternative branches */ 

/* shablon prawila */ r69(&rez1,&success1,&pl3);
if( !success1 ) goto _L101;
goto _L103/*uspeh*/;
_L101:; 
pl3=pl5;

/* shablon prawila */ r63(&rez1,&success1,&pl3);
if( !success1 ) goto _L102;
goto _L103/*uspeh*/;
_L102:; 
pl3=pl5;
goto  _L104;
_L103:;/*uspeh alxtern.*/
 pl4=pl3;
;}; 
_L104:if( ! success1 )pl3=pl4;
success1 = true ; 

outatm(acnst[15],"goto _L99;  _L",true, false); 
outxt(acnst[ 15 ], glob10_2 .sa , false, false); 
outatm(acnst[15],":;",false, false); 
outatm(acnst[15],"  /* metka wyhoda po neuspehu wetwi */",false, false); ;xxx; 

if( pl3.nel !=0 )
{ success1=false;rez1=NULL;goto _L107;};
success1=true;rez1=pl2.cel;
 if( pl2.ptrtype!=ptrtree ) next(&pl2);
selop(acnst[61],false,0L,pl1.cel,&rez1);pl2.cel=rez1;
   if( rez1==NULL ) { success1=false;goto _L105;};

outatm(acnst[15],"/* ONFAIL-dejstwiq */",true, true); ;xxx; 

/* shablon listmain */ rez1=pl2.cel;
success1=false;if(pl2.nel==0 ) goto _L105; 
 if (rez1!=NULL ) { pointr(rez1,&x.sa); 
       if (x.smld->dtype!= listmain )  
        { rez1=NULL;goto _L105;};
{pl3.ptrtype=ptrlist; pl3.nel=1;
pl3.cel=x.smld->elt[0];pl3.UU.U1.curfragment=rez1;}
;} else  
{pl3.ptrtype=ptrlist;pl3.nel=0;pl3.cel=NULL;}

/*shablon STARLIST */ 
 pl4=pl3;while(pl3.nel!=0 ) { 

/* shablon prawila */ r63(&rez1,&success1,&pl3);
if( !success1 ) goto _L106;
 pl4=pl3;
;}; 
_L106:if( ! success1 )pl3=pl4;
success1 = true ; 

if( pl3.nel !=0 )
{ success1=false;rez1=NULL;goto _L105;};
success1=true;rez1=pl2.cel;
 if( pl2.ptrtype!=ptrtree ) next(&pl2);
_L105:success1=true;
if( success1 ) {
 rez1=pl1.cel;if( pl1.ptrtype!=ptrtree ) next(&pl1) ;}
 else { rez1=NULL;goto _L107 ;};
goto _L99;  _L107:;  /* metka wyhoda po neuspehu wetwi */
 _L99: rez1=NULL; 
 _L98: *rez=rez1;*success=success1; 
 if (*success) *pl=pl1; /* prodwinutx ukazatelx leksem */ 
/* wosstanowitx GLOB */ 
glob10_1=oldglob10_1;
glob10_2=oldglob10_2;
glob10_3=oldglob10_3;
glob10_4=oldglob10_4;
#ifdef XX  
 d(2,"G_SIMPLE", 10 ,*rez,*success); 
#endif 
;};/* RULE */ 
