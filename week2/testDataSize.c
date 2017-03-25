#include <stdio.h>



int main()
{
	//  127   127
	//  128  -128
	//  129  -127 
	//  -128 ~0 ~ 127 
	
	//char ch=129;
	/*
	short ch;
	printf("%d\n", ch);
	
	for(ch=0; ch<1000; ch++)
		printf("%c,%d\n", ch, ch);
	
	printf("abc\b123\n");
	*/
	
	
	int x=123456;
	char y=10;
	//x=y;
	//y = x;
	y=(char)x;
	printf("%d,%d\n", x, y);
	
	
	
	
	
	
	
	
	
	
	
	
	
	return 0;
}
