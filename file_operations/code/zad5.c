#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(int argc, char* argv[]) {
    int fd = open(argv[1], O_RDONLY);
    char buff;

    lseek(fd, 0 , SEEK_END);

    while (lseek(fd, -2, SEEK_CUR) >= 0) {
        read(fd, &buff, 1);
        printf("%c", buff);
        }



}