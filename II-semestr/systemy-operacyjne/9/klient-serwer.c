#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <wait.h>

#define BUF_SIZE 2048

size_t get_number_from_server(const char* str);

int main(int argc, char** argv) {
    int pipe_fd[2];
    if (pipe(pipe_fd) == -1) {
        printf("Niepowodzenie funkcji pipe\n");
        fflush(stdout);
        return EXIT_FAILURE;
    }

    char buffer[BUF_SIZE] = { '\0' };

    pid_t pid = fork();
    if (pid == -1) {
        printf("Niepowodzenie funkcji fork\n");
        fflush(stdout);
        return EXIT_FAILURE;
    }
    else if (pid == 0) {
        close(pipe_fd[0]);
        for (int i = 0; i < 10; ++i) {
            snprintf(buffer, BUF_SIZE, "Serwer: wysylam linie nr %d\n", i);
            write(pipe_fd[1], buffer, strlen(buffer));
        }

        close(pipe_fd[1]);
        exit(EXIT_SUCCESS);
    }
    else {
        close(pipe_fd[1]);
        int bytes_read = read(pipe_fd[0], buffer, BUF_SIZE);
        while (bytes_read > 0) {
            printf("Serwer wyslal: %zu\n", get_number_from_server(buffer));
            bytes_read = read(pipe_fd[0], buffer, BUF_SIZE);
        }

        close(pipe_fd[0]);
        exit(EXIT_SUCCESS);
    }
}

size_t get_number_from_server(const char* str) {
    size_t number = 0;
    sscanf(str, "Serwer: wysylam linie nr %zu\n", &number);
    return number;
}