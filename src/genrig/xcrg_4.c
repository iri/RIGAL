
#include "globrig.h" 
#include "define.h"  
#include "defpage.h" 
#include "nef2.h"    
#include "c1.h"      
#include "usemod.h"  
#include "def180.h"  
#include "xcrg.h"    
/*  R32 QQQ */ 
/*  R33 G_ASSGN */ 
/*  R34 G_ANORM */ 
/*  R35 G_ALONGLIST */ 
/*  R36 G_ALONGTREE */ 
/*  R37 obqzatelxno_obxekt */ 
/*  R38 obxekt_ili_NULL */ 
/*  R39 INTEGER_ili_obxekt */ 
/*  R40 ACONST_ili_obxekt */ 
/*===============================================*/ 
/* GENERATED TEXT OF RULE   #QQQ   */ 
 Void r32(rez,success,pl)
long *rez;boolean *success;ptr_ *pl; 
{  a rez1;  boolean success1; long k; mpd x; 
v loc1;/* $S*/ 
ptr_ pl1;
#ifdef XX  
 d(1,"QQQ", 32 ,pl->cel,0); 
#endif 
/* sohranitx GLOB */ 

/* branch */ pl1=*pl;rez1=NULL;success1=true; 
/* inicializaciq peremennyh */ 

loc1 .sa=NULL; 

/* shablon atoma */ atmpat(acnst[62],&pl1,&rez1,&success1);
if( !success1 ) goto _L101;
loc1 .sa=rez1; 
goto _L99;  _L101:;  /* metka wyhoda po neuspehu wetwi */
 _L99: rez1=NULL; 
 _L98: *rez=rez1;*success=success1; 
 if (*success) *pl=pl1; /* prodwinutx ukazatelx leksem */ 
/* wosstanowitx GLOB */ 
#ifdef XX  
 d(2,"QQQ", 32 ,*rez,*success); 
#endif 
;};/* RULE */ 
/*===============================================*/ 
/* GENERATED TEXT OF RULE   #G_ASSGN   */ 
 Void r33(rez,success,pl)
long *rez;boolean *success;ptr_ *pl; 
{  a rez1;  boolean success1; long k; mpd x; 
v loc1;/* $R*/ 
v loc2;/* $OP*/ 
v wrk1;
v wrk2;
ptr_ pl1;
ptr_ pl2;
boolean flag1;
#ifdef XX  
 d(1,"G_ASSGN", 33 ,pl->cel,0); 
#endif 
/* sohranitx GLOB */ 

/* branch */ pl1=*pl;rez1=NULL;success1=true; 
/* inicializaciq peremennyh */ 
loc1.sa=NULL;/* $R*/ 
loc2.sa=NULL;/* $OP*/ 

loc1 .sa=NULL; 

/* shablon treemain */ rez1=pl1.cel;
success1=false;if(pl1.nel==0 ) goto _L102; 
 if (rez1!=NULL ) { pointr(rez1,&x.sa); 
       if (x.smld->dtype!= treemain )  
        { rez1=NULL;goto _L102;};
/* prowerka imeni */ 
success1=eqatom(x.smld->name,acnst[ 63 ]); 
if( ! success1 ) { rez1=NULL;goto _L102;};
;}; 
pl2.nel=1;pl2.ptrtype=ptrtree;
success1=true; 
selop(acnst[64],false,0L,pl1.cel,&rez1);pl2.cel=rez1;
   if( rez1==NULL ) { success1=false;goto _L102;};

/* shablon peremennoj */ 
success1=(pl2.nel!=0);rez1=pl2.cel;
if( (pl2.ptrtype!=ptrtree) && success1 ) next(&pl2);
loc2 .sa=rez1; 
if( !success1 ) goto _L102;
if( success1 ) {
 rez1=pl1.cel;if( pl1.ptrtype!=ptrtree ) next(&pl1) ;}
 else { rez1=NULL;goto _L102 ;};
loc1 .sa=rez1; 

/* IF-operator */ 
/* operaciq = */ wrk1 .bo= eqatom( loc2 .sa ,acnst[ 65 ]) ; 
if( wrk1 .bo) 
{ 
/* CALL #L */ 
pl2.ptrtype=packedlist;pl2.nel=1;pl2.cel=loc1.sa;
pl2.plistsize= 1;
r35(&wrk1.sa,&flag1,&pl2);/* #G_ALONGLIST*/ ;xxx; 
goto _L101;
;} 
/* operaciq = */ wrk2 .bo= eqatom( loc2 .sa ,acnst[ 66 ]) ; 
if( wrk2 .bo) 
{ 
/* CALL #L */ 
pl2.ptrtype=packedlist;pl2.nel=1;pl2.cel=loc1.sa;
pl2.plistsize= 1;
r36(&wrk1.sa,&flag1,&pl2);/* #G_ALONGTREE*/ ;xxx; 
goto _L101;
;} 
{ 
/* CALL #L */ 
pl2.ptrtype=packedlist;pl2.nel=1;pl2.cel=loc1.sa;
pl2.plistsize= 1;
r34(&wrk1.sa,&flag1,&pl2);/* #G_ANORM*/ ;xxx; 
;} 
_L101:;xxx; 
goto _L99;  _L102:;  /* metka wyhoda po neuspehu wetwi */
 _L99: rez1=NULL; 
 _L98: *rez=rez1;*success=success1; 
 if (*success) *pl=pl1; /* prodwinutx ukazatelx leksem */ 
/* wosstanowitx GLOB */ 
#ifdef XX  
 d(2,"G_ASSGN", 33 ,*rez,*success); 
#endif 
;};/* RULE */ 
/*===============================================*/ 
/* GENERATED TEXT OF RULE   #G_ANORM   */ 
 Void r34(rez,success,pl)
