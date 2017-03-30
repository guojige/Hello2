#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define LEN 640
void array_init(int arr[], int size);
void select_sort(int array[], int size);
void array_display(int arr[], int size);

int main()
{

	int array[LEN];
	array_init(array, LEN);
	select_sort(array, LEN);
	array_display(array, LEN);
	return 0;
}
void array_init(int arr[], int size)
{
	srand(time(0));
	// init
	int i;
	for(i=0; i<size; i++)
		arr[i] = random() % 10000;


}
void select_sort(int array[], int size)
{
	// sort
	int i; 
	int max;
	int index;
	int temp;
	int step = size;
	for(step=size; step>0; step--)
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

}
void array_display(int arr[], int size)
{
	// display
	int i;	
	for(i=0; i<size; i++)
		printf("arr[%d] = %d\n", i, arr[i]);
	
}
