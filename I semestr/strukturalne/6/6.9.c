#include <stdio.h>
#include <stdlib.h>

int main() {
    unsigned n;

    printf("Podaj n: \n");
    scanf("%u", &n);

    unsigned i;

    float* oceny = (float*)malloc(n * sizeof(float));

    for (i = 0; i < n; i++) {
        printf("Podaj ocene %u. studenta: \n", i + 1);
        scanf("%f", &oceny[i]);
    }

    for (i = 0; i < n; i++)
        if (oceny[i] < 3) {
            printf("Student nr %u nie zdal", i + 1);
            break;
        }

    return 0;
}