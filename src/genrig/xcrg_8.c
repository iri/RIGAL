
#include "globrig.h" 
#include "define.h"  
#include "defpage.h" 
#include "nef2.h"    
#include "c1.h"      
#include "usemod.h"  
#include "def180.h"  
#include "xcrg.h"    
/*  R63 G_STMT */ 
/*  R64 G_IF */ 
/*  R65 G_PRINT */ 
/*  R66 G_LOAD_SAVE */ 
/*  R67 G_RETURN */ 
/*  R68 G_FAIL */ 
/*===============================================*/ 
/* GENERATED TEXT OF RULE   #G_STMT   */ 
 Void r63(rez,success,pl)
long *rez;boolean *success;ptr_ *pl; 
{  a rez1;  boolean success1; long k; mpd x; 
v loc1;/* $E*/ 
ptr_ pl1;
ptr_ pl2;
ptr_ pl3;
#ifdef XX  
 d(1,"G_STMT", 63 ,pl->cel,0); 
#endif 
/* sohranitx GLOB */ 

/* branch */ pl1=*pl;rez1=NULL;success1=true; 
/* inicializaciq peremennyh */ 

/* Alternative pattern */ 
pl2=pl1;
/* nonatomic alternative branches */ 

/* shablon prawila */ r64(&rez1,&success1,&pl1);
if( !success1 ) goto _L101;
goto _L117/*uspeh*/;
_L101:; 
pl1=pl2;

/* shablon prawila */ r67(&rez1,&success1,&pl1);
if( !success1 ) goto _L102;
goto _L117/*uspeh*/;
_L102:; 
pl1=pl2;

/* shablon prawila */ r65(&rez1,&success1,&pl1);
if( !success1 ) goto _L103;
goto _L117/*uspeh*/;
_L103:; 
pl1=pl2;

/* shablon prawila */ r19(&rez1,&success1,&pl1);
if( !success1 ) goto _L104;
goto _L117/*uspeh*/;
_L104:; 
pl1=pl2;

/* shablon prawila */ r68(&rez1,&success1,&pl1);
if( !success1 ) goto _L105;
goto _L117/*uspeh*/;
_L105:; 
pl1=pl2;

/* shablon prawila */ r66(&rez1,&success1,&pl1);
if( !success1 ) goto _L106;
goto _L117/*uspeh*/;
_L106:; 
pl1=pl2;

/* shablon prawila */ r21(&rez1,&success1,&pl1);
if( !success1 ) goto _L107;
goto _L117/*uspeh*/;
_L107:; 
pl1=pl2;

/* shablon prawila */ r23(&rez1,&success1,&pl1);
if( !success1 ) goto _L108;
goto _L117/*uspeh*/;
_L108:; 
pl1=pl2;

/* shablon prawila */ r25(&rez1,&success1,&pl1);
if( !success1 ) goto _L109;
goto _L117/*uspeh*/;
_L109:; 
pl1=pl2;

/* shablon prawila */ r20(&rez1,&success1,&pl1);
if( !success1 ) goto _L110;
goto _L117/*uspeh*/;
_L110:; 
pl1=pl2;

/* shablon prawila */ r22(&rez1,&success1,&pl1);
if( !success1 ) goto _L111;
goto _L117/*uspeh*/;
_L111:; 
pl1=pl2;

/* shablon prawila */ r26(&rez1,&success1,&pl1);
if( !success1 ) goto _L112;
goto _L117/*uspeh*/;
_L112:; 
pl1=pl2;

/* shablon prawila */ r33(&rez1,&success1,&pl1);
if( !success1 ) goto _L113;
goto _L117/*uspeh*/;
_L113:; 
pl1=pl2;

/* Alternative pattern */ 
pl3=pl1;

/* shablon peremennoj */ 
success1=(pl1.nel!=0);rez1=pl1.cel;
if( (pl1.ptrtype!=ptrtree) && success1 ) next(&pl1);
loc1 .sa=rez1; 
if( !success1 ) goto _L114;

outatm(acnst[15],"/* operator ne realizowan!!!! */",true, true); ;xxx; 
goto _L115/*uspeh*/;
_L114:; 
pl1=pl3;
goto  _L116;
_L115:;/*uspeh alxtern.*/
goto _L117/*uspeh*/;
_L116:; 
pl1=pl2;
goto  _L118;
_L117:;/*uspeh alxtern.*/

outatm(acnst[15],";xxx;",false, true); ;xxx; 
goto _L99;  _L118:;  /* metka wyhoda po neuspehu wetwi */
 _L99: rez1=NULL; 
 _L98: *rez=rez1;*success=success1; 
 if (*success) *pl=pl1; /* prodwinutx ukazatelx leksem */ 
/* wosstanowitx GLOB */ 
#ifdef XX  
 d(2,"G_STMT", 63 ,*rez,*success); 
#endif 
;};/* RULE */ 
/*===============================================*/ 
/* GENERATED TEXT OF RULE   #G_IF   */ 
 Void r64(rez,success,pl)
