#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>

#define BUF_SIZE 2048
#define FIFO_NAME "fifo"

int main(int argc, char** argv) {
    if (mkfifo(FIFO_NAME, 0666)) {
        printf("Niepowodzenie funkcji mkfifo\n");
        fflush(stdout);
        return EXIT_FAILURE;
    }

    char buffer[BUF_SIZE] = { '\0' };
    int fifo_fd = open(FIFO_NAME, O_WRONLY);
    for (int i = 0; i < 10; ++i) {
        snprintf(buffer, BUF_SIZE, "Serwer: wysylam linie nr %d\n", i);
        write(fifo_fd, buffer, strlen(buffer));
        sleep(1);
    }

    close(fifo_fd);
    exit(EXIT_SUCCESS);
}