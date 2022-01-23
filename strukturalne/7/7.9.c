#include <stdio.h>
#include <math.h>
#include <stdbool.h>

bool is_prime(int n) {
    int i;
    for (i = 2; i <= sqrt(n); i++)
        if (n % i == 0)
            return false;

    return true;
} 

void fill_primes(int* arr, unsigned len) {
    unsigned index = 0;
    unsigned start = 2;
    while (index < len) {
        if (is_prime(start)) {
            arr[index] = start;
            index++;
        }
        start++;
    }
}

/// przyjmuje ze liczby nie-pierwsze sa zliczane od 2, poniewaz 0 i 1 nie sa ani pierwsze, ani zlozone
int count_non_primes_from_two_to_num(int num) {
    int i;
    int count = 0;

    for (i = 2; i < num; i++) {
        if (!is_prime(i))
            count++;
    }

    return count;
}

int main() {
    int n;
    int primes[20];
    fill_primes(primes, 20);

    do {
        printf("Podaj liczbe pomiedzy 1 a 20: \n");
        scanf("%i", &n);
    } while (n < 1 || n > 20);

    int i;
    printf("%i kolejnych liczb pierwszych: \n", n);
    for (i = 0; i < n; i++)
        printf("%i\n", primes[i]);

    printf("%i kolejnych liczb pierwszych w odwrotnej kolejnosci: \n", n);
    for (i = n - 1; i >= 0; i--)
        printf("%i\n", primes[i]);

    printf("Liczb, ktore nie sa pierwsze w tym przedziale: %i", count_non_primes_from_two_to_num(primes[n - 1]));

    return 0;
}