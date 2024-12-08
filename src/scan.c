#include "globrig.h"
#include "define.h"
#include "defpage.h"
#include "scan.h"
#include "nef2.h"
/*4-jul-93 invented maxline as length of input line*/
#define maxline 255

typedef unsigned char bigstring[maxline + 1];

/* changes:
   11-nov-92
    now in m+ mode "ab""cd" is accespted as ab"cd value
    earlier it were two values "ab" and "cd"

   mar-93
    now mif conditional definition is available.
   may-93
    now tex scaner is available.
     t+ defines latex lexical rules
     and value of new "tex_lexics" boolean variable
     @+ defines (additionaly to t+) .sty - file mode of latex,
      when @ characters are allowed in command names

    .tex file have to be with 'P-U-p-A-T+'
    .sty file have to be with 'P-U-p-A-T+@+'
  may - 95
    You can use # ifdef russian if want capitalization
    of characters according to russian ALTernaticve coding
    of characters. Earlier it was default and
    could lead to problems.
*/

#define new_line_code '\015' /* chr(0 is allowed too */
#define endfile_code '\032'

#define is_control 0
#define is_letter 1
#define is_digit 2
#define is_underscore 3
#define is_printable 4
#define is_special 5
#define is_space 6
#define is_first_of_two 7

typedef unsigned char pair[2];

a a1;  /* global variable for only local use */
       /*aa1 : aa ;*/
       /* --"-- */
mpd x; /* --"-- */
bl80 bl801;
/* -- " -- */
/* array[1..80] of char*/
long k, kk; /* -"- */
unsigned char c1;

word saved_coord; /* where current token began */
word coord_mark;  /* what was set by coordinate marker */
word line_byte_number;
/* number of totally read bytes till beginning
                      of current line */
word last_mark_byte_number;
/* number of totally read bytes till
                       last coordinate marker */
/* length of the current line,
                   used only for incrementation of "lyne_byte_number"*/
word old_line_length;
unsigned char dt;
/* type of last read token or control character */
a aadr;              /* a-space address of last read token */
longint linenumber;  /* current line number */
longint tokennumber; /* current token number */
a errlist;           /* list of numbers of errors */
long read_mode;      /* 1,2,3 */
ptr_ ptr1;           /* list pointer when read from list of atoms */

FILE *inpfile;
boolean c_lexics, pascal_lexics, sty_lexics, tex_lexics, row80_coord,
    byte_coord, mark_byte_coord, mark_only_coord, string_coord,
    char_coord, token_coord, collect_errors, screen_errors,
    to_uppercase, pascal_comment, c_comment, ada_comment,
    pascal_string, modula_string;
bigstring s, s_for_val; /* added 17-feb-92 */
long i;
unsigned char as[256];
unsigned char isa;
unsigned Char upcase_tab[256];
unsigned char set_of_second_of_two[9]; /* long -> char */
long two_char_symbols_num;
pair two_char_symbols[30];

union
{
  unsigned Char b1;
  unsigned Char b2[2];
  unsigned Char b3[3];
} b123;

boolean in_comment, in_string, is_2quote;
/* if in_string then it is possible */
longint str_constlen;
string80 str_const; /* array of char is allowed too */

/*=====  sun version ===*/
Static Void jnc(xxx)
long *xxx;
{
  (*xxx)++;
}

Static Void jnc2(xxx, yyy)
long *xxx, yyy;
{
  *xxx += yyy;
}

Static Void jncx(xxx)
long *xxx;
{
  (*xxx)++;
}

Static Void jnc2x(xxx, yyy)
long *xxx, yyy;
{
  *xxx += yyy;
}

/*=====*/

Static unsigned Char cont_char_to_dt PP((int c));

Static word getcoord PV();

Static Void er_lex PP((long er_number));

/*procedure initialize_scan_variables;forward;*/
Static Void read_file PP((long *read_file_rez));

Static long read_item PP((long *pghead));

Static Void readline PV();

Static Void putatom PP((long j));

Static Void putit PP((unsigned Char dd, long j));

Static Void putident PP((long j));

Static Void putfloat PP((long j));

Static Void putnumber PV();

Static Void putstr PP((unsigned Char dd));

/*procedure scaner;forward;*/
Static Void setlexics PV();

Static Void stradd PP((int c));

Static Void strbegin PV();

Static Void token PV();

Static long take_digits PP((long *jj));

Static long take_letters PV();

/* uses global string, received from readline procedure,
   produces global attributes of new one token read.
   some variables also should be initialized if by initial_token
   procedure at the start of the whole programm */

