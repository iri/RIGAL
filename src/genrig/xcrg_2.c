
#include "globrig.h" 
#include "define.h"  
#include "defpage.h" 
#include "nef2.h"    
#include "c1.h"      
#include "usemod.h"  
#include "def180.h"  
#include "xcrg.h"    
/*  R13 ZZZ */ 
/*  R14 GEN_TREE_ELT */ 
/*  R16 GEN_TREE_LOOP */ 
/*  R17 GEN_acnst_COND */ 
/*  R18 G_NAME_CHECK */ 
/*  R19 G_CALL */ 
/*  R20 G_OPEN */ 
/*  R21 G_OUTXT */ 
/*  R22 G_CLOSE */ 
/*  R23 G_LOOP */ 
/*  R25 G_BREAK */ 
/*  R26 G_BLTIN */ 
/*  R27 G_CALL_PAS */ 
/*  R28 TAIL */ 
/*===============================================*/ 
/* GENERATED TEXT OF RULE   #ZZZ   */ 
 Void r13(rez,success,pl)
long *rez;boolean *success;ptr_ *pl; 
{  a rez1;  boolean success1; long k; mpd x; 
v loc1;/* $E*/ 
ptr_ pl1;
#ifdef XX  
 d(1,"ZZZ", 13 ,pl->cel,0); 
#endif 
/* sohranitx GLOB */ 

/* branch */ pl1=*pl;rez1=NULL;success1=true; 
/* inicializaciq peremennyh */ 

loc1 .sa=NULL; 

/* shablon ~islowogo atoma */ 
 rez1=pl1.cel;
 if ((pl1.nel==0)||(rez1==NULL))   
 { success1=false; 
goto  _L101;};
 pointr(rez1,&x.sa); 
 success1=(x.sad->dtype  ==number) 
    &&(x.snd->val== 5 ); 
if (success1){ 
   if (pl1.ptrtype!=ptrtree ) next(&pl1) ;} 
 else { rez1=NULL;goto _L101;};
loc1 .sa=rez1; 
goto _L99;  _L101:;  /* metka wyhoda po neuspehu wetwi */
 _L99: rez1=NULL; 
 _L98: *rez=rez1;*success=success1; 
 if (*success) *pl=pl1; /* prodwinutx ukazatelx leksem */ 
/* wosstanowitx GLOB */ 
#ifdef XX  
 d(2,"ZZZ", 13 ,*rez,*success); 
#endif 
;};/* RULE */ 
/*===============================================*/ 
/* GENERATED TEXT OF RULE   #GEN_TREE_ELT   */ 
 Void r14(rez,success,pl)
long *rez;boolean *success;ptr_ *pl; 
{  a rez1;  boolean success1; long k; mpd x; 
v loc1;/* $OLDPL*/ 
v loc2;/* $NPL*/ 
v loc3;/* $FAC*/ 
v loc4;/* $Nmetki*/ 
v loc5;/* $NACONST*/ 
v loc6;/* $OLDLABEL*/ 
ptr_ pl1;
ptr_ pl2;
ptr_ pl3;
ptr_ pl4;
#ifdef XX  
 d(1,"GEN_TREE_ELT", 14 ,pl->cel,0); 
#endif 
/* sohranitx GLOB */ 

/* branch */ pl1=*pl;rez1=NULL;success1=true; 
/* inicializaciq peremennyh */ 
loc1.sa=NULL;/* $OLDPL*/ 
loc2.sa=NULL;/* $NPL*/ 
loc3.sa=NULL;/* $FAC*/ 
loc4.sa=NULL;/* $Nmetki*/ 
loc5.sa=NULL;/* $NACONST*/ 
loc6.sa=NULL;/* $OLDLABEL*/ 

/* shablon peremennoj */ 
success1=(pl1.nel!=0);rez1=pl1.cel;
if( (pl1.ptrtype!=ptrtree) && success1 ) next(&pl1);
loc1 .sa=rez1; 
if( !success1 ) goto _L111;

/* shablon peremennoj */ 
varpat(&pl1,number,&rez1,&success1);
loc2 .sa=rez1; 
if( !success1 ) goto _L111;

/* shablon listmain */ rez1=pl1.cel;
success1=false;if(pl1.nel==0 ) goto _L111; 
 if (rez1!=NULL ) { pointr(rez1,&x.sa); 
       if (x.smld->dtype!= listmain )  
        { rez1=NULL;goto _L111;};
/* prowerka imeni */ 
loc3 .sa=x.smld->name; 
{pl2.ptrtype=ptrlist; pl2.nel=1;
pl2.cel=x.smld->elt[0];pl2.UU.U1.curfragment=rez1;}
;} else  
{pl2.ptrtype=ptrlist;pl2.nel=0;pl2.cel=NULL;}

/* shablon peremennoj */ 
varpat(&pl2,number,&rez1,&success1);
loc4 .sa=rez1; 
if( !success1 ) goto _L111;

/* Alternative pattern */ 
pl3=pl2;
/* nonatomic alternative branches */ 

/* Alternative pattern */ 
pl4=pl2;

/* shablon peremennoj */ 
varpat(&pl2,number,&rez1,&success1);
loc5 .sa=rez1; 
if( !success1 ) goto _L101;

/* operator := */ 
loc6 .sa= glob10_2 .sa ;xxx; 

/* operator := */ 
glob10_2 .sa= loc4 .sa ;xxx; 
goto _L102/*uspeh*/;
_L101:; 
pl2=pl4;
goto  _L103;
_L102:;/*uspeh alxtern.*/
goto _L105/*uspeh*/;
_L103:; 
pl2=pl3;

/* operator := */ 
loc5 .sa= loc4 .sa ;xxx; success1=true; 
goto _L105/*uspeh*/;
_L104:; 
pl2=pl3;
goto  _L111;
_L105:;/*uspeh alxtern.*/

/* operator !.:= */ 
lconc(& glob15_1 .sa, loc5 .sa ) ;xxx; 

outatm(acnst[15],"selop(acnst[",true, false); 
outxt(acnst[ 15 ], loc5 .sa , false, false); 
outatm(acnst[15],"],false,0L,pl",false, false); 
outxt(acnst[ 15 ], loc1 .sa , false, false); 
outatm(acnst[15],".cel,&rez1);pl",false, false); 
outxt(acnst[ 15 ], loc2 .sa , false, false); 
outatm(acnst[15],".cel=rez1;",false, false); ;xxx; 

outxt(acnst[ 15 ], cnst[16] .sa , true, false); 
outxt(acnst[ 15 ], glob10_2 .sa , false, false); 
outatm(acnst[15],";};",false, false); ;xxx; 

/*shablon STARLIST */ 
 pl3=pl2;while(pl2.nel!=0 ) { 

/* Alternative pattern */ 
pl4=pl2;
/* nonatomic alternative branches */ 

/* shablon prawila */ r69(&rez1,&success1,&pl2);
if( !success1 ) goto _L106;
goto _L108/*uspeh*/;
_L106:; 
pl2=pl4;

/* shablon prawila */ r63(&rez1,&success1,&pl2);
if( !success1 ) goto _L107;
goto _L108/*uspeh*/;
_L107:; 
pl2=pl4;
goto  _L109;
_L108:;/*uspeh alxtern.*/
 pl3=pl2;
;}; 
_L109:if( ! success1 )pl2=pl3;
success1 = true ; 

if( pl2.nel !=0 )
{ success1=false;rez1=NULL;goto _L111;};
success1=true;rez1=pl1.cel;
 if( pl1.ptrtype!=ptrtree ) next(&pl1);

/* IF-operator */ 
if( loc3 .sa!=NULL) 
{ 
outatm(acnst[15],"_L",true, false); 
outxt(acnst[ 15 ], loc4 .sa , false, false); 
outatm(acnst[15],":success1=true;",false, false); ;xxx; 
/* operator := */ 
glob10_2 .sa= loc6 .sa ;xxx; 
;} 
_L110:;xxx; 
goto _L99;  _L111:;  /* metka wyhoda po neuspehu wetwi */
 _L99: rez1=NULL; 
 _L98: *rez=rez1;*success=success1; 
 if (*success) *pl=pl1; /* prodwinutx ukazatelx leksem */ 
/* wosstanowitx GLOB */ 
#ifdef XX  
 d(2,"GEN_TREE_ELT", 14 ,*rez,*success); 
#endif 
;};/* RULE */ 
/*===============================================*/ 
/* GENERATED TEXT OF RULE   #GEN_TREE_LOOP   */ 
 Void r16(rez,success,pl)
