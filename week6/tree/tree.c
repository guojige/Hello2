#include "tree.h"


void pre_order(tree_t *root)
{
	if(root != NULL)
	{
		printf("%c\n", root->data);
		pre_order(root->left);
		pre_order(root->right);
	}
}
void mid_order(tree_t *root)
{
	if(root != NULL)
	{
		mid_order(root->left);
		printf("%c\n", root->data);
		mid_order(root->right);
	}
}

void post_order(tree_t *root)
{
	if(root != NULL)
	{
		post_order(root->left);
		post_order(root->right);
		printf("%c\n", root->data);
	}
}