/* this procedure is oriented to turbo pascal language */
/* procedure call graph follows :
                                  /self\
  usepas -> scan -> readfile -> readitem  ->  addel.nef
                             -> lconc.nef     er_lex
                 -> setoptions                gets1.defpage
                 -> first.nef                 token
                 -> assign.system             pointr.defpage
                 -> reset.system              lconc.nef
                 -> readline


  token    -> er
                -> read_letters_or_digits
                -> read_digits
                -> strbegin
                -> putnumber
                -> stradd -> er
                -> putstr -> putatm.defpage
                -> putatom ->\
                -> putfloat     -> putit -> putatm.defpage
                -> putident     ->/
*/

Static unsigned Char cont_char_to_dt(c)
unsigned Char c;
{
  /************************************************/
  return ((unsigned Char)c);
}

Static word getcoord()
{
  /*************************/
  if (row80_coord)
    return (i + linenumber * 80);
  else
  {
    if (mark_only_coord)
      return coord_mark;
    else
    {
      if (mark_byte_coord)
        return (coord_mark + line_byte_number + i - last_mark_byte_number);
      else
      {
        if (byte_coord)
          return (line_byte_number + i);
        else
        {
          if (string_coord)
            return linenumber;
          else
          {
            if (token_coord)
              return tokennumber;
            else
              return 0;
          }
        }
      }
    }
  }
}

Static Void er_lex(er_number)
long er_number;
{
  /*************************************/
  a er_atom;
  word co;
  numberdescriptor *WITH;

  co = getcoord();
  if (collect_errors)
  {
    gets1(&er_atom, &x.sa);
    WITH = x.snd; /*global*/
    WITH->dtype = number;
    WITH->cord = co;
    WITH->val = er_number;
    lconc(&errlist, er_atom);
  }
  if (screen_errors)
    printf("Lexical error (%12ld) line=%12d column=%12d\n",
           er_number, co / 80, co % 80);
}

Void initialize_scan_variables()
{

  /*************************************/
  unsigned Char c;
  short TEMP;

  for (TEMP = '\0'; TEMP <= 255; TEMP++)
  {
    c = TEMP;
    upcase_tab[c] = c;
  }
  for (c = 'a'; c <= 'z'; c++) /*ascii*/
    upcase_tab[c] = c - 32;

#ifdef russian
  for (TEMP = 160; TEMP <= 175; TEMP++)
  {
    c = TEMP;
    upcase_tab[c] = c - 32;
  }
  /*russian*/
  for (TEMP = 224; TEMP <= 239; TEMP++)
  {
    c = TEMP;
    upcase_tab[c] = c - 60;
  }
  /*russian*/
#endif

  for (c = '\0'; c <= '\037'; c++)
    as[c] = is_control;
  for (TEMP = 128; TEMP <= 255; TEMP++)
  {
    c = TEMP;
    as[c] = is_letter;
  }
  /* russian and pseudographics */
  for (TEMP = ' '; TEMP <= '\177'; TEMP++)
  {
    c = TEMP;
    /* not used actually */

    as[c] = is_printable;
  }
  as[new_line_code] = is_control;

  as[' '] = is_space;
  as['\t'] = is_space;
  /* these are allowed to be first letter of identifiers */
  for (c = 'A'; c <= 'Z'; c++)
    as[c] = is_letter;
  for (c = 'a'; c <= 'z'; c++)
    as[c] = is_letter;
  for (c = '0'; c <= '9'; c++)
    as[c] = is_digit;
  /* allowed to be non-first letter of odentifier */
  as['_'] = is_underscore;

  /* all the rest settings - see procedure setlexics */
}

Static Void read_file(read_file_rez)
long *read_file_rez;
{
  /********************************/
  /* reads whole input, produces list of items */
  a head;

  *read_file_rez = null_;
  do
  {
    a1 = read_item(&head);
    if (dt == start_tree || dt == end_tree || dt == start_list ||
        dt == end_list || dt == name_obj)
    {
      er_lex(6L);
      goto _L99;
    }
    if (dt != eof_desk)
    {
      if (head != null_)
        lconc(read_file_rez, head);
      lconc(read_file_rez, a1);
    }
  } while (dt != eof_desk);
_L99:;
}

