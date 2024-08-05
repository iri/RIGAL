/* Version 5-07-93 */
#include "globrig.h"
#include "define.h"
#include "defpage.h"



#ifdef MIPSEL
/* For DEC variant, ULTRIX computers,
/* Little endian variant of MIPS architecture:
   changed ... */
#define dos             1
#endif 

#ifdef i386
/* INTEL architecture:
   changed ... */
#define dos             1
#endif 

#ifdef LE
/* All other little-endian architectures */
#define dos             1
#endif 

  /* #define dos             1 */
 /* defines order of bytes */
 /* set to yes if lower byte is first in the word;
  * set to no if lower byte is last in the word */

/* memory manager error messages */
#define m_cur_rewrite   "1001 - Current disk rewrite error"
#define m_vir_rewrite   "1002 - Virtual disk rewrite error"
#define m_cur_read      "1003 - Current disk read error"
#define m_vir_read      "1004 - Virtual disk read error"
#define m_cur_write     "1005 - Current disk write error"
#define m_vir_write     "1006 - Virtual disk write error"
#define m_over          "1007 - Structured object memory overflow"
#define m_aover         "1008 - Atomic memory overflow"
#define m_load          "1009 - Disk error during LOAD"
#define m_reset         "1010 - Disk reset error during LOAD"
#define m_save          "1011 - Disk error during SAVE"
#define m_rewrite       "1012 - Disk rewrite error during SAVE"
#define m_uns           "1013 - Unsufficient core memory"
#define m_wrong         "1014 - Internal error - wrong Spointer"


static Void mess(messstr)
Char *messstr;
{
  printf("\n--------------------------\n");
  printf("Paging manager : %s\n", messstr);
  printf("------ PRESS ENTER ------ \n");
  scanf("%*[^\n]");
  getchar();

  exit(0);

}


#define lblksize        128
#define cblksize        512
#define asize           32767   /* increased size of a_page, not limited */
/*2048;*/
#define ssize           16384   /* must be 2^^shiftpage */
/*11;*/
#define shiftpage       14

#define andoffs         (ssize - 1)

#define msize           12
#define fssize          (ssize + lblksize)
#define spazime         255   /* tiek lietots izteiksme chr(...).   */
#define apazime         254   /* ja ir problemas,var lietot 127 126 */
#define one             256
#define setflag         1
#define clearflag       126

#define minpage         0

#define maxpage         32767   /* maxpage */
         /* set to maximum value = 32767  */
         /* Size of S-Space is maxpage*ssize*4 bytes =32 K * 16K * 4=2048 MB */


typedef unsigned char pagenumber;


typedef Char x512[512];

typedef struct a_block {
  word infgar;
  Char inform[asize];
} a_block;


typedef a_block a_buf[32];


typedef struct s_buf {
  a inform[fssize];
  struct s_buf *nextbuf;   /* not used */
  pagenumber pagenr;   /* not used */
  boolean modif;   /* not used here */
  word infgar;   /* not used */
} s_buf;

/* Order of bytes is important */
#ifdef dos
typedef struct {
    Char pazime;
    Char page;       /* used for number of A-page 0..31 */
    word offset; } pazofpa;
typedef
  struct {    word  offsetpart , segmentpart;  } segoff;

typedef struct {
    word page,offset;
  } newstru;

#else
typedef struct {
    word offset;
    Char page;       /* used for number of A-page 0..31 */
    Char pazime; } pazofpa;
typedef struct {
    word segmentpart, offsetpart;
  } segoff;
typedef struct {
    word offset, page;
  } newstru;
#endif

typedef union sa_pointer {
  a pointa;
  Char immed[4];
  pazofpa struct_;
  segoff wstruct;
  longint exnumb;
  newstru newstruct;
} sa_pointer;

/* type descriptortype =
       (dummy   , listmain  , listfragm  , treemain  , treefragm ,
        atomm   , idatom    , keyword    , number    , tatom     ,
        fatom   , variable  , idvariable , nvariable , fvariable ,
        rulename, objekts   , coord      , spec      );  *********/


typedef union object_type {
  struct {
    char dtype;
    char flags;
  } U1;
  sa_pointer pointarray[10];
  longint longintarray[10];
} object_type;


typedef union absadr {
  a adrese;
  object_type *objpoint;
  longint *lintpoint;
} absadr;


typedef struct bl80rec {
  bl80 c;
} bl80rec;

typedef union charmas {
  Char *cptr1;
  bl80rec *cptrec80;
  Char *cptr80;
} charmas;


typedef struct _REC_dinformtype {
  word length, apointbit, spointbit;
} _REC_dinformtype;

typedef _REC_dinformtype dinformtype[27];


/*========================================*/
word rezwrite;
dinformtype dinform;


