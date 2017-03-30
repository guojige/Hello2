#ifndef __SRC_H__	
#define __SRC_H__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
  // 宏定义
#define  BUFFLEN  1024
  // 类型定义
typedef unsigned int uint32;
typedef unsigned char unit8;

  // 变量声明
extern int gval;

  //函数声明
extern int myadd (int x, int y);
extern int mysub (int x, int y);
extern int mymul (int x, int y);
extern int mydiv (int x, int y);

#endif
