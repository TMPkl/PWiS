#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <string.h>

int main() {
    int fd[2];  
    char buff[4] = ""; 
    
    if (pipe(fd) == -1) {
        perror("Error");
        return 1;
    }


    if (fork() == 0) {

        close(fd[0]);
        write(fd[1], "H W", 3); 
        close(fd[1]);
        return 0;
    }

    if (fork() == 0) {
       
        close(fd[1]);  
        read(fd[0], buff, 4);  
        printf("Odczytano z potoku: %s\n", buff);
        close(fd[0]);
        return 0;
    }

   
    close(fd[0]);  
    close(fd[1]);  

 
    wait(NULL);
    wait(NULL);

    return 0;
}