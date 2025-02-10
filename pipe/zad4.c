/*

4. Napisz program, który wygeneruje cztery procesy. Zadaniem pierwszego procesu jest
wysłanie przez potok liczb 1,2,3,4. Każdy kolejny proces po odczytaniu liczb ma
zwiększyć ich wartość i przesłać liczby do następnego procesu. Ostatni proces po
zwiększeniu wartości wypisuje otrzymane liczby na ekranie. 

*/

#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <string.h>

void increment_line(char* line) {
    for (int i = 0; i < strlen(line); i++) {
        if (line[i] >= '0' && line[i] <= '9') {
            int num = line[i] - '0'; 
            num += 1;                
            line[i] = num + '0';     
        }
    }
}

int main(){

    int fd[2];  
    char buff[10] = "1 2 3 4";

    if (pipe(fd) == -1) {
        perror("Error");
        return 1;
    }

    if (fork() == 0) {
        close(fd[0]);
        write(fd[1], buff, 10); 
        close(fd[1]);
        return 0;
    }


for(int i = 0; i < 3; i++){
    if(fork() == 0){
        read(fd[0], buff, 10);
        increment_line(buff);
        
        if(i == 2)
            {
            printf(" \n\n %s \n\n", buff);
            close(fd[0]);
            close(fd[1]);
            return 0;
            }

        write(fd[1],buff,10);
        close(fd[0]);
        close(fd[1]);


        return 0;
    }    
}



}