#include <stdio.h>

int mystrlen(char str[]);

int main()
{
	printf("%d\n", mystrlen("11234abc"));
	printf("%d\n", mystrlen("1123"));
	char s[10] = {'\0'};
	printf("%d\n", mystrlen(s));

	return 0;
}




int mystrlen(char str[])
{

	int i=0;
	while(str[i] != '\0') 
			i++;
	return i;
}
