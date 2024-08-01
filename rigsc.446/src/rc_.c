#include "globrig.h"
#include "define.h"
#include "defpage.h"
#include "ley.h"
#include "nef2.h"

/* ******************* rclib ******************** */

#define filemax         3   /* chislo wlovenij dlja include */
#define bufmaxlen       10   /* dlina malogo bufera , kak minimum - 8 */
#define rulemaxnum      400   /* chislo prawil w programme     */
#define two_char_sym_max  50   /* maks. chislo dwuhbajtowyh simwolow */



typedef char keyint;
   /* nomer kljuchewogo slowa, ogranichen dlja case */



a m1[150], etalon[150];
/* massiwy, postojannye dlja poddervki
          prikreplennyh cepochek w prostranstwah */
long varn_desks;
filespecification curfile_name;
a currulename;   /* adres w sp2 imeni tekushchego prawila */
ptr_ l;   /* pojnter dlja whodnogo spiska chekera w sp1 */
ptr_ r;   /* obshchego naznachenija pojntery */
long errmuch;   /* chislo oshibok */

boolean bspi;   /* we are within v' or S' */
a ass_1;   /* special variable $ */
a saveladr;   /* sohranjaemyj dlja el/val adres */
keyint saveelkey;   /* sohranejaemyj nomer. kl. slowa el/val */
a tabv[rulemaxnum], tabn[rulemaxnum], tabflags[rulemaxnum];
aa tabfiles[rulemaxnum];
word tabcord[rulemaxnum];


/* tablica adresow spiskow peremennyh, imen prawil i flagow dlja nee */

/* source list */
/* result code */

extern Void che11 PP((long chein, long *rezche, Char *main_name,
              error_rec_type *error_rec_rw,int an_argc,char *an_argv[]));

/* ukazatelj el-ta spiska */
/* nowyj el-t */
extern Void push PP((ptr_ *pp, long adr));

/* dobawljaet element k spisku */
extern Void newlist PP((ptr_ *pp));

/* nowyj ukazatelj spiska */
/* sozdaet nowyj spisok */
/* ukazatelj spiska */
/* imja */
extern Void namelist PP((ptr_ pp, long name));

/* priswaiwaet imja spisku */
/* gde izmenitj */
/* na chto */
extern Void changeelement PP((ptr_ *pp, long adr));



error_rec_type error_rec_ch;
aa error_rec_ch_adr;   /* renew by incfile */
string80 error_rec_ch_mainstr;   /* constant */
boolean er;


/* transported in oll big procedures
                   as last, var- paramerter */
extern Void err PP((long err_num));

/* wydaet soobshchenija ob oshibkah rigal-teksta */
extern Void tabrule PP((long av, long ar));

/* sozdaet nowoe imja peremennoj av prawila ar w
 tablice prawil w sp2 , adresa iz sp2 */
extern Void dul PP((long *ad));

/* beret l.cel iz sp1 i dubliruet w ad w sp2 */
extern Void pushl PP((ptr_ *m));

/* kak push(m,l.cel) , no iz sp1 w sp2 */
extern char des PP((ptr_ g));

extern Void nextl PV();

extern keyint valc PP((ptr_ pp));

extern boolean el PP((keyint ii));

extern Void bltn PP((long rname, long *rnum));


extern Void operator_ PP((ptr_ *m));

extern Void instruc PP((ptr_ *m));

extern Void expr PP((ptr_ *p, boolean bigexpr));

extern Void chepro PV();

extern Void chepil PP((ptr_ *v));

extern Void rule PP((ptr_ *d));

extern Void pict PP((ptr_ *m, long *siz, long *act));


#define let_sign        1
#define d_colon         2
#define more_eq         3
#define less_more       4
#define lpar_point      5
#define rpar_point      6
#define less_eq         7
#define minus_more      8
#define lpar_star       9
#define rpar_star       10
#define lpar_plus       11
#define rpar_plus       12
#define d_cross         13
#define d_semic         14
#define d_excl          15
#define d_plus          16
#define excl_point      17
#define less_point      18
#define more_point      19
#define less_star       20
#define more_star       21
#define lpar_colon      22   /* ---- */
#define d_less          22
#define rpar_colon      23   /* ---- */
#define d_more          23
#define if_key          24
#define fi_key          25
#define in_key          26   /* ---- */
#define do_key          27
#define od_key          28
#define or_key          29
#define plus            30
#define excl_sign       31
#define lpar            32
#define rpar            33
#define minus           34
#define eq_sign         35
#define star            36
#define point           37
#define more_sign       38
#define less_sign       39
#define lbrac           40
#define rbrac           41

#define and_key         42
#define mod_key         43
#define div_key         44
#define not_key         45
#define save_key        46
#define load_key        47
#define fail_key        48
#define copy_key        49
#define elsif_key       50
#define onfail_key      51
#define print_key       52
#define report_key      52   /* ---- */
#define forall_key      53
#define open_key        54
#define outtext_key     54   /* ---- */
#define slash           55
#define semic           56
#define return_key      57
#define last_key        58
#define null_key        59
#define colon_sign      60
#define comma_sign      61
#define close_key       62
#define break_key       63
#define end_key         64
#define loop_key        65
#define d_sun           66   /* ------ */
#define less_rbrac      67   /* ------ */
#define s_apost         68   /* ------ */
#define v_apost         69   /* ------ */
#define reserv5_key     70   /* ------ */
#define selectors_key   71
#define branches_key    72

#define maxkey          72


Void chepil(v)
ptr_ *v;
{
  mpd x, x1;
  a p1, aar, ruleadr;
  longint varcoun;
  long nb, i, j;
  /*array[1..80] of char*/
  bl80 str80;

  p1 = v->UU.U1.mainadr;
  first(p1, v);

  while (v->nel != 0)   /*while*/
  {  /*1*/
    ruleadr = v->cel;
    pointr(ruleadr, &x1.sa);
    nb = 1;
    aar = x1.srd->name;
    while (aar != tabn[nb - 1] && nb < rulemaxnum)
      nb++;
    if (nb == rulemaxnum) {
      err(523L);
      goto _L77;
    }
    /* ==== tabflag[nb]:=tabflag[nb]+1;==== */
    p1 = tabv[nb - 1];
    if (p1 == 0)   /* if/else/ p1 */
      varcoun = 1;
    else {  /*2*/
      pointr(p1, &x.sa);
      if (x.smld->dtype != listmain) {
	err(522L);
	goto _L77;
      }
      varcoun = x.smld->totalelnum;
      if (varcoun == 0)
	varcoun = 1;
    }
    /*2*/
    next(v);
    p1 = v->cel;
    points(p1, &x1.sa);
    if (x1.snd->dtype != number) {
      err(524L);
      goto _L77;
    }
    x1.snd->val = -1;
    next(v);
    p1 = v->cel;

    points(p1, &x1.sa);
    if (x1.snd->dtype != number) {
      err(525L);
      goto _L77;
    }
    x1.snd->val = varcoun;


    while (v->cel != 0 && v->nel != 0)
      next(v);
    next(v);
  }
  /*1*/
  /* prowerka na nalichie w tablice neopredelennyh prawil */
  nb = 1;
  while (tabn[nb - 1] != 0 && nb != rulemaxnum)   /*while*/
  {  /*1*/
    if (tabflags[nb - 1] == 0)   /* if */
    {  /*2*/
      strcpy(error_rec_ch.message, "406 THIS RULE WAS NOT DEFINED IN PROGRAM");
      if (tabfiles[nb - 1] == 0)
	strcpy(error_rec_ch.filename, error_rec_ch_mainstr);
      else {
	pointa(tabfiles[nb - 1], str80, &j);
	*error_rec_ch.filename = '\0';
	for (i = 0; i < j; i++)
	  sprintf(error_rec_ch.filename + strlen(error_rec_ch.filename), "%c",
		  str80[i]);
      }
      error_rec_ch.address = tabcord[nb - 1];
      er = true;
      goto _L77;
    }
    /*2*/
    nb++;
  }
  /*1*/
_L77: ;
}  /*chepil*/


typedef union bufrectype {
  Char lexbuf[bufmaxlen];
  Char b1;
  Char b2[2];
  Char b3[3];
  Char b4[4];
  Char b5[5];
  Char b6[6];
  Char b7[7];
  Char b8[8];
  Char b9[9];
  Char b10[10];
} bufrectype;


/* Local variables for chepro: */
struct LOC_chepro {
  bufrectype bufrec;
} ;

Local Void makekey(ki, LINK)
keyint ki;
struct LOC_chepro *LINK;
{
  /* nomer k-ty */
  /* sozdaet w sp1 konstantu, berja ee iz bufrec */
  long q;
  a a1, aadr;
  mpd x;
  long l1len;

  for (q = 1; q <= 10; q++) {
    if (LINK->bufrec.b10[q - 1] != ' ')
      l1len = q;
  }
  putatm(LINK->bufrec.b10, l1len, &aadr);
  if (ki <= 75) {
    gets1(&a1, &x.sa);
    x.sad->dtype = keyword;
    x.sad->name = aadr;
  } else {
    gets2(&a1, &x.sa);
    x.srd->dtype = rulename;
    x.srd->name = aadr;
    x.srd->fragmadr = 0;
    x.srd->nomintab = 0;
  }
  for (q = 0; q <= 9; q++)
    LINK->bufrec.b10[q] = ' ';
  m1[ki] = a1;   /* zakrepljaet adres */
  etalon[ki] = aadr;   /* zakrepljaet a-adres */
  /*==$ifdef harddebug*/
  /*      if bb7 then
          writeln('razm. ', str80[1], str80[2], str80[3], ki: 3,
                  'A1(S)=', a1, ' AADR(A)=', aadr);*/
  /*==$endif*/
}


