#include <stdio.h>

int main()
{
	
	
#if 0
	char str2[] = {'h', 'e', 'l', 'l', 'o'};
	char str1[] = {'h', 'e', 'l', 'l', 'o'};
	char str3[] = {'x', 'e', 'l', 'l', 'o'};
	printf("size = %d\n", sizeof(str1));
	printf("%s\n", str1);

	char str4[] = "aello";
	char str5[] = {'h', 'e', 'l', 'l', 'o', '\0'};
	char str6[] = {'w', 'e', 'l', 'l', 'o', '\0'};
	printf("size = %d,%d\n", sizeof(str4), sizeof(str5));
	printf("%s\n", str5);

#endif

#if 0
	char str7[5] = {'H', 'E', 'L'};
   	int i;
	for(i=0; i<5; i++)
		printf("%c,%d\n", str7[i], str7[i])	;
	if(str7[3] == '\0')
		printf("\\0");

	printf("%s\n", str7);
#endif 

	char stra[2];
	char strb[3];
	
	scanf("%c%c", &stra[0], &stra[1]);
	printf("%c%c\n", stra[0], stra[1]);
	char ch;
	do{
		scanf("%c", &ch);	
	}while(ch == '\n');

	scanf("%c%c%c", &strb[0], &strb[1], &strb[2]);
	printf("%c%c%c\n",  strb[0], strb[1], strb[2]);
	



	return 0;

}
