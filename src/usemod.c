#include "globrig.h"
#include "define.h"
#include "defpage.h"
#include "ley.h"
#include "scan.h"
#include "nef2.h"
#include "usemod.h"
#include <math.h>
#include <string.h>
/* us1   bodies of use-procedures      for sun */

mpd xx;

Static boolean plstr(p0, strval, lenval, stringflag, stringval)
long p0;
Char *strval;
long *lenval;
boolean stringflag;
Char *stringval;
{
  /* input - s-address*/
  /* output: array */
  /* length of atom */
  /* need stringval ? */
  /* string */
  /* returns array of letters of atom if it is list parameter; */
  /* stringval with the same contest returned only
     if required by stringflag */
  aa atm;
  long i, FORLIM;

  *stringval = '\0';
  if (p0 == null_)
    return false;
  else
  {
    pointr(p0, &xx.sa); /* access to atom in memory */
    if (((1L << ((long)xx.sad->dtype)) & ((1L << ((long)fatom + 1)) - (1L << ((long)atom))) & (~(1L << ((long)number)))) == 0)
      return false;
    else
    {
      atm = xx.sad->name;          /* access to a-address */
      pointa(atm, strval, lenval); /* reads value to str variable */
      if (stringflag)
      {
        FORLIM = *lenval;
        for (i = 0; i < FORLIM; i++)
          sprintf(stringval + strlen(stringval), "%c", strval[i]);
        /* and to stringval variable */
      }

      return true;
    }
  }
} /* plstr */

Static Char bc(a_)
long a_;
{
  if (a_ >= 10)
    return ((Char)(a_ + 55));
  else
    return ((Char)(a_ + 48));
}

Static Void dump(adr, sad)
long adr, sad;
{
  /* physical address */
}

a a2, atm;
long j, l, i1;
error_rec_type error_rec_use;
Char dty;
FILE *workfile;
Char c;
boolean id;
string80 sv1, sv2, svar;
bl80 str_;  /*for pointa & putatm*/
bl80 str1_; /*for pointa & putatm*/
longint im[5];

typedef union sa_pointer
{
  a pointa;
  Char immed[4];
  struct
  {

    word offset;
    Char page, pazime;

  } struct_;
} sa_pointer;

Void use_42(p1, p2, p3, rez)
long p1, p2, p3, *rez;
{
  /* returns current page (very useful for big algorythms) */
  sa_pointer xxx;
  long i;
  numberdescriptor *WITH;

  gets1(rez, &xx.sa);
  WITH = xx.snd;

  WITH->dtype = number;
  WITH->cord = 0;
  xxx.pointa = *rez;
  putchar('\n');
  for (i = 0; i <= 3; i++)
    printf("%d-", xxx.immed[i]);
  putchar('\n');
  WITH->val = xxx.immed[1];
}

Void use_43(p1, p2, p3, rez)
long p1, p2, p3, *rez;
{
  /* returns #call_pas(42) if current disk in use,
        0 otherwise. */
  numberdescriptor *WITH;

  gets1(rez, &xx.sa);
  WITH = xx.snd;
  WITH->dtype = number;
  WITH->cord = 0;
  vols(im, &im[1], &WITH->val);
}

Void use_30(p1, p2, p3, rez)
long p1, p2, p3, *rez;
{
  *rez = null_;
  /*write atom or number*/
  if (plstr(p1, str_, &l, true, sv1))
    fputs(sv1, stdout);
  else
  {
    if (plnum(p1, im))
      printf("%12ld", im[0]);
  }
}

Void use_31(p1, p2, p3, rez)
long p1, p2, p3, *rez;
{
  long i, FORLIM;

  /*write atom or number with adding spaces after it or rupping the end*/
  *rez = 0;
  if (!plstr(p1, str_, &l, true, sv1))
  {
    if (!plnum(p1, &im[1]))
      goto _L1;
    long_to_str(sv1, im[1]);
  }
  if (plnum(p2, im))
  {
    if (im[0] > strlen(sv1))
    {
      FORLIM = im[0];
      for (i = strlen(sv1); i < FORLIM; i++)
        sv1[i] = ' ';
    }

    printf("%*s", (int)im[0], sv1);
  }
  else
    fputs(sv1, stdout);
_L1:;
}

Void use_1(p1, p2, p3, rez)
long p1, p2, p3, *rez;
{
  char *TEMP; /* Char ->char */

  *rez = 0;
  /* puts an atom (or null) to screen.
     user's answer (atom, identifier or number ) is returned */
  if (plstr(p1, str_, &l, true, sv1))
    fputs(sv1, stdout);
  fgets(svar, 81, stdin);
  TEMP = strchr(svar, '\n');
  if (TEMP != NULL) /* enters from screen */
    *TEMP = 0;
  *rez = str_to_atom(svar);
}

