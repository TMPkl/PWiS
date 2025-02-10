#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <string.h>

int main(){
    char even[] = {'0','2','4','6'};
    char odd[] = {'1','3','5','7'};

    int fd[2]; 
    pipe(fd);

    if (fork() == 0)
    {
        close(fd[0]);
        for(int i = 0; i<4; i++)
        {
            write(fd[1],&even[i],1);
        }
        close(fd[1]);
        return 0;
    }

if (fork() == 0)
    {
        close(fd[0]);
        for(int i = 0; i<4;i++)
        {
            write(fd[1],&odd[i],1);
        }
        close(fd[1]);
        return 0;
    }

char buff[10]="";
    if(fork()==0)
    {
        close(fd[1]);
        read(fd[0],buff,10);
        close(fd[0]);
        int rez = 0;
        for (int i = 0; i < strlen(buff); i++) 
    {
        if (buff[i] >= '0' && buff[i] <= '9') 
        {
            int num = buff[i] - '0'; 
            rez += num;                      
        }
    }
        printf("\n %d \n",rez);
        return 0;
    }
}