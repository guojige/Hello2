#include <stdio.h>
#include <string.h>
int main()
{
	char str[20];
	gets(str);
	
	//puts(str);
	//
	int len;
	len = strlen(str);
#if 0
	int i;
	for(i=len-1; i>=0; i--)
		printf("%c", str[i]);
	puts("");
#endif 

	int i=0;
	int j=len-1;
	//int flag=1;
	while(i<j)
	{
		if(str[i] == str[j])
		{
			i++;
			j--;
		}
		else
		{
			//flag =0; 
			break;
		}
	}
	
	if(i>=j)
		printf("Yes\n");
	else
		printf("No\n");


	return 0;
}
