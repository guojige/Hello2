#include <stdio.h>

#define PI	3.1415926
#define NUM 6
#define STR  "HELLOWORLD"
#define MAX(x,y)  x>y?x:y
//#define MUL(x,y)  x * y
#define MUL(x,y)  (x) * (y)

int mymul(int x, int y)
{
	return x * y;
}

int main()
{
	int r= 2;
	double area;
	
	area = PI * r * r;
	int array[NUM];
	int i;
	for(i=0; i<NUM; i++)
			;
	puts(STR);

	printf("%d\n", MAX(1,3));
	printf("%d\n", MUL(3,8));
	printf("%d\n", MUL(3+3,8+8));
	printf("%d\n", mymul(3+3,8+8));
			
	return 0;
}


