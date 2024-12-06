#include "globrig.h"
#include "define.h"
#include "defpage.h"
#include "ley.h"
#include "nef2.h"

/***************** nef2.inc ***************/
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


Void next(p)
ptr_ *p;
{
  /* refers to list/tree element */
  /*=======================================*/
  /* moves reference to next element  ,    */
  /* if no more elements then              */
  /* p.nel = 0                             */
  /*=======================================*/
  mpd x;
  a y, a1;


  if (p->nel != 0) {
    switch (p->ptrtype) {

    case ptrlist:
      a1 = p->UU.U1.curfragment;
      pointr(a1, &x.sa);   /* access fragment */
      switch (x.smld->dtype) {

      case listmain:
	if (p->nel < x.smld->elnum) {  /* may stay in this descriptor */
	  p->nel++;
	  p->cel = x.smld->elt[p->nel - 1];
	} else {
	  /* to next deskriptor */
	  y = x.smld->next;
	  if (y == 0) {   /* end of list */
	    p->nel = 0;
	    p->cel = 0;
	  } else {
	    pointr(y, &x.sa);
	    p->nel = 1;
	    p->cel = x.sfld->elt[0];
	    p->UU.U1.curfragment = y;
	  }
	}
	break;

      case listfragm:
	if (p->nel < x.sfld->elnum) {  /* may stay here */
	  p->nel++;
	  p->cel = x.sfld->elt[p->nel - 1];
	} else {
	  do {
	    y = x.sfld->next;
	    /* go next */
	    if (y == 0) {   /* end of list */
	      p->nel = 0;
	      p->cel = 0;
	    } else {
	      pointr(y, &x.sa);
	      if (x.sfld->elnum > 0) {
		p->nel = 1;
		p->cel = x.sfld->elt[0];
		p->UU.U1.curfragment = y;
		goto _L99;
	      }
	    }
	  } while (x.sfld->next != 0);   /* next.deskr. */
	}
	break;

      default:
	printf(" Internal error (NEXT-1)\n");
	break;
      }/* case */


      break;
      /* ptrlist */


    case ptrtree:   /*------  tree --------*/
      a1 = p->UU.U1.curfragment;
      pointr(a1, &x.sa);   /* access to fragment */
      switch (x.smtd->dtype) {

      case treemain:
	if (p->nel < x.smtd->arcnum) {  /* may stay here */
	  p->nel++;
	  p->cel = x.smtd->arc[p->nel - 1].elt;
	  p->UU.U1.arc = x.smtd->arc[p->nel - 1].arcname;
	} else {
	  /* go to next descriptor */
	  y = x.smtd->next;
	  if (y == 0) {   /* end of tree */
	    p->nel = 0;
	    p->cel = 0;
	  } else {
	    pointr(y, &x.sa);

	    while (x.sftd->next != 0 && x.sftd->arcnum == 0) {
	      y = x.sftd->next;
	      pointr(y, &x.sa);
	    }
	    if (x.sftd->arcnum > 0) {
	      p->nel = 1;
	      p->cel = x.sftd->arc[0].elt;
	      p->UU.U1.arc = x.sftd->arc[0].arcname;
	      p->UU.U1.curfragment = y;

	    } else {
	      p->cel = 0;
	      p->nel = 0;
	    }

	  }
	}
	break;

      case treefragm:
	if (p->nel < x.sftd->arcnum) {  /* may stay here */
	  p->nel++;
	  p->cel = x.sftd->arc[p->nel - 1].elt;
	  p->UU.U1.arc = x.sftd->arc[p->nel - 1].arcname;
	} else {
	  do {

	    y = x.sftd->next;
	    /* go to next */
	    if (y == 0) {   /* end of tree */
	      p->nel = 0;
	      p->cel = 0;
	    } else {
	      pointr(y, &x.sa);


	      while (x.sftd->next != 0 && x.sftd->arcnum == 0) {
		y = x.sftd->next;
		pointr(y, &x.sa);
	      }


	      if (x.sftd->arcnum > 0) {
		p->nel = 1;
		p->cel = x.sftd->arc[0].elt;
		p->UU.U1.arc = x.sftd->arc[0].arcname;
		p->UU.U1.curfragment = y;
		goto _L99;
	      }

	      p->cel = 0;
	      p->nel = 0;
	    }  /*else */


	  } while (x.sftd->next != 0);   /* else */
	}
	break;


      default:
	printf(" Internal error NEXT-2\n");
	break;
      }/* case */


      break;

      /* ptrtree */

    case packedlist:
      /* ----  list built-in in ptr  ---------- */
      if (p->nel == p->plistsize) {
	p->nel = 0;
	p->cel = null_;
      } else {
	p->nel++;
	/* nel <= plistsize <= 4 */
	p->cel = p->UU.plistelt[p->nel - 2];
      }
      break;


    default:
      printf(" Internal error NEXT-3 \n");

      break;
    }/* big case */
  }

_L99: ;   /*exit*/





}  /* next */