long *rez;boolean *success;ptr_ *pl; 
{  a rez1;  boolean success1; long k; mpd x; 
v loc0;/* $_*/ 
v loc1;/* $A1*/ 
v loc2;/* $A2*/ 
v loc3;/* $E*/ 
v loc4;/* $E1*/ 
v loc5;/* $W*/ 
v loc6;/* $A3*/ 
v wrk1;
v wrk2;
ptr_ pl1;
ptr_ pl2;
ptr_ pl3;
ptr_ pl4;
ptr_ pl5;
ptr_ pl6;
ptr_ pl7;
ptr_ pl8;
ptr_ pl9;
ptr_ pl10;
ptr_ pl11;
ptr_ pl12;
ptr_ pl13;
ptr_ pl14;
ptr_ pl15;
boolean flag1;
#ifdef XX  
 d(1,"G_ANORM", 34 ,pl->cel,0); 
#endif 
/* sohranitx GLOB */ 
loc0.sa=pl->cel; 

/* branch */ pl1=*pl;rez1=NULL;success1=true; 
/* inicializaciq peremennyh */ 
loc1.sa=NULL;/* $A1*/ 
loc2.sa=NULL;/* $A2*/ 
loc3.sa=NULL;/* $E*/ 
loc4.sa=NULL;/* $E1*/ 

/* shablon treemain */ rez1=pl1.cel;
success1=false;if(pl1.nel==0 ) goto _L111; 
 if (rez1!=NULL ) { pointr(rez1,&x.sa); 
       if (x.smld->dtype!= treemain )  
        { rez1=NULL;goto _L111;};
/* prowerka imeni */ 
success1=eqatom(x.smld->name,acnst[ 63 ]); 
if( ! success1 ) { rez1=NULL;goto _L111;};
;}; 
pl2.nel=1;pl2.ptrtype=ptrtree;
success1=true; 
selop(acnst[64],false,0L,pl1.cel,&rez1);pl2.cel=rez1;
   if( rez1==NULL ) { success1=false;goto _L111;};

/* shablon atoma */ atmpat(acnst[67],&pl2,&rez1,&success1);
if( !success1 ) goto _L111;

outatm(acnst[15],"/* operator := */",true, true); ;xxx; 
selop(acnst[68],false,0L,pl1.cel,&rez1);pl2.cel=rez1;
   if( rez1==NULL ) { success1=false;goto _L111;};

/* Alternative pattern */ 
pl3=pl2;
/* nonatomic alternative branches */ 

/* Alternative pattern */ 
pl4=pl2;

/* shablon treemain */ rez1=pl2.cel;
success1=false;if(pl2.nel==0 ) goto _L101; 
 if (rez1!=NULL ) { pointr(rez1,&x.sa); 
       if (x.smld->dtype!= treemain )  
        { rez1=NULL;goto _L101;};
/* prowerka imeni */ 
success1=eqatom(x.smld->name,acnst[ 69 ]); 
if( ! success1 ) { rez1=NULL;goto _L101;};
;}; 
pl5.nel=1;pl5.ptrtype=ptrtree;
success1=true; 
selop(acnst[70],false,0L,pl2.cel,&rez1);pl5.cel=rez1;
   if( rez1==NULL ) { success1=false;goto _L101;};

loc1 .sa=NULL; 

/* shablon prawila */ r38(&rez1,&success1,&pl5);
if( !success1 ) goto _L101;
loc1 .sa=rez1; 
selop(acnst[71],false,0L,pl2.cel,&rez1);pl5.cel=rez1;
   if( rez1==NULL ) { success1=false;goto _L101;};

loc2 .sa=NULL; 

/* shablon prawila */ r39(&rez1,&success1,&pl5);
if( !success1 ) goto _L101;
loc2 .sa=rez1; 
if( success1 ) {
 rez1=pl2.cel;if( pl2.ptrtype!=ptrtree ) next(&pl2) ;}
 else { rez1=NULL;goto _L101 ;};

/* operator := */ 
/* CALL #L */ 
selop( acnst[ 72 ],false,NULL, loc0 .sa ,& wrk1 .sa); 
pl5.ptrtype=packedlist;pl5.nel=1;pl5.cel=wrk1.sa;
pl5.plistsize= 1;
r37(&wrk2.sa,&flag1,&pl5);/* #obqzatelxno_obxekt*/ ; 
loc3 .sa= wrk2 .sa ;xxx; 

outatm(acnst[15],"setind(",true, true); 
outxt(acnst[ 15 ], loc2 .sa , false, true); 
outxt(acnst[ 15 ], loc1 .sa , false, true); 
outatm(acnst[15],",",false, true); 
outxt(acnst[ 15 ], loc3 .sa , false, true); 
outatm(acnst[15],")",false, true); ;xxx; 
goto _L102/*uspeh*/;
_L101:; 
pl2=pl4;
goto  _L103;
_L102:;/*uspeh alxtern.*/
goto _L110/*uspeh*/;
_L103:; 
pl2=pl3;

/* Alternative pattern */ 
pl5=pl2;

/* shablon treemain */ rez1=pl2.cel;
success1=false;if(pl2.nel==0 ) goto _L104; 
 if (rez1!=NULL ) { pointr(rez1,&x.sa); 
       if (x.smld->dtype!= treemain )  
        { rez1=NULL;goto _L104;};
/* prowerka imeni */ 
success1=eqatom(x.smld->name,acnst[ 73 ]); 
if( ! success1 ) { rez1=NULL;goto _L104;};
;}; 
pl6.nel=1;pl6.ptrtype=ptrtree;
success1=true; 
selop(acnst[70],false,0L,pl2.cel,&rez1);pl6.cel=rez1;
   if( rez1==NULL ) { success1=false;goto _L104;};

loc1 .sa=NULL; 

/* shablon prawila */ r38(&rez1,&success1,&pl6);
if( !success1 ) goto _L104;
loc1 .sa=rez1; 
selop(acnst[71],false,0L,pl2.cel,&rez1);pl6.cel=rez1;
   if( rez1==NULL ) { success1=false;goto _L104;};

loc2 .sa=NULL; 

/* shablon prawila */ r40(&rez1,&success1,&pl6);
if( !success1 ) goto _L104;
loc2 .sa=rez1; 
if( success1 ) {
 rez1=pl2.cel;if( pl2.ptrtype!=ptrtree ) next(&pl2) ;}
 else { rez1=NULL;goto _L104 ;};

/* operator := */ 
/* CALL #L */ 
selop( acnst[ 72 ],false,NULL, loc0 .sa ,& wrk1 .sa); 
pl6.ptrtype=packedlist;pl6.nel=1;pl6.cel=wrk1.sa;
pl6.plistsize= 1;
r37(&wrk2.sa,&flag1,&pl6);/* #obqzatelxno_obxekt*/ ; 
loc3 .sa= wrk2 .sa ;xxx; 

outatm(acnst[15],"setsel(",true, true); 
outxt(acnst[ 15 ], loc2 .sa , false, true); 
outxt(acnst[ 15 ], loc1 .sa , false, true); 
outatm(acnst[15],",",false, true); 
outxt(acnst[ 15 ], loc3 .sa , false, true); 
outatm(acnst[15],")",false, true); ;xxx; 
goto _L105/*uspeh*/;
_L104:; 
pl2=pl5;
goto  _L106;
_L105:;/*uspeh alxtern.*/
goto _L110/*uspeh*/;
_L106:; 
pl2=pl3;

/* Alternative pattern */ 
pl6=pl2;

/* shablon peremennoj */ 
success1=(pl2.nel!=0);rez1=pl2.cel;
if( (pl2.ptrtype!=ptrtree) && success1 ) next(&pl2);
loc4 .sa=rez1; 
if( !success1 ) goto _L107;

/* CALL #L */ 
pl7.ptrtype=packedlist;pl7.nel=1;pl7.cel=loc4.sa;
pl7.plistsize= 1;
r41(&wrk1.sa,&flag1,&pl7);/* #G_wyravenie*/ ;xxx; 

/* operator := */ 
selop( acnst[ 72 ],false,NULL, loc0 .sa ,& wrk1 .sa); 
loc3 .sa= wrk1 .sa ;xxx; 

/* operator := */ 
/* CALL #L */ 
pl7.ptrtype=packedlist;pl7.nel=1;pl7.cel=loc3.sa;
pl7.plistsize= 1;
r37(&wrk1.sa,&flag1,&pl7);/* #obqzatelxno_obxekt*/ ; 
loc3 .sa= wrk1 .sa ;xxx; 

selop( acnst[ 19 ],false,NULL, loc4 .sa ,& wrk1 .sa); 
outxt(acnst[ 15 ], wrk1 .sa , true, true); 
outatm(acnst[15],".sa=",false, true); 
outxt(acnst[ 15 ], loc3 .sa , false, true); ;xxx; 
goto _L108/*uspeh*/;
_L107:; 
pl2=pl6;
goto  _L109;
_L108:;/*uspeh alxtern.*/
goto _L110/*uspeh*/;
_L109:; 
pl2=pl3;
goto  _L111;
_L110:;/*uspeh alxtern.*/
if( success1 ) {
 rez1=pl1.cel;if( pl1.ptrtype!=ptrtree ) next(&pl1) ;}
 else { rez1=NULL;goto _L111 ;};
goto _L99;  _L111:;  /* metka wyhoda po neuspehu wetwi */

/* branch */ pl1=*pl;rez1=NULL;success1=true; 
/* inicializaciq peremennyh */ 
loc1.sa=NULL;/* $A1*/ 
loc2.sa=NULL;/* $A2*/ 
loc3.sa=NULL;/* $E*/ 
loc4.sa=NULL;/* $E1*/ 
loc5.sa=NULL;/* $W*/ 

/* shablon treemain */ rez1=pl1.cel;
success1=false;if(pl1.nel==0 ) goto _L122; 
 if (rez1!=NULL ) { pointr(rez1,&x.sa); 
       if (x.smld->dtype!= treemain )  
        { rez1=NULL;goto _L122;};
/* prowerka imeni */ 
success1=eqatom(x.smld->name,acnst[ 63 ]); 
if( ! success1 ) { rez1=NULL;goto _L122;};
;}; 
pl6.nel=1;pl6.ptrtype=ptrtree;
success1=true; 
selop(acnst[64],false,0L,pl1.cel,&rez1);pl6.cel=rez1;
   if( rez1==NULL ) { success1=false;goto _L122;};

/* shablon atoma */ atmpat(acnst[74],&pl6,&rez1,&success1);
if( !success1 ) goto _L122;

outatm(acnst[15],"/* operator !.:= */",true, true); ;xxx; 
selop(acnst[72],false,0L,pl1.cel,&rez1);pl6.cel=rez1;
   if( rez1==NULL ) { success1=false;goto _L122;};

loc3 .sa=NULL; 

/* shablon prawila */ r37(&rez1,&success1,&pl6);
if( !success1 ) goto _L122;
loc3 .sa=rez1; 
selop(acnst[68],false,0L,pl1.cel,&rez1);pl6.cel=rez1;
   if( rez1==NULL ) { success1=false;goto _L122;};

/* Alternative pattern */ 
pl7=pl6;
/* nonatomic alternative branches */ 

/* Alternative pattern */ 
pl8=pl6;

/* shablon treemain */ rez1=pl6.cel;
success1=false;if(pl6.nel==0 ) goto _L112; 
 if (rez1!=NULL ) { pointr(rez1,&x.sa); 
       if (x.smld->dtype!= treemain )  
        { rez1=NULL;goto _L112;};
/* prowerka imeni */ 
success1=eqatom(x.smld->name,acnst[ 69 ]); 
if( ! success1 ) { rez1=NULL;goto _L112;};
;}; 
pl9.nel=1;pl9.ptrtype=ptrtree;
success1=true; 
selop(acnst[70],false,0L,pl6.cel,&rez1);pl9.cel=rez1;
   if( rez1==NULL ) { success1=false;goto _L112;};

loc1 .sa=NULL; 

/* shablon prawila */ r38(&rez1,&success1,&pl9);
if( !success1 ) goto _L112;
loc1 .sa=rez1; 
selop(acnst[71],false,0L,pl6.cel,&rez1);pl9.cel=rez1;
   if( rez1==NULL ) { success1=false;goto _L112;};

loc2 .sa=NULL; 

/* shablon prawila */ r39(&rez1,&success1,&pl9);
if( !success1 ) goto _L112;
loc2 .sa=rez1; 
selop(acnst[19],false,0L,pl6.cel,&rez1);pl9.cel=rez1;
   if( rez1==NULL ) { success1=false;goto _L112;};

/* shablon peremennoj */ 
success1=(pl9.nel!=0);rez1=pl9.cel;
if( (pl9.ptrtype!=ptrtree) && success1 ) next(&pl9);
loc5 .sa=rez1; 
if( !success1 ) goto _L112;
if( success1 ) {
 rez1=pl6.cel;if( pl6.ptrtype!=ptrtree ) next(&pl6) ;}
 else { rez1=NULL;goto _L112 ;};

outatm(acnst[15],"indxop(",true, true); 
outxt(acnst[ 15 ], loc2 .sa , false, true); 
outxt(acnst[ 15 ], loc1 .sa , false, true); 
outatm(acnst[15],",&",false, true); 
outxt(acnst[ 15 ], loc5 .sa , false, true); 
outatm(acnst[15],".sa);",false, true); 
outatm(acnst[15],"lconc(&",false, true); 
outxt(acnst[ 15 ], loc5 .sa , false, true); 
outatm(acnst[15],".sa,",false, true); 
outxt(acnst[ 15 ], loc3 .sa , false, true); 
outatm(acnst[15],");",false, true); 
outatm(acnst[15],"setind(",false, true); 
outxt(acnst[ 15 ], loc2 .sa , false, true); 
outxt(acnst[ 15 ], loc1 .sa , false, true); 
outatm(acnst[15],",",false, true); 
outxt(acnst[ 15 ], loc5 .sa , false, true); 
outatm(acnst[15],".sa)",false, true); ;xxx; 
goto _L113/*uspeh*/;
_L112:; 
pl6=pl8;
goto  _L114;
_L113:;/*uspeh alxtern.*/
goto _L121/*uspeh*/;
_L114:; 
pl6=pl7;

/* Alternative pattern */ 
pl9=pl6;

/* shablon treemain */ rez1=pl6.cel;
success1=false;if(pl6.nel==0 ) goto _L115; 
 if (rez1!=NULL ) { pointr(rez1,&x.sa); 
       if (x.smld->dtype!= treemain )  
        { rez1=NULL;goto _L115;};
/* prowerka imeni */ 
success1=eqatom(x.smld->name,acnst[ 73 ]); 
if( ! success1 ) { rez1=NULL;goto _L115;};
;}; 
pl10.nel=1;pl10.ptrtype=ptrtree;
success1=true; 
selop(acnst[70],false,0L,pl6.cel,&rez1);pl10.cel=rez1;
   if( rez1==NULL ) { success1=false;goto _L115;};

loc1 .sa=NULL; 

/* shablon prawila */ r38(&rez1,&success1,&pl10);
if( !success1 ) goto _L115;
loc1 .sa=rez1; 
selop(acnst[71],false,0L,pl6.cel,&rez1);pl10.cel=rez1;
   if( rez1==NULL ) { success1=false;goto _L115;};

loc2 .sa=NULL; 

/* shablon prawila */ r40(&rez1,&success1,&pl10);
if( !success1 ) goto _L115;
loc2 .sa=rez1; 
selop(acnst[19],false,0L,pl6.cel,&rez1);pl10.cel=rez1;
   if( rez1==NULL ) { success1=false;goto _L115;};

/* shablon peremennoj */ 
success1=(pl10.nel!=0);rez1=pl10.cel;
if( (pl10.ptrtype!=ptrtree) && success1 ) next(&pl10);
loc5 .sa=rez1; 
if( !success1 ) goto _L115;
if( success1 ) {
 rez1=pl6.cel;if( pl6.ptrtype!=ptrtree ) next(&pl6) ;}
 else { rez1=NULL;goto _L115 ;};

outatm(acnst[15],"selop(",true, true); 
outxt(acnst[ 15 ], loc2 .sa , false, true); 
outxt(acnst[ 15 ], loc1 .sa , false, true); 
outatm(acnst[15],",&",false, true); 
outxt(acnst[ 15 ], loc5 .sa , false, true); 
outatm(acnst[15],".sa);lconc(&",false, true); 
outxt(acnst[ 15 ], loc5 .sa , false, true); 
outatm(acnst[15],".sa,",false, true); 
outxt(acnst[ 15 ], loc3 .sa , false, true); 
outatm(acnst[15],");if(",false, true); 
outxt(acnst[ 15 ], loc5 .sa , false, true); 
outatm(acnst[15],".sa==NULL ) setsel(",false, true); 
outxt(acnst[ 15 ], loc2 .sa , false, true); 
outxt(acnst[ 15 ], loc1 .sa , false, true); 
outatm(acnst[15],",NULL)",false, true); ;xxx; 
goto _L116/*uspeh*/;
_L115:; 
pl6=pl9;
goto  _L117;
_L116:;/*uspeh alxtern.*/
goto _L121/*uspeh*/;
_L117:; 
pl6=pl7;

/* Alternative pattern */ 
pl10=pl6;

/* shablon peremennoj */ 
success1=(pl6.nel!=0);rez1=pl6.cel;
if( (pl6.ptrtype!=ptrtree) && success1 ) next(&pl6);
loc4 .sa=rez1; 
if( !success1 ) goto _L118;

/* CALL #L */ 
pl11.ptrtype=packedlist;pl11.nel=1;pl11.cel=loc4.sa;
pl11.plistsize= 1;
r41(&wrk1.sa,&flag1,&pl11);/* #G_wyravenie*/ ;xxx; 

outatm(acnst[15],"lconc(&",true, true); 
selop( acnst[ 19 ],false,NULL, loc4 .sa ,& wrk1 .sa); 
outxt(acnst[ 15 ], wrk1 .sa , false, true); 
outatm(acnst[15],".sa,",false, true); 
outxt(acnst[ 15 ], loc3 .sa , false, true); 
outatm(acnst[15],")",false, true); ;xxx; 
goto _L119/*uspeh*/;
_L118:; 
pl6=pl10;
goto  _L120;
_L119:;/*uspeh alxtern.*/
goto _L121/*uspeh*/;
_L120:; 
pl6=pl7;
goto  _L122;
_L121:;/*uspeh alxtern.*/
if( success1 ) {
 rez1=pl1.cel;if( pl1.ptrtype!=ptrtree ) next(&pl1) ;}
 else { rez1=NULL;goto _L122 ;};
goto _L99;  _L122:;  /* metka wyhoda po neuspehu wetwi */

/* branch */ pl1=*pl;rez1=NULL;success1=true; 
/* inicializaciq peremennyh */ 
loc1.sa=NULL;/* $A1*/ 
loc2.sa=NULL;/* $A2*/ 
loc3.sa=NULL;/* $E*/ 
loc4.sa=NULL;/* $E1*/ 
loc5.sa=NULL;/* $W*/ 
loc6.sa=NULL;/* $A3*/ 

/* shablon treemain */ rez1=pl1.cel;
success1=false;if(pl1.nel==0 ) goto _L133; 
 if (rez1!=NULL ) { pointr(rez1,&x.sa); 
       if (x.smld->dtype!= treemain )  
        { rez1=NULL;goto _L133;};
/* prowerka imeni */ 
success1=eqatom(x.smld->name,acnst[ 63 ]); 
if( ! success1 ) { rez1=NULL;goto _L133;};
;}; 
pl10.nel=1;pl10.ptrtype=ptrtree;
success1=true; 
selop(acnst[64],false,0L,pl1.cel,&rez1);pl10.cel=rez1;
   if( rez1==NULL ) { success1=false;goto _L133;};

/* shablon atoma */ atmpat(acnst[75],&pl10,&rez1,&success1);
if( !success1 ) goto _L133;

outatm(acnst[15],"/* operator +:= */",true, true); ;xxx; 
selop(acnst[72],false,0L,pl1.cel,&rez1);pl10.cel=rez1;
   if( rez1==NULL ) { success1=false;goto _L133;};

/* shablon peremennoj */ 
success1=(pl10.nel!=0);rez1=pl10.cel;
if( (pl10.ptrtype!=ptrtree) && success1 ) next(&pl10);
loc3 .sa=rez1; 
if( !success1 ) goto _L133;

/* CALL #L */ 
pl11.ptrtype=packedlist;pl11.nel=1;pl11.cel=loc3.sa;
pl11.plistsize= 1;
r41(&wrk1.sa,&flag1,&pl11);/* #G_wyravenie*/ ;xxx; 

/* operator := */ 
/* CALL #L */ 
pl11.ptrtype=packedlist;pl11.nel=1;pl11.cel=loc3.sa;
pl11.plistsize= 1;
r48(&wrk1.sa,&flag1,&pl11);/* #~islo_ili_0*/ ; 
loc6 .sa= wrk1 .sa ;xxx; 
selop(acnst[68],false,0L,pl1.cel,&rez1);pl10.cel=rez1;
   if( rez1==NULL ) { success1=false;goto _L133;};

/* Alternative pattern */ 
pl11=pl10;
/* nonatomic alternative branches */ 

/* Alternative pattern */ 
pl12=pl10;

/* shablon treemain */ rez1=pl10.cel;
success1=false;if(pl10.nel==0 ) goto _L123; 
 if (rez1!=NULL ) { pointr(rez1,&x.sa); 
       if (x.smld->dtype!= treemain )  
        { rez1=NULL;goto _L123;};
/* prowerka imeni */ 
success1=eqatom(x.smld->name,acnst[ 69 ]); 
if( ! success1 ) { rez1=NULL;goto _L123;};
;}; 
pl13.nel=1;pl13.ptrtype=ptrtree;
success1=true; 
selop(acnst[70],false,0L,pl10.cel,&rez1);pl13.cel=rez1;
   if( rez1==NULL ) { success1=false;goto _L123;};

loc1 .sa=NULL; 

/* shablon prawila */ r38(&rez1,&success1,&pl13);
if( !success1 ) goto _L123;
loc1 .sa=rez1; 
selop(acnst[71],false,0L,pl10.cel,&rez1);pl13.cel=rez1;
   if( rez1==NULL ) { success1=false;goto _L123;};

loc2 .sa=NULL; 

/* shablon prawila */ r39(&rez1,&success1,&pl13);
if( !success1 ) goto _L123;
loc2 .sa=rez1; 
selop(acnst[19],false,0L,pl10.cel,&rez1);pl13.cel=rez1;
   if( rez1==NULL ) { success1=false;goto _L123;};

/* shablon peremennoj */ 
success1=(pl13.nel!=0);rez1=pl13.cel;
if( (pl13.ptrtype!=ptrtree) && success1 ) next(&pl13);
loc5 .sa=rez1; 
if( !success1 ) goto _L123;
if( success1 ) {
 rez1=pl10.cel;if( pl10.ptrtype!=ptrtree ) next(&pl10) ;}
 else { rez1=NULL;goto _L123 ;};

outatm(acnst[15],"indxop(",true, true); 
outxt(acnst[ 15 ], loc2 .sa , false, true); 
outxt(acnst[ 15 ], loc1 .sa , false, true); 
outatm(acnst[15],",&",false, true); 
outxt(acnst[ 15 ], loc5 .sa , false, true); 
outatm(acnst[15],".sa);addnum(&",false, true); 
outxt(acnst[ 15 ], loc5 .sa , false, true); 
outatm(acnst[15],".sa,",false, true); 
outxt(acnst[ 15 ], loc6 .sa , false, true); 
outatm(acnst[15],");setind(",false, true); 
outxt(acnst[ 15 ], loc2 .sa , false, true); 
outxt(acnst[ 15 ], loc1 .sa , false, true); 
outatm(acnst[15],",",false, true); 
outxt(acnst[ 15 ], loc5 .sa , false, true); 
outatm(acnst[15],".sa)",false, true); ;xxx; 
goto _L124/*uspeh*/;
_L123:; 
pl10=pl12;
goto  _L125;
_L124:;/*uspeh alxtern.*/
goto _L132/*uspeh*/;
_L125:; 
pl10=pl11;

/* Alternative pattern */ 
pl13=pl10;

/* shablon treemain */ rez1=pl10.cel;
success1=false;if(pl10.nel==0 ) goto _L126; 
 if (rez1!=NULL ) { pointr(rez1,&x.sa); 
       if (x.smld->dtype!= treemain )  
        { rez1=NULL;goto _L126;};
/* prowerka imeni */ 
success1=eqatom(x.smld->name,acnst[ 73 ]); 
if( ! success1 ) { rez1=NULL;goto _L126;};
;}; 
pl14.nel=1;pl14.ptrtype=ptrtree;
success1=true; 
selop(acnst[70],false,0L,pl10.cel,&rez1);pl14.cel=rez1;
   if( rez1==NULL ) { success1=false;goto _L126;};

loc1 .sa=NULL; 

/* shablon prawila */ r38(&rez1,&success1,&pl14);
if( !success1 ) goto _L126;
loc1 .sa=rez1; 
selop(acnst[71],false,0L,pl10.cel,&rez1);pl14.cel=rez1;
   if( rez1==NULL ) { success1=false;goto _L126;};

loc2 .sa=NULL; 

/* shablon prawila */ r40(&rez1,&success1,&pl14);
if( !success1 ) goto _L126;
loc2 .sa=rez1; 
selop(acnst[19],false,0L,pl10.cel,&rez1);pl14.cel=rez1;
   if( rez1==NULL ) { success1=false;goto _L126;};

/* shablon peremennoj */ 
success1=(pl14.nel!=0);rez1=pl14.cel;
if( (pl14.ptrtype!=ptrtree) && success1 ) next(&pl14);
loc5 .sa=rez1; 
if( !success1 ) goto _L126;
if( success1 ) {
 rez1=pl10.cel;if( pl10.ptrtype!=ptrtree ) next(&pl10) ;}
 else { rez1=NULL;goto _L126 ;};

outatm(acnst[15],"selop(",true, true); 
outxt(acnst[ 15 ], loc2 .sa , false, true); 
outxt(acnst[ 15 ], loc1 .sa , false, true); 
outatm(acnst[15],",&",false, true); 
outxt(acnst[ 15 ], loc5 .sa , false, true); 
outatm(acnst[15],".sa);addnum(&",false, true); 
outxt(acnst[ 15 ], loc5 .sa , false, true); 
outatm(acnst[15],".sa,",false, true); 
outxt(acnst[ 15 ], loc6 .sa , false, true); 
outatm(acnst[15],");setsel(",false, true); 
outxt(acnst[ 15 ], loc2 .sa , false, true); 
outxt(acnst[ 15 ], loc1 .sa , false, true); 
outatm(acnst[15],",",false, true); 
outxt(acnst[ 15 ], loc5 .sa , false, true); 
outatm(acnst[15],".sa)",false, true); ;xxx; 
goto _L127/*uspeh*/;
_L126:; 
pl10=pl13;
goto  _L128;
_L127:;/*uspeh alxtern.*/
goto _L132/*uspeh*/;
_L128:; 
pl10=pl11;

/* Alternative pattern */ 
pl14=pl10;

/* shablon peremennoj */ 
success1=(pl10.nel!=0);rez1=pl10.cel;
if( (pl10.ptrtype!=ptrtree) && success1 ) next(&pl10);
loc4 .sa=rez1; 
if( !success1 ) goto _L129;

/* CALL #L */ 
pl15.ptrtype=packedlist;pl15.nel=1;pl15.cel=loc4.sa;
pl15.plistsize= 1;
r41(&wrk1.sa,&flag1,&pl15);/* #G_wyravenie*/ ;xxx; 

outatm(acnst[15],"addnum(&",true, true); 
selop( acnst[ 19 ],false,NULL, loc4 .sa ,& wrk1 .sa); 
outxt(acnst[ 15 ], wrk1 .sa , false, true); 
outatm(acnst[15],".sa,",false, true); 
outxt(acnst[ 15 ], loc6 .sa , false, true); 
outatm(acnst[15],")",false, true); ;xxx; 
goto _L130/*uspeh*/;
_L129:; 
pl10=pl14;
goto  _L131;
_L130:;/*uspeh alxtern.*/
goto _L132/*uspeh*/;
_L131:; 
pl10=pl11;
goto  _L133;
_L132:;/*uspeh alxtern.*/
if( success1 ) {
 rez1=pl1.cel;if( pl1.ptrtype!=ptrtree ) next(&pl1) ;}
 else { rez1=NULL;goto _L133 ;};
goto _L99;  _L133:;  /* metka wyhoda po neuspehu wetwi */
 _L99: rez1=NULL; 
 _L98: *rez=rez1;*success=success1; 
 if (*success) *pl=pl1; /* prodwinutx ukazatelx leksem */ 
/* wosstanowitx GLOB */ 
#ifdef XX  
 d(2,"G_ANORM", 34 ,*rez,*success); 
#endif 
;};/* RULE */ 
/*===============================================*/ 
/* GENERATED TEXT OF RULE   #G_ALONGLIST   */ 
 Void r35(rez,success,pl)
