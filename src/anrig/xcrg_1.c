
#include "globrig.h" 
#include "define.h"  
#include "defpage.h" 
#include "nef2.h"    
#include "c1.h"      
#include "usemod.h"  
#include "def180.h"  
#include "xcrg.h"    
/*  R2 programma */ 
/*  R3 glawnoe_prawilo */ 
/*===============================================*/ 
/* GENERATED TEXT OF RULE   #programma   */ 
 Void r2(rez,success,pl)
long *rez;boolean *success;ptr_ *pl; 
{  a rez1;  boolean success1; long k; mpd x; 
v loc1;/* $E*/ 
v oldglob2_1;
v oldglob2_2;
v oldglob2_3;
v oldglob2_4;
v oldglob2_5;
v oldglob2_6;
v oldglob2_7;
v oldglob2_8;
ptr_ pl1;
ptr_ pl2;
ptr_ pl3;
ptr_ pl4;
ptr_ pl5;
#ifdef XX  
 d(1,"programma", 2 ,pl->cel,0); 
#endif 
/* sohranitx GLOB */ 
oldglob2_1=glob2_1;
oldglob2_2=glob2_2;
oldglob2_3=glob2_3;
oldglob2_4=glob2_4;
oldglob2_5=glob2_5;
oldglob2_6=glob2_6;
oldglob2_7=glob2_7;
oldglob2_8=glob2_8;

/* branch */ pl1=*pl;rez1=NULL;success1=true; 
/* inicializaciq peremennyh */ 
loc1.sa=NULL;/* $E*/ 
glob2_1.sa=NULL;
glob2_2.sa=NULL;
glob2_3.sa=NULL;
glob2_4.sa=NULL;
glob2_5.sa=NULL;
glob2_6.sa=NULL;
glob2_7.sa=NULL;
glob2_8.sa=NULL;

/* OPT SP */  
/* OPT SP */  
/* Alternative pattern */ 
pl2=pl1;
rez1=pl1.cel;
if ((pl1.nel==0) || (rez1==NULL)) goto _L108;
else { pointr(rez1,&x.sa); 
if (!((x.sad->dtype==atom)|| (x.sad->dtype==idatom)||(x.sad->dtype==keyword) 
||(x.sad->dtype==fatom)) ) goto _L108;
else x.sa=x.sad->name ;}; 

/* atomic branch */ 
if (x.sa==acnst[ 13 ] ) { success1=true; 
 if (pl1.ptrtype!=ptrtree ) 
next(&pl1);

/* shablon listmain */ rez1=pl1.cel;
success1=false;if(pl1.nel==0 ) goto _L108; 
 if (rez1!=NULL ) { pointr(rez1,&x.sa); 
       if (x.smld->dtype!= listmain )  
        { rez1=NULL;goto _L108;};
{pl4.ptrtype=ptrlist; pl4.nel=1;
pl4.cel=x.smld->elt[0];pl4.UU.U1.curfragment=rez1;}
;} else  
{pl4.ptrtype=ptrlist;pl4.nel=0;pl4.cel=NULL;}


/* shablon prawila */ r3(&rez1,&success1,&pl4);
if( !success1 ) goto _L108;
lconc(& loc1 .sa,rez1); 

/*shablon STARLIST */ 
 pl5=pl4;while(pl4.nel!=0 ) { 


/* shablon prawila */ r24(&rez1,&success1,&pl4);
if( !success1 ) goto _L101;
lconc(& loc1 .sa,rez1); 
 pl5=pl4;
;}; 
_L101:if( ! success1 )pl4=pl5;
success1 = true ; 

if( pl4.nel !=0 )
{ success1=false;rez1=NULL;goto _L108;};
success1=true;rez1=pl1.cel;
 if( pl1.ptrtype!=ptrtree ) next(&pl1);
goto _L109;}; _L104:;

/* atomic branch */ 
if (x.sa==acnst[ 14 ] ) { success1=true; 
 if (pl1.ptrtype!=ptrtree ) 
next(&pl1);

/* shablon listmain */ rez1=pl1.cel;
success1=false;if(pl1.nel==0 ) goto _L108; 
 if (rez1!=NULL ) { pointr(rez1,&x.sa); 
       if (x.smld->dtype!= listmain )  
        { rez1=NULL;goto _L108;};
{pl4.ptrtype=ptrlist; pl4.nel=1;
pl4.cel=x.smld->elt[0];pl4.UU.U1.curfragment=rez1;}
;} else  
{pl4.ptrtype=ptrlist;pl4.nel=0;pl4.cel=NULL;}

/*shablon STARLIST */ 
 pl5=pl4;while(pl4.nel!=0 ) { 


/* shablon prawila */ r24(&rez1,&success1,&pl4);
if( !success1 ) goto _L105;
lconc(& loc1 .sa,rez1); 
 pl5=pl4;
;}; 
_L105:if( ! success1 )pl4=pl5;
success1 = true ; 

if( pl4.nel !=0 )
{ success1=false;rez1=NULL;goto _L108;};
success1=true;rez1=pl1.cel;
 if( pl1.ptrtype!=ptrtree ) next(&pl1);
goto _L109;}; _L108:;
success1=false;rez1=NULL; 
pl1=pl2;
goto _L110;
_L109:;/*uspeh alxtern.*/

/* RETURN-op. */ 
rez1 = loc1 .sa ;goto _L98 ;xxx; 
goto _L99;  _L110:;  /* metka wyhoda po neuspehu wetwi */
 _L99: rez1=NULL; 
 _L98: *rez=rez1;*success=success1; 
 if (*success) *pl=pl1; /* prodwinutx ukazatelx leksem */ 
/* wosstanowitx GLOB */ 
glob2_1=oldglob2_1;
glob2_2=oldglob2_2;
glob2_3=oldglob2_3;
glob2_4=oldglob2_4;
glob2_5=oldglob2_5;
glob2_6=oldglob2_6;
glob2_7=oldglob2_7;
glob2_8=oldglob2_8;
#ifdef XX  
 d(2,"programma", 2 ,*rez,*success); 
#endif 
;};/* RULE */ 
/*===============================================*/ 
/* GENERATED TEXT OF RULE   #glawnoe_prawilo   */ 
 Void r3(rez,success,pl)
