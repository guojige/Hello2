#include <stdio.h>

#define PRICE  30

int main()
{
#if 0	
	//PRICE = 10;   error
	int  price = 10;
	price = 20;
	price = 30;
	
	const int yy = 100;
	//yy = 20;      error
#endif 	

	int x=100;
	int y=200;
	printf("x/y addr:(no)%p,%p\n", &x, &y);
	printf("x/y size:%d,%d\n", sizeof(x), sizeof(y));
	printf("x/y value:%d,%d\n",x, y);
	
	return 0;
}
