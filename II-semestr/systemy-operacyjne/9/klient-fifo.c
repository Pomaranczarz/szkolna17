#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#define BUF_SIZE 2048
#define FIFO_NAME "fifo"

size_t get_number_from_server(const char* str);

int main(int argc, char** argv) {
    if (!popen("./serwer-fifo", "r")) {
        printf("Niepowodzenie funkcji popen\n");
        fflush(stdout);
        return EXIT_FAILURE;
    }
    sleep(1);
    int pipe = open(FIFO_NAME, O_RDONLY);
    char buffer[BUF_SIZE] = { '\0' };
    int bytes_read = read(pipe, buffer, BUF_SIZE);
    while (bytes_read > 0) {
        printf("Serwer wyslal: %zu\n", get_number_from_server(buffer));
        bytes_read = read(pipe, buffer, BUF_SIZE);
    }
    close(pipe);
    remove(FIFO_NAME);
    exit(EXIT_SUCCESS);
}

size_t get_number_from_server(const char* str) {
    size_t number = 0;
    sscanf(str, "Serwer: wysylam linie nr %zu\n", &number);
    return number;
}