/*rigal lexical analyser */
Void use_14(p1, p2, p3, rez)
long p1, p2, p3, *rez;
{
  *rez = 0;
  *error_rec_use.message = '\0';
  if (plstr(p1, str_, &l, true, sv1))
    ley(sv1, rez, false, &error_rec_use);
}

Void use_15(p1, p2, p3, rez)
long p1, p2, p3, *rez;
{
  *rez = 0;
  *error_rec_use.message = '\0';
  if (plstr(p1, str_, &l, true, sv1))
    ley(sv1, rez, true, &error_rec_use);
}

Void use_16(p1, p2, p3, rez)
long p1, p2, p3, *rez;
{
  FILE *inpfile;
  string80 s;
  Char c;
  long rline;
  int fff;

  inpfile = NULL;
  *rez = 0;
  if (plstr(p1, str_, &l, true, sv1))
  {
    if (existfile(sv1))
    {
      inpfile = fopen(sv1, "r");
      if (inpfile == NULL)
        _EscIO(FileNotFound);

      *rez = null_;
      while (!feof(inpfile))
      {

        fgets(s, 145, inpfile);
        if (s[strlen(s) - 1] == '\n')
        {
          s[strlen(s) - 1] = 0;
          fff = fgetc(inpfile);
          if (fff != 10)
          {
            ungetc(fff, inpfile);
          }
        }

        a2 = str_to_textatom(s);
        lconc(rez, a2);
      } /*while eof*/
      /*    readln(inftext,svar);  */

      if (inpfile != NULL)
        fclose(inpfile);
      inpfile = NULL;
    }
  }
  if (inpfile != NULL)
    fclose(inpfile);
}

Void use_4(p1, p2, p3, rez)
long p1, p2, p3, *rez;
{
  numberdescriptor *WITH;

  *rez = 0;
  /* finds coordinate of atom */
  if (p1 == 0)
    return;
  pointr(p1, &xx.sa);
  if (((1L << ((long)xx.sad->dtype)) & ((1L << ((long)fatom + 1)) - (1L << ((long)atom))) & (~(1L << ((long)number)))) != 0)
    a2 = xx.sad->cord;
  else if (xx.snd->dtype == number)
    a2 = xx.snd->cord;
  else
    a2 = 0;
  /* make numerical atom */
  gets1(rez, &xx.sa); /* fill descriptor */
  WITH = xx.snd;
  WITH->dtype = number;
  WITH->cord = 0;
  WITH->val = a2;
}

Void use_10(p1, p2, p3, rez)
long p1, p2, p3, *rez;
{

  /* dump */
  *rez = 0;
  if (p1 == 0)
    return;
  a2 = p1;
  do
  {
    pointr(a2, &xx.sa);
    dump(xx.sa, a2);
    printf(" Another address=");
    scanf("%ld%*[^\n]", &a2);
    getchar();
  } while (a2 != 0);
}

Void use_13(p1, p2, p3, rez)
long p1, p2, p3, *rez;
{
  /* nice print */
  *rez = 0;
  if (p1 != 0)
    putchar('\n'); /* dout(p1);*/
}

Void use_12(p1, p2, p3, rez)
long p1, p2, p3, *rez;
{
  *rez = 0;
  /* nice print */
  if (p1 != 0)
    fprintf(out, "\n\n"); /*dout2(p1);*/
}

Void use_19(p1, p2, p3, rez)
long p1, p2, p3, *rez;
{
  *rez = 0;
}

Void use_20(p1, p2, p3, rez)
long p1, p2, p3, *rez;
{
  /*random*/
  *rez = 0;
}

Void use_21(p1, p2, p3, rez)
long p1, p2, p3, *rez;
{
  /* atom->number, others->null */
  *rez = 0;
  if (!plstr(p1, str_, &l, true, sv1))
    return;
  /*     if (sv1[l]='l') or (sv1[l]='L')
    then sv1:=substr(sv1,1,l-1);*/
  /*substr*/
  val(sv1, im, &l);
  if (l == 0)
    *rez = long_to_atom(im[0]);
}

a erlist;

/* used to leave error message list in usepas after scaner
                return it to another usepas call later - when it will
                be retrieved */

Void use_35(p1, p2, p3, rez)
long p1, p2, p3, *rez;
{
  /* scaner receives data from file */
  /* format #call_pas(35 $dos_filename [ $options ])  */
  /* returns null if file  does not exist */
  erlist = 0;
  *rez = 0;
  if (!plstr(p1, str_, &l, true, sv1)) /* file name */
    return;
  if (!plstr(p2, str_, &l, true, sv2)) /* options */
    *sv2 = '\0';
  initialize_scan_variables();
  scaner(1L, sv1, sv2, rez, &erlist, (long)null_, 0L, 0L);
}

