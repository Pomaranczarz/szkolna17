#include <stdio.h>

int main() {
    int num;
    int sum_of_even = 0;
    int sum_of_odd = 0;
    int even_count = 0;
    int odd_count = 0;
    
    do {
        printf("Podaj liczbe, wpisanie 0 konczy wpisywanie\n");
        scanf("%i", &num);

        if (num % 2 == 0) {
            sum_of_even += num;
            even_count++;
        } else {
            sum_of_odd += num;
            odd_count++;
        }
    } while (num != 0);

    printf("Suma parzystych: %f \n", sum_of_even * 1.0 / even_count);
    printf("Suma nieparzystych: %f \n", sum_of_odd * 1.0 / odd_count);

    return 0;
}