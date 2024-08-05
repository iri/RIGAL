#include "globrig.h"
#include "define.h"
#include "defpage.h"
#include "nef2.h"
#include "c1.h"


Void addnum(a1, a2)
long *a1, a2;
{
  /*===========*/
  /* a1 +:= a2 */
  /*===========*/
  mpd x;
  numberdescriptor *WITH;


  if (*a1 == null_) {
    mknumb(a2, a1);
    return;
  }
  points(*a1, &x.sa);
  /* changed from pointr 25-jul-1989
     due to change in vax 10-feb-1989 */
  if (x.snd->dtype != number) {
    er(9L);
    *a1 = null_;
  } else {
    WITH = x.snd;
    WITH->val += a2;   /* deleted sign */
  }
}  /* addnum*/


Void setsel(xn, not_atomic, xa, tr_, rez)
long xn;
boolean not_atomic;
long xa, tr_, rez;
{
  /*==============================================*/
  /* whod:                tr              x       */
  /* wyhod:         t.x  <- rez                   */
  /*==============================================*/
  /* wyhod */

  mpd x;
  a n;   /* imq selektora */
  a t;
  long i, j;
  maintreedescriptor *WITH;
  long FORLIM, FORLIM1;
  fragmtreedescriptor *WITH1;



  if (not_atomic) {
    if (xa == null_) {
      er(21L);
      goto _L1;
    }
    pointr(xa, &x.sa);
    if (x.sad->dtype != idatom) {
      er(22L);
      goto _L1;
    }
    n = x.sad->name;
  } else
    n = xn;
  if (tr_ == null_)
    goto _L1;
  /* rezulxtat =null */

  /* opredelitx tip tr */
  pointr(tr_, &x.sa);
  if (x.smtd->dtype != treemain) {   /* sna~ala w glawnom derewe */
    /* oibka */
    er(23L);
    goto _L1;
  }

  /*=====================================*/
  /* x  ukazywaet na glawn.deskr. derewa */
  /*  tr na deskr.glawn. derewa          */
  /*=====================================*/
  /* poisk selektora n w derewe x */

  WITH = x.smtd;   /* with */
  FORLIM = WITH->arcnum;
  for (i = 1; i <= FORLIM; i++) {
    if (WITH->arc[i - 1].arcname == n) {   /* na{li */
      points(tr_, &x.sa);
      WITH->arc[i - 1].elt = rez;
      if (rez == null_) {
	FORLIM1 = WITH->arcnum;
	for (j = i; j < FORLIM1; j++)
	  WITH->arc[j - 1] = WITH->arc[j];
	WITH->arcnum--;
	WITH->totalarcnum--;
      }
      goto _L1;
    }
  }
  t = WITH->next;
  /* prodolvaem poisk w fragmentah */
  while (t != null_) {
    pointr(t, &x.sa);
    WITH1 = x.sftd;
    FORLIM = WITH1->arcnum;
    for (i = 1; i <= FORLIM; i++) {
      if (WITH1->arc[i - 1].arcname == n) {   /* na{li */
	points(t, &x.sa);
	WITH1->arc[i - 1].elt = rez;
	if (rez == null_) {
	  FORLIM1 = WITH1->arcnum;
	  for (j = i; j < FORLIM1; j++)
	    WITH1->arc[j - 1] = WITH1->arc[j];
	  WITH1->arcnum--;
	  points(tr_, &x.sa);
	  WITH = x.smtd;
	  WITH->totalarcnum--;
	}
	goto _L1;
      }
    }
    t = WITH1->next;   /* with */
  }  /* while */

  /* ne nali !  */
  er(8L);
_L1: ;
}  /* setsel */


