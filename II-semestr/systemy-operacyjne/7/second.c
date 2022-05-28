#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    printf("Wykonuje polecenie za pomoca funkcji system()\n");
    system("echo Pospie sobie chwileczke");
    system("sleep 1");
    printf("Polecenie wywolane za pomoca system() zakonczylo sie\n");

    printf("Wykonuje polecenie za pomoca funkcji execlp()\n");

    pid_t first_child = fork();
    if (first_child < 0) {
        perror("Nie udalo sie utworzyc procesu potomnego");
        exit(EXIT_FAILURE);
    }
    else if (first_child == 0) {
        execlp("echo", "echo", "Pospie sobie chwileczke", NULL);
    }
    else {
        pid_t second_child = fork();
        if (second_child < 0) {
            perror("Nie udalo sie utworzyc procesu potomnego");
            exit(EXIT_FAILURE);
        }
        else if (second_child == 0) {
            execlp("sleep", "sleep", "1", NULL);
        }
        else {
            wait(NULL);
            wait(NULL);
            printf("Polecenie wywolane za pomoca execlp() zakonczylo sie\n");
        }
    }

    return 0;
}