Void use_121(p1, p2, p3, rez)
long p1, p2, p3, *rez;
{
  /* scaner receives data from file */
  /* format #call_pas(121 $mif_filename [ $options ])  */
  /* returns null if file  does not exist */
  erlist = 0;
  *rez = 0;
  if (!plstr(p1, str_, &l, true, sv1)) /* file name */
    return;
  if (!plstr(p2, str_, &l, true, sv2)) /* options */
    *sv2 = '\0';
  initialize_scan_variables_mif();
  scaner_mif(1L, sv1, sv2, rez, &erlist, (long)null_, 0L, 0L);
}

Void use_36(p1, p2, p3, rez)
long p1, p2, p3, *rez;
{
  /* scaner receives data from list of strings,
     numbers and complex structures in the input list are ignored */
  /* format  #call_pas(36 $list [$options] ) */
  *rez = 0;
  erlist = 0;
  if (!plstr(p2, str_, &l, true, sv2)) /* options */
    *sv2 = '\0';
  initialize_scan_variables();
  scaner(2L, "", sv2, rez, &erlist, p1, 0L, 0L);
}

Void use_38(p1, p2, p3, rez)
long p1, p2, p3, *rez;
{
  /* returns error message list,
     produced after last call of "scaner" */
  *rez = erlist;
}

Void use_40(p1, p2, p3, rez)
long p1, p2, p3, *rez;
{
  /* any -> s-address */
  numberdescriptor *WITH;

  gets1(rez, &xx.sa);
  WITH = xx.snd;
  WITH->dtype = number;
  WITH->cord = 0;
  WITH->val = p1;
}

Void use_41(p1, p2, p3, rez)
long p1, p2, p3, *rez;
{
  /* returns current s-address */
  numberdescriptor *WITH;

  gets1(rez, &xx.sa);
  WITH = xx.snd;
  WITH->dtype = number;
  WITH->cord = 0;
  WITH->val = *rez;
}

Void use_44(p1, p2, p3, rez)
long p1, p2, p3, *rez;
{
  /* sets coordinate to atom */
  *rez = 0;
  if (!plnum(p2, im))
    goto _L1;
  if (p1 != 0)
  {
    *rez = p1;
    a2 = p1;
    points(a2, &xx.sa);
    if (((1L << ((long)xx.sad->dtype)) & ((1L << ((long)fatom + 1)) - (1L << ((long)atom))) & (~(1L << ((long)number)))) != 0)
      xx.sad->cord = im[0];
    else if (xx.snd->dtype == number)
      xx.snd->cord = im[0];
  }
_L1:;
}

Void use_45(p1, p2, p3, rez)
long p1, p2, p3, *rez;
{
  reopen(rez, &p1);
  /* removes all s-space saving only this p1 value in result;
     all variables after that moment will have wrong values  */
  /* this not allowed in interpreter ! */
}

Void use_46(p1, p2, p3, rez)
long p1, p2, p3, *rez;
{
  *rez = null_;
} /* returns null if we are in compiler */

Void use_9(p1, p2, p3, rez)
long p1, p2, p3, *rez;
{
  *rez = 0;
}

Void use_85(p1, p2, p3, rez)
long p1, p2, p3, *rez;
{
  /* upcase */
  long FORLIM;

  *rez = 0;
  if (!plstr(p1, str_, &l, true, sv1))
    return;
  FORLIM = strlen(sv1);
  for (j = 1; j <= FORLIM; j++)
  {
    if (islower(sv1[j - 1]))
      sv1[j - 1] -= 32;
  }
  *rez = str_to_textatom(sv1);
}

Void use_86(p1, p2, p3, rez)
long p1, p2, p3, *rez;
{
  /* locase */
  long FORLIM;

  *rez = 0;
  if (!plstr(p1, str_, &l, true, sv1))
    return;
  FORLIM = strlen(sv1);
  for (j = 1; j <= FORLIM; j++)
  {
    if (isupper(sv1[j - 1]))
      sv1[j - 1] += 32;
  }
  *rez = str_to_textatom(sv1);
}

Void use_87(p1, p2, p3, rez)
long p1, p2, p3, *rez;
{
  /* substr */
  Char STR1[256];

  *rez = 0;
  if (!plstr(p1, str_, &l, true, sv1))
    return;
  if (plnum(p2, im))
  {
    if (!plnum(p3, &im[1]))
      im[1] = l;
  }
  sprintf(STR1, "%.*s", (int)im[1], sv1 + im[0] - 1);
  *rez = str_to_textatom(STR1);
}