long *rez;boolean *success;ptr_ *pl; 
{  a rez1;  boolean success1; long k; mpd x; 
v loc1;/* $B*/ 
v loc2;/* $A1*/ 
v loc3;/* $A2*/ 
v loc4;/* $W*/ 
v loc5;/* $E1*/ 
v loc6;/* $EL*/ 
v loc7;/* $E*/ 
v wrk1;
ptr_ pl1;
ptr_ pl2;
ptr_ pl3;
ptr_ pl4;
ptr_ pl5;
ptr_ pl6;
ptr_ pl7;
ptr_ pl8;
ptr_ pl9;
ptr_ pl10;
ptr_ pl11;
ptr_ pl12;
ptr_ pl13;
ptr_ pl14;
boolean flag1;
#ifdef XX  
 d(1,"G_ALONGLIST", 35 ,pl->cel,0); 
#endif 
/* sohranitx GLOB */ 

/* branch */ pl1=*pl;rez1=NULL;success1=true; 
/* inicializaciq peremennyh */ 
loc2.sa=NULL;/* $A1*/ 
loc3.sa=NULL;/* $A2*/ 
loc4.sa=NULL;/* $W*/ 
loc5.sa=NULL;/* $E1*/ 
loc6.sa=NULL;/* $EL*/ 

/* shablon treemain */ rez1=pl1.cel;
success1=false;if(pl1.nel==0 ) goto _L122; 
 if (rez1!=NULL ) { pointr(rez1,&x.sa); 
       if (x.smld->dtype!= treemain )  
        { rez1=NULL;goto _L122;};
/* prowerka imeni */ 
success1=eqatom(x.smld->name,acnst[ 63 ]); 
if( ! success1 ) { rez1=NULL;goto _L122;};
;}; 
pl2.nel=1;pl2.ptrtype=ptrtree;
success1=true; 
selop(acnst[64],false,0L,pl1.cel,&rez1);pl2.cel=rez1;
   if( rez1==NULL ) { success1=false;goto _L122;};

/* shablon atoma */ atmpat(acnst[65],&pl2,&rez1,&success1);
if( !success1 ) goto _L122;

outatm(acnst[15],"/* operator !!:= */",true, true); ;xxx; 
selop(acnst[72],false,0L,pl1.cel,&rez1);pl2.cel=rez1;
   if( rez1==NULL ) { success1=false;goto _L122;};

/* shablon treemain */ rez1=pl2.cel;
success1=false;if(pl2.nel==0 ) goto _L122; 
 if (rez1!=NULL ) { pointr(rez1,&x.sa); 
       if (x.smld->dtype!= treemain )  
        { rez1=NULL;goto _L122;};
/* prowerka imeni */ 
success1=eqatom(x.smld->name,acnst[ 76 ]); 
if( ! success1 ) { rez1=NULL;goto _L122;};
;}; 
pl3.nel=1;pl3.ptrtype=ptrtree;
success1=true; 
selop(acnst[39],false,0L,pl2.cel,&rez1);pl3.cel=rez1;
   if( rez1==NULL ) { success1=false;goto _L101;};

/* shablon peremennoj */ 
success1=(pl3.nel!=0);rez1=pl3.cel;
if( (pl3.ptrtype!=ptrtree) && success1 ) next(&pl3);
loc1 .sa=rez1; 
if( !success1 ) goto _L101;
_L101:success1=true;
if( success1 ) {
 rez1=pl2.cel;if( pl2.ptrtype!=ptrtree ) next(&pl2) ;}
 else { rez1=NULL;goto _L122 ;};
selop(acnst[68],false,0L,pl1.cel,&rez1);pl2.cel=rez1;
   if( rez1==NULL ) { success1=false;goto _L122;};

/* Alternative pattern */ 
pl3=pl2;
/* nonatomic alternative branches */ 

/* Alternative pattern */ 
pl4=pl2;

/* shablon treemain */ rez1=pl2.cel;
success1=false;if(pl2.nel==0 ) goto _L102; 
 if (rez1!=NULL ) { pointr(rez1,&x.sa); 
       if (x.smld->dtype!= treemain )  
        { rez1=NULL;goto _L102;};
/* prowerka imeni */ 
success1=eqatom(x.smld->name,acnst[ 69 ]); 
if( ! success1 ) { rez1=NULL;goto _L102;};
;}; 
pl5.nel=1;pl5.ptrtype=ptrtree;
success1=true; 
selop(acnst[70],false,0L,pl2.cel,&rez1);pl5.cel=rez1;
   if( rez1==NULL ) { success1=false;goto _L102;};

loc2 .sa=NULL; 

/* shablon prawila */ r38(&rez1,&success1,&pl5);
if( !success1 ) goto _L102;
loc2 .sa=rez1; 
selop(acnst[71],false,0L,pl2.cel,&rez1);pl5.cel=rez1;
   if( rez1==NULL ) { success1=false;goto _L102;};

loc3 .sa=NULL; 

/* shablon prawila */ r39(&rez1,&success1,&pl5);
if( !success1 ) goto _L102;
loc3 .sa=rez1; 
selop(acnst[19],false,0L,pl2.cel,&rez1);pl5.cel=rez1;
   if( rez1==NULL ) { success1=false;goto _L102;};

/* shablon peremennoj */ 
success1=(pl5.nel!=0);rez1=pl5.cel;
if( (pl5.ptrtype!=ptrtree) && success1 ) next(&pl5);
loc4 .sa=rez1; 
if( !success1 ) goto _L102;
if( success1 ) {
 rez1=pl2.cel;if( pl2.ptrtype!=ptrtree ) next(&pl2) ;}
 else { rez1=NULL;goto _L102 ;};

outatm(acnst[15],"indxop(",true, true); 
outxt(acnst[ 15 ], loc3 .sa , false, true); 
outxt(acnst[ 15 ], loc2 .sa , false, true); 
outatm(acnst[15],",&",false, true); 
outxt(acnst[ 15 ], loc4 .sa , false, true); 
outatm(acnst[15],".sa);",false, true); ;xxx; 
goto _L103/*uspeh*/;
_L102:; 
pl2=pl4;
goto  _L104;
_L103:;/*uspeh alxtern.*/
goto _L111/*uspeh*/;
_L104:; 
pl2=pl3;

/* Alternative pattern */ 
pl5=pl2;

/* shablon treemain */ rez1=pl2.cel;
success1=false;if(pl2.nel==0 ) goto _L105; 
 if (rez1!=NULL ) { pointr(rez1,&x.sa); 
       if (x.smld->dtype!= treemain )  
        { rez1=NULL;goto _L105;};
/* prowerka imeni */ 
success1=eqatom(x.smld->name,acnst[ 73 ]); 
if( ! success1 ) { rez1=NULL;goto _L105;};
;}; 
pl6.nel=1;pl6.ptrtype=ptrtree;
success1=true; 
selop(acnst[70],false,0L,pl2.cel,&rez1);pl6.cel=rez1;
   if( rez1==NULL ) { success1=false;goto _L105;};

loc2 .sa=NULL; 

/* shablon prawila */ r38(&rez1,&success1,&pl6);
if( !success1 ) goto _L105;
loc2 .sa=rez1; 
selop(acnst[71],false,0L,pl2.cel,&rez1);pl6.cel=rez1;
   if( rez1==NULL ) { success1=false;goto _L105;};

loc3 .sa=NULL; 

/* shablon prawila */ r40(&rez1,&success1,&pl6);
if( !success1 ) goto _L105;
loc3 .sa=rez1; 
selop(acnst[19],false,0L,pl2.cel,&rez1);pl6.cel=rez1;
   if( rez1==NULL ) { success1=false;goto _L105;};

/* shablon peremennoj */ 
success1=(pl6.nel!=0);rez1=pl6.cel;
if( (pl6.ptrtype!=ptrtree) && success1 ) next(&pl6);
loc4 .sa=rez1; 
if( !success1 ) goto _L105;
if( success1 ) {
 rez1=pl2.cel;if( pl2.ptrtype!=ptrtree ) next(&pl2) ;}
 else { rez1=NULL;goto _L105 ;};

outatm(acnst[15],"selop(",true, true); 
outxt(acnst[ 15 ], loc3 .sa , false, true); 
outxt(acnst[ 15 ], loc2 .sa , false, true); 
outatm(acnst[15],",&",false, true); 
outxt(acnst[ 15 ], loc4 .sa , false, true); 
outatm(acnst[15],".sa);",false, true); ;xxx; 
goto _L106/*uspeh*/;
_L105:; 
pl2=pl5;
goto  _L107;
_L106:;/*uspeh alxtern.*/
goto _L111/*uspeh*/;
_L107:; 
pl2=pl3;

/* Alternative pattern */ 
pl6=pl2;

/* shablon peremennoj */ 
success1=(pl2.nel!=0);rez1=pl2.cel;
if( (pl2.ptrtype!=ptrtree) && success1 ) next(&pl2);
loc5 .sa=rez1; 
if( !success1 ) goto _L108;

/* CALL #L */ 
pl7.ptrtype=packedlist;pl7.nel=1;pl7.cel=loc5.sa;
pl7.plistsize= 1;
r41(&wrk1.sa,&flag1,&pl7);/* #G_wyravenie*/ ;xxx; 

/* operator := */ 
selop( acnst[ 19 ],false,NULL, loc5 .sa ,& wrk1 .sa); 
loc4 .sa= wrk1 .sa ;xxx; 
goto _L109/*uspeh*/;
_L108:; 
pl2=pl6;
goto  _L110;
_L109:;/*uspeh alxtern.*/
goto _L111/*uspeh*/;
_L110:; 
pl2=pl3;
goto  _L122;
_L111:;/*uspeh alxtern.*/
selop(acnst[72],false,0L,pl1.cel,&rez1);pl2.cel=rez1;
   if( rez1==NULL ) { success1=false;goto _L122;};

/* shablon treemain */ rez1=pl2.cel;
success1=false;if(pl2.nel==0 ) goto _L122; 
 if (rez1!=NULL ) { pointr(rez1,&x.sa); 
       if (x.smld->dtype!= treemain )  
        { rez1=NULL;goto _L122;};
;}; 
pl7.nel=1;pl7.ptrtype=ptrtree;
success1=true; 
selop(acnst[39],false,0L,pl2.cel,&rez1);pl7.cel=rez1;
   if( rez1==NULL ) { success1=false;goto _L112;};

/* shablon listmain */ rez1=pl7.cel;
success1=false;if(pl7.nel==0 ) goto _L112; 
 if (rez1!=NULL ) { pointr(rez1,&x.sa); 
       if (x.smld->dtype!= listmain )  
        { rez1=NULL;goto _L112;};
{pl8.ptrtype=ptrlist; pl8.nel=1;
pl8.cel=x.smld->elt[0];pl8.UU.U1.curfragment=rez1;}
;} else  
{pl8.ptrtype=ptrlist;pl8.nel=0;pl8.cel=NULL;}

loc6 .sa=NULL; 

/* shablon prawila */ r37(&rez1,&success1,&pl8);
if( !success1 ) goto _L112;
loc6 .sa=rez1; 

outatm(acnst[15],"lconc(&",true, true); 
outxt(acnst[ 15 ], loc4 .sa , false, true); 
outatm(acnst[15],".sa,",false, true); 
outxt(acnst[ 15 ], loc6 .sa , false, true); 
outatm(acnst[15],");",false, true); ;xxx; 

/*shablon STARLIST */ 
 pl9=pl8;while(pl8.nel!=0 ) { 

loc6 .sa=NULL; 

/* shablon prawila */ r37(&rez1,&success1,&pl8);
if( !success1 ) goto _L113;
loc6 .sa=rez1; 

outatm(acnst[15],"if(",true, true); 
outxt(acnst[ 15 ], loc4 .sa , false, true); 
outatm(acnst[15],".sa!=NULL ) lconc(&",false, true); 
outxt(acnst[ 15 ], loc4 .sa , false, true); 
outatm(acnst[15],".sa,",false, true); 
outxt(acnst[ 15 ], loc6 .sa , false, true); 
outatm(acnst[15],");",false, true); ;xxx; 
 pl9=pl8;
;}; 
_L113:if( ! success1 )pl8=pl9;
success1 = true ; 

if( pl8.nel !=0 )
{ success1=false;rez1=NULL;goto _L112;};
success1=true;rez1=pl7.cel;
 if( pl7.ptrtype!=ptrtree ) next(&pl7);
_L112:success1=true;
if( success1 ) {
 rez1=pl2.cel;if( pl2.ptrtype!=ptrtree ) next(&pl2) ;}
 else { rez1=NULL;goto _L122 ;};
selop(acnst[68],false,0L,pl1.cel,&rez1);pl2.cel=rez1;
   if( rez1==NULL ) { success1=false;goto _L122;};

/* Alternative pattern */ 
pl7=pl2;
/* nonatomic alternative branches */ 

/* Alternative pattern */ 
pl8=pl2;

/* shablon treemain */ rez1=pl2.cel;
success1=false;if(pl2.nel==0 ) goto _L114; 
 if (rez1!=NULL ) { pointr(rez1,&x.sa); 
       if (x.smld->dtype!= treemain )  
        { rez1=NULL;goto _L114;};
/* prowerka imeni */ 
success1=eqatom(x.smld->name,acnst[ 69 ]); 
if( ! success1 ) { rez1=NULL;goto _L114;};
;}; 
pl9.nel=1;pl9.ptrtype=ptrtree;
success1=true; 
selop(acnst[70],false,0L,pl2.cel,&rez1);pl9.cel=rez1;
   if( rez1==NULL ) { success1=false;goto _L114;};

/* shablon peremennoj */ 
success1=(pl9.nel!=0);rez1=pl9.cel;
if( (pl9.ptrtype!=ptrtree) && success1 ) next(&pl9);
loc1 .sa=rez1; 
if( !success1 ) goto _L114;
if( success1 ) {
 rez1=pl2.cel;if( pl2.ptrtype!=ptrtree ) next(&pl2) ;}
 else { rez1=NULL;goto _L114 ;};

outatm(acnst[15],"setind(",true, true); 
outxt(acnst[ 15 ], loc3 .sa , false, true); 
outxt(acnst[ 15 ], loc2 .sa , false, true); 
outatm(acnst[15],",",false, true); 
outxt(acnst[ 15 ], loc4 .sa , false, true); 
outatm(acnst[15],".sa)",false, true); ;xxx; 
goto _L115/*uspeh*/;
_L114:; 
pl2=pl8;
goto  _L116;
_L115:;/*uspeh alxtern.*/
goto _L121/*uspeh*/;
_L116:; 
pl2=pl7;

/* Alternative pattern */ 
pl9=pl2;

/* shablon treemain */ rez1=pl2.cel;
success1=false;if(pl2.nel==0 ) goto _L117; 
 if (rez1!=NULL ) { pointr(rez1,&x.sa); 
       if (x.smld->dtype!= treemain )  
        { rez1=NULL;goto _L117;};
/* prowerka imeni */ 
success1=eqatom(x.smld->name,acnst[ 73 ]); 
if( ! success1 ) { rez1=NULL;goto _L117;};
;}; 
pl10.nel=1;pl10.ptrtype=ptrtree;
success1=true; 
selop(acnst[70],false,0L,pl2.cel,&rez1);pl10.cel=rez1;
   if( rez1==NULL ) { success1=false;goto _L117;};

/* shablon peremennoj */ 
success1=(pl10.nel!=0);rez1=pl10.cel;
if( (pl10.ptrtype!=ptrtree) && success1 ) next(&pl10);
loc1 .sa=rez1; 
if( !success1 ) goto _L117;
if( success1 ) {
 rez1=pl2.cel;if( pl2.ptrtype!=ptrtree ) next(&pl2) ;}
 else { rez1=NULL;goto _L117 ;};

outatm(acnst[15],"if(",true, true); 
outxt(acnst[ 15 ], loc4 .sa , false, true); 
outatm(acnst[15],".sa==NULL )",false, true); 
outatm(acnst[15],"setsel(",false, true); 
outxt(acnst[ 15 ], loc3 .sa , false, true); 
outxt(acnst[ 15 ], loc2 .sa , false, true); 
outatm(acnst[15],",NULL)",false, true); ;xxx; 
goto _L118/*uspeh*/;
_L117:; 
pl2=pl9;
goto  _L119;
_L118:;/*uspeh alxtern.*/
goto _L121/*uspeh*/;
_L119:; 
pl2=pl7;

/* shablon peremennoj */ 
success1=(pl2.nel!=0);rez1=pl2.cel;
if( (pl2.ptrtype!=ptrtree) && success1 ) next(&pl2);
loc5 .sa=rez1; 
if( !success1 ) goto _L120;
goto _L121/*uspeh*/;
_L120:; 
pl2=pl7;
goto  _L122;
_L121:;/*uspeh alxtern.*/
if( success1 ) {
 rez1=pl1.cel;if( pl1.ptrtype!=ptrtree ) next(&pl1) ;}
 else { rez1=NULL;goto _L122 ;};
goto _L99;  _L122:;  /* metka wyhoda po neuspehu wetwi */

/* branch */ pl1=*pl;rez1=NULL;success1=true; 
/* inicializaciq peremennyh */ 
loc2.sa=NULL;/* $A1*/ 
loc3.sa=NULL;/* $A2*/ 
loc4.sa=NULL;/* $W*/ 
loc5.sa=NULL;/* $E1*/ 
loc7.sa=NULL;/* $E*/ 

/* shablon treemain */ rez1=pl1.cel;
success1=false;if(pl1.nel==0 ) goto _L133; 
 if (rez1!=NULL ) { pointr(rez1,&x.sa); 
       if (x.smld->dtype!= treemain )  
        { rez1=NULL;goto _L133;};
/* prowerka imeni */ 
success1=eqatom(x.smld->name,acnst[ 63 ]); 
if( ! success1 ) { rez1=NULL;goto _L133;};
;}; 
pl9.nel=1;pl9.ptrtype=ptrtree;
success1=true; 
selop(acnst[64],false,0L,pl1.cel,&rez1);pl9.cel=rez1;
   if( rez1==NULL ) { success1=false;goto _L133;};

/* shablon atoma */ atmpat(acnst[65],&pl9,&rez1,&success1);
if( !success1 ) goto _L133;
selop(acnst[72],false,0L,pl1.cel,&rez1);pl9.cel=rez1;
   if( rez1==NULL ) { success1=false;goto _L133;};

loc7 .sa=NULL; 

/* shablon prawila */ r37(&rez1,&success1,&pl9);
if( !success1 ) goto _L133;
loc7 .sa=rez1; 
selop(acnst[68],false,0L,pl1.cel,&rez1);pl9.cel=rez1;
   if( rez1==NULL ) { success1=false;goto _L133;};

/* Alternative pattern */ 
pl10=pl9;
/* nonatomic alternative branches */ 

/* Alternative pattern */ 
pl11=pl9;

/* shablon treemain */ rez1=pl9.cel;
success1=false;if(pl9.nel==0 ) goto _L123; 
 if (rez1!=NULL ) { pointr(rez1,&x.sa); 
       if (x.smld->dtype!= treemain )  
        { rez1=NULL;goto _L123;};
/* prowerka imeni */ 
success1=eqatom(x.smld->name,acnst[ 69 ]); 
if( ! success1 ) { rez1=NULL;goto _L123;};
;}; 
pl12.nel=1;pl12.ptrtype=ptrtree;
success1=true; 
selop(acnst[70],false,0L,pl9.cel,&rez1);pl12.cel=rez1;
   if( rez1==NULL ) { success1=false;goto _L123;};

loc2 .sa=NULL; 

/* shablon prawila */ r38(&rez1,&success1,&pl12);
if( !success1 ) goto _L123;
loc2 .sa=rez1; 
selop(acnst[71],false,0L,pl9.cel,&rez1);pl12.cel=rez1;
   if( rez1==NULL ) { success1=false;goto _L123;};

loc3 .sa=NULL; 

/* shablon prawila */ r39(&rez1,&success1,&pl12);
if( !success1 ) goto _L123;
loc3 .sa=rez1; 
selop(acnst[19],false,0L,pl9.cel,&rez1);pl12.cel=rez1;
   if( rez1==NULL ) { success1=false;goto _L123;};

/* shablon peremennoj */ 
success1=(pl12.nel!=0);rez1=pl12.cel;
if( (pl12.ptrtype!=ptrtree) && success1 ) next(&pl12);
loc4 .sa=rez1; 
if( !success1 ) goto _L123;
if( success1 ) {
 rez1=pl9.cel;if( pl9.ptrtype!=ptrtree ) next(&pl9) ;}
 else { rez1=NULL;goto _L123 ;};

outatm(acnst[15],"indxcon(",true, true); 
outxt(acnst[ 15 ], loc3 .sa , false, true); 
outxt(acnst[ 15 ], loc2 .sa , false, true); 
outatm(acnst[15],",",false, true); 
outxt(acnst[ 15 ], loc7 .sa , false, true); 
outatm(acnst[15],")",false, true); ;xxx; 
goto _L124/*uspeh*/;
_L123:; 
pl9=pl11;
goto  _L125;
_L124:;/*uspeh alxtern.*/
goto _L132/*uspeh*/;
_L125:; 
pl9=pl10;

/* Alternative pattern */ 
pl12=pl9;

/* shablon treemain */ rez1=pl9.cel;
success1=false;if(pl9.nel==0 ) goto _L126; 
 if (rez1!=NULL ) { pointr(rez1,&x.sa); 
       if (x.smld->dtype!= treemain )  
        { rez1=NULL;goto _L126;};
/* prowerka imeni */ 
success1=eqatom(x.smld->name,acnst[ 73 ]); 
if( ! success1 ) { rez1=NULL;goto _L126;};
;}; 
pl13.nel=1;pl13.ptrtype=ptrtree;
success1=true; 
selop(acnst[70],false,0L,pl9.cel,&rez1);pl13.cel=rez1;
   if( rez1==NULL ) { success1=false;goto _L126;};

loc2 .sa=NULL; 

/* shablon prawila */ r38(&rez1,&success1,&pl13);
if( !success1 ) goto _L126;
loc2 .sa=rez1; 
selop(acnst[71],false,0L,pl9.cel,&rez1);pl13.cel=rez1;
   if( rez1==NULL ) { success1=false;goto _L126;};

loc3 .sa=NULL; 

/* shablon prawila */ r40(&rez1,&success1,&pl13);
if( !success1 ) goto _L126;
loc3 .sa=rez1; 
selop(acnst[19],false,0L,pl9.cel,&rez1);pl13.cel=rez1;
   if( rez1==NULL ) { success1=false;goto _L126;};

/* shablon peremennoj */ 
success1=(pl13.nel!=0);rez1=pl13.cel;
if( (pl13.ptrtype!=ptrtree) && success1 ) next(&pl13);
loc4 .sa=rez1; 
if( !success1 ) goto _L126;
if( success1 ) {
 rez1=pl9.cel;if( pl9.ptrtype!=ptrtree ) next(&pl9) ;}
 else { rez1=NULL;goto _L126 ;};

outatm(acnst[15],"selop(",true, true); 
outxt(acnst[ 15 ], loc3 .sa , false, true); 
outxt(acnst[ 15 ], loc2 .sa , false, true); 
outatm(acnst[15],",&",false, true); 
outxt(acnst[ 15 ], loc4 .sa , false, true); 
outatm(acnst[15],".sa);",false, true); 
outatm(acnst[15],"concop(&",false, true); 
outxt(acnst[ 15 ], loc4 .sa , false, true); 
outatm(acnst[15],".sa,",false, true); 
outxt(acnst[ 15 ], loc7 .sa , false, true); 
outatm(acnst[15],");",false, true); 
outatm(acnst[15],"if(",false, true); 
outxt(acnst[ 15 ], loc4 .sa , false, true); 
outatm(acnst[15],".sa==NULL )",false, true); 
outatm(acnst[15],"setsel(",false, true); 
outxt(acnst[ 15 ], loc3 .sa , false, true); 
outxt(acnst[ 15 ], loc2 .sa , false, true); 
outatm(acnst[15],",NULL)",false, true); ;xxx; 
goto _L127/*uspeh*/;
_L126:; 
pl9=pl12;
goto  _L128;
_L127:;/*uspeh alxtern.*/
goto _L132/*uspeh*/;
_L128:; 
pl9=pl10;

/* Alternative pattern */ 
pl13=pl9;

/* shablon peremennoj */ 
success1=(pl9.nel!=0);rez1=pl9.cel;
if( (pl9.ptrtype!=ptrtree) && success1 ) next(&pl9);
loc5 .sa=rez1; 
if( !success1 ) goto _L129;

/* CALL #L */ 
pl14.ptrtype=packedlist;pl14.nel=1;pl14.cel=loc5.sa;
pl14.plistsize= 1;
r41(&wrk1.sa,&flag1,&pl14);/* #G_wyravenie*/ ;xxx; 

outatm(acnst[15],"concop(&",true, true); 
selop( acnst[ 19 ],false,NULL, loc5 .sa ,& wrk1 .sa); 
outxt(acnst[ 15 ], wrk1 .sa , false, true); 
outatm(acnst[15],".sa,",false, true); 
outxt(acnst[ 15 ], loc7 .sa , false, true); 
outatm(acnst[15],")",false, true); ;xxx; 
goto _L130/*uspeh*/;
_L129:; 
pl9=pl13;
goto  _L131;
_L130:;/*uspeh alxtern.*/
goto _L132/*uspeh*/;
_L131:; 
pl9=pl10;
goto  _L133;
_L132:;/*uspeh alxtern.*/
if( success1 ) {
 rez1=pl1.cel;if( pl1.ptrtype!=ptrtree ) next(&pl1) ;}
 else { rez1=NULL;goto _L133 ;};
goto _L99;  _L133:;  /* metka wyhoda po neuspehu wetwi */
 _L99: rez1=NULL; 
 _L98: *rez=rez1;*success=success1; 
 if (*success) *pl=pl1; /* prodwinutx ukazatelx leksem */ 
/* wosstanowitx GLOB */ 
#ifdef XX  
 d(2,"G_ALONGLIST", 35 ,*rez,*success); 
#endif 
;};/* RULE */ 
/*===============================================*/ 
/* GENERATED TEXT OF RULE   #G_ALONGTREE   */ 
 Void r36(rez,success,pl)
