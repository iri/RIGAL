
#include "globrig.h" 
#include "define.h"  
#include "defpage.h" 
#include "nef2.h"    
#include "c1.h"      
#include "usemod.h"  
#include "def180.h"  
#include "xcrg.h"    
/*  R54 ss6 */ 
/*  R55 ss7 */ 
/*  R56 ss9 */ 
/*  R57 ss10 */ 
/*  R58 ss11 */ 
/*  R59 ss12 */ 
/*  R60 ss13 */ 
/*  R61 ss14 */ 
/*  R62 ss17 */ 
/*===============================================*/ 
/* GENERATED TEXT OF RULE   #ss6   */ 
 Void r54(rez,success,pl)
long *rez;boolean *success;ptr_ *pl; 
{  a rez1;  boolean success1; long k; mpd x; 
ptr_ pl1;
#ifdef XX  
 d(1,"ss6", 54 ,pl->cel,0); 
#endif 
/* sohranitx GLOB */ 

/* branch */ pl1=*pl;rez1=NULL;success1=true; 
/* inicializaciq peremennyh */ 

outatm(acnst[15]," _L99: rez1=NULL;",true, true); ;xxx; 

outatm(acnst[15]," _L98: *rez=rez1;*success=success1;",true, true); ;xxx; 

outatm(acnst[15]," if (*success) *pl=pl1;",true, true); 
outatm(acnst[15],"/* prodwinutx ukazatelx leksem */",false, true); ;xxx; 
goto _L99;  _L101:;  /* metka wyhoda po neuspehu wetwi */
 _L99: rez1=NULL; 
 _L98: *rez=rez1;*success=success1; 
 if (*success) *pl=pl1; /* prodwinutx ukazatelx leksem */ 
/* wosstanowitx GLOB */ 
#ifdef XX  
 d(2,"ss6", 54 ,*rez,*success); 
#endif 
;};/* RULE */ 
/*===============================================*/ 
/* GENERATED TEXT OF RULE   #ss7   */ 
 Void r55(rez,success,pl)
long *rez;boolean *success;ptr_ *pl; 
{  a rez1;  boolean success1; long k; mpd x; 
ptr_ pl1;
#ifdef XX  
 d(1,"ss7", 55 ,pl->cel,0); 
#endif 
/* sohranitx GLOB */ 

/* branch */ pl1=*pl;rez1=NULL;success1=true; 
/* inicializaciq peremennyh */ 

outxt(acnst[ 15 ],NULL,true,false) ;xxx; 

outatm(acnst[15],"/* branch */ pl1=*pl;rez1=NULL;success1=true;",true, true); 
;xxx; 
goto _L99;  _L101:;  /* metka wyhoda po neuspehu wetwi */
 _L99: rez1=NULL; 
 _L98: *rez=rez1;*success=success1; 
 if (*success) *pl=pl1; /* prodwinutx ukazatelx leksem */ 
/* wosstanowitx GLOB */ 
#ifdef XX  
 d(2,"ss7", 55 ,*rez,*success); 
#endif 
;};/* RULE */ 
/*===============================================*/ 
/* GENERATED TEXT OF RULE   #ss9   */ 
 Void r56(rez,success,pl)
