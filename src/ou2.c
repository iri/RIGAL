#include "globrig.h"
#include "define.h"
#include "defpage.h"
#include "ley.h"
#include "nef2.h"

#define sh_depth 2

/* Local variables for pscr: */
struct LOC_pscr
{
  mpd x;
  long shift;
  bl80 str80;
};

Local long sh_atom(atm, LINK)
long atm;
struct LOC_pscr *LINK;
{
  /*length of atom*/
  long len;

  pointa(atm, LINK->str80, &len);
  return (len + 1);
}

Local long sh_rec(root, LINK)
long root;
struct LOC_pscr *LINK;
{
  /*length of rigal object*/
  /** recursive **/
  long Result, sum;
  ptr_ pp;

  if (root == 0)
  {
    Result = 5;
    goto _L99;
  }
  if ((root & 511) == 0 && root < 65536L && root >= 0)
  {
    Result = 8;
    goto _L99;
  }
  pointr(root, &LINK->x.sa);
  switch (LINK->x.sad->dtype)
  { /* with */

  case listmain:
    LINK->shift += sh_depth;
    if (LINK->shift / sh_depth > max_printlevel)
    {
      Result = 12;
      LINK->shift -= sh_depth;
      goto _L99;
    }
    sum = 0;
    if (LINK->x.smld->name != 0)
      sum += sh_rec(LINK->x.smld->name, LINK) + 1;
    first(root, &pp);
    while (pp.nel != 0)
    {
      sum += sh_rec(pp.cel, LINK);
      if (sum > 150)
      {
        Result = sum;
        LINK->shift -= sh_depth;
        goto _L99;
      }
      next(&pp);
    }
    Result = sum + 5;
    LINK->shift -= sh_depth;
    break;

  case treemain:
    LINK->shift += sh_depth;
    if (LINK->shift / sh_depth > max_printlevel)
    {
      Result = 12;
      LINK->shift -= sh_depth;
      goto _L99;
    }
    sum = 0;
    if (LINK->x.smtd->name != 0)
      sum += sh_rec(LINK->x.smtd->name, LINK) + 2;
    first(root, &pp);
    while (pp.nel != 0)
    {
      sum += sh_atom(pp.UU.U1.arc, LINK) + sh_rec(pp.cel, LINK) + 2;
      if (sum > 150)
      {
        Result = sum;
        LINK->shift -= sh_depth;
        goto _L99;
      }
      next(&pp);
    }
    Result = sum + 4;
    LINK->shift -= sh_depth;
    break;

  case idatom:
  case atom:
  case tatom:
  case keyword:
    Result = sh_atom(LINK->x.sad->name, LINK) + 2;
    break;

  case fatom:
    Result = 14;
    break;

  case number:
    if (LINK->x.snd->val > 65536L)
      Result = 10;
    else
    {
      if (LINK->x.snd->val > 99)
        Result = 5;
      else
        Result = 2;
    }
    break;

  case variable:
  case idvariable:
  case fvariable:
  case nvariable:
    Result = sh_atom(LINK->x.svd->name, LINK) + 1;
    break;

  case rulename:
    Result = sh_atom(LINK->x.srd->name, LINK) + 1;
    break;

  default:
    Result = 80;
    break;
  } /* case */
_L99:
  return Result;
}

Local boolean is_short(root, LINK)
long root;
struct LOC_pscr *LINK;
{
  long i_shorts;

  i_shorts = sh_rec(root, LINK);
  return (i_shorts < 80 - LINK->shift);
}

Local Void printunit(un, LINK)
long un;
struct LOC_pscr *LINK;
{
  long ilen, i;

  pointa(un, LINK->str80, &ilen);
  for (i = 0; i < ilen; i++)
  {
    putchar(LINK->str80[i]);
    if (LINK->str80[i] == '\'')
      putchar('\'');
  }
}

Local Void poutrec(root, sm, LINK)
long root;
boolean sm;
struct LOC_pscr *LINK;
{
  /** recursive **/
  ptr_ pp;
  boolean nofirstflag, treenamed;

  if (!sm)
  {
    if (is_short(root, LINK))
    {
      poutrec(root, true, LINK);
      goto _L99;
    }
  }

  if (root == 0)
  {
    printf(" NULL ");
    goto _L99;
  }
  if ((root & 511) == 0 && root < 65536L && root >= 0)
  {
    printf(" a'%5ld ", root);
    goto _L99;
  }

