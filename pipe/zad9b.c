#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <string.h>

int main() {
    int fd[2], fd1[2];

   pipe(fd);
   pipe(fd1);
       

    if (fork() == 0) {
        close(fd[0]);
        close(fd1[0]);
        close(fd1[1]);
        dup2(fd[1], 1);
        execlp("ls", "ls", "-l", NULL);
        return 1;
    }

    if (fork() == 0) {
        //grep ^d
        close(fd[1]);
        close(fd1[0]);
        dup2(fd[0], 0);
        dup2(fd1[1], 1);
        execlp("grep", "grep", "^d", NULL);
        return 1;
    }

        close(fd[0]);
        close(fd[1]);
        close(fd1[1]);
        dup2(fd1[0], 0);
        execlp("more", "more", NULL);
    	return 0;
}
