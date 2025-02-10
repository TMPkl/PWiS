#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(int argc, char* argv[]){
    int fd;
    if (argc != 2) {
        fd = STDIN_FILENO;
    }
    else{
        fd = open(argv[1], O_RDONLY);
    }
    int fdc = open("EXA.txt", O_CREAT | O_WRONLY, 0644);
    char buff;
    while(read(fd, &buff, 1) > 0){
        char new_buff = toupper(buff);
        write(fdc,&new_buff, 1);
    }



/*Napisz program konwertujący małe litery na duże w pliku o nazwie wskazanej
jako argument. Jeśli nazwa pliku nie została podana, dane powinny zostać
odczytane ze standardowego wejścia. 
*/

}