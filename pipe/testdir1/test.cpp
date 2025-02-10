#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <string.h>

//finger | cut -d' ' -f1
//ls -l | grep ^d | more

int main(){

    int fd[2];
    pipe(fd);

    if(fork()==0)
    {
        close(fd[0]);
        dup2(fd[1],1);
        execlp("ls","ls","-l",NULL);
        close(fd[1]);
    }
    if(fork()==0)
    {
        close(fd[1]);
        dup2(fd[0],0);
        execlp("grep", "grep", "^","d", NULL);
        close(fd[0]);
    }
    if(fork()==0)
    {
        close(fd[1]);
        dup2(fd[0],0);
        execlp("more", "more", NULL);
        close(fd[0]);
    }
    close(fd[0]);
    close(fd[1]);
    wait(NULL);
    wait(NULL);
    return 0;
}
