
#include "globrig.h" 
#include "define.h"  
#include "defpage.h" 
#include "nef2.h"    
#include "c1.h"      
#include "usemod.h"  
#include "def180.h"  
#include "xcrg.h"    
/*  R15 G_PATTERN2 */ 
/*  R70 G_alternative_pat */ 
/*  R71 split_branches */ 
/*  R72 notin */ 
/*  R73 good_atom */ 
/*===============================================*/ 
/* GENERATED TEXT OF RULE   #G_PATTERN2   */ 
 Void r15(rez,success,pl)
long *rez;boolean *success;ptr_ *pl; 
{  a rez1;  boolean success1; long k; mpd x; 
v loc2;/* $P*/ 
v loc3;/* $NPL*/ 
v loc4;/* $LABEL*/ 
v loc5;/* $OLDBL*/ 
v loc6;/* $NFLAG*/ 
v loc7;/* $OLD_LABEL*/ 
v loc8;/* $DL*/ 
v loc9;/* $E*/ 
v loc10;/* $A*/ 
v loc11;/* $OLDPL*/ 
v loc12;/* $L*/ 
v loc13;/* $metka*/ 
v loc14;/* $WORK_PL*/ 
v loc15;/* $OLDLABEL*/ 
v loc16;/* $S*/ 
v loc17;/* $T*/ 
v loc18;/* $M*/ 
v wrk1;
v wrk2;
v wrk3;
v oldglob15_1;
ptr_ pl1;
ptr_ pl2;
ptr_ pl3;
ptr_ pl4;
ptr_ pl5;
boolean flag1;
#ifdef XX  
 d(1,"G_PATTERN2", 15 ,pl->cel,0); 
#endif 
/* sohranitx GLOB */ 
oldglob15_1=glob15_1;

/* branch */ pl1=*pl;rez1=NULL;success1=true; 
/* inicializaciq peremennyh */ 
glob15_1.sa=NULL;
loc2.sa=NULL;/* $P*/ 
loc3.sa=NULL;/* $NPL*/ 
loc4.sa=NULL;/* $LABEL*/ 
loc5.sa=NULL;/* $OLDBL*/ 
loc6.sa=NULL;/* $NFLAG*/ 
loc7.sa=NULL;/* $OLD_LABEL*/ 
loc8.sa=NULL;/* $DL*/ 
loc9.sa=NULL;/* $E*/ 

/* shablon treemain */ rez1=pl1.cel;
success1=false;if(pl1.nel==0 ) goto _L113; 
 if (rez1!=NULL ) { pointr(rez1,&x.sa); 
       if (x.smld->dtype!= treemain )  
        { rez1=NULL;goto _L113;};
/* prowerka imeni */ 
loc2 .sa=x.smld->name; 
;}; 
pl2.nel=1;pl2.ptrtype=ptrtree;
success1=true; 
selop(acnst[115],false,0L,pl1.cel,&rez1);pl2.cel=rez1;
   if( rez1==NULL ) { success1=false;goto _L113;};

/* shablon peremennoj */ 
varpat(&pl2,number,&rez1,&success1);
loc3 .sa=rez1; 
if( !success1 ) goto _L113;

/* IF-operator */ 
/* operaciq <> */ wrk1 .bo= ! eqatom( loc2 .sa ,acnst[ 119 ]) ; 
if( !( wrk1 .bo )) wrk3 .bo=false; else { 
/* operaciq <> */ wrk2 .bo= ! eqatom( loc2 .sa ,acnst[ 120 ]) ; wrk3 = wrk2 
;}/*log*/; 
if( wrk3 .bo) 
{ 
/* FAIL */ rez1=NULL;success1=false; 
if (pl1.ptrtype!=ptrtree) next(&pl1); /*wyhod iz der.ili sp.*/ 
goto _L113;xxx; 
;} 
_L101:;xxx; 

outatm(acnst[15],"/*shablon",true, true); 
outxt(acnst[ 15 ], loc2 .sa , false, true); 
outatm(acnst[15],"*/",false, true); ;xxx; 
selop(acnst[38],false,0L,pl1.cel,&rez1);pl2.cel=rez1;
   if( rez1==NULL ) { success1=false;goto _L113;};

/* shablon peremennoj */ 
success1=(pl2.nel!=0);rez1=pl2.cel;
if( (pl2.ptrtype!=ptrtree) && success1 ) next(&pl2);
loc4 .sa=rez1; 
if( !success1 ) goto _L113;

/* operator := */ 
loc5 .sa= glob24_1 .sa ;xxx; 

/* operator := */ 
glob24_1 .sa= loc4 .sa ;xxx; 
selop(acnst[28],false,0L,pl1.cel,&rez1);pl2.cel=rez1;
   if( rez1==NULL ) { success1=false;goto _L102;};

/* shablon peremennoj */ 
varpat(&pl2,number,&rez1,&success1);
loc6 .sa=rez1; 
if( !success1 ) goto _L102;

outatm(acnst[15],"flag",true, false); 
outxt(acnst[ 15 ], loc6 .sa , false, false); 
outatm(acnst[15],"=",false, false); 
outatm(acnst[15],"false",false, false); 
outatm(acnst[15],";",false, false); ;xxx; 
_L102:success1=true;
selop(acnst[39],false,0L,pl1.cel,&rez1);pl2.cel=rez1;
   if( rez1==NULL ) { success1=false;goto _L113;};

outatm(acnst[15]," pl",true, false); 
outxt(acnst[ 15 ], loc3 .sa , false, false); 
outxt(acnst[ 15 ], cnst[84] .sa , false, false); 
outxt(acnst[ 15 ], glob3_3 .sa , false, false); 
outatm(acnst[15],";",false, false); 
outxt(acnst[ 15 ], cnst[85] .sa , false, false); 
outxt(acnst[ 15 ], glob3_3 .sa , false, false); 
outatm(acnst[15],".nel!=0",false, false); 
outatm(acnst[15]," ) { ",false, false); ;xxx; 

/* operator := */ 
loc7 .sa= glob10_2 .sa ;xxx; 

/* operator := */ 
glob10_2 .sa= loc4 .sa ;xxx; 

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
if( !success1 ) goto _L103;
goto _L105/*uspeh*/;
_L103:; 
pl3=pl5;

/* shablon prawila */ r63(&rez1,&success1,&pl3);
if( !success1 ) goto _L104;
goto _L105/*uspeh*/;
_L104:; 
pl3=pl5;
goto  _L106;
_L105:;/*uspeh alxtern.*/
 pl4=pl3;
;}; 
_L106:if( ! success1 )pl3=pl4;
success1 = true ; 

if( pl3.nel !=0 )
{ success1=false;rez1=NULL;goto _L113;};
success1=true;rez1=pl2.cel;
 if( pl2.ptrtype!=ptrtree ) next(&pl2);

outatm(acnst[15]," pl",true, false); 
outxt(acnst[ 15 ], loc3 .sa , false, false); 
outxt(acnst[ 15 ], cnst[84] .sa , false, false); 
outxt(acnst[ 15 ], glob3_3 .sa , false, false); 
outatm(acnst[15],";",false, false); ;xxx; 

/* IF-operator */ 
if( loc6 .sa!=NULL) 
{ 
outatm(acnst[15],"flag",true, false); 
outxt(acnst[ 15 ], loc6 .sa , false, false); 
outatm(acnst[15],"=true;",false, false); ;xxx; 
;} 
_L107:;xxx; 
selop(acnst[121],false,0L,pl1.cel,&rez1);pl2.cel=rez1;
   if( rez1==NULL ) { success1=false;goto _L108;};

/* shablon peremennoj */ 
success1=(pl2.nel!=0);rez1=pl2.cel;
if( (pl2.ptrtype!=ptrtree) && success1 ) next(&pl2);
loc8 .sa=rez1; 
if( !success1 ) goto _L108;
_L108:success1=true;
selop(acnst[122],false,0L,pl1.cel,&rez1);pl2.cel=rez1;
   if( rez1==NULL ) { success1=false;goto _L109;};

/* shablon peremennoj */ 
success1=(pl2.nel!=0);rez1=pl2.cel;
if( (pl2.ptrtype!=ptrtree) && success1 ) next(&pl2);
loc9 .sa=rez1; 
if( !success1 ) goto _L109;

