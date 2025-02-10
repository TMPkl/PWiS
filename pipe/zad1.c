#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main()
{
    int fd[2];
    pipe(fd);
   if (fork() == 0){

close (fd[0]);
write(fd[1], "Hello", 5);
close(fd[1]);
_exit(0);

   }
   else {
    close(fd[1]);
    char buff[100];
    read(fd[0], buff, 5);
    close(fd[0]);
    printf("%s\n", buff);
   }
    return 0;
}