Static long read_item(pghead)
long *pghead;
{
  /**********************/
  long Result;
  a aadr1, result, temp_res, dum;
  atomdescriptor *WITH;
  numberdescriptor *WITH1;

  Result = null_; /* default value for exits with errors */
  *pghead = null_;
  result = null_;
  token();

  /*writeln('DT=',dt,ord(dt));*/

  switch (dt)
  {

  case atom:
  case idatom:
  case tatom:
  case fatom:
  case keyword:
    gets1(&result, &x.sa);
    WITH = x.sad;
    WITH->dtype = dt;
    WITH->cord = saved_coord;
    WITH->name = aadr;
    break;

  case number:
    gets1(&result, &x.sa);
    WITH1 = x.snd;
    WITH1->dtype = dt;
    WITH1->cord = saved_coord;
    WITH1->val = aadr; /* is set in token .. is_digit */
    break;

  case dummy:
    result = null_;
    break;

  case start_tree:
    result = null_;
    do
    {
      token();
      aadr1 = aadr; /* to save */
      if (dt == idatom || dt == atom || dt == tatom || dt == keyword)
      {
        /* what is allowed selector in scaner input ?
           normally - idatom only, but here
           atom is allowed too - for experiment purposes */
        a1 = read_item(&dum);
        if (dt == end_list)
        {
          er_lex(6L);
          goto _L99;
        }
        if (dt == eof_desk)
        {
          er_lex(1L);
          goto _L99;
        }
        addel3(&result, aadr1, a1);
      }
      else if (dt != end_tree)
      {
        er_lex(2L);
        goto _L99;
      }
    } while (dt != end_tree && dt != eof_desk);
    if (dt == eof_desk)
    {
      er_lex(3L);
      goto _L99;
    }
    dt = complex_desk;
    /* to ignore analysis in upper level of
                        recursion */
    break;

  case start_list:
    result = null_;

    do
    {
      a1 = read_item(&dum);
      if (dt == eof_desk)
      {
        er_lex(4L);
        goto _L99;
      }
      if (dt != end_list)
        lconc(&result, a1);
    } while (dt != end_list);

    dt = complex_desk;
    break;

  case end_tree:
    er_lex(5L);
    goto _L99;
    break;

  case end_list:
    break;
    /*immodiately returns to the upper level*/

  case name_obj:
    temp_res = read_item(&dum);
    if (dt == end_list)
    {
      er_lex(6L);
      goto _L99;
    }
    if (dt == eof_desk)
    {
      er_lex(7L);
      goto _L99;
    }
    result = read_item(&dum);
    if (dt == end_list)
    {
      er_lex(6L);
      goto _L99;
    }
    if (dt == eof_desk)
    {
      er_lex(8L);
      goto _L99;
    }
    if (result != null_)
    {
      points(result, &x.sa);
      if (x.smld->dtype == listmain || x.smtd->dtype == treemain)
        x.smtd->name = temp_res;
    }
    dt = complex_desk;
    break;

  case eof_desk:
    break;
    /* returns to the upper level */

  default:
    er_lex(9L);
    goto _L99; /* impossible value */
    break;
  } /* case */
  Result = result;
_L99:
  return Result;
} /* read_item */

Static Void readline()
{
  /*****************************/
  /* sets new values for "s" and "i" global variables */
  unsigned Char c;
  long rline;
  atomdescriptor *WITH;
  long FORLIM;
  int fff;
  int len;
  i = 1;
  /* in any case, so; only here it is initialized.
          it is column number.
          variable "s" is string only for speed purposes;
          it plays exactly as packed array of char,
          never used as whole and the length byte is never used */
  linenumber++;
  line_byte_number += old_line_length;
  if (read_mode == 1)
  {
    if (feof(inpfile))
      s[0] = endfile_code;
    else
    {
      /*readln(inpfile,s);*/
      /* Here we want to obtain C string with
         new_line_code at the end if there is end of line */
      if (fgets((char *)s, maxline - 1, inpfile))
      {
        len = strlen((char *)s);
        if (len >= maxline - 2)
          printf(" FATAL ERROR: Line %12ld too long !\n", linenumber);
        /*printf("\n Input=<%s> \n",s); */

        /* This place have been corrected in version 4.46
           in order to handle last line of the file with
           \n missing */
        if (s[len - 1] == '\n')
        {
          s[len - 1] = new_line_code;
        }
        else
        {
          s[len] = new_line_code;
          s[len + 1] = '\0';
        }
        old_line_length = len;
      }
      else
        s[0] = endfile_code;
    }
  }
  else
  {
    if (read_mode == 2)
    {
      if (ptr1.nel == 0)
      {
        s[0] = endfile_code;
        goto _L99;
      }
      if (ptr1.cel == 0)
      {
        s[0] = new_line_code;
        old_line_length = 0;
      }
      else
      {
        pointr(ptr1.cel, &x.sa);
        WITH = x.sad; /* with */
        if (WITH->dtype == atom || WITH->dtype == idatom ||
            WITH->dtype == fatom ||
            WITH->dtype == tatom || WITH->dtype == keyword)
        {
          pointa(WITH->name, bl801, &k);
          FORLIM = k;
          for (kk = 1; kk <= FORLIM; kk++)
            s[kk - 1] = bl801[kk - 1];
          old_line_length = k;
          s[k] = new_line_code;
        }
        else
        {
          s[0] = new_line_code; /* other objects are ignored */
          old_line_length = 0;
        }
      } /* <>0 */
      next(&ptr1);

    } /*=2*/
  }
_L99:;
}

Static Void putatom(j)
long j;
{
  /*************************/
  putit(atom, j);
}