long *rez;boolean *success;ptr_ *pl; 
{  a rez1;  boolean success1; long k; mpd x; 
v loc1;/* $OLDPL*/ 
v loc2;/* $NPL*/ 
v loc3;/* $acnst_LIST*/ 
v loc4;/* $VAR*/ 
v wrk1;
ptr_ pl1;
ptr_ pl2;
ptr_ pl3;
ptr_ pl4;
boolean flag1;
#ifdef XX  
 d(1,"GEN_TREE_LOOP", 16 ,pl->cel,0); 
#endif 
/* sohranitx GLOB */ 

/* branch */ pl1=*pl;rez1=NULL;success1=true; 
/* inicializaciq peremennyh */ 
loc1.sa=NULL;/* $OLDPL*/ 
loc2.sa=NULL;/* $NPL*/ 
loc3.sa=NULL;/* $acnst_LIST*/ 
loc4.sa=NULL;/* $VAR*/ 

/* shablon peremennoj */ 
success1=(pl1.nel!=0);rez1=pl1.cel;
if( (pl1.ptrtype!=ptrtree) && success1 ) next(&pl1);
loc1 .sa=rez1; 
if( !success1 ) goto _L107;

/* shablon peremennoj */ 
varpat(&pl1,number,&rez1,&success1);
loc2 .sa=rez1; 
if( !success1 ) goto _L107;

/* shablon peremennoj */ 
success1=(pl1.nel!=0);rez1=pl1.cel;
if( (pl1.ptrtype!=ptrtree) && success1 ) next(&pl1);
loc3 .sa=rez1; 
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
loc4 .sa=rez1; 
if( !success1 ) goto _L107;

/* CALL #L */ 
pl3.ptrtype=packedlist;pl3.nel=1;pl3.cel=loc4.sa;
pl3.plistsize= 1;
r41(&wrk1.sa,&flag1,&pl3);/* #G_wyravenie*/ ;xxx; 

outatm(acnst[15],"first(pl",true, false); 
outxt(acnst[ 15 ], loc1 .sa , false, false); 
outatm(acnst[15],".cel,&pl",false, false); 
outxt(acnst[ 15 ], loc2 .sa , false, false); 
outatm(acnst[15],");while(pl",false, false); 
outxt(acnst[ 15 ], loc2 .sa , false, false); 
outatm(acnst[15],".nel!=0)   { ",false, false); ;xxx; 

/* IF-operator */ 
if( loc3 .sa!=NULL) 
{ 
/* CALL #L */ 
pl3.ptrtype=packedlist;pl3.nel=1;pl3.cel=loc2.sa;
pl3.UU.plistelt[ 0 ]=loc3.sa;
pl3.plistsize= 2;
r17(&wrk1.sa,&flag1,&pl3);/* #GEN_acnst_COND*/ ;xxx; 
;} 
_L101:;xxx; 

outatm(acnst[15],"mkatom(pl",true, false); 
outxt(acnst[ 15 ], loc2 .sa , false, false); 
outatm(acnst[15],".UU.U1.arc,idatom,&",false, false); 
selop( acnst[ 19 ],false,NULL, loc4 .sa ,& wrk1 .sa); 
outxt(acnst[ 15 ], wrk1 .sa , false, false); 
outatm(acnst[15],".sa);",false, false); ;xxx; 

/*shablon STARLIST */ 
 pl3=pl2;while(pl2.nel!=0 ) { 

/* Alternative pattern */ 
pl4=pl2;
/* nonatomic alternative branches */ 

/* shablon prawila */ r69(&rez1,&success1,&pl2);
if( !success1 ) goto _L102;
goto _L104/*uspeh*/;
_L102:; 
pl2=pl4;

/* shablon prawila */ r63(&rez1,&success1,&pl2);
if( !success1 ) goto _L103;
goto _L104/*uspeh*/;
_L103:; 
pl2=pl4;
goto  _L105;
_L104:;/*uspeh alxtern.*/
 pl3=pl2;
;}; 
_L105:if( ! success1 )pl2=pl3;
success1 = true ; 

if( pl2.nel !=0 )
{ success1=false;rez1=NULL;goto _L107;};
success1=true;rez1=pl1.cel;
 if( pl1.ptrtype!=ptrtree ) next(&pl1);

/* IF-operator */ 
if( loc3 .sa!=NULL) 
{ 
outatm(acnst[15],";};",true, true); ;xxx; 
;} 
_L106:;xxx; 

outatm(acnst[15],"next(&pl",true, false); 
outxt(acnst[ 15 ], loc2 .sa , false, false); 
outatm(acnst[15],") ;};",false, false); ;xxx; 
goto _L99;  _L107:;  /* metka wyhoda po neuspehu wetwi */
 _L99: rez1=NULL; 
 _L98: *rez=rez1;*success=success1; 
 if (*success) *pl=pl1; /* prodwinutx ukazatelx leksem */ 
/* wosstanowitx GLOB */ 
#ifdef XX  
 d(2,"GEN_TREE_LOOP", 16 ,*rez,*success); 
#endif 
;};/* RULE */ 
/*===============================================*/ 
/* GENERATED TEXT OF RULE   #GEN_acnst_COND   */ 
 Void r17(rez,success,pl)
long *rez;boolean *success;ptr_ *pl; 
{  a rez1;  boolean success1; long k; mpd x; 
v loc1;/* $NPL*/ 
v loc2;/* $N1*/ 
ptr_ pl1;
ptr_ pl2;
ptr_ pl3;
#ifdef XX  
 d(1,"GEN_acnst_COND", 17 ,pl->cel,0); 
#endif 
/* sohranitx GLOB */ 

/* branch */ pl1=*pl;rez1=NULL;success1=true; 
/* inicializaciq peremennyh */ 
loc1.sa=NULL;/* $NPL*/ 
loc2.sa=NULL;/* $N1*/ 

/* shablon peremennoj */ 
varpat(&pl1,number,&rez1,&success1);
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

/* shablon peremennoj */ 
varpat(&pl2,number,&rez1,&success1);
loc2 .sa=rez1; 
if( !success1 ) goto _L102;

outatm(acnst[15],"if( (pl",true, false); 
outxt(acnst[ 15 ], loc1 .sa , false, false); 
outatm(acnst[15],".UU.U1.arc!=acnst[",false, false); 
outxt(acnst[ 15 ], loc2 .sa , false, false); 
outatm(acnst[15],"])",false, false); ;xxx; 

/*shablon STARLIST */ 
 pl3=pl2;while(pl2.nel!=0 ) { 

/* shablon peremennoj */ 
varpat(&pl2,number,&rez1,&success1);
loc2 .sa=rez1; 
if( !success1 ) goto _L101;

outatm(acnst[15],"&&(pl",true, false); 
outxt(acnst[ 15 ], loc1 .sa , false, false); 
outatm(acnst[15],".UU.U1.arc!=acnst[",false, false); 
outxt(acnst[ 15 ], loc2 .sa , false, false); 
outatm(acnst[15],"])",false, false); ;xxx; 
 pl3=pl2;
;}; 
_L101:if( ! success1 )pl2=pl3;
success1 = true ; 

if( pl2.nel !=0 )
{ success1=false;rez1=NULL;goto _L102;};
success1=true;rez1=pl1.cel;
 if( pl1.ptrtype!=ptrtree ) next(&pl1);

outatm(acnst[15]," ) {",true, true); ;xxx; 
goto _L99;  _L102:;  /* metka wyhoda po neuspehu wetwi */
 _L99: rez1=NULL; 
 _L98: *rez=rez1;*success=success1; 
 if (*success) *pl=pl1; /* prodwinutx ukazatelx leksem */ 
/* wosstanowitx GLOB */ 
#ifdef XX  
 d(2,"GEN_acnst_COND", 17 ,*rez,*success); 
#endif 
;};/* RULE */ 
/*===============================================*/ 
/* GENERATED TEXT OF RULE   #G_NAME_CHECK   */ 
 Void r18(rez,success,pl)
long *rez;boolean *success;ptr_ *pl; 
{  a rez1;  boolean success1; long k; mpd x; 
v loc1;/* $A*/ 
v loc2;/* $E*/ 
v wrk1;
ptr_ pl1;
ptr_ pl2;
boolean flag1;
#ifdef XX  
 d(1,"G_NAME_CHECK", 18 ,pl->cel,0); 
#endif 
/* sohranitx GLOB */ 

/* branch */ pl1=*pl;rez1=NULL;success1=true; 
/* inicializaciq peremennyh */ 
loc1.sa=NULL;/* $A*/ 

outatm(acnst[15],"/* prowerka imeni */",true, true); ;xxx; 

/* shablon listmain */ rez1=pl1.cel;
success1=false;if(pl1.nel==0 ) goto _L101; 
 if (rez1!=NULL ) { pointr(rez1,&x.sa); 
       if (x.smld->dtype!= listmain )  
        { rez1=NULL;goto _L101;};
/* prowerka imeni */ 
success1=eqatom(x.smld->name,acnst[ 22 ]); 
if( ! success1 ) { rez1=NULL;goto _L101;};
{pl2.ptrtype=ptrlist; pl2.nel=1;
pl2.cel=x.smld->elt[0];pl2.UU.U1.curfragment=rez1;}
;} else  
{pl2.ptrtype=ptrlist;pl2.nel=0;pl2.cel=NULL;}

/* shablon peremennoj */ 
success1=(pl2.nel!=0);rez1=pl2.cel;
if( (pl2.ptrtype!=ptrtree) && success1 ) next(&pl2);
loc1 .sa=rez1; 
if( !success1 ) goto _L101;

if( pl2.nel !=0 )
{ success1=false;rez1=NULL;goto _L101;};
success1=true;rez1=pl1.cel;
 if( pl1.ptrtype!=ptrtree ) next(&pl1);

outatm(acnst[15],"success1=eqatom(x.smld->name,acnst[",true, true); 
outxt(acnst[ 15 ], loc1 .sa , false, true); 
outatm(acnst[15],"]);",false, true); ;xxx; 

outxt(acnst[ 15 ], cnst[17] .sa , true, false); 
outxt(acnst[ 15 ], glob10_2 .sa , false, false); 
outatm(acnst[15],";};",false, false); ;xxx; 
goto _L99;  _L101:;  /* metka wyhoda po neuspehu wetwi */

/* branch */ pl1=*pl;rez1=NULL;success1=true; 
/* inicializaciq peremennyh */ 
loc1.sa=NULL;/* $A*/ 

/* shablon listmain */ rez1=pl1.cel;
success1=false;if(pl1.nel==0 ) goto _L102; 
 if (rez1!=NULL ) { pointr(rez1,&x.sa); 
       if (x.smld->dtype!= listmain )  
        { rez1=NULL;goto _L102;};
/* prowerka imeni */ 
success1=eqatom(x.smld->name,acnst[ 23 ]); 
if( ! success1 ) { rez1=NULL;goto _L102;};
{pl2.ptrtype=ptrlist; pl2.nel=1;
pl2.cel=x.smld->elt[0];pl2.UU.U1.curfragment=rez1;}
;} else  
{pl2.ptrtype=ptrlist;pl2.nel=0;pl2.cel=NULL;}

/* shablon peremennoj */ 
success1=(pl2.nel!=0);rez1=pl2.cel;
if( (pl2.ptrtype!=ptrtree) && success1 ) next(&pl2);
loc1 .sa=rez1; 
if( !success1 ) goto _L102;

if( pl2.nel !=0 )
{ success1=false;rez1=NULL;goto _L102;};
success1=true;rez1=pl1.cel;
 if( pl1.ptrtype!=ptrtree ) next(&pl1);

outatm(acnst[15],"success1=eqnum(x.smld->name,",true, false); 
outxt(acnst[ 15 ], loc1 .sa , false, false); 
outatm(acnst[15],"L);",false, false); ;xxx; 

outxt(acnst[ 15 ], cnst[17] .sa , true, false); 
outxt(acnst[ 15 ], glob10_2 .sa , false, false); 
outatm(acnst[15],";};",false, false); ;xxx; 
goto _L99;  _L102:;  /* metka wyhoda po neuspehu wetwi */

/* branch */ pl1=*pl;rez1=NULL;success1=true; 
/* inicializaciq peremennyh */ 

/* shablon atoma */ atmpat(acnst[24],&pl1,&rez1,&success1);
if( !success1 ) goto _L103;

outatm(acnst[15]," success1=(x.smld->name ==NULL) ; ",true, true); ;xxx; 

outxt(acnst[ 15 ], cnst[17] .sa , true, false); 
outxt(acnst[ 15 ], glob10_2 .sa , false, false); 
outatm(acnst[15],";};",false, false); ;xxx; 
goto _L99;  _L103:;  /* metka wyhoda po neuspehu wetwi */

/* branch */ pl1=*pl;rez1=NULL;success1=true; 
/* inicializaciq peremennyh */ 
loc2.sa=NULL;/* $E*/ 

/* shablon peremennoj */ 
success1=(pl1.nel!=0);rez1=pl1.cel;
if( (pl1.ptrtype!=ptrtree) && success1 ) next(&pl1);
loc2 .sa=rez1; 
if( !success1 ) goto _L104;

/* CALL #L */ 
pl2.ptrtype=packedlist;pl2.nel=1;pl2.cel=loc2.sa;
pl2.plistsize= 1;
r41(&wrk1.sa,&flag1,&pl2);/* #G_wyravenie*/ ;xxx; 

selop( acnst[ 19 ],false,NULL, loc2 .sa ,& wrk1 .sa); 
outxt(acnst[ 15 ], wrk1 .sa , true, true); 
outatm(acnst[15],".sa=x.smld->name;",false, true); ;xxx; 
goto _L99;  _L104:;  /* metka wyhoda po neuspehu wetwi */
 _L99: rez1=NULL; 
 _L98: *rez=rez1;*success=success1; 
 if (*success) *pl=pl1; /* prodwinutx ukazatelx leksem */ 
/* wosstanowitx GLOB */ 
#ifdef XX  
 d(2,"G_NAME_CHECK", 18 ,*rez,*success); 
#endif 
;};/* RULE */ 
/*===============================================*/ 
/* GENERATED TEXT OF RULE   #G_CALL   */ 
 Void r19(rez,success,pl)
