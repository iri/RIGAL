
#include "globrig.h" 
#include "define.h"  
#include "defpage.h" 
#include "nef2.h"    
#include "c1.h"      
#include "usemod.h"  
#include "def180.h"  
#include "xcrg.h"    
/*  R41 G_wyravenie */ 
/*  R42 G_AND */ 
/*  R43 G_OR */ 
/*  R44 IS_CONSTRUCTOR */ 
/*  R45 CONLIST */ 
/*  R46 G_EQOP */ 
/*  R47 mesto */ 
/*  R48 ~islo_ili_0 */ 
/*===============================================*/ 
/* GENERATED TEXT OF RULE   #G_wyravenie   */ 
 Void r41(rez,success,pl)
long *rez;boolean *success;ptr_ *pl; 
{  a rez1;  boolean success1; long k; mpd x; 
v loc0;/* $_*/ 
v loc1;/* $ID*/ 
v loc2;/* $X*/ 
v loc3;/* $mesto*/ 
v loc4;/* $ID1*/ 
v loc5;/* $REZ*/ 
v loc6;/* $E1*/ 
v loc7;/* $E2*/ 
v loc8;/* $WRK*/ 
v loc9;/* $E*/ 
v loc10;/* $EL*/ 
v loc11;/* $E22*/ 
v loc12;/* $EL2*/ 
v loc13;/* $OP*/ 
v loc14;/* $tip*/ 
v loc15;/* $E11*/ 
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
v wrk15;
v wrk16;
v wrk17;
ptr_ pl1;
ptr_ pl2;
ptr_ pl3;
ptr_ pl4;
ptr_ pl5;
ptr_ pl6;
ptr_ pl7;
ptr_ pl8;
boolean flag1;
#ifdef XX  
 d(1,"G_wyravenie", 41 ,pl->cel,0); 
#endif 
/* sohranitx GLOB */ 
loc0.sa=pl->cel; 

/* branch */ pl1=*pl;rez1=NULL;success1=true; 
/* inicializaciq peremennyh */ 
loc1.sa=NULL;/* $ID*/ 
loc2.sa=NULL;/* $X*/ 
loc3.sa=NULL;/* $mesto*/ 

/* shablon treemain */ rez1=pl1.cel;
success1=false;if(pl1.nel==0 ) goto _L102; 
 if (rez1!=NULL ) { pointr(rez1,&x.sa); 
       if (x.smld->dtype!= treemain )  
        { rez1=NULL;goto _L102;};
/* prowerka imeni */ 
success1=eqatom(x.smld->name,acnst[ 41 ]); 
if( ! success1 ) { rez1=NULL;goto _L102;};
;}; 
pl2.nel=1;pl2.ptrtype=ptrtree;
success1=true; 
selop(acnst[26],false,0L,pl1.cel,&rez1);pl2.cel=rez1;
   if( rez1==NULL ) { success1=false;goto _L102;};

/* shablon peremennoj */ 
varpat(&pl2,idatom,&rez1,&success1);
loc1 .sa=rez1; 
if( !success1 ) goto _L102;
if( success1 ) {
 rez1=pl1.cel;if( pl1.ptrtype!=ptrtree ) next(&pl1) ;}
 else { rez1=NULL;goto _L102 ;};

/* operator := */ 
selop( 0L,true, glob24_2 .sa, glob1_2 .sa ,& wrk1 .sa); 
selop( 0L,true, loc1 .sa, wrk1 .sa ,& wrk2 .sa); 
loc2 .sa= wrk2 .sa ;xxx; 

/* IF-operator */ 
if( loc2 .sa!=NULL) 
{ 
/* operator := */ 
wrk2 .sa=NULL; 
lconc(& wrk2 .sa , cnst[39] .sa ); 
selop( 0L,true, glob24_2 .sa, glob1_3 .sa ,& wrk1 .sa); 
lconc(& wrk2 .sa , wrk1 .sa ); 
lconc(& wrk2 .sa , cnst[40] .sa ); 
lconc(& wrk2 .sa , loc2 .sa ); 
first(wrk2.sa,&pl2);implod(&pl2,&wrk2.sa); 
loc3 .sa= wrk2 .sa ;xxx; 
goto _L101;
;} 
{ 
/* operator := */ 
wrk3 .sa=NULL; 
lconc(& wrk3 .sa , cnst[41] .sa ); 
selop( 0L,true, glob24_2 .sa, glob1_1 .sa ,& wrk1 .sa); 
selop( 0L,true, loc1 .sa, wrk1 .sa ,& wrk2 .sa); 
lconc(& wrk3 .sa , wrk2 .sa ); 
first(wrk3.sa,&pl2);implod(&pl2,&wrk3.sa); 
loc3 .sa= wrk3 .sa ;xxx; 
;} 
_L101:;xxx; 

/* operator ++:= */ 
wrk1 = loc0 ; 
addel( acnst[ 19 ],false,NULL, loc3 .sa ,& loc0 .sa); ;xxx; 
goto _L99;  _L102:;  /* metka wyhoda po neuspehu wetwi */

/* branch */ pl1=*pl;rez1=NULL;success1=true; 
/* inicializaciq peremennyh */ 

/* shablon treemain */ rez1=pl1.cel;
success1=false;if(pl1.nel==0 ) goto _L104; 
 if (rez1!=NULL ) { pointr(rez1,&x.sa); 
       if (x.smld->dtype!= treemain )  
        { rez1=NULL;goto _L104;};
/* prowerka imeni */ 
success1=eqatom(x.smld->name,acnst[ 78 ]); 
if( ! success1 ) { rez1=NULL;goto _L104;};
;}; 
pl2.nel=1;pl2.ptrtype=ptrtree;
success1=true; 
selop(acnst[51],false,0L,pl1.cel,&rez1);pl2.cel=rez1;
   if( rez1==NULL ) { success1=false;goto _L103;};

/* shablon peremennoj */ 
success1=(pl2.nel!=0);rez1=pl2.cel;
if( (pl2.ptrtype!=ptrtree) && success1 ) next(&pl2);
loc2 .sa=rez1; 
if( !success1 ) goto _L103;
_L103:success1=true;
if( success1 ) {
 rez1=pl1.cel;if( pl1.ptrtype!=ptrtree ) next(&pl1) ;}
 else { rez1=NULL;goto _L104 ;};
goto _L99;  _L104:;  /* metka wyhoda po neuspehu wetwi */

/* branch */ pl1=*pl;rez1=NULL;success1=true; 
/* inicializaciq peremennyh */ 
loc1.sa=NULL;/* $ID*/ 
loc3.sa=NULL;/* $mesto*/ 
loc4.sa=NULL;/* $ID1*/ 

/* shablon treemain */ rez1=pl1.cel;
success1=false;if(pl1.nel==0 ) goto _L105; 
 if (rez1!=NULL ) { pointr(rez1,&x.sa); 
       if (x.smld->dtype!= treemain )  
        { rez1=NULL;goto _L105;};
/* prowerka imeni */ 
success1=eqatom(x.smld->name,acnst[ 79 ]); 
if( ! success1 ) { rez1=NULL;goto _L105;};
;}; 
pl2.nel=1;pl2.ptrtype=ptrtree;
success1=true; 
selop(acnst[80],false,0L,pl1.cel,&rez1);pl2.cel=rez1;
   if( rez1==NULL ) { success1=false;goto _L105;};

/* shablon peremennoj */ 
varpat(&pl2,idatom,&rez1,&success1);
loc1 .sa=rez1; 
if( !success1 ) goto _L105;
selop(acnst[41],false,0L,pl1.cel,&rez1);pl2.cel=rez1;
   if( rez1==NULL ) { success1=false;goto _L105;};

/* shablon peremennoj */ 
varpat(&pl2,idatom,&rez1,&success1);
loc4 .sa=rez1; 
if( !success1 ) goto _L105;
if( success1 ) {
 rez1=pl1.cel;if( pl1.ptrtype!=ptrtree ) next(&pl1) ;}
 else { rez1=NULL;goto _L105 ;};

/* operator := */ 
wrk4 .sa=NULL; 
lconc(& wrk4 .sa , cnst[39] .sa ); 
selop( 0L,true, loc1 .sa, glob1_3 .sa ,& wrk1 .sa); 
lconc(& wrk4 .sa , wrk1 .sa ); 
lconc(& wrk4 .sa , cnst[40] .sa ); 
selop( 0L,true, loc1 .sa, glob1_2 .sa ,& wrk2 .sa); 
selop( 0L,true, loc4 .sa, wrk2 .sa ,& wrk3 .sa); 
lconc(& wrk4 .sa , wrk3 .sa ); 
first(wrk4.sa,&pl2);implod(&pl2,&wrk4.sa); 
loc3 .sa= wrk4 .sa ;xxx; 

/* operator ++:= */ 
wrk1 = loc0 ; 
addel( acnst[ 19 ],false,NULL, loc3 .sa ,& loc0 .sa); ;xxx; 
goto _L99;  _L105:;  /* metka wyhoda po neuspehu wetwi */

/* branch */ pl1=*pl;rez1=NULL;success1=true; 
/* inicializaciq peremennyh */ 
loc2.sa=NULL;/* $X*/ 
loc5.sa=NULL;/* $REZ*/ 

/* shablon treemain */ rez1=pl1.cel;
success1=false;if(pl1.nel==0 ) goto _L107; 
 if (rez1!=NULL ) { pointr(rez1,&x.sa); 
       if (x.smld->dtype!= treemain )  
        { rez1=NULL;goto _L107;};
/* prowerka imeni */ 
success1=eqatom(x.smld->name,acnst[ 76 ]); 
if( ! success1 ) { rez1=NULL;goto _L107;};
;}; 
pl2.nel=1;pl2.ptrtype=ptrtree;
success1=true; 
selop(acnst[19],false,0L,pl1.cel,&rez1);pl2.cel=rez1;
   if( rez1==NULL ) { success1=false;goto _L107;};

/* shablon peremennoj */ 
success1=(pl2.nel!=0);rez1=pl2.cel;
if( (pl2.ptrtype!=ptrtree) && success1 ) next(&pl2);
loc5 .sa=rez1; 
if( !success1 ) goto _L107;

/* operator := */ 
wrk1 .sa =NULL; 
lconc(& wrk1 .sa , loc5 .sa ); 
lconc(& wrk1 .sa , cnst[18] .sa ); 
loc5 .sa= wrk1 .sa ;xxx; 

outxt(acnst[ 15 ], loc5 .sa , true, true); 
outatm(acnst[15],"=NULL;",false, true); ;xxx; 
selop(acnst[39],false,0L,pl1.cel,&rez1);pl2.cel=rez1;
   if( rez1==NULL ) { success1=false;goto _L106;};

/* shablon peremennoj */ 
success1=(pl2.nel!=0);rez1=pl2.cel;
if( (pl2.ptrtype!=ptrtree) && success1 ) next(&pl2);
loc2 .sa=rez1; 
if( !success1 ) goto _L106;

/* CALL #L */ 
pl3.ptrtype=packedlist;pl3.nel=1;pl3.cel=loc5.sa;
pl3.UU.plistelt[ 0 ]=loc2.sa;
pl3.plistsize= 2;
r45(&wrk1.sa,&flag1,&pl3);/* #CONLIST*/ ;xxx; 
_L106:success1=true;
if( success1 ) {
 rez1=pl1.cel;if( pl1.ptrtype!=ptrtree ) next(&pl1) ;}
 else { rez1=NULL;goto _L107 ;};
goto _L99;  _L107:;  /* metka wyhoda po neuspehu wetwi */

/* branch */ pl1=*pl;rez1=NULL;success1=true; 
/* inicializaciq peremennyh */ 
loc5.sa=NULL;/* $REZ*/ 
loc6.sa=NULL;/* $E1*/ 
loc7.sa=NULL;/* $E2*/ 

/* shablon treemain */ rez1=pl1.cel;
success1=false;if(pl1.nel==0 ) goto _L110; 
 if (rez1!=NULL ) { pointr(rez1,&x.sa); 
       if (x.smld->dtype!= treemain )  
        { rez1=NULL;goto _L110;};
/* prowerka imeni */ 
success1=eqatom(x.smld->name,acnst[ 77 ]); 
if( ! success1 ) { rez1=NULL;goto _L110;};
;}; 
pl2.nel=1;pl2.ptrtype=ptrtree;
success1=true; 
selop(acnst[19],false,0L,pl1.cel,&rez1);pl2.cel=rez1;
   if( rez1==NULL ) { success1=false;goto _L110;};

/* shablon peremennoj */ 
success1=(pl2.nel!=0);rez1=pl2.cel;
if( (pl2.ptrtype!=ptrtree) && success1 ) next(&pl2);
loc5 .sa=rez1; 
if( !success1 ) goto _L110;

/* operator := */ 
wrk1 .sa =NULL; 
lconc(& wrk1 .sa , loc5 .sa ); 
lconc(& wrk1 .sa , cnst[18] .sa ); 
loc5 .sa= wrk1 .sa ;xxx; 

outxt(acnst[ 15 ], loc5 .sa , true, true); 
outatm(acnst[15],"=NULL;",false, true); ;xxx; 
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

loc6 .sa=NULL; 

/* shablon prawila */ r40(&rez1,&success1,&pl3);
if( !success1 ) goto _L109;
loc6 .sa=rez1; 

loc7 .sa=NULL; 

/* shablon prawila */ r37(&rez1,&success1,&pl3);
if( !success1 ) goto _L109;
loc7 .sa=rez1; 

outatm(acnst[15],"addel(",true, true); 
outxt(acnst[ 15 ], loc6 .sa , false, true); 
outxt(acnst[ 15 ], loc7 .sa , false, true); 
outatm(acnst[15],",&",false, true); 
outxt(acnst[ 15 ], loc5 .sa , false, true); 
outatm(acnst[15],");",false, true); ;xxx; 
 pl4=pl3;
;}; 
_L109:if( ! success1 )pl3=pl4;
success1 = true ; 

if( pl3.nel !=0 )
{ success1=false;rez1=NULL;goto _L108;};
success1=true;rez1=pl2.cel;
 if( pl2.ptrtype!=ptrtree ) next(&pl2);
_L108:success1=true;
if( success1 ) {
 rez1=pl1.cel;if( pl1.ptrtype!=ptrtree ) next(&pl1) ;}
 else { rez1=NULL;goto _L110 ;};
goto _L99;  _L110:;  /* metka wyhoda po neuspehu wetwi */

/* branch */ pl1=*pl;rez1=NULL;success1=true; 
/* inicializaciq peremennyh */ 
loc6.sa=NULL;/* $E1*/ 
loc7.sa=NULL;/* $E2*/ 
loc8.sa=NULL;/* $WRK*/ 