Static Void putit(dd, j)
unsigned Char dd;
long j;
{
  /*************************/
  if (j > 80)
  {
    dt = keyword;
    er_lex(10L);
    j = 80;
  }
  else
    dt = dd;
  putatm(&s[i - 1], j, &aadr);
  dt = dd;
  saved_coord = getcoord();
  tokennumber++;
}

Static Void putident(j)
long j;
{
  /*************************/
  putit(idatom, j);
}

Static Void putfloat(j)
long j;
{ /*ignored*/
  /* This function takes "j" characters,
     starting from the current position s[i-1]
     and converts them to "sizeof(double)" character
     A-atom, which serves are internal presentation for
     #FATOMs.
  */
  /*************************/
  double rea_val;
  long ii, kk;
  real_char reac;
  Char STR1[256];

  sprintf(STR1, "%.*s", (int)j, s + i - 1);
  /* STR1 - 0-terminated string */

  val2(STR1, &rea_val, &ii);
  /* rea_val - double value.
     We ignore ii here because we already checked
     syntax correctness earlier  */

  ii = sizeof(double);
  for (kk = 0; kk < ii; kk++)
    reac[kk] = ((Char *)(&rea_val))[kk];
  /* Copy the sizeof(double) characters to the "reac"
     string */

  putatm(reac, ii, &aadr);
  /* Store "reac" into the A-memory */

  dt = fatom;
  saved_coord = getcoord();
  jnc(&tokennumber);
}

Static Void putnumber()
{
  /*************************/
  dt = number;
  saved_coord = getcoord();
  jnc(&tokennumber);
}

Static Void putstr(dd)
Char dd;
{
  /*************************/
  if (str_constlen > 80)
  {
    str_constlen = 80;
    dt = keyword; /* too long string constant */
    er_lex(10L);
  }
  else
    dt = dd;
  putatm(str_const, str_constlen, &aadr);
  in_string = false;
  tokennumber++;
}

/* Local variables for scaner: */
struct LOC_scaner
{
  string80 options_str;
};

/*inner function*/
Local boolean setop(c, LINK)
Char c;
struct LOC_scaner *LINK;
{
  boolean Result;
  char *tmp;
  Result = false;
  tmp = strchr(LINK->options_str, c);

  if (tmp)
  {
    if (tmp[1] != '-') /* Check next position */
      return true;
  }

  return Result;
}

/* normally this procedure uses parameter tatom ;
   this procedure used only for modula2 or c-style string constants like 'x', -
   to show difference between 'x' and "x".
   access via #_keyword built_in rule is possible.
   when input  use 'm+p-' !
   when output such tokens you should write
    if #_keyword($x) -> out <] @ '"' $x '"' elsif t-> out <] $x fi;
  */

Void scaner(mode_parm, filename_, options_str_, rez, erlist_parm, strlist,
            segm, ofs)
long mode_parm;
Char *filename_, *options_str_;
long *rez, *erlist_parm, strlist, segm, ofs;
{

  /*******************************************/
  /*1=from file,2=list of strings,3=absulute address*/
  /* result; set to null if input is absent */
  /* error number list; set to null if no error */
  /* list of atoms */
  /* parts of absolute address */
  struct LOC_scaner V;
  string80 filename;

  strcpy(filename, filename_);
  strcpy(V.options_str, options_str_);
  read_mode = mode_parm; /* save for global use */
  *rez = null_;
  *erlist_parm = null_;
  errlist = null_; /* global */

  /* initializes  all  options */
  /* defaults */
  strcat(V.options_str, "D-C-P+p+m-U+S+O+s-t-L-A+R+Y-B-N-");
  /* to every option su,me default value should be given,
     otherwise the flag remains uninitialized */

  /*errors*/
  screen_errors = setop('S', &V);
  collect_errors = setop('O', &V);

  /*comments*/
  ada_comment = setop('D', &V);
  c_comment = setop('C', &V);
  pascal_comment = setop('P', &V);

  /*string constants*/
  pascal_string = setop('p', &V);
  modula_string = setop('m', &V);
  to_uppercase = setop('U', &V);

  /*coordinate*/
  string_coord = setop('s', &V);
  token_coord = setop('t', &V);
  row80_coord = setop('R', &V);
  byte_coord = setop('Y', &V);
  mark_byte_coord = setop('B', &V);
  mark_only_coord = setop('N', &V);

  /*language_specific lexics*/
  c_lexics = setop('L', &V);
  pascal_lexics = setop('A', &V);
  tex_lexics = setop('T', &V);
  sty_lexics = setop('@', &V);

  /* initializes language-specific settings */
  setlexics();

  /* initializes "session" flags (alf order)*/
  coord_mark = 0;
  in_comment = false;
  in_string = false;
  is_2quote = false;
  last_mark_byte_number = 0;
  line_byte_number = 0;
  linenumber = 0;
  old_line_length = 0;
  str_constlen = 0;
  tokennumber = 0;

  /* initializes physical level reading */

  if (read_mode == 1)
  { /* read from file */
    if (!existfile(filename))
    {
      *rez = 0;
      goto _L1;
    }

    inpfile = fopen(filename, "r");
    if (inpfile == NULL)
      _EscIO(FileNotFound);

    readline(); /* reads first line of file */
  }
  else
  {
    if (read_mode == 2)
    { /* read from list */
      if (strlist == null_)
      {
        *rez = 0;
        goto _L99;
      }
      first(strlist, &ptr1); /* sets global list-pointer ptr1 */
      if (ptr1.ptrtype != ptrlist || ptr1.nel == 0)
      {
        *rez = 0;
        goto _L99;
      }
      readline(); /* reads line from current list-pointer position */
      /* read from ms-dos ram memory */
    }
  }

  read_file(rez); /* main call ... */

  *erlist_parm = errlist; /*global*/
_L1:
_L99:;
} /* scaner */