Void use_88(p1, p2, p3, rez)
long p1, p2, p3, *rez;
{
  char *tmp;
  /* position */
  *rez = 0;
  if (plstr(p1, str_, &l, true, sv1))
  {
    if (plstr(p2, str_, &l, true, sv2))
    {
      tmp = strstr(sv2, sv1);
      *rez = long_to_atom((long)(tmp ? ((long)tmp - (long)sv1) : 0));
    }
  }
}

Void use_90(p1, p2, p3, rez)
long p1, p2, p3, *rez;
{
  long iii;

  /* if plnum(p2,im[1]) then hlt:=im[1] else hlt:=0; */
  for (iii = 0; iii < filenum; iii++)
  {
    if (filetab[iii].isopen)
    {
      if (filetab[iii].screen)
        putchar('\n'); /* Corrected 29/5/95 */
      else
      {
        putc('\n', files[iii]);
        if (files[iii] != NULL)
          fclose(files[iii]);
      }
      files[iii] = NULL;
    }
  }
  if (out_open)
  {
    if (out != NULL)
      fclose(out);
    out = NULL;
  }
  closea();
  closes();

  exit(0);
}

Void use_78(p1, p2, p3, rez)
long p1, p2, p3, *rez;
{
  if (plnum(p1, im))
    max_printlevel = im[0];
}

Void use_79(p1, p2, p3, rez)
long p1, p2, p3, *rez;
{
  boolean is_tree;
  ptr_ ap;
  longint elnum;
  atomdescriptor *WITH;

  *rez = null_;
  first(p1, &ap);
  is_tree = (ap.ptrtype == ptrtree);
  elnum = 0;
  while (ap.nel != 0)
  {
    elnum++;
    if (eqatoms(ap.cel, p2))
      goto _L22;
    next(&ap);
  }
  return;
_L22:
  if (!is_tree)
  {
    *rez = long_to_atom(elnum);
    return;
  }

  gets1(rez, &xx.sa); /* makes s-address */
  /* fills descriptor */
  WITH = xx.sad; /* with */
  WITH->dtype = idatom;
  WITH->name = ap.UU.U1.arc;
}

Void use_91(p1, p2, p3, rez)
long p1, p2, p3, *rez;
{
  /* for lists - modifies list descriptor and
     makes it 1 element shorter by deleting ladst element ;
     returns the argument.
     if length of list is 1 or 0 then this function returns null,
     but list descriptor is not modified (!!!)
     if argument is not list then returns null.

     e.g.
       $a:=(.a.)
       #call_pas(91 $a) returns null , but $a retain (.a.)

       $a:=(.a b.)
       #call_pas(91 $a) returns (.a.), and $a is (.a.)
   */
  ptr_ ap;
  longint len, i;

  *rez = null_;
  points(p1, &xx.sa);
  if (xx.smld->dtype != listmain)
    return;
  len = xx.smld->totalelnum;
  if (len == 1 || len == 0)
    return;
  first(p1, &ap);
  for (i = 1; i <= len - 2; i++)
    next(&ap);
  /* we are standing on the last element of future list */
  /* the next elements (or descriptor) are to cut off,
     we split to 4 cases main/fragm  element/descriptor */
  *rez = p1;
  points(ap.UU.U1.curfragment, &xx.sa);
  if (xx.smld->dtype == listmain)
  {
    if (ap.nel == mainlistelnum)
    {
      xx.smld->next = null_;
      xx.smld->lastfragm = ap.UU.U1.curfragment;
      /* correction 8-apr-1993 */
    }
    else
      xx.smld->elnum--;
    xx.smld->totalelnum--;
    return;
  }
  if (ap.nel == fragmlistelnum)
  {
    xx.sfld->next = null_;
    points(p1, &xx.sa);
    xx.smld->lastfragm = ap.UU.U1.curfragment;
    /* correction 8-apr-1993 */
  }
  else
    xx.sfld->elnum--;
  points(p1, &xx.sa);
  xx.smld->totalelnum--;
}

Static long selection(tree, arc)
long tree, arc;
{
  long Result;
  ptr_ ap;

  Result = null_;
  first(tree, &ap);
  if (ap.ptrtype != ptrtree)
    return Result;
  while (ap.nel != null_ && ap.UU.U1.arc != arc)
    next(&ap);
  if (ap.UU.U1.arc == arc)
    return (ap.cel);
  return Result;
}

