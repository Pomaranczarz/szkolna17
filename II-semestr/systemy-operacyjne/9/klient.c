#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define BUF_SIZE 2048

size_t get_number_from_server(const char* str);

int main(int argc, char** argv) {
    FILE* command_result = popen("./serwer", "r");

    if (command_result) {
        char buffer[BUF_SIZE] = { '\0' };
        fgets(buffer, BUF_SIZE, command_result);

        while (!feof(command_result)) {
            sleep(2);
            printf("Serwer wyslal: %d\n", get_number_from_server(buffer));
            fgets(buffer, BUF_SIZE, command_result);
        }

        pclose(command_result);
        fflush(stdout);
        return EXIT_SUCCESS;
    }
    else {
        printf("Niepowodzenie funkcji popen\n");
        fflush(stdout);
        return EXIT_FAILURE;
    }
}

size_t get_number_from_server(const char* str) {
    size_t number = 0;
    sscanf(str, "Serwer: wysylam linie nr %zu\n", &number);
    return number;
}