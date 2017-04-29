#ifndef __TREE_H__
#define __TREE_H__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct tree
{
	char data;
	struct tree *left;
	struct tree *right;
}tree_t;


extern void  pre_order(tree_t *root);
extern void  mid_order(tree_t *root);
extern void  post_order(tree_t *root);



#endif 
