#include "globrig.h"
#include "define.h"
#include "defpage.h"
#include "ley.h"
#include "nef2.h"


/* lexic analysis for rigal language
   input : text file with name first_file
           and if 'NOT_INCLUDE' is false
             then all included files
   output :s-object code and added a-objects

   may be called from editor environment through checker
   or from usepas for user's call
   #call_pas(14 'A.RIG') or #call_pas(15 'A.RIG') .

   token's COoRDinates returned as LINE_NUMBER*80+SYMBOL_NUMBER
   included file names returned as tatom descriptors;
     exception: first_file never returned as first lexem.
   added letter to filename  i if %included file
                             c if returned from %include
*/

#define filemax         4   /* ~islo wlovenij dlq include */
#define bufmaxlen       10   /* dlina malogo bufera , kak minimum - 8 */
#define two_char_sym_max  50   /* maks. massiwa */


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


FILE *infile[filemax];   /* fajly ish. teksta */
bufrectype bufrec;   /* sohranenie dlq leksera !!!! */
c2 twochar_symbols[two_char_sym_max];
char twochar_symbols_num;


typedef Char a146[146];   /* source string type */

typedef Char bigstr_type[146];



typedef struct _REC_fistack {
  long curline;   /* current line of this file */
  filespecification f;   /* file name */
} _REC_fistack;

/* Local variables for ley: */
struct LOC_ley {
  error_rec_type *error_rec;
  a satomadr;
  long i;   /* current byte */
  boolean errflag;
  a146 s;

  _REC_fistack fistack[filemax + 1];
  long fistacklen;
} ;

Local Void newlist(pp, LINK)
ptr_ *pp;
struct LOC_ley *LINK;
{
  /* nowyj ukazatelx spiska */
  /* sozdaet nowyj spisok */
  mpd x;
  a a1;

  gets5(&a1, &x.sa);
  points(a1, &x.sa);
  x.smld->dtype = listmain;
  x.smld->lastfragm = a1;
  pp->ptrtype = ptrlist;
  pp->cel = 0;
  pp->nel = 0;
  pp->UU.U1.curfragment = a1;
  pp->UU.U1.mainadr = a1;
}

Local Void push(pp, adr, LINK)
ptr_ *pp;
long adr;
struct LOC_ley *LINK;
{
  mpd x, x1;
  a a1;

  /* dobawlqet po pojnteru spiska nowyj |lement k spisku*/
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
    /* w slu~ae dostiveniq konca fragmenta spiska */
    gets5(&a1, &x1.sa);
    if (x.smld->dtype == listmain)   /* podceplenie */
      x.smld->next = a1;
    else
      x.sfld->next = a1;
    /* obrazuem i zapolnqem nowyj  */
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
  /* ob{ij clu~aj dobawleniq |lementa wnutri fragmenta */
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

Local Void mistake(mistake_num, LINK)
long mistake_num;
struct LOC_ley *LINK;
{
  string80 com;

  printf("Error...%12ld M=%s\n", mistake_num, LINK->error_rec->message);
  switch (mistake_num) {

  case 1:
    strcpy(com, "MAIN PROGRAM FILE  IS NOT FOUND ");
    break;

  case 2:
    strcpy(com, "MORE THAN 2 NESTED %INCLUDE FILES");
    break;

  case 3:
    strcpy(com, "THIS %INCLUDE FILE  IS NOT FOUND ");
    break;

  case 4:
    strcpy(com, "TOO LONG (>80 BYTES) TOKEN");
    break;

  case 5:
    strcpy(com, "WRONG CHARACTER AFTER NUMBER");
    break;

  case 6:
    strcpy(com, "TOO BIG NUMBER (> 2.**31) ");
    break;

  case 8:
    strcpy(com, "ENDING APOSTROPHE NOT FOUND IN THIS LINE");
    break;

  case 11:
    strcpy(com, "THIS CHARACTER NOT ALLOWED ");
    break;

  case 12:
    strcpy(com, "NUMBER AFTER \"A'\" NOT FOUND ");
    break;

  case 13:
    strcpy(com, "ZERO LENGTH STRING NOT ALLOWED");
    break;

  case 14:
    strcpy(com, "RULE NAME AFTER \"#\" NOT FOUND ");
    break;

  case 17:
    strcpy(com, "NUMBER AFTER \"A'\" MUST BE N*512");
    break;

  case 18:
    strcpy(com, "WRONG DIGIT (8 or 9) IN OCTAL NUMBER ");
    break;


  default:
    strcpy(com, "UNKNOWN LEXICAL ERROR");
    break;
  }
  printf("...\n");
  LINK->errflag = true;
  strcpy(LINK->error_rec->message, com);
  LINK->error_rec->address =
    LINK->fistack[LINK->fistacklen - 1].curline * 80 + LINK->i;
  strcpy(LINK->error_rec->filename, LINK->fistack[LINK->fistacklen - 1].f);
  printf(" LEXICAL ERROR : %s\n", com);
  printf(" LINE=%12ld  SYMBOL=%12ld\n",
	 LINK->fistack[LINK->fistacklen - 1].curline, LINK->i);
}

Local Void makeatom(ik, jk, desk, LINK)
long ik, jk;
char desk;
struct LOC_ley *LINK;
{
  /* makes s-atom
     from array s, starting ik, length jk
   */
  mpd x;
  a a1m;
  atomdescriptor *WITH;

  putatm(&LINK->s[ik - 1], jk, &a1m);
  gets1(&LINK->satomadr, &x.sa);
  WITH = x.sad;
  WITH->cord = LINK->fistack[LINK->fistacklen - 1].curline * 80 + LINK->i;
      /*!!*/
  WITH->dtype = desk;
  WITH->name = a1m;
}



Void ley(first_file_, lesrez, not_include, error_rec_)
Char *first_file_;
long *lesrez;
boolean not_include;
error_rec_type *error_rec_;
{
  /* added lastfragm 12-jul-91 */

  struct LOC_ley V;
  string80 first_file;
  char dt;
  longint ilong;
  a adr;
  char jcase;
  long j, nn, jj, ii;
  mpd x;
  long len;   /* current line length */
  ptr_ p;
  mpd y;
  boolean is_ident, x_lists;
  /*  srb,srl,slb,sll: string; */
  Char table[254]; 
  boolean maybe_octal;
  bigstr_type a_long;   /*varying[145] of char;*/
  a146 s1;
  filespecification ff1;
  string80 ssint;


  /***  Char twochar_string[161]; **/
  long rline;
  Char c;
  long FORLIM;
  numberdescriptor *WITH;
  ruledescriptor *WITH1;
  vardescriptor *WITH2;
  specdescriptor *WITH3;


printf("L1");

}




/* End. */

