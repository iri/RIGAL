#include "globrig.h"
#include "define.h"
#include "defpage.h"
#include "scan.h"
#include "nef2.h"

 /*4-jul-93 invented maxline as length of input line*/
 /* 6-dec-93: user can set on or off definition "bbs" */
 /*   University of New Mexico: #define bbs
      Other places where bbs filter is not used:
                                / * #define bbs * /


 september-95  (release rig444c)
    Added processing for cases when a newline appears within FrameMaker
    string constants.

    Added processing of comma within a   FrameMaker  string constant 
    as separate atom
  */
/*#define bbs*/


#define maxline         255


typedef Char bigstring[maxline + 1];


#define new_line_code   '\015'   /* chr(0 is allowed too */
#define endfile_code    '\032'

#define is_control      0
#define is_letter       1
#define is_digit        2
#define is_underscore   3
#define is_printable    4
#define is_special      5
#define is_space        6
#define is_first_of_two  7


typedef Char pair[2];


 a a1;   /* global variable for only local use */
/*aa1 : aa ;*/
/* --"-- */
 mpd x;   /* --"-- */
 bl80 bl801;
/* -- " -- */
/* array[1..80] of char*/
 long k, kk;   /* -"- */
 Char c1;

 word saved_coord;   /* where current token_ began */
 word coord_mark;   /* what was set by coordinate marker */
 word line_byte_number;
/* number of totally read bytes till beginning
                      of current line */
 word last_mark_byte_number;
/* number of totally read bytes till
                       last coordinate marker */
/* length of the current line,
                   used only for incrementation of "lyne_byte_number"*/
 word old_line_length;
 Char dt;
/* type of last read token_ or control character */
 a aadr;   /* a-space address of last read token_ */
 longint linenumber;   /* current line number */
 longint tokennumber;   /* current token_ number */
 a errlist;   /* list of numbers of errors */
 long read_mode;   /* 1,2,3 */
 ptr_ ptr1;   /* list pointer when read from list of atoms */

 FILE *inpfile;
 boolean c_lexics, pascal_lexics, row80_coord, byte_coord,
	       mark_byte_coord, mark_only_coord, string_coord, char_coord,
	       token_coord, collect_errors, screen_errors, to_uppercase,
	       pascal_comment, c_comment, ada_comment, pascal_string,
	       modula_string;
 bigstring s, s_for_val;   /* added 17-feb-92 */
 long i;
 char as[256];
 char isa;
 Char upcase_tab[256];
 char set_of_second_of_two[9];
 long two_char_symbols_num;
 pair two_char_symbols[30];

 union {
  Char b1;
  Char b2[2];
  Char b3[3];
} b123;


 boolean in_comment, in_string, is_2quote;
    /* if in_string then it is possible */
 longint str_constlen;
 string80 str_const;   /* array of char is allowed too */


/*=====  sun version ===*/
Static Void jnc_(xxx)
long *xxx;
{
  (*xxx)++;
}


Static Void jnc2_(xxx, yyy)
long *xxx, yyy;
{
  *xxx += yyy;
}


Static Void jncx_(xxx)
long *xxx;
{
  (*xxx)++;
}


Static Void jnc2x_(xxx, yyy)
long *xxx, yyy;
{
  *xxx += yyy;
}


/*=====*/

Static Char cont_char_to_dt_ PP((int c));

Static word getcoord_ PV();

Static Void er_lex_ PP((long er_number));

/*procedure initialize_scan_variables;forward;*/
Static Void read_file_ PP((long *read_file_rez));

Static long read_item_ PP((long *pghead));

Static Void readline_ PV();

Static Void putatom_ PP((long j));

Static Void putit_ PP((Char dd, long j));

Static Void putident_ PP((long j));

Static Void putfloat_ PP((long j));

Static Void putnumber_ PV();

Static Void putstr_ PP((Char dd));

/*procedure scaner;forward;*/
Static Void setlexics_ PV();

Static Void stradd_ PP((int c));

Static Void strbegin_ PV();

Static Void token_ PV();

Static long take_digits_ PP((long *jj));

Static long take_letters_ PV();



