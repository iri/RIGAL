/* Output from p2c, the Pascal-to-C translator */
/* From input file "def_tst.z" */


/* this file is test for define.pas*/

#include <p2c/p2c.h>


/* the declaration of main data structures of
   s-space for rigal/ unix;
   (c) rigal v.00-v.2.xx
*/

/* changed for version 1.60 - mainlistnum is set to 5,
                             lastfragm is added
  for version 1.60 - ptr is changed */


#define version         "2.18"

/* character set *********************************** */

/* all these additional characters are added only for compatibility
   with old version with russian letters */

/* descriptor sizes ******************************** */


#define listnodenumb    5   /*  number of nodes for list descriptor  */
#define mainlistelnum   5
/* was = 6 before 1.60 */
/* = (listnodenumb - 2) * 2 -1 number of list elements in the
    main list descriptor */

#define fragmlistelnum  8
/*= (listnodenumb - 1) * 2  number of list elements in
     auxilary list descriptors */

#define treenodenumb    5   /*  number of nodes for tree descriptor */

#define maintreearcnum  3
/* (treenodenumb - 2) number of list elements in the
         main tree descriptor */


#define fragmtreearcnum  4
/* (treenodenumb - 1)  in auxilary */

#define null_           0   /* empty  object */
#define maxvarnumb      127   /* maximal number of variables in one rule */
#define filenum         5   /* maximal number of opened files */


/* following s-addresses are reserved for internal purposes
   - for the interpretable code. they are x*512 , they are in  0 <= x < 64k */
/*      0    512   1024   1536   2048   2560   3072 */
/*   3584   4096   4608   5120   5632   6144   6656 */
/*   7168   7680   8192   8704   9216   9728  10240 */
/*  10752  11264  11776  12288  12800  13312  13824 */
/*  14336  14848  15360  15872  16384  16896  17408 */
/*  17920  18432  18944  19456  19968  20480  20992 */
/*  21504  22016  22528  23040  23552  24064  24576 */
/*  25088  25600  26112  26624  27136  27648  28160 */
/*  28672  29184  29696  30208  30720  31232  31744 */

/* codes used in the interpreter  */

#define tr              512   /* tree <. .> */
#define li              1024   /* list (. .) */
#define al              1536   /* alternatiwa ( ! ) */
#define fa              2048   /* fakultatiw [ ] */
#define se              2560   /* star el. ( * * ) */
#define ps              3072   /* plus (+ +) */
#define ti              3584   /* tree iteration <* *> */
#define vpat            6144   /* v -pattern */
#define spat            6656   /* s -pattern */

/* separatori w s-kodah rigal */

#define tdelim          4096   /* separatorx wetwej derewa */
#define adelim          4608   /* separatorx wetwej alxternatiwy */
#define asdelim         5632   /* razd.lew. i praw. ~astej := */
#define opdelim         28672   /* separatorx / */
#define clistdelim      14336
#define ctreedelim      15872
#define seldelim        30720   /* razd.selektora i obxekta */

/* statements and operators  */

#define cfail           12288
#define creturn         11776
#define cass1           6144
#define cass2           6656
#define cass3           7168
#define cass4           7680
#define cass5           8192
#define cnull           29184   /* $e:= null w {ablone */
#define clast           17408
#define crule           17920
#define cselect         18432
#define cindex          18944
#define cname           19456
#define cmult           19968
#define cdiv            20480
#define cmod            20992
#define cconc           21504
#define clconc          22016
#define ctradd          22528
#define cadd            23040
#define cminus          23552
#define cequ            24064
#define cnequ           24576
#define cgt             25088
#define clt             25600
#define cge             26112
#define cle             26624
#define cin             27136
#define cand            27648
#define cor             28160
#define cnot            16384
#define cunminus        16896
#define ccopy           29696
#define clist1          13312
#define clist2          13824
#define ctree1          14848
#define ctree2          15360


/* data types */


typedef long longint;


typedef short word;
   /* must be 2 byte positive integer */
typedef Char string80[81];

typedef short byte_type;

/* string80=string[80];*/

typedef long a;

typedef long aa;
   /* adresses of a-space */

typedef Char c2[2];   /* =2.  bytes */
typedef Char c4[4];
/* c8 = packed array [1..8] of char;*/
typedef Char bl80[80];
typedef Char a80[80];
typedef Char real_char[sizeof(double)];   /*added 17-feb-92*/

#define dummy           0
#define listmain        1
#define listfragm       2
#define treemain        3
#define treefragm       4
#define atom            5
#define idatom          6
#define keyword         7
#define number          8
#define tatom           9
#define fatom           10
#define variable        11
#define idvariable      12
#define nvariable       13
#define fvariable       14
#define rulename        15
#define object_d        16
#define set_coord       17
#define spec            18
#define xxx_19          19
#define complex_desk    20
#define start_list      21
#define end_list        22
#define start_tree      23
#define end_tree        24
#define name_obj        25
#define eof_desk        26