boolean eqatoms(p1, p2)
long p1, p2;
{
  /* atom address  */
  /* atom address */
  /*===================================*/
  /*  equivalence of two atoms         */
  /*===================================*/
  mpd s1, s2;

  if (p1 == p2)
    return true;
  else if (p1 != 0) {
    pointr(p1, &s1.sa);
    if (p2 != 0) {
      pointr(p2, &s2.sa);


      return (!memcmp(s1.sc8, s2.sc8, sizeof(atomdescriptor)) ||
	      (((1L << ((long)s1.sad->dtype)) &
		(((1L << ((long)keyword + 1)) - (1L << ((long)atom))) |
		 (1L << ((long)fatom)))) !=
	       0 &&
	       ((1L << ((long)s2.sad->dtype)) &
		(((1L << ((long)keyword + 1)) - (1L << ((long)atom))) |
		 (1L << ((long)fatom)))) !=
	       0 &&
	       s1.sad->name == s2.sad->name) ||
	      (s1.sad->dtype == tatom &&
	       s2.sad->dtype == tatom &&
	       s1.sad->name == s2.sad->name) ||
	      (s1.sad->dtype == number &&
	       s2.sad->dtype == number &&
	       s1.snd->val == s2.snd->val));
/* p2c: nef2.z, line 710: Note:
 * Line breaker spent 0.9+0.49 seconds, 5000 tries on line 811 [251] */
      /* added 20-jul-1989 in pc/at */



    } else  /* p2 = 0 */
      return (s1.smld->totalelnum == 0);

  } else if (p2 != 0) {
    pointr(p2, &s2.sa);
    return (s2.smld->totalelnum == 0);
  } else
    return true;


  /* p1 = 0 */
}  /* eqatoms */



Void first(p, pp)
long p;
ptr_ *pp;
{
  /* address of main descriptor of tree/list */
  /* result */
  /*=======================================*/
  /* sets first element of tree or list to pp */
  /* if p=null then pp.nel = 0            */
  /*=======================================*/
  mpd x;
  a y;


  pp->ptrtype = ptrlist;
  if (p == null_) {
    pp->nel = 0;
    pp->cel = 0;
  } else {  /*1*/
    pointr(p, &x.sa);


    if (x.smld->dtype == listmain)
      pp->ptrtype = ptrlist;
    else
      pp->ptrtype = ptrtree;
    switch (pp->ptrtype) {

    case ptrlist:
      /*----------- for lists -----------------*/
      if (x.smld->totalelnum == 0) {   /* empty list */
	pp->nel = 0;
	pp->cel = 0;
      }  /*2*/
      else {  /*2*/
	pp->nel = 1;
	pp->cel = x.smld->elt[0];
	pp->UU.U1.curfragment = p;
      }  /*2*/
      /*2*/
      break;


    case ptrtree:
      /*----------- for trees -----------------*/
      if (x.smtd->totalarcnum == 0) {  /* empty tree */
	pp->nel = 0;
	pp->cel = 0;
      } else {  /*2*/
	if (x.smtd->arcnum != 0) {
	  pp->nel = 1;
	  pp->cel = x.smtd->arc[0].elt;
	  pp->UU.U1.arc = x.smtd->arc[0].arcname;
	  pp->UU.U1.curfragment = p;
	} else {
	  while (x.sftd->next != 0 && x.sftd->arcnum == 0) {
	    y = x.sftd->next;
	    pointr(y, &x.sa);
	  }
	  pp->nel = 1;
	  pp->cel = x.sftd->arc[0].elt;
	  pp->UU.U1.arc = x.sftd->arc[0].arcname;
	  pp->UU.U1.curfragment = y;
	}
      }  /*2*/
      break;


    default:
      printf("Internal FIRST error (not agregate)\n");

      break;
    }/* case */
  }  /*1*/

  pp->UU.U1.mainadr = p;
}  /* first */