Static long indexing(list, index)
long list, index;
{
  long Result;
  ptr_ ap;
  longint maxind, i;

  Result = null_;
  first(list, &ap);
  if (ap.ptrtype != ptrlist)
    return Result;
  pointr(list, &xx.sa);
  maxind = xx.smld->totalelnum;
  if (index < -maxind || index == 0 || index > maxind)
    return Result;
  if (index < 0)
    index += maxind + 1;
  for (i = 1; i < index; i++)
    next(&ap);
  return (ap.cel);
}

Void use_92(p1, p2, p3, rez)
long p1, p2, p3, *rez;
{
  /* traverses list "p1".
      if element is a number then index is applied to "p2"
      if element is an atom the selection ia applied to "p2" */
  ptr_ ap;

  *rez = p2;
  first(p1, &ap);
  if (ap.ptrtype != ptrlist)
  {
    *rez = null_;
    return;
  }
  while (ap.nel != null_)
  {
    pointr(ap.cel, &xx.sa);
    if (xx.snd->dtype == number)
      *rez = indexing(*rez, xx.snd->val);
    else if (xx.sad->dtype == idatom)
      *rez = selection(*rez, xx.sad->name);
    else
      *rez = null_;
    if (*rez == null_)
      return;
    next(&ap);
  }
}

Void use_93(p1, p2, p3, rez)
long p1, p2, p3, *rez;
{
  /* returns stack size*/
  *rez = 0;
}

Void use_108(p1, p2, p3, rez)
long p1, p2, p3, *rez;
{
  /* get environment variable ;
     requires variable name(string)
     returns null if absent
      or value (converted to number if possible) */
  string80 pc;

  *rez = 0;
  if (plstr(p1, str_, &l, true, sv1))
  {

    *rez = str_to_atom(getenv(sv1));
  }
}

Void use_110(p1, p2, p3, rez)
long p1, p2, p3, *rez;
{
  *rez = 0;
}

Void use_111(p1, p2, p3, rez)
long p1, p2, p3, *rez;
{
  *rez = 0;
}

Void use_116(p1, p2, p3, rez)
long p1, p2, p3, *rez;
{
  /* returns c-string value 'a"bc\n' -> '"abc\\m\"' */
  long i, FORLIM;

  *rez = 0;
  if (!plstr(p1, str_, &l, true, sv1))
    return;
  strcpy(sv2, "\"");
  FORLIM = l;
  for (i = 0; i < FORLIM; i++)
  {
    if (sv1[i] == '\\' || sv1[i] == '"')
      strcat(sv2, "\\");
    sprintf(sv2 + strlen(sv2), "%c", sv1[i]);
  }
  strcat(sv2, "\"");
  *rez = str_to_atom(sv2);
}