/* shablon treemain */ rez1=pl1.cel;
success1=false;if(pl1.nel==0 ) goto _L111; 
 if (rez1!=NULL ) { pointr(rez1,&x.sa); 
       if (x.smld->dtype!= treemain )  
        { rez1=NULL;goto _L111;};
/* prowerka imeni */ 
success1=eqatom(x.smld->name,acnst[ 69 ]); 
if( ! success1 ) { rez1=NULL;goto _L111;};
;}; 
pl2.nel=1;pl2.ptrtype=ptrtree;
success1=true; 
selop(acnst[70],false,0L,pl1.cel,&rez1);pl2.cel=rez1;
   if( rez1==NULL ) { success1=false;goto _L111;};

/* shablon peremennoj */ 
success1=(pl2.nel!=0);rez1=pl2.cel;
if( (pl2.ptrtype!=ptrtree) && success1 ) next(&pl2);
loc6 .sa=rez1; 
if( !success1 ) goto _L111;

/* operator := */ 
/* CALL #L */ 
pl3.ptrtype=packedlist;pl3.nel=1;pl3.cel=loc6.sa;
pl3.plistsize= 1;
r38(&wrk1.sa,&flag1,&pl3);/* #obxekt_ili_NULL*/ ; 
loc6 .sa= wrk1 .sa ;xxx; 
selop(acnst[71],false,0L,pl1.cel,&rez1);pl2.cel=rez1;
   if( rez1==NULL ) { success1=false;goto _L111;};

/* shablon peremennoj */ 
success1=(pl2.nel!=0);rez1=pl2.cel;
if( (pl2.ptrtype!=ptrtree) && success1 ) next(&pl2);
loc7 .sa=rez1; 
if( !success1 ) goto _L111;

/* operator := */ 
/* CALL #L */ 
pl3.ptrtype=packedlist;pl3.nel=1;pl3.cel=loc7.sa;
pl3.plistsize= 1;
r39(&wrk1.sa,&flag1,&pl3);/* #INTEGER_ili_obxekt*/ ; 
loc7 .sa= wrk1 .sa ;xxx; 
selop(acnst[19],false,0L,pl1.cel,&rez1);pl2.cel=rez1;
   if( rez1==NULL ) { success1=false;goto _L111;};

/* shablon peremennoj */ 
success1=(pl2.nel!=0);rez1=pl2.cel;
if( (pl2.ptrtype!=ptrtree) && success1 ) next(&pl2);
loc8 .sa=rez1; 
if( !success1 ) goto _L111;
if( success1 ) {
 rez1=pl1.cel;if( pl1.ptrtype!=ptrtree ) next(&pl1) ;}
 else { rez1=NULL;goto _L111 ;};

outatm(acnst[15],"indxop(",true, true); 
outxt(acnst[ 15 ], loc7 .sa , false, true); 
outxt(acnst[ 15 ], loc6 .sa , false, true); 
outatm(acnst[15],",&",false, true); 
outxt(acnst[ 15 ], loc8 .sa , false, true); 
outatm(acnst[15],".sa);",false, true); ;xxx; 
goto _L99;  _L111:;  /* metka wyhoda po neuspehu wetwi */

/* branch */ pl1=*pl;rez1=NULL;success1=true; 
/* inicializaciq peremennyh */ 
loc6.sa=NULL;/* $E1*/ 
loc7.sa=NULL;/* $E2*/ 
loc8.sa=NULL;/* $WRK*/ 

/* shablon treemain */ rez1=pl1.cel;
success1=false;if(pl1.nel==0 ) goto _L112; 
 if (rez1!=NULL ) { pointr(rez1,&x.sa); 
       if (x.smld->dtype!= treemain )  
        { rez1=NULL;goto _L112;};
/* prowerka imeni */ 
success1=eqatom(x.smld->name,acnst[ 73 ]); 
if( ! success1 ) { rez1=NULL;goto _L112;};
;}; 
pl2.nel=1;pl2.ptrtype=ptrtree;
success1=true; 
selop(acnst[70],false,0L,pl1.cel,&rez1);pl2.cel=rez1;
   if( rez1==NULL ) { success1=false;goto _L112;};

loc6 .sa=NULL; 

/* shablon prawila */ r38(&rez1,&success1,&pl2);
if( !success1 ) goto _L112;
loc6 .sa=rez1; 
selop(acnst[71],false,0L,pl1.cel,&rez1);pl2.cel=rez1;
   if( rez1==NULL ) { success1=false;goto _L112;};

loc7 .sa=NULL; 

/* shablon prawila */ r40(&rez1,&success1,&pl2);
if( !success1 ) goto _L112;
loc7 .sa=rez1; 
selop(acnst[19],false,0L,pl1.cel,&rez1);pl2.cel=rez1;
   if( rez1==NULL ) { success1=false;goto _L112;};

/* shablon peremennoj */ 
success1=(pl2.nel!=0);rez1=pl2.cel;
if( (pl2.ptrtype!=ptrtree) && success1 ) next(&pl2);
loc8 .sa=rez1; 
if( !success1 ) goto _L112;
if( success1 ) {
 rez1=pl1.cel;if( pl1.ptrtype!=ptrtree ) next(&pl1) ;}
 else { rez1=NULL;goto _L112 ;};

outatm(acnst[15],"selop(",true, true); 
outxt(acnst[ 15 ], loc7 .sa , false, true); 
outxt(acnst[ 15 ], loc6 .sa , false, true); 
outatm(acnst[15],",&",false, true); 
outxt(acnst[ 15 ], loc8 .sa , false, true); 
outatm(acnst[15],".sa);",false, true); ;xxx; 
goto _L99;  _L112:;  /* metka wyhoda po neuspehu wetwi */

/* branch */ pl1=*pl;rez1=NULL;success1=true; 
/* inicializaciq peremennyh */ 

/* shablon prawila */ r46(&rez1,&success1,&pl1);
if( !success1 ) goto _L113;
goto _L99;  _L113:;  /* metka wyhoda po neuspehu wetwi */

/* branch */ pl1=*pl;rez1=NULL;success1=true; 
/* inicializaciq peremennyh */ 

/* Alternative pattern */ 
pl2=pl1;
/* nonatomic alternative branches */ 

/* shablon prawila */ r19(&rez1,&success1,&pl1);
if( !success1 ) goto _L114;
goto _L116/*uspeh*/;
_L114:; 
pl1=pl2;

/* shablon prawila */ r26(&rez1,&success1,&pl1);
if( !success1 ) goto _L115;
goto _L116/*uspeh*/;
_L115:; 
pl1=pl2;
goto  _L117;
_L116:;/*uspeh alxtern.*/

outatm(acnst[15],";",false, true); ;xxx; 
goto _L99;  _L117:;  /* metka wyhoda po neuspehu wetwi */

/* branch */ pl1=*pl;rez1=NULL;success1=true; 
/* inicializaciq peremennyh */ 
loc8.sa=NULL;/* $WRK*/ 
loc9.sa=NULL;/* $E*/ 

/* shablon treemain */ rez1=pl1.cel;
success1=false;if(pl1.nel==0 ) goto _L119; 
 if (rez1!=NULL ) { pointr(rez1,&x.sa); 
       if (x.smld->dtype!= treemain )  
        { rez1=NULL;goto _L119;};
/* prowerka imeni */ 
success1=eqatom(x.smld->name,acnst[ 81 ]); 
if( ! success1 ) { rez1=NULL;goto _L119;};
;}; 
pl2.nel=1;pl2.ptrtype=ptrtree;
success1=true; 
selop(acnst[47],false,0L,pl1.cel,&rez1);pl2.cel=rez1;
   if( rez1==NULL ) { success1=false;goto _L119;};

/* shablon peremennoj */ 
success1=(pl2.nel!=0);rez1=pl2.cel;
if( (pl2.ptrtype!=ptrtree) && success1 ) next(&pl2);
loc9 .sa=rez1; 
if( !success1 ) goto _L119;

/* CALL #L */ 
pl3.ptrtype=packedlist;pl3.nel=1;pl3.cel=loc9.sa;
pl3.plistsize= 1;
r41(&wrk1.sa,&flag1,&pl3);/* #G_wyravenie*/ ;xxx; 
selop(acnst[19],false,0L,pl1.cel,&rez1);pl2.cel=rez1;
   if( rez1==NULL ) { success1=false;goto _L119;};

/* shablon peremennoj */ 
success1=(pl2.nel!=0);rez1=pl2.cel;
if( (pl2.ptrtype!=ptrtree) && success1 ) next(&pl2);
loc8 .sa=rez1; 
if( !success1 ) goto _L119;
if( success1 ) {
 rez1=pl1.cel;if( pl1.ptrtype!=ptrtree ) next(&pl1) ;}
 else { rez1=NULL;goto _L119 ;};

outxt(acnst[ 15 ], loc8 .sa , true, true); 
outatm(acnst[15],".bo=",false, true); ;xxx; 

/* IF-operator */ 
selop( acnst[ 17 ],false,NULL, loc9 .sa ,& wrk1 .sa); 
/* operaciq = */ wrk2 .bo= eqatom( wrk1 .sa ,acnst[ 18 ]) ; 
if( wrk2 .bo) 
{ 
outatm(acnst[15],"!(",false, true); 
selop( acnst[ 19 ],false,NULL, loc9 .sa ,& wrk1 .sa); 
outxt(acnst[ 15 ], wrk1 .sa , false, true); 
outatm(acnst[15],".bo);",false, true); ;xxx; 
goto _L118;
;} 
selop( acnst[ 17 ],false,NULL, loc9 .sa ,& wrk1 .sa); 
if( wrk1 .sa!=NULL) 
{ 
outatm(acnst[15],"false;",false, true); ;xxx; 
goto _L118;
;} 
selop( acnst[ 19 ],false,NULL, loc9 .sa ,& wrk1 .sa); 
/* operaciq = */ wrk2 .bo= eqatom( wrk1 .sa ,acnst[ 24 ]) ; 
if( wrk2 .bo) 
{ 
outatm(acnst[15],"true;",false, true); ;xxx; 
goto _L118;
;} 
{ 
selop( acnst[ 19 ],false,NULL, loc9 .sa ,& wrk1 .sa); 
outxt(acnst[ 15 ], wrk1 .sa , false, true); 
outatm(acnst[15],".sa==NULL;",false, true); ;xxx; 
;} 
_L118:;xxx; 
goto _L99;  _L119:;  /* metka wyhoda po neuspehu wetwi */

/* branch */ pl1=*pl;rez1=NULL;success1=true; 
/* inicializaciq peremennyh */ 

/* Alternative pattern */ 
pl2=pl1;
/* nonatomic alternative branches */ 

/* shablon prawila */ r42(&rez1,&success1,&pl1);
if( !success1 ) goto _L120;
goto _L122/*uspeh*/;
_L120:; 
pl1=pl2;

/* shablon prawila */ r43(&rez1,&success1,&pl1);
if( !success1 ) goto _L121;
goto _L122/*uspeh*/;
_L121:; 
pl1=pl2;
goto  _L123;
_L122:;/*uspeh alxtern.*/
goto _L99;  _L123:;  /* metka wyhoda po neuspehu wetwi */

/* branch */ pl1=*pl;rez1=NULL;success1=true; 
/* inicializaciq peremennyh */ 
loc6.sa=NULL;/* $E1*/ 
loc7.sa=NULL;/* $E2*/ 
loc8.sa=NULL;/* $WRK*/ 

/* shablon treemain */ rez1=pl1.cel;
success1=false;if(pl1.nel==0 ) goto _L124; 
 if (rez1!=NULL ) { pointr(rez1,&x.sa); 
       if (x.smld->dtype!= treemain )  
        { rez1=NULL;goto _L124;};
/* prowerka imeni */ 
success1=eqatom(x.smld->name,acnst[ 82 ]); 
if( ! success1 ) { rez1=NULL;goto _L124;};
;}; 
pl2.nel=1;pl2.ptrtype=ptrtree;
success1=true; 
selop(acnst[70],false,0L,pl1.cel,&rez1);pl2.cel=rez1;
   if( rez1==NULL ) { success1=false;goto _L124;};

loc6 .sa=NULL; 

/* shablon prawila */ r38(&rez1,&success1,&pl2);
if( !success1 ) goto _L124;
loc6 .sa=rez1; 
selop(acnst[71],false,0L,pl1.cel,&rez1);pl2.cel=rez1;
   if( rez1==NULL ) { success1=false;goto _L124;};

loc7 .sa=NULL; 

/* shablon prawila */ r37(&rez1,&success1,&pl2);
if( !success1 ) goto _L124;
loc7 .sa=rez1; 
selop(acnst[19],false,0L,pl1.cel,&rez1);pl2.cel=rez1;
   if( rez1==NULL ) { success1=false;goto _L124;};

/* shablon peremennoj */ 
success1=(pl2.nel!=0);rez1=pl2.cel;
if( (pl2.ptrtype!=ptrtree) && success1 ) next(&pl2);
loc8 .sa=rez1; 
if( !success1 ) goto _L124;
if( success1 ) {
 rez1=pl1.cel;if( pl1.ptrtype!=ptrtree ) next(&pl1) ;}
 else { rez1=NULL;goto _L124 ;};

outxt(acnst[ 15 ], loc8 .sa , true, true); 
outatm(acnst[15],".sa=",false, true); 
outxt(acnst[ 15 ], loc6 .sa , false, true); 
outatm(acnst[15],";",false, true); 
outatm(acnst[15],"lconc(&",false, true); 
outxt(acnst[ 15 ], loc8 .sa , false, true); 
outatm(acnst[15],".sa,",false, true); 
outxt(acnst[ 15 ], loc7 .sa , false, true); 
outatm(acnst[15],");",false, true); ;xxx; 
goto _L99;  _L124:;  /* metka wyhoda po neuspehu wetwi */

/* branch */ pl1=*pl;rez1=NULL;success1=true; 
/* inicializaciq peremennyh */ 
loc6.sa=NULL;/* $E1*/ 
loc7.sa=NULL;/* $E2*/ 
loc8.sa=NULL;/* $WRK*/ 
loc10.sa=NULL;/* $EL*/ 
loc11.sa=NULL;/* $E22*/ 

/* shablon treemain */ rez1=pl1.cel;
success1=false;if(pl1.nel==0 ) goto _L129; 
 if (rez1!=NULL ) { pointr(rez1,&x.sa); 
       if (x.smld->dtype!= treemain )  
        { rez1=NULL;goto _L129;};
/* prowerka imeni */ 
success1=eqatom(x.smld->name,acnst[ 83 ]); 
if( ! success1 ) { rez1=NULL;goto _L129;};
;}; 
pl2.nel=1;pl2.ptrtype=ptrtree;
success1=true; 
selop(acnst[70],false,0L,pl1.cel,&rez1);pl2.cel=rez1;
   if( rez1==NULL ) { success1=false;goto _L129;};

loc6 .sa=NULL; 

/* shablon prawila */ r38(&rez1,&success1,&pl2);
if( !success1 ) goto _L129;
loc6 .sa=rez1; 
selop(acnst[19],false,0L,pl1.cel,&rez1);pl2.cel=rez1;
   if( rez1==NULL ) { success1=false;goto _L129;};

