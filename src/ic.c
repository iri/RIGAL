#include "globrig.h"
#include "define.h"
#include "defpage.h"
#include "nef2.h"
#include "cim.h"
/* #include "usemod.h" */

a ttt, tt1, tt2, tt3, middle;
long arnum;
filespecification p1, p2, p3;
string80 printfile_str, sstr;
boolean debug;
long pp1, pp2, pp3, i;

main(argc, argv) int argc;
Char *argv[];
{
  out = NULL;
  out_open = false;
  debug = false;
  if (argc > 1)
  {
    strcpy(p1, argv[1]);
    brt(p1);
  }
  else
    *p1 = '\0';
  *printfile_str = '\0';

  if (*p1 == '\0')
  {
    printf(" Rigal Interpreter  V.%s\n", rigal_version);
    printf(" ic codefile [ -p printfilename ] [ -d ] [ parameter ...]\n");
    printf(" codefile must be without extension, .RSC is appended \n");
    if (*p1 == '\0')
      goto _L99;
  }

  init_dinform();
  opens('@');
  opena();

  for (i = 1; i < argc; i++)
  {
    strcpy(printfile_str, argv[(int)i]);
    brt(printfile_str);
    if (!strcmp(printfile_str, "-d"))
    {
      pp1 = i;
      debug = true;
      goto _L17;
    }
  }
_L17:

  *printfile_str = '\0';
  for (i = 1; i < argc; i++)
  {
    strcpy(sstr, argv[(int)i]);
    brt(sstr);
    if (!strcmp(sstr, "-p"))
    {
      pp2 = i;
      if (i <= argc - 2)
      {
        pp3 = i + 1;
        strcpy(printfile_str, argv[(int)(i + 1)]);
        brt(printfile_str);
        goto _L18;
      }
    }
  }
_L18:

  if (*printfile_str != '\0')
  {
    if (!rightfile(printfile_str))
    {
      printf(" Wrong PRINT file changed to Screen \n");
      *printfile_str = '\0';
    }
  }

  out_screen = (*printfile_str == '\0');
  out_open = !out_screen;
  if (out_open)
  {
    out = fopen(printfile_str, "w");
    if (out == NULL)
      _EscIO(FileNotFound);
  }

  max_printlevel = max_printconst;

  sprintf(p2, "%s.rsc", p1);

  if (!existfile(p2))
  {
    printf("\nERROR:  Code %s not found\n", p2);

    goto _L99;
  }
  loads(p2, &ttt);
  run_param_cnt = 0;
  for (arnum = 2; arnum < argc; arnum++)
  {
    if (arnum != pp1 && arnum != pp2 && arnum != pp3)
    {
      run_param_cnt++;
      strcpy(run_param_array[run_param_cnt - 1], argv[(int)arnum]);
      brt(run_param_array[run_param_cnt - 1]);
    }
  }

  int11(debug, ttt);
_L99:
  if (out != NULL)
    fclose(out);
  exit(0);
}

/* End. */
