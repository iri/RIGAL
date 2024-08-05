#include "globrig.h"
#include "define.h"
#include "defpage.h"
#include "nef2.h"
#include "c1.h"

boolean eqatom(m1, atm)
long m1, atm;
{
  mpd x;
  atomdescriptor *WITH;

  if (m1 == null_)
    return false;
  else {
    pointr(m1, &x.sa);
    WITH = x.sad;
    return (((1L << ((long)WITH->dtype)) & (((1L << ((long)keyword + 1)) -
		 (1L << ((long)atom))) | (1L << ((long)fatom)))) != 0 &&
	    WITH->name == atm);
  }
}


Void varpat(pl, tip, rez, success)
ptr_ *pl;
char tip;
long *rez;
boolean *success;
{
  mpd x;
  atomdescriptor *WITH;


  *rez = pl->cel;
  if (pl->nel == 0 || *rez == null_)
    *success = false;
  else {
    pointr(*rez, &x.sa);
    WITH = x.sad;
    *success = (WITH->dtype == tip);
  }
  if (*success) {
    if (pl->ptrtype != ptrtree)
      next(pl);
  } else
    *rez = null_;
}  /* varpat */


Void atmpat(aconval, pl, rez, success)
long aconval;
ptr_ *pl;
long *rez;
boolean *success;
{
  mpd x;
  atomdescriptor *WITH;


  *rez = pl->cel;
  if (pl->nel == 0 || *rez == null_)
    *success = false;
  else {
    pointr(*rez, &x.sa);
    WITH = x.sad;
    *success = ((WITH->dtype == atom || WITH->dtype == idatom ||
		 WITH->dtype == keyword ||
		 WITH->dtype == fatom) && WITH->name == aconval);
    /* tatom removed from this set 25-july 1989 */
  }
  if (*success) {
    if (pl->ptrtype != ptrtree)
      next(pl);
  } else
    *rez = null_;
}  /* atmpat */



boolean eqnum(m1, n)
long m1, n;
{
  mpd x;
  numberdescriptor *WITH;


  if (m1 == null_)
    return false;
  else {
    pointr(m1, &x.sa);
    WITH = x.snd;
    return (WITH->dtype == number && WITH->val == n);
  }
}  /* eqnum */



boolean eqop(o, a1, a2)
long o, a1, a2;
{
  /* cequ(=), cnequ(<>) */
  /*====================================*/
  /*   rawenstwo/ nerawenstwo obxektow  */
  /* whod: a1             a2            */
  /* wyhod:  true / false w rez1        */
  /*====================================*/
  /*wyhod */

  mpd x, y;
  boolean rez;
  ptr_ px, py;



  rez = true;
  if (a2 == null_) {
    if (a1 == null_)
      goto _L1;
    else {
      pointr(a1, &x.sa);
      rez = (((1L << ((long)x.smld->dtype)) &
	      ((1L << ((long)listmain)) | (1L << ((long)treemain)))) != 0 &&
	     x.smld->totalelnum == 0);
      goto _L1;
    }
  }  /* a2 =null */
  pointr(a2, &x.sa);
  if (a1 == null_) {
    rez = (((1L << ((long)x.smld->dtype)) &
	    ((1L << ((long)listmain)) | (1L << ((long)treemain)))) != 0 &&
	   x.smld->totalelnum == 0);
    goto _L1;
  }
  pointr(a1, &y.sa);
  /* oba ne null */
  switch (x.smld->dtype) {

  case variable:
  case idvariable:
  case nvariable:
  case fvariable:
  case spec:
  case rulename:   /* coord removed */
    rez = (memcmp(x.sc8, y.sc8, sizeof(atomdescriptor)) == 0);
    break;

  case number:
    rez = (y.snd->dtype == number && x.snd->val == y.snd->val);
    break;


  case atom:
  case idatom:
  case keyword:
  case tatom:
  case fatom:
    rez = (((1L << ((long)y.sad->dtype)) &
	    (((1L << ((long)keyword + 1)) - (1L << ((long)atom))) |
	     (1L << ((long)tatom)) | (1L << ((long)fatom)))) != 0 &&
	   x.sad->name == y.sad->name);
    break;

  case listmain:
    rez = (x.smld->totalelnum == y.smld->totalelnum &&
	   y.smld->dtype == listmain);
    if (rez) {
      first(a1, &px);
      first(a2, &py);
      while (rez && px.nel != 0) {
	rez = eqop(o, px.cel, py.cel);
	next(&px);
	next(&py);
      }  /* while */
    }
    break;

  case treemain:
    rez = (x.smtd->totalarcnum == y.smtd->totalarcnum &&
	   y.smtd->dtype == treemain);
    if (rez) {
      first(a1, &px);
      while (rez && px.nel != 0) {
	first(a2, &py);
	while (py.nel != 0 && px.UU.U1.arc != py.UU.U1.arc)
	  next(&py);
	if (py.nel == 0)
	  rez = false;
	else
	  rez = eqop(o, px.cel, py.cel);
	next(&px);
      }  /* while */
    }
    break;
  }/* case */
_L1:
  return rez;

  /* a2 <>null */
}  /* eqop */


