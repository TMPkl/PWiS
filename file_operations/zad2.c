#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <stdio.h>

int main(int argc, char* argv[])
{
    long length_of_the_file = 0;  
    for (int i = 1; i < argc; i++) 
    {
        int fd = open(argv[i], O_RDONLY);
        char buff;
        ssize_t n;
        while ((n = read(fd, &buff, 1)) > 0) 
        {
            length_of_the_file++; 
        }

        close(fd);  
    }

    printf("\nLength of the file: %ld\n", length_of_the_file);
    return 0;
}