/* shablon peremennoj */ 
success1=(pl2.nel!=0);rez1=pl2.cel;
if( (pl2.ptrtype!=ptrtree) && success1 ) next(&pl2);
loc8 .sa=rez1; 
if( !success1 ) goto _L129;

outxt(acnst[ 15 ], loc8 .sa , true, true); 
outatm(acnst[15],".sa=",false, true); 
outxt(acnst[ 15 ], loc6 .sa , false, true); 
outatm(acnst[15],";",false, true); ;xxx; 
selop(acnst[71],false,0L,pl1.cel,&rez1);pl2.cel=rez1;
   if( rez1==NULL ) { success1=false;goto _L129;};

/* Alternative pattern */ 
pl3=pl2;
/* nonatomic alternative branches */ 

/* shablon treemain */ rez1=pl2.cel;
success1=false;if(pl2.nel==0 ) goto _L126; 
 if (rez1!=NULL ) { pointr(rez1,&x.sa); 
       if (x.smld->dtype!= treemain )  
        { rez1=NULL;goto _L126;};
/* prowerka imeni */ 
success1=eqatom(x.smld->name,acnst[ 76 ]); 
if( ! success1 ) { rez1=NULL;goto _L126;};
;}; 
pl4.nel=1;pl4.ptrtype=ptrtree;
success1=true; 
selop(acnst[39],false,0L,pl2.cel,&rez1);pl4.cel=rez1;
   if( rez1==NULL ) { success1=false;goto _L126;};

/* shablon listmain */ rez1=pl4.cel;
success1=false;if(pl4.nel==0 ) goto _L126; 
 if (rez1!=NULL ) { pointr(rez1,&x.sa); 
       if (x.smld->dtype!= listmain )  
        { rez1=NULL;goto _L126;};
{pl5.ptrtype=ptrlist; pl5.nel=1;
pl5.cel=x.smld->elt[0];pl5.UU.U1.curfragment=rez1;}
;} else  
{pl5.ptrtype=ptrlist;pl5.nel=0;pl5.cel=NULL;}

loc10 .sa=NULL; 

/* shablon prawila */ r37(&rez1,&success1,&pl5);
if( !success1 ) goto _L126;
loc10 .sa=rez1; 

outatm(acnst[15],"lconc(&",true, true); 
outxt(acnst[ 15 ], loc8 .sa , false, true); 
outatm(acnst[15],".sa,",false, true); 
outxt(acnst[ 15 ], loc10 .sa , false, true); 
outatm(acnst[15],");",false, true); ;xxx; 

/*shablon STARLIST */ 
 pl6=pl5;while(pl5.nel!=0 ) { 

loc10 .sa=NULL; 

/* shablon prawila */ r37(&rez1,&success1,&pl5);
if( !success1 ) goto _L125;
loc10 .sa=rez1; 

outatm(acnst[15],"if(",true, true); 
outxt(acnst[ 15 ], loc8 .sa , false, true); 
outatm(acnst[15],".sa!=NULL ) lconc(&",false, true); 
outxt(acnst[ 15 ], loc8 .sa , false, true); 
outatm(acnst[15],".sa,",false, true); 
outxt(acnst[ 15 ], loc10 .sa , false, true); 
outatm(acnst[15],");",false, true); ;xxx; 
 pl6=pl5;
;}; 
_L125:if( ! success1 )pl5=pl6;
success1 = true ; 

if( pl5.nel !=0 )
{ success1=false;rez1=NULL;goto _L126;};
success1=true;rez1=pl4.cel;
 if( pl4.ptrtype!=ptrtree ) next(&pl4);
if( success1 ) {
 rez1=pl2.cel;if( pl2.ptrtype!=ptrtree ) next(&pl2) ;}
 else { rez1=NULL;goto _L126 ;};
goto _L128/*uspeh*/;
_L126:; 
pl2=pl3;

/* shablon peremennoj */ 
success1=(pl2.nel!=0);rez1=pl2.cel;
if( (pl2.ptrtype!=ptrtree) && success1 ) next(&pl2);
loc11 .sa=rez1; 
if( !success1 ) goto _L127;

/* operator := */ 
/* CALL #L */ 
pl4.ptrtype=packedlist;pl4.nel=1;pl4.cel=loc11.sa;
pl4.plistsize= 1;
r37(&wrk1.sa,&flag1,&pl4);/* #obqzatelxno_obxekt*/ ; 
loc7 .sa= wrk1 .sa ;xxx; 

outatm(acnst[15],"concop(&",true, true); 
outxt(acnst[ 15 ], loc8 .sa , false, true); 
outatm(acnst[15],".sa,",false, true); 
outxt(acnst[ 15 ], loc7 .sa , false, true); 
outatm(acnst[15],");",false, true); ;xxx; 
goto _L128/*uspeh*/;
_L127:; 
pl2=pl3;
goto  _L129;
_L128:;/*uspeh alxtern.*/
if( success1 ) {
 rez1=pl1.cel;if( pl1.ptrtype!=ptrtree ) next(&pl1) ;}
 else { rez1=NULL;goto _L129 ;};
goto _L99;  _L129:;  /* metka wyhoda po neuspehu wetwi */

/* branch */ pl1=*pl;rez1=NULL;success1=true; 
/* inicializaciq peremennyh */ 
loc6.sa=NULL;/* $E1*/ 
loc7.sa=NULL;/* $E2*/ 
loc8.sa=NULL;/* $WRK*/ 
loc10.sa=NULL;/* $EL*/ 
loc11.sa=NULL;/* $E22*/ 
loc12.sa=NULL;/* $EL2*/ 

/* shablon treemain */ rez1=pl1.cel;
success1=false;if(pl1.nel==0 ) goto _L137; 
 if (rez1!=NULL ) { pointr(rez1,&x.sa); 
       if (x.smld->dtype!= treemain )  
        { rez1=NULL;goto _L137;};
/* prowerka imeni */ 
success1=eqatom(x.smld->name,acnst[ 84 ]); 
if( ! success1 ) { rez1=NULL;goto _L137;};
;}; 
pl3.nel=1;pl3.ptrtype=ptrtree;
success1=true; 
selop(acnst[70],false,0L,pl1.cel,&rez1);pl3.cel=rez1;
   if( rez1==NULL ) { success1=false;goto _L137;};

loc6 .sa=NULL; 

/* shablon prawila */ r38(&rez1,&success1,&pl3);
if( !success1 ) goto _L137;
loc6 .sa=rez1; 
selop(acnst[19],false,0L,pl1.cel,&rez1);pl3.cel=rez1;
   if( rez1==NULL ) { success1=false;goto _L137;};

/* shablon peremennoj */ 
success1=(pl3.nel!=0);rez1=pl3.cel;
if( (pl3.ptrtype!=ptrtree) && success1 ) next(&pl3);
loc8 .sa=rez1; 
if( !success1 ) goto _L137;

outxt(acnst[ 15 ], loc8 .sa , true, true); 
outatm(acnst[15],".sa=",false, true); 
outxt(acnst[ 15 ], loc6 .sa , false, true); 
outatm(acnst[15],";",false, true); ;xxx; 
selop(acnst[71],false,0L,pl1.cel,&rez1);pl3.cel=rez1;
   if( rez1==NULL ) { success1=false;goto _L137;};

/* Alternative pattern */ 
pl4=pl3;
/* nonatomic alternative branches */ 

/* Alternative pattern */ 
pl5=pl3;

/* shablon treemain */ rez1=pl3.cel;
success1=false;if(pl3.nel==0 ) goto _L132; 
 if (rez1!=NULL ) { pointr(rez1,&x.sa); 
       if (x.smld->dtype!= treemain )  
        { rez1=NULL;goto _L132;};
/* prowerka imeni */ 
success1=eqatom(x.smld->name,acnst[ 77 ]); 
if( ! success1 ) { rez1=NULL;goto _L132;};
;}; 
pl6.nel=1;pl6.ptrtype=ptrtree;
success1=true; 
selop(acnst[39],false,0L,pl3.cel,&rez1);pl6.cel=rez1;
   if( rez1==NULL ) { success1=false;goto _L130;};

/* shablon listmain */ rez1=pl6.cel;
success1=false;if(pl6.nel==0 ) goto _L130; 
 if (rez1!=NULL ) { pointr(rez1,&x.sa); 
       if (x.smld->dtype!= listmain )  
        { rez1=NULL;goto _L130;};
{pl7.ptrtype=ptrlist; pl7.nel=1;
pl7.cel=x.smld->elt[0];pl7.UU.U1.curfragment=rez1;}
;} else  
{pl7.ptrtype=ptrlist;pl7.nel=0;pl7.cel=NULL;}

/*shablon STARLIST */ 
 pl8=pl7;while(pl7.nel!=0 ) { 

loc10 .sa=NULL; 

/* shablon prawila */ r40(&rez1,&success1,&pl7);
if( !success1 ) goto _L131;
loc10 .sa=rez1; 

loc12 .sa=NULL; 

/* shablon prawila */ r37(&rez1,&success1,&pl7);
if( !success1 ) goto _L131;
loc12 .sa=rez1; 

outatm(acnst[15],"addel(",true, true); 
outxt(acnst[ 15 ], loc10 .sa , false, true); 
outxt(acnst[ 15 ], loc12 .sa , false, true); 
outatm(acnst[15],",&",false, true); 
outxt(acnst[ 15 ], loc8 .sa , false, true); 
outatm(acnst[15],".sa);",false, true); ;xxx; 
 pl8=pl7;
;}; 
_L131:if( ! success1 )pl7=pl8;
success1 = true ; 

if( pl7.nel !=0 )
{ success1=false;rez1=NULL;goto _L130;};
success1=true;rez1=pl6.cel;
 if( pl6.ptrtype!=ptrtree ) next(&pl6);
_L130:success1=true;
if( success1 ) {
 rez1=pl3.cel;if( pl3.ptrtype!=ptrtree ) next(&pl3) ;}
 else { rez1=NULL;goto _L132 ;};

outatm(acnst[15],"if(",true, true); 
outxt(acnst[ 15 ], loc6 .sa , false, true); 
outatm(acnst[15],"!=NULL ) {",false, true); 
outatm(acnst[15],"pointr(",false, true); 
outxt(acnst[ 15 ], loc6 .sa , false, true); 
outatm(acnst[15],",&x.sa);",false, true); 
outatm(acnst[15],"if( x.smtd->dtype!=treemain )",false, true); 
outxt(acnst[ 15 ], loc8 .sa , false, true); 
outatm(acnst[15],".sa=NULL ;};",false, true); ;xxx; 
goto _L133/*uspeh*/;
_L132:; 
pl3=pl5;
goto  _L134;
_L133:;/*uspeh alxtern.*/
goto _L136/*uspeh*/;
_L134:; 
pl3=pl4;

/* shablon peremennoj */ 
success1=(pl3.nel!=0);rez1=pl3.cel;
if( (pl3.ptrtype!=ptrtree) && success1 ) next(&pl3);
loc11 .sa=rez1; 
if( !success1 ) goto _L135;

/* operator := */ 
/* CALL #L */ 
pl6.ptrtype=packedlist;pl6.nel=1;pl6.cel=loc11.sa;
pl6.plistsize= 1;
r37(&wrk1.sa,&flag1,&pl6);/* #obqzatelxno_obxekt*/ ; 
loc7 .sa= wrk1 .sa ;xxx; 

outatm(acnst[15],"addtre(&",true, true); 
outxt(acnst[ 15 ], loc8 .sa , false, true); 
outatm(acnst[15],".sa,",false, true); 
outxt(acnst[ 15 ], loc7 .sa , false, true); 
outatm(acnst[15],");",false, true); ;xxx; 
goto _L136/*uspeh*/;
_L135:; 
pl3=pl4;
goto  _L137;
_L136:;/*uspeh alxtern.*/
if( success1 ) {
 rez1=pl1.cel;if( pl1.ptrtype!=ptrtree ) next(&pl1) ;}
 else { rez1=NULL;goto _L137 ;};
goto _L99;  _L137:;  /* metka wyhoda po neuspehu wetwi */

/* branch */ pl1=*pl;rez1=NULL;success1=true; 
/* inicializaciq peremennyh */ 

/* shablon treemain */ rez1=pl1.cel;
success1=false;if(pl1.nel==0 ) goto _L138; 
 if (rez1!=NULL ) { pointr(rez1,&x.sa); 
       if (x.smld->dtype!= treemain )  
        { rez1=NULL;goto _L138;};
/* prowerka imeni */ 
success1=eqatom(x.smld->name,acnst[ 24 ]); 
if( ! success1 ) { rez1=NULL;goto _L138;};
;}; 
pl5.nel=1;pl5.ptrtype=ptrtree;
success1=true; 
selop(acnst[19],false,0L,pl1.cel,&rez1);pl5.cel=rez1;
   if( rez1==NULL ) { success1=false;goto _L138;};

/* shablon peremennoj */ 
success1=(pl5.nel!=0);rez1=pl5.cel;
if( (pl5.ptrtype!=ptrtree) && success1 ) next(&pl5);
loc2 .sa=rez1; 
if( !success1 ) goto _L138;
if( success1 ) {
 rez1=pl1.cel;if( pl1.ptrtype!=ptrtree ) next(&pl1) ;}
 else { rez1=NULL;goto _L138 ;};
goto _L99;  _L138:;  /* metka wyhoda po neuspehu wetwi */

/* branch */ pl1=*pl;rez1=NULL;success1=true; 
/* inicializaciq peremennyh */ 
loc6.sa=NULL;/* $E1*/ 
loc7.sa=NULL;/* $E2*/ 
loc8.sa=NULL;/* $WRK*/ 
loc11.sa=NULL;/* $E22*/ 
loc13.sa=NULL;/* $OP*/ 
loc14.sa=NULL;/* $tip*/ 
loc15.sa=NULL;/* $E11*/ 

/* shablon treemain */ rez1=pl1.cel;
success1=false;if(pl1.nel==0 ) goto _L144; 
 if (rez1!=NULL ) { pointr(rez1,&x.sa); 
       if (x.smld->dtype!= treemain )  
        { rez1=NULL;goto _L144;};
/* prowerka imeni */ 
loc13 .sa=x.smld->name; 
;}; 
pl5.nel=1;pl5.ptrtype=ptrtree;
success1=true; 
selop(acnst[70],false,0L,pl1.cel,&rez1);pl5.cel=rez1;
   if( rez1==NULL ) { success1=false;goto _L144;};

/* shablon peremennoj */ 
success1=(pl5.nel!=0);rez1=pl5.cel;
if( (pl5.ptrtype!=ptrtree) && success1 ) next(&pl5);
loc6 .sa=rez1; 
if( !success1 ) goto _L144;
selop(acnst[71],false,0L,pl1.cel,&rez1);pl5.cel=rez1;
   if( rez1==NULL ) { success1=false;goto _L144;};