Void init_dinform()
{
  char dt;

  long SET[4];
  long SET1[4];
  long SET2[4];
  long SET3[5], SET4[5];
  long SET5[5], SET6[5];
  long SET7[9];

  _REC_dinformtype *WITH;

#ifdef bad_sets
  P_addsetr(P_expset(digit, 0L), '0', '9');
  P_addset(P_expset(SET5, 0L), '~');
  P_addset(SET5, '|');
  P_addset(SET5, '`');
  P_addset(SET5, '{');
  P_setunion(letter, P_setunion(SET6,
      P_setunion(SET4, P_setunion(SET2, P_addset(P_expset(SET, 0L), '_'),
				  P_addsetr(P_expset(SET1, 0L), 'A', 'Z')),
		 P_addsetr(P_expset(SET3, 0L), 'a', 'z')),
      P_addset(SET5, '}')), P_addsetr(P_expset(SET7, 0L), 128, 255));
/* p2c: defsun3.z, line 805: Note:
 * Line breaker spent 0.7+0.19 seconds, 5000 tries on line 1049 [251] */
  /* all these additional characters are added only for compatibility
     with old version with russian letters */
  P_setunion(symbols, letter, digit);
#endif


  for (dt = dummy; (long)dt <= (long)spec; dt = (char)((long)dt + 1)) {
    WITH = &dinform[(long)dt];
    WITH->length = 2;
    WITH->apointbit = 0;
    WITH->spointbit = 0;
  }
  dinform[(long)dummy].length = 1;
  dinform[(long)rulename].length = 4;
  dinform[(long)object_d].length = 4;
  for (dt = listmain; (long)dt <= (long)treefragm; dt = (char)((long)dt + 1))
    dinform[(long)dt].length = 10;
  dinform[(long)listmain].spointbit = 0x3fc;
  dinform[(long)listfragm].spointbit = 0x3fe;
  dinform[(long)treemain].spointbit = 0x354;
  dinform[(long)treefragm].spointbit = 0x354;
  dinform[(long)treemain].apointbit = 0xa8;
  dinform[(long)treefragm].apointbit = 0xaa;
  for (dt = atom; (long)dt <= (long)rulename; dt = (char)((long)dt + 1))
    dinform[(long)dt].apointbit = 2;
  dinform[(long)number].apointbit = 0;
}




boolean sopen_space, dopen;
long dpagenum;
a_block *a_bufp;
s_buf *prevbuf, *holdbuf;
s_buf *addrmas[maxpage - minpage + 1];
sa_pointer ffby;



/************************* statistika ******************/
longint adiscread, adiscwrite, adiscpage, sdiscread, sdiscwrite, sdiscpage;


/*******************************************************/
Static Void nextsp(sptr, length)
sa_pointer *sptr;
word length;
{
  newstru *WITH; /* pazofpa -> newstru, 5-jul-93 */
  WITH = &sptr->newstruct;
/*printf(" Nextsp: page= %d offs=%d \n",WITH->page,WITH->offset);*/
  WITH->offset += length;
  if (WITH->offset < fssize - msize)
    return;
  if (WITH->page == maxpage)
    mess(m_over);
  WITH->page++;
  WITH->offset = 0;
}


/*******************************************************/
/**** pointx ieksejam vajadzibam - loti lidzigs vecajam pointr(s) ****/
Static long pointx(e1)
long e1;
{
  sa_pointer mm;

  mm.pointa = e1 ;
  prevbuf = addrmas[mm.newstruct.page - minpage];
  if (prevbuf != NULL)
    return ((long)(&prevbuf->inform[mm.newstruct.offset]));

  prevbuf = (s_buf *)Malloc(sizeof(s_buf));
 /*printf(" Next buffer page is from %p \n",prevbuf);*/

  if (prevbuf == NULL)
    mess(m_uns);



  addrmas[mm.newstruct.page - minpage] = prevbuf;
  return ((long)(&prevbuf->inform[mm.newstruct.offset]));
}


/******************************************** opena *****/
Void opena()
{
  long i;
  a_block *WITH;

  adiscread = 0;
  adiscwrite = 0;
  adiscpage = 0;
  a_bufp = (a_block *)Malloc(sizeof(a_buf));
  if (a_bufp == NULL)
    mess(m_uns);
  for (i = 0; i <= 31; i++) {
    WITH = &a_bufp[i];
    WITH->infgar = 0;
  }
}  /* end of opena */


/* Local variables for putatm: */
struct LOC_putatm {
  long na;
  charmas cptr;
  sa_pointer atbilde;
  long intpage;
} ;

Local Void pagecheck(LINK)
struct LOC_putatm *LINK;
{
  long j, k, l, garums;
  a_block *WITH;
  bl80rec *WITH1;
  long FORLIM;

  /*if intpage>7 then write('[A=',intpage,']');*/
  if (LINK->intpage > 31)
    mess(m_aover);
  WITH = &a_bufp[LINK->intpage];   /*with*/
  WITH1 = LINK->cptr.cptrec80;
  j = 1;
  while (j < WITH->infgar) {
    garums = WITH->inform[j - 1];   /* atoma garums < 128 */
    if (garums == LINK->na) {
      l = j + 1;
      for (k = 0; k < garums; k++) {
	if (WITH1->c[k] != WITH->inform[l - 1])
	  goto _Lstep;
	l++;
      }
      goto _Lfind;
    }
_Lstep:
    j += garums + 1;
  }  /*while*/

  k = asize - WITH->infgar;

  if (LINK->na >= k)
    goto _L99;
  WITH->inform[j - 1] = (Char)LINK->na;
  l = j;
  FORLIM = LINK->na;
  for (k = 0; k < FORLIM; k++) {
    l++;
    WITH->inform[l - 1] = WITH1->c[k];
  }
  WITH->infgar = l;
_Lfind:
  LINK->atbilde.struct_.pazime = (Char)apazime;
  LINK->atbilde.struct_.offset = j;
  LINK->atbilde.struct_.page = (Char)LINK->intpage;





_L99: ;
}  /* end of pagecheck */