Void setind(xx, isobject, xa, l, rez)
long xx;
boolean isobject;
long xa, l, rez;
{
  /*==============================================*/
  /* whod:        l               xx              */
  /* wyhod:       l[ xx ] := rez                  */
  /*                                              */
  /*  l[ -1 ]  - poslednij |l-t spiska            */
  /*  l[ -2 ]  - predposlednij |l-t spiska  ...   */
  /*==============================================*/
  /* wyhod */

  mpd y;
  long k, n;
  a t;



  if (isobject) {
    n = numval(xa);
    if (n == 0) {
      er(3L);
      goto _L1;
    }
  } else
    n = xx;
  /* w n -zna~enie indeksa */
  if (l == null_)   /* rezulxtat= null */
    goto _L1;
  /* opredelitx tip l */
  pointr(l, &y.sa);
  if (y.smld->dtype != listmain) {
    er(4L);
    goto _L1;
  }
  /*============================================*/
  /* y ukazywaet na deskriptor glawnogo spiska  */
  /*============================================*/
  /* wy~islenie l[x] */
  k = y.smld->totalelnum;
  if (n < 0)
    n += k + 1;
  if (n < 1 || n > k) {
    er(5L);
    /*  indeks wne spiska */
    goto _L1;
  }
  /*================================*/
  /* poisk |l-ta spiska             */
  /*================================*/
  if (n <= y.smld->elnum) {
    points(l, &y.sa);
    y.smld->elt[n - 1] = rez;
  } else {
    n -= y.smld->elnum;
    t = y.smld->next;
    pointr(t, &y.sa);
    while (n > y.sfld->elnum) {
      n -= y.sfld->elnum;
      t = y.sfld->next;
      pointr(t, &y.sa);
    }
    points(t, &y.sa);
    y.sfld->elt[n - 1] = rez;
  }
_L1: ;
}  /* setind */


Void selop(xn, not_atomic, xa, tr_, rez)
long xn;
boolean not_atomic;
long xa, tr_, *rez;
{
  /*==============================================*/
  /* whod:                tr              x       */
  /* wyhod:         t.x  -> rez                   */
  /*==============================================*/
  /* wyhod */

  mpd x;
  a n;   /* imq selektora */
  a t;
  long i;
  maintreedescriptor *WITH;
  long FORLIM;
  fragmtreedescriptor *WITH1;


  *rez = null_;
  if (not_atomic) {
    if (xa == null_) {
      er(21L);
      goto _L1;
    }
    pointr(xa, &x.sa);
    if (x.sad->dtype != idatom) {
      er(22L);
      goto _L1;
    }
    n = x.sad->name;
  } else
    n = xn;
  if (tr_ == null_)
    goto _L1;
  /* rezulxtat =null */

  /* opredelitx tip tr */
  pointr(tr_, &x.sa);
  if (x.smtd->dtype != treemain) {   /* sna~ala w glawnom derewe */
    /* o{ibka */
    er(23L);
    goto _L1;
  }

  /*=====================================*/
  /* x  ukazywaet na glawn.deskr. derewa */
  /*  tr na deskr.glawn. derewa          */
  /*=====================================*/
  /* poisk selektora n w derewe x */

  WITH = x.smtd;   /* with */
  FORLIM = WITH->arcnum;
  for (i = 0; i < FORLIM; i++) {
    if (WITH->arc[i].arcname == n) {   /* na{li */
      *rez = WITH->arc[i].elt;
      goto _L1;
    }
  }
  t = WITH->next;
  /* prodolvaem poisk w fragmentah */
  while (t != null_) {
    pointr(t, &x.sa);
    WITH1 = x.sftd;
    FORLIM = WITH1->arcnum;
    for (i = 0; i < FORLIM; i++) {
      if (WITH1->arc[i].arcname == n) {   /* na{li */
	*rez = WITH1->arc[i].elt;
	goto _L1;
      }
    }
    t = WITH1->next;   /* with */
  }  /* while */

  /* ne na{li !  */
_L1: ;
}  /* selop */


