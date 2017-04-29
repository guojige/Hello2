#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>


int main(int argc, char *argv)
{

	//   int open(const char *pathname, int flags);
	//   FILE *fopen(const char *path, const char *mode);
	int fd1;
	fd1 = open("test.txt", O_RDONLY);
	printf("fd = %d\n", fd1);

	int fd2;
	fd2 = open("txt.test", O_RDONLY);
	printf("fd = %d\n", fd2);

	//ssize_t read(int fd, void *buf, size_t count);
	char x;
	int ret = read(fd1, &x, sizeof(x));	
	//printf("ret=%d, x=%c\n", ret, x);
	//ssize_t write(int fd, const void *buf, size_t count);
	write(1, "ret=", 4);
	write(1, &ret,  sizeof(ret));
	


	close(fd1);
	close(fd2);

	return 0;
}
