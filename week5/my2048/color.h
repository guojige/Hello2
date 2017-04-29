#ifndef __COLOR_H__
#define __COLOR_H__

#include <stdio.h>

#define SPACE()         printf("      ")
#define RED(val)        printf("\033[31;1m%3d   \033[0m", val)
#define GREEN(val)      printf("\033[32;1m%3d   \033[0m", val)
#define YELLOW(val)     printf("\033[33;1m%3d   \033[0m", val)
#define BLUE(val)       printf("\033[34;1m%3d   \033[0m", val)
#define PURPLE(val)     printf("\033[35;1m%3d   \033[0m", val)
#define DEEPGREEN(val)  printf("\033[36;1m%3d   \033[0m", val)

void print_number(int val);

#endif