/* c4.pas */

boolean compare(op, a1, a2)
long op, a1, a2;
{
  /* kod operacii */
  /*=======================*/
  /* operacii              */
  /*      > < >= <=        */
  /* whod:                 */
  /*         a1   a2       */
  /* wyhod:                */
  /*           a1 op a2    */
  /*=======================*/
  boolean Result;
  /* wyhod */

  mpd x;
  longint n[2];   /* changed 17-nov-90 */
  aa a_adr[2];
  char dts[2];


  Result = false;

  if (a1 == null_) {
    n[0] = 0;
    dts[0] = dummy;
  } else {
    pointr(a1, &x.sa);
    n[0] = x.snd->val;
    dts[0] = x.snd->dtype;
    a_adr[0] = x.sad->name;
  }

  if (a2 == null_) {
    n[1] = 0;
    dts[1] = dummy;
  } else {
    pointr(a2, &x.sa);
    n[1] = x.snd->val;
    dts[1] = x.snd->dtype;
    a_adr[1] = x.sad->name;
  }

  if ((dts[0] == dummy || dts[0] == number) &&
      (dts[1] == dummy || dts[1] == number)) {
    Result = (op == 3 && n[0] > n[1] || op == 1 && n[0] < n[1] ||
	      op == 4 && n[0] >= n[1] || op == 2 && n[0] <= n[1]);

  } else {
    if (((1L << ((long)dts[0])) & ((1L << ((long)atom)) | (1L << ((long)idatom)) |
	   (1L << ((long)keyword)) | (1L << ((long)tatom)))) != 0) {
      if (((1L << ((long)dts[1])) &
	   ((1L << ((long)atom)) | (1L << ((long)idatom)) |
	    (1L << ((long)keyword)) | (1L << ((long)tatom)))) != 0) {
	Result = compatom(op, a_adr[0], a_adr[1]);

      } else {
	if (dts[1] == dummy)
	  Result = (op > 2);
      }

    } else {
      if (dts[0] == dummy &&
	  ((1L << ((long)dts[1])) & ((1L << ((long)atom)) | (1L << ((long)idatom)) |
	     (1L << ((long)keyword)) | (1L << ((long)tatom)))) != 0)
	Result = (op < 3);
    }
  }




_L33:
  return Result;


}  /* compare */



void indxcon(xx, isobject, xa, l1, l2)
long xx;
boolean isobject;
long xa, l1,l2;
/* l1[xx]!!:=l2 */
{ a wrk;
    indxop(xx, isobject, xa, l1, &wrk);
    if (wrk==NULL) {
                       concop(& wrk,l2);
                       setind(xx, isobject, xa, l1,  wrk);
                   }
    else {
             concop(& wrk,l2);
             if (wrk==NULL) {
                                setind(xx, isobject, xa, l1, NULL);
                            }
         }
}

void indxaddtre(xx, isobject, xa, l1, l2)
long xx;
boolean isobject;
long xa, l1,l2;
/* l1[xx]!!:=l2 */
{ a wrk;
    indxop(xx, isobject, xa, l1, &wrk);
    if (wrk==NULL) {
                       addtre(& wrk,l2);
                       setind(xx, isobject, xa, l1,  wrk);
                   }
    else {
             addtre(& wrk,l2);
             if (wrk==NULL) {
                                setind(xx, isobject, xa, l1, NULL);
                            }
         }
}


/* End. */
