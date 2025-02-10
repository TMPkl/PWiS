#include <signal.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

void obsluga(int signo) {
printf("Odebrano sygnał %d\n", signo);
}


int main() {
signal(SIGINT, SIG_IGN);


while(1) ; //pętla nieskończona
}
