#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX_STREET_NAME_LEN 20
#define MAX_NAME_LEN 20

struct Poll {
    struct Address {
        char street[MAX_STREET_NAME_LEN];
        unsigned house_nr;
        unsigned apartment_nr;
    } address;

    enum Gender { 
        MALE, 
        FEMALE, 
    } gender;

    unsigned age;
    char name[MAX_NAME_LEN];
    char lastname[MAX_NAME_LEN];
};

unsigned CountIf(struct Poll* begin, struct Poll* end, bool(*predicate)(struct Poll));
void ReadStdinToPoll(struct Poll* poll);

bool LivesAtSpecialPlaceAndWoman(struct Poll poll) {
    return strcmp(poll.address.street, "Kwiatowa") == 0 
            && poll.address.house_nr == 6 
            && poll.address.apartment_nr == 9 && poll.gender == FEMALE;
}

bool LivesAtSpecialPlaceAndMan(struct Poll poll) {
    return strcmp(poll.address.street, "Kwiatowa") == 0 
            && poll.address.house_nr == 6 
            && poll.address.apartment_nr == 9 && poll.gender == MALE;
}

bool LivesAtSpecialPlaceAndAge(struct Poll poll) {
    return (poll.age >= 18 && poll.age <= 60) && strcmp(poll.address.street, "Kwiatowa") == 0;
}

int main(void) {    
    size_t poll_count;
    printf("Podaj liczbe ankietowanych: \n");
    scanf("%llu", &poll_count);

    struct Poll* polls = (struct Poll*)malloc(poll_count * sizeof(struct Poll));
    for (int i = 0; i < poll_count; i++)
        ReadStdinToPoll(&polls[i]);

    printf("Mieszkajacych przy Kwiatowej 6/9:\nKobiet: %u\nMezczyzn: %u\n", 
        CountIf(polls, polls + poll_count, LivesAtSpecialPlaceAndWoman),
        CountIf(polls, polls + poll_count, LivesAtSpecialPlaceAndMan)
    );
    printf("Mezczyzn w wieku 18-60 mieszkajacych przy Kwiatowej: %u", 
        CountIf(polls, polls + poll_count, LivesAtSpecialPlaceAndAge)
    );

    free(polls);

    return 0;
}

unsigned CountIf(struct Poll* begin, struct Poll* end, bool(*predicate)(struct Poll)) {
    unsigned count = 0;
    for (struct Poll* it = begin; it != end; it++) 
        if (predicate(*it))
            count++;

    return count;
}

void ReadStdinToPoll(struct Poll* poll) {
    fflush(stdin);
    char gender;
    printf("Podaj plec (k - kobieta, m - mezczyzna)");
    scanf("%c", &gender);
    if (gender == 'k')
        poll->gender = FEMALE;
    else if (gender == 'm')
        poll->gender = MALE;
    else {
        perror("Podano nieprawidlowa wartosc dla plci");
        exit(EXIT_FAILURE);
    }
    printf("Podaj imie (max %d znakow): \n", MAX_NAME_LEN);
    scanf("%s", poll->name);
    printf("Podaj nazwisko (max %d znakow): \n", MAX_NAME_LEN);
    scanf("%s", poll->lastname);
    printf("Podaj wiek: \n");
    scanf("%u", &poll->age);
    printf("Podaj ulice (max %d znakow): \n", MAX_STREET_NAME_LEN);
    scanf("%s", poll->address.street);
    printf("Podaj nr domu: \n");
    scanf("%u", &poll->address.house_nr);
    printf("Podaj nr mieszkania: \n");
    scanf("%u", &poll->address.apartment_nr);
}