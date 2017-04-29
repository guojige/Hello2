#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>


int main(int argc, char *argv)
{

	FILE  *fp;
	fp = fopen("txt.test", "w");
	int x=123456;
	fprintf(fp, "%d", x);
	fclose(fp);


	return 0;
}
