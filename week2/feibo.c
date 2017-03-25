#include <stdio.h>

int main()
{

#if 0
	int arr[20] = {1,1};
	int i;
	for(i=2; i<=20; i++)
		arr[i] = arr[i-1] + arr[i-2];
	
	for(i=0; i<20; i++)
		printf("arr[%d]= %d\n", i, arr[i]);

	arr[20] = 11;
#endif 	
	//int s;
	//printf("hello\n", s);
	//
	

	int arr[4] = {1,2,3,4};
	int x =-10;
	int y = -20;
	int i;
	for(i=0;i<=4; i++)
		arr[i] = 2*arr[i];

	for(i=0; i<=4; i++)
		printf("arr[%d]= %d\n", i, arr[i]);


	return 0;
}
