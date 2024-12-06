
#include "globrig.h" 
#include "define.h"  
#include "defpage.h" 
#include "nef2.h"    
#include "c1.h"      
#include "usemod.h"  
#include "def180.h"  
#include "xcrg.h"    
/*  R33 EXPR1 */ 
/*  R34 atom_selektor */ 
/*  R35 sozdatx_mesto2 */ 
/*  R36 ne~islowoj_atom */ 
/*  R37 ADD_USEVAR */ 
/*===============================================*/ 
/* GENERATED TEXT OF RULE   #EXPR1   */ 
 Void r33(rez,success,pl)
long *rez;boolean *success;ptr_ *pl; 
{  a rez1;  boolean success1; long k; mpd x; 
v loc1;/* $E1*/ 
v loc2;/* $E*/ 
v loc3;/* $ID*/ 
v loc4;/* $R*/ 
v loc5;/* $BLTIN*/ 
v loc6;/* $tip*/ 
v loc7;/* $FLAG*/ 
v loc8;/* $CALL*/ 
v loc9;/* $N*/ 
v loc10;/* $mesto*/ 
v wrk1;
v wrk2;
v wrk3;
v wrk4;
ptr_ pl1;
ptr_ pl2;
ptr_ pl3;
ptr_ pl4;
boolean flag1;
boolean flag2;
#ifdef XX  
 d(1,"EXPR1", 33 ,pl->cel,0); 
#endif 
/* sohranitx GLOB */ 

/* branch */ pl1=*pl;rez1=NULL;success1=true; 
/* inicializaciq peremennyh */ 
loc1.sa=NULL;/* $E1*/ 
loc2.sa=NULL;/* $E*/ 

/* shablon VPAT */ 
wrk1.sa=pl1.cel;
/* operaciq = */ wrk2 .bo= eqatom( wrk1 .sa ,acnst[ 50 ]) ; 
success1= wrk2 .bo ;if( success1 ) { 
rez1=pl1.cel;
   ;} else { rez1=NULL;goto _L102 ;};

bltin1(&rez1,&success1,&pl1,10L);
if( !success1 ) goto _L102;

/*shablon STARLIST */ 
 pl2=pl1;while(pl1.nel!=0 ) { 

loc1 .sa=NULL; 

/* shablon prawila */ r15(&rez1,&success1,&pl1);
if( !success1 ) goto _L101;
loc1 .sa=rez1; 

/* CALL #L */ 
pl3.ptrtype=packedlist;pl3.nel=1;pl3.cel=loc1.sa;
pl3.plistsize= 1;
r35(&wrk1.sa,&flag1,&pl3);/* #sozdatx_mesto2*/ ;xxx; 

/* operator !.:= */ 
lconc(& loc2 .sa, loc1 .sa ) ;xxx; 
 pl2=pl1;
;}; 
_L101:if( ! success1 )pl1=pl2;
success1 = true ; 

/* shablon VPAT */ 
wrk1.sa=pl1.cel;
/* operaciq = */ wrk2 .bo= eqatom( wrk1 .sa ,acnst[ 51 ]) ; 
success1= wrk2 .bo ;if( success1 ) { 
rez1=pl1.cel;
   ;} else { rez1=NULL;goto _L102 ;};

bltin1(&rez1,&success1,&pl1,10L);
if( !success1 ) goto _L102;

/* RETURN-op. */ 
wrk3 .sa =NULL; 
addel( acnst[ 21 ],false,NULL, loc2 .sa ,& wrk3 .sa ); 
wrk2 .sa=NULL; 
lconc(& wrk2 .sa , cnst[44] .sa ); 
/* CALL #L */ 
pl3.ptrtype=ptrlist;pl3.nel=0;pl3.cel=NULL;
r40(&wrk1.sa,&flag2,&pl3);/* #GETWRK*/ ; 
lconc(& wrk2 .sa , wrk1 .sa ); 
first(wrk2.sa,&pl2);implod(&pl2,&wrk2.sa); 
addel( acnst[ 47 ],false,NULL, wrk2 .sa ,& wrk3 .sa ); 
/* operaciq :: */ wrk4 .sa=NULL; 
if( wrk3 .sa!=NULL ) { points( wrk3 .sa,&x.sa); 
x.smtd->name= cnst[60] .sa ; wrk4 = wrk3 ;}; 
rez1 = wrk4 .sa ;goto _L98 ;xxx; 
goto _L99;  _L102:;  /* metka wyhoda po neuspehu wetwi */

/* branch */ pl1=*pl;rez1=NULL;success1=true; 
/* inicializaciq peremennyh */ 
loc2.sa=NULL;/* $E*/ 
loc3.sa=NULL;/* $ID*/ 
loc4.sa=NULL;/* $R*/ 

/* shablon VPAT */ 
wrk1.sa=pl1.cel;
/* operaciq = */ wrk2 .bo= eqatom( wrk1 .sa ,acnst[ 52 ]) ; 
success1= wrk2 .bo ;if( success1 ) { 
rez1=pl1.cel;
   ;} else { rez1=NULL;goto _L108 ;};

bltin1(&rez1,&success1,&pl1,10L);
if( !success1 ) goto _L108;

/*shablon STARLIST */ 
 pl2=pl1;while(pl1.nel!=0 ) { 

loc3 .sa=NULL; 

/* Alternative pattern */ 
pl3=pl1;
/* nonatomic alternative branches */ 

/* shablon prawila */ r34(&rez1,&success1,&pl1);
if( !success1 ) goto _L103;
goto _L105/*uspeh*/;
_L103:; 
pl1=pl3;

/* shablon prawila */ r15(&rez1,&success1,&pl1);
if( !success1 ) goto _L104;
goto _L105/*uspeh*/;
_L104:; 
pl1=pl3;
goto  _L107;
_L105:;/*uspeh alxtern.*/
loc3 .sa=rez1; 

/* CALL #L */ 
pl4.ptrtype=packedlist;pl4.nel=1;pl4.cel=loc3.sa;
pl4.plistsize= 1;
r35(&wrk1.sa,&flag1,&pl4);/* #sozdatx_mesto2*/ ;xxx; 

/* shablon VPAT */ 
wrk1.sa=pl1.cel;
/* operaciq = */ wrk2 .bo= eqatom( wrk1 .sa ,acnst[ 55 ]) ; 
success1= wrk2 .bo ;if( success1 ) { 
rez1=pl1.cel;
   ;} else { rez1=NULL;goto _L107 ;};

bltin1(&rez1,&success1,&pl1,10L);
if( !success1 ) goto _L107;

loc2 .sa=NULL; 

/* shablon prawila */ r15(&rez1,&success1,&pl1);
if( !success1 ) goto _L107;
loc2 .sa=rez1; 

/* CALL #L */ 
pl4.ptrtype=packedlist;pl4.nel=1;pl4.cel=loc2.sa;
pl4.plistsize= 1;
r35(&wrk1.sa,&flag1,&pl4);/* #sozdatx_mesto2*/ ;xxx; 

/* operator !.:= */ 
lconc(& loc4 .sa, loc3 .sa ) ;xxx; 

/* operator !.:= */ 
lconc(& loc4 .sa, loc2 .sa ) ;xxx; 
 pl2=pl1;

/* shablon prawila */ r13(&rez1,&success1,&pl1);
if( !success1 ) goto _L106;
;}; 
_L107:if( ! success1 )pl1=pl2;
_L106:;
success1 = true ; 

/* shablon VPAT */ 
wrk1.sa=pl1.cel;
/* operaciq = */ wrk2 .bo= eqatom( wrk1 .sa ,acnst[ 53 ]) ; 
success1= wrk2 .bo ;if( success1 ) { 
rez1=pl1.cel;
   ;} else { rez1=NULL;goto _L108 ;};

bltin1(&rez1,&success1,&pl1,10L);
if( !success1 ) goto _L108;

/* RETURN-op. */ 
wrk3 .sa =NULL; 
addel( acnst[ 21 ],false,NULL, loc4 .sa ,& wrk3 .sa ); 
wrk2 .sa=NULL; 
lconc(& wrk2 .sa , cnst[44] .sa ); 
/* CALL #L */ 
pl4.ptrtype=ptrlist;pl4.nel=0;pl4.cel=NULL;
r40(&wrk1.sa,&flag2,&pl4);/* #GETWRK*/ ; 
lconc(& wrk2 .sa , wrk1 .sa ); 
first(wrk2.sa,&pl3);implod(&pl3,&wrk2.sa); 
addel( acnst[ 47 ],false,NULL, wrk2 .sa ,& wrk3 .sa ); 
/* operaciq :: */ wrk4 .sa=NULL; 
if( wrk3 .sa!=NULL ) { points( wrk3 .sa,&x.sa); 
x.smtd->name= cnst[61] .sa ; wrk4 = wrk3 ;}; 
rez1 = wrk4 .sa ;goto _L98 ;xxx; 
goto _L99;  _L108:;  /* metka wyhoda po neuspehu wetwi */

/* branch */ pl1=*pl;rez1=NULL;success1=true; 
/* inicializaciq peremennyh */ 
loc2.sa=NULL;/* $E*/ 
loc3.sa=NULL;/* $ID*/ 

/* shablon VPAT */ 
wrk1.sa=pl1.cel;
/* operaciq = */ wrk2 .bo= eqatom( wrk1 .sa ,acnst[ 138 ]) ; 
success1= wrk2 .bo ;if( success1 ) { 
rez1=pl1.cel;
   ;} else { rez1=NULL;goto _L109 ;};

bltin1(&rez1,&success1,&pl1,10L);
if( !success1 ) goto _L109;

loc3 .sa=NULL; 

bltin1(&rez1,&success1,&pl1,16L);
if( !success1 ) goto _L109;
loc3 .sa=rez1; 

loc2 .sa=NULL; 

bltin1(&rez1,&success1,&pl1,17L);
if( !success1 ) goto _L109;
loc2 .sa=rez1; 

/* CALL #L */ 
pl3.ptrtype=packedlist;pl3.nel=1;pl3.cel=loc3.sa;
pl3.UU.plistelt[ 0 ]=loc2.sa;
pl3.plistsize= 2;
r38(&wrk1.sa,&flag1,&pl3);/* #TAB*/ ;xxx; 

/* CALL #L */ 
pl3.ptrtype=packedlist;pl3.nel=1;pl3.cel=loc3.sa;
pl3.UU.plistelt[ 0 ]=loc2.sa;
pl3.plistsize= 2;
r39(&wrk1.sa,&flag1,&pl3);/* #LASTTAB*/ ;xxx; 

/* RETURN-op. */ 
wrk1 .sa =NULL; 
addel( acnst[ 139 ],false,NULL, loc3 .sa ,& wrk1 .sa ); 
addel( acnst[ 40 ],false,NULL, loc2 .sa ,& wrk1 .sa ); 
/* operaciq :: */ wrk2 .sa=NULL; 
if( wrk1 .sa!=NULL ) { points( wrk1 .sa,&x.sa); 
x.smtd->name= cnst[62] .sa ; wrk2 = wrk1 ;}; 
rez1 = wrk2 .sa ;goto _L98 ;xxx; 
goto _L99;  _L109:;  /* metka wyhoda po neuspehu wetwi */

/* branch */ pl1=*pl;rez1=NULL;success1=true; 
/* inicializaciq peremennyh */ 
loc2.sa=NULL;/* $E*/ 

/* shablon VPAT */ 
wrk1.sa=pl1.cel;
/* operaciq = */ wrk2 .bo= eqatom( wrk1 .sa ,acnst[ 140 ]) ; 
success1= wrk2 .bo ;if( success1 ) { 
rez1=pl1.cel;
   ;} else { rez1=NULL;goto _L111 ;};

bltin1(&rez1,&success1,&pl1,10L);
if( !success1 ) goto _L111;

/* shablon VPAT */ 
wrk1.sa=pl1.cel;
/* operaciq = */ wrk2 .bo= eqatom( wrk1 .sa ,acnst[ 36 ]) ; 
success1= wrk2 .bo ;if( success1 ) { 
rez1=pl1.cel;
   ;} else { rez1=NULL;goto _L111 ;};

bltin1(&rez1,&success1,&pl1,10L);
if( !success1 ) goto _L111;

loc2 .sa=NULL; 

/* shablon prawila */ r15(&rez1,&success1,&pl1);
if( !success1 ) goto _L111;
loc2 .sa=rez1; 

/* shablon VPAT */ 
wrk1.sa=pl1.cel;
/* operaciq = */ wrk2 .bo= eqatom( wrk1 .sa ,acnst[ 25 ]) ; 
success1= wrk2 .bo ;if( success1 ) { 
rez1=pl1.cel;
   ;} else { rez1=NULL;goto _L111 ;};

bltin1(&rez1,&success1,&pl1,10L);
if( !success1 ) goto _L111;

/* IF-operator */ 
selop( acnst[ 86 ],false,NULL, loc2 .sa ,& wrk1 .sa); 
if( wrk1 .sa!=NULL) 
{ 
/* RETURN-op. */ 
rez1 = loc2 .sa ;goto _L98 ;xxx; 
goto _L110;
;} 
{ 
/* RETURN-op. */ 
wrk3 .sa =NULL; 
addel( acnst[ 98 ],false,NULL, loc2 .sa ,& wrk3 .sa ); 
wrk2 .sa=NULL; 
lconc(& wrk2 .sa , cnst[44] .sa ); 
/* CALL #L */ 
pl4.ptrtype=ptrlist;pl4.nel=0;pl4.cel=NULL;
r40(&wrk1.sa,&flag2,&pl4);/* #GETWRK*/ ; 
lconc(& wrk2 .sa , wrk1 .sa ); 
first(wrk2.sa,&pl3);implod(&pl3,&wrk2.sa); 
addel( acnst[ 47 ],false,NULL, wrk2 .sa ,& wrk3 .sa ); 
/* operaciq :: */ wrk4 .sa=NULL; 
if( wrk3 .sa!=NULL ) { points( wrk3 .sa,&x.sa); 
x.smtd->name= cnst[63] .sa ; wrk4 = wrk3 ;}; 
rez1 = wrk4 .sa ;goto _L98 ;xxx; 
;} 
_L110:;xxx; 
goto _L99;  _L111:;  /* metka wyhoda po neuspehu wetwi */

/* branch */ pl1=*pl;rez1=NULL;success1=true; 
/* inicializaciq peremennyh */ 
loc2.sa=NULL;/* $E*/ 
loc3.sa=NULL;/* $ID*/ 
loc4.sa=NULL;/* $R*/ 
loc5.sa=NULL;/* $BLTIN*/ 
loc6.sa=NULL;/* $tip*/ 
loc7.sa=NULL;/* $FLAG*/ 

loc3 .sa=NULL; 

bltin1(&rez1,&success1,&pl1,16L);
if( !success1 ) goto _L116;
loc3 .sa=rez1; 

/* shablon VPAT */ 
wrk1.sa=pl1.cel;
/* operaciq = */ wrk2 .bo= eqatom( wrk1 .sa ,acnst[ 36 ]) ; 
success1= wrk2 .bo ;if( success1 ) { 
rez1=pl1.cel;
   ;} else { rez1=NULL;goto _L116 ;};

bltin1(&rez1,&success1,&pl1,10L);
if( !success1 ) goto _L116;

/* operator := */ 
/* CALL #L */ 
pl3.ptrtype=packedlist;pl3.nel=1;pl3.cel=loc3.sa;
pl3.plistsize= 1;
r14(&wrk1.sa,&flag1,&pl3);/* #BUILTIN*/ ; 
loc4 .sa= wrk1 .sa ;xxx; 

/* Alternative pattern */ 
pl3=pl1;
/* nonatomic alternative branches */ 

/* shablon VPAT */ 
success1= loc4 .sa!=NULL ;if( success1 ) { 
rez1=pl1.cel;
   ;} else { rez1=NULL;goto _L112 ;};

/* operator := */ 
loc5 .sa= cnst[51] .sa ;xxx; 
goto _L114/*uspeh*/;
_L112:; 
pl1=pl3;

/* shablon VPAT */ 
/* operaciq = */ wrk1 .bo= eqatom( loc3 .sa ,acnst[ 48 ]) ; 
success1= wrk1 .bo ;if( success1 ) { 
rez1=pl1.cel;
   ;} else { rez1=NULL;goto _L113 ;};

/* operator := */ 
loc5 .sa= loc3 .sa ;xxx; 
goto _L114/*uspeh*/;
_L113:; 
pl1=pl3;
goto  _L116;
_L114:;/*uspeh alxtern.*/

loc2 .sa=NULL; 

/* shablon prawila */ r15(&rez1,&success1,&pl1);
if( !success1 ) goto _L116;
loc2 .sa=rez1; 

/* CALL #L */ 
pl3.ptrtype=packedlist;pl3.nel=1;pl3.cel=loc2.sa;
pl3.plistsize= 1;
r35(&wrk1.sa,&flag1,&pl3);/* #sozdatx_mesto2*/ ;xxx; 

/* shablon VPAT */ 
wrk1.sa=pl1.cel;
/* operaciq = */ wrk2 .bo= eqatom( wrk1 .sa ,acnst[ 25 ]) ; 
success1= wrk2 .bo ;if( success1 ) { 
rez1=pl1.cel;
   ;} else { rez1=NULL;goto _L116 ;};

bltin1(&rez1,&success1,&pl1,10L);
if( !success1 ) goto _L116;

/* IF-operator */ 
/* operaciq = */ wrk1 .bo= eqnum( loc4 .sa , 15L ) ; 
if( wrk1 .bo ) wrk3 .bo=true; else { 
/* operaciq = */ wrk2 .bo= eqnum( loc4 .sa , 25L ) ; wrk3 = wrk2 ;}; 
if( wrk3 .bo) 
{ 
/* operator := */ 
loc6 .sa= cnst[46] .sa ;xxx; 
;} 
_L115:;xxx; 

/* operator := */ 
/* CALL #L */ 
pl3.ptrtype=ptrlist;pl3.nel=0;pl3.cel=NULL;
r43(&wrk1.sa,&flag1,&pl3);/* #GET_FLAG*/ ; 
loc7 .sa= wrk1 .sa ;xxx; 

/* operator := */ 
wrk1 .nu= numval( glob2_8 .sa) - 1L ; 
mknumb( wrk1 .nu ,& wrk2 .sa); 
glob2_8 .sa= wrk2 .sa ;xxx; 

/* RETURN-op. */ 
wrk3 .sa =NULL; 
addel( acnst[ 113 ],false,NULL, loc4 .sa ,& wrk3 .sa ); 
addel( acnst[ 98 ],false,NULL, loc2 .sa ,& wrk3 .sa ); 
wrk2 .sa=NULL; 
lconc(& wrk2 .sa , cnst[44] .sa ); 
/* CALL #L */ 
pl4.ptrtype=ptrlist;pl4.nel=0;pl4.cel=NULL;
r40(&wrk1.sa,&flag2,&pl4);/* #GETWRK*/ ; 
lconc(& wrk2 .sa , wrk1 .sa ); 
first(wrk2.sa,&pl3);implod(&pl3,&wrk2.sa); 
addel( acnst[ 47 ],false,NULL, wrk2 .sa ,& wrk3 .sa ); 
addel( acnst[ 86 ],false,NULL, loc6 .sa ,& wrk3 .sa ); 
addel( acnst[ 33 ],false,NULL, loc7 .sa ,& wrk3 .sa ); 
/* operaciq :: */ wrk4 .sa=NULL; 
if( wrk3 .sa!=NULL ) { points( wrk3 .sa,&x.sa); 
x.smtd->name= loc5 .sa ; wrk4 = wrk3 ;}; 
rez1 = wrk4 .sa ;goto _L98 ;xxx; 
goto _L99;  _L116:;  /* metka wyhoda po neuspehu wetwi */

/* branch */ pl1=*pl;rez1=NULL;success1=true; 
/* inicializaciq peremennyh */ 
loc1.sa=NULL;/* $E1*/ 
loc2.sa=NULL;/* $E*/ 
loc3.sa=NULL;/* $ID*/ 
loc7.sa=NULL;/* $FLAG*/ 
loc8.sa=NULL;/* $CALL*/ 
loc9.sa=NULL;/* $N*/ 

loc3 .sa=NULL; 

bltin1(&rez1,&success1,&pl1,16L);
if( !success1 ) goto _L121;
loc3 .sa=rez1; 

/* shablon VPAT */ 
wrk1.sa=pl1.cel;
/* operaciq = */ wrk2 .bo= eqatom( wrk1 .sa ,acnst[ 36 ]) ; 
success1= wrk2 .bo ;if( success1 ) { 
rez1=pl1.cel;
   ;} else { rez1=NULL;goto _L121 ;};

bltin1(&rez1,&success1,&pl1,10L);
if( !success1 ) goto _L121;

/* Alternative pattern */ 
pl3=pl1;
/* nonatomic alternative branches */ 

/* shablon VPAT */ 
/* operaciq = */ wrk1 .bo= eqatom( loc3 .sa ,acnst[ 49 ]) ; 
success1= wrk1 .bo ;if( success1 ) { 
rez1=pl1.cel;
   ;} else { rez1=NULL;goto _L117 ;};

/* operator := */ 
loc8 .sa= cnst[52] .sa ;xxx; 
goto _L119/*uspeh*/;
_L117:; 
pl1=pl3;

/* operator := */ 
loc8 .sa= cnst[53] .sa ;xxx; success1=true; 
goto _L119/*uspeh*/;
_L118:; 
pl1=pl3;
goto  _L121;
_L119:;/*uspeh alxtern.*/

/* operator := */ 
/* CALL #L */ 
pl3.ptrtype=ptrlist;pl3.nel=0;pl3.cel=NULL;
r42(&wrk1.sa,&flag1,&pl3);/* #GET_WORK_PL*/ ; 
loc9 .sa= wrk1 .sa ;xxx; 

/* operator := */ 
/* CALL #L */ 
pl3.ptrtype=ptrlist;pl3.nel=0;pl3.cel=NULL;
r43(&wrk1.sa,&flag1,&pl3);/* #GET_FLAG*/ ; 
loc7 .sa= wrk1 .sa ;xxx; 

/*shablon STARLIST */ 
 pl3=pl1;while(pl1.nel!=0 ) { 

loc1 .sa=NULL; 

/* shablon prawila */ r15(&rez1,&success1,&pl1);
if( !success1 ) goto _L120;
loc1 .sa=rez1; 

/* CALL #L */ 
pl4.ptrtype=packedlist;pl4.nel=1;pl4.cel=loc1.sa;
pl4.plistsize= 1;
r35(&wrk1.sa,&flag1,&pl4);/* #sozdatx_mesto2*/ ;xxx; 

/* operator !.:= */ 
lconc(& loc2 .sa, loc1 .sa ) ;xxx; 
 pl3=pl1;
;}; 
_L120:if( ! success1 )pl1=pl3;
success1 = true ; 

/* shablon VPAT */ 
wrk1.sa=pl1.cel;
/* operaciq = */ wrk2 .bo= eqatom( wrk1 .sa ,acnst[ 25 ]) ; 
success1= wrk2 .bo ;if( success1 ) { 
rez1=pl1.cel;
   ;} else { rez1=NULL;goto _L121 ;};

bltin1(&rez1,&success1,&pl1,10L);
if( !success1 ) goto _L121;

/* operator := */ 
wrk1 .nu= numval( glob2_4 .sa) - 1L ; 
mknumb( wrk1 .nu ,& wrk2 .sa); 
glob2_4 .sa= wrk2 .sa ;xxx; 

/* operator := */ 
wrk1 .nu= numval( glob2_8 .sa) - 1L ; 
mknumb( wrk1 .nu ,& wrk2 .sa); 
glob2_8 .sa= wrk2 .sa ;xxx; 

/* CALL #L */ 
pl3.ptrtype=packedlist;pl3.nel=1;pl3.cel=loc3.sa;
pl3.plistsize= 1;
r46(&wrk1.sa,&flag1,&pl3);/* #CROSS*/ ;xxx; 

/* RETURN-op. */ 
wrk3 .sa =NULL; 
addel( acnst[ 41 ],false,NULL, loc3 .sa ,& wrk3 .sa ); 
addel( acnst[ 108 ],false,NULL, loc9 .sa ,& wrk3 .sa ); 
addel( acnst[ 33 ],false,NULL, loc7 .sa ,& wrk3 .sa ); 
addel( acnst[ 114 ],false,NULL, loc2 .sa ,& wrk3 .sa ); 
wrk2 .sa=NULL; 
lconc(& wrk2 .sa , cnst[44] .sa ); 
/* CALL #L */ 
pl4.ptrtype=ptrlist;pl4.nel=0;pl4.cel=NULL;
r40(&wrk1.sa,&flag2,&pl4);/* #GETWRK*/ ; 
lconc(& wrk2 .sa , wrk1 .sa ); 
first(wrk2.sa,&pl3);implod(&pl3,&wrk2.sa); 
addel( acnst[ 47 ],false,NULL, wrk2 .sa ,& wrk3 .sa ); 
/* operaciq :: */ wrk4 .sa=NULL; 
if( wrk3 .sa!=NULL ) { points( wrk3 .sa,&x.sa); 
x.smtd->name= loc8 .sa ; wrk4 = wrk3 ;}; 
rez1 = wrk4 .sa ;goto _L98 ;xxx; 
goto _L99;  _L121:;  /* metka wyhoda po neuspehu wetwi */

/* branch */ pl1=*pl;rez1=NULL;success1=true; 
/* inicializaciq peremennyh */ 

/* shablon VPAT */ 
wrk1.sa=pl1.cel;
/* operaciq = */ wrk2 .bo= eqatom( wrk1 .sa ,acnst[ 141 ]) ; 
success1= wrk2 .bo ;if( success1 ) { 
rez1=pl1.cel;
   ;} else { rez1=NULL;goto _L122 ;};

bltin1(&rez1,&success1,&pl1,10L);
if( !success1 ) goto _L122;

/* RETURN-op. */ 
wrk3 .sa =NULL; 
addel( acnst[ 98 ],false,NULL, cnst[1] .sa ,& wrk3 .sa ); 
wrk2 .sa=NULL; 
lconc(& wrk2 .sa , cnst[44] .sa ); 
/* CALL #L */ 
pl4.ptrtype=ptrlist;pl4.nel=0;pl4.cel=NULL;
r40(&wrk1.sa,&flag2,&pl4);/* #GETWRK*/ ; 
lconc(& wrk2 .sa , wrk1 .sa ); 
first(wrk2.sa,&pl3);implod(&pl3,&wrk2.sa); 
addel( acnst[ 47 ],false,NULL, wrk2 .sa ,& wrk3 .sa ); 
/* operaciq :: */ wrk4 .sa=NULL; 
if( wrk3 .sa!=NULL ) { points( wrk3 .sa,&x.sa); 
x.smtd->name= cnst[64] .sa ; wrk4 = wrk3 ;}; 
rez1 = wrk4 .sa ;goto _L98 ;xxx; 
goto _L99;  _L122:;  /* metka wyhoda po neuspehu wetwi */

/* branch */ pl1=*pl;rez1=NULL;success1=true; 
/* inicializaciq peremennyh */ 
loc3.sa=NULL;/* $ID*/ 

loc3 .sa=NULL; 

bltin1(&rez1,&success1,&pl1,17L);
if( !success1 ) goto _L124;
loc3 .sa=rez1; 

/* CALL #L */ 
pl3.ptrtype=packedlist;pl3.nel=1;pl3.cel=glob2_5.sa;
pl3.UU.plistelt[ 0 ]=loc3.sa;
pl3.plistsize= 2;
r38(&wrk1.sa,&flag1,&pl3);/* #TAB*/ ;xxx; 

/* IF-operator */ 
/* operaciq = */ wrk1 .bo= eqatom( loc3 .sa ,acnst[ 130 ]) ; 
if( wrk1 .bo) 
{ 
/* operator := */ 
glob24_1 .sa= cnst[1] .sa ;xxx; 
goto _L123;
;} 
{ 
/* CALL #L */ 
pl3.ptrtype=packedlist;pl3.nel=1;pl3.cel=loc3.sa;
pl3.plistsize= 1;
r37(&wrk1.sa,&flag1,&pl3);/* #ADD_USEVAR*/ ;xxx; 
;} 
_L123:;xxx; 

/* RETURN-op. */ 
wrk1 .sa =NULL; 
addel( acnst[ 41 ],false,NULL, loc3 .sa ,& wrk1 .sa ); 
/* operaciq :: */ wrk2 .sa=NULL; 
if( wrk1 .sa!=NULL ) { points( wrk1 .sa,&x.sa); 
x.smtd->name= cnst[27] .sa ; wrk2 = wrk1 ;}; 
rez1 = wrk2 .sa ;goto _L98 ;xxx; 
goto _L99;  _L124:;  /* metka wyhoda po neuspehu wetwi */

/* branch */ pl1=*pl;rez1=NULL;success1=true; 
/* inicializaciq peremennyh */ 

/* shablon VPAT */ 
wrk1.sa=pl1.cel;
bltin(&wrk2,&flag1,wrk1.sa,21L); 
/* operaciq = */ wrk3 .bo= eqnum( wrk2 .sa , 0L ) ; 
success1= wrk3 .bo ;if( success1 ) { 
rez1=pl1.cel;
   ;} else { rez1=NULL;goto _L125 ;};

bltin1(&rez1,&success1,&pl1,11L);
if( !success1 ) goto _L125;

/* RETURN-op. */ 
wrk1 .sa =NULL; 
addel( acnst[ 47 ],false,NULL, cnst[29] .sa ,& wrk1 .sa ); 
/* operaciq :: */ wrk2 .sa=NULL; 
if( wrk1 .sa!=NULL ) { points( wrk1 .sa,&x.sa); 
x.smtd->name= cnst[29] .sa ; wrk2 = wrk1 ;}; 
rez1 = wrk2 .sa ;goto _L98 ;xxx; 
goto _L99;  _L125:;  /* metka wyhoda po neuspehu wetwi */

/* branch */ pl1=*pl;rez1=NULL;success1=true; 
/* inicializaciq peremennyh */ 
loc2.sa=NULL;/* $E*/ 
loc6.sa=NULL;/* $tip*/ 
loc10.sa=NULL;/* $mesto*/ 

/* shablon VPAT */ 
wrk1.sa=pl1.cel;
bltin(&wrk2,&flag1,wrk1.sa,10L); 
wrk3 .bo= wrk2 .sa==NULL; 
success1= wrk3 .bo ;if( success1 ) { 
rez1=pl1.cel;
   ;} else { rez1=NULL;goto _L127 ;};

loc2 .sa=NULL; 

bltin1(&rez1,&success1,&pl1,3L);
if( !success1 ) goto _L127;
loc2 .sa=rez1; 

/* IF-operator */ 
bltin(&wrk1,&flag1,loc2.sa,4L); 
if( wrk1 .sa!=NULL) 
{ 
/* operator := */ 
loc10 .sa= loc2 .sa ;xxx; 
/* operator := */ 
loc6 .sa= cnst[46] .sa ;xxx; 
goto _L126;
;} 
{ 
/* operator := */ 
wrk2 .sa=NULL; 
lconc(& wrk2 .sa , cnst[65] .sa ); 
lconc(& wrk2 .sa , cnst[41] .sa ); 
/* CALL #L */ 
pl4.ptrtype=packedlist;pl4.nel=1;pl4.cel=loc2.sa;
pl4.UU.plistelt[ 0 ]=glob1_1.sa;
pl4.plistsize= 2;
r41(&wrk1.sa,&flag2,&pl4);/* #GETCNST*/ ; 
lconc(& wrk2 .sa , wrk1 .sa ); 
lconc(& wrk2 .sa , cnst[66] .sa ); 
first(wrk2.sa,&pl3);implod(&pl3,&wrk2.sa); 
loc10 .sa= wrk2 .sa ;xxx; 
;} 
_L126:;xxx; 

/* RETURN-op. */ 
wrk1 .sa =NULL; 
addel( acnst[ 46 ],false,NULL, loc2 .sa ,& wrk1 .sa ); 
addel( acnst[ 47 ],false,NULL, loc10 .sa ,& wrk1 .sa ); 
addel( acnst[ 86 ],false,NULL, loc6 .sa ,& wrk1 .sa ); 
/* operaciq :: */ wrk2 .sa=NULL; 
if( wrk1 .sa!=NULL ) { points( wrk1 .sa,&x.sa); 
x.smtd->name= cnst[67] .sa ; wrk2 = wrk1 ;}; 
rez1 = wrk2 .sa ;goto _L98 ;xxx; 
goto _L99;  _L127:;  /* metka wyhoda po neuspehu wetwi */

/* branch */ pl1=*pl;rez1=NULL;success1=true; 
/* inicializaciq peremennyh */ 
loc2.sa=NULL;/* $E*/ 

/* shablon VPAT */ 
wrk1.sa=pl1.cel;
/* operaciq = */ wrk2 .bo= eqatom( wrk1 .sa ,acnst[ 36 ]) ; 
success1= wrk2 .bo ;if( success1 ) { 
rez1=pl1.cel;
   ;} else { rez1=NULL;goto _L128 ;};

bltin1(&rez1,&success1,&pl1,10L);
if( !success1 ) goto _L128;

loc2 .sa=NULL; 

/* shablon prawila */ r15(&rez1,&success1,&pl1);
if( !success1 ) goto _L128;
loc2 .sa=rez1; 

/* shablon VPAT */ 
wrk1.sa=pl1.cel;
/* operaciq = */ wrk2 .bo= eqatom( wrk1 .sa ,acnst[ 25 ]) ; 
success1= wrk2 .bo ;if( success1 ) { 
rez1=pl1.cel;
   ;} else { rez1=NULL;goto _L128 ;};

bltin1(&rez1,&success1,&pl1,10L);
if( !success1 ) goto _L128;

/* RETURN-op. */ 
rez1 = loc2 .sa ;goto _L98 ;xxx; 
goto _L99;  _L128:;  /* metka wyhoda po neuspehu wetwi */
 _L99: rez1=NULL; 
 _L98: *rez=rez1;*success=success1; 
 if (*success) *pl=pl1; /* prodwinutx ukazatelx leksem */ 
/* wosstanowitx GLOB */ 
#ifdef XX  
 d(2,"EXPR1", 33 ,*rez,*success); 
#endif 
;};/* RULE */ 
/*===============================================*/ 
/* GENERATED TEXT OF RULE   #atom_selektor   */ 
 Void r34(rez,success,pl)