/* shablon peremennoj */ 
success1=(pl5.nel!=0);rez1=pl5.cel;
if( (pl5.ptrtype!=ptrtree) && success1 ) next(&pl5);
loc7 .sa=rez1; 
if( !success1 ) goto _L144;
selop(acnst[17],false,0L,pl1.cel,&rez1);pl5.cel=rez1;
   if( rez1==NULL ) { success1=false;goto _L144;};

/* shablon peremennoj */ 
success1=(pl5.nel!=0);rez1=pl5.cel;
if( (pl5.ptrtype!=ptrtree) && success1 ) next(&pl5);
loc14 .sa=rez1; 
if( !success1 ) goto _L144;
selop(acnst[19],false,0L,pl1.cel,&rez1);pl5.cel=rez1;
   if( rez1==NULL ) { success1=false;goto _L144;};

/* shablon peremennoj */ 
success1=(pl5.nel!=0);rez1=pl5.cel;
if( (pl5.ptrtype!=ptrtree) && success1 ) next(&pl5);
loc8 .sa=rez1; 
if( !success1 ) goto _L144;
if( success1 ) {
 rez1=pl1.cel;if( pl1.ptrtype!=ptrtree ) next(&pl1) ;}
 else { rez1=NULL;goto _L144 ;};

/* IF-operator */ 
/* operaciq <> */ wrk1 .bo= ! eqatom( loc13 .sa ,acnst[ 85 ]) ; 
if( !( wrk1 .bo )) wrk3 .bo=false; else { 
/* operaciq <> */ wrk2 .bo= ! eqatom( loc13 .sa ,acnst[ 86 ]) ; wrk3 = wrk2 
;}/*log*/; 
if( !( wrk3 .bo )) wrk5 .bo=false; else { 
/* operaciq <> */ wrk4 .bo= ! eqatom( loc13 .sa ,acnst[ 87 ]) ; wrk5 = wrk4 
;}/*log*/; 
if( !( wrk5 .bo )) wrk7 .bo=false; else { 
/* operaciq <> */ wrk6 .bo= ! eqatom( loc13 .sa ,acnst[ 88 ]) ; wrk7 = wrk6 
;}/*log*/; 
if( !( wrk7 .bo )) wrk9 .bo=false; else { 
/* operaciq <> */ wrk8 .bo= ! eqatom( loc13 .sa ,acnst[ 89 ]) ; wrk9 = wrk8 
;}/*log*/; 
if( !( wrk9 .bo )) wrk11 .bo=false; else { 
/* operaciq <> */ wrk10 .bo= ! eqatom( loc13 .sa ,acnst[ 90 ]) ; wrk11 = wrk10 
;}/*log*/; 
if( !( wrk11 .bo )) wrk13 .bo=false; else { 
/* operaciq <> */ wrk12 .bo= ! eqatom( loc13 .sa ,acnst[ 91 ]) ; wrk13 = wrk12 
;}/*log*/; 
if( !( wrk13 .bo )) wrk15 .bo=false; else { 
/* operaciq <> */ wrk14 .bo= ! eqatom( loc13 .sa ,acnst[ 92 ]) ; wrk15 = wrk14 
;}/*log*/; 
if( !( wrk15 .bo )) wrk17 .bo=false; else { 
/* operaciq <> */ wrk16 .bo= ! eqatom( loc13 .sa ,acnst[ 93 ]) ; wrk17 = wrk16 
;}/*log*/; 
if( wrk17 .bo) 
{ 
/* FAIL */ rez1=NULL;success1=false; 
if (pl1.ptrtype!=ptrtree) next(&pl1); /*wyhod iz der.ili sp.*/ 
goto _L144;xxx; 
;} 
_L139:;xxx; 

/* IF-operator */ 
selop( acnst[ 17 ],false,NULL, loc6 .sa ,& wrk1 .sa); 
/* operaciq = */ wrk2 .bo= eqatom( wrk1 .sa ,acnst[ 21 ]) ; 
if( wrk2 .bo ) wrk5 .bo=true; else { 
selop( acnst[ 17 ],false,NULL, loc7 .sa ,& wrk3 .sa); 
/* operaciq = */ wrk4 .bo= eqatom( wrk3 .sa ,acnst[ 21 ]) ; wrk5 = wrk4 ;}; 
if( wrk5 .bo ) wrk7 .bo=true; else { 
/* operaciq = */ wrk6 .bo= eqatom( loc13 .sa ,acnst[ 85 ]) ; wrk7 = wrk6 ;}; 
if( wrk7 .bo ) wrk9 .bo=true; else { 
/* operaciq = */ wrk8 .bo= eqatom( loc13 .sa ,acnst[ 86 ]) ; wrk9 = wrk8 ;}; 
if( wrk9 .bo ) wrk11 .bo=true; else { 
/* operaciq = */ wrk10 .bo= eqatom( loc13 .sa ,acnst[ 87 ]) ; wrk11 = wrk10 ;}; 
if( wrk11 .bo ) wrk13 .bo=true; else { 
/* operaciq = */ wrk12 .bo= eqatom( loc13 .sa ,acnst[ 88 ]) ; wrk13 = wrk12 ;}; 
if( wrk13 .bo ) wrk15 .bo=true; else { 
/* operaciq = */ wrk14 .bo= eqatom( loc13 .sa ,acnst[ 89 ]) ; wrk15 = wrk14 ;}; 
if( wrk15 .bo) 
{ 
/* CALL #L */ 
pl5.ptrtype=packedlist;pl5.nel=1;pl5.cel=loc6.sa;
pl5.plistsize= 1;
r41(&wrk1.sa,&flag1,&pl5);/* #G_wyravenie*/ ;xxx; 
/* CALL #L */ 
pl5.ptrtype=packedlist;pl5.nel=1;pl5.cel=loc7.sa;
pl5.plistsize= 1;
r41(&wrk1.sa,&flag1,&pl5);/* #G_wyravenie*/ ;xxx; 
outxt(acnst[ 15 ], loc8 .sa , true, true); ;xxx; 
/* IF-operator */ 
/* operaciq = */ wrk1 .bo= eqatom( loc14 .sa ,acnst[ 21 ]) ; 
if( wrk1 .bo) 
{ 
outatm(acnst[15],".nu=",false, true); ;xxx; 
goto _L141;
;} 
{ 
outatm(acnst[15],".bo=",false, true); ;xxx; 
;} 
_L141:;xxx; 
/* IF-operator */ 
/* operaciq = */ wrk1 .bo= eqatom( loc13 .sa ,acnst[ 88 ]) ; 
if( wrk1 .bo) 
{ 
/* operator := */ 
loc13 .sa= cnst[42] .sa ;xxx; 
goto _L142;
;} 
/* operaciq = */ wrk1 .bo= eqatom( loc13 .sa ,acnst[ 89 ]) ; 
if( wrk1 .bo) 
{ 
/* operator := */ 
loc13 .sa= cnst[43] .sa ;xxx; 
;} 
_L142:;xxx; 
/* CALL #L */ 
pl5.ptrtype=packedlist;pl5.nel=1;pl5.cel=loc6.sa;
pl5.plistsize= 1;
r48(&wrk1.sa,&flag1,&pl5);/* #~islo_ili_0*/ ; 
outxt(acnst[ 15 ], wrk1 .sa , false, true); 
outxt(acnst[ 15 ], loc13 .sa , false, true); 
/* CALL #L */ 
pl5.ptrtype=packedlist;pl5.nel=1;pl5.cel=loc7.sa;
pl5.plistsize= 1;
r48(&wrk1.sa,&flag1,&pl5);/* #~islo_ili_0*/ ; 
outxt(acnst[ 15 ], wrk1 .sa , false, true); 
outatm(acnst[15],";",false, true); ;xxx; 
goto _L140;
;} 
{ 
/* operator := */ 
/* CALL #L */ 
pl5.ptrtype=packedlist;pl5.nel=1;pl5.cel=loc6.sa;
pl5.plistsize= 1;
r37(&wrk1.sa,&flag1,&pl5);/* #obqzatelxno_obxekt*/ ; 
loc15 .sa= wrk1 .sa ;xxx; 
/* operator := */ 
/* CALL #L */ 
pl5.ptrtype=packedlist;pl5.nel=1;pl5.cel=loc7.sa;
pl5.plistsize= 1;
r37(&wrk1.sa,&flag1,&pl5);/* #obqzatelxno_obxekt*/ ; 
loc11 .sa= wrk1 .sa ;xxx; 
outxt(acnst[ 15 ], loc8 .sa , true, true); 
outatm(acnst[15],".bo=compare(",false, true); ;xxx; 
/* IF-operator */ 
/* operaciq = */ wrk1 .bo= eqatom( loc13 .sa ,acnst[ 90 ]) ; 
if( wrk1 .bo) 
{ 
outatm(acnst[15],"3L",false, true); ;xxx; 
goto _L143;
;} 
/* operaciq = */ wrk1 .bo= eqatom( loc13 .sa ,acnst[ 92 ]) ; 
if( wrk1 .bo) 
{ 
outatm(acnst[15],"4L",false, true); ;xxx; 
goto _L143;
;} 
/* operaciq = */ wrk1 .bo= eqatom( loc13 .sa ,acnst[ 91 ]) ; 
if( wrk1 .bo) 
{ 
outatm(acnst[15],"1L",false, true); ;xxx; 
goto _L143;
;} 
/* operaciq = */ wrk1 .bo= eqatom( loc13 .sa ,acnst[ 93 ]) ; 
if( wrk1 .bo) 
{ 
outatm(acnst[15],"2L",false, true); ;xxx; 
;} 
_L143:;xxx; 
outatm(acnst[15],",",false, true); 
outxt(acnst[ 15 ], loc15 .sa , false, true); 
outatm(acnst[15],",",false, true); 
outxt(acnst[ 15 ], loc11 .sa , false, true); 
outatm(acnst[15],");",false, true); ;xxx; 
;} 
_L140:;xxx; 
goto _L99;  _L144:;  /* metka wyhoda po neuspehu wetwi */

/* branch */ pl1=*pl;rez1=NULL;success1=true; 
/* inicializaciq peremennyh */ 
loc8.sa=NULL;/* $WRK*/ 
loc9.sa=NULL;/* $E*/ 

/* shablon treemain */ rez1=pl1.cel;
success1=false;if(pl1.nel==0 ) goto _L145; 
 if (rez1!=NULL ) { pointr(rez1,&x.sa); 
       if (x.smld->dtype!= treemain )  
        { rez1=NULL;goto _L145;};
/* prowerka imeni */ 
success1=eqatom(x.smld->name,acnst[ 86 ]); 
if( ! success1 ) { rez1=NULL;goto _L145;};
;}; 
pl5.nel=1;pl5.ptrtype=ptrtree;
success1=true; 
selop(acnst[47],false,0L,pl1.cel,&rez1);pl5.cel=rez1;
   if( rez1==NULL ) { success1=false;goto _L145;};

/* shablon peremennoj */ 
success1=(pl5.nel!=0);rez1=pl5.cel;
if( (pl5.ptrtype!=ptrtree) && success1 ) next(&pl5);
loc9 .sa=rez1; 
if( !success1 ) goto _L145;

/* CALL #L */ 
pl6.ptrtype=packedlist;pl6.nel=1;pl6.cel=loc9.sa;
pl6.plistsize= 1;
r41(&wrk1.sa,&flag1,&pl6);/* #G_wyravenie*/ ;xxx; 
selop(acnst[19],false,0L,pl1.cel,&rez1);pl5.cel=rez1;
   if( rez1==NULL ) { success1=false;goto _L145;};

/* shablon peremennoj */ 
success1=(pl5.nel!=0);rez1=pl5.cel;
if( (pl5.ptrtype!=ptrtree) && success1 ) next(&pl5);
loc8 .sa=rez1; 
if( !success1 ) goto _L145;
if( success1 ) {
 rez1=pl1.cel;if( pl1.ptrtype!=ptrtree ) next(&pl1) ;}
 else { rez1=NULL;goto _L145 ;};

outxt(acnst[ 15 ], loc8 .sa , true, true); 
outatm(acnst[15],".nu=-",false, true); 
/* CALL #L */ 
pl5.ptrtype=packedlist;pl5.nel=1;pl5.cel=loc9.sa;
pl5.plistsize= 1;
r48(&wrk1.sa,&flag1,&pl5);/* #~islo_ili_0*/ ; 
outxt(acnst[ 15 ], wrk1 .sa , false, true); 
outatm(acnst[15],";",false, true); ;xxx; 
goto _L99;  _L145:;  /* metka wyhoda po neuspehu wetwi */

/* branch */ pl1=*pl;rez1=NULL;success1=true; 
/* inicializaciq peremennyh */ 
loc8.sa=NULL;/* $WRK*/ 

/* shablon treemain */ rez1=pl1.cel;
success1=false;if(pl1.nel==0 ) goto _L146; 
 if (rez1!=NULL ) { pointr(rez1,&x.sa); 
       if (x.smld->dtype!= treemain )  
        { rez1=NULL;goto _L146;};
/* prowerka imeni */ 
success1=eqatom(x.smld->name,acnst[ 94 ]); 
if( ! success1 ) { rez1=NULL;goto _L146;};
;}; 
pl5.nel=1;pl5.ptrtype=ptrtree;
success1=true; 
selop(acnst[19],false,0L,pl1.cel,&rez1);pl5.cel=rez1;
   if( rez1==NULL ) { success1=false;goto _L146;};

/* shablon peremennoj */ 
success1=(pl5.nel!=0);rez1=pl5.cel;
if( (pl5.ptrtype!=ptrtree) && success1 ) next(&pl5);
loc8 .sa=rez1; 
if( !success1 ) goto _L146;
if( success1 ) {
 rez1=pl1.cel;if( pl1.ptrtype!=ptrtree ) next(&pl1) ;}
 else { rez1=NULL;goto _L146 ;};

outxt(acnst[ 15 ], loc8 .sa , true, false); 
outxt(acnst[ 15 ], cnst[44] .sa , false, false); 
outxt(acnst[ 15 ], glob3_3 .sa , false, false); 
outatm(acnst[15],".cel;",false, false); ;xxx; 
goto _L99;  _L146:;  /* metka wyhoda po neuspehu wetwi */

/* branch */ pl1=*pl;rez1=NULL;success1=true; 
/* inicializaciq peremennyh */ 
loc6.sa=NULL;/* $E1*/ 
loc7.sa=NULL;/* $E2*/ 
loc8.sa=NULL;/* $WRK*/ 