long *rez;boolean *success;ptr_ *pl; 
{  a rez1;  boolean success1; long k; mpd x; 
v loc1;/* $B*/ 
v loc2;/* $REZ*/ 
v loc3;/* $A1*/ 
v loc4;/* $A2*/ 
v loc5;/* $W*/ 
v loc6;/* $E1*/ 
v loc7;/* $EL*/ 
v loc8;/* $EL2*/ 
v loc9;/* $E*/ 
v wrk1;
ptr_ pl1;
ptr_ pl2;
ptr_ pl3;
ptr_ pl4;
ptr_ pl5;
ptr_ pl6;
ptr_ pl7;
ptr_ pl8;
ptr_ pl9;
ptr_ pl10;
ptr_ pl11;
ptr_ pl12;
ptr_ pl13;
ptr_ pl14;
boolean flag1;
#ifdef XX  
 d(1,"G_ALONGTREE", 36 ,pl->cel,0); 
#endif 
/* sohranitx GLOB */ 

/* branch */ pl1=*pl;rez1=NULL;success1=true; 
/* inicializaciq peremennyh */ 
loc2.sa=NULL;/* $REZ*/ 
loc3.sa=NULL;/* $A1*/ 
loc4.sa=NULL;/* $A2*/ 
loc5.sa=NULL;/* $W*/ 
loc6.sa=NULL;/* $E1*/ 
loc7.sa=NULL;/* $EL*/ 
loc8.sa=NULL;/* $EL2*/ 

/* shablon treemain */ rez1=pl1.cel;
success1=false;if(pl1.nel==0 ) goto _L122; 
 if (rez1!=NULL ) { pointr(rez1,&x.sa); 
       if (x.smld->dtype!= treemain )  
        { rez1=NULL;goto _L122;};
/* prowerka imeni */ 
success1=eqatom(x.smld->name,acnst[ 63 ]); 
if( ! success1 ) { rez1=NULL;goto _L122;};
;}; 
pl2.nel=1;pl2.ptrtype=ptrtree;
success1=true; 
selop(acnst[64],false,0L,pl1.cel,&rez1);pl2.cel=rez1;
   if( rez1==NULL ) { success1=false;goto _L122;};

/* shablon atoma */ atmpat(acnst[66],&pl2,&rez1,&success1);
if( !success1 ) goto _L122;

outatm(acnst[15],"/* operator ++:= */",true, true); ;xxx; 
selop(acnst[72],false,0L,pl1.cel,&rez1);pl2.cel=rez1;
   if( rez1==NULL ) { success1=false;goto _L122;};

/* shablon treemain */ rez1=pl2.cel;
success1=false;if(pl2.nel==0 ) goto _L122; 
 if (rez1!=NULL ) { pointr(rez1,&x.sa); 
       if (x.smld->dtype!= treemain )  
        { rez1=NULL;goto _L122;};
/* prowerka imeni */ 
success1=eqatom(x.smld->name,acnst[ 77 ]); 
if( ! success1 ) { rez1=NULL;goto _L122;};
;}; 
pl3.nel=1;pl3.ptrtype=ptrtree;
success1=true; 
selop(acnst[39],false,0L,pl2.cel,&rez1);pl3.cel=rez1;
   if( rez1==NULL ) { success1=false;goto _L101;};

/* shablon peremennoj */ 
success1=(pl3.nel!=0);rez1=pl3.cel;
if( (pl3.ptrtype!=ptrtree) && success1 ) next(&pl3);
loc1 .sa=rez1; 
if( !success1 ) goto _L101;
_L101:success1=true;
selop(acnst[19],false,0L,pl2.cel,&rez1);pl3.cel=rez1;
   if( rez1==NULL ) { success1=false;goto _L122;};

/* shablon peremennoj */ 
success1=(pl3.nel!=0);rez1=pl3.cel;
if( (pl3.ptrtype!=ptrtree) && success1 ) next(&pl3);
loc2 .sa=rez1; 
if( !success1 ) goto _L122;
if( success1 ) {
 rez1=pl2.cel;if( pl2.ptrtype!=ptrtree ) next(&pl2) ;}
 else { rez1=NULL;goto _L122 ;};
selop(acnst[68],false,0L,pl1.cel,&rez1);pl2.cel=rez1;
   if( rez1==NULL ) { success1=false;goto _L122;};

/* Alternative pattern */ 
pl3=pl2;
/* nonatomic alternative branches */ 

/* Alternative pattern */ 
pl4=pl2;

/* shablon treemain */ rez1=pl2.cel;
success1=false;if(pl2.nel==0 ) goto _L102; 
 if (rez1!=NULL ) { pointr(rez1,&x.sa); 
       if (x.smld->dtype!= treemain )  
        { rez1=NULL;goto _L102;};
/* prowerka imeni */ 
success1=eqatom(x.smld->name,acnst[ 69 ]); 
if( ! success1 ) { rez1=NULL;goto _L102;};
;}; 
pl5.nel=1;pl5.ptrtype=ptrtree;
success1=true; 
selop(acnst[70],false,0L,pl2.cel,&rez1);pl5.cel=rez1;
   if( rez1==NULL ) { success1=false;goto _L102;};

loc3 .sa=NULL; 

/* shablon prawila */ r38(&rez1,&success1,&pl5);
if( !success1 ) goto _L102;
loc3 .sa=rez1; 
selop(acnst[71],false,0L,pl2.cel,&rez1);pl5.cel=rez1;
   if( rez1==NULL ) { success1=false;goto _L102;};

loc4 .sa=NULL; 

/* shablon prawila */ r39(&rez1,&success1,&pl5);
if( !success1 ) goto _L102;
loc4 .sa=rez1; 
selop(acnst[19],false,0L,pl2.cel,&rez1);pl5.cel=rez1;
   if( rez1==NULL ) { success1=false;goto _L102;};

/* shablon peremennoj */ 
success1=(pl5.nel!=0);rez1=pl5.cel;
if( (pl5.ptrtype!=ptrtree) && success1 ) next(&pl5);
loc5 .sa=rez1; 
if( !success1 ) goto _L102;
if( success1 ) {
 rez1=pl2.cel;if( pl2.ptrtype!=ptrtree ) next(&pl2) ;}
 else { rez1=NULL;goto _L102 ;};

outatm(acnst[15],"indxop(",true, true); 
outxt(acnst[ 15 ], loc4 .sa , false, true); 
outxt(acnst[ 15 ], loc3 .sa , false, true); 
outatm(acnst[15],",&",false, true); 
outxt(acnst[ 15 ], loc5 .sa , false, true); 
outatm(acnst[15],".sa);",false, true); ;xxx; 
goto _L103/*uspeh*/;
_L102:; 
pl2=pl4;
goto  _L104;
_L103:;/*uspeh alxtern.*/
goto _L111/*uspeh*/;
_L104:; 
pl2=pl3;

/* Alternative pattern */ 
pl5=pl2;

/* shablon treemain */ rez1=pl2.cel;
success1=false;if(pl2.nel==0 ) goto _L105; 
 if (rez1!=NULL ) { pointr(rez1,&x.sa); 
       if (x.smld->dtype!= treemain )  
        { rez1=NULL;goto _L105;};
/* prowerka imeni */ 
success1=eqatom(x.smld->name,acnst[ 73 ]); 
if( ! success1 ) { rez1=NULL;goto _L105;};
;}; 
pl6.nel=1;pl6.ptrtype=ptrtree;
success1=true; 
selop(acnst[70],false,0L,pl2.cel,&rez1);pl6.cel=rez1;
   if( rez1==NULL ) { success1=false;goto _L105;};

loc3 .sa=NULL; 

/* shablon prawila */ r38(&rez1,&success1,&pl6);
if( !success1 ) goto _L105;
loc3 .sa=rez1; 
selop(acnst[71],false,0L,pl2.cel,&rez1);pl6.cel=rez1;
   if( rez1==NULL ) { success1=false;goto _L105;};

loc4 .sa=NULL; 

/* shablon prawila */ r40(&rez1,&success1,&pl6);
if( !success1 ) goto _L105;
loc4 .sa=rez1; 
selop(acnst[19],false,0L,pl2.cel,&rez1);pl6.cel=rez1;
   if( rez1==NULL ) { success1=false;goto _L105;};

/* shablon peremennoj */ 
success1=(pl6.nel!=0);rez1=pl6.cel;
if( (pl6.ptrtype!=ptrtree) && success1 ) next(&pl6);
loc5 .sa=rez1; 
if( !success1 ) goto _L105;
if( success1 ) {
 rez1=pl2.cel;if( pl2.ptrtype!=ptrtree ) next(&pl2) ;}
 else { rez1=NULL;goto _L105 ;};

outatm(acnst[15],"selop(",true, true); 
outxt(acnst[ 15 ], loc4 .sa , false, true); 
outxt(acnst[ 15 ], loc3 .sa , false, true); 
outatm(acnst[15],",&",false, true); 
outxt(acnst[ 15 ], loc5 .sa , false, true); 
outatm(acnst[15],".sa);",false, true); ;xxx; 
goto _L106/*uspeh*/;
_L105:; 
pl2=pl5;
goto  _L107;
_L106:;/*uspeh alxtern.*/
goto _L111/*uspeh*/;
_L107:; 
pl2=pl3;

/* Alternative pattern */ 
pl6=pl2;

/* shablon peremennoj */ 
success1=(pl2.nel!=0);rez1=pl2.cel;
if( (pl2.ptrtype!=ptrtree) && success1 ) next(&pl2);
loc6 .sa=rez1; 
if( !success1 ) goto _L108;

/* CALL #L */ 
pl7.ptrtype=packedlist;pl7.nel=1;pl7.cel=loc6.sa;
pl7.plistsize= 1;
r41(&wrk1.sa,&flag1,&pl7);/* #G_wyravenie*/ ;xxx; 

/* operator := */ 
selop( acnst[ 19 ],false,NULL, loc6 .sa ,& wrk1 .sa); 
loc5 .sa= wrk1 .sa ;xxx; 
goto _L109/*uspeh*/;
_L108:; 
pl2=pl6;
goto  _L110;
_L109:;/*uspeh alxtern.*/
goto _L111/*uspeh*/;
_L110:; 
pl2=pl3;
goto  _L122;
_L111:;/*uspeh alxtern.*/

outxt(acnst[ 15 ], loc2 .sa , true, true); 
outatm(acnst[15],"=",false, true); 
outxt(acnst[ 15 ], loc5 .sa , false, true); 
outatm(acnst[15],";",false, true); ;xxx; 
selop(acnst[72],false,0L,pl1.cel,&rez1);pl2.cel=rez1;
   if( rez1==NULL ) { success1=false;goto _L122;};

/* shablon treemain */ rez1=pl2.cel;
success1=false;if(pl2.nel==0 ) goto _L122; 
 if (rez1!=NULL ) { pointr(rez1,&x.sa); 
       if (x.smld->dtype!= treemain )  
        { rez1=NULL;goto _L122;};
;}; 
pl7.nel=1;pl7.ptrtype=ptrtree;
success1=true; 
selop(acnst[39],false,0L,pl2.cel,&rez1);pl7.cel=rez1;
   if( rez1==NULL ) { success1=false;goto _L112;};

/* shablon listmain */ rez1=pl7.cel;
success1=false;if(pl7.nel==0 ) goto _L112; 
 if (rez1!=NULL ) { pointr(rez1,&x.sa); 
       if (x.smld->dtype!= listmain )  
        { rez1=NULL;goto _L112;};
{pl8.ptrtype=ptrlist; pl8.nel=1;
pl8.cel=x.smld->elt[0];pl8.UU.U1.curfragment=rez1;}
;} else  
{pl8.ptrtype=ptrlist;pl8.nel=0;pl8.cel=NULL;}

/*shablon STARLIST */ 
 pl9=pl8;while(pl8.nel!=0 ) { 

loc7 .sa=NULL; 

/* shablon prawila */ r40(&rez1,&success1,&pl8);
if( !success1 ) goto _L113;
loc7 .sa=rez1; 

loc8 .sa=NULL; 

/* shablon prawila */ r37(&rez1,&success1,&pl8);
if( !success1 ) goto _L113;
loc8 .sa=rez1; 

outatm(acnst[15],"addel(",true, true); 
outxt(acnst[ 15 ], loc7 .sa , false, true); 
outxt(acnst[ 15 ], loc8 .sa , false, true); 
outatm(acnst[15],",&",false, true); 
outxt(acnst[ 15 ], loc5 .sa , false, true); 
outatm(acnst[15],".sa);",false, true); ;xxx; 
 pl9=pl8;
;}; 
_L113:if( ! success1 )pl8=pl9;
success1 = true ; 

if( pl8.nel !=0 )
{ success1=false;rez1=NULL;goto _L112;};
success1=true;rez1=pl7.cel;
 if( pl7.ptrtype!=ptrtree ) next(&pl7);
_L112:success1=true;
if( success1 ) {
 rez1=pl2.cel;if( pl2.ptrtype!=ptrtree ) next(&pl2) ;}
 else { rez1=NULL;goto _L122 ;};
selop(acnst[68],false,0L,pl1.cel,&rez1);pl2.cel=rez1;
   if( rez1==NULL ) { success1=false;goto _L122;};

/* Alternative pattern */ 
pl7=pl2;
/* nonatomic alternative branches */ 

/* Alternative pattern */ 
pl8=pl2;

/* shablon treemain */ rez1=pl2.cel;
success1=false;if(pl2.nel==0 ) goto _L114; 
 if (rez1!=NULL ) { pointr(rez1,&x.sa); 
       if (x.smld->dtype!= treemain )  
        { rez1=NULL;goto _L114;};
/* prowerka imeni */ 
success1=eqatom(x.smld->name,acnst[ 69 ]); 
if( ! success1 ) { rez1=NULL;goto _L114;};
;}; 
pl9.nel=1;pl9.ptrtype=ptrtree;
success1=true; 
selop(acnst[70],false,0L,pl2.cel,&rez1);pl9.cel=rez1;
   if( rez1==NULL ) { success1=false;goto _L114;};

/* shablon peremennoj */ 
success1=(pl9.nel!=0);rez1=pl9.cel;
if( (pl9.ptrtype!=ptrtree) && success1 ) next(&pl9);
loc1 .sa=rez1; 
if( !success1 ) goto _L114;
if( success1 ) {
 rez1=pl2.cel;if( pl2.ptrtype!=ptrtree ) next(&pl2) ;}
 else { rez1=NULL;goto _L114 ;};

outatm(acnst[15],"setind(",true, true); 
outxt(acnst[ 15 ], loc4 .sa , false, true); 
outxt(acnst[ 15 ], loc3 .sa , false, true); 
outatm(acnst[15],",",false, true); 
outxt(acnst[ 15 ], loc5 .sa , false, true); 
outatm(acnst[15],".sa)",false, true); ;xxx; 
goto _L115/*uspeh*/;
_L114:; 
pl2=pl8;
goto  _L116;
_L115:;/*uspeh alxtern.*/
goto _L121/*uspeh*/;
_L116:; 
pl2=pl7;

/* Alternative pattern */ 
pl9=pl2;

/* shablon treemain */ rez1=pl2.cel;
success1=false;if(pl2.nel==0 ) goto _L117; 
 if (rez1!=NULL ) { pointr(rez1,&x.sa); 
       if (x.smld->dtype!= treemain )  
        { rez1=NULL;goto _L117;};
/* prowerka imeni */ 
success1=eqatom(x.smld->name,acnst[ 73 ]); 
if( ! success1 ) { rez1=NULL;goto _L117;};
;}; 
pl10.nel=1;pl10.ptrtype=ptrtree;
success1=true; 
selop(acnst[70],false,0L,pl2.cel,&rez1);pl10.cel=rez1;
   if( rez1==NULL ) { success1=false;goto _L117;};

/* shablon peremennoj */ 
success1=(pl10.nel!=0);rez1=pl10.cel;
if( (pl10.ptrtype!=ptrtree) && success1 ) next(&pl10);
loc1 .sa=rez1; 
if( !success1 ) goto _L117;
if( success1 ) {
 rez1=pl2.cel;if( pl2.ptrtype!=ptrtree ) next(&pl2) ;}
 else { rez1=NULL;goto _L117 ;};

outatm(acnst[15],"if(",true, true); 
outxt(acnst[ 15 ], loc5 .sa , false, true); 
outatm(acnst[15],".sa==NULL )",false, true); 
outatm(acnst[15],"setsel(",false, true); 
outxt(acnst[ 15 ], loc4 .sa , false, true); 
outxt(acnst[ 15 ], loc3 .sa , false, true); 
outatm(acnst[15],",NULL)",false, true); ;xxx; 
goto _L118/*uspeh*/;
_L117:; 
pl2=pl9;
goto  _L119;
_L118:;/*uspeh alxtern.*/
goto _L121/*uspeh*/;
_L119:; 
pl2=pl7;

/* shablon peremennoj */ 
success1=(pl2.nel!=0);rez1=pl2.cel;
if( (pl2.ptrtype!=ptrtree) && success1 ) next(&pl2);
loc6 .sa=rez1; 
if( !success1 ) goto _L120;
goto _L121/*uspeh*/;
_L120:; 
pl2=pl7;
goto  _L122;
_L121:;/*uspeh alxtern.*/
if( success1 ) {
 rez1=pl1.cel;if( pl1.ptrtype!=ptrtree ) next(&pl1) ;}
 else { rez1=NULL;goto _L122 ;};
goto _L99;  _L122:;  /* metka wyhoda po neuspehu wetwi */

/* branch */ pl1=*pl;rez1=NULL;success1=true; 
/* inicializaciq peremennyh */ 
loc3.sa=NULL;/* $A1*/ 
loc4.sa=NULL;/* $A2*/ 
loc5.sa=NULL;/* $W*/ 
loc6.sa=NULL;/* $E1*/ 
loc9.sa=NULL;/* $E*/ 

/* shablon treemain */ rez1=pl1.cel;
success1=false;if(pl1.nel==0 ) goto _L133; 
 if (rez1!=NULL ) { pointr(rez1,&x.sa); 
       if (x.smld->dtype!= treemain )  
        { rez1=NULL;goto _L133;};
/* prowerka imeni */ 
success1=eqatom(x.smld->name,acnst[ 63 ]); 
if( ! success1 ) { rez1=NULL;goto _L133;};
;}; 
pl9.nel=1;pl9.ptrtype=ptrtree;
success1=true; 
selop(acnst[64],false,0L,pl1.cel,&rez1);pl9.cel=rez1;
   if( rez1==NULL ) { success1=false;goto _L133;};

/* shablon atoma */ atmpat(acnst[66],&pl9,&rez1,&success1);
if( !success1 ) goto _L133;
selop(acnst[72],false,0L,pl1.cel,&rez1);pl9.cel=rez1;
   if( rez1==NULL ) { success1=false;goto _L133;};

loc9 .sa=NULL; 

/* shablon prawila */ r37(&rez1,&success1,&pl9);
if( !success1 ) goto _L133;
loc9 .sa=rez1; 
selop(acnst[68],false,0L,pl1.cel,&rez1);pl9.cel=rez1;
   if( rez1==NULL ) { success1=false;goto _L133;};

/* Alternative pattern */ 
pl10=pl9;
/* nonatomic alternative branches */ 

/* Alternative pattern */ 
pl11=pl9;

/* shablon treemain */ rez1=pl9.cel;
success1=false;if(pl9.nel==0 ) goto _L123; 
 if (rez1!=NULL ) { pointr(rez1,&x.sa); 
       if (x.smld->dtype!= treemain )  
        { rez1=NULL;goto _L123;};
/* prowerka imeni */ 
success1=eqatom(x.smld->name,acnst[ 69 ]); 
if( ! success1 ) { rez1=NULL;goto _L123;};
;}; 
pl12.nel=1;pl12.ptrtype=ptrtree;
success1=true; 
selop(acnst[70],false,0L,pl9.cel,&rez1);pl12.cel=rez1;
   if( rez1==NULL ) { success1=false;goto _L123;};

loc3 .sa=NULL; 

/* shablon prawila */ r38(&rez1,&success1,&pl12);
if( !success1 ) goto _L123;
loc3 .sa=rez1; 
selop(acnst[71],false,0L,pl9.cel,&rez1);pl12.cel=rez1;
   if( rez1==NULL ) { success1=false;goto _L123;};

loc4 .sa=NULL; 

/* shablon prawila */ r39(&rez1,&success1,&pl12);
if( !success1 ) goto _L123;
loc4 .sa=rez1; 
selop(acnst[19],false,0L,pl9.cel,&rez1);pl12.cel=rez1;
   if( rez1==NULL ) { success1=false;goto _L123;};

/* shablon peremennoj */ 
success1=(pl12.nel!=0);rez1=pl12.cel;
if( (pl12.ptrtype!=ptrtree) && success1 ) next(&pl12);
loc5 .sa=rez1; 
if( !success1 ) goto _L123;
if( success1 ) {
 rez1=pl9.cel;if( pl9.ptrtype!=ptrtree ) next(&pl9) ;}
 else { rez1=NULL;goto _L123 ;};

outatm(acnst[15],"indxaddtre(",true, true); 
outxt(acnst[ 15 ], loc4 .sa , false, true); 
outxt(acnst[ 15 ], loc3 .sa , false, true); 
outatm(acnst[15],",",false, true); 
outxt(acnst[ 15 ], loc9 .sa , false, true); 
outatm(acnst[15],")",false, true); ;xxx; 
goto _L124/*uspeh*/;
_L123:; 
pl9=pl11;
goto  _L125;
_L124:;/*uspeh alxtern.*/
goto _L132/*uspeh*/;
_L125:; 
pl9=pl10;

/* Alternative pattern */ 
pl12=pl9;

/* shablon treemain */ rez1=pl9.cel;
success1=false;if(pl9.nel==0 ) goto _L126; 
 if (rez1!=NULL ) { pointr(rez1,&x.sa); 
       if (x.smld->dtype!= treemain )  
        { rez1=NULL;goto _L126;};
/* prowerka imeni */ 
success1=eqatom(x.smld->name,acnst[ 73 ]); 
if( ! success1 ) { rez1=NULL;goto _L126;};
;}; 
pl13.nel=1;pl13.ptrtype=ptrtree;
success1=true; 
selop(acnst[70],false,0L,pl9.cel,&rez1);pl13.cel=rez1;
   if( rez1==NULL ) { success1=false;goto _L126;};

loc3 .sa=NULL; 

/* shablon prawila */ r38(&rez1,&success1,&pl13);
if( !success1 ) goto _L126;
loc3 .sa=rez1; 
selop(acnst[71],false,0L,pl9.cel,&rez1);pl13.cel=rez1;
   if( rez1==NULL ) { success1=false;goto _L126;};

loc4 .sa=NULL; 

/* shablon prawila */ r40(&rez1,&success1,&pl13);
if( !success1 ) goto _L126;
loc4 .sa=rez1; 
selop(acnst[19],false,0L,pl9.cel,&rez1);pl13.cel=rez1;
   if( rez1==NULL ) { success1=false;goto _L126;};

/* shablon peremennoj */ 
success1=(pl13.nel!=0);rez1=pl13.cel;
if( (pl13.ptrtype!=ptrtree) && success1 ) next(&pl13);
loc5 .sa=rez1; 
if( !success1 ) goto _L126;
if( success1 ) {
 rez1=pl9.cel;if( pl9.ptrtype!=ptrtree ) next(&pl9) ;}
 else { rez1=NULL;goto _L126 ;};

outatm(acnst[15],"selop(",true, true); 
outxt(acnst[ 15 ], loc4 .sa , false, true); 
outxt(acnst[ 15 ], loc3 .sa , false, true); 
outatm(acnst[15],",&",false, true); 
outxt(acnst[ 15 ], loc5 .sa , false, true); 
outatm(acnst[15],".sa);",false, true); 
outatm(acnst[15],"addtre(&",false, true); 
outxt(acnst[ 15 ], loc5 .sa , false, true); 
outatm(acnst[15],".sa,",false, true); 
outxt(acnst[ 15 ], loc9 .sa , false, true); 
outatm(acnst[15],");",false, true); 
outatm(acnst[15],"if(",false, true); 
outxt(acnst[ 15 ], loc5 .sa , false, true); 
outatm(acnst[15],".sa==NULL )",false, true); 
outatm(acnst[15],"setsel(",false, true); 
outxt(acnst[ 15 ], loc4 .sa , false, true); 
outxt(acnst[ 15 ], loc3 .sa , false, true); 
outatm(acnst[15],",NULL)",false, true); ;xxx; 
goto _L127/*uspeh*/;
_L126:; 
pl9=pl12;
goto  _L128;
_L127:;/*uspeh alxtern.*/
goto _L132/*uspeh*/;
_L128:; 
pl9=pl10;

/* Alternative pattern */ 
pl13=pl9;

/* shablon peremennoj */ 
success1=(pl9.nel!=0);rez1=pl9.cel;
if( (pl9.ptrtype!=ptrtree) && success1 ) next(&pl9);
loc6 .sa=rez1; 
if( !success1 ) goto _L129;

/* CALL #L */ 
pl14.ptrtype=packedlist;pl14.nel=1;pl14.cel=loc6.sa;
pl14.plistsize= 1;
r41(&wrk1.sa,&flag1,&pl14);/* #G_wyravenie*/ ;xxx; 

outatm(acnst[15],"addtre(&",true, true); 
selop( acnst[ 19 ],false,NULL, loc6 .sa ,& wrk1 .sa); 
outxt(acnst[ 15 ], wrk1 .sa , false, true); 
outatm(acnst[15],".sa,",false, true); 
outxt(acnst[ 15 ], loc9 .sa , false, true); 
outatm(acnst[15],")",false, true); ;xxx; 
goto _L130/*uspeh*/;
_L129:; 
pl9=pl13;
goto  _L131;
_L130:;/*uspeh alxtern.*/
goto _L132/*uspeh*/;
_L131:; 
pl9=pl10;
goto  _L133;
_L132:;/*uspeh alxtern.*/
if( success1 ) {
 rez1=pl1.cel;if( pl1.ptrtype!=ptrtree ) next(&pl1) ;}
 else { rez1=NULL;goto _L133 ;};
goto _L99;  _L133:;  /* metka wyhoda po neuspehu wetwi */
 _L99: rez1=NULL; 
 _L98: *rez=rez1;*success=success1; 
 if (*success) *pl=pl1; /* prodwinutx ukazatelx leksem */ 
/* wosstanowitx GLOB */ 
#ifdef XX  
 d(2,"G_ALONGTREE", 36 ,*rez,*success); 
#endif 
;};/* RULE */ 
/*===============================================*/ 
/* GENERATED TEXT OF RULE   #obqzatelxno_obxekt   */ 
 Void r37(rez,success,pl)
