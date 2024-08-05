#include "globrig.h"
#include "define.h"
#include "defpage.h"
#include "nef2.h"
 
#include "cim.h"

Void alter(rez, success, pl, p)
long *rez;
boolean *success;
ptr_ *pl;
long p;
{
  /* ukaz.na 1-` leksemu */
  /* prodwigaetsq wpered */
  /* adres |l-ta {ablona
        (alxternatiwa) */
  /*=================================*/
  /*  {ablon  ( a1 ! a2 ! ... ! an ) */
  /*=================================*/
  /* wyhod */

  a rez1;
  boolean success1;
  ptr_ pp;   /* tek.|l-t {ablona */
  ptr_ pl1;   /* tek. leksema */
  boolean ispattern;

  /* true - tek.|l-t pp - {ablon, */
  /*  false - operator */


  /*==================================*/
  /* posle uspeha alter pl ukazywaet  */
  /* na sled. leksemu                 */
  /*==================================*/
  rez1 = null_;
  success1 = true;
  ispattern = true;
  first(p, &pp);   /* wojti w spisok {ablonow */
  /*  osnownoj cikl */
  while (continue_ && pp.nel != 0 && !fail) {
    pl1 = *pl;
    rez1 = null_;
    success1 = true;
    while (pp.nel != 0 && pp.cel != adelim && success1 && continue_) {
      if (pp.cel == opdelim)
	ispattern = !ispattern;
      else if (ispattern)
	pattern(&rez1, &success1, &pl1, &pp);
      else
	statement(pp.cel, &success1, &rez1);
      next(&pp);
    }  /* while */
    if (success1 || !continue_) {
      goto _L1;
      /* normalxnyj wyhod iz cikla */
    }
    while (pp.cel != adelim && pp.nel != 0)
      next(&pp);
    next(&pp);
  }  /* while */
  /* esli popali s`da, to ni odna wetwx ne uspe{na */
  success1 = false;
  rez1 = null_;
_L1:
  *rez = rez1;
  *success = success1;
  if (success1)
    *pl = pl1;

  /* prognatx pp do adelim ili do konca */
}  /* alter */


Void assgn(ot, p)
long ot, p;
{
  /* tip operatora (specadres)*/
  /* ssylka na deskriptor spiska
        operatora */
  /* wyhod */

  mpd x, y, z;
  ptr_ c;   /* tek.|l_t spiska operatora */
  long nvar;
  a rr;   /* rez.praw. ~asti := */
  boolean t;   /* lew.~astx w st-prostr.*/
  a m, xfrag, xglavn;
  long i, xnel;   /* :: otli~ie ot inter/rsx !!!!! */
  fragmtreedescriptor *WITH;
  long FORLIM;
  maintreedescriptor *WITH1;

  first(p, &c);   /* c na na~alo wyrav.lew.~asti */
  objexpr(&c, &nvar, &t);
  /*======================================*/
  /* wy~islitx lew. ~astx, w nvar nomer   */
  /* per. w steke , gde nahoditsq ssylka  */
  /* na objdescriptor(st-prostr.)(t=true) */
  /*               ili                    */
  /* sam nomer peremennoj w prawile       */
  /* ( t=false)                           */
  /*======================================*/
  next(&c);   /* na na~alo prawoj ~asti */
  expression(&c, &rr);   /* wy~islitx praw.~astx */
  /*            w rr ssylka na rezulxtat */
  if (t) {
    if (v[nvar - 1] == null_) {
      err(8L);
      /* null w lewoj ~asti := */
      goto _L1;
    }
    pointr(v[nvar - 1], &x.sa);
  }
  /* polu~itx deskriptor lew.~asti */
  if (t && !x.sobj->variable_) {
    /* ~to-to menqem w strukturah */
    xfrag = x.sobj->fragmorvar;
    xnel = x.sobj->nel;   /* :: !! otli~ie ot inter/rsx !!!!! */
    xglavn = x.sobj->glavn;
    /* zapomnim, tak kak cass2..cass5 lista`t s-prostr.*/
    points(xfrag, &y.sa);
    /* posmotrim deskr.struktury */
    if (((1L << ((long)y.smld->dtype)) &
	 ((1L << ((long)listfragm + 1)) - (1L << ((long)listmain)))) != 0) {
      /* lew.~astx estx spisok  */
      if (ot == cass1)   /* prosto := */
	y.sfld->elt[xnel - 1] = rr;
      else {
	m = y.sfld->elt[xnel - 1];
	if (ot == cass2)
	  add(&m, &rr);
	else if (ot == cass3)
	  addtre(&m, rr);
	else if (ot == cass4)
	  concop(&m, rr);
	else if (ot == cass5)
	  lconc(&m, rr);
	points(xfrag, &y.sa);
	/* s-prostr. mogli
	                          prolistatx */
	y.sfld->elt[xnel - 1] = m;
      }
    } else if (((1L << ((long)y.smtd->dtype)) &
		((1L << ((long)treefragm + 1)) - (1L << ((long)treemain)))) !=
	       0) {
      /* lew.~astx  estx derewo  */
      if (ot == cass1) {   /* prosto := */
	if (y.sftd->dtype == treefragm)
	  y.sftd->arc[xnel - 1].elt = rr;
	else
	  y.smtd->arc[xnel - 1].elt = rr;
      } else {
	if (y.sftd->dtype == treefragm)
	  m = y.sftd->arc[xnel - 1].elt;
	else
	  m = y.smtd->arc[xnel - 1].elt;
	if (ot == cass2)
	  add(&m, &rr);
	else if (ot == cass3)
	  addtre(&m, rr);
	else if (ot == cass4)
	  concop(&m, rr);
	else if (ot == cass5)
	  lconc(&m, rr);
	points(xfrag, &y.sa);
	/* s-prostr.mogli
	                          prolistatx */
	if (y.sftd->dtype == treefragm)
	  y.sftd->arc[xnel - 1].elt = m;
	else
	  y.smtd->arc[xnel - 1].elt = m;
      }
      if (y.sftd->dtype == treefragm) {
	WITH = y.sftd;
	if (WITH->arc[xnel - 1].elt == null_) {   /* with */
	  FORLIM = WITH->arcnum;
	  /* umenx{itx ~islo |l-tow derewa */
	  /* sdwinem |l-ty w fragmente */
	  for (i = xnel; i < FORLIM; i++)
	    WITH->arc[i - 1] = WITH->arc[i];
	  WITH->arcnum--;
	  points(xglavn, &z.sa);
	  z.smtd->totalarcnum--;
	}
      } else {
	WITH1 = y.smtd;
	if (WITH1->arc[xnel - 1].elt == null_) {   /* with */
	  FORLIM = WITH1->arcnum;
	  /* umenx{itx ~islo |l-tow derewa */
	  /* sdwinem |l-ty w fragmente */
	  for (i = xnel; i < FORLIM; i++)
	    WITH1->arc[i - 1] = WITH1->arc[i];
	  WITH1->arcnum--;
	  WITH1->totalarcnum--;
	}
      }
    } else {
      /* o{ibka, popytka priswoitx w strukturu , k-q  */
      /* ne qwl. ni spiskom ni derewom                */
      err(2L);
      goto _L1;
    }
  }  /* prisw. w strukture */
  else {  /* prisw.peremennoj */
    if (t) {
      /* lew.~astx object */
      /* if x.sobj^.variable then */
      nvar = x.sobj->fragmorvar;
    } else  /* prosto perem. w lew.~asti */
      nvar += mybase;
    if (ot == cass1)
      v[nvar - 1] = rr;
    else if (ot == cass2)
      add(&v[nvar - 1], &rr);
    else if (ot == cass3)
      addtre(&v[nvar - 1], rr);
    else if (ot == cass4)
      concop(&v[nvar - 1], rr);
    else if (ot == cass5)
      lconc(&v[nvar - 1], rr);
  }  /* prisw.peremennoj */
_L1:
  if (t)   /* oswoboditx w steke per. */
    base--;
}  /* assgn */


Void cond(p, succ, rez)
long p;
boolean *succ;
long *rez;
{
  /* s-adres spiska operatora w
                        sr-prostranstwe*/
  /* dlq wozwrata
                      neuspeha iz fail */
  /* dlq wozwrata rezulxtata iz
              return */
  /*==================================================*/
  /* operator  if c1 -> s1 ; elseif c2 -> s2 ; ... fi */
  /*==================================================*/
  /* wyhod */

  ptr_ pp;
  a r;


  first(p, &pp);   /* wojti w spisok operatora */
  while (pp.nel != 0) {
    expression(&pp, &r);
    /* razdelitelx proglo~en w expression */
    if (r != null_) {
      while (pp.cel != 9216 && pp.nel != 0 && !break_ && !fail && continue_)
      {   /* added 23.10.89 */
	statement(pp.cel, succ, rez);
	next(&pp);
      }  /* while*/
      goto _L1;
    }
    do {
      next(&pp);
    } while (pp.cel != 9216 && pp.nel != 0);
    next(&pp);
  }  /* while */
_L1: ;
}  /* cond */


