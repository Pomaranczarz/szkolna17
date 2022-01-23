#include <stdio.h>
#include <stdbool.h>

bool is_pythagorean_triple(unsigned a, unsigned b, unsigned c) {
    return (a * a + b * b == c * c);
}

int main() {
    int n;
    do {
        printf("Podaj liczbe pomiedzy 10 a 100: \n");
        scanf("%i", &n);
    } while (n < 10 || n > 100);

    int i, j, k;
    for (i = 1; i < n; i++)
        for (j = 1; j < n; j++)
            for (k = 1; k < n; k++)
                if (is_pythagorean_triple(i, j, k))
                    printf("(%2i, %2i, %2i)\n", i, j, k);

    return 0;
}