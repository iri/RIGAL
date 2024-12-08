#include "globrig.h"
#include "define.h"
#include "defpage.h"
#include "ley.h"
#include "nef2.h"

main(argc, argv) int argc;
Char *argv[];
{
  string80 s;
  a a1;

  out = NULL;
  if (argc > 1)
  {
    strcpy(s, argv[1]);
    brt(s);
    if (existfile(s))
    {
      max_printlevel = max_printconst;
      opena();
      opens('&');
      init_dinform();
      loads(s, &a1);
      pscr(a1);
    }
    else
      printf("Error: file %s not found\n", s);
  }
  else
    printf("Usage:  v filename\n");
  if (out != NULL)
    fclose(out);
  exit(0);
}

/* End. */
