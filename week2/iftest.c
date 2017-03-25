#include <stdio.h>



int main()
{
	/*
	char ch;
	printf("input a character...");
	scanf("%c", &ch);
	if(ch<32)  //ASCII
		printf("%c is control character\n", ch);
	else if(ch>='0' && ch <= '9')
		printf("%c is digital character\n", ch);
	else if(ch>=65 && ch<'A'+26)
		printf("%c is a capital letter\n", ch);
	*/
	int a,b;
	scanf("%d,%d", &a, &b);
	if(a!=b)
	{
		if(a>b)
			printf("%d > %d\n",a, b);
		else 
			printf("%d < %d\n", a, b);
	}
	else
	{
		printf("%d == %d\n",a , b );
	}
	
	/*
	if(a==b)
	else if(a>b)
	else if(a<b)
	*/
	
	
	
	
	
	
	
	return 0;
}