/* operator := */ 
glob10_2 .sa= loc8 .sa ;xxx; 

/* CALL #L */ 
pl3.ptrtype=packedlist;pl3.nel=1;pl3.cel=loc9.sa;
pl3.plistsize= 1;
r69(&wrk1.sa,&flag1,&pl3);/* #G_PATTERN*/ ;xxx; 
_L109:success1=true;
if( success1 ) {
 rez1=pl1.cel;if( pl1.ptrtype!=ptrtree ) next(&pl1) ;}
 else { rez1=NULL;goto _L113 ;};

outatm(acnst[15],";};",true, true); ;xxx; 

outatm(acnst[15],"_L",true, false); 
outxt(acnst[ 15 ], loc4 .sa , false, false); 
outatm(acnst[15],":if( ! success1 )",false, false); 
outxt(acnst[ 15 ], cnst[70] .sa , false, false); 
outxt(acnst[ 15 ], glob3_3 .sa , false, false); 
outatm(acnst[15],"=",false, false); 
outatm(acnst[15],"pl",false, false); 
outxt(acnst[ 15 ], loc3 .sa , false, false); 
outatm(acnst[15],";",false, false); ;xxx; 

/* IF-operator */ 
if( loc8 .sa!=NULL) 
{ 
outatm(acnst[15],"_L",true, false); 
outxt(acnst[ 15 ], loc8 .sa , false, false); 
outatm(acnst[15],":;",false, false); ;xxx; 
;} 
_L110:;xxx; 

outatm(acnst[15],"success1",true, true); 
outatm(acnst[15],"=",false, true); ;xxx; 

/* IF-operator */ 
if( loc6 .sa!=NULL) 
{ 
outatm(acnst[15],"flag",false, false); 
outxt(acnst[ 15 ], loc6 .sa , false, false); 
outatm(acnst[15],";",false, false); ;xxx; 
goto _L111;
;} 
{ 
outatm(acnst[15],"true",false, true); 
outatm(acnst[15],";",false, true); ;xxx; 
;} 
_L111:;xxx; 

/* operator := */ 
glob10_2 .sa= loc7 .sa ;xxx; 

/* operator := */ 
glob24_1 .sa= loc5 .sa ;xxx; 

/* IF-operator */ 
if( loc6 .sa!=NULL) 
{ 
outatm(acnst[15],"if( ! success1 ) goto _L",true, false); 
outxt(acnst[ 15 ], loc7 .sa , false, false); 
outatm(acnst[15],";",false, false); ;xxx; 
;} 
_L112:;xxx; 
goto _L99;  _L113:;  /* metka wyhoda po neuspehu wetwi */

/* branch */ pl1=*pl;rez1=NULL;success1=true; 
/* inicializaciq peremennyh */ 
glob15_1.sa=NULL;
loc3.sa=NULL;/* $NPL*/ 
loc4.sa=NULL;/* $LABEL*/ 
loc5.sa=NULL;/* $OLDBL*/ 
loc9.sa=NULL;/* $E*/ 
loc10.sa=NULL;/* $A*/ 
loc11.sa=NULL;/* $OLDPL*/ 
loc12.sa=NULL;/* $L*/ 

/* shablon treemain */ rez1=pl1.cel;
success1=false;if(pl1.nel==0 ) goto _L121; 
 if (rez1!=NULL ) { pointr(rez1,&x.sa); 
       if (x.smld->dtype!= treemain )  
        { rez1=NULL;goto _L121;};
/* prowerka imeni */ 
success1=eqatom(x.smld->name,acnst[ 123 ]); 
if( ! success1 ) { rez1=NULL;goto _L121;};
;}; 
pl2.nel=1;pl2.ptrtype=ptrtree;
success1=true; 
selop(acnst[26],false,0L,pl1.cel,&rez1);pl2.cel=rez1;
   if( rez1==NULL ) { success1=false;goto _L114;};

/* shablon peremennoj */ 
success1=(pl2.nel!=0);rez1=pl2.cel;
if( (pl2.ptrtype!=ptrtree) && success1 ) next(&pl2);
loc10 .sa=rez1; 
if( !success1 ) goto _L114;
_L114:success1=true;
selop(acnst[115],false,0L,pl1.cel,&rez1);pl2.cel=rez1;
   if( rez1==NULL ) { success1=false;goto _L121;};

/* shablon peremennoj */ 
varpat(&pl2,number,&rez1,&success1);
loc3 .sa=rez1; 
if( !success1 ) goto _L121;

/* CALL #L */ 
pl3.ptrtype=packedlist;pl3.nel=1;pl3.cel=cnst[86].sa;
pl3.plistsize= 1;
r58(&wrk1.sa,&flag1,&pl3);/* #ss11*/ ;xxx; 

/* IF-operator */ 
if( loc10 .sa!=NULL) 
{ 
/* CALL #L */ 
pl3.ptrtype=packedlist;pl3.nel=1;pl3.cel=loc10.sa;
pl3.plistsize= 1;
r18(&wrk1.sa,&flag1,&pl3);/* #G_NAME_CHECK*/ ;xxx; 
;} 
_L115:;xxx; 

outatm(acnst[15],";};",true, true); ;xxx; 

/* operator +:= */ 
addnum(& glob10_3 .sa, 1L ) ;xxx; 

outatm(acnst[15],"pl",true, false); 
outxt(acnst[ 15 ], loc3 .sa , false, false); 
outatm(acnst[15],".nel=1;pl",false, false); 
outxt(acnst[ 15 ], loc3 .sa , false, false); 
outatm(acnst[15],".ptrtype=ptrtree;",false, false); ;xxx; 

outatm(acnst[15],"success1=true;",true, true); ;xxx; 

/* operator := */ 
loc11 .sa= glob3_3 .sa ;xxx; 

/* operator := */ 
glob3_3 .sa= loc3 .sa ;xxx; 
selop(acnst[38],false,0L,pl1.cel,&rez1);pl2.cel=rez1;
   if( rez1==NULL ) { success1=false;goto _L116;};

/* shablon peremennoj */ 
success1=(pl2.nel!=0);rez1=pl2.cel;
if( (pl2.ptrtype!=ptrtree) && success1 ) next(&pl2);
loc4 .sa=rez1; 
if( !success1 ) goto _L116;

/* operator := */ 
loc5 .sa= glob24_1 .sa ;xxx; 

/* operator := */ 
glob24_1 .sa= loc4 .sa ;xxx; 
_L116:success1=true;
selop(acnst[39],false,0L,pl1.cel,&rez1);pl2.cel=rez1;
   if( rez1==NULL ) { success1=false;goto _L117;};

/* shablon listmain */ rez1=pl2.cel;
success1=false;if(pl2.nel==0 ) goto _L117; 
 if (rez1!=NULL ) { pointr(rez1,&x.sa); 
       if (x.smld->dtype!= listmain )  
        { rez1=NULL;goto _L117;};
{pl3.ptrtype=ptrlist; pl3.nel=1;
pl3.cel=x.smld->elt[0];pl3.UU.U1.curfragment=rez1;}
;} else  
{pl3.ptrtype=ptrlist;pl3.nel=0;pl3.cel=NULL;}

/*shablon STARLIST */ 
 pl4=pl3;while(pl3.nel!=0 ) { 

/* shablon peremennoj */ 
success1=(pl3.nel!=0);rez1=pl3.cel;
if( (pl3.ptrtype!=ptrtree) && success1 ) next(&pl3);
loc9 .sa=rez1; 
if( !success1 ) goto _L118;

/* CALL #L */ 
pl5.ptrtype=packedlist;pl5.nel=1;pl5.cel=loc11.sa;
pl5.UU.plistelt[ 0 ]=loc3.sa;
pl5.UU.plistelt[ 1 ]=loc9.sa;
pl5.plistsize= 3;
r14(&wrk1.sa,&flag1,&pl5);/* #GEN_TREE_ELT*/ ;xxx; 
 pl4=pl3;
;}; 
_L118:if( ! success1 )pl3=pl4;
success1 = true ; 