long *rez;boolean *success;ptr_ *pl; 
{  a rez1;  boolean success1; long k; mpd x; 
v loc0;/* $_*/ 
v loc1;/* $LABEL*/ 
v loc2;/* $BNUM*/ 
v loc3;/* $I*/ 
v loc4;/* $E*/ 
v wrk1;
v wrk2;
v wrk3;
v wrk4;
v wrk5;
ptr_ pl1;
ptr_ pl2;
ptr_ pl3;
ptr_ pl4;
ptr_ pl5;
ptr_ pl6;
ptr_ pl7;
boolean flag1;
#ifdef XX  
 d(1,"G_IF", 64 ,pl->cel,0); 
#endif 
/* sohranitx GLOB */ 
loc0.sa=pl->cel; 

/* branch */ pl1=*pl;rez1=NULL;success1=true; 
/* inicializaciq peremennyh */ 
loc1.sa=NULL;/* $LABEL*/ 
loc2.sa=NULL;/* $BNUM*/ 
loc3.sa=NULL;/* $I*/ 
loc4.sa=NULL;/* $E*/ 

/* shablon treemain */ rez1=pl1.cel;
success1=false;if(pl1.nel==0 ) goto _L105; 
 if (rez1!=NULL ) { pointr(rez1,&x.sa); 
       if (x.smld->dtype!= treemain )  
        { rez1=NULL;goto _L105;};
/* prowerka imeni */ 
success1=eqatom(x.smld->name,acnst[ 105 ]); 
if( ! success1 ) { rez1=NULL;goto _L105;};
;}; 
pl2.nel=1;pl2.ptrtype=ptrtree;
success1=true; 
selop(acnst[38],false,0L,pl1.cel,&rez1);pl2.cel=rez1;
   if( rez1==NULL ) { success1=false;goto _L105;};

/* shablon peremennoj */ 
success1=(pl2.nel!=0);rez1=pl2.cel;
if( (pl2.ptrtype!=ptrtree) && success1 ) next(&pl2);
loc1 .sa=rez1; 
if( !success1 ) goto _L105;

/* operator := */ 
selop( acnst[ 106 ],false,NULL, loc0 .sa ,& wrk1 .sa); 
bltin(&wrk2,&flag1,wrk1.sa,15L); 
mknumb( wrk2 .nu ,& wrk3 .sa); 
loc2 .sa= wrk3 .sa ;xxx; 
selop(acnst[106],false,0L,pl1.cel,&rez1);pl2.cel=rez1;
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

outatm(acnst[15],"/* IF-operator */",true, true); ;xxx; 

/*shablon STARLIST */ 
 pl4=pl3;while(pl3.nel!=0 ) { 

/* operator +:= */ 
addnum(& loc3 .sa, 1L ) ;xxx; 

/* shablon treemain */ rez1=pl3.cel;
success1=false;if(pl3.nel==0 ) goto _L104; 
 if (rez1!=NULL ) { pointr(rez1,&x.sa); 
       if (x.smld->dtype!= treemain )  
        { rez1=NULL;goto _L104;};
;}; 
pl5.nel=1;pl5.ptrtype=ptrtree;
success1=true; 
selop(acnst[107],false,0L,pl3.cel,&rez1);pl5.cel=rez1;
   if( rez1==NULL ) { success1=false;goto _L104;};

/* shablon peremennoj */ 
success1=(pl5.nel!=0);rez1=pl5.cel;
if( (pl5.ptrtype!=ptrtree) && success1 ) next(&pl5);
loc4 .sa=rez1; 
if( !success1 ) goto _L104;

/* CALL #L */ 
pl6.ptrtype=packedlist;pl6.nel=1;pl6.cel=loc4.sa;
pl6.plistsize= 1;
r41(&wrk1.sa,&flag1,&pl6);/* #G_wyravenie*/ ;xxx; 

/* IF-operator */ 
selop( acnst[ 17 ],false,NULL, loc4 .sa ,& wrk1 .sa); 
/* operaciq = */ wrk2 .bo= eqatom( wrk1 .sa ,acnst[ 18 ]) ; 
if( wrk2 .bo) 
{ 
outatm(acnst[15],"if(",true, true); 
selop( acnst[ 19 ],false,NULL, loc4 .sa ,& wrk1 .sa); 
outxt(acnst[ 15 ], wrk1 .sa , false, true); 
outatm(acnst[15],".bo)",false, true); ;xxx; 
goto _L101;
;} 
selop( acnst[ 19 ],false,NULL, loc4 .sa ,& wrk1 .sa); 
/* operaciq = */ wrk2 .bo= eqatom( wrk1 .sa ,acnst[ 24 ]) ; 
if( wrk2 .bo) 
{ 
outatm(acnst[15]," if(false)",true, true); ;xxx; 
goto _L101;
;} 
selop( acnst[ 17 ],false,NULL, loc4 .sa ,& wrk1 .sa); 
/* operaciq = */ wrk2 .bo= wrk1 .sa ==NULL ; 
if( !( wrk2 .bo )) wrk5 .bo=false; else { 
selop( acnst[ 51 ],false,NULL, loc4 .sa ,& wrk3 .sa); 
/* operaciq = */ wrk4 .bo= wrk3 .sa ==NULL ; wrk5 = wrk4 ;}/*log*/; 
if( wrk5 .bo) 
{ 
outatm(acnst[15],"if(",true, true); 
selop( acnst[ 19 ],false,NULL, loc4 .sa ,& wrk1 .sa); 
outxt(acnst[ 15 ], wrk1 .sa , false, true); 
outatm(acnst[15],".sa!=NULL)",false, true); ;xxx; 
;} 
_L101:;xxx; 
selop(acnst[39],false,0L,pl3.cel,&rez1);pl5.cel=rez1;
   if( rez1==NULL ) { success1=false;goto _L104;};

/* shablon listmain */ rez1=pl5.cel;
success1=false;if(pl5.nel==0 ) goto _L104; 
 if (rez1!=NULL ) { pointr(rez1,&x.sa); 
       if (x.smld->dtype!= listmain )  
        { rez1=NULL;goto _L104;};
{pl6.ptrtype=ptrlist; pl6.nel=1;
pl6.cel=x.smld->elt[0];pl6.UU.U1.curfragment=rez1;}
;} else  
{pl6.ptrtype=ptrlist;pl6.nel=0;pl6.cel=NULL;}

outatm(acnst[15],"{",true, true); ;xxx; 

/*shablon STARLIST */ 
 pl7=pl6;while(pl6.nel!=0 ) { 

/* shablon prawila */ r63(&rez1,&success1,&pl6);
if( !success1 ) goto _L102;
 pl7=pl6;
;}; 
_L102:if( ! success1 )pl6=pl7;
success1 = true ; 

if( pl6.nel !=0 )
{ success1=false;rez1=NULL;goto _L104;};
success1=true;rez1=pl5.cel;
 if( pl5.ptrtype!=ptrtree ) next(&pl5);

/* IF-operator */ 
wrk1 .bo=compare( 1L , loc3 .sa , loc2 .sa ); 
if( wrk1 .bo) 
{ 
outatm(acnst[15],"goto",true, false); 
outatm(acnst[15]," _L",false, false); 
outxt(acnst[ 15 ], loc1 .sa , false, false); 
outatm(acnst[15],";",false, false); ;xxx; 
;} 
_L103:;xxx; 

outatm(acnst[15],";}",true, true); ;xxx; 
if( success1 ) {
 rez1=pl3.cel;if( pl3.ptrtype!=ptrtree ) next(&pl3) ;}
 else { rez1=NULL;goto _L104 ;};
 pl4=pl3;
;}; 
_L104:if( ! success1 )pl3=pl4;
success1 = true ; 

if( pl3.nel !=0 )
{ success1=false;rez1=NULL;goto _L105;};
success1=true;rez1=pl2.cel;
 if( pl2.ptrtype!=ptrtree ) next(&pl2);
if( success1 ) {
 rez1=pl1.cel;if( pl1.ptrtype!=ptrtree ) next(&pl1) ;}
 else { rez1=NULL;goto _L105 ;};

outatm(acnst[15],"_L",true, false); 
outxt(acnst[ 15 ], loc1 .sa , false, false); 
outatm(acnst[15],":",false, false); ;xxx; 
goto _L99;  _L105:;  /* metka wyhoda po neuspehu wetwi */
 _L99: rez1=NULL; 
 _L98: *rez=rez1;*success=success1; 
 if (*success) *pl=pl1; /* prodwinutx ukazatelx leksem */ 
/* wosstanowitx GLOB */ 
#ifdef XX  
 d(2,"G_IF", 64 ,*rez,*success); 
#endif 
;};/* RULE */ 
/*===============================================*/ 
/* GENERATED TEXT OF RULE   #G_PRINT   */ 
 Void r65(rez,success,pl)
