#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

void reverseWithoutWhitespace(char str[]) {
    int start = 0;
    int end = strlen(str) - 1;

    while (start < end) {
        if (isspace(str[start])) {
            start++;
        } else if (isspace(str[end])) {
            end--;
        } else {
            char temp = str[start];
            str[start] = str[end];
            str[end] = temp;
            start++;
            end--;
        }
    }
}

int main(int argc, char* argv[]) {
    if (argc < 3) {
        printf("Usage: %s <input_filename> <output_filename>\n", argv[0]);
        return 1;
    }

    char line[100] = {0};
    char buff;
    int fd = open(argv[1], O_RDONLY);
    int fdn = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (fdn == -1) {
        perror("Error opening output file");
        return 1;
    }

    ssize_t n;
    int index = 0;

    if (fd < 0) {
        perror("Error opening input file");
        return 1;
    }

    while ((n = read(fd, &buff, 1)) > 0) {
        if (buff == '\n' || index >= 99) {
            line[index] = '\0';
            reverseWithoutWhitespace(line);
            printf("%s\n", line);
            write(fdn, line, strlen(line));
            write(fdn, "\n", 1);
            memset(line, 0, sizeof(line));
            index = 0;
        } else {
            line[index++] = buff;
        }
    }

    if (index > 0) {
        line[index] = '\0';
        reverseWithoutWhitespace(line);
        printf("%s\n", line);
        write(fdn, line, strlen(line));
        write(fdn, "\n", 1);
    }

    close(fd);
    close(fdn);

    return 0;
}