Void crlst(l)
long *l;
{
  /*  sozdatx pustoj spisok  */
  mpd x;

  gets5(l, &x.sa);
  x.smld->dtype = listmain;
  x.smld->lastfragm = *l;
}  /* crlst */


Void crlistfr(el, f)
long el, *f;
{
  /* s-adr. dob.|l-ta */
  /* s- adr.sozdannogo fragmenta */
  /*========================================*/
  /* sozdaet nowyj deskriptor fragmenta     */
  /* spiska i dobawlqet tuda el             */
  /*========================================*/
  mpd y;
  fragmlistdescriptor *WITH;

  gets5(f, &y.sa);
  WITH = y.sfld;
  WITH->dtype = listfragm;
  WITH->elnum = 1;
  WITH->elt[0] = el;
}  /* crlistfr */



Void crtree(t)
long *t;
{
  /* make empty tree */
  mpd x;

  gets5(t, &x.sa);
  x.smtd->dtype = treemain;
}  /* creatree */


Void crtreefr(sel, ob, frag)
long sel, ob, *frag;
{
  /* s-address of new tree fragment */
  /*===========================================*/
  /* makes new fragment of tree and adds       */
  /* to him an element                         */
  /*===========================================*/
  mpd y;
  fragmtreedescriptor *WITH;

  gets5(frag, &y.sa);
  WITH = y.sftd;   /* with */
  WITH->dtype = treefragm;
  WITH->arcnum = 1;
  WITH->arc[0].arcname = sel;
  WITH->arc[0].elt = ob;
}  /* crtreefr */


Void lconc(a1, a2)
long *a1, a2;
{
  /*==========================*/
  /* a1 - mainlist,           */
  /* a2 - l`boj obxekt        */
  /* ( a1 !. a2 ) -->  a1     */
  /*==========================*/
  /* wyhod */

  a l;   /* s-nomer glawn.deskr.spiska */
  a m;
  mpd x, y, z;
  mainlistdescriptor *WITH;
  fragmlistdescriptor *WITH1;

  if (*a1 == null_) {
    /* creates empty list */
    gets5(&l, &x.sa);
    x.smld->dtype = listmain;
    x.smld->lastfragm = l;
  } else {
    l = *a1;
    points(l, &x.sa);
  }
  /* fi */

  WITH = x.smld;
  if (WITH->dtype != listmain) {
    l = null_;
    goto _L1;
  }
  WITH->totalelnum++;
  if (WITH->lastfragm == l) {   /* ends on the same first descriptor */
    if (WITH->elnum == mainlistelnum) {
      gets5(&m, &y.sa);
      WITH1 = y.sfld;
      WITH1->dtype = listfragm;
      WITH1->elnum = 1;
      WITH1->elt[0] = a2;
      WITH->lastfragm = m;
      WITH->next = m;
    } else {
      WITH->elnum++;
      WITH->elt[WITH->elnum - 1] = a2;
    }
  } else {
    points(WITH->lastfragm, &z.sa);
    if (z.sfld->elnum == fragmlistelnum) {
      gets5(&m, &y.sa);
      WITH1 = y.sfld;
      WITH1->dtype = listfragm;
      WITH1->elnum = 1;
      WITH1->elt[0] = a2;
      z.sfld->next = m;
      points(l, &x.sa);
      WITH->lastfragm = m;
    } else {
      /* using with is danger here */
      z.sfld->elnum++;
      z.sfld->elt[z.sfld->elnum - 1] = a2;
    }
  }
_L1:
  *a1 = l;   /* nuvno, esli l sozdaw.zanowo */
}  /* lconc */


