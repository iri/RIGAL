
/* Local variables for acon: */   
struct LOC_acon {a k;allpacked r;} ; 
Local Void uc(l, cn, dt, LINK)       
long l, cn; char dt;                 
struct LOC_acon *LINK;               
{  putatm(LINK->r.bl, l, &LINK->k);  
  mkatom(LINK->k, dt, &cnst[cn ].sa);} 
Static Void acon()                  
{  struct LOC_acon V;    mpd x;     
  mainlistdescriptor *WITH;         
V.r.p1='T';
uc (1L,1L,idatom,&V);
V.r.p1=' ';
uc (1L,2L,atom,&V);
memcpy(V.r.p11,"RIGCOMP.TMP",11L);
uc (11L,3L,atom,&V);
memcpy(V.r.p4,".RC4",4L);
uc (4L,4L,atom,&V);
memcpy(V.r.p4,".RC2",4L);
uc (4L,5L,atom,&V);
memcpy(V.r.p13,"RIGAL v.4.45 ",13L);
uc (13L,6L,atom,&V);
memcpy(V.r.p4,"MAIN",4L);
uc (4L,7L,idatom,&V);
memcpy(V.r.p8,"CONTINUE",8L);
uc (8L,8L,idatom,&V);
memcpy(V.r.p8,"acon(); ",8L);
uc (8L,9L,atom,&V);
memcpy(V.r.p7,"Coding ",7L);
uc (7L,10L,atom,&V);
memcpy(V.r.p2," (",2L);
uc (2L,11L,atom,&V);
memcpy(V.r.p4," of ",4L);
uc (4L,12L,atom,&V);
memcpy(V.r.p7," files)",7L);
uc (7L,13L,atom,&V);
memcpy(V.r.p6,"NOMAIN",6L);
uc (6L,14L,idatom,&V);
memcpy(V.r.p3,"old",3L);
uc (3L,15L,idatom,&V);
memcpy(V.r.p44,"   if( rez1==NULL ) { success1=false;goto _L",44L);
uc (44L,16L,atom,&V);
memcpy(V.r.p36,"if( ! success1 ) { rez1=NULL;goto _L",36L);
uc (36L,17L,atom,&V);
memcpy(V.r.p3,".sa",3L);
uc (3L,18L,atom,&V);
memcpy(V.r.p17,"/*BREAK*/ goto _L",17L);
uc (17L,19L,atom,&V);
memcpy(V.r.p3,".nu",3L);
uc (3L,20L,atom,&V);
V.r.p1='0';
uc (1L,21L,atom,&V);
memcpy(V.r.p7,"numval(",7L);
uc (7L,22L,atom,&V);
memcpy(V.r.p4,".sa)",4L);
uc (4L,23L,atom,&V);
memcpy(V.r.p4,"NULL",4L);
uc (4L,24L,idatom,&V);
memcpy(V.r.p6,"xcrg.c",6L);
uc (6L,25L,atom,&V);
memcpy(V.r.p5,"xcrg_",5L);
uc (5L,26L,idatom,&V);
memcpy(V.r.p2,".c",2L);
uc (2L,27L,atom,&V);
memcpy(V.r.p5,"/*  R",5L);
uc (5L,28L,atom,&V);
memcpy(V.r.p3,"sss",3L);
uc (3L,29L,idatom,&V);
memcpy(V.r.p2,"ss",2L);
uc (2L,30L,idatom,&V);
memcpy(V.r.p9,"sohranitx",9L);
uc (9L,31L,idatom,&V);
memcpy(V.r.p13,"L,false,NULL,",13L);
uc (13L,32L,atom,&V);
memcpy(V.r.p15,".nu,false,NULL,",15L);
uc (15L,33L,atom,&V);
memcpy(V.r.p13,"0L,true,NULL,",13L);
uc (13L,34L,atom,&V);
memcpy(V.r.p8,"0L,true,",8L);
uc (8L,35L,atom,&V);
memcpy(V.r.p4,".sa,",4L);
uc (4L,36L,atom,&V);
memcpy(V.r.p6,"acnst[",6L);
uc (6L,37L,atom,&V);
memcpy(V.r.p13,"],false,NULL,",13L);
uc (13L,38L,atom,&V);
memcpy(V.r.p4,"glob",4L);
uc (4L,39L,idatom,&V);
V.r.p1='_';
uc (1L,40L,idatom,&V);
memcpy(V.r.p3,"loc",3L);
uc (3L,41L,idatom,&V);
V.r.p1='/';
uc (1L,42L,atom,&V);
V.r.p1='%';
uc (1L,43L,atom,&V);
memcpy(V.r.p6,".sa=pl",6L);
uc (6L,44L,atom,&V);
memcpy(V.r.p2,"==",2L);
uc (2L,45L,atom,&V);
memcpy(V.r.p2,"!=",2L);
uc (2L,46L,atom,&V);
V.r.p1='L';
uc (1L,47L,idatom,&V);
memcpy(V.r.p3,".bo",3L);
uc (3L,48L,atom,&V);
memcpy(V.r.p2,"0L",2L);
uc (2L,49L,atom,&V);
memcpy(V.r.p7,"xcrga.h",7L);
uc (7L,50L,atom,&V);
memcpy(V.r.p6,"idatom",6L);
uc (6L,51L,idatom,&V);
memcpy(V.r.p4,"atom",4L);
uc (4L,52L,idatom,&V);
memcpy(V.r.p6,"xcrg.h",6L);
uc (6L,53L,atom,&V);
memcpy(V.r.p6,"v glob",6L);
uc (6L,54L,atom,&V);
memcpy(V.r.p8," rez1=pl",8L);
uc (8L,55L,atom,&V);
memcpy(V.r.p8," if ((pl",8L);
uc (8L,56L,atom,&V);
memcpy(V.r.p3," _L",3L);
uc (3L,57L,atom,&V);
memcpy(V.r.p9,"   if (pl",9L);
uc (9L,58L,atom,&V);
memcpy(V.r.p28,".ptrtype!=ptrtree ) next(&pl",28L);
uc (28L,59L,atom,&V);
memcpy(V.r.p25," else { rez1=NULL;goto _L",25L);
uc (25L,60L,atom,&V);
memcpy(V.r.p7,"rez1=pl",7L);
uc (7L,61L,atom,&V);
memcpy(V.r.p20,"success1=false;if(pl",20L);
uc (20L,62L,atom,&V);
memcpy(V.r.p17,".nel==0 ) goto _L",17L);
uc (17L,63L,atom,&V);
memcpy(V.r.p27,"        { rez1=NULL;goto _L",27L);
uc (27L,64L,atom,&V);
memcpy(V.r.p34,"{ success1=false;rez1=NULL;goto _L",34L);
uc (34L,65L,atom,&V);
memcpy(V.r.p21,"success1=true;rez1=pl",21L);
uc (21L,66L,atom,&V);
memcpy(V.r.p7," if( pl",7L);
uc (7L,67L,atom,&V);
memcpy(V.r.p23,"if( !success1 ) goto _L",23L);
uc (23L,68L,atom,&V);
memcpy(V.r.p3,"{pl",3L);
uc (3L,69L,idatom,&V);
memcpy(V.r.p2,"pl",2L);
uc (2L,70L,idatom,&V);
memcpy(V.r.p5,"],&pl",5L);
uc (5L,71L,atom,&V);
memcpy(V.r.p12,"success1=(pl",12L);
uc (12L,72L,atom,&V);
memcpy(V.r.p16,".cel==NULL)&&(pl",16L);
uc (16L,73L,atom,&V);
memcpy(V.r.p7,"goto _L",7L);
uc (7L,74L,atom,&V);
memcpy(V.r.p6,"number",6L);
uc (6L,75L,idatom,&V);
memcpy(V.r.p10,"varpat(&pl",10L);
uc (10L,76L,atom,&V);
memcpy(V.r.p7,"if( (pl",7L);
uc (7L,77L,atom,&V);
memcpy(V.r.p41,".ptrtype!=ptrtree) && success1 ) next(&pl",41L);
uc (41L,78L,atom,&V);
memcpy(V.r.p8,"listmain",8L);
uc (8L,79L,idatom,&V);
memcpy(V.r.p20,"(&rez1,&success1,&pl",20L);
uc (20L,80L,atom,&V);
memcpy(V.r.p26,"bltin1(&rez1,&success1,&pl",26L);
uc (26L,81L,atom,&V);
memcpy(V.r.p10,"implod(&pl",10L);
uc (10L,82L,atom,&V);
memcpy(V.r.p9,"explod(pl",9L);
uc (9L,83L,atom,&V);
memcpy(V.r.p3,"=pl",3L);
uc (3L,84L,atom,&V);
memcpy(V.r.p8,"while(pl",8L);
uc (8L,85L,atom,&V);
memcpy(V.r.p8,"treemain",8L);
uc (8L,86L,idatom,&V);
memcpy(V.r.p20,":if( ! success1 ) pl",20L);
uc (20L,87L,atom,&V);
memcpy(V.r.p6,"if( pl",6L);
uc (6L,88L,atom,&V);
memcpy(V.r.p34,".nel==0 ) { success1=false;goto _L",34L);
uc (34L,89L,atom,&V);
memcpy(V.r.p30,"   ;} else { rez1=NULL;goto _L",30L);
uc (30L,90L,atom,&V);
memcpy(V.r.p7,"if ((pl",7L);
uc (7L,91L,atom,&V);
memcpy(V.r.p7," if (pl",7L);
uc (7L,92L,atom,&V);
memcpy(V.r.p8,"next(&pl",8L);
uc (8L,93L,atom,&V);
  gets5(&cnst[ 94 ].sa, &x.sa); 
  WITH = x.smld;   
  WITH->dtype = listmain;  
  WITH->elnum = 1;         
  WITH->totalelnum = 1;    
  WITH->name = null_;      
  WITH->next = null_;}     