if( pl3.nel !=0 )
{ success1=false;rez1=NULL;goto _L117;};
success1=true;rez1=pl2.cel;
 if( pl2.ptrtype!=ptrtree ) next(&pl2);
_L117:success1=true;
selop(acnst[37],false,0L,pl1.cel,&rez1);pl2.cel=rez1;
   if( rez1==NULL ) { success1=false;goto _L119;};

/* shablon peremennoj */ 
success1=(pl2.nel!=0);rez1=pl2.cel;
if( (pl2.ptrtype!=ptrtree) && success1 ) next(&pl2);
loc12 .sa=rez1; 
if( !success1 ) goto _L119;

/* CALL #L */ 
pl3.ptrtype=packedlist;pl3.nel=1;pl3.cel=loc11.sa;
pl3.UU.plistelt[ 0 ]=loc3.sa;
pl3.UU.plistelt[ 1 ]=glob15_1.sa;
pl3.UU.plistelt[ 2 ]=loc12.sa;
pl3.plistsize= 4;
r16(&wrk1.sa,&flag1,&pl3);/* #GEN_TREE_LOOP*/ ;xxx; 
_L119:success1=true;
if( success1 ) {
 rez1=pl1.cel;if( pl1.ptrtype!=ptrtree ) next(&pl1) ;}
 else { rez1=NULL;goto _L121 ;};

/* operator +:= */ 
wrk1 .nu=- 1L ; 
addnum(& glob10_3 .sa, wrk1 .nu ) ;xxx; 

/* operator := */ 
glob3_3 .sa= loc11 .sa ;xxx; 

/* IF-operator */ 
if( loc4 .sa!=NULL) 
{ 
outatm(acnst[15],"_L",true, false); 
outxt(acnst[ 15 ], loc4 .sa , false, false); 
outatm(acnst[15],":",false, false); ;xxx; 
/* operator := */ 
glob24_1 .sa= loc5 .sa ;xxx; 
;} 
_L120:;xxx; 

outatm(acnst[15],"if( success1 ) {",true, false); ;xxx; 

outatm(acnst[15]," rez1=pl",true, false); 
outxt(acnst[ 15 ], loc11 .sa , false, false); 
outatm(acnst[15],".cel;if( pl",false, false); 
outxt(acnst[ 15 ], loc11 .sa , false, false); 
outatm(acnst[15],".ptrtype!=ptrtree ) next(&pl",false, false); 
outxt(acnst[ 15 ], loc11 .sa , false, false); 
outatm(acnst[15],") ;}",false, false); ;xxx; 

outxt(acnst[ 15 ], cnst[60] .sa , true, false); 
outxt(acnst[ 15 ], glob10_2 .sa , false, false); 
outatm(acnst[15]," ;};",false, false); ;xxx; 
goto _L99;  _L121:;  /* metka wyhoda po neuspehu wetwi */

/* branch */ pl1=*pl;rez1=NULL;success1=true; 
/* inicializaciq peremennyh */ 
glob15_1.sa=NULL;
loc13.sa=NULL;/* $metka*/ 
loc14.sa=NULL;/* $WORK_PL*/ 
loc15.sa=NULL;/* $OLDLABEL*/ 

/* shablon treemain */ rez1=pl1.cel;
success1=false;if(pl1.nel==0 ) goto _L126; 
 if (rez1!=NULL ) { pointr(rez1,&x.sa); 
       if (x.smld->dtype!= treemain )  
        { rez1=NULL;goto _L126;};
/* prowerka imeni */ 
success1=eqatom(x.smld->name,acnst[ 124 ]); 
if( ! success1 ) { rez1=NULL;goto _L126;};
;}; 
pl2.nel=1;pl2.ptrtype=ptrtree;
success1=true; 
selop(acnst[38],false,0L,pl1.cel,&rez1);pl2.cel=rez1;
   if( rez1==NULL ) { success1=false;goto _L126;};

/* shablon peremennoj */ 
success1=(pl2.nel!=0);rez1=pl2.cel;
if( (pl2.ptrtype!=ptrtree) && success1 ) next(&pl2);
loc13 .sa=rez1; 
if( !success1 ) goto _L126;
selop(acnst[115],false,0L,pl1.cel,&rez1);pl2.cel=rez1;
   if( rez1==NULL ) { success1=false;goto _L126;};

/* shablon peremennoj */ 
success1=(pl2.nel!=0);rez1=pl2.cel;
if( (pl2.ptrtype!=ptrtree) && success1 ) next(&pl2);
loc14 .sa=rez1; 
if( !success1 ) goto _L126;

outatm(acnst[15],"/* shablon [ ... ] */",true, true); 
outatm(acnst[15],"pl",false, false); 
outxt(acnst[ 15 ], loc14 .sa , false, false); 
outxt(acnst[ 15 ], cnst[84] .sa , false, false); 
outxt(acnst[ 15 ], glob3_3 .sa , false, false); 
outatm(acnst[15],";",false, false); ;xxx; 

/* operator := */ 
loc15 .sa= glob10_2 .sa ;xxx; 

/* operator := */ 
glob10_2 .sa= loc13 .sa ;xxx; 
selop(acnst[39],false,0L,pl1.cel,&rez1);pl2.cel=rez1;
   if( rez1==NULL ) { success1=false;goto _L126;};

/* shablon listmain */ rez1=pl2.cel;
success1=false;if(pl2.nel==0 ) goto _L126; 
 if (rez1!=NULL ) { pointr(rez1,&x.sa); 
       if (x.smld->dtype!= listmain )  
        { rez1=NULL;goto _L126;};
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
if( !success1 ) goto _L122;
goto _L124/*uspeh*/;
_L122:; 
pl3=pl5;

/* shablon prawila */ r63(&rez1,&success1,&pl3);
if( !success1 ) goto _L123;
goto _L124/*uspeh*/;
_L123:; 
pl3=pl5;
goto  _L125;
_L124:;/*uspeh alxtern.*/
 pl4=pl3;
;}; 
_L125:if( ! success1 )pl3=pl4;
success1 = true ; 

if( pl3.nel !=0 )
{ success1=false;rez1=NULL;goto _L126;};
success1=true;rez1=pl2.cel;
 if( pl2.ptrtype!=ptrtree ) next(&pl2);
if( success1 ) {
 rez1=pl1.cel;if( pl1.ptrtype!=ptrtree ) next(&pl1) ;}
 else { rez1=NULL;goto _L126 ;};

outatm(acnst[15],"_L",true, false); 
outxt(acnst[ 15 ], loc13 .sa , false, false); 
outxt(acnst[ 15 ], cnst[87] .sa , false, false); 
outxt(acnst[ 15 ], glob3_3 .sa , false, false); 
outatm(acnst[15],"=pl",false, false); 
outxt(acnst[ 15 ], loc14 .sa , false, false); 
outatm(acnst[15],";success1=true;",false, false); ;xxx; 

/* operator := */ 
glob10_2 .sa= loc15 .sa ;xxx; 
goto _L99;  _L126:;  /* metka wyhoda po neuspehu wetwi */

/* branch */ pl1=*pl;rez1=NULL;success1=true; 
/* inicializaciq peremennyh */ 
glob15_1.sa=NULL;
loc9.sa=NULL;/* $E*/ 
loc16.sa=NULL;/* $S*/ 
loc17.sa=NULL;/* $T*/ 
loc18.sa=NULL;/* $M*/ 

/* shablon listmain */ rez1=pl1.cel;
success1=false;if(pl1.nel==0 ) goto _L131; 
 if (rez1!=NULL ) { pointr(rez1,&x.sa); 
       if (x.smld->dtype!= listmain )  
        { rez1=NULL;goto _L131;};
/* prowerka imeni */ 
loc16 .sa=x.smld->name; 
{pl2.ptrtype=ptrlist; pl2.nel=1;
pl2.cel=x.smld->elt[0];pl2.UU.U1.curfragment=rez1;}
;} else  
{pl2.ptrtype=ptrlist;pl2.nel=0;pl2.cel=NULL;}