long *rez;boolean *success;ptr_ *pl; 
{  a rez1;  boolean success1; long k; mpd x; 
v loc1;/* $ID*/ 
v loc2;/* $NPL*/ 
v loc3;/* $WRK*/ 
v loc4;/* $B*/ 
v loc5;/* $E*/ 
v loc6;/* $E1*/ 
v loc7;/* $I*/ 
v loc8;/* $NUM*/ 
v wrk1;
v wrk2;
v wrk3;
ptr_ pl1;
ptr_ pl2;
boolean flag1;
#ifdef XX  
 d(1,"G_CALL", 19 ,pl->cel,0); 
#endif 
/* sohranitx GLOB */ 

/* branch */ pl1=*pl;rez1=NULL;success1=true; 
/* inicializaciq peremennyh */ 

/* shablon prawila */ r27(&rez1,&success1,&pl1);
if( !success1 ) goto _L101;
goto _L99;  _L101:;  /* metka wyhoda po neuspehu wetwi */

/* branch */ pl1=*pl;rez1=NULL;success1=true; 
/* inicializaciq peremennyh */ 
loc1.sa=NULL;/* $ID*/ 
loc2.sa=NULL;/* $NPL*/ 
loc3.sa=NULL;/* $WRK*/ 
loc4.sa=NULL;/* $B*/ 
loc5.sa=NULL;/* $E*/ 
loc6.sa=NULL;/* $E1*/ 
loc7.sa=NULL;/* $I*/ 
loc8.sa=NULL;/* $NUM*/ 

/* shablon treemain */ rez1=pl1.cel;
success1=false;if(pl1.nel==0 ) goto _L106; 
 if (rez1!=NULL ) { pointr(rez1,&x.sa); 
       if (x.smld->dtype!= treemain )  
        { rez1=NULL;goto _L106;};
/* prowerka imeni */ 
success1=eqatom(x.smld->name,acnst[ 25 ]); 
if( ! success1 ) { rez1=NULL;goto _L106;};
;}; 
pl2.nel=1;pl2.ptrtype=ptrtree;
success1=true; 
selop(acnst[26],false,0L,pl1.cel,&rez1);pl2.cel=rez1;
   if( rez1==NULL ) { success1=false;goto _L106;};

/* shablon peremennoj */ 
varpat(&pl2,idatom,&rez1,&success1);
loc1 .sa=rez1; 
if( !success1 ) goto _L106;

outatm(acnst[15],"/* CALL #L */",true, true); ;xxx; 
selop(acnst[27],false,0L,pl1.cel,&rez1);pl2.cel=rez1;
   if( rez1==NULL ) { success1=false;goto _L106;};

/* shablon peremennoj */ 
varpat(&pl2,number,&rez1,&success1);
loc2 .sa=rez1; 
if( !success1 ) goto _L106;
selop(acnst[19],false,0L,pl1.cel,&rez1);pl2.cel=rez1;
   if( rez1==NULL ) { success1=false;goto _L106;};

/* shablon peremennoj */ 
success1=(pl2.nel!=0);rez1=pl2.cel;
if( (pl2.ptrtype!=ptrtree) && success1 ) next(&pl2);
loc3 .sa=rez1; 
if( !success1 ) goto _L106;
selop(acnst[28],false,0L,pl1.cel,&rez1);pl2.cel=rez1;
   if( rez1==NULL ) { success1=false;goto _L106;};

/* shablon peremennoj */ 
success1=(pl2.nel!=0);rez1=pl2.cel;
if( (pl2.ptrtype!=ptrtree) && success1 ) next(&pl2);
loc4 .sa=rez1; 
if( !success1 ) goto _L106;
selop(acnst[29],false,0L,pl1.cel,&rez1);pl2.cel=rez1;
   if( rez1==NULL ) { success1=false;goto _L102;};

/* shablon peremennoj */ 
success1=(pl2.nel!=0);rez1=pl2.cel;
if( (pl2.ptrtype!=ptrtree) && success1 ) next(&pl2);
loc5 .sa=rez1; 
if( !success1 ) goto _L102;
_L102:success1=true;
if( success1 ) {
 rez1=pl1.cel;if( pl1.ptrtype!=ptrtree ) next(&pl1) ;}
 else { rez1=NULL;goto _L106 ;};

/* IF-operator */ 
if( loc5 .sa==NULL ) wrk3 .bo=false; else { 
bltin(&wrk1,&flag1,loc5.sa,15L); 
wrk2 .bo= wrk1 .nu <= 4L ; wrk3 = wrk2 ;}; 
if( wrk3 .bo) 
{ 
/* operator := */ 
/* CALL #L */ 
indxop( 1L,false,NULL, loc5 .sa ,& wrk1 .sa); 
pl2.ptrtype=packedlist;pl2.nel=1;pl2.cel=wrk1.sa;
pl2.plistsize= 1;
r37(&wrk2.sa,&flag1,&pl2);/* #obqzatelxno_obxekt*/ ; 
loc6 .sa= wrk2 .sa ;xxx; 
outatm(acnst[15],"pl",true, false); 
outxt(acnst[ 15 ], loc2 .sa , false, false); 
outatm(acnst[15],".ptrtype=packedlist;",false, false); 
outatm(acnst[15],"pl",false, false); 
outxt(acnst[ 15 ], loc2 .sa , false, false); 
outatm(acnst[15],".nel=1;pl",false, false); 
outxt(acnst[ 15 ], loc2 .sa , false, false); 
outatm(acnst[15],".cel=",false, false); 
outxt(acnst[ 15 ], loc6 .sa , false, false); 
outatm(acnst[15],";",false, false); ;xxx; 
/* operator := */ 
mknumb( 2L,& wrk1 .sa); 
loc7 .sa= wrk1 .sa ;xxx; 
/*LOOP*/while (true) { 
/* IF-operator */ 
bltin(&wrk1,&flag1,loc5.sa,15L); 
wrk2 .bo= numval( loc7 .sa) > wrk1 .nu ; 
if( wrk2 .bo) 
{ 
/*BREAK*/ goto _L105;xxx; 
;} 
_L104:;xxx; 
/* operator := */ 
/* CALL #L */ 
indxop( 0L,true, loc7 .sa, loc5 .sa ,& wrk1 .sa); 
pl2.ptrtype=packedlist;pl2.nel=1;pl2.cel=wrk1.sa;
pl2.plistsize= 1;
r37(&wrk2.sa,&flag1,&pl2);/* #obqzatelxno_obxekt*/ ; 
loc6 .sa= wrk2 .sa ;xxx; 
outatm(acnst[15],"pl",true, false); 
outxt(acnst[ 15 ], loc2 .sa , false, false); 
outatm(acnst[15],".UU.plistelt[ ",false, false); 
wrk1 .nu= numval( loc7 .sa) - 2L ; 
mknumb( wrk1 .nu ,& wrk2 .sa); 
outxt(acnst[ 15 ], wrk2 .sa , false, false); 
outatm(acnst[15]," ]=",false, false); 
outxt(acnst[ 15 ], loc6 .sa , false, false); 
outatm(acnst[15],";",false, false); ;xxx; 
/* operator +:= */ 
addnum(& loc7 .sa, 1L ) ;xxx; 
;};  _L105:/*END LOOP*/;xxx; 
outatm(acnst[15],"pl",true, false); 
outxt(acnst[ 15 ], loc2 .sa , false, false); 
outatm(acnst[15],".plistsize= ",false, false); 
bltin(&wrk1,&flag1,loc5.sa,15L); 
mknumb( wrk1 .nu ,& wrk2 .sa); 
outxt(acnst[ 15 ], wrk2 .sa , false, false); 
outatm(acnst[15],";",false, false); ;xxx; 
goto _L103;
;} 
if( loc5 .sa!=NULL) 
{ 
outxt(acnst[ 15 ], loc3 .sa , true, true); 
outatm(acnst[15],".sa=NULL;",false, true); ;xxx; 
/* CALL #L */ 
wrk1 .sa =NULL; 
lconc(& wrk1 .sa , loc3 .sa ); 
lconc(& wrk1 .sa , cnst[18] .sa ); 
pl2.ptrtype=packedlist;pl2.nel=1;pl2.cel=wrk1.sa;
pl2.UU.plistelt[ 0 ]=loc5.sa;
pl2.plistsize= 2;
r45(&wrk2.sa,&flag1,&pl2);/* #CONLIST*/ ;xxx; 
outatm(acnst[15],"first(",true, false); 
outxt(acnst[ 15 ], loc3 .sa , false, false); 
outatm(acnst[15],".sa,&pl",false, false); 
outxt(acnst[ 15 ], loc2 .sa , false, false); 
outatm(acnst[15],");",false, false); ;xxx; 
goto _L103;
;} 
{ 
outatm(acnst[15],"pl",true, false); 
outxt(acnst[ 15 ], loc2 .sa , false, false); 
outatm(acnst[15],".ptrtype=ptrlist;",false, false); 
outatm(acnst[15],"pl",false, false); 
outxt(acnst[ 15 ], loc2 .sa , false, false); 
outatm(acnst[15],".nel=0;pl",false, false); 
outxt(acnst[ 15 ], loc2 .sa , false, false); 
outatm(acnst[15],".cel=NULL;",false, false); ;xxx; 
;} 
_L103:;xxx; 

/* operator := */ 
selop( 0L,true, loc1 .sa, glob1_3 .sa ,& wrk1 .sa); 
loc8 .sa= wrk1 .sa ;xxx; 

outatm(acnst[15],"r",true, false); 
outxt(acnst[ 15 ], loc8 .sa , false, false); 
outatm(acnst[15],"(&",false, false); 
outxt(acnst[ 15 ], loc3 .sa , false, false); 
outatm(acnst[15],".sa,&flag",false, false); 
outxt(acnst[ 15 ], loc4 .sa , false, false); 
outatm(acnst[15],",&pl",false, false); 
outxt(acnst[ 15 ], loc2 .sa , false, false); 
outatm(acnst[15],");/* #",false, false); ;xxx; 

/* CALL #L */ 
pl2.ptrtype=packedlist;pl2.nel=1;pl2.cel=loc1.sa;
pl2.plistsize= 1;
r31(&wrk1.sa,&flag1,&pl2);/* #Print_name*/ ;xxx; 

outatm(acnst[15],"*/",false, true); ;xxx; 
goto _L99;  _L106:;  /* metka wyhoda po neuspehu wetwi */
 _L99: rez1=NULL; 
 _L98: *rez=rez1;*success=success1; 
 if (*success) *pl=pl1; /* prodwinutx ukazatelx leksem */ 
/* wosstanowitx GLOB */ 
#ifdef XX  
 d(2,"G_CALL", 19 ,*rez,*success); 
#endif 
;};/* RULE */ 
/*===============================================*/ 
/* GENERATED TEXT OF RULE   #G_OPEN   */ 
 Void r20(rez,success,pl)
