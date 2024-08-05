#include "globrig.h"
#include "define.h"
#include "defpage.h"
#include "nef2.h"
#include "c1.h"

Void prolog()
{
  /*===============*/
  /* inicializaciq */
  /*===============*/
  long k, iii, i;
  string80 printfile_str, sstr;





  /* inicializaciq peremennyh */

  /*if argc>1 then    argv(1,printfile_str) else printfile_str:='';*/
  *printfile_str = '\0';
  for (i = 1; i < g_argc; i++) {
    strcpy(sstr,g_argv[i]);
    brt(sstr);
    if (!strcmp(sstr, "-p")) {
      if (i <= g_argc - 2) {
    strcpy(printfile_str,g_argv[i + 1]);
	brt(printfile_str);
	goto _L18;
      }
    }
  }
_L18:





  /*   writeln('Compiled Rigal/SUN /(c)1992 v.',rigal_version,
                ', LU, Riga');
     writeln('');
     writeln(
     ' print-file-name may be s=screen, NUL=dummy, or any file');
     writeln(' parms    - user''s parameters');
     writeln(' Press ENTER to continue ');
     readln; */


  opens('@');

  init_dinform();
  opena();
  if (!strcmp(printfile_str, "s"))
    *printfile_str = '\0';
  if (!((*printfile_str == '\0') | rightfile(printfile_str))) {
    printf(" Wrong PRINT file name changed to standard output\n");
    *printfile_str = '\0';
  }
  max_printlevel = max_printconst;




  out_screen = (*printfile_str == '\0');
  out_open = !out_screen;
  if (!out_screen) {
    out = fopen(printfile_str,"w");
    if (out == NULL)
      _EscIO(FileNotFound);
  }


  debugrule = false;
  /* all the files are closed */
  for (iii = 0; iii < filenum; iii++)
    filetab[iii].isopen = false;
}  /* prolog */


Void epilog()
{
  long iii;
  longint dr, dw, dp;


  for (iii = 0; iii < filenum; iii++) {
    if (filetab[iii].isopen) {
      if (filetab[iii].screen)
	putchar('\n');
      else {
	putc('\n', files[iii]);
	if (files[iii] != NULL)
	  fclose(files[iii]);
	files[iii] = NULL;
      }
    }
  }
  if (out_open) {
    if (out != NULL)
      fclose(out);
    out = NULL;
  }
  vola(&dr, &dw, &dp);
  if (dr + dw + dp > 0)
    printf("A-Space:%12ld reads %12ld writes %12ld pages \n", dr, dw, dp);
  vols(&dr, &dw, &dp);
  if (dr + dw + dp > 0)
    printf("S-Space:%12ld reads %12ld writes %12ld pages \n", dr, dw, dp);
  closea();
  closes();




}  /* epilog */


Static Void wrg(i, s)
long i;
Char *s;
{
  if (filetab[i - 1].screen)
    fputs(s, stdout);
  else
    fputs(s, files[i - 1]);
}


Static Void wrgln(i)
long i;
{
  if (filetab[i - 1].screen)
    putchar('\n');
  else
    putc('\n', files[i - 1]);
}


/* Local variables for outxt: */
struct LOC_outxt {
  boolean blanks;

  union {
    struct {
      Char c00;
      bl80 a80_;
    } U1;
    string80 s0;
  } rec00;
  long i;   /* i - nomer fajla */
  longint rezlong;
  long len;   /* dlina atoma */
} ;



Local Void line(symlen, LINK)
long symlen;
struct LOC_outxt *LINK;
{
  /* kontroliruet zapolnenie stroki fajla */
  /* curlen - tekusaq dlina , symlen - nado wywesti ,*/
  /* strlen - specifikaciq fajla-dlina stroki */
  _REC_filetab *WITH;

  WITH = &filetab[LINK->i - 1];   /*with*/
  if (!(LINK->blanks && WITH->curlen + symlen > WITH->strlen))
  {  /* esli na |toj stroke ne pomeaetsq */
    WITH->curlen += symlen;
    return;
  }
  if (symlen > WITH->strlen + 1)   /* slikom dlinnaq stroka */
    er(17L);
  wrgln(LINK->i);
  /* perewod na nowu` stroku
                      */
  WITH->curlen = symlen;
}  /*line*/


Local Void printlist(la, i, LINK)
long la, i;
struct LOC_outxt *LINK;
{
  /* procedura dlq pe~ati spiska */
  /*la-adres, i-nomer fajla */
  mpd x;
  ptr_ lptr;
  boolean tatomflag;
  a a1;
  longint k;
  long j;
  double rref;
  long FORLIM;
  Char STR1[256];
  string80 STR2;