long *rez;boolean *success;ptr_ *pl; 
{  a rez1;  boolean success1; long k; mpd x; 
v loc1;/* $A*/ 
v loc2;/* $M*/ 
v wrk1;
ptr_ pl1;
ptr_ pl2;
ptr_ pl3;
ptr_ pl4;
ptr_ pl5;
boolean flag1;
#ifdef XX  
 d(1,"G_PRINT", 65 ,pl->cel,0); 
#endif 
/* sohranitx GLOB */ 

/* branch */ pl1=*pl;rez1=NULL;success1=true; 
/* inicializaciq peremennyh */ 
loc1.sa=NULL;/* $A*/ 
loc2.sa=NULL;/* $M*/ 

/* shablon listmain */ rez1=pl1.cel;
success1=false;if(pl1.nel==0 ) goto _L108; 
 if (rez1!=NULL ) { pointr(rez1,&x.sa); 
       if (x.smld->dtype!= listmain )  
        { rez1=NULL;goto _L108;};
/* prowerka imeni */ 
success1=eqatom(x.smld->name,acnst[ 108 ]); 
if( ! success1 ) { rez1=NULL;goto _L108;};
{pl2.ptrtype=ptrlist; pl2.nel=1;
pl2.cel=x.smld->elt[0];pl2.UU.U1.curfragment=rez1;}
;} else  
{pl2.ptrtype=ptrlist;pl2.nel=0;pl2.cel=NULL;}

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
success1=eqatom(x.smld->name,acnst[ 78 ]); 
if( ! success1 ) { rez1=NULL;goto _L101;};
;}; 
pl5.nel=1;pl5.ptrtype=ptrtree;
success1=true; 
selop(acnst[51],false,0L,pl2.cel,&rez1);pl5.cel=rez1;
   if( rez1==NULL ) { success1=false;goto _L101;};