Void chepro()
{  /* inicializacija peremennyh */
  struct LOC_chepro V;
  Char onechar_array[12];
  c2 twochar_symbols[29];

  long ii, i;
  /* a1: a;*/
  ptr_ f1;


  errmuch = 0;   /* chislo oshibok */
  /* nomera prostranstw i konstanty */
  for (i = 0; i <= 149; i++)   /* ochistka */
    m1[i] = 0;
  for (i = 0; i < rulemaxnum; i++)   /* ochistka */
    tabv[i] = 0;
  memcpy(tabn, tabv, rulemaxnum * sizeof(long));
  memcpy(tabflags, tabv, rulemaxnum * sizeof(long));
  memcpy(twochar_symbols[0], ":=", sizeof(c2));
  memcpy(twochar_symbols[1], "::", sizeof(c2));
  memcpy(twochar_symbols[2], ">=", sizeof(c2));
  memcpy(twochar_symbols[3], "<>", sizeof(c2));
  memcpy(twochar_symbols[4], "(.", sizeof(c2));
  memcpy(twochar_symbols[5], ".)", sizeof(c2));
  memcpy(twochar_symbols[6], "<=", sizeof(c2));
  memcpy(twochar_symbols[7], "->", sizeof(c2));
  memcpy(twochar_symbols[8], "(*", sizeof(c2));
  memcpy(twochar_symbols[9], "*)", sizeof(c2));
  memcpy(twochar_symbols[10], "(+", sizeof(c2));
  memcpy(twochar_symbols[11], "+)", sizeof(c2));
  memcpy(twochar_symbols[12], "##", sizeof(c2));
  memcpy(twochar_symbols[13], ";;", sizeof(c2));
  memcpy(twochar_symbols[14], "!!", sizeof(c2));
  memcpy(twochar_symbols[15], "++", sizeof(c2));
  memcpy(twochar_symbols[16], "!.", sizeof(c2));
  memcpy(twochar_symbols[17], "<.", sizeof(c2));
  memcpy(twochar_symbols[18], ".>", sizeof(c2));
  memcpy(twochar_symbols[19], "<*", sizeof(c2));
  memcpy(twochar_symbols[20], "*>", sizeof(c2));
  memcpy(twochar_symbols[21], "<<", sizeof(c2));
  memcpy(twochar_symbols[22], ">>", sizeof(c2));
  memcpy(twochar_symbols[23], "IF", sizeof(c2));
  memcpy(twochar_symbols[24], "FI", sizeof(c2));
  memcpy(twochar_symbols[25], "IN", sizeof(c2));
  memcpy(twochar_symbols[26], "DO", sizeof(c2));
  memcpy(twochar_symbols[27], "OD", sizeof(c2));
  memcpy(twochar_symbols[28], "OR", sizeof(c2));
  memcpy(V.bufrec.b10, "          ", 10L);
  for (i = 1; i <= 29; i++) {
    V.bufrec.b2[0] = twochar_symbols[i - 1][0];
    V.bufrec.b2[1] = twochar_symbols[i - 1][1];
    makekey((int)i, &V);
  }
  memcpy(onechar_array, "+!()-=*.><[]", 12L);
  for (i = 1; i <= 12; i++) {
    V.bufrec.b1 = onechar_array[i - 1];
    makekey((int)(i + 29), &V);
  }
  memcpy(V.bufrec.b3, "AND", 3L);
  makekey(42, &V);
  memcpy(V.bufrec.b3, "MOD", 3L);
  makekey(43, &V);
  memcpy(V.bufrec.b3, "DIV", 3L);
  makekey(44, &V);
  memcpy(V.bufrec.b3, "NOT", 3L);
  makekey(45, &V);
  memcpy(V.bufrec.b4, "SAVE", 4L);
  makekey(46, &V);
  memcpy(V.bufrec.b4, "LOAD", 4L);
  makekey(47, &V);
  memcpy(V.bufrec.b4, "FAIL", 4L);
  makekey(48, &V);
  memcpy(V.bufrec.b4, "COPY", 4L);
  makekey(49, &V);
  memcpy(V.bufrec.b5, "ELSIF", 5L);
  makekey(50, &V);
  memcpy(V.bufrec.b6, "ONFAIL", 6L);
  makekey(51, &V);
  memcpy(V.bufrec.b5, "PRINT", 5L);
  makekey(52, &V);
  memcpy(V.bufrec.b6, "FORALL", 6L);
  makekey(53, &V);
  memcpy(V.bufrec.b4, "OPEN", 4L);
  makekey(54, &V);
  V.bufrec.b1 = '/';
  makekey(55, &V);
  V.bufrec.b1 = ';';
  makekey(56, &V);
  memcpy(V.bufrec.b6, "RETURN", 6L);
  makekey(57, &V);
  memcpy(V.bufrec.b4, "LAST", 4L);
  makekey(58, &V);
  memcpy(V.bufrec.b4, "NULL", 4L);
  makekey(59, &V);
  V.bufrec.b1 = ':';
  makekey(60, &V);
  V.bufrec.b1 = ',';
  makekey(61, &V);
  memcpy(V.bufrec.b5, "CLOSE", 5L);
  makekey(62, &V);
  memcpy(V.bufrec.b5, "BREAK", 5L);
  makekey(63, &V);
  memcpy(V.bufrec.b3, "END", 3L);
  makekey(64, &V);
  memcpy(V.bufrec.b4, "LOOP", 4L);
  makekey(65, &V);
  memcpy(V.bufrec.b2, "$$", 2L);
  makekey(66, &V);
  memcpy(V.bufrec.b2, "<]", 2L);
  makekey(67, &V);
  memcpy(V.bufrec.b2, "S'", 2L);
  makekey(68, &V);
  memcpy(V.bufrec.b2, "V'", 2L);
  makekey(69, &V);
  V.bufrec.b1 = '@';
  makekey(70, &V);
  memcpy(V.bufrec.b9, "SELECTORS", 9L);
  makekey(71, &V);
  memcpy(V.bufrec.b8, "BRANCHES", 8L);
  makekey(72, &V);
  V.bufrec.b1 = '_';
  makekey(73, &V);
  ass_1 = etalon[73];
  /* this is used after maxkey and necessary for
     $ - variable name is '_' */
  /* nachinaja s nomera 76 - etalony imen wstroennyh prawil */
  /* nomer prawila wychisljaetsja w programme bltn :  i-75  */
  memcpy(V.bufrec.b7, "IMPLODE", 7L);
  makekey(76, &V);   /* 1 */
  memcpy(V.bufrec.b7, "EXPLODE", 7L);
  makekey(77, &V);   /* 2 */
  memcpy(V.bufrec.b4, "ATOM", 4L);
  makekey(78, &V);   /* 3 */
  memcpy(V.bufrec.b6, "NUMBER", 6L);
  makekey(79, &V);   /* 4 */
  memcpy(V.bufrec.b5, "IDENT", 5L);
  makekey(80, &V);   /* 5 */
  memcpy(V.bufrec.b4, "LIST", 4L);
  makekey(81, &V);   /* 6 */
  memcpy(V.bufrec.b4, "TREE", 4L);
  makekey(82, &V);   /* 7 */
  memcpy(V.bufrec.b5, "TATOM", 5L);
  makekey(83, &V);   /* 8 */
  memcpy(V.bufrec.b5, "FATOM", 5L);
  makekey(84, &V);   /* 9 */
  memcpy(V.bufrec.b8, "_KEYWORD", 8L);
  makekey(85, &V);   /* 10 */
  memcpy(V.bufrec.b9, "_SPECDESC", 9L);
  makekey(86, &V);   /* 11 */
  memcpy(V.bufrec.b3, "LEN", 3L);
  makekey(87, &V);   /* 12 */
  memcpy(V.bufrec.b9, "_SPECATOM", 9L);
  makekey(88, &V);   /* 13 */
  memcpy(V.bufrec.b9, "_RULENAME", 9L);
  makekey(89, &V);   /* 14 */
  memcpy(V.bufrec.b8, "_VARNAME", 8L);
  makekey(90, &V);   /* 15 */
  memcpy(V.bufrec.b10, "_RULETOATM", 10L);
  makekey(91, &V);   /* 16 */
  memcpy(V.bufrec.b10, "_VARNTOATM", 10L);
  makekey(92, &V);   /* 17 */
  memcpy(V.bufrec.b10, "_VARDESLOC", 10L);
  makekey(93, &V);   /* 18 */
  memcpy(V.bufrec.b5, "DEBUG", 5L);
  makekey(94, &V);   /* 19 */
  memcpy(V.bufrec.b10, "_SPECTODSC", 10L);
  makekey(95, &V);   /* 20 */
  memcpy(V.bufrec.b9, "_CONTENT2", 9L);
  makekey(96, &V);   /* 21 */
  memcpy(V.bufrec.b3, "CHR", 3L);
  makekey(97, &V);   /* 22 */
  memcpy(V.bufrec.b4, "PARM", 4L);
  makekey(98, &V);   /* 23 */
  memcpy(V.bufrec.b8, "_TOTATOM", 8L);
  makekey(99, &V);   /* 24 */
  memcpy(V.bufrec.b3, "ORD", 3L);
  makekey(100, &V);   /* 25 */
  memcpy(V.bufrec.b8, "CALL_PAS", 8L);
  makekey(101, &V);   /* 26 */
  for (i = 102; i <= 149; i++)
    etalon[i] = 0;
  /* ..... */
  /* b3 := '...'    ; makekey(99);  24 */
  /* ee kakie-to inicializacii */
  varn_desks = (1L << ((long)variable)) | (1L << ((long)idvariable)) |
	       (1L << ((long)fvariable)) | (1L << ((long)nvariable));
  newlist(&f1);
  /* nowyj spisok - dlja tablicy prawil */
  /*m2[1] := f1.mainadr;*/
  push(&f1, 0L);
  bspi = false;   /* dlja $$ w s' */
  saveladr = 512;   /* any impossible address */
  /* with */
}


Static Char *home_dir(Result,argum)
Char *Result;
char *argum;
{
  filespecification s;
  long i;

  strcpy(s,argum);
  i = strlen(s);
  while (i > 1 && s[i - 1] != '\\')
    i--;
  sprintf(Result, "%.*s", (int)i, s);
  return Result;
}


/* Local variables for che11: */
struct LOC_che11 {
  mpd x;
  a a1;
  FILE *batfile;
  long icc;
} ;

Local Void incfile(LINK)
struct LOC_che11 *LINK;
{
  /* processing file name description */
  Char STR1[256];

  pointr(l.cel, &LINK->x.sa);
  LINK->a1 = LINK->x.sad->name;
  aa_str(curfile_name, LINK->a1);
  error_rec_ch_adr = LINK->a1;
  strcpy(error_rec_ch.filename, curfile_name);

  if (curfile_name[strlen(curfile_name) - 1] == 'I') {
    sprintf(STR1, "%.*s", (int)(strlen(curfile_name) - 5L), curfile_name);
    strcpy(curfile_name, STR1);
    printf("%s:\n", curfile_name);
    /* we delete extension ".rig" in curfile_name */
    fprintf(LINK->batfile, "%s\n", curfile_name);   /* ==> rigcomp.tmp */
    LINK->icc++;
  }
  next(&l);
}


Void che11(chein, rezche, main_name_, error_rec_rw, an_argc, an_argv)
long chein, *rezche;
Char *main_name_;
error_rec_type *error_rec_rw;
int  an_argc;
char *an_argv[];
{
  /* source list */
  /* result code */
  struct LOC_che11 V;
  string80 main_name;
  ptr_ rrr;   /* pointer moves along input list */
  long ii, ri, i;
  string80 stt;
  long FORLIM;


  strcpy(main_name, main_name_);
  V.batfile = NULL;
  m1[0] = chein;
  V.icc = 0;
  er = false;
  *error_rec_ch.message = '\0';
  sprintf(error_rec_ch.filename, "%s.rig", main_name);
  error_rec_ch_adr = 0;
  sprintf(error_rec_ch_mainstr, "%s.rig", main_name);

  chepro();   /* prolog of checker , makes descriptors  */


  if (V.batfile != NULL)
    V.batfile = freopen("RIGCOMP.TMP", "w", V.batfile);
  else
    V.batfile = fopen("RIGCOMP.TMP", "w");
  if (V.batfile == NULL)
    _EscIO(FileNotFound);
  fprintf(V.batfile, "%s\n", main_name);


  newlist(&rrr);

  first(chein, &l);

  if (des(l) != rulename) {
    err(21L);
    goto _L77;
  }
  pushl(&rrr);
  bltn(l.cel, &V.a1);
  if (V.a1 != 0) {
    err(23L);
    goto _L77;
  }
  /* main rule is not built_in */
  tabrule(512L, rrr.cel);
  if (er)
    goto _L77;
  currulename = rrr.cel;
  for (ii = 1; ii <= 2; ii++) {
    gets1(&V.a1, &V.x.sa);
    push(&rrr, V.a1);
    V.x.snd->dtype = number;
    V.x.snd->val = 0;
  }
  nextl();

  instruc(&rrr);
  if (er)
    goto _L77;
  if (!el(d_cross)) {
    err(22L);
    goto _L77;
  }
  next(&l);
  push(&rrr, 0L);   /* razdelitelj */
  /*  write('Rule 1:');
    pointr(currulename,x.sa);
    writeln('#',aa_str(x.srd^.name));*/
  /*clreol;
    gotoxy(1,wherey);
   */
  ri = 2;

  while (l.nel != 0) {
    while (true) {
      if (l.cel == 0 || l.nel == 0)
	goto _L69;
      if (des(l) != tatom)
	goto _L12;
      incfile(&V);
    }

_L12:
    if (l.cel != 0 && l.nel != 0) {
      if (des(l) != rulename) {
	err(3L);
	goto _L77;
      }  /* if rulename */
      /*   write('Rule ', ri,':');
         pointr(l.cel,x.sa);    writeln('#',aa_str(x.srd^.name));*/
      /* clreol;
         gotoxy(1,wherey); */
      rule(&rrr);
      if (er)
	goto _L77;
      push(&rrr, (long)null_);
      ri++;
      if (!el(d_cross)) {
	err(25L);
	goto _L77;
      }
      next(&l);
    }

    while (true) {
      if (l.cel == 0 || l.nel == 0)
	goto _L69;
      if (des(l) != tatom)
	goto _L13;
      incfile(&V);
    }



_L13: ;
  }  /* l.nel = 0 */

_L69:
  chepil(&rrr);
  if (er)
    goto _L77;
_L77:
_L97:
  *rezche = rrr.UU.U1.mainadr;
  *error_rec_rw = error_rec_ch;
  /*different places of rec=rw and chefun*/

  if (!er)
    printf("Saving code ...\n");

  if (!er) {
    if (V.batfile != NULL)
      fclose(V.batfile);
    V.batfile = NULL;   /* ==> rigcomp.tmp */
    if (V.batfile != NULL)
      V.batfile = freopen("xd", "w", V.batfile);
    else
      V.batfile = fopen("xd", "w");
    if (V.batfile == NULL)
      _EscIO(FileNotFound);
    fprintf(V.batfile, "#!/bin/csh -f\n");

    char *binpath = realpath(an_argv[0], NULL);
    if (binpath == NULL) binpath = strdup(getenv("_"));
    fprintf(V.batfile, "if !($?rig) set rig=`dirname \"%s\"`\n", binpath);
    free(binpath);

    fprintf(V.batfile, "$rig/anrig -p N.TMP\n");
    fprintf(V.batfile, "$rig/genrigd  S -p N.TMP\n");
    fprintf(V.batfile, " cc   -w ");
    for (i = 1; i < an_argc; i++) {
      strcpy(stt,an_argv[i]);
      brt(stt);
      if (!strcmp(stt, "-P")) {
	if (i <= an_argc - 2) {
	  strcpy(stt,an_argv[i+1]);
	  fprintf(V.batfile, " %s", stt);
	}
      }
    }
    fprintf(V.batfile, " -I{$rig}/../include  -I.  xcrg.c  xcrg_0.c\\\n");
    FORLIM = V.icc;
    for (i = 1; i <= FORLIM; i++)
      fprintf(V.batfile, "xcrg_%ld.c\\\n", i);
    fprintf(V.batfile, "-o %s\\\n", main_name);
    fprintf(V.batfile, "$rig/../lib/riglib.a -lm %s\n", STATIC_CCFLAGS);

    for (i = 1; i < an_argc; i++) {
      strcpy(stt,an_argv[i]);
      brt(stt);
      if (!strcmp(stt, "-D"))
	goto _L99;
    }

    FORLIM = V.icc;
    for (i = 0; i <= FORLIM; i++)
      fprintf(V.batfile, "rm -f xcrg_%ld.c  xcrg_%ld.o \n", i, i);
    fprintf(V.batfile, "rm -f xcrg.c  xcrg.o xcrga.h xcrg.h\n");
    fprintf(V.batfile, "rm -f *.RC2 *.RC4  RIGCOMP.TMP N.TMP\n");
    fprintf(V.batfile, "rm -f check_tmp.out $0\n");
    fprintf(V.batfile, "rm -fr %s.dSYM\n", main_name);

_L99:
    /*
writeln(batfile,'echo Terminated successfully, result is ',main_name);*/
    if (V.batfile != NULL)
      fclose(V.batfile);
    V.batfile = NULL;

  }



  if (V.batfile != NULL)
    fclose(V.batfile);
}