Void changeel(pp, adr)
ptr_ *pp;
long adr;
{
  /* where to change */
  /* change to adr */
  /* changes one element of list */
  mpd x;
  a a1;

  if (pp->ptrtype != ptrlist) {
    printf(" Internal error  (Changeel) ");
    return;
  }
  a1 = pp->UU.U1.curfragment;
  points(a1, &x.sa);
  if (x.sfld->dtype == listfragm)
    x.sfld->elt[pp->nel - 1] = adr;
  else
    x.smld->elt[pp->nel - 1] = adr;
  pp->cel = adr;
}


boolean plnum(sval, intval)
long sval, *intval;
{
  /* input - s-address*/
  /* output:long integer value */
  /* returns integer if it is list parameter; */
  mpd x;

  if (sval == 0)
    return false;
  else {
    pointr(sval, &x.sa);   /* access to atom in memory */
    if (x.snd->dtype != number)
      return false;
    else {
      *intval = x.snd->val;   /* access to number */
      return true;
    }
  }
}  /*plnum*/


Void mknumb(n, r)
long n, *r;
{
  mpd x;
  numberdescriptor *WITH;

  gets1(r, &x.sa);
  WITH = x.snd;   /* with */
  WITH->dtype = number;
  WITH->val = n;
}  /* mknumb */



Void addel3(tr_, sel, ob)
long *tr_, sel, ob;
{
  /* s-address of main tree descr*/
  /* selector, a-address */
  /* object*/
  /*===============================*/
  /* add element to tree           */
  /*  tr := tr ++ <. sel : ob .>   */
  /*===============================*/
  /* wyhod s tr:=l */
  /* wyhod bez tr:=l */

  a l;   /* s-adres glawnogo derewa */
  mpd x;   /* dostup k glawnomu deskr.derewa */
  mpd y;
  a n, npred;
  long i;
  maintreedescriptor *WITH;
  long FORLIM;
  fragmtreedescriptor *WITH1;



  if (*tr_ == null_)   /* sozdatx pustoe derewo */
    crtree(&l);
  else
    l = *tr_;
  pointr(l, &x.sa);
  /* dostup k glawn.fragmentu */
  if (x.smtd->dtype != treemain) {  /* tr ne derewo */
    l = null_;
    goto _L1;
  }
  if (ob == null_)   /* ni~ego ne menqem */
    goto _L2;

  if (x.smtd->totalarcnum == 0) {
    points(l, &x.sa);
    WITH = x.smtd;   /* with */
    WITH->totalarcnum = 1;
    WITH->arcnum = 1;
    WITH->arc[0].arcname = sel;
    WITH->arc[0].elt = ob;
    goto _L1;
  }

  WITH = x.smtd;   /* with */

  FORLIM = WITH->arcnum;
  /*======================*/
  /*  poisk sel  w l    */
  /*======================*/
  for (i = 0; i < FORLIM; i++) {
    if (WITH->arc[i].arcname == sel) {
      points(l, &y.sa);
      y.smtd->arc[i].elt = ob;
      goto _L1;
    }
  }
  npred = l;
  n = WITH->next;
  /* prodolvaem poisk w fragmentah */
  while (n != null_) {
    pointr(n, &y.sa);
    WITH1 = y.sftd;
    /* with */
    FORLIM = WITH1->arcnum;
    for (i = 0; i < FORLIM; i++) {
      if (WITH1->arc[i].arcname == sel) {
	points(n, &y.sa);
	y.sftd->arc[i].elt = ob;
	goto _L1;
      }
    }
    npred = n;
    n = WITH1->next;
  }  /* while */

  /*========================================*/
  /*  |l-ta w tr net.                       */
  /* w npred s-adres poslednego fragmenta , */
  /* nuvno dobawitx |l-t w konce            */
  /*========================================*/
  points(l, &x.sa);
  WITH = x.smtd;   /* with */

  WITH->totalarcnum++;
  if (WITH->arcnum != maintreearcnum) {
    /* dobawim tut-ve    */
    WITH->arcnum++;
    WITH->arc[WITH->arcnum - 1].arcname = sel;
    WITH->arc[WITH->arcnum - 1].elt = ob;
    goto _L1;
  }
  if (WITH->next == null_) {
    /*===========================================*/
    /* pricepim nowyj fragment k glawnomu fragm. */
    /* i pomestim tuda |l-t                      */
    /*===========================================*/
    crtreefr(sel, ob, &n);
    WITH->next = n;
    goto _L1;
  }
  /* dobawlqem |l-t w ne glawnom fragmente */
  points(npred, &x.sa);
  WITH1 = x.sftd;   /* with */
  if (WITH1->arcnum != fragmtreearcnum) {
    /* dobawim tut-ve */
    WITH1->arcnum++;
    WITH1->arc[WITH1->arcnum - 1].arcname = sel;
    WITH1->arc[WITH1->arcnum - 1].elt = ob;
  } else {  /* pricepim nowyj fragment */
    crtreefr(sel, ob, &n);
    WITH1->next = n;
  }
_L1:
  *tr_ = l;
_L2: ;
}  /* addel */