Void indxop(xx, isobject, xa, l, rez)
long xx;
boolean isobject;
long xa, l, *rez;
{
  /*==============================================*/
  /* whod:        l               xx              */
  /* wyhod:       l[ xx ]                         */
  /*                                              */
  /*  l[ -1 ]  - poslednij |l-t spiska            */
  /*  l[ -2 ]  - predposlednij |l-t spiska  ...   */
  /*==============================================*/
  /* wyhod */

  mpd y;
  long k, n;
  a t;



  *rez = null_;
  if (isobject) {
    n = numval(xa);
    if (n == 0) {
      er(3L);
      goto _L1;
    }
  } else
    n = xx;
  /* w n -zna~enie indeksa */
  if (l == null_)   /* rezulxtat= null */
    goto _L1;
  /* opredelitx tip l */
  pointr(l, &y.sa);
  if (y.smld->dtype != listmain) {
    er(4L);
    goto _L1;
  }
  /*============================================*/
  /* y ukazywaet na deskriptor glawnogo spiska  */
  /*============================================*/
  /* wy~islenie l[x] */
  k = y.smld->totalelnum;
  if (n < 0)
    n += k + 1;
  if (n < 1 || n > k) {
    er(5L);
    /*  indeks wne spiska */
    goto _L1;
  }
  /*================================*/
  /* poisk |l-ta spiska             */
  /*================================*/
  if (n <= y.smld->elnum)
    *rez = y.smld->elt[n - 1];
  else {
    n -= y.smld->elnum;
    t = y.smld->next;
    pointr(t, &y.sa);
    while (n > y.sfld->elnum) {
      n -= y.sfld->elnum;
      t = y.sfld->next;
      pointr(t, &y.sa);
    }
    *rez = y.sfld->elt[n - 1];
  }
  /* w rez rezulxtat = l [ x ]  */
_L1: ;
}  /* indxop */


Void concop(a1, a2)
long *a1, a2;
{
  /*======================================*/
  /* operaciq  a1 !! a2                   */
  /*       ( a1 !! a2 ) -> a1             */
  /*======================================*/
  /* wyhod */

  mpd x;
  ptr_ p1;
  a l;



  l = *a1;
  if (a2 == null_) {
    if (l == null_)
      goto _L99;
    else {
      pointr(l, &x.sa);
      if (x.smld->dtype == listmain)
	goto _L99;
      else {
	l = null_;
	goto _L99;
      }
    }
  }
  pointr(a2, &x.sa);
  if (x.smld->dtype != listmain) {
    l = null_;
    goto _L99;
  }
  if (l != null_) {
    pointr(l, &x.sa);
    if (x.smld->dtype != listmain) {
      l = null_;
      goto _L99;
    }
  }
  first(a2, &p1);
  while (p1.nel != 0) {
    lconc(&l, p1.cel);
    next(&p1);
  }
_L99:
  *a1 = l;
}  /* concop */


Void copyop(ob, rez)
long ob, *rez;
{
  /*==========================*/
  /*whod:        ob           */
  /*wyhod:  copy( a )-> rez   */
  /*==========================*/
  /* wyhod */

  long k;
  mpd x, y, z;
  a r1, r2, r3;



  if (ob == null_) {
    *rez = null_;
    goto _L99;
  }
  pointr(ob, &x.sa);
  switch (x.sad->dtype) {

  case atom:
  case idatom:
  case keyword:
  case number:
  case tatom:
  case fatom:
  case variable:
  case idvariable:
  case nvariable:
  case fvariable:
  case spec:   /* coord removed */
    gets1(&r1, &y.sa);
    *y.sad = *x.sad;
    *rez = r1;
    break;

  case rulename:
  case object_d:
    gets2(&r1, &y.sa);
    *y.srd = *x.srd;
    *rez = r1;
    break;

  case listmain:
  case treemain:
    gets5(&r1, &y.sa);
    /* skopirowatx glawnyj deskriptor */
    *y.smld = *x.smld;
    *rez = r1;
    r2 = x.smld->next;
    while (r2 != null_) {
      pointr(r2, &x.sa);
      gets5(&r3, &z.sa);
      *z.smld = *x.smld;
      points(r1, &y.sa);
      y.smld->next = r3;
      r1 = r3;
      r2 = z.smld->next;
    }  /* while */
    break;

  }/* case */
_L99: ;   /* wyhod */
}  /* copyop */





/* End. */