Void conlst(c)
ptr_ *c;
{
  /* na~alo konstruktora, a'13312. */
  /* c prodw.wpered, rez. (. .) w  */
  /* steke v[ ]                    */

  /*==================================*/
  /* konstruktor  (. e1 e2 ... en .)  */
  /*==================================*/
  /* wyhod */

  a x;   /* rezulxtat */

  v[base - 1] = null_;
  push();
  next(c);   /* na na~alo e1 */
  if (c->cel == clist2)   /* pustoj spisok */
    goto _L1;
  /* sozdatx pustoj spisok */
  crlst(&v[base - 2]);
  while (c->cel != clist2) {
    /* wy~islitx wyravenie */
    expression(c, &x);
    /* c na clistdelim */
    /* dobawitx x k spisku v[base-1] */
    lconc(&v[base - 2], x);
    /* clistdelim proglatywaetsq w expression */
  }  /* while */
_L1: ;   /* c.cel = clist2 */
}  /* conlst */


Void contre(c)
ptr_ *c;
{
  /* na~alo konstruktora  a'14848  */
  /* c prodw.wpered, rezulxtat     */
  /* op. <. ... .> w steke v[ ]    */
  /*===============================================*/
  /*                                               */
  /* konstruktor   <. e1 : ob1 , e2 : ob2 , ... .> */
  /*                                               */
  /*===============================================*/
  /* wyhod */

  a x, y;
  mpd s;
  long count;
  boolean wrong;   /* was wrong selector */

  /* wrong branch ignored and error 22 issued */
  wrong = false;
  v[base - 1] = null_;
  push();
  count = 0;
  next(c);   /* na na~alo e1 */
  if (c->cel == ctree2)   /* pustoe derewo */
    goto _L1;
  /* sozdatx pustoe derewo */
  crtree(&v[base - 2]);
  while (c->cel != ctree2) {
    /* wy~islitx ei  */
    expression(c, &x);   /* selektor */
    /* c na na~alo obi ,         */
    /*      seldelim proglatywaet express */
    if (x == null_) {
      /* null ne movet bytx selektorom */
      err(22L);
      wrong = true;
      goto _L2;
    }
    pointr(x, &s.sa);
    if (s.sad->dtype != idatom) {
      /* selektor dolven bytx identifikatorom */
      err(22L);
      wrong = true;
      goto _L2;
    }
    x = s.sad->name;

_L2:
    expression(c, &y);   /* obxekt */
    /* ctreedelim proglatywaetsq w expression */
    if (y != null_) {
      /* added 23.10.89 and 13.11.89 */
      if (!wrong) {
	addel3(&v[base - 2], x, y);
	count++;
      }
    }
    wrong = false;
  }  /* while */
  if (count == 0)
    v[base - 2] = null_;
_L1: ;
}  /* contre */


Void expression(c, rez)
ptr_ *c;
long *rez;
{
  /* na~alo obratnoj */
  /* polxsk.zapisi wyraveniq .   */
  /* c prodwigaetsq wpered , w   */
  /* konce nah. na sled. za wyr. */
  /* |l-te                       */
  /* rezulxtat */
  /*============================================*/
  /* wy~islqet wyravenie , kak stek ispolxzuet  */
  /* v[ ] pri skanirowanii argumenty posylaet   */
  /* w v[base] (push).                          */
  /* atomy, var, rule kopiru`tsq iz sr-prostr.  */
  /* w st-prostranstwo.                         */
  /* operacii wypolnqet bop v[base-1] v[base-2] */
  /*                    unop v[base-1]          */
  /* esli odin iz operandow . ili [] -object, to*/
  /* i rezulxtat -object.                       */
  /* asdelim rabotaet kak unarnaq operaciq,     */
  /* wozwr.zna~enie per. iz steka, no ne oswob. */
  /* stek i c ostaetsq na asdelim               */
  /*                                            */
  /*============================================*/
  /* wyhod */
  /* oregon'S ERROR */

  boolean notfinished;
  mpd x, y;
  a n, rez1;
  boolean success;
  ptr_ p, pl;

  notfinished = true;
  while (notfinished) {
    /* skanirowanie wyraveniq */
    if (c->nel == 0)
      notfinished = false;
    else if (c->cel != null_ && (c->cel & 511) == 0 && c->cel < 65536L) {
      if (c->cel == clast)
	lastop();
      else if (c->cel == crule) {
	if (debugrule) {
	  if (out_screen) {
	    printf("\n=>>>CALLS RULE #");
	    pointr(v[base - 3], &x.sa);
	    pratom(x.srd->name);
	    printf(" IN STATEMENT");
	  } else {
	    fprintf(out, "\n=>>>CALLS RULE #");
	    pointr(v[base - 3], &x.sa);
	    pratom(x.srd->name);
	    fprintf(out, " IN STATEMENT");
	  }
	}
	srchrule(v[base - 3], &p);
	first(v[base - 2], &pl);
	rule(&rez1, &success, &pl, &p);
	if (debugrule) {
	  if (out_screen) {
	    printf("\n<<<=EXITS FROM RULE #");
	    pointr(v[base - 3], &x.sa);
	    pratom(x.srd->name);
	    printf(": ");
	    if (success)
	      printf("SUCCESS\n");
	    else
	      printf("UNSUCCESS\n");
	    printf("RESULT=");
	    pscr(rez1);
	  } else {
	    fprintf(out, "\n<<<=EXITS FROM RULE #");
	    pointr(v[base - 3], &x.sa);
	    pratom(x.srd->name);
	    fprintf(out, ": ");
	    if (success)
	      fprintf(out, "SUCCESS\n");
	    else
	      fprintf(out, "UNSUCCESS\n");
	    fprintf(out, "RESULT=");
	    pout(rez1);
	  }
	}
	v[base - 3] = rez1;
	base--;
      } else if (c->cel == cin) {
	/* wstroennoe prawilo */
	first(v[base - 2], &pl);
	pointr(v[base - 3], &x.sa);
	bltin(&rez1, &success, &pl, x.snd->val);
	if (debugrule) {
	  if (out_screen) {
	    printf("\n=>>>CALLS BUILT-IN RULE ");
	    prblt(v[base - 3]);
	    printf(" IN STATEMENT:");
	    if (success)
	      printf(" SUCCESS\n");
	    else
	      printf(" UNSUCCESS\n");
	    printf(" RESULT:");
	    pscr(rez1);
	  } else {
	    fprintf(out, "\n=>>>CALLS BUILT-IN RULE ");
	    prblt(v[base - 3]);
	    fprintf(out, " IN STATEMENT:");
	    if (success)
	      fprintf(out, " SUCCESS\n");
	    else
	      fprintf(out, " UNSUCCESS\n");
	    fprintf(out, " RESULT:");
	    pout(rez1);
	  }
	}
	v[base - 3] = rez1;
	base--;
      } else if (c->cel == cselect)
	selctr();
      else if (c->cel == cindex)
	indxop();
      else if (c->cel == cname)
	nameop();
      else if (c->cel == cmult || c->cel == cdiv || c->cel == cmod ||
	       c->cel == cadd || c->cel == cminus || c->cel == cgt ||
	       c->cel == clt || c->cel == cge || c->cel == cle)
	arithm(c->cel);
      else if (c->cel == cconc) {
	getval(&v[base - 3]);
	getval(&v[base - 2]);
	concop(&v[base - 3], v[base - 2]);
	base--;
      } else if (c->cel == clconc) {
	getval(&v[base - 2]);
	getval(&v[base - 3]);
	lconc(&v[base - 3], v[base - 2]);
	base--;
      } else
	goto _L3;
      goto _L4;
_L3:
      if (c->cel == ctradd) {
	getval(&v[base - 2]);
	getval(&v[base - 3]);
	addtre(&v[base - 3], v[base - 2]);
	base--;
      } else if (c->cel == cequ || c->cel == cnequ)
	eqop(c->cel);
      else if (c->cel == cand) {
	getval(&v[base - 3]);
	getval(&v[base - 2]);
	if (v[base - 3] != null_ && v[base - 2] != null_)
	  v[base - 3] = atomt;
	else
	  v[base - 3] = null_;
	base--;
      } else if (c->cel == cor) {
	getval(&v[base - 3]);
	getval(&v[base - 2]);
	if (v[base - 3] != null_ || v[base - 2] != null_)
	  v[base - 3] = atomt;
	else
	  v[base - 3] = null_;
	base--;
      } else if (c->cel == cnot) {
	getval(&v[base - 2]);
	if (v[base - 2] == null_)
	  v[base - 2] = atomt;
	else
	  v[base - 2] = null_;
      } else if (c->cel == cunminus)
	unmins();
      else if (c->cel == ccopy)
	copyop();
      else if (c->cel == 512) {
	/* spec.perem.  $$ ustanawliwaetsq */
	/*           iz glob.per. teklexem */
	v[base - 2] = teklexem;
      } else if (c->cel == clist1)
	conlst(c);
      else if (c->cel == ctree1)
	contre(c);
      else if (c->cel == asdelim) {
	*rez = v[base - 2];
	goto _L1;
      } else if (c->cel == clist2 || c->cel == ctree2) {
	goto _L2;
	/* wozwr.rez., no ne sdwigatx c */
	/* nuvno conlst i contree       */
      } else if (c->cel == 1024) {
	/* ^ w spiske << */
	v[base - 1] = c->cel;
	push();
      } else
	notfinished = false;
    } else {
      if (c->cel == null_)
	n = null_;
      else {
	n = c->cel;
	points(n, &x.sa);

	if (x.sspec->dtype == spec) {
	  n = x.sspec->val;
	  /* perewesti zna~enie w specadres */
	} else if (x.snd->dtype == number) {
	  gets1(&n, &y.sa);
	  *y.snd = *x.snd;
	} else if (x.sad->dtype == rulename && x.srd->fragmadr == 0)
	  x.srd->nomintab = c->cel;
	/* pomestitx s-adres #l w sr-prostr.  */
	/*  dlq nastrojki wo wremq wypolneniq */
      }
      v[base - 1] = n;
      push();
    }
_L4:
    next(c);
  }  /* while */
_L2:
  base--;
  *rez = v[base - 1];
_L1:
  getval(rez);

  /* wyzow prawila */
  /* (c.cel mod 512)=0 */
  /* atom, var, rule */
}


