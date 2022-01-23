#include <stdio.h>
#define M_PI 3.14159265359

void szescian();
void prostopadloscian();
void walec();

int main() {
    printf("Obliczanie pola powierzchni bocznej i objetosci wybranych bryl\n");
    printf("Wybierz bryle:\n1. Szescian\n2. Prostopadloscian\n3. Walec");
    int choice;
    scanf("%i", &choice);
    switch (choice) {
    case 1:
        szescian();
        break;
    case 2:
        prostopadloscian();
        break;
    case 3:
        walec();
        break;
    default:
        perror("Podano nieprawidlowa wartosc");
        return -1;
    }
    return 0;
}

void szescian() {
    float krawedz;
    printf("Podaj krawedz szescianu:");
    scanf("%f", &krawedz);

    if (krawedz < 0) {
        perror("Podano nieprawidlowa wartosc");
        return;
    }

    float poleBoczne = 6 * krawedz * krawedz;
    float objetosc = krawedz * krawedz * krawedz;
    printf("Pole boczne: %.2f\nObjetosc: %.2f", poleBoczne, objetosc);
}

void prostopadloscian() {
    float a;
    float b;
    float c;

    printf("Podaj a:");
    scanf("%f", &a);
    printf("Podaj b:");
    scanf("%f", &b);
    printf("Podaj c:");
    scanf("%f", &c);

    if (a < 0 || b < 0 || c < 0) {
        perror("Podano nieprawidlowa wartosc");
        return;
    }
    float poleBoczne = 2 * a * b + 2 * a * c + 2 * b * c;
    float objetosc = a * b * c;
    printf("Pole boczne: %.2f\nObjetosc: %.2f", poleBoczne, objetosc);
}

void walec() {
    float promien;
    float wysokosc;

    printf("Podaj promien podstawy:");
    scanf("%f", &promien);
    printf("Podaj wysokosc:");
    scanf("%f", &wysokosc);

    if (promien < 0 || wysokosc < 0) {
        perror("Podano nieprawidlowa wartosc");
        return;
    }

    float poleBoczne = 2 * M_PI * promien * wysokosc;
    float objetosc = M_PI * promien * promien * wysokosc;
    printf("Pole boczne: %.2f\nObjetosc: %.2f", poleBoczne, objetosc);
}
