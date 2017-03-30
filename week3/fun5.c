#include <stdio.h>
#include "log.h"

int log_level = 6;

int dec1(int num)
{
	//int num=10;
	int res;
	while(1)
	{
		if(num==0)
			break;
		res = num % 2;
		printf("%d", res);
		num /= 2;	
	}

}

int dec2(int num)
{

	if(num==0)
		return ;
	int res;
	res = num % 2;
	SPIDER_LOG(SPIDER_LEVEL_DEBUG, "res:%p,%d,num=%d\n", &res, res, num);
	//printf("%d", res);
	num /= 2;
	dec2(num);
	printf("%d", res);
}

int main()
{
	SPIDER_LOG(SPIDER_LEVEL_DEBUG, "%s\n", "ENTER main");
	dec2(10);
	return 0;
}


