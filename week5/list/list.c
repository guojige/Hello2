#include "list.h"

void  list_display(list_t *head)
{
	if(head == NULL)
		return ;
	
	list_t *p = head;
	while(p!=NULL)
	{
		printf("%d\n", p->data);
		p = p->next;
	}	
	
}

#if 0
void list_insert(list_t *head, int value)
{

	//list_t node;   cannot use stack space
	//node.data = value;
	//node.next = NULL;
	
	list_t *newnode = (list_t *)malloc(sizeof(list_t));
	newnode->data = value;
	newnode->next = NULL;

	newnode->next = head;
	head  = newnode;

}
#endif
list_t *list_insert(list_t *head, int value)
{

	//list_t node;   cannot use stack space
	//node.data = value;
	//node.next = NULL;
	
	list_t *newnode = (list_t *)malloc(sizeof(list_t));
	newnode->data = value;
	newnode->next = NULL;

	newnode->next = head;
	head  = newnode;
	return head;
}
list_t *list_insert_last(list_t *head, int value)
{
	list_t *p, *pre;
	p = head;
	pre = head;
	while(p!=NULL)
	{
		pre = p;
		p = p->next;
	}
	
	list_t *newnode = (list_t *)malloc(sizeof(list_t));
	newnode->data = value;
	newnode->next = NULL;
#if 0
	printf("111\n");
	pre->next = newnode;
	printf("222\n");
#endif 
	if(pre == NULL)
		head = newnode;
	else
		pre->next = newnode;

	return head;
}


list_t *list_delete(list_t *head, int value)
{
	if(head == NULL)
		return head;
	list_t *p;
	p = head;
	list_t *pre = head;
	while(p!=NULL)
	{
		if(p->data == value)
			break;
		pre = p;
		p = p->next;
	}

	if(p == NULL) // not found
		return head;
	/// found
	if(p == head)
	{
		head = head->next;
	}
	else
	{
		pre->next = p->next;
	}
	free(p);
	p = NULL;
	return head;

}

























