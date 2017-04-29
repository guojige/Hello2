#include "klist.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#if 0


// 1   ����ṹ�壬�����ں�����

struct student
{
	char name[32];
	int age;
	char sex;
	float score;
	struct list_head nextnode;
};



void list_insert(struct list_head *head, char *name, int age, char sex, float score)
{
	// 5 ����һ���ѽ��
	struct student *pstu = (struct student *)malloc(sizeof(struct student));
	strcpy(pstu->name, name);
	pstu->age = age;
	pstu->sex  = sex;
	pstu->score = score;
	// 6 ��ʼ��ָ�벿��
	INIT_LIST_HEAD(&(pstu->nextnode));
	// 7 ��ָ�벿�ָ�����ͷ����
	list_add(&(pstu->nextnode), head);
	//list_add_tail(struct list_head * newnode,struct list_head * head)
}

int main(int argc, char *argv[])
{
	// 2 �����ں�����ͷ
	struct list_head stu_head;
	// 3 ��ʼ���ں�����ͷ 
	INIT_LIST_HEAD(&stu_head);  // ptr
	// 4 ���µ����ݲ�������
	list_insert(&stu_head, "guojige", 18, 'F', 59.5);
	list_insert(&stu_head, "guojige2", 182, 'M', 59.5);


	// 8 �������� stu_head,
	// ͨ��pos ȥ���� stu_head��ÿ���ڵ�(ֻ����ָ�벿��)
	// �ֲ�==> ���� nextnode =>  student
	struct list_head *pos;
	struct student *pstu;
	list_for_each(pos,&stu_head)
	{
		pstu = list_entry(pos,struct student,nextnode);
		printf("%s,%d,%c,%f\n", pstu->name, pstu->age,pstu->sex, pstu->score);
		//list_del_init(&pstu->nextnode);
	}
	
}


#endif 


#if 0


struct list
{
	int data;
	struct list *prev;
	struct list *next;
};

struct klist 
{
	int data;
	struct list_head listnode;
};




int main(int argc, char *argv[])
{

	struct list_head mylist;
	INIT_LIST_HEAD(&mylist);//��ʼ������ͷ:  ָ�벿��

	struct klist A;		//���ݽڵ�
	A.data = 1;
	INIT_LIST_HEAD(&(A.listnode));
	list_add_tail(&A.listnode , &mylist);  //��ָ�벿�ֲ�������

	struct klist B;		//���ݽڵ�
	A.data = 2;
	INIT_LIST_HEAD(&(B.listnode));
	list_add_tail(&B.listnode , &mylist);

	struct list_head *pos;
	struct klist *p;
	list_for_each(pos, &mylist)
	{
		p=list_entry(pos, struct klist, listnode); //ͨ��struct klist �ĳ�Աlistnode��������ṹ��
		printf("data=%d\n", p->data);
	}
	
	list_del(&A.listnode);
	list_for_each(pos, &mylist)
	{
		p=list_entry(pos, struct klist, listnode); //ͨ��struct klist �ĳ�Աlistnode��������ṹ��
		printf("data=%d\n", p->data);
	}
	
	list_del(&B.listnode);
	list_for_each(pos, &mylist)
	{
		p=list_entry(pos, struct klist, listnode); //ͨ��struct klist �ĳ�Աlistnode��������ṹ��
		printf("data=%d\n", p->data);
	}
	
	return 0;
}


#endif 


