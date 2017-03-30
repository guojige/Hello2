#ifndef __PTR_H__
#define __PTR_H__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LENGTH 9

extern void pointer_test1();
extern void pointer_test2();
extern void pointer_test3();
extern void pointer_test4();
extern void pointer_test5();
extern void pointer_test6();
extern void pointer_test7();
extern void pointer_test8();
extern void pointer_test9();
extern void pointer_test11();
//extern int  mystrlen(char str[]);
extern int  mystrlen(char *str);
extern int  mystrcmp(char *str1, char *str2);
extern void mystrcpy(char *dst, char *src);
extern void mystrcat(char str1[], char str2[]);



#endif