/* shablon treemain */ rez1=pl1.cel;
success1=false;if(pl1.nel==0 ) goto _L150; 
 if (rez1!=NULL ) { pointr(rez1,&x.sa); 
       if (x.smld->dtype!= treemain )  
        { rez1=NULL;goto _L150;};
/* prowerka imeni */ 
success1=eqatom(x.smld->name,acnst[ 95 ]); 
if( ! success1 ) { rez1=NULL;goto _L150;};
;}; 
pl5.nel=1;pl5.ptrtype=ptrtree;
success1=true; 
selop(acnst[70],false,0L,pl1.cel,&rez1);pl5.cel=rez1;
   if( rez1==NULL ) { success1=false;goto _L150;};

loc6 .sa=NULL; 

/* shablon prawila */ r37(&rez1,&success1,&pl5);
if( !success1 ) goto _L150;
loc6 .sa=rez1; 
selop(acnst[71],false,0L,pl1.cel,&rez1);pl5.cel=rez1;
   if( rez1==NULL ) { success1=false;goto _L150;};

/* shablon peremennoj */ 
success1=(pl5.nel!=0);rez1=pl5.cel;
if( (pl5.ptrtype!=ptrtree) && success1 ) next(&pl5);
loc7 .sa=rez1; 
if( !success1 ) goto _L150;

/* CALL #L */ 
pl6.ptrtype=packedlist;pl6.nel=1;pl6.cel=loc7.sa;
pl6.plistsize= 1;
r41(&wrk1.sa,&flag1,&pl6);/* #G_wyravenie*/ ;xxx; 
selop(acnst[19],false,0L,pl1.cel,&rez1);pl5.cel=rez1;
   if( rez1==NULL ) { success1=false;goto _L150;};

/* shablon peremennoj */ 
success1=(pl5.nel!=0);rez1=pl5.cel;
if( (pl5.ptrtype!=ptrtree) && success1 ) next(&pl5);
loc8 .sa=rez1; 
if( !success1 ) goto _L150;
if( success1 ) {
 rez1=pl1.cel;if( pl1.ptrtype!=ptrtree ) next(&pl1) ;}
 else { rez1=NULL;goto _L150 ;};

outatm(acnst[15],"/* operaciq :: */",true, true); 
outxt(acnst[ 15 ], loc8 .sa , false, true); 
outatm(acnst[15],".sa=NULL;",false, true); ;xxx; 

/* IF-operator */ 
selop( acnst[ 17 ],false,NULL, loc7 .sa ,& wrk1 .sa); 
/* operaciq = */ wrk2 .bo= wrk1 .sa ==NULL ; 
if( !( wrk2 .bo )) wrk5 .bo=false; else { 
selop( acnst[ 19 ],false,NULL, loc7 .sa ,& wrk3 .sa); 
/* operaciq <> */ wrk4 .bo= ! eqatom( wrk3 .sa ,acnst[ 24 ]) ; wrk5 = wrk4 
;}/*log*/; 
if( wrk5 .bo) 
{ 
outatm(acnst[15],"if(",true, true); 
selop( acnst[ 19 ],false,NULL, loc7 .sa ,& wrk1 .sa); 
outxt(acnst[ 15 ], wrk1 .sa , false, true); 
outatm(acnst[15],".sa!=NULL ) { points(",false, true); 
selop( acnst[ 19 ],false,NULL, loc7 .sa ,& wrk1 .sa); 
outxt(acnst[ 15 ], wrk1 .sa , false, true); 
outatm(acnst[15],".sa,&x.sa);",false, true); ;xxx; 
/* IF-operator */ 
/* CALL #L */ 
pl5.ptrtype=packedlist;pl5.nel=1;pl5.cel=loc7.sa;
pl5.plistsize= 1;
r44(&wrk1.sa,&flag1,&pl5);/* #IS_CONSTRUCTOR*/ ; 
wrk2 .bo= wrk1 .sa==NULL; 
if( wrk2 .bo) 
{ 
outatm(acnst[15],"if( (x.smld->dtype==treemain)||(x.smtd->dtype==listmain)) {",
true, true); ;xxx; 
;} 
_L148:;xxx; 
outatm(acnst[15],"x.smtd->name=",true, true); 
outxt(acnst[ 15 ], loc6 .sa , false, true); 
outatm(acnst[15],";",false, true); 
outxt(acnst[ 15 ], loc8 .sa , false, true); 
outatm(acnst[15],"=",false, true); 
selop( acnst[ 19 ],false,NULL, loc7 .sa ,& wrk1 .sa); 
outxt(acnst[ 15 ], wrk1 .sa , false, true); ;xxx; 
/* IF-operator */ 
/* CALL #L */ 
pl5.ptrtype=packedlist;pl5.nel=1;pl5.cel=loc7.sa;
pl5.plistsize= 1;
r44(&wrk1.sa,&flag1,&pl5);/* #IS_CONSTRUCTOR*/ ; 
wrk2 .bo= wrk1 .sa==NULL; 
if( wrk2 .bo) 
{ 
outatm(acnst[15],";}",false, true); ;xxx; 
;} 
_L149:;xxx; 
outatm(acnst[15],";};",false, true); ;xxx; 
;} 
_L147:;xxx; 
goto _L99;  _L150:;  /* metka wyhoda po neuspehu wetwi */

/* branch */ pl1=*pl;rez1=NULL;success1=true; 
/* inicializaciq peremennyh */ 
loc8.sa=NULL;/* $WRK*/ 
loc9.sa=NULL;/* $E*/ 

/* shablon treemain */ rez1=pl1.cel;
success1=false;if(pl1.nel==0 ) goto _L151; 
 if (rez1!=NULL ) { pointr(rez1,&x.sa); 
       if (x.smld->dtype!= treemain )  
        { rez1=NULL;goto _L151;};
/* prowerka imeni */ 
success1=eqatom(x.smld->name,acnst[ 96 ]); 
if( ! success1 ) { rez1=NULL;goto _L151;};
;}; 
pl5.nel=1;pl5.ptrtype=ptrtree;
success1=true; 
selop(acnst[47],false,0L,pl1.cel,&rez1);pl5.cel=rez1;
   if( rez1==NULL ) { success1=false;goto _L151;};

loc9 .sa=NULL; 

/* shablon prawila */ r37(&rez1,&success1,&pl5);
if( !success1 ) goto _L151;
loc9 .sa=rez1; 
selop(acnst[19],false,0L,pl1.cel,&rez1);pl5.cel=rez1;
   if( rez1==NULL ) { success1=false;goto _L151;};

/* shablon peremennoj */ 
success1=(pl5.nel!=0);rez1=pl5.cel;
if( (pl5.ptrtype!=ptrtree) && success1 ) next(&pl5);
loc8 .sa=rez1; 
if( !success1 ) goto _L151;
if( success1 ) {
 rez1=pl1.cel;if( pl1.ptrtype!=ptrtree ) next(&pl1) ;}
 else { rez1=NULL;goto _L151 ;};

outatm(acnst[15],"copyop(",true, true); 
outxt(acnst[ 15 ], loc9 .sa , false, true); 
outatm(acnst[15],",&",false, true); 
outxt(acnst[ 15 ], loc8 .sa , false, true); 
outatm(acnst[15],".sa);",false, true); ;xxx; 
goto _L99;  _L151:;  /* metka wyhoda po neuspehu wetwi */

/* branch */ pl1=*pl;rez1=NULL;success1=true; 
/* inicializaciq peremennyh */ 

/* shablon peremennoj */ 
success1=(pl1.nel!=0);rez1=pl1.cel;
if( (pl1.ptrtype!=ptrtree) && success1 ) next(&pl1);
loc9 .sa=rez1; 
if( !success1 ) goto _L152;

outatm(acnst[15],"/* GENEXPR: operaciq ne realizowana !!! */",true, true); ;xxx;
 
goto _L99;  _L152:;  /* metka wyhoda po neuspehu wetwi */
 _L99: rez1=NULL; 
 _L98: *rez=rez1;*success=success1; 
 if (*success) *pl=pl1; /* prodwinutx ukazatelx leksem */ 
/* wosstanowitx GLOB */ 
#ifdef XX  
 d(2,"G_wyravenie", 41 ,*rez,*success); 
#endif 
;};/* RULE */ 
/*===============================================*/ 
/* GENERATED TEXT OF RULE   #G_AND   */ 
 Void r42(rez,success,pl)
long *rez;boolean *success;ptr_ *pl; 
{  a rez1;  boolean success1; long k; mpd x; 
v loc1;/* $WRK*/ 
v loc2;/* $E1*/ 
v loc3;/* $tip*/ 
v loc4;/* $mesto*/ 
v loc5;/* $E2*/ 
v loc6;/* $tip2*/ 
v loc7;/* $mesto2*/ 
v wrk1;
v wrk2;
ptr_ pl1;
ptr_ pl2;
ptr_ pl3;
boolean flag1;
#ifdef XX  
 d(1,"G_AND", 42 ,pl->cel,0); 
#endif 
/* sohranitx GLOB */ 

/* branch */ pl1=*pl;rez1=NULL;success1=true; 
/* inicializaciq peremennyh */ 
loc1.sa=NULL;/* $WRK*/ 
loc2.sa=NULL;/* $E1*/ 
loc3.sa=NULL;/* $tip*/ 
loc4.sa=NULL;/* $mesto*/ 
loc5.sa=NULL;/* $E2*/ 
loc6.sa=NULL;/* $tip2*/ 
loc7.sa=NULL;/* $mesto2*/ 

/* shablon treemain */ rez1=pl1.cel;
success1=false;if(pl1.nel==0 ) goto _L104; 
 if (rez1!=NULL ) { pointr(rez1,&x.sa); 
       if (x.smld->dtype!= treemain )  
        { rez1=NULL;goto _L104;};
/* prowerka imeni */ 
success1=eqatom(x.smld->name,acnst[ 97 ]); 
if( ! success1 ) { rez1=NULL;goto _L104;};
;}; 
pl2.nel=1;pl2.ptrtype=ptrtree;
success1=true; 
selop(acnst[19],false,0L,pl1.cel,&rez1);pl2.cel=rez1;
   if( rez1==NULL ) { success1=false;goto _L104;};

/* shablon peremennoj */ 
success1=(pl2.nel!=0);rez1=pl2.cel;
if( (pl2.ptrtype!=ptrtree) && success1 ) next(&pl2);
loc1 .sa=rez1; 
if( !success1 ) goto _L104;
selop(acnst[70],false,0L,pl1.cel,&rez1);pl2.cel=rez1;
   if( rez1==NULL ) { success1=false;goto _L104;};

/* shablon peremennoj */ 
success1=(pl2.nel!=0);rez1=pl2.cel;
if( (pl2.ptrtype!=ptrtree) && success1 ) next(&pl2);
loc2 .sa=rez1; 
if( !success1 ) goto _L104;

/* CALL #L */ 
pl3.ptrtype=packedlist;pl3.nel=1;pl3.cel=loc2.sa;
pl3.plistsize= 1;
r41(&wrk1.sa,&flag1,&pl3);/* #G_wyravenie*/ ;xxx; 

/* operator := */ 
selop( acnst[ 17 ],false,NULL, loc2 .sa ,& wrk1 .sa); 
loc3 .sa= wrk1 .sa ;xxx; 

/* operator := */ 
selop( acnst[ 19 ],false,NULL, loc2 .sa ,& wrk1 .sa); 
loc4 .sa= wrk1 .sa ;xxx; 

/* IF-operator */ 
/* operaciq = */ wrk1 .bo= eqatom( loc3 .sa ,acnst[ 18 ]) ; 
if( wrk1 .bo) 
{ 
outatm(acnst[15],"if( !(",true, true); 
outxt(acnst[ 15 ], loc4 .sa , false, true); 
outatm(acnst[15],".bo ))",false, true); 
outxt(acnst[ 15 ], loc1 .sa , false, true); 
outatm(acnst[15],".bo=false; else {",false, true); ;xxx; 
goto _L101;
;} 
if( loc3 .sa!=NULL ) wrk2 .bo=true; else { 
selop( acnst[ 51 ],false,NULL, loc2 .sa ,& wrk1 .sa); wrk2 .bo= wrk1 .sa!=NULL 
;}; 
if( wrk2 .bo) 
{ 
outxt(acnst[ 15 ],NULL,true,false) ;xxx; 
goto _L101;
;} 
/* operaciq = */ wrk1 .bo= eqatom( loc4 .sa ,acnst[ 24 ]) ; 
if( wrk1 .bo) 
{ 
outxt(acnst[ 15 ], loc1 .sa , true, true); 
outatm(acnst[15],".bo=false;",false, true); ;xxx; 
/* RETURN-op. */ 
rez1 = NULL 
;if (pl1.ptrtype!=ptrtree) next(&pl1) /*wyhod iz der.ili sp.*/ ;goto _L98 ;xxx; 
goto _L101;
;} 
{ 
outatm(acnst[15],"if(",true, true); 
outxt(acnst[ 15 ], loc4 .sa , false, true); 
outatm(acnst[15],".sa==NULL )",false, true); 
outxt(acnst[ 15 ], loc1 .sa , false, true); 
outatm(acnst[15],".bo=false; else {",false, true); ;xxx; 
;} 
_L101:;xxx; 
selop(acnst[71],false,0L,pl1.cel,&rez1);pl2.cel=rez1;
   if( rez1==NULL ) { success1=false;goto _L104;};

/* shablon peremennoj */ 
success1=(pl2.nel!=0);rez1=pl2.cel;
if( (pl2.ptrtype!=ptrtree) && success1 ) next(&pl2);
loc5 .sa=rez1; 
if( !success1 ) goto _L104;

/* CALL #L */ 
pl3.ptrtype=packedlist;pl3.nel=1;pl3.cel=loc5.sa;
pl3.plistsize= 1;
r41(&wrk1.sa,&flag1,&pl3);/* #G_wyravenie*/ ;xxx; 

/* operator := */ 
selop( acnst[ 17 ],false,NULL, loc5 .sa ,& wrk1 .sa); 
loc6 .sa= wrk1 .sa ;xxx; 

/* operator := */ 
selop( acnst[ 19 ],false,NULL, loc5 .sa ,& wrk1 .sa); 
loc7 .sa= wrk1 .sa ;xxx; 

/* IF-operator */ 
/* operaciq = */ wrk1 .bo= eqatom( loc6 .sa ,acnst[ 18 ]) ; 
if( wrk1 .bo) 
{ 
outxt(acnst[ 15 ], loc1 .sa , false, true); 
outatm(acnst[15],"=",false, true); 
outxt(acnst[ 15 ], loc7 .sa , false, true); ;xxx; 
goto _L102;
;} 
if( loc6 .sa!=NULL ) wrk2 .bo=true; else { 
selop( acnst[ 51 ],false,NULL, loc5 .sa ,& wrk1 .sa); wrk2 .bo= wrk1 .sa!=NULL 
;}; 
if( wrk2 .bo) 
{ 
outxt(acnst[ 15 ], loc1 .sa , false, true); 
outatm(acnst[15],".bo=true",false, true); ;xxx; 
goto _L102;
;} 
/* operaciq = */ wrk1 .bo= eqatom( loc7 .sa ,acnst[ 24 ]) ; 
if( wrk1 .bo) 
{ 
outxt(acnst[ 15 ], loc1 .sa , false, true); 
outatm(acnst[15],".bo=false",false, true); ;xxx; 
goto _L102;
;} 
{ 
outxt(acnst[ 15 ], loc1 .sa , false, true); 
outatm(acnst[15],".bo=",false, true); 
outxt(acnst[ 15 ], loc7 .sa , false, true); 
outatm(acnst[15],".sa!=NULL",false, true); ;xxx; 
;} 
_L102:;xxx; 

/* IF-operator */ 
/* operaciq = */ wrk1 .bo= eqatom( loc3 .sa ,acnst[ 18 ]) ; 
if( wrk1 .bo) 
{ 
outatm(acnst[15],";}/*log*/;",false, true); ;xxx; 
goto _L103;
;} 
if( loc3 .sa!=NULL ) wrk2 .bo=true; else { 
selop( acnst[ 51 ],false,NULL, loc2 .sa ,& wrk1 .sa); wrk2 .bo= wrk1 .sa!=NULL 
;}; 
if( wrk2 .bo) 
{ 
outatm(acnst[15],";",false, true); ;xxx; 
goto _L103;
;} 
{ 
outatm(acnst[15],";};",false, true); ;xxx; 
;} 
_L103:;xxx; 
if( success1 ) {
 rez1=pl1.cel;if( pl1.ptrtype!=ptrtree ) next(&pl1) ;}
 else { rez1=NULL;goto _L104 ;};
goto _L99;  _L104:;  /* metka wyhoda po neuspehu wetwi */
 _L99: rez1=NULL; 
 _L98: *rez=rez1;*success=success1; 
 if (*success) *pl=pl1; /* prodwinutx ukazatelx leksem */ 
/* wosstanowitx GLOB */ 
#ifdef XX  
 d(2,"G_AND", 42 ,*rez,*success); 
#endif 
;};/* RULE */ 
/*===============================================*/ 
/* GENERATED TEXT OF RULE   #G_OR   */ 
 Void r43(rez,success,pl)