/* IF-operator */ 
/* operaciq <> */ wrk1 .bo= ! eqatom( loc16 .sa ,acnst[ 125 ]) ; 
if( !( wrk1 .bo )) wrk3 .bo=false; else { 
/* operaciq <> */ wrk2 .bo= ! eqatom( loc16 .sa ,acnst[ 126 ]) ; wrk3 = wrk2 
;}/*log*/; 
if( wrk3 .bo) 
{ 
/* FAIL */ rez1=NULL;success1=false; 
if (pl1.ptrtype!=ptrtree) next(&pl1); /*wyhod iz der.ili sp.*/ 
goto _L131;xxx; 
;} 
_L127:;xxx; 

outatm(acnst[15],"/* shablon",true, true); 
outxt(acnst[ 15 ], loc16 .sa , false, true); 
outatm(acnst[15],"*/",false, true); ;xxx; 

/* IF-operator */ 
/* operaciq = */ wrk1 .bo= eqatom( loc16 .sa ,acnst[ 125 ]) ; 
if( wrk1 .bo) 
{ 
outxt(acnst[ 15 ], cnst[88] .sa , true, false); 
outxt(acnst[ 15 ], glob3_3 .sa , false, false); 
outxt(acnst[ 15 ], cnst[89] .sa , false, false); 
outxt(acnst[ 15 ], glob10_2 .sa , false, false); 
outatm(acnst[15]," ;};",false, false); ;xxx; 
;} 
_L128:;xxx; 

/* shablon peremennoj */ 
success1=(pl2.nel!=0);rez1=pl2.cel;
if( (pl2.ptrtype!=ptrtree) && success1 ) next(&pl2);
loc9 .sa=rez1; 
if( !success1 ) goto _L131;

/* CALL #L */ 
pl3.ptrtype=packedlist;pl3.nel=1;pl3.cel=loc9.sa;
pl3.plistsize= 1;
r41(&wrk1.sa,&flag1,&pl3);/* #G_wyravenie*/ ;xxx; 

outatm(acnst[15],"success1=",true, true); ;xxx; 

/* operator := */ 
selop( acnst[ 17 ],false,NULL, loc9 .sa ,& wrk1 .sa); 
loc17 .sa= wrk1 .sa ;xxx; 

/* operator := */ 
selop( acnst[ 19 ],false,NULL, loc9 .sa ,& wrk1 .sa); 
loc18 .sa= wrk1 .sa ;xxx; 

/* IF-operator */ 
/* operaciq = */ wrk1 .bo= eqatom( loc17 .sa ,acnst[ 18 ]) ; 
if( wrk1 .bo) 
{ 
outxt(acnst[ 15 ], loc18 .sa , false, true); 
outatm(acnst[15],".bo",false, true); ;xxx; 
goto _L129;
;} 
/* operaciq = */ wrk1 .bo= eqatom( loc17 .sa ,acnst[ 21 ]) ; 
if( wrk1 .bo) 
{ 
outatm(acnst[15],"true",false, true); ;xxx; 
goto _L129;
;} 
/* operaciq = */ wrk1 .bo= eqatom( loc18 .sa ,acnst[ 24 ]) ; 
if( wrk1 .bo) 
{ 
outatm(acnst[15],"false",false, true); ;xxx; 
goto _L129;
;} 
{ 
outxt(acnst[ 15 ], loc18 .sa , false, true); 
outatm(acnst[15],".sa!=NULL",false, true); ;xxx; 
;} 
_L129:;xxx; 

outatm(acnst[15],";if( success1 ) {",false, true); ;xxx; 

outxt(acnst[ 15 ], cnst[61] .sa , true, false); 
outxt(acnst[ 15 ], glob3_3 .sa , false, false); 
outatm(acnst[15],".cel;",false, false); ;xxx; 

/* IF-operator */ 
/* operaciq = */ wrk1 .bo= eqatom( loc16 .sa ,acnst[ 125 ]) ; 
if( wrk1 .bo) 
{ 
outxt(acnst[ 15 ], cnst[88] .sa , true, false); 
outxt(acnst[ 15 ], glob3_3 .sa , false, false); 
outxt(acnst[ 15 ], cnst[59] .sa , false, false); 
outxt(acnst[ 15 ], glob3_3 .sa , false, false); 
outatm(acnst[15],");",false, false); ;xxx; 
;} 
_L130:;xxx; 

outxt(acnst[ 15 ], cnst[90] .sa , true, false); 
outxt(acnst[ 15 ], glob10_2 .sa , false, false); 
outatm(acnst[15]," ;};",false, false); ;xxx; 

if( pl2.nel !=0 )
{ success1=false;rez1=NULL;goto _L131;};
success1=true;rez1=pl1.cel;
 if( pl1.ptrtype!=ptrtree ) next(&pl1);
goto _L99;  _L131:;  /* metka wyhoda po neuspehu wetwi */
 _L99: rez1=NULL; 
 _L98: *rez=rez1;*success=success1; 
 if (*success) *pl=pl1; /* prodwinutx ukazatelx leksem */ 
/* wosstanowitx GLOB */ 
glob15_1=oldglob15_1;
#ifdef XX  
 d(2,"G_PATTERN2", 15 ,*rez,*success); 
#endif 
;};/* RULE */ 
/*===============================================*/ 
/* GENERATED TEXT OF RULE   #G_alternative_pat   */ 
 Void r70(rez,success,pl)
