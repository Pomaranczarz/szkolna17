#include <signal.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdbool.h>

typedef void(*sighandler_t)(int);

sighandler_t default_sigint_handler = NULL;
sighandler_t default_sigquit_handler = NULL;
sighandler_t default_sigalarm_handler = NULL;

void obsluga_sig_int(int sig) {
    static char napisy[4][80] = {
        "Ha! Ha! Ha! To tylko sygnal powierzchowny\n",
        "Tylko proces %d smieje sie sygnalowi %d prosto w twarz!\n",
        "Auc - to bolalo!\n",
        "Dobrze! Dobrze! Juz koncze\n"
    };

    static int nr_napisu = 0;

    printf(napisy[nr_napisu], getpid(), sig);

    if (nr_napisu == 3)
        exit(0);

    nr_napisu++;
}

void restore_default_sigint_handler(int sig) {
    signal(SIGINT, default_sigint_handler);
}

int main(int argc, char** argv) {
    size_t counter = 0;
    default_sigint_handler = signal(SIGINT, obsluga_sig_int);
    default_sigquit_handler = signal(SIGQUIT, restore_default_sigint_handler);
    default_sigalarm_handler = signal(SIGALRM, restore_default_sigint_handler);

    while (true) {
        printf("Czesc, tu proces: %d\n", getpid());
        sleep(1);
        counter++;
        if (counter == 14) {
            printf("Ding! Ding! Ding! - Przywracam domyslna obsluge CTRL+C\n");
            alarm(1);
        }
    }

    return 0;
}