long *rez;boolean *success;ptr_ *pl; 
{  a rez1;  boolean success1; long k; mpd x; 
v loc1;/* $ANOM*/ 
v loc2;/* $E*/ 
ptr_ pl1;
ptr_ pl2;
#ifdef XX  
 d(1,"G_OPEN", 20 ,pl->cel,0); 
#endif 
/* sohranitx GLOB */ 

/* branch */ pl1=*pl;rez1=NULL;success1=true; 
/* inicializaciq peremennyh */ 
loc1.sa=NULL;/* $ANOM*/ 
loc2.sa=NULL;/* $E*/ 

/* shablon treemain */ rez1=pl1.cel;
success1=false;if(pl1.nel==0 ) goto _L101; 
 if (rez1!=NULL ) { pointr(rez1,&x.sa); 
       if (x.smld->dtype!= treemain )  
        { rez1=NULL;goto _L101;};
/* prowerka imeni */ 
success1=eqatom(x.smld->name,acnst[ 30 ]); 
if( ! success1 ) { rez1=NULL;goto _L101;};
;}; 
pl2.nel=1;pl2.ptrtype=ptrtree;
success1=true; 
selop(acnst[26],false,0L,pl1.cel,&rez1);pl2.cel=rez1;
   if( rez1==NULL ) { success1=false;goto _L101;};

/* shablon peremennoj */ 
success1=(pl2.nel!=0);rez1=pl2.cel;
if( (pl2.ptrtype!=ptrtree) && success1 ) next(&pl2);
loc1 .sa=rez1; 
if( !success1 ) goto _L101;
selop(acnst[31],false,0L,pl1.cel,&rez1);pl2.cel=rez1;
   if( rez1==NULL ) { success1=false;goto _L101;};

loc2 .sa=NULL; 

/* shablon prawila */ r37(&rez1,&success1,&pl2);
if( !success1 ) goto _L101;
loc2 .sa=rez1; 
if( success1 ) {
 rez1=pl1.cel;if( pl1.ptrtype!=ptrtree ) next(&pl1) ;}
 else { rez1=NULL;goto _L101 ;};

outatm(acnst[15],"opn(acnst[",true, true); 
outxt(acnst[ 15 ], loc1 .sa , false, true); 
outatm(acnst[15],"],",false, true); 
outxt(acnst[ 15 ], loc2 .sa , false, true); 
outatm(acnst[15],")",false, true); ;xxx; 
goto _L99;  _L101:;  /* metka wyhoda po neuspehu wetwi */
 _L99: rez1=NULL; 
 _L98: *rez=rez1;*success=success1; 
 if (*success) *pl=pl1; /* prodwinutx ukazatelx leksem */ 
/* wosstanowitx GLOB */ 
#ifdef XX  
 d(2,"G_OPEN", 20 ,*rez,*success); 
#endif 
;};/* RULE */ 
/*===============================================*/ 
/* GENERATED TEXT OF RULE   #G_OUTXT   */ 
 Void r21(rez,success,pl)
long *rez;boolean *success;ptr_ *pl; 
{  a rez1;  boolean success1; long k; mpd x; 
v loc0;/* $_*/ 
v loc1;/* $ANOM*/ 
v loc2;/* $OP*/ 
v loc3;/* $NOBLANKS*/ 
v loc4;/* $E*/ 
v loc5;/* $I*/ 
v wrk1;
v wrk2;
v wrk3;
v wrk4;
ptr_ pl1;
ptr_ pl2;
ptr_ pl3;
ptr_ pl4;
ptr_ pl5;
ptr_ pl6;
ptr_ pl7;
boolean flag1;
#ifdef XX  
 d(1,"G_OUTXT", 21 ,pl->cel,0); 
#endif 
/* sohranitx GLOB */ 
loc0.sa=pl->cel; 

/* branch */ pl1=*pl;rez1=NULL;success1=true; 
/* inicializaciq peremennyh */ 
loc1.sa=NULL;/* $ANOM*/ 
loc2.sa=NULL;/* $OP*/ 
loc3.sa=NULL;/* $NOBLANKS*/ 
loc4.sa=NULL;/* $E*/ 
loc5.sa=NULL;/* $I*/ 

/* shablon treemain */ rez1=pl1.cel;
success1=false;if(pl1.nel==0 ) goto _L118; 
 if (rez1!=NULL ) { pointr(rez1,&x.sa); 
       if (x.smld->dtype!= treemain )  
        { rez1=NULL;goto _L118;};
/* prowerka imeni */ 
success1=eqatom(x.smld->name,acnst[ 32 ]); 
if( ! success1 ) { rez1=NULL;goto _L118;};
;}; 
pl2.nel=1;pl2.ptrtype=ptrtree;
success1=true; 
selop(acnst[26],false,0L,pl1.cel,&rez1);pl2.cel=rez1;
   if( rez1==NULL ) { success1=false;goto _L118;};

/* shablon peremennoj */ 
success1=(pl2.nel!=0);rez1=pl2.cel;
if( (pl2.ptrtype!=ptrtree) && success1 ) next(&pl2);
loc1 .sa=rez1; 
if( !success1 ) goto _L118;
selop(acnst[17],false,0L,pl1.cel,&rez1);pl2.cel=rez1;
   if( rez1==NULL ) { success1=false;goto _L118;};

/* shablon peremennoj */ 
success1=(pl2.nel!=0);rez1=pl2.cel;
if( (pl2.ptrtype!=ptrtree) && success1 ) next(&pl2);
loc2 .sa=rez1; 
if( !success1 ) goto _L118;
selop(acnst[33],false,0L,pl1.cel,&rez1);pl2.cel=rez1;
   if( rez1==NULL ) { success1=false;goto _L101;};

/* shablon listmain */ rez1=pl2.cel;
success1=false;if(pl2.nel==0 ) goto _L101; 
 if (rez1!=NULL ) { pointr(rez1,&x.sa); 
       if (x.smld->dtype!= listmain )  
        { rez1=NULL;goto _L101;};
{pl3.ptrtype=ptrlist; pl3.nel=1;
pl3.cel=x.smld->elt[0];pl3.UU.U1.curfragment=rez1;}
;} else  
{pl3.ptrtype=ptrlist;pl3.nel=0;pl3.cel=NULL;}

/*shablon STARLIST */ 
 pl4=pl3;while(pl3.nel!=0 ) { 

/* OPT SP */  
/* Alternative pattern */ 
pl5=pl3;
rez1=pl3.cel;
if ((pl3.nel==0) || (rez1==NULL)) goto _L104;
else { pointr(rez1,&x.sa); 
if (!((x.sad->dtype==atom)|| (x.sad->dtype==idatom)||(x.sad->dtype==keyword) 
||(x.sad->dtype==fatom)) ) goto _L104;
else x.sa=x.sad->name ;}; 

/* atomic branch */ 
if (x.sa==acnst[ 34 ] ) { success1=true; 
 if (pl3.ptrtype!=ptrtree ) 
next(&pl3);

/* operator := */ 
wrk1 .bo= loc3 .sa==NULL; 
if( wrk1 .bo ) wrk2 .sa=cnst[1].sa; else wrk2 .sa=NULL; 
loc3 .sa= wrk2 .sa ;xxx; 
goto _L115;}; _L104:;
success1=false;rez1=NULL; 
pl3=pl5;
/* nonatomic alternative branches */ 

/* Alternative pattern */ 
pl6=pl3;

loc4 .sa=NULL; 

bltin1(&rez1,&success1,&pl3,3L);
if( !success1 ) goto _L107;
loc4 .sa=rez1; 

/* operator +:= */ 
addnum(& loc5 .sa, 1L ) ;xxx; 

outatm(acnst[15],"outatm(acnst[",true, false); 
outxt(acnst[ 15 ], loc1 .sa , false, false); 
outatm(acnst[15],"],",false, false); 
/* CALL_PAS */ 
use_116(loc4.sa,NULL,NULL,&wrk2.sa);; 
outxt(acnst[ 15 ], wrk2 .sa , false, false); 
outatm(acnst[15],",",false, false); ;xxx; 

/* IF-operator */ 
/* operaciq = */ wrk1 .bo= eqnum( loc5 .sa , 1L ) ; 
if( !( wrk1 .bo )) wrk3 .bo=false; else { 
/* operaciq = */ wrk2 .bo= eqatom( loc2 .sa ,acnst[ 35 ]) ; wrk3 = wrk2 
;}/*log*/; 
if( wrk3 .bo) 
{ 
outatm(acnst[15],"true,",false, true); ;xxx; 
goto _L105;
;} 
{ 
outatm(acnst[15],"false,",false, true); ;xxx; 
;} 
_L105:;xxx; 

/* IF-operator */ 
if( loc3 .sa!=NULL) 
{ 
outatm(acnst[15],"false);",false, true); ;xxx; 
goto _L106;
;} 
{ 
outatm(acnst[15],"true);",false, true); ;xxx; 
;} 
_L106:;xxx; 
goto _L108/*uspeh*/;
_L107:; 
pl3=pl6;
goto  _L109;
_L108:;/*uspeh alxtern.*/
goto _L115/*uspeh*/;
_L109:; 
pl3=pl5;

/* Alternative pattern */ 
pl6=pl3;

loc4 .sa=NULL; 

/* shablon prawila */ r37(&rez1,&success1,&pl3);
if( !success1 ) goto _L112;
loc4 .sa=rez1; 

/* operator +:= */ 
addnum(& loc5 .sa, 1L ) ;xxx; 

outatm(acnst[15],"outxt(acnst[",true, true); 
outxt(acnst[ 15 ], loc1 .sa , false, true); 
outatm(acnst[15],"],",false, true); 
outxt(acnst[ 15 ], loc4 .sa , false, true); 
outatm(acnst[15],",",false, true); ;xxx; 

/* IF-operator */ 
/* operaciq = */ wrk1 .bo= eqnum( loc5 .sa , 1L ) ; 
if( !( wrk1 .bo )) wrk3 .bo=false; else { 
/* operaciq = */ wrk2 .bo= eqatom( loc2 .sa ,acnst[ 35 ]) ; wrk3 = wrk2 
;}/*log*/; 
if( wrk3 .bo) 
{ 
outatm(acnst[15],"true,",false, true); ;xxx; 
goto _L110;
;} 
{ 
outatm(acnst[15],"false,",false, true); ;xxx; 
;} 
_L110:;xxx; 

/* IF-operator */ 
if( loc3 .sa!=NULL) 
{ 
outatm(acnst[15],"false);",false, true); ;xxx; 
goto _L111;
;} 
{ 
outatm(acnst[15],"true);",false, true); ;xxx; 
;} 
_L111:;xxx; 
goto _L113/*uspeh*/;
_L112:; 
pl3=pl6;
goto  _L114;
_L113:;/*uspeh alxtern.*/
goto _L115/*uspeh*/;
_L114:; 
pl3=pl5;
goto  _L116;
_L115:;/*uspeh alxtern.*/
 pl4=pl3;
;}; 
_L116:if( ! success1 )pl3=pl4;
success1 = true ; 

if( pl3.nel !=0 )
{ success1=false;rez1=NULL;goto _L101;};
success1=true;rez1=pl2.cel;
 if( pl2.ptrtype!=ptrtree ) next(&pl2);
_L101:success1=true;
if( success1 ) {
 rez1=pl1.cel;if( pl1.ptrtype!=ptrtree ) next(&pl1) ;}
 else { rez1=NULL;goto _L118 ;};

/* IF-operator */ 
selop( acnst[ 33 ],false,NULL, loc0 .sa ,& wrk1 .sa); 
/* operaciq = */ wrk2 .bo= wrk1 .sa ==NULL ; 
if( !( wrk2 .bo )) wrk4 .bo=false; else { 
/* operaciq = */ wrk3 .bo= eqatom( loc2 .sa ,acnst[ 35 ]) ; wrk4 = wrk3 
;}/*log*/; 
if( wrk4 .bo) 
{ 
outatm(acnst[15],"outxt(acnst[",true, true); 
outxt(acnst[ 15 ], loc1 .sa , false, true); 
outatm(acnst[15],"],NULL,true,false)",false, true); ;xxx; 
;} 
_L117:;xxx; 
goto _L99;  _L118:;  /* metka wyhoda po neuspehu wetwi */
 _L99: rez1=NULL; 
 _L98: *rez=rez1;*success=success1; 
 if (*success) *pl=pl1; /* prodwinutx ukazatelx leksem */ 
/* wosstanowitx GLOB */ 
#ifdef XX  
 d(2,"G_OUTXT", 21 ,*rez,*success); 
#endif 
;};/* RULE */ 
/*===============================================*/ 
/* GENERATED TEXT OF RULE   #G_CLOSE   */ 
 Void r22(rez,success,pl)
