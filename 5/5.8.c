#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool isTicketLucky(int number);

int main() {
    int ticketNr;
    printf("Podaj numer biletu: \n");
    scanf("%i", &ticketNr);

    if (isTicketLucky(ticketNr))
        printf("To szczesliwy numer");
    else 
        printf("To nie jest szczesliwy numer");

    return 0;
}

unsigned getNumberLen(int number) {
    unsigned count = 0;

    while (number /= 10)
        count++;

    return count;
}

int* makeArrayFromNumber(int number) {
    int* result = (int*)malloc(getNumberLen(number) * sizeof(int));
    int i = 0;
    while (number) {
        result[i++] = number % 10;
        number /= 10;
    }

    return result;
}

bool isTicketLucky(int number) {
    if (number < 0 || getNumberLen(number) != 5) {
        perror("Niewlasciwy numer");
        return false;
    }

    int* numArray = makeArrayFromNumber(number);
    bool result = (numArray[0] + numArray[1] + numArray[2]) == (numArray[3] + numArray[4] + numArray[5]);

    free(numArray);

    return result;
}