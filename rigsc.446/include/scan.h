extern Void initialize_scan_variables PV();

/*******************************************/
/*1=from file,2=list of strings,3=absulute address*/
/* result; set to null if input is absent */
/* error number list; set to null if no error*/
/* list of atoms */
extern Void scaner PP((long mode_parm, Char *filename, Char *options_str,
		       long *rez, long *erlist_parm, long strlist, long segm,
		       long ofs));

extern Void initialize_scan_variables_mif PV();

/*******************************************/
/*1=from file,2=list of strings,3=absulute address*/
/* result; set to null if input is absent */
/* error number list; set to null if no error*/
/* list of atoms */
extern Void scaner_mif PP((long mode_parm, Char *filename, Char *options_str,
		       long *rez, long *erlist_parm, long strlist, long segm,
		       long ofs));