/*********************************** putatm(ad,na,e) *****/
Void putatm(ad, na_, e)
Char *ad;
long na_, *e;
{
  struct LOC_putatm V;
  long i;
  bl80rec *WITH;
  long FORLIM;

  /***  start  of  putatm (ad , na , e)  ***/

  V.na = na_;
  V.atbilde.pointa = 0;
  V.cptr.cptr1 = ad;
  WITH = V.cptr.cptrec80;
  if (V.na < 5) {
    FORLIM = V.na;
    for (i = 0; i < FORLIM; i++)
      V.atbilde.immed[i] = WITH->c[i];
  } else {
    V.intpage = WITH->c[0] & 7;

    if (V.na > 9)
      V.intpage += 8;
    pagecheck(&V);
    V.intpage = 15;
    while (V.atbilde.pointa == 0) {
      V.intpage++;
      pagecheck(&V);
    }
  }
  *e = V.atbilde.pointa;


}  /* end of putatm */


/************************************* pointa(e,ad,na) *****/
Void pointa(e, ad, na)
long e;
Char *ad;
long *na;
{
  long i, j;
  sa_pointer atbilde;
  long FORLIM;
  a_block *WITH;

  atbilde.pointa = e;
  if (atbilde.struct_.pazime != (Char)apazime) {
    *na = 0;
    for (i = 0; i <= 3; i++) {
      if (atbilde.immed[i] == '\0')
	goto _Lalles;
      ad[i] = atbilde.immed[i];
      (*na)++;
    }
  } else {
    WITH = &a_bufp[atbilde.struct_.page];
    *na = WITH->inform[atbilde.struct_.offset - 1];
    j = atbilde.struct_.offset + 1;
    FORLIM = *na;
    for (i = 0; i < FORLIM; i++) {
      ad[i] = WITH->inform[j - 1];
      j++;
    }
  }
_Lalles: ;
}  /* end of pointa */


/******************************************* closea *****/
Void closea()
{
}  /* end of savea */


Void savea()
{
  closea();
}


/******************************************** closes *****/
Void closes()
{
}


/******************************************** vola *****/
Void vola(dr, dw, dp)
long *dr, *dw, *dp;
{
  *dr = adiscread;
  *dw = adiscwrite;
  *dp = adiscpage;
}  /* end of vola */


/** * * * * * *  s - m a n a g e r * * * * * * * * * * **/
/******************************************** opens *****/
Void opens(d_drive)
Char d_drive;
{
  s_buf *ptr;
  long k;


  ptr = (s_buf *)Malloc(sizeof(s_buf));
  /*printf(" First page pointer is %p \n",ptr);*/
  if (ptr == NULL)
    mess(m_uns);

  addrmas[0] = ptr;
  for (k = minpage + 1; k <= maxpage; k++)
    addrmas[k - minpage] = NULL;
  /* ffby.newstruct.pazime = (Char)spazime; */  /* removed 1-2-93 */
  ffby.newstruct.offset = 0;
  ffby.newstruct.page = minpage;
  prevbuf = ptr;
  holdbuf = NULL;
  sopen_space = false;
  dopen = false;
  sdiscread = 0;
  sdiscwrite = 0;
  sdiscpage = 0;
  /*???? sun "new" allocatio error handle ??*/
}  /* end of opens */


/****************************************** pointr (e1,e2) *****/
Void pointr(e1, e2)
long e1, *e2;
{
  sa_pointer sap;
/*printf("  pointr %p \n",e1);*/
  sap = *(sa_pointer *)(&e1);
  if (sap.wstruct.segmentpart == 0)
    mess(m_wrong);
  *e2 = e1;
}


/****************************************** points (e1,e2) *****/
Void points(e1, e2)
long e1, *e2;
{
  sa_pointer sap;

  sap = *(sa_pointer *)(&e1);
  if (sap.wstruct.segmentpart == 0)
    mess(m_wrong);
  *e2 = e1;
}


/***************************************** gets1 (e1,e2) *****/
Void gets1(e1, e2)
long *e1, *e2;
{
  absadr absa;
  object_type *WITH;
/*printf (" gests1 PAGE=%d bits=%p \n",ffby.newstruct.page,ffby.pointa);*/
  *e1 = pointx(ffby.pointa);
  nextsp(&ffby, 2);
  *e2 = *e1;
  absa = *(absadr *)e2;
  WITH = absa.objpoint;
  WITH->longintarray[0] = 0;
  WITH->longintarray[1] = 0;
/*printf("  gets1 %p \n",*e1);*/

}


/***************************************** gets2 (e1,e2) *****/
Void gets2(e1, e2)
long *e1, *e2;
{
  absadr absa;
  object_type *WITH;

  *e1 = pointx(ffby.pointa);
  nextsp(&ffby, 4);
  *e2 = *e1;
  absa = *(absadr *)e2;
  WITH = absa.objpoint;
  WITH->longintarray[0] = 0;
  WITH->longintarray[1] = 0;
  WITH->longintarray[2] = 0;
  WITH->longintarray[3] = 0;
}


