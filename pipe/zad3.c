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
    char buff[3] = "";

    if(pipe(fd)==-1){
        perror("Error");
        return 1;
    }

    if (fork() == 0) {

        close(fd[0]);
        write(fd[1], "H", 1); 
        close(fd[1]);
        return 0;
    }
    if (fork() == 0) {

        close(fd[0]);
        write(fd[1], " W", 2); 
        close(fd[1]);
        return 0;
    }

    close(fd[1]);
    read(fd[0],buff,1);
    printf("Odczytano z potoków: %s\n", buff);
    close(fd[0]);
       

    wait(NULL);
    wait(NULL);
    return 0;


}