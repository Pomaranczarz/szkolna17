#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

struct Worker {
    char name[20];
    char lastname[20];
    size_t hours_worked;
    size_t money_per_hour;
    size_t bonus_in_percents;
};

void ReadStdinToWorker(struct Worker* worker);
float ComputeWorkerPayment(struct Worker worker);
void ReadFile(const char* filename);
void SaveToTxtFile(const char* filename, struct Worker worker);
void SaveToBinFile(const char* filename, struct Worker worker);
void PrintFileIf(const char* filename, bool(*predicate)(float));
bool GreaterThan500(float f) { return f > 500.f; }

int main(void) {
    size_t num_of_workers;
    printf("Podaj liczbe pracownikow: \n");
    scanf("%llu", &num_of_workers);

    struct Worker* workers = (struct Worker*)malloc(num_of_workers * sizeof(struct Worker));

    for (int i = 0; i < num_of_workers; i++) {
        ReadStdinToWorker(&workers[i]);
        SaveToBinFile("wyplaty.bin", workers[i]);
    }

    ReadFile("wyplaty.bin");

    printf("\nWyplaty wieksze niz 500: \n");
    PrintFileIf("wyplaty.bin", GreaterThan500);

    free(workers);
    return 0;
}

void SaveToTxtFile(const char* filename, struct Worker worker) {
    FILE* out = fopen(filename, "a");
    float worker_payment = ComputeWorkerPayment(worker);

    fprintf(out, "%.2f\n", worker_payment);

    fclose(out);
}

void SaveToBinFile(const char* filename, struct Worker worker) {
    FILE* out = fopen(filename, "ab");
    float worker_payment = ComputeWorkerPayment(worker);

    fwrite(&worker_payment, sizeof(float), 1, out);

    fclose(out);
}

void PrintFileIf(const char* filename, bool(*predicate)(float)) {
    FILE* in = fopen(filename, "r");

    float value;
    while (fread(&value, sizeof(float), 1, in) == 1) {
        if (predicate(value))
            printf("%.2f\n", value);
    }
}

void ReadFile(const char* filename) {
    FILE* in = fopen(filename, "r");
    if (in == NULL) {
        perror("Nie udalo sie otworzyc pliku");
        return;
    }

    char buff[100];
    while (fgets(buff, 100, in) != NULL)
        printf("%s", buff);

    fclose(in);
}

float ComputeWorkerPayment(struct Worker worker) {
    size_t payment_from_hours = worker.hours_worked * worker.money_per_hour;
    return ((float)worker.bonus_in_percents / 100) * payment_from_hours + payment_from_hours;
}

void ReadStdinToWorker(struct Worker* worker) {
    printf("Podaj imie (max 20 znakow): \n");
    scanf("%20s", worker->name);
    printf("Podaj nazwisko (max 20 znakow): \n");
    scanf("%20s", worker->lastname);
    printf("Podaj liczbe godzin: \n");
    scanf("%llu", &worker->hours_worked);
    printf("Podaj stawke godzinowa: \n");
    scanf("%llu", &worker->money_per_hour);
    printf("Podaj %% premii: \n");
    scanf("%llu", &worker->bonus_in_percents);
}