/* Local variables for expr: */
struct LOC_expr {
  boolean bigexpr;
} ;

Local Void expr1(p, LINK)
ptr_ *p;
struct LOC_expr *LINK;
{
  a a1;
  mpd x;
  char TEMP;

  /* wyravenija samogo nizkogo urownja */


  TEMP = des(l);
  if (((1L << ((long)TEMP)) & ((1L << ((long)idatom)) | (1L << ((long)atom)) |
	 (1L << ((long)number)) | (1L << ((long)fatom)))) != 0) {
    pushl(p);
    nextl();
    goto _L99;
  }

  TEMP = des(l);
  if (((1L << ((long)TEMP)) & varn_desks) != 0) {
    pushl(p);
    tabrule(p->cel, currulename);
    nextl();
    goto _L99;
  }

  if (des(l) == rulename) {
    bltn(l.cel, &a1);
    if (a1 == 0) {   /* pomechaetsja nomer prawila */
      pushl(p);
      tabrule(0L, p->cel);
    } else  /* wyzow wstroennoj f-ii */
      push(p, a1);
    nextl();
    if (el(lpar)) {
      /* " #....   ( ... ) " - konstruktor */
      nextl();
      push(p, 13312L);
      while (!el(rpar)) {
	expr(p, true);
	if (er)
	  goto _L99;
	push(p, 14336L);
      }
      if (p->cel == 14336)   /* poslednij */
	changeelement(p, 13824L);
      else
	push(p, 13824L);
      nextl();
      if (a1 == 0)   /* priznak tipa prawila */
	push(p, 17920L);
      else
	push(p, 27136L);
      goto _L99;
    } else {
      err(325L);
      goto _L99;
    }
  }

  if (des(l) == spec) {
    if (LINK->bigexpr) {
      pushl(p);
      nextl();
    } else
      err(324L);
    goto _L99;
  }

  if (des(l) == keyword) {   /* ob'ekt neizwestnogo tipa w wyravenii */
    switch (valc(l)) {

    case lpar_point:  /* "(." - konstruktor */
      nextl();
      push(p, 13312L);
      while (!el(rpar_point)) {
	expr(p, true);
	if (er)
	  goto _L99;
	push(p, 14336L);
      }
      if (p->cel == 14336)   /* poslednij */
	changeelement(p, 13824L);
      else
	push(p, 13824L);
      nextl();
      break;

    case less_point:   /* <. - konstruktor */
      nextl();
      push(p, 14848L);
      if (!el(more_point)) {
	do {
	  expr(p, true);
	  if (er)
	    goto _L99;
	  /* imja wetwi derewa - wyravenie */
	  if (el(colon_sign))
	    nextl();
	  else
	    err(329L);
	  /* net : w opisanii wetwi derewa */
	  push(p, 30720L);
	  expr(p, true);   /* sodervanie wetwi */
	  if (er)
	    goto _L99;
	  if (!el(more_point)) {
	    if (!el(comma_sign)) {
	      err(330L);
	      goto _L99;
	    }
	    push(p, 15872L);
	    nextl();
	    if (el(more_point)) {
	      err(331L);
	      goto _L99;
	    }
	  }
	} while (!el(more_point));
      }
      push(p, 15360L);
      nextl();
      break;

    case lpar:
      nextl();
      expr(p, true);
      if (er)
	goto _L99;
      if (!el(rpar)) {
	err(301L);
	goto _L99;
      }
      /* obychnye skobki */
      nextl();
      break;

    case last_key:
      nextl();   /* last-wyravenie */
      if (des(l) != rulename) {
	err(302L);
	goto _L99;
      }
      bltn(l.cel, &a1);
      if (a1 != 0) {
	err(304L);
	goto _L99;
      }
      pushl(p);
      a1 = p->cel;
      nextl();
      TEMP = des(l);
      if (!(((1L << ((long)TEMP)) & varn_desks) != 0)) {
	err(303L);
	goto _L99;
      }
      pushl(p);
      tabrule(p->cel, a1);
      nextl();
      push(p, 17408L);
      break;

    case copy_key:
      nextl();
      if (!el(lpar)) {
	err(313L);
	goto _L99;
      }
      nextl();
      expr(p, true);
      if (er)
	goto _L99;
      if (!el(rpar)) {
	err(314L);
	goto _L99;
      }
      nextl();
      push(p, 29696L);
      break;

    case d_sun:
      nextl();
      push(p, 0L);
      push(p, 512L);
      pointr(currulename, &x.sa);
      if (x.srd->name == tabn[0]) {
	err(409L);
	goto _L99;
      }
      /* $$ not allowed in the main rule */
      break;
      /* if not(bspi) then err(307);*/
      /* commented 30-aug-89 */
      /* toljko w  s'..*/



    default:
      err(323L);
      nextl();
      goto _L99;   /* else */
      /* neovidannyj keyword wnutri wyravenija */
      break;
    }/*case*/
  }  /* if/keyword */
  else
    err(327L);
_L99: ;

}  /* expr1 */

Local Void expr3(p, LINK)
ptr_ *p;
struct LOC_expr *LINK;
{
  expr1(p, LINK);
  if (er)
    goto _L1;
  do {
    switch (valc(l)) {

    case point:
      nextl();
      expr1(p, LINK);
      push(p, 18432L);
      break;

    case d_colon:
      nextl();
      expr1(p, LINK);
      push(p, 19456L);
      break;

    case lbrac:
      nextl();
      expr(p, true);
      if (er)
	goto _L1;
      if (!el(rbrac)) {
	err(321L);
	goto _L1;
      }
      nextl();
      push(p, 18944L);
      break;



    default:
      goto _L1;
      break;
    }/* case */
  } while (true);
_L1: ;
}  /* expr3 */

Local Void expr4(p, LINK)
ptr_ *p;
struct LOC_expr *LINK;
{
  switch (valc(l)) {

  case not_key:
    nextl();
    expr3(p, LINK);
    push(p, 16384L);
    break;

  case minus:
    nextl();
    expr3(p, LINK);
    push(p, 16896L);
    break;

  /* plus: begin nextl; expr3(p); push(p,.       .); end;  */


  default:
    expr3(p, LINK);
    break;
  }/* case */
}  /* expr4 */

Local Void expr5(p, LINK)
ptr_ *p;
struct LOC_expr *LINK;
{
  expr4(p, LINK);
  if (er)
    goto _L1;
  do {
    switch (valc(l)) {

    case star:
      nextl();
      expr4(p, LINK);
      push(p, 19968L);
      break;

    case div_key:
      nextl();
      expr4(p, LINK);
      push(p, 20480L);
      break;

    case mod_key:
      nextl();
      expr4(p, LINK);
      push(p, 20992L);
      break;


    default:
      goto _L1;
      break;
    }/*case */
    if (er)
      goto _L1;
  } while (true);
_L1: ;
}  /* expr5 */

Local Void expr6(p, LINK)
ptr_ *p;
struct LOC_expr *LINK;
{
  expr5(p, LINK);
  if (er)
    goto _L1;
  do {
    switch (valc(l)) {

    case d_excl:
      nextl();
      expr5(p, LINK);
      push(p, 21504L);
      break;

    case excl_point:
      nextl();
      expr5(p, LINK);
      push(p, 22016L);
      break;

    case d_plus:
      nextl();
      expr5(p, LINK);
      push(p, 22528L);
      break;

    case plus:
      nextl();
      expr5(p, LINK);
      push(p, 23040L);
      break;

    case minus:
      nextl();
      expr5(p, LINK);
      push(p, 23552L);
      break;


    default:
      goto _L1;
      break;
    }/* case */
    if (er)
      goto _L1;
  } while (true);
_L1: ;
}  /* expr6 */

Local Void expr7(p, LINK)
ptr_ *p;
struct LOC_expr *LINK;
{
  expr6(p, LINK);
  if (er)
    goto _L1;
  do {
    switch (valc(l)) {

    case eq_sign:
      nextl();
      expr6(p, LINK);
      push(p, 24064L);
      break;

    case less_more:
      nextl();
      expr6(p, LINK);
      push(p, 24576L);
      break;

    case more_sign:
      nextl();
      expr6(p, LINK);
      push(p, 25088L);
      break;

    case less_sign:
      nextl();
      expr6(p, LINK);
      push(p, 25600L);
      break;

    case more_eq:
      nextl();
      expr6(p, LINK);
      push(p, 26112L);
      break;

    case less_eq:
      nextl();
      expr6(p, LINK);
      push(p, 26624L);
      break;



    default:
      goto _L1;
      break;
    }/* case */
    if (er)
      goto _L1;
  } while (true);
_L1: ;
}  /* expr7 */

Local Void expr8(p, LINK)
ptr_ *p;
struct LOC_expr *LINK;
{
  expr7(p, LINK);
  if (er)
    goto _L1;
  while (el(and_key)) {
    nextl();
    expr7(p, LINK);
    if (er)
      goto _L1;
    push(p, 27648L);
  }
_L1: ;
}


Void expr(p, bigexpr_)
ptr_ *p;
boolean bigexpr_;
{
  struct LOC_expr V;

  /* telo samoj proc. expr */
  V.bigexpr = bigexpr_;
  /*-$ifdef harddebug*/
  /*   if bb3 then writeln('*EXPR*', valc(l));*/
  /*-$endif*/
  if (V.bigexpr) {   /* esli nastojashchee wyravenie */
    expr8(p, &V);
    if (er)
      goto _L1;
    while (el(or_key)) {
      nextl();
      expr8(p, &V);
      if (er)
	goto _L1;
      push(p, 28160L);
    }
  } else  /* esli odin obxekt */
    expr3(p, &V);



  /*-$ifdef harddebug*/
  /*      if bb3 then writeln('**EXPR/END *');*/
  /*-$endif*/

_L1: ;



}