long *rez;boolean *success;ptr_ *pl; 
{  a rez1;  boolean success1; long k; mpd x; 
v loc1;/* $WRK*/ 
v loc2;/* $E1*/ 
v loc3;/* $tip*/ 
v loc4;/* $mesto*/ 
v loc5;/* $E2*/ 
v loc6;/* $tip2*/ 
v loc7;/* $mesto2*/ 
v wrk1;
v wrk2;
ptr_ pl1;
ptr_ pl2;
ptr_ pl3;
boolean flag1;
#ifdef XX  
 d(1,"G_OR", 43 ,pl->cel,0); 
#endif 
/* sohranitx GLOB */ 

/* branch */ pl1=*pl;rez1=NULL;success1=true; 
/* inicializaciq peremennyh */ 
loc1.sa=NULL;/* $WRK*/ 
loc2.sa=NULL;/* $E1*/ 
loc3.sa=NULL;/* $tip*/ 
loc4.sa=NULL;/* $mesto*/ 
loc5.sa=NULL;/* $E2*/ 
loc6.sa=NULL;/* $tip2*/ 
loc7.sa=NULL;/* $mesto2*/ 

/* shablon treemain */ rez1=pl1.cel;
success1=false;if(pl1.nel==0 ) goto _L104; 
 if (rez1!=NULL ) { pointr(rez1,&x.sa); 
       if (x.smld->dtype!= treemain )  
        { rez1=NULL;goto _L104;};
/* prowerka imeni */ 
success1=eqatom(x.smld->name,acnst[ 98 ]); 
if( ! success1 ) { rez1=NULL;goto _L104;};
;}; 
pl2.nel=1;pl2.ptrtype=ptrtree;
success1=true; 
selop(acnst[19],false,0L,pl1.cel,&rez1);pl2.cel=rez1;
   if( rez1==NULL ) { success1=false;goto _L104;};

/* shablon peremennoj */ 
success1=(pl2.nel!=0);rez1=pl2.cel;
if( (pl2.ptrtype!=ptrtree) && success1 ) next(&pl2);
loc1 .sa=rez1; 
if( !success1 ) goto _L104;
selop(acnst[70],false,0L,pl1.cel,&rez1);pl2.cel=rez1;
   if( rez1==NULL ) { success1=false;goto _L104;};

/* shablon peremennoj */ 
success1=(pl2.nel!=0);rez1=pl2.cel;
if( (pl2.ptrtype!=ptrtree) && success1 ) next(&pl2);
loc2 .sa=rez1; 
if( !success1 ) goto _L104;

/* CALL #L */ 
pl3.ptrtype=packedlist;pl3.nel=1;pl3.cel=loc2.sa;
pl3.plistsize= 1;
r41(&wrk1.sa,&flag1,&pl3);/* #G_wyravenie*/ ;xxx; 

/* operator := */ 
selop( acnst[ 17 ],false,NULL, loc2 .sa ,& wrk1 .sa); 
loc3 .sa= wrk1 .sa ;xxx; 

/* operator := */ 
selop( acnst[ 19 ],false,NULL, loc2 .sa ,& wrk1 .sa); 
loc4 .sa= wrk1 .sa ;xxx; 

/* IF-operator */ 
/* operaciq = */ wrk1 .bo= eqatom( loc3 .sa ,acnst[ 18 ]) ; 
if( wrk1 .bo) 
{ 
outatm(acnst[15],"if(",true, true); 
outxt(acnst[ 15 ], loc4 .sa , false, true); 
outatm(acnst[15],".bo )",false, true); 
outxt(acnst[ 15 ], loc1 .sa , false, true); 
outatm(acnst[15],".bo=true; else {",false, true); ;xxx; 
goto _L101;
;} 
if( loc3 .sa!=NULL ) wrk2 .bo=true; else { 
selop( acnst[ 51 ],false,NULL, loc2 .sa ,& wrk1 .sa); wrk2 .bo= wrk1 .sa!=NULL 
;}; 
if( wrk2 .bo) 
{ 
outxt(acnst[ 15 ], loc1 .sa , true, true); 
outatm(acnst[15],".bo=true;",false, true); ;xxx; 
/* RETURN-op. */ 
rez1 = NULL 
;if (pl1.ptrtype!=ptrtree) next(&pl1) /*wyhod iz der.ili sp.*/ ;goto _L98 ;xxx; 
goto _L101;
;} 
/* operaciq = */ wrk1 .bo= eqatom( loc4 .sa ,acnst[ 24 ]) ; 
if( wrk1 .bo) 
{ 
outxt(acnst[ 15 ],NULL,true,false) ;xxx; 
goto _L101;
;} 
{ 
outatm(acnst[15],"if(",true, true); 
outxt(acnst[ 15 ], loc4 .sa , false, true); 
outatm(acnst[15],".sa!=NULL )",false, true); 
outxt(acnst[ 15 ], loc1 .sa , false, true); 
outatm(acnst[15],".bo=true; else {",false, true); ;xxx; 
;} 
_L101:;xxx; 
selop(acnst[71],false,0L,pl1.cel,&rez1);pl2.cel=rez1;
   if( rez1==NULL ) { success1=false;goto _L104;};

/* shablon peremennoj */ 
success1=(pl2.nel!=0);rez1=pl2.cel;
if( (pl2.ptrtype!=ptrtree) && success1 ) next(&pl2);
loc5 .sa=rez1; 
if( !success1 ) goto _L104;

/* CALL #L */ 
pl3.ptrtype=packedlist;pl3.nel=1;pl3.cel=loc5.sa;
pl3.plistsize= 1;
r41(&wrk1.sa,&flag1,&pl3);/* #G_wyravenie*/ ;xxx; 

/* operator := */ 
selop( acnst[ 17 ],false,NULL, loc5 .sa ,& wrk1 .sa); 
loc6 .sa= wrk1 .sa ;xxx; 

/* operator := */ 
selop( acnst[ 19 ],false,NULL, loc5 .sa ,& wrk1 .sa); 
loc7 .sa= wrk1 .sa ;xxx; 

/* IF-operator */ 
/* operaciq = */ wrk1 .bo= eqatom( loc6 .sa ,acnst[ 18 ]) ; 
if( wrk1 .bo) 
{ 
outxt(acnst[ 15 ], loc1 .sa , false, true); 
outatm(acnst[15],"=",false, true); 
outxt(acnst[ 15 ], loc7 .sa , false, true); ;xxx; 
goto _L102;
;} 
if( loc6 .sa!=NULL ) wrk2 .bo=true; else { 
selop( acnst[ 51 ],false,NULL, loc5 .sa ,& wrk1 .sa); wrk2 .bo= wrk1 .sa!=NULL 
;}; 
if( wrk2 .bo) 
{ 
outxt(acnst[ 15 ], loc1 .sa , false, true); 
outatm(acnst[15],".bo=true",false, true); ;xxx; 
goto _L102;
;} 
/* operaciq = */ wrk1 .bo= eqatom( loc7 .sa ,acnst[ 24 ]) ; 
if( wrk1 .bo) 
{ 
outxt(acnst[ 15 ], loc1 .sa , false, true); 
outatm(acnst[15],".bo=false",false, true); ;xxx; 
goto _L102;
;} 
{ 
outxt(acnst[ 15 ], loc1 .sa , false, true); 
outatm(acnst[15],".bo=",false, true); 
outxt(acnst[ 15 ], loc7 .sa , false, true); 
outatm(acnst[15],".sa!=NULL",false, true); ;xxx; 
;} 
_L102:;xxx; 

/* IF-operator */ 
/* operaciq = */ wrk1 .bo= eqatom( loc4 .sa ,acnst[ 24 ]) ; 
if( wrk1 .bo) 
{ 
outatm(acnst[15],";",false, true); ;xxx; 
goto _L103;
;} 
{ 
outatm(acnst[15],";};",false, true); ;xxx; 
;} 
_L103:;xxx; 
if( success1 ) {
 rez1=pl1.cel;if( pl1.ptrtype!=ptrtree ) next(&pl1) ;}
 else { rez1=NULL;goto _L104 ;};
goto _L99;  _L104:;  /* metka wyhoda po neuspehu wetwi */
 _L99: rez1=NULL; 
 _L98: *rez=rez1;*success=success1; 
 if (*success) *pl=pl1; /* prodwinutx ukazatelx leksem */ 
/* wosstanowitx GLOB */ 
#ifdef XX  
 d(2,"G_OR", 43 ,*rez,*success); 
#endif 
;};/* RULE */ 
/*===============================================*/ 
/* GENERATED TEXT OF RULE   #IS_CONSTRUCTOR   */ 
 Void r44(rez,success,pl)
long *rez;boolean *success;ptr_ *pl; 
{  a rez1;  boolean success1; long k; mpd x; 
v loc1;/* $OP*/ 
v loc2;/* $R*/ 
v wrk1;
v wrk2;
v wrk3;
v wrk4;
ptr_ pl1;
ptr_ pl2;
#ifdef XX  
 d(1,"IS_CONSTRUCTOR", 44 ,pl->cel,0); 
#endif 
/* sohranitx GLOB */ 

/* branch */ pl1=*pl;rez1=NULL;success1=true; 
/* inicializaciq peremennyh */ 
loc1.sa=NULL;/* $OP*/ 

/* shablon treemain */ rez1=pl1.cel;
success1=false;if(pl1.nel==0 ) goto _L101; 
 if (rez1!=NULL ) { pointr(rez1,&x.sa); 
       if (x.smld->dtype!= treemain )  
        { rez1=NULL;goto _L101;};
/* prowerka imeni */ 
loc1 .sa=x.smld->name; 
;}; 
pl2.nel=1;pl2.ptrtype=ptrtree;
success1=true; 
selop(acnst[19],false,0L,pl1.cel,&rez1);pl2.cel=rez1;
   if( rez1==NULL ) { success1=false;goto _L101;};

/* shablon peremennoj */ 
success1=(pl2.nel!=0);rez1=pl2.cel;
if( (pl2.ptrtype!=ptrtree) && success1 ) next(&pl2);
loc2 .sa=rez1; 
if( !success1 ) goto _L101;
if( success1 ) {
 rez1=pl1.cel;if( pl1.ptrtype!=ptrtree ) next(&pl1) ;}
 else { rez1=NULL;goto _L101 ;};

/* RETURN-op. */ 
/* operaciq = */ wrk1 .bo= eqatom( loc1 .sa ,acnst[ 76 ]) ; 
if( wrk1 .bo ) wrk3 .bo=true; else { 
/* operaciq = */ wrk2 .bo= eqatom( loc1 .sa ,acnst[ 77 ]) ; wrk3 = wrk2 ;}; 
if( wrk3 .bo ) wrk4 .sa=cnst[1].sa; else wrk4 .sa=NULL; 
rez1 = wrk4 .sa ;goto _L98 ;xxx; 
goto _L99;  _L101:;  /* metka wyhoda po neuspehu wetwi */
 _L99: rez1=NULL; 
 _L98: *rez=rez1;*success=success1; 
 if (*success) *pl=pl1; /* prodwinutx ukazatelx leksem */ 
/* wosstanowitx GLOB */ 
#ifdef XX  
 d(2,"IS_CONSTRUCTOR", 44 ,*rez,*success); 
#endif 
;};/* RULE */ 
/*===============================================*/ 
/* GENERATED TEXT OF RULE   #CONLIST   */ 
 Void r45(rez,success,pl)
long *rez;boolean *success;ptr_ *pl; 
{  a rez1;  boolean success1; long k; mpd x; 
v loc1;/* $REZ*/ 
v loc2;/* $E*/ 
ptr_ pl1;
ptr_ pl2;
ptr_ pl3;
#ifdef XX  
 d(1,"CONLIST", 45 ,pl->cel,0); 
#endif 
/* sohranitx GLOB */ 

/* branch */ pl1=*pl;rez1=NULL;success1=true; 
/* inicializaciq peremennyh */ 
loc1.sa=NULL;/* $REZ*/ 
loc2.sa=NULL;/* $E*/ 

/* shablon peremennoj */ 
success1=(pl1.nel!=0);rez1=pl1.cel;
if( (pl1.ptrtype!=ptrtree) && success1 ) next(&pl1);
loc1 .sa=rez1; 
if( !success1 ) goto _L102;

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

loc2 .sa=NULL; 

/* shablon prawila */ r37(&rez1,&success1,&pl2);
if( !success1 ) goto _L101;
loc2 .sa=rez1; 

outatm(acnst[15],"lconc(&",true, true); 
outxt(acnst[ 15 ], loc1 .sa , false, true); 
outatm(acnst[15],",",false, true); 
outxt(acnst[ 15 ], loc2 .sa , false, true); 
outatm(acnst[15],");",false, true); ;xxx; 
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
#ifdef XX  
 d(2,"CONLIST", 45 ,*rez,*success); 
#endif 
;};/* RULE */ 
/*===============================================*/ 
/* GENERATED TEXT OF RULE   #G_EQOP   */ 
 Void r46(rez,success,pl)
