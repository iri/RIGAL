
#include "globrig.h" 
#include "define.h"  
#include "defpage.h" 
#include "nef2.h"    
#include "c1.h"      
#include "usemod.h"  
#include "def180.h"  
#include "xcrg.h"    
/*  R69 G_PATTERN */ 
/*===============================================*/ 
/* GENERATED TEXT OF RULE   #G_PATTERN   */ 
 Void r69(rez,success,pl)
long *rez;boolean *success;ptr_ *pl; 
{  a rez1;  boolean success1; long k; mpd x; 
v loc0;/* $_*/ 
v loc1;/* $N*/ 
v loc2;/* $D*/ 
v loc3;/* $A*/ 
v loc4;/* $TIP*/ 
v loc5;/* $NPL*/ 
v loc6;/* $OLDPL*/ 
v loc7;/* $ID*/ 
v loc8;/* $P*/ 
v wrk1;
v wrk2;
ptr_ pl1;
ptr_ pl2;
ptr_ pl3;
ptr_ pl4;
ptr_ pl5;
boolean flag1;
#ifdef XX  
 d(1,"G_PATTERN", 69 ,pl->cel,0); 
#endif 
/* sohranitx GLOB */ 
loc0.sa=pl->cel; 

/* branch */ pl1=*pl;rez1=NULL;success1=true; 
/* inicializaciq peremennyh */ 
loc1.sa=NULL;/* $N*/ 

outxt(acnst[ 15 ],NULL,true,false) ;xxx; 

/* shablon treemain */ rez1=pl1.cel;
success1=false;if(pl1.nel==0 ) goto _L101; 
 if (rez1!=NULL ) { pointr(rez1,&x.sa); 
       if (x.smld->dtype!= treemain )  
        { rez1=NULL;goto _L101;};
/* prowerka imeni */ 
success1=eqatom(x.smld->name,acnst[ 112 ]); 
if( ! success1 ) { rez1=NULL;goto _L101;};
;}; 
pl2.nel=1;pl2.ptrtype=ptrtree;
success1=true; 
selop(acnst[19],false,0L,pl1.cel,&rez1);pl2.cel=rez1;
   if( rez1==NULL ) { success1=false;goto _L101;};

/* shablon peremennoj */ 
varpat(&pl2,number,&rez1,&success1);
loc1 .sa=rez1; 
if( !success1 ) goto _L101;
if( success1 ) {
 rez1=pl1.cel;if( pl1.ptrtype!=ptrtree ) next(&pl1) ;}
 else { rez1=NULL;goto _L101 ;};

outatm(acnst[15],"/* shablon atoma */",true, true); 
outatm(acnst[15],"atmpat(acnst[",false, false); 
outxt(acnst[ 15 ], loc1 .sa , false, false); 
outxt(acnst[ 15 ], cnst[71] .sa , false, false); 
outxt(acnst[ 15 ], glob3_3 .sa , false, false); 
outatm(acnst[15],",&rez1,&success1);",false, false); ;xxx; 

/* CALL #L */ 
pl2.ptrtype=ptrlist;pl2.nel=0;pl2.cel=NULL;
r61(&wrk1.sa,&flag1,&pl2);/* #ss14*/ ;xxx; 
goto _L99;  _L101:;  /* metka wyhoda po neuspehu wetwi */

/* branch */ pl1=*pl;rez1=NULL;success1=true; 
/* inicializaciq peremennyh */ 
loc1.sa=NULL;/* $N*/ 

/* shablon treemain */ rez1=pl1.cel;
success1=false;if(pl1.nel==0 ) goto _L102; 
 if (rez1!=NULL ) { pointr(rez1,&x.sa); 
       if (x.smld->dtype!= treemain )  
        { rez1=NULL;goto _L102;};
/* prowerka imeni */ 
success1=eqatom(x.smld->name,acnst[ 112 ]); 
if( ! success1 ) { rez1=NULL;goto _L102;};
;}; 
pl2.nel=1;pl2.ptrtype=ptrtree;
success1=true; 
selop(acnst[51],false,0L,pl1.cel,&rez1);pl2.cel=rez1;
   if( rez1==NULL ) { success1=false;goto _L102;};

/* shablon peremennoj */ 
varpat(&pl2,number,&rez1,&success1);
loc1 .sa=rez1; 
if( !success1 ) goto _L102;
if( success1 ) {
 rez1=pl1.cel;if( pl1.ptrtype!=ptrtree ) next(&pl1) ;}
 else { rez1=NULL;goto _L102 ;};

outatm(acnst[15],"/* shablon ~islowogo atoma */",true, true); ;xxx; 

/* CALL #L */ 
pl2.ptrtype=ptrlist;pl2.nel=0;pl2.cel=NULL;
r56(&wrk1.sa,&flag1,&pl2);/* #ss9*/ ;xxx; 

outatm(acnst[15],"==number)",false, true); ;xxx; 

outatm(acnst[15],"    &&(x.snd->val==",true, true); 
outxt(acnst[ 15 ], loc1 .sa , false, true); ;xxx; 

/* CALL #L */ 
pl2.ptrtype=ptrlist;pl2.nel=0;pl2.cel=NULL;
r57(&wrk1.sa,&flag1,&pl2);/* #ss10*/ ;xxx; 
goto _L99;  _L102:;  /* metka wyhoda po neuspehu wetwi */

/* branch */ pl1=*pl;rez1=NULL;success1=true; 
/* inicializaciq peremennyh */ 

/* shablon listmain */ rez1=pl1.cel;
success1=false;if(pl1.nel==0 ) goto _L103; 
 if (rez1!=NULL ) { pointr(rez1,&x.sa); 
       if (x.smld->dtype!= listmain )  
        { rez1=NULL;goto _L103;};
/* prowerka imeni */ 
success1=eqatom(x.smld->name,acnst[ 24 ]); 
if( ! success1 ) { rez1=NULL;goto _L103;};
{pl2.ptrtype=ptrlist; pl2.nel=1;
pl2.cel=x.smld->elt[0];pl2.UU.U1.curfragment=rez1;}
;} else  
{pl2.ptrtype=ptrlist;pl2.nel=0;pl2.cel=NULL;}

/* shablon atoma */ atmpat(acnst[1],&pl2,&rez1,&success1);
if( !success1 ) goto _L103;

if( pl2.nel !=0 )
{ success1=false;rez1=NULL;goto _L103;};
success1=true;rez1=pl1.cel;
 if( pl1.ptrtype!=ptrtree ) next(&pl1);

outatm(acnst[15],"/* shablon NULL */",true, true); 
outxt(acnst[ 15 ], cnst[72] .sa , false, false); 
outxt(acnst[ 15 ], glob3_3 .sa , false, false); 
outxt(acnst[ 15 ], cnst[73] .sa , false, false); 
outxt(acnst[ 15 ], glob3_3 .sa , false, false); 
outatm(acnst[15],".nel!=0);rez1=NULL;",false, false); ;xxx; 

outatm(acnst[15],"if( success1 ) { if( ",true, true); 
outxt(acnst[ 15 ], cnst[70] .sa , false, false); 
outxt(acnst[ 15 ], glob3_3 .sa , false, false); 
outxt(acnst[ 15 ], cnst[59] .sa , false, false); 
outxt(acnst[ 15 ], glob3_3 .sa , false, false); 
outatm(acnst[15],") ;}",false, false); ;xxx; 

outatm(acnst[15],"   else",true, true); 
outxt(acnst[ 15 ], cnst[74] .sa , false, false); 
outxt(acnst[ 15 ], glob10_2 .sa , false, false); 
outatm(acnst[15],";",false, false); ;xxx; 
goto _L99;  _L103:;  /* metka wyhoda po neuspehu wetwi */

/* branch */ pl1=*pl;rez1=NULL;success1=true; 
/* inicializaciq peremennyh */ 
loc2.sa=NULL;/* $D*/ 
loc3.sa=NULL;/* $A*/ 
loc4.sa=NULL;/* $TIP*/ 

/* shablon treemain */ rez1=pl1.cel;
success1=false;if(pl1.nel==0 ) goto _L106; 
 if (rez1!=NULL ) { pointr(rez1,&x.sa); 
       if (x.smld->dtype!= treemain )  
        { rez1=NULL;goto _L106;};
/* prowerka imeni */ 
success1=eqatom(x.smld->name,acnst[ 41 ]); 
if( ! success1 ) { rez1=NULL;goto _L106;};
;}; 
pl2.nel=1;pl2.ptrtype=ptrtree;
success1=true; 
selop(acnst[26],false,0L,pl1.cel,&rez1);pl2.cel=rez1;
   if( rez1==NULL ) { success1=false;goto _L106;};

/* shablon peremennoj */ 
success1=(pl2.nel!=0);rez1=pl2.cel;
if( (pl2.ptrtype!=ptrtree) && success1 ) next(&pl2);
loc2 .sa=rez1; 
if( !success1 ) goto _L106;
if( success1 ) {
 rez1=pl1.cel;if( pl1.ptrtype!=ptrtree ) next(&pl1) ;}
 else { rez1=NULL;goto _L106 ;};

/* CALL #L */ 
pl2.ptrtype=packedlist;pl2.nel=1;pl2.cel=loc0.sa;
pl2.plistsize= 1;
r41(&wrk1.sa,&flag1,&pl2);/* #G_wyravenie*/ ;xxx; 

outatm(acnst[15],"/* shablon peremennoj */",true, true); ;xxx; 

/* operator := */ 
if( loc2 .sa ==NULL ) wrk1 .sa=NULL; else explod( loc2 .sa ,& wrk1 .sa) ; 
indxop( 1L,false,NULL, wrk1 .sa ,& wrk2 .sa); 
loc3 .sa= wrk2 .sa ;xxx; 

/* IF-operator */ 
/* operaciq = */ wrk1 .bo= eqatom( loc3 .sa ,acnst[ 113 ]) ; 
if( wrk1 .bo) 
{ 
/* operator := */ 
loc4 .sa= cnst[51] .sa ;xxx; 
goto _L104;
;} 
/* operaciq = */ wrk1 .bo= eqatom( loc3 .sa ,acnst[ 3 ]) ; 
if( wrk1 .bo) 
{ 
/* operator := */ 
loc4 .sa= cnst[75] .sa ;xxx; 
;} 
_L104:;xxx; 

/* IF-operator */ 
if( loc4 .sa!=NULL) 
{ 
outxt(acnst[ 15 ], cnst[76] .sa , true, false); 
outxt(acnst[ 15 ], glob3_3 .sa , false, false); 
outatm(acnst[15],",",false, false); 
outxt(acnst[ 15 ], loc4 .sa , false, false); 
outatm(acnst[15],",&rez1,&success1);",false, false); ;xxx; 
goto _L105;
;} 
{ 
outxt(acnst[ 15 ], cnst[72] .sa , true, false); 
outxt(acnst[ 15 ], glob3_3 .sa , false, false); 
outatm(acnst[15],".nel!=0);",false, false); 
outxt(acnst[ 15 ], cnst[61] .sa , false, false); 
outxt(acnst[ 15 ], glob3_3 .sa , false, false); 
outatm(acnst[15],".cel;",false, false); ;xxx; 
outxt(acnst[ 15 ], cnst[77] .sa , true, false); 
outxt(acnst[ 15 ], glob3_3 .sa , false, false); 
outxt(acnst[ 15 ], cnst[78] .sa , false, false); 
outxt(acnst[ 15 ], glob3_3 .sa , false, false); 
outatm(acnst[15],");",false, false); ;xxx; 
;} 
_L105:;xxx; 

selop( acnst[ 19 ],false,NULL, loc0 .sa ,& wrk1 .sa); 
outxt(acnst[ 15 ], wrk1 .sa , true, true); 
outatm(acnst[15],".sa=rez1;",false, true); ;xxx; 

/* CALL #L */ 
pl2.ptrtype=ptrlist;pl2.nel=0;pl2.cel=NULL;
r61(&wrk1.sa,&flag1,&pl2);/* #ss14*/ ;xxx; 
goto _L99;  _L106:;  /* metka wyhoda po neuspehu wetwi */

/* branch */ pl1=*pl;rez1=NULL;success1=true; 
/* inicializaciq peremennyh */ 

/* shablon prawila */ r70(&rez1,&success1,&pl1);
if( !success1 ) goto _L107;
goto _L99;  _L107:;  /* metka wyhoda po neuspehu wetwi */

/* branch */ pl1=*pl;rez1=NULL;success1=true; 
/* inicializaciq peremennyh */ 
loc5.sa=NULL;/* $NPL*/ 
loc6.sa=NULL;/* $OLDPL*/ 

/* shablon treemain */ rez1=pl1.cel;
success1=false;if(pl1.nel==0 ) goto _L113; 
 if (rez1!=NULL ) { pointr(rez1,&x.sa); 
       if (x.smld->dtype!= treemain )  
        { rez1=NULL;goto _L113;};
/* prowerka imeni */ 
success1=eqatom(x.smld->name,acnst[ 114 ]); 
if( ! success1 ) { rez1=NULL;goto _L113;};
;}; 
pl2.nel=1;pl2.ptrtype=ptrtree;
success1=true; 
selop(acnst[115],false,0L,pl1.cel,&rez1);pl2.cel=rez1;
   if( rez1==NULL ) { success1=false;goto _L113;};

/* shablon peremennoj */ 
varpat(&pl2,number,&rez1,&success1);
loc5 .sa=rez1; 
if( !success1 ) goto _L113;

/* CALL #L */ 
pl3.ptrtype=packedlist;pl3.nel=1;pl3.cel=cnst[79].sa;
pl3.plistsize= 1;
r58(&wrk1.sa,&flag1,&pl3);/* #ss11*/ ;xxx; 
selop(acnst[26],false,0L,pl1.cel,&rez1);pl2.cel=rez1;
   if( rez1==NULL ) { success1=false;goto _L108;};

/* shablon prawila */ r18(&rez1,&success1,&pl2);
if( !success1 ) goto _L108;
_L108:success1=true;
selop(acnst[39],false,0L,pl1.cel,&rez1);pl2.cel=rez1;
   if( rez1==NULL ) { success1=false;goto _L113;};

/* operator := */ 
loc6 .sa= glob3_3 .sa ;xxx; 

/* operator := */ 
glob3_3 .sa= loc5 .sa ;xxx; 

/* operator +:= */ 
addnum(& glob10_3 .sa, 1L ) ;xxx; 

/* CALL #L */ 
pl3.ptrtype=packedlist;pl3.nel=1;pl3.cel=glob3_3.sa;
pl3.plistsize= 1;
r59(&wrk1.sa,&flag1,&pl3);/* #ss12*/ ;xxx; 

/* CALL #L */ 
pl3.ptrtype=ptrlist;pl3.nel=0;pl3.cel=NULL;
r62(&wrk1.sa,&flag1,&pl3);/* #ss17*/ ;xxx; 

/* shablon listmain */ rez1=pl2.cel;
success1=false;if(pl2.nel==0 ) goto _L113; 
 if (rez1!=NULL ) { pointr(rez1,&x.sa); 
       if (x.smld->dtype!= listmain )  
        { rez1=NULL;goto _L113;};
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
if( !success1 ) goto _L109;
goto _L111/*uspeh*/;
_L109:; 
pl3=pl5;

/* shablon prawila */ r63(&rez1,&success1,&pl3);
if( !success1 ) goto _L110;
goto _L111/*uspeh*/;
_L110:; 
pl3=pl5;
goto  _L112;
_L111:;/*uspeh alxtern.*/
 pl4=pl3;
;}; 
_L112:if( ! success1 )pl3=pl4;
success1 = true ; 

if( pl3.nel !=0 )
{ success1=false;rez1=NULL;goto _L113;};
success1=true;rez1=pl2.cel;
 if( pl2.ptrtype!=ptrtree ) next(&pl2);
if( success1 ) {
 rez1=pl1.cel;if( pl1.ptrtype!=ptrtree ) next(&pl1) ;}
 else { rez1=NULL;goto _L113 ;};

outxt(acnst[ 15 ],NULL,true,false) ;xxx; 

outatm(acnst[15],"if( pl",true, false); 
outxt(acnst[ 15 ], loc5 .sa , false, false); 
outatm(acnst[15],".nel !=0 )",false, false); ;xxx; 

/* operator +:= */ 
wrk1 .nu=- 1L ; 
addnum(& glob10_3 .sa, wrk1 .nu ) ;xxx; 

/* operator := */ 
glob3_3 .sa= loc6 .sa ;xxx; 

/* CALL #L */ 
pl2.ptrtype=ptrlist;pl2.nel=0;pl2.cel=NULL;
r60(&wrk1.sa,&flag1,&pl2);/* #ss13*/ ;xxx; 
goto _L99;  _L113:;  /* metka wyhoda po neuspehu wetwi */

/* branch */ pl1=*pl;rez1=NULL;success1=true; 
/* inicializaciq peremennyh */ 
loc1.sa=NULL;/* $N*/ 
loc7.sa=NULL;/* $ID*/ 

/* shablon listmain */ rez1=pl1.cel;
success1=false;if(pl1.nel==0 ) goto _L114; 
 if (rez1!=NULL ) { pointr(rez1,&x.sa); 
       if (x.smld->dtype!= listmain )  
        { rez1=NULL;goto _L114;};
/* prowerka imeni */ 
success1=eqatom(x.smld->name,acnst[ 116 ]); 
if( ! success1 ) { rez1=NULL;goto _L114;};
{pl2.ptrtype=ptrlist; pl2.nel=1;
pl2.cel=x.smld->elt[0];pl2.UU.U1.curfragment=rez1;}
;} else  
{pl2.ptrtype=ptrlist;pl2.nel=0;pl2.cel=NULL;}

/* shablon peremennoj */ 
varpat(&pl2,idatom,&rez1,&success1);
loc7 .sa=rez1; 
if( !success1 ) goto _L114;

if( pl2.nel !=0 )
{ success1=false;rez1=NULL;goto _L114;};
success1=true;rez1=pl1.cel;
 if( pl1.ptrtype!=ptrtree ) next(&pl1);

/* operator := */ 
selop( 0L,true, loc7 .sa, glob1_3 .sa ,& wrk1 .sa); 
loc1 .sa= wrk1 .sa ;xxx; 

outatm(acnst[15],"/* shablon prawila */",true, true); 
outatm(acnst[15],"r",false, false); 
outxt(acnst[ 15 ], loc1 .sa , false, false); 
outxt(acnst[ 15 ], cnst[80] .sa , false, false); 
outxt(acnst[ 15 ], glob3_3 .sa , false, false); 
outatm(acnst[15],");",false, false); ;xxx; 

/* CALL #L */ 
pl2.ptrtype=ptrlist;pl2.nel=0;pl2.cel=NULL;
r61(&wrk1.sa,&flag1,&pl2);/* #ss14*/ ;xxx; 
goto _L99;  _L114:;  /* metka wyhoda po neuspehu wetwi */

/* branch */ pl1=*pl;rez1=NULL;success1=true; 
/* inicializaciq peremennyh */ 
loc1.sa=NULL;/* $N*/ 

/* shablon listmain */ rez1=pl1.cel;
success1=false;if(pl1.nel==0 ) goto _L115; 
 if (rez1!=NULL ) { pointr(rez1,&x.sa); 
       if (x.smld->dtype!= listmain )  
        { rez1=NULL;goto _L115;};
/* prowerka imeni */ 
success1=eqatom(x.smld->name,acnst[ 117 ]); 
if( ! success1 ) { rez1=NULL;goto _L115;};
{pl2.ptrtype=ptrlist; pl2.nel=1;
pl2.cel=x.smld->elt[0];pl2.UU.U1.curfragment=rez1;}
;} else  
{pl2.ptrtype=ptrlist;pl2.nel=0;pl2.cel=NULL;}

/* shablon peremennoj */ 
varpat(&pl2,number,&rez1,&success1);
loc1 .sa=rez1; 
if( !success1 ) goto _L115;

if( pl2.nel !=0 )
{ success1=false;rez1=NULL;goto _L115;};
success1=true;rez1=pl1.cel;
 if( pl1.ptrtype!=ptrtree ) next(&pl1);

outxt(acnst[ 15 ], cnst[81] .sa , true, false); 
outxt(acnst[ 15 ], glob3_3 .sa , false, false); 
outatm(acnst[15],",",false, false); 
outxt(acnst[ 15 ], loc1 .sa , false, false); 
outatm(acnst[15],"L);",false, false); ;xxx; 

/* CALL #L */ 
pl2.ptrtype=ptrlist;pl2.nel=0;pl2.cel=NULL;
r61(&wrk1.sa,&flag1,&pl2);/* #ss14*/ ;xxx; 
goto _L99;  _L115:;  /* metka wyhoda po neuspehu wetwi */

/* branch */ pl1=*pl;rez1=NULL;success1=true; 
/* inicializaciq peremennyh */ 

/* shablon listmain */ rez1=pl1.cel;
success1=false;if(pl1.nel==0 ) goto _L116; 
 if (rez1!=NULL ) { pointr(rez1,&x.sa); 
       if (x.smld->dtype!= listmain )  
        { rez1=NULL;goto _L116;};
/* prowerka imeni */ 
success1=eqatom(x.smld->name,acnst[ 48 ]); 
if( ! success1 ) { rez1=NULL;goto _L116;};
{pl2.ptrtype=ptrlist; pl2.nel=1;
pl2.cel=x.smld->elt[0];pl2.UU.U1.curfragment=rez1;}
;} else  
{pl2.ptrtype=ptrlist;pl2.nel=0;pl2.cel=NULL;}

/* shablon atoma */ atmpat(acnst[1],&pl2,&rez1,&success1);
if( !success1 ) goto _L116;

if( pl2.nel !=0 )
{ success1=false;rez1=NULL;goto _L116;};
success1=true;rez1=pl1.cel;
 if( pl1.ptrtype!=ptrtree ) next(&pl1);

outxt(acnst[ 15 ], cnst[82] .sa , true, false); 
outxt(acnst[ 15 ], glob3_3 .sa , false, false); 
outatm(acnst[15],",&rez1);success1=true;",false, false); ;xxx; 
goto _L99;  _L116:;  /* metka wyhoda po neuspehu wetwi */

/* branch */ pl1=*pl;rez1=NULL;success1=true; 
/* inicializaciq peremennyh */ 

/* shablon listmain */ rez1=pl1.cel;
success1=false;if(pl1.nel==0 ) goto _L117; 
 if (rez1!=NULL ) { pointr(rez1,&x.sa); 
       if (x.smld->dtype!= listmain )  
        { rez1=NULL;goto _L117;};
/* prowerka imeni */ 
success1=eqatom(x.smld->name,acnst[ 49 ]); 
if( ! success1 ) { rez1=NULL;goto _L117;};
{pl2.ptrtype=ptrlist; pl2.nel=1;
pl2.cel=x.smld->elt[0];pl2.UU.U1.curfragment=rez1;}
;} else  
{pl2.ptrtype=ptrlist;pl2.nel=0;pl2.cel=NULL;}

/* shablon atoma */ atmpat(acnst[1],&pl2,&rez1,&success1);
if( !success1 ) goto _L117;

if( pl2.nel !=0 )
{ success1=false;rez1=NULL;goto _L117;};
success1=true;rez1=pl1.cel;
 if( pl1.ptrtype!=ptrtree ) next(&pl1);

outxt(acnst[ 15 ], cnst[83] .sa , true, false); 
outxt(acnst[ 15 ], glob3_3 .sa , false, false); 
outatm(acnst[15],".cel,&rez1);",false, false); ;xxx; 

/* CALL #L */ 
pl2.ptrtype=ptrlist;pl2.nel=0;pl2.cel=NULL;
r61(&wrk1.sa,&flag1,&pl2);/* #ss14*/ ;xxx; 
goto _L99;  _L117:;  /* metka wyhoda po neuspehu wetwi */

/* branch */ pl1=*pl;rez1=NULL;success1=true; 
/* inicializaciq peremennyh */ 
loc2.sa=NULL;/* $D*/ 
loc8.sa=NULL;/* $P*/ 

/* shablon treemain */ rez1=pl1.cel;
success1=false;if(pl1.nel==0 ) goto _L118; 
 if (rez1!=NULL ) { pointr(rez1,&x.sa); 
       if (x.smld->dtype!= treemain )  
        { rez1=NULL;goto _L118;};
/* prowerka imeni */ 
success1=eqatom(x.smld->name,acnst[ 67 ]); 
if( ! success1 ) { rez1=NULL;goto _L118;};
;}; 
pl2.nel=1;pl2.ptrtype=ptrtree;
success1=true; 
selop(acnst[41],false,0L,pl1.cel,&rez1);pl2.cel=rez1;
   if( rez1==NULL ) { success1=false;goto _L118;};

/* shablon peremennoj */ 
success1=(pl2.nel!=0);rez1=pl2.cel;
if( (pl2.ptrtype!=ptrtree) && success1 ) next(&pl2);
loc2 .sa=rez1; 
if( !success1 ) goto _L118;

/* CALL #L */ 
pl3.ptrtype=packedlist;pl3.nel=1;pl3.cel=loc2.sa;
pl3.plistsize= 1;
r41(&wrk1.sa,&flag1,&pl3);/* #G_wyravenie*/ ;xxx; 

selop( acnst[ 19 ],false,NULL, loc2 .sa ,& wrk1 .sa); 
outxt(acnst[ 15 ], wrk1 .sa , true, true); 
outatm(acnst[15],".sa=NULL;",false, true); ;xxx; 
selop(acnst[118],false,0L,pl1.cel,&rez1);pl2.cel=rez1;
   if( rez1==NULL ) { success1=false;goto _L118;};

/* shablon peremennoj */ 
success1=(pl2.nel!=0);rez1=pl2.cel;
if( (pl2.ptrtype!=ptrtree) && success1 ) next(&pl2);
loc8 .sa=rez1; 
if( !success1 ) goto _L118;

/* CALL #L */ 
pl3.ptrtype=packedlist;pl3.nel=1;pl3.cel=loc8.sa;
pl3.plistsize= 1;
r69(&wrk1.sa,&flag1,&pl3);/* #G_PATTERN*/ ;xxx; 

selop( acnst[ 19 ],false,NULL, loc2 .sa ,& wrk1 .sa); 
outxt(acnst[ 15 ], wrk1 .sa , true, true); 
outatm(acnst[15],".sa=rez1;",false, true); ;xxx; 
if( success1 ) {
 rez1=pl1.cel;if( pl1.ptrtype!=ptrtree ) next(&pl1) ;}
 else { rez1=NULL;goto _L118 ;};
goto _L99;  _L118:;  /* metka wyhoda po neuspehu wetwi */

/* branch */ pl1=*pl;rez1=NULL;success1=true; 
/* inicializaciq peremennyh */ 
loc2.sa=NULL;/* $D*/ 
loc8.sa=NULL;/* $P*/ 

/* shablon treemain */ rez1=pl1.cel;
success1=false;if(pl1.nel==0 ) goto _L119; 
 if (rez1!=NULL ) { pointr(rez1,&x.sa); 
       if (x.smld->dtype!= treemain )  
        { rez1=NULL;goto _L119;};
/* prowerka imeni */ 
success1=eqatom(x.smld->name,acnst[ 74 ]); 
if( ! success1 ) { rez1=NULL;goto _L119;};
;}; 
pl2.nel=1;pl2.ptrtype=ptrtree;
success1=true; 
selop(acnst[41],false,0L,pl1.cel,&rez1);pl2.cel=rez1;
   if( rez1==NULL ) { success1=false;goto _L119;};

/* shablon peremennoj */ 
success1=(pl2.nel!=0);rez1=pl2.cel;
if( (pl2.ptrtype!=ptrtree) && success1 ) next(&pl2);
loc2 .sa=rez1; 
if( !success1 ) goto _L119;

/* CALL #L */ 
pl3.ptrtype=packedlist;pl3.nel=1;pl3.cel=loc2.sa;
pl3.plistsize= 1;
r41(&wrk1.sa,&flag1,&pl3);/* #G_wyravenie*/ ;xxx; 
selop(acnst[118],false,0L,pl1.cel,&rez1);pl2.cel=rez1;
   if( rez1==NULL ) { success1=false;goto _L119;};

/* shablon peremennoj */ 
success1=(pl2.nel!=0);rez1=pl2.cel;
if( (pl2.ptrtype!=ptrtree) && success1 ) next(&pl2);
loc8 .sa=rez1; 
if( !success1 ) goto _L119;

/* CALL #L */ 
pl3.ptrtype=packedlist;pl3.nel=1;pl3.cel=loc8.sa;
pl3.plistsize= 1;
r69(&wrk1.sa,&flag1,&pl3);/* #G_PATTERN*/ ;xxx; 

outatm(acnst[15],"lconc(&",true, true); 
selop( acnst[ 19 ],false,NULL, loc2 .sa ,& wrk1 .sa); 
outxt(acnst[ 15 ], wrk1 .sa , false, true); 
outatm(acnst[15],".sa,rez1);",false, true); ;xxx; 
if( success1 ) {
 rez1=pl1.cel;if( pl1.ptrtype!=ptrtree ) next(&pl1) ;}
 else { rez1=NULL;goto _L119 ;};
goto _L99;  _L119:;  /* metka wyhoda po neuspehu wetwi */

/* branch */ pl1=*pl;rez1=NULL;success1=true; 
/* inicializaciq peremennyh */ 
loc2.sa=NULL;/* $D*/ 
loc8.sa=NULL;/* $P*/ 

/* shablon treemain */ rez1=pl1.cel;
success1=false;if(pl1.nel==0 ) goto _L120; 
 if (rez1!=NULL ) { pointr(rez1,&x.sa); 
       if (x.smld->dtype!= treemain )  
        { rez1=NULL;goto _L120;};
/* prowerka imeni */ 
success1=eqatom(x.smld->name,acnst[ 65 ]); 
if( ! success1 ) { rez1=NULL;goto _L120;};
;}; 
pl2.nel=1;pl2.ptrtype=ptrtree;
success1=true; 
selop(acnst[41],false,0L,pl1.cel,&rez1);pl2.cel=rez1;
   if( rez1==NULL ) { success1=false;goto _L120;};

/* shablon peremennoj */ 
success1=(pl2.nel!=0);rez1=pl2.cel;
if( (pl2.ptrtype!=ptrtree) && success1 ) next(&pl2);
loc2 .sa=rez1; 
if( !success1 ) goto _L120;

/* CALL #L */ 
pl3.ptrtype=packedlist;pl3.nel=1;pl3.cel=loc2.sa;
pl3.plistsize= 1;
r41(&wrk1.sa,&flag1,&pl3);/* #G_wyravenie*/ ;xxx; 
selop(acnst[118],false,0L,pl1.cel,&rez1);pl2.cel=rez1;
   if( rez1==NULL ) { success1=false;goto _L120;};

/* shablon peremennoj */ 
success1=(pl2.nel!=0);rez1=pl2.cel;
if( (pl2.ptrtype!=ptrtree) && success1 ) next(&pl2);
loc8 .sa=rez1; 
if( !success1 ) goto _L120;

/* CALL #L */ 
pl3.ptrtype=packedlist;pl3.nel=1;pl3.cel=loc8.sa;
pl3.plistsize= 1;
r69(&wrk1.sa,&flag1,&pl3);/* #G_PATTERN*/ ;xxx; 

outatm(acnst[15],"concop(&",true, true); 
selop( acnst[ 19 ],false,NULL, loc2 .sa ,& wrk1 .sa); 
outxt(acnst[ 15 ], wrk1 .sa , false, true); 
outatm(acnst[15],".sa,rez1);",false, true); ;xxx; 
if( success1 ) {
 rez1=pl1.cel;if( pl1.ptrtype!=ptrtree ) next(&pl1) ;}
 else { rez1=NULL;goto _L120 ;};
goto _L99;  _L120:;  /* metka wyhoda po neuspehu wetwi */

/* branch */ pl1=*pl;rez1=NULL;success1=true; 
/* inicializaciq peremennyh */ 
loc2.sa=NULL;/* $D*/ 
loc8.sa=NULL;/* $P*/ 

/* shablon treemain */ rez1=pl1.cel;
success1=false;if(pl1.nel==0 ) goto _L121; 
 if (rez1!=NULL ) { pointr(rez1,&x.sa); 
       if (x.smld->dtype!= treemain )  
        { rez1=NULL;goto _L121;};
/* prowerka imeni */ 
success1=eqatom(x.smld->name,acnst[ 66 ]); 
if( ! success1 ) { rez1=NULL;goto _L121;};
;}; 
pl2.nel=1;pl2.ptrtype=ptrtree;
success1=true; 
selop(acnst[41],false,0L,pl1.cel,&rez1);pl2.cel=rez1;
   if( rez1==NULL ) { success1=false;goto _L121;};

/* shablon peremennoj */ 
success1=(pl2.nel!=0);rez1=pl2.cel;
if( (pl2.ptrtype!=ptrtree) && success1 ) next(&pl2);
loc2 .sa=rez1; 
if( !success1 ) goto _L121;

/* CALL #L */ 
pl3.ptrtype=packedlist;pl3.nel=1;pl3.cel=loc2.sa;
pl3.plistsize= 1;
r41(&wrk1.sa,&flag1,&pl3);/* #G_wyravenie*/ ;xxx; 
selop(acnst[118],false,0L,pl1.cel,&rez1);pl2.cel=rez1;
   if( rez1==NULL ) { success1=false;goto _L121;};

/* shablon peremennoj */ 
success1=(pl2.nel!=0);rez1=pl2.cel;
if( (pl2.ptrtype!=ptrtree) && success1 ) next(&pl2);
loc8 .sa=rez1; 
if( !success1 ) goto _L121;

/* CALL #L */ 
pl3.ptrtype=packedlist;pl3.nel=1;pl3.cel=loc8.sa;
pl3.plistsize= 1;
r69(&wrk1.sa,&flag1,&pl3);/* #G_PATTERN*/ ;xxx; 

outatm(acnst[15],"addtre(&",true, true); 
selop( acnst[ 19 ],false,NULL, loc2 .sa ,& wrk1 .sa); 
outxt(acnst[ 15 ], wrk1 .sa , false, true); 
outatm(acnst[15],".sa,rez1);",false, true); ;xxx; 
if( success1 ) {
 rez1=pl1.cel;if( pl1.ptrtype!=ptrtree ) next(&pl1) ;}
 else { rez1=NULL;goto _L121 ;};
goto _L99;  _L121:;  /* metka wyhoda po neuspehu wetwi */

/* branch */ pl1=*pl;rez1=NULL;success1=true; 
/* inicializaciq peremennyh */ 
loc2.sa=NULL;/* $D*/ 
loc8.sa=NULL;/* $P*/ 

/* shablon treemain */ rez1=pl1.cel;
success1=false;if(pl1.nel==0 ) goto _L122; 
 if (rez1!=NULL ) { pointr(rez1,&x.sa); 
       if (x.smld->dtype!= treemain )  
        { rez1=NULL;goto _L122;};
/* prowerka imeni */ 
success1=eqatom(x.smld->name,acnst[ 75 ]); 
if( ! success1 ) { rez1=NULL;goto _L122;};
;}; 
pl2.nel=1;pl2.ptrtype=ptrtree;
success1=true; 
selop(acnst[41],false,0L,pl1.cel,&rez1);pl2.cel=rez1;
   if( rez1==NULL ) { success1=false;goto _L122;};

/* shablon peremennoj */ 
success1=(pl2.nel!=0);rez1=pl2.cel;
if( (pl2.ptrtype!=ptrtree) && success1 ) next(&pl2);
loc2 .sa=rez1; 
if( !success1 ) goto _L122;

/* CALL #L */ 
pl3.ptrtype=packedlist;pl3.nel=1;pl3.cel=loc2.sa;
pl3.plistsize= 1;
r41(&wrk1.sa,&flag1,&pl3);/* #G_wyravenie*/ ;xxx; 
selop(acnst[118],false,0L,pl1.cel,&rez1);pl2.cel=rez1;
   if( rez1==NULL ) { success1=false;goto _L122;};

/* shablon peremennoj */ 
success1=(pl2.nel!=0);rez1=pl2.cel;
if( (pl2.ptrtype!=ptrtree) && success1 ) next(&pl2);
loc8 .sa=rez1; 
if( !success1 ) goto _L122;

/* CALL #L */ 
pl3.ptrtype=packedlist;pl3.nel=1;pl3.cel=loc8.sa;
pl3.plistsize= 1;
r69(&wrk1.sa,&flag1,&pl3);/* #G_PATTERN*/ ;xxx; 

outatm(acnst[15],"addnum(&",true, true); 
selop( acnst[ 19 ],false,NULL, loc2 .sa ,& wrk1 .sa); 
outxt(acnst[ 15 ], wrk1 .sa , false, true); 
outatm(acnst[15],".sa,numval(rez1));",false, true); ;xxx; 
if( success1 ) {
 rez1=pl1.cel;if( pl1.ptrtype!=ptrtree ) next(&pl1) ;}
 else { rez1=NULL;goto _L122 ;};
goto _L99;  _L122:;  /* metka wyhoda po neuspehu wetwi */

/* branch */ pl1=*pl;rez1=NULL;success1=true; 
/* inicializaciq peremennyh */ 

/* shablon prawila */ r15(&rez1,&success1,&pl1);
if( !success1 ) goto _L123;
goto _L99;  _L123:;  /* metka wyhoda po neuspehu wetwi */
 _L99: rez1=NULL; 
 _L98: *rez=rez1;*success=success1; 
 if (*success) *pl=pl1; /* prodwinutx ukazatelx leksem */ 
/* wosstanowitx GLOB */ 
#ifdef XX  
 d(2,"G_PATTERN", 69 ,*rez,*success); 
#endif 
;};/* RULE */ 
