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
		dup2(fd,1);
		execlp("ls","ls",NULL);
		return 0;
	}

	int fd = open("fifo", O_RDONLY);
	dup2(fd,0);
	execlp("wc","wc",NULL);
	return 0;
}