long *rez;boolean *success;ptr_ *pl; 
{  a rez1;  boolean success1; long k; mpd x; 
v loc1;/* $OP*/ 
v loc2;/* $E1*/ 
v loc3;/* $tip*/ 
v loc4;/* $mesto*/ 
v loc5;/* $E2*/ 
v loc6;/* $tip2*/ 
v loc7;/* $WRK*/ 
v loc8;/* $E*/ 
v loc9;/* $mesto2*/ 
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
ptr_ pl1;
ptr_ pl2;
ptr_ pl3;
boolean flag1;
#ifdef XX  
 d(1,"G_EQOP", 46 ,pl->cel,0); 
#endif 
/* sohranitx GLOB */ 

/* branch */ pl1=*pl;rez1=NULL;success1=true; 
/* inicializaciq peremennyh */ 
loc1.sa=NULL;/* $OP*/ 
loc2.sa=NULL;/* $E1*/ 
loc3.sa=NULL;/* $tip*/ 
loc4.sa=NULL;/* $mesto*/ 
loc5.sa=NULL;/* $E2*/ 
loc6.sa=NULL;/* $tip2*/ 
loc7.sa=NULL;/* $WRK*/ 
loc8.sa=NULL;/* $E*/ 
loc9.sa=NULL;/* $mesto2*/ 

/* shablon treemain */ rez1=pl1.cel;
success1=false;if(pl1.nel==0 ) goto _L120; 
 if (rez1!=NULL ) { pointr(rez1,&x.sa); 
       if (x.smld->dtype!= treemain )  
        { rez1=NULL;goto _L120;};
/* prowerka imeni */ 
loc1 .sa=x.smld->name; 
;}; 
pl2.nel=1;pl2.ptrtype=ptrtree;
success1=true; 
selop(acnst[70],false,0L,pl1.cel,&rez1);pl2.cel=rez1;
   if( rez1==NULL ) { success1=false;goto _L120;};

/* shablon peremennoj */ 
success1=(pl2.nel!=0);rez1=pl2.cel;
if( (pl2.ptrtype!=ptrtree) && success1 ) next(&pl2);
loc2 .sa=rez1; 
if( !success1 ) goto _L120;

/* IF-operator */ 
/* operaciq <> */ wrk1 .bo= ! eqatom( loc1 .sa ,acnst[ 99 ]) ; 
if( !( wrk1 .bo )) wrk3 .bo=false; else { 
/* operaciq <> */ wrk2 .bo= ! eqatom( loc1 .sa ,acnst[ 100 ]) ; wrk3 = wrk2 
;}/*log*/; 
if( wrk3 .bo) 
{ 
/* FAIL */ rez1=NULL;success1=false; 
if (pl1.ptrtype!=ptrtree) next(&pl1); /*wyhod iz der.ili sp.*/ 
goto _L120;xxx; 
;} 
_L101:;xxx; 

/* CALL #L */ 
pl3.ptrtype=packedlist;pl3.nel=1;pl3.cel=loc2.sa;
pl3.plistsize= 1;
r41(&wrk1.sa,&flag1,&pl3);/* #G_wyravenie*/ ;xxx; 

/* operator := */ 
selop( acnst[ 17 ],false,NULL, loc2 .sa ,& wrk1 .sa); 
loc3 .sa= wrk1 .sa ;xxx; 

/* operator := */ 
selop( acnst[ 19 ],false,NULL, loc2 .sa ,& wrk1 .sa); 
loc4 .sa= wrk1 .sa ;xxx; 
selop(acnst[71],false,0L,pl1.cel,&rez1);pl2.cel=rez1;
   if( rez1==NULL ) { success1=false;goto _L120;};

/* shablon peremennoj */ 
success1=(pl2.nel!=0);rez1=pl2.cel;
if( (pl2.ptrtype!=ptrtree) && success1 ) next(&pl2);
loc5 .sa=rez1; 
if( !success1 ) goto _L120;

/* CALL #L */ 
pl3.ptrtype=packedlist;pl3.nel=1;pl3.cel=loc5.sa;
pl3.plistsize= 1;
r41(&wrk1.sa,&flag1,&pl3);/* #G_wyravenie*/ ;xxx; 

/* operator := */ 
selop( acnst[ 17 ],false,NULL, loc5 .sa ,& wrk1 .sa); 
loc6 .sa= wrk1 .sa ;xxx; 
selop(acnst[19],false,0L,pl1.cel,&rez1);pl2.cel=rez1;
   if( rez1==NULL ) { success1=false;goto _L120;};

/* shablon peremennoj */ 
success1=(pl2.nel!=0);rez1=pl2.cel;
if( (pl2.ptrtype!=ptrtree) && success1 ) next(&pl2);
loc7 .sa=rez1; 
if( !success1 ) goto _L120;
if( success1 ) {
 rez1=pl1.cel;if( pl1.ptrtype!=ptrtree ) next(&pl1) ;}
 else { rez1=NULL;goto _L120 ;};

outatm(acnst[15],"/* operaciq",true, true); 
outxt(acnst[ 15 ], loc1 .sa , false, true); 
outatm(acnst[15],"*/",false, true); 
outxt(acnst[ 15 ], loc7 .sa , false, true); 
outatm(acnst[15],".bo=",false, true); ;xxx; 

/* IF-operator */ 
/* operaciq = */ wrk1 .bo= eqatom( loc3 .sa ,acnst[ 21 ]) ; 
if( !( wrk1 .bo )) wrk3 .bo=false; else { 
/* operaciq = */ wrk2 .bo= eqatom( loc6 .sa ,acnst[ 18 ]) ; wrk3 = wrk2 
;}/*log*/; 
if( wrk3 .bo ) wrk6 .bo=true; else { 
/* operaciq = */ wrk4 .bo= loc3 .sa ==NULL ; 
if( !( wrk4 .bo )) wrk5 .bo=false; else { wrk5 .bo= loc6 .sa!=NULL ;}/*log*/; 
wrk6 = wrk5 ;}; 
if( wrk6 .bo ) wrk10 .bo=true; else { 
/* operaciq = */ wrk7 .bo= eqatom( loc4 .sa ,acnst[ 24 ]) ; 
if( !( wrk7 .bo )) wrk9 .bo=false; else { 
/* operaciq = */ wrk8 .bo= loc6 .sa ==NULL ; wrk9 = wrk8 ;}/*log*/; wrk10 = wrk9
 ;}; 
if( wrk10 .bo) 
{ 
/* operator := */ 
loc8 .sa= loc2 .sa ;xxx; 
/* operator := */ 
loc2 .sa= loc5 .sa ;xxx; 
/* operator := */ 
loc5 .sa= loc8 .sa ;xxx; 
;} 
_L102:;xxx; 

/* operator := */ 
selop( acnst[ 17 ],false,NULL, loc2 .sa ,& wrk1 .sa); 
loc3 .sa= wrk1 .sa ;xxx; 

/* operator := */ 
/* CALL #L */ 
pl2.ptrtype=packedlist;pl2.nel=1;pl2.cel=loc2.sa;
pl2.plistsize= 1;
r47(&wrk1.sa,&flag1,&pl2);/* #mesto*/ ; 
loc4 .sa= wrk1 .sa ;xxx; 

/* operator := */ 
selop( acnst[ 17 ],false,NULL, loc5 .sa ,& wrk1 .sa); 
loc6 .sa= wrk1 .sa ;xxx; 

/* operator := */ 
/* CALL #L */ 
pl2.ptrtype=packedlist;pl2.nel=1;pl2.cel=loc5.sa;
pl2.plistsize= 1;
r47(&wrk1.sa,&flag1,&pl2);/* #mesto*/ ; 
loc9 .sa= wrk1 .sa ;xxx; 

/* IF-operator */ 
if( loc3 .sa==NULL ) wrk2 .bo=false; else { 
/* operaciq = */ wrk1 .bo= eqop(0L, loc3 .sa , loc6 .sa ) ; wrk2 = wrk1 ;}; 
if( wrk2 .bo) 
{ 
/* IF-operator */ 
/* operaciq = */ wrk1 .bo= eqatom( loc1 .sa ,acnst[ 99 ]) ; 
if( wrk1 .bo) 
{ 
/* operator := */ 
loc1 .sa= cnst[45] .sa ;xxx; 
goto _L104;
;} 
{ 
/* operator := */ 
loc1 .sa= cnst[46] .sa ;xxx; 
;} 
_L104:;xxx; 
outxt(acnst[ 15 ], loc4 .sa , false, true); 
outxt(acnst[ 15 ], loc1 .sa , false, true); 
outxt(acnst[ 15 ], loc9 .sa , false, true); ;xxx; 
goto _L103;
;} 
/* operaciq = */ wrk1 .bo= eqatom( loc3 .sa ,acnst[ 18 ]) ; 
if( wrk1 .bo) 
{ 
/* IF-operator */ 
selop( acnst[ 10 ],false,NULL, loc5 .sa ,& wrk1 .sa); 
/* operaciq = */ wrk2 .bo= eqnum( wrk1 .sa , 1L ) ; 
if( wrk2 .bo) 
{ 
/* IF-operator */ 
/* operaciq = */ wrk1 .bo= eqatom( loc1 .sa ,acnst[ 99 ]) ; 
if( wrk1 .bo) 
{ 
outxt(acnst[ 15 ], loc4 .sa , false, true); ;xxx; 
goto _L106;
;} 
{ 
outatm(acnst[15],"!(",false, true); 
outxt(acnst[ 15 ], loc4 .sa , false, true); 
outatm(acnst[15],")",false, true); ;xxx; 
;} 
_L106:;xxx; 
goto _L105;
;} 
selop( acnst[ 10 ],false,NULL, loc5 .sa ,& wrk1 .sa); 
wrk2 .bo= numval( wrk1 .sa) > 1L ; 
if( wrk2 .bo) 
{ 
/* IF-operator */ 
/* operaciq = */ wrk1 .bo= eqatom( loc1 .sa ,acnst[ 99 ]) ; 
if( wrk1 .bo) 
{ 
outatm(acnst[15],"false",false, true); ;xxx; 
goto _L107;
;} 
{ 
outatm(acnst[15],"true",false, true); ;xxx; 
;} 
_L107:;xxx; 
goto _L105;
;} 
/* operaciq = */ wrk1 .bo= eqatom( loc9 .sa ,acnst[ 24 ]) ; 
if( wrk1 .bo) 
{ 
/* IF-operator */ 
/* operaciq = */ wrk1 .bo= eqatom( loc1 .sa ,acnst[ 99 ]) ; 
if( wrk1 .bo) 
{ 
outatm(acnst[15],"!(",false, true); 
outxt(acnst[ 15 ], loc4 .sa , false, true); 
outatm(acnst[15],")",false, true); ;xxx; 
goto _L108;
;} 
{ 
outxt(acnst[ 15 ], loc4 .sa , false, true); ;xxx; 
;} 
_L108:;xxx; 
goto _L105;
;} 
/* operaciq = */ wrk1 .bo= loc6 .sa ==NULL ; 
if( wrk1 .bo) 
{ 
/* IF-operator */ 
/* operaciq = */ wrk1 .bo= eqatom( loc1 .sa ,acnst[ 100 ]) ; 
if( wrk1 .bo) 
{ 
outatm(acnst[15],"!",false, true); ;xxx; 
;} 
_L109:;xxx; 
outatm(acnst[15],"((",false, true); 
outxt(acnst[ 15 ], loc4 .sa , false, true); 
outatm(acnst[15],"&& eqop(0L,",false, true); 
outxt(acnst[ 15 ], loc9 .sa , false, true); 
outatm(acnst[15],",cnst[1].sa))||(!(",false, true); 
outxt(acnst[ 15 ], loc4 .sa , false, true); 
outatm(acnst[15],")&&(",false, true); 
outxt(acnst[ 15 ], loc9 .sa , false, true); 
outatm(acnst[15],"==NULL)))",false, true); ;xxx; 
goto _L105;
;} 
{ 
/* IF-operator */ 
/* operaciq = */ wrk1 .bo= eqatom( loc1 .sa ,acnst[ 99 ]) ; 
if( wrk1 .bo) 
{ 
outatm(acnst[15],"false",false, true); ;xxx; 
goto _L110;
;} 
{ 
outatm(acnst[15],"true",false, true); ;xxx; 
;} 
_L110:;xxx; 
;} 
_L105:;xxx; 
goto _L103;
;} 
/* operaciq = */ wrk1 .bo= eqatom( loc3 .sa ,acnst[ 21 ]) ; 
if( !( wrk1 .bo )) wrk3 .bo=false; else { 
/* operaciq = */ wrk2 .bo= loc6 .sa ==NULL ; wrk3 = wrk2 ;}/*log*/; 
if( !( wrk3 .bo )) wrk6 .bo=false; else { 
selop( acnst[ 10 ],false,NULL, loc5 .sa ,& wrk4 .sa); 
/* operaciq = */ wrk5 .bo= wrk4 .sa ==NULL ; wrk6 = wrk5 ;}/*log*/; 
if( wrk6 .bo) 
{ 
/* IF-operator */ 
/* operaciq = */ wrk1 .bo= eqatom( loc1 .sa ,acnst[ 100 ]) ; 
if( wrk1 .bo) 
{ 
outatm(acnst[15],"!",false, true); ;xxx; 
;} 
_L111:;xxx; 
/* IF-operator */ 
bltin(&wrk1,&flag1,loc9.sa,4L); 
if( wrk1 .sa!=NULL) 
{ 
/* operator := */ 
wrk1 .sa=NULL; 
lconc(& wrk1 .sa , loc9 .sa ); 
lconc(& wrk1 .sa , cnst[47] .sa ); 
first(wrk1.sa,&pl2);implod(&pl2,&wrk1.sa); 
loc9 .sa= wrk1 .sa ;xxx; 
;} 
_L112:;xxx; 
/* IF-operator */ 
bltin(&wrk1,&flag1,loc4.sa,4L); 
if( wrk1 .sa!=NULL) 
{ 
/* operator := */ 
wrk1 .sa=NULL; 
lconc(& wrk1 .sa , loc4 .sa ); 
lconc(& wrk1 .sa , cnst[47] .sa ); 
first(wrk1.sa,&pl2);implod(&pl2,&wrk1.sa); 
loc4 .sa= wrk1 .sa ;xxx; 
;} 
_L113:;xxx; 
outatm(acnst[15],"eqnum(",false, true); 
outxt(acnst[ 15 ], loc9 .sa , false, true); 
outatm(acnst[15],",",false, true); 
outxt(acnst[ 15 ], loc4 .sa , false, true); 
outatm(acnst[15],")",false, true); ;xxx; 
goto _L103;
;} 
/* operaciq = */ wrk1 .bo= eqatom( loc4 .sa ,acnst[ 24 ]) ; 
if( !( wrk1 .bo )) wrk3 .bo=false; else { 
/* operaciq = */ wrk2 .bo= eqatom( loc9 .sa ,acnst[ 24 ]) ; wrk3 = wrk2 
;}/*log*/; 
if( wrk3 .bo) 
{ 
/* IF-operator */ 
/* operaciq = */ wrk1 .bo= eqatom( loc1 .sa ,acnst[ 99 ]) ; 
if( wrk1 .bo) 
{ 
outatm(acnst[15],"true",false, true); ;xxx; 
goto _L114;
;} 
{ 
outatm(acnst[15],"false",false, true); ;xxx; 
;} 
_L114:;xxx; 
goto _L103;
;} 
/* operaciq = */ wrk1 .bo= loc3 .sa ==NULL ; 
if( wrk1 .bo) 
{ 
/* IF-operator */ 
/* operaciq = */ wrk1 .bo= eqatom( loc9 .sa ,acnst[ 24 ]) ; 
if( wrk1 .bo) 
{ 
/* IF-operator */ 
/* operaciq = */ wrk1 .bo= eqatom( loc1 .sa ,acnst[ 99 ]) ; 
if( wrk1 .bo) 
{ 
outxt(acnst[ 15 ], loc4 .sa , false, true); 
outatm(acnst[15],"==NULL",false, true); ;xxx; 
goto _L116;
;} 
{ 
outxt(acnst[ 15 ], loc4 .sa , false, true); 
outatm(acnst[15],"!=NULL",false, true); ;xxx; 
;} 
_L116:;xxx; 
goto _L115;
;} 
selop( acnst[ 10 ],false,NULL, loc5 .sa ,& wrk1 .sa); 
if( wrk1 .sa!=NULL) 
{ 
/* IF-operator */ 
/* operaciq = */ wrk1 .bo= eqatom( loc1 .sa ,acnst[ 100 ]) ; 
if( wrk1 .bo) 
{ 
outatm(acnst[15],"!",false, true); ;xxx; 
;} 
_L117:;xxx; 
outatm(acnst[15],"eqatom(",false, true); 
outxt(acnst[ 15 ], loc4 .sa , false, true); 
outatm(acnst[15],",acnst[",false, true); 
selop( acnst[ 10 ],false,NULL, loc5 .sa ,& wrk1 .sa); 
outxt(acnst[ 15 ], wrk1 .sa , false, true); 
outatm(acnst[15],"])",false, true); ;xxx; 
goto _L115;
;} 
{ 
/* IF-operator */ 
/* operaciq = */ wrk1 .bo= eqatom( loc1 .sa ,acnst[ 100 ]) ; 
if( wrk1 .bo) 
{ 
outatm(acnst[15],"!",false, true); ;xxx; 
;} 
_L118:;xxx; 
outatm(acnst[15],"eqop(0L,",false, true); 
outxt(acnst[ 15 ], loc4 .sa , false, true); 
outatm(acnst[15],",",false, true); 
outxt(acnst[ 15 ], loc9 .sa , false, true); 
outatm(acnst[15],")",false, true); ;xxx; 
;} 
_L115:;xxx; 
goto _L103;
;} 
{ 
/* IF-operator */ 
/* operaciq = */ wrk1 .bo= eqatom( loc1 .sa ,acnst[ 99 ]) ; 
if( wrk1 .bo) 
{ 
outatm(acnst[15],"false",false, true); ;xxx; 
goto _L119;
;} 
{ 
outatm(acnst[15],"true",false, true); ;xxx; 
;} 
_L119:;xxx; 
;} 
_L103:;xxx; 

outatm(acnst[15],";",false, true); ;xxx; 
goto _L99;  _L120:;  /* metka wyhoda po neuspehu wetwi */
 _L99: rez1=NULL; 
 _L98: *rez=rez1;*success=success1; 
 if (*success) *pl=pl1; /* prodwinutx ukazatelx leksem */ 
/* wosstanowitx GLOB */ 
#ifdef XX  
 d(2,"G_EQOP", 46 ,*rez,*success); 
#endif 
;};/* RULE */ 
/*===============================================*/ 
/* GENERATED TEXT OF RULE   #mesto   */ 
 Void r47(rez,success,pl)