long *rez;boolean *success;ptr_ *pl; 
{  a rez1;  boolean success1; long k; mpd x; 
v loc0;/* $_*/ 
v loc1;/* $LABEL*/ 
v loc2;/* $WORK_PL*/ 
v loc3;/* $nonatbrlbl*/ 
v loc4;/* $OLDLABEL*/ 
v loc5;/* $branch_label*/ 
v loc6;/* $aconst*/ 
v loc7;/* $L*/ 
v loc8;/* $BRANCH_LABEL*/ 
v loc9;/* $I*/ 
v loc10;/* $SUCC*/ 
v wrk1;
v wrk2;
v wrk3;
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
 d(1,"G_alternative_pat", 70 ,pl->cel,0); 
#endif 
/* sohranitx GLOB */ 
loc0.sa=pl->cel; 

/* branch */ pl1=*pl;rez1=NULL;success1=true; 
/* inicializaciq peremennyh */ 

/* shablon prawila */ r71(&rez1,&success1,&pl1);
if( !success1 ) goto _L101;

/* FAIL */ rez1=NULL;success1=false; 
if (pl1.ptrtype!=ptrtree) next(&pl1); /*wyhod iz der.ili sp.*/ 
goto _L101;xxx; 
goto _L99;  _L101:;  /* metka wyhoda po neuspehu wetwi */

/* branch */ pl1=*pl;rez1=NULL;success1=true; 
/* inicializaciq peremennyh */ 
loc1.sa=NULL;/* $LABEL*/ 
loc2.sa=NULL;/* $WORK_PL*/ 
loc3.sa=NULL;/* $nonatbrlbl*/ 
loc4.sa=NULL;/* $OLDLABEL*/ 
loc5.sa=NULL;/* $branch_label*/ 
loc6.sa=NULL;/* $aconst*/ 
loc7.sa=NULL;/* $L*/ 
loc8.sa=NULL;/* $BRANCH_LABEL*/ 
loc9.sa=NULL;/* $I*/ 
loc10.sa=NULL;/* $SUCC*/ 

/* shablon treemain */ rez1=pl1.cel;
success1=false;if(pl1.nel==0 ) goto _L127; 
 if (rez1!=NULL ) { pointr(rez1,&x.sa); 
       if (x.smld->dtype!= treemain )  
        { rez1=NULL;goto _L127;};
/* prowerka imeni */ 
success1=eqatom(x.smld->name,acnst[ 127 ]); 
if( ! success1 ) { rez1=NULL;goto _L127;};
;}; 
pl2.nel=1;pl2.ptrtype=ptrtree;
success1=true; 
selop(acnst[128],false,0L,pl1.cel,&rez1);pl2.cel=rez1;
   if( rez1==NULL ) { success1=false;goto _L102;};

/* shablon peremennoj */ 
success1=(pl2.nel!=0);rez1=pl2.cel;
if( (pl2.ptrtype!=ptrtree) && success1 ) next(&pl2);
loc1 .sa=rez1; 
if( !success1 ) goto _L102;
_L102:success1=true;
selop(acnst[115],false,0L,pl1.cel,&rez1);pl2.cel=rez1;
   if( rez1==NULL ) { success1=false;goto _L103;};

/* shablon peremennoj */ 
success1=(pl2.nel!=0);rez1=pl2.cel;
if( (pl2.ptrtype!=ptrtree) && success1 ) next(&pl2);
loc2 .sa=rez1; 
if( !success1 ) goto _L103;

outatm(acnst[15],"/* Alternative pattern */",true, true); ;xxx; 

outatm(acnst[15],"pl",true, false); 
outxt(acnst[ 15 ], loc2 .sa , false, false); 
outxt(acnst[ 15 ], cnst[84] .sa , false, false); 
outxt(acnst[ 15 ], glob3_3 .sa , false, false); 
outatm(acnst[15],";",false, false); ;xxx; 
_L103:success1=true;
selop(acnst[129],false,0L,pl1.cel,&rez1);pl2.cel=rez1;
   if( rez1==NULL ) { success1=false;goto _L104;};

/* shablon peremennoj */ 
success1=(pl2.nel!=0);rez1=pl2.cel;
if( (pl2.ptrtype!=ptrtree) && success1 ) next(&pl2);
loc3 .sa=rez1; 
if( !success1 ) goto _L104;

/* operator := */ 
loc4 .sa= glob10_2 .sa ;xxx; 

/* operator := */ 
glob10_2 .sa= loc3 .sa ;xxx; 
_L104:success1=true;
selop(acnst[130],false,0L,pl1.cel,&rez1);pl2.cel=rez1;
   if( rez1==NULL ) { success1=false;goto _L105;};

/* shablon listmain */ rez1=pl2.cel;
success1=false;if(pl2.nel==0 ) goto _L105; 
 if (rez1!=NULL ) { pointr(rez1,&x.sa); 
       if (x.smld->dtype!= listmain )  
        { rez1=NULL;goto _L105;};
{pl3.ptrtype=ptrlist; pl3.nel=1;
pl3.cel=x.smld->elt[0];pl3.UU.U1.curfragment=rez1;}
;} else  
{pl3.ptrtype=ptrlist;pl3.nel=0;pl3.cel=NULL;}

outxt(acnst[ 15 ], cnst[61] .sa , true, false); 
outxt(acnst[ 15 ], glob3_3 .sa , false, false); 
outatm(acnst[15],".cel;",false, false); ;xxx; 

outxt(acnst[ 15 ], cnst[91] .sa , true, false); 
outxt(acnst[ 15 ], glob3_3 .sa , false, false); 
outatm(acnst[15],".nel==0) || (rez1==NULL)) goto _L",false, false); 
outxt(acnst[ 15 ], loc3 .sa , false, false); 
outatm(acnst[15],";",false, false); ;xxx; 

outatm(acnst[15],"else { pointr(rez1,&x.sa);",true, true); ;xxx; 

outatm(acnst[15],"if (!((x.sad->dtype==atom)||",true, true); 
outatm(acnst[15],"(x.sad->dtype==idatom)||(x.sad->dtype==keyword)",false, true);
 ;xxx; 

outatm(acnst[15],"||(x.sad->dtype==fatom)) ) goto _L",true, false); 
outxt(acnst[ 15 ], loc3 .sa , false, false); 
outatm(acnst[15],";",false, false); ;xxx; 

outatm(acnst[15],"else x.sa=x.sad->name ;};",true, true); ;xxx; 

/*shablon STARLIST */ 
 pl4=pl3;while(pl3.nel!=0 ) { 

/* shablon listmain */ rez1=pl3.cel;
success1=false;if(pl3.nel==0 ) goto _L110; 
 if (rez1!=NULL ) { pointr(rez1,&x.sa); 
       if (x.smld->dtype!= listmain )  
        { rez1=NULL;goto _L110;};
{pl5.ptrtype=ptrlist; pl5.nel=1;
pl5.cel=x.smld->elt[0];pl5.UU.U1.curfragment=rez1;}
;} else  
{pl5.ptrtype=ptrlist;pl5.nel=0;pl5.cel=NULL;}

/* shablon peremennoj */ 
success1=(pl5.nel!=0);rez1=pl5.cel;
if( (pl5.ptrtype!=ptrtree) && success1 ) next(&pl5);
loc5 .sa=rez1; 
if( !success1 ) goto _L110;

/* shablon peremennoj */ 
success1=(pl5.nel!=0);rez1=pl5.cel;
if( (pl5.ptrtype!=ptrtree) && success1 ) next(&pl5);
loc6 .sa=rez1; 
if( !success1 ) goto _L110;

outxt(acnst[ 15 ],NULL,true,false) ;xxx; 

outatm(acnst[15],"/* atomic branch */",true, true); ;xxx; 

outatm(acnst[15],"if (x.sa==acnst[",true, true); 
outxt(acnst[ 15 ], loc6 .sa , false, true); 
outatm(acnst[15],"] ) { success1=true;",false, true); ;xxx; 

outxt(acnst[ 15 ], cnst[92] .sa , true, false); 
outxt(acnst[ 15 ], glob3_3 .sa , false, false); 
outatm(acnst[15],".ptrtype!=ptrtree ) ",false, false); ;xxx; 

outxt(acnst[ 15 ], cnst[93] .sa , true, false); 
outxt(acnst[ 15 ], glob3_3 .sa , false, false); 
outatm(acnst[15],");",false, false); ;xxx; 

/*shablon STARLIST */ 
 pl6=pl5;while(pl5.nel!=0 ) { 

/* Alternative pattern */ 
pl7=pl5;
/* nonatomic alternative branches */ 

/* shablon prawila */ r69(&rez1,&success1,&pl5);
if( !success1 ) goto _L106;
goto _L108/*uspeh*/;
_L106:; 
pl5=pl7;

/* shablon prawila */ r63(&rez1,&success1,&pl5);
if( !success1 ) goto _L107;
goto _L108/*uspeh*/;
_L107:; 
pl5=pl7;
goto  _L109;
_L108:;/*uspeh alxtern.*/
 pl6=pl5;
;}; 
_L109:if( ! success1 )pl5=pl6;
success1 = true ; 

if( pl5.nel !=0 )
{ success1=false;rez1=NULL;goto _L110;};
success1=true;rez1=pl3.cel;
 if( pl3.ptrtype!=ptrtree ) next(&pl3);

outatm(acnst[15],"goto _L",true, false); 
outxt(acnst[ 15 ], loc1 .sa , false, false); 
outatm(acnst[15],";}; _L",false, false); 
outxt(acnst[ 15 ], loc5 .sa , false, false); 
outatm(acnst[15],":;",false, false); ;xxx; 
 pl4=pl3;
;}; 
_L110:if( ! success1 )pl3=pl4;
success1 = true ; 

outatm(acnst[15],"success1=false;rez1=NULL;",true, true); ;xxx; 

outxt(acnst[ 15 ], cnst[70] .sa , true, false); 
outxt(acnst[ 15 ], glob3_3 .sa , false, false); 
outatm(acnst[15],"=pl",false, false); 
outxt(acnst[ 15 ], loc2 .sa , false, false); 
outatm(acnst[15],";",false, false); ;xxx; 

if( pl3.nel !=0 )
{ success1=false;rez1=NULL;goto _L105;};
success1=true;rez1=pl2.cel;
 if( pl2.ptrtype!=ptrtree ) next(&pl2);

/* operator := */ 
glob10_2 .sa= loc4 .sa ;xxx; 

/* IF-operator */ 
selop( acnst[ 39 ],false,NULL, loc0 .sa ,& wrk1 .sa); 
wrk2 .bo= wrk1 .sa==NULL; 
if( wrk2 .bo) 
{ 
outxt(acnst[ 15 ], cnst[74] .sa , true, false); 
outxt(acnst[ 15 ], glob10_2 .sa , false, false); 
outatm(acnst[15],";",false, false); ;xxx; 
;} 
_L111:;xxx; 
_L105:success1=true;
selop(acnst[39],false,0L,pl1.cel,&rez1);pl2.cel=rez1;
   if( rez1==NULL ) { success1=false;goto _L112;};

/* shablon listmain */ rez1=pl2.cel;
success1=false;if(pl2.nel==0 ) goto _L112; 
 if (rez1!=NULL ) { pointr(rez1,&x.sa); 
       if (x.smld->dtype!= listmain )  
        { rez1=NULL;goto _L112;};
{pl3.ptrtype=ptrlist; pl3.nel=1;
pl3.cel=x.smld->elt[0];pl3.UU.U1.curfragment=rez1;}
;} else  
{pl3.ptrtype=ptrlist;pl3.nel=0;pl3.cel=NULL;}

/* operator := */ 
selop( acnst[ 39 ],false,NULL, loc0 .sa ,& wrk1 .sa); 
bltin(&wrk2,&flag1,wrk1.sa,15L); 
mknumb( wrk2 .nu ,& wrk3 .sa); 
loc7 .sa= wrk3 .sa ;xxx; 

/* operator := */ 
loc4 .sa= glob10_2 .sa ;xxx; 

/* IF-operator */ 
wrk1 .bo= numval( loc7 .sa) > 1L ; 
if( wrk1 .bo) 
{ 
outatm(acnst[15],"/* nonatomic alternative branches */",true, true); ;xxx; 
;} 
_L113:;xxx; 

/*shablon STARLIST */ 
 pl4=pl3;while(pl3.nel!=0 ) { 

/* shablon listmain */ rez1=pl3.cel;
success1=false;if(pl3.nel==0 ) goto _L126; 
 if (rez1!=NULL ) { pointr(rez1,&x.sa); 
       if (x.smld->dtype!= listmain )  
        { rez1=NULL;goto _L126;};
{pl5.ptrtype=ptrlist; pl5.nel=1;
pl5.cel=x.smld->elt[0];pl5.UU.U1.curfragment=rez1;}
;} else  
{pl5.ptrtype=ptrlist;pl5.nel=0;pl5.cel=NULL;}

/* shablon peremennoj */ 
success1=(pl5.nel!=0);rez1=pl5.cel;
if( (pl5.ptrtype!=ptrtree) && success1 ) next(&pl5);
loc8 .sa=rez1; 
if( !success1 ) goto _L126;

/* operator +:= */ 
addnum(& loc9 .sa, 1L ) ;xxx; 

/* operator := */ 
glob10_2 .sa= loc8 .sa ;xxx; 

/* operator := */ 
loc10 .sa= cnst[1] .sa ;xxx; 

/*shablon STARLIST */ 
 pl6=pl5;while(pl5.nel!=0 ) { 

/* Alternative pattern */ 
pl7=pl5;
/* nonatomic alternative branches */ 

/* Alternative pattern */ 
pl8=pl5;

/* shablon prawila */ r69(&rez1,&success1,&pl5);
if( !success1 ) goto _L114;

/* operator := */ 
loc10 .sa= NULL ;xxx; 
goto _L115/*uspeh*/;
_L114:; 
pl5=pl8;
goto  _L116;
_L115:;/*uspeh alxtern.*/
goto _L121/*uspeh*/;
_L116:; 
pl5=pl7;

/* Alternative pattern */ 
pl8=pl5;

/* shablon prawila */ r63(&rez1,&success1,&pl5);
if( !success1 ) goto _L118;

/* IF-operator */ 
if( loc10 .sa!=NULL) 
{ 
outatm(acnst[15],"success1=true;",false, true); ;xxx; 
/* operator := */ 
loc10 .sa= NULL ;xxx; 
;} 
_L117:;xxx; 
goto _L119/*uspeh*/;
_L118:; 
pl5=pl8;
goto  _L120;
_L119:;/*uspeh alxtern.*/
goto _L121/*uspeh*/;
_L120:; 
pl5=pl7;
goto  _L122;
_L121:;/*uspeh alxtern.*/
 pl6=pl5;
;}; 
_L122:if( ! success1 )pl5=pl6;
success1 = true ; 

if( pl5.nel !=0 )
{ success1=false;rez1=NULL;goto _L126;};
success1=true;rez1=pl3.cel;
 if( pl3.ptrtype!=ptrtree ) next(&pl3);

/* IF-operator */ 
if( loc1 .sa!=NULL) 
{ 
outatm(acnst[15],"goto _L",true, false); 
outxt(acnst[ 15 ], loc1 .sa , false, false); 
outatm(acnst[15],"/*uspeh*/;",false, false); ;xxx; 
;} 
_L123:;xxx; 

outatm(acnst[15],"_L",true, false); 
outxt(acnst[ 15 ], loc8 .sa , false, false); 
outatm(acnst[15],":; ",false, false); ;xxx; 

/* IF-operator */ 
if( loc2 .sa!=NULL) 
{ 
outxt(acnst[ 15 ], cnst[70] .sa , true, false); 
outxt(acnst[ 15 ], glob3_3 .sa , false, false); 
outatm(acnst[15],"=pl",false, false); 
outxt(acnst[ 15 ], loc2 .sa , false, false); 
outatm(acnst[15],";",false, false); ;xxx; 
;} 
_L124:;xxx; 

/* IF-operator */ 
/* operaciq = */ wrk1 .bo= eqop(0L, loc9 .sa , loc7 .sa ) ; 
if( wrk1 .bo) 
{ 
/* operator := */ 
glob10_2 .sa= loc4 .sa ;xxx; 
outatm(acnst[15],"goto",true, true); 
outatm(acnst[15]," _L",false, false); 
outxt(acnst[ 15 ], loc4 .sa , false, false); 
outatm(acnst[15],";",false, false); ;xxx; 
;} 
_L125:;xxx; 
 pl4=pl3;
;}; 
_L126:if( ! success1 )pl3=pl4;
success1 = true ; 

if( pl3.nel !=0 )
{ success1=false;rez1=NULL;goto _L112;};
success1=true;rez1=pl2.cel;
 if( pl2.ptrtype!=ptrtree ) next(&pl2);
_L112:success1=true;
if( success1 ) {
 rez1=pl1.cel;if( pl1.ptrtype!=ptrtree ) next(&pl1) ;}
 else { rez1=NULL;goto _L127 ;};

outatm(acnst[15],"_L",true, false); 
outxt(acnst[ 15 ], loc1 .sa , false, false); 
outatm(acnst[15],":;/*uspeh alxtern.*/",false, false); ;xxx; 
goto _L99;  _L127:;  /* metka wyhoda po neuspehu wetwi */
 _L99: rez1=NULL; 
 _L98: *rez=rez1;*success=success1; 
 if (*success) *pl=pl1; /* prodwinutx ukazatelx leksem */ 
/* wosstanowitx GLOB */ 
#ifdef XX  
 d(2,"G_alternative_pat", 70 ,*rez,*success); 
#endif 
;};/* RULE */ 
/*===============================================*/ 
/* GENERATED TEXT OF RULE   #split_branches   */ 
 Void r71(rez,success,pl)