/* floating point processor */
Void use_80(p1, p2, p3, rez)
long p1, p2, p3, *rez;
{
  long real_size;

  long i;
  double re1, re2, re3;
  Char c1, c2_;
  mpd x;
  double *refr2, *refr3;
  numberdescriptor *WITH;
  atomdescriptor *WITH1;

  real_size = sizeof(double);
  *rez = 0; /* in case of unsuccessful data returns null */
  if (!plstr(p1, str1_, &l, false, sv1))
    goto _L1;

  c1 = str1_[0];
  if (l > 1)
    c2_ = str1_[1];
  else
    c2_ = ' ';
  switch (c1)
  { /*1*/

  case 'S': /* string -> real */
    if (!plstr(p2, str_, &l, true, sv1))
      goto _L1;
    val2(sv1, &re1, &i);
    if (i != 0)
      goto _L1;
    break;

  case 'I': /*2*/
    /* integer -> real */
    if (!plnum(p2, &im[1]))
      goto _L1;
    re1 = im[1]; /* *1.0 */
    break;

    /* real -> ... */

  default:
    if (!plstr(p2, str_, &l, false, sv1))
      goto _L1;
    if (l != real_size)
      goto _L1;
    refr2 = (double *)str_;
    /*  re2 = *refr2; */
    memcpy(&re2, refr2, sizeof(double));
    switch (c1)
    { /*3*/

    case 'T':
      im[2] = (long)re2;
      gets1(rez, &x.sa);
      WITH = x.snd;
      WITH->dtype = number;
      WITH->val = im[2];
      goto _L1;
      break;

    case 'Z': /*4*/
      if (!plnum(p3, &im[1]))
        goto _L1;
      real_to_string_f(svar, re2, im[1] / 100, im[1] % 100);
      /* p2c: ./use80.pas, line 48:
       * Note: Using % for possibly-negative arguments [317] */
      i = strlen(svar);
      putatm(svar, i, &atm);
      gets1(rez, &x.sa);
      WITH1 = x.sad;
      WITH1->dtype = atom;
      WITH1->name = atm;
      goto _L1;
      break;

    case 'V': /*4*/
      sprintf(svar, "%E", re2);
      i = strlen(svar);
      putatm(svar, i, &atm);
      gets1(rez, &x.sa);
      WITH1 = x.sad;
      WITH1->dtype = atom;
      WITH1->name = atm;
      goto _L1;
      break;

    case 'F':
      if (!plstr(p3, str_, &l, true, sv1))
        goto _L1;
      sprintf(svar, sv1, re2);
      i = strlen(svar);
      putatm(svar, i, &atm);
      gets1(rez, &x.sa);
      WITH1 = x.sad;
      WITH1->dtype = atom;
      WITH1->name = atm;
      goto _L1;
      break;

    case 'Q':
      if (re2 > 0)
        re1 = sqrt(re2);
      else
        goto _L1;
      break;
    case 'X':
      re1 = exp(re2);
      break;
    case 'L':
      if (re2 > 0)
        re1 = log(re2);
      else
        goto _L1;
      break;

    case 't':
      if (!strncmp("tSIN", str1_, 4))
        re1 = sin(re2);
      else if (!strncmp("tCOS", str1_, 4))
        re1 = cos(re2);
      else if (!strncmp("tTAN", str1_, 4))
        re1 = tan(re2);
      else if (!strncmp("tASIN", str1_, 5))
        re1 = asin(re2);
      else if (!strncmp("tACOS", str1_, 5))
        re1 = acos(re2);
      else if (!strncmp("tATAN", str1_, 5))
        re1 = atan(re2);
      break;

    default:
      if (!plstr(p3, str_, &l, false, sv1))
        goto _L1;
      if (l != real_size)
        goto _L1;
      refr3 = (double *)str_;
      /*   re3 = *refr3; */
      memcpy(&re3, refr3, sizeof(double));

      switch (c1)
      { /*5*/

      case '+':
        re1 = re2 + re3;
        break;

      case '-':
        re1 = re2 - re3;
        break;

      case '*':
        re1 = re2 * re3;
        break;

      case '/':
        if (re3 == 0)
          goto _L1;
        re1 = re2 / re3;
        break;

      case '=':
        if (re2 == re3)
          *rez = p2;
        goto _L1;
        break;

      case '>':
        if (c2_ == '=')
        {
          if (re2 >= re3)
            *rez = p2;
        }
        else
        {
          if (re2 > re3)
            *rez = p2;
        }
        goto _L1;
        break;

      case '<':
        if (c2_ == '=')
        {
          if (re2 <= re3)
            *rez = p2;
        }
        else if (c2_ == '>')
        {
          if (re2 != re3)
            *rez = p2;
        }
        else if (re2 < re3)
          *rez = p2;
        goto _L1;
        break;

      case 'P':
        re1 = pow(re2, re3);
        break;

      default: /* wrong real operation */
        goto _L1;
        break;
      } /*5*/
      /*4*/
      break;
    } /*3*/
    /*2*/
    break;
  } /*1*/
  /* this part processes only + - * / s(str->real) i(int->real) */
  refr2 = (double *)svar;
  /*  *refr2 = re1; */
  memcpy(refr2, &re1, sizeof(double));

  putatm(svar, real_size, &atm);
  gets1(rez, &x.sa);
  WITH1 = x.sad;
  WITH1->dtype = fatom;
  WITH1->name = atm;
_L1:;
}

/* these procedures currently are used in ibm/pc version
   of rigal. don't use them for future compatibility */
Void use_2(p1, p2, p3, rez)
long p1, p2, p3, *rez;
{
}

Void use_3(p1, p2, p3, rez)
long p1, p2, p3, *rez;
{
}

Void use_5(p1, p2, p3, rez)
long p1, p2, p3, *rez;
{
}

Void use_6(p1, p2, p3, rez)
long p1, p2, p3, *rez;
{
}

Void use_7(p1, p2, p3, rez)
long p1, p2, p3, *rez;
{
}

Void use_8(p1, p2, p3, rez)
long p1, p2, p3, *rez;
{
}

Void use_11(p1, p2, p3, rez)
long p1, p2, p3, *rez;
{
}

Void use_17(p1, p2, p3, rez)
long p1, p2, p3, *rez;
{
}

Void use_18(p1, p2, p3, rez)
long p1, p2, p3, *rez;
{
}

Void use_22(p1, p2, p3, rez)
long p1, p2, p3, *rez;
{
}

Void use_23(p1, p2, p3, rez)
long p1, p2, p3, *rez;
{
}

Void use_24(p1, p2, p3, rez)
long p1, p2, p3, *rez;
{
}

Void use_25(p1, p2, p3, rez)
long p1, p2, p3, *rez;
{
}

