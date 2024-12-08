#include <stdlib.h>
// #include <floatingpoint.h>
#include "globrig.h"
#include "define.h"
#include "defpage.h"

/*procedure argv(i:integer;var rez:string80);
  begin rez:=paramstr(i);end;
function argc:integer;
  begin argc:=paramcount+1;end;*/

long long_to_atom(a_long)
long a_long;
{
  a a_rez;
  mpd x;
  numberdescriptor *WITH;

  gets1(&a_rez, &x.sa);
  WITH = x.snd;
  WITH->dtype = number;
  WITH->cord = 0;
  WITH->val = a_long;
  return a_rez;
}

Char *real_to_string(Result, ar)
Char *Result;
double ar;
{
  sprintf(Result, "%E", ar);
  /*
    boolean neg;
    string80 bs, cs;

    neg = false;
    if (ar < 0) {
      ar = -ar;
      neg = true;
    }
    long_to_str(bs, (long)ar);
    long_to_str(cs, (long)((ar - (long)ar + 1.0) * 100000L));
    cs[0] = '.';
    if (neg) {
      sprintf(Result, "-%s%s", bs, cs);
      return Result;
    } else {
      sprintf(Result, "%s%s", bs, cs);
      return Result;
    }
  */
}

boolean is_rig_letter(let)
int let;
{
  return (isalpha(let) || (let == '_') || (let == '~') || (let == '|') || (let == '`') || (let == '{') || (let == '}'));
}

boolean is_rig_symbol(let)
int let;
{
  return (is_rig_letter(let) || isdigit(let));
}

char *_OutMem()
{
  printf(" **** Out of memory ****");
  exit(0);
}

void _EscIO(d) int d;
{
  printf(" ****** I/O Error *****");
  exit(0);
}

Char *real_to_string_f(Result, ar, dignum, afterpoint)
Char *Result; /* MANUAL CHANGE char to Char */
double ar;
long dignum, afterpoint;
{
  boolean neg;
  string80 bs, cs;
  double mult;
  long i;
  Char STR1[82];
  Char STR2[162];

  mult = 1.0;
  for (i = 1; i <= afterpoint; i++)
    mult *= 10;

  neg = false;
  if (ar < 0)
  {
    ar = -ar;
    neg = true;
  }
  long_to_str(bs, (long)ar);
  long_to_str(cs, (long)((ar - (long)ar + 1.0) * mult));
  cs[0] = '.';
  if (afterpoint == 0)
    *cs = '\0';
  if (neg)
    sprintf(bs, "-%s%s", strcpy(STR2, bs), cs);
  else
    strcat(bs, cs);
  if (strlen(bs) < dignum)
  {
    while (strlen(bs) != dignum)
      sprintf(bs, " %s", strcpy(STR1, bs));
  }
  strcpy(Result, bs); /* Splitted manually */
  return Result;
}

long str_to_atom(ssr_)
Char *ssr_;
{
  string80 ssr;
  long l;
  a rez;
  aa atm;
  longint intval;
  boolean id;
  long i;

  strcpy(ssr, ssr_);
  rez = null_;
  val(ssr, &intval, &l);
  if (l == 0)
  {
    rez = long_to_atom(intval);
    return rez;
  }
  else
  {
    rez = str_to_textatom(ssr);
    return rez;
  }
}

long str_to_textatom(ssr_)
Char *ssr_;
{
  string80 ssr;
  long l;
  a rez;
  aa atm;
  longint intval;
  boolean id;
  long i;
  mpd x;
  atomdescriptor *WITH;

  strcpy(ssr, ssr_);
  rez = null_;
  l = strlen(ssr);
  if (l == 0)
    return rez;
  id = is_rig_letter(ssr[0]);
  for (i = 0; i < l; i++)
    id &= is_rig_letter(ssr[i]);
  putatm(ssr, l, &atm); /* makes a-address */
  gets1(&rez, &x.sa);   /* makes s-address */
  /* fills descriptor */
  WITH = x.sad;
  if (id)
    WITH->dtype = idatom;
  else
    WITH->dtype = atom;
  WITH->name = atm;
  return rez;
}

