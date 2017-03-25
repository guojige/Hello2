#include <stdio.h>
#define NUM 11
int main()
{
	int i=0, j=0;
	int arr[NUM][NUM]={0};
	int count = 1;
	int N=NUM;
	int s=0;
for(s=0; s<(N/2+1) ; s++)
{
	for(; j<N-1-s; j++)
		arr[i][j] = count++;
	//j--;  // back
	printf("i=%d,j=%d\n", i, j);

	for(; i<N-1-s; i++)
		arr[i][j] = count++;
	printf("i=%d,j=%d\n", i, j);

	for(; j>s; j--)
		arr[i][j] = count++;
	printf("i=%d,j=%d\n", i, j);

	for(; i>s+1; i--)
		arr[i][j] = count++;		
	printf("i=%d,j=%d\n", i, j);
}
	arr[i][j] = N*N;
	/*
//---------------------------------------
	for(; j<5; j++)
		arr[i][j] = count++;
	//j--;  // back
	printf("i=%d,j=%d\n", i, j);

	for(; i<5; i++)
		arr[i][j] = count++;
	printf("i=%d,j=%d\n", i, j);

	for(; j>1; j--)
		arr[i][j] = count++;
	printf("i=%d,j=%d\n", i, j);

	for(; i>2; i--)
		arr[i][j] = count++;		
//--------------------------------------------
	*/
	for(i=0; i<NUM; i++)
	{
		for(j=0; j<NUM; j++)
		{
			if(arr[i][j] !=0 )
				printf("%4d", arr[i][j]);
			else
				printf("    ");
		}
		printf("\n");
	}

	return 0;
}
