#include <stdio.h>

int main()
{
	FILE *fp;
	FILE *fpw;
	char ch;

	fp = fopen("file.txt", "r");
	fpw =	fopen("txt.file", "w");

	int ret ; 
while(1)
{
	ret = fscanf(fp, "%c", &ch);
	printf("ret = %d\n", ret);
	if(ret == -1)
		break;
	printf("%c\n", ch);
	fprintf(fpw ,"%c",  ch);
}	//fprintf(stdout ,"%c",  ch);
	
	/*
	fscanf(fp, "%c", &ch);
	printf("%c\n", ch);
	fprintf(fpw ,"%c",  ch);

	fscanf(fp, "%c", &ch);
	printf("%c\n", ch);
	fprintf(fpw ,"%c",  ch);

  //scanf(        "%c", &ch);
	fscanf(stdin, "%c", &ch);
	printf("%c\n", ch);
	*/
	fclose(fp);
	fclose(fpw);

	return 0;
}