Char *long_to_str(Result, int_)
Char *Result;
long int_;
{
  sprintf(Result, "%ld", int_);
  return (Result);
  /* *******************
    string80 rezstr;
    boolean neg;
    Char STR1[256];
    Char STR2[82];

    neg = false;
    if (int_ < 0) {
      int_ = -int_;
      neg = true;
    }
    *rezstr = '\0';
    do {
      sprintf(STR1, "%c", (Char)(int_ % 10 + rezstr + '0'));
      strcpy(rezstr, STR1);
   p2c: defsun3.z, line 541:
   * Note: Using % for possibly-negative arguments [317]
      int_ /= 10;
    } while (int_ != 0);
    if (neg)
      sprintf(rezstr, "-%s", strcpy(STR2, rezstr));
    printf("SC=%s",strcpy(Result,rezstr));
    printf("RE=%s",Result);
    return strcpy(Result, rezstr);
   ************************ */
}

Char *aa_str(Result, a1)
Char *Result;
long a1;
{
  bl80 b80;
  long len;
  Char STR2[256];

  pointa(a1, b80, &len);

  sprintf(STR2, "%.80s", b80);
  sprintf(Result, "%.*s", (int)len, STR2);
  return Result;
}

Void val(m, intval, rez)
Char *m;
long *intval, *rez;
{
  /* converts string to longint. returns 0 if normal terminated */
  int i;
  boolean sign;
  i = 1;
  *intval = 0;
  *rez = 1;
  sign = false;
  if (m[0] == '-')
  {
    sign = true;
    i++;
  }
  if (m[0] == '+')
    i++;
  while ((i <= strlen(m)) && isdigit(m[i - 1]))
  {
    *intval = *intval * 10 + m[i - 1] - '0';
    i++;
  }
  if (i <= strlen(m))
  {
    *rez = i;
    *intval = 0;
  }
  else
    *rez = 0;
  if (sign)
    *intval = -*intval;
}

Void val2(st_, r, code)
Char *st_;
double *r;
long *code;
{
  char *res; /* Help variable , used to analyze the result of "strtod" */
  res = st_;
  *r = strtod(st_, &res);
  if ((res != st_) && (res >= st_ + strlen(st_)))
    *code = 0; /* Correct value */
  else
    *code = 1; /* Incorrect value */

  /*
    string80 st;
    long i, l;
    double rx;
    boolean sign;
    long SET[3];
    long SET1[9];

    strcpy(st, st_);
    *code = 0;
    i = 1;
    l = strlen(st);
    *r = 0.0;
    while (i <= l && st[i - 1] == ' ')
      i++;
    if (i <= l && st[i - 1] == '-') {
      sign = true;
      i++;
    } else
      sign = false;
    if ((i > l) | (!
    ( isdigit(st[i-1]) || (st[i-1]=='.') )
  #ifdef xxx
    P_inset(st[i - 1],
      P_setunion
       (SET1, digit,
      P_addset(P_expset(SET, 0L), '.')))
  #endif

      ))
   {
      *code = i;
      *r = 0.0;
      goto _L1;
    }
    while ((i <= l) && isdigit(st[i - 1])) {
      *r = *r * 10 + st[i - 1] - '0';
      i++;
    }
    if (i <= l && st[i - 1] == '.') {
      i++;
      rx = 1.0;
      while ((i <= l) && isdigit(st[i - 1])) {
        rx /= 10.0;
        *r += rx * (st[i - 1] - '0');
        i++;
      }
    }

    if (i != l + 1) {
      *code = i;
      *r = 0.0;
    }
    if (sign)
      *r = -*r;
  _L1: ;

  */
}

Void brt(p1)
Char *p1;
{
  long i;
  Char STR1[256];

  i = 1;
  while (i <= strlen(p1) && p1[i - 1] != ' ')
    i++;
  /* writeln('i=',i);*/
  sprintf(p1, "%.*s", (int)(i - 1), strcpy(STR1, p1));
}

FILE *fi;

boolean existfile(fname)
Char *fname;
{
  FILE *FF;
  /* returns true if it is screen file ('') or existing disk file */
  FF = fopen(fname, "r");
  if (FF != 0)
    fclose(FF);
  return (FF != 0);
}

boolean rightfile(fname)
Char *fname;
{

  /* returns true if it is screen or nul (dummy) or valid disk file
     ( former version is erased (!) )  */
  return true;
}
