#include <stdio.h>

long int getSumOfDigitsCube(int number) {
    long int result = 0;
    int digit;
    while (number) {
        digit = number % 10;
        result += digit * digit * digit;
        number /= 10;
    } 

    return result;
}

int main() {
    int i;
    for (i = 100; i < 1000; i++)
        if (getSumOfDigitsCube(i) == i)
            printf("%u\n", i);

    return 0;
}