long *rez;boolean *success;ptr_ *pl; 
{  a rez1;  boolean success1; long k; mpd x; 
v loc1;/* $E*/ 
v loc2;/* $M*/ 
v wrk1;
v wrk2;
v wrk3;
ptr_ pl1;
ptr_ pl2;
boolean flag1;
#ifdef XX  
 d(1,"obqzatelxno_obxekt", 37 ,pl->cel,0); 
#endif 
/* sohranitx GLOB */ 

/* branch */ pl1=*pl;rez1=NULL;success1=true; 
/* inicializaciq peremennyh */ 
loc1.sa=NULL;/* $E*/ 
loc2.sa=NULL;/* $M*/ 

/* shablon peremennoj */ 
success1=(pl1.nel!=0);rez1=pl1.cel;
if( (pl1.ptrtype!=ptrtree) && success1 ) next(&pl1);
loc1 .sa=rez1; 
if( !success1 ) goto _L102;

/* CALL #L */ 
pl2.ptrtype=packedlist;pl2.nel=1;pl2.cel=loc1.sa;
pl2.plistsize= 1;
r41(&wrk1.sa,&flag1,&pl2);/* #G_wyravenie*/ ;xxx; 

/* operator := */ 
selop( acnst[ 19 ],false,NULL, loc1 .sa ,& wrk1 .sa); 
loc2 .sa= wrk1 .sa ;xxx; 

/* IF-operator */ 
selop( acnst[ 17 ],false,NULL, loc1 .sa ,& wrk1 .sa); 
if( wrk1 .sa!=NULL) 
{ 
/* CALL #L */ 
pl2.ptrtype=packedlist;pl2.nel=1;pl2.cel=loc1.sa;
pl2.plistsize= 1;
r11(&wrk1.sa,&flag1,&pl2);/* #G_ATOM_FROM_REZ*/ ;xxx; 
/* RETURN-op. */ 
wrk2 .sa =NULL; 
selop( acnst[ 20 ],false,NULL, loc1 .sa ,& wrk1 .sa); 
lconc(& wrk2 .sa , wrk1 .sa ); 
lconc(& wrk2 .sa , cnst[18] .sa ); 
rez1 = wrk2 .sa ;goto _L98 ;xxx; 
goto _L101;
;} 
/* operaciq = */ wrk3 .bo= eqatom( loc2 .sa ,acnst[ 24 ]) ; 
if( wrk3 .bo) 
{ 
/* RETURN-op. */ 
rez1 = cnst[24] .sa ;goto _L98 ;xxx; 
goto _L101;
;} 
{ 
/* RETURN-op. */ 
wrk1 .sa =NULL; 
lconc(& wrk1 .sa , loc2 .sa ); 
lconc(& wrk1 .sa , cnst[18] .sa ); 
rez1 = wrk1 .sa ;goto _L98 ;xxx; 
;} 
_L101:;xxx; 
goto _L99;  _L102:;  /* metka wyhoda po neuspehu wetwi */
 _L99: rez1=NULL; 
 _L98: *rez=rez1;*success=success1; 
 if (*success) *pl=pl1; /* prodwinutx ukazatelx leksem */ 
/* wosstanowitx GLOB */ 
#ifdef XX  
 d(2,"obqzatelxno_obxekt", 37 ,*rez,*success); 
#endif 
;};/* RULE */ 
/*===============================================*/ 
/* GENERATED TEXT OF RULE   #obxekt_ili_NULL   */ 
 Void r38(rez,success,pl)
