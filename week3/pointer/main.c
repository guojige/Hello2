#include "ptr.h"


void sort(int array[])
{
		
	printf("sort-size:%d\n", sizeof(array));
}


void pointer_test10()
{
	int arra[10] = {1,2,3,4};
	printf("1,size:%d\n", sizeof(arra));
	sort(arra);
	printf("2,size:%d\n", sizeof(arra));

}

int main(int argc, char *argv[])
{
	//pointer_test1();
	//pointer_test2();
	//pointer_test3();
	//pointer_test4();
	//pointer_test5();
	//pointer_test6();
	//pointer_test7();
	//pointer_test8();
	//pointer_test9();
	//pointer_test10();
	//pointer_test11();
	
	printf("argc = %d\n", argc);
	printf("argv[0] = %s\n", argv[0]);
	
	int i;
	for(i=0; i<argc; i++)
		printf("argv[%d] = %s\n", i,argv[i]);


	return 0;
}