Void facult(rez, success, pl, p)
long *rez;
boolean *success;
ptr_ *pl;
long p;
{
  /* ukaz.na 1-` leksemu, */
  /* prodwigaetsq wpered */
  /* s-adres |l-ta {ablona */
  /*======================*/
  /* {ablon fakulxtatiwa  */
  /*======================*/
  a rez1;
  boolean success1;
  ptr_ pl1;   /* tek.leksema */
  ptr_ pp;   /* tek.|l-t {ablona */
  boolean ispattern;

  rez1 = null_;
  *success = true;
  /* wojti w spisok {ablonow */
  first(p, &pp);
  ispattern = true;
  pl1 = *pl;
  success1 = true;
  /* osnownoj cikl */
  while (success1 && continue_ && pp.cel != 0) {
    if (pp.cel == opdelim)
      ispattern = !ispattern;
    else {
      if (ispattern)
	pattern(&rez1, &success1, &pl1, &pp);
      else
	statement(pp.cel, &success1, &rez1);
    }
    next(&pp);
  }  /* while */
  if (success1) {
    *pl = pl1;
    *rez = rez1;
  }
}  /* facult*/


/* Local variables for inout: */
struct LOC_inout {

  bl80 a80_;
  filespecification namestr;
  longint rezlong;
  long i, openlen;   /* dlq pods~eta hiriny fajla */
  mpd x;

  a rez;   /* rezulxtat expression */
  long len;   /* dlina atoma */
  a fsp;   /* a-adres specifikacii fajla */
  boolean blank;   /* nado probely mevdu atomami */
} ;


Local Void make80(ee, LINK)
long ee;
struct LOC_inout *LINK;
{
  /* sozdaet a80 i len */


  pointa(ee, LINK->a80_, &LINK->len);   /* ibm/pc bez [1] */
}  /* make80 */


Local Void line(symlen, LINK)
long symlen;
struct LOC_inout *LINK;
{
  /* kontroliruet zapolnenie stroki fajla */
  /* curlen - tekusaq dlina , symlen - nado wywesti ,*/
  /* strlen - specifikaciq fajla-dlina stroki */
  _REC_filetab *WITH;

  WITH = &filetab[LINK->i - 1];   /*with*/
  if (!(LINK->blank && WITH->curlen + symlen > WITH->strlen))
  {  /* esli na |toj stroke ne pomehhaetsq */
    WITH->curlen += symlen;
    return;
  }
  if (symlen > WITH->strlen + 1)   /* slihkom dlinnaq stroka */
    err(17L);
  /* perewod na nowu` stroku
   */
  if (filetab[LINK->i - 1].screen)
    putchar('\n');
  else
    putc('\n', files[LINK->i - 1]);
  WITH->curlen = symlen;
}  /*line*/


Local Void printlist(la, i, fil, scr, LINK)
long la, i;
FILE **fil;
boolean scr;
struct LOC_inout *LINK;
{
  /* procedura dlq pe~ati spiska */
  /*la-adres, i-nomer fajla */
  mpd x;
  ptr_ lptr;
  boolean tatomflag;
  a a1;
  longint k;   /* changed 17-nov-90 from integer */
  long j, FORLIM;


  if ((la & 511) == 0 && la > 0 && la < 65536L) {
    line(20L, LINK);
    if (scr)
      printf("  <!<!!A*!*!!>!>  ");
    else
      fprintf(*fil, "  <!<!!A*!*!!>!>  ");
    return;
  }
  if (la == 0) {
    return;
  }  /* else mod<>512 */
  pointr(la, &x.sa);
  switch (x.sad->dtype) {

  case listmain:   /*listmain*/
    /* raspe~atka spiska */
    /*line(5);*/
    /* garantii koncow spiska */
    first(la, &lptr);
    while (lptr.nel != 0) {
      if (lptr.cel == 1024) {
	LINK->blank = !LINK->blank;
	/*if not(blank) then line(25);*/
	/*
	           garantiq neperenosa*/
      } else  /* a'1024 - smena revima pe~ati */
	printlist(lptr.cel, i, fil, scr, LINK);
      next(&lptr);
    }  /*while*/
    break;

  case fatom:  /* added 17-feb-1992 */
    line(12L, LINK);   /* standard length of written real */

    if (scr)
      printf("%E", take_fatom(x.sad->name));
    else
      fprintf(*fil, "%E", take_fatom(x.sad->name));
    break;

  case atom:
  case idatom:
  case tatom:
  case keyword:
  case variable:
  case fvariable:
  case nvariable:
  case idvariable:
  case rulename:   /*atom ...*/
    /* pe~atx otdelxnogo atoma */
    tatomflag = (x.sad->dtype == tatom);
    switch (x.sad->dtype) {

    case variable:
    case fvariable:
    case nvariable:
    case idvariable:
      a1 = x.svd->name;
      if (scr)
	putchar('$');
      else
	putc('$', *fil);
      break;

    case rulename:
      a1 = x.srd->name;
      if (scr)
	putchar('#');
      else
	putc('#', *fil);
      break;


    default:
      a1 = x.sad->name;
      break;
    }/*case*/
    make80(a1, LINK);   /* daet a80 i len */
    if (tatomflag) {
      line(LINK->len + 2, LINK);
      if (scr) {
	putchar('\'');
	FORLIM = LINK->len;
	for (j = 0; j < FORLIM; j++) {
	  if (LINK->a80_[j] == '\'')
	    printf("''");
	  else
	    putchar(LINK->a80_[j]);
	}
	putchar('\'');
      } else {
	putc('\'', *fil);
	FORLIM = LINK->len;
	for (j = 0; j < FORLIM; j++) {
	  if (LINK->a80_[j] == '\'')
	    fprintf(*fil, "''");
	  else
	    putc(LINK->a80_[j], *fil);
	}
	putc('\'', *fil);
      }
    } else {   /* if/else */
      line(LINK->len, LINK);
      if (scr) {
	FORLIM = LINK->len;
	for (j = 0; j < FORLIM; j++)
	  putchar(LINK->a80_[j]);
      } else {
	FORLIM = LINK->len;
	for (j = 0; j < FORLIM; j++)
	  putc(LINK->a80_[j], *fil);
      }
    }

    if (LINK->blank) {
      line(1L, LINK);
      if (scr)
	putchar(' ');
      else
	putc(' ', *fil);
    }
    break;

  case number:  /* pe~atx ~isla */
    LINK->rezlong = x.snd->val;
    k = LINK->rezlong;
    if (k < 0)   /* cahanged from abs call */
      k = -k;
    j = 0;
    do {
      k /= 10;
      j++;
    } while (k >= 1);
    line(j, LINK);
    if (scr)
      printf("%ld", LINK->rezlong);
    else
      fprintf(*fil, "%ld", LINK->rezlong);
    if (LINK->blank) {
      line(1L, LINK);
      if (scr)
	putchar(' ');
      else
	putc(' ', *fil);
    }

    break;
    /*number*/

  case treemain:
    line(20L, LINK);

    if (scr)
      printf(" <!<!<*TREE*>!>!> ");
    else
      fprintf(*fil, " <!<!<*TREE*>!>!> ");
    break;



  default:
    line(20L, LINK);

    if (scr)   /* otherwise */
      printf(" <!<!<UNK***>!>!> ");
    else
      fprintf(*fil, " <!<!<UNK***>!>!> ");
    break;
  }/* case */