long *rez;boolean *success;ptr_ *pl; 
{  a rez1;  boolean success1; long k; mpd x; 
v loc1;/* $E*/ 
v loc2;/* $M*/ 
v wrk1;
v wrk2;
v wrk3;
ptr_ pl1;
ptr_ pl2;
boolean flag1;
#ifdef XX  
 d(1,"obxekt_ili_NULL", 38 ,pl->cel,0); 
#endif 
/* sohranitx GLOB */ 

/* branch */ pl1=*pl;rez1=NULL;success1=true; 
/* inicializaciq peremennyh */ 
loc1.sa=NULL;/* $E*/ 
loc2.sa=NULL;/* $M*/ 

/* shablon peremennoj */ 
success1=(pl1.nel!=0);rez1=pl1.cel;
if( (pl1.ptrtype!=ptrtree) && success1 ) next(&pl1);
loc1 .sa=rez1; 
if( !success1 ) goto _L102;

/* CALL #L */ 
pl2.ptrtype=packedlist;pl2.nel=1;pl2.cel=loc1.sa;
pl2.plistsize= 1;
r41(&wrk1.sa,&flag1,&pl2);/* #G_wyravenie*/ ;xxx; 

/* operator := */ 
selop( acnst[ 19 ],false,NULL, loc1 .sa ,& wrk1 .sa); 
loc2 .sa= wrk1 .sa ;xxx; 

/* IF-operator */ 
selop( acnst[ 17 ],false,NULL, loc1 .sa ,& wrk1 .sa); 
if( wrk1 .sa!=NULL ) wrk3 .bo=true; else { 
/* operaciq = */ wrk2 .bo= eqatom( loc2 .sa ,acnst[ 24 ]) ; wrk3 = wrk2 ;}; 
if( wrk3 .bo) 
{ 
/* RETURN-op. */ 
rez1 = cnst[24] .sa ;goto _L98 ;xxx; 
goto _L101;
;} 
{ 
/* RETURN-op. */ 
wrk1 .sa =NULL; 
lconc(& wrk1 .sa , loc2 .sa ); 
lconc(& wrk1 .sa , cnst[18] .sa ); 
rez1 = wrk1 .sa ;goto _L98 ;xxx; 
;} 
_L101:;xxx; 
goto _L99;  _L102:;  /* metka wyhoda po neuspehu wetwi */
 _L99: rez1=NULL; 
 _L98: *rez=rez1;*success=success1; 
 if (*success) *pl=pl1; /* prodwinutx ukazatelx leksem */ 
/* wosstanowitx GLOB */ 
#ifdef XX  
 d(2,"obxekt_ili_NULL", 38 ,*rez,*success); 
#endif 
;};/* RULE */ 
/*===============================================*/ 
/* GENERATED TEXT OF RULE   #INTEGER_ili_obxekt   */ 
 Void r39(rez,success,pl)
