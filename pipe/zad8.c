#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <string.h>

int main(){

    int fd[2];
    pipe(fd);

    if(fork()==0)
    {
        close(fd[0]);
        dup2(fd[1],1);
        execlp("ls","ls",NULL);
        close(fd[1]);     
        return 0;   
    }
    if(fork()==0)
    {
        close(fd[1]);
        dup2(fd[0],0);
        execlp("tr","tr","a-z",,NULL);
        close(fd[0]);
        return 0;
    }



}