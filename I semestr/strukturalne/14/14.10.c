#include <stdio.h>

#define SOURCE_FILE "source.txt"
#define DEST_FILE "destination.txt"

void CopyEvery3Char(const char* source_filename, const char* destination_filename);
void PrintFile(const char* filename);

int main(void) {
    CopyEvery3Char(SOURCE_FILE, DEST_FILE);

    printf("Zawartosc pliku zrodlowego: \n");
    PrintFile(SOURCE_FILE);
    printf("\nZawartosc pliku docelowego: \n");
    PrintFile(DEST_FILE);
}

void CopyEvery3Char(const char* source_filename, const char* destination_filename) {
    FILE* src = fopen(source_filename, "r");
    FILE* dst = fopen(destination_filename, "w");

    if (src == NULL || dst == NULL) {
        perror("Nie udalo sie otworzyc pliku\n");
        return;
    }

    char c;
    int count = 0;
    while ((c = getc(src)) != EOF) {
        count++;
        if (count == 3) {
            fprintf(dst, "%c", c);
            count = 0;
        }
    }

    fclose(src);
    fclose(dst);
}

void PrintFile(const char* filename) {
    FILE* in = fopen(filename, "r");
    if (in == NULL) {
        perror("Nie udalo sie otworzyc pliku\n");
        return;
    }

    char c;
    while ((c = getc(in)) != EOF)
        printf("%c", c);

    fclose(in);
}
