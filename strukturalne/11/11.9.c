#include "../utils.h"

int** getMatchingProducts(int** t, int rows, int greaterThan, int* matchCount);

int main(void) {
    int** products = (int**)malloc(5 * sizeof(int*));
    for (int i = 0; i < 5; i++) {
        products[i] = (int*)malloc(2 * sizeof(int));
        products[i][0] = GetRandomI(1, 100);
        products[i][1] = GetRandomI(25, 125);
    }

    int userPrice = 0;
    printf("Podaj wartosc: \n");
    scanf("%d", &userPrice);

    int matchCount;
    int** matching = getMatchingProducts(products, 5, userPrice, &matchCount);
    for (int i = 0; i < matchCount; i++)
        printf("%d: $%d\n", matching[i][0], matching[i][1]);

    for (int i = 0; i < 5; i++)
        free(products[i]);

    free(products);

    for (int i = 0; i < matchCount; i++)
        free(matching[i]);

    free(matching);

    return 0;
}

int** getMatchingProducts(int** t, int rows, int greaterThan, int* matchCount) {
    int match_count = 0;
    for (int i = 0; i < rows; i++)
        match_count += t[i][1] > greaterThan ? 1 : 0;

    int** result = (int**)malloc(match_count * sizeof(int*));
    for (int i = 0; i < match_count; i++)
        result[i] = (int*)malloc(2 * sizeof(int));

    *matchCount = match_count;

    int resultIndex = 0;
    for (int i = 0; i < rows; i++)
        if (t[i][1] > greaterThan) {
            result[resultIndex][0] = t[i][0];
            result[resultIndex++][1] = t[i][1];
        }

    return result;
}