/***************************************** gets5 (e1,e2) *****/
Void gets5(e1, e2)
long *e1, *e2;
{
  long i;
  absadr absa;
  object_type *WITH;

  *e1 = pointx(ffby.pointa);
  nextsp(&ffby, 10);
  *e2 = *e1;
  absa = *(absadr *)e2;
  WITH = absa.objpoint;
  for (i = 0; i <= 9; i++)
    WITH->longintarray[i] = 0;
}


/*************************************** loads (f,e) *****/
Void loads(f, e)
Char *f;
long *e;
{
  FILE *infile;
  sa_pointer bulta1, bulta2, rab1;
  absadr p1, p2, p3;
  long m, kp, la;
  union {
    longint long_[256];
    Char chr[1024];
    struct {
      x512 b1, b2;
    } U3;
  } buffer;
  long i, j, k, garums, biti;
  longint rab2;
  Char STR1[34];
  _REC_dinformtype *WITH;
  object_type *WITH1;
  sa_pointer *WITH2;

  /****             seit  sakas  loads ( f , e )   ****/
  infile = NULL;
  if (ffby.newstruct.offset >= ssize) {
    ffby.newstruct.page++;
    ffby.newstruct.offset = 0;
  }

    infile = fopen(f,"rb");
  if (infile == NULL)
    _EscIO(FileNotFound);

  /****  ievadam s-kodu un  korigejam s-pointerus  ****/
  if (feof(infile)) {
    sprintf(STR1, "%s(2)", m_load);
    mess(STR1);
  }
  fread(buffer.U3.b1, sizeof(x512), 1, infile);
  /******** read 1 **************/
  if (feof(infile)) {
    sprintf(STR1, "%s(1)", m_load);
    mess(STR1);
  }
  fread(buffer.U3.b2, sizeof(x512), 1, infile);
  /******** read 1 **************/
  bulta2.pointa = ffby.pointa;
  p2.adrese = pointx(bulta2.pointa);
  holdbuf = prevbuf;   /*izmantos holdbuf*/
  *e = p2.adrese;   /** result of load **/
  kp = buffer.long_[0];
  i = 2;
  for (m = 1; m <= kp; m++) {   /* for each object in infile do */
    p1.lintpoint = &buffer.long_[i - 1];
    WITH = &dinform[(long)p1.objpoint->U1.dtype];
    garums = WITH->length;
    biti = WITH->spointbit;
    for (k = 1; k <= garums; k++) {   /* for each longword in object */
      rab1.pointa = buffer.long_[i - 1];

      if ((biti & 1) == 1 && rab1.struct_.pazime == (Char)spazime)
      {  /* transform offset to s-addr */
	rab2 = rab1.pointa / 256 + ffby.newstruct.offset;
	rab1.newstruct.offset = rab2 & andoffs;
	rab1.newstruct.page = rab2 / ssize + ffby.newstruct.page;

	rab1.pointa = pointx(rab1.pointa);
      }


      holdbuf->inform[bulta2.newstruct.offset] = rab1.pointa;
      bulta2.newstruct.offset++;

      i++;
      biti /= 2;

    }
    if (i > lblksize) {   /* if end of input block */
      i -= lblksize;
      for (k = i - 1; k < lblksize; k++)
	buffer.long_[k] = buffer.long_[k + lblksize];
      if (feof(infile)) {
	sprintf(STR1, "%s(3)", m_load);
	mess(STR1);
      }
      fread(buffer.U3.b2, sizeof(x512), 1, infile);
      /******** read 1 **************/
    }
    if (bulta2.newstruct.offset >= ssize) {   /* if end of s-page */
      bulta2.newstruct.offset -= ssize;
      bulta2.newstruct.page++;
      p2.adrese = pointx(bulta2.pointa);
      holdbuf = prevbuf;   /* izmantos holdbuf */
      for (k = 0; k <= bulta2.newstruct.offset; k++)
	holdbuf->inform[k] = 0;
    }
  }
  /*** s-kods ir ievadits , tagad ievadisim a-kodu    ***/
  /*** bulta2 rada uz vina beigam tas ir jaunais ffby ***/
  bulta1.pointa = bulta2.pointa;
  la = buffer.long_[lblksize];
  i = cblksize + 5;
  for (m = 1; m <= la; m++) {   /* for each atom in file */
    j = 17;
    if (i <= cblksize * 2) {
      garums = buffer.chr[i - 1];   /* >>>>>>>>> chr(?) >>> */
      j = i + garums - cblksize * 2;
    }
    if (j > 0) {
      i -= cblksize;
      for (j = i - 1; j < cblksize; j++)
	buffer.chr[j] = buffer.chr[j + cblksize];
      if (feof(infile)) {
	sprintf(STR1, "%s(4)", m_load);
	mess(STR1);
      }
      fread(buffer.U3.b2, sizeof(x512), 1, infile);
      /******** read 1 **************/
    }
    garums = buffer.chr[i - 1];   /* >>>>>>>>>>> chr (?) >> */
    i++;
    putatm(&buffer.chr[i - 1], garums,
	   &holdbuf->inform[bulta1.newstruct.offset]);
    i += garums;
    bulta1.newstruct.offset++;
    if (bulta1.newstruct.offset >= fssize) {
      bulta1.newstruct.offset = 0;
      bulta1.newstruct.page++;
      p1.adrese = pointx(bulta1.pointa);
      holdbuf = prevbuf;   /*izmantos holdbuf*/
    }
  }
  if (infile != NULL)
    fclose(infile);
  infile = NULL;
  /*** a-kods ir ievadits , tagad korigejam a-pointerus ***/
  while (ffby.pointa != bulta2.pointa) {
    p1.adrese = pointx(ffby.pointa);   /* for each loaded object */
    WITH1 = p1.objpoint;   /* nextsp (ffby , garums); */
    WITH = &dinform[(long)WITH1->U1.dtype];
    biti = WITH->apointbit;
    garums = WITH->length;
    i = 1;
    while (biti != 0) {
      if ((biti & 1) == 1) {
	WITH2 = &WITH1->pointarray[i - 1];
	if (WITH2->struct_.pazime == (Char)apazime) {
	  bulta1.pointa = bulta2.pointa;
	  k = bulta1.newstruct.offset + WITH2->exnumb / 256;


	  while (k >= fssize) {
	    k -= fssize;
	    bulta1.newstruct.page++;
	  }
	  bulta1.newstruct.offset = k;
	  p3.adrese = pointx(bulta1.pointa);
	  WITH2->exnumb = *p3.lintpoint;
	}
      }


      i++;
      biti /= 2;

    }

    ffby.newstruct.offset += garums;
    if (ffby.newstruct.offset >= ssize) {
      ffby.newstruct.page++;
      ffby.newstruct.offset -= ssize;
    }
  }
  if (infile != NULL)
    fclose(infile);
}  /* end of loads */