loc1 .sa=NULL; 

bltin1(&rez1,&success1,&pl5,4L);
if( !success1 ) goto _L101;
loc1 .sa=rez1; 
if( success1 ) {
 rez1=pl2.cel;if( pl2.ptrtype!=ptrtree ) next(&pl2) ;}
 else { rez1=NULL;goto _L101 ;};

outatm(acnst[15],"if (out_screen)  printf(\"%12ld\\n\",",true, false); 
outxt(acnst[ 15 ], loc1 .sa , false, false); 
outatm(acnst[15],");",false, false); ;xxx; 

outatm(acnst[15],"else fprintf(out,\"%12ld\\n\",",true, false); 
outxt(acnst[ 15 ], loc1 .sa , false, false); 
outatm(acnst[15],")",false, false); ;xxx; 
goto _L102/*uspeh*/;
_L101:; 
pl2=pl4;
goto  _L103;
_L102:;/*uspeh alxtern.*/
goto _L107/*uspeh*/;
_L103:; 
pl2=pl3;

/* Alternative pattern */ 
pl4=pl2;

/* shablon peremennoj */ 
success1=(pl2.nel!=0);rez1=pl2.cel;
if( (pl2.ptrtype!=ptrtree) && success1 ) next(&pl2);
loc2 .sa=rez1; 
if( !success1 ) goto _L104;

