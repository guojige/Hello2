#include <stdio.h>
#include <stdlib.h>

typedef struct list
{
	int data;
	//void  *next;
	struct list *next;
}list_t;


int main()
{

#if 0
	char chr[] = {0x41, 0x42, 0x43, 0x44, 0x45, 0x46, 0x47, 0x48};
	char *p = chr;
	printf("size:%d,%d\n", sizeof(p), sizeof(*p));
	short *s = (short *)p;
	printf("addr:%p,%p\n", s, p);
	printf("size:%d,%d\n", sizeof(s), sizeof(*s));
	printf("*s = 0x%x\n", *s);
#endif 	
	printf("size:%d\n", sizeof(list_t));

	list_t A, B, C, D;
	A.data = 1;
	B.data = 3;
	C.data = 5;
	D.data = 7;

	A.next = &B;
	B.next = &C;
	C.next = &D;
	D.next = NULL;

	list_t *head = &A;

	printf("A.data = %d\n", head->data);
	printf("head:%p,&A:%p\n", head, &A);
	printf("head->next:%p, A.next:%p, &B:%p\n", head->next, A.next, &B);


	list_t *p ;
	p = head;
	while(p!=NULL)
	{
		printf("data:%d\n", p->data);
		p=p->next;	
	}


	list_t E;
	E.data = 2;
	E.next = NULL;
	
	E.next = &B;
	A.next = &E;
	
	p = head;
	while(p!=NULL)
	{
		printf("data:%d\n", p->data);
		p=p->next;	
	}

	list_t F;
	F.data = 4;
	F.next = NULL;
	list_t *newnode = &F;

	p = head;
	list_t *pre = head;
	while(p!=NULL)
	{
		if(newnode->data < p->data)
			break;
		pre = p;
		p=p->next;	
	}
	printf("p->data:%d\n", p->data);
	printf("pre->data:%d\n", pre->data);
	newnode->next = p;
	pre->next = newnode;

	
	p = head;
	while(p!=NULL)
	{
		printf("data:%d\n", p->data);
		p=p->next;	
	}



#if 0	
	printf("%p,%p\n", p , &A);
	printf("data:%d\n", p->data);

	p=p->next;
	printf("%p,%p\n", p , &B);
	printf("data:%d\n", p->data);
	
	p=p->next;
	printf("%p,%p\n", p , &C);
	printf("data:%d\n", p->data);
	
#endif
















	return 0;
}