long *rez;boolean *success;ptr_ *pl; 
{  a rez1;  boolean success1; long k; mpd x; 
v loc1;/* $ANOM*/ 
ptr_ pl1;
ptr_ pl2;
#ifdef XX  
 d(1,"G_CLOSE", 22 ,pl->cel,0); 
#endif 
/* sohranitx GLOB */ 

/* branch */ pl1=*pl;rez1=NULL;success1=true; 
/* inicializaciq peremennyh */ 
loc1.sa=NULL;/* $ANOM*/ 

/* shablon listmain */ rez1=pl1.cel;
success1=false;if(pl1.nel==0 ) goto _L101; 
 if (rez1!=NULL ) { pointr(rez1,&x.sa); 
       if (x.smld->dtype!= listmain )  
        { rez1=NULL;goto _L101;};
/* prowerka imeni */ 
success1=eqatom(x.smld->name,acnst[ 36 ]); 
if( ! success1 ) { rez1=NULL;goto _L101;};
{pl2.ptrtype=ptrlist; pl2.nel=1;
pl2.cel=x.smld->elt[0];pl2.UU.U1.curfragment=rez1;}
;} else  
{pl2.ptrtype=ptrlist;pl2.nel=0;pl2.cel=NULL;}

/* shablon peremennoj */ 
success1=(pl2.nel!=0);rez1=pl2.cel;
if( (pl2.ptrtype!=ptrtree) && success1 ) next(&pl2);
loc1 .sa=rez1; 
if( !success1 ) goto _L101;

if( pl2.nel !=0 )
{ success1=false;rez1=NULL;goto _L101;};
success1=true;rez1=pl1.cel;
 if( pl1.ptrtype!=ptrtree ) next(&pl1);

outatm(acnst[15],"clsfil(acnst[",true, true); 
outxt(acnst[ 15 ], loc1 .sa , false, true); 
outatm(acnst[15],"])",false, true); ;xxx; 
goto _L99;  _L101:;  /* metka wyhoda po neuspehu wetwi */
 _L99: rez1=NULL; 
 _L98: *rez=rez1;*success=success1; 
 if (*success) *pl=pl1; /* prodwinutx ukazatelx leksem */ 
/* wosstanowitx GLOB */ 
#ifdef XX  
 d(2,"G_CLOSE", 22 ,*rez,*success); 
#endif 
;};/* RULE */ 
/*===============================================*/ 
/* GENERATED TEXT OF RULE   #G_LOOP   */ 
 Void r23(rez,success,pl)