/* !! internal representation of these enumerable constants
     is important !! */
/* =1.  bytes */
/*0*/
/*1*/
/*2*/
/*3*/
/*4*/
/*5*/
/*6*/
/* identifier */
/*7*/
/*8*/
/*9*/
/* text constant */
/*10*/
/* float constant */
/*11*/
/*17*/
/* sets coordinate */
/*18*/
/* special delimiter 0,512,1024,..*/
/* reserved */
/*20*/
/*21*/
/*22*/
/*23*/
/*24*/
/*25*/
/*26*/

/* these structures are important,
   if something is shifted, it must be marked in
   defpage.pas tables */
/* "dtype" and "flags" must be 2 first bytes */
/*  "next" must be the last 37-40 bytes */
/* "xx", "xxx" are reserved fields */
/* "cord" is unsigned integer, 2 bytes */
/* "val"  is signed long integer */

/* old version :
mainlistdescriptor= record             (* =40.  bytes *)
   dtype : descriptortype;                   (* =1.  bytes *)
   flags : 0 ..31;                           (* =1.  bytes *)
   xx :   array [ 1 ..  1  ] of boolean;(* =1.  bytes *)
   elnum : 0 ..mainlistelnum;                (* =1.  bytes *)
   totalelnum : longint;                      (* =4.  bytes *)
   name : aa;                                (* =4.  bytes *)
   elt : array[ 1 ..mainlistelnum] of a;     (* =6*4=24.  bytes *)
   next : a; end;                            (* =4.  bytes *)
*/

typedef struct mainlistdescriptor {
  /* =40.  bytes */
  char dtype;   /* =1.  bytes */
  char flags;   /* =1.  bytes */
  boolean xx[1];   /* =1.  bytes */
  char elnum;   /* =1.  bytes */
  longint totalelnum;   /* =4.  bytes */
  aa name;   /* =4.  bytes */
  a elt[mainlistelnum];   /* =5*4=20.  bytes */
  a lastfragm;   /* last descriptor address    =4.  bytes */
  a next;
} mainlistdescriptor;   /* =4.  bytes */

typedef struct fragmlistdescriptor {
  /* =40.  bytes */
  char dtype;   /* =1.  bytes */
  char flags;   /* =1.  bytes */
  char elnum;   /* =1.  bytes */
  boolean xx[1];   /* =1.  bytes */
  a elt[fragmlistelnum];   /* =8*4=32.  bytes */
  a next;
} fragmlistdescriptor;   /* =4.  bytes */


typedef struct te {
  aa arcname;   /* =8=4+4.  bytes */
  a elt;
} te;


typedef struct maintreedescriptor {
  /* =40.  bytes */
  char dtype;   /* =1.  bytes */
  char flags;   /* =1.  bytes */
  char arcnum;   /* =1.  bytes */
  boolean xx[1];   /* =1.  bytes */
  longint totalarcnum;   /* =4.  bytes */
  aa name;   /* =4.  bytes */
  te arc[maintreearcnum];   /* =8*3=24.  bytes */
  a next;
} maintreedescriptor;   /* =4.  bytes */

typedef struct fragmtreedescriptor {
  /* =40.  bytes */
  char dtype;   /* =1.  bytes */
  char flags;   /* =1.  bytes */
  char arcnum;   /* =1.  bytes */
  boolean xx[1];   /* =1.  bytes */
  te arc[fragmtreearcnum];   /* =8*4=32.  bytes */
  a next;
} fragmtreedescriptor;   /* =4.  bytes */


typedef struct atomdescriptor {
  /* =8.  bytes */
  char dtype;   /* =1.  bytes */
  char flags;   /* =1.  bytes */
  word cord;
  /* unsigned */
  /* =2.  bytes */
  aa name;   /* =4.  bytes */
} atomdescriptor;

typedef struct numberdescriptor {
  /* =8.  bytes */
  char dtype;   /* =1.  bytes */
  char flags;   /* =1.  bytes */
  word cord;   /* =2.  bytes */
  longint val;   /* signed */
} numberdescriptor;   /* =4.  bytes */

typedef struct vardescriptor {
  /* =8.  bytes */
  char dtype;   /* =1.  bytes */
  char flags;   /* =1.  bytes */
  boolean guard;   /* =1.  bytes */
  char location;   /* =1.  bytes */
  aa name;
} vardescriptor;   /* =4.  bytes */

