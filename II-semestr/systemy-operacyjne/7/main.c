#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void print_process_data(pid_t child_pid) {
    printf("PID: %d\n", getpid());
    printf("PPID: %d\n", getppid());
    printf("Child PID: %d\n", child_pid);
}

int main(int argc, char** argv) {
    srand(time(NULL));
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
        i = 2;
        break;
    }

    for (; i > 0; i--) {
        puts(message);
        print_process_data(child_pid);
        sleep(1);
    }

    // 7.6
    // child_pid == 0 ? 0 : (printf("Czekam na zakonczenie procesu potomka\n"), waitpid(child_pid, NULL, WIFEXITED(0) ? 0 : WNOHANG));
    // child_pid == 0 ? printf("Jestem potomkiem i zakonczylem dzialanie\n") : printf("Jestem rodzicem i zakonczylem dzialanie\n");

    // 7.7/8
    // int child_status;
    // if (child_pid != 0) {
    //     while (waitpid(child_pid, &child_status, WNOHANG) == 0) {
    //         puts("Czekam na zakonczenie procesu potomka");
    //         sleep(1);
    //     }

    //     printf("Proces potomny zakonczyl dzialanie z kodem: %d", WEXITSTATUS(child_status));
    // }

    // child_pid == 0 ? exit(rand() % 100) : exit(0);


}