  /* this test is not actual
   if ((la mod 512) = 0) and (la > 0) and (la<65536) then
      begin
      line(20);
      wrg(i, '  <!<!!A*!*!!>!>  ');
      end
    else
     */
  /* pri la=0 - ni~ego ne pe~ataetsq */
  if (la == 0) {
    return;
  }  /* else mod<>512 */
  pointr(la, &x.sa);

  switch (x.sad->dtype) {

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

    case atom:
    case idatom:
    case tatom:
    case keyword:
      a1 = x.sad->name;
      break;

    case variable:
    case fvariable:
    case nvariable:
    case idvariable:
      a1 = x.svd->name;
      wrg(i, "$");
      break;

    case rulename:
      a1 = x.srd->name;
      wrg(i, "#");
      break;

    }/*case*/
    pointa(a1, LINK->rec00.U1.a80_, &LINK->len);   /* daet a80 i len */
    LINK->rec00.U1.c00 = (Char)LINK->len;
    if (tatomflag) {
      line(LINK->len + 2, LINK);
      wrg(i, "'");
      FORLIM = LINK->len;
      for (j = 0; j < FORLIM; j++) {
	if (LINK->rec00.U1.a80_[j] == '\'')
	  wrg(i, "''");
	else {
	  sprintf(STR1, "%c", LINK->rec00.U1.a80_[j]);
	  wrg(i, STR1);
	}
      }
      wrg(i, "'");
    } else {   /* if/else */
      line(LINK->len, LINK);

      FORLIM = LINK->len;
      for (j = 0; j < FORLIM; j++) {
	sprintf(STR1, "%c", LINK->rec00.U1.a80_[j]);
	wrg(i, STR1);
      }

    }
    if (LINK->blanks) {
      line(1L, LINK);
      wrg(i, " ");
    }
    break;

  case fatom:   /* added 17-feb-92 */
    line(12L, LINK);   /* standard length of written real */


    rref = take_fatom(x.sad->name);
    wrg(i, real_to_string(STR2, rref));
    if (LINK->blanks)
      wrg(i, " ");
    break;



  case number:  /* pe~atx ~isla */
    LINK->rezlong = x.snd->val;
    k = LINK->rezlong;
    if (k < 0)   /* changed from abs call*/
      k = -k;
    j = 0;
    do {
      k /= 10;
      j++;
    } while (k >= 1);
    line(j, LINK);

    wrg(i, long_to_str(STR2, LINK->rezlong));
    if (LINK->blanks) {
      line(1L, LINK);
      wrg(i, " ");
    }
    break;
    /*number*/

  case listmain:   /*listmain*/
    /* raspe~atka spiska */
    /* line(5);*/
    /* garantii koncow spiska */
    first(la, &lptr);
    while (lptr.nel != 0) {
      printlist(lptr.cel, i, LINK);
      next(&lptr);
    }  /*while*/
    break;

  case treemain:
    line(20L, LINK);
    wrg(i, " <!<!<*TREE*>!>!> ");
    break;




  default:
    line(20L, LINK);
    wrg(i, " <!<!<UNK***>!>!> ");   /* otherwise */
    break;
  }/* case */

  /*  if blanks then-- pereneseno wwerh 20.7.88
      wrg(i, ' '); */

}  /* printlist */


Void outxt(fname, arg, nl, blanks_)
long fname, arg;
boolean nl, blanks_;
{
  /* a-adr.imeni fajla*/
  /* s-adr.wyw.obxekta*/
  /* s now.stroki*/
  /* s probelami*/
  /*   =====================================   */
  /* obespe~iwaet wypolnenie operatorow wywoda */
  /*   =====================================   */
  struct LOC_outxt V;
  long openlen;   /* dlq pods~eta {iriny fajla */
  a rez;   /* rezulxtat expression */

  /* ========= osnownaq procedura ========== */


  V.blanks = blanks_;
  /* wywod << << << << */
  /*writeln('OUTXT dlq FNAME=', fname);**********/
  for (V.i = 1; V.i <= filenum; V.i++) {
    if (filetab[V.i - 1].name == fname && filetab[V.i - 1].isopen) {
      if (nl) {
	wrgln(V.i);
	filetab[V.i - 1].curlen = 0;
      }
      printlist(arg, V.i, &V);
      goto _L99;
    }  /* for/ if open */
  }

  er(14L);   /* fajl ne otkryt */
_L99: ;
}  /* outxt */


