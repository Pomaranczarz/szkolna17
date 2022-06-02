#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <wait.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#define BUF_SIZE 2048
#define FIFO_NAME "fifo"

size_t get_number_from_server(const char* str);

int main(int argc, char** argv) {
    char buffer[BUF_SIZE] = { '\0' };
    if (mkfifo(FIFO_NAME, 0666)) {
        printf("Niepowodzenie funkcji mkfifo\n");
        fflush(stdout);
        return EXIT_FAILURE;
    }

    pid_t pid = fork();
    if (pid == -1) {
        printf("Niepowodzenie funkcji fork\n");
        fflush(stdout);
        return EXIT_FAILURE;
    }
    else if (pid == 0) {
        int fifo_fd = open(FIFO_NAME, O_WRONLY);
        for (int i = 0; i < 10; ++i) {
            snprintf(buffer, BUF_SIZE, "Serwer: wysylam linie nr %d\n", i);
            write(fifo_fd, buffer, strlen(buffer));
            sleep(1);
        }
        exit(EXIT_SUCCESS);
    }
    else {
        int fifo_fd = open(FIFO_NAME, O_RDONLY);
        int bytes_read = read(fifo_fd, buffer, BUF_SIZE);
        while (bytes_read > 0) {
            printf("Serwer wyslal: %zu\n", get_number_from_server(buffer));
            bytes_read = read(fifo_fd, buffer, BUF_SIZE);
        }

        wait(NULL);
        remove(FIFO_NAME);
        exit(EXIT_SUCCESS);
    }
}

size_t get_number_from_server(const char* str) {
    size_t number = 0;
    sscanf(str, "Serwer: wysylam linie nr %zu\n", &number);
    return number;
}