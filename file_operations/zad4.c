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
    char line[100] = {0};
    char buff;
    int fd = open(argv[1], O_RDONLY);
    int max_line_now = 0;
    int max_line = 0;

    if (fd == -1) {
        perror("Error opening input file");
        return 1;
    }

    ssize_t n;
    int index = 0;

    while ((n = read(fd, &buff, 1)) > 0) {
        if (buff == '\n' || index >= 99) {
            line[index] = '\0';
            max_line_now = strlen(line);
            if (max_line_now >= max_line) {
                max_line = max_line_now;
            }
            memset(line, 0, sizeof(line));
            index = 0;
        } else {
            line[index++] = buff;
        }
    }

    if (index > 0) {
        line[index] = '\0';
        max_line_now = strlen(line);
        if (max_line_now >= max_line) {
            max_line = max_line_now;
        }
    }

    close(fd);
    printf("Max line length: %d\n", max_line);
    return 0;
}