long *rez;boolean *success;ptr_ *pl; 
{  a rez1;  boolean success1; long k; mpd x; 
v loc1;/* $A*/ 
v wrk1;
v wrk2;
v wrk3;
ptr_ pl1;
ptr_ pl2;
boolean flag1;
#ifdef XX  
 d(1,"atom_selektor", 34 ,pl->cel,0); 
#endif 
/* sohranitx GLOB */ 

/* branch */ pl1=*pl;rez1=NULL;success1=true; 
/* inicializaciq peremennyh */ 
loc1.sa=NULL;/* $A*/ 

loc1 .sa=NULL; 

bltin1(&rez1,&success1,&pl1,5L);
if( !success1 ) goto _L101;
loc1 .sa=rez1; 

/* RETURN-op. */ 
wrk2 .sa =NULL; 
/* CALL #L */ 
pl2.ptrtype=packedlist;pl2.nel=1;pl2.cel=loc1.sa;
pl2.UU.plistelt[ 0 ]=glob1_2.sa;
pl2.plistsize= 2;
r41(&wrk1.sa,&flag1,&pl2);/* #GETCNST*/ ; 
addel( acnst[ 11 ],false,NULL, wrk1 .sa ,& wrk2 .sa ); 
/* operaciq :: */ wrk3 .sa=NULL; 
if( wrk2 .sa!=NULL ) { points( wrk2 .sa,&x.sa); 
x.smtd->name= cnst[67] .sa ; wrk3 = wrk2 ;}; 
rez1 = wrk3 .sa ;goto _L98 ;xxx; 
goto _L99;  _L101:;  /* metka wyhoda po neuspehu wetwi */
 _L99: rez1=NULL; 
 _L98: *rez=rez1;*success=success1; 
 if (*success) *pl=pl1; /* prodwinutx ukazatelx leksem */ 
/* wosstanowitx GLOB */ 
#ifdef XX  
 d(2,"atom_selektor", 34 ,*rez,*success); 
#endif 
;};/* RULE */ 
/*===============================================*/ 
/* GENERATED TEXT OF RULE   #sozdatx_mesto2   */ 
 Void r35(rez,success,pl)
