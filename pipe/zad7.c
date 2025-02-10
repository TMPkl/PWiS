#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>  

int main(){
    int fd[2];
    pipe(fd);
    char buff[100] = "";
    
   if(fork()==0)
    {
        close(fd[0]);
        dup2(fd[1],1);
        execlp("ls","ls",NULL);
        close(fd[1]);        
    }
    if(fork()==0)
    {
        close(fd[1]);
        while(read(fd[0],buff,100)!=0)
        {
            for(int i = 0; i < strlen(buff); i++)
            {
                char p = buff[i];
                if(isalpha(p))
                {
                    p = toupper(p);
                }
                printf("%c",p);
            }
            memset(buff, 0, sizeof(buff)); 
        }
        
        close(fd[0]);
        close(fd[1]);
        return 0;
    }
    printf("\n");
    return 0;
}