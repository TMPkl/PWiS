#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(int argc, char* argv[])
{
    if (argc < 3) {
        return 1;
    }

    int file_to_write = open(argv[argc - 1], O_CREAT | O_WRONLY | O_TRUNC, 0644);
    char buff[1024];
    ssize_t bytes_read, bytes_written;
    int fd;

    for (int i = 1; i < argc - 1; i++) {
        fd = open(argv[i], O_RDONLY); 
        if (fd == -1) {
            continue;
        }

        while ((bytes_read = read(fd, buff, sizeof(buff))) > 0) {
            bytes_written = write(file_to_write, buff, bytes_read);
        }

        close(fd); 
        write(file_to_write, "\n", 1);
    }

    close(file_to_write);
    return 0;
}
