#include <stdio.h>

#define N 11

int main()
{
	int arr[N][N] = {1};
	int idir=1;
	int jdir=-1;
	int i=0,j=0;
	int ipos;
	int jpos;
	int cnt=2;
	for(cnt=2;cnt<=N*N;cnt++)
	{
		ipos = i+idir;
		jpos = j+jdir;
		if(jpos<0 && ipos < N){  // fix here
			ipos = i+1;  //down
			jpos = j;
			idir *= -1;
			jdir *= -1;
		}		
		else if(ipos<0)
		{
			ipos = i;
			jpos = j+1;  // right
			idir *= -1;
			jdir *= -1;
		}
		else if(ipos>=N)
		{
			ipos = i;
			jpos = j+1; // right	
			idir *= -1;
			jdir *= -1;
		}
		else if(jpos>=N)
		{
			ipos = i+1; // down
			jpos = j;
			idir *= -1;
			jdir *= -1;

		}
		arr[ipos][jpos] = cnt;
		i = ipos;
		j = jpos;
	}
	for(i=0; i<N; i++)
	{
		for(j=0; j<N; j++)
		{
			printf("%4d", arr[i][j]);
		}
		printf("\n");
	}
	return 0;
}