/* uses global string, received from readline_ procedure,
   produces global attributes of new one token_ read.
   some variables also should be initialized if by initial_token
   procedure at the start of the whole programm */

/* this procedure is oriented to turbo pascal language */
/* procedure call graph follows :
                                  /self\
  usepas -> scan -> readfile -> readitem  ->  addel.nef
                             -> lconc.nef     er_lex_
                 -> setoptions                gets1.defpage
                 -> first.nef                 token_
                 -> assign.system             pointr.defpage
                 -> reset.system              lconc.nef
                 -> readline_


  token_    -> er
                -> read_letters_or_digits
                -> read_digits
                -> strbegin_
                -> putnumber_
                -> stradd_ -> er
                -> putstr_ -> putatm.defpage
                -> putatom_ ->\
                -> putfloat_     -> putit_ -> putatm.defpage
                -> putident_     ->/
*/



Static Char cont_char_to_dt_(c)
Char c;
{
  /************************************************/
  Char Result;

  Result = (Char)c;

  if (c == '<')
    Result = start_list;
  if (c == '>')
    return end_list;

  return Result;
}


Static word getcoord_()
{
  /*************************/
  if (row80_coord)
    return (i + linenumber * 80);
  else {
    if (mark_only_coord)
      return coord_mark;
    else {
      if (mark_byte_coord)
	return (coord_mark + line_byte_number + i - last_mark_byte_number);
      else {
	if (byte_coord)
	  return (line_byte_number + i);
	else {
	  if (string_coord)
	    return linenumber;
	  else {
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


Static Void er_lex_(er_number)
long er_number;
{
  /*************************************/
  a er_atom;
  word co;
  numberdescriptor *WITH;

  co = getcoord_();
  if (collect_errors) {
    gets1(&er_atom, &x.sa);
    WITH = x.snd;   /*global*/
    WITH->dtype = number;
    WITH->cord = co;
    WITH->val = er_number;
    lconc(&errlist, er_atom);
  }
  if (screen_errors)
    printf("Lexical error (%12ld) line=%12d column=%12d\n",
	   er_number, co / 80, co % 80);
}





Void initialize_scan_variables_mif()
{

  /*************************************/
  Char c;
  short TEMP;

  for (TEMP = '\0'; TEMP <= 255; TEMP++) {
    c = TEMP;
    upcase_tab[c] = c;
  }
  for (c = 'a'; c <= 'z'; c++)   /*ascii*/
    upcase_tab[c] = c - 32;
  for (TEMP = 160; TEMP <= 175; TEMP++) {
    c = TEMP;
    upcase_tab[c] = c - 32;
  }
  /*russian*/
  for (TEMP = 224; TEMP <= 239; TEMP++) {
    c = TEMP;
    upcase_tab[c] = c - 60;
  }
  /*russian*/
  for (c = '\0'; c <= '\037'; c++)
    as[c] = is_control;
  for (TEMP = 128; TEMP <= 255; TEMP++) {
    c = TEMP;
    as[c] = is_letter;
  }
  /* russian and pseudographics */
  for (TEMP = ' '; TEMP <= '\177'; TEMP++) {
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

  /* all the rest settings - see procedure setlexics_ */

}








Static Void read_file_(read_file_rez)
long *read_file_rez;
{
  /********************************/
  /* reads whole input, produces list of items */
  a head;

  *read_file_rez = null_;
  do {
    a1 = read_item_(&head);
    if (dt == start_tree || dt == end_tree || dt == start_list ||
	dt == end_list || dt == name_obj) {
      er_lex_(6L);
      goto _L99;
    }
    if (dt != eof_desk) {
      if (head != null_)
	lconc(read_file_rez, head);
      lconc(read_file_rez, a1);
    }
  } while (dt != eof_desk);
_L99: ;
}



Static long read_item_(pghead)
long *pghead;
{
  /**********************/
  long Result;
  a aadr1, result, temp_res, dum, head;
  atomdescriptor *WITH;
  numberdescriptor *WITH1;

  Result = null_;   /* default value for exits with errors */
  *pghead = null_;
  result = null_;
  token_();

  /*writeln('DT=',dt,ord(dt));*/

  switch (dt) {

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
    WITH1->val = aadr;   /* is set in token_ .. is_digit */
    break;

  case dummy:
    result = null_;
    break;

  case start_tree:
    result = null_;
    do {
      token_();
      aadr1 = aadr;   /* to save */
      if (dt == idatom || dt == atom || dt == tatom || dt == keyword) {
	/* what is allowed selector in scaner input ?
	   normally - idatom only, but here
	   atom is allowed too - for experiment purposes */
	a1 = read_item_(&dum);
	if (dt == end_list) {
	  er_lex_(6L);
	  goto _L99;
	}
	if (dt == eof_desk) {
	  er_lex_(1L);
	  goto _L99;
	}
	addel3(&result, aadr1, a1);
      } else if (dt != end_tree) {
	er_lex_(2L);
	goto _L99;
      }
    } while (dt != end_tree && dt != eof_desk);
    if (dt == eof_desk) {
      er_lex_(3L);
      goto _L99;
    }
    dt = complex_desk;
    /* to ignore analysis in upper level of
                        recursion */
    break;

  case start_list:
    result = null_;

    *pghead = read_item_(&dum);
    do {
      a1 = read_item_(&head);
      if (dt == eof_desk) {
	er_lex_(4L);
	goto _L99;
      }
      if (dt != end_list) {
	if (head != null_)
	  lconc(&result, head);
	lconc(&result, a1);
      }
    } while (dt != end_list);


    dt = complex_desk;
    break;

  case end_tree:
    er_lex_(5L);
    goto _L99;
    break;

  case end_list:
    break;
    /*immodiately returns to the upper level*/

  case name_obj:
    temp_res = read_item_(&dum);
    if (dt == end_list) {
      er_lex_(6L);
      goto _L99;
    }
    if (dt == eof_desk) {
      er_lex_(7L);
      goto _L99;
    }
    result = read_item_(&dum);
    if (dt == end_list) {
      er_lex_(6L);
      goto _L99;
    }
    if (dt == eof_desk) {
      er_lex_(8L);
      goto _L99;
    }
    if (result != null_) {
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
    er_lex_(9L);
    goto _L99;   /* impossible value */
    break;
  }/* case */
  Result = result;
_L99:
  return Result;
}  /* read_item_ */




Static Void readline_()
{
  /*****************************/
  /* sets new values for "s" and "i" global variables */
  Char c;
  long rline;
  atomdescriptor *WITH;
  long FORLIM;
  int fff;
  i = 1;
  /* in any case, so; only here it is initialized.
          it is column number.
          variable "s" is string only for speed purposes;
          it plays exactly as packed array of char,
          never used as whole and the length byte is never used */
  linenumber++;
  line_byte_number += old_line_length;
  if (read_mode == 1) {
   if (feof(inpfile))
      s[0] = endfile_code;
    else {
      /*readln(inpfile,s);*/
      if  ( fgets(s, maxline-1 ,inpfile) )
        { if (strlen(s) >= maxline - 2)
       	   printf(" FATAL ERROR: Line %12ld too long !\n", linenumber);
    /*    printf("\n Input=<%s> \n",s); */
          s[strlen(s)-1] = new_line_code;
          old_line_length = strlen(s);
        }
      else  s[0] = endfile_code;

       }
      } else {
    if (read_mode == 2) {
      if (ptr1.nel == 0) {
	s[0] = endfile_code;
	goto _L99;
      }
      if (ptr1.cel == 0) {
	s[0] = new_line_code;
	old_line_length = 0;
      } else {
	pointr(ptr1.cel, &x.sa);
	WITH = x.sad;   /* with */
	if (WITH->dtype == atom || WITH->dtype == idatom ||
	    WITH->dtype == fatom ||
	    WITH->dtype == tatom || WITH->dtype == keyword) {
	  pointa(WITH->name, bl801, &k);
	  FORLIM = k;
	  for (kk = 1; kk <= FORLIM; kk++)
	    s[kk - 1] = bl801[kk - 1];
	  old_line_length = k;
	  s[k] = new_line_code;
	} else {
	  s[0] = new_line_code;   /* other objects are ignored */
	  old_line_length = 0;
	}
      }  /* <>0 */
      next(&ptr1);

    }  /*=2*/
  }
_L99: ;


}





Static Void putatom_(j)
long j;
{
  /*************************/
  putit_(atom, j);
}


Static Void putit_(dd, j)
Char dd;
long j;
{
  /*************************/
  putatm(&s[i - 1], j, &aadr);
  dt = dd;
  saved_coord = getcoord_();
  tokennumber++;
}


Static Void putident_(j)
long j;
{
  /*************************/
  putit_(idatom, j);
}


Static Void putfloat_(j)
long j;
{   /*ignored*/
  /*************************/
  double rea_val;
  long ii, kk;
  real_char reac;
  Char STR1[256];

  sprintf(STR1, "%.*s", (int)j, s + i - 1);
  val2(STR1, &rea_val, &ii);
  ii = sizeof(double);

  for (kk = 0; kk < ii; kk++)
    reac[kk] = ((Char *)(&rea_val))[kk];


  putatm(reac, ii, &aadr);
  dt = fatom;
  saved_coord = getcoord_();
  jnc_(&tokennumber);
}


Static Void putnumber_()
{
  /*************************/
  dt = number;
  saved_coord = getcoord_();
  jnc_(&tokennumber);
}


Static Void putstr_(dd)
Char dd;
{
  /*************************/
  if (str_constlen > 80) {
    str_constlen = 80;
    dt = keyword;   /* too long string constant */
    er_lex_(10L);
  } else
    dt = dd;
  putatm(str_const, str_constlen, &aadr);
  in_string = false;
  tokennumber++;


  if (str_constlen == 0)
    dt = dummy;
  /* string constants of 0 length are converted to null*/


}


/* Local variables for scaner_mif: */
struct LOC_scaner_mif {
  string80 options_str;
} ;

/*inner function*/
Local boolean setop(c, LINK)
Char c;
struct LOC_scaner_mif *LINK;
{
  boolean Result;
  char * tmp;
  Result = false;
  tmp=strchr(LINK->options_str,c);

  if ( tmp ) {
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



Void scaner_mif(mode_parm, filename_, options_str_, rez, erlist_parm, strlist,
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
  struct LOC_scaner_mif V;
  string80 filename;


  strcpy(filename, filename_);
  strcpy(V.options_str, options_str_);
  read_mode = mode_parm;   /* save for global use */
  *rez = null_;
  *erlist_parm = null_;
  errlist = null_;   /* global */

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


  /* initializes language-specific settings */
  setlexics_();

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

  if (read_mode == 1) {  /* read from file */
    if (!existfile(filename)) {
      *rez = 0;
      goto _L1;
    }

    inpfile = fopen(filename, "r");
    if (inpfile == NULL)
     _EscIO(FileNotFound);

    readline_();   /* reads first line of file */
  } else {
    if (read_mode == 2) {  /* read from list */
      if (strlist == null_) {
	*rez = 0;
	goto _L99;
      }
      first(strlist, &ptr1);   /* sets global list-pointer ptr1 */
      if (ptr1.ptrtype != ptrlist || ptr1.nel == 0) {
	*rez = 0;
	goto _L99;
      }
      readline_();   /* reads line from current list-pointer position */
      /* read from ms-dos ram memory */

    }
  }



  read_file_(rez);   /* main call ... */

  *erlist_parm = errlist;   /*global*/
_L1:
_L99: ;
}  /* scaner */


Static Void setlexics_()
{
  /*************************/
  long j, FORLIM;

  as['<'] = is_control;
  as['>'] = is_control;
  goto _L99;

  /* changes in standard, necessary for pascal*/
/* p2c: scanmif.pas: Note: Deleting unreachable code [255] */
  /* used to process <<= */
  /* used to process >>= */
  /* used to process / *  */
  /* otherwise isa:=is_first_of_two
     is assigned ! */

_L99: ;
}




Static Void stradd_(c)
Char c;
{
  /*************************/
  if (str_constlen > 80)   /* string is truncated */
    er_lex_(10L);
  else
    jnc_(&str_constlen);
  str_const[str_constlen - 1] = c;
}


Static Void strbegin_()
{
  /********************/
  saved_coord = getcoord_();
  /* it will be used when putstr_ works and token_ exits - in read_item_*/
  in_string = true;
  str_constlen = 0;
}





Static Void token_()
{   /* variant record ,b1=b2[1]=b3[1]; b2[2]=b3[2] */
  /**********************/
  long j, i_saved;   /* positions */
  long FORLIM;

  /* at beginning time
     "i" - is already set to character in string "s";
     array "as" is already initialized;
     coordinate mode "coord_mode" is already known;
  */

_L1:   /* we return to this label if token_ is not ready still */

  b123.b1 = s[i - 1];
  isa = as[b123.b1];   /* type of this character */


  if (isa == is_control) {  /*1*/
      if (b123.b1 == new_line_code) {
          readline_();          /* skips to next line, sets new "s" and "i" */
          if (in_string) {
              /* This place modified 13/9/95 */
              if (str_constlen == 81) /*An atom just have been produced last time and buffer is empty */
              {str_constlen = 0;
               goto _L1;
           }
              else
              {
                  putstr_(atom); /* newline serves as end of atom*/
                  strbegin_();  /*initializes buffer */
                  is_2quote = false;
                  goto _L99;    /*next time we contiue to read from the string*/
              }
          }
          
          /* End of modified place */
          goto _L1;
      }
          /*never here*/
          if (b123.b1 == endfile_code) {
              if (in_comment)
                  er_lex_(12L);
              /* error = end of file appears in comment */
              dt = eof_desk;
              goto _L99;
          }
    /* others are control characters; */
    /* they set "dt" field and then form rigal list/tree structure */

    if (!in_string) {  /*2*/
      if (in_comment) {
	er_lex_(13L);
	in_comment = false;
      }
      /* error = control char in comment */
      if (in_string) {
	er_lex_(14L);
	putstr_(keyword);
	goto _L99;
	/* will take control character next time */
      }
      /* error = control char in string */
      dt = cont_char_to_dt_(b123.b1);
      i++;
      if (dt == set_coord && as[s[i - 1]] == is_digit) {
	/* this control character sets coordinate to value given in input */
	coord_mark = take_digits_(&j);
	last_mark_byte_number = line_byte_number + i;
	i += j;
	goto _L1;   /* does not returns ! */

      }
      goto _L99;
    }  /*2*/

  }  /*1*/




  /* all the following executes after check of is_control */

  /*b3[1]:=s[i];*/
  /* this character */
  b123.b3[1] = s[i];   /* next */
  b123.b3[2] = s[i + 1];   /* next */

  if (in_comment)   /* check for end of comment */
  {  /*1*/
    /* we are in comment;
       here only comments that have some special end mark are processed */
    if (pascal_comment) {  /*2*/
      if (b123.b1 == '}') {
	jncx_(&i);
	in_comment = false;
	goto _L1;
      }



      if (!strncmp(b123.b2, "*)", 2)) {
	jnc2x_(&i, 2L);
	in_comment = false;
	goto _L1;
      }


    }  /*2*/
    else {
      if (c_comment) {  /*2*/
	if (!strncmp(b123.b2, "*/", 2)) {
	  jnc2x_(&i, 2L);
	  in_comment = false;
	  goto _L1;
	}
      }  /*2*/
    }
    jncx_(&i);
    goto _L1;
  }  /*1*/
  /*this part never appears in mif input, since there is no in_comment status*/



  if (in_string) {  /*1*/
    if (b123.b1 == '\'') {
      if (str_constlen == 81) {
	/*constant ends after special character or in 80 character*/
	strbegin_();   /*sets str_constlen to 0*/
	is_2quote = false;
      }

      putstr_(atom);
      jncx_(&i);
      goto _L99;
    }

    /*end if mif constant*/

/* THIS PIECE WAS INSERTED MANUALLY FOR
   BBS VERSION ! */

#ifdef bbs
/* BBS variant of processing:
    If \\ appears in MIF format, \ is included output atom;
       \>                        >
       \xd2                      "
       \xd4                      $B4
       \xd5                      '
    If \letters
       then new IDENT-atom is created. It contains only 'letters', without \
  */

    if (b123.b1 == '\\') {
      if (b123.b2[1] == '\\') {
	stradd_(b123.b2[1]);
	jnc2x_(&i, 2L);
	goto _L1;
      }
      if (b123.b2[1] == '>') {
	stradd_(b123.b2[1]);
	jnc2x_(&i, 2L);
	goto _L1;
      }
      if (b123.b2[1] == 'x' && b123.b3[2] == 'd' &&
	  (s[i + 2] == '5' || s[i + 2] == '4' || s[i + 2] == '2')) {
	switch (s[i + 2]) {

	case '2':
	  stradd_('"');
	  break;

	case '4':   /* you can choose symbol here */
	  stradd_('`');
	  break;

	case '5':
	  stradd_('\'');
	  break;
	}
	jnc2x_(&i, 4L);
	goto _L1;
      }
      /* unregistred control sequence */
      putstr_(atom);
      jncx_(&i);   /* symbol \ is ignored */
      in_string = true;
      str_constlen = 82;   /* special value, normally impossible */
      goto _L99;
    }


#else

   /* END OF MANUALLY INSERTED CODE */





    /* latex variant of processing:
       if any of control characters appears then a separate idatom with  such contents
          is created.
       if \x(n)(n)(space) then idatom with \x(n)(n) is created;
       if \t              then idatom t
          \b                          b
          \n                          n
          \\                          \\
          \>                          \>
          \(another letter)           \(another letter)

      empty mif strings are coded as null
      after and before idents additional nulls can appear sometimes
     */
    if (str_constlen == 83)
    {   /* special value for taking one character to next idatom */
      strbegin_();
      is_2quote = false;
      stradd_(b123.b1);
      putstr_(idatom);
      jncx_(&i);
      in_string = true;
      str_constlen = 81;   /* go to next part of the constant*/
      goto _L99;
    }
    if (str_constlen == 84)
    {   /* special value for taking two characters to next idatom */
      strbegin_();
      is_2quote = false;
      stradd_(b123.b1);
      stradd_(b123.b2[1]);
      putstr_(idatom);
      jnc2x_(&i, 2L);
      in_string = true;
      str_constlen = 81;   /* go to next part of the constant*/
      goto _L99;
    }

    if (str_constlen == 85) {
      /* special value for taking 4 characters to next idatom,
                               and ignoring one more after them */
      strbegin_();
      is_2quote = false;
      stradd_(b123.b2[0]);
      stradd_(b123.b2[1]);
      stradd_(b123.b3[2]);
      stradd_(s[i + 2]);
      putstr_(idatom);
      jnc2x_(&i, 5L);
      in_string = true;
      str_constlen = 81;   /* go to next part of the constant*/
      goto _L99;
    }

    if (b123.b1 == '*' || b123.b1 == '-' || b123.b1 == '_' ||
	b123.b1 == '<' || b123.b1 == '|' || b123.b1 == '>' ||
	b123.b1 == '~' || b123.b1 == '^' || b123.b1 == '`' ||
	b123.b1 == ']' || b123.b1 == '[' || b123.b1 == '}' ||
	b123.b1 == '{' || b123.b1 == '/' || b123.b1 == '&' ||
	b123.b1 == '%' || b123.b1 == '$' || b123.b1 == '#' ||
	b123.b1 == '@' || b123.b1 == '"' || b123.b1 == '!'
        || b123.b1 == ','
/*   b123.b1 == ',' is added in Pascal code in june-95; here in september-95 */
       )
   
       {
      if (str_constlen == 81)
	dt = dummy;
      else
	putstr_(atom);
      in_string = true;
      str_constlen = 83;
      /* special value for taking one character to next idatom */
      goto _L99;
    }

    if (b123.b1 == '\\') {
      if (b123.b2[1] == 'x') {
	if (str_constlen == 81)
	  dt = dummy;
	else
	  putstr_(atom);
	in_string = true;
	str_constlen = 85;   /*take 4 chars*/
	goto _L99;
      }
      if (b123.b2[1] == 'n' || b123.b2[1] == 'b' || b123.b2[1] == 't') {
	jncx_(&i);
	if (str_constlen == 81)
	  dt = dummy;
	else
	  putstr_(atom);
	in_string = true;
	str_constlen = 83;   /*take 1 char*/
	goto _L99;
      }
      if (str_constlen == 81)
	dt = dummy;
      else
	putstr_(atom);
      in_string = true;
      str_constlen = 84;   /*take 2 chars*/
      goto _L99;
    }



#endif
 /* MANUALLY INSERTED ENDIF ! */



    if (str_constlen < 80) {
      stradd_(b123.b1);
      jncx_(&i);
      goto _L1;
    }  /*normal case*/
    if (str_constlen == 82) {
      /* ****
      strbegin_;is_2quote:=false;
      stradd_(b3[1]);stradd_(b3[2]);stradd_(b3[3]);
      putstr_(idatom);
      ****/
      j = take_letters_();
      putident_(j);
      in_string = true;
      str_constlen = 81;   /* special value, normally impossible */
      i += j;

      goto _L99;
    }

    if (str_constlen == 80) {
      putstr_(atom);
      in_string = true;
      jnc_(&str_constlen);
      /*becomes 81; no shift in input performed, ends part of constant*/
      goto _L99;
    }
    if (str_constlen == 81) {
      /*immediately afrer previous case; starts next part of constant*/
      strbegin_();   /*sets str_constlen to 0*/
      is_2quote = false;
#ifdef bbs
      stradd_(b123.b1);
      jncx_(&i);
#else
#endif

      goto _L1;
    }

    /************************
      else   begin
             stradd_(b1);  jncx_(i);   goto 1; end ;
*************************/


  }  /*1*/
  if (b123.b1 == '`') {
    strbegin_();
    is_2quote = false;
    jncx_(&i);
    goto _L1;
  }
  /*starts new mif text constant*/
  if (b123.b1 == '#') {
    readline_();
    goto _L1;
  }  /*mif comment*/





  /* all the following executes after check for in_string & in_comment */

  if (isa == is_special) {  /*1*/
    if (pascal_comment) {  /*2*/
      if (!strncmp(b123.b2, "(*", 2)) {
	in_comment = true;
	jnc2x_(&i, 2L);
	goto _L1;
      }
      if (b123.b1 == '{' && b123.b2[1] != '$') {
	in_comment = true;
	jncx_(&i);
	goto _L1;
      }
    }  /*2*/
    else {
      if (c_comment) {  /*2*/
	if (!strncmp(b123.b2, "/*", 2)) {
	  in_comment = true;
	  jnc2x_(&i, 2L);
	  goto _L1;
	}
      }  /*2*/
      else {
	if (ada_comment) {  /*2*/
	  if (!strncmp(b123.b2, "--", 2)) {
	    readline_();
	    goto _L1;
	  }
	}  /*2*/
      }
    }

    if (pascal_string) {  /*2*/
      if (b123.b1 == '\'') {
	strbegin_();
	is_2quote = false;
	jncx_(&i);
	goto _L1;
      }
    }  /*2*/
    else {
      if (modula_string) {  /*2*/
	if (b123.b1 == '\'') {
	  strbegin_();
	  is_2quote = false;
	  jncx_(&i);
	  goto _L1;
	}
	if (b123.b1 == '"') {
	  strbegin_();
	  is_2quote = true;
	  jncx_(&i);
	  goto _L1;
	}
      }  /*2*/
    }
    if (pascal_lexics) {  /*2*/
      /* specially takes turbo pascal directive-comments */
      if (!strncmp(b123.b2, "{$", 2)) {  /*3*/
	j = 0;
	do {
	  jncx_(&j);
	} while (s[i + j - 1] != '}' && as[s[i + j - 1]] != is_control);
	if (s[i + j - 1] == '}')
	  jncx_(&j);
	putatom_(j);
	jnc2x_(&i, j);
	goto _L99;
      }  /*3*/

      /* additional symbols */
      if (b123.b1 == '#' || b123.b1 == '$' || b123.b1 == '%') {  /*3*/
	jncx_(&i);
	j = take_letters_();   /* starts from i-th position */
	i--;
	putatom_(j + 1);   /* takes token_ from i-th position */
	jnc2x_(&i, j + 1);
	goto _L99;
      }  /*3*/

    }  /*2*/
    else {
      if (c_lexics) {   /*2*/
	if (!strncmp(b123.b3, "<<=", 3) || !strncmp(b123.b3, ">>=", 3)) {
	  putatom_(3L);
	  jnc2x_(&i, 3L);
	  goto _L99;
	}
	isa = is_first_of_two;
	/* !! in c case <<, >>, >=, <=  will be tested further
	   in  two_char_symbols section, hence we go to there
	   using assignment to "isa" */

      }  /*2*/
      /* symbols=  > < */
      /* special cases for c language */

    }

  }  /*1*/
  /*this part never appears in mif input, since there is no is_special*/


  if (isa == is_space) {
    jncx_(&i);
    goto _L1;
  }

  if (isa == is_letter) {
    j = take_letters_();
    putident_(j);
    i += j;
    goto _L99;
  }


  if (isa == is_digit) {  /*1*/
    if (c_lexics) {  /*2*/
      /* additional symbols; here hex and octal numbers are saved as
         normal atoms */
      if ((b123.b1 == '0')
          &&
          ( 
            (as[b123.b2[1]] == is_letter)|| 
            (as[b123.b2[1]] == is_digit) || 
            (as[b123.b2[1]] == is_underscore)
          )
         ) 
      {  /*3*/
	jncx_(&i);
	j = take_letters_();   /* starts from i-th position */
	i--;
	putatom_(j + 1);   /* takes token_ from i-th position */
	jnc2x_(&i, j + 1);
	goto _L99;
      }  /*3*/
    }  /*2*/


    i_saved = i;   /* remember starting position */
    aadr = take_digits_(&j);

    if (j < 10 &&
	(s[i + j - 1] == '.' && s[i + j] == '.' ||
	 s[i + j - 1] != '.' && s[i + j - 1] != 'E' && s[i + j - 1] != 'e')) {
      putnumber_();
      jnc2x_(&i, j);
      goto _L99;
    }
    jnc2x_(&i, j);
    if (s[i - 1] == '.') {
      jncx_(&i);
      aadr = take_digits_(&j);
      jnc2x_(&i, j);
    }
    if (s[i - 1] == 'E' || s[i - 1] == 'e') {
      jncx_(&i);
      if (s[i - 1] == '-' || s[i - 1] == '+')
	jncx_(&i);
      aadr = take_digits_(&j);
      jnc2x_(&i, j);
    }
    j = i - i_saved;
    i = i_saved;   /* to set "i" to starting position */
    putfloat_(j);
    jnc2x_(&i, j);
    goto _L99;
  }  /*1*/

  if (isa == is_first_of_two) {  /*1*/
    if (strchr(set_of_second_of_two,(int)b123.b2[1])) {
       FORLIM = two_char_symbols_num;
      for (j = 0; j < FORLIM; j++) {
	if (b123.b2[0] == two_char_symbols[j][0] &&
	    b123.b2[1] == two_char_symbols[j][1]) {
	  putatom_(2L);
	  i += 2;
	  goto _L99;
	}
      }
    }
  }  /*1*/

  putatom_(1L);
  jncx_(&i);   /* with*/
_L99: ;







}



Static long take_letters_()
{
  /****************************************/
  long Result;
  /* reads only letters, digits and underscores.
     returns number of characters read */

  long jj;
  Char c;

  jj = 0;
  while (true) {
    c = s[i + jj - 1];
    isa = as[c];
    if (isa != is_letter && isa != is_digit && isa != is_underscore) {
      Result = jj;
      goto _L99;
    }
    if (to_uppercase)
      s[i + jj - 1] = upcase_tab[c];
    jncx_(&jj);
  }
_L99:
  return Result;
}




Static long take_digits_(jj)
long *jj;
{
  /**************************************************/
  long Result;
  longint summator;
  Char c;

  *jj = 0;
  summator = 0;
  while (true) {
    c = s[i + *jj - 1];
    if (as[c] != is_digit) {
      Result = summator;
      goto _L99;
    }
    summator = summator * 10 + c - '0';
    jncx_(jj);
  }
_L99:
  return Result;
}



/*begin*/
/* press f8 when debugging ! */
/*initialize_scan_variables;*/




/* End. */