  pointr(root, &LINK->x.sa);
  /* write( ' '); */
  switch (LINK->x.sad->dtype)
  { /* with */

  case listmain:
    if (!sm)
      putchar('\n');
    LINK->shift += sh_depth;
    if (!sm)
      printf("%*s", (int)LINK->shift, "  ");
    /* pe~atx spiska - pe~atx zagolowka,
       ustanowka na perwyj |lement, */
    if (LINK->x.smld->name != 0)
    {
      poutrec(LINK->x.smld->name, sm, LINK);
      printf("::");
      if (!sm)
        putchar('\n');
      if (!sm)
        printf("%*s", (int)LINK->shift, "  ");
    }
    printf("(.");
    if (LINK->shift / sh_depth > max_printlevel)
    {
      printf(" .. .)");
      if (!sm)
        putchar('\n');
    }
    else
    {
      first(root, &pp);
      while (pp.nel != 0)
      {
        poutrec(pp.cel, sm, LINK);
        next(&pp);

        if (pp.nel == mainlistelnum)
        {
          putchar('\n');
          if (!sm)
            printf("%*s", (int)(LINK->shift + sh_depth), "   ");
        }
        putchar(' ');
      }

      if (!sm)
        putchar('\n');
      if (!sm)
        printf("%*s", (int)LINK->shift, "  ");
      printf(".)");
      if (!sm)
        putchar('\n');
    }
    if (!sm)
      printf("%*c", (int)LINK->shift, ' ');
    LINK->shift -= sh_depth;
    break;

  case treemain:
    if (!sm)
      putchar('\n');
    LINK->shift += sh_depth;
    if (!sm)
      printf("%*c", (int)LINK->shift, ' ');
    treenamed = false;
    if (LINK->x.smtd->name != 0)
    {
      treenamed = true;
      poutrec(LINK->x.smtd->name, sm, LINK);
      printf("::");
      if (!sm)
        putchar('\n');
      if (!sm)
        printf("%*c", (int)LINK->shift, ' ');
    }
    if (LINK->shift / sh_depth > max_printlevel)
      printf("<. .. .>\n");
    else
    {
      printf("<.");
      first(root, &pp);
      nofirstflag = false;
      while (pp.nel != 0)
      {
        if (nofirstflag)
        {
          putchar(',');
          if (!sm)
            putchar('\n');
          if (!sm)
            printf("%*c", (int)(LINK->shift + sh_depth), ' ');
        }
        nofirstflag = true;
        /* pe~atx |lementow derewa */
        printunit(pp.UU.U1.arc, LINK);
        putchar(':');
        poutrec(pp.cel, sm, LINK);
        next(&pp);
      }
      if (!sm)
        putchar('\n');
      if (!sm)
        printf("%*c", (int)LINK->shift, ' ');
      printf(".>");
    }
    LINK->shift -= sh_depth;
    /*if not sm then write( '   ': shift);*/
    break;

  case idatom:
  case atom:
  case tatom:
    putchar('\'');
    printunit(LINK->x.sad->name, LINK);
    putchar('\'');
    break;

  case keyword:
    printunit(LINK->x.sad->name, LINK);
    break;

  case fatom:
    /*    printf("% .5E", take_fatom(LINK->x.sad->name));*/
    printf("%E", take_fatom(LINK->x.sad->name));
    break;

  case number:
    printf("%12ld", LINK->x.snd->val);
    break;

  case variable:
  case idvariable:
  case fvariable:
  case nvariable:
    putchar('$');
    printunit(LINK->x.svd->name, LINK);
    /*  if ((svd^.location <> 0) and bb3) then
        write('(', svd^.location: 3, ')');*/
    break;

  case rulename:
    printf("  #");
    printunit(LINK->x.srd->name, LINK);
    /*           if ((srd^.fragmadr <> 0) and bb3) then
                  write('[[', srd^.fragmadr, ']]');*/

    break;

  case spec:
    printf("aspec'%6ld", LINK->x.sspec->val);
    break;

  default:
    printf("--/ ?? /--");
    break;
  } /* case */
_L99:;

} /* poutrec */

/*procedure pscr(xxx:a); begin end;*/
/* #include "p4.inc" */
/* #include "pscr.pas" */
/*  #include "poutx.pas"  */

/* ********************* pscr_.pas ******************* */
/* only procedure text/ implementation part of poutlexu */

Void pscr(root)
long root;
{
  /* have some local procedures */
  struct LOC_pscr V;

  if (true)
  {              /*out_open*/
    V.shift = 0; /* sdwig ot lewogo kraq stroki wywoda */
    poutrec(root, false, &V);
  } /* wyzow rekursiwnoj ~asti iz postoqnnoj pout */
}

#undef sh_depth

#define sh_depth 2