/* CALL #L */ 
pl5.ptrtype=packedlist;pl5.nel=1;pl5.cel=loc2.sa;
pl5.plistsize= 1;
r41(&wrk1.sa,&flag1,&pl5);/* #G_wyravenie*/ ;xxx; 

outatm(acnst[15],"if (out_screen) {pscr(",true, true); 
selop( acnst[ 19 ],false,NULL, loc2 .sa ,& wrk1 .sa); 
outxt(acnst[ 15 ], wrk1 .sa , false, true); 
outatm(acnst[15],".sa);putchar('\\n');}",false, true); 
outatm(acnst[15],"else { pout(",false, true); 
selop( acnst[ 19 ],false,NULL, loc2 .sa ,& wrk1 .sa); 
outxt(acnst[ 15 ], wrk1 .sa , false, true); 
outatm(acnst[15],".sa);putc('\\n',out);} ",false, true); ;xxx; 
goto _L105/*uspeh*/;
_L104:; 
pl2=pl4;
goto  _L106;
_L105:;/*uspeh alxtern.*/
goto _L107/*uspeh*/;
_L106:; 
pl2=pl3;
goto  _L108;
_L107:;/*uspeh alxtern.*/

if( pl2.nel !=0 )
{ success1=false;rez1=NULL;goto _L108;};
success1=true;rez1=pl1.cel;
 if( pl1.ptrtype!=ptrtree ) next(&pl1);
goto _L99;  _L108:;  /* metka wyhoda po neuspehu wetwi */
 _L99: rez1=NULL; 
 _L98: *rez=rez1;*success=success1; 
 if (*success) *pl=pl1; /* prodwinutx ukazatelx leksem */ 
/* wosstanowitx GLOB */ 
#ifdef XX  
 d(2,"G_PRINT", 65 ,*rez,*success); 
#endif 
;};/* RULE */ 
/*===============================================*/ 
/* GENERATED TEXT OF RULE   #G_LOAD_SAVE   */ 
 Void r66(rez,success,pl)
