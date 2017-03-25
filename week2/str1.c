#include <stdio.h>
#include <string.h>

int main()
{

	char str1[20], str2[20];
	scanf("%s%s", str1, str2);
	//gets(str1);
	//gets(str2);
	puts(str1);
	puts(str2);

#if 0	
	printf("%d,%d\n", strlen(str1), strlen(str2));
	strcat(str1,str2);  //  str1 = str1+str2 
	puts(str1);
#endif 
	printf("cmp=%d\n", strcmp(str1, str2)); // -1 0 1 

	strcpy(str1, str2);   // str1 = str2
	puts(str1);

	printf("pos=%s\n", strchr(str1, 'x'));
	printf("pos=%s\n", strrchr(str1, 'x'));

	return 0;
}