long *rez;boolean *success;ptr_ *pl; 
{  a rez1;  boolean success1; long k; mpd x; 
v loc1;/* $E*/ 
v loc2;/* $M*/ 
v loc3;/* $T*/ 
v wrk1;
v wrk2;
v wrk3;
ptr_ pl1;
ptr_ pl2;
boolean flag1;
#ifdef XX  
 d(1,"INTEGER_ili_obxekt", 39 ,pl->cel,0); 
#endif 
/* sohranitx GLOB */ 

/* branch */ pl1=*pl;rez1=NULL;success1=true; 
/* inicializaciq peremennyh */ 
loc1.sa=NULL;/* $E*/ 
loc2.sa=NULL;/* $M*/ 
loc3.sa=NULL;/* $T*/ 

/* shablon peremennoj */ 
success1=(pl1.nel!=0);rez1=pl1.cel;
if( (pl1.ptrtype!=ptrtree) && success1 ) next(&pl1);
loc1 .sa=rez1; 
if( !success1 ) goto _L102;

/* CALL #L */ 
pl2.ptrtype=packedlist;pl2.nel=1;pl2.cel=loc1.sa;
pl2.plistsize= 1;
r41(&wrk1.sa,&flag1,&pl2);/* #G_wyravenie*/ ;xxx; 

/* operator := */ 
selop( acnst[ 19 ],false,NULL, loc1 .sa ,& wrk1 .sa); 
loc2 .sa= wrk1 .sa ;xxx; 

/* operator := */ 
selop( acnst[ 17 ],false,NULL, loc1 .sa ,& wrk1 .sa); 
loc3 .sa= wrk1 .sa ;xxx; 

/* IF-operator */ 
/* operaciq = */ wrk1 .bo= eqatom( loc3 .sa ,acnst[ 21 ]) ; 
if( !( wrk1 .bo )) wrk3 .bo=false; else { 
bltin(&wrk2,&flag1,loc2.sa,4L); wrk3 .bo= wrk2 .sa!=NULL ;}/*log*/; 
if( wrk3 .bo) 
{ 
/* RETURN-op. */ 
wrk1 .sa=NULL; 
lconc(& wrk1 .sa , loc2 .sa ); 
lconc(& wrk1 .sa , cnst[32] .sa ); 
first(wrk1.sa,&pl2);implod(&pl2,&wrk1.sa); 
rez1 = wrk1 .sa ;goto _L98 ;xxx; 
goto _L101;
;} 
/* operaciq = */ wrk2 .bo= eqatom( loc3 .sa ,acnst[ 21 ]) ; 
if( wrk2 .bo) 
{ 
/* RETURN-op. */ 
wrk1 .sa =NULL; 
lconc(& wrk1 .sa , loc2 .sa ); 
lconc(& wrk1 .sa , cnst[33] .sa ); 
rez1 = wrk1 .sa ;goto _L98 ;xxx; 
goto _L101;
;} 
if( loc3 .sa!=NULL ) wrk3 .bo=true; else { 
/* operaciq = */ wrk2 .bo= eqatom( loc2 .sa ,acnst[ 24 ]) ; wrk3 = wrk2 ;}; 
if( wrk3 .bo) 
{ 
/* RETURN-op. */ 
rez1 = cnst[34] .sa ;goto _L98 ;xxx; 
goto _L101;
;} 
{ 
/* RETURN-op. */ 
wrk1 .sa =NULL; 
lconc(& wrk1 .sa , cnst[35] .sa ); 
lconc(& wrk1 .sa , loc2 .sa ); 
lconc(& wrk1 .sa , cnst[36] .sa ); 
rez1 = wrk1 .sa ;goto _L98 ;xxx; 
;} 
_L101:;xxx; 
goto _L99;  _L102:;  /* metka wyhoda po neuspehu wetwi */
 _L99: rez1=NULL; 
 _L98: *rez=rez1;*success=success1; 
 if (*success) *pl=pl1; /* prodwinutx ukazatelx leksem */ 
/* wosstanowitx GLOB */ 
#ifdef XX  
 d(2,"INTEGER_ili_obxekt", 39 ,*rez,*success); 
#endif 
;};/* RULE */ 
/*===============================================*/ 
/* GENERATED TEXT OF RULE   #ACONST_ili_obxekt   */ 
 Void r40(rez,success,pl)