long *rez;boolean *success;ptr_ *pl; 
{  a rez1;  boolean success1; long k; mpd x; 
v loc0;/* $_*/ 
v loc1;/* $OP*/ 
v loc2;/* $V*/ 
v loc3;/* $E*/ 
v wrk1;
v wrk2;
v wrk3;
ptr_ pl1;
ptr_ pl2;
boolean flag1;
#ifdef XX  
 d(1,"G_LOAD_SAVE", 66 ,pl->cel,0); 
#endif 
/* sohranitx GLOB */ 
loc0.sa=pl->cel; 

/* branch */ pl1=*pl;rez1=NULL;success1=true; 
/* inicializaciq peremennyh */ 
loc1.sa=NULL;/* $OP*/ 
loc2.sa=NULL;/* $V*/ 
loc3.sa=NULL;/* $E*/ 

/* shablon treemain */ rez1=pl1.cel;
success1=false;if(pl1.nel==0 ) goto _L103; 
 if (rez1!=NULL ) { pointr(rez1,&x.sa); 
       if (x.smld->dtype!= treemain )  
        { rez1=NULL;goto _L103;};
/* prowerka imeni */ 
loc1 .sa=x.smld->name; 
;}; 
pl2.nel=1;pl2.ptrtype=ptrtree;
success1=true; 
selop(acnst[41],false,0L,pl1.cel,&rez1);pl2.cel=rez1;
   if( rez1==NULL ) { success1=false;goto _L103;};

/* shablon peremennoj */ 
success1=(pl2.nel!=0);rez1=pl2.cel;
if( (pl2.ptrtype!=ptrtree) && success1 ) next(&pl2);
loc2 .sa=rez1; 
if( !success1 ) goto _L103;
selop(acnst[31],false,0L,pl1.cel,&rez1);pl2.cel=rez1;
   if( rez1==NULL ) { success1=false;goto _L103;};

/* shablon peremennoj */ 
success1=(pl2.nel!=0);rez1=pl2.cel;
if( (pl2.ptrtype!=ptrtree) && success1 ) next(&pl2);
loc3 .sa=rez1; 
if( !success1 ) goto _L103;
if( success1 ) {
 rez1=pl1.cel;if( pl1.ptrtype!=ptrtree ) next(&pl1) ;}
 else { rez1=NULL;goto _L103 ;};

outatm(acnst[15],"/* operator",true, true); 
outxt(acnst[ 15 ], loc1 .sa , false, true); 
outatm(acnst[15],"*/",false, true); ;xxx; 

/* CALL #L */ 
pl2.ptrtype=packedlist;pl2.nel=1;pl2.cel=loc3.sa;
pl2.plistsize= 1;
r41(&wrk1.sa,&flag1,&pl2);/* #G_wyravenie*/ ;xxx; 

/* CALL #L */ 
pl2.ptrtype=packedlist;pl2.nel=1;pl2.cel=loc2.sa;
pl2.plistsize= 1;
r41(&wrk1.sa,&flag1,&pl2);/* #G_wyravenie*/ ;xxx; 

/* IF-operator */ 
selop( acnst[ 17 ],false,NULL, loc3 .sa ,& wrk1 .sa); 
if( wrk1 .sa!=NULL) 
{ 
outatm(acnst[15],"/*",true, true); 
outatm(acnst[15],"newernaq",false, true); 
outatm(acnst[15],"specifikaciq",false, true); 
outatm(acnst[15],"fajla",false, true); 
outatm(acnst[15],"w",false, true); 
outxt(acnst[ 15 ], loc1 .sa , false, true); 
outatm(acnst[15],"!!!!!*/",false, true); ;xxx; 
;} 
_L101:;xxx; 

outatm(acnst[15],"loasav(&",true, true); 
selop( acnst[ 19 ],false,NULL, loc2 .sa ,& wrk1 .sa); 
outxt(acnst[ 15 ], wrk1 .sa , false, true); 
outatm(acnst[15],",",false, true); 
selop( acnst[ 19 ],false,NULL, loc3 .sa ,& wrk1 .sa); 
outxt(acnst[ 15 ], wrk1 .sa , false, true); 
outatm(acnst[15],".sa,",false, true); ;xxx; 

/* IF-operator */ 
/* operaciq = */ wrk1 .bo= eqatom( loc1 .sa ,acnst[ 109 ]) ; 
if( wrk1 .bo) 
{ 
outatm(acnst[15],"0L",false, true); ;xxx; 
goto _L102;
;} 
wrk1 .nu=- 1L ; 
indxop( wrk1 .nu,false,NULL, glob30_1 .sa ,& wrk2 .sa); 
/* operaciq = */ wrk3 .bo= eqop(0L, wrk2 .sa , loc0 .sa ) ; 
if( wrk3 .bo) 
{ 
outatm(acnst[15],"2L",false, true); ;xxx; 
goto _L102;
;} 
{ 
outatm(acnst[15],"1L",false, true); ;xxx; 
;} 
_L102:;xxx; 

outatm(acnst[15],")",true, true); ;xxx; 
goto _L99;  _L103:;  /* metka wyhoda po neuspehu wetwi */
 _L99: rez1=NULL; 
 _L98: *rez=rez1;*success=success1; 
 if (*success) *pl=pl1; /* prodwinutx ukazatelx leksem */ 
/* wosstanowitx GLOB */ 
#ifdef XX  
 d(2,"G_LOAD_SAVE", 66 ,*rez,*success); 
#endif 
;};/* RULE */ 
/*===============================================*/ 
/* GENERATED TEXT OF RULE   #G_RETURN   */ 
 Void r67(rez,success,pl)