/* Local variables for saves: */
struct LOC_saves {
  FILE *outfile;
  longint kp;
  sa_pointer bulta2;
  absadr p2, p3;
  union {
    longint long_[256];
    Char chr[1024];
    struct {
      x512 b1, b2;
    } U3;
  } buffer;
} ;

Local Void move_(LINK)
struct LOC_saves *LINK;
{
  long i, garums;
  object_type *WITH;

  /*si procedura parsuta treso (points jau ir) uz otro*/
  WITH = LINK->p3.objpoint;
  garums = dinform[(long)WITH->U1.dtype].length;
  LINK->p2.adrese = pointx(LINK->bulta2.pointa);
  for (i = 0; i < garums; i++)
    LINK->p2.objpoint->longintarray[i] = WITH->longintarray[i];
  /* save two words for restore */
  LINK->p2.objpoint->pointarray[garums].pointa = LINK->p3.adrese;
  LINK->p2.objpoint->longintarray[garums + 1] = WITH->longintarray[1];

  WITH->U1.flags |= setflag;

  WITH->longintarray[1] = LINK->kp;
  LINK->kp += one * garums;
  nextsp(&LINK->bulta2, (int)(garums + 2));
}

Local Void writeblock(LINK)
struct LOC_saves *LINK;
{
  fwrite(LINK->buffer.U3.b1, sizeof(x512), 1, LINK->outfile);
  /*** write   1 ***/
}