Void use_26(p1, p2, p3, rez)
long p1, p2, p3, *rez;
{
}

Void use_27(p1, p2, p3, rez)
long p1, p2, p3, *rez;
{
}

Void use_28(p1, p2, p3, rez)
long p1, p2, p3, *rez;
{
}

Void use_29(p1, p2, p3, rez)
long p1, p2, p3, *rez;
{
}

Void use_32(p1, p2, p3, rez)
long p1, p2, p3, *rez;
{
}

Void use_33(p1, p2, p3, rez)
long p1, p2, p3, *rez;
{
}

Void use_34(p1, p2, p3, rez)
long p1, p2, p3, *rez;
{
}

Void use_37(p1, p2, p3, rez)
long p1, p2, p3, *rez;
{
}

Void use_39(p1, p2, p3, rez)
long p1, p2, p3, *rez;
{
}

Void use_47(p1, p2, p3, rez)
long p1, p2, p3, *rez;
{
}

Void use_48(p1, p2, p3, rez)
long p1, p2, p3, *rez;
{
}

Void use_49(p1, p2, p3, rez)
long p1, p2, p3, *rez;
{
}

Void use_50(p1, p2, p3, rez)
long p1, p2, p3, *rez;
{
}

Void use_51(p1, p2, p3, rez)
long p1, p2, p3, *rez;
{
}

Void use_52(p1, p2, p3, rez)
long p1, p2, p3, *rez;
{
}

Void use_53(p1, p2, p3, rez)
long p1, p2, p3, *rez;
{
}

Void use_54(p1, p2, p3, rez)
long p1, p2, p3, *rez;
{
}

Void use_55(p1, p2, p3, rez)
long p1, p2, p3, *rez;
{
}

Void use_56(p1, p2, p3, rez)
long p1, p2, p3, *rez;
{
}

Void use_57(p1, p2, p3, rez)
long p1, p2, p3, *rez;
{
}

Void use_58(p1, p2, p3, rez)
long p1, p2, p3, *rez;
{
}

Void use_59(p1, p2, p3, rez)
long p1, p2, p3, *rez;
{
}

Void use_60(p1, p2, p3, rez)
long p1, p2, p3, *rez;
{
}

Void use_61(p1, p2, p3, rez)
long p1, p2, p3, *rez;
{
}

Void use_62(p1, p2, p3, rez)
long p1, p2, p3, *rez;
{
}

Void use_63(p1, p2, p3, rez)
long p1, p2, p3, *rez;
{
}

Void use_64(p1, p2, p3, rez)
long p1, p2, p3, *rez;
{
}

Void use_65(p1, p2, p3, rez)
long p1, p2, p3, *rez;
{
}

Void use_66(p1, p2, p3, rez)
long p1, p2, p3, *rez;
{
}

Void use_67(p1, p2, p3, rez)
long p1, p2, p3, *rez;
{
}

Void use_68(p1, p2, p3, rez)
long p1, p2, p3, *rez;
{
}

Void use_69(p1, p2, p3, rez)
long p1, p2, p3, *rez;
{
}

Void use_70(p1, p2, p3, rez)
long p1, p2, p3, *rez;
{
}

Void use_71(p1, p2, p3, rez)
long p1, p2, p3, *rez;
{
}

Void use_72(p1, p2, p3, rez)
long p1, p2, p3, *rez;
{
}

Void use_73(p1, p2, p3, rez)
long p1, p2, p3, *rez;
{
}

Void use_74(p1, p2, p3, rez)
long p1, p2, p3, *rez;
{
}

Void use_75(p1, p2, p3, rez)
long p1, p2, p3, *rez;
{
}

Void use_76(p1, p2, p3, rez)
long p1, p2, p3, *rez;
{
}

Void use_77(p1, p2, p3, rez)
long p1, p2, p3, *rez;
{
}

Void use_81(p1, p2, p3, rez)
long p1, p2, p3, *rez;
{
}

Void use_82(p1, p2, p3, rez)
long p1, p2, p3, *rez;
{
}

Void use_83(p1, p2, p3, rez)
long p1, p2, p3, *rez;
{
}

Void use_84(p1, p2, p3, rez)
long p1, p2, p3, *rez;
{
}

Void use_89(p1, p2, p3, rez)
long p1, p2, p3, *rez;
{
}

Void use_94(p1, p2, p3, rez)
long p1, p2, p3, *rez;
{
}

Void use_95(p1, p2, p3, rez)
long p1, p2, p3, *rez;
{
}

Void use_96(p1, p2, p3, rez)
long p1, p2, p3, *rez;
{
}

Void use_97(p1, p2, p3, rez)
long p1, p2, p3, *rez;
{
}