long *rez;boolean *success;ptr_ *pl; 
{  a rez1;  boolean success1; long k; mpd x; 
v loc0;/* $_*/ 
v loc1;/* $branch_label*/ 
v loc2;/* $L*/ 
v loc3;/* $aconst*/ 
v loc4;/* $P*/ 
v loc5;/* $b_l*/ 
v loc6;/* $atomic*/ 
v loc8;/* $nonatbrlbl*/ 
v loc9;/* $body*/ 
v wrk1;
v wrk2;
v wrk3;
v oldglob71_1;
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
#ifdef XX  
 d(1,"split_branches", 71 ,pl->cel,0); 
#endif 
/* sohranitx GLOB */ 
oldglob71_1=glob71_1;
loc0.sa=pl->cel; 

/* branch */ pl1=*pl;rez1=NULL;success1=true; 
/* inicializaciq peremennyh */ 
loc1.sa=NULL;/* $branch_label*/ 
loc2.sa=NULL;/* $L*/ 
loc3.sa=NULL;/* $aconst*/ 
loc6.sa=NULL;/* $atomic*/ 
glob71_1.sa=NULL;
loc8.sa=NULL;/* $nonatbrlbl*/ 
loc9.sa=NULL;/* $body*/ 

/* shablon treemain */ rez1=pl1.cel;
success1=false;if(pl1.nel==0 ) goto _L111; 
 if (rez1!=NULL ) { pointr(rez1,&x.sa); 
       if (x.smld->dtype!= treemain )  
        { rez1=NULL;goto _L111;};
/* prowerka imeni */ 
success1=eqatom(x.smld->name,acnst[ 127 ]); 
if( ! success1 ) { rez1=NULL;goto _L111;};
;}; 
pl2.nel=1;pl2.ptrtype=ptrtree;
success1=true; 
selop(acnst[39],false,0L,pl1.cel,&rez1);pl2.cel=rez1;
   if( rez1==NULL ) { success1=false;goto _L111;};

/* shablon listmain */ rez1=pl2.cel;
success1=false;if(pl2.nel==0 ) goto _L111; 
 if (rez1!=NULL ) { pointr(rez1,&x.sa); 
       if (x.smld->dtype!= listmain )  
        { rez1=NULL;goto _L111;};
{pl3.ptrtype=ptrlist; pl3.nel=1;
pl3.cel=x.smld->elt[0];pl3.UU.U1.curfragment=rez1;}
;} else  
{pl3.ptrtype=ptrlist;pl3.nel=0;pl3.cel=NULL;}

/*shablon STARLIST */ 
 pl4=pl3;while(pl3.nel!=0 ) { 

/* shablon listmain */ rez1=pl3.cel;
success1=false;if(pl3.nel==0 ) goto _L108; 
 if (rez1!=NULL ) { pointr(rez1,&x.sa); 
       if (x.smld->dtype!= listmain )  
        { rez1=NULL;goto _L108;};
{pl5.ptrtype=ptrlist; pl5.nel=1;
pl5.cel=x.smld->elt[0];pl5.UU.U1.curfragment=rez1;}
;} else  
{pl5.ptrtype=ptrlist;pl5.nel=0;pl5.cel=NULL;}

/* shablon peremennoj */ 
success1=(pl5.nel!=0);rez1=pl5.cel;
if( (pl5.ptrtype!=ptrtree) && success1 ) next(&pl5);
loc1 .sa=rez1; 
if( !success1 ) goto _L108;

/* operator := */ 
loc2 .sa= NULL ;xxx; 

/* Alternative pattern */ 
pl6=pl5;
/* nonatomic alternative branches */ 

/* Alternative pattern */ 
pl7=pl5;

/* shablon treemain */ rez1=pl5.cel;
success1=false;if(pl5.nel==0 ) goto _L102; 
 if (rez1!=NULL ) { pointr(rez1,&x.sa); 
       if (x.smld->dtype!= treemain )  
        { rez1=NULL;goto _L102;};
/* prowerka imeni */ 
success1=eqatom(x.smld->name,acnst[ 112 ]); 
if( ! success1 ) { rez1=NULL;goto _L102;};
;}; 
pl8.nel=1;pl8.ptrtype=ptrtree;
success1=true; 
selop(acnst[19],false,0L,pl5.cel,&rez1);pl8.cel=rez1;
   if( rez1==NULL ) { success1=false;goto _L102;};

loc3 .sa=NULL; 

/* shablon prawila */ r73(&rez1,&success1,&pl8);
if( !success1 ) goto _L102;
loc3 .sa=rez1; 
if( success1 ) {
 rez1=pl5.cel;if( pl5.ptrtype!=ptrtree ) next(&pl5) ;}
 else { rez1=NULL;goto _L102 ;};

/*shablon STARLIST */ 
 pl8=pl5;while(pl5.nel!=0 ) { 


/* shablon peremennoj */ 
success1=(pl5.nel!=0);rez1=pl5.cel;
if( (pl5.ptrtype!=ptrtree) && success1 ) next(&pl5);
loc4 .sa=rez1; 
if( !success1 ) goto _L101;
lconc(& loc2 .sa,rez1); 
 pl8=pl5;
;}; 
_L101:if( ! success1 )pl5=pl8;
success1 = true ; 
goto _L103/*uspeh*/;
_L102:; 
pl5=pl7;
goto  _L104;
_L103:;/*uspeh alxtern.*/
goto _L107/*uspeh*/;
_L104:; 
pl5=pl6;

/* shablon treemain */ rez1=pl5.cel;
success1=false;if(pl5.nel==0 ) goto _L106; 
 if (rez1!=NULL ) { pointr(rez1,&x.sa); 
       if (x.smld->dtype!= treemain )  
        { rez1=NULL;goto _L106;};
/* prowerka imeni */ 
success1=eqatom(x.smld->name,acnst[ 127 ]); 
if( ! success1 ) { rez1=NULL;goto _L106;};
;}; 
pl7.nel=1;pl7.ptrtype=ptrtree;
success1=true; 
selop(acnst[39],false,0L,pl5.cel,&rez1);pl7.cel=rez1;
   if( rez1==NULL ) { success1=false;goto _L106;};

/* shablon listmain */ rez1=pl7.cel;
success1=false;if(pl7.nel==0 ) goto _L106; 
 if (rez1!=NULL ) { pointr(rez1,&x.sa); 
       if (x.smld->dtype!= listmain )  
        { rez1=NULL;goto _L106;};
{pl8.ptrtype=ptrlist; pl8.nel=1;
pl8.cel=x.smld->elt[0];pl8.UU.U1.curfragment=rez1;}
;} else  
{pl8.ptrtype=ptrlist;pl8.nel=0;pl8.cel=NULL;}

/* shablon listmain */ rez1=pl8.cel;
success1=false;if(pl8.nel==0 ) goto _L106; 
 if (rez1!=NULL ) { pointr(rez1,&x.sa); 
       if (x.smld->dtype!= listmain )  
        { rez1=NULL;goto _L106;};
{pl9.ptrtype=ptrlist; pl9.nel=1;
pl9.cel=x.smld->elt[0];pl9.UU.U1.curfragment=rez1;}
;} else  
{pl9.ptrtype=ptrlist;pl9.nel=0;pl9.cel=NULL;}

/* shablon peremennoj */ 
success1=(pl9.nel!=0);rez1=pl9.cel;
if( (pl9.ptrtype!=ptrtree) && success1 ) next(&pl9);
loc5 .sa=rez1; 
if( !success1 ) goto _L106;

/* shablon treemain */ rez1=pl9.cel;
success1=false;if(pl9.nel==0 ) goto _L106; 
 if (rez1!=NULL ) { pointr(rez1,&x.sa); 
       if (x.smld->dtype!= treemain )  
        { rez1=NULL;goto _L106;};
/* prowerka imeni */ 
success1=eqatom(x.smld->name,acnst[ 112 ]); 
if( ! success1 ) { rez1=NULL;goto _L106;};
;}; 
pl10.nel=1;pl10.ptrtype=ptrtree;
success1=true; 
selop(acnst[19],false,0L,pl9.cel,&rez1);pl10.cel=rez1;
   if( rez1==NULL ) { success1=false;goto _L106;};

loc3 .sa=NULL; 

/* shablon prawila */ r73(&rez1,&success1,&pl10);
if( !success1 ) goto _L106;
loc3 .sa=rez1; 
if( success1 ) {
 rez1=pl9.cel;if( pl9.ptrtype!=ptrtree ) next(&pl9) ;}
 else { rez1=NULL;goto _L106 ;};

/*shablon STARLIST */ 
 pl10=pl9;while(pl9.nel!=0 ) { 


/* shablon peremennoj */ 
success1=(pl9.nel!=0);rez1=pl9.cel;
if( (pl9.ptrtype!=ptrtree) && success1 ) next(&pl9);
loc4 .sa=rez1; 
if( !success1 ) goto _L105;
lconc(& loc2 .sa,rez1); 
 pl10=pl9;
;}; 
_L105:if( ! success1 )pl9=pl10;
success1 = true ; 

if( pl9.nel !=0 )
{ success1=false;rez1=NULL;goto _L106;};
success1=true;rez1=pl8.cel;
 if( pl8.ptrtype!=ptrtree ) next(&pl8);

if( pl8.nel !=0 )
{ success1=false;rez1=NULL;goto _L106;};
success1=true;rez1=pl7.cel;
 if( pl7.ptrtype!=ptrtree ) next(&pl7);
if( success1 ) {
 rez1=pl5.cel;if( pl5.ptrtype!=ptrtree ) next(&pl5) ;}
 else { rez1=NULL;goto _L106 ;};
goto _L107/*uspeh*/;
_L106:; 
pl5=pl6;
goto  _L108;
_L107:;/*uspeh alxtern.*/

if( pl5.nel !=0 )
{ success1=false;rez1=NULL;goto _L108;};
success1=true;rez1=pl3.cel;
 if( pl3.ptrtype!=ptrtree ) next(&pl3);

/* operator !.:= */ 
wrk1 .sa =NULL; 
lconc(& wrk1 .sa , loc1 .sa ); 
lconc(& wrk1 .sa , loc3 .sa ); 
wrk2 .sa= wrk1 .sa ; 
concop(& wrk2 .sa, loc2 .sa ); 
lconc(& loc6 .sa, wrk2 .sa ) ;xxx; 

/* operator !.:= */ 
lconc(& glob71_1 .sa, loc3 .sa ) ;xxx; 
 pl4=pl3;
;}; 
_L108:if( ! success1 )pl3=pl4;
success1 = true ; 

/* IF-operator */ 
if( loc6 .sa!=NULL) 
{ 
/* operator := */ 
wrk1 .nu=- 1L ; 
indxop( wrk1 .nu,false,NULL, loc6 .sa ,& wrk2 .sa); 
indxop( 1L,false,NULL, wrk2 .sa ,& wrk3 .sa); 
loc8 .sa= wrk3 .sa ;xxx; 
;} 
_L109:;xxx; 

/*shablon STARLIST */ 
 pl4=pl3;while(pl3.nel!=0 ) { 


/* shablon peremennoj */ 
success1=(pl3.nel!=0);rez1=pl3.cel;
if( (pl3.ptrtype!=ptrtree) && success1 ) next(&pl3);
loc4 .sa=rez1; 
if( !success1 ) goto _L110;
lconc(& loc9 .sa,rez1); 
 pl4=pl3;
;}; 
_L110:if( ! success1 )pl3=pl4;
success1 = true ; 

if( pl3.nel !=0 )
{ success1=false;rez1=NULL;goto _L111;};
success1=true;rez1=pl2.cel;
 if( pl2.ptrtype!=ptrtree ) next(&pl2);
if( success1 ) {
 rez1=pl1.cel;if( pl1.ptrtype!=ptrtree ) next(&pl1) ;}
 else { rez1=NULL;goto _L111 ;};

/* operator := */ 
setsel( acnst[ 39 ],false,NULL, loc0 .sa , NULL ) ;xxx; 

/* operator ++:= */ 
wrk1 = loc0 ; 
addel( acnst[ 129 ],false,NULL, loc8 .sa ,& loc0 .sa); 
addel( acnst[ 130 ],false,NULL, loc6 .sa ,& loc0 .sa); 
addel( acnst[ 39 ],false,NULL, loc9 .sa ,& loc0 .sa); ;xxx; 
goto _L99;  _L111:;  /* metka wyhoda po neuspehu wetwi */
 _L99: rez1=NULL; 
 _L98: *rez=rez1;*success=success1; 
 if (*success) *pl=pl1; /* prodwinutx ukazatelx leksem */ 
/* wosstanowitx GLOB */ 
glob71_1=oldglob71_1;
#ifdef XX  
 d(2,"split_branches", 71 ,*rez,*success); 
#endif 
;};/* RULE */ 
/*===============================================*/ 
/* GENERATED TEXT OF RULE   #notin   */ 
 Void r72(rez,success,pl)
