#include <stdio.h>
#include <stdlib.h>

#define LETTER_OF_COMMENDATION_MAX_LEN 120
#define DATE_LEN 11
#define DESTINATION_MAX_LEN 30
#define NAME_MAX_LEN 20
#define CLEAR_BUFF fflush(stdin)
#define PRINT_SEPARATOR "---------------------------------------------------" // :)

struct Prize {
    enum Type { 
        MONEY, 
        TRIP, 
        LETTER 
    } type;

    union PrizeDetails {
        struct Trip{
            char date[DATE_LEN]; // dd.mm.yyyy
            char destination[DESTINATION_MAX_LEN];
        } trip;
        size_t money;
        char letter_of_commendation[LETTER_OF_COMMENDATION_MAX_LEN];
    } details;
};

struct Worker {
    char name[NAME_MAX_LEN];
    char lastname[NAME_MAX_LEN];
    struct Prize prize;
};

void PrintPrize(struct Prize* prize);
void ReadStdinToWorker(struct Worker* worker);

int main(void) {
    size_t num_of_workers;
    printf("Podaj liczbe pracownikow: \n");
    scanf("%llu", &num_of_workers);
    CLEAR_BUFF;

    struct Worker* workers = (struct Worker*)malloc(num_of_workers * sizeof(struct Worker));

    for (int i = 0; i < num_of_workers; i++)
        ReadStdinToWorker(&workers[i]);

    for (int i = 0; i < num_of_workers; i++) {
        printf("%s\n", PRINT_SEPARATOR);
        printf("Nagroda dla %s %s: \n", workers[i].name, workers[i].lastname);
        PrintPrize(&workers[i].prize);
    }

    return 0;
}

void PrintPrize(struct Prize* prize) {
    switch (prize->type) {
        case MONEY:
            printf("Nagroda pieniezna: $%llu\n", prize->details.money);
            break;
        case TRIP: 
            printf("Wycieczka: \ndo: %skiedy: %s\n", 
                prize->details.trip.destination,
                prize->details.trip.date
            );
            break;
        case LETTER:
            printf("List pochwalny: \n%s", prize->details.letter_of_commendation);
            break;
        default:
            perror("Fatal error");
            exit(EXIT_FAILURE);
    }
}

void ReadStdinToPrize(struct Prize* prize) {
    int choice;
    printf("Jaka nagroda: \n1. Pieniadze\n2. Wycieczka\n3. List pochwalny\n");
    CLEAR_BUFF;
    choice = getchar() - '0';
    CLEAR_BUFF;

    switch(choice) {
        case 1:
            prize->type = MONEY;
            printf("Podaj kwote: \n");
            scanf("%llu", &prize->details.money);
            break;
        case 2: 
            prize->type = TRIP;
            printf("Podaj date wycieczki w formacie dd.mm.yyyy: \n");
            fgets(prize->details.trip.date, DATE_LEN, stdin);
            CLEAR_BUFF;
            printf("Podaj miejsce wycieczki: \n");
            fgets(prize->details.trip.destination, DESTINATION_MAX_LEN, stdin);
            CLEAR_BUFF;
            break;
        case 3:
            prize->type = LETTER;
            printf("Podaj tresc listu pochwalnego: \n");
            fgets(prize->details.letter_of_commendation, LETTER_OF_COMMENDATION_MAX_LEN, stdin);
            CLEAR_BUFF;
            break;
        default: 
            perror("Podano nieprawidlowa wartosc");
            exit(EXIT_FAILURE);
    }
}

void ReadStdinToWorker(struct Worker* worker) {
    printf("Podaj imie (max 20 znakow): \n");
    scanf("%20s", worker->name);
    printf("Podaj nazwisko (max 20 znakow): \n");
    scanf("%20s", worker->lastname);
    ReadStdinToPrize(&worker->prize);
}