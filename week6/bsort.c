#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define LEN 1024000
void array_init(int arr[], int size);
void select_sort(int array[], int size);
void array_display(int arr[], int size);
void quick_sort(int arr[], int left, int right); // 0 , size-1
void merge_sort(int arr[], int left, int right);
int main()
{

	int array[LEN];
	array_init(array, LEN);
	//select_sort(array, LEN);
	//quick_sort(array, 0, LEN-1);
	merge_sort(array, 0, LEN-1);
	//array_display(array, LEN);
	return 0;
}
void array_init(int arr[], int size)
{
	srand(time(0));
	// init
	int i;
	for(i=0; i<size; i++)
		arr[i] = random();


}
static int temp[LEN];
static void merge(int arr[], int left, int mid, int right)
{
	int i=left;
	int j=mid+1;
	int t=left;
	while(i<=mid && j<=right)
	{
		if(arr[i] < arr[j])
			temp[t++] = arr[i++];
		else
			temp[t++] = arr[j++];
	}	
	while(i<=mid)
		temp[t++] = arr[i++];
	while(j<=right)
		temp[t++] = arr[j++];

	i = left;
	for(i=left; i<=right; i++)
		arr[i] = temp[i];
}

void merge_sort(int arr[], int left, int right)
{
	if(left>=right)
		return ;
	int mid = (left+right) / 2; // left...mid,  mid+1...right
	merge_sort(arr, left, mid);
	merge_sort(arr, mid+1, right);
	merge(arr, left, mid, right);
}

static int small[LEN];
static int big[LEN];
static int partion(int arr[], int left, int right)
{
	int i;
	int key = arr[left];
	int bi= 0;
	int si= 0;
	for(i=left+1; i<=right; i++)
	{
		if(arr[i]>key)	
			big[bi++] = arr[i];
		else 
			small[si++] = arr[i];
	}
	// samll key big
	i = left;
	int s;
	for(s=0; s<si; s++)
		arr[i++] = small[s];

	int index = i; // key index
	arr[i++] = key;

	int b=0;
	for(b=0; b<bi;b++)
		arr[i++] = big[b];

	return index;
}

void quick_sort(int arr[], int left, int right) // 0 , size-1
{ //  


	if(left>=right)
		return ;
	//int key = arr[left];
	int index=partion(arr, left, right); // left....index-1  < index < index+1....right
	quick_sort(arr,left, index-1);
	quick_sort(arr,index+1, right);

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
