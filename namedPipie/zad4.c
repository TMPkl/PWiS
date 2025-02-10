#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

int main(){

    mkfifo("init_rura", 0644);

    if(fork()==0) //klient
    {

        int fd_init = open("init_rura",O_WRONLY);


        char klient_to_server[4] ="kts\0";
        char server_to_klient[4]="stk\0";



        mkfifo("kts",0644);
        mkfifo("stk",0644);

        printf("ty nie działasz\n");
        

        write(fd_init,klient_to_server,4);
        write(fd_init,server_to_klient,4);


        int fd_to_read = open(server_to_klient,O_RDONLY);
        int fd_to_write = open(klient_to_server,O_WRONLY);


        write(fd_to_write,"ls",2);

        char buff[100] = "";
        read(fd_to_read,buff,100);
        printf("klient pozdrawia i pisze co sie tu dzije (: : %s",buff);

        return 0;
    }

    int fd_init = open("init_rura", O_RDONLY);
    char klient_to_server[4]="";
    char server_to_klient[4]="";

    read(fd_init,klient_to_server,4);
    read(fd_init,server_to_klient,4);
    printf("-> %s %s \n",klient_to_server,server_to_klient);

    int fd_to_write = open(server_to_klient,O_WRONLY);
    int fd_to_read = open(klient_to_server,O_RDONLY);

    char exe_name[2];
    read(fd_to_read,exe_name,2);

    printf("powiedz czemu\n");

    dup2(fd_to_write,1);
    execlp(exe_name,exe_name,NULL);
    perror("nie dziala");

    return 0;

}