long *rez;boolean *success;ptr_ *pl; 
{  a rez1;  boolean success1; long k; mpd x; 
v loc1;/* $E*/ 
v loc2;/* $M*/ 
v loc3;/* $T*/ 
v loc4;/* $A*/ 
v wrk1;
v wrk2;
v wrk3;
ptr_ pl1;
ptr_ pl2;
boolean flag1;
#ifdef XX  
 d(1,"ACONST_ili_obxekt", 40 ,pl->cel,0); 
#endif 
/* sohranitx GLOB */ 

/* branch */ pl1=*pl;rez1=NULL;success1=true; 
/* inicializaciq peremennyh */ 
loc1.sa=NULL;/* $E*/ 
loc2.sa=NULL;/* $M*/ 
loc3.sa=NULL;/* $T*/ 
loc4.sa=NULL;/* $A*/ 

/* shablon peremennoj */ 
success1=(pl1.nel!=0);rez1=pl1.cel;
if( (pl1.ptrtype!=ptrtree) && success1 ) next(&pl1);
loc1 .sa=rez1; 
if( !success1 ) goto _L102;

/* CALL #L */ 
pl2.ptrtype=packedlist;pl2.nel=1;pl2.cel=loc1.sa;
pl2.plistsize= 1;
r41(&wrk1.sa,&flag1,&pl2);/* #G_wyravenie*/ ;xxx; 

/* operator := */ 
selop( acnst[ 19 ],false,NULL, loc1 .sa ,& wrk1 .sa); 
loc2 .sa= wrk1 .sa ;xxx; 

/* operator := */ 
selop( acnst[ 17 ],false,NULL, loc1 .sa ,& wrk1 .sa); 
loc3 .sa= wrk1 .sa ;xxx; 

/* operator := */ 
selop( acnst[ 10 ],false,NULL, loc1 .sa ,& wrk1 .sa); 
loc4 .sa= wrk1 .sa ;xxx; 

/* IF-operator */ 
if( loc4 .sa!=NULL) 
{ 
/* RETURN-op. */ 
wrk1 .sa =NULL; 
lconc(& wrk1 .sa , cnst[37] .sa ); 
lconc(& wrk1 .sa , loc4 .sa ); 
lconc(& wrk1 .sa , cnst[38] .sa ); 
rez1 = wrk1 .sa ;goto _L98 ;xxx; 
goto _L101;
;} 
if( loc3 .sa!=NULL) 
{ 
/* CALL #L */ 
pl2.ptrtype=packedlist;pl2.nel=1;pl2.cel=loc1.sa;
pl2.plistsize= 1;
r11(&wrk1.sa,&flag1,&pl2);/* #G_ATOM_FROM_REZ*/ ;xxx; 
/* RETURN-op. */ 
wrk2 .sa =NULL; 
lconc(& wrk2 .sa , cnst[35] .sa ); 
selop( acnst[ 20 ],false,NULL, loc1 .sa ,& wrk1 .sa); 
lconc(& wrk2 .sa , wrk1 .sa ); 
lconc(& wrk2 .sa , cnst[36] .sa ); 
rez1 = wrk2 .sa ;goto _L98 ;xxx; 
goto _L101;
;} 
/* operaciq = */ wrk3 .bo= eqatom( loc2 .sa ,acnst[ 24 ]) ; 
if( wrk3 .bo) 
{ 
/* RETURN-op. */ 
rez1 = cnst[34] .sa ;goto _L98 ;xxx; 
goto _L101;
;} 
{ 
/* RETURN-op. */ 
wrk1 .sa =NULL; 
lconc(& wrk1 .sa , cnst[35] .sa ); 
lconc(& wrk1 .sa , loc2 .sa ); 
lconc(& wrk1 .sa , cnst[36] .sa ); 
rez1 = wrk1 .sa ;goto _L98 ;xxx; 
;} 
_L101:;xxx; 
goto _L99;  _L102:;  /* metka wyhoda po neuspehu wetwi */
 _L99: rez1=NULL; 
 _L98: *rez=rez1;*success=success1; 
 if (*success) *pl=pl1; /* prodwinutx ukazatelx leksem */ 
/* wosstanowitx GLOB */ 
#ifdef XX  
 d(2,"ACONST_ili_obxekt", 40 ,*rez,*success); 
#endif 
;};/* RULE */ 
