#include <stdio.h>

int main(void) {
    unsigned n;
    
    printf("Podaj n: \n");
    scanf("%u", &n);

    unsigned positive_counter = 0;
    unsigned equal_to_zero_counter = 0;
    int number;

    while (n--) {
        printf("Podaj liczbe: \n");
        scanf("%i", &number);

        if (number == 0)
            equal_to_zero_counter++;
        else if (number > 0)
            positive_counter++;    
    }

    printf("Dodatnich: %u\nRownych 0: %u\n", positive_counter, equal_to_zero_counter);
    
    return 0;
}