long *rez;boolean *success;ptr_ *pl; 
{  a rez1;  boolean success1; long k; mpd x; 
v loc1;/* $E*/ 
v wrk1;
v wrk2;
ptr_ pl1;
ptr_ pl2;
ptr_ pl3;
boolean flag1;
#ifdef XX  
 d(1,"G_RETURN", 67 ,pl->cel,0); 
#endif 
/* sohranitx GLOB */ 

/* branch */ pl1=*pl;rez1=NULL;success1=true; 
/* inicializaciq peremennyh */ 
loc1.sa=NULL;/* $E*/ 

/* shablon listmain */ rez1=pl1.cel;
success1=false;if(pl1.nel==0 ) goto _L104; 
 if (rez1!=NULL ) { pointr(rez1,&x.sa); 
       if (x.smld->dtype!= listmain )  
        { rez1=NULL;goto _L104;};
/* prowerka imeni */ 
success1=eqatom(x.smld->name,acnst[ 110 ]); 
if( ! success1 ) { rez1=NULL;goto _L104;};
{pl2.ptrtype=ptrlist; pl2.nel=1;
pl2.cel=x.smld->elt[0];pl2.UU.U1.curfragment=rez1;}
;} else  
{pl2.ptrtype=ptrlist;pl2.nel=0;pl2.cel=NULL;}

outatm(acnst[15],"/* RETURN-op. */",true, true); ;xxx; 

/* shablon peremennoj */ 
success1=(pl2.nel!=0);rez1=pl2.cel;
if( (pl2.ptrtype!=ptrtree) && success1 ) next(&pl2);
loc1 .sa=rez1; 
if( !success1 ) goto _L104;

/* CALL #L */ 
pl3.ptrtype=packedlist;pl3.nel=1;pl3.cel=loc1.sa;
pl3.plistsize= 1;
r41(&wrk1.sa,&flag1,&pl3);/* #G_wyravenie*/ ;xxx; 

if( pl2.nel !=0 )
{ success1=false;rez1=NULL;goto _L104;};
success1=true;rez1=pl1.cel;
 if( pl1.ptrtype!=ptrtree ) next(&pl1);

/* IF-operator */ 
selop( acnst[ 17 ],false,NULL, loc1 .sa ,& wrk1 .sa); 
if( wrk1 .sa!=NULL) 
{ 
/* CALL #L */ 
pl2.ptrtype=packedlist;pl2.nel=1;pl2.cel=loc1.sa;
pl2.plistsize= 1;
r11(&wrk1.sa,&flag1,&pl2);/* #G_ATOM_FROM_REZ*/ ;xxx; 
;} 
_L101:;xxx; 

outatm(acnst[15],"rez1",true, true); 
outatm(acnst[15],"=",false, true); ;xxx; 

/* IF-operator */ 
selop( acnst[ 20 ],false,NULL, loc1 .sa ,& wrk1 .sa); 
if( wrk1 .sa!=NULL) 
{ 
selop( acnst[ 20 ],false,NULL, loc1 .sa ,& wrk1 .sa); 
outxt(acnst[ 15 ], wrk1 .sa , false, true); 
outatm(acnst[15],".sa",false, true); ;xxx; 
goto _L102;
;} 
selop( acnst[ 19 ],false,NULL, loc1 .sa ,& wrk1 .sa); 
/* operaciq = */ wrk2 .bo= eqatom( wrk1 .sa ,acnst[ 24 ]) ; 
if( wrk2 .bo) 
{ 
outatm(acnst[15],"NULL",false, true); ;xxx; 
goto _L102;
;} 
{ 
selop( acnst[ 19 ],false,NULL, loc1 .sa ,& wrk1 .sa); 
outxt(acnst[ 15 ], wrk1 .sa , false, true); 
outatm(acnst[15],".sa",false, true); ;xxx; 
;} 
_L102:;xxx; 

/* IF-operator */ 
wrk1 .bo= numval( glob10_3 .sa) > 0L ; 
if( wrk1 .bo) 
{ 
outatm(acnst[15],";if (pl1.ptrtype!=ptrtree) next(&pl1)",true, true); 
outatm(acnst[15],"/*wyhod iz der.ili sp.*/",false, true); ;xxx; 
;} 
_L103:;xxx; 

outatm(acnst[15],";goto _L98",false, true); ;xxx; 
goto _L99;  _L104:;  /* metka wyhoda po neuspehu wetwi */
 _L99: rez1=NULL; 
 _L98: *rez=rez1;*success=success1; 
 if (*success) *pl=pl1; /* prodwinutx ukazatelx leksem */ 
/* wosstanowitx GLOB */ 
#ifdef XX  
 d(2,"G_RETURN", 67 ,*rez,*success); 
#endif 
;};/* RULE */ 
/*===============================================*/ 
/* GENERATED TEXT OF RULE   #G_FAIL   */ 
 Void r68(rez,success,pl)