Void err(err_num)
long err_num;
{
  long cint;
  ptr_ local, listp;
  string80 m;
  boolean found, var_mes;
  mpd x;
  string80 STR1;

  local = l;
  /*  writeln;
    writeln('RIGAL SYNTAX ERROR NO.',err_num);*/
  switch (err_num) {

  case 2:
    strcpy(m, "SYMBOL '##' NOT FOUND AFTER THE MAIN RULE");
    break;

  case 3:
    strcpy(m, "RULE NAME '#...' NOT FOUND IN THE BEGINNING OF THE RULE");
    break;

  case 5:
    strcpy(m, "SYMBOL '##' NOT FOUND AFTER THE RULE");
    break;

  case 21:
    strcpy(m, "RULE NAME '#...' NOT FOUND IN THE BEGINNING OF THE  MAIN RULE");
    break;

  case 22:
    strcpy(m, "SYMBOL '##' NOT FOUND AFTER THE MAIN RULE");
    break;

  case 23:
    strcpy(m, "MAIN RULE NAME IS BUILT-IN RULE NAME");
    break;

  case 30:
    strcpy(m, "ENDING '/' NOT FOUND AFTER LIST OF STATEMENTS");
    break;

  case 31:
    strcpy(m, "SYMBOL '.)' MATCHING '(.' WAS NOT FOUND");
    break;

  case 37:
    strcpy(m, "UNEXPECTED ELEMENT IN PATTERN");
    break;

  case 38:
    strcpy(m, "UNEXPECTED KEYWORD OR SYMBOL IN PATTERN");
    break;

  case 40:
    strcpy(m,
	   "UNEXPECTED BRANCH FOUND IN TREE PATTERN AFTER VARIABLE  $A:...");
    break;

  case 41:
    strcpy(m, "VARIABLES NOT ALLOWED IN TREE PATTERN  <. $A : ...");
    break;

  case 42:
    strcpy(m, "VARIABLES NOT ALLOWED IN TREE PATTERN  <. ... [ $A : ..]");
    break;

  case 43:
    strcpy(m,
      "ONLY VARIABLES AND IDENTIFIERS ALLOWED AS BRANCH NAME IN TREE PATTERN");
    break;

  case 44:
    strcpy(m, "SYMBOL ':' NOT FOUND IN TREE PATTERN");
    break;

  case 45:
    strcpy(m, "ONLY ONE PATTERN AS BRANCH VALUE IN TREE PATTERN ALLOWED");
    break;

  case 46:
    strcpy(m, "SYMBOL ']' MATCHING ']' NOT FOUND IN TREE PATTERN");
    break;

  case 47:
    strcpy(m, "SYMBOL '.>', '*>' OR ',' MUST BE AFTER BRANCH PATTERN");
    break;

  case 48:
    strcpy(m, "PATTERN  <* ... .> NOT ALLOWED");
    break;

  case 49:
    strcpy(m, "PATTERN  <. ... *> NOT ALLOWED");
    break;

  case 50:
    strcpy(m, "A VARIABLE NOT FIND IN THE LAST BRANCH OF  <* ... *>");
    break;

  case 51:
    strcpy(m, "NO MORE THAN 5 BRANCHES IN  <* ... *> ALLOWED");
    break;

  case 52:
    strcpy(m, "SYMBOL '::' NOT ALLOWED BEFORE RULE NAME");
    break;

  case 53:
    strcpy(m, "SYMBOL '::' NOT ALLOWED BEFORE '('");
    break;

  case 54:
    strcpy(m, "MUST BE AT LEAST ONE PATTERN OR ACTION WITHIN (* *)");
    break;

  case 55:
    strcpy(m, "MUST BE AT LEAST ONE PATTERN OR ACTION WITHIN (+ +)");
    break;

  case 56:
    strcpy(m, "MUST BE AT LEAST ONE PATTERN OR ACTION WITHIN [ ]");
    break;

  case 57:
    strcpy(m, "EMPTY TREE PATTERN IS NOT ALLOWED");
    break;

  case 58:
    strcpy(m, "SYMBOL '::' IS NOT ALLOWED IN THIS POSITION");
    break;

  case 59:
    strcpy(m, "EMPTY ALTERNATIVE IN (..!..) OR EMPTY () ARE NOT ALLOWED");
    break;

  case 61:
    strcpy(m, "SYMBOL ';;' OR '##' EXPECTED");
    break;

  case 63:
    strcpy(m, "RULE NAME  #... NOT FOUND IN THE BEGINNING OF THE RULE");
    break;

  case 64:
    strcpy(m, "SYMBOL ';;' OR '##' EXPECTED");
    break;

  case 65:
    strcpy(m, "THIS RULE NAME IS BUILT-IN RULE NAME");
    break;

  case 66:
    strcpy(m, "SYMBOL ';;' OR '##' EXPECTED");
    break;

  case 71:
    strcpy(m, "WRONG DELIMITER IN (*...* .. ) PATTERN");
    break;

  case 72:
    strcpy(m, "SYMBOL ')' EXPECTED IN (*...* .. ) PATTERN");
    break;

  case 73:
    strcpy(m, "SYMBOL '*)' MATCHING '(*' NOT FOUND");
    break;

  case 74:
    strcpy(m, "WRONG DELIMITER IN (+...+ .. )");
    break;

  case 75:
    strcpy(m, "SYMBOL ')' EXPECTED IN (+...+ .. ) PATTERN");
    break;

  case 76:
    strcpy(m, "SYMBOL '+)' MATCHING '(+' NOT FOUND");
    break;

  case 77:
    strcpy(m, "SYMBOL ']'  MATCHING '['  NOT FOUND");
    break;

  case 81:
    strcpy(m, "ONLY ONE ELEMENT MIGHT BE IN EVERY PART OF (..!..!..!..)");
    break;

  case 82:
    strcpy(m, "ONLY ONE ELEMENT MIGHT BE IN THE LAST PART OF (..!..!..!..)");
    break;

  case 83:
    strcpy(m, "UNEXPECTED SYMBOL IN PATTERN (..!..!..!..)");
    break;

  case 84:
    strcpy(m, "UNEXPECTED  '!' FOUND IN PATTERN (..!..!..!..)");
    break;

  case 86:
    strcpy(m, "SYMBOL '(' EXPECTED AFTER S' OR V'");
    break;

  case 87:
    strcpy(m, "SYMBOL ')' EXPECTED AFTER S'(... OR  V'(...");
    break;

  case 91:
    strcpy(m, "ASSIGNMENT SYMBOL ':=' EXPECTED AFTER '!!', '!.', '++' OR '+'");
    break;

  case 101:
    strcpy(m, "INTERNAL ERROR :MAINADR<>LISTMAIN");
    break;

  case 102:
    strcpy(m, "INTERNAL ERROR : PUSH FOR TREES");
    break;

  case 201:
    strcpy(m, "SYMBOL 'FI','OD', '/', '##' OR  ';;' EXPECTED");
    break;

  case 202:
    strcpy(m, "SYMBOL '->' AFTER 'IF' EXPECTED");
    break;

  case 203:
    strcpy(m, "SYMBOL 'FI' AFTER 'IF...->' EXPECTED");
    break;

  case 205:
    strcpy(m, "SYMBOL '->' AFTER 'ELSIF' EXPECTED");
    break;

  case 206:
    strcpy(m, "SYMBOL 'FI' AFTER 'ELSIF...->' EXPECTED");
    break;

  case 207:
    strcpy(m, "STATEMENT EXPECTED AFTER 'ELSIF..->'");
    break;

  case 208:
    strcpy(m, "SYMBOL 'END' MATCHING 'LOOP' NO FOUND");
    break;

  case 209:
    strcpy(m, "STATEMENT EXPECTED AFTER 'IF..->'");
    break;

  case 210:
    strcpy(m, "VARIABLE NAME OR \"BRANCHES\" OR \"SELECTORS\" EXPECTED");
    break;

  case 211:
    strcpy(m, "SYMBOL 'IN' AFTER 'FORALL' EXPECTED");
    break;

  case 212:
    strcpy(m, "SYMBOL 'DO' AFTER 'FORALL...IN' EXPECTED");
    break;

  case 213:
    strcpy(m, "SYMBOL 'OD' OR ';' EXPECTED AFTER FORALL..DO...");
    break;

  case 215:
    strcpy(m, "SYMBOL ':=' EXPECTED AFTER THIS OBJECT");
    break;

  case 216:
    strcpy(m, "ASSIGNMENT SYMBOL ':=' EXPECTED AFTER '!!','!.','+' OR '++'");
    break;

  case 217:
    strcpy(m, "VARIABLE EXPECTED AFTER \"SELECTORS\" ");
    break;

  case 218:
    strcpy(m, "VARIABLE EXPECTED AFTER \"BRANCHES\" ");
    break;

  case 220:
    strcpy(m, "VARIABLE EXPECTED AFTER 'LOAD'");
    break;

  case 221:
    strcpy(m, "VARIABLE EXPECTED AFTER 'SAVE'");
    break;

  case 222:
    strcpy(m, "FILE IDENTIFIER  EXPECTED AFTER 'OPEN'");
    break;

  case 223:
    strcpy(m, "FILE IDENTIFIER  EXPECTED AFTER 'CLOSE'");
    break;

  case 224:
    strcpy(m, "WRONG BEGINNING OF THE STATEMENT");
    break;

  case 225:
    strcpy(m, "UNEXPECTED SYMBOL AFTER RULE CALL #..(..)");
    break;

  case 301:
    strcpy(m, "SYMBOL ')' EXPECTED");
    break;

  case 302:
    strcpy(m, "RULE NAME #... EXPECTED AFTER 'LAST'");
    break;

  case 303:
    strcpy(m, "VARIABLE NAME $... EXPECTED AFTER 'LAST #...'");
    break;

  case 304:
    strcpy(m, "BUILT-IN RULE NOT ALLOWED IN 'LAST'");
    break;

  case 307:
    strcpy(m, "SYMBOL '$$' ALLOWED ONLY INSIDE  S' PATTERN");
    break;

  case 313:
    strcpy(m, "SYMBOL '(' EXPECTED AFTER 'COPY'");
    break;

  case 314:
    strcpy(m, "SYMBOL ')' EXPECTED AFTER 'COPY (...'");
    break;

  case 321:
    strcpy(m, "SYMBOL ']' MATCHING '[' NOT FOUND IN EXPRESSION");
    break;

  case 323:
    strcpy(m, "UNEXPECTED SYMBOL (END OF '<<'-STATEMENT NOT FOUND)");
    break;

  case 324:
    strcpy(m, "NULL OR A'... NOT ALLOWED IN THE LEFT  SIDE OF THE ASSIGNMENT");
    break;

  case 325:
    strcpy(m, "SYMBOL '(' EXPECTED AFTER RULE CALL IN EXPRESSION");
    break;

  case 327:
    strcpy(m, "WRONG OBJECT OR SYMBOL IN EXPRESSION");
    break;

  case 329:
    strcpy(m, "SYMBOL ':' EXPECTED IN <. ... .> CONSTRUCTOR");
    break;

  case 330:
    strcpy(m, "SYMBOL ',' OR '.>' EXPECTED IN <. ... .> CONSTRUCTOR");
    break;

  case 331:
    strcpy(m, "SYMBOL ',' IS UNEXPECTED");
    break;

  case 405:
    strcpy(m, "RULE WAS DEFINED TWO TIMES (THIS IS THE SECOND) ");
    break;

  case 406:
    strcpy(m, "RULE WAS NOT DEFINED IN PROGRAM ");
    break;

  case 407:
    strcpy(m, "CALL OF THE MAIN RULE NOT ALLOWED ");
    break;

  case 408:
    strcpy(m, "VARIABLE $ NOT ALLOWED IN THE MAIN RULE");
    break;

  case 409:
    strcpy(m, "VARIABLE $$ NOT ALLOWED IN THE MAIN RULE");
    break;

  /* this message is formed in tabr */
  case 501:
    strcpy(m, "INTERNAL ERROR : 1ST PARM - NOT RULE NAME");
    break;

  case 503:
    strcpy(m, "INTERNAL ERROR : 2ND PARM - NOT VARIABLE");
    break;

  case 504:
    strcpy(m, "MORE THAN 255 VARIABLES IN RULE");
    break;

  case 505:
    strcpy(m, "MORE THAN 400 RULES IN PROGRAM");
    break;

  case 521:
    strcpy(m, "no RULENAME in V-list");
    break;

  case 522:
    strcpy(m, "no LISTMAIN in R-list variable list");
    break;

  case 523:
    strcpy(m, "INTERNAL ERROR : THIS RULE NOT FOUND");
    break;

  case 524:
    strcpy(m, "no num in V-list 1-st parm");
    break;

  case 525:
    strcpy(m, "no num in V-list 2-nd parm");
    break;

  case 526:
    sprintf(m, "RULE %s WAS NOT DEFINED IN PROGRAM", error_rec_ch.message);
    break;

  case 527:
    sprintf(m, "RULE %s WAS DEFINED TWO TIMES", error_rec_ch.message);
    break;

  case 528:
    strcpy(m, "INTERNAL ERROR : wrong type in BLTIN rule table");
    break;

  case 699:
    strcpy(m, "UNEXPECTED END OF PROGRAM");
    break;


  default:
    strcpy(m, "UNKNOWN ERROR");
    break;
  }
  /*  writeln(m);*/
  /*  write(' BEFORE THIS TEXT:');*/
  listp = local;
  /*  for cint:=1 to 13 do begin dout(listp.cel);next(listp);end;*/
  cint = 1;
  found = false;
  var_mes = true;

  sprintf(error_rec_ch.message, "%s ", long_to_str(STR1, err_num));
  error_rec_ch.address = 0;
  if (err_num < 500) {
    while (local.nel != 0 && cint < 50 && !found) {
      pointr(local.cel, &x.sa);
      switch (x.sad->dtype) {

      case atom:
      case idatom:
      case keyword:
      case tatom:
      case fatom:
	error_rec_ch.address = x.sad->cord;
	found = true;
	break;

      case rulename:
	error_rec_ch.address = x.srd->cord;
	found = true;
	break;

      case number:
	error_rec_ch.address = x.snd->cord;
	found = true;
	break;

      case variable:
      case idvariable:
      case fvariable:
      case nvariable:  /* allows only for first variable to move to message*/
	if (var_mes) {
	  sprintf(error_rec_ch.message + strlen(error_rec_ch.message), "$%s ",
		  aa_str(STR1, x.svd->name));
	  var_mes = false;
	}
	next(&local);
	break;

      default:
	next(&local);
	break;
      }/*case*/
    }  /* while */
  }

  /*  writeln;
    writeln('Press Enter to see file');
    readln;   */
  er = true;
  strcat(error_rec_ch.message, m);   /* with */


}  /* err */