long *rez;boolean *success;ptr_ *pl; 
{  a rez1;  boolean success1; long k; mpd x; 
v loc1;/* $M*/ 
v loc2;/* $C*/ 
v wrk1;
ptr_ pl1;
ptr_ pl2;
#ifdef XX  
 d(1,"mesto", 47 ,pl->cel,0); 
#endif 
/* sohranitx GLOB */ 

/* branch */ pl1=*pl;rez1=NULL;success1=true; 
/* inicializaciq peremennyh */ 
loc1.sa=NULL;/* $M*/ 

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
if( success1 ) {
 rez1=pl1.cel;if( pl1.ptrtype!=ptrtree ) next(&pl1) ;}
 else { rez1=NULL;goto _L101 ;};

/* RETURN-op. */ 
wrk1 .sa =NULL; 
lconc(& wrk1 .sa , loc1 .sa ); 
lconc(& wrk1 .sa , cnst[48] .sa ); 
rez1 = wrk1 .sa ;goto _L98 ;xxx; 
goto _L99;  _L101:;  /* metka wyhoda po neuspehu wetwi */

/* branch */ pl1=*pl;rez1=NULL;success1=true; 
/* inicializaciq peremennyh */ 
loc1.sa=NULL;/* $M*/ 
loc2.sa=NULL;/* $C*/ 

/* shablon treemain */ rez1=pl1.cel;
success1=false;if(pl1.nel==0 ) goto _L103; 
 if (rez1!=NULL ) { pointr(rez1,&x.sa); 
       if (x.smld->dtype!= treemain )  
        { rez1=NULL;goto _L103;};
/* prowerka imeni */ 
loc2 .sa=x.smld->name; 
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
if( success1 ) {
 rez1=pl1.cel;if( pl1.ptrtype!=ptrtree ) next(&pl1) ;}
 else { rez1=NULL;goto _L103 ;};

/* IF-operator */ 
/* operaciq = */ wrk1 .bo= eqatom( loc2 .sa ,acnst[ 78 ]) ; 
if( wrk1 .bo) 
{ 
/* RETURN-op. */ 
rez1 = loc1 .sa ;goto _L98 ;xxx; 
goto _L102;
;} 
{ 
/* RETURN-op. */ 
wrk1 .sa =NULL; 
lconc(& wrk1 .sa , loc1 .sa ); 
lconc(& wrk1 .sa , cnst[20] .sa ); 
rez1 = wrk1 .sa ;goto _L98 ;xxx; 
;} 
_L102:;xxx; 
goto _L99;  _L103:;  /* metka wyhoda po neuspehu wetwi */

/* branch */ pl1=*pl;rez1=NULL;success1=true; 
/* inicializaciq peremennyh */ 

/* shablon treemain */ rez1=pl1.cel;
success1=false;if(pl1.nel==0 ) goto _L104; 
 if (rez1!=NULL ) { pointr(rez1,&x.sa); 
       if (x.smld->dtype!= treemain )  
        { rez1=NULL;goto _L104;};
;}; 
pl2.nel=1;pl2.ptrtype=ptrtree;
success1=true; 
selop(acnst[19],false,0L,pl1.cel,&rez1);pl2.cel=rez1;
   if( rez1==NULL ) { success1=false;goto _L104;};

/* shablon atoma */ atmpat(acnst[24],&pl2,&rez1,&success1);
if( !success1 ) goto _L104;
if( success1 ) {
 rez1=pl1.cel;if( pl1.ptrtype!=ptrtree ) next(&pl1) ;}
 else { rez1=NULL;goto _L104 ;};

/* RETURN-op. */ 
rez1 = cnst[24] .sa ;goto _L98 ;xxx; 
goto _L99;  _L104:;  /* metka wyhoda po neuspehu wetwi */

/* branch */ pl1=*pl;rez1=NULL;success1=true; 
/* inicializaciq peremennyh */ 
loc1.sa=NULL;/* $M*/ 

/* shablon treemain */ rez1=pl1.cel;
success1=false;if(pl1.nel==0 ) goto _L105; 
 if (rez1!=NULL ) { pointr(rez1,&x.sa); 
       if (x.smld->dtype!= treemain )  
        { rez1=NULL;goto _L105;};
;}; 
pl2.nel=1;pl2.ptrtype=ptrtree;
success1=true; 
selop(acnst[19],false,0L,pl1.cel,&rez1);pl2.cel=rez1;
   if( rez1==NULL ) { success1=false;goto _L105;};

/* shablon peremennoj */ 
success1=(pl2.nel!=0);rez1=pl2.cel;
if( (pl2.ptrtype!=ptrtree) && success1 ) next(&pl2);
loc1 .sa=rez1; 
if( !success1 ) goto _L105;
if( success1 ) {
 rez1=pl1.cel;if( pl1.ptrtype!=ptrtree ) next(&pl1) ;}
 else { rez1=NULL;goto _L105 ;};

/* RETURN-op. */ 
wrk1 .sa =NULL; 
lconc(& wrk1 .sa , loc1 .sa ); 
lconc(& wrk1 .sa , cnst[18] .sa ); 
rez1 = wrk1 .sa ;goto _L98 ;xxx; 
goto _L99;  _L105:;  /* metka wyhoda po neuspehu wetwi */
 _L99: rez1=NULL; 
 _L98: *rez=rez1;*success=success1; 
 if (*success) *pl=pl1; /* prodwinutx ukazatelx leksem */ 
/* wosstanowitx GLOB */ 
#ifdef XX  
 d(2,"mesto", 47 ,*rez,*success); 
#endif 
;};/* RULE */ 
/*===============================================*/ 
/* GENERATED TEXT OF RULE   #~islo_ili_0   */ 
 Void r48(rez,success,pl)
long *rez;boolean *success;ptr_ *pl; 
{  a rez1;  boolean success1; long k; mpd x; 
v loc0;/* $_*/ 
v loc1;/* $N*/ 
v loc2;/* $WRK*/ 
v wrk1;
v wrk2;
v wrk3;
v wrk4;
ptr_ pl1;
ptr_ pl2;
boolean flag1;
#ifdef XX  
 d(1,"~islo_ili_0", 48 ,pl->cel,0); 
#endif 
/* sohranitx GLOB */ 
loc0.sa=pl->cel; 

/* branch */ pl1=*pl;rez1=NULL;success1=true; 
/* inicializaciq peremennyh */ 
loc1.sa=NULL;/* $N*/ 

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

/* shablon atoma */ atmpat(acnst[21],&pl2,&rez1,&success1);
if( !success1 ) goto _L101;
selop(acnst[51],false,0L,pl1.cel,&rez1);pl2.cel=rez1;
   if( rez1==NULL ) { success1=false;goto _L101;};

/* shablon peremennoj */ 
varpat(&pl2,number,&rez1,&success1);
loc1 .sa=rez1; 
if( !success1 ) goto _L101;
if( success1 ) {
 rez1=pl1.cel;if( pl1.ptrtype!=ptrtree ) next(&pl1) ;}
 else { rez1=NULL;goto _L101 ;};

/* RETURN-op. */ 
wrk1 .sa=NULL; 
lconc(& wrk1 .sa , loc1 .sa ); 
lconc(& wrk1 .sa , cnst[47] .sa ); 
first(wrk1.sa,&pl2);implod(&pl2,&wrk1.sa); 
rez1 = wrk1 .sa ;goto _L98 ;xxx; 
goto _L99;  _L101:;  /* metka wyhoda po neuspehu wetwi */

/* branch */ pl1=*pl;rez1=NULL;success1=true; 
/* inicializaciq peremennyh */ 
loc2.sa=NULL;/* $WRK*/ 

/* shablon treemain */ rez1=pl1.cel;
success1=false;if(pl1.nel==0 ) goto _L102; 
 if (rez1!=NULL ) { pointr(rez1,&x.sa); 
       if (x.smld->dtype!= treemain )  
        { rez1=NULL;goto _L102;};
;}; 
pl2.nel=1;pl2.ptrtype=ptrtree;
success1=true; 
selop(acnst[17],false,0L,pl1.cel,&rez1);pl2.cel=rez1;
   if( rez1==NULL ) { success1=false;goto _L102;};

/* shablon atoma */ atmpat(acnst[21],&pl2,&rez1,&success1);
if( !success1 ) goto _L102;
selop(acnst[19],false,0L,pl1.cel,&rez1);pl2.cel=rez1;
   if( rez1==NULL ) { success1=false;goto _L102;};

/* shablon peremennoj */ 
success1=(pl2.nel!=0);rez1=pl2.cel;
if( (pl2.ptrtype!=ptrtree) && success1 ) next(&pl2);
loc2 .sa=rez1; 
if( !success1 ) goto _L102;
if( success1 ) {
 rez1=pl1.cel;if( pl1.ptrtype!=ptrtree ) next(&pl1) ;}
 else { rez1=NULL;goto _L102 ;};

/* RETURN-op. */ 
wrk1 .sa =NULL; 
lconc(& wrk1 .sa , loc2 .sa ); 
lconc(& wrk1 .sa , cnst[20] .sa ); 
rez1 = wrk1 .sa ;goto _L98 ;xxx; 
goto _L99;  _L102:;  /* metka wyhoda po neuspehu wetwi */

/* branch */ pl1=*pl;rez1=NULL;success1=true; 
/* inicializaciq peremennyh */ 

/* IF-operator */ 
selop( acnst[ 17 ],false,NULL, loc0 .sa ,& wrk1 .sa); 
if( wrk1 .sa!=NULL ) wrk4 .bo=true; else { 
selop( acnst[ 19 ],false,NULL, loc0 .sa ,& wrk2 .sa); 
/* operaciq = */ wrk3 .bo= eqatom( wrk2 .sa ,acnst[ 24 ]) ; wrk4 = wrk3 ;}; 
if( wrk4 .bo) 
{ 
/* RETURN-op. */ 
rez1 = cnst[49] .sa ;goto _L98 ;xxx; 
goto _L103;
;} 
{ 
/* RETURN-op. */ 
wrk2 .sa =NULL; 
lconc(& wrk2 .sa , cnst[22] .sa ); 
selop( acnst[ 19 ],false,NULL, loc0 .sa ,& wrk1 .sa); 
lconc(& wrk2 .sa , wrk1 .sa ); 
lconc(& wrk2 .sa , cnst[23] .sa ); 
rez1 = wrk2 .sa ;goto _L98 ;xxx; 
;} 
_L103:;xxx; 
goto _L99;  _L104:;  /* metka wyhoda po neuspehu wetwi */
 _L99: rez1=NULL; 
 _L98: *rez=rez1;*success=success1; 
 if (*success) *pl=pl1; /* prodwinutx ukazatelx leksem */ 
/* wosstanowitx GLOB */ 
#ifdef XX  
 d(2,"~islo_ili_0", 48 ,*rez,*success); 
#endif 
;};/* RULE */ 
