#include <stdio.h>
#include <stdlib.h>

int main() {
    unsigned n;
    printf("Podaj n: \n");
    scanf("%u", &n);

    unsigned i;
    int temp;
    int sum_of_even = 0;
    unsigned even_count = 0;
    for (i = 0; i < n; i++) {
        printf("Podaj %u. liczbe: \n", i + 1);
        scanf("%i", &temp);

        if (temp % 2 == 0) {
            sum_of_even += temp;
            even_count++;
        }
    }

    printf("Srednia parzystych: %.2f", sum_of_even * 1.0 / even_count);
}