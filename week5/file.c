#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[])
{

	if(argc != 3)
	{
		printf("Usage: %s src dst\n", argv[0]);
		return -1;
	}

	FILE *fpr=NULL;
	FILE *fpw=NULL;

	fpr = fopen(argv[1], "r");
	//if(fpr=NULL)  
	if(NULL == fpr)
	{
		printf("%s: No such file or directory\n", argv[1]);
		return -2;
	}
	fpw = fopen(argv[2], "w");
	if(NULL == fpw)
	{
		printf("open file %s error\n", argv[2]);
		fclose(fpr);
		return -3;
	}

#if 0	
	char buff[1024];
	char *p;
	while(1)
	{
		p = fgets(buff, 1024, fpr);
		if(NULL == p)
			break;
		fputs(buff, fpw);
	}
#endif 

	char buff[32];
	int cnt;
	while(1)
	{
		cnt=fread(buff, 1, 32, fpr);
		if(cnt == 0)
			break;
		printf("cnt=%d\n", cnt);
		fwrite(buff, 1, cnt, fpw);
	}



	
	fclose(fpr);
	fclose(fpw);


	return 0;
}