  /* pri la=0 - ni~ego ne pe~ataetsq */
}  /* printlist */


Local boolean makefilespec(LINK)
struct LOC_inout *LINK;
{
  boolean Result;

  long j, k, k1, FORLIM1;


  Result = false;

  if ((LINK->rez & 511) == null_ && LINK->rez < 65536L && LINK->rez >= 0) {
    err(11L);
    goto _L99;
  }  /* 17-apr-91 */

  pointr(LINK->rez, &LINK->x.sa);
  if (((1L << ((long)LINK->x.sad->dtype)) & ((1L << ((long)atom)) |
	 (1L << ((long)idatom)) | (1L << ((long)tatom)))) == 0) {
    err(11L);
    goto _L99;
  }
  /* specifikaciq fajla - ne atom */
  LINK->fsp = LINK->x.sad->name;
  make80(LINK->fsp, LINK);   /* daet a80 i len */
  if (LINK->len > 80) {
    err(12L);
    goto _L99;
  }
  LINK->openlen = 80;
  for (k = LINK->len; k >= 1; k--) {
    if (LINK->a80_[k - 1] == ',') {
      LINK->openlen = 0;
      FORLIM1 = LINK->len;
      for (k1 = k + 1; k1 <= FORLIM1; k1++)
	LINK->openlen = LINK->openlen * 10 + LINK->a80_[k] - '0';
      LINK->len = k - 1;
    }
  }
  *LINK->namestr = '\0';
  FORLIM1 = LINK->len;

  for (j = 0; j < FORLIM1; j++)
    sprintf(LINK->namestr + strlen(LINK->namestr), "%c", LINK->a80_[j]);
  Result = true;
_L99:
  return Result;
}  /* makefilespec */


Void inout(p, ot)
long p, ot;
{
  /*   ==================={========================   */
  /* obespe~iwaet wypolnenie operatorow wwoda-wywoda */
  /*   ===========================================   */
  /* p - adres spiska, predstawlq`hego operator */
  /* ot - imq spiska */
  struct LOC_inout V;
  long j;   /* i - nomer fajla */

  ptr_ opptr;   /* pointer po s-kodu operatora */
  a aadr;   /* a-adres atoma */
  a opcel;   /* rawen opptr.cel*/
  boolean succmakeflag;   /* uspehno oformleno imq */

  /* ========= osnownaq procedura ========== */



  if (ot == 10752) {  /* open , otkrytie fajla */
    first(p, &opptr);
    opcel = opptr.cel;
    pointr(opcel, &V.x.sa);
    aadr = V.x.sad->name;
    /* a-adres imeni fajla
                               */
    for (V.i = 1; V.i <= filenum; V.i++) {
      if (filetab[V.i - 1].name == aadr && filetab[V.i - 1].isopen)
      {  /* otkrytx fajl snowa */
	err(16L);
	/* nado zakrywatx fajl pered
	          otkrytiem */
	/* $$$ !!! wyravenie ne wy~islqetsq */
	goto _L99;
      }
    }
    for (V.i = 1; V.i <= filenum; V.i++) {
      if (!filetab[V.i - 1].isopen) {
	j = V.i;
	goto _L98;
      }
    }
    /* ihetsq perwoe neotkrytoe gnezda dlq fajla */
    err(13L);
    goto _L99;   /* slihkom mnogo otkrytyh fajlow */

_L98:
    next(&opptr);
    expression(&opptr, &V.rez);
    /* wy~islenie wyraveniq,
                             rez-rezulxtat */
    if (!makefilespec(&V))
      goto _L99;
    /*  w p80 ustanowitsq sp. fajla  */
    if (!strcmp(V.namestr, " "))
      filetab[j - 1].screen = true;
    else {
      filetab[j - 1].screen = false;
      if (!rightfile(V.namestr)) {
	errstr(19L, V.namestr);
	goto _L99;
      }

    files[j - 1] = fopen(V.namestr, "w");
      if (files[j - 1] == NULL)
	_EscIO(FileNotFound);
    }


    filetab[j - 1].isopen = true;
    filetab[j - 1].strlen = V.openlen;
    filetab[j - 1].curlen = 0;
    filetab[j - 1].name = aadr;
    /* rightfile */
    goto _L99;

  }
  if (ot == 31744) {  /* close */
    first(p, &opptr);
    opcel = opptr.cel;
    pointr(opcel, &V.x.sa);
    aadr = V.x.sad->name;
    for (V.i = 1; V.i <= filenum; V.i++) {
      if (filetab[V.i - 1].name == aadr && filetab[V.i - 1].isopen) {
	if (filetab[V.i - 1].screen)
	  putchar('\n');
	else {
	  putc('\n', files[V.i - 1]);
	  if (files[V.i - 1] != NULL)
	    fclose(files[V.i - 1]);
	  files[V.i - 1] = NULL;
	}
	filetab[V.i - 1].isopen = false;
      }
    }
  }  /*close*/
  else if (ot == 32256) {
    first(p, &opptr);
    expression(&opptr, &V.rez);
    if (out_screen)
      pscr(V.rez);
    else
      pout(V.rez);
    if (out_screen)
      putchar('\n');
    else
      putc('\n', out);
    /* otlado~nyj wywod w fajl out*/
  } else if (ot == 11264 || ot == 18432) {
    /* write('%'); */
    first(p, &opptr);
    opcel = opptr.cel;
    pointr(opcel, &V.x.sa);
    aadr = V.x.sad->name;
    for (V.i = 1; V.i <= filenum; V.i++) {
      if (filetab[V.i - 1].name == aadr && filetab[V.i - 1].isopen) {
	next(&opptr);
	if (ot == 11264) {
	  if (filetab[V.i - 1].screen)
	    putchar('\n');
	  else
	    putc('\n', files[V.i - 1]);
	  filetab[V.i - 1].curlen = 0;
	}
	if (opptr.cel != 0) {
	  expression(&opptr, &V.rez);
	  V.blank = true;
	  printlist(V.rez, V.i, &files[V.i - 1], filetab[V.i - 1].screen, &V);
	}  /* if <> 0 */
	goto _L99;
      }  /* for/ if open */
    }

    err(14L);   /* fajl ne otkryt */
    /* $$$ !!!! pri |tom wyravenie ne wy~islqetsq */

  } else if (ot == 9728 || ot == 10240) {
    first(p, &opptr);
    opcel = opptr.cel;
    pointr(opcel, &V.x.sa);
    j = V.x.svd->location + mybase;
    next(&opptr);
    expression(&opptr, &V.rez);
    if (!makefilespec(&V))
      goto _L99;
    if (ot == 9728) {
      if (existfile(V.namestr))
	loads(V.namestr, &v[j - 1]);
      else {
	v[j - 1] = 0;
	errstr(18L, V.namestr);
      }

    }
    if (ot == 10240) {
      if (v[j - 1] != 0) {
	if (rightfile(V.namestr) && *V.namestr != '\0')
	  saves(V.namestr, &v[j - 1]);
	else
	  errstr(15L, V.namestr);
      }
    }
  }

_L99: ;


  /*print*/
  /* wywod << << << << */
  /* wywod << */
}


