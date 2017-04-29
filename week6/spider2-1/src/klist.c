#include "klist.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#if 0


// 1   定义结构体，包含内核链表

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
	// 5 构造一个堆结点
	struct student *pstu = (struct student *)malloc(sizeof(struct student));
	strcpy(pstu->name, name);
	pstu->age = age;
	pstu->sex  = sex;
	pstu->score = score;
	// 6 初始化指针部分
	INIT_LIST_HEAD(&(pstu->nextnode));
	// 7 把指针部分跟链表头相连
	list_add(&(pstu->nextnode), head);
	//list_add_tail(struct list_head * newnode,struct list_head * head)
}

int main(int argc, char *argv[])
{
	// 2 定义内核链表头
	struct list_head stu_head;
	// 3 初始化内核链表头 
	INIT_LIST_HEAD(&stu_head);  // ptr
	// 4 把新的数据插入链表
	list_insert(&stu_head, "guojige", 18, 'F', 59.5);
	list_insert(&stu_head, "guojige2", 182, 'M', 59.5);


	// 8 遍历链表 stu_head,
	// 通过pos 去访问 stu_head的每个节点(只看到指针部分)
	// 局部==> 整体 nextnode =>  student
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
	INIT_LIST_HEAD(&mylist);//初始化链表头:  指针部分

	struct klist A;		//数据节点
	A.data = 1;
	INIT_LIST_HEAD(&(A.listnode));
	list_add_tail(&A.listnode , &mylist);  //把指针部分插入链表

	struct klist B;		//数据节点
	A.data = 2;
	INIT_LIST_HEAD(&(B.listnode));
	list_add_tail(&B.listnode , &mylist);

	struct list_head *pos;
	struct klist *p;
	list_for_each(pos, &mylist)
	{
		p=list_entry(pos, struct klist, listnode); //通过struct klist 的成员listnode获得整个结构体
		printf("data=%d\n", p->data);
	}
	
	list_del(&A.listnode);
	list_for_each(pos, &mylist)
	{
		p=list_entry(pos, struct klist, listnode); //通过struct klist 的成员listnode获得整个结构体
		printf("data=%d\n", p->data);
	}
	
	list_del(&B.listnode);
	list_for_each(pos, &mylist)
	{
		p=list_entry(pos, struct klist, listnode); //通过struct klist 的成员listnode获得整个结构体
		printf("data=%d\n", p->data);
	}
	
	return 0;
}


#endif 


