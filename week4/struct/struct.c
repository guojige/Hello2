#include "struct.h"


void struct_test1()
{
	student_t s1;
	struct student s2;
	printf("size:%d,%d\n", sizeof(s1), sizeof(s2));
	printf("addr:%p,%p,%p, %p\n", &s1, s1.name, &s1.sex, &s1.num);
}
void struct_test2()
{
	student_t s1 = {"guojige", 'M', 1001, 59.9, 5};
	student_t s2;
	s2 = s1;
	printf("%s,%c,%d,%2f,%d\n", s2.name, s2.sex, s2.num, s2.score, s2.age);
}

static void pass_struct(student_t s1)
{
	printf("size:%d\n", sizeof(s1));
	
	printf("%s-addr:%p,%p,%p, %p\n", __FUNCTION__, &s1, s1.name, &s1.sex, &s1.num);
}
static void pass_pstruct(student_t *ps1)
{
	printf("%s,%c,%d,%2f,%d\n", ps1->name, ps1->sex, ps1->num, ps1->score, ps1->age);
	
}

void struct_test3()
{
	student_t s1 = {"guojige", 'M', 1001, 59.9, 5};
	printf("%s-addr:%p,%p,%p, %p\n",__FUNCTION__, &s1, s1.name, &s1.sex, &s1.num);
	pass_struct(s1);
	pass_pstruct(&s1);
}


candidate_t  *candidate_init(int len)
{
	candidate_t *pa = (candidate_t *)malloc(sizeof(candidate_t) * len);
	memset(pa, 0, sizeof(candidate_t)*len);
	int i;
	char name[30];
	for(i=0; i<len;i++)
	{
		//strcpy(pa[i].name, "ddd");  //error
		do{
			printf("input name of candidate:");
			scanf("%s", name);
			if(name[0] == '\n')
				continue;
			pa[i].name = (char *)malloc(strlen(name)+1);		
			strcpy(pa[i].name, name);
			break;
		}while(1);
	}

	return pa;


}
void candidate_vote(candidate_t *pcan, int len, char *name)
{
	int i;
	candidate_t *item = pcan;
	for(i=0; i<len; i++)
	{
		if(strcmp(item->name, name) == 0)			
		{
			item->cnt++;
			break;
		}
		else{
			item++;
		}
	}	
}
void candidate_disp(candidate_t *pcan, int len)
{
	if(NULL == pcan)  // if(pcan=NULL)
		return ;
	int i;
	for(i=0; i<len; i++)
	{
		printf("%s : %d\n", pcan[i].name, pcan[i].cnt);
	}

}


void candidate_desotry(candidate_t *pcan, int len)
{
	if(NULL == pcan)  // if(pcan=NULL)
		return ;
	int i;
	for(i=0; i<len; i++)
	{
		free(pcan[i].name);
		pcan[i].name = NULL;
	}
	free(pcan);
	
}


void struct_test5()
{
	student_t s1;
	union ustudent s2;
	printf("size:%d,%d\n", sizeof(s1), sizeof(s2));
}




