long *rez;boolean *success;ptr_ *pl; 
{  a rez1;  boolean success1; long k; mpd x; 
v loc1;/* $E*/ 
v wrk1;
v wrk2;
v wrk3;
ptr_ pl1;
ptr_ pl2;
ptr_ pl3;
boolean flag1;
boolean flag2;
#ifdef XX  
 d(1,"sozdatx_mesto2", 35 ,pl->cel,0); 
#endif 
/* sohranitx GLOB */ 

/* branch */ pl1=*pl;rez1=NULL;success1=true; 
/* inicializaciq peremennyh */ 
loc1.sa=NULL;/* $E*/ 

/* shablon peremennoj */ 
success1=(pl1.nel!=0);rez1=pl1.cel;
if( (pl1.ptrtype!=ptrtree) && success1 ) next(&pl1);
loc1 .sa=rez1; 
if( !success1 ) goto _L102;

/* IF-operator */ 
selop( acnst[ 86 ],false,NULL, loc1 .sa ,& wrk1 .sa); 
if( wrk1 .sa!=NULL) 
{ 
/* operator ++:= */ 
wrk3 = loc1 ; 
wrk2 .sa=NULL; 
lconc(& wrk2 .sa , cnst[44] .sa ); 
/* CALL #L */ 
pl3.ptrtype=ptrlist;pl3.nel=0;pl3.cel=NULL;
r40(&wrk1.sa,&flag2,&pl3);/* #GETWRK*/ ; 
lconc(& wrk2 .sa , wrk1 .sa ); 
first(wrk2.sa,&pl2);implod(&pl2,&wrk2.sa); 
addel( acnst[ 142 ],false,NULL, wrk2 .sa ,& loc1 .sa); ;xxx; 
;} 
_L101:;xxx; 
goto _L99;  _L102:;  /* metka wyhoda po neuspehu wetwi */
 _L99: rez1=NULL; 
 _L98: *rez=rez1;*success=success1; 
 if (*success) *pl=pl1; /* prodwinutx ukazatelx leksem */ 
/* wosstanowitx GLOB */ 
#ifdef XX  
 d(2,"sozdatx_mesto2", 35 ,*rez,*success); 
#endif 
;};/* RULE */ 
/*===============================================*/ 
/* GENERATED TEXT OF RULE   #ne~islowoj_atom   */ 
 Void r36(rez,success,pl)
