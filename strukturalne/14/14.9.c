#include <stdio.h>
#include <string.h>

#define EXPORT_FILENAME "produkty.txt"

void ReadFile(const char* filename);
void PrintCountriesExporting(const char* filename, const char* product_name);
unsigned ExportSum(const char* filename);

int main(void) {
    printf("Zawartosc pliku: \n");
    ReadFile(EXPORT_FILENAME);
    printf("\nKraje eksportujace jablka: \n");
    PrintCountriesExporting(EXPORT_FILENAME, "jablka");
    printf("\nSuma eksportu: %u", ExportSum(EXPORT_FILENAME));
}

void ReadFile(const char* filename) {
    FILE* in = fopen(filename, "r");
    if (in == NULL) {
        perror("Nie udalo sie otworzyc pliku\n");
        return;
    }

    char product[20];
    char country[20];
    unsigned quantity;

    while (fscanf(in, "%s %s %u\n", product, country, &quantity) == 3) 
        printf("%s %s: %u\n", product, country, quantity);

    fclose(in);
}

void PrintCountriesExporting(const char* filename, const char* product_name) {
    FILE* in = fopen(filename, "r");
    if (in == NULL) {
        perror("Nie udalo sie otworzyc pliku\n");
        return;
    }

    char product[20];
    char country[20];
    unsigned quantity;

    while (fscanf(in, "%s %s %u\n", product, country, &quantity) == 3)
        if (strcmp(product, product_name) == 0)
            printf("%s %s: %u\n", product, country, quantity);

    fclose(in);
}

unsigned ExportSum(const char* filename) {
    FILE* in = fopen(filename, "r");
    if (in == NULL) {
        perror("Nie udalo sie otworzyc pliku\n");
        return -1;
    }

    char product[20];
    char country[20];
    unsigned quantity;
    unsigned sum = 0;

    while (fscanf(in, "%s %s %u\n", product, country, &quantity) == 3) 
        sum += quantity;

    fclose(in);

    return sum;
}