Void list(rez, success, pl, p)
long *rez;
boolean *success;
ptr_ *pl;
long p;
{
  /* ukazatelx na deskriptor spiska (leksema) */
  /* ukazatelx na |l-t {ablona */
  /*===================================*/
  /*  {ablon (.   .)                   */
  /*                                   */
  /*                                   */
  /*===================================*/
  /* wyhod */

  ptr_ pp;
  /* tek.|l-t {ablona wnutri (.  .) ,esli p=0 ,to  */
  /* pp.nel=0                                      */
  ptr_ pl1;
  /* tek. leksema wnutri spiska leksem, */
  /* esli is~erpan, ili pl=0, to pl.nel=0 */
  a rez1;
  boolean success1, ispattern;
  /* tek.|l-t spiska- {ablon, */
  /* false -operator */
  mpd s1;


  rez1 = null_;
  /* proweritx ,~to pl ukazywaet na glawnyj  */
  /*    fragment spiska, ina~e fail */
  if (pl->nel == 0) {
    *success = false;
    goto _L99;
  }
  if (pl->cel != null_) {
    rez1 = pl->cel;
    pointr(rez1, &s1.sa);
    if (s1.smld->dtype != listmain) {  /* leksema ne spisok */
      *success = false;
      rez1 = null_;
      goto _L99;   /* konec */
    }
    /* ustanowitx pl1 na perwyj |l-t wnutri spiska pl */
    first(pl->cel, &pl1);
  } else {
    pl1.nel = 0;
    pl1.cel = null_;
  }
  /* wojti w spisok {ablonow,  */
  /* pp-perwyj |l-t {ablona wnutri spiska {ablona */
  first(p, &pp);
  /* proweritx sowpadenie imeni spiska i  */
  /* imeni w {ablone(esli estx )*/
  if ((pp.cel & 511) != 0 || pp.cel >= 65536L || pp.cel < 0) {
    /* w {ablone estx atom ili perem. */
    if (!compnames(pp.cel, pl->cel)) {
      *success = false;
      goto _L99;   /* konec */
    }
  }
  /* ustanowitx pp na perwyj wypolnimyj |l-t {ablona*/
  next(&pp);
  success1 = true;
  /* osnownoj cikl */
  ispattern = true;
  while (success1 && continue_ && pp.nel != 0 && !fail) {   /* while */
    if (pp.cel == opdelim)
      ispattern = !ispattern;
    else {  /*30-aug-89*/
      teklexem = pl1.cel;
      if (ispattern)
	pattern(&rez1, &success1, &pl1, &pp);
      else
	statement(pp.cel, &success1, &rez1);
    }
    next(&pp);
  }

  if (success1 && continue_) {
    if (pl1.nel != 0) {
      /* spisok {ablonow kon~ilsq ranx{e, */
      /*        ~em spisok leksem */
      success1 = false;
      rez1 = null_;
    } else
      rez1 = pl->cel;
  }
  if (success1 && pl->ptrtype == ptrlist)
    next(pl);
  *success = success1;
_L99:
  *rez = rez1;
  /* wyhod */
}


Void loop(p, succ, rez)
long p;
boolean *succ;
long *rez;
{
  /* s-adres spiska operatora */
  /* dlq wozwrata
                      neuspeha iz fail */
  /* dlq wozwrata rez.iz return
              */
  ptr_ pp;
  a r, ats;
  long nvar;   /* nomer per.cikla w steke v[ ]*/
  long nbvar;   /* nom. branches-var in stack */
  mpd x;
  ptr_ p2, stmtbeg, p3;
  boolean islist;
  /* deskriptor atoma -selektora */
  long n;
  atomdescriptor *WITH;


  first(p, &pp);
  r = pp.cel;
  if (r == null_)
    nvar = 0;
  else {
    pointr(r, &x.sa);
    nvar = x.svd->location + mybase;
  }
  next(&pp);
  if (pp.cel == null_)
    nbvar = 0;
  else {
    r = pp.cel;
    pointr(r, &x.sa);
    nbvar = x.svd->location + mybase;
  }
  next(&pp);   /* pp na na~alo wyraveniq */
  expression(&pp, &r);
  if (r == null_)
    goto _L1;
  pointr(r, &x.sa);
  /* pp na perwom operatore */
  stmtbeg = pp;
  if (x.smld->dtype == listmain)
    islist = true;
  else if (x.smld->dtype == treemain)
    islist = false;
  else {
    err(24L);
    goto _L1;
  }
  first(r, &p2);   /* wojti w spisok/derewo */
  break_ = false;
  while (p2.nel != 0 && continue_ && *succ && !break_) {
    /* cikl po spisku/derewu */
    if (islist) {
      if (nvar == 0 || nbvar != 0) {
	err(26L);
	goto _L1;
      }
      v[nvar - 1] = p2.cel;
    } else {  /* tree */
      if (nvar != 0) {
	gets1(&ats, &x.sa);
	WITH = x.sad;
	WITH->dtype = idatom;
	WITH->name = p2.UU.U1.arc;
	v[nvar - 1] = ats;
      }
      if (nbvar != 0)
	v[nbvar - 1] = p2.cel;
    }  /** tree **/
    p3 = stmtbeg;
    while (p3.nel != 0 && continue_ && *succ && !fail && !break_) {
      /* added 23.10.89 */
      /* wypolnitx telo cikla forall */
      statement(p3.cel, succ, rez);
      next(&p3);
    }
    next(&p2);
  }  /* while */
_L1:
  break_ = false;
}  /* loop */


Void objexpr(c, nvar, t)
ptr_ *c;
long *nvar;
boolean *t;
{
  /* na~alo obxekta */
  /*  prodwigaetsq wpered , */
  /*  pri wyhode iz objexpr */
  /*  pokazywaet na razdelitelx asdelim */
  /* nomer perem.w steke, gde */
  /* nah. ssylka na object(t= true) */
  /*          ili nomer     */
  /* samoj peremennoj w prawile (t =false) */
  mpd x, y;
  a k, k1;
  ptr_ m;
  objdescriptor *WITH;


  k = c->cel;
  next(c);   /* c na 2-j |l-t wyr.*/
  pointr(k, &x.sa);
  /* 1-j |l-t wyraveniq */
  if (c->cel == asdelim) {   /* $e := ... */
    *t = false;
    *nvar = x.svd->location;
    return;
  }
  *t = true;
  /*  $e.... := ...               */
  /*  #l $e last ... := ...       */
  if (x.srd->dtype == rulename) {   /* s- adres uzla */
    /* #l $e last ...   */
    srchrule1(k, &m);
    /* w m ssylka na base dlq prawila */
    k1 = m.cel;
    pointr(k1, &x.sa);
    /* x na base prawila #l */
    k = x.snd->val;   /* base */
    k1 = c->cel;
    pointr(k1, &x.sa);   /* x na $e */
    k += x.svd->location;
    /* nomer w steke dlq last #l $e */
    next(c);
    next(c);   /* c na sled. za last */
  }  /* #l $e last */
  else {  /* $e ..... */
    /*   x, k na $e  */
    k = x.svd->location + mybase;
  }
  /*================================*/
  /* sformirowatx    object         */
  /*                                */
  /*================================*/

  /* abs.adres uzla */
  gets2(&k1, &y.sa);
  WITH = y.sobj;
  WITH->dtype = object_d;
  WITH->variable_ = true;
  WITH->fragmorvar = k;
  push();
  /* zanqtx perem. w steke , ee nomer ( base -1) */
  /*        oswoboditx w assgn                   */
  v[base - 2] = k1;
  /* primenitx select i index i sformirowatx   */
  /*   object s rezulxtatom                    */
  expression(c, &k);
  v[base - 2] = k;
  *nvar = base - 1;

  /* sformirowatx object */
  /* t=true */
}  /* objexpr */