long *rez;boolean *success;ptr_ *pl; 
{  a rez1;  boolean success1; long k; mpd x; 
v loc2;/* $E*/ 
v wrk1;
v wrk2;
v wrk3;
v wrk4;
v wrk5;
v oldglob3_1;
ptr_ pl1;
ptr_ pl2;
ptr_ pl3;
boolean flag1;
boolean flag2;
#ifdef XX  
 d(1,"glawnoe_prawilo", 3 ,pl->cel,0); 
#endif 
/* sohranitx GLOB */ 
oldglob3_1=glob3_1;

/* branch */ pl1=*pl;rez1=NULL;success1=true; 
/* inicializaciq peremennyh */ 
glob3_1.sa=NULL;
loc2.sa=NULL;/* $E*/ 

glob3_1 .sa=NULL; 

bltin1(&rez1,&success1,&pl1,16L);
if( !success1 ) goto _L104;
glob3_1 .sa=rez1; 

/* CALL_PAS */ 
mknumb( 55L,& wrk2 .sa); 
/* CALL_PAS */ 
use_34(NULL,NULL,NULL,&wrk4.sa);; 
use_25(wrk2.sa,wrk4.sa,NULL,&wrk5.sa);;xxx; 

/* CALL_PAS */ 
wrk2 .sa=NULL; 
lconc(& wrk2 .sa , cnst[22] .sa ); 
lconc(& wrk2 .sa , glob3_1 .sa ); 
first(wrk2.sa,&pl3);implod(&pl3,&wrk2.sa); 
use_30(wrk2.sa,NULL,NULL,&wrk3.sa);;xxx; 

/* CALL_PAS */ 
use_28(NULL,NULL,NULL,&wrk2.sa);;xxx; 

/* operator := */ 
mknumb( 0L,& wrk1 .sa); 
glob2_1 .sa= wrk1 .sa ;xxx; 

/* operator := */ 
mknumb( 0L,& wrk1 .sa); 
glob2_2 .sa= wrk1 .sa ;xxx; 

/* operator := */ 
mknumb( 1L,& wrk1 .sa); 
glob2_3 .sa= wrk1 .sa ;xxx; 

/* operator := */ 
mknumb( 0L,& wrk1 .sa); 
glob2_4 .sa= wrk1 .sa ;xxx; 

/* operator := */ 
glob2_5 .sa= glob3_1 .sa ;xxx; 

/* operator := */ 
mknumb( 100L,& wrk1 .sa); 
glob2_6 .sa= wrk1 .sa ;xxx; 

/* operator !.:= */ 
lconc(& glob1_1 .sa, cnst[1] .sa ) ;xxx; 

/* operator !.:= */ 
lconc(& glob1_2 .sa, cnst[1] .sa ) ;xxx; 

/* CALL #L */ 
pl2.ptrtype=packedlist;pl2.nel=1;pl2.cel=glob3_1.sa;
pl2.plistsize= 1;
r38(&wrk1.sa,&flag1,&pl2);/* #TAB*/ ;xxx; 

/*shablon STARLIST */ 
 pl2=pl1;while(pl1.nel!=0 ) { 


/* shablon prawila */ r30(&rez1,&success1,&pl1);
if( !success1 ) goto _L102;
lconc(& loc2 .sa,rez1); 
 pl2=pl1;

/* shablon atoma */ atmpat(acnst[15],&pl1,&rez1,&success1);
if( !success1 ) goto _L101;
;}; 
_L102:if( ! success1 )pl1=pl2;
_L101:;
success1 = true ; 

/* shablon [ ... ] */ pl2=pl1;

/* shablon atoma */ atmpat(acnst[15],&pl1,&rez1,&success1);
if( !success1 ) goto _L103;
_L103:if( ! success1 ) pl1=pl2;success1=true;

/* shablon SPAT */ 
if( pl1.nel==0 ) { success1=false;goto _L104 ;};
wrk1.sa=pl1.cel;
bltin(&wrk2,&flag1,wrk1.sa,10L); 
if( wrk2 .sa==NULL ) wrk5 .bo=false; else { 
wrk3.sa=pl1.cel;
/* operaciq = */ wrk4 .bo= eqatom( wrk3 .sa ,acnst[ 16 ]) ; wrk5 = wrk4 ;}; 
success1= wrk5 .bo ;if( success1 ) { 
rez1=pl1.cel;
if( pl1.ptrtype!=ptrtree ) next(&pl1);
   ;} else { rez1=NULL;goto _L104 ;};

/* RETURN-op. */ 
wrk1 .sa =NULL; 
addel( acnst[ 17 ],false,NULL, glob2_2 .sa ,& wrk1 .sa ); 
addel( acnst[ 18 ],false,NULL, glob2_3 .sa ,& wrk1 .sa ); 
addel( acnst[ 19 ],false,NULL, glob2_7 .sa ,& wrk1 .sa ); 
addel( acnst[ 20 ],false,NULL, glob2_6 .sa ,& wrk1 .sa ); 
addel( acnst[ 21 ],false,NULL, loc2 .sa ,& wrk1 .sa ); 
/* operaciq :: */ wrk2 .sa=NULL; 
if( wrk1 .sa!=NULL ) { points( wrk1 .sa,&x.sa); 
x.smtd->name= glob3_1 .sa ; wrk2 = wrk1 ;}; 
rez1 = wrk2 .sa ;goto _L98 ;xxx; 
goto _L99;  _L104:;  /* metka wyhoda po neuspehu wetwi */

/* branch */ pl1=*pl;rez1=NULL;success1=true; 
/* inicializaciq peremennyh */ 
glob3_1.sa=NULL;

outatm(acnst[2],"ERROR:  COMPILATION ERROR IN MAIN  RULE OF PROGRAM",true, 
true); ;xxx; 

outatm(acnst[2],"        TRY CHECK IT",true, true); ;xxx; 
goto _L99;  _L105:;  /* metka wyhoda po neuspehu wetwi */
 _L99: rez1=NULL; 
 _L98: *rez=rez1;*success=success1; 
 if (*success) *pl=pl1; /* prodwinutx ukazatelx leksem */ 
/* wosstanowitx GLOB */ 
glob3_1=oldglob3_1;
#ifdef XX  
 d(2,"glawnoe_prawilo", 3 ,*rez,*success); 
#endif 
;};/* RULE */ 
