#include <stdio.h>

int factorial_iter(int n) {
    int i;
    int result = 1;
    for (i = 1; i <= n; i++)
        result *= i;

    return result;
}

int factorial_recur(int n) {
    return n == 0 ? 1 : n * factorial_recur(n - 1);
}

int main() {
    const int test_value = 12;

    if (factorial_iter(test_value) == factorial_recur(test_value))
        printf("Taki sam wynik");
    else
        printf("Cos jest nie tak");

    return 0;
}