Void pattern(rez, success, pl, p)
long *rez;
boolean *success;
ptr_ *pl, *p;
{
  /* tek.leksema  */
  /* ukazatelx |l-ta {ablona  */
  /* w s-prostranstwe rigal  */

  /*===========================*/
  /* wybor podprogrammy        */
  /*  {ablona                  */
  /*                           */
  /*===========================*/
  /* wyhod */

  mpd s;   /* wirt.adres |l-ta {ablona */
  mpd s2;   /* wirt.adres leksemy */
  ptr_ x;
  a y, ot;


  ot = p->cel;
  if (ot == cnull) {
    /* $e:= null pered {ablonom */
    next(p);   /* na varname */
    y = p->cel;
    pointr(y, &s.sa);
    /* polu~itx dostup k deskr.per. */
    v[mybase + s.svd->location - 1] = null_;
    goto _L1;   /* wyhod */
  }

  if ((ot & 511) == 0 && ot >= cass1 && ot <= cass5 && ot < 65536L && ot >= 0)
  {  /* $e:= rez */
    next(p);   /* na varname */
    y = p->cel;
    pointr(y, &s.sa);   /* deskr. per.*/
    y = mybase + s.svd->location;
    /* nomer per. w steke */
    if (ot == cass1)   /* prosto := */
      v[y - 1] = *rez;
    else if (ot == cass2)
      add(&v[y - 1], rez);
    else if (ot == cass3)
      addtre(&v[y - 1], *rez);
    else if (ot == cass4)
      concop(&v[y - 1], *rez);
    else if (ot == cass5)
      lconc(&v[y - 1], *rez);
    goto _L1;   /* wyhod */
  }
  if (ot == cin) {
    /* wstroennoe prawilo */
    next(p);
    y = p->cel;
    pointr(y, &s.sa);
    bltin(rez, success, pl, s.snd->val);
    if (debugrule) {
      if (out_screen) {
	printf("\n=>>>CALLS BUILT-IN RULE ");
	prblt(y);
	printf(" IN PATTERN:");
	if (*success)
	  printf(" SUCCESS\n");
	else
	  printf(" UNSUCCESS\n");
	printf(" RESULT:");
	pscr(*rez);
      } else {
	fprintf(out, "\n=>>>CALLS BUILT-IN RULE ");
	prblt(y);
	fprintf(out, " IN PATTERN:");
	if (*success)
	  fprintf(out, " SUCCESS\n");
	else
	  fprintf(out, " UNSUCCESS\n");
	fprintf(out, " RESULT:");
	pout(*rez);
      }
    }
    goto _L1;
  }
  /* polu~itx dostup k |l-tu {ablona */
  y = p->cel;
  pointr(y, &s.sa);
  switch (s.sad->dtype) {

  case atom:
  case idatom:
  case number:
  case fatom:  /* srawnenie atomow */
    if (pl->nel == 0)   /* leksemy net */
    {  /* neuspeh */
      *success = false;
      *rez = null_;
    } else {
      if (eqatoms(p->cel, pl->cel)) {  /* atomy rawny */
	*success = true;
	*rez = pl->cel;
	if (pl->ptrtype == ptrlist)   /* sdwig leksemy */
	  next(pl);
      } else {  /* ne rawny atomy */
	*success = false;
	*rez = null_;
      }
    }
    break;
    /* srawnenie atomow */

  case spec:
    if ((pl->cel & 511) == 0 && pl->cel < 65536L && pl->cel >= 0) {
      /* leksema uve priwedena k specadresu */
      *success = (pl->cel == s.sspec->val);
      if (*success)
	*rez = pl->cel;
      else
	*rez = null_;
    } else {
      ot = pl->cel;
      pointr(ot, &s2.sa);
      if (((1L << ((long)s2.smld->dtype)) &
	   ((1L << ((long)listmain)) | (1L << ((long)treemain)))) != 0 &&
	  s2.smld->totalelnum == 0 && s.sspec->val == null_)
	*success = true;
      else
	*success = (s.sc8 == s2.sc8);
      if (*success)
	*rez = s.sspec->val;
      else
	*rez = null_;
    }
    if (*success && pl->ptrtype == ptrlist)
      next(pl);
    break;
    /* spec */

  case rulename:  /* #imq w {ablone */
    if (debugrule) {
      if (out_screen) {
	printf("\n=>>>CALLS RULE #");
	y = p->cel;
	pointr(y, &s.sa);
	pratom(s.srd->name);
	printf(" IN PATTERN");
      } else {
	fprintf(out, "\n=>>>CALLS RULE #");
	y = p->cel;
	pointr(y, &s.sa);
	pratom(s.srd->name);
	fprintf(out, " IN PATTERN");
      }
    }
    srchrule1(p->cel, &x);
    rule(rez, success, pl, &x);

    if (debugrule) {
      if (out_screen) {
	printf("\n<<<=EXITS FROM RULE #");
	y = p->cel;
	pointr(y, &s.sa);
	pratom(s.srd->name);
	printf(": ");
	if (*success)
	  printf("SUCCESS\n");
	else
	  printf("UNSUCCESS\n");
	printf("RESULT:");
	pscr(*rez);
      } else {
	fprintf(out, "\n<<<=EXITS FROM RULE #");
	y = p->cel;
	pointr(y, &s.sa);
	pratom(s.srd->name);
	fprintf(out, ": ");
	if (*success)
	  fprintf(out, "SUCCESS\n");
	else
	  fprintf(out, "UNSUCCESS\n");
	fprintf(out, "RESULT:");
	pout(*rez);
      }
    }
    break;

  case variable:
  case idvariable:
  case nvariable:
  case fvariable:
    /* peremennaq w {ablone */
    if (pl->nel == 0)   /* neuspeh */
      *success = false;
    else {
      y = pl->cel;
      if (y != null_) {
	pointr(y, &s2.sa);
	*success = (s.svd->dtype == variable ||
		    s.svd->dtype == idvariable && s2.sad->dtype == idatom ||
		    s.svd->dtype == nvariable && s2.sad->dtype == number);
      } else
	*success = (s.svd->dtype != idvariable && s.svd->dtype != nvariable);
      /* if y=null */
    }  /* pl.nel<>0 */

    if (*success) {
      v[mybase + s.svd->location - 1] = pl->cel;
      *rez = pl->cel;
      if (pl->ptrtype == ptrlist)
	next(pl);
    } else {
      *rez = null_;
      v[mybase + s.svd->location - 1] = null_;
    }
    /* changed 28-jan-90 to null for $e must success
                               and null for $i - unsuccess */
    break;
    /* peremennaq w {abl. */

  case listmain:
    /* spisok rigal s-koda */
    *rez = null_;
    *success = true;
    y = s.smld->name;

    if (y == li)
      list(rez, success, pl, p->cel);
    else if (y == al)
      alter(rez, success, pl, p->cel);
    else if (y == se || y == ps)
      starlist(rez, success, pl, p->cel, y == ps);
    else if (y == fa)
      facult(rez, success, pl, p->cel);
    else if (y == tr || y == ti)
      tree(rez, success, pl, p->cel, y == ti);
    else if (y == spat || y == vpat)
      spatt(rez, success, pl, p->cel, y);
    /* {ablon  spiska (. .) */

    break;
    /* spisok rigal s-koda */
  }/* case */

_L1:   /* wyhod */
  teklexem = pl->cel;   /* added 30-aug-89 */

  /* +:= */
  /* ++:= */
  /* !!:= */
  /* !.:= */

  /* {ablon alxternatiwy ( a1 ! a2 ! ... ! an ) */

  /* {ablon (*... * ) ili (+...+) */

  /* {ablon fakulxtatiwa */

  /* {ablon derewa <.  .> ili <*  *> */

  /* s- i v- {ablon  */

}


Void rule(rez, success, pl, pp)
long *rez;
boolean *success;
ptr_ *pl, *pp;
{
  /* tek.leksema */
  /* sna~ala ukaz.na sled.posle #l |l-t */
  /*  w   spiske programmy */

  /*========================================*/
  /*                                        */
  /*    primenitx  prawilo                  */
  /*                                        */
  /*========================================*/
  a rez1, obasep;
  boolean success1;
  ptr_ pl1;
  numberdescriptor oldbase;
  long oldmybase;
  /* prevnqq baza, mybase pered whodom w prawilo */
  mpd x;
  long branch;


  /* razmestitx lok.per. w steke v */
  oldmybase = mybase;
  mybase = base - 1;
  /* zapomnitx, a pri wyhode iz rule wosstanowitx */
  obasep = pp->cel;
  points(obasep, &x.sa);
  /* dostup k base w spiske prawil */
  oldbase = *x.snd;   /* w stek */
  /* deleted sign 3-oct-89 */
  x.snd->val = mybase;
  next(pp);

  rez1 = pp->cel;
  pointr(rez1, &x.sa);
  /* dostup k ~islu lok.per. */
  base += x.snd->val + 1;
  if (base > varnum)
    err(1L);

  pl1 = *pl;
  next(pp);   /* ustanow.na perwu` wetwx prawila */
  rez1 = null_;
  success1 = true;
  branch = 0;
  /* osnownoj cikl */
  do {
    branch++;
    if (debugrule) {
      if (out_screen) {
	putchar('\n');
	if (branch > 1)
	  printf(">> (BRANCH NO %12ld)\n", branch);
	printf("  1-ST ARGUMENT($): ");
	pscr(pl1.cel);
      } else {
	putc('\n', out);
	if (branch > 1)
	  fprintf(out, ">> (BRANCH NO %12ld)\n", branch);
	fprintf(out, "  1-ST ARGUMENT($): ");
	pout(pl1.cel);
      }
    }
    simple(&rez1, &success1, &pl1, pp->cel);
    next(pp);
  } while (!(success1 || pp->cel == 0) && (success1 || continue_));
  /* priznak konca prawila */

  continue_ = true;
  *rez = rez1;
  *success = success1;
  if (*success)
    *pl = pl1;
  /* prodwinutx ukazatelx leksem */
  /* wosstanowitx base */
  points(obasep, &x.sa);
  *x.snd = oldbase;
  base = mybase + 1;
  mybase = oldmybase;
}  /* rule */


