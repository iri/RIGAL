/***************** nef2.h ***************/
extern Void next PP((ptr_ *p));

extern boolean eqatoms PP((long p1, long p2));

extern Void first PP((long p, ptr_ *pp));

extern Void lconc PP((long *a1, long a2));

/* add an element*/
extern Void crlst PP((long *l));

/* s-adr. added element */
/* s- adr. new fragment */
extern Void crlistfr PP((long el, long *f));

extern Void crtree PP((long *t));

/* make empty tree */
/* s-address of new tree fragment */
extern Void crtreefr PP((long sel, long ob, long *frag));

/* where to change */
/* change to adr */
extern Void changeel PP((ptr_ *pp, long adr));

/* input - s-address */
/* output:long integer value */
extern boolean plnum PP((long sval, long *intval));

/* input - any number */
extern Void mknumb PP((long n, long *r));

/* output - new descriptor (number) */
/* s-address of main tree descr*/
/* selector, a-address */
/* object*/
extern Void addel3 PP((long *tr_, long sel, long ob));

/* 1-st tree */
/* 2-nd tree */
extern Void addtre PP((long *m, long t2));

extern boolean compatom PP((long op, long adr1, long adr2));

extern double take_fatom PP((long a1));

extern Void pout PP((long root));

extern Void pscr PP((long root));


