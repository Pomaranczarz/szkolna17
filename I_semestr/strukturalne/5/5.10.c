#include <stdio.h>

float getAverage(float* arr, unsigned size) {
    unsigned i;
    float sum = 0.f;
    for (i = 0; i < size; i++)
        sum += arr[i];

    return sum / size;
}

int main() {
    float oceny[3] = { 0 };
    int i;
    for (i = 0; i < 3; i++) {
        printf("Podaj ocene z %i. egzaminu: \n", i + 1);
        scanf("%f", &oceny[i]);
    }

    float srednia = getAverage(oceny, 3);
    if (srednia > 4.f) 
        printf("500zl");
    else if (srednia > 3.f && srednia <= 4.f)
        printf("300 zl");
    else 
        printf("Brak stypednium");

    return 0;
}