typedef struct ruledescriptor {
  /* =16.  bytes */
  char dtype;   /* =1.  bytes */
  char flags;   /* =1.  bytes */
  word cord;   /* =2.  bytes */
  aa name;   /* =4.  bytes */
  a fragmadr;   /* =4.  bytes */
  a nomintab;   /* =4.  bytes */
} ruledescriptor;


typedef struct specdescriptor {
  /* =8.  bytes */
  char dtype;   /* =1.  bytes */
  char flags;   /* =1.  bytes */
  boolean xx[2];   /* =2.  bytes */
  longint val;
} specdescriptor;   /* =4.  bytes */

typedef struct objdescriptor {
  /* =16.  bytes */
  char dtype;   /* =1.  bytes */
  char flags;   /* =1.  bytes */
  boolean variable_;   /* =1.  bytes */
  char nel;   /* =1.  bytes */

  a fragmorvar;   /* =4.  bytes */
  a glavn;   /* =4.  bytes */
  a rezerv;   /* =4.  bytes */
} objdescriptor;

typedef a a10_type[10];

typedef union mpd {
  /* multiply pointers to descriptors */
  a sa;
  mainlistdescriptor *smld;
  fragmlistdescriptor *sfld;
  maintreedescriptor *smtd;
  fragmtreedescriptor *sftd;
  atomdescriptor *sad;
  numberdescriptor *snd;
  vardescriptor *svd;
  ruledescriptor *srd;
  atomdescriptor *sc8;
  specdescriptor *sspec;
  objdescriptor *sobj;
  Char *sbl80;
  long *sa10;
} mpd;   /* =4.  bytes */

#define ptrlist         0
#define ptrtree         1
#define packedlist      2

/*------------------------------------------------*/

typedef struct ptr_ {
  /* refers to the current element of agregate */
  unsigned ptrtype : 2;
/* p2c: def_tst.z, line 309: Note:
 * Field width for PTRTYPE assumes enum ptrtype_enum has 3 elements [105] */
  /* type of agregate */
  unsigned nel : 4;
  /* number of element in current fragment of agregate,
     or in array */
  /* =0 if no more elements */
  unsigned plistsize : 3;
  /* current size of array;
      used for rule call optimization
      with <= 4 arguments.
    used only if ptrtype=packedlist ,
    undefined otherwise */

  a cel;   /* refers to the current element */
  union {
    struct {
      a arc;   /* arc selector a-address */

      a curfragment;   /* current fragment descriptor */

      /* main fragment */
      a mainadr;
    } U1;
    /* number "4" is fixed in compiler code-generation phase
       file stmt2.rig rule #g_call */
    a plistelt[3];
  } UU;
} ptr_;

/*======================================*/
/* this is used for access to os file names */
typedef Char filename_type[81];

typedef Char checker_message_type[81];


typedef Char filespecification[81];


/* this is used for checker and editor common variables */

typedef struct error_rec_type {
  checker_message_type message;
  filename_type filename;
  word address;
} error_rec_type;


typedef struct _REC_filetab {
  a name;   /* a-address of rigal file */
  boolean isopen;   /*  */
  boolean screen;
  long strlen;   /* specified max length */
  long curlen;   /* current length */
} _REC_filetab;


long SET[4];
long SET1[4];
long SET2[4];
long SET3[5], SET4[5];
long SET5[5], SET6[5];
long SET7[9], SET8[9];
long SET9[3];
_REC_filetab filetab[filenum];

FILE *files[filenum];
mpd x;


Static Void cln()
{
  long i;

  for (i = 0; i <= 79; i++)
    x.sbl80[i] = '\0';
}


Static Void wrx(i)
long i;
{
  if (i < 10)
    putchar((Char)(i + '0'));
  else
    putchar((Char)(i + 87));
}


Static long consum()
{
  long rez, i;

  rez = 0;
  for (i = 1; i <= 80; i++) {
    rez += x.sbl80[i - 1] * i % 1001;
/* p2c: def_tst.z, line 378:
 * Note: Using % for possibly-negative arguments [317] */
  }
  return rez;
}


Static long consum2()
{
  long rez, i;

  rez = 0;
  for (i = 1; i <= 10; i++) {
    rez += x.sa10[i - 1] % 1001 * i % 1001;
/* p2c: def_tst.z, line 387:
 * Note: Using % for possibly-negative arguments [317] */
/* p2c: def_tst.z, line 387:
 * Note: Using % for possibly-negative arguments [317] */
  }
  return rez;
}


Static Void pr()
{
  long i, j;

  printf("%12ld/%12ld\n", consum(), consum2());

  for (j = 0; j <= 1; j++) {
    for (i = j * 20; i <= j * 20 + 19; i++) {
      wrx(x.sbl80[i] / 16L);
      wrx(x.sbl80[i] & 15L);
      putchar(' ');
    }
    putchar('\n');
  }
}


