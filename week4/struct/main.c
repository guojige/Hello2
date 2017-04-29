#include "struct.h"

//#pragma pack(1)

int main(int argc, char *argv[])
{

	//struct_test1();
	//struct_test2();
	//struct_test3();
	//
		
	struct_test5();
	

#if 0	
	int num;
	printf("please input number of candidate\n");
	scanf("%d", &num);

	candidate_t *parr = candidate_init(num);


	char name[30];
	while(1)
	{
		printf("please input name of candidate\n");
		do{
			scanf("%s", name);
		}while(name[0] == '\n');
		
		if(strcmp(name, "exit") == 0)
			break;
		candidate_vote(parr, num, name);
		//candidate_disp(parr, num);
	}

	candidate_disp(parr, num);
	candidate_desotry(parr, num);
	parr = NULL;
#endif 
	return 0;
}