/*************************************** saves (f,e) *****/
Void saves(f, e)
Char *f;
long *e;
{
  struct LOC_saves V;
  long i, j, k;
  longint l, m, la;
  sa_pointer bulta1, bulta3, rab1, rab2;
  absadr p1;
  long biti, garums;
  charmas cptr;
  object_type *WITH;
  _REC_dinformtype *WITH1;
  sa_pointer *WITH2;

  /***  seit  ir  saves  sakums  saves ( f , e ) ***/
  V.outfile = NULL;
  bulta1.pointa = ffby.pointa;
  V.bulta2.pointa = ffby.pointa;
  V.kp = spazime;
  m = 0;
  pointr(*e, &V.p3.adrese);
  move_(&V);
  /*** formesanas cikls, kamer pirma bulta panak otro ***/
  while (bulta1.pointa != V.bulta2.pointa) {
    p1.adrese = pointx(bulta1.pointa);
    WITH = p1.objpoint;
    WITH1 = &dinform[(long)WITH->U1.dtype];
    garums = WITH1->length + 2;
    biti = WITH1->spointbit;
    i = 1;
    while (biti != 0) {
      if ((biti & 1) == 1) {
	WITH2 = &WITH->pointarray[i - 1];
	bulta3.pointa = WITH2->pointa;
	if (bulta3.wstruct.segmentpart != 0) {
	  V.p3.adrese = bulta3.pointa;

	  if ((V.p3.objpoint->U1.flags & setflag) == 1)
	    WITH2->exnumb = V.p3.objpoint->longintarray[1];
	  else {
	    WITH2->exnumb = V.kp;
	    move_(&V);
	  }

	}
      }


      i++;
      biti /= 2;

    }

    nextsp(&bulta1, (int)garums);
    m++;
  }
  /*** objekts ir uzbuvets un bulta2 rada uz vina beigam ***/
  /*** tagad atjaunojam esoso objektu , ko sabojaja move ***/
  /*** izstaigajam  jauno  objektu  un  nomainam  akodus ***/
  bulta1.pointa = ffby.pointa;
  bulta3.pointa = V.bulta2.pointa;
  la = 0;
  while (bulta1.pointa != V.bulta2.pointa) {
    p1.adrese = pointx(bulta1.pointa);
    WITH = p1.objpoint;
    WITH1 = &dinform[(long)WITH->U1.dtype];
    garums = WITH1->length + 2;
    biti = WITH1->apointbit;
    i = 1;
    while (biti != 0) {
      if ((biti & 1) == 1) {
	WITH2 = &WITH->pointarray[i - 1];
	rab1.pointa = WITH2->pointa;
	if (rab1.struct_.pazime == (Char)apazime) {
	  rab2.pointa = V.bulta2.pointa;
	  V.p2.adrese = pointx(rab2.pointa);   /*izmanto prevbuf*/
	  k = rab2.newstruct.offset;
	  l = apazime;
	  for (j = 1; j <= la; j++) {   /* tada vel nav */
	    if (prevbuf->inform[k] == rab1.pointa)   /* tads jau ir */
	      goto _Lara;
	    k++;
	    if (k >= fssize) {
	      rab2.newstruct.page++;
	      V.p2.adrese = pointx(rab2.pointa);   /* prevbuf! */
	      k = 0;
	    }
	    l += one;
	  }
	  la++;
	  prevbuf->inform[k] = rab1.pointa;
_Lara:
	  WITH2->exnumb = l;
	}
      }


      i++;
      biti /= 2;

    }

    V.p2.adrese = WITH->pointarray[garums - 2].pointa;

    V.p2.objpoint->U1.flags &= clearflag;

    V.p2.objpoint->longintarray[1] = WITH->longintarray[garums - 1];
    nextsp(&bulta1, (int)garums);
  }
  /*** seit visi pointeri ir sataisiti un javada lauka ***/
  bulta1.pointa = ffby.pointa;

    V.outfile = fopen(f, "wb");
  if (V.outfile == NULL)
    _EscIO(FileNotFound);

  V.buffer.long_[0] = m;
  i = 2;

  /*writeln('MMMMMM M=',m);
writeln;*/
  while (bulta1.pointa != V.bulta2.pointa) {
    p1.adrese = pointx(bulta1.pointa);
    WITH = p1.objpoint;
    garums = dinform[(long)WITH->U1.dtype].length;
    for (k = 0; k < garums; k++) {
      V.buffer.long_[i - 1] = WITH->longintarray[k];
      i++;
    }
    nextsp(&bulta1, (int)(garums + 2));
    if (i > lblksize) {
      writeblock(&V);
      i -= lblksize;
      for (k = 0; k < i; k++)
	V.buffer.long_[k] = V.buffer.long_[k + lblksize];
    }
  }
  writeblock(&V);
  /*** talak izvadam klat a_telpu ***/
  V.buffer.long_[0] = la;
  i = 5;
  V.p2.adrese = pointx(V.bulta2.pointa);   /*izmanto prevbuf*/
  k = V.bulta2.newstruct.offset;
  for (j = 1; j <= la; j++) {
    cptr.cptr1 = &V.buffer.chr[i];
    pointa(prevbuf->inform[k], cptr.cptr80, &garums);
    V.buffer.chr[i - 1] = (Char)garums;
    i += garums + 1;
    if (i > cblksize) {
      writeblock(&V);
      i -= cblksize;
      for (l = 0; l < i; l++)
	V.buffer.chr[l] = V.buffer.chr[l + cblksize];
    }
    k++;
    if (k >= fssize) {
      V.bulta2.newstruct.page++;
      V.p2.adrese = pointx(V.bulta2.pointa);
      k = 0;
    }
  }
  writeblock(&V);
  if (V.outfile != NULL)
    fclose(V.outfile);
  V.outfile = NULL;
  if (V.outfile != NULL)
    fclose(V.outfile);
}  /* end of saves */


/* Local variables for savesn: */
struct LOC_savesn {
  FILE *outfile;
  longint kp;
  sa_pointer bulta2;
  absadr p2, p3;
  union {
    longint long_[256];
    Char chr[1024];
    struct {
      x512 b1, b2;
    } U3;
  } buffer;
} ;

Local Void move__(LINK)
struct LOC_savesn *LINK;
{
  long i, garums;
  object_type *WITH;

  /*si procedura parsuta treso(points jau ir) uz otro*/
  WITH = LINK->p3.objpoint;
  garums = dinform[(long)WITH->U1.dtype].length;
  LINK->p2.adrese = pointx(LINK->bulta2.pointa);
  for (i = 0; i < garums; i++)
    LINK->p2.objpoint->longintarray[i] = WITH->longintarray[i];

  WITH->U1.flags |= setflag;

  WITH->longintarray[1] = LINK->kp;
  LINK->kp += one * garums;
  nextsp(&LINK->bulta2, (int)garums);
}

Local Void writeblock_(LINK)
struct LOC_savesn *LINK;
{

   fwrite(LINK->buffer.U3.b1, sizeof(x512), 1, LINK->outfile);

  /*** write   1 ***/
}