/* Local variables for pout: */
struct LOC_pout
{
  mpd x;
  long shift;
  bl80 str80;
};

Local long sh_atom_(atm, LINK)
long atm;
struct LOC_pout *LINK;
{
  /*length of atom*/
  long len;

  pointa(atm, LINK->str80, &len);
  return (len + 1);
}

Local long sh_rec_(root, LINK)
long root;
struct LOC_pout *LINK;
{
  /*length of rigal object*/
  /** recursive **/
  long Result, sum;
  ptr_ pp;

  if (root == 0)
  {
    Result = 5;
    goto _L99;
  }
  if ((root & 511) == 0 && root < 65536L && root >= 0)
  {
    Result = 8;
    goto _L99;
  }
  pointr(root, &LINK->x.sa);
  switch (LINK->x.sad->dtype)
  { /* with */

  case listmain:
    LINK->shift += sh_depth;
    if (LINK->shift / sh_depth > max_printlevel)
    {
      Result = 12;
      LINK->shift -= sh_depth;
      goto _L99;
    }
    sum = 0;
    if (LINK->x.smld->name != 0)
      sum += sh_rec_(LINK->x.smld->name, LINK) + 1;
    first(root, &pp);
    while (pp.nel != 0)
    {
      sum += sh_rec_(pp.cel, LINK);
      if (sum > 150)
      {
        Result = sum;
        LINK->shift -= sh_depth;
        goto _L99;
      }
      next(&pp);
    }
    Result = sum + 5;
    LINK->shift -= sh_depth;
    break;

  case treemain:
    LINK->shift += sh_depth;
    if (LINK->shift / sh_depth > max_printlevel)
    {
      Result = 12;
      LINK->shift -= sh_depth;
      goto _L99;
    }
    sum = 0;
    if (LINK->x.smtd->name != 0)
      sum += sh_rec_(LINK->x.smtd->name, LINK) + 2;
    first(root, &pp);
    while (pp.nel != 0)
    {
      sum += sh_atom_(pp.UU.U1.arc, LINK) + sh_rec_(pp.cel, LINK) + 2;
      if (sum > 150)
      {
        Result = sum;
        LINK->shift -= sh_depth;
        goto _L99;
      }
      next(&pp);
    }
    Result = sum + 4;
    LINK->shift -= sh_depth;
    break;

  case idatom:
  case atom:
  case tatom:
  case keyword:
    Result = sh_atom_(LINK->x.sad->name, LINK) + 2;
    break;

  case fatom:
    Result = 14;
    break;

  case number:
    if (LINK->x.snd->val > 65536L)
      Result = 10;
    else
    {
      if (LINK->x.snd->val > 99)
        Result = 5;
      else
        Result = 2;
    }
    break;

  case variable:
  case idvariable:
  case fvariable:
  case nvariable:
    Result = sh_atom_(LINK->x.svd->name, LINK) + 1;
    break;

  case rulename:
    Result = sh_atom_(LINK->x.srd->name, LINK) + 1;
    break;

  default:
    Result = 80;
    break;
  } /* case */
_L99:
  return Result;
}

Local boolean is_short_(root, LINK)
long root;
struct LOC_pout *LINK;
{
  long i_shorts;

  i_shorts = sh_rec_(root, LINK);
  return (i_shorts < 80 - LINK->shift);
}

Local Void printunit_(un, LINK)
long un;
struct LOC_pout *LINK;
{
  long ilen, i;

  pointa(un, LINK->str80, &ilen);
  for (i = 0; i < ilen; i++)
  {
    putc(LINK->str80[i], out);
    if (LINK->str80[i] == '\'')
      putc('\'', out);
  }
}

Local Void poutrec_(root, sm, LINK)
long root;
boolean sm;
struct LOC_pout *LINK;
{
  /** recursive **/
  ptr_ pp;
  boolean nofirstflag, treenamed;

  if (!sm)
  {
    if (is_short_(root, LINK))
    {
      poutrec_(root, true, LINK);
      goto _L99;
    }
  }

  if (root == 0)
  {
    fprintf(out, " NULL ");
    goto _L99;
  }
  if ((root & 511) == 0 && root < 65536L && root >= 0)
  {
    fprintf(out, " a'%5ld ", root);
    goto _L99;
  }

