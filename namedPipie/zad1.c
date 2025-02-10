#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>


int main(){
	mkfifo("fifo",0644);
	if (fork() == 0)
	{
		int fd = open("fifo", O_WRONLY);
		write(fd,"HALLO!",6);
		return 0;
	}
		char buff[10] = "";
		int fd = open("fifo", O_RDONLY);
		read(fd,buff,10);
		printf("%s",buff);
		printf("\n");	
		return 0;
}


