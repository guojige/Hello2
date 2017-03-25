#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
	srand(time(0));
	
	int array[10];
	
	// init
	int i;
	for(i=0; i<10; i++)
		array[i] = random() % 10000;

	// sort 
	int max;
	int index;
	int temp;
	int step = 10;
	for(step=10; step>0; step--)
	{
		max=array[0];
		index=0;
		
		for(i=1;i<step;i++)
		{
			if(max<array[i])
			{
				max = array[i];
				index = i;			
			}
		}

		temp = array[step-1];
		array[step-1] = array[index];
		array[index] = temp;
	}

	// display
	for(i=0; i<10; i++)
		printf("array[%d] = %d\n", i, array[i]);

	return 0;
}
