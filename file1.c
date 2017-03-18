#include <stdio.h>  //  FILE *   (stdin     stdout)


int main()
{
	/*
	FILE *fp;
	fp = fopen("test.txt", "w");
	// printf("helloworld")
	fprintf(fp,"helloworld111\n");
	fprintf(stdout,"helloworld222\n");
	fclose(fp);
	*/
	char str[100];
	char ch;
	FILE *fp2;
	fp2 = fopen("test.txt", "r");
	int pos;
	pos = ftell(fp2);
	printf("pos=ast%d\n", pos);
	fscanf(fp2, "%c", &ch);
	pos = ftell(fp2);
	printf("pos=%d\n", pos);
	//fscanf(fp2, "%s", str);
	//printf("resutl:%s\n", str);
	fclose(fp2);
	
	return 0;
}