long *rez;boolean *success;ptr_ *pl; 
{  a rez1;  boolean success1; long k; mpd x; 
ptr_ pl1;
#ifdef XX  
 d(1,"ss9", 56 ,pl->cel,0); 
#endif 
/* sohranitx GLOB */ 

/* branch */ pl1=*pl;rez1=NULL;success1=true; 
/* inicializaciq peremennyh */ 

outxt(acnst[ 15 ], cnst[55] .sa , true, false); 
outxt(acnst[ 15 ], glob3_3 .sa , false, false); 
outatm(acnst[15],".cel;",false, false); ;xxx; 

outxt(acnst[ 15 ], cnst[56] .sa , true, false); 
outxt(acnst[ 15 ], glob3_3 .sa , false, false); 
outatm(acnst[15],".nel==0)||(rez1==NULL)) ",false, false); 
outatm(acnst[15],"  ",false, false); ;xxx; 

outatm(acnst[15]," { success1=false;",true, true); ;xxx; 

outatm(acnst[15],"goto",true, true); 
outxt(acnst[ 15 ], cnst[57] .sa , false, false); 
outxt(acnst[ 15 ], glob10_2 .sa , false, false); 
outatm(acnst[15],";};",false, false); ;xxx; 

outatm(acnst[15]," pointr(rez1,&x.sa);",true, true); ;xxx; 

outatm(acnst[15]," success1=(x.sad->dtype ",true, true); ;xxx; 
goto _L99;  _L101:;  /* metka wyhoda po neuspehu wetwi */
 _L99: rez1=NULL; 
 _L98: *rez=rez1;*success=success1; 
 if (*success) *pl=pl1; /* prodwinutx ukazatelx leksem */ 
/* wosstanowitx GLOB */ 
#ifdef XX  
 d(2,"ss9", 56 ,*rez,*success); 
#endif 
;};/* RULE */ 
/*===============================================*/ 
/* GENERATED TEXT OF RULE   #ss10   */ 
 Void r57(rez,success,pl)
long *rez;boolean *success;ptr_ *pl; 
{  a rez1;  boolean success1; long k; mpd x; 
ptr_ pl1;
#ifdef XX  
 d(1,"ss10", 57 ,pl->cel,0); 
#endif 
/* sohranitx GLOB */ 

/* branch */ pl1=*pl;rez1=NULL;success1=true; 
/* inicializaciq peremennyh */ 

outatm(acnst[15],");",false, true); ;xxx; 

outatm(acnst[15],"if (success1){",true, true); ;xxx; 

outxt(acnst[ 15 ], cnst[58] .sa , true, false); 
outxt(acnst[ 15 ], glob3_3 .sa , false, false); 
outxt(acnst[ 15 ], cnst[59] .sa , false, false); 
outxt(acnst[ 15 ], glob3_3 .sa , false, false); 
outatm(acnst[15],") ;}",false, true); ;xxx; 

outxt(acnst[ 15 ], cnst[60] .sa , true, false); 
outxt(acnst[ 15 ], glob10_2 .sa , false, false); 
outatm(acnst[15],";};",false, false); ;xxx; 
goto _L99;  _L101:;  /* metka wyhoda po neuspehu wetwi */
 _L99: rez1=NULL; 
 _L98: *rez=rez1;*success=success1; 
 if (*success) *pl=pl1; /* prodwinutx ukazatelx leksem */ 
/* wosstanowitx GLOB */ 
#ifdef XX  
 d(2,"ss10", 57 ,*rez,*success); 
#endif 
;};/* RULE */ 
/*===============================================*/ 
/* GENERATED TEXT OF RULE   #ss11   */ 
 Void r58(rez,success,pl)