  pointr(root, &LINK->x.sa);
  /* write(out, ' '); */
  switch (LINK->x.sad->dtype)
  { /* with */

  case listmain:
    if (!sm)
      putc('\n', out);
    LINK->shift += sh_depth;
    if (!sm)
      fprintf(out, "%*s", (int)LINK->shift, "  ");
    /* pe~atx spiska - pe~atx zagolowka,
       ustanowka na perwyj |lement, */
    if (LINK->x.smld->name != 0)
    {
      poutrec_(LINK->x.smld->name, sm, LINK);
      fprintf(out, "::");
      if (!sm)
        putc('\n', out);
      if (!sm)
        fprintf(out, "%*s", (int)LINK->shift, "  ");
    }
    fprintf(out, "(.");
    if (LINK->shift / sh_depth > max_printlevel)
    {
      fprintf(out, " .. .)");
      if (!sm)
        putc('\n', out);
    }
    else
    {
      first(root, &pp);
      while (pp.nel != 0)
      {
        poutrec_(pp.cel, sm, LINK);
        next(&pp);

        if (pp.nel == mainlistelnum)
        {
          putc('\n', out);
          if (!sm)
            fprintf(out, "%*s", (int)(LINK->shift + sh_depth), "   ");
        }
        putc(' ', out);
      }

      if (!sm)
        putc('\n', out);
      if (!sm)
        fprintf(out, "%*s", (int)LINK->shift, "  ");
      fprintf(out, ".)");
      if (!sm)
        putc('\n', out);
    }
    if (!sm)
      fprintf(out, "%*c", (int)LINK->shift, ' ');
    LINK->shift -= sh_depth;
    break;

  case treemain:
    if (!sm)
      putc('\n', out);
    LINK->shift += sh_depth;
    if (!sm)
      fprintf(out, "%*c", (int)LINK->shift, ' ');
    treenamed = false;
    if (LINK->x.smtd->name != 0)
    {
      treenamed = true;
      poutrec_(LINK->x.smtd->name, sm, LINK);
      fprintf(out, "::");
      if (!sm)
        putc('\n', out);
      if (!sm)
        fprintf(out, "%*c", (int)LINK->shift, ' ');
    }
    if (LINK->shift / sh_depth > max_printlevel)
      fprintf(out, "<. .. .>\n");
    else
    {
      fprintf(out, "<.");
      first(root, &pp);
      nofirstflag = false;
      while (pp.nel != 0)
      {
        if (nofirstflag)
        {
          putc(',', out);
          if (!sm)
            putc('\n', out);
          if (!sm)
            fprintf(out, "%*c", (int)(LINK->shift + sh_depth), ' ');
        }
        nofirstflag = true;
        /* pe~atx |lementow derewa */
        printunit_(pp.UU.U1.arc, LINK);
        putc(':', out);
        poutrec_(pp.cel, sm, LINK);
        next(&pp);
      }
      if (!sm)
        putc('\n', out);
      if (!sm)
        fprintf(out, "%*c", (int)LINK->shift, ' ');
      fprintf(out, ".>");
    }
    LINK->shift -= sh_depth;
    /*if not sm then write(out, '   ': shift);*/
    break;

  case idatom:
  case atom:
  case tatom:
    putc('\'', out);
    printunit_(LINK->x.sad->name, LINK);
    putc('\'', out);
    break;

  case keyword:
    printunit_(LINK->x.sad->name, LINK);
    break;

  case number:
    fprintf(out, "%12ld", LINK->x.snd->val);
    break;

  case fatom:
    fprintf(out, "%E", take_fatom(LINK->x.sad->name));
    break;

  case variable:
  case idvariable:
  case fvariable:
  case nvariable:
    putc('$', out);
    printunit_(LINK->x.svd->name, LINK);
    /*--$ifdef harddeb*/
    /*               if ((svd^.location <> 0) and bb3) then
                     write('(', svd^.location: 3, ')');*/
    /*--$endif*/
    break;

  case rulename:
    fprintf(out, "  #");
    printunit_(LINK->x.srd->name, LINK);
    /*--$ifdef harddeb*/
    /*             if ((srd^.fragmadr <> 0) and bb3) then
                    write('[[', srd^.fragmadr, ']]');*/
    /*--$endif*/
    break;

  case spec:
    fprintf(out, "aspec'%6ld", LINK->x.sspec->val);
    break;

  default:
    fprintf(out, "--/ ?? /--");
    break;
  } /* case */
_L99:;

} /* poutrec */

/* ********************* poutx.pas ******************* */
/* only procedure text/ implementation part of poutlexu */

Void pout(root)
long root;
{
  /* have some local procedures */
  struct LOC_pout V;

  if (out_open)
  {
    V.shift = 0; /* sdwig ot lewogo kraq stroki wywoda */
    poutrec_(root, false, &V);
  } /* wyzow rekursiwnoj ~asti iz postoqnnoj pout */
}

#undef sh_depth

/* End. */
