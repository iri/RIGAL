/******** GLOBRIG.H ******/
#define Char    char
#define boolean char
#define Void    void
#define PP(x)   ()
#define PV()    ()
#define true    1
#define false   0
#define Static  static
#define Local   static
#define FileNotFound 1
	char* __M__;

#define Malloc(n)  ((__M__ = malloc(n)) ? __M__ : (char*)_OutMem())
#include <ctype.h>
#include <stdio.h>
#include <string.h>
#include <malloc.h>


