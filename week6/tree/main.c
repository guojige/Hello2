#include "tree.h"

tree_t *create_tree_node(char ch)
{
	tree_t *newnode = (tree_t *)malloc(sizeof(tree_t));
	newnode->data = ch;
	newnode->left = NULL;
	newnode->right = NULL;
	return newnode;
}

tree_t *create_static_tree()
{
	tree_t *A,*B,*C,*D,*E,*F;
	
	A = create_tree_node('A');
	B =	create_tree_node('B');
	C = create_tree_node('C');
	D = create_tree_node('D');
	E =	create_tree_node('E');
	F = create_tree_node('F');

	tree_t *root = A;
	
	A->left=B;
	A->right=C;

	B->left = NULL;
	B->right = NULL;

	C->left = D;
	C->right = E;

	D->left = F;
	D->right = NULL;

	E->left = NULL;
	E->right = NULL;

	F->left = NULL;
	F->right = NULL;

	return root;
}

int main()
{
	
	tree_t *root = create_static_tree();	
	printf("pre oder\n");
	pre_order(root);
	printf("mid oder\n");
	mid_order(root);
	printf("post oder\n");
	post_order(root);

	return 0;
}