Void simple(rez, success, pl, p)
long *rez;
boolean *success;
ptr_ *pl;
long p;
{
  /* tek.leksema */
  /* ukazatelx na spisok wetwi (prostogo prawila)*/
  /*=============================*/
  /* primenitx prostoe prawilo   */
  /*    ( wetwx )                */
  /*                             */
  /*=============================*/
  ptr_ pp;   /* |l-t spiska wetwi */
  a rez1;
  boolean success1;
  ptr_ pl1;
  boolean ispattern;
  /* tek. |l-t spiska wetwi - {ablon, */
  /*              false -operator     */
  /*  many: boolean;*/
  /* w wetwi neskolxko |l-w {ablonow */

  /* many and statements with many deleted 29-jan-1992
     due to
        #l <. a : #n .> ##
        #n  pat pat ##
  */
  a onfail;   /* ukazatelx na deskr. onfail-spiska */
  long k, FORLIM;
  a oldteklexem;   /* added for using $$ in statements / 30-aug-1989 */

  FORLIM = base;
  /* o~istka peremennyh  */
  for (k = mybase; k < FORLIM; k++)
    v[k] = null_;
  /* ustanowitx zna~enie $ */
  v[mybase] = pl->cel;
  oldteklexem = teklexem;
  teklexem = pl->cel;
  /* ustanowitx pp na na~alo spiska wetwi */
  first(p, &pp);
  onfail = pp.cel;
  pl1 = *pl;
  rez1 = null_;
  success1 = true;
  /*    many := false;*/
  fail = false;
  next(&pp);
  /* na~atx so 2-go |l-ta         */

  /* osnownoj cikl po spisku wetwi */
  ispattern = true;
  continue_ = true;
  while (success1 && continue_ && pp.nel != 0 && !fail) {
    /* added 23.10.89 */
    if (pp.cel == opdelim) {
      ispattern = !ispattern;
      /* dlq / perekl`~itx revim */
    } else if (ispattern)
      pattern(&rez1, &success1, &pl1, &pp);
    else
      statement(pp.cel, &success1, &rez1);
    next(&pp);
  }  /* while */
  fail = false;
  if (success1)   /* uspeh */
    *pl = pl1;
  else {  /* neuspeh */
    if (onfail != 0) {  /* wypolnitx on-fail operatory */
      first(onfail, &pp);
      continue_ = true;
      while (continue_ && pp.nel != 0) {
	statement(pp.cel, &success1, &rez1);
	next(&pp);
      }  /* while */
    }  /* onfail */
  }
  *success = success1;
  if (continue_)
    *rez = null_;
  else
    *rez = rez1;

  teklexem = oldteklexem;

  /*  begin
    if not many or (pl1.ptrtype=ptrlist) then  */
  /* prodwivenie pl i slu~aj pl1.nel=0  */
  /*     rassm. w {ablonah */
  /*     else
         begin*/
  /* popytka primenitx posledowatelxnostx  */
  /*        {ablonow k lekseme,  */
  /* kotoraq ne whodit w spisok     */
  /*      success1 := false;
        rez1 := null
        end;
      many := true
      end */
  /* ispattern */
}  /* simple */


Void spatt(rez, success, pl, p, y)
long *rez;
boolean *success;
ptr_ *pl;
long p, y;
{
  /* spat or vpat */
  /*===================*/
  /* s-, ili v- {ablon */
  /*===================*/
  a r, oldteklexem;
  ptr_ c;


  oldteklexem = teklexem;
  /* tek.leksemu w globalxn.per. $$ */
  teklexem = pl->cel;
  /* wojti w spisok (. #wyravenie .)  */
  first(p, &c);
  expression(&c, &r);   /* wy~.wyravenie */
  if (r == null_) {
    *rez = null_;
    *success = false;
  } else {
    *rez = pl->cel;
    *success = true;
    if (pl->ptrtype == ptrlist && y == spat)
      next(pl);
  }
  teklexem = oldteklexem;
}  /* spatt */


Void starlist(rez, success, pl, p, pluslist)
long *rez;
boolean *success;
ptr_ *pl;
long p;
boolean pluslist;
{
  /* ukaz.tek.leksemu */
  /* s-adres |l-ta {ablona */
  /* (+...+) -true, (*...* )- false */
  /*=======================*/
  /* {ablon iteracii       */
  /*  (+...+) ili (*...* ) */
  /*=======================*/
  /* wyhod */

  ptr_ razd;   /* razdelitelx */
  a rez1, n;
  ptr_ pp;   /* perwyj |l-t {ablona */
  ptr_ pp2;   /* tek.|l-t {ablona */
  ptr_ pl2;   /* tek.leksema */
  ptr_ pl3;   /* na~alo iteracii leksem */
  boolean sraz;   /* uspeh razdelitelq */
  boolean ispattern, wasoneiteration;


  rez1 = null_;
  if (pl->ptrtype == ptrtree) {
    /* leksema ne w spiske */
    *success = false;
    goto _L1;
  }
  /* wojti w spisok {ablonow */
  first(p, &pp);
  razd = pp;   /* zapomnitx razdelitelx */
  next(&pp);   /* pp na 1-j |l-t {ablona */
  ispattern = true;
  wasoneiteration = false;
  *success = true;
  sraz = true;
  pl2 = *pl;
  pl3 = *pl;
  break_ = false;

  /* osnownoj cikl */
  while (pl2.nel != 0 && sraz) {
    pp2 = pp;
    /*===========================*/
    /* wypolnitx posled.{ablonow */
    /*===========================*/
    while (*success && continue_ && pp2.nel != 0) {
      if (pp2.cel == opdelim)
	ispattern = !ispattern;
      else {  /* a */
	if (ispattern)
	  pattern(&rez1, success, &pl2, &pp2);
	else
	  statement(pp2.cel, success, &rez1);
	if (!continue_) {
	  if (*success)   /* return -operator */
	    *pl = pl2;
	  /* dlq fail-operatora pl sohranqetsq */
	  goto _L1;
	}
	if (break_) {
	  *pl = pl2;
	  goto _L1;
	}
	if (!*success) {
	  /* esli neuspeh {ablona */
	  *pl = pl3;
	  goto _L1;
	}
      }  /* a */
      next(&pp2);   /* sled.|l-t {ablona */
    }  /* while */
    /* sdelana odna iteraciq posled.{ablonow */
    wasoneiteration = true;
    pl3 = pl2;
    /* na na~alo nowoj iterat.gruppy */
    /* teperx primenitx razdelitelx */
    if (razd.cel == 5120)
      continue;
    if ((razd.cel & 511) != 0 || razd.cel >= 65536L || razd.cel < 0) {
      pattern(&rez1, &sraz, &pl2, &razd);
      if (!sraz) {
	*pl = pl3;
	goto _L1;
      }
      continue;
    }
    /* wstroennoe prawilo */
    n = razd.cel / 512 - 10;
    /* nomer wstr.pr.*/
    bltin(&rez1, &sraz, &pl2, n);
    if (!sraz) {
      *pl = pl3;
      goto _L1;
    }
  }  /* while */
  *pl = pl2;
_L1:
  break_ = false;
  if (continue_) {
    if (pluslist)
      *success = wasoneiteration && (!fail);/* correction as 5-JUN-93 */
    else
      *success = !fail;
  }
  *rez = rez1;
}