long *rez;boolean *success;ptr_ *pl; 
{  a rez1;  boolean success1; long k; mpd x; 
v loc1;/* $wid*/ 
ptr_ pl1;
#ifdef XX  
 d(1,"ss11", 58 ,pl->cel,0); 
#endif 
/* sohranitx GLOB */ 

/* branch */ pl1=*pl;rez1=NULL;success1=true; 
/* inicializaciq peremennyh */ 
loc1.sa=NULL;/* $wid*/ 

/* shablon peremennoj */ 
success1=(pl1.nel!=0);rez1=pl1.cel;
if( (pl1.ptrtype!=ptrtree) && success1 ) next(&pl1);
loc1 .sa=rez1; 
if( !success1 ) goto _L101;

outatm(acnst[15],"/* shablon",true, true); 
outxt(acnst[ 15 ], loc1 .sa , false, true); 
outatm(acnst[15],"*/",false, true); 
outxt(acnst[ 15 ], cnst[61] .sa , false, false); 
outxt(acnst[ 15 ], glob3_3 .sa , false, false); ;xxx; 

outatm(acnst[15],".cel;",false, false); ;xxx; 

outxt(acnst[ 15 ], cnst[62] .sa , true, false); 
outxt(acnst[ 15 ], glob3_3 .sa , false, false); 
outxt(acnst[ 15 ], cnst[63] .sa , false, false); 
outxt(acnst[ 15 ], glob10_2 .sa , false, false); 
outatm(acnst[15],";",false, true); ;xxx; 

outatm(acnst[15]," if (rez1!=NULL ) { pointr(rez1,&x.sa);",true, true); ;xxx; 

outatm(acnst[15],"       if (x.smld->dtype!=",true, true); 
outxt(acnst[ 15 ], loc1 .sa , false, true); 
outatm(acnst[15],") ",false, true); ;xxx; 

outxt(acnst[ 15 ], cnst[64] .sa , true, false); 
outxt(acnst[ 15 ], glob10_2 .sa , false, false); 
outatm(acnst[15],";};",false, false); ;xxx; 
goto _L99;  _L101:;  /* metka wyhoda po neuspehu wetwi */
 _L99: rez1=NULL; 
 _L98: *rez=rez1;*success=success1; 
 if (*success) *pl=pl1; /* prodwinutx ukazatelx leksem */ 
/* wosstanowitx GLOB */ 
#ifdef XX  
 d(2,"ss11", 58 ,*rez,*success); 
#endif 
;};/* RULE */ 
/*===============================================*/ 
/* GENERATED TEXT OF RULE   #ss12   */ 
 Void r59(rez,success,pl)
long *rez;boolean *success;ptr_ *pl; 
{  a rez1;  boolean success1; long k; mpd x; 
v loc1;/* $NPL*/ 
ptr_ pl1;
#ifdef XX  
 d(1,"ss12", 59 ,pl->cel,0); 
#endif 
/* sohranitx GLOB */ 

/* branch */ pl1=*pl;rez1=NULL;success1=true; 
/* inicializaciq peremennyh */ 
loc1.sa=NULL;/* $NPL*/ 

/* shablon peremennoj */ 
varpat(&pl1,number,&rez1,&success1);
loc1 .sa=rez1; 
if( !success1 ) goto _L101;

outatm(acnst[15],"{pl",true, false); 
outxt(acnst[ 15 ], loc1 .sa , false, false); 
outatm(acnst[15],".ptrtype=ptrlist; pl",false, false); 
outxt(acnst[ 15 ], loc1 .sa , false, false); 
outatm(acnst[15],".nel=1;",false, false); ;xxx; 

outatm(acnst[15],"pl",true, false); 
outxt(acnst[ 15 ], loc1 .sa , false, false); 
outatm(acnst[15],".cel=x.smld->elt[0];pl",false, false); 
outxt(acnst[ 15 ], loc1 .sa , false, false); 
outatm(acnst[15],".UU.U1.curfragment=rez1;}",false, false); ;xxx; 
goto _L99;  _L101:;  /* metka wyhoda po neuspehu wetwi */
 _L99: rez1=NULL; 
 _L98: *rez=rez1;*success=success1; 
 if (*success) *pl=pl1; /* prodwinutx ukazatelx leksem */ 
/* wosstanowitx GLOB */ 
#ifdef XX  
 d(2,"ss12", 59 ,*rez,*success); 
#endif 
;};/* RULE */ 
/*===============================================*/ 
/* GENERATED TEXT OF RULE   #ss13   */ 
 Void r60(rez,success,pl)