Void addtre(m, t2)
long *m, t2;
{
  /* 1-st tree */
  /* 2-nd tree */
  /*==============*/
  /* m ++:= t2    */
  /*==============*/
  /* wyhod */

  mpd x;
  long i;
  a n;
  maintreedescriptor mx;
  fragmtreedescriptor fx;


  if (t2 == null_)
    goto _L1;
  pointr(t2, &x.sa);
  if (x.smtd->dtype != treemain) {
    *m = null_;
    goto _L1;
  }
  /* cikl po t2, prisoedinqem |l-ty po odnomu */
  mx = *x.smtd;
  for (i = 0; i < mx.arcnum; i++)
    addel3(m, mx.arc[i].arcname, mx.arc[i].elt);
  n = mx.next;   /* with */
  /* prodolvaem w fragmentah */
  while (n != null_) {
    pointr(n, &x.sa);
    fx = *x.sftd;
    for (i = 0; i < fx.arcnum; i++)
      addel3(m, fx.arc[i].arcname, fx.arc[i].elt);
    n = fx.next;   /* with */
  }  /* while */
_L1: ;
}  /* addtre */


boolean compatom(op, adr1, adr2)
long op, adr1, adr2;
{
  /* op in 1..4   1 <  2 <=  3 >  4 >=
     compares valid a-adresses of two valid atoms of types
     atom idatom keyword  tatom */
  bl80 a1, a2;
  long i, l1, l2;

  if (adr1 == adr2)
    return (op == 2 || op == 4);
  else {
    pointa(adr1, a1, &l1);
    pointa(adr2, a2, &l2);


    i = 1;
_L1:
    if (i > l1)
      return (op <= 2);
    else if (i > l2)
      return (op >= 3);
    else if (a1[i - 1] > a2[i - 1])
      return (op >= 3);
    else if (a1[i - 1] < a2[i - 1])
      return (op <= 2);
    else {
      i++;
      goto _L1;
    }
  }
}


double take_fatom(a1)
long a1;
{
  bl80 a80_;
  long j;
  double *rre;

  pointa(a1, a80_, &j);
  rre = (double *)a80_;
  return (*rre);
}








/* End. */

