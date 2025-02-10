#include <signal.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

void f(int signo) {
printf("Koniec czasu\n");
exit(0);
}

int main() {


int time;
printf("Podaj czas");
scanf("%d", &time);

alarm(time);
signal(SIGALRM, *f);

printf("Czekam na sygnał\n");
while(1)  //pętla nieskończona
{
    char buffer[10] = "";
        if (fgets(buffer, sizeof(buffer), stdin))
        {
            printf("Wpisałeś: %s", buffer);     //????????????????????
        }
}

}
