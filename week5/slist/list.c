#include "list.h"

void  list_display(list_t *head)
{
	if(head == NULL)
		return ;
	
	list_t *p = head;

	do{
		printf("%d\n", p->data);
		p = p->next;	
	}while(p!=head);
	

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
		
	list_t *newnode = (list_t *)malloc(sizeof(list_t));
	newnode->data = value;
	newnode->next = NULL;

	if(head==NULL)
	{
		head = newnode;
		head->next = head;
		return  head;
	}

	list_t *p, *pre;
	
	p = head->next;
	pre = head;

	while(p != head )
	{
		pre = p;
		p = p->next;
	}

	newnode->next = p;
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

























