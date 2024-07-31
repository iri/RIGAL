#include <stdio.h>
#include <dos.h>
main (argc,argv)
 char * argv[];
 int argc;
 { FILE* ff;
   FILE * fi;
   int c,rez;
   char filnam[80];
   char newfilnam[80];
   struct find_t * buffer;
  _dos_findfirst(argv[1],_A_NORMAL,buffer);
  do

{
  strcpy(newfilnam,"a\\");
  strcat(newfilnam,buffer->name);
  printf("( %s - > %s )\n",buffer->name,newfilnam);
/*  getch(); */
  ff=fopen(newfilnam,"wb");
  fi=fopen(buffer->name,"rt");
  while ((c=fgetc (fi)) != EOF)
   if ((c>=32)||(c=='\t')||(c=='\n'))
   { /*printf ("%d ",c);*/
     fputc(c,ff);
   }
 fputc(0,ff);
 fclose(ff);
 fclose(fi);
 rez=_dos_findnext(buffer);
 printf ("rez=%d\n",rez);
}
 while( rez==0);

}
