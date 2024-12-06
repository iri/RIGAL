#include <malloc.h>
main ()
{
  int i=0;
  while(1)
   {  printf("Page=%d  Adr=%p\n",i++,malloc(10000));
      printf(" memmax=%ld, memavl=%ld\n",_memmax(),_memavl());
      getch();
   }
}