Static Void setlexics()
{
  /*************************/
  long j, FORLIM;

  if (pascal_lexics)
  {
    /* changes in standard, necessary for pascal*/
    as['{'] = is_special;
    as['#'] = is_special;
    as['$'] = is_special;
    as['%'] = is_special;
    as['\''] = is_special;
    as['('] = is_special;
    memcpy(two_char_symbols[0], ":=", sizeof(pair));
    memcpy(two_char_symbols[1], "<=", sizeof(pair));
    memcpy(two_char_symbols[2], ">=", sizeof(pair));
    memcpy(two_char_symbols[3], "**", sizeof(pair));
    memcpy(two_char_symbols[4], "..", sizeof(pair));
    memcpy(two_char_symbols[5], "<>", sizeof(pair));
    two_char_symbols_num = 6;
    strcpy((char *)set_of_second_of_two, "=*.>");
    FORLIM = two_char_symbols_num;
    for (j = 0; j < FORLIM; j++)
      as[two_char_symbols[j][0]] = is_first_of_two;
    if (modula_string)
    {
      as['"'] = is_special;
      as['{'] = is_printable;
    }
  }
  else
  {
    if (c_lexics)
    {
      as['_'] = is_letter;
      as['$'] = is_letter;
      memcpy(two_char_symbols[0], "->", sizeof(pair));
      memcpy(two_char_symbols[1], "++", sizeof(pair));
      memcpy(two_char_symbols[2], "--", sizeof(pair));
      memcpy(two_char_symbols[3], ">>", sizeof(pair));
      memcpy(two_char_symbols[4], "<<", sizeof(pair));
      memcpy(two_char_symbols[5], "==", sizeof(pair));
      memcpy(two_char_symbols[6], "+=", sizeof(pair));
      memcpy(two_char_symbols[7], "*=", sizeof(pair));
      memcpy(two_char_symbols[8], "-=", sizeof(pair));
      memcpy(two_char_symbols[9], "/=", sizeof(pair));
      memcpy(two_char_symbols[10], "%=", sizeof(pair));
      memcpy(two_char_symbols[11], "&=", sizeof(pair));
      memcpy(two_char_symbols[12], "^=", sizeof(pair));
      memcpy(two_char_symbols[13], "|=", sizeof(pair));
      memcpy(two_char_symbols[14], "!=", sizeof(pair));
      two_char_symbols_num = 15;
      strcpy((char *)set_of_second_of_two, ">+-<=");
      FORLIM = two_char_symbols_num;
      for (j = 0; j < FORLIM; j++)
        as[two_char_symbols[j][0]] = is_first_of_two;
      as['<'] = is_special; /* used to process <<= */
      as['>'] = is_special; /* used to process >>= */
      as['/'] = is_special; /* used to process / *  */
      /* otherwise isa:=is_first_of_two
         is assigned ! */
      as['\''] = is_special;
      as['"'] = is_special;
    }
  }
  if (!tex_lexics)
    return;

  as['!'] = is_special;
  as['"'] = is_special;
  as['#'] = is_special;
  as['$'] = is_special;
  as['%'] = is_special;
  as['&'] = is_special;
  as['/'] = is_special;
  as['{'] = is_special;
  as['}'] = is_special;
  as['('] = is_special;
  as[')'] = is_special;
  as['['] = is_special;
  as[']'] = is_special;
  as['='] = is_special;
  as['?'] = is_special;
  as['\\'] = is_special;
  as['`'] = is_special;
  as['^'] = is_special;
  as['~'] = is_special;
  as['*'] = is_special;
  as['<'] = is_special;
  as['>'] = is_special;
  as['|'] = is_special;
  as[';'] = is_special;
  as[','] = is_special;
  as[':'] = is_special;
  as['.'] = is_special;
  as['-'] = is_special;
  as['_'] = is_special;
  as['\''] = is_special;
  if (sty_lexics) /*it is the only place where sty_lexics is used*/
    as['@'] = is_letter;
  else
    as['@'] = is_special;
}

