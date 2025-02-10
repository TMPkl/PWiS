#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <stdio.h>
#include <string.h>




int main(){
    int id = msgget(1234, IPC_CREAT | 0644);

    struct msgbuf
{
    long type;
    char text[1024];
}msg;

    msg.type = 1 ;
    strcpy(msg.text,"Hello");
    msgsnd(id,&msg,10,0);
}