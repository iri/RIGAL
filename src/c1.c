#include "globrig.h"
#include "define.h"
#include "defpage.h"
#include "nef2.h"
#include "c1.h"

/* Local variables for bltin: */
struct LOC_bltin
{
  long l;
  bl80 mm;
};

Local long alen(k, LINK)
long k;
struct LOC_bltin *LINK;
{
  a t;

  t = k;
  pointa(t, LINK->mm, &LINK->l); /*ibm*/
  return LINK->l;
} /* alen */

Void bltin(rr, success, arg, n)
v *rr;
boolean *success;
long arg, n;
{
  /* nomer wstr.prawila */
  /*===========================*/
  /* wyzow wstroennogo prawila */
  /*===========================*/
  struct LOC_bltin V;
  /* wyhod */

  char rulenum;
  a k, s, rez;
  mpd x, y;
  long t;
  longint li_;
  string80 s80; /* for parameter */
  atomdescriptor *WITH;
  numberdescriptor *WITH1;

  rr->nu = 0;
  rulenum = n;
  k = arg;
  if ((k & 511) != 0 || k >= 65536L || k < 0)
    pointr(k, &x.sa);
  *success = true;
  rez = arg;
  switch (rulenum)
  {

  case 3: /* #atom */
    if (k == null_)
      goto _L99;
    *success = (((1L << ((long)x.sad->dtype)) &
                 ((1L << ((long)fatom + 1)) - (1L << ((long)atom)))) != 0);
    break;

  case 4: /* #number */
    if (k == null_)
      *success = false;
    else
      *success = (x.sad->dtype == number);
    break;

  case 5: /* #ident */
    if (k == null_)
      *success = false;
    else
      *success = (x.sad->dtype == idatom);
    break;

  case 6: /* #list */
    if (k == null_)
      goto _L99;
    *success = (x.sad->dtype == listmain);
    break;

  case 7: /* #tree */
    if (k == null_)
      goto _L99;
    *success = (x.sad->dtype == treemain);
    break;

  case 8: /* #tatom */
    if (k == null_)
      *success = false;
    else
      *success = (x.sad->dtype == tatom);
    break;

  case 9: /* #fatom */
    if (k == null_)
      *success = false;
    else
      *success = (x.sad->dtype == fatom);
    break;

  case 10: /* #_keyword */
    if (k == null_)
      *success = false;
    else
      *success = (x.sad->dtype == keyword);
    break;

  case 11: /* #_specdesc */
    if (k == null_)
      *success = false;
    else
      *success = (x.sad->dtype == spec);
    break;

  case 15: /* #len */
    if (k == null_)
      rr->nu = 0;
    else
    {
      switch (x.sad->dtype)
      {

      case atom:
      case idatom:
      case keyword:
      case tatom:
      case fatom:
        rr->nu = alen(x.sad->name, &V);
        break;

      case number:
        /* pods~itatx ~islo zna~.cifr */
        li_ = x.snd->val;
        t = 0;
        while (li_ != 0)
        {
          li_ /= 10;
          t++;
        }
        if (t == 0)
          t = 1;
        if (x.snd->val < 0)
          t++;
        rr->nu = t;
        break;
        /* number */

      case listmain:
        rr->nu = x.smld->totalelnum;
        break;

      case treemain:
        rr->nu = x.smtd->totalarcnum;
        break;

      default:
        rr->nu = 0;
        break;
      } /* case */
    }
    break;
    /* #len */

  case 14: /* #_rulename */
    if (k == null_)
      *success = false;
    else
      *success = (x.sad->dtype == rulename);
    break;

  case 12: /* #_varname */
    if (k == null_)
      *success = false;
    else
      *success = (((1L << ((long)x.sad->dtype)) &
                   ((1L << ((long)fvariable + 1)) - (1L << ((long)variable)))) != 0);
    break;

  case 16:
  case 17: /* #_ruletoatom, #_varntoatm */
    if (k == null_)
      *success = false;
    else
    {
      if (x.srd->dtype == rulename && rulenum == 16 ||
          (((1L << ((long)x.svd->dtype)) &
            ((1L << ((long)fvariable + 1)) - (1L << ((long)variable)))) != 0 &&
           rulenum == 17))
      {
        gets1(&s, &y.sa);
        WITH = y.sad;
        WITH->dtype = idatom;
        if (rulenum == 16)
          WITH->name = x.srd->name;
        else
          WITH->name = x.svd->name;
        rez = s;
      }
      else
        *success = false;
    }
    break;

  case 19: /* #debug */
    debugrule = true;
    break;

  case 21: /* _content2 */
    if ((k & 511) == 0 && k < 65536L && k >= 0)
      *success = false;
    else
    {
      s = x.snd->val;
      gets1(&k, &x.sa);
      WITH1 = x.snd;
      WITH1->dtype = number;
      WITH1->val = s;
      rez = k;
    }
    break;
    /* _content2 */

  case 22: /* #chr */
    if ((k & 511) == 0 && k < 65536L && k >= 0)
    {
      rez = null_;
      *success = false;
    }
    else if (x.snd->dtype != number || x.snd->val > 255 || x.snd->val < 0)
    {
      rez = null_;
      *success = false;
    }
    else
    {
      t = x.snd->val;
      V.mm[0] = (Char)t;
      V.l = 1;
      putatm(V.mm, V.l, &s);
      gets1(&k, &x.sa);
      WITH = x.sad;
      if (is_rig_letter((int)t))
        WITH->dtype = idatom;
      else
        WITH->dtype = atom;
      WITH->name = s;
      rez = k;
    }
    break;
    /* chr */

  case 23: /* parm */
    rez = null_;
    V.l = 1;
    while (V.l < g_argc)
    {
      strcpy(s80, g_argv[(int)V.l]);
      brt(s80);
      if (!strcmp(s80, "-p"))
        V.l++;
      else
        lconc(&rez, str_to_atom(s80));
      V.l++;
    }

    break;

  case 24: /* #_totatom */
    if (k == null_)
      *success = false;
    else
    {
      gets1(&s, &y.sa);
      WITH = y.sad;
      WITH->dtype = tatom;
      WITH->name = x.sad->name;
      WITH->flags = 0;
      rez = s;
    }
    break;

  case 25: /* #ord */
    if ((k & 511) == 0 && k < 65536L && k >= 0)
    {
      *success = false;
      goto _L99;
    }
    if (((1L << ((long)x.sad->dtype)) &
         (((1L << ((long)keyword + 1)) - (1L << ((long)atom))) |
          (1L << ((long)tatom)))) != 0)
    {
      k = x.sad->name;
      pointa(k, V.mm, &V.l);
      rr->nu = V.mm[0];
    }
    else
      *success = false;
    break;
    /* ord */

  } /* case */
_L99:
  if (!*success)
    rez = null_;
  if (n != 15 && n != 25)
    rr->sa = rez;
}

