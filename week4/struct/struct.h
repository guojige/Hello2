#ifndef __STRUCT_H__
#define __STRUCT_H__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#pragma pack(1)

#define BUFFLEN  20

struct student
{
	char name[BUFFLEN];
	char sex;
	int num;
	//short age;
	//char sex;
	float score;
	short age;
};
union ustudent
{
	char name[BUFFLEN];
	char sex;
	int num;
	//short age;
	//char sex;
	float score;
	short age;
};


typedef struct candidate
{
	char *name;
	int cnt;
}candidate_t;

//  struct student s1, s2;


// rename
typedef struct student student_t;

extern void struct_test1();
extern void struct_test2();
extern void struct_test3();
extern void struct_test5();



candidate_t  *candidate_init(int len);
void candidate_vote(candidate_t *pcan, int len, char *name);
void candidate_disp(candidate_t *pcan, int len);
void candidate_desotry(candidate_t *pcan, int len);



#endif
