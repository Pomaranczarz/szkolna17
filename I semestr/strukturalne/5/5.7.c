#include <stdio.h>

void getQuarter(unsigned monthNr) {
    if (monthNr <= 3) 
        putchar('1');
    else if (monthNr > 3 && monthNr <= 6)
        putchar('2');
    else if (monthNr > 6 && monthNr <= 9)
        putchar('3');
    else if (monthNr > 9 && monthNr <= 12)
        putchar('4');
    else {
        perror("never should reach here");
        return;
    }

    printf(" kwartal\n");
}

unsigned getNumberOfDays(unsigned monthNr) {
    if (monthNr == 2)
        return 29;
    else if (monthNr == 1 || monthNr == 3 || monthNr == 5 || monthNr == 7 || monthNr == 8 
            || monthNr == 12 || monthNr == 10)
        return 31;
    else
        return 30;
}

int main() {
    unsigned monthNr;
    printf("Podaj numer miesiaca: \n");
    scanf("%u", &monthNr);

    if (monthNr > 12 || monthNr == 0) {
        perror("Podano niewlasciwy numer miesiaca");
        return -1;
    }

    getQuarter(monthNr);
    printf("Ma on %u dni", getNumberOfDays(monthNr));

    return 0;
}