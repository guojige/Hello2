#include <stdio.h>
#include <unistd.h>
int main()
{

	int i;
	char ch='x';
	for(i=0; i<104; i++)
		write(1, &ch, sizeof(ch));

#if 0
	int i;
	for(i=0; i< 1025; i++)
		printf("*");
#endif 
	while(1)
		;
}