long *rez;boolean *success;ptr_ *pl; 
{  a rez1;  boolean success1; long k; mpd x; 
v loc1;/* $E*/ 
v wrk1;
v wrk2;
v wrk3;
ptr_ pl1;
ptr_ pl2;
ptr_ pl3;
ptr_ pl4;
boolean flag1;
#ifdef XX  
 d(1,"ne~islowoj_atom", 36 ,pl->cel,0); 
#endif 
/* sohranitx GLOB */ 

/* branch */ pl1=*pl;rez1=NULL;success1=true; 
/* inicializaciq peremennyh */ 
loc1.sa=NULL;/* $E*/ 

loc1 .sa=NULL; 

bltin1(&rez1,&success1,&pl1,3L);
if( !success1 ) goto _L119;
loc1 .sa=rez1; 

/* IF-operator */ 
bltin(&wrk1,&flag1,loc1.sa,4L); 
if( wrk1 .sa!=NULL ) wrk3 .bo=true; else { 
bltin(&wrk2,&flag1,loc1.sa,10L); wrk3 .bo= wrk2 .sa!=NULL ;}; 
if( wrk3 .bo) 
{ 
/* FAIL */ rez1=NULL;success1=false; 
if (pl1.ptrtype!=ptrtree) next(&pl1); /*wyhod iz der.ili sp.*/ 
goto _L119;xxx; 
;} 
_L101:;xxx; 

/* Alternative pattern */ 
pl2=pl1;
/* nonatomic alternative branches */ 

/* OPT SP */  
/* Alternative pattern */ 
pl3=pl1;

/* OPT SP */  
/* OPT SP */  
/* OPT SP */  
/* OPT SP */  
/* OPT SP */  
/* OPT SP */  
/* OPT SP */  
/* OPT SP */  
/* OPT SP */  
/* OPT SP */  
/* OPT SP */  
/* Alternative pattern */ 
pl4=pl1;
rez1=pl1.cel;
if ((pl1.nel==0) || (rez1==NULL)) goto _L112;
else { pointr(rez1,&x.sa); 
if (!((x.sad->dtype==atom)|| (x.sad->dtype==idatom)||(x.sad->dtype==keyword) 
||(x.sad->dtype==fatom)) ) goto _L112;
else x.sa=x.sad->name ;}; 

/* atomic branch */ 
if (x.sa==acnst[ 99 ] ) { success1=true; 
 if (pl1.ptrtype!=ptrtree ) 
next(&pl1);
goto _L113;}; _L102:;

/* atomic branch */ 
if (x.sa==acnst[ 34 ] ) { success1=true; 
 if (pl1.ptrtype!=ptrtree ) 
next(&pl1);
goto _L113;}; _L103:;

/* atomic branch */ 
if (x.sa==acnst[ 58 ] ) { success1=true; 
 if (pl1.ptrtype!=ptrtree ) 
next(&pl1);
goto _L113;}; _L104:;

/* atomic branch */ 
if (x.sa==acnst[ 24 ] ) { success1=true; 
 if (pl1.ptrtype!=ptrtree ) 
next(&pl1);
goto _L113;}; _L105:;

/* atomic branch */ 
if (x.sa==acnst[ 95 ] ) { success1=true; 
 if (pl1.ptrtype!=ptrtree ) 
next(&pl1);
goto _L113;}; _L106:;

/* atomic branch */ 
if (x.sa==acnst[ 96 ] ) { success1=true; 
 if (pl1.ptrtype!=ptrtree ) 
next(&pl1);
goto _L113;}; _L107:;

/* atomic branch */ 
if (x.sa==acnst[ 44 ] ) { success1=true; 
 if (pl1.ptrtype!=ptrtree ) 
next(&pl1);
goto _L113;}; _L108:;

/* atomic branch */ 
if (x.sa==acnst[ 45 ] ) { success1=true; 
 if (pl1.ptrtype!=ptrtree ) 
next(&pl1);
goto _L113;}; _L109:;

/* atomic branch */ 
if (x.sa==acnst[ 43 ] ) { success1=true; 
 if (pl1.ptrtype!=ptrtree ) 
next(&pl1);
goto _L113;}; _L110:;

/* atomic branch */ 
if (x.sa==acnst[ 32 ] ) { success1=true; 
 if (pl1.ptrtype!=ptrtree ) 
next(&pl1);
goto _L113;}; _L111:;

/* atomic branch */ 
if (x.sa==acnst[ 94 ] ) { success1=true; 
 if (pl1.ptrtype!=ptrtree ) 
next(&pl1);
goto _L113;}; _L112:;
success1=false;rez1=NULL; 
pl1=pl4;
goto _L114;
_L113:;/*uspeh alxtern.*/

/* FAIL */ rez1=NULL;success1=false; 
if (pl1.ptrtype!=ptrtree) next(&pl1); /*wyhod iz der.ili sp.*/ 
goto _L119;xxx; 
goto _L115/*uspeh*/;
_L114:; 
pl1=pl3;
goto  _L116;
_L115:;/*uspeh alxtern.*/
goto _L118/*uspeh*/;
_L116:; 
pl1=pl2;

/* shablon VPAT */ 
success1= cnst[1] .sa!=NULL ;if( success1 ) { 
rez1=pl1.cel;
   ;} else { rez1=NULL;goto _L117 ;};
goto _L118/*uspeh*/;
_L117:; 
pl1=pl2;
goto  _L119;
_L118:;/*uspeh alxtern.*/

/* RETURN-op. */ 
wrk2 .sa =NULL; 
/* CALL #L */ 
pl2.ptrtype=packedlist;pl2.nel=1;pl2.cel=loc1.sa;
pl2.UU.plistelt[ 0 ]=glob1_2.sa;
pl2.plistsize= 2;
r41(&wrk1.sa,&flag1,&pl2);/* #GETCNST*/ ; 
addel( acnst[ 11 ],false,NULL, wrk1 .sa ,& wrk2 .sa ); 
/* operaciq :: */ wrk3 .sa=NULL; 
if( wrk2 .sa!=NULL ) { points( wrk2 .sa,&x.sa); 
x.smtd->name= cnst[67] .sa ; wrk3 = wrk2 ;}; 
rez1 = wrk3 .sa ;goto _L98 ;xxx; 
goto _L99;  _L119:;  /* metka wyhoda po neuspehu wetwi */
 _L99: rez1=NULL; 
 _L98: *rez=rez1;*success=success1; 
 if (*success) *pl=pl1; /* prodwinutx ukazatelx leksem */ 
/* wosstanowitx GLOB */ 
#ifdef XX  
 d(2,"ne~islowoj_atom", 36 ,*rez,*success); 
#endif 
;};/* RULE */ 
/*===============================================*/ 
/* GENERATED TEXT OF RULE   #ADD_USEVAR   */ 
 Void r37(rez,success,pl)
