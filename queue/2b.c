#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>




int main(){
    int id = msgget(1234, IPC_CREAT | 0644);

    struct msgbuf
{
    long type;
    char text[1024];
}msg;

    for(int i = 0; i<10;i++){
    msg.type = i ;

    strcpy(msg.text,"Hello");
    strcat(msg.text,itoa(i));
    msgsnd(id,&msg,10,0);
}

}