long *rez;boolean *success;ptr_ *pl; 
{  a rez1;  boolean success1; long k; mpd x; 
v loc1;/* $X*/ 
ptr_ pl1;
ptr_ pl2;
#ifdef XX  
 d(1,"G_FAIL", 68 ,pl->cel,0); 
#endif 
/* sohranitx GLOB */ 

/* branch */ pl1=*pl;rez1=NULL;success1=true; 
/* inicializaciq peremennyh */ 
loc1.sa=NULL;/* $X*/ 

/* shablon listmain */ rez1=pl1.cel;
success1=false;if(pl1.nel==0 ) goto _L103; 
 if (rez1!=NULL ) { pointr(rez1,&x.sa); 
       if (x.smld->dtype!= listmain )  
        { rez1=NULL;goto _L103;};
/* prowerka imeni */ 
success1=eqatom(x.smld->name,acnst[ 111 ]); 
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

outatm(acnst[15],"/* FAIL */ rez1=NULL;success1=false;",true, true); ;xxx; 

/* IF-operator */ 
if( glob10_3 .sa!=NULL) 
{ 
outatm(acnst[15],"if (pl1.ptrtype!=ptrtree) next(&pl1);",true, true); 
outatm(acnst[15],"/*wyhod iz der.ili sp.*/",false, true); ;xxx; 
;} 
_L101:;xxx; 

/* operator := */ 
loc1 .sa= glob10_4 .sa ;xxx; 

/* IF-operator */ 
if( loc1 .sa!=NULL) 
{ 
outatm(acnst[15],"goto",true, false); 
outatm(acnst[15]," _L",false, false); 
outxt(acnst[ 15 ], loc1 .sa , false, false); ;xxx; 
goto _L102;
;} 
{ 
outatm(acnst[15],"goto _L99;",true, true); ;xxx; 
;} 
_L102:;xxx; 
goto _L99;  _L103:;  /* metka wyhoda po neuspehu wetwi */
 _L99: rez1=NULL; 
 _L98: *rez=rez1;*success=success1; 
 if (*success) *pl=pl1; /* prodwinutx ukazatelx leksem */ 
/* wosstanowitx GLOB */ 
#ifdef XX  
 d(2,"G_FAIL", 68 ,*rez,*success); 
#endif 
;};/* RULE */ 
