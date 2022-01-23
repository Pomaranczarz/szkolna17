#include <stdio.h>

int determineTypeOfSetOfEquations(int A1, int B1, int C1, int A2, int B2, int C2);

int main(void) {
    int A1, A2, B1, B2, C1, C2;
    printf("Podaj kolejno A1, B1, C1: \n");
    scanf("%d %d %d", &A1, &B1, &C1);

    printf("Podaj kolejno A2, B2, C2: \n");
    scanf("%d %d %d", &A2, &B2, &C2);

    printf("\n");

    switch(determineTypeOfSetOfEquations(A1, B1, C1, A2, B2, C2)) {
    case 0:
        printf("Nieoznaczony");
        break;
    case 1:
        printf("Oznaczony");
        break;
    case -1:
        printf("Sprzeczny");
        break;
    }

    return 0;
}

int determineTypeOfSetOfEquations(int A1, int B1, int C1, int A2, int B2, int C2) {
    int W = A1 * B2 - A2 * B1;
    int Wx = C1 * B2 - C2 * B1; 
    int Wy= A1 * C2 - A2 * C1;

    if (W == 0 && Wx == 0 && Wy == 0)
        return 0;
    else if (W == 0 && (Wx != 0 || Wy != 0))
        return -1;
    else 
        return 1;
}