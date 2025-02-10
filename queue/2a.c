#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <stdio.h>
#include <string.h>


int main(int argc, char *argv[]){
    int id = msgget(1234, IPC_CREAT | 0644);

    struct msgbuf
{
    long type;
    char text[1024];
}msg;

    msgrcv(id,&msg,10,1,0);
    printf("%s",msg.text);

    //msgctl(id,IPC_RMID,NULL);
}