/* Local variables for outatm: */
struct LOC_outatm {
  boolean blanks;
  long i;
} ;

/* curlen - tekusaq dlina , symlen - nado wywesti ,*/
/* strlen - specifikaciq fajla-dlina stroki */

Local Void line_(symlen, LINK)
long symlen;
struct LOC_outatm *LINK;
{
  /* kontroliruet zapolnenie stroki fajla */
  /* curlen - tekusaq dlina , symlen - nado wywesti ,*/
  /* strlen - specifikaciq fajla-dlina stroki */
  _REC_filetab *WITH;

  WITH = &filetab[LINK->i - 1];   /*with*/
  if (!(LINK->blanks && WITH->curlen + symlen > WITH->strlen))
  {  /* esli na |toj stroke ne pomeaetsq */
    WITH->curlen += symlen;
    return;
  }
  if (symlen > WITH->strlen + 1)   /* slikom dlinnaq stroka */
    er(17L);
  wrgln(LINK->i);
  /* perewod na nowu` stroku
                      */
  WITH->curlen = symlen;
}  /*line*/


Void outatm(fname, arg_, nl, blanks_)
long fname;
Char *arg_;
boolean nl, blanks_;
{
  /* a-adr.imeni fajla*/
  /* wywodimyj atom*/
  /* s now.stroki*/
  /* s probelami*/
  /*   =====================================   */
  /* obespe~iwaet wypolnenie bystrogo wywoda ne~islowogo atoma */
  /*   =====================================   */
  struct LOC_outatm V;
  string80 arg;
  _REC_filetab *WITH;

  strcpy(arg, arg_);
  V.blanks = blanks_;
  for (V.i = 1; V.i <= filenum; V.i++) {
    if (filetab[V.i - 1].name == fname && filetab[V.i - 1].isopen) {
      WITH = &filetab[V.i - 1];   /*with*/
      if (nl) {
	wrgln(V.i);
	WITH->curlen = 0;
      }
      /* change 4-dec-92 */
      line_((long)strlen(arg), &V);
      wrg(V.i, arg);
      if (V.blanks) {
	line_(1L, &V);
	wrg(V.i, " ");
      }  /* change 4-dec-92 */
      goto _L99;
    }  /* for/ if open */
  }

  er(14L);   /* fajl ne otkryt */
_L99: ;
}  /* outatm */


/* Local variables for opn: */
struct LOC_opn {
  long fspec;

  bl80 a80_;
  long openlen;   /* dlq pods~eta {iriny fajla */
  filespecification namestr;
  mpd x;
  long len;   /* dlina atoma */
  a fsp;   /* a-adres specifikacii fajla */
} ;

Local boolean makefilespec(LINK)
struct LOC_opn *LINK;
{
  boolean Result;

  long j, k, k1, FORLIM1;