long *rez;boolean *success;ptr_ *pl; 
{  a rez1;  boolean success1; long k; mpd x; 
v loc1;/* $A*/ 
v wrk1;
v wrk2;
ptr_ pl1;
ptr_ pl2;
ptr_ pl3;
#ifdef XX  
 d(1,"notin", 72 ,pl->cel,0); 
#endif 
/* sohranitx GLOB */ 

/* branch */ pl1=*pl;rez1=NULL;success1=true; 
/* inicializaciq peremennyh */ 
loc1.sa=NULL;/* $A*/ 

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

/* shablon SPAT */ 
if( pl2.nel==0 ) { success1=false;goto _L101 ;};
wrk1.sa=pl2.cel;
/* operaciq <> */ wrk2 .bo= ! eqop(0L, wrk1 .sa , loc1 .sa ) ; 
success1= wrk2 .bo ;if( success1 ) { 
rez1=pl2.cel;
if( pl2.ptrtype!=ptrtree ) next(&pl2);
   ;} else { rez1=NULL;goto _L101 ;};
 pl3=pl2;
;}; 
_L101:if( ! success1 )pl2=pl3;
success1 = true ; 

if( pl2.nel !=0 )
{ success1=false;rez1=NULL;goto _L102;};
success1=true;rez1=pl1.cel;
 if( pl1.ptrtype!=ptrtree ) next(&pl1);