Void statement(p, succ, rez)
long p;
boolean *succ;
long *rez;
{

  /* ukazatelx na spisok operatora */
  /* dlq wozwrata neuspeha iz fail */
  /* dlq wozwr.rezulxtata iz return */
  /* wyhod */

  mpd x;
  ptr_ c;   /* tek.|l-t spiska operatora */
  a ot;   /* tip operatora (specadres) */


  if (p == cfail) {  /* fail -operator */
    *succ = false;
    fail = true;
    *rez = null_;
    goto _L1;
  }

  if (p == 16384) {   /* break -operator */
    break_ = true;
    goto _L1;
  }
  if ((p & 511) != 0 || p >= 65536L || p < 0) {
    pointr(p, &x.sa);
    /* polu~itx deskr.spiska operatora */
    ot = x.smld->name;
    if (ot == creturn) {  /* return-operator */
      first(p, &c);   /* c na na~alo wyraveniq */
      expression(&c, rez);
      continue_ = false;
    } else if ((ot & 511) == 0 && ot >= cass1 && ot <= cass5 && ot < 65536L &&
	       ot >= 0) {
      /* assignment */
      assgn(ot, p);
    } else if (ot == 9728 || ot == 10240 || ot == 10752 || ot == 11264 ||
	       ot == 18432 || ot == 31744 || ot == 32256) {
      /* load , save , open , << , close , print */
      inout(p, ot);
    } else if (ot == 8704)
      cond(p, succ, rez);
    else if (ot == 12800) {
      /* forall -operator */
      loop(p, succ, rez);
    } else if (ot == 28160) {
      break_ = false;
      while (continue_ && *succ && !break_) {
	first(p, &c);
	/* wojti w spisok operatorow
	                  */
	while (c.nel != 0 && continue_ && *succ && !fail && !break_)
	{   /* added 23.10.89 */
	  statement(c.cel, succ, rez);
	  next(&c);
	}

      }
      /* while */
      break_ = false;
    } else if (ot == 17920 || ot == 27136) {
      first(p, &c);
      expression(&c, rez);
    }
  }
_L1: ;

  /* if -operator */
  /* loop -operator */
  /* wyzow prawila */
}


/* Local variables for tree: */
struct LOC_tree {
  a msel[5];
  /* spisok ispolxz.selektorow w <* *> */
  long nsel;   /* ~islo |l-tow msel */
} ;

Local long atomsel(s, LINK)
long s;
struct LOC_tree *LINK;
{
  /* sozdaet iz selektora s atom i */
  /* wozwr. ego deskriptor         */
  a ats;
  mpd x;
  atomdescriptor *WITH;


  gets1(&ats, &x.sa);
  WITH = x.sad;
  WITH->dtype = idatom;
  WITH->name = s;
  return ats;
}  /* atomsel */


Local boolean notintom(s, LINK)
long s;
struct LOC_tree *LINK;
{
  /* true , esli s ne sod. w msel */
  long k;
  boolean found;
  long FORLIM;


  found = false;
  FORLIM = LINK->nsel;
  for (k = 0; k < FORLIM; k++) {
    if (LINK->msel[k] == s)
      found = true;
  }
  return (!found);
}  /* notintom */


Void tree(parmrez, parmsuccess, parmpl, p, star)
long *parmrez;
boolean *parmsuccess;
ptr_ *parmpl;
long p;
boolean star;
{
  /* ukazatelx na deskriptor derewa leksem */
  /* |l-t {ablona */
  /*====================*/
  /* {ablon  <.    .>   */
  /* ili   <*  *>       */
  /*====================*/
  struct LOC_tree V;
  /* wyhod */

  ptr_ pp;   /* tek.|l-t {ablona */
  a sel;   /* atom-selektor iz {ablona */
  mpd x;
  boolean facel;
  /* true-tek.|l-t {ablona imeet [ ]
                   */
  ptr_ pt;   /* tek.|l-t derewa leksem */
  ptr_ ptold;   /* |l-t derewa leksem, s kotorogo */
  /*      na~at poisk */
  a rez1, rez;
  boolean success1, found, ispattern;
  long nvar;   /* nomer per.w steke */
  boolean success;
  ptr_ pl;


  rez = *parmrez;
  success = *parmsuccess;
  pl = *parmpl;
  rez1 = null_;
  /* proweritx, ~to pl ukazyw.na glawnyj deskriptor  */
  /* derewa, ina~e fail                              */
  if (pl.nel == 0) {
    success = false;
    goto _L99;
  }
  if (pl.cel != null_) {
    rez1 = pl.cel;
    pointr(rez1, &x.sa);
    if (x.smtd->dtype != treemain) {
      /* leksema ne derewo */
      success = false;
      rez1 = null_;
      goto _L99;
    }
    first(pl.cel, &ptold);
  } else {
    ptold.nel = 0;
    ptold.cel = null_;
    ptold.UU.U1.curfragment = null_;
  }

  /* wojti w spisok {ablonow */
  first(p, &pp);
  /*  proweritx   sowpadenie imeni derewa i   */
  /*  imeni w {ablone (esli estx )            */
  if ((pp.cel & 511) != 0 || pp.cel >= 65536L || pp.cel < 0) {
    /* w {ablone estx atom ili perem.dlq imeni */
    if (!compnames(pp.cel, pl.cel)) {
      success = false;
      goto _L99;
    }
  }
  next(&pp);
  /* ustanowitx pp na perwyj wyp.|l-t {ablona */
  break_ = false;

  /*==========================================*/
  /* osnownoj cikl po {ablonu, perebor wetwej */
  /*==========================================*/
  success1 = true;
  V.nsel = 0;
  while (pp.nel != 0 && success1 && continue_ && pp.cel != 30208 && !break_) {
    facel = (pp.cel == 31232);   /* wetwx s [ ] ? */
    next(&pp);
    /*  pro~itatx atom-selektor */
    sel = pp.cel;
    pointr(sel, &x.sa);
    sel = x.sad->name;
    if (star) {
      /* zanesti w massiw msel */
      V.nsel++;
      V.msel[V.nsel - 1] = sel;
    }

    /*=====================================*/
    /* poisk w derewe leksem selektora sel */
    /*=====================================*/
    pt = ptold;
    found = false;
    do {
      if (pt.nel != 0 && pt.UU.U1.arc == sel)
	found = true;
      else {
	next(&pt);
	if (pt.nel == 0)
	  first(pl.cel, &pt);
      }
    } while (!(found || (pt.nel == ptold.nel &&
			 pt.UU.U1.curfragment == ptold.UU.U1.curfragment)));
    if (!found) {
      if (!facel) {  /* ne najden sel */
	success = false;
	goto _L99;
      }
      /* propustitx wetwx w {ablone */
      do {
	next(&pp);
      } while (pp.nel != 0 && pp.cel != 4096);
    } else {
      /*=============================*/
      /* wypolnitx dejstwiq i {ablon */
      /*=============================*/
      next(&pp);
      ispattern = true;
      while (success1 && continue_ && pp.nel != 0 && pp.cel != 4096 && !break_) {
	if (pp.cel == opdelim)
	  ispattern = !ispattern;
	else {  /* 30-aug-89 */
	  teklexem = pt.cel;
	  if (ispattern)
	    pattern(&rez1, &success1, &pt, &pp);
	  else
	    statement(pp.cel, &success1, &rez1);
	}
	next(&pp);
      }  /* while */
      ptold = pt;
    }  /* dejstwiq i {ablon */
    next(&pp);
  }  /* osnownoj cikl */

  /*=========================================*/
  /* dlq <*  *> otrabotatx wetwx   $e : sss  */
  /*=========================================*/
  if (star && !break_ && continue_ && success1) {
    /*===============================================*/
    /* cikl po derewu leksem, primenitx sss ko wsem  */
    /* selektoram, krome teh , ~to nah.w msel        */
    /*===============================================*/
    next(&pp);   /* pp na varname */
    rez1 = pp.cel;
    pointr(rez1, &x.sa);
    nvar = x.svd->location + mybase;
    next(&pp);
    ptold = pp;
    /* na na~alo dejstwij i {ablona dlq
                  var */
    success1 = true;
    first(pl.cel, &pt);
    /* na na~alo derewa leksem */
    while (pt.nel != 0 && success1 && continue_ && !break_) {
      /*=========================*/
      /*  cikl po derewu leksem  */
      /*=========================*/
      if (notintom(pt.UU.U1.arc, &V)) {
	/* selektor wne msel  */
	v[nvar - 1] = atomsel(pt.UU.U1.arc, &V);   /* sozdatx atom */
	/*==============================*/
	/*  wypolnitx dejstwiq i {ablon */
	/*==============================*/
	pp = ptold;
	ispattern = true;
	while (success1 && continue_ && pp.nel != 0 && !break_) {
	  if (pp.cel == opdelim)
	    ispattern = !ispattern;
	  else {  /*30-aug-89*/
	    teklexem = pt.cel;
	    if (ispattern)
	      pattern(&rez1, &success1, &pt, &pp);
	    else
	      statement(pp.cel, &success1, &rez1);
	  }
	  next(&pp);
	}  /* while */
      }  /* notintom */
      next(&pt);
    }  /* while, cikl po derewu */
  }  /* star */

  if (success1) {
    if (continue_)
      rez1 = pl.cel;
    if (pl.ptrtype == ptrlist)
      next(&pl);
  }
  success = success1;
_L99:
  rez = rez1;
  /* wyhod */
  break_ = false;
  *parmrez = rez;
  *parmsuccess = success;
  *parmpl = pl;
}



/* End. */