/* Local variables for acop: */     
struct LOC_acop {  allpacked r;} ;  
Local Void uc_(l, cn, dt, LINK)     
long l, cn; char dt;                
struct LOC_acop *LINK;              
{putatm(LINK->r.bl, l, &acnst[cn ]);}   
Static Void acop()     
{struct LOC_acop V;    
V.r.p1='T';
uc_(1L,1L,idatom,&V);
memcpy(V.r.p3,"ERR",3L);
uc_(3L,2L,idatom,&V);
V.r.p1='N';
uc_(1L,3L,idatom,&V);
V.r.p1='S';
uc_(1L,4L,idatom,&V);
memcpy(V.r.p3,"TAB",3L);
uc_(3L,5L,idatom,&V);
memcpy(V.r.p7,"RULENUM",7L);
uc_(7L,6L,idatom,&V);
memcpy(V.r.p6,"RIGLIB",6L);
uc_(6L,7L,idatom,&V);
memcpy(V.r.p7,"LASTVAR",7L);
uc_(7L,8L,idatom,&V);
memcpy(V.r.p5,"CONST",5L);
uc_(5L,9L,idatom,&V);
memcpy(V.r.p6,"ACONST",6L);
uc_(6L,10L,idatom,&V);
memcpy(V.r.p5,"FLCUR",5L);
uc_(5L,11L,idatom,&V);
memcpy(V.r.p2,"FL",2L);
uc_(2L,12L,idatom,&V);
V.r.p1='_';
uc_(1L,13L,idatom,&V);
memcpy(V.r.p6,"USESUN",6L);
uc_(6L,14L,idatom,&V);
memcpy(V.r.p3,"GEN",3L);
uc_(3L,15L,idatom,&V);
memcpy(V.r.p6,"USEVAR",6L);
uc_(6L,16L,idatom,&V);
memcpy(V.r.p3,"tip",3L);
uc_(3L,17L,idatom,&V);
memcpy(V.r.p3,"log",3L);
uc_(3L,18L,idatom,&V);
memcpy(V.r.p5,"mesto",5L);
uc_(5L,19L,idatom,&V);
memcpy(V.r.p6,"mesto2",6L);
uc_(6L,20L,idatom,&V);
memcpy(V.r.p5,"~islo",5L);
uc_(5L,21L,idatom,&V);
memcpy(V.r.p4,"ATOM",4L);
uc_(4L,22L,idatom,&V);
memcpy(V.r.p3,"NUM",3L);
uc_(3L,23L,idatom,&V);
memcpy(V.r.p4,"NULL",4L);
uc_(4L,24L,idatom,&V);
memcpy(V.r.p4,"CALL",4L);
uc_(4L,25L,idatom,&V);
memcpy(V.r.p4,"NAME",4L);
uc_(4L,26L,idatom,&V);
memcpy(V.r.p2,"PL",2L);
uc_(2L,27L,idatom,&V);
memcpy(V.r.p4,"FLAG",4L);
uc_(4L,28L,idatom,&V);
memcpy(V.r.p4,"ARGS",4L);
uc_(4L,29L,idatom,&V);
memcpy(V.r.p4,"OPEN",4L);
uc_(4L,30L,idatom,&V);
memcpy(V.r.p9,"FILE_SPEC",9L);
uc_(9L,31L,idatom,&V);
memcpy(V.r.p3,"PUT",3L);
uc_(3L,32L,idatom,&V);
memcpy(V.r.p3,"arg",3L);
uc_(3L,33L,idatom,&V);
V.r.p1='@';
uc_(1L,34L,atom,&V);
memcpy(V.r.p2,"<<",2L);
uc_(2L,35L,atom,&V);
memcpy(V.r.p5,"CLOSE",5L);
uc_(5L,36L,idatom,&V);
memcpy(V.r.p4,"LOOP",4L);
uc_(4L,37L,idatom,&V);
memcpy(V.r.p5,"LABEL",5L);
uc_(5L,38L,idatom,&V);
memcpy(V.r.p4,"BODY",4L);
uc_(4L,39L,idatom,&V);
memcpy(V.r.p6,"FORALL",6L);
uc_(6L,40L,idatom,&V);
memcpy(V.r.p3,"VAR",3L);
uc_(3L,41L,idatom,&V);
memcpy(V.r.p12,"BRANCHES_VAR",12L);
uc_(12L,42L,idatom,&V);
memcpy(V.r.p2,"IN",2L);
uc_(2L,43L,idatom,&V);
memcpy(V.r.p5,"BREAK",5L);
uc_(5L,44L,idatom,&V);
memcpy(V.r.p5,"BLTIN",5L);
uc_(5L,45L,idatom,&V);
memcpy(V.r.p3,"NOM",3L);
uc_(3L,46L,idatom,&V);
memcpy(V.r.p3,"ARG",3L);
uc_(3L,47L,idatom,&V);
memcpy(V.r.p7,"IMPLODE",7L);
uc_(7L,48L,idatom,&V);
memcpy(V.r.p7,"EXPLODE",7L);
uc_(7L,49L,idatom,&V);
memcpy(V.r.p8,"CALL_PAS",8L);
uc_(8L,50L,idatom,&V);
memcpy(V.r.p3,"VAL",3L);
uc_(3L,51L,idatom,&V);
memcpy(V.r.p4,"MAIN",4L);
uc_(4L,52L,idatom,&V);
memcpy(V.r.p6,"MAXWRK",6L);
uc_(6L,53L,idatom,&V);
memcpy(V.r.p5,"MAXPL",5L);
uc_(5L,54L,idatom,&V);
memcpy(V.r.p8,"MAX_FLAG",8L);
uc_(8L,55L,idatom,&V);
memcpy(V.r.p8,"MAXLABEL",8L);
uc_(8L,56L,idatom,&V);
memcpy(V.r.p6,"NOMAIN",6L);
uc_(6L,57L,idatom,&V);
memcpy(V.r.p8,"CONTINUE",8L);
uc_(8L,58L,idatom,&V);
V.r.p1='}';
uc_(1L,59L,idatom,&V);
V.r.p1='{';
uc_(1L,60L,idatom,&V);
memcpy(V.r.p6,"ONFAIL",6L);
uc_(6L,61L,idatom,&V);
V.r.p1='u';
uc_(1L,62L,idatom,&V);
memcpy(V.r.p5,"ASSGN",5L);
uc_(5L,63L,idatom,&V);
memcpy(V.r.p2,"op",2L);
uc_(2L,64L,idatom,&V);
memcpy(V.r.p4,"!!:=",4L);
uc_(4L,65L,atom,&V);
memcpy(V.r.p4,"++:=",4L);
uc_(4L,66L,atom,&V);
memcpy(V.r.p2,":=",2L);
uc_(2L,67L,atom,&V);
memcpy(V.r.p3,"lew",3L);
uc_(3L,68L,idatom,&V);
memcpy(V.r.p5,"INDEX",5L);
uc_(5L,69L,idatom,&V);
memcpy(V.r.p4,"ARG1",4L);
uc_(4L,70L,idatom,&V);
memcpy(V.r.p4,"ARG2",4L);
uc_(4L,71L,idatom,&V);
memcpy(V.r.p4,"praw",4L);
uc_(4L,72L,idatom,&V);
memcpy(V.r.p8,"SELECTOR",8L);
uc_(8L,73L,idatom,&V);
memcpy(V.r.p4,"!.:=",4L);
uc_(4L,74L,atom,&V);
memcpy(V.r.p3,"+:=",3L);
uc_(3L,75L,atom,&V);
memcpy(V.r.p7,"CONLIST",7L);
uc_(7L,76L,idatom,&V);
memcpy(V.r.p7,"CONTREE",7L);
uc_(7L,77L,idatom,&V);
memcpy(V.r.p8,"CONSTANT",8L);
uc_(8L,78L,idatom,&V);
memcpy(V.r.p4,"LAST",4L);
uc_(4L,79L,idatom,&V);
memcpy(V.r.p4,"RULE",4L);
uc_(4L,80L,idatom,&V);
memcpy(V.r.p3,"NOT",3L);
uc_(3L,81L,idatom,&V);
memcpy(V.r.p2,"!.",2L);
uc_(2L,82L,atom,&V);
memcpy(V.r.p2,"!!",2L);
uc_(2L,83L,atom,&V);
memcpy(V.r.p2,"++",2L);
uc_(2L,84L,atom,&V);
V.r.p1='+';
uc_(1L,85L,atom,&V);
V.r.p1='-';
uc_(1L,86L,atom,&V);
V.r.p1='*';
uc_(1L,87L,atom,&V);
memcpy(V.r.p3,"DIV",3L);
uc_(3L,88L,idatom,&V);
memcpy(V.r.p3,"MOD",3L);
uc_(3L,89L,idatom,&V);
V.r.p1='>';
uc_(1L,90L,atom,&V);
V.r.p1='<';
uc_(1L,91L,atom,&V);
memcpy(V.r.p2,">=",2L);
uc_(2L,92L,atom,&V);
memcpy(V.r.p2,"<=",2L);
uc_(2L,93L,atom,&V);
memcpy(V.r.p2,"$$",2L);
uc_(2L,94L,atom,&V);
memcpy(V.r.p2,"::",2L);
uc_(2L,95L,atom,&V);
memcpy(V.r.p4,"COPY",4L);
uc_(4L,96L,idatom,&V);
memcpy(V.r.p3,"AND",3L);
uc_(3L,97L,idatom,&V);
memcpy(V.r.p2,"OR",2L);
uc_(2L,98L,idatom,&V);
V.r.p1='=';
uc_(1L,99L,atom,&V);
memcpy(V.r.p2,"<>",2L);
uc_(2L,100L,atom,&V);
memcpy(V.r.p2,"FF",2L);
uc_(2L,101L,idatom,&V);
V.r.p1='\\';
uc_(1L,102L,atom,&V);
V.r.p1='\'';
uc_(1L,103L,atom,&V);
memcpy(V.r.p3,"DDD",3L);
uc_(3L,104L,idatom,&V);
memcpy(V.r.p2,"IF",2L);
uc_(2L,105L,idatom,&V);
memcpy(V.r.p8,"BRANCHES",8L);
uc_(8L,106L,idatom,&V);
memcpy(V.r.p4,"COND",4L);
uc_(4L,107L,idatom,&V);
memcpy(V.r.p5,"PRINT",5L);
uc_(5L,108L,idatom,&V);
memcpy(V.r.p4,"LOAD",4L);
uc_(4L,109L,idatom,&V);
memcpy(V.r.p6,"RETURN",6L);
uc_(6L,110L,idatom,&V);
memcpy(V.r.p4,"FAIL",4L);
uc_(4L,111L,idatom,&V);
memcpy(V.r.p3,"ATM",3L);
uc_(3L,112L,idatom,&V);
V.r.p1='I';
uc_(1L,113L,idatom,&V);
memcpy(V.r.p4,"LIST",4L);
uc_(4L,114L,idatom,&V);
memcpy(V.r.p7,"WORK_PL",7L);
uc_(7L,115L,idatom,&V);
memcpy(V.r.p8,"RULENAME",8L);
uc_(8L,116L,idatom,&V);
memcpy(V.r.p10,"BLTIN_NAME",10L);
uc_(10L,117L,idatom,&V);
memcpy(V.r.p3,"PAT",3L);
uc_(3L,118L,idatom,&V);
memcpy(V.r.p8,"STARLIST",8L);
uc_(8L,119L,idatom,&V);
memcpy(V.r.p8,"PLUSLIST",8L);
uc_(8L,120L,idatom,&V);
memcpy(V.r.p11,"DELIM_LABEL",11L);
uc_(11L,121L,idatom,&V);
memcpy(V.r.p9,"DELIMITER",9L);
uc_(9L,122L,idatom,&V);
memcpy(V.r.p4,"TREE",4L);
uc_(4L,123L,idatom,&V);
memcpy(V.r.p6,"FACULT",6L);
uc_(6L,124L,idatom,&V);
memcpy(V.r.p4,"SPAT",4L);
uc_(4L,125L,idatom,&V);
memcpy(V.r.p4,"VPAT",4L);
uc_(4L,126L,idatom,&V);
memcpy(V.r.p11,"ALTERNATIVE",11L);
uc_(11L,127L,idatom,&V);
memcpy(V.r.p12,"metka_uspeha",12L);
uc_(12L,128L,idatom,&V);
memcpy(V.r.p22,"nonatomic_branch_label",22L);
uc_(22L,129L,idatom,&V);
memcpy(V.r.p6,"atomic",6L);
uc_(6L,130L,idatom,&V);
} 