Void use_98(p1, p2, p3, rez)
long p1, p2, p3, *rez;
{
}

Void use_99(p1, p2, p3, rez)
long p1, p2, p3, *rez;
{
}

Void use_100(p1, p2, p3, rez)
long p1, p2, p3, *rez;
{
}

Void use_101(p1, p2, p3, rez)
long p1, p2, p3, *rez;
{
}

Void use_102(p1, p2, p3, rez)
long p1, p2, p3, *rez;
{
}

Void use_103(p1, p2, p3, rez)
long p1, p2, p3, *rez;
{
}

Void use_104(p1, p2, p3, rez)
long p1, p2, p3, *rez;
{
}

Void use_105(p1, p2, p3, rez)
long p1, p2, p3, *rez;
{
}

Void use_106(p1, p2, p3, rez)
long p1, p2, p3, *rez;
{
}

Void use_107(p1, p2, p3, rez)
long p1, p2, p3, *rez;
{
}

Void use_109(p1, p2, p3, rez)
long p1, p2, p3, *rez;
{
}

Void use_112(p1, p2, p3, rez)
long p1, p2, p3, *rez;
{
}

Void use_113(p1, p2, p3, rez)
long p1, p2, p3, *rez;
{
}

Void use_114(p1, p2, p3, rez)
long p1, p2, p3, *rez;
{
}

Void use_115(p1, p2, p3, rez)
long p1, p2, p3, *rez;
{
}

Void use_117(p1, p2, p3, rez)
long p1, p2, p3, *rez;
{
}

Void use_118(p1, p2, p3, rez)
long p1, p2, p3, *rez;
{
}

Void use_119(p1, p2, p3, rez)
long p1, p2, p3, *rez;
{
}

/* these procedures are not used , you can use them ! */

Void use_120(p1, p2, p3, rez)
long p1, p2, p3, *rez;
{
}

Void use_122(p1, p2, p3, rez)
long p1, p2, p3, *rez;
{
}

Void use_123(p1, p2, p3, rez)
long p1, p2, p3, *rez;
{
}

Void use_124(p1, p2, p3, rez)
long p1, p2, p3, *rez;
{
}

Void use_125(p1, p2, p3, rez)
long p1, p2, p3, *rez;
{
}

Void use_126(p1, p2, p3, rez)
long p1, p2, p3, *rez;
{
}

Void use_127(p1, p2, p3, rez)
long p1, p2, p3, *rez;
{
}

Void use_128(p1, p2, p3, rez)
long p1, p2, p3, *rez;
{
}

Void use_129(p1, p2, p3, rez)
long p1, p2, p3, *rez;
{
}

Void use_130(p1, p2, p3, rez)
long p1, p2, p3, *rez;
{
}

Void use_131(p1, p2, p3, rez)
long p1, p2, p3, *rez;
{
}

Void use_132(p1, p2, p3, rez)
long p1, p2, p3, *rez;
{
}

Void use_133(p1, p2, p3, rez)
long p1, p2, p3, *rez;
{
}

Void use_134(p1, p2, p3, rez)
long p1, p2, p3, *rez;
{
}

Void use_135(p1, p2, p3, rez)
long p1, p2, p3, *rez;
{
}

Void use_136(p1, p2, p3, rez)
long p1, p2, p3, *rez;
{
}

Void use_137(p1, p2, p3, rez)
long p1, p2, p3, *rez;
{
}

Void use_138(p1, p2, p3, rez)
long p1, p2, p3, *rez;
{
}

Void use_139(p1, p2, p3, rez)
long p1, p2, p3, *rez;
{
}

Void use_140(p1, p2, p3, rez)
long p1, p2, p3, *rez;
{
}

Void use_141(p1, p2, p3, rez)
long p1, p2, p3, *rez;
{
}

Void use_142(p1, p2, p3, rez)
long p1, p2, p3, *rez;
{
}

Void use_143(p1, p2, p3, rez)
long p1, p2, p3, *rez;
{
}

Void use_144(p1, p2, p3, rez)
long p1, p2, p3, *rez;
{
}

Void use_145(p1, p2, p3, rez)
long p1, p2, p3, *rez;
{
}

Void use_146(p1, p2, p3, rez)
long p1, p2, p3, *rez;
{
}

Void use_147(p1, p2, p3, rez)
long p1, p2, p3, *rez;
{
}

Void use_148(p1, p2, p3, rez)
long p1, p2, p3, *rez;
{
}

Void use_149(p1, p2, p3, rez)
long p1, p2, p3, *rez;
{
}

Void use_150(p1, p2, p3, rez)
long p1, p2, p3, *rez;
{
}

/* End. */
