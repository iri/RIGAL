 /* from glovar */

#define varnum          500   /* dlina steka lokalxnyh peremennyh */


a v[varnum];
/* stek lokalxnyh peremennyh */
long base;   /* 1-j swobodnyj |l-t steka perem.*/
long mybase;   /* baza dlq tek.aktiwn. prawila */

a vs[1];
/* stek lok.per. dlq sr-prostr.*/
/* vs[1] ukazywaet na s-kod rigal-programmy  */
/* adres glawnogo deskriptora spiska */
long sbase;   /* tek. dlina vs */

a teklexem;   /* tek.zna~enie $$ */
/*      ustanawl.w spatt i vpatt  */
boolean break_;   /* true -prerwatx ohwatyw. iteratiwnu` */
/*              konstrukci`  */
boolean continue_;   /* false -w prawile wypolnilsq */
/*                               return ili fail  */
boolean fail;   /* byl operator fail(=true) */
a atomt;   /* s-adres atoma t, sozd. w prolog */
boolean debugrule;   /* true-wkl`~ena trassirowka */
a atomrules, atomnorules;
/* adresa atomow rules,norules -sozd.w prolog */
/* ispolxz. w debug                           */

string80 run_param_array[10];
long run_param_cnt;


/* kod o{ibki */
extern Void err PP((long n));

extern Void getval PP((long *m));

/* kod o{ibki */
extern Void errstr PP((long n, Char *s));

/* usepasu  */
/*interpreter access*/
/* number of option */
/* pointer to argument list */
extern Void usepas PP((long n, ptr_ *pl, long *rez));

/* result */


/* from psu */

extern Void push PV();

extern Void pratom PP((long aa_));

/* adres nom.wstr.prawila */
extern Void prblt PP((long nn));

/* adres w sr-prostr. (<>0) deskr.atoma */
/*    ili peremennoj w {ablone    */
/* adres w st-prostr. (<>0) glawnogo */
/* fragmenta deskr.spiska */
extern boolean compnames PP((long p, long ld));

extern Void srchrule PP((long rd, ptr_ *pp));

extern Void srchrule1 PP((long rd, ptr_ *pp));

extern Void lastop PV();

/* from aru */
/* kod op. */
extern Void arithm PP((long op));

extern Void unmins PV();

extern Void selctr PV();

/* cequ(=), cnequ(<>) */
extern Void eqop PP((long o));

/* cequ(=), cnequ(<>) */
extern Void eqop1 PP((long o, long a1, long a2, boolean *rez1));

extern Void copyop PV();

extern Void indxop PV();

extern Void add PP((long *d, long *r));

/* from beiu */
extern Void concop PP((long *a1, long a2));

extern Void nameop PV();

extern Void explode PP((long kk, long *rez));

/* 1-j argument */
/* nomer wstr.prawila */
extern Void bltin PP((long *rez, boolean *success, ptr_ *pl, long n));

/* 1-j argument */
extern Void implode PP((ptr_ *pl, long *rez));

/* from ci */
extern Void rule PP((long *rez, boolean *success, ptr_ *pl, ptr_ *pp));

extern Void expression PP((ptr_ *c, long *rez));

extern Void pattern PP((long *rez, boolean *success, ptr_ *pl, ptr_ *p));

extern Void statement PP((long p, boolean *succ, long *rez));

extern Void contre PP((ptr_ *c));

extern Void objexpr PP((ptr_ *c, long *nvar, boolean *t));

/* tip operatora (specadres)*/
/* ssylka na deskriptor spiska
      operatora */
extern Void assgn PP((long ot, long p));

/* s-adres spiska operatora w
                      sr-prostranstwe*/
/* dlq wozwrata
                    neuspeha iz fail */
/* dlq wozwrata rezulxtata iz
            return */
extern Void cond PP((long p, boolean *succ, long *rez));

/* s-adres spiska operatora */
/* dlq wozwrata
                    neuspeha iz fail */
/* dlq wozwrata rez.iz return
            */
extern Void loop PP((long p, boolean *succ, long *rez));

extern Void inout PP((long p, long ot));

/* ukaz.na 1-` leksemu */
/* prodwigaetsq wpered */
/* adres |l-ta {ablona
      (alxternatiwa) */
extern Void alter PP((long *rez, boolean *success, ptr_ *pl, long p));

/* ukaz.tek.leksemu */
/* s-adres |l-ta {ablona */
/* (+...+) -true, (*...* )- false */
extern Void starlist PP((long *rez, boolean *success, ptr_ *pl, long p,
       boolean pluslist));

/* ukaz.na 1-` leksemu, */
/* prodwigaetsq wpered */
/* s-adres |l-ta {ablona */
extern Void facult PP((long *rez, boolean *success, ptr_ *pl, long p));

/* ukazatelx na deskriptor derewa leksem */
/* |l-t {ablona */
extern Void tree PP((long *parmrez, boolean *parmsuccess, ptr_ *parmpl,
         long p, boolean star));

/* ukazatelx na deskriptor spiska (leksema) */
/* ukazatelx na |l-t {ablona */
extern Void list PP((long *rez, boolean *success, ptr_ *pl, long p));

/* spat or vpat */
extern Void spatt PP((long *rez, boolean *success, ptr_ *pl, long p, long y));

/*===================*/
/* s-, ili v- {ablon */
/*===================*/
/* tek.leksema */
/* ukazatelx na spisok
       wetwi (prostogo prawila)*/
extern Void simple PP((long *rez, boolean *success, ptr_ *pl, long p));

/* na~alo konstruktora, a'13312. */
/* c prodw.wpered, rez. (. .) w  */
/* steke v[ ]                    */
extern Void conlst PP((ptr_ *c));

extern Void int11 PP((boolean debug, long code));

extern Void prolog PP((ptr_ *y, boolean debug, long code));

extern Void epilog PV();