Static Void stradd(c)
unsigned Char c;
{
  /*************************/
  if (str_constlen > 80) /* string is truncated */
    er_lex(10L);
  else
    jnc(&str_constlen);
  str_const[str_constlen - 1] = c;
}

Static Void strbegin()
{
  /********************/
  saved_coord = getcoord();
  /* it will be used when putstr works and token exits - in read_item*/
  in_string = true;
  str_constlen = 0;
}

Static Void token()
{ /* variant record ,b1=b2[1]=b3[1]; b2[2]=b3[2] */
  /**********************/
  long j, i_saved; /* positions */
  long FORLIM;

  /* at beginning time
     "i" - is already set to character in string "s";
     array "as" is already initialized;
     coordinate mode "coord_mode" is already known;
  */

_L1: /* we return to this label if token is not ready still */

  b123.b1 = s[i - 1];
  isa = as[b123.b1]; /* type of this character */

  if (isa == is_control)
  { /*1*/
    if (b123.b1 == new_line_code)
    {
      readline(); /* skips to next line, sets new "s" and "i" */

      if (tex_lexics)
      {
        dt = dummy;
        goto _L99;
      } /*null is returned at the end of line*/

      if (in_string)
      {
        er_lex(11L);
        putstr(keyword);
        goto _L99;
      }
      /* error= end of line appears in string constant */
      goto _L1;
    }
    else
    {
      if (b123.b1 == endfile_code)
      {
        if (in_comment)
          er_lex(12L);
        /* error = end of file appears in comment */
        dt = eof_desk;
        goto _L99;
      }
      else
      { /*2*/
        if (in_comment)
        {
          er_lex(13L);
          in_comment = false;
        }
        /* error = control char  in comment */
        if (in_string)
        {
          er_lex(14L);
          putstr(keyword);
          goto _L99;
          /* will take control character next time */
        }
        /* error = control char in string */
        dt = cont_char_to_dt(b123.b1);
        i++;
        if (dt == set_coord && as[s[i - 1]] == is_digit)
        {
          /* this control character sets coordinate to value given in input */
          coord_mark = take_digits(&j);
          last_mark_byte_number = line_byte_number + i;
          i += j;
          goto _L1; /* does not returns ! */
        }
        goto _L99;
      } /*2*/
    }
    /*never here*/
  } /*1*/

  /* all the following executes after check of is_control */

  /*b3[1]:=s[i];*/
  /* this character */
  b123.b3[1] = s[i];     /* next */
  b123.b3[2] = s[i + 1]; /* next */

  if (in_comment) /* check for end of comment */
  {               /*1*/
    /* we are in comment;
       here only comments that have some special end mark are processed */
    if (pascal_comment)
    { /*2*/
      if (b123.b1 == '}')
      {
        jncx(&i);
        in_comment = false;
        goto _L1;
      }

      if (!strncmp((char *)b123.b2, "*)", 2))
      {
        jnc2x(&i, 2L);
        in_comment = false;
        goto _L1;
      }

    } /*2*/
    else
    {
      if (c_comment)
      { /*2*/
        if (!strncmp((char *)b123.b2, "*/", 2))
        {
          jnc2x(&i, 2L);
          in_comment = false;
          goto _L1;
        }
      } /*2*/
    }
    jncx(&i);
    goto _L1;
  } /*1*/
  /*this part never appears in mif input, since there is no in_comment status*/

  if (in_string)
  { /*1*/
    if (pascal_string)
    { /*2*/
      if (b123.b1 == '\'')
      { /*3*/
        if (b123.b2[1] == '\'')
        {
          stradd('\'');
          jnc2x(&i, 2L);
          goto _L1;
        }
        else
        {
          putstr(tatom);
          jncx(&i);
          goto _L99;
        }
        /* this allow to save '''' as '' */

      } /*3*/
      else
      { /*3*/
        stradd(b123.b1);
        jncx(&i);
        goto _L1;
      } /*3*/

    } /*2*/
    if (modula_string)
    { /*2*/
      if (is_2quote && b123.b1 == '"')
      {
        if (b123.b2[1] == '"')
        {
          stradd('"');
          jnc2x(&i, 2L);
          goto _L1;
        }
        else
        {
          putstr(tatom);
          jncx(&i);
          goto _L99;
        }
      }
      if (!is_2quote && b123.b1 == '\'')
      {
        putstr(keyword);
        jncx(&i);
        goto _L99;
      }
      else
      { /*3*/
        if (b123.b1 == '\\')
        {
          stradd(b123.b1);
          stradd(b123.b2[1]);
          /* this allows to save \? as ? even if \" appears" */
          jnc2x(&i, 2L);
          goto _L1;
        }

        stradd(b123.b1);
        jncx(&i);
        goto _L1;
      } /*3*/
    } /*2*/
  } /*1*/

  /* check for end of string or something special in string */

  /* all the following executes after check for in_string & in_comment */

  if (isa == is_special)
  { /*1*/
    if (pascal_comment)
    { /*2*/
      if (!strncmp((char *)b123.b2, "(*", 2))
      {
        in_comment = true;
        jnc2x(&i, 2L);
        goto _L1;
      }
      if (b123.b1 == '{' && b123.b2[1] != '$')
      {
        in_comment = true;
        jncx(&i);
        goto _L1;
      }
    } /*2*/
    else
    {
      if (c_comment)
      { /*2*/
        if (!strncmp((char *)b123.b2, "/*", 2))
        {
          in_comment = true;
          jnc2x(&i, 2L);
          goto _L1;
        }
      } /*2*/
      else
      {
        if (ada_comment)
        { /*2*/
          if (!strncmp((char *)b123.b2, "--", 2))
          {
            readline();
            goto _L1;
          }
        } /*2*/
      }
    }

    if (pascal_string)
    { /*2*/
      if (b123.b1 == '\'')
      {
        strbegin();
        is_2quote = false;
        jncx(&i);
        goto _L1;
      }
    } /*2*/
    else
    {
      if (modula_string)
      { /*2*/
        if (b123.b1 == '\'')
        {
          strbegin();
          is_2quote = false;
          jncx(&i);
          goto _L1;
        }
        if (b123.b1 == '"')
        {
          strbegin();
          is_2quote = true;
          jncx(&i);
          goto _L1;
        }
      } /*2*/
    }
    if (pascal_lexics)
    { /*2*/
      /* specially takes turbo pascal directive-comments */
      if (!strncmp((char *)b123.b2, "{$", 2))
      { /*3*/
        j = 0;
        do
        {
          jncx(&j);
        } while (s[i + j - 1] != '}' && as[s[i + j - 1]] != is_control);
        if (s[i + j - 1] == '}')
          jncx(&j);
        putatom(j);
        jnc2x(&i, j);
        goto _L99;
      } /*3*/

      /* additional symbols */
      if (b123.b1 == '#' || b123.b1 == '$' || b123.b1 == '%')
      { /*3*/
        jncx(&i);
        j = take_letters(); /* starts from i-th position */
        i--;
        putatom(j + 1); /* takes token from i-th position */
        jnc2x(&i, j + 1);
        goto _L99;
      } /*3*/

    } /*2*/
    else
    {
      if (c_lexics)
      { /*2*/
        if (!strncmp((char *)b123.b3, "<<=", 3) || !strncmp((char *)b123.b3, ">>=", 3))
        {
          putatom(3L);
          jnc2x(&i, 3L);
          goto _L99;
        }
        isa = is_first_of_two;
        /* !! in c case <<, >>, >=, <=  will be tested further
           in  two_char_symbols section, hence we go to there
           using assignment to "isa" */

      } /*2*/
      /* symbols=  > < */
      /* special cases for c language */
    }

  } /*1*/
  /*this part never appears in mif input, since there is no is_special*/

  if (tex_lexics)
  { /*1*/
    if (b123.b1 == '\\')
    { /*2*/
      if (as[b123.b2[1]] == is_letter)
      {
        /* command like  \def, or \d@f \@ in sty_lexics */
        j = 1;
        while (as[s[i + j - 1]] == is_letter)
          jncx(&j);
        /* non-loop condition: s[last_element]=' ', it is not a is_letter
           character */
        putit(idatom, j);
        jnc2x(&i, j);
        goto _L99;
      }
      else
      {
        if (b123.b2[1] == new_line_code)
        {
          /* THIS ADDITIONAL IF IS ADDED 4/5/1995 (!)   */
          putit(keyword, 1L);
          jnc2x(&i, 1L);
          goto _L99;
        }
        else
        {
          /*commands like \% \$ and so on; \@ if not sty_lexics */
          putit(keyword, 2L);
          jnc2x(&i, 2L);
          goto _L99;
        }
      }
    } /*2*/

    /*my comment: \ is included in is_special, but it makes
      no any difference*/

    if (isa == is_special)
    {
      putit(keyword, 1L);
      jncx(&i);
      goto _L99;
    }
    /*separate character like $ ( ) etc. */

    if (b123.b1 == ' ')
    {
      putit(atom, 1L);
      jncx(&i);
      goto _L99;
    }

    /*all other characters*/
    /*all other characters simply form 80-byte atoms;
      end of line and end of file cannot be included to it;
      tabulators are changed to spaces.*/
    j = 0;
    while (as[s[i + j - 1]] != is_special && j < 80 &&
           s[i + j - 1] != new_line_code && s[i + j - 1] != endfile_code)
    {
      if (s[i + j - 1] == '\t')
        s[i + j - 1] = ' ';
      jncx(&j);
    }

    putit(atom, j);
    jnc2x(&i, j);
    goto _L99;
  } /*1*/
  /********* description of tex lexics *********
     end_of_line,(but not end_of_file) are null atom
     \letters  is command , where letters are a-z,a-z.
                @ is added to letters if we are in sty_lexics submode
               recognizable by #ident rule

     \?        is command , where ? is arbitrary.
               recognizable by #_keyword rule

     \(newline)  is command,  recognizable by #_keyword rule

     ?         is command , where ? is one of special characters,
                      (all visible except letters and digits)
               recognizable by #_keyword rule

     ' '       is command. every space-separately.
               recognizable as #atoms, not #idatom, not #_keyword

     letters,digits,spaces that can form unlimited
               sequences.
               recognizable as #atoms, not #idatom, not #_keyword
  **********************************************/
  /* my comments: end_of_file is not null atom,
     because it is unclear how to stop main loop then.
     #xxx is not accepted as camment bacause of \verbatim
     environment */

  if (isa == is_space)
  {
    jncx(&i);
    goto _L1;
  }

  if (isa == is_letter)
  {
    j = take_letters();
    putident(j);
    i += j;
    goto _L99;
  }

  if (isa == is_digit)
  { /*1*/
    if (c_lexics)
    { /*2*/
      /* additional symbols; here hex and octal numbers are saved as
         normal atoms */
      if ((b123.b1 == '0') &&
          ((as[b123.b2[1]] == is_letter) ||
           (as[b123.b2[1]] == is_digit) ||
           (as[b123.b2[1]] == is_underscore)))

      { /*3*/
        jncx(&i);
        j = take_letters(); /* starts from i-th position */
        i--;
        putatom(j + 1); /* takes token from i-th position */
        jnc2x(&i, j + 1);
        goto _L99;
      } /*3*/
    } /*2*/

    i_saved = i; /* remember starting position */
    aadr = take_digits(&j);

    if (j < 10 &&
        (s[i + j - 1] == '.' && s[i + j] == '.' ||
         s[i + j - 1] != '.' && s[i + j - 1] != 'E' && s[i + j - 1] != 'e'))
    {
      putnumber();
      jnc2x(&i, j);
      goto _L99;
    }
    jnc2x(&i, j);
    if (s[i - 1] == '.')
    {
      jncx(&i);
      aadr = take_digits(&j);
      jnc2x(&i, j);
    }
    if (s[i - 1] == 'E' || s[i - 1] == 'e')
    {
      jncx(&i);
      if (s[i - 1] == '-' || s[i - 1] == '+')
        jncx(&i);
      aadr = take_digits(&j);
      jnc2x(&i, j);
    }
    j = i - i_saved;
    i = i_saved; /* to set "i" to starting position */
    putfloat(j);
    jnc2x(&i, j);
    goto _L99;
  } /*1*/

  if (isa == is_first_of_two)
  { /*1*/
    if (strchr((char *)set_of_second_of_two, (int)b123.b2[1]))
    {
      FORLIM = two_char_symbols_num;
      for (j = 0; j < FORLIM; j++)
      {
        if (b123.b2[0] == two_char_symbols[j][0] &&
            b123.b2[1] == two_char_symbols[j][1])
        {
          putatom(2L);
          i += 2;
          goto _L99;
        }
      }
    }
  } /*1*/

  putatom(1L);
  jncx(&i); /* with*/
_L99:;

  /* others are control characters; */
  /* they set "dt" field and then form rigal list/tree structure */
}

Static long take_letters()
{
  /****************************************/
  long Result;
  /* reads only letters, digits and underscores.
     returns number of characters read */

  long jj;
  unsigned char c;

  jj = 0;
  while (true)
  {
    c = s[i + jj - 1];
    isa = as[c];
    if (isa != is_letter && isa != is_digit && isa != is_underscore)
    {
      Result = jj;
      goto _L99;
    }
    if (to_uppercase)
      s[i + jj - 1] = upcase_tab[c];
    jncx(&jj);
  }
_L99:
  return Result;
}

Static long take_digits(jj)
long *jj;
{
  /**************************************************/
  long Result;
  longint summator;
  unsigned char c;

  *jj = 0;
  summator = 0;
  while (true)
  {
    c = s[i + *jj - 1];
    if (as[c] != is_digit)
    {
      Result = summator;
      goto _L99;
    }
    summator = summator * 10 + c - '0';
    jncx(jj);
  }
_L99:
  return Result;
}

/*begin*/
/* press f8 when debugging ! */
/*initialize_scan_variables;*/

/* End. */
