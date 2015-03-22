#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/mman.h>
#include <string.h>

int main(int argc, char *argv[])
{
	char buf[] = "hello world, hello world1234";
	printf("1 failed\n");
	int fd = open("a.txt", O_RDWR | O_CREAT, 00664);
	printf("2 failed\n");
	if(fd < 0)
	{
		printf("open failed\n");
		return -1;
	}
	printf("3 failed\n");
	char *addr = (char *)mmap(NULL, 1024, PROT_WRITE | PROT_READ, MAP_SHARED , fd, 0);
	printf("4 failed\n");
	if(addr == (char *)-1)
	{
		printf("mmap failed\n");
		return -1;
	}
	
	printf("5 %d  failed\n",(int)strlen(buf));
	
	memcpy(addr, buf, strlen(buf));
	printf("6 failed\n");

	munmap(addr, 1024);
	printf("7 failed\n");

	close(fd);

	return 0;
}
