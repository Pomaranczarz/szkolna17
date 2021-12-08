#include <stdio.h>

/*
Napisz funkcje, które dla dwuwymiarowej kwadratowej tablicy liczb rzeczywistych o rozmiarze N x N pozwolą na:
    - obliczenie iloczynu elementów na głównej przekątnej,
    - obliczenie sumy elementów nad główną przekątną.
Napisz program, w którym wczytane są dane, wywołane funkcje, wyświetlone wyniki.
*/

int main(void) {
    unsigned N;
    printf("Podaj N:");
    scanf("%u", &N);

    int** tab = (int*)malloc(N * sizeof(int));    
    for (int i = 0; i < N; i++)
        tab[i] = (int*)malloc(N * sizeof(int));

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            scanf("%d", &tab[i][j]);
        }
    }
}