long *rez;boolean *success;ptr_ *pl; 
{  a rez1;  boolean success1; long k; mpd x; 
ptr_ pl1;
#ifdef XX  
 d(1,"ss13", 60 ,pl->cel,0); 
#endif 
/* sohranitx GLOB */ 

/* branch */ pl1=*pl;rez1=NULL;success1=true; 
/* inicializaciq peremennyh */ 

outxt(acnst[ 15 ], cnst[65] .sa , true, false); 
outxt(acnst[ 15 ], glob10_2 .sa , false, false); 
outatm(acnst[15],";};",false, false); ;xxx; 

outxt(acnst[ 15 ], cnst[66] .sa , true, false); 
outxt(acnst[ 15 ], glob3_3 .sa , false, false); 
outatm(acnst[15],".cel;",false, false); ;xxx; 

outxt(acnst[ 15 ], cnst[67] .sa , true, false); 
outxt(acnst[ 15 ], glob3_3 .sa , false, false); 
outxt(acnst[ 15 ], cnst[59] .sa , false, false); 
outxt(acnst[ 15 ], glob3_3 .sa , false, false); 
outatm(acnst[15],");",false, false); ;xxx; 
goto _L99;  _L101:;  /* metka wyhoda po neuspehu wetwi */
 _L99: rez1=NULL; 
 _L98: *rez=rez1;*success=success1; 
 if (*success) *pl=pl1; /* prodwinutx ukazatelx leksem */ 
/* wosstanowitx GLOB */ 
#ifdef XX  
 d(2,"ss13", 60 ,*rez,*success); 
#endif 
;};/* RULE */ 
/*===============================================*/ 
/* GENERATED TEXT OF RULE   #ss14   */ 
 Void r61(rez,success,pl)
long *rez;boolean *success;ptr_ *pl; 
{  a rez1;  boolean success1; long k; mpd x; 
ptr_ pl1;
#ifdef XX  
 d(1,"ss14", 61 ,pl->cel,0); 
#endif 
/* sohranitx GLOB */ 

/* branch */ pl1=*pl;rez1=NULL;success1=true; 
/* inicializaciq peremennyh */ 

outxt(acnst[ 15 ], cnst[68] .sa , true, false); 
outxt(acnst[ 15 ], glob10_2 .sa , false, false); 
outatm(acnst[15],";",false, false); ;xxx; 
goto _L99;  _L101:;  /* metka wyhoda po neuspehu wetwi */
 _L99: rez1=NULL; 
 _L98: *rez=rez1;*success=success1; 
 if (*success) *pl=pl1; /* prodwinutx ukazatelx leksem */ 
/* wosstanowitx GLOB */ 
#ifdef XX  
 d(2,"ss14", 61 ,*rez,*success); 
#endif 
;};/* RULE */ 
/*===============================================*/ 
/* GENERATED TEXT OF RULE   #ss17   */ 
 Void r62(rez,success,pl)
long *rez;boolean *success;ptr_ *pl; 
{  a rez1;  boolean success1; long k; mpd x; 
ptr_ pl1;
#ifdef XX  
 d(1,"ss17", 62 ,pl->cel,0); 
#endif 
/* sohranitx GLOB */ 

/* branch */ pl1=*pl;rez1=NULL;success1=true; 
/* inicializaciq peremennyh */ 

outatm(acnst[15],";} else ",true, true); ;xxx; 

outxt(acnst[ 15 ], cnst[69] .sa , true, false); 
outxt(acnst[ 15 ], glob3_3 .sa , false, false); 
outatm(acnst[15],".ptrtype=ptrlist;",false, false); 
outxt(acnst[ 15 ], cnst[70] .sa , false, false); 
outxt(acnst[ 15 ], glob3_3 .sa , false, false); 
outatm(acnst[15],".nel=0;",false, false); 
outxt(acnst[ 15 ], cnst[70] .sa , false, false); 
outxt(acnst[ 15 ], glob3_3 .sa , false, false); 
outatm(acnst[15],".cel=NULL;}",false, false); ;xxx; 
goto _L99;  _L101:;  /* metka wyhoda po neuspehu wetwi */
 _L99: rez1=NULL; 
 _L98: *rez=rez1;*success=success1; 
 if (*success) *pl=pl1; /* prodwinutx ukazatelx leksem */ 
/* wosstanowitx GLOB */ 
#ifdef XX  
 d(2,"ss17", 62 ,*rez,*success); 
#endif 
;};/* RULE */ 