Void instruc(m)
ptr_ *m;
{
  keyint TEMP, TEMP1;

  while (!(TEMP = valc(l),
	   TEMP == d_semic || TEMP == d_cross || TEMP == slash)) {
    operator_(m);
    if (er)
      goto _L1;
    if (el(semic))
      nextl();
    else {
      TEMP1 = valc(l);
      if (!(TEMP1 == d_semic || TEMP1 == d_cross || TEMP1 == slash)) {
	err(201L);
	goto _L1;
      }
    }
  }
_L1: ;
}


/* Local variables for operator_: */
struct LOC_operator_ {
  ptr_ *m, p;
} ;

Local Void oplist(opcode, LINK)
long opcode;
struct LOC_operator_ *LINK;
{
  nextl();
  newlist(&LINK->p);
  push(LINK->m, LINK->p.UU.U1.mainadr);
  namelist(LINK->p, opcode);
}


Void operator_(m_)
ptr_ *m_;
{
  struct LOC_operator_ V;
  a a1;
  boolean selectors_flag;
  keyint TEMP1, TEMP2;
  char TEMP3;

  V.m = m_;
  if (er)
    goto _L1;
  switch (valc(l)) {

  case if_key:
    oplist(8704L, &V);
    expr(&V.p, true);
    if (er)
      goto _L1;
    if (!el(minus_more)) {
      err(202L);
      goto _L1;
    }
    nextl();
    push(&V.p, 30208L);
    TEMP1 = valc(l);
    if (TEMP1 == elsif_key || TEMP1 == fi_key) {
      err(209L);
      goto _L1;
    }
    while (!(TEMP1 = valc(l), TEMP1 == elsif_key || TEMP1 == fi_key)) {
      operator_(&V.p);
      if (er)
	goto _L1;
      if (el(semic))
	nextl();
      else {
	TEMP2 = valc(l);
	if (!(TEMP2 == elsif_key || TEMP2 == fi_key || TEMP2 == semic)) {
	  err(203L);
	  goto _L1;
	}
      }
    }
    while (el(elsif_key)) {
      nextl();
      push(&V.p, 9216L);

      expr(&V.p, true);
      if (er)
	goto _L1;
      if (el(minus_more))
	nextl();
      else
	err(205L);
      push(&V.p, 30208L);
      TEMP1 = valc(l);
      if (TEMP1 == elsif_key || TEMP1 == fi_key) {
	err(208L);
	goto _L1;
      }
      while (!(TEMP1 = valc(l), TEMP1 == elsif_key || TEMP1 == fi_key)) {
	operator_(&V.p);
	if (er)
	  goto _L1;
	if (el(semic))
	  nextl();
	else {
	  TEMP2 = valc(l);
	  if (!(TEMP2 == elsif_key || TEMP2 == fi_key || TEMP2 == semic)) {
	    err(206L);
	    goto _L1;
	  }
	}
      }  /* while / valc */
    }  /* while / el */
    if (!el(fi_key)) {
      err(207L);
      goto _L1;
    }
    nextl();
    break;

  case load_key:
    oplist(9728L, &V);
    TEMP3 = des(l);
    if (!(((1L << ((long)TEMP3)) & varn_desks) != 0)) {
      err(220L);
      goto _L1;
    }
    pushl(&V.p);
    tabrule(V.p.cel, currulename);
    nextl();
    expr(&V.p, true);
    break;

  case save_key:
    oplist(10240L, &V);
    TEMP3 = des(l);
    if (!(((1L << ((long)TEMP3)) & varn_desks) != 0)) {
      err(221L);
      goto _L1;
    }
    pushl(&V.p);
    tabrule(V.p.cel, currulename);
    nextl();
    expr(&V.p, true);
    break;
    /* oformlenija spiskow dlja razn. tipow operatora */

  case open_key:
    oplist(10752L, &V);
    TEMP3 = des(l);
    if (!(((1L << ((long)TEMP3)) &
	   ((1L << ((long)atom)) | (1L << ((long)idatom)))) != 0)) {
      err(222L);
      goto _L1;
    }
    pushl(&V.p);
    nextl();
    expr(&V.p, true);
    break;

  case close_key:
    oplist(31744L, &V);
    TEMP3 = des(l);
    if (!(((1L << ((long)TEMP3)) &
	   ((1L << ((long)atom)) | (1L << ((long)idatom)))) != 0)) {
      err(223L);
      goto _L1;
    }
    pushl(&V.p);
    nextl();
    break;

  case break_key:
    nextl();
    push(V.m, 16384L);
    break;

  case return_key:
    oplist(11776L, &V);
    expr(&V.p, true);
    break;

  case loop_key:
    oplist(28160L, &V);
    while (!el(end_key)) {   /* while */
      operator_(&V.p);
      if (er)
	goto _L1;
      if (!el(semic)) {
	if (el(end_key))
	  break;
	err(208L);
	goto _L1;
      }
      /* net end posle loop */
      nextl();
    }
    nextl();   /* 'END' - konec operatora */
    break;
    /* loop - key */

  case print_key:
    oplist(32256L, &V);
    expr(&V.p, true);
    break;

  case fail_key:
    nextl();
    push(V.m, 12288L);
    break;

  case forall_key:   /* wyzow prawila,priswaiwanie ili wywod*/
    oplist(12800L, &V);   /* operator cikla */
    if (el(selectors_key)) {
      nextl();
      TEMP3 = des(l);
      if (!(((1L << ((long)TEMP3)) & varn_desks) != 0)) {
	err(217L);
	goto _L1;
      }
      /* variable exp. after selectors */
    }
    TEMP3 = des(l);
    selectors_flag = (((1L << ((long)TEMP3)) & varn_desks) != 0);
    if (selectors_flag) {
      pushl(&V.p);   /* 1st position */
      tabrule(V.p.cel, currulename);
      nextl();
    } else
      push(&V.p, 0L);   /* 1st position */
    if (el(branches_key)) {  /*b*/
      nextl();
      TEMP3 = des(l);
      if (!(((1L << ((long)TEMP3)) & varn_desks) != 0)) {
	err(218L);
	goto _L1;
      }
      /* variable expected after branches */
      pushl(&V.p);   /* 2nd position */
      tabrule(V.p.cel, currulename);
      nextl();
    }  /*b*/
    else {  /* no b */
      push(&V.p, 0L);   /* 2nd position */
      if (!selectors_flag) {
	err(210L);
	goto _L1;
      }
      /* variable name or selector or branches expected */
    }  /* no b */

    if (!el(in_key)) {
      err(211L);
      goto _L1;
    }
    nextl();
    expr(&V.p, true);   /* wyravenie */
    if (er)
      goto _L1;
    if (!el(do_key)) {
      err(212L);
      goto _L1;
    }
    nextl();
    push(&V.p, 30208L);
    while (!el(od_key)) {   /* while */
      operator_(&V.p);   /* telo cikla */
      if (er)
	goto _L1;
      TEMP1 = valc(l);
      if (!(TEMP1 == od_key || TEMP1 == semic)) {
	err(213L);
	goto _L1;
      }
      if (el(semic))
	nextl();
    }
    nextl();   /* od - konec */

    break;
    /* forall - key */



    /* otherwise */

  default:   /* otherw. */
    if (des(l) == rulename) {
      newlist(&V.p);
      push(V.m, V.p.UU.U1.mainadr);
      expr(&V.p, false);
      if (er)
	goto _L1;
      if (V.p.cel != 17920 && V.p.cel != 27136) {
	err(225L);
	goto _L1;
      }
      /* lishnie simwoly posle operatora-wyzowa prawila */
      namelist(V.p, V.p.cel);
    } else {
      TEMP3 = des(l);
      if (((1L << ((long)TEMP3)) &
	   ((1L << ((long)idatom)) | (1L << ((long)atom)))) != 0) {
	/* wywod w fajl */
	newlist(&V.p);
	push(V.m, V.p.UU.U1.mainadr);
	pushl(&V.p);
	nextl();
	if (!(el(d_less) | el(less_rbrac))) {
	  err(224L);
	  goto _L1;
	}
	if (el(d_less))
	  namelist(V.p, 11264L);
	else
	  namelist(V.p, 18432L);
	nextl();
	push(&V.p, 13312L);
	while (!(TEMP1 = valc(l), TEMP1 == od_key || TEMP1 == elsif_key ||
				  TEMP1 == end_key || TEMP1 == d_semic ||
				  TEMP1 == d_cross || TEMP1 == slash ||
				  TEMP1 == fi_key || TEMP1 == semic)) {
	  if (el(reserv5_key)) {
	    push(&V.p, 1024L);
	    nextl();
	  } else
	    expr(&V.p, true);
	  if (er)
	    goto _L1;
	  push(&V.p, 14336L);
	}

	if (V.p.cel == 14336)
	  changeelement(&V.p, 13824L);
	else
	  changeelement(&V.p, 0L);
      } else {  /* priswaiwanie */
	newlist(&V.p);
	push(V.m, V.p.UU.U1.mainadr);
	expr(&V.p, false);   /* lewaja chastj prisw. */
	if (er)
	  goto _L1;
	push(&V.p, 5632L);
	switch (valc(l)) {

	case plus:
	  a1 = 6656;
	  nextl();
	  break;

	case d_plus:
	  a1 = 7168;
	  nextl();
	  break;

	case d_excl:
	  a1 = 7680;
	  nextl();
	  break;

	case excl_point:
	  a1 = 8192;
	  nextl();
	  break;

	case let_sign:
	  a1 = 6144;
	  break;


	default:
	  err(215L);
	  goto _L1;
	  break;
	}/* case/valc */
	if (!el(let_sign)) {
	  err(216L);
	  goto _L1;
	}
	nextl();   /* propuskaem znak ":=" */
	namelist(V.p, a1);   /* tip priswaiwanija -> w imja */
	expr(&V.p, true);   /* prawaja chastj prisw. */
      }  /* priswaiwanie */
    }
    break;
  }/* boljoj case/valc */
_L1: ;


}  /*operator*/


