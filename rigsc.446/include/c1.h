/*#define xxx printf("lin=%d file=%s\n",__LINE__,__FILE__);*/
#define xxx ;
int g_argc;
Char ** g_argv;

typedef union v {
  a sa;   /* s -adres */
  longint nu;
  boolean bo;
  a at;   /* a -adres */
} v;


boolean debugrule;   /* to be used in future */
Char filebuf[2048];


/************ definitions in  c1 ***************/
extern Void er PP((long n));

/* kod o{ibki */
extern Void errstr PP((long n, Char *s));

extern Void crlist PP((long *l));
/* p2c: c1.z, line 471:
 * Note: Turbo Pascal conditional compilation directive was ignored [218] */

/*  sozdatx pustoj spisok  */
/*$ifdef xx*/
/*extern Void d PP((long r, long s));*/
extern Void d PP((long status_r ,char * rulename,long  rulenum,long  param,boolean  success));

extern Void d1 PP((long r));

/*$endif*/
extern Void addel PP((long sel, boolean not_atomic, long xsel, long ob, long *tr_));

extern long numval PP((long ob));

/* nomer wstr.prawila */
extern Void bltin PP((v *rr, boolean *success, long arg, long n));

/* a-adres  */
extern Void mkatom PP((long k, char atype, long *r));

/*************** c2 *****************/
extern Void concop PP((long *a1, long a2));

extern Void indxop PP((long xx, boolean isobject, long xa, long l, long *rez));

extern Void selop PP((long xn, boolean not_atomic, long xa, long tr_, long *rez));

extern Void setind PP((long xx, boolean isobject, long xa, long l, long rez));

extern Void setsel PP((long xn, boolean not_atomic, long xa, long tr_, long rez));

extern Void addnum PP((long *a1, long a2));

extern Void copyop PP((long ob, long *rez));


/* ******************* c3 ******************* */

#define max_digit       10


extern Void epilog PV();

extern Void prolog PV();

/* a-adr.imeni fajla*/
/* s-adr.wyw.obxekta*/
/* s now.stroki*/
/* s probelami*/
extern Void outxt PP((long fname, long arg, boolean nl, boolean blanks));

/* a-adr.imeni fajla*/
/* wywodimyj atom*/
/* s now.stroki*/
/* s probelami*/
extern Void outatm PP((long fname, Char *arg, boolean nl, boolean blanks));


/* a-adres imeni fajla*/
/* s-adr.*/
extern Void opn PP((long fname, long fspec));

/* 0-load,1 -save*/
extern Void loasav PP((v *p, long f, long paz));

extern Void explod PP((long kk, long *rez));

extern Void implod PP((ptr_ *pl, long *rez));

extern Void bltin1 PP((long *rez, boolean *success, ptr_ *pl, long n));

/* a-adr.*/
extern Void clsfil PP((long fname));

/**************** c4 ******************* */
/* cequ(=), cnequ(<>) */
extern boolean eqop PP((long o, long a1, long a2));

extern Void varpat PP((ptr_ *pl, char tip, long *rez, boolean *success));

extern Void atmpat PP((long aconval, ptr_ *pl, long *rez, boolean *success));

extern boolean eqnum PP((long m1, long n));

extern boolean eqatom PP((long m1, long atm));

/* kod operacii */
extern boolean compare PP((long op, long a1, long a2));

extern Void indxcon PP((xx, isobject, xa, l1, l2));

extern  Void indxaddtre PP((xx, isobject, xa, l1, l2));
