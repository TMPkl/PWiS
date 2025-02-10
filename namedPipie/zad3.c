#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
/*
Napisać program tworzący dwa procesy: klienta i serwera. +
Serwer tworzy ogólnodostępną kolejkę FIFO, +
i czeka na zgłoszenia klientów. Każdy klient tworzy własną kolejkę, + 
poprzez którą będą przychodzić odpowiedzi serwera.+
 Zadaniem klienta jest przesłanie nazwy stworzonej przez niego kolejki,
 a serwera odesłaniem poprzez kolejkę, stworzoną przez klienta, wyniku polecenia ls
 */

int main(){
	mkfifo("ktos",0644);
	//mkfifo("stok",0644);

	if (fork() == 0)  

	{

		int fd = open("ktos", O_WRONLY);
		mkfifo("stok",0644);
		write(fd, "stok", 4);
		close(fd);

		int fd2 = open("stok", O_RDONLY);

		dup2(fd2, 0);
		close(fd2); ////////////czemu to działa z i bez tego????????????


		char buf[100] = "";
		read(0, buf, 100);
	

		printf("tutaj jest wynik ls i pisze to klient: %s\n", buf);
		return 0;
	}

	int fd = open("ktos", O_RDONLY);
	char fifo_name[10] = "";
	read(fd, fifo_name, sizeof(fifo_name));
	close(fd);

	int fd2 = open(fifo_name, O_WRONLY);


	dup2(fd2, 1); 
	close(fd2); ////////////czemu to działa z i bez tego????????????

	execlp("ls", "ls", NULL); 
	return 1;

}
