#include <stdio.h>
#include <stdbool.h>
#include <math.h>

bool is_automorphic(int n) {
    if (n == 1)
        return true;

    int num_squared = n * n;
    int last_digit = num_squared % 10;

    if (last_digit != 5 && last_digit != 6)
        return false;
    else {
        int pos = 1;
        while (n > 0) {
            if (n % 10 != num_squared % 10)
                return false;

            n /= 10;
            num_squared /= 10;
            pos++;
        }
        return true;
    }
}

bool is_prime(int n) {
    int i;
    for (i = 2; i <= sqrt(n); i++)
        if (n % i == 0)
            return false;

    return true;
} 

bool is_pythagorean_triple(unsigned a, unsigned b, unsigned c) {
    return (a * a + b * b == c * c);
}

void print_pythagorean_in_range(unsigned begin, unsigned end) {
    unsigned i, j, k;
    for (i = begin; i < end; i++)
        for (j = begin; j < end; j++)
            for (k = begin; k < end; k++)
                if (is_pythagorean_triple(i, j, k))
                    printf("(%2i, %2i, %2i)\n", i, j, k);
}

int main() {
    int choice;
    printf("1. Liczba automorficzna\n2. Liczba pierwsza\n3. Trojki pitagorejskie");
    choice = getchar() - '0';

    int num, m, n;

    switch (choice) {
        case 1:
            printf("Podaj liczbe: \n");
            scanf("%i", &num);

            if (is_automorphic(num)) 
                printf("Jest automorficzna");
            else 
                printf("Nie jest automorficzna");
        break;
        case 2:
            printf("Podaj liczbe: \n");
            scanf("%i", &num);

            if (is_prime(num)) 
                printf("Jest pierwsza");
            else 
                printf("Nie jest pierwsza");
        break;
        case 3:
            printf("Podaj m: \n");
            scanf("%i", &m);

            printf("Podaj n: \n");
            scanf("%i", &n);

            print_pythagorean_in_range(m, n);
        break;
    }

    return 0;
}