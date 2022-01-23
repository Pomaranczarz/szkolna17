#include <stdio.h>
#include <stdlib.h>

#define MONEY_PER_HOUR 20

struct Worker {
    char name[20];
    char lastname[20];
    size_t hours_worked;
    size_t bonus_in_percents;
};

void ReadStdinToWorker(struct Worker* worker);
float ComputeWorkerPayment(struct Worker* worker);

int main(void) {
    size_t num_of_workers;
    printf("Podaj liczbe pracownikow: \n");
    scanf("%llu", &num_of_workers);

    struct Worker* workers = (struct Worker*)malloc(num_of_workers * sizeof(struct Worker));

    for (int i = 0; i < num_of_workers; i++)
        ReadStdinToWorker(&workers[i]);

    for (int i = 0; i < num_of_workers; i++) 
        printf("Wyplata dla %s %s: $%.2f\n", 
            workers[i].name, 
            workers[i].lastname, 
            ComputeWorkerPayment(&workers[i])
        );
    
    free(workers);

    return 0;
}

float ComputeWorkerPayment(struct Worker* worker) {
    size_t payment_from_hours = worker->hours_worked * MONEY_PER_HOUR;
    return ((float)worker->bonus_in_percents / 100) * payment_from_hours + payment_from_hours;
}

void ReadStdinToWorker(struct Worker* worker) {
    printf("Podaj imie (max 20 znakow): \n");
    scanf("%20s", worker->name);
    printf("Podaj nazwisko (max 20 znakow): \n");
    scanf("%20s", worker->lastname);
    printf("Podaj liczbe godzin: \n");
    scanf("%llu", &worker->hours_worked);
    printf("Podaj %% premii: \n");
    scanf("%llu", &worker->bonus_in_percents);
}
