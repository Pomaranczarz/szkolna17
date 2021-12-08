#include <stdio.h>
#define STATUS "student"
#define SREDNIA 4.20f
#define DEBUG

int main() {
    char imie[20] = { '\0' };
    char nazwisko[20] = { '\0' };
    int wiek;
    char plec;

    printf("Podaj imie:");
    scanf("%s", &imie);

    printf("Podaj nazwisko:");
    scanf("%s", &nazwisko);

    printf("Podaj wiek:");
    scanf("%i", &wiek);

    getchar();  // usuwamy '\n' z bufora

    printf("Podaj plec: (k/m)\n");
    scanf("%c", &plec);

    printf("%s %s, %c\n%s %.2f", imie, nazwisko, plec, STATUS, SREDNIA);

    return 0;
}