Local Void bltnvar(rname, rnum)
long rname, *rnum;
{
  a a1;
  long ii;
  mpd x, x1;


  *rnum = 0;
  pointr(rname, &x1.sa);   /* access to tested name */
  for (ii = 76; ii <= 99; ii++) {
    if (m1[ii] != 0) {
      pointr(m1[ii], &x.sa);   /* access to "etalon" name */
      if (x.srd->dtype == x1.srd->dtype) {   /* esli tipy ne rawny*/
	if (x.srd->name == x1.srd->name) {
	  /* return specaddress with number
	          (n+10)*512 , where n- function's number */
	  *rnum = (ii - 65) * 512;
	  goto _L1;
	}  /*if =name*/
      }  /*if =dtype*/
      else
	err(528L);
    }  /* if m1[ii]>0 */
  }
_L1: ;
}


/* 2-jul-91 some comments inserted and some pretty-printed */
/* 23-jan-92 additional limitations and un-limitations added:
   errors no. 52-59 */
Void pict(m, siz, act)
ptr_ *m;
long *siz, *act;
{
  /* processes sequence of pattersn, puts code to list "m",
     count of patterns is "siz", count of action pieces is "act"  */
  boolean pattern;
  long s1, ac1, arcnumber;   /* number of arc patterns*/
  ptr_ z, z1, l1, l3;
  a spopcode, a_title, a_arcvar, a_varname, limiter, a_bltnvar;
  boolean specoperator, agregname, lastarcflag, treestarflag, treebracflag,
	  alternflag;
  char TEMP;
  keyint TEMP1;
  char TEMP2;


  *siz = 0;   /* counter of patterns */
  *act = 0;   /* counter of non-empty actions */
  specoperator = false;   /* net operatora */
  agregname = false;   /* net agregata */
  pattern = true;   /* w nachale ovidaetsja shablon,a ne operator */

  do {

    /******************************************* / actions / ******/
    if (el(slash)) {  /* the slash "/" switches */
      nextl();
      push(m, 28672L);
      if (!el(slash))
	(*act)++;
      instruc(m);
      if (er)   /*operatory wnutri spiska */
	goto _L1;
      push(m, 28672L);
      if (!el(slash)) {
	err(30L);
	goto _L1;
      }
      nextl();
    } else {
      /* enters one pattern */
      (*siz)++;

      /********************************************   (* interation *) ****/
      if (el(lpar_star)) {
	nextl();
	newlist(&z);
	push(m, z.UU.U1.mainadr);
	namelist(z, (long)se);   /* se - standart */
	push(&z, 5120L);   /* net ogranichitelja w "( *"-konstr. */
	z1 = z;   /* movet-budet */
	pict(&z, &s1, &ac1);   /* rekursiwno wyzow posledowateljnosti */
	if (er)
	  goto _L1;

	if (s1 + ac1 == 0) {
	  err(54L);
	  goto _L1;
	}

	if (el(star)) {
	  nextl();
	  TEMP = des(l);
	  if (!(((1L << ((long)TEMP)) & ((1L << ((long)idatom)) |
		   (1L << ((long)atom)) | (1L << ((long)rulename)) |
		   (1L << ((long)number)) | (1L << ((long)spec)))) != 0))
	  {   /* added */
	    err(71L);
	    goto _L1;
	  }
	  /* estj ogranichitelj */
	  dul(&limiter);   /* l.cel -> w sp2 po adresu limitera*/
	  if (des(l) == rulename) {
	    bltnvar(l.cel, &a_bltnvar);
	    if (a_bltnvar != 0)
	      limiter = a_bltnvar;
	    else
	      tabrule(0L, limiter);
	  }
	  if (er)
	    goto _L1;
	  changeelement(&z1, limiter);
	  /* perewod w sp2 w mesto z1 iz l-spiska */
	  nextl();
	  /* skobka posle ogranichitelja */
	  if (!el(rpar)) {
	    err(72L);
	    goto _L1;
	  }
	  nextl();
	} else if (el(rpar_star))
	  nextl();
	else {
	  err(73L);
	  goto _L1;
	}
	goto _L99;
      }

      /********************************************   (+ interation +) ****/
      if (el(lpar_plus)) {
	nextl();
	newlist(&z);
	push(m, z.UU.U1.mainadr);
	namelist(z, (long)ps);   /*  ps - standart */
	push(&z, 5120L);   /*  net ogranichitelja w "(+"-konstr. */
	z1 = z;   /* movet-budet */
	pict(&z, &s1, &ac1);   /* rekursiwno wyzow posledowateljnosti */
	if (er)
	  goto _L1;

	if (s1 + ac1 == 0) {
	  err(55L);
	  goto _L1;
	}

	if (el(plus)) {
	  nextl();
	  TEMP = des(l);
	  if (!(((1L << ((long)TEMP)) & ((1L << ((long)idatom)) |
		   (1L << ((long)atom)) | (1L << ((long)rulename)) |
		   (1L << ((long)number)) | (1L << ((long)spec)))) != 0))
	  {   /* added */
	    err(74L);
	    goto _L1;
	  }
	  /* estj ogranichitelj */
	  dul(&limiter);   /* perewod w sp2 w mesto z1 iz l-spiska*/
	  if (des(l) == rulename) {
	    bltnvar(l.cel, &a_bltnvar);
	    if (a_bltnvar != 0)
	      limiter = a_bltnvar;
	    else
	      tabrule(0L, limiter);
	  }
	  if (er)
	    goto _L1;
	  changeelement(&z1, limiter);
	  nextl();
	  /* skobka posle ogranichitelja */
	  if (!el(rpar)) {
	    err(75L);
	    goto _L1;
	  }
	  nextl();
	} else if (el(rpar_plus))
	  nextl();
	else {
	  err(76L);
	  goto _L1;
	}
	goto _L99;
      }

      /******************************************** [ optional ] ****/

      if (el(lbrac)) {
	nextl();
	newlist(&z);
	push(m, z.UU.U1.mainadr);
	namelist(z, (long)fa);   /*  fakuljtatiw - standart */
	pict(&z, &s1, &ac1);
	if (er)
	  goto _L1;
	if (s1 + ac1 == 0) {
	  err(56L);
	  goto _L1;
	}
	if (!el(rbrac)) {
	  err(77L);
	  goto _L1;
	}
	nextl();
	goto _L99;
      }

      specoperator = false;
      /* estj li dop.
                              operator
                              priswaiwanija */
      agregname = false;
      /* ukazano li imja
                           agregata */


      TEMP = des(l);
      /******************************    assign variable $x:=   ****/

      if (((1L << ((long)TEMP)) & varn_desks) != 0) {
	dul(&a_varname);   /* zdesj imja peremennoj*/
	tabrule(a_varname, currulename);
	if (er)
	  goto _L1;
	l1 = l;   /* sohranim na sluchaj, esli dalee ne operator */
	nextl();
	/* added 17-jan-1990 for (+ $e $r + tt ) difference from
	                              $r + := tt */
	if (valc(l) == plus) {
	  nextl();
	  nextl();
	  if (valc(l) == rpar) {
	    l = l1;
	    goto _L55;
	  }
	  l = l1;
	  nextl();
	}

	TEMP1 = valc(l);
	if ((unsigned)TEMP1 < 32 &&
	    ((1L << TEMP1) & ((1L << plus) | (1L << d_plus) | (1L << d_excl) |
			      (1L << excl_point))) != 0)
	{   /* backtracking : no assignment symbols */
	  /* esli posle perem. +,++,!!,!. i :=, to dop. operator */
	  l3 = l;   /* l3 - zdesj znak tipa priswaiwanija */
	  nextl();
	  if (!el(let_sign))
	    err(91L);
	  if (er)
	    goto _L1;
	  nextl();   /* propuskaetsja znak := */
	  switch (valc(l3)) {

	  /* generiruetsja kod specoperatora */
	  case plus:
	    spopcode = 6656;
	    break;

	  case d_plus:
	    spopcode = 7168;
	    break;

	  case d_excl:
	    spopcode = 7680;
	    break;

	  case excl_point:
	    spopcode = 8192;
	    break;
	  }/* case */
	  specoperator = true;
	}  /* if/in */
	else {  /* movet bytj operator priswaiwanija */
	  if (el(let_sign)) {  /* esli $a:= ... */
	    push(m, 29184L);   /* null -> $a */
	    push(m, a_varname);
	    nextl();   /* propusk ego ":=" */
	    spopcode = 6144;   /* kod obychnogo prisw. */
	    specoperator = true;
	  }  /* if ":=" */
	  else  /* woobshe ne operator */
	    l = l1;
	}
      }  /* if variable */


_L55:

      /*****************  position after assignment ( main position ) ****/


      TEMP = des(l);
      /****************   $x ::  or  aa ::  ********/

      if (((1L << ((long)TEMP)) & (varn_desks | (1L << ((long)atom)) |
	     (1L << ((long)idatom)) | (1L << ((long)number)) |
	     (1L << ((long)fatom)) | (1L << ((long)spec)))) != 0) {
	dul(&a_title);
	TEMP2 = des(l);
	if (((1L << ((long)TEMP2)) & varn_desks) != 0) {
	  tabrule(a_title, currulename);
	  if (er)
	    goto _L1;
	  if (specoperator)
	    nextl();
	  else {  /* ne nado powtorno pechatatj imja perem.*/
	    next(&l);
	    if (l.nel == 0)
	      err(699L);
	    if (er)
	      goto _L1;
	  }
	} else
	  nextl();


	if (!el(d_colon)) {  /* ******** no :: **** */
	  /* esli dalee ne "::", to eto prosto */
	  /*  peremennaja ili atom */
	  push(m, a_title);
	  goto _L99;
	}
	nextl();
	agregname = true;
      }  /* if/in */

      /********************************************   (. list .) ****/

      if (el(lpar_point)) {
	nextl();
	newlist(&z);
	push(m, z.UU.U1.mainadr);   /* spisok opisanija ego */
	namelist(z, (long)li);   /* standart */
	if (agregname) {   /* net imeni */
	  agregname = false;
	  /* wstawljaem imja spiska */
	  push(&z, a_title);
	} else
	  push(&z, 5120L);
	pict(&z, &s1, &ac1);   /* sam spisok*/
	if (er)
	  goto _L1;
	if (el(rpar_point))
	  nextl();
	else
	  err(31L);
	if (er)
	  goto _L1;
	goto _L99;
      }


      /******************************   ( alternative or group ) ****/

      if (el(lpar)) {  /* "(" */
	if (agregname) {
	  err(53L);
	  goto _L1;
	}
	alternflag = false;   /* ovidaetsja, chto net '!' */
	nextl();
	newlist(&z);
	push(m, z.UU.U1.mainadr);
	namelist(z, (long)al);   /* aljternatiwa-standart */
	do {
	  pict(&z, &s1, &ac1);
	  if (er)
	    goto _L1;
	  if (s1 + ac1 == 0) {
	    err(59L);
	    goto _L1;
	  }
	  if (!(el(excl_sign) | el(rpar))) {
	    err(83L);   /* newernyj simwol w */
	    if (er)   /*      (..!..!..) */
	      goto _L1;
	    nextl();
	  }
	  if ((s1 <= 1) & el(excl_sign)) {
	    /* eto nastojashaja aljternatiwa */
	    push(&z, 4608L);   /* razdelitelj aljternatiw */
	    alternflag = true;   /* wse ve estj '!'*/
	    nextl();
	    if (el(rpar))
	      err(84L);
	    if (er)   /* ')' posle '!' */
	      goto _L1;
	  }
	  if ((s1 > 1) & el(excl_sign))
	    err(81L);
	  if (er)
	    goto _L1;
	} while (!el(rpar));   /* do prawoj skobki */
	if (s1 > 1 && alternflag)
	  err(82L);
	if (er)
	  goto _L1;
	nextl();
	goto _L99;
      }

      /******************************   #xxx ****/

      if (des(l) == rulename) {  /* imja prawila */
	if (agregname) {
	  err(52L);
	  goto _L1;
	}
	bltn(l.cel, &a_bltnvar);
	if (a_bltnvar == 0) {
	  pushl(m);
	  tabrule(0L, m->cel);
	  if (er)
	    goto _L1;
	} else {
	  push(m, 27136L);
	  push(m, a_bltnvar);
	}
	nextl();
	goto _L99;
      }

      TEMP1 = valc(l);
      /******************************   <* tree iteration  *>  <. tree .> ****/
      if ((unsigned)TEMP1 < 32 &&
	  ((1L << TEMP1) & ((1L << less_point) | (1L << less_star))) != 0) {
	treestarflag = (valc(l) == less_star);
	nextl();
	newlist(&z);
	push(m, z.UU.U1.mainadr);
	if (treestarflag)
	  namelist(z, 3584L);
	else
	  namelist(z, 512L);
	/* tip shablona <* ili <. */
	if (agregname) {
	  agregname = false;   /* esli bylo imja derewa */
	  push(&z, a_title);
	} else
	  push(&z, 5120L);
	lastarcflag = false;   /* poslednjaja li wetwj */
	if (el(more_star) | el(more_point)) {
	  err(57L);
	  goto _L1;
	}
	/* empty tree is not allowed */
	arcnumber = 0;
	while (!(el(more_star) | el(more_point))) {
	  arcnumber++;   /* podschet wetwej */
	  if (lastarcflag)
	    err(40L);
	  if (er)
	    goto _L1;
	  /* ne dolvno bytj wetwej za   $a:... */
	  if (el(lbrac)) {
	    push(&z, 31232L);
	    nextl();
	    treebracflag = true;   /* estj [...] */
	  } else {
	    push(&z, 0L);
	    z1 = z;   /* sohranjaem chtoby potom */
	    /* w poslednij raz menjatj  0  na 30208 */
	    treebracflag = false;
	  }
	  TEMP = des(l);
	  if (((1L << ((long)TEMP)) & (1L << ((long)idatom))) != 0) {
		/*atom,*/
		  /* atom - imja wetwi derewa */
		  pushl(&z);
	    nextl();
	  } else {
	    TEMP2 = des(l);
	    if (((1L << ((long)TEMP2)) & varn_desks) != 0) {
	      lastarcflag = true;   /* tut poslednjaja wetwj */
	      if (!treestarflag)
		err(41L);
	      if (er)
		goto _L1;
	      /* zapretna peremennaja w <. $a : ... .> */
	      if (treebracflag)
		err(42L);
	      if (er)
		goto _L1;
	      /* zapretna peremennaja w [ $a : ... ] */
	      changeelement(&z1, 30208L);   /* zamenjaem 0 dlja priznaka */
	      dul(&a_arcvar);
	      tabrule(a_arcvar, currulename);
	      if (er)
		goto _L1;
	      push(&z, a_arcvar);   /* peremennaja -imja wetwi */
	      nextl();
	    } else
	      err(43L);
	  }
	  /*, fatom, number */
	  if (er)   /* ne peremennaja i ne atom */
	    goto _L1;

	  /* ****************************** : ***** */
	  if (el(colon_sign))
	    nextl();
	  else
	    err(44L);
	  if (er)   /* net : */
	    goto _L1;
	  pict(&z, &s1, &ac1);
	  if (er)
	    goto _L1;
	  if (s1 != 1)
	    err(45L);
	  if (er)   /* ne odin shablon */
	    goto _L1;
	  if (treebracflag) {
	    if (el(rbrac))
	      nextl();
	    else
	      err(46L);
	  }
	  if (er)
	    goto _L1;
	  /* net ] posle [... : ... */
	  if (el(comma_sign)) {
	    push(&z, 4096L);
	    nextl();
	    if (el(more_point) | el(more_star))
	      err(331L);
	  } else if (!(el(more_point) | el(more_star)))
	    err(47L);
	  if (er)
	    goto _L1;
	}  /* while , cikl po wetwjam derewa */

	if (treestarflag & el(more_point))
	  err(48L);
	if (er)   /* <* .> */
	  goto _L1;
	if ((!treestarflag) & el(more_star))
	  err(49L);
	if (er)   /* <. *> */
	  goto _L1;
	if (treestarflag && !lastarcflag)
	  err(50L);
	if (er)   /* netu <* ..,...,$e:...*> */
	  goto _L1;
	if (treestarflag && arcnumber > 5)
	  err(51L);
	if (er)
	  goto _L1;
	/* bolee  5  wetwej zapreseny */
	nextl();
	goto _L99;
      }


      if (agregname) {
	err(58L);
	goto _L1;
      }

      /* ********************* v'()  S'() *********** */



      if (el(v_apost) | el(s_apost)) {
	newlist(&z);
	bspi = true;
	if (el(s_apost))
	  namelist(z, 6656L);
	else
	  namelist(z, 6144L);
	nextl();
	if (!el(lpar))
	  err(86L);
	if (er)
	  goto _L1;
	nextl();
	push(m, z.UU.U1.mainadr);
	expr(&z, true);
	if (er)
	  goto _L1;
	if (!el(rpar))
	  err(87L);
	if (er)
	  goto _L1;
	nextl();
	bspi = false;
	goto _L99;
      }

      (*siz)--;
      /* it was not a pattern element, but
                         pattern close symbol */
      /* ******************************* errors ********** */
      if (des(l) == keyword) {
	TEMP1 = valc(l);
	if (!(TEMP1 == comma_sign || TEMP1 == more_point ||
	      TEMP1 == more_star || TEMP1 == rpar_plus ||
	      TEMP1 == rpar_point || TEMP1 == excl_sign || TEMP1 == rpar ||
	      TEMP1 == rbrac || TEMP1 == plus || TEMP1 == onfail_key ||
	      TEMP1 == d_cross || TEMP1 == d_semic || TEMP1 == rpar_star ||
	      TEMP1 == star))
	{   /* slash ? */
	  err(38L);
	  if (er)
	    goto _L1;
	  nextl();
	}  /* neovidannoe kl. slowo w shablone */
      } else
	err(37L);
      if (er)
	goto _L1;
      /* neovidannyj simwol w
                  shablone */

_L99:
      if (specoperator) {
	specoperator = false;
	push(m, spopcode);
	/* stawitsja imja peremennoj w specoperatore */
	push(m, a_varname);
      }
    }  /* if/pattern */
_L111:
    if (er)
      goto _L1;
    /*
      slash ? */
  } while (!(TEMP1 = valc(l), TEMP1 == comma_sign || TEMP1 == more_point ||
			      TEMP1 == more_star || TEMP1 == rpar_plus ||
			      TEMP1 == rpar_point || TEMP1 == excl_sign ||
			      TEMP1 == rpar || TEMP1 == rbrac ||
			      TEMP1 == plus || TEMP1 == onfail_key ||
			      TEMP1 == d_cross || TEMP1 == d_semic ||
			      TEMP1 == rpar_star || TEMP1 == star));
_L1: ;

  /* eto imja agregata */
}  /* pict */