Void mkatom(k, atype, r)
long k;
char atype;
long *r;
{
  /* a-adres  */
  mpd x;
  atomdescriptor *WITH;

  if (k == 0)
  {
    *r = null_;
    return;
  }
  gets1(r, &x.sa);
  WITH = x.sad;
  WITH->dtype = atype;
  WITH->name = k;
} /* mkatom */

Void crlist(l)
long *l;
{
  /*  sozdatx pustoj spisok  */
  long n;
  mpd x;
  mainlistdescriptor *WITH;

  gets5(l, &x.sa);
  WITH = x.smld;
  WITH->dtype = listmain;
  WITH->elnum = 0;
  WITH->totalelnum = 0;
  WITH->name = null_;
  WITH->next = null_;
  for (n = 0; n < mainlistelnum; n++)
    WITH->elt[n] = null_;
} /* crlist */

Static Void errstrmes(n, m)
long n;
Char *m;
{
  Char STR2[130];

  switch (n)
  {

  case 1:
    sprintf(m, "Interpreter stack size overflow (stack size = %s);",
            strcpy(STR2, m));
    break;

  case 2:
    strcpy(m, "Assignment left side is not list or tree");
    break;

  case 3:
    strcpy(m, "List index is not number");
    break;

  case 4:
    strcpy(m, "Using [..] not for list");
    break;

  case 5:
    strcpy(m, "Index value exceeds list bounds");
    break;

  case 6:
    strcpy(m, "Not list or tree after \"::\"");
    break;

  case 7:
    strcpy(m, "Not atomic name before \"::\"");
    break;

  case 8:
    strcpy(m, "NULL in left side of assignment");
    break;

  case 9:
    strcpy(m, "Not numerical value in left side of \"+:=\" statement");
    break;

  case 10:
    strcpy(m, "Not numerical value in right side of \"+:=\" statement");
    break;

  case 11:
    strcpy(m, "File specification is not atom");
    break;

  case 12:
    strcpy(m, "Too long file specification");
    break;

  case 13:
    strcpy(m, "Too much open text files");
    break;

  case 14:
    strcpy(m, "File not open for output");
    break;

  case 15:
    strcpy(m, "Wrong file name in SAVE statement ");
    break;

  case 16:
    strcpy(m, "File was not closed before new opening");
    break;

  case 17:
    strcpy(m, "Atom length exceeds file record length");
    break;

  case 18:
    strcpy(m, "Not exist file in LOAD statement ");
    break;

  case 19:
    strcpy(m, "Wrong file name in OPEN statement ");
    break;

  case 21:
    strcpy(m, "Selector after \".\" is not identifier ");
    break;

  case 22:
    strcpy(m, "Selector in tree constructor is not identifier ");
    break;

  case 23:
    strcpy(m, "Not tree before \".\" operation ");
    break;

  case 24:
    strcpy(m, "Not tree or list as base of FORALL-IN statement ");
    break;

  case 25:
    strcpy(m, "Atom length more than 80 bytes in #IMPLODE ");
    break;

  case 26:
    strcpy(m, "\"BRANCHES\" option cannot be used for lists ");
    break;

  default:
    strcpy(m, "Unknown error");
    break;
  }
}