long *rez;boolean *success;ptr_ *pl; 
{  a rez1;  boolean success1; long k; mpd x; 
v loc1;/* $LABEL*/ 
v loc2;/* $OLDBL*/ 
v loc3;/* $NPL*/ 
v loc4;/* $VAR*/ 
v loc5;/* $BVAR*/ 
v loc6;/* $E*/ 
v wrk1;
v wrk2;
ptr_ pl1;
ptr_ pl2;
ptr_ pl3;
ptr_ pl4;
boolean flag1;
#ifdef XX  
 d(1,"G_LOOP", 23 ,pl->cel,0); 
#endif 
/* sohranitx GLOB */ 

/* branch */ pl1=*pl;rez1=NULL;success1=true; 
/* inicializaciq peremennyh */ 
loc1.sa=NULL;/* $LABEL*/ 
loc2.sa=NULL;/* $OLDBL*/ 

/* shablon treemain */ rez1=pl1.cel;
success1=false;if(pl1.nel==0 ) goto _L103; 
 if (rez1!=NULL ) { pointr(rez1,&x.sa); 
       if (x.smld->dtype!= treemain )  
        { rez1=NULL;goto _L103;};
/* prowerka imeni */ 
success1=eqatom(x.smld->name,acnst[ 37 ]); 
if( ! success1 ) { rez1=NULL;goto _L103;};
;}; 
pl2.nel=1;pl2.ptrtype=ptrtree;
success1=true; 
selop(acnst[38],false,0L,pl1.cel,&rez1);pl2.cel=rez1;
   if( rez1==NULL ) { success1=false;goto _L103;};

/* shablon peremennoj */ 
success1=(pl2.nel!=0);rez1=pl2.cel;
if( (pl2.ptrtype!=ptrtree) && success1 ) next(&pl2);
loc1 .sa=rez1; 
if( !success1 ) goto _L103;

outatm(acnst[15],"/*LOOP*/while (true) {",true, true); ;xxx; 

/* operator := */ 
loc2 .sa= glob24_1 .sa ;xxx; 

/* operator := */ 
glob24_1 .sa= loc1 .sa ;xxx; 
selop(acnst[39],false,0L,pl1.cel,&rez1);pl2.cel=rez1;
   if( rez1==NULL ) { success1=false;goto _L101;};

/* shablon listmain */ rez1=pl2.cel;
success1=false;if(pl2.nel==0 ) goto _L101; 
 if (rez1!=NULL ) { pointr(rez1,&x.sa); 
       if (x.smld->dtype!= listmain )  
        { rez1=NULL;goto _L101;};
{pl3.ptrtype=ptrlist; pl3.nel=1;
pl3.cel=x.smld->elt[0];pl3.UU.U1.curfragment=rez1;}
;} else  
{pl3.ptrtype=ptrlist;pl3.nel=0;pl3.cel=NULL;}

/*shablon STARLIST */ 
 pl4=pl3;while(pl3.nel!=0 ) { 

/* shablon prawila */ r63(&rez1,&success1,&pl3);
if( !success1 ) goto _L102;
 pl4=pl3;
;}; 
_L102:if( ! success1 )pl3=pl4;
success1 = true ; 

if( pl3.nel !=0 )
{ success1=false;rez1=NULL;goto _L101;};
success1=true;rez1=pl2.cel;
 if( pl2.ptrtype!=ptrtree ) next(&pl2);
_L101:success1=true;
if( success1 ) {
 rez1=pl1.cel;if( pl1.ptrtype!=ptrtree ) next(&pl1) ;}
 else { rez1=NULL;goto _L103 ;};

outatm(acnst[15],";};  _L",true, false); 
outxt(acnst[ 15 ], loc1 .sa , false, false); 
outatm(acnst[15],":/*END LOOP*/",false, false); ;xxx; 

/* operator := */ 
glob24_1 .sa= loc2 .sa ;xxx; 
goto _L99;  _L103:;  /* metka wyhoda po neuspehu wetwi */

/* branch */ pl1=*pl;rez1=NULL;success1=true; 
/* inicializaciq peremennyh */ 
loc1.sa=NULL;/* $LABEL*/ 
loc2.sa=NULL;/* $OLDBL*/ 
loc3.sa=NULL;/* $NPL*/ 
loc4.sa=NULL;/* $VAR*/ 
loc5.sa=NULL;/* $BVAR*/ 
loc6.sa=NULL;/* $E*/ 

/* shablon treemain */ rez1=pl1.cel;
success1=false;if(pl1.nel==0 ) goto _L111; 
 if (rez1!=NULL ) { pointr(rez1,&x.sa); 
       if (x.smld->dtype!= treemain )  
        { rez1=NULL;goto _L111;};
/* prowerka imeni */ 
success1=eqatom(x.smld->name,acnst[ 40 ]); 
if( ! success1 ) { rez1=NULL;goto _L111;};
;}; 
pl2.nel=1;pl2.ptrtype=ptrtree;
success1=true; 
selop(acnst[38],false,0L,pl1.cel,&rez1);pl2.cel=rez1;
   if( rez1==NULL ) { success1=false;goto _L111;};

/* shablon peremennoj */ 
success1=(pl2.nel!=0);rez1=pl2.cel;
if( (pl2.ptrtype!=ptrtree) && success1 ) next(&pl2);
loc1 .sa=rez1; 
if( !success1 ) goto _L111;

outatm(acnst[15],"/*FORALL-op.*/",true, true); ;xxx; 

/* operator := */ 
loc2 .sa= glob24_1 .sa ;xxx; 

/* operator := */ 
glob24_1 .sa= loc1 .sa ;xxx; 
selop(acnst[27],false,0L,pl1.cel,&rez1);pl2.cel=rez1;
   if( rez1==NULL ) { success1=false;goto _L111;};

/* shablon peremennoj */ 
varpat(&pl2,number,&rez1,&success1);
loc3 .sa=rez1; 
if( !success1 ) goto _L111;
selop(acnst[41],false,0L,pl1.cel,&rez1);pl2.cel=rez1;
   if( rez1==NULL ) { success1=false;goto _L104;};

/* shablon peremennoj */ 
success1=(pl2.nel!=0);rez1=pl2.cel;
if( (pl2.ptrtype!=ptrtree) && success1 ) next(&pl2);
loc4 .sa=rez1; 
if( !success1 ) goto _L104;

/* CALL #L */ 
pl3.ptrtype=packedlist;pl3.nel=1;pl3.cel=loc4.sa;
pl3.plistsize= 1;
r41(&wrk1.sa,&flag1,&pl3);/* #G_wyravenie*/ ;xxx; 
_L104:success1=true;
selop(acnst[42],false,0L,pl1.cel,&rez1);pl2.cel=rez1;
   if( rez1==NULL ) { success1=false;goto _L105;};

/* shablon peremennoj */ 
success1=(pl2.nel!=0);rez1=pl2.cel;
if( (pl2.ptrtype!=ptrtree) && success1 ) next(&pl2);
loc5 .sa=rez1; 
if( !success1 ) goto _L105;

/* CALL #L */ 
pl3.ptrtype=packedlist;pl3.nel=1;pl3.cel=loc5.sa;
pl3.plistsize= 1;
r41(&wrk1.sa,&flag1,&pl3);/* #G_wyravenie*/ ;xxx; 
_L105:success1=true;
selop(acnst[43],false,0L,pl1.cel,&rez1);pl2.cel=rez1;
   if( rez1==NULL ) { success1=false;goto _L111;};

loc6 .sa=NULL; 

/* shablon prawila */ r37(&rez1,&success1,&pl2);
if( !success1 ) goto _L111;
loc6 .sa=rez1; 

outatm(acnst[15],"if( ",true, false); 
outxt(acnst[ 15 ], loc6 .sa , false, false); 
outatm(acnst[15],"==NULL ) goto _L",false, false); 
outxt(acnst[ 15 ], loc1 .sa , false, false); 
outatm(acnst[15],";",false, false); ;xxx; 

outatm(acnst[15],"pointr (",true, true); 
outxt(acnst[ 15 ], loc6 .sa , false, true); 
outatm(acnst[15],",&x.sa); ",false, true); ;xxx; 

outatm(acnst[15],"if( (x.smld->dtype!=listmain)&&(x.smld->dtype!=treemain)",
true, true); ;xxx; 

outatm(acnst[15],"  ) { er(24L);goto _L",true, false); 
outxt(acnst[ 15 ], loc1 .sa , false, false); 
outatm(acnst[15],";}; ",false, false); ;xxx; 

outatm(acnst[15],"first(",true, false); 
outxt(acnst[ 15 ], loc6 .sa , false, false); 
outatm(acnst[15],",&pl",false, false); 
outxt(acnst[ 15 ], loc3 .sa , false, false); 
outatm(acnst[15],");",false, false); ;xxx; 

outatm(acnst[15],"while (pl",true, false); 
outxt(acnst[ 15 ], loc3 .sa , false, false); 
outatm(acnst[15],".nel!=0){",false, false); ;xxx; 

outatm(acnst[15],"    if( pl",true, false); 
outxt(acnst[ 15 ], loc3 .sa , false, false); 
outatm(acnst[15],".ptrtype==ptrlist ) ",false, false); ;xxx; 

/* IF-operator */ 
if( loc4 .sa==NULL ) wrk2 .bo=false; else { 
wrk1 .bo= loc5 .sa==NULL; wrk2 = wrk1 ;}; 
if( wrk2 .bo) 
{ 
outatm(acnst[15],"{",true, false); 
selop( acnst[ 19 ],false,NULL, loc4 .sa ,& wrk1 .sa); 
outxt(acnst[ 15 ], wrk1 .sa , false, false); 
outatm(acnst[15],".sa=pl",false, false); 
outxt(acnst[ 15 ], loc3 .sa , false, false); 
outatm(acnst[15],".cel;} ",false, false); ;xxx; 
goto _L106;
;} 
{ 
outatm(acnst[15],"{ er(26L); goto _L",true, false); 
outxt(acnst[ 15 ], loc1 .sa , false, false); 
outatm(acnst[15],";}",false, false); ;xxx; 
;} 
_L106:;xxx; 

outatm(acnst[15],"   else {",true, false); ;xxx; 

/* IF-operator */ 
if( loc4 .sa!=NULL) 
{ 
outatm(acnst[15],"  mkatom(pl",true, false); 
outxt(acnst[ 15 ], loc3 .sa , false, false); 
outatm(acnst[15],".UU.U1.arc,idatom,&",false, false); 
selop( acnst[ 19 ],false,NULL, loc4 .sa ,& wrk1 .sa); 
outxt(acnst[ 15 ], wrk1 .sa , false, false); 
outatm(acnst[15],".sa);",false, false); ;xxx; 
;} 
_L107:;xxx; 

/* IF-operator */ 
if( loc5 .sa!=NULL) 
{ 
selop( acnst[ 19 ],false,NULL, loc5 .sa ,& wrk1 .sa); 
outxt(acnst[ 15 ], wrk1 .sa , true, false); 
outatm(acnst[15],".sa=pl",false, false); 
outxt(acnst[ 15 ], loc3 .sa , false, false); 
outatm(acnst[15],".cel ",false, false); ;xxx; 
;} 
_L108:;xxx; 

outatm(acnst[15],";};",true, true); ;xxx; 
selop(acnst[39],false,0L,pl1.cel,&rez1);pl2.cel=rez1;
   if( rez1==NULL ) { success1=false;goto _L109;};

/* shablon listmain */ rez1=pl2.cel;
success1=false;if(pl2.nel==0 ) goto _L109; 
 if (rez1!=NULL ) { pointr(rez1,&x.sa); 
       if (x.smld->dtype!= listmain )  
        { rez1=NULL;goto _L109;};
{pl3.ptrtype=ptrlist; pl3.nel=1;
pl3.cel=x.smld->elt[0];pl3.UU.U1.curfragment=rez1;}
;} else  
{pl3.ptrtype=ptrlist;pl3.nel=0;pl3.cel=NULL;}

/*shablon STARLIST */ 
 pl4=pl3;while(pl3.nel!=0 ) { 

/* shablon prawila */ r63(&rez1,&success1,&pl3);
if( !success1 ) goto _L110;
 pl4=pl3;
;}; 
_L110:if( ! success1 )pl3=pl4;
success1 = true ; 

if( pl3.nel !=0 )
{ success1=false;rez1=NULL;goto _L109;};
success1=true;rez1=pl2.cel;
 if( pl2.ptrtype!=ptrtree ) next(&pl2);
_L109:success1=true;
if( success1 ) {
 rez1=pl1.cel;if( pl1.ptrtype!=ptrtree ) next(&pl1) ;}
 else { rez1=NULL;goto _L111 ;};

outatm(acnst[15],"next(&pl",true, false); 
outxt(acnst[ 15 ], loc3 .sa , false, false); 
outatm(acnst[15],") ;};",false, false); 
outatm(acnst[15],"_L",false, false); 
outxt(acnst[ 15 ], loc1 .sa , false, false); 
outatm(acnst[15],":/*END FORALL*/",false, false); ;xxx; 

/* operator := */ 
glob24_1 .sa= loc2 .sa ;xxx; 
goto _L99;  _L111:;  /* metka wyhoda po neuspehu wetwi */
 _L99: rez1=NULL; 
 _L98: *rez=rez1;*success=success1; 
 if (*success) *pl=pl1; /* prodwinutx ukazatelx leksem */ 
/* wosstanowitx GLOB */ 
#ifdef XX  
 d(2,"G_LOOP", 23 ,*rez,*success); 
#endif 
;};/* RULE */ 
/*===============================================*/ 
/* GENERATED TEXT OF RULE   #G_BREAK   */ 
 Void r25(rez,success,pl)
long *rez;boolean *success;ptr_ *pl; 
{  a rez1;  boolean success1; long k; mpd x; 
ptr_ pl1;
ptr_ pl2;
#ifdef XX  
 d(1,"G_BREAK", 25 ,pl->cel,0); 
#endif 
/* sohranitx GLOB */ 

/* branch */ pl1=*pl;rez1=NULL;success1=true; 
/* inicializaciq peremennyh */ 

/* shablon listmain */ rez1=pl1.cel;
success1=false;if(pl1.nel==0 ) goto _L102; 
 if (rez1!=NULL ) { pointr(rez1,&x.sa); 
       if (x.smld->dtype!= listmain )  
        { rez1=NULL;goto _L102;};
/* prowerka imeni */ 
success1=eqatom(x.smld->name,acnst[ 44 ]); 
if( ! success1 ) { rez1=NULL;goto _L102;};
{pl2.ptrtype=ptrlist; pl2.nel=1;
pl2.cel=x.smld->elt[0];pl2.UU.U1.curfragment=rez1;}
;} else  
{pl2.ptrtype=ptrlist;pl2.nel=0;pl2.cel=NULL;}

/* shablon atoma */ atmpat(acnst[1],&pl2,&rez1,&success1);
if( !success1 ) goto _L102;

if( pl2.nel !=0 )
{ success1=false;rez1=NULL;goto _L102;};
success1=true;rez1=pl1.cel;
 if( pl1.ptrtype!=ptrtree ) next(&pl1);

/* IF-operator */ 
if( glob24_1 .sa!=NULL) 
{ 
outxt(acnst[ 15 ], cnst[19] .sa , true, false); 
outxt(acnst[ 15 ], glob24_1 .sa , false, false); ;xxx; 
;} 
_L101:;xxx; 
goto _L99;  _L102:;  /* metka wyhoda po neuspehu wetwi */
 _L99: rez1=NULL; 
 _L98: *rez=rez1;*success=success1; 
 if (*success) *pl=pl1; /* prodwinutx ukazatelx leksem */ 
/* wosstanowitx GLOB */ 
#ifdef XX  
 d(2,"G_BREAK", 25 ,*rez,*success); 
#endif 
;};/* RULE */ 
/*===============================================*/ 
/* GENERATED TEXT OF RULE   #G_BLTIN   */ 
 Void r26(rez,success,pl)
