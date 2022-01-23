#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX_PRODUCER_NAME_LEN 20
#define MAX_NAME_LEN 10

struct Date {
    unsigned day;
    unsigned month;
    unsigned year;
};

static const struct Date CurrentDate = { .day = 28, .month = 12, .year = 2021 };

struct Candy {
    char name[MAX_NAME_LEN];
    char producer[MAX_PRODUCER_NAME_LEN];
    struct Date prod_date;
    struct Date expiry_date;
    unsigned quantity_kg;
    unsigned price_kg;
};

void PrintExpiredCandies(struct Candy* begin, struct Candy* end, struct Date date_to_compare);
void PrintCandiesInPriceRange(struct Candy* begin, struct Candy* end, int min, int max);
void ReadStdinToCandy(struct Candy* candy);
bool IsDateBefore(struct Date date, struct Date before);

int main(void) {
    size_t num_of_candy_types;
    printf("Podaj liczbe rodzajow cukierkow: \n");
    scanf("%llu", &num_of_candy_types);

    struct Candy* candies = (struct Candy*)malloc(num_of_candy_types * sizeof(struct Candy));

    for (int i = 0; i < num_of_candy_types; i++)
        ReadStdinToCandy(&candies[i]);

    printf("Cukierki ktorych koszt jest w przedziale 15 - 25 zl za kg: \n");
    PrintCandiesInPriceRange(candies, candies + num_of_candy_types, 15, 25);
    printf("Cukierki ktore przekroczyly date przydatnosci: \n");
    PrintExpiredCandies(candies, candies + num_of_candy_types, CurrentDate);

    free(candies);

    return 0;
}

struct Date StrToDate(char* stringified_date) {
    struct Date result;
    char* day_end = stringified_date + 2;
    char* month_end = stringified_date + 5;
    char* year_end = stringified_date + strlen(stringified_date);
    result.day = strtol(stringified_date, &day_end, 10);
    result.month = strtol(stringified_date + 3, &month_end, 10);
    result.year = strtol(stringified_date + 6, &year_end, 10);

    return result;
}

void ReadStdinToCandy(struct Candy* candy) {
    char date[11];

    printf("Podaj nazwe (max 10 znakow): \n");
    scanf("%s", candy->name);
    printf("Podaj producenta (max 20 znakow): \n");
    scanf("%s", candy->producer);
    printf("Podaj date produkcji (dd.mm.yyyy): \n");
    scanf("%s", date);
    candy->prod_date = StrToDate(date);
    printf("Podaj date przydatnosci (dd.mm.yyyy): \n");
    scanf("%s", date);
    candy->expiry_date = StrToDate(date);
    printf("Podaj ilosc (w kg): \n");
    scanf("%u", &candy->quantity_kg);
    printf("Podaj cene za 1 kg: \n");
    scanf("%u", &candy->price_kg);
}

void PrintCandiesInPriceRange(struct Candy* begin, struct Candy* end, int min, int max) {
    for (struct Candy* it = begin; it != end; it++)
        if (it->price_kg > min && it->price_kg < max)
            printf("%s\n", it->name);
}

bool IsDateBefore(struct Date date, struct Date before) {
    if (date.year < before.year)
        return true;
    else if (date.month < before.month)
        return true;
    else if (date.day < before.day)
        return true;
    else
        return false;
}

void PrintExpiredCandies(struct Candy* begin, struct Candy* end, struct Date date_to_compare) {
    for (struct Candy* it = begin; it != end; it++)
        if (!IsDateBefore(date_to_compare, it->expiry_date))
            printf("%s\n", it->name);
}