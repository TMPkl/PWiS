#include <signal.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

void f(int signo) {

printf("Koniec sleepa\n");
}

int main(int argc, char *argv[]){

int time_to_sleep = atoi(argv[1]);

signal(SIGALRM, f);

if(fork() == 0){
    alarm(time_to_sleep);
    pause();
    kill(getppid(), SIGALRM);
}
pause();
return 0;

    
}