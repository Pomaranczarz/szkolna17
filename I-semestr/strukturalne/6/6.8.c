#include <stdio.h>

int main() {
    unsigned wyplata;
    float oprocentowanie;
    float temp_wyplata;
    unsigned count = 0;

    printf("Podaj wyplate: \n");
    scanf("%u", &wyplata);

    printf("Podaj oprocentowanie: \n");
    scanf("%f", &oprocentowanie);

    temp_wyplata = wyplata;

    while (temp_wyplata < wyplata * 2) {
        temp_wyplata += temp_wyplata * oprocentowanie;
        count++;
    }

    printf("Po %u okresach kapitalizacji", count);

    return 0;
}