Void er(n)
long n;
{
  /* kod oshibki */
  string80 m;

  errstrmes(n, m);
  if (out_open)
    fprintf(out, "*** ERROR %12ld %s\n", n, m);
  else
    printf("*** ERROR %12ld %s\n", n, m);

} /* err */

Void errstr(n, s)
long n;
Char *s;
{
  string80 m;

  errstrmes(n, m);
  if (out_open)
    fprintf(out, "*** ERROR %12ld %s%s\n", n, m, s);
  else
    printf("*** ERROR %12ld %s%s\n", n, m, s);
} /* err */

/* used for statistics only */
Void d1(r)
long r;
{
  /* called from runtime library, s=1, r=1000..1030 */
}

Void d(
    status_r,
    rule_name, rulenum, param, success)
long status_r, rulenum, param;
char *rule_name;
boolean success;
{
  /* called from r1..r999 r=1..999, s=1..4 */
  if (status_r == 1)
  { /* Enters rule */
    printf("=>>>CALLS RULE #%s\n", rule_name);
    printf("  1-ST ARGUMENT($):");
    pscr(param);
    printf("\n");
  }
  if (status_r == 2)
  {
    printf("<<<=EXITS FROM RULE #%s:", rule_name);
    if (success)
      printf(" SUCCESS\n");
    else
      printf(" UNSUCCESS\n");
    printf("RESULT:");
    pscr(param);
    printf("\n");
  }
  /*  if (s == 3)
      printf(".r.%12ld\n", r);
    if (s == 4)
      printf(".e.%12ld\n", r); */
  /*    if s=1 then inc(dmas[r]);
        if s=10 then for i:=1 to 200 do dmas[i]:=0;
        if s=11 then begin
         assign(ff,'sta.lst');
         rewrite(ff);
         for i:=0 to 49 do begin
          for j:=1 to 4 do write(ff,i*4+j:3,' ',dmas[i*4+j]:4,' !');
          writeln(ff); end;
        close (ff);
        end;
    */
}

Void addel(sel, not_atomic, xsel, ob, tr_)
long sel;
boolean not_atomic;
long xsel, ob, *tr_;
{
  /*===============================*/
  /* dobawitx k derewu |lement     */
  /*  tr := tr ++ <. sel : ob .>   */
  /*===============================*/
  /* wyhod s tr:=l */
  /* wyhod bez tr:=l */

  a l;   /* s-adres glawnogo derewa */
  mpd x; /* dostup k glawnomu deskr.derewa */

  if (not_atomic)
  {
    if (xsel == null_)
    {
      er(21L);
      goto _L2;
    }
    pointr(xsel, &x.sa);
    if (x.sad->dtype != idatom)
    {
      er(22L);
      goto _L2;
    }
    sel = x.sad->name;
  }
  addel3(tr_, sel, ob);
_L2:;
}

long numval(ob)
long ob;
{
  /*=============*/
  /* ob -> ~islo */
  /*=============*/
  mpd x;

  if (ob == null_)
    return 0;
  else
  {
    pointr(ob, &x.sa);
    if (x.snd->dtype != number)
      return 0;
    else
      return (x.snd->val); /* sign proc deleted */
  }
}

/* numval*/

/* End. */