long *rez;boolean *success;ptr_ *pl; 
{  a rez1;  boolean success1; long k; mpd x; 
v loc1;/* $N*/ 
v loc2;/* $E*/ 
v loc3;/* $WRK*/ 
v loc4;/* $NFLAG*/ 
v loc5;/* $NPL*/ 
v wrk1;
v wrk2;
ptr_ pl1;
ptr_ pl2;
ptr_ pl3;
boolean flag1;
#ifdef XX  
 d(1,"G_BLTIN", 26 ,pl->cel,0); 
#endif 
/* sohranitx GLOB */ 

/* branch */ pl1=*pl;rez1=NULL;success1=true; 
/* inicializaciq peremennyh */ 
loc1.sa=NULL;/* $N*/ 
loc2.sa=NULL;/* $E*/ 
loc3.sa=NULL;/* $WRK*/ 
loc4.sa=NULL;/* $NFLAG*/ 

/* shablon treemain */ rez1=pl1.cel;
success1=false;if(pl1.nel==0 ) goto _L101; 
 if (rez1!=NULL ) { pointr(rez1,&x.sa); 
       if (x.smld->dtype!= treemain )  
        { rez1=NULL;goto _L101;};
/* prowerka imeni */ 
success1=eqatom(x.smld->name,acnst[ 45 ]); 
if( ! success1 ) { rez1=NULL;goto _L101;};
;}; 
pl2.nel=1;pl2.ptrtype=ptrtree;
success1=true; 
selop(acnst[46],false,0L,pl1.cel,&rez1);pl2.cel=rez1;
   if( rez1==NULL ) { success1=false;goto _L101;};

/* shablon peremennoj */ 
varpat(&pl2,number,&rez1,&success1);
loc1 .sa=rez1; 
if( !success1 ) goto _L101;
selop(acnst[47],false,0L,pl1.cel,&rez1);pl2.cel=rez1;
   if( rez1==NULL ) { success1=false;goto _L101;};

loc2 .sa=NULL; 

/* shablon prawila */ r37(&rez1,&success1,&pl2);
if( !success1 ) goto _L101;
loc2 .sa=rez1; 
selop(acnst[19],false,0L,pl1.cel,&rez1);pl2.cel=rez1;
   if( rez1==NULL ) { success1=false;goto _L101;};

/* shablon peremennoj */ 
success1=(pl2.nel!=0);rez1=pl2.cel;
if( (pl2.ptrtype!=ptrtree) && success1 ) next(&pl2);
loc3 .sa=rez1; 
if( !success1 ) goto _L101;
selop(acnst[28],false,0L,pl1.cel,&rez1);pl2.cel=rez1;
   if( rez1==NULL ) { success1=false;goto _L101;};

/* shablon peremennoj */ 
varpat(&pl2,number,&rez1,&success1);
loc4 .sa=rez1; 
if( !success1 ) goto _L101;
if( success1 ) {
 rez1=pl1.cel;if( pl1.ptrtype!=ptrtree ) next(&pl1) ;}
 else { rez1=NULL;goto _L101 ;};

outatm(acnst[15],"bltin(&",true, false); 
outxt(acnst[ 15 ], loc3 .sa , false, false); 
outatm(acnst[15],",&flag",false, false); 
outxt(acnst[ 15 ], loc4 .sa , false, false); 
outatm(acnst[15],",",false, false); 
outxt(acnst[ 15 ], loc2 .sa , false, false); 
outatm(acnst[15],",",false, false); 
outxt(acnst[ 15 ], loc1 .sa , false, false); 
outatm(acnst[15],"L)",false, false); ;xxx; 
goto _L99;  _L101:;  /* metka wyhoda po neuspehu wetwi */

/* branch */ pl1=*pl;rez1=NULL;success1=true; 
/* inicializaciq peremennyh */ 
loc2.sa=NULL;/* $E*/ 
loc3.sa=NULL;/* $WRK*/ 
loc5.sa=NULL;/* $NPL*/ 

/* shablon treemain */ rez1=pl1.cel;
success1=false;if(pl1.nel==0 ) goto _L104; 
 if (rez1!=NULL ) { pointr(rez1,&x.sa); 
       if (x.smld->dtype!= treemain )  
        { rez1=NULL;goto _L104;};
/* prowerka imeni */ 
success1=eqatom(x.smld->name,acnst[ 48 ]); 
if( ! success1 ) { rez1=NULL;goto _L104;};
;}; 
pl2.nel=1;pl2.ptrtype=ptrtree;
success1=true; 
selop(acnst[27],false,0L,pl1.cel,&rez1);pl2.cel=rez1;
   if( rez1==NULL ) { success1=false;goto _L104;};

/* shablon peremennoj */ 
varpat(&pl2,number,&rez1,&success1);
loc5 .sa=rez1; 
if( !success1 ) goto _L104;
selop(acnst[19],false,0L,pl1.cel,&rez1);pl2.cel=rez1;
   if( rez1==NULL ) { success1=false;goto _L104;};

/* shablon peremennoj */ 
success1=(pl2.nel!=0);rez1=pl2.cel;
if( (pl2.ptrtype!=ptrtree) && success1 ) next(&pl2);
loc3 .sa=rez1; 
if( !success1 ) goto _L104;
selop(acnst[29],false,0L,pl1.cel,&rez1);pl2.cel=rez1;
   if( rez1==NULL ) { success1=false;goto _L102;};

/* shablon peremennoj */ 
success1=(pl2.nel!=0);rez1=pl2.cel;
if( (pl2.ptrtype!=ptrtree) && success1 ) next(&pl2);
loc2 .sa=rez1; 
if( !success1 ) goto _L102;

outxt(acnst[ 15 ], loc3 .sa , true, true); 
outatm(acnst[15],".sa=NULL;",false, true); ;xxx; 

/* CALL #L */ 
wrk1 .sa =NULL; 
lconc(& wrk1 .sa , loc3 .sa ); 
lconc(& wrk1 .sa , cnst[18] .sa ); 
pl3.ptrtype=packedlist;pl3.nel=1;pl3.cel=wrk1.sa;
pl3.UU.plistelt[ 0 ]=loc2.sa;
pl3.plistsize= 2;
r45(&wrk2.sa,&flag1,&pl3);/* #CONLIST*/ ;xxx; 
_L102:success1=true;
if( success1 ) {
 rez1=pl1.cel;if( pl1.ptrtype!=ptrtree ) next(&pl1) ;}
 else { rez1=NULL;goto _L104 ;};

/* IF-operator */ 
if( loc2 .sa!=NULL) 
{ 
outatm(acnst[15],"first(",true, false); 
outxt(acnst[ 15 ], loc3 .sa , false, false); 
outatm(acnst[15],".sa,&pl",false, false); 
outxt(acnst[ 15 ], loc5 .sa , false, false); 
outatm(acnst[15],");implod(&pl",false, false); 
outxt(acnst[ 15 ], loc5 .sa , false, false); 
outatm(acnst[15],",&",false, false); 
outxt(acnst[ 15 ], loc3 .sa , false, false); 
outatm(acnst[15],".sa)",false, false); ;xxx; 
goto _L103;
;} 
{ 
outxt(acnst[ 15 ], loc3 .sa , true, true); 
outatm(acnst[15],".sa=NULL",false, true); ;xxx; 
;} 
_L103:;xxx; 
goto _L99;  _L104:;  /* metka wyhoda po neuspehu wetwi */

/* branch */ pl1=*pl;rez1=NULL;success1=true; 
/* inicializaciq peremennyh */ 
loc2.sa=NULL;/* $E*/ 
loc3.sa=NULL;/* $WRK*/ 

/* shablon treemain */ rez1=pl1.cel;
success1=false;if(pl1.nel==0 ) goto _L105; 
 if (rez1!=NULL ) { pointr(rez1,&x.sa); 
       if (x.smld->dtype!= treemain )  
        { rez1=NULL;goto _L105;};
/* prowerka imeni */ 
success1=eqatom(x.smld->name,acnst[ 49 ]); 
if( ! success1 ) { rez1=NULL;goto _L105;};
;}; 
pl2.nel=1;pl2.ptrtype=ptrtree;
success1=true; 
selop(acnst[47],false,0L,pl1.cel,&rez1);pl2.cel=rez1;
   if( rez1==NULL ) { success1=false;goto _L105;};

loc2 .sa=NULL; 

/* shablon prawila */ r37(&rez1,&success1,&pl2);
if( !success1 ) goto _L105;
loc2 .sa=rez1; 
selop(acnst[19],false,0L,pl1.cel,&rez1);pl2.cel=rez1;
   if( rez1==NULL ) { success1=false;goto _L105;};

/* shablon peremennoj */ 
success1=(pl2.nel!=0);rez1=pl2.cel;
if( (pl2.ptrtype!=ptrtree) && success1 ) next(&pl2);
loc3 .sa=rez1; 
if( !success1 ) goto _L105;
if( success1 ) {
 rez1=pl1.cel;if( pl1.ptrtype!=ptrtree ) next(&pl1) ;}
 else { rez1=NULL;goto _L105 ;};

outatm(acnst[15],"if(",true, true); 
outxt(acnst[ 15 ], loc2 .sa , false, true); 
outatm(acnst[15],"==NULL )",false, true); 
outxt(acnst[ 15 ], loc3 .sa , false, true); 
outatm(acnst[15],".sa=NULL; else explod(",false, true); 
outxt(acnst[ 15 ], loc2 .sa , false, true); 
outatm(acnst[15],",&",false, true); 
outxt(acnst[ 15 ], loc3 .sa , false, true); 
outatm(acnst[15],".sa)",false, true); ;xxx; 
goto _L99;  _L105:;  /* metka wyhoda po neuspehu wetwi */
 _L99: rez1=NULL; 
 _L98: *rez=rez1;*success=success1; 
 if (*success) *pl=pl1; /* prodwinutx ukazatelx leksem */ 
/* wosstanowitx GLOB */ 
#ifdef XX  
 d(2,"G_BLTIN", 26 ,*rez,*success); 
#endif 
;};/* RULE */ 
/*===============================================*/ 
/* GENERATED TEXT OF RULE   #G_CALL_PAS   */ 
 Void r27(rez,success,pl)