/* RETURN-op. */ 
rez1 = cnst[1] .sa ;goto _L98 ;xxx; 
goto _L99;  _L102:;  /* metka wyhoda po neuspehu wetwi */
 _L99: rez1=NULL; 
 _L98: *rez=rez1;*success=success1; 
 if (*success) *pl=pl1; /* prodwinutx ukazatelx leksem */ 
/* wosstanowitx GLOB */ 
#ifdef XX  
 d(2,"notin", 72 ,*rez,*success); 
#endif 
;};/* RULE */ 
/*===============================================*/ 
/* GENERATED TEXT OF RULE   #good_atom   */ 
 Void r73(rez,success,pl)
long *rez;boolean *success;ptr_ *pl; 
{  a rez1;  boolean success1; long k; mpd x; 
v loc1;/* $A*/ 
v wrk1;
ptr_ pl1;
ptr_ pl2;
boolean flag1;
#ifdef XX  
 d(1,"good_atom", 73 ,pl->cel,0); 
#endif 
/* sohranitx GLOB */ 

/* branch */ pl1=*pl;rez1=NULL;success1=true; 
/* inicializaciq peremennyh */ 
loc1.sa=NULL;/* $A*/ 

/* shablon peremennoj */ 
success1=(pl1.nel!=0);rez1=pl1.cel;
if( (pl1.ptrtype!=ptrtree) && success1 ) next(&pl1);
loc1 .sa=rez1; 
if( !success1 ) goto _L103;

/* IF-operator */ 
if( glob1_8 .sa!=NULL) 
{ 
outatm(acnst[15]," /* OPT */",true, true); ;xxx; 
/* FAIL */ rez1=NULL;success1=false; 
if (pl1.ptrtype!=ptrtree) next(&pl1); /*wyhod iz der.ili sp.*/ 
goto _L103;xxx; 
;} 
_L101:;xxx; 

outatm(acnst[15],"/* OPT SP */ ",true, true); ;xxx; 

/* IF-operator */ 
/* CALL #L */ 
pl2.ptrtype=packedlist;pl2.nel=1;pl2.cel=loc1.sa;
pl2.UU.plistelt[ 0 ]=glob71_1.sa;
pl2.plistsize= 2;
r72(&wrk1.sa,&flag1,&pl2);/* #notin*/ ; 
if( wrk1 .sa!=NULL) 
{ 
/* RETURN-op. */ 
rez1 = loc1 .sa ;goto _L98 ;xxx; 
goto _L102;
;} 
{ 
/* FAIL */ rez1=NULL;success1=false; 
if (pl1.ptrtype!=ptrtree) next(&pl1); /*wyhod iz der.ili sp.*/ 
goto _L103;xxx; 
;} 
_L102:;xxx; 
goto _L99;  _L103:;  /* metka wyhoda po neuspehu wetwi */
 _L99: rez1=NULL; 
 _L98: *rez=rez1;*success=success1; 
 if (*success) *pl=pl1; /* prodwinutx ukazatelx leksem */ 
/* wosstanowitx GLOB */ 
#ifdef XX  
 d(2,"good_atom", 73 ,*rez,*success); 
#endif 
;};/* RULE */ 
