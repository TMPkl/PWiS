#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/time.h>
#include <stdio.h>
#include <string.h>
#include <sys/wait.h>

int main(int argc, char* argv[]) {
    struct timeval t0, t1;

    // Prepare arguments for execvp
    char* av_[argc];
    for (int i = 1; i < argc; i++) {
        av_[i - 1] = argv[i];
    }
    av_[argc - 1] = NULL;  // NULL terminator for execvp

    // Start measuring time
    gettimeofday(&t0, NULL);

    // Fork the process
    pid_t pid = fork();
    if (pid == 0) {
        // Child process executes the command
        execvp(av_[0], av_);
        _exit(1);  // Exit if execvp fails
    } else if (pid > 0) {
        // Parent process waits for the child to finish
        wait(NULL);
        
        // End time after child completes
        gettimeofday(&t1, NULL);

        // Calculate elapsed time in microseconds
        long long elapsed = (t1.tv_sec - t0.tv_sec) * 1000000LL + (t1.tv_usec - t0.tv_usec);
        printf("Elapsed time: %lld microseconds\n", elapsed);
    }

    return 0;
}