long *rez;boolean *success;ptr_ *pl; 
{  a rez1;  boolean success1; long k; mpd x; 
v loc1;/* $NPL*/ 
v loc2;/* $WRK*/ 
v loc3;/* $E*/ 
v loc4;/* $T*/ 
v loc5;/* $M*/ 
v loc6;/* $X*/ 
v loc7;/* $IND_E*/ 
v loc8;/* $A*/ 
v wrk1;
v wrk2;
v wrk3;
ptr_ pl1;
ptr_ pl2;
boolean flag1;
#ifdef XX  
 d(1,"G_CALL_PAS", 27 ,pl->cel,0); 
#endif 
/* sohranitx GLOB */ 

/* branch */ pl1=*pl;rez1=NULL;success1=true; 
/* inicializaciq peremennyh */ 
loc2.sa=NULL;/* $WRK*/ 
loc3.sa=NULL;/* $E*/ 
loc4.sa=NULL;/* $T*/ 
loc5.sa=NULL;/* $M*/ 
loc6.sa=NULL;/* $X*/ 
loc7.sa=NULL;/* $IND_E*/ 
loc8.sa=NULL;/* $A*/ 

/* shablon treemain */ rez1=pl1.cel;
success1=false;if(pl1.nel==0 ) goto _L108; 
 if (rez1!=NULL ) { pointr(rez1,&x.sa); 
       if (x.smld->dtype!= treemain )  
        { rez1=NULL;goto _L108;};
/* prowerka imeni */ 
success1=eqatom(x.smld->name,acnst[ 25 ]); 
if( ! success1 ) { rez1=NULL;goto _L108;};
;}; 
pl2.nel=1;pl2.ptrtype=ptrtree;
success1=true; 
selop(acnst[26],false,0L,pl1.cel,&rez1);pl2.cel=rez1;
   if( rez1==NULL ) { success1=false;goto _L108;};

/* shablon atoma */ atmpat(acnst[50],&pl2,&rez1,&success1);
if( !success1 ) goto _L108;

outatm(acnst[15],"/* CALL_PAS */",true, true); ;xxx; 
selop(acnst[27],false,0L,pl1.cel,&rez1);pl2.cel=rez1;
   if( rez1==NULL ) { success1=false;goto _L108;};

/* shablon peremennoj */ 
varpat(&pl2,number,&rez1,&success1);
loc1 .sa=rez1; 
if( !success1 ) goto _L108;
selop(acnst[19],false,0L,pl1.cel,&rez1);pl2.cel=rez1;
   if( rez1==NULL ) { success1=false;goto _L108;};

/* shablon peremennoj */ 
success1=(pl2.nel!=0);rez1=pl2.cel;
if( (pl2.ptrtype!=ptrtree) && success1 ) next(&pl2);
loc2 .sa=rez1; 
if( !success1 ) goto _L108;
selop(acnst[29],false,0L,pl1.cel,&rez1);pl2.cel=rez1;
   if( rez1==NULL ) { success1=false;goto _L101;};

/* shablon peremennoj */ 
success1=(pl2.nel!=0);rez1=pl2.cel;
if( (pl2.ptrtype!=ptrtree) && success1 ) next(&pl2);
loc3 .sa=rez1; 
if( !success1 ) goto _L101;
_L101:success1=true;
if( success1 ) {
 rez1=pl1.cel;if( pl1.ptrtype!=ptrtree ) next(&pl1) ;}
 else { rez1=NULL;goto _L108 ;};

/* IF-operator */ 
if( loc3 .sa!=NULL) 
{ 
/* CALL #L */ 
indxop( 1L,false,NULL, loc3 .sa ,& wrk1 .sa); 
pl2.ptrtype=packedlist;pl2.nel=1;pl2.cel=wrk1.sa;
pl2.plistsize= 1;
r41(&wrk2.sa,&flag1,&pl2);/* #G_wyravenie*/ ;xxx; 
;} 
_L102:;xxx; 

/* operator := */ 
indxop( 1L,false,NULL, loc3 .sa ,& wrk1 .sa); 
selop( acnst[ 17 ],false,NULL, wrk1 .sa ,& wrk2 .sa); 
loc4 .sa= wrk2 .sa ;xxx; 

/* operator := */ 
indxop( 1L,false,NULL, loc3 .sa ,& wrk1 .sa); 
selop( acnst[ 19 ],false,NULL, wrk1 .sa ,& wrk2 .sa); 
loc5 .sa= wrk2 .sa ;xxx; 

/* IF-operator */ 
/* operaciq = */ wrk1 .bo= eqatom( loc4 .sa ,acnst[ 21 ]) ; 
if( !( wrk1 .bo )) wrk3 .bo=false; else { 
bltin(&wrk2,&flag1,loc5.sa,4L); wrk3 .bo= wrk2 .sa!=NULL ;}/*log*/; 
if( wrk3 .bo) 
{ 
/* operator := */ 
loc6 .sa= loc5 .sa ;xxx; 
goto _L103;
;} 
/* operaciq = */ wrk1 .bo= eqatom( loc4 .sa ,acnst[ 21 ]) ; 
if( wrk1 .bo) 
{ 
/* operator := */ 
wrk1 .sa =NULL; 
lconc(& wrk1 .sa , loc5 .sa ); 
lconc(& wrk1 .sa , cnst[20] .sa ); 
loc6 .sa= wrk1 .sa ;xxx; 
goto _L103;
;} 
if( loc4 .sa!=NULL ) wrk3 .bo=true; else { 
/* operaciq = */ wrk2 .bo= eqatom( loc5 .sa ,acnst[ 24 ]) ; wrk3 = wrk2 ;}; 
if( wrk3 .bo) 
{ 
/* operator := */ 
loc6 .sa= cnst[21] .sa ;xxx; 
goto _L103;
;} 
indxop( 1L,false,NULL, loc3 .sa ,& wrk1 .sa); 
if( wrk1 .sa!=NULL) 
{ 
/* operator := */ 
wrk1 .sa =NULL; 
lconc(& wrk1 .sa , cnst[22] .sa ); 
lconc(& wrk1 .sa , loc5 .sa ); 
lconc(& wrk1 .sa , cnst[23] .sa ); 
loc6 .sa= wrk1 .sa ;xxx; 
goto _L103;
;} 
{ 
/* operator := */ 
loc6 .sa= cnst[21] .sa ;xxx; 
;} 
_L103:;xxx; 

/* IF-operator */ 
/* operaciq = */ wrk1 .bo= eqnum( loc6 .sa , 99L ) ; 
if( wrk1 .bo) 
{ 
outatm(acnst[15],"/* USER:*/",true, true); 
indxop( 2L,false,NULL, loc3 .sa ,& wrk1 .sa); 
selop( acnst[ 51 ],false,NULL, wrk1 .sa ,& wrk2 .sa); 
outxt(acnst[ 15 ], wrk2 .sa , false, true); 
indxop( 3L,false,NULL, loc3 .sa ,& wrk1 .sa); 
selop( acnst[ 51 ],false,NULL, wrk1 .sa ,& wrk2 .sa); 
outxt(acnst[ 15 ], wrk2 .sa , false, true); 
indxop( 4L,false,NULL, loc3 .sa ,& wrk1 .sa); 
selop( acnst[ 51 ],false,NULL, wrk1 .sa ,& wrk2 .sa); 
outxt(acnst[ 15 ], wrk2 .sa , false, true); ;xxx; 
goto _L104;
;} 
{ 
/* operator := */ 
mknumb( 2L,& wrk1 .sa); 
loc7 .sa= wrk1 .sa ;xxx; 
/*LOOP*/while (true) { 
/* IF-operator */ 
bltin(&wrk1,&flag1,loc3.sa,15L); 
wrk2 .bo= numval( loc7 .sa) <= wrk1 .nu ; 
if( wrk2 .bo) 
{ 
/* operator !.:= */ 
/* CALL #L */ 
indxop( 0L,true, loc7 .sa, loc3 .sa ,& wrk1 .sa); 
pl2.ptrtype=packedlist;pl2.nel=1;pl2.cel=wrk1.sa;
pl2.plistsize= 1;
r37(&wrk2.sa,&flag1,&pl2);/* #obqzatelxno_obxekt*/ ; 
lconc(& loc8 .sa, wrk2 .sa ) ;xxx; 
goto _L105;
;} 
{ 
/* operator !.:= */ 
lconc(& loc8 .sa, cnst[24] .sa ) ;xxx; 
;} 
_L105:;xxx; 
/* IF-operator */ 
/* operaciq = */ wrk1 .bo= eqnum( loc7 .sa , 4L ) ; 
if( wrk1 .bo) 
{ 
/*BREAK*/ goto _L107;xxx; 
;} 
_L106:;xxx; 
/* operator +:= */ 
addnum(& loc7 .sa, 1L ) ;xxx; 
;};  _L107:/*END LOOP*/;xxx; 
outatm(acnst[15],"use_",true, false); 
outxt(acnst[ 15 ], loc6 .sa , false, false); 
outatm(acnst[15],"(",false, false); 
indxop( 1L,false,NULL, loc8 .sa ,& wrk1 .sa); 
outxt(acnst[ 15 ], wrk1 .sa , false, false); 
outatm(acnst[15],",",false, false); 
indxop( 2L,false,NULL, loc8 .sa ,& wrk1 .sa); 
outxt(acnst[ 15 ], wrk1 .sa , false, false); 
outatm(acnst[15],",",false, false); 
indxop( 3L,false,NULL, loc8 .sa ,& wrk1 .sa); 
outxt(acnst[ 15 ], wrk1 .sa , false, false); 
outatm(acnst[15],",&",false, false); 
outxt(acnst[ 15 ], loc2 .sa , false, false); 
outatm(acnst[15],".sa);",false, false); ;xxx; 
;} 
_L104:;xxx; 
goto _L99;  _L108:;  /* metka wyhoda po neuspehu wetwi */
 _L99: rez1=NULL; 
 _L98: *rez=rez1;*success=success1; 
 if (*success) *pl=pl1; /* prodwinutx ukazatelx leksem */ 
/* wosstanowitx GLOB */ 
#ifdef XX  
 d(2,"G_CALL_PAS", 27 ,*rez,*success); 
#endif 
;};/* RULE */ 
/*===============================================*/ 
/* GENERATED TEXT OF RULE   #TAIL   */ 
 Void r28(rez,success,pl)
long *rez;boolean *success;ptr_ *pl; 
{  a rez1;  boolean success1; long k; mpd x; 
v loc1;/* $A*/ 
v loc2;/* $E*/ 
v loc3;/* $B*/ 
ptr_ pl1;
ptr_ pl2;
ptr_ pl3;
#ifdef XX  
 d(1,"TAIL", 28 ,pl->cel,0); 
#endif 
/* sohranitx GLOB */ 

/* branch */ pl1=*pl;rez1=NULL;success1=true; 
/* inicializaciq peremennyh */ 
loc2.sa=NULL;/* $E*/ 

/* shablon listmain */ rez1=pl1.cel;
success1=false;if(pl1.nel==0 ) goto _L102; 
 if (rez1!=NULL ) { pointr(rez1,&x.sa); 
       if (x.smld->dtype!= listmain )  
        { rez1=NULL;goto _L102;};
{pl2.ptrtype=ptrlist; pl2.nel=1;
pl2.cel=x.smld->elt[0];pl2.UU.U1.curfragment=rez1;}
;} else  
{pl2.ptrtype=ptrlist;pl2.nel=0;pl2.cel=NULL;}

/* shablon peremennoj */ 
success1=(pl2.nel!=0);rez1=pl2.cel;
if( (pl2.ptrtype!=ptrtree) && success1 ) next(&pl2);
loc1 .sa=rez1; 
if( !success1 ) goto _L102;

/*shablon STARLIST */ 
 pl3=pl2;while(pl2.nel!=0 ) { 


/* shablon peremennoj */ 
success1=(pl2.nel!=0);rez1=pl2.cel;
if( (pl2.ptrtype!=ptrtree) && success1 ) next(&pl2);
loc3 .sa=rez1; 
if( !success1 ) goto _L101;
lconc(& loc2 .sa,rez1); 
 pl3=pl2;
;}; 
_L101:if( ! success1 )pl2=pl3;
success1 = true ; 

if( pl2.nel !=0 )
{ success1=false;rez1=NULL;goto _L102;};
success1=true;rez1=pl1.cel;
 if( pl1.ptrtype!=ptrtree ) next(&pl1);

/* RETURN-op. */ 
rez1 = loc2 .sa ;goto _L98 ;xxx; 
goto _L99;  _L102:;  /* metka wyhoda po neuspehu wetwi */
 _L99: rez1=NULL; 
 _L98: *rez=rez1;*success=success1; 
 if (*success) *pl=pl1; /* prodwinutx ukazatelx leksem */ 
/* wosstanowitx GLOB */ 
#ifdef XX  
 d(2,"TAIL", 28 ,*rez,*success); 
#endif 
;};/* RULE */ 
