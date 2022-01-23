#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define FILENAME "liczby.txt"
#define NUM_COUNT 30

int GetRandomI(int begin, int end);
void SaveToFile(const char* filename, int num);
void ReadFileWithPosInfo(const char* filename);

int main(void) {
    srand(time(NULL));

    for (int i = 0; i < NUM_COUNT; i++)
        SaveToFile(FILENAME, GetRandomI(0, 100));

    ReadFileWithPosInfo(FILENAME);

    return 0;
}

void SaveToFile(const char* filename, int num) {
    FILE* out = fopen(filename, "a");
    if (out == NULL) {
        perror("Nie udalo sie otworzyc pliku\n");
        return;
    }

    fprintf(out, "%d\n", num);

    fclose(out);
}

void ReadFileWithPosInfo(const char* filename) {
    FILE* in = fopen(filename, "r");
    if (in == NULL) {
        perror("Nie udalo sie otworzyc pliku\n");
        return;
    }

    int current_num;
    int current_pos = ftell(in);
    while ((current_pos = ftell(in), fscanf(in, "%d\n", &current_num)) == 1)
        printf("%d, pozycja: %d\n", current_num, current_pos);


    fclose(in);
} 

int GetRandomI(int begin, int end) {
    return rand() % (end - begin) + begin;
}