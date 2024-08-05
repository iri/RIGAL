/******* defpage.h *********/
extern Void opena PV();

/********* putatm input ad : address of first char
                       na : length of charstring
                 output e : a_pointer for this atom  **/
extern Void putatm PP((Char *ad, long na, long *e));

/********* pointa input  e : a_pointer
                 output ad: charstring
                        na: length of charstring     **/
extern Void pointa PP((long e, Char *ad, long *na));

extern Void savea PV();

extern Void closea PV();

extern Void opens PP((Char d_drive));

/********* loads  input  f : file specifikation string
                 output e : s_pointer of loud object **/
extern Void loads PP((Char *f, long *e));

/********* saves  input  f : file specification string
                        e : s_pointer of object to be saved
                 output none    ***********************/
extern Void saves PP((Char *f, long *e));

extern Void savesn PP((Char *f, long *e));

extern Void reopen PP((long *f, long *e));

/********* reopen        e  : old s_pointer
                        f  : new s_pointer */
/********* getsn  input none
                 output e1 : s_pointer of new memory
                        e2 : address of new memory   **/
extern Void gets1 PP((long *e1, long *e2));

extern Void gets2 PP((long *e1, long *e2));

extern Void gets5 PP((long *e1, long *e2));

/********* pointx input  e1 : s_pointer of object
                 output e2 : address of object       **/
extern Void points PP((long e1, long *e2));

extern Void pointr PP((long e1, long *e2));

/********* closes input none
                 output none                         **/
extern Void closes PV();

/********* voly  input none
                output k : number of disc reads
                       l : number of disc writes
                       m : number of pages on ddisc  **/
extern Void vola PP((long *dr, long *dw, long *dp));

extern Void vols PP((long *dr, long *dw, long *dp));


#define max_printconst  15
    /* will be assigned to max_printlevel in prologs */


FILE *out;   /* file used as print file */
boolean out_screen;   /* works pscr, not pout */
boolean out_open;   /* this file is open for output */
long max_printlevel;   /*  maximum level of nested prints */
Char vdname;   /* drive name used as ram disk , "winm-" only */


extern boolean existfile PP((Char *fname));

extern boolean rightfile PP((Char *fname));

extern Char *aa_str PP((Char *Result, long a1));

extern long long_to_atom PP((long a_long));

extern long str_to_atom PP((Char *ssr));
extern long str_to_textatom PP((Char *ssr));

extern Void val PP((Char *m, long *intval, long *rez));

extern Void init_dinform PV();

/*procedure argv(i:integer;var rez:string80); extern;
function argc:integer;             extern;*/
extern Char *long_to_str PP((Char *Result, long int_));

extern Char *real_to_string PP((Char *Result, double ar));

extern Void val2 PP((Char *st, double *r, long *code));

extern Char *real_to_string_f PP((Char *Result, double ar, long dignum,
				  long afterpoint));

extern Void brt PP((Char *p1));

extern boolean is_rig_letter PP((int));
extern boolean is_rig_symbol PP((int));
extern char* _OutMem PP((void));
extern Void  _EscIO  PP((int));