main(argc, argv)
int argc;
Char *argv[];
{
  long i;
  mainlistdescriptor *WITH;
  fragmlistdescriptor *WITH1;
  maintreedescriptor *WITH2;
  fragmtreedescriptor *WITH3;
  atomdescriptor *WITH4;
  numberdescriptor *WITH5;
  vardescriptor *WITH6;
  ruledescriptor *WITH7;
  specdescriptor *WITH8;
  objdescriptor *WITH9;

/* p2c: def_tst.z: Note: Array of files files should be initialized [257] */
  PASCAL_MAIN(argc, argv);
  printf(" STARTUP \n");
  x.sbl80 = (Char *)Malloc(sizeof(bl80));
  printf("smld%12ld\n", sizeof(mainlistdescriptor));
  cln();
  WITH = x.smld;
  WITH->dtype = listmain;
  WITH->flags = 3;
  WITH->elnum = 4;
  WITH->totalelnum = 5;
  WITH->name = 6;
  for (i = 1; i <= 5; i++)
    WITH->elt[i - 1] = i + 6;
  WITH->lastfragm = 12;
  WITH->next = 13;
  pr();

  printf("sfld%12ld\n", sizeof(fragmlistdescriptor));
  cln();
  WITH1 = x.sfld;
  WITH1->dtype = listfragm;
  WITH1->flags = 3;
  WITH1->elnum = 4;
  WITH1->xx[0] = true;
  for (i = 1; i <= 8; i++)
    WITH1->elt[i - 1] = i + 6;
  WITH1->next = 15;
  pr();

  printf("smtd%12ld\n", sizeof(maintreedescriptor));
  cln();
  WITH2 = x.smtd;
  WITH2->dtype = treemain;
  WITH2->flags = 3;
  WITH2->arcnum = 2;
  WITH2->xx[0] = true;

  WITH2->totalarcnum = 5;
  WITH2->name = 6;
  for (i = 1; i <= 3; i++)
    WITH2->arc[i - 1].arcname = i + 6;
  for (i = 1; i <= 3; i++)
    WITH2->arc[i - 1].elt = i + 12;
  WITH2->next = 23;
  pr();

  printf("sftd%12ld\n", sizeof(fragmtreedescriptor));
  cln();
  WITH3 = x.sftd;
  WITH3->dtype = treefragm;
  WITH3->flags = 3;
  WITH3->arcnum = 4;
  WITH3->xx[0] = true;

  for (i = 1; i <= 4; i++)
    WITH3->arc[i - 1].arcname = i + 6;
  for (i = 1; i <= 4; i++)
    WITH3->arc[i - 1].elt = i + 12;
  WITH3->next = 23;
  pr();

  printf("sad%12ld\n", sizeof(atomdescriptor));
  cln();
  WITH4 = x.sad;
  WITH4->dtype = idatom;
  WITH4->flags = 3;
  WITH4->cord = 50004L;
  WITH4->name = 90005L;
  pr();

  printf("snd%12ld\n", sizeof(numberdescriptor));
  cln();
  WITH5 = x.snd;
  WITH5->dtype = idatom;
  WITH5->flags = 3;
  WITH5->cord = 50004L;
  WITH5->val = 10090005L;
  pr();

  printf("svd%12ld\n", sizeof(vardescriptor));
  cln();
  WITH6 = x.svd;
  WITH6->dtype = nvariable;
  WITH6->flags = 3;
  WITH6->guard = true;
  WITH6->location = 77;
  WITH6->name = 90005L;
  pr();

  printf("srd%12ld\n", sizeof(ruledescriptor));
  cln();
  WITH7 = x.srd;
  WITH7->dtype = rulename;
  WITH7->flags = 3;
  WITH7->cord = 50004L;
  WITH7->name = 90005L;
  WITH7->fragmadr = 55;
  WITH7->nomintab = 66;
  pr();

  printf("sspec%12ld\n", sizeof(specdescriptor));
  cln();
  WITH8 = x.sspec;
  WITH8->dtype = idatom;
  WITH8->flags = 3;
  WITH8->xx[0] = true;
  WITH8->xx[1] = true;
  WITH8->val = 900009L;
  pr();

  printf("sobj%12ld\n", sizeof(objdescriptor));
  cln();
  WITH9 = x.sobj;
  WITH9->dtype = idatom;
  WITH9->flags = 3;
  WITH9->variable_ = true;
  WITH9->nel = 5;
  WITH9->fragmorvar = 10;
  WITH9->glavn = 11;
  WITH9->rezerv = 12;
  pr();
  exit(EXIT_SUCCESS);
}




/* End. */