/*************************************** savesn (f,e) *****/
Void savesn(f, e)
Char *f;
long *e;
{
  struct LOC_savesn V;
  long i, j, k;
  longint l, m, la;
  sa_pointer bulta1, bulta3, rab1, rab2;
  absadr p1;
  long biti, garums;
  charmas cptr;
  object_type *WITH;
  _REC_dinformtype *WITH1;
  sa_pointer *WITH2;

  /***  seit  ir  saves  sakums  saves ( f , e ) ***/
  V.outfile = NULL;
  bulta1.pointa = ffby.pointa;
  V.bulta2.pointa = ffby.pointa;
  V.kp = spazime;
  m = 0;
  pointr(*e, &V.p3.adrese);
  move__(&V);
  /*** formesanas cikls kamer pirma bulta panak otro ***/
  while (bulta1.pointa != V.bulta2.pointa) {
    p1.adrese = pointx(bulta1.pointa);
    WITH = p1.objpoint;
    WITH1 = &dinform[(long)WITH->U1.dtype];
    garums = WITH1->length;
    biti = WITH1->spointbit;
    i = 1;
    while (biti != 0) {
      if ((biti & 1) == 1) {
	WITH2 = &WITH->pointarray[i - 1];
    bulta3.pointa = WITH2->pointa;
	if (bulta3.wstruct.segmentpart != 0) {
	  V.p3.adrese = bulta3.pointa;

	  if ((V.p3.objpoint->U1.flags & setflag) == 1)
       {WITH2->exnumb = V.p3.objpoint->longintarray[1];}
     else
         {WITH2->exnumb = V.kp;move__(&V);}

       }
      }


      i++;
      biti /= 2;

    }

    nextsp(&bulta1, (int)garums);
    m++;
  }
  /*** objekts ir uzbuvets un bulta2 rada uz vina beigam ***/
  /*** izstaigajam  jauno  objektu  un  nomainam  akodus ***/
  bulta1.pointa = ffby.pointa;
  bulta3.pointa = V.bulta2.pointa;
  la = 0;
  while (bulta1.pointa != V.bulta2.pointa) {
    p1.adrese = pointx(bulta1.pointa);
    WITH = p1.objpoint;
    WITH1 = &dinform[(long)WITH->U1.dtype];
    garums = WITH1->length;
    biti = WITH1->apointbit;
    i = 1;
    while (biti != 0) {
      if ((biti & 1) == 1) {
	WITH2 = &WITH->pointarray[i - 1];
    rab1.pointa = WITH2->pointa;
	if (rab1.struct_.pazime == (Char)apazime) {
	  rab2.pointa = V.bulta2.pointa;
	  V.p2.adrese = pointx(rab2.pointa);   /*izmantos prevbuf*/
	  k = rab2.newstruct.offset;
	  l = apazime;
      for (j = 1; j <= la; j++) {   /* tada vel nav */
	    if (prevbuf->inform[k] == rab1.pointa)   /* tads jau ir */
	      goto _Lara;
	    k++;
        if (k >= fssize) {
	      rab2.newstruct.page++;
	      V.p2.adrese = pointx(rab2.pointa);
          k = 0;
	    }
	    l += one;
      }
	  la++;
      prevbuf->inform[k] = rab1.pointa;
_Lara:
	  WITH2->exnumb = l;
	}
      }


      i++;
      biti /= 2;

    }

    nextsp(&bulta1, (int)garums);
  }
  /*** seit visi pointeri ir sataisiti un javada lauka ***/
  bulta1.pointa = ffby.pointa;

    V.outfile = fopen(f, "wb");

  if (V.outfile == NULL)
      _EscIO(FileNotFound);

  V.buffer.long_[0] = m;
  i = 2;
  while (bulta1.pointa != V.bulta2.pointa) {
    p1.adrese = pointx(bulta1.pointa);
    WITH = p1.objpoint;
    garums = dinform[(long)WITH->U1.dtype].length;
    for (k = 0; k < garums; k++) {
      V.buffer.long_[i - 1] = WITH->longintarray[k];
      i++;
    }
    nextsp(&bulta1, (int)garums);
    if (i > lblksize) {
      writeblock_(&V);
      i -= lblksize;
      for (k = 0; k < i; k++)
	V.buffer.long_[k] = V.buffer.long_[k + lblksize];
    }
  }
  writeblock_(&V);
  /*** talak izvadam klat a_telpu ***/
  V.buffer.long_[0] = la;
  i = 5;
  V.p2.adrese = pointx(V.bulta2.pointa);   /*izmantos prevbuf*/
  k = V.bulta2.newstruct.offset;
  for (j = 1; j <= la; j++) {
    cptr.cptr1 = &V.buffer.chr[i];
    pointa(prevbuf->inform[k], cptr.cptr80, &garums);
    V.buffer.chr[i - 1] = (Char)garums;
    i += garums + 1;
    if (i > cblksize) {
      writeblock_(&V);
      i -= cblksize;
      for (l = 0; l < i; l++)
	V.buffer.chr[l] = V.buffer.chr[l + cblksize];
    }
    k++;
    if (k >= fssize) {
      V.bulta2.newstruct.page++;
      V.p2.adrese = pointx(V.bulta2.pointa);
      k = 0;
    }
  }
  writeblock_(&V);
  if (V.outfile != NULL)
    fclose(V.outfile);
  V.outfile = NULL;
  if (V.outfile != NULL)
    fclose(V.outfile);
}  /* end of savesn */


/*************************************** vols *****/
Void vols(dr, dw, dp)
long *dr, *dw, *dp;
{
  *dr = sdiscread;
  *dw = sdiscwrite;
  *dp = sdiscpage;
}  /* end of vols */


