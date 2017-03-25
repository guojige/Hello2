#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int cmp(const void *a, const void *b)
{
	return *(char *)a - *(char *)b;
}



int main()
{
	char str[64];
	scanf("%s", str);
	int arr[5] = {11, 89, 1, 4, 3} ;
	qsort(str, strlen(str), 1, cmp);
	qsort(arr, 5, 4, cmp);

	puts(str);
	int i;
	for(i=0; i<5; i++)
		printf("%d\n", arr[i]);
	return 0;
}
