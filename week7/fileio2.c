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
	fd1 = open("test.txt", O_WRONLY | O_CREAT);
	int x=123456;
	write(fd1, &x, sizeof(x));
	close(fd1);

	fd1 = open("test.txt", O_RDONLY);
	//ssize_t read(int fd, void *buf, size_t count);
	
	int ret = read(fd1, &x, sizeof(x));	
	printf("ret=%d, x=%d\n", ret, x);
	//ssize_t write(int fd, const void *buf, size_t count);


	close(fd1);

	return 0;
}