Void push(pp, adr)
ptr_ *pp;
long adr;
{
  mpd x, x1;
  a a1;

  /* dobawljaet po pojnteru spiska nowyj element k spisku*/
  /* i sdwigaet pojnter pp */
  if (pp->ptrtype != ptrlist) {
    printf("Rigal internal error Push-102\n");
    return;
  }  /* if/then */
  points(pp->UU.U1.mainadr, &x.sa);
  if (x.smld->dtype == listmain)
    x.smld->totalelnum++;
  else
    printf("Rigal internal error Push-101\n");
  points(pp->UU.U1.curfragment, &x.sa);
  if (x.smld->dtype == listmain && pp->nel == mainlistelnum ||
      x.sfld->dtype == listfragm && pp->nel == fragmlistelnum) {
    /* w sluchae dostivenija konca fragmenta spiska */
    gets5(&a1, &x1.sa);
    if (x.smld->dtype == listmain)   /* podceplenie */
      x.smld->next = a1;
    else
      x.sfld->next = a1;
    /* obrazuem i zapolnjaem nowyj  */
    x1.sfld->dtype = listfragm;
    x1.sfld->elnum = 1;
    x1.sfld->elt[0] = adr;
    points(pp->UU.U1.mainadr, &x.sa);
    x.smld->lastfragm = a1;
    /* sdwig pojntera */
    pp->nel = 1;
    pp->cel = adr;
    pp->UU.U1.curfragment = a1;
    return;
  }  /* then */
  /* ob{ij cluchaj dobawlenija elementa wnutri fragmenta */
  switch (x.smld->dtype) {

  case listmain:
    x.smld->elnum++;
    x.smld->elt[pp->nel] = adr;
    break;

  case listfragm:
    x.sfld->elnum++;
    x.sfld->elt[pp->nel] = adr;
    break;
  }/* case */
  pp->nel++;
  pp->cel = adr;

  /* else */
}  /* push */


Void newlist(pp)
ptr_ *pp;
{
  /* nowyj ukazatelj spiska */
  /* sozdaet nowyj spisok */
  mpd x;

  a a1;

  gets5(&a1, &x.sa);
  x.smld->dtype = listmain;
  x.smld->lastfragm = a1;
  pp->ptrtype = ptrlist;
  pp->cel = 0;
  pp->nel = 0;
  pp->UU.U1.curfragment = a1;
  pp->UU.U1.mainadr = a1;
}


Void namelist(pp, name)
ptr_ pp;
long name;
{
  /* ukazatelj spiska */
  /* imja */
  /* priswaiwaet imja spisku */
  mpd x;
  a a1;

  a1 = pp.UU.U1.mainadr;
  points(a1, &x.sa);
  x.smld->name = name;
}


Void changeelement(pp, adr)
ptr_ *pp;
long adr;
{
  /* gde izmenitj */
  /* na chto */
  /* izmenjaet odin el-t spiska */
  mpd x;
  a a1;

  a1 = pp->UU.U1.curfragment;
  points(a1, &x.sa);
  if (x.sfld->dtype == listfragm)
    x.sfld->elt[pp->nel - 1] = adr;
  else
    x.smld->elt[pp->nel - 1] = adr;
  pp->cel = adr;
}


/*=================================*/
Void bltn(rname, rnum)
long rname, *rnum;
{
  a a1;
  long ii;
  mpd x, x1;


  *rnum = 0;
  pointr(rname, &x1.sa);   /* dostup k prowerjaemomu imeni */
  for (ii = 76; ii <= 111; ii++) {   /* 111-76=35 funkcij */
    if (etalon[ii] != 0) {
      if (rulename == x1.srd->dtype) {   /* esli tipy ne rawny */
	if (x1.srd->name == etalon[ii])
	{  /* zapolnjaetsja deskriptor s nomerom */
	  gets1(&a1, &x.sa);
	  x.snd->dtype = number;
	  x.snd->val = ii - 75;
	  *rnum = a1;
	  goto _L1;
	}  /*if =name*/
      }  /*if =dtype*/
      else
	err(528L);
    }  /* if m1[ii]>0 */
  }
_L1: ;
}


Void dul(ad)
long *ad;
{
  a a1, a2;
  mpd x1, x;

  a2 = 12;   /* fikcija */
  a1 = l.cel;
  pointr(a1, &x.sa);
  switch (x.sad->dtype) {

  case listfragm:
  case listmain:
  case treefragm:
  case treemain:
    gets5(&a2, &x1.sa);
    *x1.sfld = *x.sfld;
    break;

  case rulename:
    gets2(&a2, &x1.sa);
    *x1.srd = *x.srd;
    break;


  default:
    gets1(&a2, &x1.sa);
    *x1.sc8 = *x.sc8;
    break;
  }/* case */
  *ad = a2;
}


Void pushl(m)
ptr_ *m;
{
  /* kak push(m,l.cel) ,no iz sp1 w sp2 */
  a a1;

  dul(&a1);
  push(m, a1);
}