  Result = false;
  if ((LINK->fspec & 511) == 0 && LINK->fspec < 65536L && LINK->fspec >= 0) {
    er(11L);
    goto _L99;
  }
  pointr(LINK->fspec, &LINK->x.sa);
  if (((1L << ((long)LINK->x.sad->dtype)) & ((1L << ((long)atom)) |
	 (1L << ((long)idatom)) | (1L << ((long)tatom)))) == 0) {
    er(11L);
    goto _L99;
  }
  /* specifikaciq fajla - ne atom */
  LINK->fsp = LINK->x.sad->name;
  pointa(LINK->fsp, LINK->a80_, &LINK->len);
  /* daet a80 i len */
  if (LINK->len > 80) {
    er(12L);
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


Void opn(fname, fspec_)
long fname, fspec_;
{
  /* a-adres imeni fajla*/
  /* s-adr.*/
  /*   ======================   */
  /* otkrytie tekstowogo fajla  */
  /*   ======================   */
  struct LOC_opn V;
  long i;   /* i - nomer fajla */
  _REC_filetab *WITH;

  /* ========= osnownaq procedura ========== */


  V.fspec = fspec_;
  for (i = 0; i < filenum; i++) {
    if (filetab[i].name == fname && filetab[i].isopen)
    {  /* otkrytx fajl snowa */
      er(16L);
      /* nado zakrywatx fajl pered otkrytiem
               */
      goto _L99;
    }
  }
  for (i = 0; i < filenum; i++) {
    if (!filetab[i].isopen) {
      if (!makefilespec(&V))
	goto _L99;
      if (!strcmp(V.namestr, " "))
	filetab[i].screen = true;
      else {
	filetab[i].screen = false;
	if (!rightfile(V.namestr)) {
	  errstr(19L, V.namestr);
	  goto _L99;
	}

    files[i] = fopen(V.namestr, "w");
	if (files[i] == NULL)
	  _EscIO(FileNotFound);
      }

      WITH = &filetab[i];


      WITH->isopen = true;
      WITH->strlen = V.openlen;
      WITH->curlen = 0;
      WITH->name = fname;
      goto _L99;

    }
    /* i{etsq perwoe neotkrytoe gnezdo dlq fajla */

  }
  er(13L);   /* sli{kom mnogo otkrytyh fajlow */
_L99: ;


}  /* opn */


Void loasav(p, f, paz)
v *p;
long f, paz;
{
  /* 0-load,1 -save, 2-saven*/
  /* wyhod */

  FILE *specfile;   /* vax */
  filespecification fname;
  mpd x;
  a r;
  bl80 a80_;
  long i, len;

  specfile = NULL;
  if (f == null_) {
    er(11L);
    goto _L99;
  }
  pointr(f, &x.sa);
  if (((1L << ((long)x.sad->dtype)) &
       (((1L << ((long)keyword + 1)) - (1L << ((long)atom))) |
	(1L << ((long)tatom)))) == 0) {
    er(11L);
    goto _L99;
  }
  r = x.sad->name;
  pointa(r, a80_, &len);
  *fname = '\0';
  for (i = 0; i < len; i++)
    sprintf(fname + strlen(fname), "%c", a80_[i]);
  if (paz == 0) {
    if (existfile(fname))
      loads(fname, &r);
    else {
      r = 0;
      errstr(18L, fname);
    }
    p->sa = r;
  } else {
    r = p->sa;
    if (r != null_) {
      if (rightfile(fname) && *fname != '\0') {
	if (paz == 1)
	  saves(fname, &r);
	else
	  savesn(fname, &r);
      } else
	errstr(15L, fname);
    }
  }
_L99:
  if (specfile != NULL)
    fclose(specfile);
}  /* loasav */


Void explod(kk, rez)
long kk, *rez;
{


  /*=====================================*/
  /* sozdaet spisok odnobukwennyh atomow */
  /*=====================================*/
  /* wyhod */

  a s, k;
  mpd x;
  longint l;
  /* changed from integer here and in like-wise
                 places in c3.pas 17-nov-90 */
  string80 str_val;   /* maximum real */
  Char STR1[256];
  long FORLIM;

  *rez = null_;
  if (kk == null_)
    goto _L99;
  pointr(kk, &x.sa);


  switch (x.sad->dtype) {

  case fatom:   /* added 17-feb-92 */
    real_to_string(str_val, take_fatom(x.sad->name));
    break;

  case number:
    long_to_str(str_val, x.snd->val);
    break;

  case 5:
  case 6:
  case 7:
  case tatom:
    aa_str(str_val, x.sad->name);
    break;


  default:
    goto _L99;
    break;
  }/* case */
  /* w m sformirowan massiw simwolow */
  s = null_;   /* rez.spisok */
  FORLIM = strlen(str_val);
  for (l = 0; l < FORLIM; l++) {
    sprintf(STR1, "%c", str_val[l]);
    k = str_to_textatom(STR1);
    lconc(&s, k);
  }  /* for */
  *rez = s;
_L99: ;
}  /* explode */


/* Local variables for implod: */
struct LOC_implod {
  bl80 m, m1;
  mpd x;
  a k;
  long p1;   /* posledn.zanqtyj |l-t w m1 */
  string80 str_val;   /* maximum real */
} ;


Local Void pass(pl, LINK)
ptr_ *pl;
struct LOC_implod *LINK;
{
  ptr_ pl1;
  long t, l;

  while (pl->nel != 0) {
    LINK->k = pl->cel;
    if (LINK->k != null_) {
      pointr(LINK->k, &LINK->x.sa);
      if (LINK->x.smld->dtype == listmain) {
	first(LINK->k, &pl1);   /*, st */
	pass(&pl1, LINK);
      } else {  /* not list */
	if (((1L << ((long)LINK->x.sad->dtype)) &
	     ((1L << ((long)fatom + 1)) - (1L << ((long)atom)))) == 0)
	  goto _L99;
	if (LINK->x.sad->dtype == fatom) {   /* added 17-feb-92 */
	  real_to_string(LINK->str_val, take_fatom(LINK->x.sad->name));

	  l = strlen(LINK->str_val);
	  if (LINK->p1 + l > 80) {
	    er(25L);
	    goto _L99;
	  }
	  for (t = 0; t < l; t++)
	    LINK->m1[LINK->p1 + t] = LINK->str_val[t];
	  LINK->p1 += l;
	} else {
	  if (((1L << ((long)LINK->x.sad->dtype)) &
	       (((1L << ((long)keyword + 1)) - (1L << ((long)atom))) |
		(1L << ((long)tatom)))) != 0) {
	    /* wzqtx atom iz a-prostranstwa w m */
	    LINK->k = LINK->x.sad->name;
	    pointa(LINK->k, LINK->m, &l);   /* [1] ibm/pc */
	    if (LINK->p1 + l > 80) {
	      er(25L);
	      goto _L99;
	    }
	    for (t = 0; t < l; t++)
	      LINK->m1[LINK->p1 + t] = LINK->m[t];
	    LINK->p1 += l;
	  } else {
	    /* number */
	    /*==============================*/
	    /* perewesti ~islo w simwoly i  */
	    /* pomestitx w m [1..max_digit]         */
	    /*==============================*/
	    LINK->k = LINK->x.snd->val;
	    if (LINK->k < 0)   /*changed from abs call */
	      LINK->k = -LINK->k;
	    for (t = max_digit - 1; t >= 0; t--) {
	      l = LINK->k % 10;
/* p2c: c3.z, line 1233:
 * Note: Using % for possibly-negative arguments [317] */
	      LINK->k /= 10;
	      LINK->m[t] = (Char)(l + '0');
	    }
	    t = 1;
	    while (t < max_digit && LINK->m[t - 1] == '0')
	      t++;
	    if (LINK->x.snd->val < 0) {
	      if (LINK->p1 == 80) {
		er(25L);
		goto _L99;
	      }
	      LINK->p1++;
	      LINK->m1[LINK->p1 - 1] = '-';
	    }
	    if (LINK->p1 + max_digit - t > 79) {
	      er(25L);
	      goto _L99;
	    }
	    for (l = t - 1; l < max_digit; l++) {
	      LINK->p1++;
	      LINK->m1[LINK->p1 - 1] = LINK->m[l];
	    }
	  }  /* number */
	}
      }  /* not list */
    }  /* k<> null */
    next(pl);
  }  /* while */
_L99: ;




}  /* pass */





Void implod(pl, rez)
ptr_ *pl;
long *rez;
{
  /* 1-j argument */
  /*======================================*/
  /* skleiwanie  atomow a1 a2 ... an  do  */
  /* perwogo, otli~nogo ot atoma ili null */
  /*======================================*/
  struct LOC_implod V;
  longint l;   /* rab. */
  boolean id;
  long FORLIM;
  atomdescriptor *WITH;


  V.p1 = 0;
  pass(pl, &V);
  if (V.p1 == 0) {
    *rez = null_;
    return;
  }
  /* zapisatx nowyj atom w a-prostr. */
  putatm(V.m1, V.p1, &V.k);
  id = is_rig_letter(V.m1[0]);
  FORLIM = V.p1;
  for (l = 0; l < FORLIM; l++)
    id &= is_rig_symbol(V.m1[l]);
  l = 1;
  gets1(rez, &V.x.sa);
  WITH = V.x.sad;
  if (id)
    WITH->dtype = idatom;
  else
    WITH->dtype = atom;
  WITH->name = V.k;
}  /* implode */


Void bltin1(rez, success, pl, n)
long *rez;
boolean *success;
ptr_ *pl;
long n;
{
  /*=======================*/
  /* wyzow bltin w {ablone */
  /*=======================*/
  v rr;

  if (pl->nel == 0) {
    *success = false;
    *rez = null_;
    return;
  }
  bltin(&rr, success, pl->cel, n);
  if (!*success) {
    *rez = null_;
    return;
  }
  if (n == 15)
    mknumb(rr.nu, rez);
  else
    *rez = rr.sa;
  if (pl->ptrtype != ptrtree)   /* 26.8.88 */
    next(pl);
}  /* bltin1*/


Void clsfil(fname)
long fname;
{  /* close */
  /* a-adr.*/
  /*   ======================== */
  /* zakrytie tekstowogo fajla  */
  /*   ======================== */
  long i;   /* i - nomer fajla */


  for (i = 0; i < filenum; i++) {
    if (filetab[i].name == fname && filetab[i].isopen) {
      wrgln(i + 1);
      if (!filetab[i].screen) {
	if (files[i] != NULL)
	  fclose(files[i]);
	files[i] = NULL;
      }
      filetab[i].isopen = false;
    }
  }
_L99: ;
}  /* clsfil */















/* End. */