/* Local variables for reopen: */
struct LOC_reopen {
  longint kp;
  sa_pointer bulta2;
  absadr p2, p3;
} ;

Local Void move___(LINK)
struct LOC_reopen *LINK;
{
  long i, garums;
  object_type *WITH;

  /* si procedura parsuta treso (points jau ir) uz otro */
  WITH = LINK->p3.objpoint;
  garums = dinform[(long)WITH->U1.dtype].length;
  LINK->p2.adrese = pointx(LINK->bulta2.pointa);
  for (i = 0; i < garums; i++)
    LINK->p2.objpoint->longintarray[i] = WITH->longintarray[i];

  WITH->U1.flags |= setflag;

  WITH->longintarray[1] = LINK->kp;   /* new addr of object */
  LINK->kp += one * garums;
  nextsp(&LINK->bulta2, (int)garums);
}


/*************************************** reopen (f,e) *****/
Void reopen(f, e)
long *f, *e;
{
  struct LOC_reopen V;
  long i, k;
  longint m, rab2;
  sa_pointer bulta1, bulta3, rab1;
  absadr p1;
  long biti, garums;
  object_type *WITH;
  _REC_dinformtype *WITH1;
  sa_pointer *WITH2;
  long FORLIM1;

  /***  seit  ir  reopen  sakums  reopen ( f , e ) ***/
  bulta1.pointa = ffby.pointa;
  V.bulta2.pointa = ffby.pointa;
  V.kp = spazime;
  m = 0;
  pointr(*e, &V.p3.adrese);
  move___(&V);
  /*** formesanas cikls kamer pirma bulta panak otro ***/
  while (bulta1.pointa != V.bulta2.pointa) {
    p1.adrese = pointx(bulta1.pointa);
    WITH = p1.objpoint;
    WITH1 = &dinform[(long)WITH->U1.dtype];
    garums = WITH1->length;
    biti = WITH1->spointbit;
    i = 1;
    while (biti != 0) {
      if ((biti & 1) == 1) {
	WITH2 = &WITH->pointarray[i - 1];
	bulta3.pointa = WITH2->pointa;
	if (bulta3.wstruct.segmentpart != 0) {
	  V.p3.adrese = bulta3.pointa;

	  if ((V.p3.objpoint->U1.flags & setflag) == 1)
	    WITH2->exnumb = V.p3.objpoint->longintarray[1];
	  else {
	    WITH2->exnumb = V.kp;
	    move___(&V);
	  }

	}
      }


      i++;
      biti /= 2;

    }

    nextsp(&bulta1, (int)garums);
    m++;
  }
  /*** objekts ir uzbuvets un m ir elementu skaits vina  ***/
  /*** tagad vinu parsutam un noskanojam                 ***/
  bulta1.pointa = ffby.pointa;   /*** no bulta1 uz bulta2 ***/
  V.bulta2.newstruct.offset = 0;
  V.bulta2.newstruct.page = minpage;
  V.p2.adrese = pointx(V.bulta2.pointa);
  holdbuf = prevbuf;
  *f = V.p2.adrese;   /** result of reopen **/
  for (V.kp = 1; V.kp <= m; V.kp++) {   /* for each object in infile do */
    p1.adrese = pointx(bulta1.pointa);
    WITH1 = &dinform[(long)p1.objpoint->U1.dtype];
    garums = WITH1->length;
    biti = WITH1->spointbit;
    for (k = 0; k < garums; k++) {   /* for each longword in object */
      rab1.pointa = p1.objpoint->pointarray[k].pointa;

      if ((biti & 1) == 1 && rab1.struct_.pazime == (Char)spazime)
      {  /* transform offset to s-addr */
	rab2 = rab1.pointa / 256;   /* + ffby.struct.offset;*/
	rab1.newstruct.offset = rab2 & andoffs;
    /*rab1.newstruct.page = rab2 / ssize + ffby.newstruct.page;*/
    rab1.newstruct.page = rab2 / ssize ;

	rab1.pointa = pointx(rab1.pointa);
      }


      holdbuf->inform[V.bulta2.newstruct.offset] = rab1.pointa;
      V.bulta2.newstruct.offset++;

      biti /= 2;

    }
    nextsp(&bulta1, (int)garums);
    if (V.bulta2.newstruct.offset >= ssize) {   /* if end of s-page */
      V.bulta2.newstruct.offset -= ssize;
      V.bulta2.newstruct.page++;
      V.p2.adrese = pointx(V.bulta2.pointa);
      holdbuf = prevbuf;
      FORLIM1 = V.bulta2.newstruct.offset;
      for (k = 0; k <= FORLIM1; k++)
	holdbuf->inform[k] = 0;
    }
  }
  holdbuf = NULL;
  ffby.pointa = V.bulta2.pointa;
}  /* end of reopen */


/*procedure aaa;*/
/*var dt:descriptortype;
begin
init_dinform;
 for dt:=dummy to spec do
  if dinform[dt].length<>dinform_1[dt].length then writeln('NO!-');
  if dinform[dt].apointbit<>dinform_1[dt].apointbit then writeln('NO!-');
  if dinform[dt].spointbit<>dinform_1[dt].spointbit then writeln('NO!-');
*/





/* End. */
