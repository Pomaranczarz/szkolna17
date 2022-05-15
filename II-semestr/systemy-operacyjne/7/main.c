#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

void print_process_data(pid_t child_pid) {
    printf("PID: %d\n", getpid());
    printf("PPID: %d\n", getppid());
    printf("Child PID: %d\n", child_pid);
}

int main(int argc, char** argv) {
    pid_t child_pid;
    const char* message;
    int i;

    printf("Na razie dziala jeden proces\n");
    child_pid = fork();

    switch (child_pid) {
    case -1:
        printf("Rozwidlenie procesu nie powiodlo sie\n");
        exit(1);
    case 0:
        message = "Jestem potomkiem";
        i = 5;
        break;
    default:
        message = "Jestem rodzicem";
        i = 5;
        break;
    }

    for (; i > 0; i--) {
        puts(message);
        print_process_data(child_pid);
        sleep(1);
    }
}