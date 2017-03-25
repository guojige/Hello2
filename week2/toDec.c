#include <stdio.h>

int main()
{
	int num = 0;
	int arr[100] = {0};
	int i=0;

	scanf("%d", &num);
	//while(num!=0)
	while(num)
	{
		arr[i++] = num % 2;
		num /= 2;
		//i++;
	}

	//  10 
	//  0101   =>  i next pos 
	int j;
	for(j=i-1; j>=0; j--)
		printf("%d", arr[j]);
	printf("\n");

	return 0;
}
