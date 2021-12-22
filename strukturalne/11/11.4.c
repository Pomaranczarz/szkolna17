#include "TabliceDyn.h"

int main(void) {
    float* oneDim = CreateOneDimensional(3);
    for (int i = 0; i < 3; i++)
        oneDim[i] = i + 1;

    PrintOneDimensional(oneDim, 3);

    DeleteOneDimensional(oneDim);

    printf("\n\n\n");

    float** twoDim = CreateTwoDimensional(3, 3);

    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            twoDim[i][j] = i + i * j + j;

    PrintTwoDimensional(twoDim, 3, 3);

    DeleteTwoDimensional(twoDim, 3);

    free(oneDim);

    for (int i = 0; i < 3; i++)
        free(twoDim[i]);

    free(twoDim);

    return 0;
}