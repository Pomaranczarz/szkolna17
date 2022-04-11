#include <stdio.h>

#define N 20

int ileRazy(int tab[], int n, int liczba);
int suma(int tab[], int n);
int max(int tab[], int n);
void wyswietl(int tab[], int n);
void wczytaj(int tab[], int n);
int ileRazy2(int tab[], int n, int x);
void losuj(int tab[], int n);
float srednia(int tab[], int n);
int min(int tab[], int n);

int main(void) {
    int tab1[N];
    int tab2[N];

    wczytaj(tab1, N);
    wyswietl(tab1, N);
    printf("Najwieksza wartosc: %d\n", max(tab1, N));
    printf("Suma elementow: %d\n", suma(tab1, N));
    printf("Ile razy wystepuje %d: %d\n", 5, ileRazy(tab1, N, 5));

    wczytaj(tab2, N);
    wyswietl(tab2, N);
    printf("Najwieksza wartosc: %d\n", max(tab2, N));
    printf("Suma elementow: %d\n", suma(tab2, N));
    printf("Ile razy wystepuje %d: %d\n", 5, ileRazy(tab2, N, 5));

    int tab3[5] = {1, 2, 3, 4, 5};
    int tab4[] = {6, 7, 8, 9, 10};
    int tab5[5];
    losuj(tab5, 5);

    printf("tab3:\n");
    printf("min: %d ", min(tab3, 5));
    printf("srednia: %f ", srednia(tab3, 5));
    printf("ile razy wystapilo 2: %d ", ileRazy2(tab3, 5, 2));

    printf("\ntab4:\n");
    printf("min: %d ", min(tab4, 5));
    printf("srednia: %f ", srednia(tab4, 5));
    printf("ile razy wystapilo 2: %d ", ileRazy2(tab4, 5, 2));

    printf("\ntab5:\n");
    printf("min: %d ", min(tab5, 5));
    printf("srednia: %f ", srednia(tab5, 5));
    printf("ile razy wystapilo 2: %d ", ileRazy2(tab5, 5, 2));

    return 0;
}

int min(int tab[], int n) {
    int min = tab[0];
    for (int i = 1; i < n; i++)
        if (tab[i] < min)
            min = tab[i];
    
    return min;
}

float srednia(int tab[], int n) {
    float suma = 0;
    for (int i = 0; i < n; i++)
        suma += tab[i];
    
    return suma / n;
}

void losuj(int tab[], int n) {
    for (int i = 0; i < n; i++)
        tab[i] = rand() % 10;
}

int ileRazy2(int tab[], int n, int x) {
    int ile = 0;
    for (int i = 0; i < n; i++)
        if (tab[i] == x)
            ile++;
    
    return ile;
}

void wczytaj(int tab[], int n) {
    int i;
    for (i = 0; i < n; i++) {
        printf("Podaj %d element tablicy: ", i + 1);
        scanf("%d", &tab[i]);
    }
}

void wyswietl(int tab[], int n) {
    int i;
    for (i = 0; i < n; i++)
        printf("%d ", tab[i]);

    printf("\n");
}

int max(int tab[], int n) {
    int i, max = tab[0];
    for (i = 1; i < n; i++)
        if (tab[i] > max)
            max = tab[i];

    return max;
}

int suma(int tab[], int n) {
    int i, suma = 0;
    for (i = 0; i < n; i++)
        suma += tab[i];

    return suma;
}

int ileRazy(int tab[], int n, int liczba) {
    int i, ile = 0;
    for (i = 0; i < n; i++)
        if (tab[i] == liczba)
            ile++;

    return ile;
}