long *rez;boolean *success;ptr_ *pl; 
{  a rez1;  boolean success1; long k; mpd x; 
v loc1;/* $V*/ 
v wrk1;
ptr_ pl1;
#ifdef XX  
 d(1,"ADD_USEVAR", 37 ,pl->cel,0); 
#endif 
/* sohranitx GLOB */ 

/* branch */ pl1=*pl;rez1=NULL;success1=true; 
/* inicializaciq peremennyh */ 
loc1.sa=NULL;/* $V*/ 

/* shablon peremennoj */ 
success1=(pl1.nel!=0);rez1=pl1.cel;
if( (pl1.ptrtype!=ptrtree) && success1 ) next(&pl1);
loc1 .sa=rez1; 
if( !success1 ) goto _L101;

/* operator ++:= */ 
wrk1 = glob26_1 ; 
addel( 0L,true, loc1 .sa, cnst[1] .sa ,& glob26_1 .sa); ;xxx; 
goto _L99;  _L101:;  /* metka wyhoda po neuspehu wetwi */
 _L99: rez1=NULL; 
 _L98: *rez=rez1;*success=success1; 
 if (*success) *pl=pl1; /* prodwinutx ukazatelx leksem */ 
/* wosstanowitx GLOB */ 
#ifdef XX  
 d(2,"ADD_USEVAR", 37 ,*rez,*success); 
#endif 
;};/* RULE */ 