char des(g)
ptr_ g;
{
  a a1;
  mpd x;

  a1 = g.cel;
  if (a1 == null_) {
    err(699L);
    return dummy;
  } else {
    pointr(a1, &x.sa);
    return (x.sad->dtype);
  }
}


Void nextl()
{
  next(&l);
  if (l.nel == 0)
    err(699L);
}


keyint valc(pp)
ptr_ pp;
{
  /* type keyint=0..127 */
  long ii;
  keyint vv;
  mpd x;
  a a1;

  vv = 127;   /* not key-valcue */

  if (pp.nel == 0)
    return vv;
  else {  /* this branch is added 15-jul-91 */
    if (pp.cel == saveladr)
      return saveelkey;
    else {
      if (des(pp) == keyword) {
	a1 = pp.cel;
	pointr(a1, &x.sa);
	a1 = x.sad->name;
	for (ii = 1; ii <= 75; ii++) {   /*maxkey*/
	  if (a1 == etalon[ii]) {
	    vv = ii;
	    goto _L1;
	  }
	}
      }
_L1:
      saveladr = pp.cel;
      saveelkey = vv;
      return vv;
    }

  }



}


boolean el(ii)
keyint ii;
{
  /* predikat na keyword-y */
  return (valc(l) == ii);
}


/***********/
Local Void simplerule(d)
ptr_ *d;
{
  long s1, ac1;
  ptr_ t, t1, k;

  newlist(&t);
  push(d, t.UU.U1.mainadr);
  push(&t, (long)null_);
  t1 = t;
  pict(&t, &s1, &ac1);
  if (er)
    goto _L16;
  if (el(onfail_key)) {
    newlist(&k);
    changeelement(&t1, k.UU.U1.mainadr);
    nextl();
    instruc(&k);
    if (er)
      goto _L16;
  }
  if (!(el(d_cross) | el(d_semic)))
    err(61L);
_L16: ;
}  /* simplerule */


Void rule(d)
ptr_ *d;
{
  mpd x;
  a a1;
  boolean end_bran;
  long ii;

  /* ************************ */
  if (des(l) == rulename) {
    bltn(l.cel, &a1);
    if (a1 != 0)
      err(65L);
    if (er)
      goto _L15;
    pushl(d);
  } else
    err(63L);
  /* pohove na push(d,l.cel) , no nado */
  /* perestawitj atom iz sp1 w sp2 */
  if (er)
    goto _L15;
  tabrule(512L, d->cel);   /* 512=registration of declaration */
  if (er)
    goto _L15;
  /* formirowanie prawila w tabl. */
  currulename = d->cel;

  for (ii = 1; ii <= 2; ii++) {
    gets2(&a1, &x.sa);
    x.snd->dtype = number;
    x.snd->val = 0;
    push(d, a1);
  }
  nextl();
  do {
    simplerule(d);
    if (er)
      goto _L15;

    if (!(el(d_semic) | el(d_cross))) {
      err(64L);
      if (er)
	goto _L15;
      nextl();
    }
    end_bran = el(d_semic);
    if (end_bran)
      nextl();
  } while (end_bran);
  if (!el(d_cross))   /* message=64 */
    err(66L);
_L15: ;
}


/* manager of rule and variable table
   - sets numbers of rules and variables in table
   and in the descriptors;
   - checks context conditions */

Void tabrule(av, ar)
long av, ar;
{
  /* s-address of varaible
                              or 0   == call of rule
                              or 512 == declaration of rule
                            */
  /* s-address of rule */
  /* tabv - array of lists of s-addresses of variable names */
  /* tabn - array of a-addresses of rule names  */
  /* list is  0    */
  /* or       0 var var var ... */
  /* program chepil also checks context conditions using this table */
  ptr_ f2, f5;   /* pointers for traversing the table */
  long vnum, nb, rn, i;   /* counters */
  boolean bb2;   /*local flags */
  mpd x, x1;   /* deskriptors */
  a p1, aar;


  /* finds or adds rule in table */

  pointr(ar, &x.sa);
  aar = x.srd->name;
  nb = 1;
  while (aar != tabn[nb - 1] && nb < rulemaxnum && tabn[nb - 1] != 0)
    nb++;
  if (nb == rulemaxnum) {
    err(505L);
    goto _L77;
  }
  /* too many rules */
  if (tabn[nb - 1] == 0) {
    tabn[nb - 1] = aar;   /* append new rule */
    tabfiles[nb - 1] = error_rec_ch_adr;
    /* a-address of current file name or 0 if main*/
    tabcord[nb - 1] = x.srd->cord;
  }
  rn = nb;

  /* checks declaration twice */

  if (av == 512) {
    /* registration of the declaration */
    tabflags[nb - 1]++;
    if (tabflags[nb - 1] == 2) {
      err(405L);
      goto _L77;
    }
    av = 0;
  } else {
    if (av == 0) {
      if (nb == 1) {
	err(407L);
	goto _L77;
      }
      /* call of the main rule is not allowed */
    }
  }


  if (av != 0) {
    points(av, &x1.sa);   /* access to variable name */
    if (x1.svd->name != null_ && x1.svd->name != ass_1) {
      if (tabv[rn - 1] == 0) {
	/* create variable list */
	newlist(&f2);
	tabv[rn - 1] = f2.UU.U1.mainadr;   /* push it to table */
	push(&f2, 0L);   /* first is null always */
      }
      /* updates variable list */
      /* nb: variable $$ is not processed here */

      p1 = tabv[rn - 1];
      first(p1, &f2);   /* f2 - at first element */
      f5 = f2;   /* save */
      bb2 = false;   /* variable not found */
      vnum = 1;   /* counter along variable list */
      next(&f2);   /* f2 at second element */

      while (f2.nel != 0) {  /* poka ne konchilsja spisok peremennyh ... */
	vnum++;
	/* cikl wdolj spiska peremennyh */
	p1 = f2.cel;
	points(p1, &x.sa);   /* dostup k mestu peremennoj w tablice */
	points(av, &x1.sa);   /* dostup k nastojashchemu opis. peremennoj */
	if (((1L << ((long)x1.svd->dtype)) & varn_desks) == 0) {
	  err(503L);
	  goto _L77;
	}  /* oshibka w chekere */
	if (x1.svd->name == x.svd->name) {
	  bb2 = true;   /* peremennaja najdena */
	  x1.svd->location = vnum;   /* ustanowka ee nomera */
	  x.svd->location = vnum;   /* to ve */
	}
	f5 = f2;   /* posledn. zanjatyj el-t */
	next(&f2);   /* sdwig na sled. opisanie peremennoj */
      }  /* while */
      if (!bb2) {  /* peremennaja ne najdena */
	gets1(&p1, &x.sa);
	push(&f5, p1);   /* el-t - nowaja peremennaja */
	points(p1, &x.sa);
	/* dostup k nowomu mestu dlja peremennoj w
	                      tabl.*/
	points(av, &x1.sa);   /* dostup k nastojashchemu opis. peremennoj */
	x1.svd->location = vnum + 1;   /* ustanowim nomer peremennoj */
	if (vnum >= 255) {
	  err(504L);
	  goto _L77;
	}
	*x.svd = *x1.svd;   /* zapolneno mesto */
      }  /* if/bb2 */
    }  /* if/  ,null,ord(' ')*/
    else {
      /* variable $ is registered with number 1  */
      if (x1.svd->name == ass_1) {
	x1.svd->location = 1;
	if (rn == 1)
	  err(408L);
	/* $ in main rule not allowed */
      }
    }

  }  /* if/ av<>0 */

_L77: ;

  /* check call of the main rule */

}  /* tabrule */

























#define tempo           "_CH_RIG.TMP"


a ttt, tt1;
filespecification name;

Char pch[101];
long i;
FILE *sour, *lstn;

error_rec_type erm;
string80 str_val, stt;
Char zzz[256];
Char zzz2[256];


extern Void system PP((Char *zz));

extern Void execl PP((Char *zz, Char *zz1, Char *rca));


Static Void copy_line()
{
  char *TEMP;
  Char STR1[256];

  fgets(str_val, 81, sour);
  TEMP = strchr(str_val, '\n');
  if (TEMP != NULL)
    *TEMP = 0;
  sprintf(STR1, "%.3s", str_val);
  if (strcmp(STR1, "--:"))
    fprintf(lstn, "%s\n", str_val);
}


main(argc, argv)
int argc;
Char *argv[];
{

  Char STR1[256];
  Char STR2[86];

/* printf("argc=%d\n",argc);
 printf("arg[0]=%s\n",argv[0]);
 printf("arg[1]=%s\n",argv[1]);
 printf("arg[2]=%s\n",argv[2]);
*/
/* p2c: rc_.z: Note: Array of files files should be initialized [257] */
  lstn = NULL;
  sour = NULL;
  out = NULL;
  if (argc > 1) {
    strcpy(name,argv[1]);
    brt(name);
  } else
    *name = '\0';
  /*****************************/
 /*  strcpy(name,"a"); */
  if (*name == '\0') {
    printf(" Rigal Checker and Compiler v.%s\n", rigal_version);
    printf(" rc filename [-c] [-D] [-P options ]\n");
    printf(" filename must be  without extension, .rig is appended\n");
    goto _L99;

  }


  printf("Rigal Checker/Compiler V.%s, 1996,LU Riga ", rigal_version);
  if (out != NULL)
    out = freopen("check_tmp.out", "w", out);
  else
    out = fopen("check_tmp.out", "w");
  if (out == NULL)
    _EscIO(FileNotFound);
  out_screen = false;
  max_printlevel = max_printconst;
  *erm.message = '\0';
  strcpy(name,argv[1]);
  brt(name);


  sprintf(STR2, "%s.rig", name);
  if (!existfile(STR2)) {
    printf("Error : file %s.rig not found \n", name);
    goto _L99;
  }
  printf("%s.rig\n", name);

  init_dinform();   /* defpage */
  opena();
  opens('@');
  sprintf(STR2, "%s.rig", name);

  ley(STR2, &ttt, false, &erm);   /*ley*/
  if (*erm.message == '\0') {
    che11(ttt, &tt1, name, &erm,argc,argv);
    if (!er) {
      strcat(name, ".rsc");
      savesn(name, &tt1);
    }
  } else
    er = true;


  closes();
  closea();
  /*
reset(sour,erm.filename);
rewrite(lstn,tempo);
if er then
writeln(lstn,'--:**  See error message in line ',erm.address div 80);
if not er then
   begin
    while not(eof(sour)) do copy_line;

   end
else
   begin
   for i:=1 to erm.address div 80 do begin
    if not(eof(sour)) then copy_line;
    end;
   end;

if er then begin
    write(lstn,'--:');
    for i:=5 to erm.address mod 80 do write(lstn,'-');
    writeln(lstn,'^');
    writeln(lstn,'--:** ',erm.message);
    writeln(lstn,'--:** **************************************************');
    writeln(lstn,'--:** **************************************************');
    while not(eof(sour)) do copy_line;
end;

close(lstn);
close(sour);


  */
  if (out != NULL)
    fclose(out);
  out = NULL;
  if (er) {
    if (erm.filename[strlen(erm.filename) - 1] != 'g') {
      sprintf(STR1, "%.*s", (int)(strlen(erm.filename) - 1L), erm.filename);
      strcpy(erm.filename, STR1);
    }
    printf(" Error in file %s\n", erm.filename);
    printf(" Line=%12d\n", erm.address / 80);
    printf(" Message=%s\n", erm.message);

    printf(" Column = %12d\n", erm.address % 80);
    /*  for i:=2 to erm.address mod 80 do write(' ');
      writeln('^');*/
    goto _L99;
  } else {
    printf("No errors found\n");
    for (i = 1; i < argc; i++) {
      strcpy(stt,argv[i]);
      brt(stt);
      if (!strcmp(stt, "-c"))
	goto _L98;
    }
    goto _L99;
  }
_L98:
  strcpy(zzz, "/bin/csh -f ./xd");
  zzz[16] = '\0';
  /* zzz:='xd';
   zzz[3]:=chr(0); */
  printf("Starts xd\n");
  /* execl(zzz,zzz,nil);*/
  system(zzz);

_L99:

  if (out != NULL)
    fclose(out);
  if (sour != NULL)
    fclose(sour);
  if (lstn != NULL)
    fclose(lstn);
  exit(0);
}
/* End. */


